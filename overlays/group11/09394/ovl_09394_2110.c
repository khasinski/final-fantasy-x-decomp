#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    u8 subD0[0x60];
} Sub720_9394;

typedef struct {
    u8 pad000[0x720];
    Sub720_9394 sub720;
    Sub720_9394 sub850;
    u8 pad980[0x4];
    float f984;
    u8 pad988[0x268];
    u8 subBF0[0x40];
    u8 subC30[0x1C0];
    u8 subDF0[0x10];
    u8 subE00[0x10];
    u8 subE10[0x40];
    u8 subE50[0x10];
    u8 subE60[0x10];
    u8 subE70[0x10];
    u8 subE80[0x10];
} Obj9394_3;

extern u8 D_01B096E0[];
extern Obj9394_3 *D_01B097A8;

extern void func_01B04F98(void *, void *, int, int, int, int, float);
extern void func_01B02B18(int, int, int, void *);
extern void func_01B09330(void *, int, void *, int);
extern void func_01B09360(void *, int, void *, int);
extern void func_01B08928(void *, int, int, float, float);

void func_01B02110(void)
{
    Obj9394_3 *s1 = D_01B097A8;
    u8 *s0 = D_01B096E0;
    Sub720_9394 *s2 = &s1->sub720;

    func_01B04F98(s0, s2, 5, 0, 0, 0, 0.19f);
    func_01B02B18(-1, 0x17, 0, s2->subD0);
    s2->fC4 = s1->f984;

    s2 = &s1->sub850;
    func_01B04F98(s0, s2, 5, 0, 0, 0, 0.19f);
    func_01B02B18(-1, 0x1A, 0, s2->subD0);
    s2->fC4 = s1->f984;
}

void func_01B021E0(void)
{
    Obj9394_3 *s1 = D_01B097A8;
    u8 *s0 = s1->subC30;

    func_01B09330(s0, 0, s1->subDF0, 30);
    func_01B09330(s0, 1, s1->subE00, 30);
    func_01B09330(s0, 2, s1->subE10, 30);
    func_01B09360(s0, 0, s1->subE50, 30);
    func_01B09360(s0, 1, s1->subE60, 30);
    func_01B09360(s0, 2, s1->subE70, 30);
    func_01B09360(s0, 3, s1->subE80, 30);
    func_01B08928(s1->subBF0, 30, 0, 0.5f, 1.0f);
}
