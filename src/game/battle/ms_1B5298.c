/* tu_184 0x1b5298-0x1b63b8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

int func_001B5298(u8 id, int v) {
    BtlChr *c;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        c->f1C9.a = c->f1BC.a = v;
        return -1;
    }
    return 0;
}

int MsSetChrMoveFlag(u8 id, int v) {
    if (MsBtlChrNumCheck(id)) {
        MsGetChr(id)->fD2 = v;
        return -1;
    }
    return 0;
}

s8 MsGetChrDist(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f1BF;
    }
    return 0;
}

u8 MsGetChrGroup(int id) {
    if (MsBtlChrNumCheck((u8)id)) {
        return MsGetChr((u8)id)->f1C4 & 7;
    }
    return 0;
}

s8 MsGetChrFly(int id) {
    if (MsBtlChrNumCheck((u8)id)) {
        return MsGetChr((u8)id)->f1C5;
    }
    return 0;
}

float MsGetChrGround(u8 id) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (c->chr != 0) {
            return Ch_GetJimen(c->chr);
        }
    }
    return 0.0f;
}

int MsGetChrEventFlag(int a, int b) {
    int r = 0;
    u8 id = a;
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        u16 v;
        r = c->fA9D;
        v = c->fA9E;
        if (r != 0 && v != 0xFF && v != b) {
            r = 2;
        }
    }
    return r;
}

s8 MsGetChrCursorFlag(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fA99;
    }
    return 0;
}

u8 func_001B5510(u8 id) {
    BtlChr *c;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        if (c->chr != 0) {
            return func_00110B78(c->chr);
        }
    }
    return 0;
}

u8 func_001B5560(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fACC;
    }
    return 0;
}

u8 func_001B55A0(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f27B;
    }
    return 0;
}

u8 MsGetChrLimitGauge(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f27C;
    }
    return 0;
}

s32 MsGetChrMotionSignal(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f5C;
    }
    return 0;
}

u8 MsGetChrLimitGaugeMax(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f27D;
    }
    return 0;
}

int func_001B56A0(int id) {
    return func_001B56E0(id) + func_001B5730(id);
}

int func_001B56E0(int a) {
    int i;
    for (i = 0; i < 18; i++) {
        MsGetChr(i);
        MsSetChrVisible(i, a);
    }
    return 18;
}

int func_001B5730(int a) {
    int i;
    for (i = 0x14; i < 0x1C; i++) {
        MsGetChr(i);
        MsSetChrVisible(i, a);
    }
    return 8;
}

void MsSetChrVisibleCameraAll(int a) {
    int i;
    for (i = 0; i < 0x1F; i++) {
        MsSetChrVisibleCamera(i, a);
    }
}

int func_001B57D0(int a, int b) {
    return func_001B5860(a, 0, b);
}

int func_001B57F0(int a, int b) {
    return func_001B5860(a, 1, b);
}

int MsSetChrVisible(int a, int b) {
    return func_001B5860(a, 2, b);
}

int MsSetChrVisibleCamera(int a, int b) {
    D_0031941E = 1;
    return func_001B5860(a, 3, b);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B5298", func_001B5860);

int MsSetChrVisibleBtl2Event(u8 id, int idx, int v) {
    int r = 0;
    int vis = 1;
    int i;
    BtlChr *c = MsGetChr(id);
    Chr *chr;

    c->f16[idx] = v;
    for (i = 0; i < 4; i++) {
        if (c->f16[i] == 0) {
            vis = 0;
        }
    }
    chr = c->chr;
    if (chr != 0) {
        func_00110738(chr, 0);
        func_00110718(chr, 0);
        if (vis == 0) {
            c->f1B = 0;
            graphicLevelGetNameHash(chr, 1);
        }
        r = 1;
    }
    for (i = 0; i < 2; i++) {
        BtlChr *s = MsGetWeapon(id, i);
        if (s != 0) {
            chr = s->chr;
            if (chr != 0) {
                func_00110738(chr, 0);
                func_00110718(chr, 0);
                if (vis == 0) {
                    graphicLevelGetNameHash(chr, 1);
                }
            }
        }
    }
    return r;
}

int MsSetChrVisibleEvent(u8 id, s32 v) {
    int r = 0;
    int i;
    BtlChr *c;
    c = MsGetChr(id);
    if (c->chr != 0) {
        graphicLevelGetNameHash(c->chr, v);
        r = 1;
    }
    for (i = 0; i < 2; i++) {
        c = MsGetWeapon(id, i);
        if (c != 0 && c->chr != 0) {
            graphicLevelGetNameHash(c->chr, v);
        }
    }
    return r;
}

void MsReturnCameraVisible(void) {
    if (D_003172F0.f212E != 0) {
        D_003172F0.f212E = 0;
        MsSetChrVisibleCameraAll(1);
    }
}

/* DEBT(TYPE): q4.h declares func_00110540 (Chr *, int, float); this file was compiled against the (Chr *, float, int) order of q2.h */
#define V2_SETF(chr, f, b) (((void (*)(Chr *, float, int))func_00110540)(chr, f, b))

int MsSetChrTransparent(int id, float f, int b)
{
    BtlChr *c;
    BtlChr *s;
    int r;
    int i;

    id &= 0xFF;
    r = 0;
    c = MsGetChr(id);
    c->f40 = f;
    if (c->chr != 0) {
        V2_SETF(c->chr, f, b);
        r = 1;
    }
    for (i = 0; i < 2; i++) {
        s = MsGetWeapon(id, i);
        if (s != 0) {
            s->f40 = f;
            if (s->chr != 0) {
                V2_SETF(s->chr, f, b);
            }
        }
    }
    if (c->f100 != 0) {
        for (i = 0; i < 0x1F; i++) {
            if (MsGetChr(i)->fFF == id) {
                MsSetChrTransparent(i, f, b);
            }
        }
    }
    return r;
}

int MsSetChrTransparentVisible(int id, float f1, float f2, int a, int flags)
{
    BtlChr *c;
    BtlChr *s;
    Chr *chr;
    int r;
    int i;

    id &= 0xFF;
    r = 0;
    c = MsGetChr(id);
    chr = c->chr;
    if (chr != 0 && (flags & 1)) {
        c->f40 = f2;
        c->fE3 = 0;
        r = 1;
        func_001B57F0(id, 1);
        V2_SETF(chr, f1, 0);
        V2_SETF(chr, f2, a);
        for (i = 0; i < 2; i++) {
            s = MsGetWeapon(id, i);
            if (s != 0) {
                chr = s->chr;
                s->f40 = f2;
                if (chr != 0) {
                    V2_SETF(chr, f1, 0);
                    V2_SETF(chr, f2, a);
                }
            }
        }
        if (c->f100 != 0) {
            for (i = 0; i < 0x1F; i++) {
                if (MsGetChr(i)->fFF == id) {
                    MsSetChrTransparentVisible(i, f1, f2, a, flags);
                }
            }
        }
    }
    return r;
}

int MsSetChrSpecular(int id, int b, float f)
{
    BtlChr *c;
    BtlChr *s;
    int r;
    int i;

    id &= 0xFF;
    r = 0;
    c = MsGetChr(id);
    if (c->chr != 0) {
        func_00110548(c->chr, f, b);
        r = 1;
    }
    for (i = 0; i < 2; i++) {
        s = MsGetWeapon(id, i);
        if (s != 0 && s->chr != 0) {
            func_00110548(s->chr, f, b);
        }
    }
    if (c->f100 != 0) {
        for (i = 0; i < 0x1F; i++) {
            if (MsGetChr(i)->fFF == id) {
                ((int (*)(int, float, int))MsSetChrSpecular)(i, f, b); /* DEBT(TYPE): recursion evaluated in the (id, f, b) order */
            }
        }
    }
    return r;
}

void func_001B60A8(int a) {
    int i;
    for (i = 0; i < 0x1F; i++) {
        msSetChrBodyHit(MsGetChr(i), 2, a);
    }
}

void func_001B60F8(int mask) {
    int i;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            msSetChrBodyHit(MsGetChr(i), 2, 0);
        }
    }
}

int func_001B6160(u8 id, int b) {
    return msSetChrBodyHit(MsGetChr(id), 2, b);
}

int msSetChrBodyHit(BtlChr *c, int i, int v)
{
    Chr *chr = c->chr;
    int k;
    s8 all;

    if (v >= 0 && i < 4) {
        c->f2E[i] = v;
    }
    all = 1;
    for (k = 0; k < 4; k++) {
        if (c->f2E[k] == 0) {
            all = 0;
            break;
        }
    }
    c->f2D = all;
    if (chr != 0) {
        Ch_EnBodyHit(chr, all);
    }
    return (int)chr;
}

int MsSetChrShadow(int a, int b) {
    return MsSetChrShadowMode(a, 2, b);
}

int MsSetChrShadowMode(int id, int i, int v)
{
    BtlChr *c;
    BtlChr *s;
    int k;

    id &= 0xFF;
    c = MsGetChr(id);
    func_001B6310(c, i, v);
    for (k = 0; k < 2; k++) {
        s = MsGetWeapon(id, k);
        if (s != 0) {
            func_001B6310(s, i, v);
        }
    }
    if (c->f100 != 0) {
        for (k = 0; k < 0x1F; k++) {
            if (MsGetChr(k)->fFF == id) {
                MsSetChrShadowMode(k, i, v);
            }
        }
    }
    return 0;
}

int func_001B6310(BtlChr *c, int i, int v)
{
    Chr *chr = c->chr;
    int k;
    s8 sel;
    s8 mode;

    if (i < 3) {
        c->f26[i] = v;
    }
    sel = 0;
    for (k = 0; k < 3; k++) {
        if (c->f26[k] >= 0) {
            sel = c->f26[k];
            if (sel == 0) {
                break;
            }
        }
    }
    c->f25 = sel;
    mode = c->f2A[sel];
    c->f29 = mode;
    if (chr != 0) {
        func_001108B8(chr, mode);
    }
    return (int)chr;
}
