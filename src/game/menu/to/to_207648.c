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

extern s32 D_003236E0[];

int TOIntToMes(int val, u8 *dst_arg, int width_arg, int mode_arg)
{
    register int width __asm__("$19") = width_arg;
    register u8 *dst __asm__("$17") = dst_arg;
    register int mode __asm__("$22") = mode_arg;
    register int len __asm__("$16");
    char buf[16];
    int i;

    val = val < 0 ? 0 : val;

    if (mode == 0) {
        func_002F0008(buf, D_00570350, val);
        len = func_002F0840(buf);
        if (len > width) {
            register int off __asm__("$3") = width << 2;
            register int div __asm__("$3") = *(s32 *)((u8 *)D_003236E0 + off);
            register int rem __asm__("$2");
            __asm__("" : "+r"(mode));
            rem = val % div;
            __asm__("" : "+r"(rem));
            val = rem;
            func_002F0008(buf, D_00570350, val);
            len = func_002F0840(buf);
        }
        if (len < width) {
            register int c5d __asm__("$21") = 0x5D;
            register int cfe __asm__("$20") = 0xFE;
            len = width - len;
            do {
                if (func_0020B850() == 0) {
                    if (func_001BD360() == 0) {
                        *dst = c5d;
                    } else {
                        *dst = cfe;
                    }
                } else {
                    *dst = cfe;
                }
                dst++;
                len--;
            } while (len != 0);
            len = width;
        }
        for (i = len - width; i < len; i++) {
            *dst++ = buf[i];
        }
    }
    if (mode == 1) {
        register s32 *tp __asm__("$3") = &D_003236E0[width];
        register int raw __asm__("$4") = *tp;
        register int max __asm__("$3") = raw - 1;
        val = val > max ? max : val < 0 ? 0 : val;
        func_002F0008(buf, D_00570350, val);
        len = func_002F0840(buf);
        if (len < width) {
            len = width - len;
            do {
                *dst++ = '0';
                len--;
            } while (len != 0);
            len = width;
        }
        for (i = 0; i < len; i++) {
            *dst++ = buf[i];
        }
    }
    *dst = 0;
    return val;
}

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

void TOFuncPadMessageInputValue(int id)
{
    s8 digits[16];
    int val;
    int i;

    func_002EF0D0(digits, 0, 16);
    val = D_00669AE0[id]->wC;
    for (i = 7; i >= 0; i--) {
        digits[i] = val / D_003236E0[i];
        val %= D_003236E0[i];
    }
    if (D_003238D0.h16 & 0x2000) {
        D_00669AE0[id]->b2++;
        func_002D70D8(1);
    }
    if (D_003238D0.h16 & 0x8000) {
        D_00669AE0[id]->b2--;
        func_002D70D8(1);
    }
    if (D_003238D0.h16 & 0x1000) {
        int pos = D_00669AE0[id]->b2 + 1;
        int idx = D_00669AE0[id]->b5 - pos;

        if (digits[idx] == 9) {
            D_00669AE0[id]->wC -= D_003236E0[idx] * 9;
        } else {
            D_00669AE0[id]->wC += D_003236E0[idx];
        }
        func_002D70D8(1);
    }
    if (D_003238D0.h16 & 0x4000) {
        int pos = D_00669AE0[id]->b2 + 1;
        int idx = D_00669AE0[id]->b5 - pos;

        if (digits[idx] == 0) {
            D_00669AE0[id]->wC += D_003236E0[idx] * 9;
        } else {
            D_00669AE0[id]->wC -= D_003236E0[idx];
        }
        func_002D70D8(1);
    }
    D_00669AE0[id]->b2 = D_00669AE0[id]->b2 > D_00669AE0[id]->b5 - 1
        ? (s8)(D_00669AE0[id]->b2 - (D_00669AE0[id]->b5 - D_00669AE0[id]->b4))
        : (D_00669AE0[id]->b2 < D_00669AE0[id]->b4
            ? (s8)(D_00669AE0[id]->b2 + (D_00669AE0[id]->b5 - D_00669AE0[id]->b4))
            : D_00669AE0[id]->b2);
    if (D_003238D0.h14 & 0x40) {
        D_00669AE0[id]->b2 = D_00669AE0[id]->b3;
        D_00669AE0[id]->wC = D_00669AE0[id]->w10;
        func_002D70D8(4);
    }
    if (D_003238D0.h14 & 0x20) {
        D_00669AE0[id]->b1 = 2;
        func_002D70D8(1);
    }
}

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
