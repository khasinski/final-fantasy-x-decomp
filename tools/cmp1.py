import json, re, sys
orig = open('build/overlay-audit/overlay-group11-file09044.bin','rb').read()
mine = open('build/_t2.bin','rb').read()
dis = open('build/_d3.txt').read()
mf = [(int(o,16), n) for o, n in re.findall(r'^([0-9a-f]+) <(func_[0-9A-Fa-f]+)>:', dis, re.M)]
fj = json.load(open('build/overlay-map/functions.json'))['functions']
origf = sorted([(int(f['addr'],16), f['size']) for f in fj if f.get('container')==9044 and 0x01B00438 <= int(f['addr'],16) < 0x01B00FB0])
name = sys.argv[1]
idx = [n for _, n in mf].index(name)
moff = mf[idx][0]; oaddr, osize = origf[idx]
seg_o = orig[oaddr-0x01B00000:oaddr-0x01B00000+osize]
seg_m = mine[moff:moff+osize]
base = 0x01B00438+moff
for j in range(0, osize, 4):
    wo = seg_o[j:j+4]; wm = seg_m[j:j+4]
    mark = '' if wo == wm else '  <<<<'
    print('%08x: %s %s%s' % (base+j, wo.hex(), wm.hex(), mark))