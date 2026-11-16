/* EE Battle-Effect Overlay: group 0x11, file 09426
 * Load base: 0x01B00000, .text: 0x01B00760..0x01B01738 (32 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00720[];
extern u8 D_01B00728[];
extern RcefObj *D_01B01740;
extern RcefObj *D_01B01744;
extern int D_01B01748;
extern int D_01B0174C;
extern int D_01B01750;
extern float D_01B01760[3];
extern float D_01B01770[4];
extern float D_01B01780[4];
extern float D_01B01790[4];
extern u8 D_01B017A0[];
extern s32 D_00313E48;

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")
#define ZF(x) (*(float *)&(x) = 0)
#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

void func_001A2F50(int chr, int a1, float out1[4], float out2[4]);
void func_001A3000(int chr, int a1, float out[4]);
void func_0018EFD0(float *out, float *a, float *b);
void func_001A0000_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0000");
void func_001A0040_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0040");
void rcefMainKickPar_k(RcefMainCtx *ctx, RcefObj *o, int idx, int sub) __asm__("func_0019FFD0");
float rcVec3fLength(Vec4 *v);
void rcVec3fNormalize(Vec4 *v);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_001A2110(W3Task *t);
void func_01B007A8(W3Task *t);
void func_01B007F0(W3Task *t);
void func_01B00860(W3Task *t);
void func_01B008A0(W3Task *t);
void func_01B008F8(W3Task *t);
void func_01B00908(W3Task *t);
void func_01B00958(W3Task *t);
void func_01B009B0(W3Task *t);
void func_01B00A20(W3Task *t);
void func_01B00A60(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00B20(W3Task *t);
void func_01B00D18(W3Task *t);
void func_01B00EF8(W3Task *t);
void func_01B00F38(W3Task *t);
void func_01B00FC0(W3Task *t);
void func_01B01048(W3Task *t);
void func_01B01100(W3Task *t);
void func_01B01228(W3Task *t);
void func_01B01428(W3Task *t);
void func_01B014D8(W3Task *t);
void func_01B01578(W3Task *t);

void func_01B00760(W3Task *t)
{
    RcefObj **p = &D_01B01740;

    D_01B01744 = 0;
    *p = 0;
    func_001A1D08(t, func_01B007A8);
    func_001A1D50(t, func_001A2058);
}

void func_01B007A8(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B008A0);
    func_001A1D50(t, func_001A2098);
}

void func_01B007F0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 184);
    func_001A1D08(t, func_01B00860);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00860(W3Task *t)
{
    func_001A2B80(D_00313E48, 185);
    func_001A1D08(t, func_01B008A0);
}

void func_01B008A0(W3Task *t)
{
    func_001A4288(0);
    func_0019FF90(&D_00313CB0, func_01B01428);
    func_001A1D08(t, func_01B008F8);
    func_001A1DF0(t, 35);
}

void func_01B008F8(W3Task *t)
{
    func_001A1D08(t, func_01B00908);
}

void func_01B00908(W3Task *t)
{
    D_01B01748 = 0;
    D_01B0174C = D_01B01750;
    func_001A1D08(t, func_01B00958);
    func_001A1DF0(t, 8);
}

void func_01B00958(W3Task *t)
{
    RcefObj *r = func_0019FF90(&D_00313CB0, func_01B00B20);

    D_01B01740 = r;
    func_001A1D08(t, func_01B009B0);
    func_001A1DF0(t, 20);
}

void func_01B009B0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 186);
    func_001A1D08(t, func_01B00A20);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A20(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00A60(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00A70(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 41);
    func_001A1420(o, 0x100);
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = o->pos[0] = 2.5f;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.02f;
    rcefMainKickPar_k(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00B20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int tgt;
    int n;
    float fs;
    float *v = D_01B01780;
    int c;

    c = D_00313CB0.caster;
    D_01B01780[0] = 2.5f;
    v[1] = 2.5f;
    tgt = D_00313CB0.targets[0];
    v[2] = 0;
    v[3] = 0;
    func_001A2F50(c, 41, v, D_01B01760);
    fs = 0.03f;
    if (D_01B01748 == 0) {
        rcefMainKickPar_k(&D_00313CB0, o, 0, 2);
    }
    n = ++D_01B01748;
    if (n < 50) {
        if (n < 25) {
            fs = (float)n * fs / 25.0f;
        }
    } else {
        int ki;
        int len;
        RcefObj *r;

        func_001A3000(tgt, 2, D_01B01770);
        VEC3_SUB(D_01B01790, D_01B01770, D_01B01760);
        len = (int)(rcVec3fLength((Vec4 *)D_01B01790) * 0.125f);
        D_01B01750 = len;
        D_01B0174C = len;
        MIPS_MFC1(ki, 1.0f / (float)len);
        VEC3_SCALE(D_01B01790, D_01B01790, ki);
        r = func_0019FF90(&D_00313CB0, func_01B014D8);
        D_01B01744 = r;
        func_001A1D20(t, func_01B00D18);
    }
    o->pos[0] = D_01B01760[0];
    o->pos[1] = D_01B01760[1];
    o->pos[2] = D_01B01760[2];
    o->scale[2] = o->scale[1] = o->scale[0] = fs;
    ZF(o->pos_w);
    o->scale[3] = 0;
}

void func_01B00D18(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float a[4];
    float b[4];
    float c[4];
    register float *cp __asm__("$16");
    float m;
    float c0;
    float c1;
    float c2;

    VEC3_COPY(a, D_01B01790);
    rcVec3fNormalize((Vec4 *)a);
    b[1] = -1.0f;
    b[0] = 0;
    b[2] = 0;
    b[3] = 0;
    cp = c;
    func_0018EFD0(cp, a, b);
    {
        int ki;

        MIPS_MFC1(ki, 0.2f);
        VEC3_SCALE(cp, cp, ki);
    }
    c0 = c[0];
    c1 = c[1];
    c2 = c[2];
    m = (float)(D_01B01750 / 2 + 1);
    D_01B01790[0] += -c0 * m;
    D_01B01790[1] += -c1 * m;
    D_01B01790[2] += -c2 * m;
    o->pos[0] = D_01B01760[0];
    o->pos[1] = D_01B01760[1];
    o->pos[2] = D_01B01760[2];
    ZF(o->pos_w);
    o->vel[0] = D_01B01790[0];
    o->vel[1] = D_01B01790[1];
    o->vel[2] = D_01B01790[2];
    o->vel[3] = 0;
    ZF(o->acc_w);
    o->scale[3] = 0;
    o->acc[0] = c0;
    o->acc[1] = c1;
    o->acc[2] = c2;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.03f;
    func_0019FF90(&D_00313CB0, func_01B00FC0);
    D_01B01744->pos[0] = D_01B01760[0];
    D_01B01744->pos[1] = -0.1f;
    D_01B01744->pos[2] = D_01B01760[2];
    ZF(D_01B01744->pos_w);
    func_001A1D08(t, func_01B00EF8);
    func_001A1DF0(t, D_01B01750);
}

void func_01B00EF8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B01048);
    t->flags |= 4;
}

void func_01B00F38(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    int c = t->frame[t->sp].count;

    c++;

    if (c >= D_01B01750) {
        t->flags |= 4;
    } else {
        VEC3_COPY(p, o->pos);
        D_01B01744->pos[0] = p[0];
        t->frame[t->sp].count = c;
        D_01B01744->pos[1] = p[1];
        D_01B01744->pos[2] = p[2];
        ZF(D_01B01744->pos_w);
    }
}

void func_01B00FC0(W3Task *t)
{
    if (--D_01B0174C >= 0) {
        int i;

        for (i = 0; i < 6; i++) {
            func_0019FF90(&D_00313CB0, func_01B01228);
        }
    } else {
        func_001A1D08(t, func_01B00A60);
    }
}

void func_01B01048(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int tgt = D_00313CB0.targets[0];

    func_001A4288(1);
    func_001A13A0(o, D_00313CB0.targets[0], 6);
    func_001A1420(o, 0x40);
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.075f;
    rcefMainKickPar_k(&D_00313CB0, o, 0, 1);
    func_001A3800(tgt, 0);
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01100(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float fs;
    float q[4];
    float sc;

    fs = (float)func_002EFD78() * 4.656613e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.656613e-10f * 0.1f + 0.1f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(q, D_01B01740->pos);
    o->rot[2] = fs;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->pos[0] = q[0];
    o->pos[1] = q[1];
    o->pos[2] = q[2];
    o->scale[2] = o->scale[1] = o->scale[0] = sc;
    o->unk18C = -0.09f;
    func_001A0000_k(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A2110);
}

void func_01B01228(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float fs;
    float p[4];
    float q[4];
    float k = 4.656613e-10f;
    float c12;
    float c06;

    fs = (float)func_002EFD78() * k * 0.005f + 0.005f;
    c12 = 1.2f;
    c06 = 0.6f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(p, D_01B01740->pos);
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    VEC3_COPY(q, D_01B01740->vel);
    {
        int ki;

        MIPS_MFC1(ki, -0.2f);
        __asm__ volatile(".set push\n\t.set noreorder\n\tlqc2 $vf31, 0(%0)\n\tqmtc2.ni %1, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%0)\n\t.set pop"
                         : : "r"(q), "r"(ki) : "memory");
    }
    q[0] += (float)func_002EFD78() * k * c12 - c06;
    q[1] += (float)func_002EFD78() * k * c12 - c06;
    q[2] += (float)func_002EFD78() * k * c12 - c06;
    o->scale[2] = o->scale[1] = o->scale[0] = fs;
    o->vel[3] = 0;
    o->scale[3] = 0;
    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->vel[0] = q[0];
    o->vel[1] = q[1];
    o->vel[2] = q[2];
    o->unk170[0] = 1.0f;
    o->unk170[1] = 0.2f;
    o->unk170[2] = 0.2f;
    o->unk170[3] = 1.0f;
    o->unk18C = -0.09f;
    func_001A0000_k(&D_00313CB0, o, 1);
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A2110);
}

void func_01B01428(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 41);
    func_001A1420(o, 0x100);
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = o->pos[0] = 2.5f;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.04f;
    rcefMainKickPar_k(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B00A60);
    func_001A1D50(t, func_001A20D8);
}

void func_01B014D8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->scale[3] = 0;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 3.0f;
    o->rot[0] = 90.0f;
    o->unk170[1] = o->unk170[0] = 1.0f;
    o->unk170[2] = 1.0f;
    o->unk170[3] = 0.4f;
    func_001A0040_k(&D_00313CB0, o, 2);
    ((u8 *)o)[0x3D8] = 0x48;
    func_001A1D08(t, func_01B01578);
}

void func_01B01578(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    int c = t->frame[t->sp].count;

    c++;

    if (c >= D_01B01750) {
        t->flags |= 4;
    } else {
        VEC3_COPY(p, D_01B01740->pos);
        t->frame[t->sp].count = c;
        o->pos[0] = p[0];
        o->pos[1] = -0.1f;
        o->pos[2] = p[2];
        ZF(o->pos_w);
    }
}

int func_01B01608(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B017A0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00720, D_01B00728);
    func_0019FF90(&D_00313CB0, func_01B00760);
    return 0;
}

int func_01B01678(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B016A0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B016C8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B016F0(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01718(void) { return 0; }
int func_01B01720(void) { return 0; }
int func_01B01728(void) { return 0; }
int func_01B01730(void) { return 0; }
