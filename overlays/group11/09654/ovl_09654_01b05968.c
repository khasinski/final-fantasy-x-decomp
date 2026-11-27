#include "common.h"

typedef struct {
    u8 pad00[0x40];  /* 0x00 */
    u8 m40[0x40];    /* 0x40 */
    int w80;         /* 0x80 */
    int w84;         /* 0x84 */
    int w88;         /* 0x88 */
    float f8C;       /* 0x8C */
    int w90;         /* 0x90 */
    float f94;       /* 0x94 */
    float f98;       /* 0x98 */
    float f9C;       /* 0x9C */
    int wA0;         /* 0xA0 */
    int wA4;         /* 0xA4 */
    void *pA8;       /* 0xA8 */
    int wAC;         /* 0xAC */
    float fB0;       /* 0xB0 */
    int wB4;         /* 0xB4 */
    int wB8;         /* 0xB8 */
    int wBC;         /* 0xBC */
    int wC0;         /* 0xC0 */
    int wC4;         /* 0xC4 */
    u8 padC8[8];
} Item8138;          /* 0xD0 */

typedef struct {
    u8 pad00[0xCD0];
    Item8138 items[1]; /* 0xCD0 */
    u8 padDA0[0xD64];
    void *p1B04;     /* 0x1B04 */
    u8 pad1B08[0x1C];
    int w1B24;       /* 0x1B24 */
} State8138;

extern State8138 *g_state_2f0;
extern void *g_sym_2f4;
extern void *g_sym_2f8;
extern int g_cnt_ee8[2];
extern u8 g_sym_7cd8[];

extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DD0C0(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);

extern void g_fn_8d70(int, void *, int);
extern void g_fn_9798(int, int);
extern float g_fn_8c48(int);
extern void g_fn_c3c0(void *, void *, void *);
extern void *g_fn_8bb8(int);
extern void *g_fn_13e8(void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void g_fn_92c0(int, void *);
extern void g_fn_9ad8(int, int);
extern void g_fn_9948(int);
extern void g_fn_9a38(int, int);
extern void *g_fn_b330(void *);
extern void g_fn_b4f8(void *);

void func_01B05968(void)
{
    float m10[16];
    float m50[16];
    float m90[16];
    float mD0[16];
    float v110[4];
    float v120[4];
    float v130[4];
    void *p140;
    State8138 *st;
    register Item8138 *it __asm__("$16");
    void *s6;
    int i;

    p140 = g_sym_2f4;
    st = g_state_2f0;
    s6 = g_sym_2f8;
    it = st->items;
    func_002DD128(m10);
    g_fn_8d70(-1, v110, 0);

    for (i = 1; i < g_cnt_ee8[1]; i++, it++) {
        int mode;
        g_fn_9798(i, 0);
        mode = st->w1B24;
        it->wC4 = mode;
        if (mode == 1) {
            register float *p_m50 __asm__("$17") = m50;
            register float *p_m90 __asm__("$18");
            float ang;
            float r;

            func_002DD318(p_m50, m10, g_fn_8c48(i));
            func_002DD0C0(mD0, p_m50);
            g_fn_8d70(i, v120, 0);
            g_fn_c3c0(v130, v110, v120);
            ang = -v130[1] + 3.1415927f;
            p_m90 = m90;
            if (ang > 3.1415927f) {
                ang -= 6.2831855f;
            } else if (ang < -3.1415927f) {
                ang += 6.2831855f;
            }
            func_002DD318(p_m90, m10, ang);
            func_002DCE38(p_m50, p_m90, p_m50);
            it->pA8 = p140;
            s6 = g_fn_13e8(g_fn_8bb8(i), p_m50, mD0, s6, &p140, &it->wA0, &it->wA4, &it->wAC, &it->fB0);
            g_fn_92c0(i, it);
            g_fn_92c0(i, it->m40);
            v120[0] = 0.0f;
            v120[1] = it->fB0;
            v120[2] = 0.0f;
            v120[3] = 1.0f;
            func_002DCE08(v120, it, v120);
            it->fB0 = v120[1];
            it->w80 = 0;
            it->w84 = 0;
            it->w88 = 0;
            it->w90 = 0;
            it->f94 = func_002B3DB0(0.08f);
            it->f98 = func_002B3DB0(0.1f);
            r = func_002B3DF8(1.0f) + 2.0f;
            it->wBC = 0x14;
            it->wC0 = 0x1E;
            it->wB4 = 0x80;
            it->f9C = r;
            it->f8C = r * 0.02f;
            g_fn_9ad8(i, 0);
            g_fn_9948(i);
        } else {
            g_fn_9a38(i, 1);
        }
        it->wB8 = 0x37;
    }

    st->p1B04 = g_fn_b330(g_sym_7cd8);
    g_fn_b4f8(st->p1B04);
}
