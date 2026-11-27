#include "common.h"

extern u8 *D_01B00F94;
extern u8 D_01B0C748[];
extern u8 D_01B0C7A8[];
extern u8 D_01B0C808[];
extern u8 D_01B0C828[];
extern u8 D_01B0C848[];
extern u8 D_01B0C868[];
extern u8 *D_01B0C888;
extern u8 *D_01B0C88C;

extern void func_01B07000(void *);
extern void func_01B07BA0(void *);
extern void func_01B09208(void);
extern void func_01B09A30(void);
extern s32 func_01B0B430(void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B036F0(void *a0)
{
    u8 *s1 = D_01B0C888;
    s32 s0;

    func_01B09208();
    D_01B00F94 = D_01B0C88C;
    s0 = func_01B0B430(D_01B0C748);
    func_01B0B430(D_01B0C7A8);
    if (s0 == 0) {
        copy_vec(s1 + 0x880, s1 + 0x960);
        copy_vec(s1 + 0x8C0, s1 + 0x980);
        copy_vec(s1 + 0x900, s1 + 0x9A0);
        copy_vec(s1 + 0x940, s1 + 0x9C0);
        func_01B07000(D_01B0C808);
        func_01B07000(D_01B0C828);
        func_01B07000(D_01B0C848);
        func_01B07000(D_01B0C868);
        func_01B09A30();
    } else {
        *(s32 *)(s1 + 0x862C) = 1;
        func_01B07BA0(a0);
    }
}
