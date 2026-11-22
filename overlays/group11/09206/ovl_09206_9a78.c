#include "common.h"
#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct CamObj {
    u8 pad00[0x48];
    float f48;          /* 0x48 */
    u8 pad4C[0x4];
    u128 vec50;         /* 0x50 */
    u128 vec60;         /* 0x60 */
    u8 sub70[0x40];     /* 0x70 */
    u8 subB0[0x40];     /* 0xB0 */
    u8 subF0[0x1C];     /* 0xF0 */
    u8 sub10C[0x30];    /* 0x10C */
    float f13C;         /* 0x13C */
    s32 w140;           /* 0x140 */
    u8 b144;            /* 0x144 */
    u8 pad145;
    s8 b146;            /* 0x146 */
} CamObj;

extern void *D_01B115A4;

void func_01B0A0E0(void *a0, void *a1);
void func_01B0A638(void *a0, float *a1);
void func_01B0A7A8(void *a0, float *a1);
void func_01B0A850(CamObj *a0);
void func_002DCE08(u128 *dst, CamObj *a1, u128 *src);
void func_001A7840(void *cam, s32 a1, u128 *a2);
void func_001A8128(void *cam, float f0);
void func_001A81E8(void *cam, float f0);

void func_01B09A78(CamObj *a0)
{
    u128 v0;
    u128 v1;

    func_01B0A0E0(a0->subB0, &a0->vec60);
    func_01B0A0E0(a0->sub70, &a0->vec50);
    func_01B0A638(a0->subF0, &a0->f48);
    func_01B0A7A8(a0->sub10C, &a0->f13C);

    switch (a0->b144) {
    case 0:
        break;
    case 1:
        func_01B0A850(a0);
        break;
    }

    if (a0->w140 == 1) {
        void *cam;

        if (a0->b146 == 0) {
            MMI_COPY_LQ_A3(&v0, &a0->vec50);
            MMI_COPY_SQ_A3(&v0);
            MMI_COPY_LQ_A3(&v1, &a0->vec60);
            MMI_COPY_SQ_A3(&v1);
        } else {
            func_002DCE08(&v0, a0, &a0->vec50);
            func_002DCE08(&v1, a0, &a0->vec60);
        }

        cam = D_01B115A4;
        func_001A7840(cam, 1, &v0);
        func_001A7840(cam, 0, &v1);
        func_001A8128(cam, a0->f48);
        func_001A81E8(cam, a0->f13C);
    }
}
