#include "iopsound.h"

extern s32 D_05A124;
extern s32 D_018FCC;
extern s32 *D_018FB4;
extern s32 D_018FD0;
extern s32 D_019320;
extern s32 D_01870C;
extern s32 D_018718;

extern char D_016BD0[];
extern char D_016BFC[];
extern char D_0165F0[];
extern char D_016604[];
extern char D_01660C[];

extern void func_00F038(s32);
extern void func_00F120(s32);
extern s32 func_00BB90(void *);
extern void func_00F0D4(s32);
extern void func_00F084(s32);

void func_0149F4(void) {
    while (1) {
        s32 rem;
        s32 *p;

        imp_thsemap_8(D_05A124);
        func_00F038(13);
        func_00F120(17);
        rem = D_018FCC;
        p = D_018FB4;
        while (rem > 0) {
            s32 sz = p[3];

            if (p[0] == 0x65536553 && p[1] == 0x20202070) {
                if (sz > 0 && (sz & 3) == 0) {
                    p[2] |= 0x80000000;
                    if (func_00BB90(p) == 0) {
                        rem -= sz;
                        break;
                    }
                    rem -= sz;
                } else {
                    imp_sysmem_14(D_016BD0, D_0165F0, D_016604, p[2] & 0x7FFFFFFF, sz, D_01660C);
                    func_00F0D4(18);
                    break;
                }
            } else {
                if ((u32)rem >= 17) {
                    imp_sysmem_14(D_016BFC, D_0165F0, D_016604, rem, D_01660C);
                    func_00F0D4(17);
                }
                break;
            }
            p = (s32 *)((u8 *)p + sz);
        }
        if (D_018FD0 != 0) {
            D_01870C = 2;
            imp_thsemap_6(D_019320);
        } else {
            D_018718++;
        }
        func_00F084(13);
    }
}
