#ifndef FFX_TYPES_H
#define FFX_TYPES_H

/* Shared structs/typedefs of the whole image. One definition per type; area-specific record types that no global or
 * prototype refers to stay in the w<N>.h of their area. Names are guesses unless a DEBT(NAME) says otherwise. */

#include "common.h"

typedef long s64; /* EE: long is 64 bit */
typedef unsigned long u64;

typedef struct Blk64 {
    u64 d[8];
} Blk64;

typedef struct Pt16 {
    u16 x, y;
} Pt16;

/* 4 floats (x y z w); used by the 0x18F000 vector helpers and the 0x2DD000 matrix code */
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct W3Whole {
    float m[4][4];
} W3Whole;

typedef struct Unk78E498 { /* DEBT(NAME): callback table and resource handles at D_0078E498 */
    int (*f00)();
    int (*f04)();
    int (*f08)();
    int (*f0C)();
    int (*f10)();
    int (*f14)();
    u8 pad18[0x10];
    int f28; /* DEBT(NAME): loaded resource handle, paired with f2C/f30. */
    int f2C;
    int f30;
    u8 pad34[0x54 - 0x34];
    int (*f54)();
    int (*f58)();
    int fd5C; /* file of the async read job (hd_file_read_th_main) */
    int (*f60)();
    u8 pad64[4];
    void (*f68)();
    u8 pad6C[0xC];
    int (*f78)();
    u8 pad7C[0xC];
    int (*f88)();
    int (*f8C)();
} Unk78E498;


/* ======== types from the 0x100000-0x127880 chr/entity accessors (w0) ======== */

/* Accessor-only object layouts, one per source chunk. Only the members touched by
 * the matched accessors are known; everything else is padding.
 * DEBT(NAME): the object is the character/entity struct of src/chr/chr.c (name guessed); member names are offset-derived (b=byte h=half w=word f=float + hex offset). */
typedef struct Chr Chr;

typedef struct ParamTbl ParamTbl;

typedef struct ChrSlot ChrSlot;

typedef struct ChrEnt ChrEnt;

/* DEBT(NAME): state snapshots/reset fields used by func_001121C8. */
typedef struct ChrUpdateLink {
    struct ChrUpdateLink *next;
    u8 pad04[2];
    s16 h06;
    s32 value08, previous0C;
    u8 pad10[4];
    s16 h14;
    u16 flags16, previous18, saved1A;
} ChrUpdateLink;


typedef struct { s64 lo, hi; } V128; /* DEBT(TYPE): 16-byte value copied as two doublewords (vector/quad) */

typedef struct { float f; u8 pad[12]; } ChrFx; /* 16-byte stride record at Chr+0x53C, only first float known */

typedef struct ChrHdr ChrHdr;

typedef struct { s32 w0; union { s32 w4; void *p4; } u4; s32 w8; u8 padC[4]; } R0Rec16; /* DEBT(NAME): 16-byte records behind Chr.p710, only +8 known */

typedef struct { float cur, dst; s32 frames; } FloatTween; /* DEBT(NAME): guessed from func_00110390 */

typedef struct GsPt {
    union {
        struct {
            s16 x;
            s16 y;
            s32 z;
        } v;
        s64 raw;
    } q;
    union {
        s64 d;
        s32 w[2];
    } id;
} Cmd16, GsPt; /* DEBT(NAME): 16-byte command record, guessed */

typedef struct ChrParam ChrParam;

struct ChrHdr {
    u8 pad00[0x4];
    u16 h04;
    u16 h06;
    u8 pad08[0x2];
    u16 h0A;
    u8 pad0C[0x4];
    s32 w10;
};

typedef struct ChrAnimEnt { u8 pad0[8]; u16 h08; u16 h0A; s32 w0C; } ChrAnimEnt; /* DEBT(NAME): 16-byte records of ChrParamSub.ents */

typedef struct ChrAnimPair { s32 a; s32 b; } ChrAnimPair; /* DEBT(NAME) */

typedef struct ChrParamSub {
    u8 pad00[4];
    u16 h04;
    u8 pad06[2];
    u16 h08;
    u8 pad0A[2];
    u16 h0C;
    u8 pad0E[2];
    u16 h10;
    u8 pad12[6];
    ChrAnimPair *pairs; /* DEBT(NAME): 8-byte records read by func_001175D8 */
    ChrAnimEnt *ents;
} ChrParamSub; /* DEBT(NAME): block behind ChrParam+0x14, only the members used so far */

struct ChrParam {
    u8 pad00[0x14];
    ChrParamSub *sub14;
    u8 pad18[4];
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    u8 pad34[0x4];
    float f38;
    u8 pad3C[0x30];
    ParamTbl * tbl6C;
    u8 pad70[0x48];
    u8 bB8[0x6C]; /* DEBT(TYPE): block handed out by func_00101B70, contents unknown */
    s32 w124;
};

struct Chr {
    u16 h00;
    s8 active;
    u8 pad03[0x1];
    s32 w04;
    u8 pad08[0x8];
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x4];
    float f20;
    float f24;
    float f28;
    u8 pad2C[0x4];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    u8 pad6C[0x4];
    float f70;
    float f74;
    float f78;
    u8 pad7C[0x4];
    s32 w80;
    float f84;
    s32 w88;
    u8 pad8C[0x1C];
    u16 hA8;
    u8 bAA;
    u8 padAB[0x15];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x44];
    s32 w110;
    float f114;
    u8 pad118[0x48];
    float f160;
    float f164;
    u8 pad168[0xC];
    float f174;
    float f178;
    float f17C;
    float f180;
    u8 pad184[0x4];
    float f188;
    s8 b18C;
    s8 b18D;
    s8 b18E;
    s8 b18F;
    s8 b190;
    s8 b191;
    s8 b192;
    s8 b193;
    s8 b194;
    u8 pad195[0x3];
    s32 w198;
    s32 w19C;
    s64 flags;
    Chr *p1A8;
    s32 w1AC;
    float v1B0[4];
    float f1C0;
    s32 w1C4;
    ChrEnt * ents;
    ChrHdr * hdr;
    ChrParam * param;
    u8 pad1D4[0xC];
    u8 u1E0[0x10]; /* DEBT(TYPE): default slot data, compared by func_00103358 */
    u8 u1F0[0x40];
    u8 u230[0x40];
    u8 pad270[0xB0];
    ChrSlot * slots;
    u8 pad324[0x4];
    FloatTween t328;
    FloatTween t334;
    FloatTween t340;
    FloatTween t34C;
    FloatTween t358;
    FloatTween t364;
    FloatTween t370;
    u8 pad37C[0x88];
    s32 w404;
    u8 pad408[0x9];
    s8 b411;
    u8 pad412[0x12];
    float f424;
    float f428;
    float f42C;
    u8 pad430[0xA0];
    union {
        struct {
            float f4D0;
            float f4D4;
        } f;
        s32 w4D0;
        Cmd16 cmd;
    } u4D0;
    s8 b4E0;
    u8 pad4E1[0xF];
    float f4F0;
    u8 pad4F4[0x4];
    float f4F8;
    float f4FC;
    float f500;
    float f504;
    u8 pad508[0x4];
    float f50C;
    float f510;
    u8 pad514[0x14];
    float f528;
    u8 pad52C[0x10];
    ChrFx fx[1];
    u8 pad54C[0x154];
    V128 v6A0;
    V128 v6B0;
    V128 v6C0;
    u8 pad6D0[0x10];
    s32 w6E0;
    s32 w6E4;
    u8 *work6E8; /* DEBT(NAME): allocation used by Ch_TextureReMapping. */
    s32 w6EC; /* DEBT(NAME): optional state copied to D_003036A8. */
    s32 w6F0;
    s16 h6F4;
    u8 pad6F6[0x2];
    s32 w6F8;
    s16 h6FC;
    u8 pad6FE[0xA];
    s32 w708;
    s32 w70C;
    R0Rec16 *p710;
    s8 b714;
    u8 pad715[0xB];
    s32 w720;
    u8 pad724[0xC];
    s16 h730;
    s16 h732;
    s16 h734;
    u8 pad736[0x2];
    s32 w738;
    s32 w73C;
    u8 pad740[0x2];
    s8 b742;
    s8 b743;
    u8 pad744[0x2];
    s16 h746;
    s16 h748;
    s8 b74A;
    u8 pad74B;
    s32 w74C;
    u8 pad750[0x4];
    s32 *p754; /* DEBT(TYPE): array of 0x28-byte records whose first word is a pointer (Ch_MotionRemappingFcurve) */
    s32 w758; /* Offset before relocation; ChrUpdateLink pointer afterwards. */
    s16 h75C;
    u8 pad75E[0xA];
    s32 w768[1];
    u8 pad76C[0x7E8 - 0x76C];
    s32 w7E8;
    u8 pad7EC[8];
    s32 w7F4;
    u8 pad7F8[0xC];
    s32 w804;
    s32 w808;
    u8 pad80C[0x4];
    float f810;
    float f814;
    float f818;
    s16 h81C;
    s16 h81E;
    u8 pad820[0x8];
    union {
        u64 flags2;
        struct {
            float f828;
            u8 pad82C[0x2];
            s16 h82E;
        } s;
    } u828;
    s32 w830;
    u8 pad834[0xC];
};

typedef struct { s8 b0; s8 kind; s16 off; } RegEntry; /* DEBT(NAME): guessed 4-byte table record, only .off known */

typedef struct { u16 h0; u8 pad2[2]; s32 w4; } ChrSlotData;

struct ChrSlot { /* size 0x140 */
    ChrSlotData *data;
    u8 pad04[0x8C];
    u8 u90[0x40];
    s32 wD0;
    s32 wD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x54];
};

struct ChrEnt { /* size 0x30 */
    ChrSlotData *data;
    s32 w04; /* DEBT(NAME): saved by func_00123878. */
    s32 w08; /* DEBT(NAME): saved by func_00123878. */
    u8 pad0C[8];
    float f14;
    s8 b18;
    u8 pad19[0x17];
};

typedef struct { s32 w0, w4, w8; } Triple; /* DEBT(NAME) */

typedef struct { u16 key; s16 val; u8 pad[12]; } ParamEntry; /* DEBT(NAME) 16-byte records */

struct ParamTbl {
    u8 pad00[0x20];
    ParamEntry *ents;
    s32 count;
};

typedef struct { s8 flag; u8 pad[15]; } Rec16; /* DEBT(NAME): 16-byte record, only the first byte known */

typedef struct Handle { /* size 0x10 */
    s32 w0;
    s8 b4;
    u8 b5;
    s8 b6;
    s8 b7;
    union {
        s32 w;
        struct {
            unsigned char st : 3;
            unsigned char rest : 5;
        } b;
    } u8;
    s32 wC;
} Handle; /* DEBT(NAME): resource handle record, guessed from func_001111xx users */

typedef struct {
    /* 0x00 */ float x, y, z;
    /* 0x0C */ u8 pad0C[4];
    /* 0x10 */ float color[3]; /* DEBT(NAME): normalized RGB from func_0010D818. */
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ float f20;
    /* 0x24 */ float f24;
    /* 0x28 */ s8 flag;
    /* 0x29 */ s8 flag2;
    /* 0x2A */ u8 pad2A[6];
} TblEntry30; /* size 0x30 */


/* ======== types from the 0x127880-0x13xxxx field-script opcode handlers (w1) ======== */

/*
 * Script-VM opcode handlers (chunks 0x127880-0x12DD80).  Every handler is
 * int/float f(Actor *a, <per-opcode state block> *op, ScriptCtx *ctx); operands
 * are popped from the script stream with AtelPopStackInteger (int) / AtelPopStackFloat (float).
 * DEBT(NAME): all type names below (Actor, ActorSlot, Effect, ScriptCtx, ...) are guesses
 * made from field usage only.
 * DEBT(TYPE): the "op" parameter type differs per opcode family, so unknown ones are void *.
 */

typedef struct ActorSlot {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 flags;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ float f08;
    /* 0x0C */ float f0C;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ float f18;
    /* 0x1C */ u8 pad1C[0xC];
    /* 0x28 */ float f28;
    /* 0x2C */ float f2C;
    /* 0x30 */ float f30;
    /* 0x34 */ u8 pad34[4];
    float f38;
    u8 pad3C[8];
    /* 0x44 */ float f44;
    /* 0x48 */ float f48;
} ActorSlot; /* size 0x4C */

typedef struct ActorSlotB {
    u8 pad0[2];
    u16 flags;
    u8 pad4[4];
    float f08, f0C;
    u8 pad10[0x10];
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    u8 pad38[0xC];
} ActorSlotB; /* size 0x44 */

/* flag word of an Actor at 0x34 (DEBT(NAME): bit meanings unknown; fields named by bit position).
   Bit-field access is what the compiler output shows: "(x & ~mask) | (v << n)" inserts. */
typedef struct ActorFlags {
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 3;
    unsigned b5 : 1;
    unsigned b6 : 7;
    unsigned f13 : 2;
    unsigned b15 : 1;
    unsigned b16 : 1;
    unsigned f17 : 2;
    unsigned b19 : 3;
    unsigned b22 : 1;
    unsigned b23 : 4;
    unsigned b27 : 1;
    unsigned b28 : 3;
    unsigned b31 : 1;
} ActorFlags;

typedef union ActorFlagWord {
    ActorFlags b;
    float f; /* DEBT(FAKE): union member only so the type-based alias analysis keeps float stores before flag updates */
    s32 w; /* whole word, for updates of bits that have no single member (bit 7 lies inside b6) */
} ActorFlagWord;

typedef union GameFlags {
    struct {
        unsigned b0 : 7;
        unsigned b7 : 1;
        unsigned b8 : 3;
        unsigned b11 : 1;
        unsigned b12 : 1;
        unsigned b13 : 3;
        unsigned b16 : 1;
        unsigned b17 : 1;
        unsigned b18 : 1;
        unsigned b19 : 7;
        unsigned b26 : 1;
        unsigned b27 : 5;
    } b;
    s32 w;
    u32 u;
    u8 byte;
} GameFlags;

typedef struct ActorHdr {
    u8 type;
    u8 pad01[0x13];
    int o14;
    u8 p18[8];
    int o20;
    int o24;
    int o28;
    int o2C;
    int o30;
} ActorHdr;

typedef struct ScrBlobQ {
    u8 p00[0x20];
    int o20;
    u8 p24[0xC];
    int o30;
} ScrBlobQ;

typedef struct Actor {
    /* 0x000 */ ActorHdr *hdr;
    /* 0x004 */ ScrBlobQ *blob;
    /* 0x008 */ u8 pad8[0x2C - 8];
    /* 0x02C */ u16 h2C;
    /* 0x02E */ u16 id;
    /* 0x030 */ u8 pad30[2];
    /* 0x032 */ u8 slotIdx;
    /* 0x033 */ u8 b33;
    /* 0x034 */ ActorFlagWord flags34;
    /* 0x038 */ s32 w38;
    /* 0x03C */ int w3C;
    /* 0x040 */ int w40;
    /* 0x044 */ int w44;
    /* 0x048 */ u8 pad48[0x90 - 0x48];
    /* 0x090 */ struct ObjNodeR *node90; /* DEBT(NAME): list passed to func_001426F0/00142218. */
    /* 0x094 */ u8 pad94[8];
    /* 0x09C */ Chr *ptr9C;
    /* 0x0A0 */ u8 padA0[4];
    /* 0x0A4 */ s32 wA4; /* DEBT(NAME): argument passed to func_00102288. */
    /* 0x0A8 */ u16 hA8;
    /* 0x0AA */ u8 stateAA;
    /* 0x0AB */ u8 flagsAB;
    /* 0x0AC */ u8 padAC[3];
    /* 0x0AF */ u8 bAF;
    /* 0x0B0 */ u8 padB0[0xBC - 0xB0];
    /* 0x0BC */ u32 wBC;
    /* 0x0C0 */ u8 idC0; /* DEBT(NAME): name guessed; func_00144158 returns &idC0 and callers pass it to MsGetChr */
    /* 0x0C1 */ u8 padC1[0x2E4 - 0xC1];
    /* 0x2E4 */ struct PoolEntQ *poolEntries;
    /* 0x2E8 */ u8 pad2E8[0x5B8 - 0x2E8];
    /* 0x5B8 */ ActorSlot slot[9]; /* DEBT(TYPE): length 9 inferred from next array at 0x864 */
    /* 0x864 */ ActorSlotB slotB[9]; /* DEBT(TYPE): length 9 guessed from the gap up to 0xAC8 */
    /* 0xAC8 */ u8 padAC8[0xAE0 - 0xAC8];
    /* 0xAE0 */ int arrAE0[4]; /* DEBT(TYPE): length guessed from next member */
    /* 0xAF0 */ int wAF0;
    /* 0xAF4 */ Chr *chrAF4; /* DEBT(TYPE): passed to the Ch_SoundSetId/Ch_EnClip family as a Chr */
    /* 0xAF8 */ Chr *chrAF8;
    /* 0xAFC */ int valueAFC[2]; /* DEBT(TYPE): indexed words, ending at hB04. */
    /* 0xB04 */ u16 hB04;
    /* 0xB06 */ u16 hB06;
    /* 0xB08 */ u32 wB08;
    /* 0xB0C */ u32 wB0C;
    /* 0xB10 */ u8 padB10[4];
    /* 0xB14 */ u16 hB14;
    /* 0xB16 */ s16 hB16;
} Actor;

typedef struct BindInfo {
    u8 pad0[2];
    u16 flags;
    u8 pad4[4];
    float offset; /* DEBT(NAME): interpretation inferred from func_001279E0. */
    float scale;
    u8 pad10[0x10];
    float f20, f24, f28, f2C, f30, f34;
    float f38;
    float f3C;
    float f40;
} BindInfo;

typedef struct ActorBind {
    u8 p00[0x10];
    u16 h10[4];
    char *p18;
    u8 b1C;
    s8 b1D;
    u8 b1E;
    u8 b1F;
    u8 pad20[8];
    int pending;
    u8 pad2C[0x10];
    u16 h3C;
    u16 h3E;
    u16 h40;
    u8 pad42[2];
    ActorSlot *slotInfo44;
    BindInfo *info;
} ActorBind;

typedef struct ActorState {
    float x, y, z;
    float f0C;
    float px, py, pz;
    float f1C;
    float f20;
    float f24;
    u16 h28;
    u8 pad2A[2];
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
} ActorState;

/* effect/particle record returned by AtelGetMesWinWork (DEBT(NAME): guess, member names too) */
typedef struct Effect {
    /* 0x00 */ s16 h00;
    /* 0x02 */ s16 h02;
    /* 0x04 */ s16 h04;
    /* 0x06 */ s16 h06;
    /* 0x08 */ int w08;
    /* 0x0C */ int w0C;
    /* 0x10 */ int w10;
    /* 0x14 */ u16 kind;
    /* 0x16 */ u16 h16;
    /* 0x18 */ int w18;
    /* 0x1C */ u8 b1C;
    /* 0x1D */ u8 b1D;
    /* 0x1E */ s8 b1E;
    /* 0x1F */ s8 b1F;
    /* 0x20 */ s8 b20;
    /* 0x21 */ u8 pad21;
    /* 0x22 */ u8 b22;
    /* 0x23 */ u8 b23;
    /* 0x24 */ int w24;
    /* 0x28 */ int w28;
} Effect;

/* DEBT(TYPE): per-opcode state blocks; the real layout is probably one union */
typedef struct OpArgs {
    int v0;
    int v1;
} OpArgs;

typedef struct OpList {
    int v0;
    s16 h4;
    u16 count;
    int arg[2];
} OpList;

typedef struct CamInfo {
    u8 pad0[6];
    s16 h06;
    float f08;
    float f0C;
    float f10;
    float f14;
} CamInfo;

typedef struct Pair32 {
    s32 w0, w4;
} Pair32;

typedef struct EvGameState {
    GameFlags flags;
    u16 h4;
    u16 h6;
    u8 pad8[4];
    u16 hC;
    u8 padE[6];
    u16 h14;
    u16 h16;
    u16 h18;
    u16 h1A;
    int w1C;
    void *p20;
    u8 pad24[8];
    int w2C;
    u8 pad30[0x44 - 0x30];
    int w44;
    int w48;
    void *p4C;
    u8 pad50[8];
    void *p58;
    void *p5C;
    void *p60;
    u8 pad64[0x1A4 - 0x64];
    Pair32 pairs1A4[8];
    u8 pad1E4[0x1F0 - 0x1E4];
    float f1F0;
    int w1F4;
    int *a1F8;
    int *a1FC;
    u8 pad200[0x208 - 0x200];
    float f208;
    u8 pad20C[4];
    s32 w210; /* flag bits */
    int w214;
    u8 pad218[0x238 - 0x218];
} EvGameState;

/* Script VM context shared by the three opcode-handler families (0x127880.., 0x24DCD0.., 0x278000..).
   DEBT(NAME): merged from the w1/w8/w9 "ScriptCtx": argc at 0 (w1), the slot-offset table at 0xC (w9 "info" ==
   w8 "mem"; both add base[i] + offset to the script memory block). */
typedef struct SlotInfo {
    int slot[3];                /* DEBT(NAME): byte offsets of the work areas inside the script memory */
} SlotInfo;

typedef struct ScriptWorkFlags { /* work area at slot[1] (script memory), only byte 0xA1 written */
    u8 pad00[0xA1];
    u8 bA1;
} ScriptWorkFlags;

typedef struct ScriptWorkA0 { /* work area at slot[1] (script memory), only word 0xA0 written */
    u8 pad00[0xA0];
    int wA0;
} ScriptWorkA0;

typedef struct ScriptWork128 { /* work area at slot[2] (script memory), only word 0x128 written */
    u8 pad00[0x128];
    int w128;
} ScriptWork128;

typedef struct ScriptCtx {
    int argc;
    int v[2];
    SlotInfo *info;
    int v_rest[0x11];
    u8 tag[0x14];
} ScriptCtx;

/* script memory block header; work areas follow at slot offsets */
typedef struct ScriptWork {
    u8 pad0[0xC];
    int owner;
    u8 m10[0x30];
    float f40;
    float f44;
    float f48;
    float f4C;
    float m50[4][4];
    struct T6_LtPt *pts;
} ScriptWork;


/* ======== types from the 0x14xxxx-0x17xxxx (w2) ======== */

/* Character record, 0x1D8 bytes per entry, D_0030E0C0 points at the array.
 * DEBT(NAME): member names are placeholders (<type letter><hex offset>); only the
 * offsets/widths that the accessors in c_16CB98..c_16EBA8 use are known. The u16 table
 * h_B2[] holds text ids (it is passed to the string lookup func_0016F368). */
typedef struct ChrRec1D8 {
    u8  pad_00[0x14];
    s32 w14;
    u8  pad_18[8];
    u8  b20[0x28];      /* 0x20..0x47 */
    u8  pad_48[6];
    u16 h4E;
    u8  pad_50[0x30];
    u16 h80[3];         /* 0x80..0x85 */
    u8  pad_86[2];
    u8  b88[4];         /* 0x88..0x8B */
    u16 h8C[4];         /* 0x8C..0x93 */
    u8  pad_94[4];
    u16 h98[4];         /* 0x98..0x9F */
    u8  pad_A0[4];
    u16 hA4[2];         /* 0xA4..0xA7 */
    u8  bA8[2];         /* 0xA8..0xA9 */
    u16 hAA;
    u8  pad_AC;
    u8  bAD;
    u8  pad_AE[3];
    u8  bB1;
    u16 hB2[0x70];      /* 0xB2..0x191 */
    u8  pad_192[2];
    s32 w194;
    u8  pad_198[0x40];
} ChrRec1D8;


/* ======== types from the 0x19Bxxx-0x1A2xxx voice/pool/task code (w3) ======== */

/* Voice/pool/task code, owner reached through g_pMainWork (area 0x19Bxxx-0x19Dxxx).
   DEBT(NAME): every W3* type name and every member name in this section is a guess from field usage only. */
typedef struct W3Pair { /* memory buffer (8 bytes), allocated by rcdtChunkNew */
    u8 *ptr;
    int size;
} W3Pair;

/* Text/binary stream reader (tokenizer); 0x8C bytes, allocated by func_0019D648. DEBT(NAME): guess. */
typedef struct W3Reader {
    W3Pair *buf;
    u8 *cur;
    int mode;   /* 0: binary, 1: text */
    s8 delim[0x80]; /* nonzero for separator characters */
} W3Reader;

/* Opaque objects living on the stack of func_0019D3C8; only their sizes are known */
typedef struct W3Obj50 { u8 pad[0x40]; void *p40; void *p44; u8 pad48[8]; } W3Obj50;

typedef struct W3Obj20 { float v[8]; } W3Obj20; /* two (x, y, z, 1) vectors, see func_0018F310 */

typedef struct W3ObjBig { u8 pad[0x240]; } W3ObjBig;

/* Image/GIF-packet buffer object (vtable-like head). DEBT(NAME): guess. */
typedef struct W3Img {
    u32 id;              /* 0x20002 */
    void (*dtor)(struct W3Img *);
    int i08;
    void (*fn0C)(struct W3Img *);
    u32 flags;           /* 0x10, bit0: owns buf */
    u8 pad14[4];
    unsigned long long reg18;
    unsigned long long reg20;
    unsigned long long reg28;
    int i30;
    int stride;          /* 0x34 */
    u8 *buf;             /* 0x38 */
    int i3C;
} W3Img;

typedef struct W3Blk { /* DEBT(NAME): guess: 0x10-byte member handled by func_002DD948 */
    u32 flags;           /* bit0: hidden (func_00198908) */
    u8 pad04[6];
    u8 b0A, b0B;         /* read by rcbgLayerLoad */
    struct W3Img *img;   /* 0xC */
} W3Blk;

typedef struct W3Obj { /* returned by func_0019D0C0; 0xE8+ bytes */
    int w00;
    u8 pad04[0x3C];
    W3Blk blk40;
    W3Blk blk50;
    float f60;
    float f64;
    u8 pad68[0x7B];
    u8 flagsE3;
    u8 enableE4;
} W3Obj;

typedef struct W3Sub90 {
    u32 flags;
    u8 pad04[2];
    s16 h6;
    u16 h8;
    u8 padA[0xA];
} W3Sub90; /* 0x14 */

typedef struct W3Voice {
    u32 flags;
    int i04;
    int i08;
    int i0C;
    int i10;
    float f14;
    u8 pad18[0xC];
    int i24;
    int i28;
    int i2C;
    int i30;
    u8 pad34[4];
    u64 d38;
    u8 rgba[3];
    u8 b43;
    float f44;
    float f48;
    float f4C;
    float f50;
    float f54;
    float f58;
    float f5C;
    float f60;
    float f64;
    float f68;
    float f6C;
    float f70;
    int i74;
    int i78;
    int i7C;
    int i80;
    u8 pad84[0xC];
    W3Sub90 sub90;
    int iA4;
    u8 padA8[8];
    W3Blk subB0; /* handled by func_00198CA8 */
} W3Voice; /* 0xC0 */

/* object kept in W3Pool.objs: a small vtable-like head. DEBT(NAME): guess */
typedef struct W3Item {
    u32 id;
    void (*dtor)(struct W3Item *o);
    void (*update)(struct W3Item *o);
    void (*draw)(struct W3Item *o);
} W3Item;

typedef struct W3Pool {
    u32 flags;
    int count;
    W3Voice *voices;
    int nobj;        /* 0x0C */
    W3Item **objs;   /* 0x10 */
    void *buf14;     /* released by rcbgSceneFini */
    s16 numItems;  /* 0x18 */
    s16 curItem;   /* 0x1A */
    void *items[18]; /* 0x1C, indexed by numItems; no code bounds the count, 18 is the span up to i64 (0x1C..0x64) */
    int i64;       /* 0x64, read by rcbgSceneLoad */
    u8 pad68[8];
    u8 blk70[0x10]; /* 0x70..0x9F: three 16-byte blocks read by rcbgSceneLoad */
    u8 blk80[0x10];
    u8 blk90[0x10];
    u8 padA0[0x10];
    int iB0;       /* 0xB0 */
    float fB4;
    u8 padB8[8];
    float fC0;
    float fC4;
    int iC8;
    float fCC;
    int iD0;
    int iD4;
    int iD8;
    int iDC;
    int iE0;
    int iE4;
    float fE8;
    int iEC;
    float fF0;
    int iF4;
    int iF8;
    float fFC;
    u8 pad100[0xC];
    int i10C;
    u8 pad110[0x10]; /* the object is 0x120 bytes (rcbgSceneInit) */
} W3Pool;

typedef struct W3Core {
    int npool;
    W3Pool *pools;
    W3Pool *pool;
    void *buf0C; /* 64 KiB buffer allocated by rcbgPreInit */
    int w10;
} W3Core;

typedef struct W3Owner {
    W3Core *core;
    struct W3Sub *sub; /* helper object most wrappers forward to */
    int w08;
    int w0C; /* DEBT(NAME): lazily created object, see func_001947E0 */
    W3Pair *buf10; /* DEBT(NAME): buffers released by rcbgFini */
    W3Pair *buf14;
    W3Pair *buf18;
} W3Owner; /* 0x1C bytes, allocated by func_00194530 */

/* Cooperative task (script-thread like) with a small stack of handler functions. DEBT(NAME): guess. */
struct W3Task;

typedef void (*W3TaskFn)();

typedef struct W3Frame {
    int count;   /* e.g. remaining wait ticks */
    int arg1;
    int arg2;
    int arg3;
} W3Frame;

typedef struct W3Task {
    u32 flags;               /* 1: alive, 2: re-run, 4: finished */
    struct W3Task *prev;
    struct W3Task *next;
    W3TaskFn fn[8];          /* 0x0C: handler stack */
    W3Frame frame[8];        /* 0x2C: per-handler data */
    int sp;                  /* 0xAC */
    W3TaskFn fnExit;         /* 0xB0 */
    W3TaskFn fnCleanup;      /* 0xB4 */
    int prio;                /* 0xB8 */
} W3Task; /* 0xBC */

typedef struct W3Sched {
    W3Task head;
    W3Task tail;             /* sentinel, prio 0xFFFF */
    int i178;
} W3Sched;


/* ======== types from the 0x1A8850-0x1D0D48 battle/party/system code (w4) ======== */

/* Worker 4 header: 0x1A8850-0x1D0D48. This range looks like the battle character / party / system
   config code: 31 BtlChr records (stride 0xC50, array pointer D_00662574, id validated by
   MsBtlChrNumCheck), 18 party slots (stride 0x94) and a big system block at D_003172F0.
   No source file name string for this range was found in the ELF (neighbours: "BtlResident",
   "INIT BATTLE"). All struct and member names below are guesses unless noted (DEBT(NAME)). */

/* Battle/party character record, stride 0xC50, array at D_00662574 (see MsGetMon).
   Only members touched by decompiled code are named. */
typedef struct Trio { u8 a, b, c; } Trio; /* DEBT(NAME): 3 byte record, usage unknown */


/* ======== types from the 0x1D1DF8-0x1F9938 battle actor helpers and event-script opcodes (w5) ======== */

typedef struct GsEnt48 { /* 0x48-byte entry */
    u8 id;
    u8 sub;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 pad5[2];
    u8 f7;
    struct GsEnt48Sub { u16 h0; u16 h2; u8 pad4[4]; s32 targets; u8 padC[4]; } f8[4]; /* DEBT(NAME): targets is a party bit mask (MsGetChrBit) */
} GsEnt48;


/* ======== types from the 0x1A8850-0x1D0D48 battle/party/system code (w4) ======== */

/* Battle/party character record, stride 0xC50, array at D_00662574 (see MsGetMon), returned by MsGetChr(id).
   DEBT(NAME): merged from the w4 "BtlChr" and the w5 "Chr" (same record: both come from MsGetChr) -- member names
   are f<hex offset>; only members touched by decompiled code are named. Signedness of fB3/fE0/f1C5/f1C8 differs between
   the two views (see the DEBT(TYPE) notes). */
typedef struct BtlChr {
    Chr *chr; /* 3D model character (Ch_GetWaitMotion/func_00110B78 take it) */
    s32 f04;
    s32 f08;
    u8 f0C;
    u8 fD;
    u16 fE;
    s8 f10;
    s8 f11;
    s8 f12;
    u8 pad13[0x1];
    u8 f14;
    u8 pad15[0x1];
    s8 f16[4];
    u8 pad1A[0x1];
    u8 f1B;
    u8 pad1C[0x3];
    u8 f1F;
    s8 f20;
    s8 f21;
    s8 f22;
    u8 f23;
    u8 pad24[0x1];
    s8 f25;         /* selected entry of f26 (func_001B6310) */
    s8 f26[3];
    s8 f29;
    s8 f2A[3];
    s8 f2D;         /* all f2E set (msSetChrBodyHit) */
    s8 f2E[4];
    u8 f32;
    s8 f33;
    s8 f34;
    s8 f35;
    u8 f36;
    s8 f37;
    s8 f38;
    s8 f39;
    s8 f3A;
    u8 f3B;
    u8 pad3C[0x1];
    s8 f3D;
    u8 f3E;
    u8 pad3F[0x1];
    float f40;
    float f44;
    struct R2Hdr0 *p48;
    s32 f4C;
    u8 pad50[0xC];
    s32 f5C;
    float f60;
    float f64;
    float f68;
    float f6C;
    u8 pad70[0x10];
    float f80[4];
    u8 pad90[0x20];
    u8 fB0;
    u8 fB1;
    u8 fB2;
    s8 fB3;
    u8 fB4;
    u8 fB5;
    u8 fB6;
    u8 fB7;
    u8 fB8;
    u8 fB9;
    u8 fBA;
    u8 fBB;
    u16 fBC;
    u8 padBE[0x2];
    u16 fC0;
    s16 fC2;
    u8 fC4;
    u8 fC5;
    u8 padC6[0x1];
    s8 fC7;
    u8 fC8;
    u8 fC9;
    u8 fCA;
    u8 fCB;
    u8 padCC[0x3];
    u8 fCF;
    u8 padD0[0x1];
    u8 fD1;
    u8 fD2;
    u8 fD3;
    u8 fD4;
    u8 fD5;
    u8 padD6[0x1];
    u8 fD7;
    u8 fD8;
    u8 padD9[0x1];
    u8 fDA;
    u8 fDB;
    u8 fDC;
    u8 fDD;
    u8 fDE;
    u8 fDF;
    s8 fE0;
    u8 padE1[0x1];
    s8 fE2;
    u8 fE3;
    u8 padE4[0x1];
    u8 fE5;
    u8 fE6;
    u8 fE7;
    u8 fE8;
    u8 fE9;
    u8 fEA;
    u8 fEB;
    u8 fEC;
    u8 padED[0x1];
    u8 fEE;
    u8 padEF[0x3];
    s8 fF2;
    s8 fF3;
    s8 fF4;
    u8 fF5;
    s8 fF6;
    u8 fF7;
    u8 fF8;
    u8 fF9;
    u8 padFA[3];
    u8 fFD;
    u8 fFE;
    u8 fFF;
    u8 f100;
    u8 f101;
    u8 pad102[0x4];
    u8 f106;
    u8 pad107;
    s8 f108;
    u8 f109;
    s8 f10A;
    s8 f10B;
    u8 f10C;
    u8 pad10D[0x1];
    s8 f10E;
    u8 f10F;
    u8 f110;
    u8 f111;
    u16 f112;
    s16 f114;
    u8 pad116[4];
    u16 f11A;
    u8 pad11C[0x8];
    float f124;
    u8 pad128[4];
    float f12C;
    u8 pad130[0x20];
    float f150[3];
    float f15C;
    u8 pad160[0xC];
    u32 flags;
    u8 pad170[0x5];
    u8 f175;
    u8 f176[2];
    u8 pad178[0x4];
    float f17C;
    float f180;
    float f184;
    float f188;
    float f18C;
    float f190;
    float f194;
    float f198;
    float f19C;
    u8 pad1A0[0x4];
    float f1A4;
    u8 pad1A8[0x8];
    float f1B0;
    u8 pad1B4[0x4];
    void *f1B8;
    Trio f1BC;
    s8 f1BF;
    Trio f1C0;
    u8 pad1C3[0x1];
    u8 f1C4;
    s8 f1C5;
    u8 pad1C6[0x2];
    s8 f1C8;
    Trio f1C9;
    s8 f1CC;
    s8 f1CD;
    u8 f1CE;
    u8 f1CF;
    u8 f1D0;
    s8 f1D1;
    s8 f1D2;
    u8 pad1D3;
    float f1D4[8];
    float f1F4;
    float f1F8;
    float f1FC;
    u8 f200[0x28];
    u8 f228[0x28];
    u8 flags250;
    u8 pad251;
    u8 item252[2]; /* DEBT(NAME): two ids looked up with MsGetSaveWeapon (func_001EE590) */
    s32 f254;
    s32 f258;
    u8 pad25C[0xC];
    u8 f268;
    u8 pad269[0x1];
    u8 f26A;
    u8 pad26B[0x1];
    u8 f26C;
    u8 f26D;
    u8 pad26E[0xA];
    u16 flags278;
    u8 f27A;
    u8 f27B;
    u8 f27C;
    u8 f27D;
    u8 f27E;
    u8 f27F;
    u8 f280;
    u8 f281;
    u8 f282;
    u8 f283;
    u8 f284;
    u8 pad285[0x1];
    u8 f286;
    u8 pad287[0x1];
    u8 f288;
    u8 pad289[0x1];
    u8 f28A;
    u8 f28B;
    u8 pad28C[0x4];
    s32 f290;
    s32 f294;
    u8 f298;
    u8 f299;
    u8 f29A;
    u8 f29B;
    u8 f29C;
    u8 f29D;
    u8 pad29E[0x28];
    u16 f2C6;
    u8 f2C8;
    u8 f2C9;
    u8 f2CA;
    u8 pad2CB[0x7];
    u8 f2D2;
    u8 f2D3;
    u8 f2D4;
    u8 pad2D5[0x1];
    u16 f2D6;
    u16 f2D8;
    u8 f2DA[13];
    u8 pad2E7[0x1];
    u16 f2E8;
    u16 f2EA;
    u16 f2EC;
    u16 f2EE;
    u8 pad2F0[0xC];
    u8 f2FC;
    u8 f2FD;
    u8 f2FE;
    u8 f2FF;
    u8 f300;
    u8 f301;
    u8 pad302[0xB];
    u8 f30D;
    u8 pad30E[0xC];
    u16 f31A;
    u8 f31C;
    u8 f31D;
    u8 pad31E[0x4];
    u8 f322;
    u8 f323;
    u16 f324[22]; /* DEBT(NAME): two 352-bit flag sets (func_001B93E8) */
    u16 f350[22];
    u16 f37C;
    u16 f37E;
    u8 pad380[0x6];
    u16 f386;
    u16 f388;
    u8 pad38A[0x2];
    u8 f38C;
    u8 f38D;
    u8 pad38E[0x1];
    u8 f38F;
    u8 pad390[0x1];
    u8 f391;
    u8 f392;
    u8 f393;
    u8 f394;
    u8 pad395[0x3];
    u8 f398;
    u8 f399;
    u8 f39A;
    u8 pad39B[0x1];
    u8 f39C;
    u8 f39D;
    u8 f39E;
    u8 pad39F[0x2];
    u8 f3A1;
    u8 pad3A2[0xE];
    s32 f3B0;
    s32 f3B4;
    s32 f3B8;
    s32 f3BC;
    u8 f3C0;
    u8 f3C1;
    u8 pad3C2[0x12];
    u8 f3D4;
    u8 f3D5;
    u8 f3D6;
    u8 pad3D7[2];
    u8 f3D9;
    u8 pad3DA[0xC];
    s8 f3E6[2];
    s8 f3E8[2];
    u8 pad3EA[0x2];
    GsEnt48 f3EC;
    u8 pad434[0x38C];
    u8 f7C0[16];
    u8 f7D0[16];
    u8 f7E0[16];
    u8 pad7F0[0x1F4];
    u8 f9E4;
    u8 f9E5;
    u8 f9E6;
    u8 pad9E7[0x5];
    float f9EC;
    float f9F0;
    u8 pad9F4[0xC];
    u8 fA00[0x20]; /* DEBT(NAME): id list filled by MsGetTargetListWakka */
    u8 fA20[0x20]; /* DEBT(NAME): id list rebuilt by MsGetTargetLinkList */
    u8 fA40[0x40]; /* DEBT(NAME): id list copied out by MsGetTargetListWakka */
    s32 fA80;
    s32 fA84;
    s8 fA88;
    u8 padA89[0x3];
    s8 fA8C;
    s8 fA8D;
    s8 fA8E;
    s8 fA8F;
    s8 fA90;
    s8 fA91;
    u8 padA92[0x2];
    s8 fA94;
    s8 fA95;
    u8 padA96[0x3];
    s8 fA99;
    s8 fA9A;
    u8 padA9B[0x2];
    s8 fA9D;
    u16 fA9E;
    u8 padAA0[0x4];
    u8 fAA4;
    u8 fAA5;
    u8 fAA6;
    u8 fAA7;
    u8 fAA8;
    u8 padAA9[0x1];
    s8 fAAA;
    u8 padAAB[0x1];
    u8 fAAC;
    s8 fAAD;
    u8 padAAE[0x1];
    u8 fAAF;
    s8 fAB0;
    s8 fAB1;
    u8 fAB2;
    s8 fAB3;
    u8 fAB4;
    u8 fAB5;
    u8 fAB6;
    u8 padAB7[0x1];
    s8 fAB8;
    u8 padAB9[0x2];
    s8 fABB;
    u8 fABC;
    s8 fABD;
    s8 fABE;
    s8 fABF;
    u8 fAC0;
    u8 fAC1;
    u8 padAC2[0x2];
    u16 fAC4;
    u16 fAC6;
    u16 fAC8;
    u16 fACA;
    u8 fACC;
    s8 fACD;
    u8 fACE;
    u8 fACF;
    u8 fAD0;
    u8 fAD1;
    u8 fAD2;
    u8 fAD3;
    u8 padAD4;
    s8 fAD5;
    s8 fAD6;
    u8 fAD7;
    u8 padAD8[0x1];
    s8 fAD9;
    s16 fADA;
    u8 padADC[0x2];
    u16 fADE;
    u8 padAE0[0x2];
    u16 fAE2;
    u16 fAE4;
    u16 fAE6;
    u8 padAE8[0x2];
    u16 fAEA;
    u8 padAEC[0x4];
    s32 fAF0[24];
    s32 fB50[4];
    int fB60;
    s32 fB64;
    int fB68; /* handle later passed to func_00297CE8 (int there; DEBT(TYPE) in that file) */
    s32 fB6C[32]; /* DEBT(NAME): resource handles released with SndSepClear */
    u8 fBEC;
    u8 padBED[0x1];
    u8 fBEE;
    u8 padBEF[0xD];
    s32 fBFC;
    s32 fC00;
    u8 padC04[0x10];
    s32 fC14;
    s32 fC18;
    u16 fC1C;
    u8 fC1E;
    u8 fC1F;
    u8 padC20[0x4];
    u8 fC24;
    u8 fC25;
    s16 fC26;
    u8 padC28[0xe];
    u16 fC36;
    u8 *pC38;
    u8 *pC3C;
    u8 *pC40;
    u8 *pC44;
    u8 padC48[0x4];
    s32 fC4C;
} BtlChr;

/* Party slot record, stride 0x94, array inside SaveData (+0x55CC == D_0031EA9C); also returned by MsGetSavePlayerPtr(id).
   DEBT(NAME): member names are offsets until the meaning is known. v1C..v88 came from the (w7) "GameSettings" view of
   the same record: MsGetSavePlayerPtr is defined in C as returning a PartySlot, so the two are the same object. */
typedef struct PartySlot {
    u8 pad00[0x4];
    s32 f04;
    s32 f08;
    u8 f0C[8];
    s32 f14;
    s32 f18;
    s32 v1C;
    s32 v20;
    s32 v24;
    s32 v28;
    u8 flags2C;
    u8 f2D;
    u8 f2E;
    u8 pad2F[2];
    u8 b31;
    u8 pad32[6];
    u8 b38;
    u8 b39;
    u8 b3A;
    u8 f3B;
    u8 b3C;
    u8 b3D;
    u16 h3E[6]; /* bit set tested by MsGetSaveCommand */
    u16 h4A;
    u16 h4C;
    u16 h4E;
    s32 v50;
    s32 v54;
    s32 v58;
    u8 pad5C[4];
    u16 h60[20];
    s32 v88;
    u8 pad8C[0x94 - 0x8C];
} PartySlot;

/* Big save/progress block at D_003194D0 (0x6034+ bytes): party slots, gil, event flag bytes/bits.
   DEBT(NAME): was "PartyBlock" (party slots, gil; w4) and "W5Flags" (event flags; w5) -- same global, no overlapping
   members, merged. The name is a guess from the content (the layout is what the save code copies around). */
typedef struct SaveData {
    u8 pad0[0x2C];
    u32 w2C[8];
    u8 pad4C[0x3D10 - 0x4C];
    u32 f3D10; /* DEBT(NAME): bit mask, bit n set by TOSetAlbhedFlg(n) */
    u8 pad3D14[0x3D48 - 0x3D14];
    s32 f3D48; /* gil, same storage as D_0031D218 */
    u8 pad3D4C[0x3D5B - 0x3D4C];
    u8 b3D5B[17];
    u16 h3D6C[0x1C]; /* DEBT(TYPE): length = gap up to f3DA4; event bits 0x3060.. (MsGetSaveCommand) */
    s32 f3DA4;
    u8 pad3DA8[0x3ECC - 0x3DA8];
    u16 h3ECC[0x70];
    u8 pad3FAC[0x40CC - 0x3FAC];
    u8 b40CC[0x70];
    u8 pad413C[0x420C - 0x413C];
    u8 flag[0x280]; /* DEBT(TYPE): indexed up to 0xFFF by MsGetMonsterCapture */
    u16 bits[8]; /* 0x448C: 128 event bits */
    u8 flag2[0xD70];
    u8 pad520C[0x55CC - 0x520C];
    PartySlot slot[18]; /* DEBT(TYPE): count from loops (0x12) */
} SaveData;

/* Table of {u16 start, u16 end, u32 pad[2]} ranges after an 8 byte header, stride 0xC. */
typedef struct RangeEnt { u16 start; u16 end; u16 stride; u16 extra; s32 off; } RangeEnt;

typedef struct RangeTbl { s16 count; u8 pad2[6]; RangeEnt ent[1]; } RangeTbl;

/* one movement limit of a camera area (0x20 bytes) */
typedef struct R2Limit {
    u32 type;   /* 0, 2: line (soft / hard), 1: floor, 3: ceiling, 4, 5: ground query */
    float d;
    float len;
    float k;
    float nx;
    float nz;
    float x;    /* also lower bound for types 1 and 3 */
    float z;    /* also upper bound for types 1 and 3 */
} R2Limit;

/* 0x130-byte area block, four of them in each Unk317120Rec at 0xC0 */
typedef struct R2AreaObj { u8 pad0[4]; u8 flags; } R2AreaObj; /* DEBT(NAME): object from AtelGetRealVarAdrs, only flags known */

typedef struct R2Area {
    s8 b00;
    u8 b01;
    u8 b02;
    u8 b03;
    u8 nlim;
    u8 b05;
    u8 b06;
    s8 b07;     /* bit flags */
    R2AreaObj *obj;
    u8 pad_0C[0x10];
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 pad_1F;
    float f20;
    float f24;
    u8 pad_28[8];
    float v30[4];
    float v40[4];
    float v50[4];
    u8 pad_60[8];
    float f68, f6C;
    float v70[4];
    u8 pad_80[0x10];
    R2Limit lim[5];
} R2Area;

/* 0x10-byte timed transition (func_001A9550 / func_001A96A8) */
typedef struct R2Fade {
    s16 mode;
    u8 pad2[2];
    s16 h4;
    s16 t0, t1, t2;
    s16 total;
    s16 time;
} R2Fade;

typedef struct Unk317120Rec { /* 0x620 bytes; DEBT(NAME): guessed from func_001A9918/MsCameraGetPosNow */
    u8 b0;
    s8 b1;
    u8 pad2[1];
    u8 b3;
    u8 pad4[4];
    float f8;
    float fC;
    float v10[3];
    u8 pad1C[4];
    float v20[3];
    u8 pad2C[0x40 - 0x2C];
    float v40[4];
    float v50[4];
    float v60[3];
    u8 pad6C[4];
    float v70[4];
    float v80[3];
    int w8C;
    float v90[3];
    u8 pad9C[0xC0 - 0x9C];
    R2Area area[4];
    R2Fade fade[3];
    struct { u8 on; u8 pad1[0x23]; } e5B0[3]; /* DEBT(NAME): 0x24-byte entries, only the first byte is known */
    u8 pad61C[0x620 - 0x61C];
} Unk317120Rec;

typedef struct Unk317120 {
    u8 pad0[0x30];
    Unk317120Rec rec[2];
    u8 padC70[0xC98 - 0xC70];
    float fC98;
    u8 padC9C[8];
    float fCA4;
} Unk317120;

/* 4-byte table entries whose only used member is the last byte */
typedef struct Ent4 { u8 b0; u8 b1; u8 b2; u8 v; } Ent4;

/* Small command record returned by value in v0: byte0, byte1, 12-bit id. */
typedef struct PackedCmd {
    u8 hi; /* DEBT(NAME): member names guessed */
    u8 lo;
    u16 id;
} PackedCmd;

/* Entry of the lookup tables at D_0031734C.. returned by MsGetExcelData (only first byte and flags known). */
typedef struct TblEnt {
    u8 f0;
    u8 pad1[0xF];
    u8 flags10;
    u8 f11;
    u8 f12;
    u8 f13;
} TblEnt;

typedef struct Unk33D0 { s16 f0; s16 f2; } Unk33D0;

typedef struct Unk65FF88 { /* 0x54-byte record, array at D_0065FF88; DEBT(NAME): guessed from MsAtelRegist */
    s32 count;
    void *w4; /* work buffer, w8 bytes */
    s32 w8;
    void *wC; /* local buffer, w10 bytes */
    s32 w10;
    void *a14[8]; /* DEBT(TYPE): objects passed to AtelGetActorBufferSize/func_00144810 */
    s32 a34[8];
} Unk65FF88;

typedef struct Unk1BFED8 { u16 h0; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 pad7[5]; u16 fC; u16 fE[4]; } Unk1BFED8;

typedef struct Unk314840 {
    u8 pad0[0x10];
    float f10, f14, f18;
    u8 pad1C[4];
    float f20, f24, f28;
    u8 pad2C[4];
    Unk317120Rec rec[2]; /* 0x30; area[j].b07 of rec[1] was e650[j].fC7 */
    struct { int id; s8 flag; s8 b5; s8 b6; u8 pad7[1]; } slot[4];
    u8 padC90[2];
    u8 fC92;
    u8 padC93[0xC9C - 0xC93];
    float fC9C;
    float fCA0;
    u8 padCA4[4];
    float fCA8;
    float fCAC;
    int wCB0;
    int wCB4;
    int wCB8[2];
    struct Unk314840Ent { float f0, f4, f8; u8 padC[4]; int w10; int w14[2]; u8 pad1C[0x14]; } eCC0[4];
    R2Fade fadeD80[2];
} Unk314840;

typedef struct Rec14 { u8 pad[0x14]; } Rec14;

typedef struct Sub1C { u8 pad0[0x1C]; u32 f1C; } Sub1C;

typedef struct Obj1A { u8 pad0[0x1A]; u16 f1A; } Obj1A;

typedef struct Obj1CD860 { u8 padx[0xC4C]; Sub1C *fC4C; } Obj1CD860;

typedef struct Obj4900 { void *p0; u8 pad4[0x3C - 4]; u16 f3C; } Obj4900;


typedef struct PairU16 { u16 v; u16 pad; } PairU16;

typedef struct Rec142F0 { u8 pad0[0x8]; float f08, f0C, f10, f14; u8 pad18[0x4]; float f1C; u8 pad20[0x10]; s32 w30[2]; u8 pad38[8]; float f40[2][4]; u8 pad60[0x20]; float f80[2][4]; u8 padA0[0x20]; u8 fC0; u8 fC1; u8 fC2[14]; s32 fD0; u8 padD4[0xDC - 0xD4]; struct Rec142F0Slot { s16 h0; u8 pad2[10]; s16 hC; s16 hE; } sl[2][4]; u8 pad15C[0x10]; struct { u8 b; u8 pad1[0x23]; } e16C[2]; u8 pad1B4[0x1C0 - 0x1B4]; } Rec142F0; /* DEBT(TYPE): stride 0x1C0 inferred from loop */

typedef struct Obj436Ent { /* 0x2C-byte entry, merged by MsMergeDamage; DEBT(NAME) */
    s8 b0;
    s8 b1;
    u8 b2;
    u8 pad3;
    u8 b4;
    u8 pad5[0x18 - 0x5];
    u16 h18;
    u16 h1A;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
} Obj436Ent;
typedef struct Obj436 { u8 pad0[0x434]; struct Obj436Slot { u8 first; u8 count; u8 v; u8 sub; u8 pad4[0x14]; Obj436Ent ent[16]; } slot[2]; } Obj436; /* DEBT(TYPE): layout inferred from loop stride */

typedef struct Rec2D8 { u8 pad0[0x2D8]; u16 f2D8; u8 f2DA[13]; u8 pad2E7; u16 f2E8; } Rec2D8;


/* ======== types from the 0x1D1DF8-0x1F9938 battle actor helpers and event-script opcodes (w5) ======== */

/* Chunks c_1D1DF8..c_1F9938 (0x1D1DF8-0x1F9938): battle/field actor helpers (BtlChr accessors)
   and the event-script opcode handlers (they fetch their argument via AtelPopStackInteger). */

typedef struct GsEnt8 { /* 8-byte entry: id/sub pair */
    u8 id;
    u8 sub;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 pad5[3];
} GsEnt8;

typedef struct Gs32 { /* 32-byte record, copied as a whole by func_001AF990 */
    s32 w0;
    s32 handle;
    s32 w8, wC, w10, w14;
    s32 w18;
    s8 *p1C;
} Gs32;

typedef struct GsTbl { s32 w0; s32 off4; s32 off8; } GsTbl;

typedef struct GsEnt14 { s16 h0; u8 pad2[12]; } GsEnt14;

/* Event list handed to MsCheckSummon: page selector at +2, then pages of 8 event ids from +8. DEBT(NAME) */
typedef struct EvList {
    u8 pad0[2];
    u8 page;
    u8 pad3[5];
    u16 ev[4][8];
} EvList;

/* Queued command of the ring at D_003172F0.f2044 (see MsMessageCueProcess). */
typedef struct CmdEnt {
    u8 op;
    u8 b1;
    u8 b2;
    u8 pad3;
    s32 a;
    s32 b;
} CmdEnt;

/* Game/system work area at D_003172F0 (0x2148 bytes).
   DEBT(NAME): was "SysCfg" (w4) and "GameState" (w5) for the same global; merged. Member names are offset
   placeholders. Many small globals between 0x3172F0 and 0x319438 (D_00317304, D_0031731C, ...) alias members of it. */
typedef struct GameState {
    u8 pad0[0x10];
    s8 f10;
    u8 pad11[0x1];
    s8 f12;
    u8 pad13[0x1];
    s8 f14;
    s8 f15;
    s8 f16;
    u8 f17;
    s8 f18;
    u8 f19;
    u8 pad1A[0x20 - 0x1A];
    s32 f20;
    u8 pad24[0x1];
    s8 f25;
    u8 pad26[0x2];
    s8 f28;
    s8 f29;
    u8 pad2A[0x2C - 0x2A];
    u8 f2C;
    u8 f2D;
    u8 pad2E[0x30 - 0x2E];
    s8 f30;
    u8 pad31[0x33 - 0x31];
    s8 f33;
    u8 pad34[0x3B - 0x34];
    s8 f3B; /* debug print switch (func_001ED990) */
    s8 f3C;
    u8 pad3D[0x4F - 0x3D];
    s8 f4F;
    u8 pad50[0x2];
    s8 f52;
    u8 pad53[0x59 - 0x53];
    u8 f59;
    u8 f5A;
    u8 pad5B[0x1];
    void *p5C; /* memory handles of the resident tables loaded by func_001AF648 */
    void *p60;
    void *p64;
    void *p68;
    void *p6C;
    void *p70;
    void *p74;
    void *p78;
    u8 pad7C[4];
    void *p80;
    void *p84;
    void *p88;
    s32 f8C;
    struct RangeTbl *p90;
    struct RangeTbl *p94;
    u16 h98;
    u16 h9A;
    u8 pad9C[0x2];
    u16 h9E;
    u16 hA0;
    u8 padA2[0xB4 - 0xA2];
    Gs32 h32[2]; /* DEBT(TYPE): count guessed (indexed up to 2 elsewhere) */
    GsTbl *pF4;
    GsEnt14 *pF8;
    void *pFC;
    s16 h100;
    u8 pad102[2];
    u8 f104;
    s8 f105;
    u8 pad106[1];
    u8 f107;
    s32 w108;
    s32 w10C;
    float f110;
    float f114;
    float f118;
    float f11C;
    s16 *p120;
    u8 pad124[0x12C - 0x124];
    u8 *p12C;
    struct { u8 id; u8 pad1; u16 val; } slot[32]; /* 0x130; DEBT(TYPE): length = distance to ent8 */
    GsEnt8 ent8[62];
    GsEnt48 ent48[62];
    s8 f1510;
    s8 f1511;
    u8 pad1512[0x1520 - 0x1512];
    GsEnt48 ent1520;
    u8 pad1568[0x15C0 - 0x1568];
    s32 f15C0;
    u8 pad15C4[0x4];
    struct SysEnt { s32 handle; s32 w4; u8 pad8[2]; u8 fA; u8 padB; } ent[32]; /* DEBT(TYPE): count guessed */
    u8 pad1748[8];
    u8 f1750;
    u8 f1751;
    u8 f1752;
    u8 f1753;
    s32 f1754;
    u8 f1758;
    u8 f1759;
    u8 f175A;
    u8 f175B;
    s32 w175C[128];
    s32 f195C[8];
    s32 f197C;
    s32 f1980;
    u8 pad1984[0x1986 - 0x1984];
    s16 h1986;
    u8 pad1988[0x198A - 0x1988];
    char s198A[0x20]; /* DEBT(TYPE): text printed by MsBattleProcess, length unknown */
    u8 pad19AA[0x1DE6 - 0x19AA];
    u16 h1DE6[0x70]; /* DEBT(NAME): two id lists rebuilt by MsSetItemWindow */
    u16 h1EC6[0x70];
    u8 pad1FA6[0x1FC5 - 0x1FA6];
    u8 f1FC5[7];
    u8 pad1FCC[0x1FF8 - 0x1FCC];
    s32 f1FF8;
    s32 f1FFC;
    s32 f2000;
    s32 f2004;
    u8 pad2008[0x200C - 0x2008];
    s32 f200C;
    s32 f2010;
    u32 w2014;
    s32 f2018;
    s32 f201C;
    s32 f2020;
    s32 f2024;
    s32 f2028;
    s32 f202C;
    u8 pad2030[0x2034 - 0x2030];
    u32 w2034;
    u32 w2038;
    s32 f203C;
    s32 f2040;
    CmdEnt f2044[4]; /* ring of queued commands, head f2075, count f2074 */
    u8 f2074;
    u8 f2075;
    s8 f2076;
    s8 f2077;
    u16 h2078;
    u8 pad207A[0x2080 - 0x207A];
    s32 f2080[31]; /* DEBT(TYPE): length guessed from the gap up to f20FE */
    s8 f20FC;
    u8 pad20FD[0x1];
    s8 f20FE;
    s8 f20FF;
    s8 f2100;
    s8 f2101;
    s8 f2102;
    s8 f2103;
    s8 f2104;
    s8 f2105;
    s8 f2106;
    u8 f2107;
    u8 pad2108[0x210E - 0x2108];
    s8 f210E;
    u8 f210F;
    u8 f2110;
    u8 f2111;
    u8 pad2112[0x2114 - 0x2112];
    s8 f2114;
    u8 f2115;
    s8 f2116;
    s8 f2117;
    s8 f2118;
    s8 f2119;
    s8 f211A;
    u8 pad211B[0x6];
    s8 f2121;
    u8 pad2122[3];
    u8 f2125;
    u8 pad2126;
    u8 f2127;
    u8 pad2128[0x212B - 0x2128];
    s8 f212B;
    s8 f212C;
    u8 pad212D[0x1];
    s8 f212E;
    s8 f212F;
    s8 f2130;
    s8 f2131;
    u8 pad2132[0x1];
    s8 f2133;
    u8 pad2134[0x2136 - 0x2134];
    s8 f2136;
    u8 pad2137[0x1];
    s8 f2138;
    u8 f2139;
    s8 f213A;
    s8 f213B;
    s8 f213C;
    u8 f213D;
    u8 pad213E[0x2140 - 0x213E];
    s8 f2140;
    u8 pad2141[0x2147 - 0x2141];
    u8 f2147;
} GameState;

/* DEBT(NAME): all W5 record structs below are named by shape only */
typedef struct W5Buf { /* btlgetdata */
    u8 pad0[0x38];
    s32 cur[18];
    s32 next[18];
    u8 padC8[0xD0 - 0xC8];
    s8 bD0;
    u8 padD1[3];
    u16 hD4[8];
    u8 bE4[8];
    u8 padEC[2];
    u16 h[8];
    u8 padFE[0x1B0 - 0xFE];
} W5Buf;

typedef struct W5Rec {
    u16 h0;
    u8 pad2[2];
    u8 b4;
    u8 b5;
    u8 pad6[6];
    u16 h0C;
    u16 h0E[4];
} W5Rec;

typedef struct W5OffTbl { u16 count; u16 off[1]; } W5OffTbl;

typedef struct W5Bits { s32 w0; s32 w4; u8 b8[8]; u16 bits[8]; } W5Bits; /* w0/w4/b8: stat bonuses added by MsGetChrAbilityMap */

typedef struct W5Ent16 { u8 pad0[2]; u8 b2; u8 b3; u8 b4; u8 b5; u8 pad6[0x10]; } W5Ent16; /* 0x16-byte entry */

typedef struct W5Msg { u8 pad0[4]; s16 h4; s16 h6; } W5Msg;


/* ======== types from the 0x1F9xxx-0x2237B0 GS packet builders, text and UI (w6) ======== */

/* One GIF A+D entry: GS register data followed by the register address. */
typedef struct {
    u64 data;
    u64 reg;
} GsAdPacket;

/* Four-word GS/GIF-style quad (vertex coordinates etc.). */
typedef struct {
    s32 w[4];
} Quad32;

typedef struct UiRgba {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} UiRgba;

/* UI slide/animation widget (c_208588 .. c_209xxx). DEBT(NAME): every member name is a guess from
 * how the animation callbacks use it (rects are x,y,w,h; phase 2 = open, 4 = close). */
typedef struct UiWidget {
    /* 0x00 */ s16 f00;
    /* 0x02 */ s16 f02;
    /* 0x04 */ s16 f04;
    /* 0x06 */ s16 f06;
    /* 0x08 */ s16 phase;
    /* 0x0A */ u8 pad0A[2];
    /* 0x0C */ s16 timer;
    /* 0x0E */ s16 duration;
    /* 0x10 */ s16 scale; /* DEBT(NAME): multiplied by f06 (4.12 fixed point) */
    /* 0x12 */ u8 pad12[4];
    /* 0x16 */ s16 start[4];
    /* 0x1E */ s16 target[4];
    /* 0x26 */ s16 stepX;
    /* 0x28 */ s16 stepY;
    /* 0x2A */ u8 pad2A[2];
    /* 0x2C */ s16 f2C;
    /* 0x2E */ s16 cur[4];
    /* 0x36 */ UiRgba col[1];
    /* 0x3A */ u8 pad3A[0x0E];
    /* 0x48 */ s32 onOpen;
    /* 0x4C */ u8 pad4C[4];
    /* 0x50 */ s32 onClose;
    /* 0x54 */ s32 result;
} UiWidget;

/* Table of byte offsets from the table start: count, then offset[count]. */
typedef struct OffsetTable {
    u32 count;
    u32 offset[1];
} OffsetTable;

/* Entry in the table at func_0020EC90() (reached by byte offset). DEBT(NAME): all member names guessed. */
typedef struct TblEntry {
    u32 w0;
    u32 flags; /* bit31/bit30 are tested and set/cleared as a pair */
    s16 val0;
    s16 val1;
} TblEntry;

/* Entry of the table at func_0020EC90(), reached by byte offset from the table base. */
#define TBL_ENTRY(base, off) ((TblEntry *)((u8 *)(base) + (off)))

/* Text window / label (c_2020A0 .. c_2040E8). DEBT(NAME): member names guessed from use. */
typedef struct TextWin {
    /* 0x00 */ s16 f00;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 font;
    /* 0x06 */ u8 pad06[0x14];
    /* 0x1A */ s16 style;
    /* 0x1C */ u8 pad1C[8];
    /* 0x24 */ s16 f24;
    /* 0x26 */ u8 pad26[6];
    /* 0x2C */ s16 f2C;
    /* 0x2E */ s16 f2E;
    /* 0x30 */ u8 pad30[8];
    /* 0x38 */ s16 textW;
    /* 0x3A */ s16 textH;
    /* 0x3C */ u8 pad3C[4];
    /* 0x40 */ s16 x0;
    /* 0x42 */ s16 y0;
    /* 0x44 */ s16 x1;
    /* 0x46 */ u8 pad46[2];
    /* 0x48 */ u8 col[4]; /* rgba, 0x80 = neutral */
    /* 0x4C */ u8 pad4C[0x30];
    /* 0x7C */ u8 *cur;
    /* 0x80 */ u8 *text;
    /* 0x84 */ s32 f84;
    /* 0x88 */ u8 pad88[4];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[4];
    /* 0x98 */ s32 f98;
    /* 0x9C */ s32 f9C;
    /* 0xA0 */ u8 padA0[4];
    /* 0xA4 */ s32 fA4;
    /* 0xA8 */ u8 padA8[0x3C];
    /* 0xE4 */ s32 fE4;
    /* 0xE8 */ u8 padE8[0xC];
    /* 0xF4 */ s32 fF4;
    /* 0xF8 */ int (*fF8)(struct TextWin *);
} TextWin;

/* Text draw item built on the stack by the label code (0x14 bytes). DEBT(NAME): names guessed. */
typedef struct TextItem {
    /* 0x00 */ u8 col[4]; /* rgba, 0x80 = neutral */
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ u8 pad08[0xA];
    /* 0x12 */ u8 f12;
    /* 0x13 */ u8 f13;
} TextItem;

/* Small frame-counter record (c_213EF8). DEBT(NAME): all names guessed. */
typedef struct FrameCounter {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 pad01[0xB];
    /* 0x0C */ s8 level;
    /* 0x0D */ u8 pad0D[2];
    /* 0x0F */ s8 frame;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ s32 value;
} FrameCounter;


/* ======== types from the 0x2237B0-0x24CC70 UI/menu state handlers (w7) ======== */

/* Area 0x2237B0-0x24CC70: UI/menu state-handler callbacks (Task/FlagRec objects), pad-flag toggles,
   party-slot accessors (PartySlot) and GS packet helpers. No source-file name string found. */

/* Event/task (UI element) record handled by the 0x22xxxx-0x24xxxx state-handler callbacks.
   DEBT(TYPE): only the members touched so far are known; names are offsets until meaning is clear. */
typedef struct Task {
    /* 0x00 */ s32 x00;
    /* 0x04 */ s32 x04;
    /* 0x08 */ void (*cb)();
    /* 0x0C */ s32 x0C;
    /* 0x10 */ s32 x10;
    /* 0x14 */ s32 x14;
    /* 0x18 */ s32 x18;
    /* 0x1C */ s32 x1C;
    /* 0x20 */ s32 x20;
    /* 0x24 */ s32 x24;
    /* 0x28 */ s32 state;
    /* 0x2C */ s16 x2C;
    /* 0x2E */ s16 x2E;
    /* 0x30 */ s16 x30;
    /* 0x32 */ s16 x32;
    /* 0x34 */ s16 x34;
    /* 0x36 */ u8 b36;
    /* 0x37 */ u8 b37;
    /* 0x38 */ s16 x38;
    /* 0x3A */ s16 x3A;
    /* 0x3C */ u8 pad3C[2];
    /* 0x3E */ u8 b3E;
    /* 0x3F */ u8 b3F;
    /* 0x40 */ u8 b40;
    /* 0x41 */ u8 b41;
    /* 0x42 */ u8 b42;
    /* 0x43 */ u8 b43;
    /* 0x44 */ u8 b44;
    /* 0x45 */ s8 b45;
    /* 0x46 */ s16 x46;
    /* 0x48 */ s16 x48;
    /* 0x4A */ s16 x4A;
    /* 0x4C */ s16 x4C;
    /* 0x4E */ s16 x4E;
    /* 0x50 */ s16 x50;
    /* 0x52 */ s16 x52;
    /* 0x54 */ s16 x54;
    /* 0x56 */ u8 pad56[2];
    /* 0x58 */ s32 ext[16]; /* x64 = ext[3], x68 = ext[4], x90 = ext[14] */
} Task;

/* DEBT(TYPE): record whose word at 0x08 is a flag (func_00235230/func_002351F8); probably the same family as Task */
typedef struct FlagRec { s16 rect[4]; s32 x08; s32 x0C; s32 x10; s32 x14; } FlagRec;

/* argument block {x, y, w, h, p8, pC} handed to func_00225718. DEBT(NAME): field names guessed */
typedef struct DrawArgs { s16 x, y, w, h; s32 p8, pC, p10, p14; } DrawArgs;

/* record with a slot list: count at 0x0B, u16 slots from 0x0E (0 or 0xFF = free) */
typedef struct SlotRec {
    /* 0x00 */ u8 pad00[0x0B];
    /* 0x0B */ u8 count;
    /* 0x0C */ u8 pad0C[2];
    /* 0x0E */ u16 slots[1];
} SlotRec;

/* 4-byte table entry (DEBT(NAME): name guessed) */
typedef struct SysEntry { u16 h0; u8 b2; u8 b3; } SysEntry;

/* record returned by func_00124828; DEBT(NAME): save/event state block at D_00580CB8 */
typedef struct Rec124828 {
    /* 0x00 */ u16 x00;
    /* 0x02 */ u16 x02;
    /* 0x04 */ u16 x04;
    /* 0x06 */ u16 x06;
    /* 0x08 */ u16 x08;
    /* 0x0A */ u16 x0A;
    /* 0x0C */ u8 x0C;
    /* 0x0D */ u8 x0D;
    /* 0x0E */ u16 x0E;
    /* 0x10 */ union {
        u32 flags;
        u8 bytes[4];
        struct {
            unsigned lo : 25;
            unsigned b25 : 1;
            unsigned b26 : 1;
            unsigned hi : 5;
        } b;
    } control10;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ s32 w18[2];
    /* 0x20 */ u8 x20;
    /* 0x21 */ u8 pad21[0x07];
    /* 0x28 */ u8 x28;
    /* 0x29 */ u8 x29;
    /* 0x2A */ u8 x2A;
    /* 0x2B */ u8 x2B;
    /* 0x2C */ s32 w2C[8];
    /* 0x4C */ u32 w4C[20];
    /* 0x9C */ u8 pad9C[0x18];
    /* 0xB4 */ u16 xB4;
    /* 0xB6 */ u16 xB6;
    /* 0xB8 */ u16 xB8;
    /* 0xBA */ u16 xBA;
    /* 0xBC */ s32 vBC;
    /* 0xC0 */ u16 hC0, hC2, hC4, hC6, hC8, hCA, hCC;
    /* 0xCE */ union { u16 h; u8 b; } vCE;
    /* 0xD0 */ u8 xD0;
    /* 0xD1 */ u8 xD1;
    /* 0xD2 */ u8 xD2;
    /* 0xD3 */ u8 padD3;
    /* 0xD4 */ u16 xD4;
    /* 0xD6 */ u8 xD6;
    /* 0xD7 */ u8 xD7;
    /* 0xD8 */ s32 xD8;
    /* 0xDC */ s32 xDC;
    /* 0xE0 */ s32 xE0;
    /* 0xE4 */ s32 xE4;
    /* 0xE8 */ u16 xE8;
    /* 0xEA */ u16 xEA;
    /* 0xEC */ u8 padEC[0x1EC - 0xEC];
    /* 0x1EC */ u8 buf1EC[0xBEC - 0x1EC];
    /* 0xBEC */ u16 xBEC;
    /* 0xBEE */ u8 padBEE[0x3D48 - 0xBEE];
    /* 0x3D48 */ u8 blk3D48[1];
} Rec124828;

/* Entry of the tables handed out by MsGetExcelData (idx, table handle D_003173xx, pos out).
   DEBT(NAME)/DEBT(TYPE): merged from the w5 "W5Ent" (f69), the w6 "ResEntry" (u16 ofs at 0 == a[0].x, flags at 0x1C)
   and the w7 "OfsTbl" views, which all describe the entries of the tables behind MsGetRomPlyCommand..MsGetRomAbility (same
   table handles D_0031734C..D_00317364). The tables behind D_00317358/D_0031736C use TblEnt instead. */
typedef struct OfsTbl {
    /* 0x00 */ Pt16 a[2];
    /* 0x08 */ Pt16 b[2];
    /* 0x10 */ u8 b10;
    /* 0x11 */ u8 pad11;
    /* 0x12 */ u8 b12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 b14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 b16;
    /* 0x17 */ u8 b17;
    /* 0x18 */ u8 pad18[2];
    /* 0x1A */ u16 h1A;
    /* 0x1C */ u32 flags;
    /* 0x20 */ u8 pad20[2];
    /* 0x22 */ u8 b22;
    /* 0x23 */ u8 pad23;
    /* 0x24 */ u8 b24;
    /* 0x25 */ u8 b25;
    /* 0x26 */ u8 b26;
    /* 0x27 */ u8 pad27;
    /* 0x28 */ u8 b28;
    /* 0x29 */ u8 pad29;
    /* 0x2A */ u8 b2A;
    /* 0x2B */ u8 pad2B[2];
    /* 0x2D */ u8 b2D;
    /* 0x2E */ u8 pad2E[0x58 - 0x2E];
    /* 0x58 */ u8 b58;
    /* 0x59 */ u8 pad59[0x5C - 0x59];
    /* 0x5C */ u8 b5C;
    /* 0x5D */ u8 b5D;
    /* 0x5E */ u8 pad5E[0x68 - 0x5E];
    /* 0x68 */ u8 b68;
    /* 0x69 */ u8 f69;
} OfsTbl;


/* ======== types from the 0x24DCD0-0x276C38 (w8) ======== */

/* DEBT(NAME): guess, circular doubly linked list; the head uses count/flags where nodes carry data words */
/* DEBT(TYPE): callback argument words follow the invocation in func_00266E08. */
typedef void (*ListCallback)(int argument, int index, int frame);
typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    ListCallback callback;
    union {
        int b;
        struct {
            u16 count;
            u16 flags;
        } head;
    } u;
} ListNode;

/* DEBT(NAME): guess, 0x340-byte character slot, array pointed to by D_006A391C */
typedef struct ChrSub {
    int id;
    u8 off;
    u8 pad5[3];
    u32 arg;
} ChrSub;

typedef struct ChrWork {
    union {
        u16 rect[4];
        struct {                /* slot 12 doubles as a request block */
            s16 id;
            s16 pad;
            void (*fn)(void);
        } req;
    } a;
    u16 rect1[4];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    s16 f18;
    s16 f1A;
    s16 f1C;
    s16 f1E;
    u16 f20;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 f25;
    u8 f26;
    u8 f27;
    u8 f28;
    u8 f29;
    u16 rect2[4];
    u8 f32;
    u8 pad33;
    void (*f34)();
    void (*f38)(struct ChrWork *w, ChrSub *sub, int idx, int x, int y); /* per-entry callback of func_0025B6E8 */
    int f3C;
    ChrSub sub[64];
} ChrWork;

/* DEBT(NAME): guess, object with a state word at 0x28 and a flag byte at 0x45 (pointed to by D_0069BE40.. globals) */
typedef struct StateObj {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0x45 - 0x2C];
    u8 flag;
} StateObj;

/* DEBT(NAME): guess, big global work area (lpamng), only the touched members are described */
typedef struct WorkEnt {
    s16 x;
    s16 y;
    u8 pad04[2];
    u16 f06;
    u8 pad08[2];
    s16 cell;                 /* 0x0A: grid cell from func_002564E8 */
    u8 pad0C[0x21 - 0xC];
    u8 flags;                 /* one bit per channel */
    u8 f22;
    u8 pad23;
    u16 f24;
    u8 pad26[2];
} WorkEnt;

typedef struct WorkEnt2 {
    u16 h0;
    u16 h2;
    u8 pad04[0xA];
    u8 f0E;
    u8 f0F;
    int seed;
} WorkEnt2;

typedef struct WorkEnt3 {
    u16 h0;
    u8 pad2[0x46];
    float f48;
    u8 pad4C[4];
} WorkEnt3;

typedef struct GlobalWork {
    u8 pad0[2];
    s16 count;
    s16 count2;
    u8 pad6[0x808 - 6];
    WorkEnt ents[100];
    u8 pad_ents[0xA808 - 0x808 - 100 * 0x28];
    WorkEnt2 ents2[100];
    u8 pad_ents2[0xF808 - 0xA808 - 100 * 0x14];
    s16 ptsF808[8][2];
    u8 padF828[0x110D4 - 0xF828];
    WorkEnt3 ents3[14];       /* DEBT(NAME): 0x50-byte records, count guessed from the gap up to 0x11558 */
    u8 pad_ents3[0x11558 - 0x110D4 - 14 * 0x50];
    void (*cb_a)(void);       /* 0x11558 */
    void (*cb_b)(void);       /* 0x1155C */
    void (*next_a)(void);     /* 0x11560 */
    void (*next_b)(void);     /* 0x11564 */
    u8 pad11568;
    u8 f11569;
    u8 f1156A;                /* display update busy flag (func_002659F8) */
    u8 f1156B;
    u8 f1156C;
    u8 pad1156D[0x11573 - 0x1156D];
    u8 f11573;
    u8 f11574;
    u8 pad11575[2];
    u8 f11577;
    u8 f11578;
    u8 pad11579[2];
    u8 f1157B;
    u8 f1157C;
    u8 f1157D;
    u8 pad1157E[0x11598 - 0x1157E];
    float f11598;
    u8 pad1159C[0x115D0 - 0x1159C];
    float f115D0;
    float f115D4;
    float f115D8;
    float f115DC;
    u16 f115E0;
    u16 f115E2;
    u16 f115E4;
    u8 pad115E6[2];
    u8 f115E8;
    u8 pad115E9[0x11600 - 0x115E9];
    u8 f11600;
    u8 pad11601[0x11608 - 0x11601];
    s32 f11608;
    s32 f1160C;
    s32 f11610;
    s32 f11614;
    s16 f11618;
    s16 f1161A;
    s32 f1161C;
    u16 f11620;
    u16 f11622;               /* button bits tested by func_00263DE8 */
} GlobalWork;

/* Event/command argument block of func_00251360-style requests */
typedef struct EvtObj {
    int f0;
    u8 b4;
    u8 pad5[3];
    u16 h8;
} EvtObj;

/* DEBT(NAME): guess, system interface table returned by func_00241FC0 */
typedef struct SysIf {
    u8 pad[8];
    void (*fn)(void (*cb)(void), int a, int b);
} SysIf;

/* DEBT(NAME): guess, config block with two bytes at 0x1A/0x1B (D_00327160, D_00327190) */
typedef struct CfgBlock {
    u8 pad[0x1A];
    u8 b1A;
    u8 b1B;
} CfgBlock;

typedef struct Slot80 {
    int f0;
    int f4;
    int f8;
    u8 padC[0x1D - 0xC];
    u8 f1D;
    u16 h1E;                  /* index into D_006EA8B0 (func_002B1D88) */
    u8 pad20[0x30 - 0x20];
    void *objs;               /* 0x30: chain released by _pppAllFreePObject */
    u8 pad34[0x3C - 0x34];
    void *buf;                /* 0x3C: heap block released by _pppAllFreePObject */
    u8 pad40[0x80 - 0x40];
} Slot80;

typedef struct SizeInfo {
    u8 pad0[4];
    u8 *f4;
    u8 *f8;
    u8 pad0C[8];
    u8 *f14;
    u8 *f18;
} SizeInfo;

typedef struct Ent50 {
    u8 pad[0x44];
    u16 f44;
    u16 f46;
    u8 pad48[0x50 - 0x48];
} Ent50;

typedef struct Ent50Tbl {
    u8 pad[4];
    u16 count;
    u8 pad6[0x20 - 6];
    Ent50 ents[1];
} Ent50Tbl;

typedef struct Slot50 {
    u32 flags;
    u8 pad[0x4C];
} Slot50;

typedef struct EntRef {
    u16 a;
    u16 b;
    u8 pad4[4];
    u16 cx;
    u16 cy;
} EntRef;

typedef struct Child {
    u8 pad[0x10];
    void (*fn10)();
    void (*fn14)();
    void (*fn18)();
} Child;

typedef struct ObjGroup {
    u8 pad0[0x14];
    int count;
    u8 pad18[0x34 - 0x18];
    Child **children;
} ObjGroup;

/* DEBT(NAME): guess, system vtable returned by GetCD */
typedef struct SysVt {
    int (*f0)();
    int (*f04)(int);
    int (*f8)();
    u8 padC[4];
    int (*f10)();
    int (*f14)();
    u8 pad18[0x20 - 0x18];
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    u8 pad34[0x54 - 0x34];
    int (*f54)();
    int (*f58)();
    int fd5C;
    int (*f60)();
    u8 pad64[4];
    void (*f68)(void);
    u8 pad6C[0xC];
    int (*f78)();
    u8 pad7C[0xC];
    int (*f88)(int a, int b);
    int (*f8C)(int a);
} SysVt;


/* ======== types from the 0x278000-0x2A0718 event-script VM support (w9) ======== */

/* Fixed-size node pool with an intrusive free list; nodes follow a 0x10 byte header. */
typedef struct PoolNode {
    struct PoolNode *next;
} PoolNode;

typedef struct Pool {
    u8 count;                   /* number of nodes */
    u8 size;                    /* node size selector, see func_00282060 */
    u16 stride;                 /* bytes per node */
    PoolNode *free;             /* head of the free list */
    int pad[2];
} Pool;

/* Index free-list: next[i] chains unused slot indices, 0xFFFF ends the chain. */
typedef struct IdPool {
    u16 *next;
    u16 count;
    u16 head;
} IdPool;

typedef struct Pair {
    void *ptr;
    u8 flag;
} Pair;

/* Script thread (actor) record used by the 0x29xxxx/0x2Axxxx opcode handlers. */
typedef struct ScriptSub {
    int reg[4];
    u8 b10[4];                  /* per-reg byte, cleared with reg[] by opu_task */
    u16 h14;                    /* NAME guess: index into owu_eff_status */
    u8 pad16[2];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[2];
    u8 b1E;                     /* index into ScriptThread.res (opu_vibration) */
    u8 pad1F[1];
    u16 *stk[4];                /* NAME guess: return-address stack; depth guessed (members from 0x30 on are used by 0x29CBD0) */
    float v30[3];               /* NAME guess: vectors/angles handed to the 0x1A7840 family by func_0029CBD0 */
    float f3C;
    float v40[3];
    float f4C;
    u8 pad50[0x40];
    float f90;                  /* NAME guess: position */
    float f94;
    float f98;
    u8 pad9C[0xC];
    union {
        u16 *p;
        int w;
        s16 h;
        s8 b;
        u8 ub[4];               /* two 3-bit fields stored by func_002A4AA0 */
    } a8;                       /* 0xA8: scratch word, accessed at several widths */
    u16 *pAC;                   /* jump target saved by opu_et_ovl */
    u16 hB0;                    /* NAME guess: flag bits tested by the 0x29DD98 family */
    u8 bB2;
    u8 bB3;
    u8 loopcnt[6];              /* NAME guess: loop counters, indexed by flags >> 12 (indices >= 6 run into the next members) */
    u8 bBA;
    u8 bBB;
    void *pBC;
    u16 hC0;
    u16 hC2;
    s16 hC4;
    s16 hC6;
    int wC8;                    /* copied into the draw request by func_002B0178 */
    u8 padCC[0x14];
    int *pE0;                   /* resource entry looked up by func_002A4AA0 */
} ScriptSub;

typedef struct ScriptThread {
    float v00[4];               /* NAME guess: two vectors at the start (func_0029CBD0) */
    float v10[4];
    u8 pad20[0x60];
    float m80[4][4];            /* matrices built by opu_mdmap */
    float mC0[4][4];
    u8 pad100[0x110];
    u8 f210;
    u8 pad211[1];
    s16 h212;
    s16 h214;
    s16 sp;                     /* NAME guess: index into sub->stk */
    s16 h218;
    u16 flags;
    u8 pad21C[2];
    s8 b21E;                    /* NAME guess: nonzero = skip debug output (0x29C598) */
    u8 pad21F[1];
    ScriptSub *sub;
    u8 pad224[0x9C];
    float m2C0[4][4];
    u8 obj300[0x5C];            /* NAME guess: embedded sub-object at 0x300 */
    int h35C;                   /* handle inside the sub-object (func_0029CBD0) */
    int res[4];                 /* 0x360: resource handles indexed by ScriptSub.b1E (count guessed) */
    u8 pad370[0x48];
    u16 h3B8;
} ScriptThread;

typedef struct Counter16 {
    s16 pad;
    s16 n;
} Counter16;

/* Slot table owu_chr_status (0x20 byte records). DEBT(NAME): merged from w9 "ResEntry" (id) and w10 "W10Slot" (ptr).
   The first word is a pointer to the character: func_00110560(Chr *) and Ch_ClutDispose take it directly. */
typedef struct ResEntry {
    Chr *chr;
    int key;
    int w8;
    u16 flags;
    u16 hE;
    u32 color10; /* DEBT(NAME): initialized to packed RGBA 0x80808080. */
    u8 pad14[2];
    u8 b16;
    u8 b17;
    u32 color18; /* DEBT(NAME): same packed color as color10. */
    u8 pad1C[4];
} ResEntry;

/* Script thread slot table (0x20 byte records). */
typedef struct SlotEntry {
    int key;
    ScriptSub *sub;
    u8 b8;
    u8 b9;
    u8 padA[2];
    int wC;
    u8 list[8];                 /* NAME guess: id list, b8 = count */
    u8 b18;
    u8 pad19[3];
    u8 b1C;
    u8 b1D;
    u8 pad1E[2];
} SlotEntry;

/* NAME guess: small handle pools at D_00703E20 */
typedef struct HandlePool {
    int cur;                    /* 0x00 */
    int pad4;
    int w8;                     /* 0x08 */
    u8 flags[4];                /* 0x0C */
    int a[4];                   /* 0x10 */
    u8 pad20[0x20];
    int b[8];                   /* 0x40 */
    u8 b60[4];
    u8 pad64[4];
    u8 b68[4];                  /* 0x68 */
    s8 b6C[4];                  /* 0x6C: per-handle level byte tested by opu_et_etc */
} HandlePool;

typedef struct PtrSlots {
    void *objs[32];             /* NAME guess: pending request queue (ring) */
    int args[32];
    u16 head;
    u16 count;
    u8 pad104[4];
    void *slot[2];
} PtrSlots;

/* NAME guess: 0x2008250 region, read by the key/pad input code */
typedef struct HwRegs2008250 {
    u8 pad0[2];
    s8 b2;                      /* tested by func_00293570 */
    u8 pad3[0x3D];
    u16 h40;
    u8 pad42[0x3E];
    int w80;
    u8 pad84[0x14];
    int w98;
    u8 pad9C[0x20];
    int wBC;                    /* passed with w98 by op_et_encount_effect_on */
} HwRegs2008250;

/* NAME guess: linked list of attached objects, see func_002803C0 */
typedef struct LinkNode {
    u8 pad0[8];
    struct LinkNode *next;
    int wC;
    u8 pad10[0x2E];
    u16 h3E;
} LinkNode;

typedef struct LinkOwner {
    u8 pad0[0x18];
    LinkNode *head;
} LinkOwner;

typedef struct ObjTable {   /* list head of ListNode entries (func_00266EA0/EB8/EE8) */
    struct ListNode *prev;
    struct ListNode *next;
    u8 pad8[4];
    u16 count;
    u16 hE;
} ObjTable;

typedef struct SysObj {
    u8 pad0[0x320];
    int w320;
} SysObj;

/* D_00703FF0. DEBT(NAME): merged from w9 "SysFlags" (b[1], b[5], h20) and w10 "W10Mgr" (flag8, val9, flagF, buf). */
typedef struct SysFlags {
    u8 b[8];
    u8 flag8;
    u8 val9;
    u8 bA;
    u8 padB[1];
    u16 hC;
    u8 bE;
    u8 flagF;
    u8 buf[0x10];   /* 0x10: passed by address to func_00173650 */
    u16 h20;
    u8 b22;
    u8 b23;
} SysFlags;

/* NAME guess: list of s16 ids (-1 terminated) at +0x1C, capacity count at +0x34 */
typedef struct IdList {
    u8 pad0[0x1C];
    s16 *list;
    u8 pad20[0x14];
    u16 count;
} IdList;

/* Message passed to the attach-style opcode handlers. */
typedef struct ScriptMsg {
    int id;
    int idx;
} ScriptMsg;

typedef struct PtKey {      /* one frame of a particle animation */
    u8 pad0[2];
    s16 dur;
    s8 flags;               /* 0x80: loop */
    u8 pad5[3];
} PtKey;

typedef struct Particle {   /* 0xA0 bytes */
    u32 flags;              /* bit 0: alive */
    u16 time;
    u16 frame;
    u32 age;
    u8 padC[4];
    Vec4 v10;
    Vec4 vel;
    Vec4 pos;
    Vec4 acc;
    u8 pad50[0x50];
} Particle;

typedef struct DataRef {
    u8 pad0[6];
    s16 frames;
    u8 pad8[8];
    PtKey keys[1];
} DataRef, PtAnim;

typedef struct T6_PKey {
    u8 pad0[4];
    u32 id;
    int count;
    union {                 /* DEBT(TYPE): union guessed; the load must alias the float stores */
        u16 h;
        float f;
    } speed;
    u8 pad10[0x40];
    Vec4 velB;
    Vec4 vel;
    u8 pad70[0x20];
    Vec4 accB;
    Vec4 acc;
} T6_PKey, PtEmitter, PtEmitterB;

typedef struct T6_PRec { u16 h[4]; } T6_PRec;

typedef struct T6_PSysW {
    u8 pad0[0x40];
    Particle *parts;            /* 0xA0-byte particles, flag word first */
    void *aux;
    int w48;
    int w4C;
    T6_PRec *rec;
    u32 nrec;
    int done;
} T6_PSysW, PtOwner;

typedef struct T6_PSysB {
    u8 pad0[0x40];
    Particle *parts;
    int w44;
    int w48;
    T6_PRec *rec;
    u32 nrec;
    int done;
} T6_PSysB, PtOwnerB;

/* Heap manager object at D_006A3924. DEBT(NAME): merged from w3 "W3Heap" (sub allocator at +0x10, passed by address
   to pppMemAlloc/func_00267028) and w9 "DataCache" (tbl at +0x24); the unused w8 "HeapHead" guess is dropped. */
typedef struct HeapMgr {
    u8 pad00[0x10];
    u8 sub[0x10];
    struct T6_LtRes *res;
    DataRef **tbl;
    struct T6_LtGrp *grp;
} HeapMgr;

typedef struct AttachWork {
    void *ref;
    DataRef **cur;
    u16 h8;
    union {
        u16 h;
        u8 b;
    } a;                        /* 0xA, accessed as byte or halfword */
    u16 hC;
    u8 bE;
} AttachWork;

/* NAME guess: attach message with extra fields, see func_0028B758 */
typedef struct AttachMsg {
    int id;
    int idx;
    u8 pad8[8];
    u16 h10;
    u16 h12;
    u8 pad14[2];
    u8 b16;
    u8 b17;
} AttachMsg;

/* NAME guess: event-trigger message, two layouts (A used by 0x284A60, B by 0x284C50) */
typedef struct EvMsgA {
    u8 pad0[4];
    s16 h4;
    u8 pad6[6];
    u8 bC;
    u8 bD;
    u8 bE;
    u8 padF;
    u32 w10;
    u8 pad14[4];
    u32 w18;
} EvMsgA;

typedef struct EvMsgB {
    u8 pad0[4];
    s16 h4;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 pad9[3];
    u32 wC;
    u8 pad10[4];
    u32 w14;
} EvMsgB;

/* NAME guess: event message, third layout (used by 0x2859B8) */
typedef struct EvMsgC {
    u8 pad0[8];
    u32 w8;
    u8 padC[4];
    u32 w10;
} EvMsgC;

typedef struct IntBox { int pad[2]; int v8; } IntBox;

typedef struct HalfBox { short pad; short v2; } HalfBox;

typedef struct PtrHolder8 { u8 type; u8 pad[7]; IntBox *p8; } PtrHolder8;

typedef struct PtrHolderC { int pad[3]; HalfBox *pC; } PtrHolderC;


/* ======== types from the 0x2A1778-0x2D6260 (w10) ======== */

/* Globals and prototypes for chunks c_2A1778 .. c_2D6260 (worker 10). */

/* ---- c_2D6260: small slot/flag manager (module name unknown) ---- */
typedef struct W10Evt {     /* DEBT(NAME): guessed; pairs of (current, pending) flag words */
    u32 cur;
    u32 pend;
    u32 w8;
} W10Evt;

typedef struct W10PadInfo {     /* DEBT(NAME): unknown 0x20-byte per-slot record */
    u8 data[0x20];
} W10PadInfo;

/* DEBT(NAME): pad structs (name and member names are guesses from usage; sizes 0x20 / 0xC0 are certain) */
typedef struct W10PadEnt {      /* one ring-buffer sample */
    u8 kind;        /* 0 */
    u8 id1;         /* 1 */
    u16 w2;
    u16 w4;
    u16 w6;
    u16 w8;
    u16 wA;
    u8 axes[16];    /* C: 0x80 = neutral */
    u16 w1C;
    u16 w1E;
} W10PadEnt;

typedef struct W10Pad {
    W10PadEnt ring[4];  /* 00 */
    u8 stat[4];     /* 80 */
    u8 axes[16];    /* 84 */
    u8 pad94[8];
    u8 head;        /* 9C: index of newest ring entry */
    u8 active;      /* 9D */
    u8 pad9E;
    u8 type;        /* 9F */
    u8 padA0[0x10];
    u8 out[6];      /* B0 */
    u8 shift[2];    /* B6 */
    u8 res[6];      /* B8 */
    u8 val[2];      /* BE */
} W10Pad;

/* ---- c_2D5180: event flag sets / command queue (module name unknown) ---- */


typedef struct W10Cmd {     /* DEBT(NAME): guessed; entry of the 17-slot queue at D_0078BAE0 */
    s16 id;
    s16 val;
    s32 arg;
} W10Cmd;

typedef struct ThreadParam {    /* EE kernel ThreadParam (sceThreadParam layout) */
    s32 status;
    void (*entry)(void *);
    void *stack;
    s32 stackSize;
    void *gpReg;
    s32 initPriority;
    s32 currentPriority;
    u32 attr;
    u32 option;
    s32 waitType;
    s32 waitId;
    s32 wakeupCount;
} ThreadParam;

typedef struct SemaParam {      /* EE kernel SemaParam (sceSemaParam layout) */
    s32 currentCount;
    s32 maxCount;
    s32 initCount;
    s32 numWaitThreads;
    s32 attr;
    s32 option;
} SemaParam;

/* ---- c_2B24F8: timed callback queue (4 banks of 0x20 entries) + DMA helpers ---- */
typedef struct W10Callback {    /* DEBT(NAME): guessed; 16-byte record */
    void (*fn)(s32, s32);
    s32 arg0;
    s32 arg1;
    u16 count;      /* remaining runs, 0 = unlimited */
    u16 pad;
} W10Callback;

typedef struct W10Actor {
    u8 pad00[0x19];
    u8 flags19;
    u8 pad1A[0x8E];
    s16 hA8;
    u8 padAA[0xE];
    u16 hB8;
    u8 padBA;
    u8 bBB;
} W10Actor;

typedef struct W10Ctx {
    u8 pad000[0x214];
    s16 h214;
    u8 pad216[4];
    s16 h21A;
    u8 pad21C[4];
    W10Actor *actor;        /* 220 */
    u8 pad224[0xDC];
    IdList list300;
} W10Ctx;

/* DEBT(NAME): dual-output (primary/mirror) sound/debug dispatcher flags, guessed */
typedef struct W10Dual { u8 pad0[0x10]; s8 mirror; u8 pad11[3]; s8 primary; s8 mode15; } W10Dual;


/* ======== types from the 0x2D5000-0x2FFFFF sound wrappers, soft float and libc (w11) ======== */

/*
 * Soft-float support (libgcc fp-bit.c, double flavour) linked into the game.
 * Layout matches libgcc 2.95: struct fp_number_type, FLO_union_type.
 */
typedef unsigned long long fractype;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        fractype ll;
        unsigned int l[2];
    } fraction;
} fp_number_type;

typedef union {
    double value;
    fractype value_raw;
    struct {
        fractype fraction : 52;
        unsigned int exp : 11;
        unsigned int sign : 1;
    } bits;
} FLO_union_type;

typedef union {
    float value;
    unsigned int value_raw;
    struct {
        unsigned int fraction : 23 __attribute__((packed));
        unsigned int exp : 8 __attribute__((packed));
        unsigned int sign : 1 __attribute__((packed));
    } bits;
} FLO_union_sf;

/* single precision flavour of the same library */
typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        unsigned int ll;
    } fraction;
} fp_number_sf;

/*
 * newlib 1.x pieces (libc area 0x2ED000-0x2F2300): struct _reent and friends.
 * DEBT(PADDING): only the members used by the matched functions are named.
 */
typedef struct W11File {
    u8 *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    u8 *_bf_base;
    int _bf_size;
    int _lbfsize;
    void *_cookie;
    void *_read;
    void *_write;
    void *_seek;
    void *_close;
    u8 *_ub_base;
    int _ub_size;
    u8 *_up;
    int _ur;
    u8 _ubuf[3];
    u8 _nbuf[1];
    u8 *_lb_base;
    int _lb_size;
    int _blksize;
    int _offset;
    struct W11Reent *_cookie54; /* DEBT(NAME): newlib _data (reent pointer) */
} W11File; /* newlib FILE, 0x58 bytes */

typedef struct W11Bigint {
    struct W11Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    u32 _x[1];
} W11Bigint; /* newlib Bigint (dtoa/strtod) */

struct W11Glue {
    struct W11Glue *_next;
    int _niobs;
    W11File *_iobs;
};

typedef struct W11Reent {
    int _errno;
    void *_stdin;
    W11File *_stdout;
    u8 pad0[0x30 - 0xC];
    int _current_category;
    const char *_current_locale;
    int __sdidinit;
    void (*__cleanup)(struct W11Reent *);
    struct W11Bigint *_result;
    int _result_k;
    struct W11Bigint *_p5s;
    W11Bigint **_freelist;
    u8 pad0b[0x58 - 0x50];
    u32 _rand_next;
    char *_strtok_last;
    u8 pad1[0x1D8 - 0x60];
    struct W11Glue __sglue;
    W11File __sf[3];
} W11Reent;

/* DEBT(NAME): ring buffer layout inferred from func_002F96D0/func_002F9710 */
typedef struct W11Ring {
    int size;
    int count;
    char *rd;
    char *wr;
    char data[1];
} W11Ring;

typedef struct {
    int w0;
    u8 *base;
    int cols;
    int rows;
} W11Grid;

/* DEBT(PADDING)/DEBT(NAME): layout inferred from two accessors only */
typedef struct {
    u8 pad0[0x10];
    int idx;
    int val;
} W11SlotSrc;

typedef struct {
    u8 pad0[8];
    int out;
    u8 pad1[0x1C - 0xC];
    int *tbl;
} W11SlotDst;

/* 16-byte command record (type 0x70 in b3) */
typedef struct CmdRec {
    s16 w0;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    s32 wC;
} CmdRec;

typedef struct Rec0E {
    s16 h0;
    u16 h2;
    s16 h4;
    s16 h6;
    u8 pad8[2];
    s8 b0A;
    u8 pad0B[3];
} Rec0E;
extern Rec0E D_006930B8[];

/* 8-byte entry of the D_00692928 queue (4 entries); DEBT(NAME): fields named by offset */
typedef struct Ent8 { s16 h0; s16 h2; s16 h4; s16 h6; } Ent8;

/* Object with a vtable-like pointer at +0 (D_006EA450), second word cleared. */
typedef struct R6VObj {
    void *vt;
    int w4;
    u8 pad8[1];
    u8 b9;
} R6VObj;

/* One 16-byte GS/DMA packet quadword. It is a union because the display-list code writes it through the union
 * members, which keeps the stores ordered against the InvokedFromSelectCursor cursor updates (alias set 0 in ee-gcc 2.9). */
typedef union Qword {
    u_long128 ul128;
    u64 ul64[2];
    u32 ui32[4];
} Qword;

/* Menu command object, one per slot of D_00668740 (state machine driven through the
   handler slots h[]). DEBT(NAME): member names are guesses from use. */
typedef s32 (*MenuFn)();
typedef struct MenuCmd {
    /* 0x00 */ s16 w00;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 id;
    /* 0x06 */ u8 pad06[0x08 - 0x06];
    /* 0x08 */ s32 x08;
    /* 0x0C */ s16 h0C;
    /* 0x0E */ u8 pad0E[2];
    /* 0x10 */ u16 h10;
    /* 0x12 */ s16 w12;
    /* 0x14 */ s16 h14;
    /* 0x16 */ s16 h16;
    /* 0x18 */ s16 h18;
    /* 0x1A */ s16 h1A;
    /* 0x1C */ s16 w1C;
    /* 0x1E */ s16 w1E;
    /* 0x20 */ u8 pad20[0x2C - 0x20];
    /* 0x2C */ s16 state;
    /* 0x2E */ s16 sub;
    /* 0x30 */ s16 x;
    /* 0x32 */ s16 y;
    /* 0x34 */ s16 x1;
    /* 0x36 */ s16 y1;
    /* 0x38 */ s16 w;
    /* 0x3A */ s16 h;
    /* 0x3C */ s16 h3C;
    /* 0x3E */ s16 h3E;
    /* 0x40 */ u8 pad40[0x4B - 0x40];
    /* 0x4B */ u8 b4B;
    /* 0x4C */ u8 pad4C[0x84 - 0x4C];
    /* 0x84 */ s32 x84;
    /* 0x88 */ u8 *text;
    /* 0x8C */ s32 x8C;
    /* 0x90 */ s32 x90;
    /* 0x94 */ s32 x94;
    /* 0x98 */ s32 x98;
    /* 0x9C */ s32 x9C;
    /* 0xA0 */ u8 padA0[0xA4 - 0xA0];
    /* 0xA4 */ s32 xA4;
    /* 0xA8 */ u8 padA8[0xD0 - 0xA8];
    /* 0xD0 */ struct SlotZ *slot;
    /* 0xD4 */ MenuFn fD4;
    /* 0xD8 */ MenuFn fD8;
    /* 0xDC */ MenuFn fDC;
    /* 0xE0 */ MenuFn fn[10];
    /* 0x108 */ MenuFn f108;
    /* 0x10C */ MenuFn f10C;
} MenuCmd;

/* Smaller menu slot object of D_0066B508. */
typedef struct MenuSlot {
    /* 0x00 */ s16 w00;
    /* 0x02 */ s16 h2;
    /* 0x04 */ s16 w04;
    /* 0x06 */ s16 w06;
    /* 0x08 */ s16 state;
    /* 0x0A */ u8 pad0A[0x10 - 0x0A];
    /* 0x10 */ s16 w;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ s16 h;
    /* 0x16 */ u8 pad16[0x1E - 0x16];
    /* 0x1E */ s16 x;
    /* 0x20 */ s16 y;
    /* 0x22 */ s16 x1;
    /* 0x24 */ s16 y1;
    /* 0x26 */ u8 pad26[0x2E - 0x26];
    /* 0x2E */ s16 h2E;
    /* 0x30 */ s16 h30;
    /* 0x32 */ s16 h32;
    /* 0x34 */ s16 h34;
    /* 0x36 */ u8 b36;
    /* 0x37 */ u8 b37;
    /* 0x38 */ u8 b38;
    /* 0x39 */ u8 b39;
    /* 0x3A */ u8 pad3A[0x40 - 0x3A];
    /* 0x40 */ MenuFn fn[7];
} MenuSlot;

/* Slot object of D_00669AE0. DEBT(NAME): member names are offsets. */
typedef struct SlotZ {
    /* 0x00 */ s8 b0;
    /* 0x01 */ s8 b1;
    /* 0x02 */ s8 b2;
    /* 0x03 */ s8 b3;
    /* 0x04 */ s8 b4;
    /* 0x05 */ s8 b5;
    /* 0x06 */ s8 b6;
    /* 0x07 */ s8 b7;
    /* 0x08 */ u8 pad08[4];
    /* 0x0C */ s32 wC;
    /* 0x10 */ s32 w10;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ u8 x18[8];
    /* 0x20 */ u8 pad20[0x38 - 0x20];
    /* 0x38 */ struct { s16 h0; s16 h2; s16 h4; s16 h6; } ent[1]; /* DEBT(TYPE): count unknown, indexed up to b5 */
} SlotZ;

typedef struct R4Ptrs {
    s16 w00;
    u8 pad02[2];
    s16 w04;
    s16 w06;
    s16 h8;
    s16 hA;
    s16 hC;
    u8 pad0E[2];
    MenuSlot *p10;
    MenuCmd *p14;
    SlotZ *p18;
} R4Ptrs;

#endif /* FFX_TYPES_H */
