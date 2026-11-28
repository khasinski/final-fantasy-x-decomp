/* tu_020 0x113938-0x113ff8: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void func_00113938(s16 v)
{
    D_0057F620 = v;
}

void func_00113948(s16 v)
{
    D_0057F624 = v;
}

void func_00113958(s16 v)
{
    D_0057F628 = v;
}

void func_00113968(s16 v)
{
    Ch_EffectTexAttr = v;
}

typedef struct G0Slot16 {
    s8 b0;
    s8 b1;
    s16 h2;
    s32 w4;
    void *p8;
    s32 wC;
} G0Slot16; /* DEBT(NAME) */

void func_00113978(void)
{
    G0Slot16 *s = (G0Slot16 *)D_0057F60C; /* DEBT(CAST) */

    if (s != 0) {
        s->b0 = 0;
        s->b1 = -1;
        s->wC = 0;
        s->p8 = 0;
        s->h2 = 0;
        D_0057F60C += 0x10;
    } else {
        D_0057F610 += 0x10;
    }
}

typedef struct {
    u16 v;
    u16 n;
    u16 u;
    u16 t;
} EffectVtx;

typedef struct {
    u8 b00;
    u8 b01;
    u16 h02;
    u8 b04;
    u8 b05;
    u8 b06;
    u8 b07;
    u32 w08;
    u32 w0C;
    u8 b10;
    u8 b11;
    u8 pad12[0xE];
} EffectPolyHdr;

typedef struct {
    u8 pad00[8];
    u16 w;
    u16 h;
    u8 pad0C[5];
    u8 b11;
    u8 b12;
    u8 pad13[5];
    u32 w18;
    u32 w1C;
} EffectTexInfo;

typedef struct {
    u16 v0;
    u16 v1;
    u16 v2;
    u16 h06;
    u16 u0;
    u16 t0;
    u16 u1;
    u16 t1;
    u16 u2;
    u16 t2;
    u16 n0;
    u16 n1;
    u16 n2;
    u16 pad1A;
} EffectPolyEnt;

extern EffectPolyHdr *D_0057F608;
extern EffectTexInfo *D_0057F630;
extern s32 D_003036A8;
extern s32 D_0057F614;
extern s32 D_0057F618;
extern s32 D_0057F61C;
extern s16 D_0057F622;
extern s16 D_0057F626;
extern s16 D_0057F62A;
extern s16 Ch_EffectPrevTexAttr;

#define EFF_MAX(a, b) ((a) > (b) ? (a) : (b))

void Ch_EffectPacketStorePoly(EffectVtx *a0, EffectVtx *a1, EffectVtx *a2)
{
    if (D_0057F620 != D_0057F622 || D_0057F624 != D_0057F626 ||
        D_0057F628 != D_0057F62A || Ch_EffectTexAttr != Ch_EffectPrevTexAttr) {
        D_0057F622 = D_0057F620;
        D_0057F626 = D_0057F624;
        D_0057F62A = D_0057F628;
        Ch_EffectPrevTexAttr = Ch_EffectTexAttr;
        if (D_0057F60C != 0) {
            D_0057F630 = D_003036A8 != 0 ? (EffectTexInfo *)D_003036A8 + D_0057F620 : 0;
            D_0057F608 = (EffectPolyHdr *)D_0057F60C;
            D_0057F608->b00 = 0;
            D_0057F608->h02 = 0;
            D_0057F608->b01 = 0x10;
            D_0057F608->b04 = 0xC0;
            D_0057F608->b05 = 0xC0;
            D_0057F608->b06 = 0xC0;
            D_0057F608->b07 = 0x7F;
            if (D_0057F630 != 0) {
                D_0057F608->w08 = D_0057F630->w18;
                D_0057F608->w0C = D_0057F630->w1C;
                D_0057F608->b10 = D_0057F630->b11;
                D_0057F608->b11 = D_0057F630->b12;
            } else {
                D_0057F608->w0C = 0;
                D_0057F608->w08 = 0;
                D_0057F608->b10 = 0x44;
                D_0057F608->b11 = 0x80;
            }
            D_0057F60C += 0x20;
        } else {
            D_0057F610 += 0x20;
        }
    }
    if (D_0057F60C != 0) {
        EffectPolyEnt *e = (EffectPolyEnt *)D_0057F60C;

        e->h06 = 0;
        e->v0 = a0->v;
        e->v1 = a1->v;
        e->v2 = a2->v;
        e->n0 = a0->n;
        e->n1 = a1->n;
        e->n2 = a2->n;
        if (D_0057F630 != 0) {
            EffectTexInfo *tex = D_0057F630;
            e->u0 = (s32)((a0->u * 4096.0f) / (tex->w * 16.0f));
            e->t0 = (s32)((a0->t * 4096.0f) / (tex->h * 16.0f));
            e->u1 = (s32)((a1->u * 4096.0f) / (tex->w * 16.0f));
            e->t1 = (s32)((a1->t * 4096.0f) / (tex->h * 16.0f));
            e->u2 = (s32)((a2->u * 4096.0f) / (tex->w * 16.0f));
            e->t2 = (s32)((a2->t * 4096.0f) / (tex->h * 16.0f));
        }
        D_0057F60C += 0x1C;
        D_0057F608->h02++;
    } else {
        D_0057F610 += 0x1C;
        D_0057F618 = EFF_MAX(EFF_MAX(EFF_MAX(a0->v, a1->v), a2->v), D_0057F618);
        D_0057F61C = EFF_MAX(EFF_MAX(EFF_MAX(a0->n, a1->n), a2->n), D_0057F61C);
        D_0057F614++;
    }
}

s32 func_00113EE8(void)
{
    return D_0057F60C;
}

typedef struct EffectPacketHdr {
    struct EffectPacketHdr *w00;
    struct EffectPacketHdr *w04;
    s32 w08;
    s32 w0C;
    u16 h10;
    u16 h12;
    u16 h14;
    char b16;
    char b17;
} EffectPacketHdr;

extern EffectPacketHdr *D_0057F604;
s32 sg_getvtex(void);
s32 sg_getnorm(void);

void Ch_EffectPacketSetPtr(int v)
{
    D_0057F60C = v;
    D_0057F622 = -1;
    D_0057F626 = -1;
    D_0057F62A = -1;
    Ch_EffectPrevTexAttr = -1;
    if (v != 0) {
        s32 next = D_0057F60C + 0x20;

        ((EffectPacketHdr *)v)->w04 = (EffectPacketHdr *)(next - v);
        D_0057F60C = next;
        ((EffectPacketHdr *)v)->w00 = 0;
        D_0057F604 = (EffectPacketHdr *)v;
        D_0057F604->w08 = sg_getvtex() - (s32)D_0057F604;
        D_0057F604->w0C = sg_getnorm() - (s32)D_0057F604;
        D_0057F604->h10 = D_0057F614;
        D_0057F604->h12 = D_0057F618 + 1;
        D_0057F604->h14 = D_0057F61C + 1;
        D_0057F604->b16 = 0;
        D_0057F604->b17 = 0;
    } else {
        D_0057F610 = 0x20;
        D_0057F614 = 0;
        D_0057F618 = 0;
        D_0057F61C = 0;
    }
}

s32 Ch_EffectPacketGetSize(void)
{
    return D_0057F610;
}
