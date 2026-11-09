/* tu_146 0x18fce0-0x190e38: medium; rcPacket (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "vu0.h"

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

int func_0018FDD0(R2Pkt *b)
{
    u32 qwc;

    b->cur->d.lo = 0x1000000000008000UL;
    b->cur->d.hi = 0;
    b->cur++;
    qwc = (((u32)b->cur - (u32)b->base) >> 4) - 1;
    b->base->q = 0;
    b->base->w[0] = qwc | 0x70000000;
    return qwc;
}

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

extern void func_00190408(int prim, float *v, int n, int a);

void func_00190588(int a, float cx, float cy, float w, float h)
{
    float v[16];
    float hw = w * 0.5f;
    float hh = h * 0.5f;

    v[0] = cx - hw;
    v[1] = cy - hh;
    v[2] = 256.0f;
    v[4] = cx + hw;
    v[5] = cy - hh;
    v[6] = 256.0f;
    v[8] = cx - hw;
    v[9] = cy + hh;
    v[10] = 256.0f;
    v[12] = cx + hw;
    v[13] = cy + hh;
    v[14] = 256.0f;
    func_00190408(0x44, v, 4, a);
}

void func_00190608(int a, float cx, float cy, float w, float h)
{
    float v[16];
    float t[4];
    float *tp = t;
    float hw = w * 0.5f;
    float hh = h * 0.5f;

    v[0] = cx - hw;
    v[1] = cy - hh;
    v[2] = 256.0f;
    v[4] = cx + hw;
    v[5] = cy - hh;
    v[6] = 256.0f;
    v[8] = cx - hw;
    v[9] = cy + hh;
    v[10] = 256.0f;
    v[12] = cx + hw;
    v[13] = cy + hh;
    v[14] = 256.0f;
    VU0_LQC2(31, 0, v);
    VU0_SQC2(31, 0, tp);
    func_00190408(0x42, v, 5, a);
}

typedef struct RcAng3 {
    int a[3];
} RcAng3;
extern RcAng3 D_0056D600;

void func_00190698(int a, float cx, float cy, float r, float rot)
{
    RcAng3 ang = D_0056D600;
    float v[3][4];
    int i;
    int base_ang = (int)(rot * 65536.0f / 6.2831855f);
    int *ap;
    float *p;

    for (i = 0, ap = ang.a, p = &v[0][0]; i < 3; i++, ap++, p += 4) {
        unsigned int cur = base_ang + *ap;
        p[0] = cx + eff_sin_t[(cur >> 4) & 0xFFF] * r;
        p[1] = cy + eff_sin_t[((cur + 0x4000) >> 4) & 0xFFF] * r * (7.0f / 6.0f);
        if (i == 0) {
            p[2] = 256.0f;
        } else {
            p[2] = 176.0f;
        }
    }
    func_00190408(0x4C, &v[0][0], 3, a);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_001907A8);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_001908B0);

INCLUDE_ASM("build/ee_asm/game/rc/rcPacket", func_00190A00);

void func_00190B40(int a, float cx, float cy, float r) {
    float v[18][4];
    unsigned int ang = 0;
    float *p = &v[1][0];
    int i;

    v[0][0] = cx;
    v[0][1] = cy;
    for (i = 0; i < 17; i++) {
        p[0] = cx + eff_sin_t[(ang >> 4) & 0xFFF] * r;
        p[1] = cy + eff_sin_t[((ang + 0x4000) >> 4) & 0xFFF] * r * (7.0f / 6.0f);
        p[2] = 256.0f;
        ang += 0x1000;
        p += 4;
    }
    func_00190408(0x45, &v[0][0], 0x12, a);
}

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

void func_00190C98(int a, float cx, float cy, float r)
{
    float v[16];
    float hw = r * 0.5f;
    float x_in = hw * (2.0f / 3.0f);
    float y_out = hw * (7.0f / 6.0f);
    float y_in = x_in * (7.0f / 6.0f);

    v[0] = cx - hw;
    v[1] = cy - y_in;
    v[2] = 256.0f;
    v[4] = cx - x_in;
    v[5] = cy - y_out;
    v[6] = 256.0f;
    v[8] = cx + x_in;
    v[9] = cy + y_out;
    v[10] = 256.0f;
    v[12] = cx + hw;
    v[13] = cy + y_in;
    v[14] = 256.0f;
    func_00190408(0x44, v, 4, a);
    v[0] = cx + x_in;
    v[1] = cy - y_out;
    v[2] = 256.0f;
    v[4] = cx + hw;
    v[5] = cy - y_in;
    v[6] = 256.0f;
    v[8] = cx - hw;
    v[9] = cy + y_in;
    v[10] = 256.0f;
    v[12] = cx - x_in;
    v[13] = cy + y_out;
    v[14] = 256.0f;
    func_00190408(0x44, v, 4, a);
}

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
