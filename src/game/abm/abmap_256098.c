/* tu_281 0x256098-0x258140: low; ~abmap (config/tu_map.tsv) */
#define func_002571B8 _hdr_func_002571B8
#define func_00257E60 _hdr_func_00257E60
#include "common.h"
#include "vu0.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */
#include "ffx/r6.h"
#include "ffx/g4.h"
#undef func_002571B8
#undef func_00257E60

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
    D_006A3924 = D_006A3690;
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
    if (o->h1E != 0) {
        pppSetMatrix();
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = D_006A3690;
        if (_pppRunPart(o, 0x30) != 0) {
            o->h1E = 0;
        }
    }
}

void func_00256278(void) {
}

extern char D_00573880[];

void dumpMatrix(char *name, float *m)
{
    func_002EF240(D_00573880, name,
                  m[0], m[1], m[2], m[3],
                  m[4], m[5], m[6], m[7],
                  m[8], m[9], m[10], m[11],
                  m[12], m[13], m[14], m[15]);
}

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

typedef struct AbmapView {
    u8 pad0[0x114D0];
    u_long128 q114D0[4];
    u_long128 q11510[4];
} AbmapView;

typedef struct AbmapFloatView {
    u8 pad0[0x114DC];
    float f114DC;
    u8 pad1[0xC];
    float f114EC;
    u8 pad2[0xC];
    float f114FC;
    u8 pad3[0xC];
    float f1150C;
} AbmapFloatView;

void func_00256478(void)
{
    u_long128 *p1;
    u_long128 *p2;

    p1 = ((AbmapView *)lpamng)->q11510;
    MMI_SQ_ZERO(0x0, p1);
    MMI_SQ_ZERO(0x10, p1);
    MMI_SQ_ZERO(0x20, p1);
    MMI_SQ_ZERO(0x30, p1);
    p2 = ((AbmapView *)lpamng)->q114D0;
    MMI_SQ_ZERO(0x0, p2);
    MMI_SQ_ZERO(0x10, p2);
    MMI_SQ_ZERO(0x20, p2);
    MMI_SQ_ZERO(0x30, p2);
    ((AbmapFloatView *)lpamng)->f114DC =
    ((AbmapFloatView *)lpamng)->f114EC =
    ((AbmapFloatView *)lpamng)->f114FC =
    ((AbmapFloatView *)lpamng)->f1150C = 1.0f;
}

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
    p = D_006A3900[D_00327914];
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
    p = D_006A3900[D_00327914];
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

void func_002567F0(int x0, int y0, int x1, int y1, s64 color)
{
    s64 *q = (s64 *)D_006A3BCC;
    u32 *w = (u32 *)q;

    D_006A3BCC = (u8 *)(q + 18);
    q[2] = 0x7021400000008001;
    q[3] = 0x55555EE;
    q[4] = 0x44;
    q[5] = 0x42;
    q[6] = color;
    q[7] = 1;
    w[32] = w[16] = (x0 << 4) + 0x7000;
    w[33] = w[17] = (y0 << 4) + 0x7300;
    w[24] = (x1 << 4) + 0x7000;
    w[25] = (y1 << 4) + 0x7300;
    w[20] = (x1 << 4) + 0x7000;
    w[21] = (y0 << 4) + 0x7300;
    w[28] = (x0 << 4) + 0x7000;
    w[29] = (y1 << 4) + 0x7300;
    w[18] = w[22] = w[26] = w[30] = w[34] = 0xFFFF00;
    w[19] = w[23] = w[27] = w[31] = w[35] = 0;
    func_002B2A80(q, 9, 1, 0);
}

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

void func_002B2AD8(void *p, int qwc, int a, int b);

void func_00256970(int x0, int y0, int x1, int y1, u64 c0, u64 c1, u64 c2, u64 c3, int z)
{
    s64 *q = (s64 *)D_006A3BCC;
    u32 *w = (u32 *)q;

    D_006A3BCC = (u8 *)(q + 22);
    q[2] = 0x9026400000008001;
    q[3] = 0x5E5E5E5EE;
    q[5] = q[4] = 0x42;
    q[6] = c0;
    q[10] = c1;
    q[14] = c2;
    q[18] = c3;
    q[19] = q[15] = q[11] = q[7] = 1;
    w[16] = w[32] = (x0 << 4) + 0x7000;
    w[17] = w[25] = (y0 << 4) + 0x7300;
    w[24] = w[40] = (x1 << 4) + 0x7000;
    w[33] = w[41] = (y1 << 4) + 0x7300;
    w[18] = z << 4;
    w[19] = 1;
    w[26] = z << 4;
    w[27] = 0;
    w[34] = z << 4;
    w[35] = 0;
    w[42] = z << 4;
    w[43] = 0;
    func_002B2AD8(q, 11, 0, 0);
}

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

u8 *_m2c_func_002571B8_func_001F4350(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32) __asm__("func_001F4350");
s32 _m2c_func_002571B8_func_002606E0() __asm__("func_002606E0");
s32 _m2c_func_002571B8_func_002B2A80(u8 *, s32, s32, s32) __asm__("func_002B2A80");
void func_002571B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 *temp_16;
    u8 *temp_2;

    _m2c_func_002571B8_func_002606E0();
    temp_16 = D_006A3BCC;
    temp_2 = _m2c_func_002571B8_func_001F4350(temp_16 + 0x10, 7, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    D_006A3BCC = temp_2;
    _m2c_func_002571B8_func_002B2A80(temp_16, (s32) (temp_2 - temp_16) >> 4, 1, 0);
}

void _m2c_func_00257288_func_00257108() __asm__("func_00257108");
void func_00257288(s32 a) {
    s16 temp_4;
    s32 temp_4_2;

    if (lpamng->f1161A > 0) {
        temp_4 = lpamng->f11618;
        lpamng->f1161A = (u16) lpamng->f1161A - 1;
        switch (temp_4) {                           /* irregular */
        case 0:
            TOMenuSetMacroCommandType(7, 0, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 0, lpamng->f1160C);
            TOMenuSetMacroCommandType(7, 1, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 1, lpamng->f11610);
            TOMenuSetMacroCommandType(7, 2, 1);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 2, lpamng->f11614);
            break;
        case 1:
            TOMenuSetMacroCommandType(7, 0, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 0, lpamng->f1160C);
            TOMenuSetMacroCommandType(7, 1, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 1, lpamng->f11610);
            break;
        case 2:
            TOMenuSetMacroCommandType(7, 0, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 0, lpamng->f1160C);
            TOMenuSetMacroCommandType(7, 1, 0);
    __asm__ volatile("" : : : "$3");
            TOMenuSetMacroCommandValue(7, 1, lpamng->f11610);
            break;
        }
        temp_4_2 = lpamng->f11608;
        if (temp_4_2 != 0) {
            func_002571B8(temp_4_2, 0x28, 4, 0, 0x80, 0x80, 0x80, lpamng->f11569);
        }
    } else if (a != 0) {
        _m2c_func_00257288_func_00257108(a, 0x28, 4);
    }
}
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
        if (MsGetSavePlyJoined(j) != 1) {
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
    if (MsGetSavePlyJoined(ch) == 0) {
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

typedef struct {
    u16 h00;
    u16 h02;
    u16 h04;
    u16 h06;
    u16 h08;
    u8 b0A[16];
    u8 b1A[16];
} AbmPad;

u16 TOMenuGetControlPad2(void);

void func_00257A78(int a, AbmPad *p)
{
    int i;
    u16 bit;
    u8 *p0A;
    u8 *p1A;

    p->h00 = TOMenuGetControlPad2();
    if (a == 0) {
        int raw = func_00220468(0, 0, 3, -1) + 0x80;
        s8 v = raw;
        if (v < -0x40) {
            p->h00 |= 0x1000;
        } else if (v > 0x40) {
            p->h00 |= 0x4000;
        }
    }
    p->h02 = p->h00 & ~p->h04;
    p->h04 = p->h00;
    p->h08 = 0;
    p->h06 = 0;
    for (bit = 1, p0A = p->b0A, p1A = p->b1A, i = 16; i != 0; bit <<= 1, p0A++, i--, p1A++) {
        if (p->h02 & bit) {
            p->h06 |= bit;
            p->h08 |= bit;
        } else if (p->h00 & bit) {
            if (++(*p0A) >= 6) {
                *p0A = 6;
                p->h06 |= bit;
                if (*p1A == 0) {
                    p->h08 |= bit;
                }
                if (++(*p1A) >= 3) {
                    *p1A = 0;
                }
            }
        } else {
            *p0A = 0;
            *p1A = 0;
        }
    }
}

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

void func_00257DC0(void)
{
    int out;
    func_00256F08(lpamng->ents[lpamng->ents3[lpamng->f1156C].h0].f06, &out);
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

int abmap_special_sphere_select_check(int a, int b, Pt16 *c, int d);

int func_00257E60(WorkEnt *e, T6_Req *req)
{
    int out;
    Pt16 *p = func_00256F08(e->f06, &out);

    if (((u8 *)req->tbl)[13] != 0) {
        req->result |= abmap_special_sphere_select_check(((u8 *)req->tbl)[13], e - lpamng->ents, p, req->ch);
    } else if ((e->flags & req->bit) == 0) {
        u16 x = p[4].x;
        u16 m = ((u16 *)req->tbl)[5];
        if ((x & 0x8000) == 0) {
            req->result |= x & m;
        }
    }
    return req->result;
}

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
    return func_00257E60(&lpamng->ents[idx], &req);
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
    if (func_00257E60(a, b) != 0) {
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
