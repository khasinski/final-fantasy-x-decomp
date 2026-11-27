#include "common.h"

typedef struct {
    u8 pad00[0x8C];
    float f8C;
    float f90;
    int w94;
    u8 pad98[0x08];
    u16 hA0;
    u16 hA2;
    u16 hA4;
    u16 hA6;
    u16 hA8;
    u16 hAA;
    u8 bAC;
} Obj4908;

typedef struct {
    u16 h00;
    u16 h02;
    int w04;
    u8 b08;
} Src4908;

typedef struct {
    Obj4908 *dst;
    Src4908 *src;
} Arg4908;

typedef struct {
    Obj4908 *dst;
    int w04;
    u16 h08;
} Arg4938;

void func_01B04908(Arg4908 *a)
{
    Src4908 *s = a->src;
    Obj4908 *d = a->dst;
    d->hA0 = s->h00;
    d->w94 = s->w04;
    d->hA2 = s->h02;
    d->bAC = s->b08;
}
