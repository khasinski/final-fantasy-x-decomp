#include "iopsound.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
} S_Fade;

extern u8 *D_019374;
extern s32 *D_01936C;
extern S_Fade D_122460;

extern s32 func_0111F4(s32);
extern void func_009040(s32, s32);
extern void func_008D48(s32, s32);

s32 func_011594(s32 *arg) {
    u8 *p = D_019374;
    s32 *q;
    s32 *b;
    s32 tmp;

    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    p += 912;
    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }

    q = D_01936C;
    if (*arg == q[449]) {
        if (D_122460.f08 != 0) {
            b = q + 228;
            do {
                tmp = *q;
                *q = *b;
                *b = tmp;
                q++;
                b++;
            } while (q < D_01936C + 228);
            if (arg[1] != 0) {
                tmp = 512 - (D_122460.f00 >> 12);
                D_122460.f00 = tmp << 12;
                D_122460.f08 = arg[1];
                D_122460.f04 = ((512 - tmp) << 12) / arg[1];
            }
        }
        return -2;
    }

    if (*arg == q[221]) {
        return -1;
    }
    if (*arg == q[449]) {
        return -1;
    }
    if (func_0111F4(*arg) < 0) {
        func_009040(D_01936C[221], arg[1]);
        return -1;
    }
    if (arg[1] != 0) {
        q = D_01936C;
        b = q + 228;
        do {
            tmp = *q;
            *q = *b;
            *b = tmp;
            q++;
            b++;
        } while (q < D_01936C + 228);
        D_122460.f00 = 0;
        D_122460.f08 = arg[1];
        D_122460.f04 = 0x200000 / arg[1];
    }
    func_008D48(*arg, 0);
    return 0;
}
