#include "common.h"

extern void func_01B0E408(void *);

typedef struct {
    void *f0;
    u8 *f4;
} Arg2698;

void func_01B02698(Arg2698 *arg) {
    u8 *s = arg->f4;
    s32 st;

loop:
    st = *(s32 *)(s + 0x18);
    if (st == 1) {
        goto case_1;
    }
    if (st == 0) {
        goto case_0;
    }
    if (st == 10000) {
        goto case_10000;
    }
    goto done;
case_0:
    __asm__("" : "+r"(st));
    st += 1;
    __asm__ volatile("" : "+r"(st));
    *(s32 *)(s + 0x40) = 90;
    __asm__ volatile("" : "+r"(st));
    *(s32 *)(s + 0x18) = st;
    goto done;
case_1:
    if (*(s32 *)(s + 0x40) > 0) {
        goto done;
    }
    *(s32 *)(s + 0x18) = 10000;
    goto loop;
case_10000: {
    void *p = arg->f0;
    func_01B0E408(&p);
}
done:
    *(s32 *)(s + 0x40) -= 1;
}
