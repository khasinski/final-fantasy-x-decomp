#include "common.h"

extern void *g_fn_8720(int);
extern void g_fn_46e0(void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);

void func_01B05DA8(void *dst)
{
    float mtx[16];
    float vec[4];
    func_002DCF48(mtx, g_fn_8720(0));
    g_fn_46e0(vec);
    func_002DCE08(dst, mtx, vec);
}
