/* tu_201 0x1d48d0-0x1d8078: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#define MsActCommandAdd _hdr_MsActCommandAdd
#include "ffx/r3.h"
#undef MsActCommandAdd
#include "ffx/v3.h"
#include "ffx/s3.h"

void func_001D48D0(BtlChr *c)
{
    c->fC4 = 1;
    c->fC2 = 0x100;
}

void func_001D48E8(BtlChr *c)
{
    c->fC4 = 0;
    c->fC2 = 0x100;
}

s32 _D48F8_func_002EC198(s64, s64) __asm__("func_002EC198");
s64 _D48F8_func_002ED038(float) __asm__("func_002ED038");

void func_001D48F8(int id, BtlChr *c, float *pos, float angle) {
    float sp0[4];
    float sp10[4];
    float a1;
    float a2;
    u8 saved;
    float x, z;
    float s, cs;

    func_001B6790(id, sp0);
    MsVectorRect2Polar(pos, 0, (int)&a1, 0, 0);
    saved = c->f394;
    c->f394 = 0xFF;
    MsGetChrBtlPos(id, sp10);
    c->f394 = saved;
    MsVectorRect2Polar(sp10, pos, (int)&a2, 0, 0);
    a2 = MsNearRag(a1, a2);
    if (_D48F8_func_002EC198(_D48F8_func_002ED038(a2 - a1), 0) < 0) {
        angle = -angle;
    }
    x = pos[0];
    z = pos[2];
    s = func_002E89C0(angle);
    cs = func_002E8648(angle);
    pos[0] = cs * x - s * z;
    pos[2] = s * x + cs * z;
}

void MsActionInit(void) {
    ZanmatoSep = -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsActionRequest);

int MsActionTarget(int mask, int v, int unused2, int unused3, int w, int mode) {
    int n = 0;
    int i;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            MsGetChr(i)->fAAD = v;
            if (mode != 1 || MsCheckCommandCue(i, 1) != 0) {
                if (MsActionRequest(i, v, w, 0, mode, 0) == 0) n++;
            }
        }
    }
    return n;
}

int func_001D4EC0(int a) {
    if (ZanmatoSep != -1) {
        MsStructClear(D_00662CC8, 0x48);
        D_00662CC8[0] = a;
        D_00662CC0 = 0;
        D_00662CBC = 0;
        return 0;
    }
    return -1;
}

void *MsGetCommand(int id, int a, int b, void *c, int *d);
int func_001B81E8(int id, int mask);
void *func_001E4A30(u32 i);

extern GsEnt48 _ent_D_00662CC8 __asm__("D_00662CC8");

int MsActCommandAdd(int id, int cmd, int mask, int d, int e) {
    int res = -1;
    if (ZanmatoSep != -1) {
        if (id == _ent_D_00662CC8.id && _ent_D_00662CC8.f3 < 4) {
            struct GsEnt48Sub *sub = &_ent_D_00662CC8.f8[_ent_D_00662CC8.f3];
            Obj1A *cmd_obj;
            int valid_mask;
            int i;
            int allow_dead;

            sub->h0 = cmd;
            sub->h2 = 0;
            cmd_obj = MsGetCommand(id, 0, -1, sub, 0);
            if (cmd_obj != 0) {
                if (e >= 0) {
                    D_00662CC0 = e;
                }
                valid_mask = 0;
                allow_dead = (cmd_obj->f1A >> 6) & 1;
                for (i = 0; i < 0x1F; i++) {
                    BtlChr *c = MsGetChr(i);
                    if ((mask >> i) & 1) {
                        if ((c->fA8C == 0) ? (c->fA88 != 0) : (allow_dead != 0)) {
                            valid_mask |= 1 << i;
                        }
                    }
                }
                sub->targets = valid_mask;
                if (valid_mask != 0) {
                    func_001B81E8(id, valid_mask);
                    res = 0;
                    D_00662CBC = d;
                    _ent_D_00662CC8.f3++;
                }
            }
        }
    }
    return res;
}

typedef struct {
    u16 h0;
    u16 h2;
} Ev3074;

int MsActReCommand(int id) {
    int sp0 = 0;
    if (ZanmatoSep != -1) {
        GsEnt48 *e = MsGetChrCommand(MsGetChr(MsGetChr(id)->fAAD)->f0C);
        int idx;
        MsGetCommand(id, 0, -1, &e->f8[e->f2], &sp0);
        idx = -1;
        switch (sp0) {
        case 0x3074:
            idx = 0;
            break;
        case 0x3075:
            idx = 1;
            break;
        case 0x3076:
            idx = 2;
            break;
        case 0x3077:
            idx = 3;
            break;
        }
        if (idx >= 0) {
            Ev3074 *ev = func_001E4A30(idx);
            if (ev != 0 && ev->h2 != 0) {
                sp0 = ev->h2;
            }
        }
    }
    return sp0;
}

int MsActChangeCommand(int id, int h, int targets) {
    if (ZanmatoSep != -1) {
        BtlChr *c = MsGetChr(MsGetChr(id)->fAAD);
        if (c->fAB0 != 3) {
            GsEnt48 *e = MsGetChrCommand2(c->f0C);
            if (e != 0) {
                e->f8[e->f2].h0 = h;
                e->f8[e->f2].h2 = 0xFF;
                e->f8[e->f2].targets = targets;
            }
        }
    }
    return 0;
}

typedef struct {
    u8 pad0[0x38B];
    u8 f38B;
    u8 pad38C[0x3DA - 0x38C];
    u16 h3DA[4];
    u8 b3E2[4];
} BtlChr38B;

typedef struct {
    u8 pad0[0x28];
    u16 h28[8];
    u8 pad38[0x478 - 0x38];
} PlyWin478;

extern PlyWin478 *_btl_ply_win __asm__("btl_ply_win");

int func_001D5260(int id, int a, int b, int c) {
    int count = 0;
    int i, j;
    int mask = MsGetChrBit(id, b, 0, 1);

    if (c < 0) {
        c = 0;
    }
    if (c >= 8) {
        c = 7;
    }
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            BtlChr38B *chr = (BtlChr38B *)MsGetChr(i);
            int idx = chr->f38B;
            if (idx < 4) {
                chr->h3DA[idx] = a;
                chr->b3E2[idx] = c;
                chr->f38B++;
                for (j = 7; c < j; j--) {
                    _btl_ply_win[i].h28[j] = _btl_ply_win[i].h28[j - 1];
                }
                _btl_ply_win[i].h28[c] = a;
                count++;
            }
        }
    }
    return count;
}

int func_001D53E0(int id, int a, int b) {
    int count = 0;
    int i, j, k, m;
    int mask = MsGetChrBit(id, b, 0, 1);

    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            BtlChr38B *chr = (BtlChr38B *)MsGetChr(i);
            for (j = 0; j < 4; j++) {
                if (chr->h3DA[j] == a) {
                    for (k = j; k < 3; k++) {
                        chr->h3DA[k] = chr->h3DA[k + 1];
                    }
                    chr->h3DA[k] = 0xFF;
                    chr->f38B--;
                    for (m = 0; m < 8; m++) {
                        if (_btl_ply_win[i].h28[m] == a) {
                            for (k = m; k < 7; k++) {
                                _btl_ply_win[i].h28[k] = _btl_ply_win[i].h28[k + 1];
                            }
                            _btl_ply_win[i].h28[k] = 0xFF;
                            break;
                        }
                    }
                    break;
                }
            }
            count++;
        }
    }
    return count;
}

int MsActTargetSearch(int a, int b, int c, int d, int e, int f, int g, int *out) {
    int sp0;
    int mask;
    int inv;
    int res_mask;
    int count;
    int best_chr;
    int best_val;
    int i;

    if (g != 0) {
        mask = b;
    } else {
        mask = MsGetChrBit(a, b, 0, 1);
    }
    inv = f & 0x80;
    res_mask = 0;
    count = 0;
    best_chr = 0xFF;
    best_val = 0;
    f &= 0x7F;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            if (MsGetChrStatInfo(a, c, i, &sp0) != 0) {
                if (inv == 0) {
                    goto found;
                }
                continue;
            } else if (inv == 0) {
                continue;
            }
        found:
            if (best_chr == 0xFF || f == 0) {
                    best_chr = i;
                    best_val = sp0;
                    res_mask |= 1 << best_chr;
                    count++;
                } else if (best_val == sp0) {
                    res_mask |= 1 << i;
                    count++;
                } else if ((f == 2 && sp0 < best_val) || (f == 1 && best_val < sp0)) {
                    best_chr = i;
                    best_val = sp0;
                    res_mask = 1 << best_chr;
                    count = 1;
                }
        }
    }
    if (count >= 2) {
        if (out != 0) {
            sp0 = brnd(e) % count;
            count = 0;
            for (i = 0; i < 0x1F; i++) {
                if ((res_mask >> i) & 1) {
                    if (sp0 == count) {
                        best_chr = i;
                        break;
                    }
                    count++;
                }
            }
        }
    }
    if (out != 0) {
        *out = best_chr;
    }
    return res_mask;
}

u32 func_001D5790(BtlChr *c)
{
    u32 flags = c->flags;

    if (c->fBB != 0) {
        flags |= 8;
    }
    return flags;
}

float func_001D57A8(BtlChr *c) {
    float f = c->f17C;
    if (c->fBB != 0) {
        f += f;
    }
    return f;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsGetChrStatInfo);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D48D0/rodata", jtbl_0056EB70);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsSetChrStatInfo);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D48D0/rodata", jtbl_0056F0E0);

float func_001D7E80(int id, int a) {
    int scaled = 0;
    float v = 0.0f;
    BtlChr *c = MsGetChr(id);

    switch (a) {
    case 0:
        v = c->f17C;
        scaled = 1;
        break;
    case 1:
        v = c->f180;
        scaled = 1;
        break;
    case 2:
        v = c->f188;
        break;
    case 3:
        v = c->f194;
        break;
    case 4:
        v = c->f198;
        break;
    case 5:
        v = c->f18C;
        break;
    case 6:
        v = c->f190;
        break;
    case 7:
        v = c->f19C;
        break;
    case 8:
        v = c->f184;
        break;
    case 9:
        v = c->f1A4;
        break;
    }
    if (scaled) {
        if (MsGetDamageResult(id, func_001B8198(id, -16, 0, 1), 0, 0, 0) == 1) {
            v += 10.0;
        }
    }
    return v;
}

void MsSetChrMotionInfo(int id, int a, float f) {
    BtlChr *c = MsGetChr(id);
    Chr *chr = c->chr;

    switch (a) {
    case 0:
        c->f17C = f;
        break;
    case 1:
        c->f180 = f;
        break;
    case 2:
        c->f188 = f;
        break;
    case 3:
        c->f194 = f;
        break;
    case 4:
        c->f198 = f;
        break;
    case 5:
        c->f18C = f;
        break;
    case 6:
        c->f190 = f;
        break;
    case 7:
        c->f19C = f;
        break;
    case 8:
        c->f184 = f;
        break;
    case 9:
        c->f1A4 = f;
        c->f10C = 1;
        if (chr != 0) {
            Ch_SetThickness(chr, f);
        }
        break;
    }
}
