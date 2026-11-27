#include "common.h"

extern void func_01B0DF60(void *);
extern void func_01B0DE58(void *);

void func_01B0BBD8(u8 **arg) {
    u8 *s3;
    s32 i;
    u8 *p;
    void *sp0;
    void *sp4;

    s3 = *arg;
    p = s3 + 0x20;
    for (i = 0; i < *(s32 *)(s3 + 0x520); i++) {
        sp0 = p;
        func_01B0DF60(&sp0);
        sp4 = p;
        func_01B0DE58(&sp4);
        p += 0xA0;
    }
}
