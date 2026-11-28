#include "common.h"
#include "vu0.h"

static inline void copy_vec_sd(void *src, void *dst) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A988;
extern u8 *D_01B0A990;
extern u8 *D_01B00D64;
extern u8 D_01B0A8A8[];
extern u8 D_01B0A908[];
extern u8 D_01B0A968[];

extern void func_01B07470(void);
extern s32 func_01B09698(void *);
extern void func_01B05268(void *);
extern void func_01B07C98(void);
extern void func_01B01D88(void);
extern void func_01B05E08(void *);

void func_01B011A0(void *a0) {
    u8 *s1 = D_01B0A988;
    s32 s0;

    func_01B07470();
    D_01B00D64 = D_01B0A990;
    s0 = func_01B09698(D_01B0A8A8);
    func_01B09698(D_01B0A908);
    if (s0 == 0) {
        register u8 *dst __asm__("$3") = s1 + 0x2AF0;
        register u8 *src __asm__("$2") = s1 + 0x2B10;
        __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        func_01B05268(D_01B0A968);
        func_01B07C98();
    } else {
        *(s32 *)(s1 + 0x3BF8) = 1;
        func_01B01D88();
        func_01B05E08(a0);
    }
}
