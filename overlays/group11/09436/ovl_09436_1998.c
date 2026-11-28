#include "common.h"

extern u8 *D_01B09358;
extern u8 D_01B09290[];
extern u8 D_01B10360[];
extern u8 D_01B00758[];

extern void func_01B05548(void *, void *, s32, s32, s32, s32, float);
extern void func_01B018C8(void);
extern void func_01B04CD0(void *, void *, void *);
extern void func_01B09048(void *, s32, s32, float, float);

void func_01B01998(void) {
    u8 *s = D_01B09358;
    u8 *obj = s + 0x4C0;

    func_01B05548(D_01B09290, obj, 4, 0, 0, 0, 0.09f);
    *(float *)(obj + 0xC4) = *(float *)(s + 0x54A0);
    *(void (**)(void))(obj + 0x104) = func_01B018C8;
    func_01B04CD0(s + 0x5420, D_01B10360, D_01B00758);
    *(void **)(obj + 0x110) = s + 0x5420;
    func_01B09048(s + 0x1160, 50, 0, 1.0f, 0.5f);
}
