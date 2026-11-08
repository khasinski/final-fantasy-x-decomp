/* tu_010 0x10d0a0-0x10d6d0: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"

typedef struct {
    /* 0x00 */ u8 unk0[0x60];
    /* 0x60 */ s32 val60;
    /* 0x64 */ u8 unk64[6];
    /* 0x6A */ u16 val6A;
    /* 0x6C */ u8 unk6C[4];
} TblEntry70; /* size 0x70 */

/* two tables (pointer + count) live at 0x6F0 and 0x6F8 of the owner struct */
typedef struct {
    /* 0x000 */ u8 unk0[0x6F0];
    /* 0x6F0 */ TblEntry70 *tblB;
    /* 0x6F4 */ s16 cntB;
    /* 0x6F6 */ s16 unk6F6;
    /* 0x6F8 */ TblEntry70 *tblA;
    /* 0x6FC */ s16 cntA;
} TblOwner;
#include "ffx/s0.h"
#include "ffx/u0.h"

void Sg_GsloadSetBase(TblEntry70 *);

s32 func_0010D0A0(int arg0, int cnt, int base, int idx)
{
    register TblEntry70 *tbl __asm__("$16") = (TblEntry70 *)arg0;
    int i;

    if (idx == -1) {
        for (i = 0; i < cnt; i++, tbl++) {
            *(u16 *)((u8 *)tbl + 0x68) = base;
            tbl->val6A = base;
            Sg_GsloadSetBase(tbl);
            if (base != -1) {
                base += *(u16 *)((u8 *)tbl + 0x66);
            }
        }
    } else {
        tbl += idx;
        *(u16 *)((u8 *)tbl + 0x68) = base;
        tbl->val6A = base;
        Sg_GsloadSetBase(tbl);
        if (base != -1) {
            base += *(u16 *)((u8 *)tbl + 0x66);
        }
    }
    return base;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10D0A0", ch_TextureLoad);

u16 Ch_TextureGetImageBase(TblOwner *o, s32 i) {
    TblEntry70 *e = o->tblA;
    if (o->cntA < i) {
        return 0;
    }
    return e[i].val6A;
}

u16 func_0010D2F0(TblOwner *o, s32 i) {
    TblEntry70 *e = o->tblB;
    if (o->cntB < i) {
        return 0;
    }
    return e[i].val6A;
}

s32 func_0010D320(TblOwner *o, s32 i) {
    TblEntry70 *e = o->tblA;
    if (o->cntA < i) {
        return 0;
    }
    return e[i].val60;
}

s32 func_0010D350(TblOwner *o, s32 i) {
    TblEntry70 *e = o->tblB;
    if (o->cntB < i) {
        return 0;
    }
    return e[i].val60;
}

s32 Ch_TextureSetImageBase(Chr *chr, s32 v, s32 w)
{
    return func_0010D0A0(chr->w6F8, chr->h6FC, w, v);
}

s32 Ch_TextureSetClutBase(Chr *chr, s32 v, s32 w)
{
    return func_0010D0A0(chr->w6F0, chr->h6F4, w, v);
}

extern s32 _m2c_func_0010D3D0_D_00307F4C __asm__("D_00307F4C");
s32 _m2c_func_0010D3D0_func_0010D320() __asm__("func_0010D320");
/* DEBT(CAST) */
void func_0010D3D0(Chr *chr) {
    u8 sp[0xA00];
    void *temp_2;

    if (chr->w708 != 0) {
        if (D_0057EAE8 != 0) {
            temp_2 = chr_texanim_draw(chr->w70C, sp, _m2c_func_0010D3D0_func_0010D320(chr, 0));
            if (temp_2 != sp) {
                (*(s64 *)((u8 *)(temp_2) + (8))) = 0;
                (*(s64 *)((u8 *)(temp_2) + (0))) = 0x70000000;
                func_002F8660(0);
                do {

                __asm__ volatile("" : : : "memory");
                } while (*(s32 *)0x10009000 & 0x100);
                func_002DBA28(_m2c_func_0010D3D0_D_00307F4C, (s32) sp);
                do {

                } while (*(volatile s32 *)0x10009000 & 0x100);
            }
        }
    }
}

void Ch_TextureLoadImage(Chr *chr, int v)
{
    ch_TextureLoad(chr->w6F8, chr->h6FC, v);
    func_0010D3D0(chr);
}

void func_0010D4D8(Chr *chr, int v)
{
    ch_TextureLoad(chr->w6F0, chr->h6F4, v);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10D0A0", Sg_GsClear);

extern void *D_00303704;
/* DEBT(CAST) */ /* DEBT(GOTO) */
int func_0010D648(u8 *chr)
{
    u8 *p;
    void *ptr;
    s8 c;

    p = (u8 *)func_00124828();
    ptr = p + 0xD2;
    D_00303704 = ptr;
    *(void **)0x00100000 = ptr;
    if (func_001AEB80() == 0 || (c = (s8)chr[0x192]) == 2) {
zero:
        return 0;
    }
    if (c == 3) {
        goto zero;
    }
    return p[0xD2];
}

TblEntry30 **Sg_PLightGetPtr(void)
{
    return &D_0057EAFC;
}
