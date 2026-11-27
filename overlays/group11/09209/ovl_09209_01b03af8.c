#include "common.h"

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float vecD0[4];
} Sub720;

typedef struct {
    u8 pad00[0x720];
    Sub720 sub720;
    u8 pad800[0x5A78];
    float f6278;
} OvlState;

extern u8 D_01B0BC30[];
extern OvlState *D_01B0BD58;

extern void func_01B02FF0(void *);
extern void func_01B07648(void *, void *, int, int, int, int, float);

void func_01B03AF8(void)
{
    OvlState *s = D_01B0BD58;
    Sub720 *m = &s->sub720;
    float ang;

    func_01B07648(D_01B0BC30, m, 6, 0, 0, 0, 0.015f);
    func_01B02FF0(m->vecD0);
    m->fC0 = 0.7853982f;
    ang = s->f6278 + 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    m->fC4 = ang;
    m->vecD0[1] -= 0.5f;
}
