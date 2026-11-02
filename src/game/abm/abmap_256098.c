/* tu_281 0x256098-0x258140: low; ~abmap (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */
#include "ffx/r6.h"
#include "ffx/g4.h"

void func_00256098(void)
{
    spline_get_near_point_init();
    spline_get_near_point();
}

void func_002560B8(void) {
}

void func_002560C0(void) {
}

void func_002560C8(void) {
}

void func_002560D0(T6TransformRecord *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    /* DEBT(CAST): byte-declared backing storage is used as a HeapMgr here. */
    D_006A3924 = (HeapMgr *)D_006A3690;
    _pppStartPart(o, 0x1000, D_00327980[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position[0] = x;
    o->rotation[2] = (int)rz;
    o->position[1] = y;
    o->position[2] = z;
    /* DEBT(ORDER): independent vector stores retain original scheduling. */
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_002561E0(S6Task *o)
{
    if (*(u16 *)((char *)o + 0x1E) != 0) { /* DEBT(CAST): h1E */
        pppSetMatrix();
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = (HeapMgr *)D_006A3690; /* DEBT(CAST) */
        if (_pppRunPart(o, 0x30) != 0) {
            *(u16 *)((char *)o + 0x1E) = 0;
        }
    }
}

void func_00256278(void) {
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", dumpMatrix);

int *func_002563D0(int *dst, int *src, int n)
{
    while (n--) {
        *dst++ = *src++;
    }
    return dst;
}

int *func_00256408(void *dst_, int val, int n)
{
    int *dst = dst_;

    while (n--) {
        *dst++ = val;
    }
    return dst;
}

int func_00256440(char *s)
{
    int n = 0;

    while (*s++ != 0) {
        n++;
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00256478);

int func_002564E8(WorkEnt *e)
{
    return (e->x + 0xA00) / 256 + (e->y + 0x920) / 256 * 20;
}

void func_00256530(WorkEnt *e)
{
    e->cell = func_002564E8(e);
}

void func_00256558(EntRef *r)
{
    r->cx = func_002564E8(&lpamng->ents[r->a]);
    r->cy = func_002564E8(&lpamng->ents[r->b]);
}

void func_002565C8(void)
{
    D_006A3900[0] = func_002B3888(0x200);
    D_006A3900[1] = func_002B3888(0x200);
}

void func_00256608(void)
{
    while (GIF_CHCR & 0x100) {
    }
    func_002B39C0(0x200);
    func_002B39C0(0x200);
}

void func_00256650(s64 a, s64 b)
{
    s64 *p;
    int qwc;

    D_00327914 ^= 1;
    p = (s64 *)D_006A3900[D_00327914]; /* DEBT(CAST): table of packet buffers */
    p[0] = 0x1000000000008001;
    p[1] = 0xE;
    qwc = 2;
    p[2] = a;
    p[3] = b;
    while (GIF_CHCR & 0x100) {
    }
    *(volatile u32 *)0x1000E010 = 4;
    *(volatile u32 *)0x1000A010 = (u32)p | 0x80000000;
    *(volatile u32 *)0x1000A020 = qwc;
    GIF_CHCR = 0x100;
}

void func_00256708(int x0, int y0, int x1, int y1, s64 rgba)
{
    s64 *p;
    int *w;
    int qwc;

    D_00327914 ^= 1;
    p = (s64 *)D_006A3900[D_00327914]; /* DEBT(CAST): table of packet buffers */
    w = (int *)p;
    p[0] = 0x3000C00000008001;
    p[1] = 0x55E;
    p[2] = rgba;
    p[3] = 1;
    w[8] = x0;
    w[9] = y0;
    w[12] = x1;
    w[13] = y1;
    w[10] = 0xFFFF00;
    w[14] = 0xFFFF00;
    w[11] = 0;
    w[15] = 0;
    qwc = 4;
    while (GIF_CHCR & 0x100) {
    }
    *(volatile u32 *)0x1000E010 = 4;
    *(volatile u32 *)0x1000A010 = (u32)p | 0x80000000;
    *(volatile u32 *)0x1000A020 = qwc;
    GIF_CHCR = 0x100;
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_002567F0);

void func_002568C8(int x0, int y0, int x1, int y1, s64 color)
{
    s64 *q = (s64 *)D_006A3BCC;
    u32 *w = (u32 *)q;

    D_006A3BCC = (u8 *)(q + 12);
    q[2] = 0x4023400000008001;
    q[3] = 0x55EE;
    q[4] = 0x44;
    q[5] = 0x42;
    q[6] = color;
    q[7] = 1;
    w[16] = (x0 << 4) + 0x7000;
    w[17] = (y0 << 4) + 0x7300;
    w[18] = 0xFFFF00;
    w[19] = 0;
    w[20] = (x1 << 4) + 0x7000;
    w[21] = (y1 << 4) + 0x7300;
    w[22] = 0xFFFF00;
    w[23] = 0;
    func_002B2A80(q, 6, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00256970);

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00256A90);

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00256B78);

void func_00256E00(int a, u8 *p, int n)
{
    int i;

    func_002EF240(D_005738C8, a, p);
    for (i = 0; i < n; i++) {
        if ((i & 0xF) == 0xF) {
            func_002EF240(D_005738E0, *p);
        } else {
            func_002EF240(D_005738F0, *p);
        }
        p++;
    }
    func_002EF240(D_005738F8);
}

void func_00256EB8(R6Dump *d) {
    func_002EF240(D_00573900, d->h0, d->h4, d->h8, d->hC, d->h10, d->h12, d->b14, d->b15, d->b16);
}

Pt16 *func_00256F08(int a, int *out)
{
    return MsGetExcelData(a, D_006A38F0, out);
}

Pt16 *func_00256F30(int a, int *out)
{
    return MsGetExcelData(a, D_006A38F4, out);
}

int func_00256F58(int a, Pt16 *tbl)
{
    return a + tbl[MsGetSaveConfigHiragana() & 1].x;
}

int func_00256FA0(int a)
{
    return MsMenuGetText(9, a, MsGetSaveConfigHiragana() & 1);
}

int func_00256FD8(int a)
{
    return MsMenuGetHelp(9, a, MsGetSaveConfigHiragana() & 1);
}

int func_00257010(int a)
{
    return MsMenuGetText(0xB, a, MsGetSaveConfigHiragana() & 1);
}

void func_00257048(s64 a, s64 b) {
    s64 *p = (s64 *)D_006A3BCC;

    D_006A3BCC = (u8 *)(p + 6);
    p[2] = 0x1000000000008001;
    p[3] = 0xE;
    p[4] = a;
    p[5] = b;
    func_002B2A80(p, 3, 1, 0);
}

void func_00257090(int x0, int y0, int x1, int y1)
{
    u32 a = 0x30;

    if (lpamng->f11569 != 0x80) {
        a = a * lpamng->f11569 >> 7;
    }
    func_00256970(x0, y0, x1, y1, ((u64)a << 24) | 0x28326E, ((u64)a << 24) | 0x5C5286, ((u64)a << 24) | 0x5C5286,
                  ((u64)a << 24) | 0x4B739E, 0x7300);
}

void func_00257108(int a, int b, int c)
{
    u8 *start = D_006A3BCC;

    if (lpamng->f11569 != 0x80) {
        D_006A3BCC = func_001F4350(start + 0x10, 7, a, b, c, 0, 0x80, 0x80, 0x80, lpamng->f11569);
    } else {
        D_006A3BCC = func_001F4178(start + 0x10, a, b, c);
    }
    func_002B2A80(start, (D_006A3BCC - start) >> 4, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_002571B8);

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00257288);

void func_00257490(int a, int b, int c, int d)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F4260(start + 0x10, a, b, c, d, 0x80, 0x80, 0x80, lpamng->f11569);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

void func_00257518(int a, int b, int c)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F5918(start + 0x10, a, b, c, 0, 0x80, 0x80, 0x80, lpamng->f11569);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

void func_002575A0(int a, int b, int c)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F46D0(start + 0x10, a, b, c, 0, 0x80, 0x80, 0x80, lpamng->f11569, 1);

    D_006A3BCC = end;
    func_002B2A28(start, (end - start) >> 4, 1, 0);
}

void func_00257630(int a, int b, int c)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F4260(start + 0x10, a, b, c, 0, 0x80, 0x80, 0x80, lpamng->f11569);

    D_006A3BCC = end;
    func_002B2A28(start, (end - start) >> 4, 1, 0);
}

void func_002576B8(int a, int b, int c, int d)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F50F8(start + 0x10, a, b, c, d);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

void func_00257720(int a, int b, int c, int d)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F5060(start + 0x10, a, b, c, d);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

void func_00257788(int a, int b, int c, int d)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F3D30(start + 0x10, a, b, c, d, 0x80, 0x80, 0x80, lpamng->f11569);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

void func_00257810(int a, int b, int c, int d)
{
    u8 *start = D_006A3BCC;
    u8 *end = func_001F3B60(start + 0x10, a, b, c, d, 0x80, 0x80, 0x80, lpamng->f11569);

    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

int abmap_check_getpanel(int ch, int i)
{
    return lpamng->ents[i].flags & (1 << ch);
}

int abmap_check_getpanel_other(int skip, int i)
{
    int bits = lpamng->ents[i].flags;
    int j;

    for (j = 0; j < 7; j++) {
        if (j == skip) {
            continue;
        }
        if (((int (*)(int))MsGetSavePlyJoined)(j) != 1) { /* DEBT(CAST): called with an int id */
            continue;
        }
        if ((bits >> j) & 1) {
            return 1;
        }
    }
    return 0;
}

void func_00257958(void)
{
    abmap_cheng_panel();
}

void func_00257960(int a, int b)
{
    SndSepPlaySimple(0x80000050);
    func_00261728(a, b);
}

void func_002579A0(int ch, int i)
{
    lpamng->ents[i].flags &= ~(1 << ch);
}

void func_002579D0(void)
{
    func_00261C40();
    lpamng->f11577 = 1;
}

int func_00257A08(int ch)
{
    if (((int (*)(int))MsGetSavePlyJoined)(ch) == 0) { /* DEBT(CAST): called with an int id */
        return -1;
    }
    return lpamng->ents3[ch].h0;
}

void abmap_snd_chg_panel0(void) {
    SndSepPlaySimple(0x8000006D);
}

void abmap_snd_chg_panel1(void) {
    SndSepPlaySimple(0x8000006E);
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00257A78);

WorkEnt2 *func_00257BE8(WorkEnt2 *p, int id, u16 *out)
{
    GlobalWork *g = lpamng;
    WorkEnt2 *end = g->ents2 + g->count2;

    p = p != 0 ? p + 1 : g->ents2;
    for (; p < end; p++) {
        if (p->h0 == (u16)id) {
            *out = p->h2;
            return p;
        }
        if (p->h2 == (u16)id) {
            *out = p->h0;
            return p;
        }
    }
    return 0;
}

void func_00257C68(int (*fn)(), T6_Req *req)
{
    WorkEnt *e;
    int n;

    for (e = lpamng->ents, n = lpamng->count; --n != -1; e++) {
        if (e->f06 == 0xFFFF) {
            continue;
        }
        if (fn(e, req) != 0) {
            break;
        }
    }
}

void func_00257D00(u16 id, int (*fn)(), T6_Req *req)
{
    u16 e;
    WorkEnt2 *h;

    if (fn(&lpamng->ents[id], req) != 0) {
        return;
    }
    h = 0;
    while ((h = func_00257BE8(h, id, &e)) != 0) {
        if (fn(&lpamng->ents[e], req) != 0) {
            break;
        }
    }
}

/* DEBT(CAST): signed/width views follow the existing shared interfaces. */
void func_00257DC0(void)
{
    int out;
    func_00256F08((s32) lpamng->ents[lpamng->ents3[lpamng->f1156C].h0].f06, &out);
}

Pt16 *func_00257E18(int a, int *out)
{
    OfsTbl *p = MsGetRomItem(a, out);
    Pt16 *r;

    if (p->b5D == 0xFF) {
        r = 0;
    } else {
        r = func_00256F30(p->b5D, out);
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/abm/abmap_256098", func_00257E60);

int func_00257F20(int ch, int idx, int id)
{
    T6_Req req;
    int out;

    if (func_001BFE30(id) == 0) {
        return 0;
    }
    req.ch = ch;
    req.bit = 1 << ch;
    req.result = 0;
    req.tbl = func_00257E18(id, &out);
    return func_00257E60((int)&lpamng->ents[idx], (int)&req); /* DEBT(TYPE): prototype takes ints */
}

int func_00257FB0(int ch, int idx, int id)
{
    T6_Req req;
    int out;

    if (func_001BFE30(id) == 0) {
        return 0;
    }
    req.ch = ch;
    req.bit = 1 << ch;
    req.result = 0;
    req.tbl = func_00257E18(id, &out);
    if (req.tbl != 0) {
        if (((u8 *)req.tbl)[12] == 0x20) { /* DEBT(CAST): byte at 0xC of the table entry */
            func_00257C68(func_00257E60, &req);
        } else {
            func_00257D00(idx, func_00257E60, &req);
        }
    }
    return req.result;
}

int func_00258060(R6Fb *a, R6Req *b) {
    if (func_00257E60((int)a, (int)b) != 0) { /* DEBT(TYPE): prototype takes ints */
        a->b22 |= b->b10;
        b->wC = 0;
    }
    return 0;
}

int func_002580B0(int ch, int idx, int id, u8 mask)
{
    T6_Req req;
    int out;

    req.ch = ch;
    req.bit = 1 << ch;
    req.mask = mask;
    req.result = 0;
    req.tbl = func_00257E18(id, &out);
    if (req.tbl != 0) {
        if (((u8 *)req.tbl)[12] == 0x20) { /* DEBT(CAST): byte at 0xC of the table entry */
            func_00257C68(func_00258060, &req);
        } else {
            func_00257D00(idx, func_00258060, &req);
        }
    }
    return req.result;
}
