#include "iopsound.h"

typedef struct {
    s32 core;
    s32 mode;
    s16 depth_L;
    s16 depth_R;
    s32 delay;
    s32 feedback;
} SdEffectAttr;

extern s32 D_05A128;
extern s32 D_06CEF4;
extern SdEffectAttr D_06CEF8;
extern s32 D_018718;

void func_014240(void) {
    SdEffectAttr *attr = &D_06CEF8;
    s32 depth;

    while (1) {
        imp_thsemap_8(D_05A128);
        depth = attr->depth_L;
        attr->depth_R = 0;
        attr->depth_L = 0;
        switch (D_06CEF4) {
        case 0:
            imp_libsd_11(2, 0);
            imp_libsd_23(0, attr);
            imp_libsd_25(0, 0, attr->mode);
            imp_libsd_11(2, 1);
            imp_libsd_5(0x0B80, depth & 0xFFFF);
            imp_libsd_5(0x0C80, depth & 0xFFFF);
            break;
        case 1:
            imp_libsd_11(3, 0);
            imp_libsd_23(1, attr);
            imp_libsd_25(1, 1, attr->mode);
            imp_libsd_11(3, 1);
            imp_libsd_5(0x0B81, depth & 0xFFFF);
            imp_libsd_5(0x0C81, depth & 0xFFFF);
            break;
        default:
            imp_libsd_11(2, 0);
            imp_libsd_11(3, 0);
            imp_libsd_23(0, attr);
            imp_libsd_23(1, attr);
            imp_libsd_25(0, 0, attr->mode);
            imp_libsd_25(1, 1, attr->mode);
            imp_libsd_11(2, 1);
            imp_libsd_11(3, 1);
            imp_libsd_5(0x0B80, depth & 0xFFFF);
            imp_libsd_5(0x0C80, depth & 0xFFFF);
            imp_libsd_5(0x0B81, depth & 0xFFFF);
            imp_libsd_5(0x0C81, depth & 0xFFFF);
            break;
        }
        D_018718++;
    }
}
