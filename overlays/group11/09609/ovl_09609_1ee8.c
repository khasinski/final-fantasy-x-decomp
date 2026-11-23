#include "common.h"

typedef struct {
    u8 pad0[0x56];
    u8 unk56;
} Arg1F58;

extern s32 D_01B0E194;
extern s32 D_01B0E198;
extern s32 D_01B0E19C;
extern s32 D_01B0E1A0;
extern s32 D_01B0E1A4;
extern s32 D_01B0E1A8;

extern void Sg_SetFocus(s32, s32);
extern void func_0011ABA8(s32);
extern void TOBtlInitWakkaLimitWindow(void);
extern void func_0021BBC8(void);
extern void TOBtlCloseWakkaLimitWindow(void);
extern s32 func_0021BC30(void);
extern s32 func_002B2E10(void (*)(void), s32, s32, s32);
extern void func_002B2F18(s32);
extern void func_01B01550(void);
extern void func_01B01A40(void);
extern void func_01B020C0(void);
extern s32 func_01B02818(void);
extern void func_01B073A8(s32);

void func_01B01EE8(void) {
    D_01B0E1A0 = 0;
    D_01B0E1A4 = 0;
    D_01B0E1A8 = 0;
    D_01B0E19C = 10;
    D_01B0E198 = func_002B2E10(func_01B01A40, 0, 0, 0);
    Sg_SetFocus(0, 0);
    Sg_SetFocus(1, 0);
}

void func_01B01F58(Arg1F58 *arg0) {
    func_01B073A8(-1);
    switch (D_01B0E1A0) {
    case 0:
        D_01B0E19C--;
        if (D_01B0E19C <= 0) {
            TOBtlInitWakkaLimitWindow();
            func_0021BBC8();
            D_01B0E1A8 = 1;
            D_01B0E1A0 = 1;
        }
        break;
    case 1:
        if (func_0021BC30() == 1) {
            func_01B020C0();
            D_01B0E1A0 = 2;
        }
        break;
    case 2:
        if (func_01B02818() == 1) {
            TOBtlCloseWakkaLimitWindow();
            D_01B0E1A8 = 0;
            D_01B0E19C = 0;
            D_01B0E1A0 = 3;
        }
        break;
    case 3:
        D_01B0E19C++;
        if (D_01B0E19C >= 10) {
            D_01B0E1A0 = 4;
            arg0->unk56 = 1;
        }
        break;
    case 4:
        break;
    }
}

void func_01B02078(void) {
    func_0011ABA8(0);
    func_002B2F18(D_01B0E198);
    D_01B0E198 = -1;
}

void func_01B020B0(void) {
    D_01B0E194 = -1;
    func_01B01550();
}
