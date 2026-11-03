#ifndef FFX_P4_OVERLAY_H
#define FFX_P4_OVERLAY_H

/* Package p4: oef polygon-shard effect library shared by ~130 group 0x11 containers
 * (TU families F6, F10, F12 in docs/overlay-families.tsv). */

#include "common.h"

/* One source triangle of a shard model (32 bytes). */
typedef struct P4SrcTri {
    u32 col[3];        /* 0x00 per-vertex RGBA */
    s16 vtx[3];        /* 0x0C indices into the s16[3] vertex table */
    s16 pad12;
    u32 uv[3];         /* 0x14 */
} P4SrcTri;

/* Shard model header; vertex table at (u8 *)hdr + vtx_ofs. */
typedef struct P4SrcModel {
    u32 w00;           /* 0x00 */
    u32 w04;
    s32 vtx_ofs;       /* 0x08 */
    u32 w0C;
    s16 count;         /* 0x10 */
    s16 h12;
    s16 h14;
    u16 h16;           /* 0x16 */
    u8 pad18[0x10];
    unsigned long long d28; /* 0x28 */
    P4SrcTri tri[1];   /* 0x30 */
} P4SrcModel;

/* One live shard (256 bytes). */
typedef struct P4Shard {
    u32 col[3];        /* 0x00 */
    u32 pad0C;
    float rel[3][4];   /* 0x10 vertices relative to pos */
    u32 uv[3];         /* 0x40 */
    u32 pad4C;
    float pos[4];      /* 0x50 */
    float vel[4];      /* 0x60 */
    float acc[4];      /* 0x70 */
    float rot[4];      /* 0x80 */
    float rvel[4];     /* 0x90 */
    float racc[4];     /* 0xA0 */
    s32 life;          /* 0xB0 */
    s32 wait;          /* 0xB4 */
    u8 padB8[8];
    float mtx[3][4];   /* 0xC0 */
    float wpos[4];     /* 0xF0 */
} P4Shard;

typedef struct P4Shards {
    u32 w00;           /* 0x00 */
    s32 count;         /* 0x04 */
    unsigned long long d08; /* 0x08 */
    u16 h10;           /* 0x10 */
    u16 mode;          /* 0x12 */
    u8 pad14[0x0C];
    P4Shard shard[1];  /* 0x20 */
} P4Shards;

/* Spawn parameters (s16 words). */
typedef struct P4Param {
    s16 h00;
    s16 h02;
    s16 scale;         /* 0x04, 1/4096 units */
    s16 vel[3];        /* 0x06 */
    s16 vel_rnd[3];    /* 0x0C */
    s16 acc[3];        /* 0x12 */
    s16 acc_rnd[3];    /* 0x18 */
    s16 rvel[3];       /* 0x1E */
    s16 rvel_rnd[3];   /* 0x24 */
    s16 racc[3];       /* 0x2A */
    s16 racc_rnd[3];   /* 0x30 */
    s16 life;          /* 0x36 */
    s16 wait;          /* 0x38 */
    s16 wait_rnd;      /* 0x3A */
} P4Param;

typedef unsigned long u_long64; /* 64-bit on ee-gcc */

/* GS SPRITE primitive in a PACKED GIF packet (80 bytes): ST, RGBAQ, XYZ2, ST, XYZ2. */
typedef struct P4Sprite {
    float st0[4];      /* 0x00 */
    s32 rgba[4];       /* 0x10 */
    s32 xyz0[4];       /* 0x20 */
    float st1[4];      /* 0x30 */
    s32 xyz1[4];       /* 0x40 */
} P4Sprite;

/* Effect parameter block (opus th->prm, offset 0x220). */
typedef struct P4Prm {
    u8 pad00[0x1E];
    u8 res_idx;        /* 0x1E */
    u8 pad1F[0x21];
    float f40;         /* 0x40 */
    u8 pad44[0x64];
    struct P4Param *param; /* 0xA8 */
    u8 padAC[0x0F];
    u8 state;          /* 0xBB */
    struct P4Shards *shards; /* 0xBC */
} P4Prm;

/* opus id list with a method table at 0x50. */
typedef struct P4List {
    u8 pad00[0x50];
    struct P4ListVt *vt; /* 0x50 */
    u8 pad54[0x0C];
} P4List;

typedef struct P4ListVt {
    u8 pad00[0x64];
    void (*draw)(P4List *list, struct P4Shards *shards, int a, int b); /* 0x64 */
} P4ListVt;

/* opus effect thread. */
typedef struct P4Thread {
    float pos[4];      /* 0x000 */
    u8 pad010[0x30];
    float mtx[4][4];   /* 0x040 */
    u8 pad080[0x194];
    s16 draw_id;       /* 0x214 */
    u8 pad216[4];
    s16 h21A;          /* 0x21A command flags */
    u8 pad21C[4];
    P4Prm *prm;        /* 0x220 */
    u8 pad224[0xDC];
    P4List draw_list;  /* 0x300 */
    void *res[0x12];   /* 0x360 */
    void *heap;        /* 0x3A8 */
} P4Thread;

/* Effect transform (pointed to by the overlay's D_01B00260.xf). */
typedef struct P4Xform {
    u8 pad00[0x40];
    float pos[4];      /* 0x40 */
    float rot[4];      /* 0x50 */
    float scale[4];    /* 0x60 */
} P4Xform;

/* Overlay-local table of shared pointers (file09044 D_01B00260; address differs per container). */
typedef struct P4Env {
    P4Xform *xf;       /* 0x00 */
    void *p04;
    float *pos;        /* 0x08 */
    void *p0C;
    void *p10;
    s32 *tex;          /* 0x14 */
    void *p18;
    void *p1C;
    float *fscale;     /* 0x20 */
} P4Env;

extern u_long128 D_006F2CE0[];  /* default GS environment (A+D register pairs) */
extern void *D_003F395C;        /* GIF DMA channel */

float func_002B3DB0(float range);
int func_002B3D10(int range);
float op_deg_get(float *v, float x0, float z0, float x1, float z1);
void *func_002B3888(int size);
void func_002B39C0(int size);
void *op_oef2_a_get(void *res, int type, int idx);
void func_002F8660(int a);
int func_002DA610(int a, int b);
void func_002DBA28(void *chan, int addr);
void *op_malloc(void *heap, int size);
void opus_draw_on(void *list, s16 id);
P4Prm *opus_no_get(void *list, P4Prm *prm, s16 id);
void op_unit_m(void *m);
void op_unit_m_scale2(void *m, float *scale);
void func_002B55F0(void *dst, void *m, float *rot, float *pos);
void func_002B5880(float *dst, void *m, float *v);
void func_002B5978(float *dst, float *src, float s);

#endif /* FFX_P4_OVERLAY_H */
