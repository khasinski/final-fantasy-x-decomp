#!/bin/sh
# First C draft of a function with m2c:  tools/draft.sh func_0010D2C0 | RealName
# (a splat name whose function got a real name is looked up in config/names_applied.tsv)
cd "$(dirname "$0")/.." || exit 1
N=$(awk -F'\t' -v n="$1" '$2 == n { print $3 }' config/names_applied.tsv 2>/dev/null); N=${N:-$1}
F=$(find asm/nonmatchings -name "$N.s" -not -path '*/rodata/*' | head -1); [ -n "$F" ] || exit 1
.venv/bin/m2c --target mipsel-gcc-c --stack-structs "$F" 2>&1
