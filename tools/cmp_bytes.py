import json
cid = 9044
orig = open('build/overlay-audit/overlay-group11-file%05d.bin' % cid, 'rb').read()
mine = open('build/_t2.bin', 'rb').read()
ts, te = 0x01B00438, 0x01B00FB0
o = orig[ts-0x01B00000:te-0x01B00000]
m = mine[:len(o)]
fj = json.load(open('build/overlay-map/functions.json'))['functions']
origf = sorted([(int(f['addr'],16), f['size']) for f in fj if f.get('container')==cid and ts <= int(f['addr'],16) < te])
for addr, size in origf:
    off = addr - ts
    seg_o = o[off:off+size]
    seg_m = m[off:off+size]
    if seg_o == seg_m:
        print('%08x MATCH' % addr)
    else:
        n = min(len(seg_o), len(seg_m))
        d = [i for i in range(n) if seg_o[i] != seg_m[i]]
        first = d[0] if d else n
        print('%08x DIFF  len %d/%d  first byte-diff at +%d (addr %08x)' % (addr, len(seg_o), len(seg_m), first, ts+off+first))