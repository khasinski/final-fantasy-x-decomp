#include "iopsound.h"

extern s32 D_05A130[];
extern s32 D_05A140;

s32 func_010028(void *src, void *dst, s32 size, s32 attr) {
    s32 oldstat;
    s32 intr_res;
    s32 id;

    D_05A130[0] = (s32)src;
    D_05A130[1] = (s32)dst;
    D_05A130[2] = size;
    D_05A130[3] = 0;
    intr_res = imp_intrman_17(&oldstat);
    do {
        id = imp_sifman_7(D_05A130, 1);
    } while (id == 0);
    if (intr_res == 0) {
        imp_intrman_18(oldstat);
    }
    D_05A140 = id;
    return id;
}

s32 func_0100AC(void) {
    s32 oldstat;
    s32 intr_res;
    s32 ret;

    intr_res = imp_intrman_17(&oldstat);
    ret = imp_sifman_8(D_05A140);
    if (intr_res == 0) {
        imp_intrman_18(oldstat);
    }
    return ret;
}
