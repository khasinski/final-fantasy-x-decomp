#include "common.h"

typedef struct {
    u8 pad00[0x9F0];
    float vec9F0[4];
    u8 padA00[0x5870];
    void *task6270;
} OvlState;

extern OvlState *D_01B0A478;

extern void func_002DCE08(float *, float *, float *);
extern void func_002DCF48(float *, void *);
extern void func_01B05F20(void *);
extern void *func_01B07F68(int);

void func_01B033F0(void)
{
    OvlState *s = D_01B0A478;

    if (s->task6270 != 0) {
        func_01B05F20(s->task6270);
        s->task6270 = 0;
    }
}

void func_01B03430(float *out)
{
    float mtx[16];
    OvlState *s = D_01B0A478;

    func_002DCF48(mtx, func_01B07F68(0));
    func_002DCE08(out, mtx, s->vec9F0);
}
