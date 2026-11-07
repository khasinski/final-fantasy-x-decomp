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

extern s32 _m2c_func_002082B8_D_00323930 __asm__("D_00323930");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002082B8(s32 arg0, u8 *arg1, TextItem *arg2) {
    register u8 *var_16 __asm__("$16");
    u8 var_2;

    func_002EF0D0(&_m2c_func_002082B8_D_00323930, 0, 0x20);
    var_16 = TOGetChangeMacroAddress(arg0, arg1);
    if (var_16 != 0) {
    __asm__ volatile("" : "+r"(var_16));
        var_2 = *var_16;
        if (var_2 != 0) {
            do {
                if (var_2 == 7) {
                    if ((u32) (((*(u8 *)((u8 *)(var_16) + (1))) + 0x20) & 0xFF) < 0x10U) {
                        arg2->x += (*(u8 *)((u8 *)(var_16) + (1))) + 0xFF20;
                    }
                } else if (TOGetGroup((*(u8 *)((u8 *)(var_16) + (0)))) == 3) {
                    { register u8 *_a1 __asm__("$5") = var_16; __asm__ volatile("" : "+r"(_a1)); func_002082B8(arg0, _a1, arg2); }
                } else {
                    func_00204CA8(var_16, &_m2c_func_002082B8_D_00323930);
                    TOMakePktFont1612(arg2, &_m2c_func_002082B8_D_00323930);
                }
                var_16 = TOSkipCode(var_16);
                var_2 = *var_16;
            } while (var_2 != 0);
        }
    }
}

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
