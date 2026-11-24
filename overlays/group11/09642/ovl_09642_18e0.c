#include "common.h"

typedef struct {
    u8 pad00[0x130];
} Part18E0;

typedef struct {
    u8 pad00[0x4C0];
    Part18E0 p[3];
    u8 pad850[0x114];
    float f964;
    u8 pad968[0x3FC];
    int fD64;
} Work18E0;

extern u8 D_01B08FE0[];
extern Work18E0 *D_01B09148;

extern void func_00118098(int, int);
extern void func_01B04E68(void *, void *);

void func_01B018E0(void)
{
    Work18E0 *w = D_01B09148;
    int i;

    w->f964 -= 30.0f;
    for (i = 0; i < 3; i++) {
        func_01B04E68(D_01B08FE0, &w->p[i]);
    }
    w->fD64 = 0x14;
    func_00118098(0, 0x10000);
    func_00118098(1, 0x8000);
}
