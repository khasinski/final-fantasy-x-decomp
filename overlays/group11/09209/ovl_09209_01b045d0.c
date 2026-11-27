#include "common.h"

typedef struct {
    u8 pad00[0x9F0];
    float vec9F0[4];
    u8 padA00[0x5870];
    void *task6270;
} OvlState;

extern OvlState *D_01B0BD58;

extern void func_002DCE08(float *, float *, float *);
extern void func_002DCF48(float *, void *);
extern void func_01B07368(void *);
extern void *func_01B093B0(int);

void func_01B045D0(void)
{
    OvlState *s = D_01B0BD58;

    if (s->task6270 != 0) {
        func_01B07368(s->task6270);
        s->task6270 = 0;
    }
}

void func_01B04610(float *out)
{
    float mtx[16];
    OvlState *s = D_01B0BD58;

    func_002DCF48(mtx, func_01B093B0(0));
    func_002DCE08(out, mtx, s->vec9F0);
}
