#include "iopsound.h"

extern s32 func_00FD60(s32, s32, s32, s32, s32);
extern void func_00FDF4(s32, s32, s32);

extern s32 D_0192F0;

s32 func_00F34C(void) {
    u8 *p;
    u8 *end;
    s32 v;

    imp_libsd_11(4, 0);
    imp_libsd_11(5, 0);
    func_00FD60(0, 2, 0, 0, 0);
    func_00FD60(1, 2, 0, 0, 0);
    imp_libsd_27(0, 0);
    func_00FDF4(0, 0, 0);
    func_00FDF4(1, 0, 0);

    p = (u8 *)D_0192F0;
    end = p + 5568;
    do {
        *(s32 *)p = 0;
        p += 116;
    } while (p < end);

    for (v = 0; v < 48; v += 2) {
        imp_libsd_5((u16)(v | 0x0300), 0x00ff);
        imp_libsd_5((u16)(v | 0x0400), 0x5fc4);
        imp_libsd_5((u16)(v | 0x0301), 0x00ff);
        imp_libsd_5((u16)(v | 0x0401), 0x5fc4);
        imp_libsd_5((u16)v, 0);
        imp_libsd_5((u16)(v | 0x0001), 0);
        imp_libsd_5((u16)(v | 0x0100), 0);
        imp_libsd_5((u16)(v | 0x0101), 0);
    }

    imp_libsd_7(0x1500, 0);
    imp_libsd_7(0x1501, 0);
    imp_libsd_7(0x1600, 0x00ffffff);
    imp_libsd_7(0x1601, 0x00ffffff);
    return 0;
}

s32 func_00F4C8(const char *path) {
    s32 size = 0;
    s32 fd = imp_ioman_4(path, 1);

    if (fd >= 0) {
        size = imp_ioman_8(fd, 0, 2);
        imp_ioman_5(fd);
    }
    return size;
}
