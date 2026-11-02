#ifndef FFX_G2_H
#define FFX_G2_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Declarations for Gemini batch slice 2 (#44..#61). */

static inline W3Core *G2_GetCore(void) {
    return g_pMainWork != 0 ? g_pMainWork->core : 0;
}

static inline W3Pool *G2_GetPool(void) {
    W3Core *c;
    W3Pool *p;

    if (g_pMainWork != 0) {
        if (g_pMainWork->core) {
            c = g_pMainWork->core;
            p = c ? c->pool : (W3Pool *)c;
        } else {
            c = g_pMainWork->core;
            p = c ? c->pool : (W3Pool *)c;
        }
    } else {
        p = 0;
    }
    return p;
}

void func_00194C18(int id);

typedef struct G2Sub90 {
    u32 flags;
    s16 h4;
    s16 h6;
    s32 n;
    s16 hC, hE, h10, h12;
} G2Sub90;

void *rcfxWindNew(void);
int func_001AAAB0(u32 idx, int b);
int func_001AE5D8(void);
#ifndef FFX_R3_H
int MsBattleLabelExe(int a, int b, int c);
#endif

typedef struct G2Hdr1B1B {
    u8 b0;
    u8 count;
    u8 map[1];
} G2Hdr1B1B;

typedef struct G2Ent1B1B {
    u8 b0;
    u8 b1;
    s16 off;
} G2Ent1B1B;

void *func_001B1BD8(G2Hdr1B1B *p, int idx, int *out);
int MsGetChrEventFlag(int a, int b);
int func_001B93E8(int id, int n);
void func_001BCE30(void);
int MsSetSaveCommandUse(int id, int cmd, int on);
int MsGetSaveCommandUse(int id, int cmd);
int func_001CCD38(int a, int b);
int MsEffectMotionLevel(int arg);
void func_001CEAD8(int a);
int MsImportantGet(int i);
#ifndef FFX_U2_H
int MsSystemMessageOpen(int a);
#endif

#endif
