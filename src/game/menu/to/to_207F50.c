/* tu_229 0x207f50-0x208448: low; ~TOGetButtonIconWidth (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"

void func_00207F50(int a, int b, int c)
{
    func_00207F70(a, b, c, 0, 0x80);
}

void func_00207F60(int a, int b, int c, u8 d)
{
    func_00207F70(a, b, c, d, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207F50", func_00207F70);

int func_00208060(void)
{
    return 20;
}

int func_00208068(int id)
{
    int base;
    OfsTbl *e = MsGetRomItem(id, &base);

    return base + e->a[0].x;
}

int func_00208090(void)
{
    return func_001C0040();
}

int func_002080B0(int id)
{
    int base;
    OfsTbl *e = MsGetComData(id, &base);

    return base + e->a[0].x;
}

s32 func_002080D8(int a)
{
    s32 pos;
    OfsTbl *t = MsGetRomAbility(a, &pos);

    return pos + t->a[0].x;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207F50", func_00208100);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207F50", func_002082B8);

int func_002083E8(u32 id)
{
    int r = 0;

    if (id - 0x40 <= 15) {
        r = 0x11;
    }
    if (id - 0x30 <= 3) {
        r = 0x12;
    }
    if (id - 0x34 <= 3) {
        r = 0x14;
    }
    if (id - 0x38 <= 1) {
        r = 0x2A;
    }
    if (id == 0x60) {
        r = 0x37;
    }
    return r + 2;
}
