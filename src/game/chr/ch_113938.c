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
    D_0057F62C = v;
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

INCLUDE_ASM("build/ee_asm/game/chr/ch_113938", Ch_EffectPacketStorePoly);

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
extern s32 D_0057F614;
extern s32 D_0057F618;
extern s32 D_0057F61C;
extern s16 D_0057F622;
extern s16 D_0057F626;
extern s16 D_0057F62A;
extern s16 D_0057F62E;
s32 sg_getvtex(void);
s32 sg_getnorm(void);

void Ch_EffectPacketSetPtr(int v)
{
    D_0057F60C = v;
    D_0057F622 = -1;
    D_0057F626 = -1;
    D_0057F62A = -1;
    D_0057F62E = -1;
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
