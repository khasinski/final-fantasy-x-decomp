#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
} MsgBF68;

extern void *D_00303550;
extern void *D_01B004D8;
extern u8 D_01B00960[];
extern u8 D_01B00998[];

extern void func_01B0BD88(void *);
extern void func_01B16C58(void *);
extern void func_01B17060(void *);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B0D110(void *);
extern void func_01B0CF18(void *);

static inline void set_m2(MsgBF68 *p, void *p4) {
    p->p4 = p4;
}

void func_01B0BF68(u8 *s0, void *s3, void *s2, void *s4, void *s5) {
    void *a00[4];
    MsgBF68 a10;
    u8 *s1 = s0 + 0x50;

    a00[0] = s0;
    a00[1] = (void *)func_01B0BD88;
    a00[2] = s0;
    func_01B16C58(a00);

    a00[0] = D_01B00960;
    a00[1] = s0;
    func_01B17060(a00);

    {
        void *v0 = func_002B49A0(D_01B004D8, 2, 2);
        MsgBF68 *p = &a10;
        a10.p0 = s1;
        *(volatile void **)&p->p4 = D_01B00998;
        a10.p8 = s3;
        a10.pC = s2;
        a10.p10 = v0;
        func_01B0D110(p);
    }

    {
        void **p = a00;
        p[0] = s1;
        p[1] = s4;
        p[2] = s5;
        p[3] = (void *)0xF0000;
        p[4] = (void *)0xBB800;
        p[5] = (void *)2;
        p[6] = D_00303550;
        p[7] = (void *)1;
        func_01B0CF18(p);
    }

    *(void **)(s0 + 0x44) = s3;
    *(u8 *)(s0 + 0xC8) = 0x80;
    *(u8 *)(s0 + 0xC9) = 0x20;
    *(u8 *)(s0 + 0xCA) = 0x80;
    *(u8 *)(s0 + 0xCB) = 0;
    *(s32 *)(s0 + 0x30) = 0;
    *(s32 *)(s0 + 0x18) = 0;
}
