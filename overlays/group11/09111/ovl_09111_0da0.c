#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x18];
    u8 prio;
} OvlTask9111;

typedef struct {
    u8 pad00[0x54];
    int f54;
} Sub5770;

extern float g_56d0[6][4];
extern float g_4a0[5][4];
extern int g_57dc;
extern float g_57d0;
extern int g_57e0;
extern u8 g_55e8[];
extern u8 g_508[];
extern Sub5770 g_5770;
extern u8 g_res_data[];
extern u8 g_4f0[];

extern void ovl_1480(int, void *, int);
extern void ovl_4ad0(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern float ovl_1358(int);
extern void func_002DCE08(void *, void *, void *);
extern void ovl_2e68(int, void *, void *);
extern void ovl_5450(void *, void *, void *, int);
extern OvlTask9111 *ovl_3a40(void (*)(void *));
extern void ovl_3c08(OvlTask9111 *);
extern void ovl_27e0(int, int);
extern void ovl_3ac0(void *);
extern void ovl_2660(int, int, float);
extern float ovl_4980(float, void *, int, int);
extern float ovl_4ea8(float, void *, int, int);
extern int ovl_1230(int);
extern void func_001B6F58(int, float);
extern void ovl_15b0(int, void *);

void ovl_09111_0f40(void *task);

void ovl_09111_0da0(void)
{
    float mat[16];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    float *dst;
    register float *p70 __asm__("$21");
    int i;
    OvlTask9111 *t;

    ovl_1480(-1, v60, 0);
    ovl_1480(0, v40, 0);
    p70 = v70;
    ovl_4ad0(p70, v40, v60);
    func_002DD128(mat);
    func_002DD318(mat, mat, v70[1]);

    MMI_COPY_LQ_A3(v50, v40);
    MMI_COPY_SQ_A3(v50);
    dst = g_56d0[0];
    MMI_COPY_LQ_A3(dst, v40);
    MMI_COPY_SQ_A3(dst);
    dst[3] = ovl_1358(0);

    for (i = 0; i < 5; i++) {
        dst += 4;
        func_002DCE08(v80, mat, g_4a0[i]);
        VU0_LQC2(1, 0, v40);
        VU0_LQC2(2, 0, v80);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, dst);
        ovl_4ad0(p70, v50, dst);
        dst[3] = v70[1];
        MMI_COPY_LQ_A3(v50, dst);
        MMI_COPY_SQ_A3(v50);
    }

    g_57dc = 60;
    g_57d0 = 0.0f;
    ovl_2e68(0, g_55e8, g_508);
    ovl_5450(&g_5770, g_res_data, g_4f0, 1);
    g_5770.f54 = 0;

    t = ovl_3a40(ovl_09111_0f40);
    t->prio = 1;
    ovl_3c08(t);
}

void ovl_09111_0f40(void *task)
{
    float pos[4];
    float t;
    float ang;

    if (--g_57dc == 0) {
        ovl_27e0(-5, 0);
        g_57e0 = 1;
        ovl_3ac0(task);
        return;
    }

    if (g_57dc == 10) {
        ovl_2660(0, 10, 0.0f);
    }

    t = g_57d0 + 0.1f;
    g_57d0 = t;
    pos[0] = ovl_4980(t, &g_56d0[0][0], 6, 4);
    pos[1] = g_56d0[0][1];
    pos[2] = ovl_4980(t, &g_56d0[0][2], 6, 4);
    pos[3] = 1.0f;

    ang = 4.712389f - ovl_4ea8(t, &g_56d0[0][3], 6, 4);
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }

    func_001B6F58(ovl_1230(0), ang);
    ovl_15b0(0, pos);
}
