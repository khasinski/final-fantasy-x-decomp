/* tu_199 0x1d2170-0x1d27c0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

/* DEBT(CAST) */
s32 func_001D2170(BtlChr *c) {
    s32 var_18;
    u8 temp_17;

    var_18 = 0;
    if (c->fFF == 0xFF) {
        if (((c->fA8C != 2) && (c->fA8E == 0) && (((*(s32 *)((u8 *)(c) + (0xA88))) & 0xFF0000FF) || (c->fB9 != 0))) || (((*(s32 *)((u8 *)(c) + (0xAA4))) & 0xFFFF0000) && ((temp_17 = c->f0C, (func_001D9780((s32) temp_17) != 0)) || (func_001D8CD0((s32) temp_17) != 0)))) {
            var_18 = 1;
        }
        if (var_18 != 0) {
            if (c->f38 != 0) {
                if (c->fFE == 0) {
                    if (c->fE6 == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void MsMotionPosCheckAll(void)
{
    int i;

    for (i = 0; i < 31; i++) {
        func_001D2298(i, MsGetChr(i));
    }
}

void func_001D2298(int id, BtlChr *c)
{
    if (func_001D2170(c)) {
        c->f1C8 = MsCheckBtlPos(id, c, c->f34);
    } else {
        c->f1C8 = 0;
    }
}

void MsMotionProcess(void) {
    BtlChr *c;
    int i;
    int k;
    int n;

    for (i = 0; i < 31; i++) {
        c = MsGetChr(i);
        if (c->chr != 0) {
            MsCalcMotionSpeed(c);
        }
        k = c->fB2;
        if (c->fF2 != 0) {
            continue;
        }
        if (k != 0xFF) {
            c->fB2 = 0xFF;
            MsSetMotion(i, k, 0, 0, 1, 0, 0);
            continue;
        }
        if (c->fD2 != 0 || c->fD5 != 0) {
            continue;
        }
        n = c->fE8;
        if (c->f1C8 != 0) {
            if (!func_001D2420(i, c)) {
                continue;
            }
            if (n < 2) {
                if (++c->fE7 >= 4) {
                    c->fE7 = 0;
                    msSetChrBodyHit(c, 2, 0);
                }
            } else {
                c->fE7 = 0;
            }
            c->fE8 = 0;
            MsSetMotion(i, 0, 0, 0, 1, 0, 0);
        } else if (n < 2) {
            c->fE8 = n + 1;
        }
    }
}

int func_001D2420(int id, BtlChr *c) {
    float pos1[4];
    float pos2[4];
    int r = -1;
    int check = 1;

    if (c->fAB0 != 0 || ((D_003172F0.f2004 >> id) & 1) || (D_003172F0.f14 != 0 && D_003172F0.f1511 == 0) || D_003172F0.f10 == 0x1B) {
        check = 0;
    }
    if (check != 0) {
        int i;
        float w1 = MsGetChrWidth(id);
        MsGetChrBtlPos(id, pos1);
        for (i = 0; i < 28; i++) {
            BtlChr *t = MsGetChr(i);
            if (t->chr != 0 && t->f2D != 0 && id != i) {
                float w = MsGetChrWidth(i) + w1;
                func_001B6790(i, pos2);
                if (func_001AC348(pos1, pos2) < w) {
                    r = 0;
                    D_003172F0.f2138 = i;
                    D_003172F0.f2139 = 0xFC;
                    break;
                }
            }
        }
    }
    return r;
}

void MsSetBtlPosReset(int id) {
    float v[4];
    BtlChr *c = MsGetChr(id);
    MsSetChrDirF(id, c->f1D4[(s8)c->f1D1]);
    MsGetChrBtlPos(id, v);
    MsSetChrPosReset(id, v);
}

void func_001D25E0(void) {
    BtlChr *c;
    Chr *chr;
    Chr *d;
    int i;
    int k;

    for (i = 0; i < 31; i++) {
        c = MsGetChr(i);
        chr = c->chr;
        if (c->f10 != 0 || c->f12 != 0) {
            if (chr != 0 && c->fFF != 0xFF) {
                Ch_BindToElem(chr, MsGetChr(c->fFF)->chr, c->f101);
            }
            func_001D2958(i);
        }
        if (c->fF9 != 0) {
            if (--c->fF9 == 0) {
                k = c->fF8;
                if (k == 0xFF) {
                    Ch_NeckSetEnable(chr, 0);
                } else {
                    d = MsGetChr(k)->chr;
                    if (chr != 0 && d != 0 && func_001D26F8(c)) {
                        Ch_NeckSetTarget(chr, (s32)d);
                    }
                }
            }
        }
    }
}

int func_001D26F8(BtlChr *c)
{
    int r = -1;
    u8 t = c->fB0;

    if ((t >= 0x20 && t < 0x25) || (t >= 0x48 && t < 0x4D)) {
        r = 0;
    }
    return r;
}

int MsCheckBtlPos(int id, BtlChr *c, int flag) {
    float p[3];
    float q[3];
    float d;
    func_001B6790(id, p);
    MsGetChrBtlPos(id, q);
    if (flag != 0) {
        d = func_001AC348(p, q);
    } else {
        d = func_001AC388(p, q);
    }
    if (d < c->f1B0) {
        return 0;
    }
    return 1;
}
