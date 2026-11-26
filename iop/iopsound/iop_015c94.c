#include "iopsound.h"

extern s32 func_015B20(void);
extern void func_00F0D4(s32);
extern s32 func_00EFB0(void);

extern char D_016C80[];
extern char D_0165F0[];
extern char D_016CA8[];
extern char D_01660C[];
extern s32 D_06D26C;

s32 func_015C94(s32 argc) {
    s32 ret = 1;

    if (argc > 0) {
        ret = func_015B20();
    } else if (argc < 0) {
        imp_sysmem_14(D_016C80, D_0165F0, D_016CA8, D_01660C);
        func_00F0D4(30);
    }

    D_06D26C = func_00EFB0();
    return ret;
}
