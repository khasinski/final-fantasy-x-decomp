#include "common.h"

extern void *D_01B04B50;
extern s32 D_01B04B54;

extern void *func_01B01258(s32);
extern void func_002A3CA0(void *, void *, s32, s32, s32, s32);
extern void func_01B03A50(void *);

void ovl_09520_0f68(void *arg0)
{
    s32 rem;
    s32 t;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 d = 120;

    rem = --D_01B04B54;
    t = d - rem;
    a2 = (t * 768) / d;
    a3 = (t * -96) / 120;
    t0 = (t * -52) / 120;
    func_002A3CA0(func_01B01258(-1), D_01B04B50, a2, a3, t0, 0);
    if (D_01B04B54 <= 0) {
        func_01B03A50(arg0);
    }
}
