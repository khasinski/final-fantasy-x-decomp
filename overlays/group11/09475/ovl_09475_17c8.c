#include "common.h"

extern void *D_01B0A074;
extern void *D_01B0A078;

extern void *func_01B037F0(s32);
extern void func_0010D380(void *, s32, s32);
extern s32 func_0010D3A8(void *, s32, s32);
extern void func_002A7308(void *, void *, s32, s32);
extern void func_01B04A98(s32, s32);

void func_01B017C8(void) {
    void *p;

    p = func_01B037F0(1);
    func_0010D380(p, -1, 0x3C00);
    func_0010D3A8(p, -1, 0x2EE0);
    func_002A7308(D_01B0A074, p, 1, 0);
    func_0010D380(p, -1, -1);
    func_0010D3A8(p, -1, -1);
    func_01B04A98(1, 1);

    p = func_01B037F0(2);
    func_0010D380(p, -1, 0x3C00);
    func_0010D3A8(p, -1, 0x2EE0);
    func_002A7308(D_01B0A078, p, 1, 0);
    func_0010D380(p, -1, -1);
    func_0010D3A8(p, -1, -1);
}
