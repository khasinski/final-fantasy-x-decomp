"""Symbol names <-> addresses for the tools (functions and data, splat names and real names).

Function names are the first column of config/funcs.txt: `func_XXXXXXXX` (splat's address name) or a
real name from the HD ports that tools/apply_names.py applied (config/names_applied.tsv records
`addr old new kind unit`). A tool must never parse an address out of a name; it asks this module:

    import os, sys; sys.path.append(os.path.dirname(os.path.abspath(__file__)))   # append, not insert:
    import ffxsyms                                    # tools/dis.py must not shadow the stdlib `dis`
    S = ffxsyms.Syms(root)
    S.addr("Ch_ArcMapping") == S.addr("func_00100F10") == 0x100F10
    S.name(0x100F10) == "Ch_ArcMapping"                 # the current funcs.txt name
    S.cur("func_00100F10") == "Ch_ArcMapping"           # old or new name -> current name
    S.is_func("Ch_ArcMapping"); S.funcs                 # [(name, addr, size)] in funcs.txt order
    S.asm_files("asm/nonmatchings")                   # current function name -> .s path

Names that are neither in funcs.txt nor in names_applied.tsv fall back to splat's address naming
(`func_`, `D_`, `jtbl_`, `piece_` + hex), so unapplied data symbols keep working.
"""
import glob, os, re

ADDR_NAME = re.compile(r"^(?:func|D|jtbl|piece)_([0-9A-Fa-f]{1,8})$")
# a splat name, also inside a longer identifier (CALL_func_X, q1_func_X, func_X_int) or a string
SPLAT = re.compile(r"(?<![A-Za-z0-9])((?:func|D)_[0-9A-F]{8})(?![0-9A-Fa-f])")


def segments(path, text):
    """[(renamable, piece)] whose concatenation is text: the parts of a file that the name rename
    (tools/apply_names.py) touches. Not renamable: asm string literals (game data), the provenance
    comment in line 1 of a unit file (`/* tu_NNN ... (config/tu_map.tsv) */`, a copy of the
    units.txt note), and every tu_map.tsv column except first_func/last_func."""
    if path.endswith(".s"):
        return [(i % 2 == 0, x) for i, x in enumerate(re.split(r'("(?:\\.|[^"\\\n])*")', text))]
    if path.endswith(".c") and text.startswith("/* tu_"):
        k = text.find("\n") + 1 or len(text)
        return [(False, text[:k]), (True, text[k:])]
    if path.endswith("tu_map.tsv"):
        out = []
        for l in text.splitlines(True):
            f = l.split("\t")
            if l.startswith("#") or len(f) < 3:
                out.append((False, l)); continue
            out += [(False, f[0] + "\t"), (True, f[1]), (False, "\t"), (True, f[2]), (False, "\t" + "\t".join(f[3:]))]
        return out
    return [(True, text)]


def scoped_sub(path, text, fn):
    """text with fn applied to its renamable segments"""
    return "".join(fn(x) if ok else x for ok, x in segments(path, text))


def rename_text(path, text, old2new):
    """apply the splat -> real name mapping to the text of a file of the tree (path decides the scope);
    used to bring files written against older names (workspaces, patches) up to date"""
    if not old2new:
        return text
    return scoped_sub(path, text, lambda s: SPLAT.sub(lambda m: old2new.get(m.group(1), m.group(1)), s))


def load_applied(root="."):
    """config/names_applied.tsv rows as dicts (addr int, old, new, kind, unit); [] if absent"""
    p = os.path.join(root, "config/names_applied.tsv")
    out = []
    if os.path.exists(p):
        for l in open(p):
            if l.startswith("#") or not l.strip():
                continue
            f = l.rstrip("\n").split("\t")
            out.append(dict(addr=int(f[0], 16), old=f[1], new=f[2], kind=f[3] if len(f) > 3 else "func",
                            unit=f[4] if len(f) > 4 else ""))
    return out


class Syms:
    def __init__(self, root="."):
        self.root = root
        self.funcs = []
        for l in open(os.path.join(root, "config/funcs.txt")):
            n, a, s = l.split()
            self.funcs.append((n, int(a, 16), int(s, 16)))
        self.by_name = {n: a for n, a, _ in self.funcs}
        self.size = {n: s for n, _, s in self.funcs}
        self.by_addr = {}
        for n, a, _ in self.funcs:
            self.by_addr.setdefault(a, n)
        self.applied = load_applied(root)
        self.old2new = {r["old"]: r["new"] for r in self.applied}
        self.new2old = {r["new"]: r["old"] for r in self.applied}
        self.data = {r["new"]: r["addr"] for r in self.applied if r["kind"] == "data"}

    def addr(self, name):
        """address of a function or data symbol (current, old or splat name); None if unknown"""
        if name in self.by_name:
            return self.by_name[name]
        if name in self.data:
            return self.data[name]
        if name in self.old2new:
            return self.addr(self.old2new[name])
        m = ADDR_NAME.match(name)
        return int(m.group(1), 16) if m else None

    def name(self, addr):
        """current funcs.txt name of the function at addr (None if no function starts there)"""
        return self.by_addr.get(addr)

    def cur(self, name):
        """old (func_XXXXXXXX / D_XXXXXXXX) or current name -> current name"""
        return self.old2new.get(name, name)

    def old(self, name):
        """current name -> splat address name (identity for unrenamed symbols)"""
        return self.new2old.get(name, name)

    def is_func(self, name):
        return name in self.by_name

    def asm_files(self, sub="asm/nonmatchings"):
        """current function name -> path of its .s under <root>/<sub> (rodata/jtbl_* files excluded)"""
        out = {}
        for p in glob.glob(os.path.join(self.root, sub, "**", "*.s"), recursive=True):
            n = os.path.basename(p)[:-2]
            if n in self.by_name:
                out.setdefault(n, p)
        return out
