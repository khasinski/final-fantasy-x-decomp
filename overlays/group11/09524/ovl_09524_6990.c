/* 09524 light init (420 B, shared by 9524, 9392, 9394, 9397, 9517). */

#include "vu0.h"

typedef struct {
    float v00[4];
    float v10[4];
    float v20[4];
    s32 timer;
    s32 duration;
    u8 pad38[0x8];
} LightSlot;

typedef struct {
    LightSlot dir[3];
    LightSlot col[4];
    float raw1C0[3][4];
    float raw1F0[3][4];
    float raw220[4][4];
    void *task;
} LightMgr;

typedef struct {
    u8 pad00[0x14];
    void *w14;
    u8 b18;
} OvlTaskObj;

extern void Sg_LightGetDir(s32, float *);
extern void Sg_LightGetColor(s32, float *);
extern void ovl_46c0(float *, float *, float *);
extern OvlTaskObj *ovl_3630(void *);
extern void ovl_37f8(OvlTaskObj *);
extern void ovl_6c30(void);

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void ovl_09524_6990(LightMgr *m)
{
    float v0[4];
    float v10[4];
    s32 i;
    LightSlot *dir;
    LightSlot *col;
    OvlTaskObj *t;

    for (i = 0; i < 3; i++) {
        Sg_LightGetDir(i, m->raw1F0[i]);
        Sg_LightGetColor(i, m->raw220[i]);
    }
    Sg_LightGetColor(i, m->raw220[i]);

    v0[0] = 0.0f;
    v0[3] = 1.0f;
    v0[1] = 0.0f;
    v0[2] = 0.0f;

    dir = m->dir;
    col = m->col;
    for (i = 0; i < 3; i++, col++) {
        ovl_46c0(v10, m->raw1F0[i], v0);
        v10[2] = 0.0f;
        v10[3] = 0.0f;
        copy_vec4_a3(dir->v00, v10);
        copy_vec4_a3(dir->v10, v10);
        copy_vec4_a3(dir->v20, v10);
        copy_vec4_a3(m->raw1C0[i], v10);
        dir->timer = 0;
        dir->duration = 1;
        dir++;

        {
            register float *r220 __asm__("$3") = m->raw220[i];
            __asm__("" : "+r"(r220));
            copy_vec4_a3(col->v00, r220);
        }
        copy_vec4_a3(col->v20, col->v00);
        col->timer = 0;
        col->duration = 1;
    }

    copy_vec4_a3(col->v00, m->raw220[i]);
    {
        register float *v20 __asm__("$3") = col->v20;
        __asm__("" : "+r"(v20));
        copy_vec4_a3(v20, col->v00);
    }
    col->timer = 0;
    col->duration = 1;

    t = ovl_3630((void *)ovl_6c30);
    t->b18 = 1;
    t->w14 = m;
    ovl_37f8(t);
    m->task = t;
}
