#include "iopsound.h"

extern u8 D_06D3F0[];
extern char D_016654[];
extern char D_0165F0[];

s32 func_012A08(void) {
    return 0;
}

s32 func_012A10(s32 *arg) {
    s32 idx = arg[1] & 1;
    s32 a2 = arg[2];
    imp_sysmem_14(D_016654, D_0165F0, arg[0], arg[1], a2,
                  *(u32 *)(D_06D3F0 + idx * 25600));
    return 0;
}
