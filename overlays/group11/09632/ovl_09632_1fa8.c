#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0xC];
    float fD4;
} Sub980;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[2];
} SubC20;

typedef struct {
    u8 pad00[0x980];
    Sub980 sub980;
    u8 padA58[0x1B8];
    float vecC10[4];
    SubC20 subC20;
    u8 padCBC[0x14C];
    float fE08;
} OvlState;

extern u8 D_01B09558[];
extern OvlState *D_01B096A0;

extern void func_01B05330(void *, void *, int, int, int, int, float);
extern void func_01B089E0(void *, int);
extern void func_00173650(int *);

void func_01B01FA8(void)
{
    int arr[4];
    register OvlState *s __asm__("$16") = D_01B096A0;
    register Sub980 *sub __asm__("$17") = &s->sub980;
    SubC20 *c20;

    func_01B05330(D_01B09558, sub, 8, 0, 0, 0, 0.01f);
    copy_vec(s->vecC10, (u8 *)s + 0xA50);

    sub->fC0 = -1.5707963705062866f;
    sub->fC4 = s->fE08;
    sub->fD4 -= 30.0f;

    c20 = &s->subC20;
    c20->b87 = 64;
    c20->w88 = 130;
    c20->b98 = 68;
    c20->b83 = 0;
    c20->b82 = 0;
    c20->b81 = 0;
    c20->b80 = 0;
    c20->b84 = 0;
    c20->b85 = 0;
    c20->b86 = 0;
    c20->b99 = 0;
    func_01B089E0(c20, 20);

    arr[0] = 0;
    arr[3] = 128;
    arr[1] = 0;
    arr[2] = 0;
    func_00173650(arr);
}
