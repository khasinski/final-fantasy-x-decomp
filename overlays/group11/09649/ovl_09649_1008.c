#include "common.h"

extern u8 *D_01B00B04;
extern u8 *D_01B0B174;
extern u8 D_01B0B178[];
extern u8 D_01B0B1D8[];
extern u8 *D_01B0B1F8;
extern u8 *D_01B0B200;
extern u8 *D_01B0B204;

extern void func_01B01CE0(void);
extern void func_01B05B38(void *);
extern void func_01B066D8(void *);
extern void func_01B07D40(void);
extern void func_01B08568(void);
extern s32 func_01B09F68(void *);

void func_01B01008(void *a0)
{
    u8 *s0 = D_01B0B1F8;

    func_01B07D40();
    D_01B00B04 = D_01B0B204;
    D_01B0B200 = D_01B0B174;
    if (func_01B09F68(D_01B0B178) == 0) {
        func_01B05B38(D_01B0B1D8);
        func_01B08568();
    } else if (*(s32 *)(s0 + 0x317C) == 1) {
        *(s32 *)(s0 + 0x3180) = 1;
        func_01B01CE0();
        func_01B066D8(a0);
    }
}
