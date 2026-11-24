/* tu_106 0x160780-0x161aa0: high; tex_anim (config/tu_map.tsv) */
#define Sg_GetDBuffDC _hdr_Sg_GetDBuffDC
#define func_00161968 _hdr_func_00161968
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"
#undef Sg_GetDBuffDC
#undef func_00161968

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

/* Keep -fno-strict-aliasing for the original ordering of pointer/word stores. */
void func_001608D0(void) {
    int i, j;

    for (i = 0; i < 64; i++) {
        D_0078D898[i].p00 = 0;
        D_0078D898[i].w04 = 0;
        D_0078D898[i].w08 = 0;
        D_0078D898[i].b0D = 0;
        D_0078D898[i].b0E = 1;
        for (j = 31; j >= 0; j--) {
            D_0078D898[i].pad_0F[j] = 0;
        }
    }
    D_00591F48 = 0;
    D_00591F49 = -1;
}


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

extern char D_0056B960[];
void func_00161968(int a0, int a1, int a2);

typedef struct {
    s8 b[32];
} TaBytes32;

typedef struct {
    u8 b00;
    u8 b01;
    u8 pad02[6];
    s32 w08;
    TaBytes32 map;
} TaFileHdrNew;

typedef struct {
    s32 w00;
    s32 w04;
    TaSubEnt ent[64];
    TaBytes32 map;
    s32 wD28[4];
    u16 hD38[4];
    u16 hD40[4];
    s32 wD48;
} TexAnimWorkNewFull;

typedef struct {
    float f00;
    float f04;
    u8 pad08[0x110 - 8];
} TaDataEntNew;

void func_00160D30(int idx, int a1, ChrParamSub *sub)
{
    TaFileHdrNew *hdr = (TaFileHdrNew *)D_0078D898[idx].p00;
    TexAnimWorkNewFull *w;
    TaSubEnt *ent;
    int i;
    int j;
    int cnt;

    w = (TexAnimWorkNewFull *)user_malloc(0xD4C, 10, D_0056B960, 0x90);
    D_0078D898[idx].w04 = (s32)w;
    D_0078D898[idx].w08 = 0;
    for (i = 31; i >= 0; i--) {
        D_0078D898[idx].pad_0F[i] = 0;
    }
    for (i = 0; i < 64; i++) {
        ent = &w->ent[i];
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
        ent->w00 = 0;
    }
    w->map = hdr->map;
    w->w04 = a1;
    w->wD48 = 0;
    cnt = hdr->b01;
    for (i = 0; i < 32; i++) {
        if (w->map.b[i] != -1) {
            switch (w->map.b[i]) {
            case 0:
                func_00160C38(idx, i, 2);
                func_00161968(idx, i, 0);
                break;
            case 4:
                func_00160C38(idx, i, 0);
                func_00161968(idx, i, 0);
                break;
            case 1:
            case 3:
                func_00160C38(idx, i, 1);
                func_00161968(idx, i, 1);
                break;
            case 2:
                func_00160C38(idx, i, 3);
                func_00161968(idx, i, 0);
                {
                    register int mv __asm__("$8") = w->map.b[i];
                    if (mv != -1) {
                        TaDataEntNew *d = &((TaDataEntNew *)((u8 *)hdr + hdr->w08))[i];
                        TaSubEnt *e = &w->ent[i];
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
    w->w00 = cnt;
    for (j = 0; j < sub->h0C; j++) {
        w->wD28[j] = sub->ents[j].w0C;
        w->hD38[j] = sub->ents[j].h08;
        w->hD40[j] = sub->ents[j].h0A;
    }
}

typedef struct {
    s8 b[6];
} TaNewInitList;

extern TaNewInitList D_0056B988;

typedef struct {
    s16 dur;
    u8 img_idx;
    u8 rand_dur;
} TaNewKey;

typedef struct {
    s16 h00;
    s16 h02;
    s16 w;
    s16 h;
    s32 ofs;
} TaNewTex;

typedef struct {
    s32 ofs;
    s16 cnt;
    s16 pad;
} TaNewAnim;

typedef struct {
    float f00;
    float f04;
    s16 h08;
    s16 h0A;
    s16 h0C;
    s16 h0E;
    TaNewAnim anim[32];
} TaNewData;

typedef struct {
    s32 w00;
    s32 w04;
    s16 h08, h0A, h0C, h0E, h10, h12;
    s16 h14, h16, h18, h1A, h1C, h1E;
    s16 h20, h22;
    float f24, f28, f2C, f30;
} TaNewEntF;

void chr_texanim_main_sub_new(int idx)
{
    TaNewInitList pass0_list = D_0056B988;
    s8 pass1_list[48];
    TaNewTex *tex_tbl;
    Rec78D898 *r;
    int pass;
    int pass1_cnt;
    u8 *hdr;
    TexAnimWorkNewFull *w;
    int anim;
    s8 speed;
    int k;
    int i;
    int cnt;
    TaNewKey *keys;
    TaNewKey *key;
    TaNewTex *tex;

    r = &D_0078D898[idx];
    hdr = (u8 *)r->p00;
    if (hdr == 0) {
        return;
    }
    if ((u32)hdr > 0x1FFFFFFU) {
        w = (TexAnimWorkNewFull *)r->w04;
        w->wD48 = 1;
        return;
    }
    switch (*(s8 *)hdr) {
    case 1:
        break;
    case 2:
        anim = r->w08;
        speed = r->b0E;
        pass1_cnt = 0;
        pass1_list[0] = -1;
        pass0_list.b[3] = anim;
        if (anim == 1) {
            pass0_list.b[3] = -1;
        }
        if (anim == 2) {
            pass0_list.b[3] = -1;
        }
        if (anim == 21) {
            pass0_list.b[3] = -1;
        }
        for (pass = 0; pass != 2; pass++) {
            for (k = 0; ; k++) {
                if (pass == 0) {
                    anim = pass0_list.b[k];
                    if (anim == -1) {
                        break;
                    }
                    if (r->pad_0F[anim] & 2) {
                        continue;
                    }
                    if (r->pad_0F[anim] & 1) {
                        pass1_list[pass1_cnt++] = anim;
                        pass1_list[pass1_cnt] = -1;
                        continue;
                    }
                } else {
                    anim = pass1_list[k];
                    if (anim == -1) {
                        break;
                    }
                }
                w = (TexAnimWorkNewFull *)r->w04;
                if ((u32)w > 0x1FFFFFFU) {
                    w->wD48 = 2;
                    return;
                }
                tex_tbl = (TaNewTex *)(hdr + *(s32 *)(hdr + 4));
                for (i = 0; i < w->w00; i++) {
                    {
                        register int mv __asm__("$16") = w->map.b[i];
                        if (mv != -1) {
                            TaNewEntF *ent = (TaNewEntF *)&w->ent[i];
                            u32 data_ofs = *(u32 *)(hdr + 8);
                            u8 *dat_p;
                            TaNewData *dat;

                            if (data_ofs > 0x1FFFFFFU) {
                                w->wD48 = 3;
                                return;
                            }
                            __asm__("" : : "r"(mv));
                            dat_p = hdr + data_ofs;
                            if ((u32)dat_p > 0x1FFFFFFU) {
                                w->wD48 = 4;
                                return;
                            }
                            dat_p += i * sizeof(TaNewData);
                            if ((u32)dat_p > 0x1FFFFFFU) {
                                w->wD48 = 5;
                                return;
                            }
                            dat = (TaNewData *)dat_p;
                        cnt = dat->anim[anim].cnt;
                        if (cnt != 0) {
                            switch (ent->h1C) {
                            case 0:
                            case 5:
                            default:
                                keys = (TaNewKey *)(hdr + dat->anim[anim].ofs);
                                key = &keys[ent->w04];
                                if (key->dur >= 0) {
                                    ent->h14 += speed;
                                    if (ent->h14 >= key->dur + ent->h16) {
                                        ent->h14 = 0;
                                        ent->h16 = ((func_002EFD78() & 0xFF) * key->rand_dur) / 256;
                                        ent->w04++;
                                        if (ent->w04 >= cnt) {
                                            ent->w04 = 0;
                                            key = keys;
                                        }
                                    }
                                }
                                break;
                            case 1:
                            case 4:
                                {
                                    register u8 *ap __asm__("$2") = (u8 *)dat + (anim << 3);
                                    int w04;
                                    s32 ofs;
                                    int kidx;
                                    __asm__("" : "+r"(ap));
                                    w04 = ent->w04;
                                    ofs = *(s32 *)(ap + 0x10);
                                    __asm__("" : "+r"(ofs));
                                    kidx = (w04 == 0);
                                    keys = (TaNewKey *)(hdr + ofs);
                                    __asm__("" : "+r"(kidx));
                                    key = &keys[kidx];
                                }
                                break;
                            case 2:
                                keys = (TaNewKey *)(hdr + dat->anim[anim].ofs);
                                switch (ent->h1A) {
                                case 0:
                                    ent->h18 = func_002EFD78() % 90 + 60;
                                    ent->h1A = 1;
                                    ent->w04 = 0;
                                    break;
                                case 1:
                                    ent->h18 -= speed;
                                    if (ent->h18 < 0) {
                                        ent->h1A = 2;
                                        ent->h18 = 4;
                                    }
                                    break;
                                case 2:
                                    ent->h18 -= speed;
                                    if (ent->h18 < 0) {
                                        ent->w04++;
                                        if (ent->w04 < cnt) {
                                            ent->h18 = 1;
                                        } else {
                                            ent->w04--;
                                            ent->h18 = 0;
                                            ent->h1A = 0;
                                        }
                                    }
                                    break;
                                }
                                key = &keys[ent->w04];
                                break;
                            case 3:
                                keys = (TaNewKey *)(hdr + dat->anim[anim].ofs);
                                key = &keys[ent->w04];
                                if (key->dur >= 0) {
                                    ent->h14 += speed;
                                    if (ent->h14 > key->dur + ent->h16) {
                                        ent->h14 = 0;
                                        ent->h16 = ((func_002EFD78() & 0xFF) * key->rand_dur) / 256;
                                        ent->w04++;
                                        if (ent->w04 >= cnt) {
                                            ent->w04 = 0;
                                            key = keys;
                                        }
                                    }
                                }
                                ent->f2C += ent->f24;
                                ent->f30 += ent->f28;
                                tex = &tex_tbl[key->img_idx];
                                if (ent->f2C < 0.0f) {
                                    ent->f2C += tex->w;
                                }
                                if (ent->f30 < 0.0f) {
                                    ent->f30 += tex->h;
                                }
                                if (ent->f2C >= tex->w) {
                                    ent->f2C -= tex->w;
                                }
                                if (ent->f30 >= tex->h) {
                                    ent->f30 -= tex->h;
                                }
                                break;
                            }
                            {
                                u16 x;
                                u8 *img;

                                ent->h1E = 0;
                                tex = &tex_tbl[key->img_idx];
                                img = hdr + tex->ofs;
                                x = dat->h08;
                                ent->h08 = x;
                                ent->h0A = dat->h0A;
                                ent->h20 = dat->h0C;
                                ent->h0C = tex->w;
                                ent->h0E = tex->h;
                                ent->h10 = tex->h00;
                                ent->h12 = tex->h02;
                                ent->w00 = (s32)img;
                                if (ent->h1C == 3) {
                                    u8 *src = img + 0x20;
                                    u8 *dst = (u8 *)w->wD28[dat->h0C];
                                    int pitch = (s16)w->hD38[dat->h0C];
                                    int y0 = (int)ent->f30;
                                    int y;

                                    dst += (s16)x;
                                    for (y = 0; y < tex->h; y++) {
                                        int sy = (y + y0) % ent->h0E;
                                        func_002EEF1C(dst + pitch * (y + ent->h0A), src + ent->h0C * sy, ent->h0C);
                                    }
                                }
                            }
                        } else if (k == 0) {
                            ent->h1E = 1;
                        }
                        }
                    }
                }
            }
        }
        break;
    }
}

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
