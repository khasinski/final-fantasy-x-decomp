import sys
orig = open('build/overlay-audit/overlay-group11-file09044.bin','rb').read()
mine = open('build/_t2.bin','rb').read()
ts = 0x01B00438
addr = int(sys.argv[1],16)
n = int(sys.argv[2]) if len(sys.argv)>2 else 12
offo = addr - 0x01B00000
offm = addr - ts
for i in range(n):
    wo = orig[offo+i*4:offo+i*4+4]
    wm = mine[offm+i*4:offm+i*4+4]
    mo = int.from_bytes(wo,'little'); mm = int.from_bytes(wm,'little')
    mark = '' if wo==wm else '   <<<<'
    print('%08x: %08x %08x%s' % (addr+i*4, mo, mm, mark))