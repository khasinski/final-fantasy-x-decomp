/* Shared projectile fade-out task (132 B, 8 open containers; 09304 @ 0x01B05938). */

#include "common.h"

typedef struct {
    u8 pad00[0x130];
    u8 b130[0x228];
    int alpha358;
    u32 pad35C;
    u8 b360[0x30];
    float scale390;
    u8 pad394[0x08];
    u16 flags39C;
} ProjObj;

typedef struct {
    u8 pad00[0x14];
    ProjObj *obj;
} TaskObj;

extern void func_002DD128(float *);
extern void func_01B05298(void *, float *, void *);
extern void func_01B03990(TaskObj *);

void ovl_09304_5938(TaskObj *t)
{
    float mat[16];
    ProjObj *o = t->obj;

    if (o->alpha358 > 0) {
        float s;
        o->alpha358 = (int)((float)o->alpha358 * 0.5f);
        func_002DD128(mat);
        s = o->scale390;
        mat[10] = s;
        mat[5] = s;
        mat[0] = s;
        func_01B05298(o->b130, mat, o->b360);
    } else {
        o->flags39C |= 0x8000;
        func_01B03990(t);
    }
}
