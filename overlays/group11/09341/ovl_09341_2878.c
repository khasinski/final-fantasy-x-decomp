#include "common.h"

typedef struct {
    u8 pad00[0x94];
    float f94;
    float f98;
    float f9C;
    float fA0;
    u8 padA4[0x10];
    u16 hB4;
} OvlObj;

typedef struct {
    OvlObj *obj;
    float f04;
    float f08;
    float f0C;
    float f10;
} Arg20;

void ovl_09341_2878(Arg20 *a)
{
    OvlObj *v1 = a->obj;

    v1->f98 = a->f04;
    v1->hB4 |= 4;
    v1->f94 = a->f08;
    v1->f9C = a->f0C;
    v1->fA0 = a->f10;
}
