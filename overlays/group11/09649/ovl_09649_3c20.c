#include "common.h"

typedef struct {
    u8 pad00[0x2E30];
    u8 sub2E30[0x10];
} Work3C20;

extern Work3C20 *D_01B0B1F8;
extern void func_01B0A4B8(void *, int, int, float, float);
extern void *func_01B08720(int);
extern void func_01B046E0(void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);

void func_01B03C20(void)
{
    func_01B0A4B8(D_01B0B1F8->sub2E30, 30, 0, 0.5f, 1.0f);
}

void func_01B03C48(void *dst)
{
    float mtx[16];
    float vec[4];
    func_002DCF48(mtx, func_01B08720(0));
    func_01B046E0(vec);
    func_002DCE08(dst, mtx, vec);
}
