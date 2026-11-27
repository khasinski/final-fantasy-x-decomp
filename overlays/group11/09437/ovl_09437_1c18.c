#include "common.h"

extern u8 *D_01B00CF4;
extern u8 D_01B0A550[];
extern u8 D_01B0A5B0[];
extern u8 D_01B0A5D0[];
extern u8 *D_01B0A5F0;
extern u8 *D_01B0A5F8;

extern s32 func_0011ABB8(void);
extern void func_01B01E58(void);
extern s32 func_01B05568(void *);
extern void func_01B06108(void *);
extern void func_01B07770(void);
extern s32 func_01B09998(void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B01C18(void *a0)
{
    u8 *s0 = D_01B0A5F0;
    s32 s2;
    s32 s1;

    func_01B07770();
    D_01B00CF4 = D_01B0A5F8;
    s2 = func_01B09998(D_01B0A550);
    if (func_0011ABB8() != 0) {
        return;
    }
    s1 = func_01B05568(D_01B0A5B0);
    func_01B05568(D_01B0A5D0);
    if (s2 == 0 || s1 == 0) {
        copy_vec(s0 + 0x1B80, s0 + 0x1BA0);
        copy_vec(s0 + 0x1BE0, s0 + 0x1C00);
        return;
    }
    *(s32 *)(s0 + 0x1F30) = 1;
    func_01B01E58();
    func_01B06108(a0);
}
