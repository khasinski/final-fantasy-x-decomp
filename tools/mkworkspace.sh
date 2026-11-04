#!/bin/sh
# Create an isolated workspace copy for parallel work:  tools/mkworkspace.sh /path/to/ws
# (the copy has its own build/, so tools/m.sh can run there without touching the main tree)
set -e
cd "$(dirname "$0")/.."
WS="$1"; [ -n "$WS" ] || { echo "usage: $0 DIR"; exit 1; }
mkdir -p "$WS/baserom"
rsync -a --delete --exclude .git --exclude build --exclude baserom --exclude .venv --exclude LOCAL_NOTES.md ./ "$WS/"
cp -n baserom/SCES_504.90 baserom/SYSTEM.CNF "$WS/baserom/"
[ -e "$WS/.venv" ] || ln -s "$PWD/.venv" "$WS/.venv"
echo "workspace ready: $WS"
