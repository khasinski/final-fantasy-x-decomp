/* tu_013 0x10ea50-0x110158: low; ~Sg (config/tu_map.tsv) */
#define func_0010EF98 _hdr_func_0010EF98
#define func_0010F060 _hdr_func_0010F060
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_0010EF98
#undef func_0010F060

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010EA50(s32 v)
{
    D_0057EB58 = v;
}

void func_0010EA60(s8 v)
{
    D_0057EB40 = v;
}

void func_0010EA70(s8 v)
{
    D_0057EB44 = v;
}

void func_0010EA80(s8 v)
{
    D_0057EB41 = v;
}

void func_0010EA90(u8 v)
{
    D_0057EB49 = v;
}

void func_0010EAA0(s8 a, s8 b, s8 c)
{
    D_0057EB46 = a;
    D_0057EB47 = b;
    D_0057EB48 = c;
}

void func_0010EAC0(s8 v)
{
    D_0057EB43 = v;
}

void func_0010EAD0(s8 v)
{
    D_0057EB45 = v;
}

void func_0010EAE0(s8 v)
{
    D_0057EB42 = v;
}

void func_0010EAF0(float v)
{
    D_0057EB4C = v;
}

void func_0010EB00(float v)
{
    D_0057EB50 = v;
}

void func_0010EB10(s8 a, s8 b, s8 c, s8 d)
{
    D_0057EB54 = a;
    D_0057EB55 = b;
    D_0057EB56 = c;
    D_0057EB57 = d;
}

s32 func_0010EB38(void)
{
    return (yiGetRenderStatus() >> 14) & 1;
}

void func_0010EB60(s32 v)
{
    D_0057EB7C = v;
}

void func_0010EB70(float v)
{
    D_0057EB8C = (s32)(v * 128.0f);
}

void func_0010EB90(float a, float b, float c)
{
    D_0057EB80 = a;
    D_0057EB84 = b;
    D_0057EB88 = c;
}

s32 *func_0010EBB0(void)
{
    return &D_0057EBA0;
}

void func_0010EBC0(void)
{
    D_00303714 = (D_00303714 + 1) & 1;
}

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
    float f[4];
} QwPkt;

typedef union {
    u_long128 q;
    struct {
        u64 NLOOP : 15;
        u64 EOP   : 1;
        u64 pad16 : 16;
        u64 id    : 14;
        u64 PRE   : 1;
        u64 PRIM  : 11;
        u64 FLG   : 2;
        u64 NREG  : 4;
        u64 REGS0 : 4;
        u64 REGS1 : 4;
        u64 REGS2 : 4;
        u64 REGS3 : 4;
        u64 REGS4 : 4;
        u64 REGS5 : 4;
        u64 REGS6 : 4;
        u64 REGS7 : 4;
        u64 REGS8 : 4;
        u64 REGS9 : 4;
        u64 REGS10: 4;
        u64 REGS11: 4;
        u64 REGS12: 4;
        u64 REGS13: 4;
        u64 REGS14: 4;
        u64 REGS15: 4;
    } bf;
} GifTagBF;

extern u64 D_0057EB90[2];
void func_00173828(float *a, float *b, float *c);

void *func_0010EBD8(QwPkt *pkt)
{
    GifTagBF tag0;
    GifTagBF tag1;
    float f0, f1, f2;
    u8 *p;

    pkt->d[1] = 0;
    pkt->d[0] = 0x1000001A;
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0x11000000;
    pkt->w[3] = 0x51000008;
    pkt++;

    pkt->d[0] = 0x1000000000008007ULL;
    pkt->d[1] = 0xE;
    pkt++;

    pkt->d[0] = 0x5000F;
    pkt->d[1] = 0x47;
    pkt++;

    pkt->d[0] = 0x0000008000000068ULL;
    pkt->d[1] = 0x42;
    pkt++;

    pkt->d[0] = 0;
    pkt->d[1] = 0x49;
    pkt++;

    pkt->d[0] = 5;
    pkt->d[1] = 0x14;
    pkt++;

    pkt->d[1] = 0x3F;
    pkt++;

    pkt->d[0] = 5;
    pkt->d[1] = 0x8;
    p = (u8 *)func_001176F0();
    pkt++;

    pkt->d[0] = *(u64 *)(p + 0x18);
    pkt->d[1] = 6;
    D_0057EB90[0] = 0x1000000000000001ULL;
    D_0057EB90[1] = (D_0057EB44 != 0) ? 0xE : 0xF;
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C010027;
    pkt++;
    pkt->d[0] = D_0057EB90[0];
    pkt->d[1] = D_0057EB90[1];
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C010213;
    pkt++;
    pkt->d[0] = D_0057EB90[0];
    pkt->d[1] = D_0057EB90[1];
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C0100DE;
    pkt++;
    pkt->d[0] = D_0057EB90[0];
    pkt->d[1] = D_0057EB90[1];
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C0102CA;
    pkt++;
    pkt->d[0] = D_0057EB90[0];
    pkt->d[1] = D_0057EB90[1];
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C010028;
    pkt++;
    pkt->d[0] = *(u64 *)(p + 0x18);
    pkt->d[1] = 0x16;
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C010214;
    pkt++;
    pkt->d[0] = *(u64 *)(p + 0x18);
    pkt->d[1] = 0x16;
    pkt++;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C010026;
    func_00173828(&f0, &f1, &f2);
    pkt++;

    pkt->f[0] = -(255.0f / (f1 - f0));
    pkt->f[1] = 255.0f - f2;
    pkt->f[2] = -f0;
    pkt->w[3] = 0;
    pkt++;

    tag0.bf.NLOOP = 0;
    tag0.bf.EOP = 0;
    tag0.bf.PRE = 1;
    tag0.bf.PRIM = 0x50;
    tag0.bf.FLG = 0;
    tag0.bf.NREG = 3;
    tag0.bf.REGS0 = 2;
    tag0.bf.REGS1 = 1;
    tag0.bf.REGS2 = 4;

    tag1 = tag0;
    tag0.bf.PRIM |= 4;
    tag1.bf.PRIM |= 3;

    pkt->d[0] = 0;
    pkt->w[2] = 0;
    pkt->w[3] = 0x6C020024;
    pkt++;

    pkt->q = tag0.q;
    pkt++;
    pkt->q = tag1.q;
    return pkt + 1;
}

void *func_0010EF98(QwPkt *pkt)
{
    pkt->q = 0;
    pkt->w[3] = 0x51000007;
    pkt++;
    pkt->d[0] = 0x6000000000008001UL;
    pkt->d[1] = 0x0EEEEEEE;
    pkt++;
    pkt->d[0] = 0x7000F;
    pkt->d[1] = 0x48;
    pkt++;
    pkt->d[0] = 0x44;
    pkt->d[1] = 0x43;
    pkt++;
    pkt->d[0] = 0;
    pkt->d[1] = 0x49;
    pkt++;
    if (D_00303714) {
        pkt->d[0] = 0x25;
    } else {
        pkt->d[0] = 0x5;
    }
    pkt->d[1] = 0x15;
    pkt++;
    pkt->d[0] = 0;
    pkt->d[1] = 0x9;
    pkt++;
    pkt->d[0] = 0x1;
    pkt->d[1] = 0x46;
    return pkt + 1;
}

s32 _m2c_func_0010F060_func_0010EBD8(s32) __asm__("func_0010EBD8");
void _m2c_func_0010F060_func_0010EF98(s32 *) __asm__("func_0010EF98");
extern u_long128 _m2c_func_0010F060_D_00578E00 __asm__("D_00578E00");
/* DEBT(CAST) */
s32 func_0010F060(u_long128 *arg0) {
    _m2c_func_0010F060_func_0010EF98(&D_0057EBA0);
    *arg0 = _m2c_func_0010F060_D_00578E00;
    return _m2c_func_0010F060_func_0010EBD8(((u_long128 *)((u8 *)arg0 + (0x10))));
}

/* DEBT(CAST) */
void *func_0010F0A8(void *arg0) {
    (*(s64 *)((u8 *)(arg0) + (0))) = 0x10000001;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0x11000000;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0x11000000;
    arg0 = (u8 *)arg0 + 0x10;
    (*(s64 *)((u8 *)(arg0) + (8))) = 0x11000000;
    (*(s64 *)((u8 *)(arg0) + (0))) = 0;
    return (u8 *)arg0 + 0x10;
}

void *func_0010F0D8(QwPkt *pkt, s32 idx)
{
    u8 *p = ((u8 **)D_0057EB7C)[idx];
    QwPkt unused;

    pkt->d[0] = 0x10000002;
    pkt->w[2] = 0x10000000;
    pkt->w[3] = 0x6C010023;
    pkt++;
    pkt->f[0] = (float)p[4] * D_0057EB80 * 2.0f;
    pkt->f[1] = (float)p[5] * D_0057EB84 * 2.0f;
    pkt->f[2] = (float)p[6] * D_0057EB88 * 2.0f;
    pkt->f[3] = (float)D_0057EB8C;
    pkt++;
    pkt->d[0] = 0x14000000;
    pkt->d[1] = 0;
    return pkt + 1;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F1A0);

extern s32 D_0057EB70;
extern s32 D_0057EB78;

s32 func_0010F308(QwPkt *pkt, s32 mode)
{
    s32 ret = 0;

    if (mode == 0 && D_0057EB70 != 0) {
        D_0057EB70 = 0;
        mode = 1;
    } else {
        D_0057EB70 = mode;
    }
    if (mode == 1) {
        pkt->d[0] = 0;
        pkt->w[2] = 0;
        pkt->w[3] = 0x6C010027;
        pkt++;
        pkt->d[0] = D_0057EB90[0];
        pkt->d[1] = D_0057EB90[1];
        pkt++;
        {
            register s32 p78 __asm__("$3") = D_0057EB78;
            if (p78 != 0) {
                register u_long128 z __asm__("$4") = 0;
                register u8 *p __asm__("$5") = (u8 *)p78;
                register u64 c17 __asm__("$7") = 0x17;
                register u32 tag2 __asm__("$2");
                pkt->q = z;
                pkt->w[3] = 0x6C0100DF;
                pkt++;
                pkt->d[0] = *(u64 *)(p + 0x18);
                pkt->d[1] = c17;
                pkt++;
                tag2 = 0x6C0102CB;
                pkt->q = z;
                pkt->w[3] = tag2;
                pkt++;
                pkt->d[0] = *(u64 *)(p + 0x18);
                pkt->d[1] = c17;
            } else {
                pkt->q = 0;
                pkt->w[3] = 0x6C0100DF;
                pkt++;
                pkt->d[0] = 0;
                pkt->d[1] = 1;
                pkt++;
                pkt->q = 0;
                pkt->w[3] = 0x6C0102CB;
                pkt++;
                pkt->d[0] = 0;
                pkt->d[1] = 1;
            }
        }
        ret = 6;
    } else if (mode == 2) {
        u8 *p = (u8 *)D_0057EB78;
        if (p != 0) {
            pkt->q = 0;
            pkt->w[3] = 0x6C010027;
            pkt++;
            pkt->d[0] = *(u64 *)(p + 0x18);
            pkt->d[1] = 0x17;
            ret = 2;
        }
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F468);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", Sg_VectorToMatrix);

typedef union QwVec4 {
    float f[4];
    u64 d[2];
    u_long128 q;
} QwVec4;

extern float D_00303760[4][4];
extern QwVec4 D_0057EC20[4];
extern QwVec4 D_0057EC60;
extern QwVec4 D_0057EC70;
extern float D_0057EB4C;
extern float D_0057EB50;
void func_00119548(float *);
void func_002DCF00(void *, void *);

typedef struct Dst10F818 {
    u8 pad0[0x1D0];
    u32 w1D0;
    u32 w1D4;
    u32 w1D8;
    u32 w1DC;
    u_long128 q1E0;
    u_long128 q1F0;
    u_long128 q200;
    u_long128 q210;
    u_long128 q220;
} Dst10F818;

void func_0010F818(Dst10F818 *dst)
{
    float mat0[4][4];
    float mat1[4][4];

    func_002DD128(mat1);
    mat1[2][2] = 1000.0f;
    mat1[1][1] = 1000.0f;
    mat1[0][0] = 1000.0f;
    func_002DCE38(mat0, D_00303760, mat1);
    func_00119548(D_0057EC60.f);
    D_0057EC60.f[0] -= mat0[3][0];
    D_0057EC60.f[1] -= mat0[3][1];
    D_0057EC60.f[2] -= mat0[3][2];
    D_0057EC70.d[0] = D_0057EC60.d[0];
    D_0057EC70.d[1] = D_0057EC60.d[1];
    func_002DCF00(mat0, mat0);
    func_002DCE08(D_0057EC60.f, mat0, D_0057EC60.f);
    D_0057EC60.f[0] *= -1000.0f;
    D_0057EC60.f[1] *= -1000.0f;
    D_0057EC60.f[2] *= -1000.0f;
    func_002DCE08(D_0057EC70.f, mat0, D_0057EC70.f);
    func_002DCEC8(D_0057EC70.f, D_0057EC70.f);
    Sg_VectorToMatrix((float (*)[4])D_0057EC20, D_0057EC70.f, 0x12);
    func_002DCF00(D_0057EC20, D_0057EC20);
    D_0057EC60.f[3] = D_0057EB4C;
    D_0057EC70.f[3] = D_0057EB50;
    dst->w1D0 = (u8)D_0057EB54;
    dst->w1D4 = (u8)D_0057EB55;
    dst->w1D8 = (u8)D_0057EB56;
    dst->w1DC = (u8)D_0057EB57;
    dst->q220 = D_0057EC70.q;
    dst->q210 = D_0057EC60.q;
    dst->q1E0 = D_0057EC20[0].q;
    dst->q1F0 = D_0057EC20[1].q;
    dst->q200 = D_0057EC20[2].q;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010F9E0(u8 v)
{
    D_0057EB74 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", Ch_CreateVu1Packet);
