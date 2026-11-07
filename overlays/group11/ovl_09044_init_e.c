#include "p1_overlay.h"

/* Resident types needed by this unit (declared locally to avoid conflicts with the
 * p1 package's own provisional declarations). */

/* r6.h R6Obj view, restricted to the fields used here. */
typedef struct OvlR6Obj {
    u8 pad00[0x54];
    int w54;
    int w58;
    u8 pad5C[0x44];
    int wA0;            /* 0xA0 */
    u8 padA4[4];
    union {
        u32 w;
        void *p;
    } a8;               /* 0xA8 */
    void *pAC;          /* 0xAC */
    int wB0;
} OvlR6Obj;

typedef struct OvlHandlePool {
    u8 pad00[4];
    void *p04;
} OvlHandlePool;

typedef struct OvlHwRegs {
    u8 pad00[0x40];
    u16 h40;
    u8 pad42[0x66];
    int wA8;
} OvlHwRegs;

typedef struct OvlW10Dual {
    u8 pad00[0x10];
    s8 primary;
    s8 mirror;
    u8 pad12[2];
} OvlW10Dual;

typedef struct OvlThread {   /* ScriptThread fields used here */
    u8 pad00[0xC];
    int wC;
    u8 pad10[0x44];
    int w50;
    u8 pad54[0x100];
} OvlThread;

typedef struct OvlScriptSub {   /* ScriptSub fields used here */
    u8 pad00[0x1A];
    u16 h1A;
    u8 pad1C[2];
    u8 b1E;
    u8 pad1F[0x31];
    u16 h50;
    u8 pad52[0x4E];
    void *pA0;          /* 0xA0 */
    void *pA4;          /* 0xA4 */
    u8 padA8[0x13];
    u8 bBB;             /* 0xBB */
    void *pBC;          /* 0xBC */
    u8 padC0[0x10];
    void *pD0;          /* 0xD0: resource table */
    u8 bD4;
    u8 padD5[7];
} OvlScriptSub;

extern OvlR6Obj *D_0054D5E8[];
extern OvlR6Obj *D_0054D5EC;
extern OvlHandlePool D_00703E20;
extern void *D_00703E24;
extern OvlHwRegs D_2008250;
extern s8 D_007649A0;
extern OvlW10Dual D_00764990;
extern u16 D_00551C98;
extern u16 D_00551CA0;
extern int D_003F3944;
extern void *D_006A3924;
extern u8 D_004F3FD0[];
extern u8 D_004F4010[];
void func_206C3B8(int a);
void func_206C3F8(int a, int b, int c);
void func_206C440(int a, int b);

/* Package p1 unit: overlay init + ppp shell (file09044 0x01B00438..0x01B00FB0; the same block
 * sits at +0x3E0 in file09335). Data syms are per-container; see overlays/units/p1.py.
 *
 * Data layout (file09044 addresses):
 *   D_01B09EB0[0x40]  0x80-byte ppp slot records (h1E = index)
 *   D_01B09DB0[0x40]  free-list counters
 *   D_01B09BB0[0x40]  id table
 *   D_01B0BEB0        ppp manager (0x2C bytes zeroed, words 0x20/0x24/0x28 from sub)
 *   D_01B00210[0x40]  resource id table
 *   D_01B00260[8]     draw-list pointer records (w08..w38 set from sub words)
 *   D_01B0C520        ppp draw env table
 *   D_01B0CBC0        static ppp object
 */

typedef struct OvlSlot {
    u8 pad00[0x1E];
    u16 h1E;            /* 0x1E: index */
    u8 pad20[0x62];
} OvlSlot;

typedef struct OvlMgr {
    u8 pad00[0x20];
    int w20;            /* cfg words saved by func_01B00F18 */
    int w24;
    int w28;
    u8 pad2C[0x24];
    u16 h50;            /* 0x50 */
} OvlMgr;

extern OvlSlot D_01B09EB0[];
extern u32 D_01B09DB0[];
extern u32 D_01B09BB0[];
extern u32 D_01B00210[];
extern void *D_01B00260[];
extern OvlMgr D_01B0BEB0;
extern u32 D_01B09CB8[];
extern u8 D_01B0C520[];
extern u8 D_01B00000[];
extern char D_01B09B68[];
extern char D_01B09B98[];
extern u8 D_01B0CBC0[];

void func_01B00A78(int a0);
void opu_test_data_read(int a);
int func_00294CD8(int a, int b);
int func_00293CD8(int a);
void func_00293D48(int a, int b);
void func_002AC750(int a);
void func_002B22F8(s32 a, s32 b);
int func_0029A8A8(int a);
void func_001A9EE0(void *a0);
void func_001AACA0(void *a0);
void *opu_init(int a, void *b, void *c, void *d, int e, int f, void *g);
void *op_oef2_a_get(void *res, int type, int idx);
void op_oef2_set2(char *a);

/* 0x01B00DD8 */
void func_01B00DD8(void)
{
}

/* 0x01B00DE0: find the ppp env for sub a0 (-1 = none) */
int func_01B00DE0(OvlScriptSub *sub)
{
    OvlScriptSub *env = D_00703E24;
    int i;

    if (env != 0) {
        for (i = 0; i < env->h50; i++) {
            if (op_oef2_a_get(env, 8, i) == (int)sub) {
                return i;
            }
        }
    }
    return -1;
}
