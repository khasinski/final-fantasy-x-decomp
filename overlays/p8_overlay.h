#ifndef FFX_P8_OVERLAY_H
#define FFX_P8_OVERLAY_H

/* Package p8: shared Ch/Ms/ppp helpers linked next to ovl_09053_pool in ~215 containers. */

#include "common.h"

/* Effect task node (0x1C bytes; 0x100 of them in a pool, see the F3 init at 0x01B03C78). */
typedef struct P8Task P8Task;
typedef void (*P8TaskFn)(P8Task *t);
struct P8Task {
    P8Task *prev;      /* 0x00 */
    P8Task *next;      /* 0x04 */
    P8Task *top;       /* 0x08: top of this task's child stack (self when empty) */
    P8Task *link;      /* 0x0C: next entry down the child stack */
    P8TaskFn fn;       /* 0x10 */
    int w14;           /* 0x14 */
    u8 group;          /* 0x18 */
};

/* Pool-backed doubly linked list (ovl_09053_pool.c PoolNode/PoolList). */
typedef struct P8Node {
    struct P8Node *prev;
    struct P8Node *next;
    void *val;
} P8Node;

typedef struct P8List {
    P8Node *head;      /* 0x00 */
    P8Node *tail;      /* 0x04 */
    P8Node *cur;       /* 0x08: iteration cursor */
    int count;         /* 0x0C */
} P8List;

/* 16-byte vector; copied as one quadword (lq/sq) through .q. */
typedef union P8Vec {
    u_long128 q;
    struct {
        float x, y, z, w;
    } v;
} P8Vec;

typedef struct P8Mtx {
    P8Vec r[4];
} P8Mtx;

typedef struct P8PppCfg {
    u8 pad00[0x10];
    int *pdt;          /* 0x10 */
} P8PppCfg;

/* ppp particle manager: OefHeapMgr header + config + live object list. */
typedef struct P8PppMgr {
    u8 main[0x10];     /* 0x00 */
    u8 sub[0x10];      /* 0x10 */
    u8 *rec20;         /* 0x20: 0x20-byte records */
    void **tbl;        /* 0x24 */
    void *p28;         /* 0x28 */
    P8PppCfg *cfg;     /* 0x2C */
    P8List list;       /* 0x30 */
} P8PppMgr;

typedef struct P8PObj P8PObj;
typedef void (*P8PObjFn)(P8PObj *o);

/* ppp part object driven by the F5 manager (0x01B03DA8.. in file09053). */
struct P8PObj {
    u8 pad00[0x1E];
    u16 enabled;       /* 0x1E */
    u8 pad20[0x20];
    P8Vec position;    /* 0x40 */
    int rotation[4];   /* 0x50 */
    P8Vec scale;       /* 0x60 */
    u8 pad70[0x10];    /* 0x70 */
    P8Vec mtx[3];      /* 0x80: explicit basis (mode 2) */
    u8 padB0[0x10];    /* 0xB0 */
    P8Vec rot;         /* 0xC0: euler angles */
    P8Vec trans;       /* 0xD0 */
    P8Vec offset;      /* 0xE0: transformed by the basis */
    P8Vec color;       /* 0xF0 */
    P8PObjFn on_frame; /* 0x100: called when frame == trigger */
    P8PObjFn on_tick;  /* 0x104 */
    int w108;          /* 0x108 */
    void *w10C;        /* 0x10C */
    void *w110;        /* 0x110 */
    int delay;         /* 0x114 */
    int frame;         /* 0x118 */
    int trigger;       /* 0x11C */
    int chr;           /* 0x120 */
    u16 flags;         /* 0x124: 0x8000 live, 0x4000 kill, 0x0001 paused */
    u8 mode;           /* 0x126: basis 0 euler zxy, 1 func_002DD3C0, 2 mtx */
};

extern P8PppMgr *D_006A3924;
extern P8Mtx D_006A3930;
extern P8Mtx D_006A3970;
extern P8Mtx D_006A39B0;
extern P8Mtx D_006A3A70;
extern P8Mtx D_006A3AB0;
extern P8Vec D_006A3BB0;
extern int D_006A3BC8;
extern void *D_006A3BCC;

void _pppAllFreePObject(P8PObj *o);
void _pppStartPart(P8PObj *o, int a1, int pdt, int a3);
void _pppInitData(P8PppCfg *cfg, void *data);
void pppInitEnv(P8PppMgr *mgr, P8PppCfg *cfg, void *buf, int size);
int _pppRunPart(P8PObj *o, int stride);
void func_00268610(P8PObj *o, void *a1, P8PObj *a2);
void func_002DCE08(P8Vec *out, P8Mtx *m, P8Vec *v);
void func_002DCE38(P8Mtx *dst, P8Mtx *a, P8Mtx *b);
void func_002DD0C0(P8Mtx *dst, P8Mtx *src);
void func_002DD128(P8Mtx *m);
void func_002DD1C8(P8Mtx *dst, P8Mtx *src, float a);
void func_002DD270(P8Mtx *dst, P8Mtx *src, float a);
void func_002DD318(P8Mtx *dst, P8Mtx *src, float a);
void func_002DD3C0(P8Mtx *dst, P8Mtx *src, P8Vec *rot);
void func_002DD948(P8Vec *dst, P8Vec *src);
void func_002DD998(P8Vec *out, P8Vec *v, float s);

/* ovl_09053_pool.c */
void func_01B04750(P8List *list);
int func_01B047E8(P8List *list, void *val);
int func_01B04948(P8List *list, void *val);
void func_01B04A78(P8List *list);
void *func_01B04AD8(P8List *list);

#endif /* FFX_P8_OVERLAY_H */
