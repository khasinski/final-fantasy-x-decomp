#include "common.h"

extern void func_01B09E80(void *);
extern void func_01B09D88(void *);
extern void func_01B0B650(void *);
extern void func_01B0B5A8(void *);
extern void func_01B0E710(void *);
extern void func_01B0E6E8(void *);

void func_01B04350(void **s4)
{
    void *a0;
    void *a1;
    void *a2;
    void *a3;
    void *a4;
    void *a5;
    void *a6;
    void *a7;
    u8 *s3 = (u8 *)s4[1];

    if (*(int *)(s3 + 0x18) != 0) {
        return;
    }
    if ((*(u32 *)(s3 + 0x2B8) & 4) != 0) {
        u8 *s0 = s3 + 0x170;
        u8 *s1 = s3 + 0x1A0;
        u8 *s2 = s3 + 0x20;
        a0 = s0;
        func_01B09E80(&a0);
        a1 = s0;
        func_01B09D88(&a1);
        a2 = s1;
        func_01B09E80(&a2);
        a3 = s1;
        func_01B09D88(&a3);
        a4 = s2;
        func_01B0B650(&a4);
        a5 = s2;
        func_01B0B5A8(&a5);
        a6 = s4[0];
        func_01B0E710(&a6);
        a7 = s4[0];
        func_01B0E6E8(&a7);
        *(int *)(s3 + 0x18) = 0x4E20;
    }
}
