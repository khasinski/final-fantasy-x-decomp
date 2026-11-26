#include "iopsound.h"

extern volatile s32 D_06D230[2];

extern void func_00F0D4(s32);
extern void func_00F120(s32);

s32 func_00FC2C(s32 ch, s32 mode, void *iop_addr, u32 spu_addr, u32 size) {
    s32 ret;
    s16 ch16;

    ch &= 1;
    if (D_06D230[ch] != 0) {
        if (ch == 0) {
            func_00F0D4(19);
        } else {
            func_00F0D4(23);
        }
        return 0;
    }
    if (ch == 0) {
        func_00F120(19);
    } else {
        func_00F120(23);
    }
    D_06D230[ch] |= 1;
    imp_libsd_28(ch);
    ch16 = ch;
    imp_libsd_19(ch16, 0);
    ret = imp_libsd_17(ch16, (u16)mode, iop_addr, spu_addr, size);
    if (ret < 0) {
        if (ch == 0) {
            func_00F0D4(14);
        } else {
            func_00F0D4(15);
        }
        D_06D230[ch] = 0;
        return ret;
    }
    if (ch == 0) {
        func_00F120(14);
    } else {
        func_00F120(15);
    }
    return ret;
}
