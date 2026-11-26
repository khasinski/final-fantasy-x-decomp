#include "iopsound.h"

extern u8 D_0196D4;
extern u8 D_018C70[];

u8 func_009330(void) {
    u8 ret = D_018C70[D_0196D4];
    D_0196D4++;
    return ret;
}
