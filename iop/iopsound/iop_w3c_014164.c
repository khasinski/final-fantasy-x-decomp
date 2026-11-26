#include "iopsound.h"

extern u8 D_05A078[];
extern u8 D_05A0D4[];
extern u8 D_05AA20[];
extern s32 D_05A118;
extern void func_013EF0(void);

s32 func_014164(void) {
    s32 sd;

    imp_sifcmd_19(D_05A078, imp_thbase_20());
    imp_sifcmd_17(D_05A0D4, 0x1001, func_013EF0, D_05AA20, NULL, NULL, D_05A078);
    while (1) {
        while ((sd = imp_sifcmd_20(D_05A078)) != 0) {
            imp_sifcmd_21(sd);
        }
        imp_thbase_24();
        if (D_05A118 != 0) {
            break;
        }
    }
    imp_sifcmd_24(D_05A0D4, D_05A078);
    imp_sifcmd_25(D_05A078);
    D_05A118--;
    return 0;
}
