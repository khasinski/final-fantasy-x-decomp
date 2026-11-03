#ifndef FFX_P1_OVERLAY_H
#define FFX_P1_OVERLAY_H

#include "common.h"

/* Package p1: shared effect "draw" TUs (opcode dispatcher + draw lists). Layouts are only as
   complete as the code in this package needs. */

typedef struct P1Chr P1Chr;
struct P1Model;
struct P1SlotList;

/* Packed 32-bit color; 4-byte struct copy (lw/sw). */
typedef struct P1Rgba {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} __attribute__((aligned(4))) P1Rgba;

/* Script sub-object (the effect instance). */
typedef struct P1Sub {
    u8 pad00[0x18];
    u8 chr;             /* 0x18: index into owu_chr_hd */
    u8 pad19[0x17];
    float pos[3];       /* 0x30 */
    float f3C;          /* 0x3C */
    float f40;          /* 0x40 */
    float f44;
    float f48;          /* 0x48 */
    float f4C;          /* 0x4C */
    u8 pad50[0x40];
    float rot[4];       /* 0x90 */
    u8 padA0[0x1C];
    void *work;         /* 0xBC: per-effect buffer from op_malloc */
    u8 padC0[8];
    P1Rgba color;       /* 0xC8 */
} P1Sub;

typedef struct P1Obj300 {
    u8 pad00[0x28];
    u8 *model;          /* 0x28: model data (func_01B08988 layout) */
    u8 pad2C[0x7C];
} P1Obj300;

/* Script thread running the effect. */
typedef struct P1Th {
    float m00[4][4];    /* 0x000: scale vector, then matrix */
    float m40[4][4];    /* 0x040 */
    float m80[4][4];
    float mC0[4][4];    /* 0x0C0 */
    u8 pad100[0x112];
    s16 h212;           /* 0x212 */
    u8 pad214[6];
    s16 op;             /* 0x21A: opcode word */
    u8 pad21C[2];
    s8 b21E;            /* 0x21E */
    u8 pad21F[1];
    P1Sub *sub;         /* 0x220 */
    u8 pad224[0x5C];
    float m280[4][4];   /* 0x280 */
    float m2C0[4][4];   /* 0x2C0 */
    P1Obj300 obj300;    /* 0x300 */
    void *heap;         /* 0x3A8 */
} P1Th;

typedef struct P1RingEnt {
    float x;
    float y;
    float z;
    float scale;
    s16 h10;
    s16 h12;
    s16 h14;
    s16 h16;
    P1Rgba color;
    u8 b1C;
    u8 pad1D[3];
} P1RingEnt;

typedef struct P1Ring {
    u32 count;
    u32 head;
    u8 pad08[8];
    P1RingEnt ent[1];
} P1Ring;

extern P1Chr *owu_chr_hd[];

void *op_malloc(void *heap, int size);
P1Sub *opus_no_get(P1Obj300 *obj300, P1Sub *sub, int id);
void *opus_local_get(P1Th *th, P1Sub *sub);
void opus_rt_m_chara(P1Th *th, int chr, float *pos, float *rot, float scale, int flag);
void op_unit_m(void *m);
void op_unit_m_scale2(void *m, void *scale);
void func_002B5318(void *dst, void *src, void *rot);
void func_002B56D8(void *dst, void *a, void *b);   /* matrix multiply */
int Ch_TextureSetImageBase(P1Chr *chr, int v, int w);
int Ch_TextureSetClutBase(P1Chr *chr, int v, int w);
int Ch_TextureLoadImage(P1Chr *chr, int v);
void func_0010D4D8(P1Chr *chr, int v);
void func_002A72F8(u8 *model, P1Chr *chr, int c, u8 *dst);
void func_00117E08(int v);

/* overlay-internal (other p1 units) */
void func_01B08330(P1Ring *ring, P1Sub *sub);
void func_01B08430(void *work, P1Sub *sub, P1Th *th, int h212);
int func_01B08988(struct P1Model *model);
void func_01B08A10(void *work, u8 *model, P1Th *th);
void func_01B08E08(void *work, P1Sub *sub, P1Sub *other, P1Th *th, void *m280, void *m2C0);
void func_01B09498(struct P1SlotList *list, u32 n);
void func_01B094D8(void *work, void *other_work, P1Sub *sub, P1Sub *other, P1Th *th, void *mC0, int h212);

#endif
