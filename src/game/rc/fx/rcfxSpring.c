/* tu_172 0x1a4a38-0x1a4dd8: medium; rcfxSpring (config/tu_map.tsv) */
#define func_001A4B60 _hdr_func_001A4B60
#define func_001A4BD0 _hdr_func_001A4BD0
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"
#undef func_001A4B60
#undef func_001A4BD0

void *func_001A4A38(void) {
    void *p = _rcAlloc(0x30, D_0056DE30, 0x13);

    func_001A4AA0(p);
    return p;
}

void func_001A4A78(void *p) {
    func_001A4B10(p);
    func_0018FC10(p);
}

void func_001A4BD0(void);
void func_001A4BD8();

/* DEBT(CAST) */
void func_001A4AA0(void *p) {
    (*(s32 *)((u8 *)(p) + (8))) = 0;
    (*(s32 *)((u8 *)(p) + (0))) = 0x30005;
    (*(void (**)(void *))((u8 *)(p) + (4))) = func_001A4A78;
    (*(void (**)(void))((u8 *)(p) + (0x10))) = func_001A4BD0;
    (*(void (**)(void))((u8 *)(p) + (0x14))) = func_001A4BD8;
    (*(s32 *)((u8 *)(p) + (0xC))) = 0;
    (*(s32 *)((u8 *)(p) + (0x18))) = 0;
    (*(s32 *)((u8 *)(p) + (0x1C))) = 0;
    (*(float *)((u8 *)(p) + (0x28))) = 0.8f;
    (*(s32 *)((u8 *)(p) + (0x20))) = 0;
    (*(s32 *)((u8 *)(p) + (0x24))) = 0;
    (*(float *)((u8 *)(p) + (0x2C))) = 0.4f;
}

void func_001A4B10(R2Ptr20 *o) {
    if (o->p20 != 0) {
        func_0018FC10(o->p20);
        o->p20 = 0;
    }
    if (o->p24 != 0) {
        func_0018FC10(o->p24);
        o->p24 = 0;
    }
}

s32 _m2c_func_001A4B60__rcRealloc(s32, s32, s8 *, s32) __asm__("_rcRealloc");
/* DEBT(CAST) */
void func_001A4B60(void *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x20))) = _m2c_func_001A4B60__rcRealloc((*(s32 *)((u8 *)(arg0) + (0x20))), arg1 * 8, D_0056DE30, 0x37);
    (*(s32 *)((u8 *)(arg0) + (0x24))) = _m2c_func_001A4B60__rcRealloc((*(s32 *)((u8 *)(arg0) + (0x24))), arg1 * 4, D_0056DE30, 0x38);
}

void func_001A4BD0(void)
{
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxSpring", func_001A4BD8);
