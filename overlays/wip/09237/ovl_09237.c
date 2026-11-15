/* EE Battle-Effect Overlay: group 0x11, file 09237
 * Load base: 0x01B00000, .text: 0x01B004B8..0x01B01380 (24 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00478[];
extern u8 D_01B00480[0x38];
extern int D_01B01390;
extern int D_01B01394;
extern int D_01B01398;
extern int D_01B0139C;
extern float D_01B013A0;
extern float D_01B013A4;
extern float D_01B013B0[4];
extern float D_01B013C0[4];
extern float D_01B013D0[4];
extern float D_01B013E0[4];
extern float D_01B013F0;
extern float D_01B013F4;
extern float D_01B01400[4];
extern float D_01B01420[4];
extern u8 D_01B01440[];
extern s32 D_00313E48;

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")
#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

float rcVec3fLength(Vec4 *v);
void MsEffectEndMotion(int chr, int a1);
void func_001A2CC0(int chr);
void func_001A3000(int chr_id, int idx, float *out);
void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
void func_001A0000_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0000");
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");
extern float eff_sin_t[];

void func_01B00508(W3Task *t);
void func_01B00550(W3Task *t);
void func_01B005A0(W3Task *t);
void func_01B008E8(W3Task *t);
void func_01B00920(W3Task *t);
void func_01B009D8(W3Task *t);
void func_01B00AC0(W3Task *t);
void func_01B00B00(W3Task *t);
void func_01B00BB8(W3Task *t);
void func_01B00B10(W3Task *t);
void func_01B00E10(W3Task *t);
void func_01B010F0(W3Task *t);
void func_01B01210(W3Task *t);
void func_01B011A0(W3Task *t);

void func_01B004B8(W3Task *t)
{
    D_01B01390 = 0;
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
    func_0019FF90(&D_00313CB0, func_01B011A0);
    func_001A1D08(t, func_01B005A0);
    func_001A1DF0(t, 30);
}

void func_01B005A0(W3Task *t)
{
    int caster = D_00313CB0.caster;
    register int n __asm__("$16");
    register int i __asm__("$18");
    float tmp[4];
    float fn;
    float k;
    register int ki __asm__("$4");
    register int ki2 __asm__("$2");
    register int len __asm__("$2");
    register int h __asm__("$3");
    register float *sv __asm__("$3");
    register float *pa __asm__("$5");
    register float *pb __asm__("$4");
    float z;

    func_001A2F00(caster, 0x119, D_01B013B0);
    func_001A2E80(caster, 0, D_01B01400);
    D_01B013C0[0] = D_01B013C0[1] = D_01B013C0[2] = D_01B013C0[3] = 0.0f;
    n = D_00313CB0.target_count;
    for (i = 0; i < n; i++) {
        func_001A3000(D_00313CB0.targets[i], 0, tmp);
        VEC3_ADD(D_01B013C0, D_01B013C0, tmp);
    }
    fn = (float)n;
    sv = D_01B013C0;
    MIPS_MFC1(ki, 1.0f / fn);
    VEC3_SCALE(sv, sv, ki);
    MIPS_MFC1(ki, -100.0f);
    VEC3_SCALE(tmp, D_01B01420, ki);
    VEC3_ADD(D_01B013C0, D_01B013C0, tmp);
    VEC3_SUB(tmp, D_01B013C0, D_01B013B0);
    len = (int)(rcVec3fLength((Vec4 *)tmp) / 1.8f);
    len = (len + 5) / 6 * 6;
    h = len >> 1;
    D_01B01398 = len;
    D_01B0139C = h;
    D_01B01394 = h * 3;
    D_01B013A0 = (float)len / 6.0f;
    if (D_01B013A0 < 1.0f) {
        D_01B013A0 = 1.0f;
    }
    D_01B013A4 = D_01B013A0 + D_01B013A0;
    pa = D_01B013D0;
    MIPS_MFC1(ki, 1.0f / (float)len);
    VEC3_SCALE(pa, tmp, ki);
    pb = D_01B013E0;
    MIPS_MFC1(ki2, 1.0f / (float)(D_01B0139C - D_01B01394));
    VEC3_SCALE(pb, pa, ki2);
    D_01B013F0 = 400.0f / (float)((D_01B01394 * D_01B01394 + D_01B01394) / 2);
    D_01B013F4 = D_01B013F0 * -0.5f;
    func_001A4310(2);
    func_0019FF90(&D_00313CB0, func_01B00B10);
    func_001A1D08(t, func_01B008E8);
    func_001A1DF0(t, 5);
}

void func_01B008E8(W3Task *t)
{
    func_001A4288(0);
    func_001A1D20(t, func_01B00920);
}

void func_01B00920(W3Task *t)
{
    if (D_01B01390 >= 20) {
        func_001A1D08(t, func_01B009D8);
        func_001A1DF0(t, D_01B01394 - 35);
    } else {
        func_0019FF90(&D_00313CB0, func_01B00BB8);
        func_0019FF90(&D_00313CB0, func_01B00BB8);
        func_0019FF90(&D_00313CB0, func_01B00BB8);
        D_01B01390++;
    }
}

void func_01B009D8(W3Task *t)
{
    W3Task *r;
    int i;

    func_001A4288(1);
    for (i = 0; i < D_00313CB0.target_count; i++) {
        func_001A3800(D_00313CB0.targets[i], 0);
        r = func_0019FF90_t(&D_00313CB0, func_01B010F0);
        r->frame[r->sp].count = i;
    }
    func_001A1D08(t, func_01B00AC0);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00AC0(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A2348);
}

void func_01B00B00(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00B10(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 0x119);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos[2] = -10.0f;
    o->pos_w = 0;
    o->scale[0] = 0.5f;
    o->scale[1] = 0.5f;
    o->scale[2] = 0.5f;
    o->scale[3] = 0;
    func_0019FFD0(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00BB8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float a;
    float b;
    float c;
    float s;
    float r;

    t->frame[t->sp].count = 0;
    t->frame[t->sp].arg1 = func_002EFD78() % 256;
    (&t->frame[0].count)[t->sp * 4 + 2] = 0;
    a = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    r = (float)func_002EFD78() * 4.656612873077393e-10f;
    s = 0.2f / (float)D_01B01394;
    b = r * 0.2f + 0.1f;
    o->pos[0] = D_01B013B0[0];
    o->pos[1] = D_01B013B0[1];
    o->pos[2] = D_01B013B0[2];
    o->pos_w = 0;
    o->flagsBC |= 0x4000;
    o->rot[2] = a;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[0] = b;
    o->scale[1] = b;
    o->scale[2] = b;
    o->scale[3] = 0;
    o->unk140[0] = s;
    o->unk140[1] = s;
    o->unk140[2] = s;
    o->unk14C_w = 0;
    o->flagsBC |= 0x4000;
    c = (float)func_002EFD78() * 4.656612873077393e-10f * 0.4f + 0.6f;
    o->vel[0] = D_01B013D0[0] * c;
    o->vel[1] = D_01B013D0[1] * c;
    o->vel[2] = D_01B013D0[2] * c;
    o->vel[3] = 0;
    o->unk18C = 0;
    o->unk170[0] = 0.609375f;
    o->unk170[1] = 0.6640625f;
    o->unk170[2] = 0.4140625f;
    o->unk170[3] = 1.0f;
    o->unk180[0] = -0.546875f / (float)D_01B01394;
    o->unk180[1] = -0.5859375f / (float)D_01B01394;
    o->unk180[2] = -0.390625f / (float)D_01B01394;
    func_001A0000_k(&D_00313CB0, o, 0);
    func_001A1D20(t, func_01B00E10);
}

void func_01B00E10(W3Task *t)
{
    RcefObj *o;
    float p[4];
    float tmp[4];
    register int ki __asm__("$7");
    register int n __asm__("$4");
    register int *base __asm__("$6");
    float x;
    float y;
    float old;

    o = (RcefObj *)t;
    base = &t->frame[0].count;
    n = base[t->sp * 4];
    MIPS_MFC1(ki, D_01B013F0 * (float)t->frame[t->sp].arg1 / 255.0f + D_01B013F4);
    VEC3_SCALE(tmp, D_01B01400, ki);
    if (n == 0) {
        o->acc[0] = tmp[0];
        o->acc[1] = tmp[1];
        o->acc[2] = tmp[2];
        *(float *)&o->acc_w = 0;
    }
    if (n == D_01B0139C) {
        o->acc[0] = D_01B013E0[0] + tmp[0];
        o->acc[1] = D_01B013E0[1] + tmp[1];
        o->acc[2] = D_01B013E0[2] + tmp[2];
        *(float *)&o->acc_w = 0;
    }
    if (n == D_01B01394 - 10) {
        o->unk18C = -0.09f;
    }
    if (n < D_01B0139C) {
        x = (float)n;
    } else {
        x = (float)(n - D_01B0139C) * 0.5f + (float)D_01B0139C;
    }
    if (x < D_01B013A0) {
        y = -eff_sin_t[((int)(x * 32768.0f / D_01B013A0) & 0xFFFF) >> 4] * 3.0f;
    } else if (x < D_01B013A4) {
        y = eff_sin_t[((int)((x - D_01B013A0) * 32768.0f / D_01B013A0) & 0xFFFF) >> 4] * 3.0f;
    } else {
        y = -eff_sin_t[((int)((x - D_01B013A4) * 32768.0f / ((float)D_01B01398 - D_01B013A4)) & 0xFFFF) >> 4] * 15.0f;
    }
    old = *(float *)&t->frame[t->sp].arg2;
    *(float *)&t->frame[t->sp].arg2 = y;
    VEC3_COPY(p, o->pos);
    p[1] += y - old;
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    n++;
    if (n >= D_01B01394) {
        t->flags |= 4;
    } else {
        base[t->sp * 4] = n;
    }
}

void func_01B010F0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[t->frame[t->sp].count], 6);
    func_001A1420(o, 16);
    o->scale[3] = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A20D8);
}

void func_01B011A0(W3Task *t)
{
    int chr = D_00313E48;

    func_001A2B80(chr, 122);
    func_001A1D08(t, func_01B01210);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = chr;
}

void func_01B01210(W3Task *t)
{
    MsEffectEndMotion(D_00313E48, 0);
    t->flags |= 4;
}

int func_01B01250(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01440, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00478, D_01B00480);
    func_0019FF90(&D_00313CB0, func_01B004B8);
    return 0;
}

int func_01B012C0(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B012E8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01310(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01338(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01360(void) { return 0; }
int func_01B01368(void) { return 0; }
int func_01B01370(void) { return 0; }
int func_01B01378(void) { return 0; }
