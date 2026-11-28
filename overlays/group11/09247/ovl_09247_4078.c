#include "common.h"

extern u8 D_01B01FC0[];
extern void *D_006A3924;

extern void func_002DD0B0(void *, void *);
extern void func_00267658(void *, s32, s32, s32);
extern void func_00267530(void *);

typedef struct Node4078 Node4078;
struct Node4078 {
    void *vtbl;         /* 0x00 */
    Node4078 *next;     /* 0x04 */
    Node4078 *prev;     /* 0x08 */
    Node4078 *head;     /* 0x0C */
    Node4078 *tail;     /* 0x10 */
    Node4078 *parent;   /* 0x14 */
    u16 count;          /* 0x18 */
    u8 b1A;             /* 0x1A */
    u8 b1B;             /* 0x1B */
    u8 pad1C[4];        /* 0x1C */
    float v20[4];       /* 0x20 */
    float v30[4];       /* 0x30 */
    float v40[4];       /* 0x40 */
    float v50[4];       /* 0x50 */
    void *w60;          /* 0x60 */
    void *mgr;          /* 0x64 */
    u8 pad68[8];        /* 0x68 */
    u8 pobj[0x70];      /* 0x70 */
    u16 hE0;            /* 0xE0 */
    u16 hE2;            /* 0xE2 */
    u16 hE4;            /* 0xE4 */
    u16 hE6;            /* 0xE6 */
    u8 padE8[8];        /* 0xE8 */
    s32 wF0;            /* 0xF0 */
    u16 hF4;            /* 0xF4 */
    u16 hF6;            /* 0xF6 */
    u32 flags;          /* 0xF8 */
    s32 wFC;            /* 0xFC */
    s32 w100;           /* 0x100 */
    s32 w104;           /* 0x104 */
    s32 w108;           /* 0x108 */
};

typedef struct {
    u8 pad00[0x10];
    s32 *pdt;
    u8 pad14[0xC];
    u8 vecs[16][16];
} Cfg4078;

typedef struct {
    Node4078 *node;
    void *vec;
    u16 h08;
} Arg4078;

typedef struct {
    Node4078 *node;
    Node4078 *parent;
    void *w08;
    Cfg4078 *cfg;
    void *mgr;
    s32 idx;
    s32 w18;
} Arg4128;

typedef struct {
    Node4078 *node;
} Arg4240;

void func_01B04078(Arg4078 *arg) {
    Node4078 *o = arg->node;
    u16 v;

    o->v30[0] = (float)o->hE0 * (1.0f / 4096.0f);
    o->v30[1] = (float)o->hE2 * (1.0f / 4096.0f);
    o->v30[2] = (float)o->hE4 * (1.0f / 4096.0f);
    o->v30[3] = (float)o->hE6 * (1.0f / 4096.0f);
    func_002DD0B0(o->v40, arg->vec);
    *(volatile u32 *)&o->flags = o->flags | 1U;
    v = arg->h08;
    *(volatile u16 *)&o->hF4 = v;
    *(volatile u16 *)&o->hF6 = v;
}

void func_01B04120(void) {
}

void func_01B04128(Arg4128 *arg) {
    Node4078 *node = arg->node;
    Node4078 *parent = arg->parent;

    node->vtbl = D_01B01FC0;
    node->b1A = 0xFF;
    node->tail = node;
    node->head = node;
    node->parent = parent;
    node->b1B = 0;
    if (parent != 0) {
        node->next = parent;
        node->prev = parent->tail;
        if (parent->tail == parent) {
            parent->head = node;
        } else {
            parent->tail->next = node;
        }
        parent->tail = node;
        parent->count++;
    }

    *(volatile u32 *)&node->flags = 0;
    *(volatile s32 *)&node->wFC = 0;
    {
        register Cfg4078 *cfg __asm__("$6") = arg->cfg;
        register s32 idx __asm__("$2") = arg->idx;
        register s32 *pdt __asm__("$3") = cfg->pdt;
        register void *mgr __asm__("$8");
        register void *w08 __asm__("$9");
        register s32 *pdt_elem __asm__("$2");
        s32 pdt_id;
        __asm__("" : "+r"(idx) : "r"(cfg));
        __asm__("" : "+r"(arg) : "r"(pdt));
        mgr = arg->mgr;
        __asm__("" : "+r"(idx) : "r"(mgr));
        idx <<= 2;
        __asm__("" : "+r"(arg) : "r"(idx));
        w08 = *(void *volatile *)&arg->w08;
        pdt_elem = (s32 *)(idx + (u32)pdt);
        __asm__("" : "+r"(pdt_elem) : "r"(w08));
        __asm__("" : "+r"(mgr) : "r"(pdt_elem));
        *(void *volatile *)&node->mgr = mgr;
        pdt_id = *(volatile s32 *)pdt_elem;
        *(void *volatile *)&node->w60 = w08;
        D_006A3924 = mgr;
        func_00267658(node->pobj, 0x1000, pdt_id, 1);
    }
    {
        s32 idx = arg->idx;
        Cfg4078 *cfg = arg->cfg;
        func_002DD0B0(arg->node->v20, cfg->vecs[idx]);
    }
    *(volatile float *)&node->v50[3] = 4096.0f;
    *(volatile s32 *)&node->w108 = arg->w18;
    *(volatile s32 *)&node->w104 = 0;
    *(volatile s32 *)&node->wF0 = 0;
    *(volatile float *)&node->v50[0] = 4096.0f;
    *(volatile float *)&node->v50[1] = 4096.0f;
    *(volatile float *)&node->v50[2] = 4096.0f;
}

void func_01B04240(Arg4240 *arg) {
    Node4078 *o = arg->node;
    if (!(o->flags & 4)) {
        D_006A3924 = o->mgr;
        func_00267530(o->pobj);
        __asm__ volatile("");
    }
}
