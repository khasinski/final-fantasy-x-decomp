#include "iopsound.h"

extern u8 D_05A060[];
extern u8 D_05A090[];
extern u8 D_05A1E0[];
extern s32 D_05A118;
extern void func_013E94(void);

s32 func_014088(void) {
    s32 sd;

    imp_sifcmd_19(D_05A060, imp_thbase_20());
    imp_sifcmd_17(D_05A090, 0x1000, func_013E94, D_05A1E0, NULL, NULL, D_05A060);
    while (1) {
        while ((sd = imp_sifcmd_20(D_05A060)) != 0) {
            imp_sifcmd_21(sd);
        }
        imp_thbase_24();
        if (D_05A118 != 0) {
            break;
        }
    }
    imp_sifcmd_24(D_05A090, D_05A060);
    imp_sifcmd_25(D_05A060);
    D_05A118--;
    return 0;
}
