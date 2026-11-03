#ifndef FFX_P3_OVERLAY_H
#define FFX_P3_OVERLAY_H

/* Package p3: F1 shared effect-draw library (opus / rcefChrDraw users) linked into ~131
 * battle-effect overlays. Types here are provisional and private to the package. */

#include "common.h"
#include "ffx/types.h"   /* ScriptSub */

/* Draw request at +0x100 of a ScriptThread-shaped block (rcefChrDraw / op1_md_draw). */
typedef struct P3Req {
    int w00;            /* 0x00 */
    int w04;            /* 0x04 */
    s16 h08;            /* 0x08 */
    s16 h0A;            /* 0x0A */
    int w0C;            /* 0x0C */
    union {
        u64 d;
        struct {
            int x, y;   /* 16.16 */
        } s;
    } ofs;              /* 0x10 */
    union {
        u32 w;
        u8 b[4];
    } rgba;             /* 0x18: ScriptSub.wC8 colour, b[3] = alpha */
    int w1C;            /* 0x1C */
    void *p20;          /* 0x20 */
    u8 pad24[8];        /* 0x24 */
    void *p2C;          /* 0x2C */
    u8 pad30[4];        /* 0x30 */
    int w34;            /* 0x34 */
    u64 d38;            /* 0x38 */
    int w40;            /* 0x40 */
    int w44;            /* 0x44 */
    u8 pad48[4];        /* 0x48 */
    u8 b4C;             /* 0x4C */
    u8 b4D;             /* 0x4D */
    u8 pad4E[2];        /* 0x4E */
    union {
        struct {
            s16 x0, y0, x1, y1;
        } s;
        u32 w[2];
    } rect;             /* 0x50 */
} P3Req;

/* Embedded object at ScriptThread+0x300 (opus_no_get / rcefChrDraw argument). */
typedef struct P3Obj300 {
    u8 pad00[0x28];
    int *md;            /* 0x28: model data, word 0 = draw flags */
    u8 pad2C[0x28];
    int w54;            /* 0x54: op1_md_draw result */
    u8 pad58[8];
} P3Obj300;

/* Generated grid mesh (func_01B05870): 32x16 textured quads over 33x17 vertices. */
typedef struct P3MeshPrim {
    u8 b0;
    s8 type;            /* 6 = quad list, -1 = end */
    u16 n;
    u8 pad4[4];
    u64 tag;            /* GIF tag */
} P3MeshPrim;

typedef struct P3MeshQuad {
    u32 col[4];         /* 0x00 */
    s16 vi[4];          /* 0x10 */
    s16 uv[4][2];       /* 0x18 */
} P3MeshQuad;

typedef struct P3Mesh {
    int w00;            /* 0x00 */
    int ofs_prim;       /* 0x04 */
    int ofs_vtx;        /* 0x08 */
    int w0C;            /* 0x0C */
    u16 nquad;          /* 0x10 */
    s16 h12;            /* 0x12 */
    s16 h14;            /* 0x14 */
    s16 h16;            /* 0x16 */
    u8 pad18[8];
    P3MeshPrim prim;    /* 0x20 */
    P3MeshQuad quad[16 * 32];   /* 0x30 */
    u8 pad5030[0x10];
    s16 vtx[17 * 33 * 3];       /* 0x5040 */
} P3Mesh;

/* ScriptThread (include/ffx/types.h) with the draw request at 0x100 spelled out. */
typedef struct P3Thread {
    float m00[4][4];    /* 0x000 */
    u8 pad40[0x40];     /* 0x040 */
    float m80[4][4];    /* 0x080 */
    float mC0[4][4];    /* 0x0C0 */
    P3Req req;          /* 0x100 */
    u8 pad158[0xC2];    /* 0x158 */
    u16 flags;          /* 0x21A */
    u8 pad21C[2];       /* 0x21C */
    s8 b21E;            /* 0x21E */
    u8 pad21F[1];       /* 0x21F */
    ScriptSub *sub;     /* 0x220 */
    u8 pad224[0x9C];    /* 0x224 */
    float m2C0[4][4];   /* 0x2C0 */
    P3Obj300 obj300;    /* 0x300 */
    int res[4];         /* 0x360 */
} P3Thread;

/* Bone/part list returned by rcefChrDraw: count at 0x04, 16-byte entries from 0x10. */
typedef struct P3PartEnt {
    int id;             /* 0x0 */
    void *mtx;          /* 0x4 */
    u8 pad8[8];
} P3PartEnt;

typedef struct P3PartList {
    u8 pad00[4];
    u16 n;              /* 0x04 */
    u8 pad06[0xA];
    P3PartEnt ent[1];   /* 0x10 */
} P3PartList;

/* Fade-out slot pool (func_01B06FD0 size, func_01B07018 init, func_01B07490 tick). */
typedef struct P3FadeEnt {
    u8 pad00[0xC];
    s16 slot;           /* 0x0C: index into P3FadePool.map, < 0 = free */
    u8 age;             /* 0x0E */
    u8 pad0F[0x4F];
    s16 alpha;          /* 0x5E */
} P3FadeEnt;

typedef struct P3FadePool {
    u16 n;              /* 0x00 */
    s16 h02;            /* 0x02 */
    s16 nmap;           /* 0x04 */
    u8 pad06[6];
    s16 *map;           /* 0x0C */
    u8 x10[0x10];       /* 0x10 */
    u8 x20[0x10];       /* 0x20 */
    P3FadeEnt ent[1];   /* 0x30 */
} P3FadePool;

/* Screen-edge particle field (func_01B026F8 init, func_01B02978 packet build). */
typedef struct P3EdgePart {
    float x;            /* 0x00 */
    float y;            /* 0x04 */
    int w08;            /* 0x08 */
    u8 pad0C[4];
    float x1;           /* 0x10 */
    float y1;           /* 0x14 */
    int w18;            /* 0x18 */
    u8 pad1C[4];
    u32 col0;           /* 0x20 */
    u32 col1;           /* 0x24 */
    u8 pad28[8];
    float dx;           /* 0x30 */
    float dy;           /* 0x34 */
    float u;            /* 0x38 */
    float v;            /* 0x3C */
    int w40;            /* 0x40 */
    int w44;            /* 0x44 */
    float t0;           /* 0x48: fade-in of the first vertex */
    float dt0;          /* 0x4C */
    float t1;           /* 0x50 */
    float dt1;          /* 0x54 */
} P3EdgePart;

typedef struct P3Edge {
    int w00;
    u8 pad04[0x1C];
    P3EdgePart part[0x740];     /* 0x20 */
} P3Edge;

void func_002B3DF8(float a);
int func_002B7E18(void *res);
void func_002B7EA0(void *res, void *a1, void *a2, void *a3);
void *func_002B3888(int size);          /* scratch alloc */
void func_002B39C0(int size);           /* scratch free */
void func_002B0178(P3Req *req, void *w, void *a2, void *a3, int a4);
void func_002B0400(P3Req *req, void *w, void *a2, void *a3, void *a4);
void func_002B56D8(void *dst, void *a, void *b);   /* matrix multiply */
void op_m_copy(void *dst, void *src);
int op1_md_draw(void *md, P3Req *req);

ScriptSub *opus_no_get(void *obj300, ScriptSub *sub, int id);
void *opus_local_get(P3Thread *th, ScriptSub *sub);
void opus_rt_m_chara(void *dst, int b18, float *v, float *pos, int b21E, float scale);
P3PartList *rcefChrDraw(P3Req *req, P3Thread *th, void *obj300, ScriptSub *sub, int a4);
void func_002B0DC8(P3Req *req, P3Thread *th, void *obj300, ScriptSub *sub, s16 *pc);
void func_002A4318(int res, int id, void *out);
void func_002B7CE8(P3PartList *l, P3Req *req, void *mtx, int a3, int a4, void *a5, void *a6, float scale);

/* F1-internal */
void func_01B03A70(P3Obj300 *obj, ScriptSub *sub, ScriptSub *o, int *buf, s16 *pc, void *mtx, void *m0, void *m1);

#endif /* FFX_P3_OVERLAY_H */
