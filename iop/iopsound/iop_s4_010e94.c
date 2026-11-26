#include "iopsound.h"

extern s32 D_05A128;
extern s32 D_06CEF4;
extern u8 D_06CEF8[];

typedef struct {
    s32 f0;
    s32 f4;
    u16 f8;
    u16 padA;
    s32 fC;
    s32 f10;
} Msg20;

s32 func_010E94(Msg20 *arg) {
    Msg20 *dst = (Msg20 *)D_06CEF8;
    s32 f0 = arg->f0;

    dst->f4 = arg->f4;
    dst->f8 = arg->f8;
    dst->fC = arg->fC;
    dst->f10 = arg->f10;
    D_06CEF4 = f0;
    imp_thsemap_7(D_05A128);
    return arg->f0;
}

s32 func_010F00(s32 *arg) {
    switch (arg[0]) {
    case 0:
        imp_libsd_5(0x0b80, *(u16 *)(arg + 1));
        imp_libsd_5(0x0c80, *(u16 *)(arg + 1));
        break;
    case 1:
        imp_libsd_5(0x0b81, *(u16 *)(arg + 1));
        imp_libsd_5(0x0c81, *(u16 *)(arg + 1));
        break;
    default:
        imp_libsd_5(0x0b80, *(u16 *)(arg + 1));
        imp_libsd_5(0x0c80, *(u16 *)(arg + 1));
        imp_libsd_5(0x0b81, *(u16 *)(arg + 1));
        imp_libsd_5(0x0c81, *(u16 *)(arg + 1));
        break;
    }
    return arg[0];
}
