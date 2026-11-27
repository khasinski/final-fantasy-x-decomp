#include "common.h"

typedef struct {
    float v[3];
    u8 pad0C[0x24];
} Entry30;

typedef struct {
    u8 pad00[0x18];
    float f18;
    u8 pad1C[0x24];
    Entry30 entries[1];
} Sub30;

typedef struct {
    u8 pad00[0x20];
    float f20;
} Sub40;

typedef struct {
    u8 pad00[0x30];
    Sub30 *p30;
    u8 pad34[0x0C];
    Sub40 *p40;
} ObjD668;

typedef struct {
    ObjD668 *obj;
    float *out;
    float t;
    int clamped;
} ArgsD668;

void ovl_09622_d668(ArgsD668 *args)
{
    ObjD668 *obj = args->obj;
    int idx = (int)(args->t / obj->p40->f20);
    Sub30 *sub = obj->p30;

    if (sub != 0) {
        int maxIdx = (int)sub->f18;
        float *src;

        if (idx >= maxIdx) {
            args->clamped = 1;
            src = sub->entries[maxIdx].v;
        } else {
            args->clamped = 0;
            src = sub->entries[idx].v;
        }
        args->out[0] = src[0];
        args->out[1] = src[1];
        args->out[2] = src[2];
    }
}
