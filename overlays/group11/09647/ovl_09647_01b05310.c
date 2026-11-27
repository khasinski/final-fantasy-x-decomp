#include "common.h"

typedef struct {
    u8 pad00[0x418];
    u8 x418[0x100];  /* 0x418 */
    float f518;      /* 0x518 */
    u8 pad51C[6];
    u16 h522;        /* 0x522 */
    u8 pad524[0x1C];
    u8 x540[0x934];  /* 0x540 */
    float fE74;      /* 0xE74 */
    u8 padE78[0x1B58];
    int rot[3];      /* 0x29D0 */
    u8 pad29DC[0x154];
    int drot[3];     /* 0x2B30 */
    u8 pad2B3C[4];
    int state;       /* 0x2B40 */
    u8 pad2B44[0x0C];
    float f2B50;     /* 0x2B50 */
} Obj5310;

typedef struct {
    void *p0;
    Obj5310 *obj;
} Arg5310;

extern int g_flag_0040;
extern int g_mode_11e0;
extern u8 g_vec_0fe0[];
extern u8 g_vec_0fd0[];
extern u8 g_vec_11d0[];

extern void func_002DD068(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void g_fn_a930(void *);
extern void g_fn_a1a8(void *);
extern void g_fn_6770(void *);

void func_01B05310(Arg5310 *a0)
{
    float v[4];
    void *m1;
    void *m2;
    void *m3;
    Obj5310 *s1;

    s1 = a0->obj;
    if (g_flag_0040 != 0) {
        return;
    }

    {
        register int t0 __asm__("$8") = s1->rot[0];
        register int v1 __asm__("$3") = s1->rot[1];
        register int v0 __asm__("$2") = s1->rot[2];
        register int a2 __asm__("$6") = s1->drot[0];
        register int a3 __asm__("$7") = s1->drot[1];
        register int t1 __asm__("$9") = s1->drot[2];
        t0 += a2;
        s1->rot[0] = t0;
        s1->rot[1] = v1 + a3;
        s1->rot[2] = v0 + t1;
    }

    func_002DD068(v, g_vec_0fe0, s1->f518);
    v[3] = 0.0f;
    if (g_mode_11e0 == 1) {
        func_002DD020(g_vec_11d0, g_vec_0fd0, v);
    } else {
        func_002DD020(g_vec_11d0, g_vec_0fd0, v);
    }

    switch (s1->state) {
    case 0:
        if (s1->f518 > 0.75f) {
            s1->fE74 -= 0.15f;
        }
        if (s1->fE74 < 0.0f) {
            s1->f2B50 = 0.0f;
            s1->state = 2;
            s1->h522 = 0;
            __asm__ volatile("");
            s1->fE74 = 0.0f;
        }
        break;
    case 2:
        s1->f2B50 += 0.033333335f;
        if (s1->f2B50 >= 2.0f) {
            u8 *s0 = s1->x540;
            m1 = s0;
            g_fn_a930(&m1);
            m2 = s0;
            g_fn_a1a8(&m2);
            m3 = s1->x418;
            g_fn_6770(&m3);
        }
        break;
    }
}
