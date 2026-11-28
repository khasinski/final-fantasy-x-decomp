#include "common.h"
#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

#define copy_vec_m(dst, src) do { \
    MMI_COPY_LQ_A3(dst, src); \
    MMI_COPY_SQ_A3(dst); \
} while (0)

extern u8 *D_01B0A568;
extern u8 *D_01B0A56C;
extern u8 *D_01B01874;
extern u8 D_01B0A488[];
extern u8 D_01B0A4E8[];
extern u8 D_01B0A548[];

extern void func_01B07038(void);
extern s32 func_01B09260(void *);
extern void func_01B04E30(void *);
extern void func_01B07860(void);
extern void func_01B02010(void);
extern void func_01B059D0(void *);

void func_01B01D28(void *a0) {
    u8 *s = D_01B0A568;
    s32 r;

    func_01B07038();
    D_01B01874 = D_01B0A56C;
    r = func_01B09260(D_01B0A488);
    func_01B09260(D_01B0A4E8);
    if (r == 0) {
        register u8 *dst __asm__("$3") = s + 0x14E0;
        register u8 *src __asm__("$2") = s + 0x1500;
        __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        func_01B04E30(D_01B0A548);
        func_01B07860();
    } else {
        *(s32 *)(s + 0x180C) = 1;
        func_01B02010();
        func_01B059D0(a0);
    }
}
