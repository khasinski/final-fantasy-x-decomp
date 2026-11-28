#include "common.h"

extern u8 *D_01B093A8;
extern s32 D_01B007C4;

extern void func_01B03328(s32, float *, s32);
extern float func_01B03778(s32);
extern float func_002B3DB0(float);
extern float func_01B06B20(float *, void *);
extern void func_01B06978(float *, void *, float *);
extern float func_01B03200(s32);
extern s32 func_01B03D00(s32);
extern void func_01B04598(s32, void *);
extern void func_01B04390(s32, s32);
extern void func_01B04448(s32, s32);
extern u8 *func_01B058E8(void (*)(void));
extern void func_01B05AB0(void *);
extern void func_01B01F40(void);

void func_01B02240(void) {
    float v0[4];
    float v1[4];
    u8 *base = D_01B093A8;
    s32 count = D_01B007C4;
    u8 *p = base + 0x1F00;
    s32 i;
    u8 *t;

    for (i = 0; i < count; i++, p += 0xB0) {
        float h;
        float dy;
        float vel;

        func_01B03328(i, v0, 0);
        h = func_01B03778(i);
        *(float *)(p + 0x74) = v0[1];
        dy = (func_002B3DB0(5.0f) + 300.0f + (v0[1] - h)) / 499.0f;
        v0[1] = *(float *)(base + 0x1904);
        *(float *)(p + 0x9C) = func_01B06B20(v0, base + 0x1900);
        *(float *)(p + 0xA0) = 80.0f;
        func_01B06978(v1, base + 0x1900, v0);

        *(float *)(p + 0x90) = v1[1];
        *(float *)(p + 0x94) = 0.0f;
        *(float *)(p + 0x98) = -0.006283186f;
        *(float *)(p + 0x40) = 0.0f;
        *(float *)(p + 0x44) = dy * -2.0f;
        *(float *)(p + 0x48) = 0.0f;
        *(float *)(p + 0x4C) = 0.0f;
        *(float *)(p + 0x50) = 0.0f;
        *(float *)(p + 0x54) = (dy + dy) / 499.0f;
        *(float *)(p + 0x58) = 0.0f;
        *(float *)(p + 0x5C) = 0.0f;
        *(float *)(p + 0x60) = 0.0f;
        *(float *)(p + 0x64) = func_01B03200(i);
        *(float *)(p + 0x68) = 0.0f;
        *(float *)(p + 0x6C) = 0.0f;
        *(float *)(p + 0x80) = 1.0f;
        *(float *)(p + 0x84) = 1.0f;
        *(float *)(p + 0x88) = 1.0f;
        *(s32 *)(p + 0xA4) = 500;
        *(s32 *)(p + 0xA8) = 0;

        if (func_01B03D00(i) == 1) {
            func_01B04598(i, p);
            func_01B04390(i, 0);
            func_01B04448(i, 0);
        }
    }

    t = func_01B058E8(func_01B01F40);
    t[0x18] = 1;
    func_01B05AB0(t);
    *(u8 **)(base + 0x2480) = t;
}
