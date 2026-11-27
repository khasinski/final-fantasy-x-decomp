#!/usr/bin/env python3
"""Build unmodified period GNU binutils 2.9.1 MIPS R3000A gas (iop-as).
Run under Linux with gcc multilib and make. Supply the official GNU
binutils-2.9.1.tar.gz archive as argv[1]. Outputs ./as beside this script.
"""
import hashlib
import os
import pathlib
import subprocess
import sys
import tarfile

ARCHIVE_SHA256 = "58d01daa576d8779e064922171276795f00ff1388b1b0f87aa1a00eb0da6c6bb"

archive = pathlib.Path(sys.argv[1]).resolve()
assert hashlib.sha256(archive.read_bytes()).hexdigest() == ARCHIVE_SHA256
work = pathlib.Path("build/iop-as-2.9-rebuild").resolve()
work.mkdir(parents=True, exist_ok=True)
source = work / "source"
source.mkdir(exist_ok=True)
with tarfile.open(archive) as tar:
    for item in tar.getmembers():
        parts = pathlib.PurePosixPath(item.name).parts
        if len(parts) > 1 and parts[1] in {"binutils", "ld", "gprof", "texinfo"}:
            continue
        if sys.version_info >= (3, 12):
            tar.extract(item, source, filter="data")
        else:
            tar.extract(item, source)
source = source / "binutils-2.9.1"
build = work / "build"
build.mkdir(exist_ok=True)
env = dict(
    os.environ,
    CC="gcc -m32 -fcommon",
    ac_cv_prog_lex_root="lex.yy",
    ac_cv_prog_lex_yytext_pointer="no",
)
subprocess.run(
    [
        str(source / "configure"),
        "--host=i686-pc-linux-gnu",
        "--target=mipsel-elf",
        "--disable-nls",
    ],
    cwd=build,
    env=env,
    check=True,
)
subprocess.run(["make", "-j4", "all-gas"], cwd=build, env=env, check=True)
output = pathlib.Path(__file__).resolve().parent / "as"
output.write_bytes((build / "gas/as-new").read_bytes())
output.chmod(0o755)
print("Built", output)
