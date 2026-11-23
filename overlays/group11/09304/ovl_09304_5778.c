/* Shared projectile update task (448 B, 8 open containers; 09304 @ 0x01B05778). */

#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0xD0];
    float posD0[4];
    u8 padE0[0x50];
    u8 b130[0x230];
    float tgt360[4];
    float vel370[4];
    void *p380;
    void (*cb384)(void *);
    void (*cb388)(void *);
    float speed38C;
    float scale390;
    int delay394;
    u32 pad398;
    u16 flags39C;
} ProjObj;

typedef struct {
    u8 pad00[0x10];
    void *fn10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *sub;
    u8 pad0C[0x08];
    ProjObj *obj;
} TaskObj;

extern void func_002DD020(float *, float *, float *);
extern void func_002DD038(float *, float *, float *);
extern void func_01B040E0(void *, void *);
extern void func_01B03990(TaskObj *);
extern void func_002DD128(float *);
extern void func_01B05298(void *, float *, void *);
extern void fn_5938(void);

static inline float vu0_vec3_len(float *v)
{
    register u32 bits __asm__("$7");
    register float f __asm__("$f1");
    VU0_LQC2(1, 0, v);
    VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
    VU0_OP("vaddy.x $vf1, $vf1, $vf1y");
    VU0_OP("vaddz.x $vf1, $vf1, $vf1z");
    VU0_OP("vsqrt Q, $vf1x");
    VU0_OP("vwaitq");
    VU0_OP("vaddq.x $vf1, $vf0, Q");
    VU0_QMFC2(bits, 1);
    __asm__ volatile("mtc1 %1, %0" : "=f"(f) : "r"(bits));
    return f;
}

void ovl_09304_5778(TaskObj *t)
{
    float mat[16];
    float tmp[4];
    register ProjObj *o __asm__("$16") = t->obj;

    if (o->delay394 > 0) {
        o->delay394--;
        return;
    }

    if (o->delay394 == 0) {
        MMI_COPY_LQ_A3(tmp, o->posD0);
        MMI_COPY_SQ_A3(tmp);
    } else {
        func_002DD020(tmp, o->posD0, o->vel370);
    }

    func_002DD038(tmp, tmp, o->tgt360);
    if (vu0_vec3_len(tmp) > o->speed38C) {
        if (o->delay394 == 0) {
            o->delay394 = -1;
        } else {
            func_002DD020(o->posD0, o->posD0, o->vel370);
        }
        if (o->cb384 != 0) {
            o->cb384(o);
        }
    } else {
        MMI_COPY_LQ_A3(o->posD0, o->tgt360);
        MMI_COPY_SQ_A3(o->posD0);
        o->posD0[3] = 1.0f;
        if (o->cb388 != 0) {
            o->cb388(o);
        }
        if (!(o->flags39C & 2)) {
            func_01B040E0(o->p380, o);
        }
        if (o->flags39C & 1) {
            t->sub->fn10 = (void *)fn_5938;
        } else {
            o->flags39C |= 0x8000;
            func_01B03990(t);
            return;
        }
    }

    if (o->flags39C & 1) {
        float s;
        func_002DD128(mat);
        s = o->scale390;
        mat[10] = s;
        mat[5] = s;
        mat[0] = s;
        func_01B05298(o->b130, mat, o->posD0);
    }
}
