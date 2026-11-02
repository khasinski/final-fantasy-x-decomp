#ifndef FFX_W9_H

#define FFX_W9_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* DEBT(CAST): work-area element types unknown, accessed at base + slot offset + literal */
#define SLOT_WORK(type, base, ctx, i) \
    ((type *)((char *)(base) + ((ctx)->info->slot[i] + 0xA0)))

#define SLOT_FIELD(type, base, ctx, i, ofs) \
    (*(type *)((ctx)->info->slot[i] + (base) + (ofs)))

typedef struct Wk9CA8 {
    u8 pad0[0x9C];
    int w9C;
    u8 padA0[8];
    int wA8;
} Wk9CA8;

typedef struct Wkb8 {
    u8 pad0[8];
    s8 b8;
} Wkb8;

/* DEBT(NAME): work area with an embedded sub-object at +0x20 handed to func_00266EB8 */
typedef struct WkSub20 {
    u8 pad0[0x20];
    u8 sub[1];
} WkSub20;

typedef struct Wkb8Sub40 {
    u8 pad0[8];
    s8 b8;
    u8 pad9[0x37];
    u8 sub[1];
} Wkb8Sub40;

typedef struct IdTable {
    u8 pad0[0x60];
    int id[16];
} IdTable;

typedef struct Wkb2 {
    u8 pad0[2];
    u8 b2;
} Wkb2;

typedef struct WkB0 {
    u8 pad0[0x8C];
    u8 b8C;
    u8 b8D;
    u8 pad8E[0xE];
    int w9C;
    u8 padA0[8];
    int wA8;
    u8 padAC[4];
    u8 sub[0x1C];
    u16 hCC;
    u8 padCE[2];
    u8 bD0;
    u8 bD1;
} WkB0;

typedef struct QueueReq { u8 type; u8 pad1[7]; int w8; } QueueReq;

/*W9STRUCTS*/
typedef struct Wkf8fCf14f18 {
    u8 pad0[0x8];
    float f8;
    float fC;
    u8 pad10[0x4];
    float f14;
    float f18;
} Wkf8fCf14f18;

typedef struct Wkf0f4f8 {
    float f0;
    float f4;
    float f8;
} Wkf0f4f8;

typedef struct Wkq0q8q10q18w20w24w28w2C {
    s64 q0;
    s64 q8;
    s64 q10;
    s64 q18;
    int w20;
    int w24;
    int w28;
    int w2C;
} Wkq0q8q10q18w20w24w28w2C;

typedef struct Wkq0q8q10q18q20q28w1F0h1F4b1F8 {
    s64 q0;
    s64 q8;
    s64 q10;
    s64 q18;
    s64 q20;
    s64 q28;
    u8 pad30[0x1C0];
    int w1F0;
    s16 h1F4;
    s16 h1F6;
    s8 b1F8;
} Wkq0q8q10q18q20q28w1F0h1F4b1F8;

typedef struct Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4 {
    s64 q0;
    s64 q8;
    s64 q10;
    s64 q18;
    s64 q20;
    s64 q28;
    u8 pad30[0x1B0];
    float f1E0;
    float f1E4;
    float f1E8;
    int w1EC;
    s16 h1F0;
    s16 h1F2;
    s8 b1F4;
} Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4;

typedef struct Wkf0f4f8f2C {
    float f0;
    float f4;
    float f8;
    u8 padC[0x20];
    float f2C;
} Wkf0f4f8f2C;

typedef struct Wkw0w4w8 {
    int w0;
    int w4;
    int w8;
} Wkw0w4w8;

typedef struct Wkh0h2 {
    s16 h0;
    s16 h2;
} Wkh0h2;

typedef struct Wkb0b1h2h4 {
    s8 b0;
    s8 b1;
    s16 h2;
    s16 h4;
} Wkb0b1h2h4;

typedef struct Wkb0b1b2b3 {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
} Wkb0b1b2b3;

typedef struct WkwCw1C {
    u8 pad0[0xC];
    int wC;
    u8 pad10[0xC];
    int w1C;
} WkwCw1C;

typedef struct Wkh0b2 {
    s16 h0;
    u8 b2;
} Wkh0b2;

typedef struct Wkq0w8 {
    s64 q0;
    int w8;
} Wkq0w8;

typedef struct Wkb0b1h2h4b6 {
    s8 b0;
    s8 b1;
    s16 h2;
    s16 h4;
    s8 b6;
} Wkb0b1h2h4b6;

typedef struct Wkw9CwA8 {
    u8 pad0[0x9C];
    int w9C;
    u8 padA0[0x8];
    int wA8;
} Wkw9CwA8;

typedef struct Wkw0w4 {
    int w0;
    int w4;
} Wkw0w4;

typedef struct Wkw80w84w88 {
    u8 pad0[0x80];
    int w80;
    int w84;
    int w88;
} Wkw80w84w88;

typedef struct Wkw10 {
    u8 pad0[0x10];
    int w10;
} Wkw10;

typedef struct WkSubB0 {
    u8 pad0[0xB0];
    u8 sub[1];
} WkSubB0;

/*W9STRUCTSEND*/

/* DEBT(NAME): integration state and event increments inferred from the two cumulative sums. */
typedef struct ScriptAxis { float acceleration, velocity, position; } ScriptAxis;
typedef struct ScriptAxisWork { ScriptAxis axis; void *velocitySource; void *positionSource; } ScriptAxisWork;
typedef struct ScriptAxisEvent { int owner; float delta[2][3]; } ScriptAxisEvent;
typedef struct ScriptAxisPair { ScriptAxis axis[2]; } ScriptAxisPair;
typedef struct ScriptTransformWork { u8 pad0[0x10]; u_long128 input[4]; u_long128 output[4]; } ScriptTransformWork;
extern float D_006A3AF0[4][4];

#endif
