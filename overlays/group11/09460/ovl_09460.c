/* EE Battle-Effect Overlay: group 0x11, file 09460
 * Load base: 0x01B00000, .text: 0x01B004B8..0x01B014B8 (27 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00478[];
extern u8 D_01B00480[0x38];
extern int D_01B014C0;
extern int D_01B014C4;
extern int D_01B014C8;
extern int D_01B014CC;
extern float D_01B014D0;
extern float D_01B014D4;
extern float D_01B014E0[4];
extern float D_01B014F0[4];
extern float D_01B01500[4];
extern float D_01B01510[4];
extern float D_01B01520;
extern float D_01B01524;
extern float D_01B01530[16];
extern float D_01B01550[4];
extern u8 D_01B01570[];
extern s32 D_00313E48;
extern float eff_sin_t[];

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

float rcVec3fLength(Vec4 *v);
void func_001A3000(int chr, int idx, float *out);
void func_001A42D0(int a0, int a1);
void func_001A4370(int a0, int a1);
void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
void MsEffectEndMotion(int chr, int a1);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B00508(W3Task *t);
void func_01B00550(W3Task *t);
void func_01B005A0(W3Task *t);
void func_01B005E0(W3Task *t);
void func_01B00960(W3Task *t);
void func_01B009A0(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00B58(W3Task *t);
void func_01B00B98(W3Task *t);
void func_01B00BA8(W3Task *t);
void func_01B00C50(W3Task *t);
void func_01B00EA8(W3Task *t);
void func_01B01178(W3Task *t);
void func_01B01228(W3Task *t);
void func_01B01298(W3Task *t);
void func_01B012D8(W3Task *t);
void func_01B01348(W3Task *t);

void func_01B004B8(W3Task *t)
{
    D_01B014C0 = 0;
    func_001A42D0(2, 0);
    func_001A1D08(t, func_01B00508);
    func_001A1D50(t, func_001A2058);
}

void func_01B00508(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00550);
    func_001A1D50(t, func_001A2098);
}

void func_01B00550(W3Task *t)
{
    func_0019FF90_t(&D_00313CB0, func_01B01228);
    func_001A1D08(t, func_01B005E0);
    func_001A1DF0(t, 0x19);
}

void func_01B005A0(W3Task *t)
{
    func_001A2B80(D_00313E48, 0xB9);
    func_001A1D08(t, func_01B005E0);
}

void func_01B005E0(W3Task *t)
{
    float tmp[4];
    int caster;
    int cnt;
    int i;
    int m;
    float len;
    float f;

    caster = D_00313CB0.caster;
    func_001A2F00(caster, 0xB, D_01B014E0);
    func_001A2E80(caster, 0, D_01B01530);
    VEC3_SCALE(tmp, D_01B01530 + 8, -50.0f);
    VEC3_ADD(D_01B014E0, D_01B014E0, tmp);
    D_01B014F0[0] = D_01B014F0[1] = D_01B014F0[2] = D_01B014F0[3] = 0;
    cnt = D_00313CB0.target_count;
    for (i = 0; i < cnt; i++) {
        func_001A3000(D_00313CB0.targets[i], 0, tmp);
        VEC3_ADD(D_01B014F0, D_01B014F0, tmp);
    }
    VEC3_SCALE(D_01B014F0, D_01B014F0, 1.0f / (float)cnt);
    VEC3_SCALE(tmp, D_01B01550, -300.0f);
    VEC3_ADD(D_01B014F0, D_01B014F0, tmp);
    VEC3_SUB(tmp, D_01B014F0, D_01B014E0);
    len = rcVec3fLength((Vec4 *)tmp);
    m = (((int)(len / 1.6f) + 5) / 6) * 6;
    D_01B014C8 = m;
    D_01B014CC = m >> 1;
    D_01B014C4 = (m >> 1) * 3;
    f = (float)m / 6.0f;
    D_01B014D0 = f;
    if (f < 1.0f) {
        D_01B014D0 = 1.0f;
    }
    D_01B014D4 = D_01B014D0 + D_01B014D0;
    VEC3_SCALE(D_01B01500, tmp, 1.0f / (float)m);
    VEC3_SCALE(D_01B01510, D_01B01500, 1.0f / (float)(D_01B014CC - D_01B014C4));
    D_01B01520 = 400.0f / (float)((D_01B014C4 * D_01B014C4 + D_01B014C4) / 2);
    D_01B01524 = D_01B01520 * -0.5f;
    func_001A4310(2);
    func_0019FF90_t(&D_00313CB0, func_01B00BA8);
    func_001A1D08(t, func_01B00960);
    func_001A1DF0(t, 5);
}

void func_01B00960(W3Task *t)
{
    func_001A4288(0);
    func_001A4370(0, 0);
    func_001A1D20(t, func_01B009A0);
}

void func_01B009A0(W3Task *t)
{
    if (D_01B014C0 >= 0x14) {
        func_0019FF90_t(&D_00313CB0, func_01B012D8);
        func_001A1D08(t, func_01B00A70);
        func_001A1DF0(t, D_01B014C4 - 0x23);
    } else {
        func_0019FF90_t(&D_00313CB0, func_01B00C50);
        func_0019FF90_t(&D_00313CB0, func_01B00C50);
        func_0019FF90_t(&D_00313CB0, func_01B00C50);
        D_01B014C0++;
    }
}

void func_01B00A70(W3Task *t)
{
    int i;
    W3Task *r;

    func_001A4288(1);
    for (i = 0; i < D_00313CB0.target_count; i++) {
        func_001A3800(D_00313CB0.targets[i], 0);
        r = func_0019FF90_t(&D_00313CB0, func_01B01178);
        r->frame[r->sp].count = i;
    }
    func_001A1D08(t, func_01B00B58);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00B58(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00B98);
    func_001A1D50(t, func_001A2348);
}

void func_01B00B98(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00BA8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 0xB);
    func_001A1420(o, 0x10);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[2] = -10.0f;
    o->scale[0] = 0.5f;
    o->scale[1] = 0.5f;
    o->scale[2] = 0.5f;
    func_0019FFD0(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00B98);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00C50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float ang;
    float sc;
    float spd;
    float s;

    t->frame[t->sp].count = 0;
    t->frame[t->sp].arg1 = func_002EFD78() % 256;
    *(int *)((t->sp << 4) + (int)t + 0x34) = 0;
    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.656612873077393e-10f * 0.2f + 0.1f;
    spd = 0.2f / (float)D_01B014C4;
    o->flagsBC |= 0x4000;
    o->pos[0] = D_01B014E0[0];
    o->pos[1] = D_01B014E0[1];
    o->pos[2] = D_01B014E0[2];
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = ang;
    o->rot_w = 0;
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[2] = sc;
    o->scale[3] = 0;
    o->unk140[0] = spd;
    o->unk140[1] = spd;
    o->unk140[2] = spd;
    o->unk14C_w = 0;
    s = (float)func_002EFD78() * 4.656612873077393e-10f * 0.4f + 0.6f;
    o->vel[0] = D_01B01500[0] * s;
    o->vel[1] = D_01B01500[1] * s;
    o->vel[2] = D_01B01500[2] * s;
    o->vel[3] = 0;
    o->unk18C = 0;
    o->unk170[0] = 0.609375f;
    o->unk170[1] = 0.6640625f;
    o->unk170[2] = 0.4140625f;
    o->unk170[3] = 1.0f;
    o->unk180[0] = -0.546875f / (float)D_01B014C4;
    o->unk180[1] = -0.5859375f / (float)D_01B014C4;
    o->unk180[2] = -0.390625f / (float)D_01B014C4;
    func_001A0000((RcefObj *)&D_00313CB0, (void *)o, 0);
    func_001A1D20(t, func_01B00EA8);
}

void func_01B00EA8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float tmp[4];
    float x;
    /* DEBT(FAKE): register pins for ee-gcc2.9 float register allocation in func_01B00EA8 */
    register float h __asm__("$f0");
    register float r __asm__("$f1");
    register float y __asm__("$f0");
    float d;
    register float e __asm__("$f0");
    register float k __asm__("$f1");
    register float a __asm__("$f1");
    register float g __asm__("$f2");
    register float dy __asm__("$f3");
    register float old __asm__("$f1");
    int i;
    int n;
    float *po;

    a = (float)t->frame[t->sp].arg1;
    e = D_01B01520 * a / 255.0f;
    g = D_01B01524;
    i = t->frame[t->sp].count;
    k = g + e;
    VEC3_SCALE(tmp, D_01B01530, k);
    if (i == 0) {
        o->acc[0] = tmp[0];
        o->acc[1] = tmp[1];
        o->acc[2] = tmp[2];
        o->acc_w = 0;
    }
    if (i == D_01B014CC) {
        o->acc[0] = D_01B01510[0] + tmp[0];
        o->acc[1] = D_01B01510[1] + tmp[1];
        o->acc[2] = D_01B01510[2] + tmp[2];
        *(float *)&o->acc_w = 0;
    }
    if (i == D_01B014C4 - 10) {
        o->unk18C = -0.09f;
    }
    if (i < D_01B014CC) {
        x = (float)i;
    } else {
        x = (float)(i - D_01B014CC) * 0.5f + (float)D_01B014CC;
    }
    d = D_01B014D0;
    if (x < d) {
        n = (int)(x * 32768.0f / d);
        y = -eff_sin_t[(n & 0xFFFF) >> 4];
        y = y + y;
    } else if (x < D_01B014D4) {
        n = (int)((x - d) * 32768.0f / d);
        y = eff_sin_t[(n & 0xFFFF) >> 4];
        y = y + y;
    } else {
        n = (int)((x - D_01B014D4) * 32768.0f / ((float)D_01B014C8 - D_01B014D4));
        y = -eff_sin_t[(n & 0xFFFF) >> 4] * 10.0f;
    }
    old = *(float *)&t->frame[t->sp].arg2;
    *(float *)&t->frame[t->sp].arg2 = y;
    VEC3_COPY(p, o->pos);
    dy = y - old;
    g = p[2];
    /* DEBT(FAKE): scheduler barrier to preserve p[2] load before p[1]/p[0] */
    __asm__ volatile("" : : "f"(y), "f"(old));
    h = p[1];
    r = p[0];
    h = h + dy;
    p[1] = h;
    o->pos[0] = r;
    /* DEBT(FAKE): order o->pos[2] store after o->pos[0] */
    __asm__("" : "+f"(g) : "f"(h));
    o->pos[2] = g;
    o->pos[1] = h;
    o->pos_w = 0;
    i++;
    if (i >= D_01B014C4) {
        t->flags |= 4;
    } else {
        t->frame[t->sp].count = i;
    }
}

void func_01B01178(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[t->frame[t->sp].count], 6);
    func_001A1420(o, 0x10);
    o->scale[3] = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00B98);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01228(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 0xB8);
    func_001A1D08(t, func_01B01298);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B01298(W3Task *t)
{
    func_001A2B80(D_00313E48, 0xB9);
    t->flags |= 4;
}

void func_01B012D8(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 0xBA);
    func_001A1D08(t, func_01B01348);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B01348(W3Task *t)
{
    MsEffectEndMotion(D_00313E48, 0);
    t->flags |= 4;
}

int func_01B01388(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01570, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00478, D_01B00480);
    func_0019FF90(&D_00313CB0, func_01B004B8);
    return 0;
}

int func_01B013F8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01420(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01448(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01470(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01498(void) { return 0; }
int func_01B014A0(void) { return 0; }
int func_01B014A8(void) { return 0; }
int func_01B014B0(void) { return 0; }
