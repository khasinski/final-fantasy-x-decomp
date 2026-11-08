/* tu_135 0x188d98-0x18aa10: medium; unk_188D98 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

void _m2c_func_00188D98_Sg_MFIFOSync(void) __asm__("Sg_MFIFOSync");
void func_00188D98(s32 arg0, s32 arg1) {
    s32 temp_2;

    _m2c_func_00188D98_Sg_MFIFOSync();
    func_002DA610(0, 0);
    temp_2 = func_002DB6D8(2);
    func_002DBF78(temp_2, 0, 0x100);
    *(volatile u8 *)(temp_2) |= 1;
    *(volatile u8 *)(temp_2) |= 0x40;
    *(volatile u8 *)(temp_2) &= 0x7F;
    *(u8 *)(temp_2) &= 0xF3;
    func_002F8660(0);
    func_002DBB00((S2DmaCtl *) temp_2, arg0, arg1);
}

void func_00188E40(Sys597F00 *s, int a) {
    if (Sg_GetDispMode() == 0) {
        func_00189040(s);
    } else {
        s->wC0E10 = 0;
    }
}

void func_00188E88(int a) {
    *(int *)(a + 0xC0DE0) = 0; /* DEBT(CAST): raw address arithmetic, base object unknown */
}

void func_00188E98(void *p) {
    R2CfgC0 *o = p;

    o->wDE8 = 0;
    o->wDEC = 0;
    o->wDF0 = 0;
    o->wDF4 = 0;
    o->wDE4 = 0;
    o->fDF8 = 0.03f;
    o->fDFC = 0.02f;
    o->fE00 = 0.005f;
    o->fE04 = 64.0f;
    o->wE08 = 0x60;
    o->bE0C = 0x80;
    o->bE0D = 0x80;
    o->bE0E = 0x80;
}

/* DEBT(FAKE) */
s32 func_00188F10(s32 arg0) {
    register s32 a0 __asm__("$4") = arg0;
    register s32 var_2 __asm__("$2");
    register s32 var_3 __asm__("$3");
    register s64 var_5 __asm__("$5");
    register s32 ret __asm__("$5");

    var_5 = -1;
    var_3 = 0;
    __asm__("" : "+r"(a0), "+r"(var_3), "+r"(var_5));
    do {
        var_2 = a0 >> var_3;
        if (var_2 & 1) {
            var_5 = var_3;
        }
        __asm__ volatile("" : "+r"(var_3), "+r"(var_5));
        var_2 = var_3 + 1;
        __asm__("" : "+r"(var_2));
        var_3 = var_2;
    } while (var_3 < 0x10);
    __asm__("" : "=r"(ret) : "0"(var_5));
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_00188F48);

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_00189040);

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_0018A4E8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_0018A5E0);
