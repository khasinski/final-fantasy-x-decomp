/* tu_235 0x20e248-0x20e8a0: low; unk_20E248 (config/tu_map.tsv) */
#define func_0020E508 _hdr_func_0020E508
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#undef func_0020E508

void func_0020E248(s8 *s, u8 *d)
{
    while (*s != 0) {
        if (*s >= 0x20 && *s < 0x7B) {
            int k = *s - 0x20;

            if (U3_CHARMAP[k][0] == 0) {
                *d++ = U3_CHARMAP[k][1];
            } else {
                d[0] = U3_CHARMAP[k][0];
                d[1] = U3_CHARMAP[k][1];
                d += 2;
            }
        }
        s++;
    }
    *d = 0;
}

int func_0020E2C8(u8 *s)
{
    R4CharInfo info;
    int w = 0;

    while (*s != 0) {
        func_0020E468(s, &info);
        w += 1 + info.h10;
        if (info.h16 != 0) {
            w += 5;
        }
        s = TOSkipCode(s);
    }
    return w;
}

void func_0020E340(void)
{
    func_002EF0D0(D_0068F740, 0, 0x180);
    D_0068F8C0 = 0;
}

void func_0020E370(u8 *s, s16 x, s16 y)
{
    func_0020E388(s, x, y, 0);
}

void func_0020E388(u8 *s, s16 x, s16 y, int a)
{
    R4CharInfo ci;
    TextItem it;

    func_002EF0D0(&ci, 0, sizeof(ci));
    func_002EF0D0(&it, 0, sizeof(it));
    it.x = x;
    it.y = y;
    it.col[0] = 0x80;
    it.col[1] = 0x80;
    it.col[2] = 0x80;
    it.col[3] = 0x80;
    it.f13 = a;
    func_001F1EB8();
    while (*s) {
        func_0020E468(s, &ci);
        func_001F1F60(&it, &ci);
        s = TOSkipCode(s);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_20E248", func_0020E468);

void func_0020E508(s8 *s, u8 *d)
{
    V4Rgba4 rep = D_00570A60;

    while (*s != 0) {
        if ((u8)(*s - '0') < 10) {
            *d++ = *s++;
        } else if (*s == ' ') {
            *d++ = ':';
            s++;
        } else if ((u8)(*s - '-') < 3) {
            *d++ = rep.c[*s++ - '-'];
        }
    }
    *d = 0;
}

void func_0020E5B0(int a, int b, int c)
{
    int n = D_0068F8C0;

    D_0068F8C0 = n + 1;
    D_0068F740[n].h0 = 1;
    D_0068F740[n].h4 = a;
    D_0068F740[n].h6 = b;
    D_0068F740[n].w8 = c;
}

void func_0020E5F0(void)
{
    char buf[0x20];
    u8 work[0x20];
    int i;

    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    for (i = 0; i < D_0068F8C0; i++) {
        func_002F0008(buf, D_00570A68, D_0068F740[i].w8);
        func_0020E508((int)buf, work); /* DEBT(CAST): text passed as int */
        func_001F64A0((int)work, D_0068F740[i].h4, D_0068F740[i].h6); /* DEBT(CAST) */
    }
    func_0020E340();
}

GsAdPacket *func_0020E6C8(GsAdPacket *p)
{
    p[0].data = SCE_GIF_SET_TAG(5, 1, 0, 0, 0, 1);
    p[0].reg = 0xE;
    p[1].data = 0;
    p[1].reg = GS_REG_TEXFLUSH;
    p[2].data = 0x8000000044;
    p[2].reg = GS_REG_ALPHA_1;
    p[3].data = 0xF;
    p[3].reg = GS_REG_TEST_1;
    p[4].data = 0x60;
    p[4].reg = GS_REG_TEX1_1;
    p[5].data = 5;
    p[5].reg = GS_REG_CLAMP_1;
    return p + 6;
}

int func_0020E740(u8 *s)
{
    int w = 0;

    while (*s) {
        w += 12;
        s = TOSkipCode(s);
    }
    return w;
}

int func_0020E788(u8 *s, int *out)
{
    int w = 0;

    while (*s) {
        w += 12;
        s = TOSkipCode(s);
    }
    w -= 2;
    *out = w;
    return 0;
}

int func_0020E7E0(u8 *s)
{
    int w = 0;

    while (*s) {
        w += 12;
        s = TOSkipCode(s);
    }
    return w - 2;
}

int func_0020E828(const char *s)
{
    return func_002F0840(s) * 12;
}

int func_0020E850(const char *s)
{
    return func_002F0840(s) * 10;
}

int func_0020E878(const char *s)
{
    return func_002F0840(s) * 10;
}
