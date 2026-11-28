#include "common.h"

typedef struct Node8390 {
    void *vtbl;
    struct Node8390 *prev;
    struct Node8390 *next;
    struct Node8390 *tail;
    struct Node8390 *head;
    struct Node8390 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x14];
    u8 f30[0x150];
    u8 f180[0x20];
    float f1A0;
    float f1A4;
    float f1A8;
    float f1AC;
    u8 f1B0[0x20];
    float f1D0;
    float f1D4;
    float f1D8;
    float f1DC;
    u8 f1E0[0x20];
    float f200;
    float f204;
    float f208;
    u32 pad20C;
    u8 f210[0x20];
    float f230;
    float f234;
    float f238;
    float f23C;
    void *f240;
    u8 pad244[0x1C];
    void *f260;
    u8 f264;
} Node8390;

typedef struct {
    Node8390 *obj;
    Node8390 *parent;
} Arg8390;

extern u8 g_sym_0830[];
extern u8 g_vtbl_8390[];
extern void fn_01b10348(void *);
extern void fn_01b10eb0(void *);
extern void fn_01b12740(void *);
extern void fn_001d9f08(s32);
extern void *fn_001cea70(s32, s32, s32);
extern void fn_001a9db8(void *, s32);

void ovl_09194_01b08390(Arg8390 *a0) {
    void *m0[4];
    void *m1[6];
    Node8390 *n = a0->obj;
    Node8390 *p = a0->parent;
    Node8390 *s0;

    n->flag_1a = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->flag_1b = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->child_count++;
    }

    s0 = a0->obj;
    s0->f264 = 0;
    s0->f240 = 0;

    m0[0] = s0->f180;
    m0[1] = s0;
    fn_01b10348(m0);
    s0->f1AC = 1.0f;
    s0->f1A0 = 0.0f;
    s0->f1A4 = 0.0f;
    s0->f1A8 = 0.0f;

    m0[0] = s0->f1B0;
    m0[1] = s0;
    fn_01b10348(m0);
    s0->f1D0 = 1.0f;
    s0->f1D4 = 1.0f;
    s0->f1D8 = 1.0f;
    s0->f1DC = 1.0f;

    m0[0] = s0->f210;
    m0[1] = s0;
    fn_01b10348(m0);
    s0->f23C = 1.0f;
    s0->f230 = 0.0f;
    s0->f234 = 0.0f;
    s0->f238 = 0.0f;

    m0[0] = s0->f1E0;
    m0[1] = s0;
    fn_01b10eb0(m0);
    s0->f200 = 0.0f;
    s0->f204 = 0.0f;
    s0->f208 = 0.0f;

    m1[0] = s0->f30;
    m1[1] = s0;
    m1[2] = g_sym_0830;
    m1[3] = s0->f180;
    m1[4] = s0->f1E0;
    m1[5] = s0->f1B0;
    fn_01b12740(m1);

    fn_001d9f08(1);
    s0->f260 = fn_001cea70(1, 0, 7);
    fn_001a9db8(s0->f260, 0);
    fn_001a9db8(s0->f260, 1);
    a0->obj->vtbl = g_vtbl_8390;
}

void ovl_09194_01b08538(void) {
}
