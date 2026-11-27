#include "common.h"

typedef struct {
    u8 pad00[0x18];
    float f18;
    u8 pad1C[0x24];
    float vecs[1][12];
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
} ObjF768;

typedef struct {
    ObjF768 *obj;
    float *out;
    float f08;
    int flag;
} ArgF768;

void func_01B0F768(ArgF768 *a)
{
    ObjF768 *o = a->obj;
    Sub30 *s30 = o->p30;
    int idx = (int)(a->f08 / o->p40->f20);
    if (s30 != 0) {
        int max_idx = (int)s30->f18;
        float *src;
        if (idx >= max_idx) {
            a->flag = 1;
            src = s30->vecs[max_idx];
        } else {
            a->flag = 0;
            src = s30->vecs[idx];
        }
        a->out[0] = src[0];
        a->out[1] = src[1];
        a->out[2] = src[2];
    }
}
