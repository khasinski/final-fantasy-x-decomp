#include "common.h"

typedef struct {
    u8 pad00[0x58];
    void *p58;
} ChrCE90;

typedef struct {
    u32 w0;
    u32 w4;
} Sub70_CE90;

typedef struct {
    u8 pad00[0x68];
    ChrCE90 *p68;     /* 0x68 */
    u8 pad6C[0x04];   /* 0x6C */
    Sub70_CE90 *p70;  /* 0x70 */
    void *p74;        /* 0x74 */
    u8 pad78[0x04];   /* 0x78 */
    float f7C;        /* 0x7C */
    float f80;        /* 0x80 */
    float f84;        /* 0x84 */
    float f88;        /* 0x88 */
    u8 pad8C[0x18];   /* 0x8C */
    u16 fA4;          /* 0xA4 */
} NodeCE90;

typedef struct {
    NodeCE90 *node;
    float f04;
    float f08;
    float f0C;
    float f10;
} MsgCEA8;

typedef struct {
    NodeCE90 *node; /* 0x00 */
    void *p04;      /* 0x04 */
    int f08;        /* 0x08 */
    u8 pad0C[0x08]; /* 0x0C */
    int f14;        /* 0x14 */
    int f18;        /* 0x18 */
    int f1C;        /* 0x1C */
} MsgCEE0;

extern int func_002A7120(void *, int, int);
extern int func_0010D380(void *, int, int);
extern int func_0010D3A8(void *, int, int);
extern int func_002A7308(void *, void *, int, int);
extern int func_002A72F8(void *, void *, int, int);

void func_01B0CE90(NodeCE90 **a0)
{
    (*a0)->fA4 |= 0x10;
}

void func_01B0CEA8(MsgCEA8 *a0)
{
    NodeCE90 *n = a0->node;

    n->f80 = a0->f04;
    n->fA4 |= 4;
    n->f7C = a0->f08;
    n->f84 = a0->f0C;
    n->f88 = a0->f10;
}

void func_01B0CEE0(MsgCEE0 *a0)
{
    NodeCE90 *s2 = a0->node;
    void *s1 = s2->p68->p58;
    int v1 = func_002A7120(s1, a0->f14, 0);

    if (a0->f08 < v1) {
        return;
    }

    a0->f08 = v1;
    s2->p74 = a0->p04;
    func_0010D380(s1, -1, s2->p70->w0 & 0x3FFF);
    func_0010D3A8(s1, -1, (s2->p70->w4 >> 5) & 0x3FFF);
    if (a0->f1C != 0) {
        func_002A7308(a0->p04, s1, a0->f14, a0->f18);
    } else {
        func_002A72F8(a0->p04, s1, a0->f14, a0->f18);
    }
    func_0010D380(s1, -1, -1);
    func_0010D3A8(s1, -1, -1);
    __asm__("");
}
