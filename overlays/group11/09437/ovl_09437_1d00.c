#include "common.h"

extern s32 D_01B0A500;
extern u8 D_01B0A508[];
extern u8 *D_01B0A54C;
extern u8 *D_01B0A5F0;

extern s32 func_0011ABB8(void);
extern void func_00110718(s32, s32);
extern void func_001CDDD8(s32);
extern void func_0029A860(void);
extern s32 func_01B03948(s32, s32);
extern s32 func_01B064C8(void *, void *);

void func_01B01D00(void)
{
    u8 *s0 = D_01B0A5F0;
    s32 r;

    if (func_0011ABB8() == 0) {
        r = func_01B064C8(D_01B0A508, D_01B0A54C);
    } else {
        r = 0;
    }
    if (r == 1 && *(s32 *)(s0 + 0x1F30) == 1) {
        func_00110718(func_01B03948(-1, 0), 0);
        func_0029A860();
        func_001CDDD8(D_01B0A500);
    }
}
