/* tu_146 0x18fce0-0x190e38: medium; rcPacket (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

void func_0018FCE0(R2Pkt *b) {
    b->cur = 0;
    b->base = 0;
}

void func_0018FCF0(int *p, int v) {
    p[1] = v;
    p[0] = v;
}

void func_0018FD00(void **p) {
    if (*p != 0) {
        func_0018FC10(*p);
        *p = 0;
    }
}

void func_0018FD38(void **p, int size) {
    *p = _rcAlloc(size, D_0056D5F0, 0x39);
}

void func_0018FD70(R2Pkt *a, R2Pkt *b) {
    R2Qw *q = b->cur;

    a->base = q;
    a->cur = q + 1;
}

void func_0018FD88(R2Pkt *b, void *p) {
    b->base = p;
    b->cur = (R2Qw *)p + 1;
}

void func_0018FD98(R2Pkt *a, R2Pkt *b) {
    func_0018FDD0(a);
    b->cur = a->cur;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_0018FDD0);

void func_0018FE28(R2Pkt *b) {
    u32 *p = func_002DB6D8(2);

    func_002F8660(0);
    func_002DBA28(p, (int)b->base);
    func_002DBF78((int)p, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_0018FE80);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_0018FFD8);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190120);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190230);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190408);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190588);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190608);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190698);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_001907A8);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_001908B0);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190A00);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190B40);

void func_00190BF0(float cx, float cy, float r, int a3) {
    float v[17][4];
    unsigned int ang = 0;
    float *p = &v[0][0];
    int i;

    for (i = 0; i < 17; i++) {
        p[0] = cx + eff_sin_t[(ang >> 4) & 0xFFF] * r;
        p[1] = cy + eff_sin_t[((ang + 0x4000) >> 4) & 0xFFF] * r * (7.0f / 6.0f);
        p[2] = 256.0f;
        ang += 0x1000;
        p += 4;
    }
    func_00190408(0x42, &v[0][0], 0x11, a3);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190C98);

void func_00190DE8(int a, float x0, float y0, float x1, float y1) {
    float v[8];

    v[0] = x0;
    v[1] = y0;
    v[2] = 256.0f;
    v[3] = 0;
    v[4] = x1;
    v[5] = y1;
    v[6] = 256.0f;
    v[7] = 0;
    func_00190408(0x41, v, 2, a);
}
