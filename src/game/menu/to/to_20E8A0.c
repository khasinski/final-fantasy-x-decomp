/* tu_236 0x20e8a0-0x20ec90: medium; ~TODapsInit (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"

void TODapsInit(void)
{
    func_002EF0D0(D_0068FA60, 0, 0x800);
    D_00324976 = 0;
    D_00690260 = 10;
    D_00690262 = 10;
}

void TODapsSetPos(int x, int y)
{
    if (D_00324976 < 0x7C0) {
        D_0068FA60[D_00324976++] = 8; /* control code: locate */
        D_0068FA60[D_00324976++] = x / 100;
        D_0068FA60[D_00324976++] = x % 100;
        D_0068FA60[D_00324976++] = y / 100;
        D_0068FA60[D_00324976++] = y % 100;
    }
}

void TODapsString(char *s)
{
    int n = func_002F0840(s);

    if (n != 0 && D_00324976 + n < 0x7C0) {
        func_002F072C(D_0068FA60 + D_00324976, s);
        D_00324976 += n;
    }
}

void func_0020EA18(int a)
{
    char buf[0x20];

    func_002F0008(buf, D_00570A70, a);
    TODapsString(buf);
}

void TODapsPrintf(char *fmt, ...)
{
    char buf[256];
    char *ap;

    R4_VA_START(ap, fmt);
    func_002F46B0(buf, fmt, ap);
    TODapsString(buf);
}

void TODapsMakePkt(void)
{
    char ch;
    int x = D_00690260;
    int y = D_00690262;
    s16 col = 0;
    s8 *p;

    func_001F56E8();
    if (Sg_GetDispMode() != 4) {
        TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    } else {
        TOMakePktScissor(0, 0, 0x27F, 0x19F);
    }
    p = (s8 *)D_0068FA60; /* DEBT(CAST): the buffer holds signed control bytes */
    while (*p != 0) {
        switch (*p) {
        case 8:
            p++;
            D_00690260 = *p++ * 100;
            D_00690260 += *p++;
            x = D_00690260;
            col = 0;
            D_00690262 = *p++ * 100;
            D_00690262 += *p++;
            y = D_00690262;
            break;
        case 9:
            col = (col + 4) / 4 * 4;
            x = D_00690260 + col * 12;
            p++;
            break;
        case 10:
            x = D_00690260;
            y += 14;
            col = 0;
            p++;
            break;
        default:
            if ((u8)(*p - 0x20) < 0x5F) {
                if ((u8)(*p - 0x61) < 0x1A) {
                    ch = *p - 0x20;
                } else {
                    ch = *p;
                }
                func_001F60B0((int)&ch, x, y); /* DEBT(CAST): text passed as int */
                x += 12;
            }
            col++;
            p++;
            break;
        }
    }
}

void func_0020EC88(void)
{
    TODapsInit();
}
