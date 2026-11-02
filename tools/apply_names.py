#!/usr/bin/env python3
"""Apply the real names of config/names_map.tsv / config/names_data.tsv to the tree, reversibly.

usage: python3 -P tools/apply_names.py --plan                      candidates and skip reasons
       python3 -P tools/apply_names.py --apply [--dir P ...] [--funcs] [--data] [--only A,B] [--dry-run]
       python3 -P tools/apply_names.py --revert [--dir P ...] [--only A,B] [--dry-run]
       python3 -P tools/apply_names.py --check                     consistency of the applied names

A name is applied by a global, purely textual rename of the splat name (`func_XXXXXXXX`,
`D_XXXXXXXX`) wherever it occurs, also inside longer identifiers (`CALL_func_X`, `q1_func_X`,
`func_X_int` become `CALL_<name>`, `q1_<name>`, `<name>_int`) and strings (`__asm__("func_X")`):
src/**/*.c, include/**, asm/**/*.s, build/ee_asm/**/*.s, the config files in CONFIG below; the
function's .s file in asm/nonmatchings/<unit>/ and build/ee_asm/<unit>/ is renamed to <name>.s.
`config/funcs.txt` keeps the address (`<name> <addr> <size>`), so `symbol_addrs.txt` (`tools/gen_chunks.py`)
carries the names for a splat re-run. Every applied name is recorded in `config/names_applied.tsv`
(`addr old new kind unit`); `--revert` renames back and drops the rows. The source tables
(`names_map.tsv`, `names_data.tsv`, `name_prefix_ranges.tsv`) are not modified.

Selection (docs/NAMES.md, "Applied names"): confidence high only; functions of `game/` units only
(not sdk/ units, not crt0); no `sce*` names; the real name must be a valid C identifier, not a C
keyword, not a libc/gcc builtin or gcc "special" name, unique among all rows of both tables
(DUPNAME), not marked CONFLICT, unique case-insensitively (file names on macOS), and must not
already occur as an identifier in the code (comments and strings excluded) or in the asm/config.
Data names additionally need a symbol definition (asm dlabel or linker-script fallback) and no use
of their raw address in src/include. Skips are written to config/names_skipped.tsv.
"""
import collections, glob, os, re, sys

sys.path.append(os.path.dirname(os.path.abspath(__file__)))   # append: tools/dis.py must not shadow `dis`
from ffxsyms import SPLAT, segments, scoped_sub   # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
P = lambda *a: os.path.join(ROOT, *a)
APPLIED = P("config/names_applied.tsv")
SKIPPED = P("config/names_skipped.tsv")
# config files in the rename scope. Not renamed: the name tables (names_map/names_data/
# name_prefix_ranges.tsv) and provenance notes in units.txt, unit_splits.tsv, modules.tsv.
CONFIG = ["funcs.txt", "symbol_addrs.txt", "undefined_funcs_auto.txt", "undefined_syms_auto.txt",
          "handwritten.txt", "symbols_extra.txt", "tu_map.tsv", "rodata_layout.txt", "cflags.txt",
          "SCES_504.90.link.ld.in", "SCES_504.90.link.ld"]
ASM_STR = re.compile(r'"(?:\\.|[^"\\\n])*"')
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
GAME_END = 0x2DDA00

C_KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register restrict return short signed sizeof static struct switch typedef union unsigned
void volatile while asm typeof __asm__ __attribute__ __inline__ __typeof__ __extension__ __const__
__volatile__ __signed__ __label__ __alignof__ _Bool _Complex""".split())
# names gcc 2.9 treats specially (builtins, special_function_p after stripping `_`/`__`), libc/libm
# functions it may call or inline by name, and identifiers of the build itself
RESERVED = set("""main abort exit _exit atexit alloca setjmp longjmp sigsetjmp siglongjmp savectx vfork fork
getcontext qsetjmp abs labs fabs fabsf sqrt sqrtf sin sinf cos cosf tan tanf atan atanf atan2 atan2f
exp log pow floor ceil fmod frexp ldexp modf memcpy memmove memset memcmp memchr bcopy bzero bcmp
strcpy strncpy strcat strncat strcmp strncmp strlen strchr strrchr strstr strtok index rindex ffs
printf sprintf vsprintf snprintf vsnprintf fprintf vfprintf puts putchar fputs fputc fwrite fread
fopen fclose malloc calloc realloc free rand srand atoi atol strtol strtoul qsort bsearch toupper
tolower isdigit isalpha isspace isupper islower isprint isxdigit isalnum ispunct iscntrl assert
open close read write lseek ioctl time clock getchar gets scanf sscanf errno _gp _end _ftext _fdata
end etext edata zero nop move sync""".split())


# ---------------------------------------------------------------------------------------------
def rows(path):
    out = []
    for l in open(path):
        if l.startswith("#") or l.startswith("ps2_symbol") or not l.strip():
            continue
        f = l.rstrip("\n").split("\t")
        out.append(dict(sym=f[0], name=f[1], source=f[2], method=f[3], conf=f[4], notes=f[5] if len(f) > 5 else ""))
    return out


def load_units():
    us = []
    for l in open(P("config/units.txt")):
        if l.startswith("#") or not l.strip():
            continue
        f = l.rstrip("\n").split("\t")
        us.append((int(f[1], 16), int(f[2], 16), f[0], f[3]))
    return us


def unit_of(units, a):
    for lo, hi, n, k in units:
        if lo <= a < hi:
            return n, k
    return None, None


def strip_c(text):
    """C text without comments and string/char literals (identifiers only)"""
    return re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'',
                  lambda m: " " if m.group(0)[0] in "/" else '""', text, flags=re.S)


def tree_files():
    """every file in the rename scope"""
    fs = glob.glob(P("src/**/*.c"), recursive=True) + glob.glob(P("include/**/*"), recursive=True)
    fs += glob.glob(P("asm/**/*.s"), recursive=True) + glob.glob(P("build/ee_asm/**/*.s"), recursive=True)
    fs += [P("config", c) for c in CONFIG]
    return [f for f in fs if os.path.isfile(f)]


def parts(tok):
    """the `_`-bounded pieces of an identifier that the reverse rename could match:
    Sg_Init_x -> Sg, Sg_Init, Sg_Init_x, Init, Init_x, x, _Init, _Init_x, _x"""
    out = {tok}
    ps = tok.split("_")
    for i in range(len(ps)):
        for j in range(i + 1, len(ps) + 1):
            s = "_".join(ps[i:j])
            if s:
                out.add(s)
                if i:
                    out.add("_" + s)
    return out


def corpus_tokens():
    """(identifiers of the code in the rename scope: C/asm without comments and strings, config files;
        `_`-bounded parts of every identifier anywhere in the rename scope, comments and C strings included)"""
    code, raw = set(), set()
    for f in tree_files():
        if "/build/ee_asm/" in f:
            continue
        t = "".join(x for ok, x in segments(f, open(f, errors="replace").read()) if ok)
        raw.update(re.findall(r"[A-Za-z_]\w*", t))
        if f.endswith((".c", ".h", ".s", ".inc")):
            t = strip_c(t)
        code.update(re.findall(r"[A-Za-z_]\w*", t))
    allp = set()
    for tok in raw:
        allp |= parts(tok)
    return code, allp


# ---------------------------------------------------------------------------------------------
def plan(verbose=True):
    """-> (candidates [dict sym name addr kind unit], skipped [(sym, name, conf, reason)])"""
    funcs = {}
    for l in open(P("config/funcs.txt")):
        n, a, s = l.split()
        funcs[n] = int(a, 16)
    applied = {r["old"]: r for r in load_applied()}
    applied_new = {r["new"] for r in applied.values()}
    units = load_units()
    fr, dr = rows(P("config/names_map.tsv")), rows(P("config/names_data.tsv"))
    # one name per symbol; a symbol listed twice with the same name is one row
    seen, uniq = {}, []
    for kind, rs in (("func", fr), ("data", dr)):
        for r in rs:
            r["kind"] = kind
            k = (r["sym"], r["name"])
            if k in seen:
                continue
            seen[k] = r; uniq.append(r)
    names_of_sym = collections.defaultdict(set)
    syms_of_name = collections.defaultdict(set)
    syms_of_lower = collections.defaultdict(set)
    for r in uniq:
        names_of_sym[r["sym"]].add(r["name"])
        syms_of_name[r["name"]].add(r["sym"])
        syms_of_lower[r["name"].lower()].add(r["sym"])
    toks, allparts = corpus_tokens()
    lower_toks = collections.defaultdict(set)
    for t in toks:
        lower_toks[t.lower()].add(t)
    data_defs = set()
    for f in glob.glob(P("asm/data/**/*.s"), recursive=True):
        data_defs.update(re.findall(r"^\s*dlabel (\w+)", open(f).read(), re.M))
    for l in open(P("config/undefined_syms_auto.txt")):
        if " = " in l:
            data_defs.add(l.split(" = ")[0].strip())
    csrc = "".join(open(f).read() for f in glob.glob(P("src/**/*.c"), recursive=True) + glob.glob(P("include/**/*.h"), recursive=True))

    cands, skipped = [], []
    for r in uniq:
        sym, name, kind = r["sym"], r["name"], r["kind"]
        addr = int(sym.split("_")[1], 16)
        unit, ukind = unit_of(units, addr)

        def skip(reason):
            skipped.append((sym, name, r["conf"], kind, reason))
        if sym in applied and applied[sym]["new"] == name:
            cands.append(dict(sym=sym, name=name, addr=addr, kind=kind, unit=applied[sym]["unit"], done=True))
            continue
        if r["conf"] != "high":
            skip(f"confidence-{r['conf']}"); continue
        if kind == "func":
            if sym not in funcs:
                skip("not-in-funcs.txt"); continue
            if addr < 0x1008D8:
                # asm/text.s (crt0 and the syscall stubs, one splat blob): only the game functions
                # that it also holds (Ch_Model*: symbols of undefined_funcs_auto.txt, called from C)
                if addr < 0x100420:
                    skip("crt0"); continue
                unit = "asm/text"
            elif addr >= GAME_END or not unit or not unit.startswith("game/"):
                skip("sdk-region"); continue
        if not IDENT.match(name):
            skip("invalid-identifier"); continue
        if name in C_KEYWORDS:
            skip("c-keyword"); continue
        if name in RESERVED or name.lstrip("_") in RESERVED or name.startswith("__builtin") or name.startswith("__"):
            skip("reserved-or-builtin"); continue
        if len(name) < 3 or SPLAT.fullmatch(name) or re.match(r"^(?:func|D|jtbl|piece|L)_[0-9A-Fa-f]+$", name):
            skip("reserved-or-builtin"); continue
        if name.lower().startswith("sce"):
            skip("sdk-name"); continue
        if re.match(r"FFX(?:Vu0|Samp0)", name):
            # Switch names of the VU0 helpers before libpad; on the PS2 they are probably Sony libvu0
            # code (sceVu0*/sceSamp0*) that the port renamed (docs/NAMES.md): ambiguous
            skip("sdk-renamed"); continue
        if "CONFLICT" in r["notes"] or "DUPNAME" in r["notes"]:
            skip("conflict"); continue
        if len(names_of_sym[sym]) > 1:
            skip("conflict"); continue
        if len(syms_of_name[name]) > 1:
            skip("duplicate-name"); continue
        if len(syms_of_lower[name.lower()]) > 1 or name.lower() in ("rodata",):
            skip("case-collision"); continue
        if name in toks:
            skip("collision"); continue
        if name in allparts:
            # only in a comment, or as part of a longer identifier: a --revert could not tell it apart
            skip("collision-comment-or-part"); continue
        if lower_toks.get(name.lower(), set()) - {name}:
            skip("case-collision"); continue
        if kind == "data":
            if sym not in data_defs:
                skip("data-no-symbol"); continue
            lo = f"{addr:x}".lstrip("0")
            if re.search(rf"0x0*{lo}\b", csrc, re.I):
                skip("data-raw-address"); continue
            # data does not live in a unit; the owner column is the section
            unit = "data" if addr < 0x568F00 else "rodata" if addr < 0x57C680 else "lit4" if addr < 0x57CB80 else "bss"
        cands.append(dict(sym=sym, name=name, addr=addr, kind=kind, unit=unit, done=False))
    if verbose:
        c = collections.Counter(s[4] for s in skipped)
        hi = [s for s in skipped if s[2] == "high"]
        print(f"rows: {len(uniq)} ({sum(1 for r in uniq if r['kind']=='func')} func, {sum(1 for r in uniq if r['kind']=='data')} data)")
        print(f"candidates: {len(cands)} ({sum(1 for x in cands if x['kind']=='func')} func, "
              f"{sum(1 for x in cands if x['kind']=='data')} data), already applied {sum(1 for x in cands if x['done'])}")
        print("skipped: " + ", ".join(f"{k}={v}" for k, v in c.most_common()))
        print("skipped high rows: " + ", ".join(f"{k}={v}" for k, v in collections.Counter(s[4] for s in hi).most_common()))
    return cands, skipped


def load_applied():
    if not os.path.exists(APPLIED):
        return []
    out = []
    for l in open(APPLIED):
        if l.startswith("#") or not l.strip():
            continue
        f = l.rstrip("\n").split("\t")
        out.append(dict(addr=int(f[0], 16), old=f[1], new=f[2], kind=f[3], unit=f[4]))
    return out


def write_applied(rs):
    rs = sorted(rs, key=lambda r: (r["kind"] != "func", r["addr"]))
    with open(APPLIED, "w") as f:
        f.write("# Real names applied to the tree by tools/apply_names.py (docs/NAMES.md, \"Applied names\").\n"
                "# addr\told (splat name)\tnew (real name)\tkind (func|data)\tunit (config/units.txt; data: section)\n")
        for r in rs:
            f.write(f"0x{r['addr']:08X}\t{r['old']}\t{r['new']}\t{r['kind']}\t{r['unit']}\n")


# ---------------------------------------------------------------------------------------------
def rename(mapping, dry=False):
    """global textual rename splat name -> real name (also inside longer identifiers and strings)"""
    if not mapping:
        return 0, 0
    nfiles = nren = 0
    for f in tree_files():
        try:
            t = open(f).read()
        except UnicodeDecodeError:
            continue
        if "func_" not in t and "D_" not in t:
            continue
        t2 = scoped_sub(f, t, lambda s: SPLAT.sub(lambda m: mapping.get(m.group(1), m.group(1)), s))
        if t2 != t:
            nfiles += 1
            if not dry:
                open(f, "w").write(t2)
    for base in (P("asm/nonmatchings"), P("build/ee_asm")):
        for f in glob.glob(os.path.join(base, "**", "*.s"), recursive=True):
            n = os.path.basename(f)[:-2]
            if n in mapping:
                g = os.path.join(os.path.dirname(f), mapping[n] + ".s")
                if os.path.exists(g):
                    raise SystemExit(f"apply_names: {g} exists")
                nren += 1
                if not dry:
                    os.rename(f, g)
    return nfiles, nren


def injective(mapping):
    """the rename must not merge two identifiers: every token of the scope that contains a renamed
    splat name (CALL_func_X, func_X_int, ...) must map to a token that does not exist yet"""
    toks = set()
    for f in tree_files():
        if "/build/ee_asm/" in f:
            continue
        toks.update(re.findall(r"[A-Za-z_]\w*", "".join(x for ok, x in segments(f, open(f, errors="replace").read()) if ok)))
    img = collections.defaultdict(set)
    for tok in toks:
        img[SPLAT.sub(lambda m: mapping.get(m.group(1), m.group(1)), tok)].add(tok)
    bad = {k: v for k, v in img.items() if len(v) > 1}
    if bad:
        raise SystemExit(f"apply_names: rename would merge identifiers: {list(bad.items())[:5]}")


def regen_symbol_addrs():
    import subprocess
    subprocess.run([sys.executable, "-P", "tools/gen_chunks.py"], cwd=ROOT, check=True, stdout=subprocess.DEVNULL)


def reverse_rename(mapping, dry=False):
    """real name -> splat name: identifiers that contain the real name as a whole `_`-separated part"""
    if not mapping:
        return 0, 0
    keys = sorted(mapping, key=len, reverse=True)
    rx = re.compile(r"(?<![A-Za-z0-9])(" + "|".join(map(re.escape, keys)) + r")(?![A-Za-z0-9])")
    nfiles = nren = 0
    for f in tree_files():
        try:
            t = open(f).read()
        except UnicodeDecodeError:
            continue
        t2 = scoped_sub(f, t, lambda s: rx.sub(lambda m: mapping[m.group(1)], s))
        if t2 != t:
            nfiles += 1
            if not dry:
                open(f, "w").write(t2)
    for base in (P("asm/nonmatchings"), P("build/ee_asm")):
        for f in glob.glob(os.path.join(base, "**", "*.s"), recursive=True):
            n = os.path.basename(f)[:-2]
            if n in mapping:
                nren += 1
                if not dry:
                    os.rename(f, os.path.join(os.path.dirname(f), mapping[n] + ".s"))
    return nfiles, nren


def args_list(opt):
    out = []
    for i, a in enumerate(sys.argv):
        if a == opt:
            j = i + 1
            while j < len(sys.argv) and not sys.argv[j].startswith("--"):
                out.append(sys.argv[j]); j += 1
    return out


def select(items, unit_key):
    dirs = args_list("--dir")
    only = set(",".join(args_list("--only")).split(",")) - {""}
    out = []
    for x in items:
        if dirs and not any(x[unit_key] == d or x[unit_key].startswith(d.rstrip("/") + "/") for d in dirs):
            continue
        if only and not ({x.get("sym"), x.get("name"), x.get("old"), x.get("new")} & only):
            continue
        out.append(x)
    return out


def check():
    """every applied row: the new name is used, the old one is gone, funcs.txt has the address"""
    rs = load_applied()
    funcs = {l.split()[0]: int(l.split()[1], 16) for l in open(P("config/funcs.txt"))}
    bad = 0
    old = {r["old"] for r in rs}
    left = collections.Counter()
    for f in tree_files():
        try:
            t = open(f).read()
        except UnicodeDecodeError:
            continue
        for ok, x in segments(f, t):
            for m in SPLAT.finditer(x) if ok else ():
                if m.group(1) in old:
                    left[m.group(1)] += 1
    for r in rs:
        if r["kind"] == "func" and funcs.get(r["new"]) != r["addr"]:
            print(f"{r['new']}: not in funcs.txt at {r['addr']:#x}"); bad += 1
        if left[r["old"]]:
            print(f"{r['old']}: still used {left[r['old']]}x"); bad += 1
    names = [r["new"] for r in rs]
    for n, c in collections.Counter(x.lower() for x in names).items():
        if c > 1:
            print(f"{n}: applied {c}x (case-insensitive)"); bad += 1
    print(f"{len(rs)} applied names ({sum(r['kind']=='func' for r in rs)} func, {sum(r['kind']=='data' for r in rs)} data), {bad} problems")
    return bad


def main():
    dry = "--dry-run" in sys.argv
    if "--plan" in sys.argv:
        cands, skipped = plan()
        with open(SKIPPED, "w") as f:
            f.write("# Rows of names_map.tsv / names_data.tsv that tools/apply_names.py does not apply (docs/NAMES.md).\n"
                    "# ps2_symbol\treal_name\tconfidence\tkind\treason\n")
            for s in sorted(skipped, key=lambda s: (s[3], s[0])):
                f.write("\t".join(s) + "\n")
        by = collections.Counter(x["unit"].rsplit("/", 1)[0] if x["kind"] == "func" else "(data)" for x in cands if not x["done"])
        for k, v in sorted(by.items()):
            print(f"  {k:24s} {v}")
        return
    if "--apply" in sys.argv:
        cands, _ = plan(verbose=False)
        kinds = {k for k in ("func", "data") if f"--{k}s" in sys.argv or (k == "data" and "--data" in sys.argv)} or {"func", "data"}
        todo = [x for x in select([x for x in cands if not x["done"] and x["kind"] in kinds], "unit")]
        mapping = {x["sym"]: x["name"] for x in todo}
        injective(mapping)
        nf, nr = rename(mapping, dry)
        print(f"apply: {len(mapping)} names, {nf} files rewritten, {nr} asm files renamed" + (" (dry run)" if dry else ""))
        if not dry and todo:
            write_applied(load_applied() + [dict(addr=x["addr"], old=x["sym"], new=x["name"], kind=x["kind"], unit=x["unit"]) for x in todo])
            regen_symbol_addrs()
        return
    if "--revert" in sys.argv:
        rs = load_applied()
        todo = select(rs, "unit")
        mapping = {r["new"]: r["old"] for r in todo}
        nf, nr = reverse_rename(mapping, dry)
        print(f"revert: {len(mapping)} names, {nf} files rewritten, {nr} asm files renamed" + (" (dry run)" if dry else ""))
        if not dry:
            gone = {r["new"] for r in todo}
            write_applied([r for r in rs if r["new"] not in gone])
            regen_symbol_addrs()
        return
    if "--check" in sys.argv:
        sys.exit(1 if check() else 0)
    print(__doc__)


if __name__ == "__main__":
    main()
