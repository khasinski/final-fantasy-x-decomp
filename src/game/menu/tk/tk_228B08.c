/* tu_253 0x228b08-0x22b9f8: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void TkMn2InitStatusBG(void)
{
    D_00693A74 = 0;
    D_00693A76 = 0;
}

void TMn2SetStatusBGDiff(s16 v)
{
    D_00693A74 = v;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", TkMn2CalcStatusBGRatio);

s16 func_00228B80(void)
{
    return D_00693A76;
}

void func_00228B90(s16 *dst, int a1)
{
    if (a1) {
        dst[0] = D_006939A8[0] + D_006938B8[0];
        dst[1] = D_006939A8[1] + D_006938B8[1];
    } else {
        dst[0] = D_00693960[0] + D_006938B8[0];
        dst[1] = D_00693960[1] + D_006938B8[1];
    }
}

void func_00228BE8(s16 *dst, int a1)
{
    if (a1) {
        dst[0] = D_006939C0[0] + D_006938B8[0];
        dst[1] = D_006939C0[1] + D_006938B8[1];
    } else {
        dst[0] = D_00693978[0] + D_006938B8[0];
        dst[1] = D_00693978[1] + D_006938B8[1];
    }
}

int TkMn2GetStatusPos(void) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    /* DEBT(CAST): TkMn2GetCommonPlate takes the part names as int */
    /* DEBT(CAST): several targets are declared with other types in shared headers */
    D_0032587C = ((u32 (*)(int))TkMn2SeqGetColor)((int)D_00571470); /* DEBT(TYPE): stored into u32 without conversion */
    D_00325880 = ((u32 (*)(int))TkMn2SeqGetColor)((int)D_00571480);
    func_002273A0(D_00571490, D_00693880);
    func_00227460(D_005714A0, D_00693888);
    func_002273A0(D_005714B0, D_00693890);
    func_002273A0(D_005714C0, D_003258B8);
    func_002273A0(D_005714D0, D_003258C0);
    func_002273A0(D_005714E0, D_006938B0);
    func_00227460(D_005714F0, D_00693A70);
    func_002273A0(D_00571500, D_00693A30);
    func_00227460(D_00571508, D_00693A38);
    D_00693A3C = TkMn2SeqGetColor((int)D_00571510);
    D_00693A40 = TkMn2SeqGetColor((int)D_00571520);
    D_00693898 = TkMn2SeqGetColor((int)D_00571530);
    D_0069389C = TkMn2SeqGetColor((int)D_00571540);
    D_006938A0 = TkMn2SeqGetColor((int)D_00571550);
    D_006938A4 = TkMn2SeqGetColor((int)D_00571560);
    D_006938A8 = TkMn2SeqGetColor((int)D_00571570);
    D_00693A2C = TkMn2SeqGetColor((int)D_00571580);
    func_00227460(D_00571590, D_006938D8);
    func_00227460(D_005715A0, D_006938E0);
    func_00227460(D_005715B0, D_00325878);
    D_006938E4 = V5_TkMn2SeqGetNum_int((int)D_005715C0);
    TkMn2GetCommonPlate(&D_006938E8, (int)D_005715D0, (int)D_005715E0, (int)D_005715F0, 0xd8, 0xd9);
    TkMn2GetCommonPlate((FlagRec *)&D_00693900, (int)D_00571600, (int)D_00571610, (int)D_00571620, 0xd8, 0xd9);
    TkMn2GetCommonPlate(&D_00693918, (int)D_00571630, (int)D_00571640, (int)D_00571650, 0x109, 0xd9);
    TkMn2GetCommonPlate(&D_00693930, (int)D_00571660, (int)D_00571670, (int)D_00571670, 0x109, 0xd9);
    TkMn2GetCommonPlate(&D_00693948, (int)D_005714B0, (int)D_00571530, (int)D_00571530, 0, 0);
    TkMn2GetCommonPlate((FlagRec *)D_00693960, (int)D_005714C0, (int)D_00571540, (int)D_00571550, 0xda, 0xdb);
    TkMn2GetCommonPlate((FlagRec *)D_00693978, (int)D_005714D0, (int)D_00571560, (int)D_00571570, 0, 0);
    TkMn2GetCommonPlate(&D_006939D8, (int)D_005714E0, (int)D_00571530, (int)D_00571530, 0xde, 0xdf);
    TkMn2GetCommonPlate(&D_00325888, (int)D_00571680, (int)D_00571690, (int)D_005716A0, 0xd8, 0xd9);
    func_00227460(D_005716B0, D_003258A0);
    func_00227460(D_005716C0, D_003258A8);
    func_00227460(D_005714A0, D_00693A28);
    D_00693A44 = V5_TkMn2SeqGetNum_int((int)D_005716D0);
    D_00693990 = D_00693948;
    *(FlagRec *)D_006939A8 = *(FlagRec *)D_00693960; /* DEBT(CAST): declared u16[] in r5.h */
    *(FlagRec *)D_006939C0 = *(FlagRec *)D_00693978;
    D_006939F0 = D_006939D8;
    D_00693990.rect[1] += D_00693A44;
    ((FlagRec *)D_006939A8)->rect[1] += D_00693A44;
    ((FlagRec *)D_006939C0)->rect[1] += D_00693A44;
    D_006939F0.rect[1] += D_00693A44;
    func_00227460(D_005716E0, D_00693A08);
    func_00227460(D_005716F0, D_00693A10);
    func_00227460(D_00571700, D_00693A18);
    func_00227460(D_00571710, D_00693A20);
    func_00227460(D_00571720, (s16 *)D_006938B8);
    func_00227460(D_00571730, D_006938C0);
    func_00227460(D_00571740, D_006938C8);
    func_00227460(D_005716F0, D_006938D0);
    D_00693A5C = V5_TkMn2SeqGetNum_int((int)D_00571750);
    D_00693A60 = V5_TkMn2SeqGetNum_int((int)D_00571760);
    D_00693A64 = V5_TkMn2SeqGetNum_int((int)D_00571770);
    func_00227460(D_00571780, D_00693A68);
    func_002273A0(D_00571790, D_00693A48);
    func_00227460(D_005717A0, D_00693A50);
    func_00227460(D_005717B0, D_00693A58);
    func_00227460(D_005717C0, D_003258B0);
}

int func_002292B8(int x, int dir) {
    if (dir < 0) {
        x = 0x1000 - func_00125D90(0x1000 - x);
    } else {
        x = func_00125D90(x);
    }
    return x;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", TkMenuCtrlStatus);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_228B08/rodata", jtbl_005717E0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_002297A0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229820);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_002299A8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229AC8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229BE8);

void func_00229CE8(int dx, int dy, U3Box *dst, U3Box *src, int size)
{
    *dst = *src;
    dst->x += dx;
    dst->y += dy;
    if (size) {
        dst->w = D_00693900.w;
        dst->h = D_00693900.h;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229D58);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_00229F98);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_0022A3F8);

void func_0022A688(int unused, int a)
{
    int n = D_00693A98 + D_00693A9A;
    int step;
    int y;
    int i;

    if (n < 4) {
        step = D_00693A44;
    } else {
        step = D_00693A44 - 4;
    }
    y = 0;
    for (i = 0; i < n; i++) {
        func_0022A3F8(a, y, i);
        y += step;
    }
}

void func_0022A728(int a, int b, int c, int mode)
{
    switch (mode) {
    case 0:
        break;
    case 1:
    case 3:
        func_0022F720(D_00693888[0], D_00693888[1]);
        break;
    case 2:
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_0022A768);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_0022A9A0);

void func_0022ABC8(void) {
}

void func_0022ABD0(void)
{
    int i;

    for (i = 5; i >= 0; i--) {
        D_00693860[i] = 0;
    }
    TkMn2GetStatusPos();
}

void func_0022AC08(Task *o, int a1)
{
    D_003258C8 = 0;
    D_003258CC = TkMenuGetCurrentPlayerPos();
    D_003258D0 = TkMenuGetCurrentPlayerPos();
    D_003258D4 = TkMenuGetCurrentPlayerPos();
    o->x20 = a1;
    o->x1C = 0;
    D_00693878 = func_0022ADB0();
    TkMn2InitStatusBG();
    func_00227480(D_00571830);
    func_00227480(D_00571838);
}

void func_0022AC90(void)
{
    int i;

    for (i = 0; i < 6; i++) {
        TkMenuCloseStatusPageWindow(i);
    }
    TkMn2InitStatusBG();
    func_00227490(D_00571838);
    func_00227490(D_005717D0);
}

void func_0022ACE8(void) {
}

void func_0022ACF0(Task *o) { func_00243508(o); }

void func_0022ACF8(Task *t)
{
    int v = TkMenuGetCurrentPlayer();

    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920_void();
    func_0022A768(0, 0, v, 0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, t->x52);
    func_0022A9A0(0, 0, v, t->x52);
    func_002297A0(func_00228B80(), 0);
    func_00225B00();
}

int func_0022ADA8(void) { return 1; }

Task * func_0022ADB0(void)
{
    Task *t = func_00243400();

    t->x0C = (s32)func_0022ACF0;
    t->x10 = (s32)func_0022ACF8;
    t->x14 = (s32)func_0022ADA8;
    t->b3E = 0x2;
    t->b36 = 0x3;
    t->x54 = 0x155;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_0022AE20(Task *o) {
    if (o->x54 != 0) {
        o->x52 += o->x54;
        if (o->x52 >= 0x1000) {
            o->x52 = 0x1000;
        }
        if (o->x52 <= 0) {
            o->x52 = 0;
        }
    }
}

int TkMenuGetCommandMax(R5Rec4 *p, int flag, int a2, int a3)
{
    int n = 0;

    if (flag == 0) {
        return 8;
    }
    while (p->b0 != 0xFF) {
        if (p->b0 == a2 && p->b1 == a3) {
            n++;
        }
        p++;
    }
    return n;
}

int TkMenuGetCommandOffset(R5Rec4 *p, int flag, int a2, int a3)
{
    int n = 0;

    if (flag == 0) {
        return 0;
    }
    while (p->b0 != 0xFF) {
        if (p->b0 == a2 && p->b1 == a3) {
            return n;
        }
        p++;
        n++;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", TkMenuFlushSummonCommand);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", TkMenuGetDispCommand);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_228B08", func_0022B598);

void func_0022B878(void) {
}

int func_0022B880(Task *o) { return o->x52 == 0; }

Task *TkMenuOpenStatusPageWindow(int a, int idx, int c, int d)
{
    Task *t;
    int k;
    int prio;
    void (*cb)();

    k = 0;
    switch (idx) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 2;
        break;
    case 2:
        k = 3;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 4;
        break;
    }
    t = func_00243400();
    D_00693860[idx] = t;
    /* DEBT(CAST): callbacks are stored as s32 in the task record */
    cb = (void (*)())func_0022B878;
    t->ext[0] = c;
    t->ext[1] = d;
    prio = idx + 3;
    t->ext[2] = idx;
    t->ext[3] = a;
    t->ext[4] = k;
    t->cb = cb;
    t->x0C = (s32)func_0022AE20;
    t->x10 = (s32)func_0022B598;
    t->x14 = (s32)func_0022B880;
    t->b3E = prio;
    t->x54 = 0xAA;
    TkMenuMainRegistWindow(t);
    return t;
}

void TkMenuCloseStatusPageWindow(int i)
{
    Task *t;

    if (D_00693860[i] != 0) {
        D_00693860[i]->b41 = 1;
        t = D_00693860[i];
        D_00693860[i] = 0;
        t->x54 = -0xAA;
    }
}
