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
#define D_00703E24 (*(void **)((u8 *)&D_00703E20 + 4))
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

/* 0x01B00438: overlay init */
void func_01B00438(OvlThread *th)
{
    OvlSlot *slot;
    u32 *cnt;
    u32 *tbl;
    int i;
    s16 h;

    func_002B22F8(0x3400, 0x800);
    if (D_007649A0 != 0) {
        h = D_2008250.h40;
        D_2008250.h40 = 0x10;
        opu_test_data_read(1);
        D_2008250.h40 = h;
    }
    *(int *)((u8 *)th + 0x50) = (int)D_01B00000;
    slot = (OvlSlot *)D_01B09EB0;
    cnt = (u32 *)D_01B09DB0;
    for (i = 0; i < 0x40; i++) {
        func_002EF0D0(slot, 0, 0x80);
        slot->h1E = i;
        *cnt = 0;
        slot = (OvlSlot *)((u8 *)slot + 0x80);
        cnt += 1;
    }
    tbl = (u32 *)D_01B09BB0;
    tbl += 0x3F;
    for (i = 0x3F; i >= 0; i--) {
        *tbl = 0;
        tbl = (u32 *)((u8 *)tbl - 4);
    }
    func_002EF0D0(&D_01B0BEB0, 0, 0x2C);
    *(int *)((u8 *)th + 0xC) = (int)((u8 *)th + 0x21200);
}

/* 0x01B00550 */
void func_01B00550(void)
{
    D_0054D5EC = 0;
    D_00764990.mirror = 0;
    if (D_00764990.primary == 0) {
        return;
    }
    func_206C3B8(1);
    func_206C3B8(2);
    func_206C3B8(0x8003);
}

/* 0x01B005A0 */
void func_01B005A0(void)
{
}

/* 0x01B005A8 */
void func_01B005A8(void)
{
    OvlR6Obj *o = D_0054D5EC;
    int mask = *(volatile u32 *)0x10000000 & 0xFFFF;

    if (o->w58 != 0) {
        o->w54 = o->w58;
    } else {
        o->w54 = D_003F3944;
    }
    func_00294CD8(1, 0);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    } else if (o->w54 != o->w58) {
        func_002EF240(D_01B09B68);
        func_002EA328(1);       /* does not return */
    }
    D_00551C98 = *(u32 *)0x10000000 - mask;
}

/* 0x01B00658 */
void func_01B00658(void)
{
    OvlR6Obj *o = D_0054D5EC;
    int mask = *(volatile u32 *)0x10000000 & 0xFFFF;
    int w58;

    if (o->w58 != 0) {
        o->w54 = o->w58;
    } else {
        o->w54 = D_003F3944;
    }
    func_001A9EE0(D_004F3FD0);
    func_001AACA0(D_004F4010);
    func_00294CD8(1, 1);
    func_002AC750(1);
    w58 = o->w58;
    if (w58 == 0) {
        D_003F3944 = o->w54;
    }
    if (D_007649A0 != 0) {
        D_00551CA0 = *(volatile u32 *)0x10000000 - mask;
        if (o->wA0 != 0) {
            func_206C3F8(o->w54 - w58, o->wB0, 1);
            func_206C3F8(func_00293CD8(o->a8.w), o->pAC, 2);
        }
    }
}

/* 0x01B00758 */
void func_01B00758(void)
{
}

/* 0x01B00760 */
void func_01B00760(void)
{
    OvlR6Obj *o = D_0054D5EC;
    int mask = *(volatile u32 *)0x10000000 & 0xFFFF;

    if (o->w58 == 0) {
        o->w54 = D_003F3944;
    }
    func_00294CD8(1, 2);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    }
}

/* 0x01B007C0 */
void func_01B007C0(OvlScriptSub *sub)
{
    OvlMgr *mgr = &D_01B0BEB0;
    int *res;
    u32 key;
    int i;
    int j;

    D_006A3924 = mgr;
    res = sub->pD0;
    mgr->w20 = res[5];
    mgr->w24 = res[6];
    mgr->w28 = res[7];
    key = ((u32)sub->b1E << 16) | sub->h1A;
    for (i = 0; i < 0x40; i++) {
        if (D_01B09DB0[i] == key) {
            break;
        }
    }
    if (i >= 0x40) {
        for (j = 0; j < 0x40; j++) {
            if (D_01B09DB0[j] == 0) {
                break;
            }
        }
        if (j >= 0x40) {
            func_002EF240(D_01B09B98);
            func_002EA328(1);
        }
        i = j;
    }
    D_006A3924 = mgr;
    _pppAllFreePObject((OvlSlot *)((u8 *)D_01B09EB0 + (i << 7)));
    D_01B09DB0[i] = key;
    sub->pBC = (OvlSlot *)((u8 *)D_01B09EB0 + (i << 7));
    _pppStartPart(sub->pBC, 0x1000,
                  ((void **)*(int *)((u8 *)res + 0x10))[sub->bD4], 1);
}

/* 0x01B00958: run + free a ppp part */
int func_01B00958(OvlScriptSub *sub)
{
    OvlMgr *mgr = &D_01B0BEB0;
    OvlSlot *slot = sub->pBC;
    int *res;
    int ret;

    D_006A3924 = mgr;
    res = sub->pD0;
    mgr->w20 = res[5];
    mgr->w24 = res[6];
    mgr->w28 = res[7];
    ret = _pppRunPart(slot, 0x30);
    if (ret != 0) {
        int idx = slot->h1E;

        D_006A3924 = mgr;
        _pppAllFreePObject(slot);
        D_01B09DB0[idx] = 0;
    }
    return ret;
}

/* 0x01B009F8: save the id table to the backup copy, then free all */
void func_01B009F8(void)
{
    u32 *dst = &D_01B09CB8[0];
    u32 *src = &D_01B09BB0[0];
    int i;

    for (i = 0x3F; i >= 0; i--) {
        *dst = *src;
        dst += 1;
        src += 1;
    }
    func_01B00A78(0);
}

/* 0x01B00A38: restore the id table from the backup copy */
void func_01B00A38(void)
{
    u32 *dst = &D_01B09BB0[0];
    u32 *src = &D_01B09CB8[0];
    int i;

    for (i = 0x3F; i >= 0; i--) {
        *dst = *src;
        dst += 1;
        src += 1;
    }
}

/* 0x01B00A78: free every live ppp object */
void func_01B00A78(int a0)
{
    OvlMgr *mgr = &D_01B0BEB0;
    u32 *tbl;
    OvlSlot *slot;
    int i;

    D_006A3924 = mgr;
    tbl = &D_01B09BB0[0x3F];
    for (i = 0x3F; i >= 0; i--) {
        *tbl = 0;
        tbl -= 1;
    }
    slot = D_01B09EB0;
    tbl = D_01B09DB0;
    for (i = 0x3F; i >= 0; i--) {
        if (*tbl != 0) {
            *tbl = 0;
            D_006A3924 = mgr;
            _pppAllFreePObject(slot);
        }
        slot += 1;
        tbl += 1;
    }
}

/* 0x01B00B38: free the ppp object bound to sub a0 */
void func_01B00B38(OvlScriptSub *sub)
{
    if (sub->bBB == 3) {
        OvlSlot *slot = sub->pBC;

        if (slot != 0) {
            int idx;

            D_006A3924 = &D_01B0BEB0;
            _pppAllFreePObject(slot);
            idx = slot->h1E;
            sub->pBC = 0;
            D_01B09DB0[idx] = 0;
            sub->bBB = 0;
        }
    }
}

/* 0x01B00BB0: free every ppp resource of sub a0 */
void func_01B00BB0(OvlScriptSub *sub)
{
    int i = 0;

    if (sub->h50 != 0) {
        do {
            void *o = op_oef2_a_get(sub, 8, i);

            if (o != 0) {
                u32 *tbl = D_01B09BB0;
                int k;

                for (k = 0x3F; k >= 0; k--) {
                    if (*tbl == (u32)o) {
                        *tbl = 0;
                    }
                    tbl += 1;
                }
            }
            i += 1;
        } while (i < sub->h50);
    }
}

/* 0x01B00C58 */
void func_01B00C58(OvlScriptSub *sub)
{
    OvlMgr *mgr = &D_01B0BEB0;

    if (mgr->w20 == 0) {
        pppInitEnv(mgr, 0, sub->pA0, sub->pA4);
        if (D_007649A0 != 0) {
            func_00293D48((int)mgr, 0x8003);
        }
    }
}

/* 0x01B00CC0: fill the D_01B00260 pointer records from sub a1 (base a0) */
void func_01B00CC0(OvlScriptSub *base, OvlScriptSub *sub)
{
    u8 *rec;
    u16 v;

    v = ((u16 *)sub)[2];
    rec = (u8 *)D_01B00260;
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x8) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[3];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0xC) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[4];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x10) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[5];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x14) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[6];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x18) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[7];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x1C) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[8];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x20) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[9];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x24) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[10];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x28) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[11];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x2C) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[12];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x30) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[13];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x34) = (u8 *)base + t;
    }
    v = ((u16 *)sub)[14];
    if (v != 0) {
        int t = v + 0xA0;
        *(void **)(rec + 0x38) = (u8 *)base + t;
    }}

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

/* 0x01B00E60: pick env, init opu and the overlay */
void func_01B00E60(OvlScriptSub *sub)
{
    int env;
    OvlHwRegs *hw = &D_2008250;
    u8 *cbc = D_01B0CBC0;

    D_00703E24 = (D_007649A0 != 0) ? (void *)hw->wA8 : D_01B0C520;
    env = (int)D_00703E24;
    op_oef2_set2(env);
    func_01B00438(opu_init(1, op_oef2_a_get(env, 1, 0), env,
                           (int)cbc, 0x200, 0, (int)sub));
}

/* 0x01B00F18 */
void func_01B00F18(OvlScriptSub *sub)
{
    int *res;
    int idx;

    D_006A3924 = &D_01B0BEB0;
    res = sub->pD0;
    D_01B0BEB0.w20 = res[5];
    D_01B0BEB0.w28 = res[7];
    D_01B0BEB0.w24 = res[6];
    idx = func_01B00DE0(sub);
    if (idx >= 0) {
        if (D_01B09BB0[idx] == 0) {
            D_01B09BB0[idx] = (u32)sub->pD0;
            _pppInitData(sub->pD0, D_01B00210[idx]);
        }
    }
}