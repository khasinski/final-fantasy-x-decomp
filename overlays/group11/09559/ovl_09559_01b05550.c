#include "common.h"

typedef struct ChrEnt {
    u8 pad00[0x16];
    u16 dir16;
    u8 pad18[0x0C];
    float f24;
    float f28;
    u8 pad2C[0x04];
    float pos30[4];
    float pos40[4];
    u8 pad50[0x80];
} ChrEnt;

extern int D_01B0D294;
void func_01B05460(ChrEnt *, int, float *, u16, u16);

void func_01B05550(ChrEnt *arr, int count, float *base, u16 a3, u16 dir)
{
    int i;
    ChrEnt *p;

    if (D_01B0D294 != 0) {
        p = arr;
        for (i = 0; i < count; i++, p++) {
            if (i == 0) {
                p->pos40[0] = base[0];
                p->pos40[1] = base[1];
                p->pos40[2] = base[2];
                p->pos40[3] = 1.0f;
            } else {
                float k = (arr[0].f28 / arr[0].f24) * 0.5f;
                p->pos40[0] = base[0] + (p->pos30[0] - arr[0].pos30[0]) * k;
                p->pos40[1] = base[1] + (p->pos30[1] - arr[0].pos30[1]) * k;
                p->pos40[2] = base[2] + (p->pos30[2] - arr[0].pos30[2]) * k;
                p->pos40[3] = 1.0f;
            }
            p->dir16 = dir;
        }
    } else {
        func_01B05460(arr, count, base, a3, dir);
    }
}
