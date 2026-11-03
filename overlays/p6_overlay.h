#ifndef FFX_P6_OVERLAY_H
#define FFX_P6_OVERLAY_H

/* Package P6: shared battle-camera/effect library TUs found in ~116 group 0x11 containers
 * (families F2, F7, F14 of docs/overlay-families.tsv). Symbols are named by their address
 * in the reference container file09047. */

#include "common.h"

/* resident (SCES_504.90) */
int func_001B4E18(int id);              /* DEBT(TYPE): u8 id in include/ffx/funcs.h; callers pass it unextended */
int MsGetChrFly(int id);                /* DEBT(TYPE): s8 return in include/ffx/funcs.h */
int MsGetEff2Chr(int id);               /* DEBT(TYPE): u8 x / u8 return in include/ffx/funcs.h */
u8 *MsGetTargetList(int id, int *n);
void MsGetChrBtlPos(int id, float *v);
float MsGetChrGround(int id);
int Sg_GetCurExecFrames(void);
void func_001A9EE0(void *m);
void func_001AACA0(void *m);
void func_002DCE38(void *a, void *b, void *c);
void func_002DD0C0(void *src, void *dst);

extern int D_006A3BC4;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];

/* F2/F7: an -O0 compiled scene-node library (frame pointer s8, every local in the frame).
 * Children of a node form a circular doubly linked list whose sentinel is the parent itself. */
struct P6Node;

typedef struct P6NodeVt {
    void (*fn[16])();
} P6NodeVt;

typedef struct P6Node {
    P6NodeVt *vt;           /* 0x00 */
    struct P6Node *next;    /* 0x04 sibling (parent = end) */
    struct P6Node *prev;    /* 0x08 */
    struct P6Node *first;   /* 0x0C first child (self when empty) */
    struct P6Node *last;    /* 0x10 last child (self when empty) */
    struct P6Node *parent;  /* 0x14 */
    u16 count;              /* 0x18 number of children */
    u8 mark;                /* 0x1A visit mark */
    u8 b1B;                 /* 0x1B */
} P6Node;

typedef struct P6AttachArg {
    P6Node *node;
    P6Node *parent;
} P6AttachArg;

/* message sent down the node tree through vt->fn[7] */
typedef struct P6Iter {
    P6Node *cur;            /* 0x00 */
    u8 done;                /* 0x04 */
    u8 mark;                /* 0x05 */
    u8 pad06[10];
} P6Iter;

typedef struct P6Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) P6Vec;

typedef struct P6IVec {
    int x, y, z, w;
} __attribute__((aligned(16))) P6IVec;

/* 0x30-byte transform component nodes, see func_01B02980 */
typedef struct P6Node30 {
    P6Node node;            /* 0x00 */
    u8 pad1C[4];
    P6Vec v;                /* 0x20 position / scale (w = uniform scale factor) */
} P6Node30;

typedef struct P6RotNode30 {
    P6Node node;            /* 0x00 */
    u8 pad1C[4];
    P6IVec v;               /* 0x20 rotation angles, 0x10000 = full turn */
} P6RotNode30;

struct P6Obj150;

/* 0x150-byte transform object (D_01B00690 in file09047) bound to three P6Node30 components */
typedef struct P6Obj150 {
    P6Node node;            /* 0x000 */
    u8 pad01C[4];
    P6Vec m20[4];           /* 0x020 local matrix (rotation * scale, row 3 = position) */
    P6Vec m60[4];           /* 0x060 local rotation matrix */
    P6Vec mA0[4];           /* 0x0A0 world matrix */
    P6Vec mE0[4];           /* 0x0E0 world rotation matrix */
    union {
        P6IVec rot;         /* 0x120 world rotation angles */
        struct {
            int pad[3];
            struct P6Obj150 *parent; /* 0x12C (aliases rot.w) */
        } p;
    } u120;
    P6Vec scale;            /* 0x130 world scale */
    P6Node30 *n0;           /* 0x140 position */
    P6Node30 *n2;           /* 0x144 scale */
    P6RotNode30 *n1;        /* 0x148 rotation */
    u8 order;               /* 0x14C rotation order, index into the euler-to-matrix table */
} P6Obj150;

typedef struct P6LinkArg {
    P6Obj150 *obj;
    int a;
    struct P6Obj150 *parent;
    P6Node30 *n0;
    P6RotNode30 *n1;
    P6Node30 *n2;
} P6LinkArg;

/* F2 particle (ppp) effect element */
typedef struct P6PartRes {
    u8 pad00[0x10];
    int *parts;             /* 0x10 */
    u8 pad14[0x0C];
    P6Vec pos[1];           /* 0x20 */
} P6PartRes;

typedef struct P6PartObj {
    u8 pad00[0x20];
    P6Vec pos;              /* 0x20 */
    float col[4];           /* 0x30 colour scale */
    P6Vec v40;              /* 0x40 */
    int w50;                /* 0x50 */
    int heap;               /* 0x54 */
    u8 pad58[0x08];
    u8 part[0x70];          /* 0x60 ppp part object */
    u16 col12[4];           /* 0xD0 colour scale, 4.12 fixed point */
    u8 padD8[8];
    int wE0;                /* 0xE0 */
    s16 hE4;                /* 0xE4 */
    s16 hE6;                /* 0xE6 */
    u32 flags;              /* 0xE8 */
    int wait;               /* 0xEC */
    u8 padF0[4];
    int wF4;                /* 0xF4 */
} P6PartObj;

typedef struct P6PartArg {
    P6PartObj *obj;
    int val;                /* 0x04 */
    int w08;
    P6PartRes *res;
    int w10;
    int idx;
} P6PartArg;

/* F2 task ring */
typedef struct P6Link {
    P6NodeVt *vt;           /* 0x00 */
    struct P6Link *next;    /* 0x04 */
    struct P6Link *prev;    /* 0x08 */
} P6Link;

typedef struct P6Task {
    P6NodeVt *vt;           /* 0x00 */
    P6Link ring;            /* 0x04 */
    u32 flags;              /* 0x10 bit0: ring empty */
} P6Task;

typedef struct P6TaskArg {
    P6Task *task;
    P6Link *link;
} P6TaskArg;

/* F2 task object: a ring node with a callback */
typedef struct P6TaskObj {
    P6NodeVt *vt;           /* 0x00 */
    struct P6TaskObj *next; /* 0x04 */
    struct P6TaskObj *prev; /* 0x08 */
    u32 flags;              /* 0x0C */
    void (*func)();         /* 0x10 */
    int arg;                /* 0x14 */
} P6TaskObj;

typedef struct P6TaskMsg {
    P6TaskObj *obj;
    int res;
} P6TaskMsg;

/* F2 positional sound emitter */
typedef struct P6SeObj {
    P6Node node;            /* 0x00 */
    P6Obj150 *frame;        /* 0x1C */
    P6Node30 *pos;          /* 0x20 */
    int se;                 /* 0x24 */
    int w28;                /* 0x28 */
    int flags;              /* 0x2C bit0: start pending, bit1: non-positional */
    int delay;              /* 0x30 */
    int vol;                /* 0x34 */
} P6SeObj;

/* resident vector / matrix helpers */
void func_002DCE08(void *dst, void *m, void *v);
void func_002DD050(void *dst, void *a, void *b);
void func_002DD068(void *dst, void *src, float s);
void func_002DD0B0(void *dst, void *src);

#endif
