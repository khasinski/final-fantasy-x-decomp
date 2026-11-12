/* tu_282 0x258140-0x25aeb0: low; ~ei (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/g4.h"
#include "ffx/s6.h"
#include "ffx/v6.h"

WorkEnt2 *func_00258140(u16 id, WorkEnt2 *from, u16 *other, u8 mask, u8 val)
{
    GlobalWork *w = lpamng;
    WorkEnt2 *end = &w->ents2[w->count2];
    WorkEnt2 *p = w->ents2;

    if (from != 0) {
        p = from + 1;
    }
    for (; p < end; p++) {
        if ((p->f0E & mask) == val) {
            if (p->h0 == id) {
                *other = p->h2;
                return p;
            }
            if (p->h2 == id) {
                *other = p->h0;
                return p;
            }
        }
    }
    return 0;
}

void func_002581D8(u8 mask)
{
    WorkEnt2 *e = lpamng->ents2;
    int n = lpamng->count2;

    while (--n != -1) {
        e->f0E &= mask;
        e++;
    }
}

void func_00258228(u8 mask)
{
    WorkEnt2 *e = lpamng->ents2;
    int n = lpamng->count2;

    while (--n != -1) {
        e->f0E |= mask;
        e++;
    }
}

void func_00258278(u8 mask)
{
    WorkEnt *e = lpamng->ents;
    WorkEnt2 *p;
    u16 other;
    int out;
    int i;

    for (i = 0; i < lpamng->count; e++, i++) {
        if (e->f06 != 0xFFFF && (func_00256F08(e->f06, &out)[4].x & 0x8000)) { /* DEBT(CAST): flag word at 0x10 of the table entry */
            p = 0;
            while ((p = func_00258140(i, p, &other, 0, 0)) != 0) {
                p->f0E |= mask;
            }
        }
    }
}

void func_00258370(u8 mask)
{
    WorkEnt *e = lpamng->ents;
    int n = lpamng->count;

    while (--n != -1) {
        if (e->f06 != 0xFFFF) {
            e->f22 &= mask;
        }
        e++;
    }
}

void func_002583C0(u8 mask)
{
    WorkEnt *e = lpamng->ents;
    int n = lpamng->count;

    while (--n != -1) {
        if (e->f06 != 0xFFFF) {
            e->f22 |= mask;
        }
        e++;
    }
}

void func_00258410(int a, u8 mask)
{
    u32 lim = (a * 4) & 0xFFFC;
    WorkEnt *e = lpamng->ents;
    int n = lpamng->count;

    while (--n != -1) {
        if (e->f06 != 0xFFFF && e->f24 <= lim) {
            e->f22 |= mask;
        }
        e++;
    }
}

void func_00258478(u16 val)
{
    WorkEnt *e = lpamng->ents;
    int n = lpamng->count;

    while (--n != -1) {
        if (e->f06 != 0xFFFF) {
            e->f24 = val;
        }
        e++;
    }
}

typedef struct EiWorkEnt {
    s16 x;
    s16 y;
    u8 pad04[2];
    u16 f06;
    u8 pad08[4];
    WorkEnt2 *links[5];
    u8 pad20;
    u8 flags;
    u8 f22;
    u8 pad23;
    u16 f24;
    u8 pad26[2];
} EiWorkEnt;

typedef struct EiGlobalWork {
    u8 pad0[2];
    s16 count;
    s16 count2;
    u8 pad6[0x808 - 6];
    EiWorkEnt ents[100];
} EiGlobalWork;

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_002584C0);

void func_00258618(u16 id, u16 n, int bit)
{
    func_00258478(0xFFFF);
    func_002581D8(0xF0);
    func_00258278(2);
    D_006A3910 = n * 4;
    D_006A3918 = 1 << bit;
    D_006A3914 = 0;
    func_002584C0(id, 0);
}

u16 func_00258698(u16 start, u16 cur, WorkEnt2 **out)
{
    u16 other;
    u16 best_id;
    u16 best_cost;
    WorkEnt2 *p;

    if (start == cur) {
        return cur;
    }
    for (;;) {
        best_id = 0xFFFF;
        best_cost = 0xFFFF;
        p = 0;
        while ((p = func_00258140(cur, p, &other, 0, 0)) != 0) {
            WorkEnt *e = (WorkEnt *)((u8 *)lpamng + other * 0x28);
            if (*(u16 *)((u8 *)e + 0x82C) < best_cost) {
                best_cost = *(u16 *)((u8 *)e + 0x82C);
                best_id = other;
                *out = p;
            }
        }
        if (best_id == 0xFFFF) {
            return 0xFFFF;
        }
        if (best_id == start) {
            break;
        }
        cur = best_id;
    }
    return cur;
}

void func_00258780(void)
{
    func_0025A8D0();
    func_00258B48();
}

int func_00257F20(int ch, int idx, int id);
int MsSaveItemUse(int item, int delta);
Pt16 *func_00257E18(int a, int *out);
void abmap_para_get_special(int a, int idx, int ch);
void func_00257960(int ch, int idx);

void func_002587A0(int ch, int idx, int item)
{
    int out;
    u8 *p;

    if ((lpamng->ents[idx].f22 & 3) != 0) {
        if (func_00257F20(ch, idx, item) != 0) {
            if (MsSaveItemUse(item, -1) == 0) {
                p = (u8 *)func_00257E18(item, &out);
                if (p[13] != 0) {
                    abmap_para_get_special(p[13], idx, ch);
                } else {
                    func_00257960(ch, idx);
                }
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", eiAbmParaGet);

void func_00258B48(void)
{
    int i;

    func_001E0328();
    for (i = 0; i < 7; i++) {
        eiAbmParaGet(i);
    }
    func_001BE878();
}

float func_00258B88(u16 id, float *out)
{
    if (id != 0xFFFF) {
        WorkEnt *e = &lpamng->ents[id];
        S6Row *row;
        s16 v;

        out[0] = e->x;
        row = (S6Row *)((char *)lpamng + e->f06 * 0x30 + 0x8000);
        out[1] = e->y;
        out[2] = 0.0f;
        out[3] = 1.0f;
        v = row->h7834;
        return v / 2;
    }
    out[3] = 1.0f;
    return out[2] = out[0] = out[1] = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00258C48);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00258EA0);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00258FB8);

int func_00258EA0(int seed, float *v0, float *v1, float r0, float r1, u8 *p);
int func_00258FB8(int seed, float *v0, float *v1, float *v2, float r0, float r1, u8 *p);

int func_00259510(WorkEnt2 *l)
{
    float v0[4];
    float v1[4];
    float v2[4];
    int seed = l->seed;
    float r0 = func_00258B88(l->h0, v0);
    float r1 = func_00258B88(l->h2, v1);

    if (((u16 *)l)[2] == 0xFFFF) {
        seed = func_00258EA0(seed, v0, v1, r0, r1, &((u8 *)l)[13]);
    } else {
        func_00258B88(((u16 *)l)[2], v2);
        seed = func_00258FB8(seed, v0, v1, v2, r0, r1, &((u8 *)l)[13]);
    }
    return seed;
}

void func_002595E8(void)
{
    WorkEnt2 *l = lpamng->ents2;
    int n = lpamng->count2;
    int v = lpamng->f1161C;

    while (--n != -1) {
        l->seed = v;
        v = func_00259510(l);
        l++;
    }
    lpamng->f1161C = v;
}

void func_00259678(void)
{
    lpamng->f1161C = 0x1E52998;
    func_002595E8();
}

float func_00259698(int a)
{
    S6Row *row = (S6Row *)((char *)lpamng + a * 0x30 + 0x8000); /* DEBT(CAST): 0x30-byte records */
    s16 v = row->h7834;

    return (v >> 1) + 3.0f;
}

float func_002596D8(int i)
{
    return func_00259698(lpamng->ents[i].f06);
}

typedef struct {
    float x;
    float y;
    s32 w8;
    float wC;
    float f10;
    float f14;
    float f18;
    float f1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    u16 h30;
    u16 h32;
    u8 pad34[8];
    float f3C;
    float f40;
    u16 h44;
    u16 h46;
    u16 h48;
    u16 h4A;
    u16 h4C;
    u8 b4E;
    u8 pad4F;
} EiPt50;

EiPt50 *func_00259708(int i, int idx, float f, int a2, int a3, int a4)
{
    EiPt50 *p = (EiPt50 *)((char *)lpamng + 0x11090 + i * 0x50);
    WorkEnt *e = &lpamng->ents[idx];
    int w;
    int h;

    p->h44 = idx;
    p->x = e->x;
    p->y = e->y;
    p->w8 = 0;
    p->wC = 1.0f;
    p->f3C = func_002596D8(idx);
    p->f40 = f;
    p->w20 = a2;
    p->w24 = a3;
    p->w28 = a4;
    p->b4E = 0;
    if (i < 7) {
        if (FFXGetLang() == 0 && func_001BD360() == 0) {
            p->w2C = (s32)MsGetSaveChrName(i);
        } else {
            p->w2C = TOGetSaveChrName(i);
        }
        if (FFXGetLang() == 0 && func_001BD360() == 0) {
            w = func_00205E78((u8 *)p->w2C, 1);
            if (w < 0x20) {
                w = 0x20;
            }
            p->h30 = w;
            p->h32 = 15;
        } else {
            TOGetEasyMesWHFontL((u8 *)p->w2C, &w, &h);
            if (w < 0x20) {
                w = 0x20;
            }
            p->h30 = w;
            switch (FFXGetLang()) {
            case 0:
            case 1:
                p->h32 = 15;
                break;
            default:
                p->h32 = 18;
                break;
            }
        }
    }
    return p;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_002598C8);

void func_002598C8(EiPt50 *p);
extern float eff_sin_t[];
extern s32 D_0032793C;
extern s32 D_00327940;
extern s32 D_00327944;
extern s32 D_00327948;
extern u16 D_0032794C;
extern u16 D_00327950;
extern u16 D_00327954;
extern u16 D_00327958;
extern u16 D_0032792C;

EiPt50 *func_002599C0(int i)
{
    EiPt50 *p = (EiPt50 *)((char *)lpamng + 0x11090 + i * 0x50);
    u32 ang = ((p->b4E & 3) << 14) | 0x2000;
    s32 dx;
    s32 dy;

    func_002598C8(p);
    p->f10 = eff_sin_t[((ang + 0x4000) & 0xFFFF) >> 4] * p->f3C + p->x;
    p->f14 = -eff_sin_t[ang >> 4] * p->f3C + p->y;
    p->f18 = 0.0f;
    p->f1C = 1.0f;
    if ((p->b4E & 4) == 0) {
        dx = D_0032793C;
        dy = D_00327940;
    } else {
        dx = D_00327944;
        dy = D_00327948;
    }
    switch (p->b4E & 3) {
    case 0:
        p->h46 = dx;
        p->h48 = -dy;
        p->h4A = D_0032794C;
        p->h4C = D_00327954;
        break;
    case 1:
        p->h46 = -dx;
        p->h48 = -dy;
        p->h4A = -D_00327950 - D_0032792C;
        p->h4C = D_00327954;
        break;
    case 2:
        p->h46 = -dx;
        p->h48 = dy;
        p->h4A = -D_00327950 - D_0032792C;
        p->h4C = D_00327958;
        break;
    case 3:
        p->h46 = dx;
        p->h48 = dy;
        p->h4A = D_0032794C;
        p->h4C = D_00327958;
        break;
    }
    return p;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00259BA8);

int func_00259DB0(float a, float b, float c, float d) {
    if (a < c) {
        return c <= b;
    }
    if (c < a) {
        return a <= d;
    }
    return 1;
}

int func_00259E08(float *a, float *b)
{
    if (a[0] == 99999997952.0f) {
        return 0;
    }
    if (b[0] == 99999997952.0f) {
        return 0;
    }
    if (func_00259DB0(a[0], a[2], b[0], b[2]) == 0) {
        return 0;
    }
    return func_00259DB0(a[1], a[3], b[1], b[3]) != 0;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00259E98);

S6Pt50 *func_0025A0C8(int i)
{
    S6Pt50 *p = (S6Pt50 *)((char *)lpamng + 0x11090 + i * 0x50); /* DEBT(CAST) */
    WorkEnt *e = &lpamng->ents[p->h44];

    p->x = e->x;
    p->y = e->y;
    p->w8 = 0;
    p->wC = 1.0f;
    p->f3C = func_002596D8(p->h44);
    return p;
}

void func_0025A158(u8 *a, int b)
{
    SysVt *vt = GetCD();

    vt->f10(0x25);
    vt->f0(a + 8, b, 0, 0);
    vt->f8(0);
}

typedef struct {
    s16 x;
    s16 y;
    u8 pad04[2];
    u16 idx06;
    u8 pad08[8];
} EiEnt10;

typedef struct {
    u8 pad00[0xC];
    u8 f0C;
    u8 pad0D[7];
} EiWorkEnt2;

typedef struct {
    s16 count0;
    s16 count;
    s16 count2;
    u8 pad06[2];
    EiEnt10 ents08[128];
    WorkEnt ents[100];
    u8 pad_ents[0xA808 - 0x808 - 100 * 0x28];
    EiWorkEnt2 ents2[100];
    u8 pad_ents2[0xF808 - 0xA808 - 100 * 0x14];
    s16 ptsF808[8][2];
    u8 padF828[0x11330 - 0xF828];
    s32 w11330;
    u8 pad11334[0xC];
    float f11340;
    float f11344;
    u8 pad11348[0x1157B - 0x11348];
    u8 f1157B;
    u8 f1157C;
    u8 pad1157D[0x115AC - 0x1157D];
    float f115AC;
    float f115B0;
    float f115B4;
    float f115B8;
    float f115BC;
    float f115C0;
    float f115C4;
    float f115C8;
} EiBoundsWork;

void func_0025A1C8(void)
{
    EiEnt10 *e = ((EiBoundsWork *)lpamng)->ents08;
    int n = ((EiBoundsWork *)lpamng)->count0;

    ((EiBoundsWork *)lpamng)->f115AC = ((EiBoundsWork *)lpamng)->f115B0 = ((EiBoundsWork *)lpamng)->f115B4 = ((EiBoundsWork *)lpamng)->f115B8 = 0.0f;
    while (--n != -1) {
        s16 *pt = lpamng->ptsF808[e->idx06];
        int hw = pt[0] / 2;
        int hh = pt[1] / 2;
        float x0 = e->x - hw;
        float y0 = e->y - hh;
        float x1 = e->x + hw;
        float y1 = e->y + hh;

        if (x0 < ((EiBoundsWork *)lpamng)->f115AC) {
            ((EiBoundsWork *)lpamng)->f115AC = x0;
        }
        if (y0 < ((EiBoundsWork *)lpamng)->f115B0) {
            ((EiBoundsWork *)lpamng)->f115B0 = y0;
        }
        if (x1 > ((EiBoundsWork *)lpamng)->f115B4) {
            ((EiBoundsWork *)lpamng)->f115B4 = x1;
        }
        if (y1 > ((EiBoundsWork *)lpamng)->f115B8) {
            ((EiBoundsWork *)lpamng)->f115B8 = y1;
        }
        e++;
    }
    ((EiBoundsWork *)lpamng)->f115BC = ((EiBoundsWork *)lpamng)->f115AC;
    ((EiBoundsWork *)lpamng)->f115C4 = ((EiBoundsWork *)lpamng)->f115B4;
    ((EiBoundsWork *)lpamng)->f115C0 = ((EiBoundsWork *)lpamng)->f115B0;
    ((EiBoundsWork *)lpamng)->f115C8 = ((EiBoundsWork *)lpamng)->f115B8;
}

extern char D_005739A8[];

void func_0025A340(void)
{
    int i;
    int j;
    u16 other;
    EiWorkEnt *e;
    WorkEnt2 *p;

    for (i = 0, e = ((EiGlobalWork *)lpamng)->ents; i < lpamng->count; e++, i++) {
        if (e->f06 != 0xFFFF) {
            j = 0;
            p = 0;
            while ((p = func_00258140(i, p, &other, 0, 0)) != 0) {
                if (j >= 5) {
                    func_002EF240(D_005739A8, 5);
                }
                e->links[j++] = p;
            }
            for (; j < 5; j++) {
                e->links[j] = 0;
            }
        }
    }
}

u8 *func_0025A478(u8 *dst, u8 *src, int n)
{
    while (n--) {
        *dst++ = *src++;
    }
    return src;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A4B0);

typedef struct {
    u8 b0;
    u8 b1;
} SaveAbmNode;

typedef struct {
    SaveAbmNode nodes[0x500];
    u8 links[0x500];
    u16 pos[12];
    u8 bF18;
    u8 bF19;
} SaveAbmMap;

float func_00260D50(void);
float func_00260B68(void);

void func_0025A730(void)
{
    SaveAbmMap *save = (SaveAbmMap *)MsGetSaveAbilityMap();
    int i;
    int j;
    int k;

    for (i = 0; i < lpamng->count; i++) {
        WorkEnt *e = &lpamng->ents[i];
        if (e->f06 != 0xFFFF) {
            SaveAbmNode *sn = &save->nodes[i];
            if (sn->b0 == 0xFF) {
                e->f06 = 0xFFFF;
            } else {
                e->f06 = sn->b0;
            }
            e->flags = sn->b1;
        }
    }
    for (j = 0; j < lpamng->count2; j++) {
        EiWorkEnt2 *e = &((EiBoundsWork *)lpamng)->ents2[j];
        e->f0C = save->links[j];
    }
    for (k = 0; k < 7; k++) {
        lpamng->ents3[k].h0 = save->pos[k];
    }
    lpamng->f1157B = save->bF18;
    lpamng->f1157C = save->bF19;
    ((EiBoundsWork *)lpamng)->w11330 = func_00260D50();
    ((EiBoundsWork *)lpamng)->f11340 = ((EiBoundsWork *)lpamng)->f11344 = func_00260B68();
}

/* DEBT(NAME): module guessed: character slots (D_006A391C, 12 slots of 0x340 bytes; slot 12 doubles as a request block).
 * Related ELF strings: src/chr/chr.c, src/chr/cache.c. */

void func_0025A8D0(void)
{
    SaveAbmMap *save = (SaveAbmMap *)MsGetSaveAbilityMap();
    int i;
    int j;

    for (i = 0; i < lpamng->count; i++) {
        WorkEnt *e = &lpamng->ents[i];
        SaveAbmNode *sn = &save->nodes[i];
        sn->b0 = e->f06;
        sn->b1 = e->flags;
    }
    for (i = 0; i < lpamng->count2; i++) {
        EiWorkEnt2 *e = &((EiBoundsWork *)lpamng)->ents2[i];
        save->links[i] = e->f0C;
    }
    for (j = 0; j < 7; j++) {
        save->pos[j] = lpamng->ents3[j].h0;
    }
    save->bF18 = lpamng->f1157B;
    save->bF19 = lpamng->f1157C;
}

void func_0025AA20(int a)
{
    unsigned int i;
    S6Hdr *src;
    s16 *dst;

    for (i = 0; i < 8; i++) {
        dst = lpamng->ptsF808[i];
        src = (S6Hdr *)op_oef2_a_get(a, 2, D_00327920[i]);
        dst[0] = src->x;
        dst[1] = src->y;
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025AAB8);

void func_0025AAB8(void);

void func_0025AD00(void)
{
    s32 *save;

    save = (s32 *)MsGetSaveMenu();
    if (FFXGetLang() != 0) {
        if (((*save >> 14) & 3) == 2) {
            func_0025A158((u8 *)0xC, D_003F3940);
        } else {
            func_0025A158(0, D_003F3940);
        }
    } else if (FFXGetLang() == 0 && func_001BD360() == 0) {
        if (((*save >> 14) & 3) == 2) {
            func_0025A158((u8 *)0xC, D_003F3940);
        } else {
            func_0025A158(0, D_003F3940);
        }
    } else {
        if (((*save >> 14) & 3) == 2) {
            func_0025A158((u8 *)0xE, D_003F3940);
        } else {
            func_0025A158((u8 *)0xD, D_003F3940);
        }
    }
    D_006A38F8 = D_003F3940;
    op_oef2_set2((char *)D_006A38F8);
    func_002D02E8(D_006A38F8, 0, 0x23, 0x100);
    func_002D05F0(0x100);
    func_002D02E8(D_006A38F8, 0x24, 1000, 0x100);
    func_002D05F0(0x100);
    func_002D0698(0x100);
    op_oef2_tex_clut_ovl_clear(0x100);
    func_0025AA20(D_006A38F8);
    func_0025AAB8();
}

void func_0025AE38(void)
{
    D_00327910 = 0;
    op_et_tex_load_triger(0);
    func_002D09D0(0);
    if (D_00327928 == 0) {
        D_00327928 = 1;
        _pppInitData(&D_00327970, &D_003271C0);
    }
}

void eiAbmTerm(void) {
    op_et_tex_load_triger(1);
    func_002D09D0(1);
}
