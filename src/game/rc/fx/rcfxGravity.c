/* tu_175 0x1a5358-0x1a55a8: medium; rcfxGravity (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxGravity", func_001A5358);

void *rcfxGravityNew(void) {
    void *p = _rcAlloc(0x30, D_0056DE60, 0x12);

    func_001A5558(p);
    return p;
}

void func_001A5550(void *p) {
    func_0018FC10(p);
}

void _m2c_func_001A5558_func_001A55A8() __asm__("func_001A55A8");
/* DEBT(CAST) */
void func_001A5558(void *p) {
    (*(s32 *)((u8 *)(p) + (0))) = 0x30002;
    (*(s32 **)((u8 *)(p) + (4))) = &func_001A5550;
    (*(s32 **)((u8 *)(p) + (0x14))) = &_m2c_func_001A5558_func_001A55A8;
    (*(s32 *)((u8 *)(p) + (8))) = 0;
    (*(s32 *)((u8 *)(p) + (0xC))) = 0;
    (*(s32 *)((u8 *)(p) + (0x10))) = 0;
    (*(s32 *)((u8 *)(p) + (0x18))) = 0;
    (*(float *)((u8 *)(p) + (0x28))) = (*(float *)((u8 *)(p) + (0x2C))) = 0.0f;
    (*(float *)((u8 *)(p) + (0x24))) = 0.0f;
    (*(float *)((u8 *)(p) + (0x20))) = 0.0f;
}
