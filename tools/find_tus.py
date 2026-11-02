#!/usr/bin/env python3
"""Recover the original translation units (TUs) of .text 0x1008D8-0x300500.

Analysis only: reads asm/, build/ee_asm/, config/funcs.txt, config/handwritten.txt and the ELF,
writes config/tu_map.tsv (and, with --debug DIR, intermediate JSON).  Method: docs/TU.md.

    python3 tools/find_tus.py [--gamma 20] [--out config/tu_map.tsv]

Pure Python, no docker, about a minute.
"""
import argparse, bisect, glob, json, os, re, struct, sys
from collections import defaultdict, Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(os.path.join(ROOT, 'tools'))     # append: tools/dis.py must not shadow `dis`
import ffxsyms                                    # noqa: E402  name <-> address (real names too)
SYMS = ffxsyms.Syms(ROOT)
TEXT0, TEXT1 = 0x1008D8, 0x300500
VRAM_OFF = 0xFF000                      # .text vram - file offset
GP = 0x584670                           # crt0: la $gp, D_00584670 (.lit4 = gp-0x7ff0)
SECS = [('data', 0x300500, 0x300500 + 0x26899c, 0x201500),
        ('rodata', 0x568f00, 0x568f00 + 0xfe99, 0x469f00),
        ('lit4', 0x57c680, 0x57c680 + 0x48c, 0x47d680),
        ('sbss', 0x57cb80, 0x57cbc4, None),
        ('bss', 0x57cc00, 0x57cc00 + 0x2187e8, None)]


def sec(a):
    for n, lo, hi, _ in SECS:
        if lo <= a < hi:
            return n
    return None


RAW = open(os.path.join(ROOT, 'baserom/SCES_504.90'), 'rb').read()


def word(vaddr):
    return struct.unpack_from('<I', RAW, vaddr - VRAM_OFF)[0]


def cstr(a):
    for n, lo, hi, off in SECS:
        if off is not None and lo <= a < hi:
            o = a - lo + off
            e = RAW.find(b'\0', o, o + 300)
            if e < 0:
                return None
            s = RAW[o:e]
            if s and all(32 <= c < 127 or c in (9, 10) or c >= 0x80 for c in s):
                return s
    return None


# ----------------------------------------------------------------------------------------------
# 1. functions and their references (per instruction address)
SYM = re.compile(r'%(hi|lo)\(([A-Za-z_]\w*)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?\)')
GPREL = re.compile(r'(-?0x[0-9A-Fa-f]+|-?\d+)\(\$gp\)')
JAL = re.compile(r'\b(?:jal|j)\s+([A-Za-z_]\w*)')
LINE = re.compile(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ')


def load_funcs():
    funcs = []
    for l in open(os.path.join(ROOT, 'config/funcs.txt')):
        n, a, s = l.split()
        funcs.append((int(a, 16), int(s, 16), n))
    funcs.sort()
    return funcs


def scan_refs(funcs):
    files = {}
    files.update(SYMS.asm_files('asm/nonmatchings'))
    for n, p in SYMS.asm_files('build/ee_asm').items():
        files.setdefault(n, p)
    refs, calls, fptr = [], [], []          # (insn_addr, target)
    for a, s, n in funcs:
        if not (TEXT0 <= a < TEXT1):
            continue
        p = files.get(n)
        if p:
            for line in open(p):
                m = LINE.match(line)
                ia = int(m.group(1), 16) if m else a
                for m in SYM.finditer(line):
                    kind, name, off = m.groups()
                    base = SYMS.addr(name)
                    if base is None:
                        continue
                    t = base + (int(off, 0) if off else 0)
                    (fptr if SYMS.is_func(name) or name.startswith('func_') else refs).append((ia, t))
                for m in GPREL.finditer(line):
                    refs.append((ia, GP + int(m.group(1), 0)))
                for m in JAL.finditer(line):
                    t = SYMS.addr(m.group(1))
                    if t is not None and (SYMS.is_func(m.group(1)) or m.group(1).startswith('func_')):
                        calls.append((ia, t))
        else:                                # no asm file: tiny resolver on the ROM
            hi = {}
            for k in range(a, a + s, 4):
                w = word(k)
                op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xffff
                simm = imm - 0x10000 if imm & 0x8000 else imm
                if op == 0x0F:
                    hi[rt] = imm << 16
                elif op == 3:
                    calls.append((k, (w & 0x3ffffff) << 2))
                elif op in (0x09, 0x0D, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F):
                    if rs == 28:
                        refs.append((k, GP + simm))
                    elif rs in hi:
                        refs.append((k, (hi[rs] + (imm if op == 0x0D else simm)) & 0xffffffff))
    return refs, calls, fptr


def data_pointers():
    """words in .data/.rodata that point to text or to data"""
    out = []
    for n, lo, hi, off in SECS[:2]:
        for k in range(0, hi - lo - 3, 4):
            v = struct.unpack_from('<I', RAW, off + k)[0]
            if TEXT0 <= v < TEXT1 or (sec(v) in ('data', 'rodata', 'bss') and v % 4 == 0):
                out.append((lo + k, v))
    return out


def hidden_starts(funcs):
    """function starts that config/funcs.txt misses: `jr $ra; <delay>` followed by a prologue"""
    out = []
    for a, s, n in funcs:
        if not (TEXT0 <= a < TEXT1):
            continue
        targets = set()
        for p in range(a, a + s, 4):
            x = word(p)
            op = x >> 26
            if op in (4, 5, 6, 7, 20, 21, 22, 23) or op == 1:
                off = x & 0xffff
                off = off - 0x10000 if off & 0x8000 else off
                targets.add(p + 4 + off * 4)
            if op == 2:
                targets.add((x & 0x3ffffff) << 2)
        for p in range(a, a + s - 8, 4):
            if word(p) == 0x03e00008:
                q = p + 8
                while q < a + s and word(q) == 0 and q % 8:
                    q += 4
                if q >= a + s or q in targets:
                    continue
                x = word(q)
                if (x >> 16) == 0x27bd and (x & 0x8000):      # addiu $sp,$sp,-N
                    out.append((q, n))
    return out


# ----------------------------------------------------------------------------------------------
class Model:
    def __init__(self):
        funcs = load_funcs()
        self.hidden = hidden_starts(funcs)
        hid_by = defaultdict(list)
        for q, n in self.hidden:
            hid_by[n].append(q)
        U = []
        for a, s, n in funcs:
            if not (TEXT0 <= a < TEXT1):
                continue
            cuts = [a] + sorted(hid_by.get(n, [])) + [a + s]
            for x, y in zip(cuts, cuts[1:]):
                U.append(dict(addr=x, end=y, name=n if x == a else 'func_%08X' % x, parent=n, hidden=x != a))
        U.sort(key=lambda u: u['addr'])
        self.U, self.N = U, len(U)
        self.addr = [u['addr'] for u in U]
        refs, calls, fptr = scan_refs(funcs)
        N = self.N
        R = [set() for _ in range(N)]
        C = [set() for _ in range(N)]
        P = [set() for _ in range(N)]
        for ia, t in refs:
            if sec(t):
                R[self.fi(ia)].add(t)
        for lst, dst in ((calls, C), (fptr, P)):
            for ia, t in lst:
                if TEXT0 <= t < TEXT1 and self.addr[self.fi(t)] == t:
                    dst[self.fi(ia)].add(self.fi(t))
        self.refs = [sorted((r, sec(r)) for r in rs) for rs in R]
        self.calls, self.fptr = C, P
        self.users = defaultdict(set)
        for i, rs in enumerate(self.refs):
            for r, s in rs:
                self.users[(s, r)].add(i)
        self.callers = defaultdict(set)
        for i, cs in enumerate(C):
            for c in cs:
                if c != i:
                    self.callers[c].add(i)
        self.ptrs = data_pointers()
        self.hw = {}
        for l in open(os.path.join(ROOT, 'config/handwritten.txt')):
            if l.startswith('#') or not l.strip():
                continue
            p = l.split()
            self.hw[p[0]] = p[1] if len(p) > 1 else ''

    def fi(self, a):
        return bisect.bisect_right(self.addr, a) - 1

    def span(self, us):
        return self.addr[max(us)] - self.addr[min(us)]


# ----------------------------------------------------------------------------------------------
FILE_RE = re.compile(rb'[\w/.\-]+\.(c|cpp|cc)')


class Evidence:
    ADJ = 0.1        # weak prior: neighbours are in the same TU
    INVW = 0.2       # data-order inversion pair
    INVCAP = 2.0     # ... at most this much inversion weight per unit
    FAR = 0x20000    # data used over a wider text span is treated as a global

    def __init__(self, m, names_map=None):
        self.m = m
        N, users, span = m.N, m.users, m.span
        self.edges = defaultdict(float)
        self.kinds = defaultdict(float)
        # -- file-name strings (__FILE__ of assert/error macros)
        self.anchors = defaultdict(set)
        for (s, r), us in users.items():
            t = cstr(r)
            if t and FILE_RE.fullmatch(t):
                for i in us:
                    self.anchors[i].add(t.decode())
        # -- hard separations: boundary required in (p, q]
        self.seps = []
        strs = defaultdict(list)
        for (s, r), us in users.items():
            if s == 'rodata' and r % 4 == 0:
                t = cstr(r)
                if t is not None:
                    strs[t].append((r, us))
        for t, cps in strs.items():          # string literals are pooled per TU: two copies = two TUs
            cps.sort()
            for (r1, u1), (r2, u2) in zip(cps, cps[1:]):
                if max(u1) < min(u2):
                    self.seps.append((max(u1), min(u2), 'dupstr %r' % t[:24].decode('latin1')))
        al = sorted((i, n) for i, ns in self.anchors.items() for n in ns)
        for (i1, n1), (i2, n2) in zip(al, al[1:]):
            if n1 != n2 and i1 < i2:
                self.seps.append((i1, i2, 'file %s|%s' % (n1, n2)))
        # asm objects: gcc aligns every function to 8, so a 4-mod-8 start is a hand-written object
        # Units that start at 4 mod 8 come from hand-written (.align 2) assembler objects. Odd units
        # less than 0x400 bytes apart are taken as one object, extended over neighbours packed
        # without padding; it is separated from the gcc code around it.
        self.odd_runs = []
        odd = [i for i in range(N) if m.addr[i] % 8]
        k = 0
        while k < len(odd):
            i = j = odd[k]
            while k + 1 < len(odd) and m.addr[odd[k + 1]] - m.U[j]['end'] < 0x400:
                k += 1
                j = odd[k]
            while j + 1 < N and m.addr[j + 1] == m.U[j]['end'] and m.U[j]['end'] % 8:
                j += 1
            self.odd_runs.append((i, j))
            if i > 0:
                self.seps.append((i - 1, i, 'asm-align'))
            if j + 1 < N:
                self.seps.append((j, j + 1, 'asm-align'))
            k += 1
        # -- hard cohesion: cuts forbidden in (lo, hi]
        self.nocut = []
        byname = defaultdict(list)
        for i, ns in self.anchors.items():
            for n in ns:
                byname[n].append(i)
        for n, l in byname.items():
            if max(l) > min(l):
                self.nocut.append((min(l), max(l), 'file ' + n))
        for (s, r), us in users.items():
            if s == 'rodata' and len(us) > 1 and span(us) <= 0x8000 and cstr(r):
                self.nocut.append((min(us), max(us), 'shared string'))
        for i, j in self.odd_runs:
            if j > i:
                self.nocut.append((i, j, 'asm object'))
        # -- soft cohesion edges
        for (s, r), us in users.items():
            if len(us) < 2:
                continue
            ul = sorted(us)
            sp = span(us)
            if s == 'rodata':
                if sp > 0x40000:
                    continue
                w, k = 4.0, 'rodata'
            elif s == 'lit4':
                w, k = 2.0, 'lit4'
            else:
                if sp > self.FAR or len(us) > 30:
                    continue
                w, k = 1.5 / (1 + len(us) / 8), s
            for a, b in zip(ul, ul[1:]):
                self.add(a, b, w, k)
        for c, cl in m.callers.items():
            allu = cl | {c}
            priv = span(allu) <= 0x6000 and len(cl) <= 8
            for i in cl:
                if priv:
                    self.add(i, c, 1.0, 'call')
                elif abs(m.addr[i] - m.addr[c]) <= 0x1000:
                    self.add(i, c, 0.3, 'call')
        ps = sorted((src, m.fi(dst)) for src, dst in m.ptrs if TEXT0 <= dst < TEXT1 and m.addr[m.fi(dst)] == dst)
        tabs, cur = [], []
        for src, t in ps:
            if cur and src - cur[-1][0] <= 0x10:
                cur.append((src, t))
            else:
                if len(cur) >= 2:
                    tabs.append(cur)
                cur = [(src, t)]
        if len(cur) >= 2:
            tabs.append(cur)
        for tb in tabs:
            ts = sorted(set(t for _, t in tb))
            if len(ts) >= 2 and span(ts) <= 0x8000:
                for a, b in zip(ts, ts[1:]):
                    self.add(a, b, 0.7, 'ftab')
        # data-order inversions: i < i' but d(i) > d(i')  =>  same TU (pools follow TU order)
        self.LP = []
        for i in range(N):
            self.LP.append([(s, r) for r, s in m.refs[i] if s != 'rodata'
                            and span(users[(s, r)]) <= 0x30000 and len(users[(s, r)]) <= 25])
        inv = defaultdict(int)
        for s in ('data', 'bss', 'lit4', 'sbss'):
            pts = [(i, r) for i in range(N) for ss, r in self.LP[i] if ss == s]
            k0 = 0
            for k, (i, r) in enumerate(pts):
                while m.addr[pts[k0][0]] < m.addr[i] - 0x3000:
                    k0 += 1
                for i2, r2 in pts[k0:k]:
                    if i2 < i and r2 > r:
                        inv[(i2, i)] += 1
        tot = defaultdict(float)             # cap each unit's inversion weight at INVCAP
        for (a, b), c in inv.items():
            tot[a] += min(c, 3)
            tot[b] += min(c, 3)
        for (a, b), c in inv.items():
            f = min(1.0, self.INVCAP / (self.INVW * max(tot[a], tot[b])))
            self.add(a, b, self.INVW * min(c, 3) * f, 'inversion')
        # same name prefix (config/names_map.tsv, high/medium) on neighbouring named functions
        if names_map:
            named = [(i, name_prefix(names_map[m.U[i]['name']][0])) for i in range(N)
                     if names_map.get(m.U[i]['name'], ('', 'low'))[1] in ('high', 'medium')]
            for (i1, p1), (i2, p2) in zip(named, named[1:]):
                if p1 == p2 and m.addr[i2] - m.addr[i1] <= 0x2000:
                    self.add(i1, i2, 0.8, 'names')
            # Switch port continuity: consecutive PS2 functions that are also consecutive (same order,
            # small gap) in the Switch NRO.  Only for names not matched by order alignment.
            sw = [(i, names_map[m.U[i]['name']][3]) for i in range(N)
                  if m.U[i]['name'] in names_map and names_map[m.U[i]['name']][1] in ('high', 'medium')
                  and names_map[m.U[i]['name']][2] != 'order' and names_map[m.U[i]['name']][3]]
            for (i1, s1), (i2, s2) in zip(sw, sw[1:]):
                dp = m.addr[i2] - m.addr[i1]
                if dp <= 0x3000 and 0 < s2 - s1 <= 3 * dp + 0x800:
                    self.add(i1, i2, 1.0, 'switch-order')
        self.strong = dict(self.edges)               # without the adjacency prior
        for i in range(N - 1):
            self.add(i, i + 1, self.ADJ, 'adj')

    def add(self, a, b, w, k):
        if a == b:
            return
        if a > b:
            a, b = b, a
        self.edges[(a, b)] += w
        self.kinds[k] += w


# ----------------------------------------------------------------------------------------------
def segment(ev, gamma, L=1600):
    """linear segmentation maximising modularity  sum_seg W_in - gamma*deg^2/4W
    with hard separations and forbidden cuts"""
    m, N = ev.m, ev.m.N
    back = defaultdict(list)
    deg = [0.0] * N
    W = 0.0
    for (a, b), w in ev.edges.items():
        back[b].append((a, w))
        deg[a] += w
        deg[b] += w
        W += w
    for b in back:
        back[b].sort(reverse=True)
    cdeg = [0.0]
    for d in deg:
        cdeg.append(cdeg[-1] + d)
    lowq = defaultdict(int)
    for p, q, _ in ev.seps:
        lowq[q] = max(lowq[q], p + 1)
    low, mx = [0] * (N + 1), 0
    for jj in range(N + 1):
        if jj - 1 in lowq:
            mx = max(mx, lowq[jj - 1])
        low[jj] = mx
    blocked = [False] * (N + 1)
    d = [0] * (N + 2)
    for lo, hi, _ in ev.nocut:
        d[lo + 1] += 1
        d[hi + 1] -= 1
    c = 0
    for t in range(N + 1):
        c += d[t]
        blocked[t] = c > 0
    best, arg = [0.0] * (N + 1), [0] * (N + 1)
    k4W = 4 * W
    row = {}
    for jj in range(1, N + 1):
        lo = max(low[jj], jj - L)
        bk = back.get(jj - 1, [])
        p, acc, new = 0, 0.0, {}
        bv, bi = -1e18, jj - 1
        for i in range(jj - 1, lo - 1, -1):
            while p < len(bk) and bk[p][0] >= i:
                acc += bk[p][1]
                p += 1
            wv = row.get(i, 0.0) + acc
            new[i] = wv
            if blocked[i] and i > 0:
                continue
            dd = cdeg[jj] - cdeg[i]
            v = best[i] + wv - gamma * dd * dd / k4W
            if v > bv:
                bv, bi = v, i
        row = new
        best[jj], arg[jj] = bv, bi
    cuts, x = [], N
    while x > 0:
        cuts.append(arg[x])
        x = arg[x]
    return sorted(set(cuts)), blocked


# ----------------------------------------------------------------------------------------------
SDK_TAGS = [  # (substring of a referenced string, library object guess)
    (b'sceGsDefDispEnv', 'libgraph'), (b'sceGsExecStoreImage', 'libgraph'), (b'libdma', 'libdma'),
    (b'D1_CHCR', 'libdma'), (b'libpad', 'libpad'), (b'libmc', 'libmc'), (b'mcserv', 'libmc'),
    (b'sceCd', 'libcdvd'), (b'Libcdvd', 'libcdvd'), (b'cmd wait', 'libcdvd'), (b'cmd fail', 'libcdvd'),
    (b'DiskReady', 'libcdvd'), (b'cdread', 'libcdvd'), (b'libkernl', 'libkernl'), (b'TTY:', 'libkernl/tty'),
    (b'rom0:UDNL', 'libkernl/iopreset'), (b'0123456789abcdef', 'newlib/vfprintf'), (b'Infinity', 'newlib/strtod'),
]
LIBM_NAMES = {b'acos', b'atan2', b'fmod', b'sqrt', b'acosf', b'atan2f', b'fmodf', b'sqrtf', b'asin', b'pow',
              b'exp', b'log', b'log10', b'asinf', b'powf', b'expf', b'logf', b'log10f'}
SOFTFLOAT = {0x2EBBB0: 'dpadd', 0x2EBC08: 'dpsub', 0x2EC198: 'dpcmp', 0x2EC1E8: 'litodp', 0x2EC2A0: 'dptoli',
             0x2EC338: 'dptoul', 0x2EC440: 'dptofp', 0x2ED038: 'fptodp'}


def name_tu(ev, a, b, names_map):
    m = ev.m
    an = sorted(set().union(*[ev.anchors.get(i, set()) for i in range(a, b)]))
    if an:
        return an[0].rsplit('/', 1)[-1].rsplit('.', 1)[0], 'file:' + '+'.join(an)
    tags = Counter()
    hint = None
    for i in range(a, b):
        for r, s in m.refs[i]:
            t = cstr(r)
            if not t:
                continue
            if t in LIBM_NAMES:
                tags['libm/' + t.decode()] += 3
            for k, lib in SDK_TAGS:
                if k in t:
                    tags[lib] += 1
            if hint is None and len(t) >= 6 and sum(ch >= 0x61 for ch in t) >= 3:
                hint = t[:28].decode('latin1').replace('\t', ' ').replace('\n', ' ').strip()
        if m.addr[i] in SOFTFLOAT:
            tags['libgcc/fp-bit(dp)'] += 5
    named = [names_map[m.U[i]['name']][0] for i in range(a, b) if m.U[i]['name'] in names_map]
    if named and not tags:
        pre = Counter(name_prefix(n) for n in named)
        p, c = pre.most_common(1)[0]
        nm = p.rstrip('_') if c * 2 >= len(named) and len(p) >= 2 else named[0]
        return '~' + nm, 'names:%d/%d %s..%s' % (len(named), b - a, named[0], named[-1])
    if tags:
        lib, _ = tags.most_common(1)[0]
        return lib, 'tag:' + lib
    return None, ('str:"%s"' % hint) if hint else ''


def load_names_map():
    """config/names_map.tsv (Switch/Steam-derived names, if present): current funcs.txt name of the
    ps2_symbol (config/names_applied.tsv) -> (name, confidence, method, switch address)"""
    p = os.path.join(ROOT, 'config/names_map.tsv')
    out = {}
    if os.path.exists(p):
        for l in open(p):
            f = l.rstrip('\n').split('\t')
            if len(f) >= 2 and f[0].startswith('func_'):
                note = f[5] if len(f) > 5 else ''
                sw = re.search(r'sw@([0-9a-f]+)', note)
                out[SYMS.cur(f[0])] = (f[1], f[4] if len(f) > 4 else '', f[3] if len(f) > 3 else '',
                             int(sw.group(1), 16) if sw else None)
    return out


def name_prefix(n):
    if '_' in n[1:]:
        return n.split('_')[0] + '_'
    mm = re.match(r'[a-z]+|[A-Z][a-z]+', n)
    return mm.group(0) if mm else n


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--gamma', type=float, default=20.0)
    ap.add_argument('--stab', default='5,10,40,80', help='extra resolutions for the stability score')
    ap.add_argument('--out', default=os.path.join(ROOT, 'config/tu_map.tsv'))
    ap.add_argument('--debug', default=None)
    args = ap.parse_args()
    m = Model()
    names_map = load_names_map()
    ev = Evidence(m, names_map)
    N = m.N
    cuts, blocked = segment(ev, args.gamma)
    stab = {}
    for g in [float(x) for x in args.stab.split(',') if x]:
        stab[g] = set(segment(ev, g)[0])
    # crossing weight of strong (non-adjacency) edges for every cut position
    diff = [0.0] * (N + 2)
    for (a, b), w in ev.strong.items():
        diff[a + 1] += w
        diff[b + 1] -= w
    cross, c = [0.0] * (N + 1), 0.0
    for t in range(N + 1):
        c += diff[t]
        cross[t] = c
    sep_at = defaultdict(list)       # cut index -> hard separation reasons bracketing it
    hard_cuts = set()
    for k, t in enumerate(cuts):
        if t == 0:
            continue
        prev = cuts[k - 1] if k else 0
        nxt = cuts[k + 1] if k + 1 < len(cuts) else N
        for p, q, why in ev.seps:
            if prev <= p < t <= q < nxt:
                sep_at[t].append((q - p, why))
    bounds = cuts + [N]
    rows = []
    bconf = {}
    for t in cuts:
        if t == 0:
            bconf[t] = ('high', 'high: text start')
            continue
        hard = sorted(sep_at.get(t, []))
        stable = sum(1 for g in stab if t in stab[g])
        # positional slack: neighbouring cut positions that are not worse
        lo_t, hi_t = t, t
        while lo_t - 1 > 0 and not blocked[lo_t - 1] and cross[lo_t - 1] <= cross[t] + 0.35:
            lo_t -= 1
        while hi_t + 1 < N and not blocked[hi_t + 1] and cross[hi_t + 1] <= cross[t] + 0.35:
            hi_t += 1
        if hard and hard[0][1] == 'asm-align':
            lo_t = hi_t = t
        slack = m.addr[hi_t] - m.addr[lo_t]
        exists = 'hard' if hard else ('stable' if stable >= len(stab) - 1 else 'weak')
        exact = slack == 0
        if exists == 'hard' and (exact or hard[0][0] <= 1):
            conf = 'high'
        elif exists == 'hard' or (exists == 'stable' and (exact or slack <= 0x100)):
            conf = 'medium'
        else:
            conf = 'low'
        why = []
        if hard:
            why.append('sep:' + hard[0][1])
        why.append('stab%d/%d' % (stable, len(stab)))
        why.append('x%.1f' % cross[t])
        if slack:
            why.append('slack%x-%x' % (m.addr[lo_t], m.addr[hi_t]))
        bconf[t] = (conf, conf + ': ' + ' '.join(why))
    order = {'low': 0, 'medium': 1, 'high': 2}
    for k, (a, b) in enumerate(zip(bounds, bounds[1:])):
        name, nev = name_tu(ev, a, b, names_map)
        ca, wa = bconf[a]
        cb, wb = bconf[b] if b < N else ('high', 'text end')
        conf = min(ca, cb, key=lambda x: order[x])
        # pools: local data first-used in this TU
        pools = []
        for s in ('rodata', 'data', 'bss', 'lit4', 'sbss'):
            rs = [r for i in range(a, b) for r, ss in m.refs[i] if ss == s
                  and min(m.users[(ss, r)]) >= a and max(m.users[(ss, r)]) < b]
            if rs:
                pools.append('%s:%x-%x' % (s, min(rs), max(rs)))
        hidden = [m.U[i]['name'] for i in (a, b - 1) if m.U[i]['hidden']]
        first = m.U[a]['name'] + ('@in:' + m.U[a]['parent'] if m.U[a]['hidden'] else '')
        last = m.U[b - 1]['parent']
        evid = '; '.join(x for x in [nev, 'start[' + wa + ']', 'pools ' + ','.join(pools) if pools else '',
                                     'asm-object' if any(r[0] <= a <= r[1] or a <= r[0] < b for r in ev.odd_runs) else '']
                         if x)
        rows.append(('tu_%03d' % k, first, last, '0x%06X' % m.addr[a], '0x%06X' % m.U[b - 1]['end'],
                     name or 'unk_%06X' % m.addr[a], evid, conf))
    with open(args.out, 'w') as f:
        f.write('# tu_id\tfirst_func\tlast_func\tstart_addr\tend_addr\tname_guess\tevidence\tconfidence\n')
        f.write('# generated by tools/find_tus.py --gamma %g; see docs/TU.md. end_addr is exclusive '
                '(end of last function, before alignment padding). first_func "X@in:Y" = boundary inside '
                'funcs.txt function Y (missed function start X).\n' % args.gamma)
        for r in rows:
            f.write('\t'.join(r) + '\n')
    cnt = Counter(r[7] for r in rows)
    print('TUs', len(rows), dict(cnt), 'hidden starts', len(m.hidden), 'seps', len(ev.seps), 'nocut', len(ev.nocut))
    if args.debug:
        os.makedirs(args.debug, exist_ok=True)
        json.dump(dict(cuts=cuts, addr=m.addr, stab={str(g): sorted(v) for g, v in stab.items()},
                       seps=ev.seps, nocut=ev.nocut, anchors={k: sorted(v) for k, v in ev.anchors.items()},
                       hidden=m.hidden, kinds=ev.kinds), open(os.path.join(args.debug, 'tus.json'), 'w'))


if __name__ == '__main__':
    main()
