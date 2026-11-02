/* tu_233 0x20d058-0x20dfc8: low; ~TOSetEnvMovieMessage (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#include "ffx/u3.h"

void TOSetEnvMovieMessage(void)
{
    R4Pmode v;

    if (Sg_GetDispMode()) {
        *(u64 *)&v = 0x42; /* DEBT(CAST): whole-register init of the bit-field view */
        v.alp = 0;
        GS_PMODE = *(u64 *)&v;
    }
}

void TOInitMovieMessage(int x, int y)
{
    if ((*(s32 *)MsGetSaveMenu() >> 9) & 1) { /* DEBT(CAST): flag word untyped */
        D_003238C8 = 1;
        if (Sg_GetDispMode()) {
            D_0068F424 = func_00160C20();
            D_0068F428 = func_00160C30();
            D_0068F42C = D_0068F424;
            D_0068F430 = 0x20000;
            D_0068F438 = 0x40000;
            D_0068F434 = D_0068F424 + 0x20000;
            if (Sg_GetDispMode() != 6) {
                D_003238C9 = 1;
                func_0020C660(D_0068F42C, 0x2100, 0x1B, 0, 0, 0x200, 0x80);
                D_003238CA = 1;
                func_0020B6F0(1);
                D_003238CC = x;
                D_003238CE = y;
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_20D058", TODrawMovieMessage);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_20D058", func_0020D468);

void func_0020D530(void)
{
    D_00323958 = 0;
}

int func_0020D540(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_20D058", TOSeqCtrl);

void TOSeqDraw(int i, int b)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (D_0068F440[i][j].h0 == 2 || D_0068F440[i][j].h0 == 3) {
            TOMenuExecLayerHandle(i, b, D_0068F440[i][j].w1C);
        }
    }
}

void func_0020D830(int i, int b)
{
    TOSeqDraw(i, b);
}

int TOSeqStartScene(int i, const char *name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            return 0;
        }
    }
    for (j = 0; j < 8; j++) {
        if (D_0068F440[i][j].h0 == 0) {
            if ((D_0068F440[i][j].w1C = TkMenuGetSceneHandle(i, name)) == 0) {
                return 0;
            }
            D_0068F440[i][j].h0 = 1;
            func_002F072C((char *)&D_0068F440[i][j].b8, name);
            break;
        }
    }
    return j != 8;
}

int TOSeqStartSceneNoErase(int i, const char *name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            return 0;
        }
    }
    for (j = 0; j < 8; j++) {
        if (D_0068F440[i][j].h0 == 0) {
            if ((D_0068F440[i][j].w1C = TkMenuGetSceneHandle(i, name)) == 0) {
                return 0;
            }
            D_0068F440[i][j].h0 = 1;
            D_0068F440[i][j].h2 = 1;
            func_002F072C((char *)&D_0068F440[i][j].b8, name);
            break;
        }
    }
    return j != 8;
}

int TOSeqStartSceneDrawContinue(int i, const char *name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            return 0;
        }
    }
    for (j = 0; j < 8; j++) {
        if (D_0068F440[i][j].h0 == 0) {
            if ((D_0068F440[i][j].w1C = TkMenuGetSceneHandle(i, name)) == 0) {
                return 0;
            }
            D_0068F440[i][j].h0 = 1;
            D_0068F440[i][j].h4 = 1;
            func_002F072C((char *)&D_0068F440[i][j].b8, name);
            break;
        }
    }
    return j != 8;
}

int TOSeqStopScene(int i, const char *name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if ((u16)(D_0068F440[i][j].h0 - 1) < 3 && func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            D_0068F440[i][j].h0 = 4;
            D_0068F440[i][j].b8 = 0;
            break;
        }
    }
    return j != 8;
}

void func_0020DBC8(int i)
{
    R4Ent32 *p = (R4Ent32 *)D_0068F440[i]; /* DEBT(CAST): Ent32 hides h2 */
    int j;

    for (j = 0; j < 8; j++) {
        if (p->h2 != 1 && (u16)(p->h0 - 2) < 2) {
            p->h0 = 4;
            p->b8 = 0;
        }
        p++;
    }
}

void func_0020DC20(int i)
{
    R4Ent32 *p = (R4Ent32 *)D_0068F440[i]; /* DEBT(CAST): Ent32 hides h2 */
    int j;

    for (j = 0; j < 8; j++) {
        if (p->h2 != 1 && (u16)(p->h0 - 1) < 3) {
            p->h0 = 4;
            p->b8 = 0;
        }
        p++;
    }
}

void func_0020DC78(int i)
{
    Ent32 *p = D_0068F440[i];
    int j;

    for (j = 0; j < 8; j++) {
        if ((u16)(p->h0 - 1) < 3) {
            p->h0 = 4;
            p->b8 = 0;
        }
        p++;
    }
}

int func_0020DCC0(int i, int name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8(name, &D_0068F440[i][j].b8) == 0) {
            return 1;
        }
    }
    return 0;
}

void func_0020DD38(void)
{
    Ent32 *p;
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        p = D_0068F440[i];
        for (j = 7; j >= 0; j--) {
            p->h0 = 0;
            p->b8 = 0;
            p++;
        }
    }
}

void TOSeqBuffFlashScene(int i)
{
    Ent32 *p = D_0068F440[i];
    int j;

    for (j = 7; j >= 0; j--) {
        p->h0 = 0;
        p->b8 = 0;
        p++;
    }
}

int TOSeqGetSceneStatus(int i, int name)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8(name, &D_0068F440[i][j].b8) == 0) {
            return D_0068F440[i][j].h0;
        }
    }
    return 0;
}

int TOSeqCheckTermScene(int i, const char *name)
{
    int ok;
    int j;

    for (j = 0, ok = 1; j < 8; j++) {
        if (func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            if (TkMenuIsTermScene(i, D_0068F440[i][j].w1C) == 0) {
                ok = 0;
            }
            return ok;
        }
    }
    return 0;
}

void func_0020DF10(int i, const char *name, int c, int d)
{
    int j;

    for (j = 0; j < 8; j++) {
        if (func_002F05E8((int)name, (u8 *)&D_0068F440[i][j].b8) == 0) { /* DEBT(CAST): the name starts at b8 */
            func_00210010(i, D_0068F440[i][j].w1C, c, d);
        }
    }
}
