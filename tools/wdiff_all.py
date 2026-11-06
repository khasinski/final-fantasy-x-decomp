import json
orig = open('build/overlay-audit/overlay-group11-file09044.bin','rb').read()
mine = open('build/_t2.bin','rb').read()
ts = 0x01B00438
fj = json.load(open('build/overlay-map/functions.json'))['functions']
origf = sorted([(int(f['addr'],16), f['size']) for f in fj if f.get('container')==9044 and ts <= int(f['addr'],16) < 0x01B00FB0])
for addr, size in origf:
    off = addr - 0x01B00000
    seg_o = orig[off:off+size]
    offm = addr - ts
    seg_m = mine[offm:offm+size]
    if seg_o == seg_m:
        print('%08x MATCH' % addr)
        continue
    d = [i for i in range(min(size, len(seg_m))) if seg_o[i] != seg_m[i]]
    fa = ts + offm + (d[0] if d else min(size,len(seg_m)))
    print('%08x DIFF first@%08x (%d bytes differ of %d)' % (addr, fa, len(d), size))
