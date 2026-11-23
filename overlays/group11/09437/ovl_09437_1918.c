#include "common.h"

extern s32 D_01B0A500;
extern s32 D_01B0A5FC;
extern s32 D_01B0A600;
extern s32 D_01B0A604;
extern s32 D_01B0A608;
extern s32 D_01B0A60C;

extern void func_0011ABA8(s32);
extern s32 func_001BBCF8(s32, s32);
extern void func_001E33E0(s32, s32);
extern s32 func_001E34E0(s32);
extern s32 func_002B2E10(void (*)(void), s32, s32, s32);
extern void func_002B2F18(s32);
extern void func_01B014C0(void);
extern s32 func_01B03878(s32);

void func_01B01918(void) {
    D_01B0A600 = 10;
    D_01B0A604 = 0;
    D_01B0A60C = 0;
    D_01B0A5FC = func_002B2E10(func_01B014C0, 0, 0, 0);
}

void func_01B01968(u8 *arg0) {
    s32 v = func_01B03878(-1);

    switch (D_01B0A604) {
    case 0:
        D_01B0A600--;
        if (D_01B0A600 <= 0) {
            func_001E33E0(v, 0);
            D_01B0A604 = 1;
        }
        break;
    case 1:
        if (func_001E34E0(v) >= 0) {
            D_01B0A600 = 0;
            D_01B0A604 = 2;
        }
        break;
    case 2:
        D_01B0A600++;
        if (D_01B0A600 >= 10) {
            D_01B0A604 = 3;
            arg0[0x56] = 1;
        }
        break;
    }
}

void func_01B01A50(void) {
    func_0011ABA8(0);
    func_002B2F18(D_01B0A5FC);
    D_01B0A5FC = -1;
    D_01B0A608 = func_001BBCF8(D_01B0A500, func_01B03878(0));
}
