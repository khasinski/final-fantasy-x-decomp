/* tu_340 0x2d6808-0x2d7090: low; ~Snd (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad/event glue (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

s32 *func_002D6818(s32 a, s32 b, s32 c);

void func_002D6808(s32 v) {
    D_0078BA48 = v;
}

extern s32 D_0078B188[16][4];
extern s32 D_0078B288[16][4];
extern s32 D_0078B388[16][4];
extern s32 D_0078B488[16];
extern s32 D_0078B4C8[16];
extern s32 D_0078B508[16];
extern s32 D_0078B548[16];
extern s32 D_0078B588[16];
extern s32 D_0078B5C8[16][4];
extern s32 D_0078B6C8[16][4];
extern s32 D_0078B7C8[16][4];
extern s32 D_0078B8C8[16];
extern s32 D_0078B908[16];
extern s32 D_0078B948[16];
extern s32 D_0078B988[16];
extern s32 D_0078B9C8[16];

s32 *func_002D6818(s32 a, s32 b, s32 c)
{
    register s32 idx __asm__("$3");
    register s32 *base __asm__("$2");

    b = (b < 0) ? 0 : (b > 15 ? 15 : b);

    switch (a) {
    case 10:
        return &D_0078B8C8[b];
    case 11:
        return &D_0078B908[b];
    case 12:
        return &D_0078B9C8[b];
    case 14:
        return &D_0078B948[b];
    case 15:
        return &D_0078B988[b];
    case 13:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B7C8[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    case 9:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B6C8[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    case 8:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B5C8[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    case 2:
        return &D_0078B488[b];
    case 3:
        return &D_0078B4C8[b];
    case 4:
        return &D_0078B588[b];
    case 6:
        return &D_0078B508[b];
    case 7:
        return &D_0078B548[b];
    case 5:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B388[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    case 1:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B288[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    case 0:
    default:
        idx = (c < 0) ? 0 : (c > 3 ? 3 : c);
        base = D_0078B188[0];
        return (s32 *)((b << 4) + (u32)(base + idx));
    }
}

void func_002D6A28(s32 unused)
{
    int i, j, k;
    int limit;

    D_0078BA48 = 0;
    for (i = 0; i < 16; i++) {
        switch (i) {
        case 2: case 3: case 4: case 6: case 7:
        case 10: case 11: case 12: case 14: case 15:
            limit = 0;
            break;
        case 0: case 1: case 5: case 8: case 9: case 13:
        default:
            limit = 3;
            break;
        }
        for (j = 0; j < 16; j++) {
            for (k = 0; k <= limit; k++) {
                s32 *p = func_002D6818(i, j, k);

                if (*p) {
                    *p = 0;
                }
            }
        }
    }
}

void SndRemoveFootSepWork(void) {
    func_002D6A28(1);
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;

    D_0078BA4C = 0;
    D_0078BA50 = 0;
}

void func_002D6B88(void) {
    func_002D6A28(0);
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;
    D_0078BA4C = 0;
    D_0078BA50 = 0;
}

void SndClearFootStatus(void) {
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0;
    D_0078BA38.cur = 0;
    D_0078BA40.cur = 0;
}

void func_002D6C08(void) {
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;
}

void func_002D6C38(void) {
    D_0078BA28.pend = D_0078BA28.cur;
    D_0078BA30.pend = D_0078BA30.cur;
    D_0078BA38.pend = D_0078BA38.cur;
    D_0078BA40.pend = D_0078BA40.cur;
}

void func_002D6C80(void) {
    D_0078BA28.cur = D_0078BA28.pend;
    D_0078BA30.cur = D_0078BA30.pend;
    D_0078BA38.cur = D_0078BA38.pend;
    D_0078BA40.cur = D_0078BA40.pend;
}

void func_002D6CC8(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA28.cur |= mask;
    } else {
        D_0078BA28.cur &= ~mask;
    }
}

void func_002D6D00(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA30.cur |= mask;
    } else {
        D_0078BA30.cur &= ~mask;
    }
}

s32 func_002D6D38(void) {
    return D_0078BA30.cur;
}

s32 func_002D6D48(void) {
    return D_0078BA28.cur;
}

s32 func_002D6D58(void) {
    return D_0078BA38.cur;
}

s32 func_002D6D68(void) {
    return D_0078BA40.cur;
}

void func_002D6D78(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA38.cur |= mask;
    } else {
        D_0078BA38.cur &= ~mask;
    }
}

void func_002D6DB0(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA40.cur |= mask;
    } else {
        D_0078BA40.cur &= ~mask;
    }
}

s32 *_m2c_SndSetFootSep_func_002D6818(s32 a, s32 b, s32 c) __asm__("func_002D6818");
void SndSetFootSep(s32 a, s32 b, s32 c, s32 d) {
    *_m2c_SndSetFootSep_func_002D6818(a, b, c) = d;
}

s32 func_002D6E10(u32 idx) {
    u32 *tbl = D_0078BA50;

    if (tbl == 0) {
        return 0;
    }
    if (idx >= tbl[0]) {
        return 0;
    }
    return tbl[idx + 1];
}

extern int func_00135F50(void);
extern void func_00135F60(void *p, s32 a, s32 b);
extern void SndSepPlaySimple(s32 sep);

typedef struct {
    u16 flags;
    u8 pad2[0x16];
    s32 sep;
    void *self;
    s16 h20;
} SndFootWork; /* DEBT(NAME): guessed struct at D_0078BA4C */

void func_002D6E48(s32 kind, s32 ch, s32 pan, s32 var)
{
    s32 mask;
    s32 sep;
    s32 v;
    s32 slot;
    SndFootWork *wk;

    if (kind == 0xFF) {
        func_00135F50();
        mask = D_0078BA40.cur;
        sep = func_002D6E10(var);
    } else {
        if (ch >= 16) {
            return;
        }
        if (ch < 0) {
            return;
        }
        func_00135F50();
        switch (kind) {
        case 4:
            mask = D_0078BA38.cur;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        default:
            mask = D_0078BA30.cur;
            break;
        }
        if (var >= 0) {
            s32 maxv;
            switch (kind) {
            case 4: case 12:
                maxv = 1;
                break;
            case 0: case 1: case 2: case 3: case 5:
            case 8: case 9: case 10: case 11: case 13:
                maxv = 3;
                break;
            case 6: case 7: case 14: case 15:
            default:
                maxv = 0;
                break;
            }
            if (var > maxv) {
                switch (kind) {
                case 4: case 12:
                    maxv = 1;
                    break;
                case 0: case 1: case 2: case 3: case 5:
                case 8: case 9: case 10: case 11: case 13:
                    maxv = 3;
                    break;
                case 6: case 7: case 14: case 15:
                default:
                    maxv = 0;
                    break;
                }
                v = maxv;
            } else {
                v = var;
            }
        } else {
            v = 0;
        }
        var = v;
        if (D_0078BA48) {
            kind += 8;
        }
        sep = *func_002D6818(kind, ch, pan);
    }

    if (sep == 0) {
        return;
    }
    if (kind != 0xFF) {
        sep += var;
    }
    slot = (ch < 16) ? D_0078BA98[ch] : 0;
    if (!((mask >> ch) & 1)) {
        return;
    }
    if (!(((s32)D_0078BA28.cur >> ch) & 1) || (wk = (SndFootWork *)D_0078BA4C) == 0 || slot < 0) {
        D_0078BBA0 = 1;
        D_0078BBA1 = pan;
        SndSepPlaySimple(sep);
    } else {
        wk->sep = sep;
        wk->h20 = slot;
        wk->self = wk;
        wk->flags = (wk->flags | 2) & ~1;
        D_0078BBA0 = 1;
        D_0078BBA1 = pan;
        func_00135F60(&wk->sep, 1, 0x100);
    }
}
