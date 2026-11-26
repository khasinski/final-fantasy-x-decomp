#include "iopsound.h"

typedef struct {
    s32 core;
    s32 mode;
    s16 depth_L;
    s16 depth_R;
    s32 delay;
    s32 feedback;
} SdEffectAttr;

extern s32 D_06D220[];
extern s32 D_06D228[];
extern u8 D_05CB70[];
extern u8 D_06CB70[];
extern u8 D_06CC70[];
extern u8 D_06CF10[];
extern u8 *D_06D218[];
extern u8 *D_06D210[];
extern volatile s32 D_06D230[];
extern u8 D_06CE70[];
extern u8 *D_06CEF0;
extern s32 D_05A1D8;
extern volatile s32 D_019350;
extern volatile s32 D_05A14C;
extern volatile s32 D_05A148;
extern volatile s32 D_05A144;
extern volatile s32 D_05A150;
extern s32 D_05A158[];
extern volatile u8 D_122570;
extern volatile u8 D_122470;
extern volatile s32 D_018700;
extern volatile s32 D_018704;
extern u8 *D_018FB4;
extern u8 *D_018FB8;
extern u8 *D_018FBC;
extern u8 D_0193B0[];
extern s32 D_019380;
extern u8 D_018FD4[];
extern s32 D_0192F4;
extern s32 D_0192F8;
extern u8 D_06D3F0[];
extern u8 D_09E3F0[];

extern void func_00FDF4(s32, s32, s32);
extern void func_00FC2C(s32, s32, void *, s32, s32);
extern void func_00FE3C(s32, s32);
extern void func_000000(void);
extern void func_00F2A0(void);

s32 func_010100(s32 *arg) {
    s32 a1 = arg[0];
    s32 a2 = arg[1];
    s32 ret;
    SdEffectAttr *attr;

    D_06D220[0] = D_06D220[1] = 0;
    D_06D228[0] = D_06D228[1] = 0;
    D_018FB4 = D_05CB70;
    D_018FB8 = D_06CB70;
    D_018FBC = D_06CC70;
    D_06D218[0] = D_06CF10;
    D_06D210[0] = D_06CF10;
    D_06D218[1] = D_06CF10 + 384;
    D_06D210[1] = D_06CF10 + 384;
    D_122570 = 0;
    D_122470 = 0;
    D_018700 = a1;
    D_018704 = 128;
    D_06D230[0] = D_06D230[1] = 0;
    D_06CEF0 = D_06CE70;
    D_05A1D8 = a2;
    D_019350 = 0;
    D_05A14C = 0;
    D_05A148 = 0;
    D_05A144 = 0;
    D_05A150 = 0;
    for (ret = 16; ret != 0; ret--) {
        D_05A158[ret - 1] = 0;
    }
    D_0193B0[0] = 0;
    D_0193B0[1] = 1;
    D_0193B0[2] = 0;
    D_0193B0[3] = 0;
    ret = imp_libsd_4(0);
    if (ret == 0) {
        imp_intrman_9();
        imp_intrman_6(36);
        imp_intrman_6(40);
        imp_intrman_6(9);
        imp_libsd_7(0x1600, 0x00FFFFFF);
        imp_libsd_7(0x1601, 0x00FFFFFF);
        imp_libsd_9(0x1D00, 0x001FFFFF);
        imp_libsd_9(0x1D01, 0x0001FFFF);
        imp_libsd_11(2, 0);
        imp_libsd_11(3, 0);
        attr = (SdEffectAttr *)D_018FB4;
        attr->mode = 4;
        attr->depth_R = 0;
        attr->depth_L = 0;
        attr->delay = 0;
        attr->feedback = 0;
        imp_libsd_23(0, attr);
        imp_libsd_23(1, attr);
        imp_libsd_25(0, 0, 5);
        imp_libsd_19(0, 1);
        imp_libsd_25(1, 0, 5);
        imp_libsd_19(0, 1);
        if (D_018700 == 0) {
            ret = 1;
            while (ret != 0) {
                s32 type = imp_cdvdman_12();

                D_019380 = type;
                switch (type) {
                case 0:
                case 1:
                case 5:
                case 16:
                case 17:
                case 253:
                case 254:
                    imp_thbase_33(1000);
                    break;
                default:
                    ret = 0;
                    break;
                }
            }
        }
        imp_libsd_5(0x0B80, 0x7FFF);
        imp_libsd_5(0x0C80, 0x7FFF);
        imp_libsd_5(0x0B81, 0x7FFF);
        imp_libsd_5(0x0C81, 0x7FFF);
        imp_libsd_5(0x0D81, 0x7FFF);
        imp_libsd_5(0x0E81, 0x7FFF);
        ret = (D_018700 != 0 || D_019380 != 18) ? 0x800 : 0;
        imp_libsd_11(10, (D_018704 | ret) & 0xFFFF);
        imp_libsd_5(0x0800, 0x0FC0);
        imp_libsd_5(0x0801, 0x0FCC);
        imp_libsd_5(0x0980, 0x3FFF);
        imp_libsd_5(0x0A80, 0x3FFF);
        imp_libsd_5(0x0981, 0x3FFF);
        imp_libsd_5(0x0A81, 0x3FFF);
        imp_libsd_5(0x0F80, 0);
        imp_libsd_5(0x1080, 0);
        imp_libsd_5(0x0F81, 0);
        imp_libsd_5(0x1081, 0);
        imp_libsd_11(2, 1);
        imp_libsd_11(4, 0);
        imp_libsd_11(6, 1);
        imp_libsd_11(3, 1);
        imp_libsd_11(5, 0);
        imp_libsd_11(7, 1);
        func_00FDF4(0, 0, 0);
        func_00FC2C(0, 0, D_018FD4, 0x5010, 64);
        func_00FE3C(0, 1);
        func_000000();
        func_00F2A0();
        ret = (s32)D_018FB4;
        arg[3] = (s32)D_06D3F0;
        arg[4] = (s32)D_09E3F0;
        arg[1] = D_0192F4;
        arg[2] = D_0192F8;
    }
    return ret;
}
