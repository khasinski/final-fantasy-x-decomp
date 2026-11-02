#!/usr/bin/env python3
"""Compare the rebuilt loadable image with the original ELF's LOAD segment."""
import hashlib, struct, sys
orig = open("baserom/SCES_504.90", "rb").read()
off, filesz = struct.unpack_from("<II", orig, 52 + 4)[0], struct.unpack_from("<I", orig, 52 + 16)[0]
want = orig[off:off + filesz]
got = open(sys.argv[1], "rb").read()
if got == want:
    print(f"OK  {hashlib.sha1(got).hexdigest()}  ({len(got):#x} bytes)"); sys.exit(0)
print(f"MISMATCH: built {len(got):#x} bytes, expected {len(want):#x}")
for i in range(min(len(got), len(want))):
    if got[i] != want[i]:
        print(f"first diff at rom+{i:#x} (vram {0x100000 + i:#x}): got {got[i]:02x} want {want[i]:02x}"); break
sys.exit(1)
