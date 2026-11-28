#include "common.h"

typedef struct {
    u8 pad[0x14];
    s32 unk14;
} S9388;

extern u8 *D_01B093A8;
extern s32 D_01B00590[];
extern S9388 D_01B09388;

extern void func_01B03328(s32, void *, s32);
extern float func_01B03200(s32);
extern s32 func_001AF358(void);
extern void func_01B03B68(void *);
extern void func_01B06978(float *, void *, void *);
extern void func_01B00C70(void *);

void func_01B01958(void) {
    float v[4];
    u8 *s = D_01B093A8;
    s32 id;
    s32 *p;
    s32 res;
    s32 idx;

    func_01B03328(-1, s + 0x18F0, 0);
    *(float *)(s + 0x2484) = func_01B03200(-1);
    id = func_001AF358();
    res = -1;
    p = D_01B00590;
    idx = 0;
    while (*p != -1) {
        if (*p == id) {
            res = idx;
            break;
        }
        p++;
        idx++;
    }
    if (res < 0) {
        func_01B03B68(s + 0x1900);
    } else {
        func_01B03328(0, s + 0x1900, 4);
    }
    *(float *)(s + 0x1904) = *(float *)(s + 0x18F4);
    func_01B06978(v, s + 0x18F0, s + 0x1900);
    {
        float y = *(volatile float *)&v[1];
        *(volatile s32 *)(s + 0x248C) = 0x10;
        *(volatile s32 *)(s + 0x2494) = -1;
        *(volatile s32 *)(s + 0x2498) = 0;
        {
            register S9388 *q __asm__("$4") = &D_01B09388;
            *(float *)(s + 0x2488) = y;
            q->unk14 = 1;
            func_01B00C70(q);
        }
    }
}
