#include "common.h"
#include "vu0.h"

extern u8 *D_01B0BC98;
extern u32 D_01B0BCA0;
extern u32 D_01B010A4;
extern u8 D_01B0BBB8[];
extern u8 D_01B0BC18[];
extern u8 D_01B0BC78[];
extern void func_01B08678(void);
extern int func_01B0A8A0(void *);
extern void func_01B06470(void *);
extern void func_01B08EA0(void);
extern void func_01B020C8(void);
extern void func_01B07010(void *);

void func_01B014E0(void *a0)
{
    u8 *s1 = D_01B0BC98;
    int s0;

    func_01B08678();
    D_01B010A4 = D_01B0BCA0;
    s0 = func_01B0A8A0(D_01B0BBB8);
    func_01B0A8A0(D_01B0BC18);
    if (s0 == 0) {
        register void *dst __asm__("$3") = s1 + 0x2AF0;
        register void *src __asm__("$2") = s1 + 0x2B10;
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
        func_01B06470(D_01B0BC78);
        func_01B08EA0();
    } else {
        *(int *)(s1 + 0x3BF8) = 1;
        func_01B020C8();
        func_01B07010(a0);
    }
}
