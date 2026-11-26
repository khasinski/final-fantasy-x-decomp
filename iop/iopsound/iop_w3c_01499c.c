#include "iopsound.h"

extern s32 D_05A120;
extern s32 D_018FB4;
extern s32 D_018718;
extern void func_00F038(s32);
extern void func_00BE50(s32);
extern void func_00F084(s32);

void func_01499C(void) {
    while (1) {
        imp_thsemap_8(D_05A120);
        func_00F038(12);
        func_00BE50(D_018FB4);
        func_00F084(12);
        D_018718++;
    }
}
