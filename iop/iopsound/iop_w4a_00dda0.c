#include "iopsound.h"

typedef struct {
    u8 pad00[0xDC];
    s32 unkDC;
} S00DDA0_Stream;

extern char D_0163F0[];
extern char D_016400[];
extern s32 D_018710;
extern S00DDA0_Stream *D_018754;
extern char *D_018758;
extern char *D_018FB8;
extern s32 D_019348;
extern s32 D_019354;
extern s32 *D_019384;
extern s32 D_06D2E0[];

extern void func_00C938(s32, s32);
extern void func_00F084(s32);
extern s32 func_00FB48(char *, s32);

void func_00DDA0(char *name, s32 a1, s32 a2) {
    func_00C938(2, 0);
    D_018710 = 1;
    *D_019384 = 0;
    imp_sysclib_23(D_018758, name);
    D_019354 = a1;
    D_018754->unkDC = a2 << 11;
    if (imp_sysclib_27(name) == 0) {
        D_06D2E0[0] = a1;
        D_06D2E0[1] = 0;
    } else {
        if (func_00FB48(name, ':') == 0) {
            if (name[0] == 'v' && (name[1] == 'j' || name[1] == 'e' || name[1] == 'p')) {
                imp_sysclib_19(D_018758, D_0163F0, D_018FB8, name);
            } else {
                imp_sysclib_19(D_018758, D_016400, D_018FB8, name);
            }
        }
        imp_sysclib_23(D_06D2E0, D_018758);
    }
    func_00F084(20);
    imp_thsemap_7(D_019348);
}
