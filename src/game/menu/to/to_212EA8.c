/* tu_239 0x212ea8-0x214650: low; ~TOBtlInitCtbWindow (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/s4.h"
#include "ffx/u3.h"

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", TOBtlInitCtbWindow);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", TOBtlCtrlCtbWindow);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", TOBtlDrawCtbWindow);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", TODrawBtlCtbParts);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", func_002140F8);

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

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", func_00214320);

int func_00214428(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_212EA8", _TOBtlGetChangePad);
