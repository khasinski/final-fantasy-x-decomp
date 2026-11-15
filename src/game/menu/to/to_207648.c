/* tu_228 0x207648-0x207f50: medium; ~TOValueToMesFontL (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"

extern char D_00570348[];
extern char D_00570350[];

void func_00207648(int val, void *out, int width)
{
    char fmt[16];
    char buf[32];
    u8 *dst = (u8 *)out;
    int i;

    if (width > 0) {
        func_002F0008(fmt, D_00570348, width);
        func_002F0008(buf, fmt, val);
    } else {
        func_002F0008(buf, D_00570350, val);
    }
    for (i = 0; (u32)i < func_002F0840(buf); i++) {
        if (buf[i] >= '0' && buf[i] <= '9') {
            *dst++ = buf[i];
        } else if (buf[i] == ' ') {
            if (func_0020B850() == 0) {
                if (func_001BD360() == 0) {
                    *dst = 0x5E;
                } else {
                    *dst = 0xFE;
                }
            } else {
                *dst = 0xFE;
            }
            dst++;
        }
    }
    *dst = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", TOIntToMes);

void func_00207988(int id, int count, int x, int y, int width)
{
    int i;
    D_00668740[id]->w1C = 2;
    D_00669AE0[id]->b1 = 0;
    D_00669AE0[id]->b4 = 0;
    D_00669AE0[id]->b5 = count;
    D_00669AE0[id]->b2 = D_00669AE0[id]->b2 > count - 1 ? count - 1 : D_00669AE0[id]->b2 < 0 ? 0 : D_00669AE0[id]->b2;
    D_00669AE0[id]->b3 = D_00669AE0[id]->b3 > count - 1 ? count - 1 : D_00669AE0[id]->b3 < 0 ? 0 : D_00669AE0[id]->b3;
    width /= count;
    for (i = 0; i < count; i++) {
        D_00669AE0[id]->ent[i].h0 = 1;
        D_00669AE0[id]->ent[i].h2 = width;
        D_00669AE0[id]->ent[i].h4 = x;
        D_00669AE0[id]->ent[i].h6 = y;
        x += width;
    }
}

int func_00207A80(int i)
{
    return D_00669AE0[i]->wC;
}

void func_00207AA0(int id)
{
    if (D_003238E4 & 0x20) {
        func_00204C60(id);
    }
}

s32 TOFuncPadMessageSelect(int id)
{
    int previous = D_00669AE0[id]->b2;
    if (D_003238D0.h14 & 0x40) {
        if (D_00669AE0[id]->b2 != D_00669AE0[id]->b3) {
            D_00669AE0[id]->b2 = D_00669AE0[id]->b3;
            func_002D70D8(4);
        }
        return;
    }
    if (D_003238D0.h14 & 0x20) {
        D_00669AE0[id]->x18[D_00669AE0[id]->b7++] = D_00669AE0[id]->b2;
        if (D_00669AE0[id]->b7 == D_00669AE0[id]->b6)
            D_00669AE0[id]->b1 = 2;
        func_002D70D8(1);
        return;
    }
    {
        if (D_003238D0.h16 & 0x6000) D_00669AE0[id]->b2++;
        if (D_003238D0.h16 & 0x9000) D_00669AE0[id]->b2--;
        if (D_00669AE0[id]->b2 >= D_00669AE0[id]->b5)
            D_00669AE0[id]->b2 = D_00669AE0[id]->b4;
        if (D_00669AE0[id]->b2 < D_00669AE0[id]->b4)
            D_00669AE0[id]->b2 = D_00669AE0[id]->b5 - 1;
        if (D_00669AE0[id]->b2 != previous) func_002D70D8(1);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", TOFuncPadMessageInputValue);

int func_00207EE0(int a)
{
    a = TOGetMessageStatus(a);
    if (a == 3) {
        if (D_003238E4 & 0x20) {
            return 1;
        }
    }
    return 0;
}

int func_00207F20(void)
{
    if (func_00205DB8(7) == 2) {
        return D_00668FEA;
    }
    return -1;
}
