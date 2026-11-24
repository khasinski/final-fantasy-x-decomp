/* tu_202 0x1d8078-0x1d8c28: low; ~Ms (config/tu_map.tsv) */
#define MsNumberRegist _hdr_MsNumberRegist
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#undef MsNumberRegist

extern s8 D_0031FB70[];
extern s8 D_0031FB78[];
extern s8 D_0031FB80[];
extern s8 D_0031FB88[];
extern s8 D_0031FB90[];
void TOBtlSetDamageValue(s16 x, s16 y, int val, int r, int g, int b, int a);

void MsNumberInit(void) {
    D_00662D1C = 0;
}

void MsNumberGetMem(void) {
    if (D_00662D1C == 0) {
        D_00662D1C = (s32)user_malloc(0xA00, 5, D_0056F6A8, -1); /* DEBT(TYPE): handle kept as int */
        MsStructClear((void *)D_00662D1C, 0xA00);
        D_00662D20 = 0;
        D_00662D24 = &D_00662D20;
    }
}

void MsNumberFreeMem(void) {
    if (D_00662D1C != 0) {
        func_0011D590(D_00662D1C, 5);
        D_00662D1C = 0;
    }
}

void func_001D8128(int a, int b, int *outa, int *outb)
{
    if (outa != 0) {
        *outa = a / 16 - 0x700;
    }
    if (outb != 0) {
        *outb = b / 16 - 0x730;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8078", MsCalcCursorPos);

int func_001D83C8(int v, u8 **out) {
    int n = 0;
    if (v >= 0) {
        do {
            D_00662D10[n++] = v % 10;
            v /= 10;
        } while (v != 0 && n < 9);
    }
    if (out != 0) {
        *out = D_00662D10;
    }
    return n;
}

void MsNumberCalcProcess(void) {
    int c1;
    BtlEvt *e;
    int total;
    BtlEvt **prev;
    int c2;

    prev = (BtlEvt **)&D_00662D20;
    c1 = 0;
    e = (BtlEvt *)D_00662D20;
    c2 = 0;
    total = 0;
    while (e != 0) {
        s8 v6;
        if (e->b5 > 0) {
            e->b5--;
        }
        v6 = ++e->b6;
        if (e->b7 < v6) {
            e->b0 = 0;
            *prev = e->next;
        } else {
            prev = &e->next;
            switch (e->b0 & 0x7F) {
            case 1:
                c1++;
            case 2:
                c2++;
                break;
            }
            total++;
        }
        e = e->next;
    }
    D_00662D24 = (s32 *)prev;
    D_003172F0.f2103 = c1;
    D_003172F0.f2104 = c2;
    D_003172F0.f2105 = total;
}

typedef struct {
    u8 pad0[0x10];
    s8 f10;
    u8 pad11[4];
    s8 f15;
    u8 pad16[0x2A];
    float f40;
    u8 pad44[0x244];
    u8 f288;
    u8 f289;
    u8 pad28A[0x4C];
    u16 f2D6;
    u8 pad2D8[0x7B0];
    s8 fA88;
    u8 padA89[0x173];
    s32 fBFC;
    s32 fC00;
    s32 fC04;
    s32 fC08;
    s32 fC0C;
    s32 fC10;
    u8 padC14[0x18];
    float fC2C;
} NumDrawChr;

typedef struct {
    s8 x;
    s8 y;
    u8 a;
} NumAnimEntry;

typedef struct NumEvt {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
    s8 b6;
    s8 b7;
    s16 h8;
    s16 hA;
    u8 bC;
    u8 bD;
    u8 padE[2];
    struct NumEvt *next;
} NumEvt;

void MsNumberDrawProcess(void)
{
    int i;
    NumDrawChr *c;
    NumEvt *e;
    int r, g, b;
    int x, y;
    int state = D_00317300;

    if (state != 0x1F && state != 0x20 && state != 0x21) {
        for (i = 0; i < 0x1F; i++) {
            c = (NumDrawChr *)MsGetChr(i);
            if (c->f10 != 0 && c->fA88 != 0 && ((c->f2D6 >> 14) & 1) != 0 && c->f15 != 0 && c->f40 != 0.0) {
                u8 *digits;
                u8 cnt = c->f288;
                u8 spd = c->f289;
                float s;
                int n, j, xoff;

                c->fC2C += (float)spd / (float)(cnt + 1) * 0.125f;
                s = func_002E89C0(c->fC2C) + 1.0f;
                r = (u8)(s * 12.0f + 140.0f);
                g = (u8)(s * 12.0f + 50.0f);
                b = (u8)(s * 6.0f + 60.0f);
                n = func_001D83C8(cnt, &digits);
                xoff = n * 6;
                for (j = 0; j < n; j++) {
                    xoff -= 12;
                    x = c->fBFC + xoff;
                    y = c->fC00 - 18;
                    if (x >= -12 && x <= 512 && y >= -16 && y <= 416) {
                        TOBtlSetDamageValue(x, y, digits[j], r, g, b, 0x80);
                    }
                }
            }
        }
    }

    r = 0;
    g = 0;
    b = 0;
    e = (NumEvt *)D_00662D20;
    while (e != 0) {
        if (e->b5 == 0) {
            int col;
            int t;
            NumAnimEntry *tbl;
            u8 alpha;

            c = (NumDrawChr *)MsGetChr(e->b2);
            col = e->b1;
            t = e->b6 - 1;
            switch (col) {
            case 0:
            case 2:
                r = 0x80;
                g = 0x80;
                b = 0x80;
                break;
            case 1:
                r = 0x4A;
                g = 0xA0;
                b = 0x58;
                break;
            }
            tbl = &((NumAnimEntry *)D_0031FB90)[t - e->b3];
            alpha = tbl->a;
            if (e->b7 - 5 < t) {
                alpha = (e->b7 - t) * 32;
            }
            if (e->b0 & 0x80) {
                x = c->fC0C;
                y = c->fC10;
            } else {
                x = c->fC04;
                y = c->fC08;
            }
            switch (col) {
            case 0:
                x += e->h8 + tbl->x;
                y += e->hA - tbl->y;
                break;
            case 1:
                x += e->h8;
                y += e->hA - t / 2;
                break;
            case 2:
                x += e->h8;
                y += e->hA - t;
                break;
            }
            if (x + e->bC >= 0 && x <= 0x200 && y + e->bD >= 0 && y <= 0x1A0) {
                TOBtlSetDamageValue(x, y, e->b4, r, g, b, alpha);
            }
        }
        e = e->next;
    }
}

int MsNumberRegist(int chr, int kind, int val, int flag, int unused, int a5, int a6)
{
    u8 *digits;
    int color = 0;
    int w;
    int h;
    int yoff;
    int dy;
    int n;
    int x;
    int i;
    s8 *str;

    if (val < 0) {
        color = 1;
        val = -val;
    }
    if (val == 0) {
        if (flag < 0) {
            color = 1;
        }
    }
    str = 0;
    w = 0;
    h = 0;
    yoff = 0;
    dy = 0;
    switch (kind) {
    case 1:
        str = D_0031FB80;
        yoff = (a5 & 1) ? 0xE : 0;
        w = 0x2D;
        h = 0xA;
        dy = 4;
        break;
    case 3:
        str = D_0031FB70;
        w = 0x61;
        val = -1;
        h = 0xE;
        break;
    case 4:
        str = D_0031FB78;
        yoff = a5 ? -0x1A : 0;
        w = 0x43;
        h = 0x16;
        val = -1;
        break;
    case 5:
        str = D_0031FB88;
        color = 2;
        w = 0xA4;
        h = 0x11;
        val = -1;
        break;
    }
    switch (a6 & 0x7F) {
    case 1:
        D_003172F0.f2103 = 1;
    case 2:
        D_003172F0.f2104 = 1;
        break;
    }
    D_003172F0.f2105 = 1;
    n = func_001D83C8(val, &digits);
    x = (n * 12 + w) / 2;
    for (i = 0; i < n; i++) {
        x -= 12;
        if (func_001D8B98(chr, i, digits[i], x, yoff, 12, 16, 30, color, a6) == 0) {
            return -1;
        }
    }
    if (str != 0) {
        x -= w;
        while (*str != 0) {
            if (func_001D8B98(chr, n, *str, x, yoff + dy, w, h, 30, color, a6) == 0) {
                return -1;
            }
            str++;
        }
    }
    return 0;
}

int func_001D8B98(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
    BtlEvt *e = (BtlEvt *)D_00662D1C; /* DEBT(CAST): pool handle kept as int */
    int i;
    for (i = 0; i < 0x80; i++, e++) {
        if (e->b0 == 0) {
            *D_00662D24 = (s32)e; /* DEBT(CAST): list links kept as int */
            e->b0 = p9;
            e->b1 = p8;
            e->b2 = p0;
            e->b3 = p1;
            e->b4 = p2;
            e->b5 = p1 + 1;
            e->b6 = 0;
            e->b7 = p7;
            e->h8 = p3;
            e->hA = p4;
            e->bC = p5;
            e->bD = p6;
            D_00662D24 = (s32 *)&e->next;
            e->next = 0;
            return 1;
        }
    }
    return 0;
}
