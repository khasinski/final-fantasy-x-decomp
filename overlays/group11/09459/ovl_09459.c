/* EE Battle-Effect Overlay: group 0x11, file 09459
 * Load base: 0x01B00000, .text: 0x01B00490..0x01B011A8 (26 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00450[];
extern u8 D_01B00458[0x38];
extern int D_01B011B0;
extern u8 D_01B011C0[];

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

#define VEC3_SCALE_L(d, a, ki) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tqmtc2.ni %2, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%0)\n1:" \
                     : : "r"(d), "r"(a), "r"(ki) : "memory")

float rcVec3fLength(Vec4 *v);
int func_001AF358(void);
void func_001A3000(int chr, int idx, float *out);
void func_001A2C20(void);
void func_001A2C88(int a0, int a1, int a2, int a3);
void func_001A2CA0(int chr, int a1, int a2);
void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");
extern s32 D_00313E48;

void func_01B004D8(W3Task *t);
void func_01B00588(W3Task *t);
void func_01B005F8(W3Task *t);
void func_01B00638(W3Task *t);
void func_01B006B0(W3Task *t);
void func_01B00790(W3Task *t);
void func_01B007C0(W3Task *t);
void func_01B007D0(W3Task *t);
void func_01B00898(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00B90(W3Task *t);
void func_01B00D48(W3Task *t);
void func_01B00D98(W3Task *t);
void func_01B00F40(W3Task *t);
void func_01B00F90(W3Task *t);

void func_01B00490(W3Task *t)
{
    D_01B011B0 = 0;
    func_001A1D08(t, func_01B004D8);
    func_001A1D50(t, func_001A2058);
    func_001A2C20();
}

void func_01B004D8(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00588);
    func_001A1D50(t, func_001A2098);
}

void func_01B00520(W3Task *t)
{
    func_001A2C88(D_00313CB0.caster, D_00313CB0.targets[D_01B011B0], 1, 2);
    func_001A1D08(t, func_01B00588);
    func_001A1DF0(t, 3);
}

void func_01B00588(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 0xC0);
    func_001A1D08(t, func_01B005F8);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B005F8(W3Task *t)
{
    func_001A2B80(D_00313E48, 0xC1);
    func_001A1D20(t, func_01B00638);
}

void func_01B00638(W3Task *t)
{
    W3Task *r;

    func_0019FF90_t(&D_00313CB0, func_01B007D0);
    r = func_0019FF90_t(&D_00313CB0, func_01B00898);
    r->frame[r->sp].count = D_01B011B0;
    func_001A1D20(t, func_01B006B0);
}

void func_01B006B0(W3Task *t)
{
    register int caster __asm__("$16");
    register int idx __asm__("$5");
    register int *cp __asm__("$2");
    register RcefMainCtx *cx __asm__("$3");
    int cnt;

    cp = &D_01B011B0;
    cx = &D_00313CB0;
    idx = *cp + 1;
    cnt = cx->target_count;
    caster = cx->caster;
    *cp = idx;
    if (idx < cnt) {
        caster = 40 / (cnt - 1);
        func_001A1D08(t, func_01B00638);
        func_001A1DF0(t, caster);
    } else {
        func_001A2B80(caster, 0xC2);
        func_001A2CA0(caster, 2, 4);
        func_001A1D08(t, func_01B00790);
        func_001A1D50(t, func_001A2148);
        t->frame[t->sp].count = caster;
    }
}

void func_01B00790(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B007C0);
}

void func_01B007C0(W3Task *t)
{
    t->flags |= 4;
}

void func_01B007D0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 0xB);
    func_001A1420(o, 0x10);
    o->pos[0] = 0;
    o->pos_w = 0;
    o->pos[1] = -1.0f;
    o->pos[2] = -2.5f;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->scale[0] = 0.55f;
    o->scale[1] = 0.55f;
    o->scale[2] = 0.55f;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B007C0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00898(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float a[4];
    float b[4];
    float c[4];
    register int n __asm__("$3");
    float k;
    register int ki __asm__("$2");
    register W3Frame *fp __asm__("$3");
    register int cn __asm__("$2");
    int tgt;
    float len;

    fp = (W3Frame *)((char *)t + t->sp * 16);
    cn = *(int *)((char *)fp + 0x2C);
    tgt = D_00313CB0.targets[cn];
    func_001A2F00(D_00313CB0.caster, 0xB, a);
    if (func_001AF358() == 0x2380000) {
        func_001A3000(tgt, 0, b);
        VEC3_SUB(c, b, a);
        len = rcVec3fLength((Vec4 *)c) * 0.4f;
    } else {
        func_001A3000(tgt, 6, b);
        VEC3_SUB(c, b, a);
        len = rcVec3fLength((Vec4 *)c);
    }
    n = (int)(len / 6.0f);
    k = 1.0f / (float)n;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(c, c, ki);
    o->pos[0] = a[0];
    o->pos[1] = a[1];
    o->pos[2] = a[2];
    *(float *)&o->pos_w = 0;
    o->vel[0] = c[0];
    o->vel[1] = c[1];
    o->vel[2] = c[2];
    o->vel[3] = 0;
    o->scale[0] = 0.17f;
    o->scale[1] = 0.17f;
    o->scale[2] = 0.17f;
    o->scale[3] = 0;
    t->frame[t->sp].arg1 = n;
    func_001A4288(0);
    func_001A4370(0, 0);
    func_0019FFD0(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00A70);
}

void func_01B00A70(W3Task *t)
{
    W3Task *r;

    t->frame[t->sp].arg1--;
    if (t->frame[t->sp].arg1 > 0) {
        r = func_0019FF90_t(&D_00313CB0, func_01B00B90);
        r->frame[r->sp].count = (int)t;
        r = func_0019FF90_t(&D_00313CB0, func_01B00D98);
        r->frame[r->sp].count = (int)t;
        r = func_0019FF90_t(&D_00313CB0, func_01B00D98);
        r->frame[r->sp].count = (int)t;
    } else {
        r = func_0019FF90_t(&D_00313CB0, func_01B00F90);
        r->frame[r->sp].count = t->frame[t->sp].count;
        t->flags |= 4;
    }
}

void func_01B00B90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefObj *s = (RcefObj *)t->frame[t->sp].count;
    float v[8];
    float ang;
    float sc;
    float u;
    float k;
    int ki;

    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.656612873077393e-10f * 0.15f + 0.15f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(v, s->pos);
    VEC3_COPY(&v[4], s->vel);
    k = 0.06f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE_L(&v[4], &v[4], ki);
    u = (float)func_002EFD78() * 4.656612873077393e-10f * 0.1f + 0.1f;
    v[5] -= u;
    o->rot[2] = ang;
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[2] = sc;
    o->pos_w = 0;
    o->vel[3] = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->unk14C_w = 0;
    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    o->vel[0] = v[4];
    o->vel[1] = v[5];
    o->vel[2] = v[6];
    o->unk140[0] = 0.008f;
    o->unk140[1] = 0.008f;
    o->unk140[2] = 0.008f;
    func_001A0000((RcefObj *)&D_00313CB0, (void *)o, 0);
    func_001A1D08(t, func_01B00D48);
    func_001A1DF0(t, 20);
}

void func_01B00D48(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.08f;
    func_001A1D08(t, func_01B007C0);
    func_001A1DF0(t, 12);
}

void func_01B00D98(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefObj *s = (RcefObj *)t->frame[t->sp].count;
    float v[8];
    float ang;
    float sc;
    float k;
    int ki;

    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    sc = (float)func_002EFD78() * 4.656612873077393e-10f * 0.15f + 0.25f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(v, s->pos);
    VEC3_COPY(&v[4], s->vel);
    k = 0.1f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(&v[4], &v[4], ki);
    o->rot[2] = ang;
    o->pos_w = 0;
    o->vel[3] = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    o->vel[0] = v[4];
    o->vel[1] = v[5];
    o->vel[2] = v[6];
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[3] = 0;
    o->scale[2] = sc;
    o->unk170[0] = 1.42f;
    o->unk170[1] = 1.11f;
    o->unk170[2] = 0.8f;
    o->unk170[3] = 1.0f;
    func_001A0000((RcefObj *)&D_00313CB0, (void *)o, 1);
    func_001A1D08(t, func_01B00F40);
    func_001A1DF0(t, 10);
}

void func_01B00F40(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.16f;
    func_001A1D08(t, func_01B007C0);
    func_001A1DF0(t, 6);
}

void func_01B00F90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int tgt;

    func_001A4288(1);
    tgt = D_00313CB0.targets[t->frame[t->sp].count];
    func_001A3800(tgt, 0);
    func_001A13A0(o, tgt, 6);
    func_001A1420(o, 0x10);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[2] = -4.0f;
    o->scale[0] = 0.3f;
    o->scale[1] = 0.3f;
    o->scale[2] = 0.3f;
    func_0019FFD0(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B007C0);
    func_001A1D50(t, func_001A20D8);
}

int func_01B01078(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B011C0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00450, D_01B00458);
    func_0019FF90(&D_00313CB0, func_01B00490);
    return 0;
}

int func_01B010E8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01110(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01138(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01160(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01188(void) { return 0; }
int func_01B01190(void) { return 0; }
int func_01B01198(void) { return 0; }
int func_01B011A0(void) { return 0; }
