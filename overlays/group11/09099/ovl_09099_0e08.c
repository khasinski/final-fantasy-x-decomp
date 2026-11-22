#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x18];
    u8 prio;
} OvlTask9099;

typedef struct {
    u8 pad00[0x54];
    int f54;
} Sub58a0;

extern int g_498[];
extern int g_5910;
extern float g_5800[6][4];
extern float g_4b0[5][4];
extern float g_500[5][4];
extern int g_590c;
extern float g_5900;
extern int g_5914;
extern u8 g_5718[];
extern u8 g_568[];
extern Sub58a0 g_58a0;
extern u8 g_res_data[];
extern u8 g_550[];

extern int ovl_1a28(int);
extern void ovl_15b0(int, void *, int);
extern void ovl_4c00(void *, void *, void *);
extern float ovl_1488(int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void ovl_2f98(int, void *, void *);
extern void ovl_5580(void *, void *, void *, int);
extern OvlTask9099 *ovl_3b70(void (*)(void *));
extern void ovl_3d38(OvlTask9099 *);
extern void ovl_2910(int, int);
extern void ovl_3bf0(void *);
extern void ovl_2790(int, int, float);
extern float ovl_4ab0(float, void *, int, int);
extern float ovl_4fd8(float, void *, int, int);
extern int ovl_1360(int);
extern void func_001B6F58(int, float);
extern void ovl_16e0(int, void *);

void ovl_09099_1060(void *task);

void ovl_09099_0e08(void)
{
    float mat[16];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    int found = 0;
    int id;
    int *p;
    float *dst;
    float *src;
    int i;
    OvlTask9099 *t;

    id = ovl_1a28(0);
    for (p = g_498; *p != -1; p++) {
        if (*p == id) {
            found = 1;
            break;
        }
    }
    g_5910 = found;

    ovl_15b0(-1, v60, 0);
    ovl_15b0(0, v40, 0);
    ovl_4c00(v70, v40, v60);
    if (found == 1) {
        v70[1] = ovl_1488(0);
    }
    func_002DD128(mat);
    func_002DD318(mat, mat, v70[1]);

    MMI_COPY_LQ_A3(v50, v40);
    MMI_COPY_SQ_A3(v50);
    dst = g_5800[0];
    MMI_COPY_LQ_A3(dst, v40);
    MMI_COPY_SQ_A3(dst);
    dst[3] = ovl_1488(0);

    src = (found == 0) ? g_4b0[0] : g_500[0];
    for (i = 0; i < 5; i++, src += 4) {
        dst += 4;
        func_002DCE08(v80, mat, src);
        VU0_LQC2(1, 0, v40);
        VU0_LQC2(2, 0, v80);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, dst);
        ovl_4c00(v70, v50, dst);
        dst[3] = v70[1];
        MMI_COPY_LQ_A3(v50, dst);
        MMI_COPY_SQ_A3(v50);
    }

    g_5900 = 0.0f;
    g_590c = 60;
    ovl_2f98(0, g_5718, g_568);
    ovl_5580(&g_58a0, g_res_data, g_550, 1);
    g_58a0.f54 = 0;

    t = ovl_3b70(ovl_09099_1060);
    t->prio = 1;
    ovl_3d38(t);
}

void ovl_09099_1060(void *task)
{
    float pos[4];
    float t;

    if (--g_590c == 0) {
        ovl_2910(-5, 0);
        g_5914 = 1;
        ovl_3bf0(task);
        return;
    }

    if (g_590c == 10) {
        ovl_2790(0, 10, 0.0f);
    }

    t = g_5900 + 0.1f;
    g_5900 = t;
    pos[0] = ovl_4ab0(t, &g_5800[0][0], 6, 4);
    pos[1] = g_5800[0][1];
    pos[2] = ovl_4ab0(t, &g_5800[0][2], 6, 4);
    pos[3] = 1.0f;

    if (g_5910 == 0) {
        float ang = 4.712389f - ovl_4fd8(t, &g_5800[0][3], 6, 4);
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        func_001B6F58(ovl_1360(0), ang);
    }
    ovl_16e0(0, pos);
}
