import json, re, sys
fj = json.load(open('build/overlay-map/functions.json'))['functions']
origf = {int(f['addr'],16): f['size'] for f in fj if f.get('container')==9044 and 0x01B00438 <= int(f['addr'],16) < 0x01B00FB0}
dis = open('build/_d2.txt').read()
funcs = [(int(o,16), n) for o,n in re.findall(r'^0*([0-9a-f]+) <(func_[0-9A-Fa-f]+)>:', dis, re.M)]
end = int(sys.argv[1],16) if len(sys.argv)>1 else 0xb50
oaddr_list = sorted(origf)
tot = 0
for i,(off,name) in enumerate(funcs):
    e = funcs[i+1][0] if i+1 < len(funcs) else end
    mine = e - off
    osz = origf[oaddr_list[i]]
    mark = '' if osz == mine else f'  <<<< {osz-mine:+d}'
    if osz != mine:
        print(f"{name} off={off:#05x} mine={mine} orig={osz}{mark}")
    tot += osz - mine
print('sum diff:', tot)