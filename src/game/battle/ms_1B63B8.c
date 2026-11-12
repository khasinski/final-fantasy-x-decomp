/* tu_185 0x1b63b8-0x1b72f0: low; ~Ms (config/tu_map.tsv) */
#define func_001B69D0 _hdr_func_001B69D0
#include "common.h"
#include "vu0.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#undef func_001B69D0

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

typedef struct Gs1B69D0 {
    u8 pad0[0x20FE];
    s8 f20FE;
    u8 pad20FF[0x210D - 0x20FF];
    s8 f210D;
} Gs1B69D0;
extern Gs1B69D0 _gs_1B69D0 __asm__("D_003172F0");

typedef struct Chr1B69D0 {
    Chr *chr;
    u8 pad4[0x15 - 0x4];
    s8 f15;
    u8 pad16[0x40 - 0x16];
    float f40;
    u8 pad44[0xDB - 0x44];
    u8 fDB;
    u8 padDC[0xEB - 0xDC];
    u8 fEB;
    u8 fEC;
    u8 fED;
    u8 fEE;
    u8 fEF;
    u8 fF0;
    u8 fF1;
    u8 padF2[0x150 - 0xF2];
    float f150;
    float f154;
    u8 pad158[0x1AC - 0x158];
    float f1AC;
    u8 pad1B0[0x1C5 - 0x1B0];
    s8 f1C5;
    u8 pad1C6[0x3D8 - 0x1C6];
    u8 f3D8;
    u8 f3D9;
    u8 pad3DA[0xA8C - 0x3DA];
    s8 fA8C;
    u8 padA8D[0xC14 - 0xA8D];
    s32 fC14;
    s32 fC18;
    u8 padC1C[0xC30 - 0xC1C];
    float fC30;
} Chr1B69D0;

int func_001B69D0(int id, float *pos) {
    id &= 0xFF;
    if (MsBtlChrNumCheck(id) != 0) {
        Chr1B69D0 *c = (Chr1B69D0 *)MsGetChr(id);
        float *p;
        if (c->chr != 0) {
            p = (float *)func_00110840(c->chr);
        } else {
            p = 0;
        }
        if (p != 0) {
            pos[0] = p[12];
            pos[1] = p[13];
            pos[2] = p[14];
        } else {
            func_001B66E0((BtlChr *)c, pos);
            if (_gs_1B69D0.f210D != 0 && c->fA8C == 2) {
                pos[1] = c->fC30;
            }
            if (c->f1C5 != 0 || _gs_1B69D0.f20FE != 0) {
                pos[1] += MsGetChrHeight(id) * 0.5f;
            }
        }
        pos[3] = 1.0f;
        return -1;
    }
    return 0;
}

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

void *MsGetScreenMatrix(void);
void func_001AC188(void *dst, void *a, void *b);
float func_001AC458(void *dst, void *mat, void *src, int flag);
float MsGetDirMode(int id, BtlChr *c, void *pos, int d, void *e, void *f);
float MsGetChrGround(int id);

int func_001B7028(int id) {
    float m[16];
    float pos[4];
    int v50[4];
    int x;
    int y;
    int r = 0;
    Chr1B69D0 *c;

    id &= 0xFF;
    c = (Chr1B69D0 *)MsGetChr(id);
    if (c->f3D8 != 0 && c->f3D9 != 0 && c->f15 != 0 && c->f40 != 0.0) {
        float w;
        r = 1;
        func_001B6790(id, pos);
        pos[1] = MsGetChrGround(id) - c->f1AC;
        func_001AC188(m, MsGetScreenMatrix(), func_001A9ED0());
        w = func_001AC458(v50, m, pos, 1);
        func_001D8128(v50[0], v50[1], &x, &y);
        if (w <= 0.0f) {
            x = -0x200;
        }
        c->fC14 = x;
        c->fC18 = y;
        if (x < 0 || x > 0x200 || y < 0 || y > 0x1A0) {
            r = 0;
        }
    }
    return r;
}

int MsSetChrDirTarget(int id, int a, int b, int c, int d, int e) {
    float zero_pos[4];
    float dir;

    id &= 0xFF;
    if (MsBtlChrNumCheck(id) != 0) {
        Chr1B69D0 *chr = (Chr1B69D0 *)MsGetChr(id);
        if (chr->fDB == 0) {
            chr->fEB = a;
            if (d + e + d <= 0) {
                e = 1;
            }
            chr->fF0 = e;
            chr->fEC = b;
            chr->fED = 0;
            chr->fEE = d + e + d;
            chr->fEF = d;
            chr->fF1 = c;
            func_001B6E48(id, &dir);
            dir = MsNearRag(0.0f, dir);
            chr->f150 = dir;
            if (b == 0) {
                float target;
                MMI_SQ_ZERO(0, zero_pos);
                target = MsGetDirMode(id, (BtlChr *)chr, zero_pos, 0, 0, 0);
                chr->f154 = MsNearRag(dir, target) - dir;
            }
            return -1;
        }
    }
    return 0;
}

void func_001B72A0(u8 id) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (c->fEE != 0) {
            c->fEB = 12;
        }
    }
}
