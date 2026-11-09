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

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_00259708);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_002598C8);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_002599C0);

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

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A1C8);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A340);

u8 *func_0025A478(u8 *dst, u8 *src, int n)
{
    while (n--) {
        *dst++ = *src++;
    }
    return src;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A4B0);

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A730);

/* DEBT(NAME): module guessed: character slots (D_006A391C, 12 slots of 0x340 bytes; slot 12 doubles as a request block).
 * Related ELF strings: src/chr/chr.c, src/chr/cache.c. */

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025A8D0);

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

INCLUDE_ASM("build/ee_asm/game/abm/ei_258140", func_0025AD00);

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
