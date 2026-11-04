/* tu_009 0x10ad70-0x10d0a0: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", Ch_Check);

void func_0010AE48(void) {
}

s32 func_0010AE50(s32 v)
{
    s8 old = D_0057EA08;

    D_0057EA08 = v & 1;
    if (v != old && ffx_debugmode) {
        func_2035A80();
    }
    return old;
}

s8 func_0010AEA0(void)
{
    return D_0057EA08;
}

s8 func_0010AEB0(s32 v)
{
    s8 old = D_00303690;

    D_00303690 = v & 1;
    return old;
}

void func_0010AEC8(void)
{
    D_00303690 = ((u8)D_00303690 + 1) & 1; /* DEBT(TYPE): read as unsigned here, signed elsewhere */
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010AEE0);

void func_0010AF88(Chr *chr, float v)
{
    chr->f188 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010AF90);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B230);

void func_0010B318(s32 v)
{
    D_0057EABC = v & 0x1;
}

s8 func_0010B328(void)
{
    return D_0057EABC;
}

void func_0010B338(s32 v)
{
    D_0057EABD = v & 0x1;
}

s8 func_0010B348(void)
{
    return D_0057EABD;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B358);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B558);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B6D0);

void Ch_DrawEnEffect(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 13, v);
}

void func_0010B7A8(Chr *chr, s32 i, void *dst)
{
    if (dst) {
        ChrSlotData *d = chr->ents[i].data;

        func_002DCE38(dst, chr->u1F0, chr->slots[d->h0].u90);
    }
}

void *Ch_ModelGetBaseMatrix(Chr *chr, s32 i, void *dst)
{
    ChrSlotData *d = chr->ents[i].data;
    u8 *p = chr->slots[d->h0].u90;

    if (dst) {
        func_002DD0C0(dst, p);
    }
    return p;
}

s32 Ch_ModelCalcSizeEffectPacket(Chr *chr, int i)
{
    ChrEnt *e = &chr->ents[i];

    D_003036A8 = 0;
    Ch_EffectPacketSetPtr(0);
    Ch_EffectPacketCreateMain(e);
    return Ch_EffectPacketGetSize();
}

void Ch_ModelCreateEffectPacket(Chr *chr, s32 index, s32 value)
{
    ChrEnt *entry;

    entry = &chr->ents[index];
    CALL_func_00123878_INT(entry->w08, entry->w04);
    D_003036A8 = D_0057EA08 ? chr->w6EC : 0;
    func_0010B6D0(chr);
    Ch_EffectPacketSetPtr(value);
    Ch_EffectPacketCreateMain(entry);
}

s32 Ch_GetNbModel(Chr *chr)
{
    ChrHdr *hdr = chr->hdr;

    if (hdr->h04 >= 0x831) {
        return hdr->h06;
    }
    return 0;
}

u16 func_0010B948(Chr *chr)
{
    return chr->hdr->h0A;
}

s32 *func_0010B958(void)
{
    return &D_003036B0;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010B968(s32 v)
{
    D_003036A0 = v;
}

R0Pkt *func_0010B978(int unused, R0Pkt *p)
{
    p->w0 = 0x30000008;
    p->w4 = (u32)func_0010EBB0(); /* DEBT(TYPE): getter returns s32 * */
    p->q8 = 0;
    return p + 1;
}

void func_0010B9B8(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 40, v);
}

void func_0010B9E8(s8 v)
{
    D_0057EAE8 = v;
}

s8 Sg_GuiGetTextureAnim(void)
{
    return D_0057EAE8;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010BA08);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010BA90);

s8 func_0010BE28(void)
{
    return D_0057EAE9;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010BE38);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010BFA0);

void Ch_DrawSetCull(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 19, v);
}

void func_0010C078(s8 v)
{
    EnableClothSystem = v;
}

s8 func_0010C088(void)
{
    return EnableClothSystem;
}

void func_0010C098(void) {
}

void func_0010C0A0(s8 v)
{
    D_003036A5 = v;
}

s8 func_0010C0B0(void)
{
    return D_003036A5;
}

void func_0010C0C0(s8 v)
{
    D_003036A6 = v;
}

s8 func_0010C0D0(void)
{
    return D_003036A6;
}

void func_0010C0E0(s8 v)
{
    D_003036A7 = v;
}

s8 func_0010C0F0(void)
{
    return D_003036A7;
}

u8 func_0010C100(void)
{
    return D_0057EAEA;
}

u8 func_0010C110(void)
{
    return D_0057EAEB;
}

void Ch_DrawSetShadowMode(u8 v)
{
    D_0057EAEA = v;
}

void func_0010C130(u8 v)
{
    D_0057EAEB = v;
}

void func_0010C140(s8 a, s8 b, s8 c)
{
    D_0057EAEC = a;
    D_0057EAED = b;
    D_0057EAEE = c;
}

void func_0010C160(s32 *a, s32 *b, s32 *c)
{
    if (a) {
        *a = D_0057EAEC;
    }
    if (b) {
        *b = D_0057EAED;
    }
    if (c) {
        *c = D_0057EAEE;
    }
}

void func_0010C198(s32 a, s32 b)
{
    D_0057EAF0 = a;
    D_0057EAF4 = b;
}

void func_0010C1B0(s32 *a, s32 *b)
{
    if (a != 0) {
        *a = D_0057EAF0;
    }
    if (b != 0) {
        *b = D_0057EAF4;
    }
}

void func_0010C1D8(Chr *chr, s32 v)
{
    chr->w6E4 = v;
}

s32 func_0010C1E0(Chr *chr)
{
    return chr->w6E4;
}

void Ch_DrawCalcShade(Chr *chr, float *x, float *y, float *z)
{
    float s;

    if (EnableClothSystem) {
        s = chr->f358 * chr->f364;
    } else {
        s = chr->f358;
    }
    *x = chr->f328 * s * chr->fC0;
    *y = chr->f334 * s * chr->fC4;
    *z = chr->f340 * s * chr->fC8;
}

float Ch_DrawGetModelAlpha(Chr *chr, s32 i)
{
    if (i == -1) {
        return chr->f34C;
    }
    return chr->ents[i].f14 * chr->f34C;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010C278);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010C6B0);

void Ch_DrawInitAll(void)
{
    func_0010AE50(1);
    func_00107B78(0);
    func_0010AEE0();
}

s32 func_0010C768(Chr **a, Chr **b)
{
    return (*a)->w6E0 - (*b)->w6E0;
}

void func_0010C780(s8 v)
{
    D_0057EAF8 = v;
}

void Ch_DrawSetSituation(Chr *chr, s8 v)
{
    chr->b193 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010C798);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010CA88);

extern char D_00569618[];
extern void func_0011EDA8(int addr, int size, void *p);
extern void func_00123C6C(void);

int func_0010D008(void)
{
    func_0011EDA8(0x1100C000, 0x4000, D_00569618);
    SYNC();
    EI();
    func_00123C6C();
    return 0;
}

extern volatile int D_003036F4;
extern void func_0011ACD8(void);

int func_0010D048(void)
{
    if ((*(volatile u32 *)0x10009000 & 0xFFFF0000) == 0xF0000000) {
        D_003036F4++;
        func_0011ACD8();
    }
    SYNC();
    EI();
    return 0;
}
