/* EE Battle-Effect Overlay: group 0x11, file 09239
 * Load base: 0x01B00000, .text: 0x01B004D0..0x01B01050 (24 functions)
 *
 * Seven bolts picked in random order from the caster's lightning table, each
 * fired at a target (or a jittered random target) and finished with a flash.
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00450[];
extern int D_01B00458[];
extern int D_01B00478[];
extern u8 D_01B00498[0x38];
extern int D_01B01060;
extern int D_01B01064;
extern float D_01B01070[7][4];
extern int D_01B010E0[7];
extern int D_01B01100[7];
extern int D_01B01100_a[7] __asm__("D_01B01100");
extern int D_01B01100_b[7] __asm__("D_01B01100");
extern u8 D_01B01120[];
extern int D_01B01100_m[7] __asm__("D_01B01100"); /* DEBT(FAKE): same object, keeps the address from being CSE'd into the loop */
extern s32 D_00313E48;
extern s32 D_00313E4C;
extern s32 D_00313E50_a[] __asm__("D_00313E50");

void *func_002EF0D0(void *dst, int val, int size);
int func_002EFD78(void);
void func_001A3000(int chr_id, int idx, float *out);
void func_001A3568(float *out);

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");
void func_01B006F8(W3Task *t);
void func_01B00740(W3Task *t);
void func_01B00798(W3Task *t);
void func_01B007E8(W3Task *t);
void func_01B00848(W3Task *t);
void func_01B00908(W3Task *t);
void func_01B00938(W3Task *t);
void func_01B00948(W3Task *t);
void func_01B00A20(W3Task *t);
void func_01B00C80(W3Task *t);
void func_01B00D00(W3Task *t);
void func_01B00E00(W3Task *t);
void func_01B00EB0(W3Task *t);
void func_01B00EE8(W3Task *t);

void func_01B004D0(W3Task *t)
{
    float d[4];
    int i;
    int idx;
    int *slot;
    float *vp;
    float k;
    int ki;

    D_01B01060 = 0;
    D_01B01064 = 0;
    func_002EF0D0(D_01B010E0, 0, 28);
    func_002EF0D0(D_01B01100_m, 0, 28);
    for (i = 0; i < 7; i++) {
        do {
            idx = func_002EFD78() % 7;
            slot = &D_01B010E0[idx];
        } while (*slot != 0);
        if (i < D_00313CB0.target_count) {
            func_001A3000(D_00313E50_a[i], 6, D_01B01070[idx]);
            D_01B010E0[idx] = 1;
            D_01B01100_a[idx] = D_00313E50_a[i];
        } else {
            func_001A3000(D_00313E50_a[func_002EFD78() % D_00313CB0.target_count], 0, D_01B01070[idx]);
            func_001A3568(d);
            k = (float)func_002EFD78() * 4.656612873077393e-10f * 10.0f + 10.0f;
            MIPS_MFC1(ki, k);
            VEC3_SCALE(d, d, ki);
            vp = D_01B01070[idx];
            VEC3_ADD(vp, vp, d);
            *slot = 2;
            D_01B01100_b[idx] = -1;
        }
    }
    func_001A1D08(t, func_01B006F8);
    func_001A1D50(t, func_001A2058);
}

void func_01B006F8(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00740);
    func_001A1D50(t, func_001A2098);
}

void func_01B00740(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00EB0);
    func_001A2B80(D_00313CB0.caster, 114);
    func_001A1D20(t, func_01B00798);
}

void func_01B00798(W3Task *t)
{
    func_001A1D08(t, func_01B007E8);
    func_001A1DF0(t, D_01B00478[D_01B01060]);
}

void func_01B007E8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00948);
    func_0019FF90(&D_00313CB0, func_01B00A20);
    func_001A1D08(t, func_01B00848);
}

void func_01B00848(W3Task *t)
{
    int caster = D_00313E48;

    if (++D_01B01060 < 7) {
        func_001A1D20(t, func_01B00798);
    } else {
        if (++D_01B01064 < 2) {
            D_01B01060 = 0;
            func_001A1D08(t, func_01B00740);
            func_001A1D50(t, func_001A2148);
            t->frame[t->sp].count = caster;
        } else {
            func_001A1D08(t, func_01B00908);
            func_001A1D50(t, func_001A2148);
            t->frame[t->sp].count = caster;
        }
    }
}

void func_01B00908(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00938);
}

void func_01B00938(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00948(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, D_01B00458[D_01B01060]);
    o->pos[0] = -1.9f;
    o->pos[1] = 0;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = 90.0f;
    o->rot_w = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00938);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00A20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float q[4];
    float r[4];
    float n[4];
    float m[4];
    float k;
    register int ki __asm__("$2"); /* DEBT(FAKE): original register assignment */
    register float *mp __asm__("$3"); /* DEBT(FAKE) */
    register int ki3 __asm__("$3"); /* DEBT(FAKE) */

    t->frame[t->sp].count = D_01B01060;
    t->frame[t->sp].arg1 = D_01B01064;
    o->flagsBC |= 0x2000;
    func_001A2F00(D_00313CB0.caster, D_01B00458[D_01B01060], p);
    VEC3_COPY(q, D_01B01070[D_01B01060]);
    VEC3_SUB(n, q, p);
    rcVec3fNormalize((Vec4 *)n);
    k = 14.0f;
    mp = m;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(mp, n, ki);
    VEC3_SUB(p, p, m);
    k = 18.0f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(mp, n, ki);
    VEC3_SUB(q, q, m);
    VEC3_SUB(r, q, p);
    k = 0.1f;
    MIPS_MFC1(ki3, k);
    VEC3_SCALE(r, r, ki3);
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->pos_w = 0;
    o->vel[0] = r[0];
    o->vel[1] = r[1];
    o->vel[2] = r[2];
    o->vel[3] = 0;
    o->rot[0] = 90.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.05f;
    o->scale[1] = 0.4f;
    o->scale[2] = 0.05f;
    o->scale[3] = 0;
    o->unk140[0] = -0.00049f;
    o->unk140[1] = 0.01f;
    o->unk140[2] = -0.0049f;
    o->unk14C_w = 0;
    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.09f;
    rcefMainKickPar(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B00C80);
    func_001A1DF0(t, 10);
}

void func_01B00C80(W3Task *t)
{
    W3Task *r = func_0019FF90_t(&D_00313CB0, func_01B00D00);

    r->frame[r->sp].count = t->frame[t->sp].count;
    r->frame[r->sp].arg1 = t->frame[t->sp].arg1;
    t->flags |= 4;
}

void func_01B00D00(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int idx = t->frame[t->sp].count;
    float *v = D_01B01070[idx];
    int st = D_01B010E0[idx];

    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    *(float *)&o->pos_w = 0;
    o->scale[0] = 0.2f;
    o->scale[3] = 0;
    o->scale[1] = 0.2f;
    o->scale[2] = 0.2f;
    rcefMainKickPar(&D_00313CB0, o, 0, st);
    if (st == 1) {
        func_001A1D08(t, func_01B00E00);
        func_001A1DF0(t, 2);
    } else {
        func_001A1D08(t, func_01B00938);
        func_001A1D50(t, func_001A20D8);
    }
}

void func_01B00E00(W3Task *t)
{
    int b = t->frame[t->sp].count;
    int a = t->frame[t->sp].arg1;

    func_001A4288(1);
    if (a == 0) {
        func_001A3800(D_01B01100[b], 8);
    } else {
        func_001A3800(D_01B01100[b], 0);
    }
    func_001A1D08(t, func_01B00938);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00EB0(W3Task *t)
{
    func_001A1D08(t, func_01B00EE8);
    func_001A1DF0(t, 32);
}

void func_01B00EE8(W3Task *t)
{
    func_001A4288(0);
    t->flags |= 4;
}

int func_01B00F20(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01120, 0x01E80000, 0x00080000, 0x01D00000, 1, D_01B00450, D_01B00498);
    func_0019FF90(&D_00313CB0, func_01B004D0);
    return 0;
}

int func_01B00F90(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00FB8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00FE0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01008(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01030(void) { return 0; }
int func_01B01038(void) { return 0; }
int func_01B01040(void) { return 0; }
int func_01B01048(void) { return 0; }
