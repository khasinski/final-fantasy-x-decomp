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
void ovl_09468_2bd8(MsgSet *m) {
    Ovl9468Node *o = m->obj;
    if (!(o->flags & 4)) {
        D_006A3924 = o->mgr;
        func_00267530(o->pobj);
        /* DEBT(ORDER): prevent sibling-call tail optimization on func_00267530 */
        __asm__ volatile("");
    }
}