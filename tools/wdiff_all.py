import json, re
fj = json.load(open('build/overlay-map/functions.json'))['functions']
origf = sorted([(int(f['addr'],16), f['size']) for f in fj if f.get('container')==9044 and 0x01B00438 <= int(f['addr'],16) < 0x01B00FB0])
orig = open('build/overlay-audit/overlay-group11-file09044.bin','rb').read()
mine = open('build/_t2.bin','rb').read()
dis = open('build/_d3.txt').read()
mf = [(int(o,16), n) for o, n in re.findall(r'^([0-9a-f]+) <(func_[0-9A-Fa-f]+)>:', dis, re.M)]
mend = 0xb50
assert len(mf) == len(origf), (len(mf), len(origf))
for i, (moff, mname) in enumerate(mf):
    msize = (mf[i+1][0] if i+1 < len(mf) else mend) - moff
    oaddr, osize = origf[i]
    seg_o = orig[oaddr-0x01B00000:oaddr-0x01B00000+osize]
    seg_m = mine[moff:moff+osize]
    if seg_o == seg_m:
        print('%s MATCH (mine@%04x size %d)' % (mname, moff, msize))
    else:
        d = [j for j in range(min(osize, len(seg_m))) if seg_o[j] != seg_m[j]]
        fa = 0x01B00438 + moff + (d[0] if d else min(osize, len(seg_m)))
        print('%s DIFF mine@%04x orig@%08x sizes %d/%d firstdiff@%08x' % (mname, moff, oaddr, msize, osize, fa))
