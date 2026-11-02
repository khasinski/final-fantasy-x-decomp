#!/bin/sh
# Rebuild and diff function(s):   tools/m.sh func_0010D2C0 [func_...]
# Run from the repo (or a workspace copy) root on the host; builds happen inside the docker image.
# With no args it just builds and runs the whole-image check.
cd "$(dirname "$0")/.." || exit 1
docker run --rm -v "$PWD":/work ffx-decomp sh -c '
  python3 tools/eeasm.py asm/nonmatchings build/ee_asm &&
  python3 configure.py &&
  ninja -k 0 -j4 build/SCES_504.90.rom 2>&1 | grep -v "Warning:\|Assembler messages\|bfd assertion\|^\[" ;
  '"$([ $# -gt 0 ] && echo "python3 tools/fdiff.py $*" || echo "ninja 2>&1 | tail -2")"
