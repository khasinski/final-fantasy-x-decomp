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

typedef struct YiVec4 { /* DEBT(TYPE): 8-byte aligned float vector (copied with ld/sd) */
    float x, y, z, w;
} __attribute__((aligned(8))) YiVec4;

typedef struct YiMat4 { /* DEBT(TYPE): 8-byte aligned 4x4 matrix (copied with ld/sd) */
    float m[4][4];
} __attribute__((aligned(8))) YiMat4;

extern const YiVec4 D_0056D140;
void func_002DCF48(void *dst, void *src);

float func_00188F48(Sys597F00 *s) {
    YiMat4 m;
    YiVec4 v;
    YiVec4 out;

    v = D_0056D140;
    v.y = -s->fC0DE4;
    *(YiMat4 *)&m = *(YiMat4 *)&s->m67F90;
    func_002DCF48(&m, &m);
    func_002DCE08(&out, &m, &v);
    return (out.y / ((208.0f / s->f68390) * 64.0f)) * 208.0f - 208.0f;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_00189040);

void func_0018A4E8(void)
{
    u32 pkt[64];
    u32 *p1, *p2, *p3, *p4, *p5, *p6, *p7;

    pkt[0] = 0x8008;
    pkt[1] = 0x10000000;
    pkt[2] = 0xE;
    pkt[3] = 0;

    p1 = &pkt[4];
    p1[0] = 0x010800D0;
    p1[1] = 0;
    p1[2] = 0x4C;
    p1[3] = 0;

    p2 = &pkt[8];
    p2[0] = 0x20000;
    p2[1] = 0;
    p2[2] = 0x47;
    p2[3] = 0;

    p3 = &pkt[12];
    p3[0] = 6;
    p3[1] = 0;
    p3[2] = 0;
    p3[3] = 0;

    p4 = &pkt[16];
    p4[0] = 0x80000000;
    p4[3] = 0;
    p4[2] = 1;
    p4[1] = 0x3F800000;

    p5 = &pkt[20];
    p5[0] = 0x73007000;
    p5[1] = 0;
    p5[2] = 0xD;
    p5[3] = 0;

    p6 = &pkt[24];
    p6[0] = 0x8D009000;
    p6[1] = 0;
    p6[2] = 5;
    p6[3] = 0;

    p7 = &pkt[28];
    p7[0] = 0;
    p7[1] = 0;
    p7[2] = 0x3F;
    p7[3] = 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_188D98", func_0018A5E0);
