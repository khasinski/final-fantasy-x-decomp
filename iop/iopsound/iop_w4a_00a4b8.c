#include "iopsound.h"

extern char D_016150[];
extern char D_016168[];
extern char D_01617C[];
extern char D_016184[];
extern char D_01618C[];
extern char D_016194[];
extern char D_01619C[];
extern char D_0161A4[];
extern s32 D_019394;
extern s32 D_01939C;

void func_00A4B8(s32 mode) {
    switch (mode) {
    case 1:
        imp_sysmem_14(D_016150, D_016168, D_01617C, D_016184);
        break;
    case 2:
        imp_sysmem_14(D_016150, D_016168, D_01618C, D_016184);
        break;
    case 3:
        imp_sysmem_14(D_016150, D_016168, D_016194, D_016184);
        break;
    default:
        imp_sysmem_14(D_016150, D_016168, D_01619C, D_016184);
        break;
    }

    D_019394 = 1;
    imp_thsemap_6(D_01939C);
    while (D_019394 != 0) {
        imp_thbase_33(1000);
    }

    switch (mode) {
    case 1:
        imp_sysmem_14(D_0161A4, D_016168, D_01617C, D_016184);
        break;
    case 2:
        imp_sysmem_14(D_0161A4, D_016168, D_01618C, D_016184);
        break;
    case 3:
        imp_sysmem_14(D_0161A4, D_016168, D_016194, D_016184);
        break;
    default:
        imp_sysmem_14(D_0161A4, D_016168, D_01619C, D_016184);
        break;
    }
}
