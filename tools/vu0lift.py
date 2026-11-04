#!/usr/bin/env python3
"""Classify and lift VU0/MMI leaf functions to C with whole-body inline asm (docs/ASM_POLICY.md, tier 2).

  tools/vu0lift.py --classify                 table of handwritten cop2/mmi functions by shape
  tools/vu0lift.py --emit NAME [NAME...]      print the lifted C for the functions
  tools/vu0lift.py --check [--unit U]         lift every eligible function of a unit, compile it in docker and
                                              compare .text bytes with the original

A function is "whole-asm eligible" when it is a straight-line leaf: no jal/jalr, no branches other than the final
`jr $ra`, no stack use.  The C wrapper declares a0-a3 (and f12-f14 when read) as inputs and writes the original
instructions with their real register names; gas fills the `jr $ra` delay slot exactly as the original did.
"""
import glob, os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

BRANCH = re.compile(r'^(b|beq|bne|beqz|bnez|bgez|bltz|blez|bgtz|bc[012][tf]l?|beql|bnel|bgezal|bltzal|j|jal|jalr)$')
SHAPES = ('leaf',)
# TUs where switching to the period assembler changes the size of their compiler-emitted functions
NO_DELAY_ASM = {'game/op/opp_2AC750'}
ARGS = ['a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3']


def handwritten():
    out = {}
    for l in open('config/handwritten.txt'):
        if l.startswith('#') or not l.strip():
            continue
        p = l.split()
        out[p[0]] = p[1]
    return out


def find(name):
    f = glob.glob(f'asm/nonmatchings/**/{name}.s', recursive=True)
    f = [x for x in f if '/rodata/' not in x]
    return f[0] if f else None


def parse(path):
    """-> (size, [(word, text)]) with labels kept as ('label', '.Lxxx')"""
    size = None
    ins = []
    for l in open(path):
        m = re.match(r'nonmatching \S+, (0x[0-9A-Fa-f]+)', l)
        if m:
            size = int(m.group(1), 16)
        m = re.match(r'\s*/\*\s*\S+\s+\S+\s+([0-9A-Fa-f]{8})\s*\*/\s*(.*)', l)
        if m:
            ins.append((m.group(1), m.group(2).strip()))
        elif re.match(r'\s*\.L\w+:', l):
            ins.append(('label', l.strip()))
    return size, ins


def mnem(t):
    return t.split()[0] if t else ''


SPECIAL = re.compile(r'^(lqc2|sqc2|qmfc2|qmtc2|cfc2|ctc2|v\w+|p[a-z0-9]+|mult1|multu1|div1|divu1|madd1|maddu1|mfhi1|mflo1|mthi1|mtlo1|qfsrv|mfsa|mtsa|syscall|mfc0|mtc0|eret|cache|tlb\w+|ei|di|sync|break)(\.\w+)*$')
# `p*` also matches ordinary mnemonics such as prefetch-free MIPS names; none exist in EE integer code (pref is excluded below)


def has_special(ins):
    for w, t in ins:
        if w == 'label' or not t:
            continue
        m = mnem(t)
        if m in ('pref',):
            continue
        if SPECIAL.match(m):
            return True
    return False


def shape(ins):
    body = [t for w, t in ins if w != 'label']
    ms = [mnem(t) for t in body]
    if any(m in ('jal', 'jalr') for m in ms):
        return 'call'
    if any('sp' in t.split(None, 1)[-1] and re.search(r'\$sp', t) for t in body):
        return 'stack'
    brs = [m for m in ms[:-2] if BRANCH.match(m)]
    if brs or any(w == 'label' for w, _ in ins):
        return 'branch'
    if not ms or ms[-1] == 'nop' and len(ms) < 2:
        return 'leaf'
    # last real instruction (ignoring a trailing nop pad) must be jr $ra with delay slot
    return 'leaf'


def lift_body(ins):
    """Instruction strings without the final jr $ra and its delay slot handling (gas redoes that)."""
    body = [t for w, t in ins if w != 'label']
    # find final jr $ra
    idx = [i for i, t in enumerate(body) if t.startswith('jr') and '$ra' in t]
    jr = idx[-1] if idx else None
    if jr is None:
        return None
    slot = body[jr + 1:jr + 2]    # the delay-slot instruction (may be nop); anything after is alignment padding
    pre = body[:jr]
    return pre + slot            # gas puts the last instruction back into the slot


def used_regs(lines):
    rd, wr = set(), set()
    for t in lines:
        m = mnem(t)
        ops = re.findall(r'\$(\w+)', t)
        for r in ops:
            pass
        # crude: dest is first operand for ALU/loads/mfc*, sources otherwise
    return rd, wr


def inputs_of(lines):
    """Registers read before written (args) in a straight-line body: -> (needed, written)."""
    written = set()
    needed = []
    STORE = {'sw', 'sh', 'sb', 'sd', 'sq', 'swc1', 'sqc2', 'swc2', 'sdc1', 'swl', 'swr', 'sdl', 'sdr', 'sdc2'}
    WR_FIRST = {'mfc1', 'qmfc2', 'qmfc2.ni', 'qmfc2.i', 'cfc2', 'mfc2', 'cfc1', 'mfhi', 'mflo', 'mfhi1', 'mflo1', 'mfsa'}
    RD_ONLY = {'mtc1', 'qmtc2', 'qmtc2.ni', 'qmtc2.i', 'ctc2', 'mtc2', 'mthi', 'mtlo', 'mthi1', 'mtlo1', 'mtsa', 'ctc1'}
    for t in lines:
        if t.endswith(':'):
            continue
        m = mnem(t)
        rest = t.split(None, 1)[1] if ' ' in t.strip() else ''
        ops = [o.strip() for o in re.split(r',(?![^()]*\))', rest)]
        def regs_in(o):
            return [r for r in re.findall(r'\$(\w+)', o) if not r.startswith('vf') and r != 'ACC']
        first = ops[0] if ops else ''
        reads, dst = [], []
        if m in STORE or m in RD_ONLY or BRANCH.match(m):
            for o in ops:
                reads += regs_in(o)
        elif m in WR_FIRST:
            dst = regs_in(first)
            for o in ops[1:]:
                reads += regs_in(o)
        else:
            dst = regs_in(first) if first.startswith('$') and not first.startswith('$vf') else []
            for o in ops[1:]:
                reads += regs_in(o)
            if dst == [] and first.startswith('$vf'):
                pass
        for r in reads:
            if r not in written and r not in needed and r != 'zero':
                needed.append(r)
        for r in dst:
            written.add(r)
    return needed, written


GPR = {'zero': 0, 'at': 1, 'v0': 2, 'v1': 3, 'a0': 4, 'a1': 5, 'a2': 6, 'a3': 7, 't0': 8, 't1': 9, 't2': 10, 't3': 11,
       't4': 12, 't5': 13, 't6': 14, 't7': 15, 's0': 16, 's1': 17, 's2': 18, 's3': 19, 's4': 20, 's5': 21, 's6': 22,
       's7': 23, 't8': 24, 't9': 25, 'k0': 26, 'k1': 27, 'gp': 28, 'sp': 29, 'fp': 30, 'ra': 31}


def numeric(t):
    return re.sub(r'\$([a-z]\w*)', lambda m: f'${GPR[m.group(1)]}' if m.group(1) in GPR else m.group(0), t)


def lift(name, ctype='void'):
    path = find(name)
    size, ins = parse(path)
    body = lift_body(ins)
    if body is None:
        return None
    need, written = inputs_of(body)
    ints = [r for r in need if r in ARGS]
    flts = [r for r in need if re.match(r'f\d+', r)]
    other = [r for r in need if r not in ARGS and not re.match(r'f\d+', r)]
    if other:
        return None
    params = []
    # a-registers in declared order a0..a3
    for r in ['a0', 'a1', 'a2', 'a3']:
        if r in ints:
            params.append(('u32', r))
    for r in ints:
        if r not in ('a0', 'a1', 'a2', 'a3'):
            return None
    for r in flts:
        params.append(('float', r))
    return name, params, body, written


def emit(name, proto=None):
    r = lift(name)
    if not r:
        return None
    name, params, body, written = r
    need, _ = inputs_of(body)
    ret = 'void'
    if proto:
        ret, params = proto
    isflt = lambda t: bool(re.match(r'(const )?(float|double)$', t.strip()))
    ps = ', '.join((f'{t} {n}' if n else t) for t, n in params) or 'void'
    NUM = {'v0': 2, 'v1': 3, 'a0': 4, 'a1': 5, 'a2': 6, 'a3': 7, 't0': 8, 't1': 9, 't2': 10, 't3': 11, 't4': 12, 't5': 13,
           't6': 14, 't7': 15, 't8': 24, 't9': 25}
    outs, ins_, covered = [], [], set()
    idx = 0
    for t, n in params:
        if isflt(t):
            continue
        reg = f'a{idx}'
        idx += 1
        if not n:
            continue
        if reg in written:
            outs.append(n)
            covered.add(reg)
        elif reg in need:
            ins_.append(n)
            covered.add(reg)
    clob = sorted(NUM[w] for w in written if w in NUM and w not in covered)
    s = f'{ret} {name}({ps})\n{{\n    __asm__ volatile(\n'
    ctrl = any(t.endswith(':') or BRANCH.match(mnem(t)) for t in body[:-1])
    lines = ['.set noreorder'] + body[:-1] + ['.set reorder'] + body[-1:] if ctrl else body
    for t in lines:
        s += f'        "{numeric(t).replace("%", "%%")}\\n"\n'
    o = ', '.join(f'"+r"({n})' for n in outs)
    i = ', '.join(f'"r"({n})' for n in ins_)
    s += f'        : {o} : {i}' + (' : ' + ', '.join(f'"${c}"' for c in clob) if clob else '') + ');\n}\n'
    return s


def classify():
    hw = handwritten()
    rows = []
    for k, v in hw.items():
        if 'cop2' not in v and 'mmi' not in v:
            continue
        p = find(k)
        if not p:
            continue
        size, ins = parse(p)
        rows.append((k, v, shape(ins), len(ins), p))
    from collections import Counter
    c = Counter((r[2]) for r in rows)
    s = Counter()
    for r in rows:
        s[r[2]] += r[3]
    print(len(rows), dict(c), dict(s))
    return rows


if __name__ == '__main__':
    a = sys.argv[1:]
    if a and a[0] == '--classify':
        classify()
    elif a and a[0] == '--emit':
        for n in a[1:]:
            print(emit(n) or f'// {n}: not liftable')


def words_masked(path):
    """original bytes with the 16-bit immediate zeroed where the instruction carries a %hi/%lo/symbol operand"""
    size, ins = parse(path)
    out = b''
    for w, t in ins:
        if w == 'label':
            continue
        b = bytearray(bytes.fromhex(w))
        if re.search(r'%(hi|lo|gp_rel)\(|D_[0-9A-Fa-f]{8}', t):
            b[0] = b[1] = 0
        out += bytes(b)
    return size, out


def words(path):
    size, ins = parse(path)
    return size, bytes.fromhex(''.join(bytes.fromhex(w)[::-1].hex() if False else w for w, _ in ins if w != 'label')) if False else b''.join(bytes.fromhex(w) for w, _ in ins if w != 'label')


def check(names, extra='-Btools/cc/ee-as-delay/'):
    """Compile the lifted wrappers and compare bytes with the original encoding; functions that do not even
    assemble are dropped (reported in `bad`)."""
    os.makedirs('build/vu0lift', exist_ok=True)
    names = list(names)
    dropped = []
    while True:
        chunks = [emit(n) for n in names]
        src = '#include "common.h"\n\n'
        starts = {}
        for n, c in zip(names, chunks):
            starts[n] = src.count('\n') + 1
            src += c + '\n'
        for f in ('t.o', 't.bin', 'syms.txt'):
            if os.path.exists('build/vu0lift/' + f):
                os.remove('build/vu0lift/' + f)
        open('build/vu0lift/t.c', 'w').write(src)
        cmd = (f'tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc -c -O2 -G0 -g0 {extra} -Iinclude build/vu0lift/t.c -o build/vu0lift/t.o 2>build/vu0lift/err.txt; '
               'mipsel-linux-gnu-nm -n -S build/vu0lift/t.o 2>/dev/null | grep " T " | grep -v NON_MATCHING > build/vu0lift/syms.txt; '
               'mipsel-linux-gnu-objcopy -O binary -j .text build/vu0lift/t.o build/vu0lift/t.bin 2>/dev/null')
        subprocess.run(['docker', 'run', '--rm', '-v', f'{ROOT}:/work', '-w', '/work', 'ffx-decomp', 'sh', '-c', cmd],
                       capture_output=True, text=True)
        out = ''
        if os.path.exists('build/vu0lift/t.bin'):
            break
        err = open('build/vu0lift/err.txt').read()
        lines = sorted({int(m) for m in re.findall(r't\.c:(\d+):', err)})
        # also assembler errors have no line: fall back to bisection by halves
        bad_fn = set()
        order = sorted(starts, key=starts.get)
        for ln in lines:
            owner = [n for n in order if starts[n] <= ln]
            if owner:
                bad_fn.add(owner[-1])
        if not bad_fn:
            # assembler error: find culprit by compiling each function alone
            for n in names:
                open('build/vu0lift/one.c', 'w').write('#include "common.h"\n\n' + emit(n))
                r = subprocess.run(['docker', 'run', '--rm', '-v', f'{ROOT}:/work', '-w', '/work', 'ffx-decomp', 'sh', '-c',
                                    f'tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc -c -O2 -G0 -g0 {extra} -Iinclude build/vu0lift/one.c -o build/vu0lift/one.o 2>&1 | grep -c "Error"'],
                                   capture_output=True, text=True)
                if r.stdout.strip() not in ('0', ''):
                    bad_fn.add(n)
            if not bad_fn:
                raise SystemExit('cannot isolate compile failure:\n' + err[:800])
        dropped += sorted(bad_fn)
        names = [n for n in names if n not in bad_fn]
    syms = [l.split() for l in open('build/vu0lift/syms.txt')]
    blob = open('build/vu0lift/t.bin', 'rb').read()
    pos = {s_[3]: (int(s_[0], 16), int(s_[1], 16)) for s_ in syms}
    ok, bad = [], []
    for n, (a_, sz) in pos.items():
        osz, _ = parse(find(n))[0], None
        orig = words_masked(find(n))[1]
        got = blob[a_:a_ + sz]
        # exact function size (the INCLUDE_ASM header carries it) and identical bytes; trailing alignment pad is ignored
        (ok if sz == osz and got == orig[:sz] else bad).append(n)
    bad += dropped
    return ok, bad, out


if __name__ == '__main__' and a and a[0] == '--check':
    hw = handwritten()
    unit = a[a.index('--unit') + 1] if '--unit' in a else None
    cands = []
    for k, v in sorted(hw.items()):
        if not any(c in v for c in ('cop2', 'mmi', 'syscall', 'cop0')):
            continue
        p = find(k)
        if not p or (unit and unit not in p):
            continue
        if shape(parse(p)[1]) not in SHAPES or lift(k) is None or not has_special(parse(p)[1]):
            continue
        cands.append(k)
    ok2, bad2, out2 = check(cands, '')
    ok, bad, out = check(cands, '-Btools/cc/ee-as-delay/')
    print(f'{len(cands)} candidates; ee-as-delay: {len(ok)} match; stock gas: {len(ok2)} match {out}{out2}')
    only = [n for n in ok if n not in ok2]
    print('  need ee-as-delay:', len(only))
    for n in bad:
        print('  differ', n)


def firstdiff(n, blob_path='build/vu0lift/t.bin', sym_path='build/vu0lift/syms.txt'):
    syms = [l.split() for l in open(sym_path)]
    blob = open(blob_path, 'rb').read()
    pos = {s[3]: int(s[0], 16) for s in syms}
    order = sorted(pos, key=pos.get)
    i = order.index(n)
    a = pos[n]
    b = pos[order[i + 1]] if i + 1 < len(order) else len(blob)
    orig = words_masked(find(n))[1]
    got = blob[a:b]
    for k in range(0, max(len(orig), len(got)), 4):
        o, g = orig[k:k + 4], got[k:k + 4]
        if o != g:
            return f'{n}: +{k:#x} orig={o[::-1].hex()} ours={g[::-1].hex()} (orig {len(orig)}B ours {len(got)}B)'
    return f'{n}: identical?'


if __name__ == '__main__' and a and a[0] == '--diff':
    for n in a[1:]:
        print(firstdiff(n))


# ---------------------------------------------------------------------------------------------- apply
def include_closure(src):
    seen, todo, out = set(), [src], []
    while todo:
        f = todo.pop()
        if f in seen or not os.path.exists(f):
            continue
        seen.add(f)
        out.append(f)
        for m in re.finditer(r'#include\s+"([^"]+)"', open(f).read()):
            for base in ('include', os.path.dirname(f)):
                c = os.path.join(base, m.group(1))
                if os.path.exists(c):
                    todo.append(c)
                    break
    return out


def _split_top(s_):
    out, depth, cur = [], 0, ''
    for ch in s_:
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur)
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [x.strip() for x in out]


def header_proto(name, closure):
    """(ret, [(type, name)]) from a prototype of `name` in the headers the TU includes, else None.
    A parameter that is not a plain `type name` (function pointers) keeps its full declarator as the 'type'
    and an empty name; the caller then never uses it as an asm operand."""
    for f in closure:
        if not f.endswith('.h'):
            continue
        t = open(f).read()
        m = re.search(r'^([A-Za-z_][\w \*]*?)\b' + re.escape(name) + r'\s*\(', t, re.M)
        if not m:
            continue
        i = m.end()
        depth, j = 1, i
        while j < len(t) and depth:
            depth += {'(': 1, ')': -1}.get(t[j], 0)
            j += 1
        if not t[j:].lstrip().startswith(';'):
            continue
        ret = re.sub(r'^(extern|static)\s+', '', m.group(1).strip())
        plist = _split_top(t[i:j - 1])
        if plist == ['void']:
            plist = []
        ps = []
        for k, x in enumerate(plist):
            if '(' in x:                           # function pointer: keep verbatim, never an operand
                ps.append((x, ''))
                continue
            mm = re.match(r'(.*?)(\b[A-Za-z_]\w*)$', x)
            if mm and mm.group(1).strip() and mm.group(1).strip() not in ('unsigned', 'signed', 'struct', 'const'):
                ps.append((mm.group(1).strip(), mm.group(2)))
            else:
                ps.append((x, f'p{k}'))
        return ret, ps
    return None


def apply(names, tu_delay):
    by_src = {}
    U = {l.split('\t')[0]: int(l.split('\t')[1], 16) for l in open('config/units.txt') if l.count('\t') >= 3 and not l.startswith('#')}
    for n in names:
        for f in glob.glob('src/**/*.c', recursive=True):
            if U.get(f[4:-2], 0) % 8:
                continue
            if f[4:-2] in NO_DELAY_ASM and n in tu_delay:
                continue
            t = open(f).read()
            if re.search(r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(n) + r'\)\s*;', t):
                by_src.setdefault(f, []).append(n)
                break
    done = []
    for f, ns in by_src.items():
        t = open(f).read()
        clo = include_closure(f)
        for n in ns:
            hp = header_proto(n, clo)
            c = emit(n, hp)
            if hp and hp[0] not in ('void',) and re.search(r'\bv0\b|\$2\b', c) and False:
                pass
            t = re.sub(r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(n) + r'\)\s*;', lambda m: c.rstrip('\n'), t, count=1)
            done.append(n)
        open(f, 'w').write(t)
    return by_src


if __name__ == '__main__' and a and a[0] == '--apply':
    hw = handwritten()
    cands = []
    for k, v in sorted(hw.items()):
        if not any(c in v for c in ('cop2', 'mmi', 'syscall', 'cop0')):
            continue
        p = find(k)
        if not p or shape(parse(p)[1]) not in SHAPES or lift(k) is None or not has_special(parse(p)[1]):
            continue
        cands.append(k)
    ok2, _, _ = check(cands, '')
    ok, bad, _ = check(cands, '-Btools/cc/ee-as-delay/')
    use = ok
    need_delay = [n for n in ok if n not in ok2]
    srcs = apply(use, need_delay)
    have = open('config/cflags.txt').read().split('\n')
    add = ''
    for f, ns in srcs.items():
        k = f[4:-2]
        if any(n in need_delay for n in ns) and not any(l.startswith(k + ' ') for l in have):
            add += f'{k} -Btools/cc/ee-as-delay/\n'
    if add:
        open('config/cflags.txt', 'a').write('# Period assembler: fills the jr $ra delay slot of whole-function VU0/MMI inline-asm blocks (tools/vu0lift.py).\n' + add)
    print(f'applied {len(use)} functions in {len(srcs)} files')
    for f, ns in srcs.items():
        nd = [n for n in ns if n in need_delay]
        print(f'  {f}: {len(ns)} funcs' + (f' (needs ee-as-delay: {len(nd)})' if nd else ''))


if __name__ == '__main__' and a and a[0] == '--misclass':
    hw = handwritten()
    mis = [k for k, v in sorted(hw.items()) if ('mmi' in v or 'cop2' in v) and find(k) and not has_special(parse(find(k))[1])]
    print(len(mis), 'listed cop2/mmi but no special instruction:')
    for k in mis:
        print(' ', k, hw[k])
