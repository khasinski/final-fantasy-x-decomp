#include "common.h"

typedef struct {
    u8 pad0[0xD0];
    float pos[4];
    u8 padE0[0x50];
} OvlObj;

typedef struct {
    OvlObj obj[9];
    u8 padAB0[0x220];
    float vecCD0[4];
    u8 padCE0[0x160];
    u8 bufE40[0x84];
} OvlState;

extern u8 D_01B0A2F8;
extern OvlState *D_01B0A480;

extern void func_00173650(void *);
extern void func_01B055C8(void *);
extern void func_01B06540(void *, void *);
extern void func_01B09A40(void *, int, int, float, float);

void func_01B02BD8(void) {
    int c[4];
    OvlState *s = D_01B0A480;
    u8 *p = s->bufE40;

    func_01B09A40(p, 75, 0, 0.0f, 0.3f);
    *(float *)(p + 0x0C) = 0.0f;
    *(float *)(p + 0x1C) = 1.0f;
    func_01B06540(&D_01B0A2F8, &s->obj[8]);
    s->obj[1].pos[1] = s->vecCD0[1];
    s->obj[0].pos[1] = s->vecCD0[1];
    s->obj[7].pos[1] += 3000.0f;
    func_01B055C8(c);
    func_00173650(c);
}
