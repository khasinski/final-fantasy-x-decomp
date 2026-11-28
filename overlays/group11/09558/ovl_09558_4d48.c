#include "common.h"

typedef struct {
    u8 pad00[0x18];
    s32 state;
    u8 pad1C[0x1E4];
} SubA4D48;

typedef struct {
    u8 pad00[0x18];
    s32 state;
    u8 pad1C[0x2C4];
} SubB4D48;

typedef struct {
    u8 pad00[0x18];
    s32 state;        /* 0x18 */
    s32 timer;        /* 0x1C */
    s32 count;        /* 0x20 */
    u8 pad24[0x0C];
    u8 obj30[0x150];  /* 0x30 */
    void *p180;       /* 0x180 */
    void *p184;       /* 0x184 */
    u8 pad188[0x08];
    u8 obj190[0x30];  /* 0x190 */
    u8 obj1C0[0x30];  /* 0x1C0 */
    u8 obj1F0[0xE8];  /* 0x1F0 */
    s32 w2D8;         /* 0x2D8 */
    u8 pad2DC[0x14];
    void *p2F0;       /* 0x2F0 */
    void *p2F4;       /* 0x2F4 */
    u8 pad2F8[0x08];
    SubA4D48 subA[5]; /* 0x300, size 0x200 each -> 0xD00 */
    SubB4D48 subB[5]; /* 0xD00, size 0x2E0 each */
} Work4D48;

extern u8 D_01B00940[];
extern u8 D_01B00B80[];
extern u8 D_01B00B98[];
extern u8 D_01B00BB8[];
extern u8 D_01B110D0[];
extern void *D_01B110FC;

extern void func_01B04B18(void *);
extern void func_01B0FBF0(void *);
extern void func_01B0FFF8(void *);
extern void func_01B0B2C0(void *);
extern void func_01B0CAE0(void *);
extern void func_01B0EC40(void *);

void func_01B04D48(Work4D48 *s4, void *s5, void *s8, void *s7, void *s6) {
    void *a00[4];
    struct {
        void *p0;
        void *p4;
        void *p8;
        void *pC;
        void *p10;
        void *p14;
    } a10;
    s32 i;

    a00[0] = s4;
    a00[1] = (void *)func_01B04B18;
    a00[2] = s4;
    func_01B0FBF0(a00);

    a00[0] = D_01B00B80;
    a00[1] = s4;
    func_01B0FFF8(a00);

    a00[0] = s4->obj190;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s4->obj190 + 0x20) = 0.0f;
    *(float *)(s4->obj190 + 0x24) = -4.5f;
    *(float *)(s4->obj190 + 0x28) = -3.2f;
    *(float *)(s4->obj190 + 0x2C) = 1.0f;

    a00[0] = s4->obj1C0;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s4->obj1C0 + 0x20) = 1.0f;
    *(float *)(s4->obj1C0 + 0x24) = 1.0f;
    *(float *)(s4->obj1C0 + 0x28) = 1.0f;
    *(volatile float *)(s4->obj1C0 + 0x2C) = 75.0f;

    {
        void **p = (void **)&a10;
        *(volatile void **)&p[1] = D_01B00B98;
        a10.p0 = s4->obj30;
        a10.pC = s4->obj190;
        *(volatile void **)&p[4] = D_01B00940;
        a10.p14 = s4->obj1C0;
        a10.p8 = s5;
        func_01B0CAE0(p);
    }

    {
        void **p = a00;
        p[0] = s4->obj1F0;
        p[1] = D_01B00BB8;
        p[2] = s4->obj30;
        p[3] = D_01B110FC;
        p[4] = D_01B110D0;
        p[5] = (void *)1;
        func_01B0EC40(p);
    }

    for (i = 0; i < 5; i++) {
        s4->subA[i].state = 20000;
        s4->subB[i].state = 20000;
    }

    s4->p2F4 = s6;
    s4->p2F0 = s7;
    s4->p184 = s8;
    s4->p180 = s5;
    s4->state = 0;
}
