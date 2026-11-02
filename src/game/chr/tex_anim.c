/* tu_106 0x160780-0x161aa0: high; tex_anim (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"

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

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", tex_anim_no_set);

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

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_001609B0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_00160B10);

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

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_00160CB8);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", func_00160D30);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim/rodata", jtbl_0056B970);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", chr_texanim_main_sub_new);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim/rodata", jtbl_0056B990);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim", chr_texanim_draw_sub_new);

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
