#include "common.h"

typedef struct Ovl9468Node Ovl9468Node;
struct Ovl9468Node {
    void *vtbl;         /* 0x00 */
    Ovl9468Node *prev;  /* 0x04 */
    Ovl9468Node *next;  /* 0x08 */
    Ovl9468Node *tail;  /* 0x0C */
    Ovl9468Node *head;  /* 0x10 */
    Ovl9468Node *parent;/* 0x14 */
    u16 child_cnt;      /* 0x18 */
    u8 b1A;             /* 0x1A */
    u8 b1B;             /* 0x1B */
    u8 pad1C[4];        /* 0x1C */
    float pos20[4];     /* 0x20 */
    float col30[4];     /* 0x30 */
    float dst40[4];     /* 0x40 */
    void *w50;          /* 0x50 */
    void *mgr;          /* 0x54 */
    u8 pad58[8];        /* 0x58 */
    u8 pobj[0x70];      /* 0x60 */
    u16 hD0;            /* 0xD0 */
    u16 hD2;            /* 0xD2 */
    u16 hD4;            /* 0xD4 */
    u16 hD6;            /* 0xD6 */
    u8 padD8[8];        /* 0xD8 */
    int wE0;            /* 0xE0 */
    u16 hE4;            /* 0xE4 */
    u16 hE6;            /* 0xE6 */
    u32 flags;          /* 0xE8 */
    int delay;          /* 0xEC */
    void *wF0;          /* 0xF0 */
    int wF4;            /* 0xF4 */
    int wF8;            /* 0xF8 */
};

typedef struct {
    u8 pad00[0x10];
    int *pdt;
    u8 pad14[0xC];
    u8 vecs[16][16];
} Ovl9468Cfg;

typedef struct { Ovl9468Node *obj; int val; } MsgSet;
typedef struct { Ovl9468Node *obj; void *vec; u16 h08; } Msg2A18;
typedef struct { Ovl9468Node *obj; Ovl9468Node *parent; void *w08; Ovl9468Cfg *cfg; void *mgr; int idx; } Msg2AC8;
typedef struct { Ovl9468Node *obj; } MsgObj;

extern u8 g_ovl_dat_1650[];
extern void fn_ovl_2728(void);
extern void *D_006A3924;
extern void func_002DD0B0(void *, void *);
extern void func_00267658(void *, int, int, int);
extern void *func_002B2E30(void *, void *, int, int);
extern float func_00267530(void *);
extern void func_002B2F20(void *);
void ovl_09468_2ac8(Msg2AC8 *m) {
    Ovl9468Node *o = m->obj;
    Ovl9468Node *p = m->parent;
    o->vtbl = g_ovl_dat_1650;
    o->b1A = 0xFF;
    o->head = o;
    o->tail = o;
    o->parent = p;
    o->b1B = 0;
    if (p != 0) {
        o->prev = p;
        o->next = p->head;
        if (p->head == p) { p->tail = o; } else { p->head->prev = o; }
        p->head = o;
        p->child_cnt++;
    }
    /* DEBT(ORDER): volatile loads/stores and ordering barriers match _pppStartPart setup */
    *(volatile u32 *)&o->flags = 0;
    *(volatile int *)&o->delay = 0;
    {
        /* DEBT(FAKE): pin cfg/idx/pdt/mgr/w08/pdt_elem to match exact register schedule */
        register Ovl9468Cfg *cfg __asm__("$6") = m->cfg;
        register int idx __asm__("$2") = m->idx;
        register int *pdt __asm__("$3") = cfg->pdt;
        register void *mgr __asm__("$8");
        register void *w08 __asm__("$9");
        register int *pdt_elem __asm__("$2");
        int pdt_id;
        __asm__("" : "+r"(idx) : "r"(cfg));
        __asm__("" : "+r"(m) : "r"(pdt));
        mgr = m->mgr;
        __asm__("" : "+r"(idx) : "r"(mgr));
        idx <<= 2;
        __asm__("" : "+r"(m) : "r"(idx));
        w08 = *(void *volatile *)&m->w08;
        pdt_elem = (int *)(idx + (u32)pdt);
        __asm__("" : "+r"(pdt_elem) : "r"(w08));
        __asm__("" : "+r"(mgr) : "r"(pdt_elem));
        *(void *volatile *)&o->mgr = mgr;
        pdt_id = *(volatile int *)pdt_elem;
        *(void *volatile *)&o->w50 = w08;
        D_006A3924 = mgr;
        func_00267658(o->pobj, 0x1000, pdt_id, 1);
    }
    { int i2 = *(volatile int *)&m->idx; Ovl9468Node *o2 = *(Ovl9468Node *volatile *)&m->obj; Ovl9468Cfg *c2 = *(Ovl9468Cfg *volatile *)&m->cfg; int off; void *dst; __asm__("" : "+r"(i2) : "r"(c2)); off = i2 * 16 + 32; __asm__("" : "+r"(o2) : "r"(off)); dst = o2->pos20; __asm__("" : "+r"(dst) : "r"(off)); __asm__("" : "+r"(c2) : "r"(dst)); func_002DD0B0(dst, (u8 *)c2 + off); }
    o->wF8 = 0;
    o->wE0 = 0;
    o->wF0 = func_002B2E30((void *)fn_ovl_2728, o, 0, 0);
}