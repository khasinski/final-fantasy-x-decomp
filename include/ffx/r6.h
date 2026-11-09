#ifndef FFX_R6_H
#define FFX_R6_H

#include "common.h"
#include "ffx/types.h"

extern char D_005737F0[];   /* "%s" */
extern char D_005737F8[];   /* build date string */

/* Object at D_0054D5E8. DEBT(NAME): guessed from field use only. */
typedef struct R6Vt {
    u8 pad0[0x50];
    int (*f50)(int a);
} R6Vt;

typedef struct R6Obj {
    u8 pad0[0x20];
    u_long128 *p20;
    u8 pad24[4];
    int w28;
    int w2C;
    u8 pad30[8];
    u16 h38;
    u8 b3A;
    u8 pad3B[0x15];
    R6Vt *vt50;
    int w54;                    /* saved D_003F3944 (func_002B19C8) */
    int w58;
    u8 pad5C[0xA8 - 0x5C];
    void *pA8;                  /* work buffer set up by opu_et_init */
} R6Obj;

/* Source/destination pair copied by the 0x27BC40 family. DEBT(NAME): guessed */
typedef struct R6Src {
    u8 pad0[8];
    float f8;
    u8 padC[8];
    float f14;
} R6Src;

typedef struct R6Dst {
    R6Src *src;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
} R6Dst;

extern char D_00574D48[];
extern char D_00574D68[];
extern char D_00574CA8[];
extern char D_005753B0[];
extern u8 D_00704012;
extern R6Obj *D_0054D5E8[];

typedef struct R6Hb {       /* DEBT(NAME): small work block, h + b */
    u16 h0;
    u8 b2;
} R6Hb;

typedef struct R6Fvec {
    float x;
    float y;
    float z;
    u8 pad[4];
    int w10;
} R6Fvec;

typedef struct R6Wvec {
    int w0;
    int w4;
    int w8;
    u8 padC[4];
    int w10;
} R6Wvec;

extern u8 D_006EA450[];

void func_00297210(R6Obj *obj, int a);
void func_002973B8(R6Obj *obj, int a);
void func_0027F2E8(R6Hb *dst, DataRef **p);

typedef struct R6Wkw0w1C {
    int w0;
    u8 pad4[0x18];
    int w1C;
} R6Wkw0w1C;

typedef struct R6Wkw68w6Cw70 {
    u8 pad0[0x68];
    int w68;
    int w6C;
    int w70;
} R6Wkw68w6Cw70;

typedef struct R6WkwD0wD4wD8wDC {
    u8 pad0[0xD0];
    int wD0;
    int wD4;
    int wD8;
    int wDC;
} R6WkwD0wD4wD8wDC;


extern char D_005735F8[];   /* "rect_iscroll" */
extern char D_00573670[];   /* "rect_abscroll" */
extern s16 D_0069BEE0[4];
extern s16 D_0069BEE8[4];

/* Script messages (DEBT(NAME): guessed from field use) */
typedef struct R6FMsg {
    int id;
    float f4;
} R6FMsg;

typedef struct R6FMsg2 {
    int id;
    float f4;
    float f8;
} R6FMsg2;

typedef struct R6FMsg3 {
    int id;
    u8 pad4[0xC];
    float f10;
    float f14;
    float f18;
} R6FMsg3;

typedef struct R6FPtr {     /* work area: float + pointer to another work area */
    float f0;
    void *p4;
} R6FPtr;

typedef struct R6TypedObj {
    u8 type;
} R6TypedObj;

typedef struct R6HeapRef1 {
    u8 pad0[0xC];
    void *pC;
} R6HeapRef1;

typedef struct R6HeapRef2 {
    u8 pad0[4];
    void *p4;
} R6HeapRef2;

typedef struct R6VecSrc {
    u8 pad0[0x10];
    float f10;
    float f14;
    float f18;
} R6VecSrc;

typedef struct R6VecSrcI {
    u8 pad0[0x10];
    int w10;
    int w14;
    int w18;
} R6VecSrcI;

typedef struct R6VecSub {
    float f0;
    float f4;
    float f8;
    u8 padC[4];
    R6VecSrc *p10;
} R6VecSub;

typedef struct R6VecSubI {
    int w0;
    int w4;
    int w8;
    u8 padC[4];
    R6VecSrcI *p10;
} R6VecSubI;

typedef struct R6Dump {     /* record printed by func_00256EB8. DEBT(NAME): guessed */
    u16 h0;
    u8 pad2[2];
    u16 h4;
    u8 pad6[2];
    u16 h8;
    u8 padA[2];
    u16 hC;
    u8 padE[2];
    u16 h10;
    u16 h12;
    u8 b14;
    u8 b15;
    u8 b16;
} R6Dump;
extern char D_00573900[];

typedef struct R6Fb {       /* work area: byte flags at +0x22, request bits at +0x10 / word at +0xC */
    u8 pad0[0x22];
    u8 b22;
} R6Fb;

typedef struct R6Req {
    u8 pad0[0xC];
    int wC;
    u8 b10;
} R6Req;

typedef struct R6Ptr0 { void *p0; } R6Ptr0;

typedef struct R6FPPtr {
    float f0;
    float f4;
    void *p8;
} R6FPPtr;

void func_002607D8(int a, int b);

typedef struct R6Ent8 { int w0; int w4; } R6Ent8;
extern R6Ent8 D_006EA550[32];

typedef struct R6W8 { u8 pad0[8]; int *p8; int hC; } R6W8;

/* Request block built on the stack by the 0x28C310 family. DEBT(NAME): guessed */
typedef struct R6Req5 {
    void *self;
    int w4;
    void *tbl;
    float fC;
    void *sub;
} R6Req5;
typedef struct R6Req6 {
    void *self;
    int w4;
    void *tbl;
    float fC;
    float f10;
    void *sub;
} R6Req6;
typedef struct R6EmitA {    /* DEBT(NAME): object handed to func_0027FD60 */
    u8 pad0[0x10];
    u8 sub[0x20];
    float f30;
    int w34;
} R6EmitA;
typedef struct R6EmitB {    /* DEBT(NAME): object handed to func_0027F960 */
    u8 pad0[0x30];
    u8 sub[0x20];
    float f50;
    float f54;
    int w58;
} R6EmitB;
extern u8 D_006A3A70[];
void func_0027FD60(void *req, int n);
void func_0027F960(void *req, int n);



extern char D_00574D08[];
extern char D_00573F98[];
extern char D_00573FA8[];
extern char D_005741D0[];
void op_mdc_mem_transfer_cue_free_all(void);

typedef struct R6Link { struct R6Link *next; } R6Link;

typedef struct R6Blk {      /* DEBT(NAME): heap block header printed by pppDumpHeap */
    struct R6Blk *next;
    int w4;
    int w8;
} R6Blk;
typedef struct R6BlkHead { u8 pad0[4]; R6Blk *first; } R6BlkHead;

typedef struct R6Mtx40 {    /* work area with a matrix at +0x10 and a vector at +0x40 */
    u8 pad0[0x10];
    u8 m[0x30];
    float f40;
    float f44;
    float f48;
} R6Mtx40;

void func_206C440(int a, int b);

typedef struct R6Vec3 { float x; float y; float z; } R6Vec3;

typedef struct R6Th300 {    /* embedded object at ScriptThread.obj300 */
    int w0;
    u32 flags4;
} R6Th300;
#define R6_TH300(th) ((R6Th300 *)(th)->obj300)

/* jump with the byte offset in operand n. DEBT(CAST): byte arithmetic on a u16 stream */
#define SCRIPT_JUMP_AT(pc, n) ((u16 *)((char *)(pc) + (s16)(pc)[n]))

extern R6Vec3 D_0054B7C0;
void func_0029D9C0(ScriptThread *th, ScriptSub *sub, u16 *target);

#endif
