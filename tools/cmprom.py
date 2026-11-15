orig = open('baserom/SCES_504.90','rb').read()
o = orig[0x1000:0x1000+0x47cb0c]
m = open('build/SCES_504.90.rom','rb').read()
import sys
a = int(sys.argv[1],16)
va = a - 0x100000
print(hex(a), 'orig', o[va:va+4].hex(), 'built', m[va:va+4].hex())
