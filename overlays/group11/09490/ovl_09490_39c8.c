#include "common.h"

extern u8 *D_01B0B398;

void func_01B039C8(u8 *arg0) {
    u8 *p = D_01B0B398 + 0xD770;

    if (*(s32 *)(p + 0x1480) == *(s32 *)(p + 0x1484)) {
        *(s32 *)(p + 0x1488) = 1;
        arg0[0x56] = 1;
    }
}
