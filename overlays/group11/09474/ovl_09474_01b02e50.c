#include "common.h"

typedef struct {
    u8 pad0[0xBD0];
    float vecBD0[4][4];
    float vecC10[4][4];
    u8 padC50[0x274];
    void *fEC4;
    u8 padEC8[0x10];
    int fED8;
} OvlState;

extern OvlState *D_01B0A480;

extern void func_01B02C88(void);
extern void *func_01B05D70(void *);
extern void func_01B05DF0(void *);
extern void func_01B05F38(void *);

void func_01B02E50(void) {
    OvlState *s = D_01B0A480;
    void *h;
    s->vecBD0[3][0] = 0.0f;
    s->vecBD0[3][1] = 0.0f;
    s->vecBD0[3][2] = 0.0f;
    s->vecBD0[3][3] = 1.0f;
    s->vecC10[3][0] = 0.0f;
    s->vecC10[3][1] = 0.0f;
    s->vecC10[3][2] = 0.0f;
    s->vecC10[3][3] = 1.0f;
    s->fED8 = 100;
    h = func_01B05D70(func_01B02C88);
    func_01B05F38(h);
    s->fEC4 = h;
}

void func_01B02EC8(void) {
    OvlState *s = D_01B0A480;
    if (s->fEC4 != 0) {
        func_01B05DF0(s->fEC4);
        s->fEC4 = 0;
    }
}
