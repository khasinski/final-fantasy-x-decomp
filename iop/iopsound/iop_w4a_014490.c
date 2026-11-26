#include "iopsound.h"

typedef struct {
    s32 unk00;
    u32 unk04;
} S014490_Req;

extern char D_0165F0[];
extern char D_016604[];
extern char D_01660C[];
extern char D_016BAC[];
extern volatile u32 D_01870C;
extern s32 D_018718;
extern s32 D_019320;
extern S014490_Req D_019358;
extern u32 D_06CE70[];
extern u32 *D_06CEF0;

extern s32 func_00AAA8(s32, u32);
extern void func_00E9A0(s32);
extern void func_00F038(s32);
extern void func_00F084(s32);
extern void func_00F0D4(s32);

void func_014490(void) {
    u32 status;
    u32 *p;
    u32 mask = 0x00FFFFFF;
    S014490_Req *req = &D_019358;

    while (1) {
        imp_thsemap_8(D_019320);
        func_00F038(1);
        status = imp_libsd_20(0, 0) | imp_libsd_20(1, 0);
        func_00E9A0(0);
        if ((status & mask) != 0) {
            func_00F0D4(24);
            do {
                imp_thbase_33(1000);
                status = imp_libsd_20(0, 0) | imp_libsd_20(1, 0);
            } while ((status & mask) != 0);
        }
        if ((D_01870C & 1) != 0) {
            if (req->unk04 < 10000U) {
                do {
                } while (func_00AAA8(req->unk00, req->unk04) < 0);
            } else {
                imp_sysmem_14(D_016BAC, D_0165F0, D_016604, req->unk04, D_01660C);
                func_00F0D4(3);
            }
            D_01870C &= ~1U;
        } else if ((D_01870C & 2) != 0) {
            for (p = D_06CE70; p < D_06CEF0; p++) {
                if (*p < 10000U) {
                    do {
                    } while (func_00AAA8(-1, *p) < 0);
                } else {
                    imp_sysmem_14(D_016BAC, D_0165F0, D_016604, *p, D_01660C);
                    func_00F0D4(3);
                }
            }
            D_06CEF0 = D_06CE70;
            D_01870C &= ~2U;
        }
        func_00F084(1);
        D_018718++;
    }
}
