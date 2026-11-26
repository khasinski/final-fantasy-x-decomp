#include "iopsound.h"

extern s32 D_019398;
extern u8 D_06D3F0[];
extern void func_00F038(s32);
extern void func_00E9A0(s32);
extern void func_00F0D4(s32);
extern void func_00B1E0(void *);
extern void func_00F084(s32);

void func_0146C8(void) {
    u32 status;

    while (1) {
        imp_thsemap_8(D_019398);
        func_00F038(0);
        status = imp_libsd_20(0, 0) | imp_libsd_20(1, 0);
        func_00E9A0(0);
        if ((status & 0x00FFFFFF) != 0) {
            func_00F0D4(24);
            do {
                imp_thbase_33(1000);
                status = imp_libsd_20(0, 0) | imp_libsd_20(1, 0);
            } while ((status & 0x00FFFFFF) != 0);
        }
        func_00B1E0(D_06D3F0);
        func_00F084(0);
    }
}
