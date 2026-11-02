/* tu_185 0x1b63b8-0x1b72f0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

/* DEBT(TYPE): q4.h declares func_00110540 (Chr *, int, float); this file was compiled against the (Chr *, float, int) order of q2.h */
#define V2_SETF(chr, f, b) (((void (*)(Chr *, float, int))func_00110540)(chr, f, b))

float MsGetChrHeight(int id) {
    u8 i = id;
    float r = 0.0f;
    BtlChr *c = MsGetChr(i);
    if (c->chr != 0) {
        r = Ch_GetFixHeight(c->chr) * c->f64;
    }
    return r;
}

float MsGetChrWidth(int id) {
    u8 i = id;
    float r = 0.0f;
    BtlChr *c = MsGetChr(i);
    if (c->chr != 0) {
        r = c->f1A4 * c->f68;
    }
    return r;
}

float MsGetChrCamWidth(int id) {
    u8 i = id;
    float r = 0.0f;
    BtlChr *c = MsGetChr(i);
    if (c->chr != 0) {
        r = func_00110950(c->chr) * c->f68;
    }
    return r;
}

float MsGetChrCamHeight(int id) {
    u8 i = id;
    float r = 0.0f;
    BtlChr *c = MsGetChr(i);
    if (c->chr != 0) {
        r = func_00110980(c->chr) * c->f64;
    }
    return r;
}

int MsGetChrStatDeath(int id) {
    id &= 0xFF;
    if (MsBtlChrNumCheck(id) && MsGetChr(id)->fA8C != 0) {
        return 1;
    }
    return 0;
}

int MsGetChrStatPoison(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return (MsGetChr(id)->f2C6 >> 3) & 1;
    }
    return 0;
}

s8 MsGetChrStatStone(int id) {
    id &= 0xFF;
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fA8E;
    }
    return 0;
}

int func_001B65D8(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return (MsGetChr(id)->f2C6 >> 1) & 1;
    }
    return 0;
}

u8 func_001B6620(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f2FD;
    }
    return 0;
}

void func_001B6660(BtlChr *c, float *out) {
    if (c->fFF != 0xFF) {
        Chr *t = MsGetChrHandle(c->fFF);
        if (t) {
            Ch_OptposGet(t, c->f101, out);
        }
    } else {
        MsGetChrBtlPos(c->f0C, out);
    }
}

void func_001B66E0(BtlChr *c, float *v) {
    Chr *chr = c->chr;
    BtlChr *t = 0;
    int id = c->fFF;
    if (id != 0xFF) {
        t = MsGetChrHandle(id);
        if (t != 0) {
            Ch_OptposGet(t, c->f101, v);
        }
    }
    if (t == 0) {
        if (chr != 0) {
            Ch_GetPos(chr, &v[0], &v[1], &v[2]);
        } else {
            func_001B6660(c, v);
        }
    }
    v[3] = 1.0f;
}

int func_001B6790(int id, float *pos) {
    if (MsBtlChrNumCheck((u8)id)) {
        func_001B66E0(MsGetChr((u8)id), pos);
    }
    return 0;
}

int MsGetChrTopPos(int a, float *v) {
    int id = a & 0xFF;
    BtlChr *c;
    if (MsBtlChrNumCheck(id) != 0) {
        c = MsGetChr(id);
        func_001B66E0(c, v);
        if (c->f1C5 != 0 || D_003193EE != 0) {
            v[1] = v[1] - MsGetChrHeight(id) * 0.5f;
        } else {
            v[1] = v[1] - MsGetChrHeight(id);
        }
        return -1;
    }
    return 0;
}

int MsGetChrCenterPos(int a, float *v) {
    int id = a & 0xFF;
    BtlChr *c;
    if (MsBtlChrNumCheck(id) != 0) {
        c = MsGetChr(id);
        func_001B66E0(c, v);
        if (c->f1C5 == 0 && D_003193EE == 0) {
            v[1] = v[1] - MsGetChrHeight(id) * 0.5f;
        }
        return -1;
    }
    return 0;
}

int MsGetChrBottomPos(int id, float *pos) {
    BtlChr *c;

    id &= 0xFF;
    if (!MsBtlChrNumCheck(id)) {
        return 0;
    }
    c = MsGetChr(id);
    func_001B66E0(c, pos);
    if (c->f1C5 != 0 || D_003193EE != 0) {
        pos[1] += MsGetChrHeight(id) * 0.5f;
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B63B8", func_001B69D0);

float func_001B6AD0(int id, float a) {
    float b = 0.0f;
    BtlChr *c;

    id &= 0xFF;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        if ((s8)c->f1D0 != 0) { /* DEBT(CAST): f1D0 is read as a signed byte here */
            b = c->f1FC;
        } else {
            b = c->f15C;
        }
    }
    return MsNearRag(a, b);
}

int MsGetChrScale(u8 id, float *out) {
    if (MsBtlChrNumCheck(id) != 0 && out != 0) {
        BtlChr *c = MsGetChr(id);
        out[0] = c->f60;
        out[1] = c->f64;
        out[2] = c->f68;
        return -1;
    }
    return 0;
}

int MsSetChrPos(u8 id, float *v) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (c->chr != 0) {
            if (c->f34 == 0) {
                Ch_SetPos3(c->chr, v[0], v[1], v[2]);
            } else {
                Ch_SetPos(c->chr, v[0], v[2]);
            }
            return -1;
        }
    }
    return 0;
}

int func_001B6C30(u8 id, float *v) {
    if (MsBtlChrNumCheck(id) != 0) {
        Chr *c = MsGetChr(id)->chr;
        if (c != 0) {
            Ch_SetPos(c, v[0], v[2]);
            return -1;
        }
    }
    return 0;
}

int MsSetChrPosReset(int id, float *v) {
    BtlChr *b;
    Chr *c;

    id &= 0xFF;
    if (MsBtlChrNumCheck(id)) {
        b = MsGetChr(id);
        c = b->chr;
        if (c != 0) {
            if (b->f34 == 0) {
                Ch_SetPos3(c, v[0], v[1], v[2]);
            } else {
                Ch_SetPos(c, v[0], v[2]);
            }
            Ch_ClothReset(c);
            return -1;
        }
    }
    return 0;
}

void MsSetBindToElem(u8 a, int b, int c) {
    Chr *s1;
    Chr *s0;
    float v[4];
    if (MsBtlChrNumCheck(a) != 0) {
        s1 = MsGetChrHandle(a);
        if (s1 != 0) {
            if (b >= 0) {
                s0 = MsGetChrHandle((u8)b);
                if (s0 != 0) {
                    Ch_BindToElem(s1, s0, c);
                    Ch_OptposGet(s0, c, v);
                    MsSetChrPos(a, v);
                }
            } else {
                Ch_BindToElem(s1, 0, c);
            }
        }
    }
}

int MsSetChrGravity(int id, int v) {
    BtlChr *c;
    s8 old;

    id &= 0xFF;
    if (!MsBtlChrNumCheck(id)) {
        return 1;
    }
    c = MsGetChr(id);
    old = c->f34;
    c->f34 = v;
    if (c->chr) {
        Ch_SetGravMode(c->chr, v);
    }
    return old;
}

int func_001B6E48(u8 id, float *out) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (c->chr != 0) {
            *out = func_00110288(c->chr);
            return -1;
        }
    }
    return 0;
}

float MsGetChrBtlDir(u8 id) {
    BtlChr *c;

    if (MsBtlChrNumCheck(id) != 0) {
        c = MsGetChr(id);
        return c->f1D4[c->f1D1];
    }
    return 0;
}

int func_001B6EF8(u8 id, float v) {
    if (MsBtlChrNumCheck(id) != 0) {
        Chr *c = MsGetChr(id)->chr;
        if (c != 0) {
            func_00110300(c, v);
            return -1;
        }
    }
    return 0;
}

int MsSetChrDirF(u8 id, float v) {
    if (MsBtlChrNumCheck(id) != 0) {
        Chr *c = MsGetChr(id)->chr;
        if (c != 0) {
            Ch_SetDirF(c, v);
            return -1;
        }
    }
    return 0;
}

s8 func_001B6FB8(u8 id) {
    return MsGetChr(id)->fE0;
}

int func_001B6FD8(u8 id, int v) {
    if (MsBtlChrNumCheck(id)) {
        MsGetChr(id)->fE0 = v;
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B63B8", func_001B7028);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B63B8", MsSetChrDirTarget);

void func_001B72A0(u8 id) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (c->fEE != 0) {
            c->fEB = 12;
        }
    }
}
