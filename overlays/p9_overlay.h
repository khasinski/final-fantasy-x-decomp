#ifndef P9_OVERLAY_H
#define P9_OVERLAY_H

/* Package p9 (overlay families F8/F11/F9/F13): shared declarations. */

#include "common.h"

/* Resident sceVu0-style helpers (handwritten VU0 macro code in the main ELF). */
void func_002DCE08(float out[4], float m[4][4], float v[4]);        /* out = m * v */
void func_002DCE38(float dst[4][4], float a[4][4], float b[4][4]);  /* matrix multiply */
void func_002DD020(float dst[4], float a[4], float b[4]);           /* dst = a + b */
void func_002DD128(float m[4][4]);                                  /* unit matrix */
void func_002DD1C8(float dst[4][4], float src[4][4], float rz);     /* rotate about Z */
void func_002DD270(float dst[4][4], float src[4][4], float rx);     /* rotate about X */
void func_002DD318(float dst[4][4], float src[4][4], float ry);     /* rotate about Y */
void func_002DD968(float dst[4], float a[4], float b[4], float t);  /* a*t + b*(1-t) */
void func_002DD998(float dst[4], float src[4], float s);            /* dst.xyz = src.xyz * s */

/* Resident libm (soft-double sqrt, float atan2). */
double func_002E9290(double x);
float func_002E94A0(float y, float x);

/* Resident memset and the effect primitive submit used by the F11 motion code. */
void *func_002EF0D0(void *dst, int c, int n);
int func_002CD590(void *prim, void *ctx);

typedef struct P9Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) P9Vec;

/* Keyframe stream: header, then 8-byte entries from +0x10. */
typedef struct P9MotKey {
    s16 ofs;    /* primitive offset from the stream start */
    s16 dur;    /* frame duration (x0x200 per tick) */
    s8 flags;   /* 0x80: loop at the end */
    u8 pad[3];
} P9MotKey;

typedef struct P9MotData {
    u8 pad0[6];
    s16 count;
    u8 pad8[8];
    P9MotKey key[1];
} P9MotData;

/* Animated primitive header (shared by both F11 object kinds). */
typedef struct P9MotHead {
    P9MotData *data;
    int active;
    s16 frame;
    s16 timer;
    u8 pad[4];
} P9MotHead;

/* Global primitive context submitted to func_002CD590 (one per overlay, D_01B007A0 in file09053). */
typedef struct P9MotCtx {
    u16 pad0;
    u16 flags;
    union {
        int word;
        u8 rgba[4];
    } col;
    u8 pad8[8];
    float (*mtx)[4];
    int result;
    u8 pad18[4];
    int unk1C;
    u8 pad20[0x10];
} P9MotCtx;

/* F9 interpolator object (file09206 0x01B09D00.. family). */
typedef struct P9Track {
    P9Vec from;     /* 0x00 */
    P9Vec to;       /* 0x10 */
    float *src;     /* 0x20 key table */
    struct P9Vec *ref; /* 0x24 */
    float *arg;     /* 0x28 five Bernstein weights */
    float pos;      /* 0x2C */
    float step;     /* 0x30 */
    int total;      /* 0x34 */
    int count;      /* 0x38 */
    int type;       /* 0x3C */
} P9Track;

typedef struct P9Ramp {
    float *table;   /* 0x00 key table (type 2) */
    float a;        /* 0x04 start value / table position */
    float b;        /* 0x08 end value / position step */
    float end;      /* 0x0C final value */
    int left;       /* 0x10 ticks left */
    int len;        /* 0x14 ticks total / table length */
    int type;       /* 0x18 */
} P9Ramp;

typedef struct P9Pt {
    float x;        /* 0x00 */
    float y;        /* 0x04 */
    int a;          /* 0x08 */
    int b;          /* 0x0C */
} P9Pt;

typedef struct P9Lerp {
    u8 pad00[0x50];
    P9Vec ref1;     /* 0x50 */
    P9Vec ref0;     /* 0x60 */
    P9Track track[2]; /* 0x70 */
    P9Ramp ramp[2]; /* 0xF0 */
    P9Pt pt;        /* 0x128 */
    u8 pad138[0xC];
    u8 on;          /* 0x144 */
} P9Lerp;

#endif
