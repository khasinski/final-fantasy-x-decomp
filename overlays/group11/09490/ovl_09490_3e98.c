#include "common.h"

extern void func_01B08760(void *);
extern s32 func_002EFD78(void);

void func_01B03E98(u8 *arg0) {
    s32 i;
    u8 *p;

    func_01B08760(arg0);
    *(s32 *)(arg0 + 0x214) = 0;
    *(s32 *)(arg0 + 0x228) = 0;
    *(u32 *)(arg0 + 0x210) = 0x80808080;
    *(float *)(arg0 + 0x218) = 1.0f;
    *(float *)(arg0 + 0x21C) = 1.0f;
    *(u32 *)(arg0 + 0x224) = (u16)func_002EFD78();
    p = arg0 + 0x24F;
    for (i = 31; i >= 0; i--) {
        *p-- = 0;
    }
}
