/* tu_239 0x212ea8-0x214650: low; ~TOBtlInitCtbWindow (config/tu_map.tsv) */
#define _TOBtlGetChangePad _hdr__TOBtlGetChangePad
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/s4.h"
#include "ffx/u3.h"
#undef _TOBtlGetChangePad

void _TOBtlGetChangePad();

int func_00212EA8(void)
{
    return 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00212EB0(void)
{
    TOSeqStartScene(2, D_00570CC0);
    return 1;
}

int func_00212ED8(void)
{
    _TOBtlGetTargetPad();
    return 0;
}

int func_00212EF8(void)
{
    return 1;
}

int func_00212F00(void)
{
    return 0;
}

int func_00212F08(void)
{
    _TOBtlDrawTargetCursor();
    return 0;
}

int func_00212F28(void)
{
    return 0;
}

int func_00212F30(R4Task *o)
{
    func_0020DC20(2);
    if (MsCheckLeftWindow(o->h8) == 1) {
        TOSeqStartScene(2, D_00570CC8);
        TOSeqStartScene(2, D_00570CD0);
    }
    if (MsCheckLeftWindow(o->h8) == 2) {
        TOSeqStartScene(2, D_00570CE0);
        TOSeqStartScene(2, D_00570CE8);
    }
    if (MsCheckLeftWindow(o->h8) == 3) {
        TOSeqStartScene(2, D_00570CF8);
        TOSeqStartScene(2, D_00570D00);
    }
    o->f88 = func_00210898;
    return 1;
}

int func_00213000(R4Task *o)
{
    func_0020DC20(2);
    if (MsCheckLeftWindow(o->h8) == 1) {
        TOSeqStartScene(2, D_00570CC8);
        TOSeqStartScene(2, D_00570CD0);
    }
    if (MsCheckLeftWindow(o->h8) == 2) {
        TOSeqStartScene(2, D_00570CE0);
        TOSeqStartScene(2, D_00570CE8);
    }
    if (MsCheckLeftWindow(o->h8) == 3) {
        TOSeqStartScene(2, D_00570CF8);
        TOSeqStartScene(2, D_00570D00);
    }
    return 1;
}

int func_002130C0(R4Task *o)
{
    o->b01 = 4;
    o->f7C = func_002109C0;
    o->f7C(o);
    return 0;
}

int func_002130F8(MenuList *o)
{
    s16 start;
    s16 end;

    start = o->top - o->cols;
    start = (start > o->count) ? o->count : (start >= 0) ? start : 0;
    end = start + o->rows * o->cols;
    end = (end > o->count) ? o->count : (end >= 0) ? end : 0;
    return 0;
}

typedef struct CtbWindowEntry {
    s8 active, id;
    u8 pad2[2];
    s32 value4, value8;
    u8 orderC, orderD, flags, padF;
    s16 x, y;
    int (*state)();
} CtbWindowEntry;
typedef struct CtbListEntry {
    s8 id, pad;
    u16 value;
} CtbListEntry;

extern s16 D_0032498C, D_0032498E, D_00324988, D_0032498A;
extern u8 D_00324990;
extern s32 D_006902BC;
extern CtbWindowEntry D_00690340[32];
extern CtbWindowEntry *D_006902C0[32];
CtbListEntry *MsGetCTBlist(int *);
int func_00213E80(R4Walk *o);
int func_00213FF0(FrameCounter *c);

void TOBtlInitCtbWindow(void)
{
    int count;
    int i;
    CtbWindowEntry *dst;
    CtbListEntry *src;
    D_00324990 = 0;
    D_0032498C = 0;
    D_0032498E = 0;
    D_00324988 = 0;
    D_0032498A = 0;
    D_006902BC = 0;
    func_002EF0D0(D_00690340, 0, 0x300);
    func_002EF0D0(D_006902C0, 0, 0x80);
    src = MsGetCTBlist(&count);
    dst = D_00690340;
    for (i = 0; i < 16; i++) {
        dst->active = 1;
        dst->id = src->id;
        dst->value4 = src->value;
        dst->value8 = src->value;
        dst->orderC = i;
        dst->orderD = i;
        dst->flags = 0;
        dst->x = 0;
        dst->y = i * 22;
        dst->state = 0;
        src++;
        dst++;
    }
    for (i = 15; i >= 0; i--) {
        D_006902C0[i] = &D_00690340[i];
    }
}

void TOBtlCtrlCtbWindow(int a0, int mask)
{
    CtbWindowEntry *tmp[32];
    int count;
    int i, j, k;
    int changed = 0;
    CtbListEntry *src;

    D_006902BC = mask;
    src = MsGetCTBlist(&count);
    for (i = 0; i < 16; i++) {
        if (D_006902C0[i]->id != src[i].id) {
            changed = 1;
            break;
        }
    }
    if (changed == 1) {
        for (i = 0; i < 16; i++) {
            D_006902C0[i]->active = 1;
            D_006902C0[i]->y = i * 22;
            D_006902C0[i]->value4 = D_006902C0[i]->value8;
            D_006902C0[i]->x = 0;
            D_006902C0[i]->padF = 0;
            D_006902C0[i]->state = 0;
        }
        for (i = 16; i < 32; i++) {
            if (D_006902C0[i] != 0) {
                D_006902C0[i]->active = 0;
                D_006902C0[i]->value4 = D_006902C0[i]->value8;
                D_006902C0[i]->x = 0;
                D_006902C0[i]->y = 0;
                D_006902C0[i]->padF = 0;
                D_006902C0[i]->state = 0;
                D_006902C0[i] = 0;
            }
        }
        func_002EF0D0(tmp, 0, 0x80);
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 16; j++) {
                if (tmp[j] == 0 && D_006902C0[i]->id == src[j].id) {
                    tmp[j] = D_006902C0[i];
                    D_006902C0[i]->orderD = D_006902C0[i]->orderC;
                    tmp[j]->orderC = j;
                    D_006902C0[i] = 0;
                    tmp[j]->value8 = src[j].value;
                    if (i == j) {
                        tmp[j]->state = 0;
                    } else if ((mask >> tmp[j]->id) & 1) {
                        tmp[j]->state = (int (*)())func_00213E80;
                    } else {
                        tmp[j]->state = (int (*)())func_00213FF0;
                    }
                    break;
                }
            }
        }
        k = 16;
        for (i = 0; i < 16; i++) {
            if (D_006902C0[i] != 0) {
                tmp[k] = D_006902C0[i];
                D_006902C0[i]->orderD = D_006902C0[i]->orderC;
                tmp[k]->orderC = k;
                D_006902C0[i] = 0;
                tmp[k]->value8 = src[i].value;
                if ((mask >> tmp[k]->id) & 1) {
                    tmp[k]->state = (int (*)())func_00213E80;
                } else {
                    tmp[k]->state = (int (*)())func_00213FF0;
                }
                k++;
            }
        }
        k = 16;
        for (i = 0; i < 16; i++) {
            if (tmp[i] == 0) {
                for (j = 0; j < 32; j++) {
                    if (D_00690340[j].active == 0) {
                        break;
                    }
                }
                D_00690340[j].orderC = i;
                D_00690340[j].active = 1;
                D_00690340[j].orderD = k;
                D_00690340[j].id = src[i].id;
                D_00690340[j].value4 = src[i].value;
                D_00690340[j].value8 = src[i].value;
                D_00690340[j].y = k * 22;
                D_00690340[j].x = 0;
                if ((mask >> D_00690340[j].id) & 1) {
                    D_00690340[j].state = (int (*)())func_00213E80;
                } else {
                    D_00690340[j].state = (int (*)())func_00213FF0;
                }
                tmp[i] = &D_00690340[j];
                k++;
            }
        }
        __builtin_memcpy(D_006902C0, tmp, 0x80);
    }
    for (i = 0; i < 32; i++) {
        if (D_006902C0[i] != 0 && D_006902C0[i]->state != 0) {
            D_006902C0[i]->state(D_006902C0[i]);
        }
    }
    for (i = 0; i < 32; i++) {
        if (D_006902C0[i] != 0 && D_006902C0[i]->value8 != D_006902C0[i]->value4) {
            if (D_006902C0[i]->value8 < D_006902C0[i]->value4) {
                D_006902C0[i]->value4 -= 3;
                if (D_006902C0[i]->value8 >= D_006902C0[i]->value4) {
                    D_006902C0[i]->value4 = D_006902C0[i]->value8;
                }
            }
            if (D_006902C0[i]->value8 > D_006902C0[i]->value4) {
                D_006902C0[i]->value4 += 3;
                if (D_006902C0[i]->value8 <= D_006902C0[i]->value4) {
                    D_006902C0[i]->value4 = D_006902C0[i]->value8;
                }
            }
        }
    }
    if (D_003238D0.h12 & 8) {
        if (D_0032498E == D_0032498A && (s8)D_00324990 > 0) {
            D_00324990--;
            D_0032498E += 22;
        }
    } else if (D_003238D0.h12 & 2) {
        if (D_0032498E == D_0032498A && (s8)D_00324990 < 8) {
            D_00324990++;
            D_0032498E -= 22;
        }
    }
    if (D_0032498E < D_0032498A) {
        D_0032498A -= 11;
        if (D_0032498E >= D_0032498A) {
            D_0032498A = D_0032498E;
        }
    }
    if (D_0032498E > D_0032498A) {
        D_0032498A += 11;
        if (D_0032498E <= D_0032498A) {
            D_0032498A = D_0032498E;
        }
    }
}

extern s32 D_003241D0;
extern s32 D_003241D4;
void TODrawBtlCtbParts(int id, int val, int x, int y);

void TOBtlDrawCtbWindow(int x, int y)
{
    int i;
    s16 px;
    s16 py;

    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA7D0(x, y, 0x3A, 0xAE);
    if ((s8)D_00324990 > 0) {
        TOMkpShapeXY(0x1B6, x + 0x3A, y);
    }
    if ((s8)D_00324990 < 8) {
        TOMkpShapeXY(0x1B7, x + 0x3A, y + 0xAE);
    }
    func_001FBFB8(x + 2, y, 4, 0xAE, 0x10, 8, (s8)D_00324990);
    TOMakePktScissor(x, y, x + 0x3A, y + 0xAE);
    for (i = 0; i < 32; i++) {
        CtbWindowEntry *e = D_006902C0[i];
        if (e != 0) {
            px = x + e->x + 8;
            py = y + e->y + D_0032498A;
            if ((void *)e->state != (void *)func_00213EF8) {
                if (i == 0) {
                    TOMkpShapeXY(0x1D8, px, py);
                }
                TODrawBtlCtbParts((s8)D_006902C0[i]->id, D_006902C0[i]->value4, px, py);
            }
        }
    }
    if (D_003249C0[(s8)D_00325020].b2 == 1) {
        TODrawScissorXYWH(x - 0x1E, y, 0x58, 0xAE);
        px = x;
        for (i = 0; i < 16; i++) {
            py = y + D_006902C0[i]->y + D_0032498A;
            if ((D_006902BC >> (s8)D_006902C0[i]->id) & 1) {
                TOMkpShapeXY(0x1D6, x + px + 8, y);
                if ((s8)D_006902C0[i]->id >= 0x14) {
                    func_001FE240(0x1AD, px, py, D_003241D4, D_003241D4);
                } else {
                    func_001FE240(0x1AD, px, py, D_003241D0, D_003241D0);
                }
                TOMkpShapeXY(0x1AE, px, py);
            }
        }
    }
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
}

void TODrawBtlCtbParts(int id, int val, int x, int y)
{
    if (val >= 0x3C) {
        func_001EFDF8(x, y, x + 0x28, y + 0x14, 0x59, 0xF, 0x7C, 0x80);
    }
    if (val >= 0x28 && val < 0x3C) {
        int x0 = x - 0x28;
        int y1 = y + 0x14;
        int x1;

        __asm__("" : "+r"(x0)); /* DEBT(ORDER): prevent CSE with val - 0x28 from branch test */
        x1 = x0 + val;
        __asm__ volatile("" : "+r"(x1)); /* DEBT(ORDER): keep x1 add before arg setup */
        func_001EFDF8(x, y, x1, y1, 0x59, 0xF, 0x7C, 0x80);
        func_001EFDF8(x1, y, x + 0x28, y1, 0x95, 0x39, 0xC1, 0x80);
    }
    if (val >= 0x14 && val < 0x28) {
        int x0 = x - 0x14;
        int y1 = y + 0x14;
        int x1;

        __asm__("" : "+r"(x0)); /* DEBT(ORDER): prevent CSE with val - 0x14 from branch test */
        x1 = x0 + val;
        __asm__ volatile("" : "+r"(x1)); /* DEBT(ORDER): keep x1 add before arg setup */
        func_001EFDF8(x, y, x1, y1, 0x95, 0x39, 0xC1, 0x80);
        func_001EFDF8(x1, y, x + 0x28, y1, 0xB5, 0x75, 0xD6, 0x80);
    }
    if (val < 0x14) {
        func_001EFDF8(x, y, x + val, y + 0x14, 0xB5, 0x75, 0xD6, 0x80);
    }
    if (val >= 0x14) {
        val = 0x14;
    }
    if (id < 8) {
        if (id == 6 && ((int (*)(void))func_0014AC00)() < 0x434) {
            TOMkpShapeXY(0x1D4, x + val, y);
        } else {
            TOMkpShapeXY(id + 0x1B8, x + val, y);
        }
    }
    if (id >= 8 && id < 0x12) {
        TOMkpShapeXY(0x1C0, x + val, y);
    }
    if (id >= 0x14) {
        int kind = func_001BC190(id);

        if (kind == 0x14) {
            TOMkpShapeXY(func_001BC1B0(id) + 0x1CB, x + val, y);
            return;
        }
        if (kind == 0x15) {
            TOMkpShapeXY(0x1C2, x + val, y);
            return;
        }
        if (kind == 0x16) {
            TOMkpShapeXY(func_001BC1B0(id) + 0x1C3, x + val, y);
            return;
        }
        if (kind == 0x17) {
            TOMkpShapeXY(0x1D3, x + val, y);
            return;
        }
        TOMkpShapeXY(0x1C1, x + val, y);
    }
}

int func_00213E80(R4Walk *o)
{
    R4S4 t = D_00570D08;

    o->h10 += t.c[o->b0F];
    o->b0F++;
    if (o->b0F >= 4) {
        o->b0F = 0;
        o->f14 = func_00213EF8;
    }
    return 0;
}

int func_00213EF8(R4Walk *o)
{
    int d = (o->b0C - o->b0D) * 22;

    o->b0F++;
    o->h12 += d / 4;
    if (o->b0F >= 4) {
        o->b0F = 0;
        o->f14 = func_00213F70;
        o->h12 = o->b0C * 22;
    }
    return 0;
}

s32 func_00213F70(R4Walk *o)
{
    U3Step4 t = D_00570D10;

    o->h10 += t.d[o->b0F];
    o->b0F++;
    if (o->b0F >= 4) {
        o->b0F = 0;
        o->f14 = 0;
        if (o->b0C >= 16) {
            o->b00 = 0;
        }
    }
    return 0;
}

/* DEBT(CAST): value member holds a handler address */
int func_00213FF0(FrameCounter *c)
{
    c->frame++;
    if (c->frame >= 4) {
        c->frame = 0;
        c->value = (s32)func_00214028;
    }
    return 0;
}

int func_00214028(R4Walk *o)
{
    int d = (o->b0C - o->b0D) * 22;

    o->b0F++;
    o->h12 += d / 4;
    if (o->b0F >= 4) {
        o->b0F = 0;
        o->f14 = func_002140A0;
        o->h12 = o->b0C * 22;
    }
    return 0;
}

int func_002140A0(FrameCounter *c)
{
    c->frame++;
    if (c->frame >= 4) {
        c->frame = 0;
        c->value = 0;
        if (c->level >= 0x10) {
            c->active = 0;
        }
    }
    return 0;
}

void func_002140E0(void) {
}

void func_002140E8(void) {
}

void func_002140F0(void) {
}

extern s16 D_00324358;
extern s16 D_0032435A;
extern s16 D_0032435C;
extern s16 D_0032435E;
extern s16 D_00324360;
extern s16 D_00324362;
extern s16 D_00324364;
extern s16 D_00324366;
extern s16 D_00324368;
extern s16 D_0032436A;
extern s16 D_0032436C;

void func_002140F8(int id, int x, int y)
{
    func_001FA7D0(x, y, D_0032435C, D_0032435E);
    if (id >= 8) {
        TOMkpShapeXY(0x1C0, x + D_00324366, y + D_00324368);
    } else if (id == 6 && ((int (*)(void))func_0014AC00)() < 0x434) {
        TOMkpShapeXY(0x1D4, x + D_00324366, y + D_00324368);
    } else {
        TOMkpShapeXY(id + 0x1B8, x + D_00324366, y + D_00324368);
    }
    TOMkpEasyMesFontLCenter(func_0021F940(id), x + D_00324362, y + D_00324364);
    TOBtlDrawParamPlate(id, x + D_0032436A, y + D_0032436C);
}

int func_00214210(R4Task *o)
{
    func_002EF0D0(&D_00690640, 0, 0x18);
    D_00690640.h0 = 3;
    D_00690640.h2 = o->h8;
    o->h42 = 0;
    o->w20 = TOGetSaveWindow(o->h8, 10, &D_00690640.wC);
    func_0020DC20(2);
    TOSeqStartScene(2, D_00570CC0);
    return 0;
}

int func_002142A0(R4Task *o)
{
    func_0020DC20(2);
    o->f80 = func_00214428;
    o->f7C = func_00214310;
    return 0;
}

int func_002142E8(void)
{
    return 1;
}

int func_002142F0(void)
{
    _TOBtlGetChangePad();
    return 1;
}

int func_00214310(void)
{
    return 1;
}

int func_00214318(void)
{
    return 0;
}

int func_00214320(R4Task *o)
{
    int i = 0;

    TOMakePktBoxXYWHRGBA(0, D_0032435A + o->h42 * D_00324360, D_00324358 + D_0032435C + 16, D_0032435E, 0x80, 0x80, 0x80, 0x80);
    TOMkpShapeXY(0x1AC, D_00324358 + 36, D_0032435A);
    for (; i < D_00690640.wC; i++) {
        func_002140F8(((s16 *)o->w20)[i], D_00324358, D_0032435A + i * D_00324360);
    }
    return 0;
}

int func_00214428(void)
{
    return 0;
}

typedef struct {
    u8 b00;
    u8 b01;
    u8 pad02[6];
    s16 h8;
    u8 b0A;
    s8 b0B;
    u16 hC;
    s16 h0E[4];
    s16 h16[4];
    u8 pad1E[2];
    s16 *w20;
    u8 pad24[0x42 - 0x24];
    s16 h42;
} ChangeTask;

void TOBtlSetChangeHelpMes(int id);
void TOBtlSetPrevAction(void);
void TOBtlSetNextAction(int a, int b);

void _TOBtlGetChangePad(ChangeTask *o)
{
    int prev = o->h42;

    if (!((D_003238D0.h12 & 0x4004) && (D_003238D0.h12 & 0x1001))) {
        if ((D_003238D0.h12 & 0x4004) != 0x4004 && (D_003238D0.h16 & 0x4004)) {
            o->h42++;
        }
        if (!((D_003238D0.h12 & 0x1000) && (D_003238D0.h12 & 1))) {
            if ((D_003238D0.h16 & 0x1000) || (D_003238D0.h16 & 1)) {
                o->h42--;
            }
        }
    }
    if (o->h42 >= D_00690640.wC) {
        o->h42 = 0;
    }
    if (o->h42 < 0) {
        o->h42 = D_00690640.wC - 1;
    }
    o->h16[o->b0B] = o->w20[o->h42];
    o->h0E[o->b0B] = o->h42;
    TOBtlSetChangeHelpMes(o->w20[o->h42]);
    if (o->h42 != prev) {
        func_002D70D8(1);
        return;
    }
    if (D_003238D0.h14 & 0x40) {
        if (D_00325020 > 0) {
            register u32 next __asm__("$3"); /* DEBT(REG): GCC 2.9 allocates v0 instead of v1 after TOBtlSetPrevAction */
            TOBtlSetPrevAction();
            next = o->b01 + 1;
            o->b01 = next;
            func_002D70D8(4);
            return;
        }
    } else if (D_003238D0.h14 & 0x20) {
        if (TOCheckBtlCommandUse(o->h8, (u16)o->h16[0]) >= 0) {
            o->b01++;
            TOBtlSetNextAction(o->h8, (u16)o->h16[0]);
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
    }
}
