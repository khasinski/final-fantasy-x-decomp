#!/usr/bin/env python3
"""Extract SCES_504.90 and SYSTEM.CNF from the PAL FFX disc image into baserom/."""
import hashlib, sys, pycdlib

iso_path = sys.argv[1]
want_sha1 = "ea6422ddfd803836701a38ae3cc8cc6420a70363"
iso = pycdlib.PyCdlib()
iso.open(iso_path)
for name in ("SCES_504.90", "SYSTEM.CNF"):
    iso.get_file_from_iso(f"baserom/{name}", iso_path=f"/{name};1")
sha = hashlib.sha1(open("baserom/SCES_504.90", "rb").read()).hexdigest()
print("SCES_504.90 sha1", sha, "OK" if sha == want_sha1 else "MISMATCH")
