#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0x10];
    void **p10;
} Sub1C;

typedef struct {
    void *p00;
    u8 pad04[0x4];
    void *p08;
} List20;

typedef struct {
    u8 pad00[0x1C];
    Sub1C *p1C;
    List20 sub20;
} Mgr20B8;

typedef struct Obj20B8 {
    u8 pad00[0x50];
    float v50[4];
    s32 w60;
    s32 w64;
    s32 w68;
    s32 w6C;
    float f70;
    float f74;
    float f78;
    float f7C;
    float v80[4];
    float v90[4];
    float vA0[4];
    u8 padB0[0x10];
    float vC0[4];
    float vD0[4];
    float vE0[4];
    float vF0[4];
    void (*fn100)(struct Obj20B8 *);
    void (*fn104)(struct Obj20B8 *);
    void *p108;
    void *p10C;
    void *p110;
    s32 w114;
    s32 w118;
    s32 w11C;
    u8 pad120[0x4];
    u16 h124;
    u8 b126;
} Obj20B8;

extern Mgr20B8 *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern u8 D_006A3BB0[];
extern void *D_006A3BC8;
extern void *D_006A3BCC;

extern void func_00267658(void *, s32, void *, s32);
extern void func_01B02038(void *, s32, s32, s32);
extern void func_01B026C0(void *, void *);
extern void func_01B017F8(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DD270(void *, void *, float);
extern void func_002DD318(void *, void *, float);
extern void func_002DD3C0(void *, void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_002DD948(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern s32 func_00267FA0(void *, s32);
extern void func_00267530(void *);
extern void func_01B02820(void *, void *);
extern void func_00268610(void *, void *, s32);
extern s32 func_01B01B20(void *);
extern Obj20B8 *func_01B029B0(void *);
extern void func_01B02950(void *);

Obj20B8 *ovl_09088_20b8(Mgr20B8 *mgr, Obj20B8 *obj, s32 idx, s32 a3, s32 t0, s32 t1, float scale)
{
    obj->v50[0] = obj->v50[1] = obj->v50[2] = 0.0f;
    obj->v50[3] = 1.0f;
    obj->f70 = obj->f74 = obj->f78 = obj->f7C = scale;
    D_006A3924 = mgr;
    obj->w60 = obj->w64 = obj->w68 = obj->w6C = 0;
    func_00267658(obj, 0x1000, mgr->p1C->p10[idx], 1);
    func_01B02038(obj, a3, t0, t1);
    func_01B026C0(&mgr->sub20, obj);
    return obj;
}

s32 ovl_09088_2198(Mgr20B8 *mgr, void *a1)
{
    float m00[4][4];
    float m40[4][4];
    float v80[4];
    s32 cnt;
    List20 *list = &mgr->sub20;
    Obj20B8 *e;
    register float (*m40p)[4] __asm__("$22");

    list->p08 = list->p00;
    cnt = 0;
    D_006A3924 = mgr;
    if (a1 != 0) {
        D_006A3BCC = a1;
    }
    func_01B017F8(D_006A3A70, D_006A3970);
    __asm__ volatile("" : "=r"(m40p));
    m40p = m40;
    func_002DD128(m40p);

    while ((e = func_01B029B0(list)) != 0) {
        if (e->h124 & 0x8000) {
            if (!(e->h124 & 1)) {
                if (e->w114 == 0) {
                    if (e->fn104 != 0) {
                        e->fn104(e);
                    }
                    if (e->fn100 != 0 && e->w11C == e->w118) {
                        e->fn100(e);
                    }
                    switch (e->b126) {
                    case 1:
                        func_002DD3C0(m00, m40p, e->vC0);
                        break;
                    case 2:
                        MMI_COPY_LQ_A3(e->v80, e->v80);
                        MMI_COPY_SQ_A3(m00[0]);
                        {
                            register u_long128 q __asm__("$7");
                            __asm__("lq %0, 0(%2)" : "=&r"(q) : "r"(m00[1]), "r"(e->v90));
                            __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(m00[1]) : "memory");
                        }
                        copy_vec(m00[2], e->vA0);
                        copy_vec(m00[3], m40[3]);
                        break;
                    default:
                        func_002DD1C8(m00, m40p, e->vC0[2]);
                        func_002DD270(m00, m00, e->vC0[0]);
                        func_002DD318(m00, m00, e->vC0[1]);
                        break;
                    }
                    func_002DCE08(v80, m00, e->vE0);
                    func_002DD998(m00[0], m00[0], e->f70);
                    {
                        register float *p1 __asm__("$19") = m00[1];
                        func_002DD998(p1, p1, e->f74);
                    }
                    {
                        register float *p2 __asm__("$17") = m00[2];
                        func_002DD998(p2, p2, e->f78);
                    }
                    m00[3][0] = e->vD0[0] + v80[0];
                    m00[3][1] = e->vD0[1] + v80[1];
                    m00[3][2] = e->vD0[2] + v80[2];
                    func_002DD948(e->v50, m00[3]);
                    func_002DD0C0(D_006A3930, m00);
                    if (e->p108 != 0) {
                        D_006A3BC8 = e->p108;
                    }
                    copy_vec(D_006A3BB0, e->vF0);
                    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                    D_006A3924 = mgr;
                    if (func_00267FA0(e, 0x30) == 1) {
                        D_006A3924 = mgr;
                        func_00267530(e);
                        e->h124 &= 0x7FFF;
                        func_01B02820(list, e);
                    } else if (e->p10C != 0) {
                        func_00268610(e, e->p10C, 0);
                    }
                    if (e->p110 != 0) {
                        if (func_01B01B20(e->p110) == 1) {
                            e->p110 = 0;
                        }
                    }
                    e->w118++;
                } else {
                    e->w114--;
                }
            }
            cnt++;
        }
        if (e == func_01B029B0(list)) {
            func_01B02950(list);
        }
    }

    return cnt == 0;
}
