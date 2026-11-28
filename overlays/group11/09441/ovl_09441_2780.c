#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B093A8;
extern s32 D_01B007C4;
extern u8 D_01B092E0[];
extern u8 D_01B10250[];
extern u8 D_01B00598[];
extern s32 D_01B093BC;

extern void func_01B05968(void *);
extern void func_01B03328(s32, void *, s32);
extern float func_002B3DB0(float);
extern void func_01B04B18(s32, void *, void *);
extern s32 func_002EFD78(void);
extern s32 func_01B03D00(s32);
extern void func_01B05C48(void *, void *, float, s32, s32, s32, void *);
extern s32 func_01B030D8(s32);
extern void func_01B053D0(void *, void *, void *);
extern void func_01B08DB8(void *, s32);
extern void func_01B04390(s32, s32);
extern u8 *func_01B058E8(void (*)(void));
extern void func_01B05AB0(void *);
extern void func_01B09098(void *, s32, s32, float, float);
extern void func_01B02750(void);
extern void func_01B02738(void);
extern void func_01B02460(void);

void func_01B02780(void) {
    float v[4];
    u8 *base = D_01B093A8;
    u8 *p4 = base + 0x1B00;
    u8 *p2 = base + 0x1F00;
    s32 count;
    s32 i;
    u8 *t;

    func_01B05968(*(void **)(base + 0x2480));
    count = D_01B007C4;

    for (i = 0; i < count; i++, p2 += 0xB0) {
        s32 rnd;
        u8 *p1;
        func_01B03328(i, v, 3);
        *(float *)(p2 + 0x70) = v[0];
        *(float *)(p2 + 0x74) -= 200.0f;
        *(float *)(p2 + 0x78) = v[2];
        *(float *)(p2 + 0x60) = func_002B3DB0(3.1415927f);
        *(float *)(p2 + 0x64) = func_002B3DB0(3.1415927f);
        *(s32 *)(p2 + 0x68) = 0;
        *(float *)(p2 + 0x80) = 1.0f;
        *(float *)(p2 + 0x84) = 1.0f;
        *(float *)(p2 + 0x88) = 1.0f;
        func_01B04B18(i, p2, p2 + 0x60);

        *(float *)(p2 + 0x30) = *(float *)(p2 + 0x70);
        *(float *)(p2 + 0x34) = *(float *)(p2 + 0x74);
        *(float *)(p2 + 0x38) = *(float *)(p2 + 0x78);
        *(float *)(p2 + 0x9C) = 0.0f;
        *(float *)(p2 + 0xA0) = 0.0f;
        *(float *)(p2 + 0x40) = 0.0f;
        *(float *)(p2 + 0x44) = -((*(float *)(p2 + 0x74) - v[1]) / 30.0f);
        *(float *)(p2 + 0x48) = 0.0f;
        *(float *)(p2 + 0x4C) = 0.0f;
        *(float *)(p2 + 0x50) = 0.0f;
        *(float *)(p2 + 0x54) = 0.0f;
        *(float *)(p2 + 0x58) = 0.0f;
        *(float *)(p2 + 0x5C) = 0.0f;

        rnd = func_002EFD78() % 11;
        *(s32 *)(p2 + 0xA4) = 30;
        *(s32 *)(p2 + 0xA8) = rnd + 20;

        if (func_01B03D00(i) == 1) {
            u8 *p0;
            s32 flag;
            p1 = base + (i * 0x130 + 0xF70);

            func_01B05C48(D_01B092E0, p1, 0.3f, 2, rnd + 48, 0, (void *)func_01B02750);
            {
                register u8 *d __asm__("$3") = p1 + 0xD0;
                MMI_COPY_LQ_A3(d, v);
                MMI_COPY_SQ_A3(d);
            }
            *(float *)(p1 + 0xD4) -= 1.0f;
            *(float *)(p1 + 0xC4) = *(float *)(base + 0x2488);
            *(s32 *)(p1 + 0x120) = func_01B030D8(i);

            p0 = base + ((i << 6) + 0x1D00);
            func_01B053D0(p0, D_01B10250, D_01B00598);
            flag = D_01B093BC;
            *(void **)(p1 + 0x110) = p0;

            if (flag != 0) {
                p1 = base + (i * 0x130 + 0x5F0);
                func_01B05C48(D_01B092E0, p1, 0.3f, 4, 20, 0, 0);
                *(s32 *)(p1 + 0x120) = i;
                *(volatile float *)(p1 + 0xC4) = *(float *)(base + 0x2488);
                *(void (*volatile *)(void))(p1 + 0x104) = func_01B02738;
            }

            func_01B08DB8(p4, 15);
            *(float *)(p4 + 0x04) = 2.0f;
            *(float *)(p4 + 0x08) = 1.0f;
            *(s32 *)(p4 + 0x0C) = 0;
            *(float *)(p4 + 0x10) = 2.0f;
            *(float *)(p4 + 0x14) = 1.0f;
            *(s32 *)(p4 + 0x18) = 0;
            *(s32 *)(p4 + 0x24) = rnd + 50;
            *(u16 *)(p4 + 0x2C) |= 3;
            p4 += 0x30;
            func_01B04390(i, -1);
        } else {
            p1 = base + (i * 0x130 + 0x5F0);
            if (D_01B093BC != 0) {
                func_01B05C48(D_01B092E0, p1, 0.3f, 4, 0, 20, (void *)func_01B02750);
            } else {
                func_01B05C48(D_01B092E0, p1, 0.0f, 4, 0, 20, (void *)func_01B02750);
            }
            func_01B03328(i, p1 + 0xD0, 4);
            *(float *)(p1 + 0xC4) = *(float *)(base + 0x2488);
            *(s32 *)(p1 + 0x120) = func_01B030D8(i);
        }
    }

    t = func_01B058E8(func_01B02460);
    t[0x18] = 1;
    func_01B05AB0(t);
    *(u8 **)(base + 0x2480) = t;
    func_01B09098(base + 0x1CC0, 20, 30, 0.5f, 1.0f);
}
