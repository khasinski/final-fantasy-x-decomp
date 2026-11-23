#include "common.h"

extern s32 D_01B0B39C;

extern void func_0010D380(s32, s32, s32);
extern void func_0010D3A8(s32, s32, s32);
extern void func_002A7308(s32, s32, s32, s32);
extern s32 func_01B04908(s32, s32);

s32 func_01B03CD8(void) {
    return func_01B04908(-1, 0);
}

void func_01B03CF8(void) {
    s32 id = func_01B03CD8();

    func_0010D380(id, -1, 0x3C00);
    func_0010D3A8(id, -1, 0x2EE0);
    func_002A7308(D_01B0B39C, id, 1, 0);
    func_0010D380(id, -1, -1);
    func_0010D3A8(id, -1, -1);
}
