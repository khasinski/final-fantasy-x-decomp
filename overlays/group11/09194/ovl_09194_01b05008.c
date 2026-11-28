#include "common.h"

typedef struct {
    u8 pad0[0x20];
    float vec20[4];
} VecNode5008;

typedef struct {
    u8 pad0[0x150];
} MtxNode5008;

typedef struct {
    u8 pad0[0x100];
} DrawNode5008;

typedef struct {
    u8 pad0[0x460];
    float f460[10][4];          /* 0x460 */
    u8 pad500[0x978];
    float fE78;                 /* 0xE78 */
    u8 padE7C[0x24];
    VecNode5008 fEA0[10];       /* 0xEA0 (stride 0x30) */
    MtxNode5008 f1080[10];      /* 0x1080 (stride 0x150) */
    DrawNode5008 f1DA0[10];     /* 0x1DA0 (stride 0x100) */
    VecNode5008 f27A0[10];      /* 0x27A0 (stride 0x30) */
    u8 pad2980[0x30C];
    s32 f2C8C;                  /* 0x2C8C */
    s32 f2C90;                  /* 0x2C90 */
    s32 f2C94;                  /* 0x2C94 */
    float f2C98;                /* 0x2C98 */
    float f2C9C;                /* 0x2C9C */
} Obj5008;

typedef struct {
    void *task;
    Obj5008 *obj;
} TaskCtx5008;

extern s32 g_sym_0040;
extern void *g_sym_0668;
extern void *g_sym_0680;
extern u8 g_sym_0800[];
extern u8 g_sym_0830[];
extern u8 g_sym_0a78[];
extern u8 g_sym_0ab8[];
extern u8 g_sym_0cb0[];
extern s32 g_sym_11e0;
extern u8 g_sym_14c8[];
extern u8 g_sym_7b58[];
extern void *g_sym_7b84;

extern void func_001C5E90(void *, s32, s32);
extern float func_001ACED8(void);
extern void func_002DD0B0(void *, void *);
extern void fn_01b10348(void *);
extern void fn_01b12740(void *);
extern void fn_01b15718(void *);
extern void fn_01b14ea8(void *);
extern void fn_01b14e70(void *);
extern void fn_01b16770(void *);

#define BASE30(s, i)  ((Obj5008 *)((u32)((i) * 0x30) + (u32)(s)))
#define BASE150(s, i) ((Obj5008 *)((u32)((i) * 0x150) + (u32)(s)))
#define BASE100(s, i) ((Obj5008 *)((u32)((i) << 8) + (u32)(s)))

typedef union {
    u8 b[4];
    void *p;
} AliasP5008;

void ovl_09194_01b05008(TaskCtx5008 *s7) {
    void *msg[10];
    void *m3[1];
    Obj5008 *s6 = s7->obj;

    if (g_sym_0040 == 0) {
    if (s6->f2C94 != 0) {
        s6->fE78 -= 0.04f;
        if (s6->fE78 < 0.0f) {
            s6->fE78 = 0.0f;
        }
    }

    {
    register s32 state __asm__("$18") = s6->f2C8C;
    if (state == 1) {
        s6->f2C98 += (1.0f / 30.0f);
        if (s6->f2C98 >= s6->f2C9C) {
            if (s6->f2C94 >= 5) {
                func_001C5E90(g_sym_0680, -5, 0);
            }
            if (s6->f460[s6->f2C94][3] > 0.0f) {
                Obj5008 *b30;

                msg[0] = &BASE30(s6, s6->f2C94)->f27A0[0];
                msg[1] = g_sym_0a78;
                fn_01b10348(msg);

                func_002DD0B0(BASE30(s6, s6->f2C94)->f27A0[0].vec20, s6->f460[s6->f2C94]);
                BASE30(s6, s6->f2C94)->f27A0[0].vec20[3] = 1.0f;

                msg[0] = &BASE30(s6, s6->f2C94)->fEA0[0];
                msg[1] = g_sym_0a78;
                fn_01b10348(msg);

                BASE30(s6, s6->f2C94)->fEA0[0].vec20[0] = 1.0f;
                BASE30(s6, s6->f2C94)->fEA0[0].vec20[1] = 1.0f;
                BASE30(s6, s6->f2C94)->fEA0[0].vec20[2] = 1.0f;

                if (g_sym_11e0 == state) {
                    register float f __asm__("$f0") = func_001ACED8() - 1.0f;
                    register s32 idx __asm__("$3") = s6->f2C94;
                    register float c1 __asm__("$f1") = 0.4f;
                    register float c2 __asm__("$f2") = 0.2f;
                    register void *p0 __asm__("$4");
                    register void *a1 __asm__("$5");
                    register void *a2 __asm__("$6");
                    register void *a3 __asm__("$7");
                    register void *t0 __asm__("$8");
                    Obj5008 *b30_2;
                    register void **m __asm__("$2");
                    f = f * c1;
                    f = f + c2;
                    p0 = &BASE150(s6, idx)->f1080[0];
                    msg[4] = p0;
                    b30_2 = BASE30(s6, idx);
                    m = &msg[4];
                    b30_2->fEA0[0].vec20[3] = f;
                    ((AliasP5008 *)&m[1])->p = g_sym_0a78;
                    a3 = &b30_2->f27A0[0];
                    a2 = g_sym_0830;
                    ((AliasP5008 *)&m[2])->p = a2;
                    t0 = &b30_2->fEA0[0];
                    msg[7] = a3;
                    a1 = g_sym_0800;
                    m[4] = a1;
                    msg[9] = t0;
                    fn_01b12740(m);

                    {
                        s32 idx2 = s6->f2C94;
                        void *mtx = &BASE150(s6, idx2)->f1080[0];
                        msg[0] = &BASE100(s6, idx2)->f1DA0[0];
                        msg[1] = g_sym_0ab8;
                        msg[2] = mtx;
                        msg[3] = g_sym_7b84;
                        msg[4] = g_sym_7b58;
                        msg[5] = (void *)4;
                        fn_01b15718(msg);
                    }
                } else {
                    Obj5008 *b30_2;
                    float f;
                    s32 idx;

                    BASE30(s6, s6->f2C94)->f27A0[0].vec20[1] -= 1.0f;
                    f = (func_001ACED8() - 1.0f) * 0.2f + 0.1f;
                    idx = s6->f2C94;

                    b30_2 = BASE30(s6, idx);
                    msg[0] = &BASE150(s6, idx)->f1080[0];
                    b30_2->fEA0[0].vec20[3] = f;
                    msg[1] = g_sym_0a78;
                    msg[2] = g_sym_0830;
                    msg[3] = &b30_2->f27A0[0];
                    msg[4] = g_sym_0800;
                    msg[5] = &b30_2->fEA0[0];
                    fn_01b12740(msg);

                    {
                        s32 idx2 = s6->f2C94;
                        void *mtx = &BASE150(s6, idx2)->f1080[0];
                        msg[0] = &BASE100(s6, idx2)->f1DA0[0];
                        msg[1] = g_sym_0ab8;
                        msg[2] = mtx;
                        msg[3] = g_sym_7b84;
                        msg[4] = g_sym_7b58;
                        msg[5] = (void *)1;
                        fn_01b15718(msg);
                    }
                }
            }

            if (s6->f2C94 == 0) {
                msg[0] = g_sym_14c8;
                msg[1] = g_sym_0a78;
                msg[2] = g_sym_0830;
                msg[3] = g_sym_0cb0;
                msg[4] = g_sym_0668;
                msg[5] = (void *)3;
                fn_01b14ea8(msg);

                msg[0] = g_sym_14c8;
                msg[1] = 0;
                fn_01b14e70(msg);

                msg[0] = g_sym_14c8 + 0x38;
                msg[1] = g_sym_0a78;
                msg[2] = g_sym_0830;
                msg[3] = g_sym_0cb0;
                msg[4] = g_sym_0668;
                msg[5] = (void *)4;
                fn_01b14ea8(msg);

                msg[0] = g_sym_14c8 + 0x38;
                msg[1] = 0;
                fn_01b14e70(msg);
            }

            s6->f2C94++;
            if (s6->f2C94 >= 10) {
                m3[0] = s7->task;
                fn_01b16770(m3);
            }
            s6->f2C9C += 0.1f;
        }
    }
    }
    }
}
