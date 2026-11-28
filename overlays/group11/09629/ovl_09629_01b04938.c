#include "common.h"

typedef struct {
    u8 pad00[0x8C];
    float fA4;
    float fA8;
    u8 pad94[0x10];
    u16 hB4;
    u16 hB6;
    u16 hB8;
} OvlObj;

typedef struct {
    OvlObj *obj;
    s32 w04;
    u16 h08;
} ArgD0B8;

void func_01B0D0B8(ArgD0B8 *a)
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
