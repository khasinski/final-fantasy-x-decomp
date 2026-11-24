#include "common.h"
#include "vu0.h"

typedef struct Ovl09607Item {
    u8 pad00[0x190];
} Ovl09607Item; /* size 0x190 */

typedef struct Ovl09607ObjC {
    int w00;            /* 0x00 */
    int w04;            /* 0x04 */
    int w08;            /* 0x08 */
    int w0C;            /* 0x0C */
    u8 pad10[0xC];
} Ovl09607ObjC;

typedef struct Ovl09607Work {
    u8 pad00[0x2B30];
    float q2B30[4];         /* 0x2B30 */
    u8 pad2B40[0x60];
    Ovl09607Item item[2];   /* 0x2BA0, 0x2D30 */
    u8 pad2EC0[0x90C];
    Ovl09607ObjC obj37CC;   /* 0x37CC */
} Ovl09607Work;

extern Ovl09607Work *D_01B0BC98;

void func_01B02338(int a0);
void func_01B025B8(void *a0, float *a1, float *a2, float a3);
void func_01B04E70(int a0, int a1, int a2, float *a3);
void *func_01B06F90(void *a0);
void func_01B07158(void *a0);
void func_01B0AB10(void *a0, int a1);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B027B8(void)
{
    float v00[4];
    float v10[4];
    Ovl09607Work *w = D_01B0BC98;
    Ovl09607ObjC *oc;

    copy_vec(v10, w->q2B30);
    v10[1] -= 30.0f;

    func_01B04E70(-1, 0x11, 0, v00);
    func_01B025B8(&w->item[0], v00, v10, 90.0f);

    func_01B04E70(-1, 0x37, 0, v00);
    func_01B025B8(&w->item[1], v00, v10, -90.0f);

    func_01B07158(func_01B06F90((void *)func_01B02338));

    oc = &w->obj37CC;
    oc->w00 = 0;
    oc->w04 = 0x3C;
    oc->w0C = 2;
    oc->w08 = 0;
    func_01B0AB10(oc, 0xE);
}
