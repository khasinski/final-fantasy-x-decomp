#include "common.h"
#include "vu0.h"

#define copy_vec_m(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0A480;

extern void func_01B04A20(s32, void *);
extern void func_01B04FA0(s32, void *, void *);
extern void func_01B044E8(s32, s32);

void func_01B03158(void) {
    u8 *s = D_01B0A480;
    u8 *pb90 = s + 0xB90;

    func_01B04A20(2, pb90);
    copy_vec(s + 0xCB0, s + 0xC70);
    {
        register u8 *src2 __asm__("$3") = s + 0xC80;
        u8 *dst2 = s + 0xCC0;
        copy_vec_m(dst2, src2);
    }
    {
        register u8 *a1 __asm__("$5") = pb90;
        func_01B04FA0(2, a1, s + 0xCB0);
    }
    func_01B044E8(2, 0);
}
