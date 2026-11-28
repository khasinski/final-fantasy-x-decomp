#include "common.h"

extern void *D_01B006A8;
extern void *D_01B007B8;
extern void *D_01B007EC;
extern s32 D_01B00BC8;
extern s32 D_01B00BCC;
extern s32 D_01B00BD0;
extern s32 D_01B00BD4;
extern void *D_00303550;

extern s32 func_002A7120(void *, s32, s32);
extern void func_002A7308(void *, void *, s32, void *);

void func_01B00C08(void) {
    func_002A7120(D_01B006A8, 2, 1);
    if (D_01B007B8 == 0) {
        D_01B007B8 = D_01B007EC;
        func_002A7308(D_01B007EC, D_01B006A8, 2, D_00303550);
    }
    {
        register s32 v0 __asm__("$2") = 0x1CCC8;
        D_01B00BCC = D_01B00BC8 = 0;
        D_01B00BD4 = D_01B00BD0 = v0;
    }
}
