/* tu_084 0x14d610-0x14d940: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

INCLUDE_ASM("build/ee_asm/game/atel/atel_14D610", func_0014D610);

void func_0014D718(u8 *src, u8 *dst)
{
    u8 c;
    u16 code;

    if (FFXGetLang() == 0) {
        do {
            c = *src++;
            code = D_0030BBB0[c];
            if (code >= 0x100) {
                *dst++ = code >> 8;
            }
            *dst++ = code;
        } while (c != 0);
    } else {
        func_002F072C((char *)dst, (char *)src);
    }
}

void func_0014D7A8(int a, int b) {
}

void AtelPs2DebugString(const char *a)
{
    func_0014D7A8((int)a, 0);
}

void func_0014D7B8(int a)
{
    func_0014D7A8(a, 0x12);
}

s32 func_0014D7C0(void)
{
    return D_0058F934;
}

void func_0014D7D0(s32 v)
{
    D_0058F934 = v;
}

float func_0014D7E0(void)
{
    return D_0058F938;
}

void func_0014D7F0(float v)
{
    D_0058F938 = v;
}

void func_0014D800(int a)
{
    D_0058F930 = 1;
    D_0058F931 = a;
    D_0058F932 = -1;
    TkSetEventJumpMapNo(TkGetNowEventJumpMapNo(), a);
}

void AtelRecoverPreBgPage(void)
{
    if (D_0058F931 >= 0) {
        func_00174A90(D_0058F931);
    }
    if (D_0058F932 >= 0) {
        func_00174AF8(D_0058F932);
    }
}

void func_0014D890(u8 v)
{
    D_0058F930 = 2;
    D_0058F932 = v;
}

void func_0014D8A8(void)
{
    D_0058F930 = 0;
    D_0058F931 = -1;
    D_0058F932 = -1;
}

void func_0014D8C8(void)
{
    switch (D_0058F930) {
    case 1:
        if (D_0058F931 >= 0) {
            func_00174A90(D_0058F931);
        }
        break;
    case 2:
        if (D_0058F932 >= 0) {
            func_00174AF8(D_0058F932);
        }
        break;
    }
    D_0058F930 = 0;
}
