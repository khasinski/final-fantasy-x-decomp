/* Battle-effect overlay 09237: 0x01B00E10..0x01B010EC */
#include "rcef_overlay.h"
#include "vu0.h"

#define MIPS_MFC1_NV(v, f) __asm__("mfc1 %0, %1" : "=r"(v) : "f"(f))

extern int D_01B01394;
extern int D_01B01398;
extern int D_01B0139C;
extern float D_01B013A0;
extern float D_01B013A4;
extern float D_01B013E0[4];
extern float D_01B013F0;
extern float D_01B013F4;
extern float D_01B01400[16];
extern float eff_sin_t[];

void func_01B00E10(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float tmp[4];
    float x;
    register float y __asm__("$f0");
    register float d __asm__("$f5");
    register float e __asm__("$f0");
    register float a __asm__("$f1");
    register float g __asm__("$f2");
    register float dy __asm__("$f3");
    register float old __asm__("$f2");
    register int i __asm__("$4");
    int n;
    register int v __asm__("$7");

    a = (float)t->frame[t->sp].arg1;
    e = D_01B013F0 * a / 255.0f;
    g = D_01B013F4;
    i = t->frame[t->sp].count;
    g = g + e;
    MIPS_MFC1_NV(v, g);
    VU0_LQC2_INPUTS(31, D_01B01400, tmp, tmp);
    VU0_QMTC2(30, v);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, tmp);

    if (i == 0) {
        o->acc[0] = tmp[0];
        o->acc[1] = tmp[1];
        o->acc[2] = tmp[2];
        *(float *)&o->acc_w = 0;
    }
    if (i == D_01B0139C) {
        o->acc[0] = D_01B013E0[0] + tmp[0];
        o->acc[1] = D_01B013E0[1] + tmp[1];
        o->acc[2] = D_01B013E0[2] + tmp[2];
        *(float *)&o->acc_w = 0;
    }
    if (i == D_01B01394 - 10) {
        o->unk18C = -0.09f;
    }
    if (i < D_01B0139C) {
        x = (float)i;
    } else {
        x = (float)(i - D_01B0139C) * 0.5f + (float)D_01B0139C;
    }
    d = D_01B013A0;
    if (x < d) {
        n = (int)(x * 32768.0f / d);
        y = -eff_sin_t[(n & 0xFFFF) >> 4] * 3.0f;
    } else if (x < D_01B013A4) {
        n = (int)((x - d) * 32768.0f / d);
        y = eff_sin_t[(n & 0xFFFF) >> 4] * 3.0f;
    } else {
        n = (int)((x - D_01B013A4) * 32768.0f / ((float)D_01B01398 - D_01B013A4));
        y = -eff_sin_t[(n & 0xFFFF) >> 4] * 15.0f;
    }
    old = *(float *)&t->frame[t->sp].arg2;
    *(float *)&t->frame[t->sp].arg2 = y;
    VU0_LQC2(31, 0, o->pos);
    VU0_SQC2(31, 0, p);
    dy = y - old;
    p[1] += dy;
    o->pos[0] = p[0];
    o->pos[2] = p[2];
    o->pos[1] = p[1];
    o->pos_w = 0;
    i++;
    {
        register int lim __asm__("$2") = D_01B01394;
        if (i >= lim) {
            t->flags |= 4;
        } else {
            t->frame[t->sp].count = i;
        }
    }
}
