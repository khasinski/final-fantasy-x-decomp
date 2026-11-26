#include "common.h"

typedef struct {
    u8 pad00[0x58];
    void *p58;
} OvlSub;

typedef struct {
    u8 pad00[0x80];
    u32 w80;
    u32 w84;
    OvlSub *p88;
    u32 w8C;
    void *w90;
    u8 pad94[0x20];
    u16 hB4;
    u16 hB6;
} OvlObj;

typedef struct {
    OvlObj *obj;
    void *w04;
    s32 w08;
    u32 w0C;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
} Arg48E0;

typedef struct {
    OvlObj *obj;
    s32 w04;
    u32 *p08;
} Arg49A8;

extern s32 func_002A7120(void *, u32, u32);
extern void func_0010D380(void *, s32, u32);
extern s32 func_0010D3A8(void *, s32, u32);
extern void func_002A7308(void *, void *, u32, s32);
extern void func_002A72F8(void *, void *, u32, s32);

void ovl_09470_48e0(Arg48E0 *s0)
{
    OvlObj *s2 = s0->obj;
    void *s1 = s2->p88->p58;
    s32 v1 = func_002A7120(s1, s0->w14, s0->w1C);

    if (s0->w08 < v1) {
        return;
    }
    s2->w90 = s0->w04;
    s0->w08 = v1;
    func_0010D380(s1, -1, s0->w0C >> 6);
    func_0010D3A8(s1, -1, s0->w10 >> 6);
    if (s0->w1C != 0) {
        func_002A7308(s0->w04, s1, s0->w14, 0);
    } else {
        func_002A72F8(s0->w04, s1, s0->w14, 0);
    }
}

void ovl_09470_49a8(Arg49A8 *a)
{
    OvlObj *a1 = a->obj;

    a1->hB4 &= ~2;
    switch (a->w04) {
    case 0:
        a1->hB4 |= 2;
        break;
    case 2:
        a1->hB4 |= 2;
    case 1:
        a1->w80 = a->p08[0];
        a1->w84 = a->p08[1];
        break;
    }
    a1->hB6 = a->w04;
}
