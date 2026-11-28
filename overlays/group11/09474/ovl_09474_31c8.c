#include "common.h"

extern u8 *D_01B0A480;

void func_01B031C8(void) {
    *(float *)(D_01B0A480 + 0xCC4) -= 5.0f;
}
