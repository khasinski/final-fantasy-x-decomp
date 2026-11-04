#!/bin/sh
# Merge a worker workspace into the main tree:  tools/mergews.sh /path/to/ws
# A src/ file is copied only if the workspace differs from the committed (HEAD) version; if the main tree already
# changed it too, it is 3-way merged. include/vu0.h and config/cflags.txt are always 3-way merged against HEAD.
cd "$(dirname "$0")/.." || exit 1
WS="$1"
for f in $(git ls-files src); do
  [ -f "$WS/$f" ] || continue
  git show HEAD:"$f" > /tmp/mw_base.txt
  cmp -s "$WS/$f" /tmp/mw_base.txt && continue
  if cmp -s "$f" /tmp/mw_base.txt; then cp "$WS/$f" "$f"; echo "copied $f"
  else git merge-file "$f" /tmp/mw_base.txt "$WS/$f" && echo "merged $f" || echo "CONFLICT $f"; fi
done
for f in include/vu0.h config/cflags.txt; do
  git show HEAD:"$f" > /tmp/mw_base.txt
  cmp -s "$WS/$f" /tmp/mw_base.txt && continue
  git merge-file "$f" /tmp/mw_base.txt "$WS/$f" && echo "merged $f" || echo "CONFLICT $f"
done
