/* tu_107 0x161aa0-0x162618: high; tex_anim_old (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"

typedef union {
    s32 w;
    char c;
} TaOldWord0;

typedef struct {
    s32 pad[0x408 / 4];
    G1Sub160BA8Ent ent[8];
    s8 b5A8[16];
    TaOldWord0 w5B8[1];
} TexAnimWorkOld;

void func_00161AA0(int a0, int a1, int a2)
{
    Rec78D898 *r = &D_0078D898[a0];

    if (r->p00 != 0) {
        G1Sub160BA8Ent *ent = &((TexAnimWorkOld *)r->w04)->ent[a1];

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

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00161B00);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim_old/rodata", jtbl_0056B9C0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", chr_texanim_main_sub_old);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim_old/rodata", jtbl_0056B9E0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", chr_texanim_draw_sub_old);

void func_00162488(int a, int idx)
{
    ChrParamSub *sub = (ChrParamSub *)a;
    TexAnimWorkOld *w;
    int i = 0;

    *(TaOldWord0 *)&D_0078D898[idx].p00 = *(TaOldWord0 *)((u8 *)sub + 0x20);
    w = (TexAnimWorkOld *)D_0078D898[idx].w04;
    if (sub->h0C != 0) {
        do {
            w->w5B8[i] = *(TaOldWord0 *)&sub->ents[i].w0C;
            i++;
        } while (i < sub->h0C);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00162500);

/* DEBT(NAME): 0x34-byte sub entries at (Rec78D898.w04 + 0x408); this is tex_anim_no_set_new (ffx-rust) */
typedef struct TaSub34 {
    u8 pad0[4];
    s32 w04;
    u8 pad08[0xC];
    s16 h14, h16, h18, h1A;
    u8 pad1C[0x10];
    s32 w2C, w30;
} TaSub34;

void func_001625B0(int i, int mode, int v)
{
    Rec78D898 *r;
    TaSub34 *s;
    int n;

    if (mode == 4) {
        r = &D_0078D898[i];
        if (r->p00 != 0) {
            r->w08 = v;
            s = (TaSub34 *)(r->w04 + 0x408);
            for (n = 7; n >= 0; n--) {
                s->w04 = 0;
                s->h14 = 0;
                s->h16 = 0;
                s->h18 = 0;
                s->w2C = 0;
                s->w30 = 0;
                s->h1A = 0;
                s++;
            }
        }
    }
}
