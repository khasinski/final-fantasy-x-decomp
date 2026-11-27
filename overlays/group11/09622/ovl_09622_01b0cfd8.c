#include "common.h"

typedef struct {
    u8 pad00[0x60];
    int f60;
    int f64;
    u8 pad68[0x3C];
    u16 fA4;
    u16 fA6;
} ObjCFD8;

typedef struct {
    ObjCFD8 *obj;
    int mode;
    int *pair;
} ArgCFD8;

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
} ObjD050;

typedef struct {
    u16 h00;
    u16 h02;
    int w04;
    u8 b08;
} SrcD050;

typedef struct {
    ObjD050 *dst;
    SrcD050 *src;
} ArgD050;

void func_01B0CFD8(ArgCFD8 *a0)
{
    ObjCFD8 *o = a0->obj;
    int mode = a0->mode;

    o->fA4 &= ~2;
    switch (mode) {
    case 0:
        o->fA4 |= 2;
        break;
    case 2:
        o->fA4 |= 2;
    case 1:
        o->f60 = a0->pair[0];
        o->f64 = a0->pair[1];
        break;
    }
    o->fA6 = a0->mode;
}

void func_01B0D050(ArgD050 *a)
{
    SrcD050 *s = a->src;
    ObjD050 *d = a->dst;
    d->hA0 = s->h00;
    d->w94 = s->w04;
    d->hA2 = s->h02;
    d->bAC = s->b08;
}
