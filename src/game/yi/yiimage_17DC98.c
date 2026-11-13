/* tu_130 0x17dc98-0x180618: low; ~yiImage (config/tu_map.tsv) */
#define func_00180370 _hdr_func_00180370
#define func_00180520 _hdr_func_00180520
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"
#undef func_00180370
#undef func_00180520

void yiImage_GSSInit(int a, int mode)
{
    switch (mode) {
    case 0:
        D_0030ECB8 = D_0030ECC8 = 0;
        D_0030ECD8 = 0x90000;
        D_0030ECBC = D_0030ECCC = D_0030ECDC = 0;
        D_0030ECEC = D_0030ECF0 = 0x90000;
        D_0030ECF4 = 0x9C000;
        break;
    case 1:
        D_0030ECB8 = D_0030ECC8 = 0x1C000;
        D_0030ECD8 = 0xAC000;
        D_0030ECBC = D_0030ECCC = D_0030ECDC = 0;
        D_0030ECEC = D_0030ECF0 = 0xAC000;
        D_0030ECF4 = 0xB8000;
        break;
    case 2:
        D_0030ECB8 = D_0030ECC8 = 0;
        D_0030ECD8 = 0x60000;
        D_0030ECBC = D_0030ECCC = 0x84000;
        D_0030ECDC = 0xB4000;
        D_0030ECEC = D_0030ECF0 = 0x60000;
        D_0030ECF4 = 0x68000;
        break;
    }
    D_0030ECC0 = D_0030ECD0 = 0xBC000;
    D_0030ECE0 = 0xE0000 - (a << 14);
    D_0030ECC4 = D_0030ECD4 = 0xF0000;
    D_0030ECE4 = 0x100000;
    D_0030ECE8 = 0xFFFFFFFF;
}

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", yiImage_printusemem);

/* DEBT(FAKE) */
s32 func_0017DF50(void) {
    register s32 var_2 __asm__("$2");

    var_2 = 0;
    if (D_0030ECD4 != D_0030ECE4) {
        var_2 = D_0030ECD4 != 0xF0000;
    }
    return var_2;
}

void func_0017DF80(s32 arg0) {
    D_0030ECE0 = 0xE0000 - (arg0 << 0xE);
}

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017DF98);
INCLUDE_RODATA("build/ee_asm/game/yi/yiimage_17DC98/rodata", jtbl_0056C840);

s32 func_0017E558(s32 arg0) {
    u32 temp_2 = D_0030ECD0;
    u32 temp_3_2 = temp_2 + (((arg0 + 0x3F) / 64) << 6);
    if ((u32) D_0030ECE0 >= temp_3_2) {
        D_0030ECD0 = temp_3_2;
        return temp_2 >> 6;
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017E5A8);
INCLUDE_RODATA("build/ee_asm/game/yi/yiimage_17DC98/rodata", jtbl_0056C860);

extern u8 D_0065FC10;

int func_0017E688(Q3Res *a, YiImage *b) {
    u32 diff = (u32)(D_0030ECF4 - D_0030ECEC) >> 8;

    if (diff < b->h) {
        return 0;
    }
    if (D_0030ECF0 == D_0030ECEC) {
        D_0065FC10 = 0;
        switch (a->psm) {
        case 0x14:
            D_0065FC10 = 1;
            a->psm = 0x2C;
            break;
        case 0x13:
            a->psm = 0x1B;
            break;
        default:
            return 0;
        }
        a->h = diff;
        a->bp = (u32)D_0030ECEC >> 6;
        D_0030ECF0 = D_0030ECF4;
    } else {
        if (D_0065FC10 != 0) {
            switch (a->psm) {
            case 0x14:
                a->psm = 0x24;
                a->bp = (u32)D_0030ECEC >> 6;
                a->h = diff;
                D_0065FC10 = 0;
                return 1;
            }
        }
        return 0;
    }
}

extern s32 _m2c_func_0017E758_D_0030ECA0 __asm__("D_0030ECA0");
void func_0017E758(s32 arg0, s32 arg1) {
    _m2c_func_0017E758_D_0030ECA0 = D_0030ECA4 = arg0;
    D_0030ECA8 = arg1;
    D_0030ECAC = 0;
    D_0030ECB0 = 0;
}

int func_0017E788(S2Ctx *ctx, S2Disp *d, int a2) {
    u8 buf[0x60];
    u16 idx;

    switch (d->type) {
    case 0x14:
    case 0x24:
    case 0x2C:
        d->h134 = D_0030ECB0;
        if (d->h134 == 0) {
            if (ctx->mode >= 2) {
                if (ctx->mode < 5) {
                    D_0030ECB4 = func_0018AAB8();
                    D_0030ECAC = func_0018AAC8(ctx->mode);
                }
            } else {
                D_0030ECAC = yiImage_GSmallocclut(0x100);
            }
        }
        d->w12C = D_0030ECAC;
        d->h138 = D_0030ECB4;
        if (ctx->mode >= 2) {
            if (ctx->mode < 5) {
                func_0018B5A8(ctx, a2, d->h138, d->h134);
            }
        }
        func_002DA928(buf, d->w12C, 1, 0, (d->h134 & 1) << 3, (s16)((d->h134 >> 1) << 1), 8, 2);
        D_0030ECB0++;
        if (D_0030ECB0 >= 0x10) {
            D_0030ECB0 = 0;
        }
        break;
    case 0x13:
    case 0x1B:
        if (ctx->mode < 2) {
            d->w12C = yiImage_GSmallocclut(0x100);
        } else if (ctx->mode < 5) {
            d->h138 = func_0018AAB8();
            d->w12C = func_0018AAC8(ctx->mode);
            func_0018B558(ctx, a2, d->h138);
        }
        d->h134 = 0;
        func_002DA928(buf, d->w12C, 1, 0, 0, 0, 0x10, 0x10);
        break;
    default:
        return 0;
    }
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(buf, a2);
}

u32 func_0017E9D0(void) {
    return D_0030ECA4;
}

int yiImage_GSmallocclut(int n) {
    u32 p = D_0030ECA4;

    D_0030ECA4 = p + ((u32)(n + 63) >> 6);
    if (D_0030ECA4 > D_0030ECA8) {
        yiAssert(0, D_0056C928, D_0056C940);
    } else {
        return p;
    }
}

void func_0017EA28(Obj17DBA0 *o) {
    o->w00 = 0;
    o->w114 = 0;
    o->w110 = 0;
    o->b04 = D_0056C958;
    o->w170 = 0;
    o->w144 = 0;
    o->w174 = 0;
    o->w124 = 0xFFFFFFFF;
}

int func_0017EA60(int mask) {
    int first = -1;
    int i;

    for (i = 0; i < 16; i++) {
        if ((mask >> i) & 1) {
            if (first != -1) {
                first = i + 1;
            } else {
                first = i;
            }
        }
    }
    return first;
}

int func_0017EAB0(int mask) {
    int first = -1;
    int i;

    for (i = 0; i < 16; i++) {
        if ((mask >> i) & 1) {
            if (first != -1) {
                return 0;
            }
            first = i;
        }
    }
    return 1;
}

int func_0017EAF8(int a) {
    return a - 1;
}

int func_0017EB00(int a) {
    int v = a / 64;

    if (v <= 0) {
        v = 1;
    }
    return v;
}

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017EB28);

int func_0017EDC8(Sys597F00 *s, YiImage *img) {
    u32 i;
    u32 psm;
    int size;
    YiImage *p;

    for (i = 0; i < s->w9E7D8; i++) {
        if (!(s->res[i].used & 2)) {
            psm = s->res[i].psm;
            if (psm == SCE_GS_PSMT4HL || psm == SCE_GS_PSMT4HH) {
                psm = SCE_GS_PSMT4;
            }
            if (psm == SCE_GS_PSMT8H) {
                psm = SCE_GS_PSMT8;
            }
            if (psm == img->psm && func_0017F630(s, &s->res[i], img)) {
                break;
            }
        }
    }
    if (i < s->w9E7D8) {
        for (p = s->res[i].list; p->next != 0; p = p->next) {
        }
        p->next = img;
        img->bp = s->res[i].bp;
        img->tbw = s->res[i].tbw;
        img->psm = s->res[i].psm;
        img->res = i;
        return 1;
    }
    s->res[s->w9E7D8].used = 1;
    s->res[s->w9E7D8].psm = img->psm;
    s->res[s->w9E7D8].tbw = 4;
    s->res[s->w9E7D8].w18 = 0;
    s->res[s->w9E7D8].list = 0;
    s->res[s->w9E7D8].w = 256;
    s->res[s->w9E7D8].h = 256;
    s->res[s->w9E7D8].list = img;
    switch (s->res[s->w9E7D8].psm) {
    default:
        yiAssert(0, D_0056C960, D_0056C978);
        return 0;
    case SCE_GS_PSMCT32: /* size is never used; it keeps one table entry per mode */
        size = 256 * 256 * 4;
        break;
    case SCE_GS_PSMCT24:
        size = 256 * 256 * 3;
        break;
    case SCE_GS_PSMCT16:
        size = 256 * 256 * 2;
        break;
    case SCE_GS_PSMT8:
        size = 256 * 256;
        break;
    case SCE_GS_PSMT4:
        size = 256 * 256 / 2;
        break;
    }
    func_0017E5A8(&s->res[s->w9E7D8]);
        if (s->res[s->w9E7D8].bp == -1 && !func_0017E688(&s->res[s->w9E7D8], img)) {
            func_0017F790(s);
            yiAssert(0, D_0056C960, D_0056C990, img->w, img->h, img->name);
        }
        img->bp = s->res[s->w9E7D8].bp;
        img->tbw = s->res[s->w9E7D8].tbw;
        img->psm = s->res[s->w9E7D8].psm;
        img->y = 0;
        img->x = 0;
        img->res = s->w9E7D8;
        s->w9E7D8++;
        return 1;
}

int func_0017F148(int a) {
    int i;

    for (i = 0; i < 16; i++) {
        if ((1 << i) >= a) {
            return 1 << i;
        }
    }
    return 0;
}

int yiImageRman_foecrentry(Sys597F00 *s, YiImage *img) {
    int w;
    int h;
    int size;

    if (img->w < 64 || (img->w & 63)) {
        return -1;
    }
    s->res[s->w9E7D8].used = 1;
    s->res[s->w9E7D8].psm = img->psm;
    s->res[s->w9E7D8].tbw = func_0017F148(img->w) / 64;
    s->res[s->w9E7D8].w18 = 0;
    s->res[s->w9E7D8].list = 0;
    w = s->res[s->w9E7D8].w = func_0017F148(img->w);
    h = s->res[s->w9E7D8].h = func_0017F148(img->h);
    s->res[s->w9E7D8].list = img;
    switch (s->res[s->w9E7D8].psm) {
    case 20:
        size = w * h / 8;
        break;
    case 19:
        size = w * h / 4;
        break;
    case 2:
        size = w * h / 2;
        break;
    case 0:
    case 1:
        size = w * h;
        break;
    default:
        yiAssert(0, D_0056C960, D_0056C978);
        return 0;
    }
    s->res[s->w9E7D8].bp = yiImage_printusemem(size, s->res[s->w9E7D8].psm);
    if (s->res[s->w9E7D8].bp == -1) {
        func_0017F790(s);
        yiAssert(0, D_0056C960, D_0056CA08);
    }
    img->bp = s->res[s->w9E7D8].bp;
    img->tbw = s->res[s->w9E7D8].tbw;
    img->psm = s->res[s->w9E7D8].psm;
    img->y = 0;
    img->x = 0;
    img->res = s->w9E7D8;
    s->w9E7D8++;
    return 1;
}

int func_0017F448(Q3Res *r, YiImage *list, YiImage *img) {
    int x0 = img->x;
    int y0 = img->y;
    int x1 = x0 + img->w - 1;
    int y1 = y0 + img->h - 1;
    YiImage *p;

    if (x1 >= r->w || y1 >= r->h) {
        return 0;
    }
    if (x0 < 0 || y0 < 0) {
        return 0;
    }
    if (func_0017EAB0(img->w) && (u32)img->x % img->w) {
        return 0;
    }
    if (func_0017EAB0(img->h) && (u32)img->y % img->h) {
        return 0;
    }
    for (p = list; p != 0; p = p->next) {
        int px0, py0, px1, py1;

        if (p == img) {
            continue;
        }
        px0 = p->x;
        py0 = p->y;
        px1 = px0 + p->w - 1;
        py1 = py0 + p->h - 1;
        if ((x0 >= px0 && x0 <= px1) || (x1 >= px0 && x1 <= px1) || (px0 >= x0 && px0 <= x1) || (px1 >= x0 && px1 <= x1)) {
            if ((y0 >= py0 && y0 <= py1) || (y1 >= py0 && y1 <= py1) || (py0 >= y0 && py0 <= y1) || (py1 >= y0 && py1 <= y1)) {
                break;
            }
        }
    }
    return p == 0;
}

int func_0017F630(Sys597F00 *s, Q3Res *r, YiImage *img) {
    YiImage *p;

    for (p = r->list; p != 0; p = p->next) {
        img->x = p->x + p->w;
        img->y = p->y;
        if (func_0017F448(r, r->list, img)) {
            return 1;
        }
        img->x = p->x;
        img->y = p->y + p->h;
        if (func_0017F448(r, r->list, img)) {
            return 1;
        }
        img->x = p->x - img->w;
        img->y = p->y;
        if (func_0017F448(r, r->list, img)) {
            return 1;
        }
        img->x = p->x;
        img->y = p->y - img->h;
        if (func_0017F448(r, r->list, img)) {
            return 1;
        }
    }
    img->x = 0;
    img->y = r->h - img->h;
    if (func_0017F448(r, r->list, img)) {
        return 1;
    }
    img->x = r->w - img->w;
    img->y = r->h - img->h;
    return func_0017F448(r, r->list, img) != 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017F790);

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017FA08);

INCLUDE_ASM("build/ee_asm/game/yi/yiimage_17DC98", func_0017FC80);

typedef struct YiImgRec {
    u32 flags;
    char name[0x104];
    u32 bp;
    u16 psm;
    u16 tbw;
    u32 w110;
    u32 w114;
    s32 res;
    s32 x;
    s32 y;
    u8 pad_124[8];
    u32 cbp;
    u8 pad_130[4];
    u16 csa;
    u8 pad_136[6];
    u32 w;
    u32 h;
    u8 *texData;
    int clutData;
    u8 pad_14C[0x24];
    struct YiImgRec *next;
    u32 w174;
} YiImgRec;

typedef struct YiImgMgr {
    u8 pad_00000[0x9E7D0];
    u32 n9E7D0;
    YiImgRec *imgs9E7D4;
} YiImgMgr;

extern char D_0056CCE0[];
extern char D_0056CCF8[];
void func_0017EB28(Sys597F00 *s, YiImgRec *img);

int yiImage_readonlyTIM1(Sys597F00 *s, YiImgRec *img)
{
    u8 buf[0x60];

    if (!func_0017EDC8(s, (YiImage *)img)) { /* DEBT(CAST) */
        img->flags |= 2;
        yiAssert(0, D_0056CCE0, D_0056CCF8);
        return -1;
    }
    func_002DA928(buf, (s16)img->bp, (s16)img->tbw, (s16)img->psm, (s16)img->x, (s16)img->y, (s16)img->w, (s16)img->h);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(buf, (int)img->texData);
    func_0017E788((S2Ctx *)s, (S2Disp *)img, img->clutData); /* DEBT(CAST) */
    func_002DA610(0, 0);
    func_0017EB28(s, img);
    img->flags |= 0x10;
    return 0;
}

int func_001801A0(Sys597F00 *s, YiImgRec *img)
{
    u8 buf[0x60];

    if (!yiImageRman_foecrentry(s, (YiImage *)img)) { /* DEBT(CAST) */
        img->flags |= 2;
        yiAssert(0, D_0056CCE0, D_0056CCF8);
        return -1;
    }
    func_002DA928(buf, (s16)img->bp, (s16)img->tbw, (s16)img->psm, (s16)img->x, (s16)img->y, (s16)img->w, (s16)img->h);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(buf, (int)img->texData);
    func_0017E788((S2Ctx *)s, (S2Disp *)img, img->clutData); /* DEBT(CAST) */
    func_0017EB28(s, img);
    img->flags |= 0x10;
    return 0;
}

int func_00180270(Sys597F00 *s, YiImgRec *img)
{
    u8 *p;
    u32 x;
    u32 y;

    switch (img->psm) {
    case 0:
        break;
    case 0x14:
        p = img->texData;
        for (y = 0; y < img->h; y++) {
            for (x = 0; x < img->w / 2; x++, p++) {
                *p = (*p << 4) | (*p & 0xF);
            }
        }
        break;
    case 0x13:
        p = img->texData;
        for (y = 0; y < img->h; y++) {
            for (x = 0; x < img->w / 2; x++, p += 2) {
                p[1] = p[0];
            }
        }
        break;
    }
}

void func_00180370(void)
{
}

void *func_0017DBA0(int size);

int func_00180378(Sys597F00 *s, YiImgRec *img)
{
    u8 *p;
    u8 *dst;
    u8 *buf;
    int size;
    u32 x;
    u32 y;

    size = img->h * img->w;
    switch (img->psm) {
    case 0:
        return;
    case 0x14:
        buf = func_0017DBA0(size / 4);
        dst = buf;
        p = img->texData;
        for (y = 0; y < img->h; y++) {
            for (x = 0; x < img->w / 4; x++, dst++) {
                u8 c0 = *p++ & 0xF;
                u8 c1 = *p++ & 0xF;
                *dst = c0 | (c1 << 4);
            }
        }
        break;
    case 0x13:
        buf = func_0017DBA0(size / 2);
        dst = buf;
        p = img->texData;
        for (y = 0; y < img->h; y++) {
            for (x = 0; x < img->w / 2; x++, p += 2, dst++) {
                *dst = *p;
            }
        }
        break;
    default:
        return;
    }
    func_0017DC70((struct Q3Ent *)img->texData);
    img->texData = buf;
    img->w /= 2;
    img->flags |= 0x100;
}

void func_00180520(void)
{
}

int func_00180528(YiImgMgr *s)
{
    u32 i;
    u32 j;
    u32 max_val;
    u32 best_idx;

    for (i = 0; i < s->n9E7D0; i++) {
        max_val = 0;
        for (j = 0; j < s->n9E7D0; j++) {
            if (!(s->imgs9E7D4[j].flags & 0x10)) {
                if (max_val < s->imgs9E7D4[j].w110) {
                    max_val = s->imgs9E7D4[j].w110;
                    best_idx = j;
                }
            }
        }
        if (max_val == 0) {
            break;
        }
        yiImage_readonlyTIM1((Sys597F00 *)s, &s->imgs9E7D4[best_idx]); /* DEBT(CAST) */
    }
}
