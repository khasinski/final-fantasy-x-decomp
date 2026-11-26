#include "iopsound.h"

extern s32 func_00FBD0(s32);

extern void (*D_06D220[2])(s32, void *);
extern void *D_06D228[2];
extern volatile s32 D_06D230[2];

s32 func_00FD60(s32 ch, s32 mode, void *iop_addr, u32 size, void *start_addr) {
    ch &= 1;
    if (D_06D230[ch] != 0) {
        return 0;
    }
    imp_libsd_28(ch);
    imp_libsd_19(ch, 0);
    return imp_libsd_18(ch, (u16)mode, iop_addr, size, start_addr);
}

s32 func_00FDF4(s32 ch, void (*cb)(s32, void *), void *arg) {
    ch &= 1;
    D_06D220[ch] = cb;
    D_06D228[ch] = arg;
    return imp_libsd_26(ch, func_00FBD0, NULL);
}
