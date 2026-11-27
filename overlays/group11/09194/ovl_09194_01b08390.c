#include "p6_overlay.h"

extern P6NodeVt g_vt_48f0;
extern u8 g_sym_0830[];
extern void g_fn_0348(void *);
extern void g_fn_0eb0(void *);
extern void g_fn_2740(void *);

extern void func_001D9F08(int);
extern int func_001CEA70(int, int, int);
extern void func_001A9DB8(int, int);

typedef struct {
    P6Node node;       /* 0x000 */
    u8 pad01C[0x14];
    u8 x30[0x150];     /* 0x030 */
    u8 x180[0x20];     /* 0x180 */
    float f1A0[4];     /* 0x1A0 */
    u8 x1B0[0x20];     /* 0x1B0 */
    float f1D0[4];     /* 0x1D0 */
    u8 x1E0[0x20];     /* 0x1E0 */
    int i200[4];       /* 0x200 */
    u8 x210[0x20];     /* 0x210 */
    float f230[4];     /* 0x230 */
    void *p240;        /* 0x240 */
    u8 pad244[0x1C];
    int w260;          /* 0x260 */
    u8 b264;           /* 0x264 */
} Obj8390;

typedef struct {
    Obj8390 *obj;
    P6Node *parent;
} Arg8390;

void func_01B08390(Arg8390 *a0)
{
    void *m0[4];
    void *m1[6];
    Obj8390 *s0;
    P6Node *v1 = &a0->obj->node;
    P6Node *p = a0->parent;

    v1->mark = 0xFF;
    v1->last = v1;
    v1->first = v1;
    v1->parent = p;
    v1->b1B = 0;
    if (p != 0) {
        v1->next = p;
        v1->prev = p->last;
        if (p->last == p) {
            p->first = v1;
        } else {
            p->last->next = v1;
        }
        p->last = v1;
        p->count++;
    }

    s0 = a0->obj;
    s0->b264 = 0;
    s0->p240 = 0;

    m0[0] = s0->x180;
    m0[1] = s0;
    g_fn_0348(m0);
    s0->f1A0[3] = 1.0f;
    s0->f1A0[0] = 0.0f;
    s0->f1A0[1] = 0.0f;
    s0->f1A0[2] = 0.0f;

    m0[0] = s0->x1B0;
    m0[1] = s0;
    g_fn_0348(m0);
    s0->f1D0[0] = 1.0f;
    s0->f1D0[1] = 1.0f;
    s0->f1D0[2] = 1.0f;
    s0->f1D0[3] = 1.0f;

    m0[0] = s0->x210;
    m0[1] = s0;
    g_fn_0348(m0);
    s0->f230[3] = 1.0f;
    s0->f230[0] = 0.0f;
    s0->f230[1] = 0.0f;
    s0->f230[2] = 0.0f;

    m0[0] = s0->x1E0;
    m0[1] = s0;
    g_fn_0eb0(m0);
    s0->i200[0] = 0;
    s0->i200[1] = 0;
    s0->i200[2] = 0;

    m1[0] = s0->x30;
    m1[1] = s0;
    m1[2] = g_sym_0830;
    m1[3] = s0->x180;
    m1[4] = s0->x1E0;
    m1[5] = s0->x1B0;
    g_fn_2740(m1);

    func_001D9F08(1);
    s0->w260 = func_001CEA70(1, 0, 7);
    func_001A9DB8(s0->w260, 0);
    func_001A9DB8(s0->w260, 1);

    a0->obj->node.vt = &g_vt_48f0;
}
