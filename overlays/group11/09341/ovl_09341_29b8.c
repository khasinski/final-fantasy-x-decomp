#include "common.h"

typedef struct {
    u8 pad00[0xA4];
    float fA4;
    float fA8;
    u32 wAC;
    u16 hB0;
    u16 hB2;
    u16 hB4;
    u16 hB6;
    u16 hB8;
    u16 hBA;
    u8 bBC;
} OvlObj;

typedef struct {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 b08;
} Sub29B8;

typedef struct {
    OvlObj *obj;
    Sub29B8 *sub;
} Arg29B8;

typedef struct {
    OvlObj *obj;
    s32 w04;
    u16 h08;
} Arg29E8;

typedef struct {
    OvlObj *obj;
} Arg2A28;

void ovl_09341_29b8(Arg29B8 *a)
{
    Sub29B8 *a1 = a->sub;
    OvlObj *a2 = a->obj;

    a2->hB0 = a1->h00;
    a2->wAC = a1->w04;
    a2->hB2 = a1->h02;
    a2->bBC = a1->b08;
}

void ovl_09341_29e8(Arg29E8 *a)
{
    register OvlObj *v1 __asm__("$3") = a->obj;
    register float d __asm__("$f1") = (float)a->w04;
    register float f0 __asm__("$f0");
    register u16 v0 __asm__("$2");
    u16 h08;

    __asm__ __volatile__("" : "+r"(v1), "+f"(d));
    f0 = 1.0f;
    v1->fA4 = f0;
    f0 = f0 / d;
    v0 = v1->hB4 | 8;
    __asm__ __volatile__("" : "+r"(v0));
    h08 = a->h08;
    v1->hB4 = v0;
    v1->hB8 = h08;
    v1->fA8 = f0;
}

void ovl_09341_2a28(Arg2A28 *a)
{
    a->obj->hB4 |= 1;
}
