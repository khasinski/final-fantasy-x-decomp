/* tu_107 0x161aa0-0x162618: high; tex_anim_old (config/tu_map.tsv) */
#define func_00162500 _hdr_func_00162500
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"
#undef func_00162500

typedef union {
    s32 w;
    char c;
} TaOldWord0;

typedef struct {
    s32 pad[0x400 / 4];
    s32 w400;
    s32 w404;
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

extern char D_0056B9B0[];
void func_00162500(int a0, int a1, int a2);

typedef struct {
    s8 b[16];
} TaBytes16;

typedef struct {
    u8 b00;
    s8 b01;
    u8 pad02[6];
    TaOldWord0 w08;
    TaBytes16 map;
} TaFileHdrOld;

typedef union {
    u16 h;
    char c;
} TaOldHalf;

typedef struct {
    s32 pad[0x400 / 4];
    TaOldWord0 w400;
    s32 w404;
    G1Sub160BA8Ent ent[8];
    TaBytes16 map;
    TaOldWord0 w5B8[4];
    TaOldHalf h5C8[4];
    TaOldHalf h5D0[4];
} TexAnimWorkOldFull;

typedef struct {
    float f00;
    float f04;
    u8 pad08[0x90 - 8];
} TaDataEntOld;

void func_00161B00(int idx, int a1, ChrParamSub *sub)
{
    TaFileHdrOld *hdr = (TaFileHdrOld *)D_0078D898[idx].p00;
    TexAnimWorkOldFull *w;
    G1Sub160BA8Ent *ent;
    int i;
    int j;
    int cnt;

    w = (TexAnimWorkOldFull *)user_malloc(0x5D8, 10, D_0056B9B0, 0x69);
    D_0078D898[idx].w04 = (s32)w;
    D_0078D898[idx].w08 = 0;
    ent = w->ent;
    for (i = 7; i >= 0; i--, ent++) {
        ent->w04 = 0;
        ent->h14 = 0;
        ent->h16 = 0;
        ent->h18 = 0;
        ent->h1A = 0;
        ent->w24 = 0;
        ent->w28 = 0;
        ent->w2C = 0;
        ent->w30 = 0;
        ent->h1C = 0;
        ent->h1E = 0;
    }
    w->map = hdr->map;
    w->w404 = a1;
    cnt = hdr->b01;
    for (i = 0; i < 16; i++) {
        if (w->map.b[i] != -1) {
            switch (w->map.b[i]) {
            case 0:
                func_00161AA0(idx, i, 2);
                func_00162500(idx, i, 0);
                break;
            case 4:
                func_00161AA0(idx, i, 0);
                func_00162500(idx, i, 0);
                break;
            case 1:
            case 3:
                func_00161AA0(idx, i, 1);
                func_00162500(idx, i, 0);
                break;
            case 2:
                func_00161AA0(idx, i, 3);
                func_00162500(idx, i, 0);
                {
                    register int mv __asm__("$8") = w->map.b[i];
                    if (mv != -1) {
                        TaDataEntOld *d = &((TaDataEntOld *)((u8 *)hdr + hdr->w08.w))[i];
                        G1Sub160BA8Ent *e = &w->ent[i];
                        *(float *)&e->w24 = d->f00;
                        *(float *)&e->w28 = d->f04;
                    }
                }
                break;
            }
            if (cnt < i + 1) {
                cnt = i + 1;
            }
        }
    }
    w->w400.w = cnt;
    for (j = 0; j < sub->h0C; j++) {
        w->w5B8[j].w = sub->ents[j].w0C;
        w->h5C8[j].h = sub->ents[j].h08;
        w->h5D0[j].h = sub->ents[j].h0A;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", chr_texanim_main_sub_old);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim_old/rodata", jtbl_0056B9E0);

typedef struct {
    s32 w00;
    s32 w04;
    s16 h08, h0A, h0C, h0E, h10, h12;
    s16 h14, h16, h18, h1A, h1C, h1E;
    s16 h20, h22;
    s32 w24, w28, w2C, w30;
} TaOldSubEnt;

u16 Ch_TextureGetImageBase(void *o, s32 i);
s32 setLoadImageTagsTexAnim(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

int chr_texanim_draw_sub_old(int index, int value)
{
    Rec78D898 *r = &D_0078D898[index];
    TexAnimWorkOld *w;
    int i;

    if (r->p00 != 0) {
        switch (*(s8 *)r->p00) {
        case 1:
            break;
        case 2:
            w = (TexAnimWorkOld *)r->w04;
            for (i = 0; i < w->w400; i++) {
                if (w->b5A8[i] != -1) {
                    TaOldSubEnt *ent = (TaOldSubEnt *)&w->ent[i];

                    if (ent->h1E == 0 && ent->h1C != 3) {
                        s32 base = Ch_TextureGetImageBase((void *)w->w404, ent->h20);

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
            break;
        }
    }
    return value;
}

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

void func_00162500(int a0, int a1, int a2)
{
    Rec78D898 *r = &D_0078D898[a0];

    if (r->p00 != 0) {
        TexAnimWorkOld *w = (TexAnimWorkOld *)r->w04;
        G1Sub160BA8Ent *ent;

        if (a1 == 1) {
            s8 *p = &w->b5A8[1];
            int n;

            for (n = 0; n < 8; n++) {
                if (*p == 1) {
                    ent = &w->ent[1];
                    ent->w04 = a2;
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
        } else {
            ent = &w->ent[a1];
            ent->w04 = a2;
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
}

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
