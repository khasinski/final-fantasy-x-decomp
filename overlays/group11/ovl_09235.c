/* EE Battle-Effect Overlay: group 0x11, file 09235
 * Load base: 0x01B00000, .text: 0x01B00490..0x01B01150 (26 functions)
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00450[];
extern u8 D_01B00458[0x38];
extern int D_01B01158;
extern u8 D_01B01160[];
extern s32 D_00313E48;
extern s32 D_00313E4C;

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

float rcVec3fLength(Vec4 *v);
#define VEC3_SCALE_L(d, a, ki) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tqmtc2.ni %2, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%0)\n1:" \
                     : : "r"(d), "r"(a), "r"(ki) : "memory")

void func_001A2CC0(int chr);
void func_001A2C88(int a0, int a1, int a2, int a3);
void func_001A2CA0(int chr, int a1, int a2);
void func_001A2CB8(int chr);
void func_001A3000(int chr_id, int idx, float *out);
void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
void func_001A0000_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0000");
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B004E0(W3Task *t);
void func_01B00528(W3Task *t);
void func_01B00590(W3Task *t);
void func_01B00628(W3Task *t);
void func_01B006C8(W3Task *t);
void func_01B00790(W3Task *t);
void func_01B007D0(W3Task *t);
void func_01B007E0(W3Task *t);
void func_01B008A8(W3Task *t);
void func_01B00A20(W3Task *t);
void func_01B00B40(W3Task *t);
void func_01B00CF8(W3Task *t);
void func_01B00D48(W3Task *t);
void func_01B00EF0(W3Task *t);
void func_01B00F40(W3Task *t);

void func_01B00490(W3Task *t)
{
    D_01B01158 = 0;
    func_001A2CC0(D_00313E48);
    func_001A1D08(t, func_01B004E0);
    func_001A1D50(t, func_001A2058);
}

void func_01B004E0(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00528);
    func_001A1D50(t, func_001A2098);
}

void func_01B00528(W3Task *t)
{
    func_001A2C88(D_00313CB0.caster, D_00313CB0.targets[D_01B01158], 1, 2);
    func_001A1D08(t, func_01B00590);
    func_001A1DF0(t, 3);
}

void func_01B00590(W3Task *t)
{
    func_001A2B80(D_00313E48, 186);
    func_001A1D08(t, func_01B00628);
    func_001A1DF0(t, 22);
}

void func_01B005D8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B007E0);
    func_001A1D08(t, func_01B00628);
    func_001A1DF0(t, 1);
}

void func_01B00628(W3Task *t)
{
    W3Task *r;

    func_0019FF90(&D_00313CB0, func_01B007E0);
    r = func_0019FF90_t(&D_00313CB0, func_01B008A8);
    r->frame[r->sp].count = D_01B01158;
    func_001A1D08(t, func_01B006C8);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = D_00313CB0.caster;
}

void func_01B006C8(W3Task *t)
{
    int caster = D_00313CB0.caster;

    if (++D_01B01158 < D_00313CB0.target_count) {
        func_001A2B80(caster, 187);
        func_001A1D20(t, func_01B00528);
    } else {
        func_001A2B80(caster, 188);
        func_001A2CA0(caster, 2, 4);
        func_001A1D08(t, func_01B00790);
        func_001A1D50(t, func_001A2148);
        t->frame[t->sp].count = caster;
    }
}

void func_01B00790(W3Task *t)
{
    func_001A2CB8(D_00313E48);
    func_001A2B68();
    func_001A1D08(t, func_01B007D0);
}

void func_01B007D0(W3Task *t)
{
    t->flags |= 4;
}

void func_01B007E0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 15);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = 1.0f;
    o->pos[2] = -2.5f;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.55f;
    o->scale[1] = 0.55f;
    o->scale[2] = 0.55f;
    o->scale[3] = 0;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B007D0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B008A8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float q[4];
    float n[4];
    float k;
    register int steps __asm__("$3");
    int ki;
    int chr;
    register int spx __asm__("$2");

    chr = D_00313CB0.targets[t->frame[t->sp].count];
    func_001A2F00(D_00313CB0.caster, 15, p);
    func_001A3000(chr, 6, q);
    VEC3_SUB(n, q, p);
    steps = (int)(rcVec3fLength((Vec4 *)n) / 6.0f);
    k = 1.0f / (float)steps;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(n, n, ki);
    spx = t->sp;
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    o->vel[0] = n[0];
    o->vel[1] = n[1];
    o->vel[2] = n[2];
    o->vel[3] = 0;
    o->scale[0] = 0.17f;
    o->scale[1] = 0.17f;
    o->scale[2] = 0.17f;
    o->scale[3] = 0;
    t->frame[spx].arg1 = steps;
    func_001A4288(0);
    func_0019FFD0(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00A20);
}

void func_01B00A20(W3Task *t)
{
    W3Task *r;

    t->frame[t->sp].arg1--;
    if (t->frame[t->sp].arg1 > 0) {
        r = func_0019FF90_t(&D_00313CB0, func_01B00B40);
        r->frame[r->sp].count = (int)t;
        r = func_0019FF90_t(&D_00313CB0, func_01B00D48);
        r->frame[r->sp].count = (int)t;
        r = func_0019FF90_t(&D_00313CB0, func_01B00D48);
        r->frame[r->sp].count = (int)t;
    } else {
        int c;

        r = func_0019FF90_t(&D_00313CB0, func_01B00F40);
        c = t->frame[t->sp].count;
        r->frame[r->sp].count = c;
        t->flags |= 4;
    }
}

void func_01B00B40(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefObj *par = (RcefObj *)t->frame[t->sp].count;
    float p[4];
    float q[4];
    float a;
    float b;
    float c;
    float k;
    int ki;

    a = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    b = (float)func_002EFD78() * 4.656612873077393e-10f * 0.15f + 0.15f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(p, par->pos);
    VEC3_COPY(q, par->vel);
    k = 0.06f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE_L(q, q, ki);
    c = (float)func_002EFD78() * 4.656612873077393e-10f * 0.1f + 0.1f;
    q[1] = q[1] - c;
    o->rot[2] = a;
    o->scale[0] = b;
    o->scale[1] = b;
    o->scale[2] = b;
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    o->vel[0] = q[0];
    o->vel[1] = q[1];
    o->vel[2] = q[2];
    o->vel[3] = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->unk140[0] = 0.008f;
    o->unk140[1] = 0.008f;
    o->unk140[2] = 0.008f;
    o->unk14C_w = 0;
    func_001A0000_k(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00CF8);
    func_001A1DF0(t, 20);
}

void func_01B00CF8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.08f;
    func_001A1D08(t, func_01B007D0);
    func_001A1DF0(t, 12);
}

void func_01B00D48(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    RcefObj *par = (RcefObj *)t->frame[t->sp].count;
    float p[4];
    float q[4];
    float a;
    float b;
    float k;
    int ki;

    a = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    b = (float)func_002EFD78() * 4.656612873077393e-10f * 0.15f + 0.25f;
    o->flagsBC |= 0x4000;
    VEC3_COPY(p, par->pos);
    VEC3_COPY(q, par->vel);
    k = 0.1f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(q, q, ki);
    o->rot[2] = a;
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    o->vel[0] = q[0];
    o->vel[1] = q[1];
    o->vel[2] = q[2];
    o->vel[3] = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[0] = b;
    o->scale[1] = b;
    o->scale[2] = b;
    o->scale[3] = 0;
    o->unk170[0] = 1.42f;
    o->unk170[1] = 1.11f;
    o->unk170[2] = 0.8f;
    o->unk170[3] = 1.0f;
    func_001A0000_k(&D_00313CB0, o, 1);
    func_001A1D08(t, func_01B00EF0);
    func_001A1DF0(t, 10);
}

void func_01B00EF0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.16f;
    func_001A1D08(t, func_01B007D0);
    func_001A1DF0(t, 6);
}

void func_01B00F40(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int chr = D_00313CB0.targets[t->frame[t->sp].count];

    func_001A3800(chr, 0);
    func_001A13A0(o, chr, 6);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos[2] = -4.0f;
    o->pos_w = 0;
    o->scale[0] = 0.3f;
    o->scale[1] = 0.3f;
    o->scale[2] = 0.3f;
    o->scale[3] = 0;
    func_0019FFD0(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B007D0);
    func_001A1D50(t, func_001A20D8);
}

int func_01B01020(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01160, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00450, D_01B00458);
    func_0019FF90(&D_00313CB0, func_01B00490);
    return 0;
}

int func_01B01090(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B010B8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B010E0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01108(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01130(void) { return 0; }
int func_01B01138(void) { return 0; }
int func_01B01140(void) { return 0; }
int func_01B01148(void) { return 0; }
