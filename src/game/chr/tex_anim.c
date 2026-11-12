/* tu_106 0x160780-0x161aa0: high; tex_anim (config/tu_map.tsv) */
#define Sg_GetDBuffDC _hdr_Sg_GetDBuffDC
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"
#undef Sg_GetDBuffDC

void func_00161A20(int a0, int a1, int a2, int a3);
void Sg_GetDBuffDC(s32 *p);

void tex_anim_pos_set(int a) {
    switch (D_0078D898[a].b0D) {
    case 0:
        func_00162500(a);
        break;
    case 1:
        func_00161968(a);
        break;
    }
}

void tex_anim_no_set(int a, int b, int c) {
    switch (D_0078D898[a].b0D) {
    case 0:
        func_001625B0(a, b, c & 0xFF);
        break;
    case 1:
        func_00161A20(a, b, c & 0xFF, (c >> 8) & 0xFF);
        break;
    }
}

int func_00160808(int i) {
    return D_0078D898[i].b0D;
}

void chr_texanim_main(int a) {
    switch (D_0078D898[a].b0D) {
    case 0:
        chr_texanim_main_sub_old(a);
        break;
    case 1:
        chr_texanim_main_sub_new(a);
        break;
    }
}

s32 chr_texanim_draw(s32 arg0, s32 arg1)
{
    s32 result;
    s8 kind;

    kind = D_0078D898[arg0].b0D;
    switch (kind)
    {
    case 0:
        result = chr_texanim_draw_sub_old(arg0, arg1);
        arg1 = result;
        break;
    case 1:
        result = chr_texanim_draw_sub_new(arg0, arg1);
        arg1 = result;
        break;
    }
    return arg1;
}

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_001608D0);

void func_00160978(void)
{
    if (D_00591F48 && D_00591F49 >= 0) {
        chr_movie_main(D_00591F49);
    }
}

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
void func_001609A8() {
}

void func_0015A568(s32 a0, s32 a1);
void func_0015BBF8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
void func_0015C068(s32 a0);

void func_001609B0(s32 x, s32 y, s32 c, s32 a3, s32 a4)
{
    s32 tbl[2];
    s32 idx;
    s32 p2 = a3 + 0x400;

    tbl[0] = 0x1A0;
    tbl[1] = 0;
    if (a4 == 0) {
        Sg_GetDBuffDC(&idx);
        idx &= 1;
        func_0015A568(a3, c);
        func_0015BBF8(p2, a3, x, y + tbl[idx], 0x10, 0x10, 0x200, 0, 0, 0, 0);
        func_0015C068(p2);
        func_002DA610(0, 0);
    } else {
        for (idx = 0; idx < 2; idx++) {
            func_0015A568(a3, c);
            func_0015BBF8(p2, a3, x, y + tbl[idx], 0x10, 0x10, 0x200, 0, 0, 0, 0);
            func_0015C068(p2);
            func_002DA610(0, 0);
        }
    }
}

void func_00160B10(s32 x, s32 y, u8 *str, s32 a3, s32 a4)
{
    u8 c;

    func_002DA610(0, 0);
    while ((c = *str++) != 0) {
        if ((u32)(c - 0x20) < 0x60) {
            func_001609B0(x, y, c, a3, a4);
        }
        x += 0x10;
    }
}

void func_00160BA8(void)
{
    if (func_0020D540()) {
        func_001609A8(0x20, 0x4C, D_0056B950);
    }
}

int func_00160BE0(int a) {
    if (FFXIsPC() == 1) {
        return func_2072900(a);
    }
    return 0;
}

int func_00160C20(void) {
    return 0x1FA0040;
}

int func_00160C30(void) {
    return 0x60000;
}

void func_00160C38(int a0, int a1, int a2) {
    Rec78D898 *r = &D_0078D898[a0];

    if (r->p00 != 0) {
        G1Sub160BA8Ent *ent = &((G1Sub160BA8Hdr *)r->w04)->ent[a1]; /* DEBT(CAST): Rec78D898.w04 is s32 in q3.h */

        ent->h1C = a2;
        ent->w04 = 0;
        ent->h14 = 0;
        ent->h16 = 0;
        ent->w24 = 0;
        ent->w28 = 0;
        ent->w2C = 0;
        ent->w30 = 0;
        ent->h18 = 0;
        ent->h1A = 0;
    }
}

void tex_anim_timer(int i, s8 v) {
    D_0078D898[i].b0E = v;
}

typedef struct {
    s32 w00;
    s32 w04;
    s16 h08, h0A, h0C, h0E, h10, h12;
    s16 h14, h16, h18, h1A, h1C, h1E;
    s16 h20, h22;
    s32 w24, w28, w2C, w30;
} TaSubEnt;

typedef union {
    s32 w;
    char c;
} TaWord0;

typedef struct {
    s32 w00;
    s32 w04;
    TaSubEnt ent[64];
    s8 bD08[32];
    TaWord0 wD28[8];
    s32 wD48;
} TexAnimWorkNew;

void func_00160CB8(int a, int idx)
{
    ChrParamSub *sub = (ChrParamSub *)a;
    TexAnimWorkNew *w;
    int i = 0;

    *(TaWord0 *)&D_0078D898[idx].p00 = *(TaWord0 *)((u8 *)sub + 0x20);
    w = (TexAnimWorkNew *)D_0078D898[idx].w04;
    if (sub->h0C != 0) {
        do {
            w->wD28[i] = *(TaWord0 *)&sub->ents[i].w0C;
            i++;
        } while (i < sub->h0C);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_00160D30);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim/rodata", jtbl_0056B970);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", chr_texanim_main_sub_new);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim/rodata", jtbl_0056B990);

u16 Ch_TextureGetImageBase(void *o, s32 i);
s32 setLoadImageTagsTexAnim(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
s32 Ch_GetName(Chr *chr);

int chr_texanim_draw_sub_new(int index, int value)
{
    Rec78D898 *r = &D_0078D898[index];
    int start = value;
    TexAnimWorkNew *w;
    int i;

    if (r->p00 != 0) {
        switch (*(s8 *)r->p00) {
        case 1:
            break;
        case 2:
            w = (TexAnimWorkNew *)r->w04;
            if (w->wD48 == 0) {
                for (i = 0; i < w->w00; i++) {
                    if (w->bD08[i] != -1) {
                        TaSubEnt *ent = &w->ent[i];

                        if (ent->h1E == 0 && ent->h1C != 3 && ent->w00 != 0) {
                            s32 base = Ch_TextureGetImageBase((void *)w->w04, ent->h20);

                            value = setLoadImageTagsTexAnim(
                                value,
                                ent->w00,
                                ent->h08,
                                ent->h0A,
                                ent->h0C,
                                ent->h0E,
                                ent->h10,
                                base
                            );
                        }
                    }
                }
            } else {
                func_0020D540();
            }
            break;
        }
    }
    if (value - start >= 0xA00) {
        Ch_GetName(Ch_TextureAnimGetHandle(index));
    }
    return value;
}

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_00161968);

void func_00161A20(int a0, int a1, int a2, int a3) {
    if (a1 == 4) {
        Rec78D898 *r = &D_0078D898[a0];

        if (r->p00 != 0) {
            r->pad_0F[a2] = a3;
            if (r->w08 == 0 || r->w08 != a2) {
                G1Sub160BA8Ent *ent = ((G1Sub160BA8Hdr *)r->w04)->ent; /* DEBT(CAST): Rec78D898.w04 is s32 in q3.h */
                int i;

                r->w08 = a2;
                for (i = 0; i < 64; i++, ent++) {
                    ent->w04 = 0;
                    ent->h14 = 0;
                    ent->h16 = 0;
                    ent->h18 = 0;
                    ent->w2C = 0;
                    ent->w30 = 0;
                    ent->h1A = 0;
                }
            }
        }
    }
}
