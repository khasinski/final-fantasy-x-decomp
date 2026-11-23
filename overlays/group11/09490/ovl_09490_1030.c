#include "common.h"

extern s32 D_01B0B2C8;
extern s32 D_01B0B2CC;
extern u8 D_01B10AB0[];

extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B03A00(void);
extern void func_01B046D8(s32);
extern void func_01B060C8(void *, s32, s32);
extern void func_01B067D8(void);
extern void func_01B06970(void *, s32, s32);
extern void func_01B06ED0(void);
extern void func_01B079A8(void);

s32 func_01B01030(s32 arg0) {
    D_01B0B2C8 = arg0;
    func_01B046D8(arg0);
    func_01B067D8();
    func_01B06ED0();
    func_01B079A8();
    func_002B22F8(0x3400, 0x800);
    func_01B03A00();
    func_002B4980(D_01B10AB0);
    func_01B060C8(D_01B10AB0, 0, 1000);
    func_01B06970(D_01B10AB0, 0, 1000);
    D_01B0B2CC = 0;
    return 0;
}
