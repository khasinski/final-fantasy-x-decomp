/* tu_110 0x1691c8-0x16cd98: low; ~TOMenuMainHelpSleep (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

int func_001691C8(void) {
    return get_hdd_inst_info();
}

void func_001691E8(void)
{
    /* DEBT(ORDER): independent resets preserve original address/store scheduling. */
    D_0030E0C8 = 0;
    D_0030E0CC = 0;
    D_0030E0BC = 0;
    D_00597E30 = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B4 = 0;
    D_0030E0B8 = 0;
    D_00597A24 = 0;
    D_0030E0C0 = 0;
    D_00597A18 = 0;
    D_00597A1A = 0;
    D_00597A1C = 0;
}

typedef struct {
    s16 fnIdx;
    s16 arg;
    s8 mode;
    u8 pad5[3];
    s32 off;
} To169278Link;

typedef struct {
    u8 b00;
    u8 b01;
    u8 b02;
    u8 pad03[0x13];
    s16 h16;
    s16 h18;
    s16 h1A;
    u16 h1C;
    s16 h1E;
    u8 pad20[4];
    s16 h24;
    u8 pad26[4];
    u8 b2A;
    u8 pad2B[5];
    To169278Link links[8];
    u8 pad90[0x60];
    s16 hF0;
    s16 hF2;
    s16 hF4;
    s16 hF6;
    s16 hF8;
    s8 bFA;
    s8 bFB;
    s8 bFC;
    u8 padFD;
    s16 hFE;
    s16 h100;
    s16 h102;
    u8 b104;
    s8 b105;
    s8 b106;
    u8 pad107;
    u16 h108;
    u16 h10A;
    s16 h10C;
    u8 pad10E[2];
    s8 b110;
    u8 pad111[5];
    u16 h116;
    u8 pad118[0x20];
} To169278Ent;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    int (**fn)(int);
    void *p2C;
    s32 w30;
    void *p34;
} To30E070;

extern To169278Ent *D_00597A10;
extern To169278Ent *D_00597A20;
extern s32 D_00597A28;
typedef union {
    s32 w;
    u16 h;
} ToRegVal;

extern ToRegVal *_to_D_00597E30 __asm__("D_00597E30");
extern void (**D_0030E064)(void);
extern To30E070 _to_D_0030E070 __asm__("D_0030E070");
extern int (**D_0030E098)(int);
void TOMenuHelpSetExtMode(int, int);
void TOMenuTermHelp(void);
void func_0016B838(void);
u8 *func_0016A268(u8 *, u8 *, int, int *, int *);
u16 func_00220318(void);
u16 TOMenuGetControlPadTrg(void);
u16 TOMenuGetControlPadRep(void);
int func_0016B5B0(s32);

void func_00169278(void)
{
    u16 pad;
    int dir;
    To169278Ent *target;
    int i;

    D_0030E0C5 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    if (D_00597A10 == 0) {
        return;
    }
    pad = 0;
    switch (D_00597A10->b02) {
    case 0:
        pad = D_00597A1A;
        break;
    case 1:
        pad = D_00597A18;
        break;
    case 2:
        pad = D_00597A1C;
        break;
    }
    if (pad == 0) {
        return;
    }
    dir = -1;
    if (pad & 0x1000) dir = 0;
    if (pad & 0x4000) dir = 1;
    if (pad & 0x2000) dir = 3;
    if (pad & 0x8000) dir = 2;
    if (pad & 0x20) dir = 4;
    if (pad & 0x40) dir = 7;
    if (pad & 0x80) dir = 5;
    if (pad & 0x10) dir = 6;
    if (dir < 0) {
        return;
    }
    target = (To169278Ent *)((s32)D_0030E0C8 + D_00597A10->links[dir].off);
    if (target == 0) {
        return;
    }
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        for (j = 0; j < n; j++, p++) {
            if (p == target) {
                int blocked = 0;

                if (D_00597A10->links[dir].fnIdx >= 0) {
                    int r = _to_D_0030E070.fn[D_00597A10->links[dir].fnIdx](D_00597A10->links[dir].arg);

                    if (D_00597A10->links[dir].mode == 0) {
                        if (r == 0) {
                            blocked = 1;
                        }
                    } else {
                        if (r != 0) {
                            blocked = 1;
                        }
                    }
                }
                if (blocked == 0) {
                    D_0030E0C5 = 1;
                    return;
                }
            }
        }
    }
}

void func_001694E8(ToRegVal *arg0)
{
    s32 oldIdx = D_00597A14;
    u16 pad;
    int dir;
    To169278Ent *target;
    int i;
    int played;
    int r;

    arg0->w = 0;
    if (D_0030E0C4 != 0) {
        if (D_0030E0C4 == 1) {
            TOMenuHelpSetExtMode(D_0030E0E0, D_0030E0DC);
            TOMenuTermHelp();
        }
        D_0030E0C4 = 2;
        D_00597A1A = 0;
        D_00597A18 = 0;
        D_00597A1C = 0;
        return;
    }
    if (D_0030E0A8 == 0) {
        return;
    }
    if (D_00597A10 == 0) {
        return;
    }
    pad = 0;
    switch (D_00597A10->b02) {
    case 0:
        pad = D_00597A1A;
        break;
    case 1:
        pad = D_00597A18;
        break;
    case 2:
        pad = D_00597A1C;
        break;
    }
    if (pad != 0) {
        dir = -1;
        if (pad & 0x1000) dir = 0;
        if (pad & 0x4000) dir = 1;
        if (pad & 0x2000) dir = 3;
        if (pad & 0x8000) dir = 2;
        if (pad & 0x20) dir = 4;
        if (pad & 0x40) dir = 7;
        if (pad & 0x80) dir = 5;
        if (pad & 0x10) dir = 6;
        played = 0;
        if (dir >= 0) {
            target = (To169278Ent *)((s32)D_0030E0C8 + D_00597A10->links[dir].off);
            if (target != 0 && D_0030E0A8 != 0) {
                for (i = 0; i < D_00597A0C; i++) {
                    register s32 idx8 __asm__("$3") = i * 8;
                    s32 *hdr = (s32 *)(idx8 + (s32)D_0030E0A8);
                    register s32 base __asm__("$4") = (s32)D_0030E0C8;
                    register s32 off __asm__("$2") = hdr[0];
                    int n = *(s16 *)(hdr + 1);
                    register To169278Ent *p __asm__("$17") = (To169278Ent *)(base + off);
                    register int j __asm__("$18");

                    for (j = 0; j < n; j++, p++) {
                        if (p == target) {
                            int blocked = 0;

                            if (D_00597A10->links[dir].fnIdx >= 0) {
                                r = _to_D_0030E070.fn[D_00597A10->links[dir].fnIdx](D_00597A10->links[dir].arg);

                                if (D_00597A10->links[dir].mode == 0) {
                                    if (r == 0) {
                                        blocked = 1;
                                    }
                                } else {
                                    if (r != 0) {
                                        blocked = 1;
                                    }
                                }
                            }
                            if (blocked == 0) {
                                if (D_00597A10->hF6 != 0 && played == 0 && i != oldIdx) {
                                    played = 1;
                                    SndSepPlaySimple(D_00597A10->hF6 | 0x80000000);
                                }
                                if (D_00597A10->hF0 != 0 && played == 0 && i == oldIdx) {
                                    SndSepPlaySimple(D_00597A10->hF0 | 0x80000000);
                                }
                                D_00597A10 = target;
                                D_00597A14 = i;
                                if (i != oldIdx) {
                                    func_0016B838();
                                }
                                D_00597A28 = D_00597A14 - (s32)D_0030E0C8;
                                if (p->h1C != 0) {
                                    s32 *tbl = (s32 *)((s32)D_0030E0B4 + (p->h1E << 3));
                                    int k;

                                    for (k = 0; k < p->h1C; k++, tbl += 2) {
                                        _to_D_00597E30[tbl[0]].w = tbl[1];
                                    }
                                }
                                D_00597A1A = 0;
                                D_00597A18 = 0;
                                D_00597A1C = 0;
                                arg0->w = 1;
                                return;
                            } else {
                                if (D_00597A10->hF8 != 0) {
                                    played = 1;
                                    SndSepPlaySimple(D_00597A10->hF8 | 0x80000000);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (D_0030E0C4 == 0) {
        switch (D_00597A10->bFB) {
        case 0:
            break;
        case 1:
            if (D_00597A18 & 0x40) {
                int blocked = 0;

                if (D_00597A10->h100 >= 0) {
                    r = D_0030E098[D_00597A10->h100](D_00597A10->h102);

                    if (D_00597A10->bFC == 0) {
                        if (r == 0) {
                            blocked = 1;
                        }
                    } else {
                        if (r != 0) {
                            blocked = 1;
                        }
                    }
                }
                if (blocked == 0) {
                    D_0030E0E0 = D_00597A10->bFA;
                    D_0030E0DC = 0;
                    if (D_00597A10->hFE != -1) {
                        D_0030E0DC = _to_D_00597E30[D_00597A10->hFE].w;
                    }
                    if (D_00597A10->hF2 != 0) {
                        SndSepPlaySimple(D_00597A10->hF2 | 0x80000000);
                    }
                    D_0030E0C4 = 1;
                    arg0->w = 2;
                } else {
                    if (D_00597A10->hF8 != 0) {
                        SndSepPlaySimple(D_00597A10->hF8 | 0x80000000);
                    }
                }
            }
            break;
        case 2:
            if (D_00597A18 & 0x20) {
                int blocked = 0;

                if (D_00597A10->h100 >= 0) {
                    r = D_0030E098[D_00597A10->h100](D_00597A10->h102);

                    if (D_00597A10->bFC == 0) {
                        if (r == 0) {
                            blocked = 1;
                        }
                    } else {
                        if (r != 0) {
                            blocked = 1;
                        }
                    }
                }
                if (blocked == 0) {
                    D_0030E0E0 = D_00597A10->bFA;
                    D_0030E0DC = 0;
                    if (D_00597A10->hFE != -1) {
                        D_0030E0DC = _to_D_00597E30[D_00597A10->hFE].w;
                    }
                    if (D_00597A10->hF4 != 0) {
                        SndSepPlaySimple(D_00597A10->hF4 | 0x80000000);
                    }
                    D_0030E0C4 = 1;
                    arg0->w = 2;
                } else {
                    if (D_00597A10->hF8 != 0) {
                        SndSepPlaySimple(D_00597A10->hF8 | 0x80000000);
                    }
                }
            }
            break;
        }
    }
}

void func_00169B10(void)
{
    int flag0;
    int retry;
    To169278Ent *p;
    int n;
    int i;
    int idx;

    if (D_0030E064 != 0) {
        D_0030E064[0]();
    }
    func_0020D540();
    D_00597A1A = func_00220318();
    D_00597A18 = TOMenuGetControlPadTrg();
    D_00597A1C = (TOMenuGetControlPadRep() & 0xFF0F) | (D_00597A18 & 0xF0);

retry_top:
    D_00597A04 = 0;
    if (D_0030E0A8 != 0) {
        s32 *hdr;
        idx = D_00597A14;
        hdr = (s32 *)((idx * 8) + (s32)D_0030E0A8);
        p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        n = *(s16 *)(hdr + 1);

        for (i = 0; i < n; i++, p++) {
            switch (p->b110) {
            case 0:
            case 1:
                break;
            case 2:
                if (p->h116 != 0) {
                    D_00597A1A = 0;
                    D_00597A18 = 0;
                    D_00597A1C = 0;
                }
                break;
            }
        }
    }
    func_00169278();
    if (D_0030E0C4 == 0 && D_0030E0A8 != 0) {
        int changed;
        int curIdx;
        s32 *hdr;

        idx = D_00597A14;
        hdr = (s32 *)((idx * 8) + (s32)D_0030E0A8);
        p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        n = *(s16 *)(hdr + 1);
        curIdx = idx;
        changed = (p != D_00597A20);
        if (D_00597A10 == 0) {
            D_00597A28 = (s32)p;
        } else {
            D_00597A28 = idx - (s32)D_0030E0C8;
        }
        D_00597A20 = p;

        for (i = 0; i < n; i++, p++) {
            int argA;
            int argB;

            argA = 0;
            if (p->h18 >= 0) {
                argA = _to_D_00597E30[p->h18].w;
            }
            argB = 0;
            if (p->h24 >= 0) {
                argB = _to_D_00597E30[p->h24].w;
            }
            if (p == D_00597A10) {
                D_00597A04 = 1;
            } else {
                D_00597A04 = 0;
            }
            if (p->b00 != 0) {
                if (p->b00 == 6) {
                    if (changed != 0) {
                        p->b2A = 0;
                        p->h1A = -1;
                    }
                }
            } else {
                func_0016A268((u8 *)D_0030E0B8, (u8 *)D_0030E0C8 + *(s32 *)((argA * 4) + ((p->h16 * 4) + (s32)D_0030E0B0)), argB, &flag0, 0);
                if (flag0 != 0) {
                    for (idx = 0; idx < D_00597A0C; idx++) {
                        s32 *hdr2 = (s32 *)((idx * 8) + (s32)D_0030E0A8);

                        p = (To169278Ent *)((s32)D_0030E0C8 + hdr2[0]);
                        n = *(s16 *)(hdr2 + 1);
                        for (i = 0; i < n; i++, p++) {
                            if (p == D_00597A10) {
                                D_00597A14 = idx;
                                D_00597A28 = idx - (s32)D_0030E0C8;
                                if (p->h1C != 0) {
                                    s32 *initPairs = (s32 *)((s32)D_0030E0B4 + (p->h1E * 8));
                                    int r;
                                    for (r = 0; r < p->h1C; r++, initPairs += 2) {
                                        _to_D_00597E30[initPairs[0]].w = initPairs[1];
                                    }
                                }
                                if (curIdx != D_00597A14) {
                                    func_0016B838();
                                }
                                D_00597A1A = 0;
                                D_00597A18 = 0;
                                D_00597A1C = 0;
                                goto retry_top;
                            }
                        }
                    }
                    goto retry_top;
                }
            }
        }

        p = D_00597A20;
        for (i = 0; i < n; i++, p++) {
            if (p->b104 & 1) {
                u16 pad = 0;

                switch (p->b106) {
                case 0:
                    pad = D_00597A1A;
                    break;
                case 1:
                    pad = D_00597A18;
                    break;
                case 2:
                    pad = D_00597A1A;
                    break;
                }
                if (pad != 0) {
                    int step;
                    int val;
                    u16 idx;
                    int minVal;
                    int maxVal;

                    step = (!(p->b104 & 4)) ? -1 : 1;
                    val = _to_D_00597E30[p->h10C].w;
                    idx = p->h10C;

                    switch (p->b105) {
                    case 0:
                        if (pad & 0x1000) val += step;
                        if (pad & 0x4000) val -= step;
                        break;
                    case 1:
                        if (pad & 0x8000) val += step;
                        if (pad & 0x2000) val -= step;
                        break;
                    case 2:
                        if (pad & 4) val += step;
                        if (pad & 8) val -= step;
                        break;
                    case 3:
                        if (pad & 1) val += step;
                        if (pad & 8) val -= step;
                        break;
                    }
                    minVal = p->h108;
                    maxVal = p->h10A;
                    if (!(p->b104 & 2)) {
                        if (val < minVal) val = minVal;
                        if (val > maxVal) val = maxVal;
                    } else {
                        if (val < minVal) val = maxVal;
                        if (val > maxVal) val = minVal;
                    }
                    _to_D_00597E30[(s16)idx].w = val;
                }
            }
        }
    }
    func_001694E8(&retry);
    if (retry == 1) {
        goto retry_top;
    }
}

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 b7;
} To16A048Cmd;

extern s32 D_005979F8;
extern s32 D_005979FC;

void func_0016A048(u8 **a0, u8 **a1, int a2)
{
    register u8 *dst __asm__("$16") = *a0;
    u8 *src = *a1;
    To16A048Cmd cmd;
    int val = 0;
    int i;

    memcpy(&cmd, src, 8);
    src += 8;
    switch (cmd.b1) {
    case 0:
        switch (cmd.b0) {
        case 0:
            val = D_0030E098[cmd.h2](cmd.h4);
            break;
        case 1:
            val = _to_D_00597E30[cmd.h4].w;
            break;
        }
        if (cmd.b6 == 0) {
            u16 digits[32];
            u16 *q;
            int nz;

            for (i = 0; i < 6; i++) {
                digits[i] = val % 10;
                val /= 10;
            }
            nz = 0;
            for (i = 5; i > 0; i--) {
                if (digits[i] == 0) {
                    if (nz != 0) {
                        digits[i] += 0x30;
                    } else {
                        digits[i] = 0x3A;
                    }
                } else {
                    nz = 1;
                    digits[i] += 0x30;
                }
            }
            digits[i] += 0x30;
            for (i = 5; i >= 0; i--) {
                *dst++ = digits[i];
            }
        } else {
            D_005979F8 = cmd.b6;
            D_005979FC = val;
        }
        break;
    case 1: {
        u8 *s = (u8 *)D_0030E098[cmd.h2](cmd.h4 + a2);

        for (i = 0; s[i] != 0; i++) {
            *dst++ = s[i];
        }
        break;
    }
    }
    *a0 = dst;
    *a1 = src;
}

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 hA;
    s32 wC;
} To16A268Cond;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    u16 h6;
    s32 w8;
} To16A268Set;

typedef struct {
    u16 h0;
    s8 b2;
    u8 b3;
    u16 h4;
    u16 h6;
    s32 w8;
} To16A268Call;

extern s32 D_00597A00;
extern void (**D_0030E09C)(int, int);
extern void (**D_0030E0A4)(int);
extern char D_0056C028[];

u8 *func_0016A268(u8 *dst, u8 *src, int arg2, int *arg3, int *arg4)
{
    To16A268Cond cond;
    To16A268Set setCmd;
    To16A268Call callCmd;
    s8 stack[32];
    int depth = 0;
    int i;
    u8 c;

    if (arg4 != 0) {
        *arg4 = 0;
    }
    for (i = 0; i < 32; i++) {
        stack[i] = 0;
    }
    for (;;) {
        if ((s32)dst - (s32)D_0030E0B8 >= 0x4000) {
            yiAssert(0, D_0056C020, D_0056C028);
        }
        c = *src++;
        if (c == 0) {
            break;
        }
        if (c < 0x30 && c != 3) {
            u8 c2 = *src++;
            u32 code = (c2 << 8) + c;

            if (code == 0xF90B) {
                D_00597A00 = 1;
            } else if (c == 0x13 && (u32)(c2 - 0x30) < 8) {
                *dst++ = c;
                *dst++ = c2;
            } else if (c == 0xB && ((u32)(c2 - 0x30) < 0x1A || c2 == 0x60)) {
                *dst++ = c;
                *dst++ = c2;
            } else if (code == 0xF00B) {
                s32 lhs = 0;
                s32 rhs;
                int res;

                memcpy(&cond, src, 16);
                src += 16;
                switch (cond.b0) {
                case 0:
                    lhs = D_0030E098[cond.h4](cond.h6);
                    break;
                case 1:
                    lhs = _to_D_00597E30[cond.h6].w;
                    break;
                }
                switch (cond.b2) {
                case 0:
                    rhs = D_0030E098[cond.h8](cond.hA);
                    break;
                case 1:
                    rhs = _to_D_00597E30[cond.hA].w;
                    break;
                case 2:
                default:
                    rhs = cond.wC;
                    break;
                }
                switch (cond.b1) {
                default:
                case 0:
                    res = (rhs == lhs);
                    break;
                case 1:
                    res = (rhs != lhs);
                    break;
                case 2:
                    res = (lhs >= rhs);
                    break;
                case 3:
                    res = (lhs <= rhs);
                    break;
                case 4:
                    res = (lhs > rhs);
                    break;
                case 5:
                    res = (lhs < rhs);
                    break;
                case 6:
                    res = ((rhs & lhs) != 0) ? 1 : 0;
                    break;
                }
                stack[depth++] = res;
            } else if (code == 0xF10B) {
                if (stack[depth - 1] == 0) {
                    int nest = 0;

                    for (;;) {
                        c = *src++;
                        if (c == 0) {
                            goto done;
                        }
                        if (c < 0x30 && c != 3) {
                            c2 = *src++;
                            code = (c2 << 8) + c;
                            if (nest <= 0) {
                                if (code == 0xF30B) {
                                    break;
                                }
                                if (code == 0xF20B) {
                                    stack[depth - 1] = 0;
                                    depth--;
                                    break;
                                }
                            }
                            if (code == 0xF40B) {
                                src += 8;
                            } else if (code == 0xF60B) {
                                src += 12;
                            } else if (code == 0xF00B) {
                                nest++;
                                src += 16;
                            } else if (code == 0xF70B) {
                                src += 4;
                            } else if (code == 0xF80B) {
                                src += 12;
                            } else if (code == 0xFA0B) {
                                src += 4;
                            } else if (code == 0xF20B) {
                                nest--;
                            }
                        }
                    }
                }
            } else if (code == 0xF20B) {
                stack[depth - 1] = 0;
                depth--;
            } else if (code == 0xF30B) {
                if (stack[depth - 1] != 0) {
                    int nest = 0;

                    for (;;) {
                        c = *src++;
                        if (c == 0) {
                            goto done;
                        }
                        if (c < 0x30 && c != 3) {
                            c2 = *src++;
                            code = (c2 << 8) + c;
                            if (code == 0xF00B) {
                                nest++;
                                src += 16;
                            } else {
                                if (nest <= 0 && code == 0xF20B) {
                                    stack[depth - 1] = 0;
                                    depth--;
                                    break;
                                }
                                if (code == 0xF20B) {
                                    nest--;
                                }
                                if (code == 0xF40B) {
                                    src += 8;
                                } else if (code == 0xF60B) {
                                    src += 12;
                                } else if (code == 0xF70B) {
                                    src += 4;
                                } else if (code == 0xF80B) {
                                    src += 12;
                                } else if (code == 0xFA0B) {
                                    src += 4;
                                }
                            }
                        }
                    }
                }
            } else if (code == 0xF40B) {
                func_0016A048(&dst, &src, arg2);
            } else if (code == 0xF60B) {
                if (arg3 != 0) {
                    memcpy(&setCmd, src, 12);
                    switch (setCmd.b0) {
                    case 0:
                        D_0030E09C[setCmd.h4](setCmd.h2, setCmd.w8);
                        break;
                    case 1:
                        _to_D_00597E30[setCmd.h2].w = setCmd.w8;
                        break;
                    }
                }
                src += 12;
            } else if (code == 0xF70B) {
                if (arg3 != 0) {
                    int off;

                    memcpy(&off, src, 4);
                    *(int *)&D_00597A10 = (s32)D_0030E0C8 + off;
                    *arg3 = 1;
                    return 0;
                }
                src += 4;
            } else if (code == 0xF80B) {
                if (arg3 != 0) {
                    memcpy(&callCmd, src, 12);
                    switch (callCmd.b2) {
                    case 0: {
                        int v = _to_D_0030E070.fn[callCmd.h4](callCmd.h6);
                        ((void (**)(int))_to_D_0030E070.p34)[callCmd.h0](v);
                        break;
                    }
                    case 1: {
                        int v = _to_D_00597E30[callCmd.h6].w;
                        D_0030E0A4[callCmd.h0](v);
                        break;
                    }
                    case 3: {
                        int v = callCmd.w8;
                        D_0030E0A4[callCmd.h0](v);
                        break;
                    }
                    case 2:
                    case 4:
                        D_0030E0A4[callCmd.h0](0);
                        break;
                    }
                }
                src += 12;
            } else if (code == 0xFA0B) {
                if (arg4 != 0) {
                    *arg4 = 1;
                }
                src += 4;
            } else {
                *dst++ = c;
                *dst++ = c2;
            }
        } else {
            *dst++ = c;
        }
    }
done:
    *dst++ = c;
    if (arg3 != 0) {
        *arg3 = 0;
    }
    return dst;
}

extern s32 D_0030E094;
void func_002DA928(void *, s16, s16, s16, s16, s16, s16, s16);
void func_002DAC50(void *, void *);

void func_0016AA88(s32 *a0, s32 *a1, s32 *a2)
{
    u8 sp[0x60];
    int v = D_0030E094;

    *a1 = a0[0];
    *a2 = a0[1];
    func_002DA928(sp, v, 1, 0, 0, 0, 0x10, 0x10);
    v += 4;
    func_002F8660(0);
    func_002DAC50(sp, a0 + 4);
    func_002DA610(0, 0);
    func_002DA928(sp, v, a0[0] / 64, 0x13, 0, 0, a0[0], a0[1]);
    func_002F8660(0);
    func_002DAC50(sp, a0 + 0x104);
    func_002DA610(0, 0);
}

typedef struct {
    u8 pad0[0x20];
    s16 h20;
    s16 h22;
    u8 pad24[7];
    s8 b2B;
} To16AB78Arg;

extern int (**D_0030E098)(int);

int func_0016AB78(To16AB78Arg *p)
{
    int r;

    if (p->h20 < 0) {
        return 0;
    }
    r = D_0030E098[p->h20](p->h22);
    switch (p->b2B) {
    case 0:
        if (r == 0) {
            return 1;
        }
        break;
    case 1:
        if (r != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

typedef struct {
    u8 b00;
    u8 pad01[3];
    s16 h04;
    s16 h06;
    s16 h08;
    s16 h0A;
    s16 h0C;
    s16 h0E;
    s16 h10;
    s16 h12;
    s16 h14;
    s16 h16;
    s16 h18;
    s16 h1A;
    u8 pad1C[8];
    s16 h24;
    s16 h26;
    s16 h28;
    u8 b2A;
    u8 pad2B[0xC7];
    s16 hF2;
    u8 padF4[6];
    s8 bFA;
    u8 padFB[3];
    s16 hFE;
    u8 pad100[0x10];
    s8 b110;
    u8 pad111[3];
    u16 h114;
    u16 h116;
    float f118;
    float f11C;
    u8 pad120[4];
    float f124;
    float f128;
    u8 pad12C[0xC];
} To16AC00Ent;

typedef struct {
    void (*fn0)(int, void *, int, int);
    s32 pad04;
    int (*fn8)(int);
    s32 pad0C;
    void (*fn10)(int);
} To78E498;

extern To78E498 _to_D_0078E498 __asm__("D_0078E498");
extern s32 D_0030E0D0, D_0030E0D4, D_0030E0DC, D_0030E0E0;
extern s32 D_005979F8, D_005979FC, D_00597A00;
extern void func_00168968(void);
extern void func_001689C8(void);
extern void func_0016C328(u8 *, To16AC00Ent *, int, int);
extern void func_0016C688(u8 *, s32, s32, int, int, int, int);
extern void func_0016C920();
extern u8 *func_001F3C58(u8 *, int, int, int, int);
extern u8 *func_001F3DE8(u8 *, int, int, int, int);
extern u8 *func_001F4350(u8 *, int, u8 *, int, int, int, int, int, int, int);
extern u8 *func_001F5F50(u8 *, int, int, int, int);
extern u8 *func_001F6400(u8 *, int, int, int, int);
extern void func_002F8660(int);

typedef union {
    u_long128 q;
    u32 w[4];
} ToDmaQword;

void func_0016AC00(void)
{
    int flag;
    int mw, mh;
    s32 w, h;
    int count;
    int i;
    u8 *pkt;
    register void *ch __asm__("$23");
    To16AC00Ent *ent;

    pkt = (u8 *)Sg_PacketGetPtr();
    if (D_0030E0D4 != 0) {
        func_001689C8();
    }
    if (D_0030E0A8 != 0) {
        u8 *hdr = (u8 *)((D_00597A14 * 8) + (s32)D_0030E0A8);
        ent = (To16AC00Ent *)((s32)D_0030E0C8 + *(s32 *)hdr);
        count = *(s16 *)(hdr + 4);
        func_002DA610(0, 0);
        ch = (void *)func_002DB6D8(2);
        for (i = 0; i < count; ) {
            int r18;
            int r24;
            int r26;
            int r28;
            int x, y;
            register u8 *end __asm__("$5");

            r18 = 0;
            if (ent->h18 >= 0) {
                r18 = _to_D_00597E30[ent->h18].w;
            }
            r24 = 0;
            if (ent->h24 >= 0) {
                r24 = _to_D_00597E30[ent->h24].w;
            }
            r28 = 0;
            r26 = 0;
            if (ent->h26 >= 0) {
                r26 = _to_D_00597E30[ent->h26].w;
            }
            if (ent->h28 >= 0) {
                r28 = _to_D_00597E30[ent->h28].w;
            }
            if (ent == (To16AC00Ent *)D_00597A10) {
                D_00597A04 = 1;
            } else {
                D_00597A04 = 0;
            }
            if (ent->b00 == 2) {
                if (D_00597A10 != 0) {
                    To16AC00Ent *cur = (To16AC00Ent *)D_00597A10;
                    x = ent->h0C + r26 + cur->h10;
                    y = ent->h0E + r28 + cur->h12;
                } else {
                    y = 0;
                    x = 0;
                }
            } else {
                int fx = ent->h04 + (int)ent->f118;
                int ox = r26 + ent->h0C;
                int fy = ent->h06 + (int)ent->f11C;
                int oy = r28 + ent->h0E;
                x = fx + ox;
                y = fy + oy;
            }
            __asm__("" : : "m"(flag), "m"(mw), "m"(mh));
            w = ent->h08;
            h = ent->h0A;
            switch (ent->b110) {
            case 0:
                ent->f118 = ent->f11C = 0.0f;
                break;
            case 1:
                ent->f118 += ent->f124;
                ent->f11C += ent->f128;
                if (x < -w) {
                    x += 0x200 + w;
                    ent->f118 += (float)w + 512.0f;
                }
                __asm__("" : "+m"(w));
                if (x > 0x200) {
                    x -= 0x200 + w;
                    ent->f118 -= (float)w + 512.0f;
                }
                if (y < -h) {
                    y += 0x1A0 + h;
                    ent->f11C += (float)h + 416.0f;
                }
                __asm__("" : "+m"(h));
                if (y > 0x1A0) {
                    y -= 0x1A0 + h;
                    ent->f11C -= (float)h + 416.0f;
                }
                break;
            case 2:
                if (ent->h116 != 0) {
                    x = (int)((float)x + ent->f124 * (float)ent->h116);
                    y = (int)((float)y + ent->f128 * (float)ent->h116);
                    if (ent->h114 != 0) {
                        ent->h114--;
                    } else {
                        ent->h116--;
                    }
                }
                break;
            }
            ent->h10 = x;
            ent->h12 = y;
            switch (ent->b00) {
            case 0:
                if (func_0016AB78((To16AB78Arg *)ent) == 0) {
                    u8 *src = (u8 *)D_0030E0C8 + *(s32 *)((r18 * 4) + ((ent->h16 * 4) + (s32)D_0030E0B0));
                    D_00597A00 = 0;
                    D_005979F8 = 0;
                    func_0016A268((u8 *)D_0030E0B8, src, r24, 0, &flag);
                    if (*(u8 *)D_0030E0B8 != 0) {
                        if (flag != 0) {
                            TOGetEasyMesWHFontL((u8 *)D_0030E0B8, &mw, &mh);
                            func_0016C920(pkt, x, y, mw, mh);
                            func_002F8660(0);
                            func_002DBA28(ch, pkt);
                            func_002DA610(0, 0);
                        }
                        end = func_001F4350(pkt + 0x10, 7, (u8 *)D_0030E0B8, x, y, 0, 0x80, 0x80, 0x80, 0x80);
                        {
                            register u_long128 z1 __asm__("$3") = 0;
                            register u32 d __asm__("$2");
                            register u32 qwc __asm__("$3");
                            register u32 etag __asm__("$6");
                            register u32 htag __asm__("$2");
                            register u32 tag __asm__("$4");
                            register u_long128 z2 __asm__("$2");
                            __asm__("" : "+r"(end));
                            __asm__("" : "+r"(z1));
                            ((ToDmaQword *)end)->q = z1;
                            d = (u32)(end - pkt) >> 4;
                            etag = 0x70000000;
                            __asm__("" : "+r"(etag) : "r"(d));
                            qwc = d - 1;
                            ((ToDmaQword *)end)->w[0] = etag;
                            __asm__("" : "+r"(qwc) : "m"(((ToDmaQword *)end)->w[0]));
                            htag = 0x10000000;
                            __asm__("" : "+r"(htag));
                            tag = qwc | htag;
                            __asm__("" : "+r"(tag));
                            z2 = 0;
                            __asm__("" : "+r"(z2));
                            ((ToDmaQword *)pkt)->q = z2;
                            ((ToDmaQword *)pkt)->w[0] = tag;
                        }
                        func_002F8660(0);
                        func_002DBA28(ch, pkt);
                        func_002DA610(0, 0);
                    }
                    {
                        int flg = D_00597A00 ? 0x25 : 0;
                        switch (D_005979F8) {
                        case 0:
                            break;
                        case 1:
                            end = func_001F5F50(pkt + 0x10, D_005979FC, x + 0x3C, y, flg);
                            goto send_dma_tag;
                        case 2:
                            end = func_001F6400(pkt + 0x10, D_005979FC, x + 0x3C, y, flg);
                            goto send_dma_tag;
                        }
                    }
                }
                break;
            case 2:
                if (D_00597A10 != 0 && func_0016AB78((To16AB78Arg *)ent) == 0) {
                    func_0016C328(pkt, ent, x, y);
                    func_002F8660(0);
                    func_002DBA28(ch, pkt);
                    func_002DA610(0, 0);
                }
                break;
            case 1:
                if (func_0016AB78((To16AB78Arg *)ent) == 0) {
                    func_0016C328(pkt, ent, x, y);
                    func_002F8660(0);
                    func_002DBA28(ch, pkt);
                    func_002DA610(0, 0);
                }
                break;
            case 3:
                if (func_0016AB78((To16AB78Arg *)ent) == 0) {
                    int val = D_0030E098[ent->h16](r18);
                    switch (ent->b2A) {
                    case 0:
                        end = func_001F3C58(pkt + 0x10, val, x, y, 0);
                        goto send_dma_tag;
                    case 1:
                        end = func_001F3DE8(pkt + 0x10, val, x, y, 0);
                    send_dma_tag:
                        {
                            register u_long128 z1 __asm__("$3") = 0;
                            register u32 d __asm__("$2");
                            register u32 qwc __asm__("$3");
                            register u32 etag __asm__("$6");
                            register u32 htag __asm__("$2");
                            register u32 tag __asm__("$4");
                            register u_long128 z2 __asm__("$2");
                            __asm__("" : "+r"(end));
                            __asm__("" : "+r"(z1));
                            ((ToDmaQword *)end)->q = z1;
                            d = (u32)(end - pkt) >> 4;
                            etag = 0x70000000;
                            __asm__("" : "+r"(etag) : "r"(d));
                            qwc = d - 1;
                            ((ToDmaQword *)end)->w[0] = etag;
                            __asm__("" : "+r"(qwc) : "m"(((ToDmaQword *)end)->w[0]));
                            htag = 0x10000000;
                            __asm__("" : "+r"(htag));
                            tag = qwc | htag;
                            __asm__("" : "+r"(tag));
                            z2 = 0;
                            __asm__("" : "+r"(z2));
                            ((ToDmaQword *)pkt)->q = z2;
                            ((ToDmaQword *)pkt)->w[0] = tag;
                        }
                        func_002F8660(0);
                        func_002DBA28(ch, pkt);
                        func_002DA610(0, 0);
                        break;
                    }
                }
                break;
            case 4:
                if ((D_00597A18 & 0x40) != 0 && D_0030E0C4 == 0) {
                    D_0030E0E0 = ent->bFA;
                    if (ent->hFE == -1) {
                        D_0030E0DC = 0;
                    } else {
                        D_0030E0DC = _to_D_00597E30[ent->hFE].w;
                    }
                    if (ent->hF2 != 0) {
                        SndSepPlaySimple(ent->hF2 | (-2147483647 - 1));
                    }
                    D_0030E0C4 = 1;
                }
                break;
            case 6:
                if (ent->h1A != r18) {
                    ent->h1A = r18;
                    ent->b2A = 0;
                }
                if (func_0016AB78((To16AB78Arg *)ent) == 0) {
                    switch (ent->b2A) {
                    case 0:
                        if (_to_D_0078E498.fn8(1) != 0) {
                            break;
                        }
                        _to_D_0078E498.fn10(ent->h14);
                        _to_D_0078E498.fn0(ent->h16 + r18, (void *)D_0030E0BC, 0, 0);
                        ent->b2A = 1;
                    case 1:
                        if (_to_D_0078E498.fn8(1) != 0) {
                            break;
                        }
                        func_0016AA88((s32 *)D_0030E0BC, &w, &h);
                        ent->h08 = w;
                        ent->h0A = h;
                        ent->b2A = 2;
                    case 2:
                        func_0016C688(pkt, D_0030E094 + 4, D_0030E094, x, y, ent->h08, ent->h0A);
                        func_002F8660(0);
                        func_002DBA28(ch, pkt);
                        func_002DA610(0, 0);
                        break;
                    }
                }
                break;
            case 5:
                break;
            }
            ent++;
            {
                register int _i __asm__("$3") = i;
                __asm__("" : "+r"(_i));
                _i++;
                i = _i;
            }
        }
    }
    if (D_0030E0D0 != 0) {
        func_00168968();
    }
}

void func_0016B4E0(void)
{
    extern s32 D_0030E05C, D_0030E0D0, D_0030E0D4, D_0030E0D8;
    extern s32 dvd_hdd_copy_system_cnf_buff;

    D_0030E0C8 = 0;
    D_00597E30 = 0;
    D_0030E0CC = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B8 = 0;
    D_0030E0C0 = 0;
    D_0030E0BC = 0;
    D_0030E060 = 0;
    D_0030E0D0 = 0;
    D_0030E0D8 = 0;
    D_0030E0D4 = 0;
    dvd_hdd_copy_system_cnf_buff = 0;
    D_0030E05C = 0;
    if (D_0030E064 != 0) {
        D_0030E064[1]();
        D_0030E064 = 0;
    }
    D_0030E068 = 0;
}

typedef union {
    struct {
        u16 w;
        u16 h;
        u8 bpp;
        u8 pad5[3];
        s32 clutOff;
        s32 imgOff;
    } s;
    s32 raw[4];
} To16B5B0Ent;

typedef union {
    struct {
        s32 psm;
        u16 w;
        u16 h;
        s32 cbp;
        s32 tbp;
    } s;
    s32 raw[4];
} To16B5B0Tex;

extern s32 D_0030E090;
extern To16B5B0Tex _to_D_00597A30[] __asm__("D_00597A30");

int func_0016B5B0(s32 arg0)
{
    u8 sp[0x60];
    u8 *base = (u8 *)arg0;
    To16B5B0Ent *ents = (To16B5B0Ent *)(base + 0x10);
    To16B5B0Ent *e;
    int vram = D_0030E090;
    int i;

    func_002DA610(0, 0);
    e = ents;
    for (i = 0; i < *(s32 *)(base + 4); i++, e++) {
        _to_D_00597A30[i].s.w = e->s.w;
        _to_D_00597A30[i].s.h = e->s.h;
        _to_D_00597A30[i].s.cbp = vram;
        func_002DA928(sp, vram, 1, 0, 0, 0, 0x10, 0x10);
        vram += 4;
        func_002F8660(0);
        func_002DAC50(sp, base + e->s.clutOff);
        func_002DA610(0, 0);
    }
    e = ents;
    for (i = 0; i < *(s32 *)(base + 4); i++, e++) {
        int psm;
        int w;
        u16 h;
        switch (e->s.bpp) {
        case 4:
            psm = 0x14;
            break;
        case 8:
            psm = 0x13;
            break;
        case 16:
            psm = 2;
            break;
        case 24:
            psm = 1;
            break;
        case 32:
        default:
            psm = 0;
            break;
        }
        _to_D_00597A30[i].s.psm = psm;
        _to_D_00597A30[i].s.tbp = vram;
        w = e->s.w;
        h = e->s.h;
        func_002DA928(sp, vram, w / 64, psm, 0, 0, w, e->s.h);
        func_002F8660(0);
        func_002DAC50(sp, base + e->s.imgOff);
        func_002DA610(0, 0);
        vram += (s32)(w * h * e->s.bpp) / 2048;
    }
    return vram;
}

void func_0016B7D8(void)
{
    s32 *hdr = (s32 *)D_0030E0C8;

    if (hdr != 0) {
        D_0030E0A8 = (u8 *)hdr + hdr[2];
        D_00597A0C = hdr[1];
        D_0030E0AC = (u8 *)hdr + hdr[3];
        D_0030E0B0 = (u8 *)hdr + hdr[4];
        D_0030E0B4 = (u8 *)hdr + hdr[5];
    }
}

typedef struct {
    s32 off;
    s16 cnt;
    s16 pad;
} To16B838Hdr;

typedef struct {
    u8 b00;
    u8 b01;
    u8 pad02[0x1A];
    u16 h1C;
    s16 h1E;
    u8 pad20[0xF4];
    u16 h114;
    u16 h116;
    s32 w118;
    s32 w11C;
    u16 h120;
    u16 h122;
    u8 pad124[0x14];
} To16B838Ent;

extern s32 _m2c_D_0030E0A8 __asm__("D_0030E0A8");
extern s32 _m2c_D_0030E0C8 __asm__("D_0030E0C8");

void func_0016B838(void)
{
    To16B838Hdr *hdr = (To16B838Hdr *)((D_00597A14 * 8) + _m2c_D_0030E0A8);
    int j;
    int n = hdr->cnt;
    To16B838Ent *p = (To16B838Ent *)(_m2c_D_0030E0C8 + hdr->off);

    for (j = 0; j < n; j++, p++) {
        p->h114 = p->h120;
        p->h116 = p->h122;
        p->w118 = 0;
        p->w11C = 0;
    }
}

void func_0016B898(void)
{
    int i;

    D_00597A28 = 0;
    D_00597A20 = 0;
    D_00597A10 = 0;
    D_00597A14 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        func_0016B838();
        for (j = 0; j < n; j++, p++) {
            if (p->b01 & 1) {
                D_00597A10 = p;
                D_00597A14 = i;
                D_00597A28 = i - (s32)D_0030E0C8;
                if (p->h1C != 0) {
                    s32 *q = (s32 *)((s32)D_0030E0B4 + (p->h1E << 3));
                    int k;

                    for (k = 0; k < p->h1C; k++, q += 2) {
                        _to_D_00597E30[q[0]].w = q[1];
                    }
                }
                return;
            }
        }
    }
}

void func_0016BA00(void)
{
    To169278Ent *target = (To169278Ent *)((s32)D_0030E0C8 + D_00597A28);
    int i;

    D_00597A28 = 0;
    D_00597A20 = 0;
    D_00597A10 = 0;
    D_00597A14 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        func_0016B838();
        for (j = 0; j < n; j++, p++) {
            if (p == target) {
                D_00597A10 = p;
                D_00597A14 = i;
                D_00597A28 = i - (s32)D_0030E0C8;
                if (p->h1C != 0) {
                    s32 *q = (s32 *)((s32)D_0030E0B4 + (p->h1E << 3));
                    int k;

                    for (k = 0; k < p->h1C; k++, q += 2) {
                        _to_D_00597E30[q[0]].w = q[1];
                    }
                }
                return;
            }
        }
    }
}

extern char D_0056C118[];

int func_0016BB88(int a0, int a1)
{
    int max = func_00220808();
    int ret;

    if (a0 == 0) {
        D_00597A24 = 0;
    }
    a1 = ((a1 + 0x3F) / 64) * 64;
    ret = func_00220800() + D_00597A24;
    D_00597A24 += a1;
    if (D_00597A24 >= max) {
        ((void (*)(int, char *, char *, int, int))yiAssert)(0, D_0056C020, D_0056C118, D_00597A24, max); /* DEBT(CAST) */
    }
    return ret;
}

void func_0016BC30(int a) {
    D_00597A24 -= ((a + 0x3F) / 64) * 64;
    if (D_00597A24 < 0) {
        yiAssert(0, D_0056C020, D_0056C140);
    }
}

void func_0016BC80(void (*v)(void)) {
    D_0030E068 = v;
}

int func_0016BC90(void) {
    return D_0030E068 != 0;
}

void func_0016BCA0(void)
{
    for (;;) {
        if (D_0030E068 != 0) {
            D_0030E068();
            D_0030E068 = 0;
        }
        func_0017135C(1);
    }
}

extern int (*D_0030E0E8[])(int);
extern void (*D_0030E860[])(int, int);
extern void (*D_0030E8A0[])(int);
extern s32 D_00597E34;
extern void *_bce0_B8 __asm__("D_0030E0B8");
extern void *_bce0_D0 __asm__("D_0030E0D0");
extern void *_bce0_D4 __asm__("D_0030E0D4");
extern void *_bce0_D8 __asm__("D_0030E0D8");
extern s32 D_0030E05C;
extern u8 *dvd_hdd_copy_system_cnf_buff;
extern s32 D_0057CB88;
extern s32 D_0057CB8C;
extern s32 D_0057CB90;
extern s32 D_0057CB94;
void func_002202D0(void);
void TOFTCTransfer(int);
int sa_task_buff_size_get(int);
void **sa_task_init2(int, int, int);
void func_0016B7D8(void);
void func_00162CD8(int);
void hdd_ins_size_check(void);

void func_0016BCE0(u32 arg0)
{
    u32 flag;
    int size;

    flag = arg0 & 0x8000;
    arg0 &= 0xFF;
    func_002202D0();
    D_00597A18 = 0;
    D_00597A1A = 0;
    D_00597A1C = 0;
    switch (arg0) {
    default:
    case 0:
        _to_D_0030E070.w14 = 1;
        _to_D_0030E070.w18 = 2;
        _to_D_0030E070.w30 = 3;
        _to_D_0030E070.fn = D_0030E0E8;
        _to_D_0030E070.p2C = D_0030E860;
        _to_D_0030E070.p34 = D_0030E8A0;
        break;
    case 1:
        _to_D_0030E070.w14 = 4;
        _to_D_0030E070.w18 = 5;
        _to_D_0030E070.w30 = 6;
        _to_D_0030E070.fn = D_0030E0E8;
        _to_D_0030E070.p2C = D_0030E860;
        _to_D_0030E070.p34 = D_0030E8A0;
        break;
    case 2:
        _to_D_0030E070.w14 = 7;
        _to_D_0030E070.w18 = 8;
        _to_D_0030E070.w30 = 9;
        _to_D_0030E070.fn = D_0030E0E8;
        _to_D_0030E070.p2C = D_0030E860;
        _to_D_0030E070.p34 = D_0030E8A0;
        break;
    case 3:
        _to_D_0030E070.w14 = 10;
        _to_D_0030E070.w18 = 11;
        _to_D_0030E070.w30 = 12;
        _to_D_0030E070.fn = D_0030E0E8;
        _to_D_0030E070.p2C = D_0030E860;
        _to_D_0030E070.p34 = D_0030E8A0;
        break;
    case 4:
        _to_D_0030E070.w14 = 13;
        _to_D_0030E070.w18 = 14;
        _to_D_0030E070.w30 = 0;
        _to_D_0030E070.fn = D_0030E0E8;
        _to_D_0030E070.p2C = D_0030E860;
        _to_D_0030E070.p34 = D_0030E8A0;
        break;
    }
    D_00597A08[0] = 0;
    D_00597A08[1] = 0;
    D_00597A08[2] = 0;
    D_00597A08[3] = 0;
    D_0030E068 = 0;
    D_0030E0C5 = 0;
    D_0030E0C4 = 0;
    D_0030E0DC = 0;
    if (func_001BD360() == 0) {
        _to_D_0030E070.w1C = 0x30;
    } else {
        _to_D_0030E070.w1C = 3;
    }
    D_0078E498.f10(_to_D_0030E070.w1C);
    size = D_0078E498.f14(_to_D_0030E070.w18);
    D_0030E0CC = func_0016BB88(0, size);
    D_0078E498.f00(_to_D_0030E070.w18, D_0030E0CC, 0, 0);
    D_0078E498.f08(0);
    _to_D_0030E070.w24 = D_00597E34 = func_0016B5B0(D_0030E0CC);
    func_0016BC30(size);
    D_0030E0CC = 0;

    D_0030E060 = func_0016BB88(1, D_0078E498.f14(0x12));
    D_0078E498.f00(0x12, D_0030E060, 0, 0);
    D_0078E498.f08(0);
    TOFTCTransfer(D_0030E060);

    {
        void **tsk = sa_task_init2(1, func_0016BB88(1, sa_task_buff_size_get(1)), 0);
        D_0030E064 = (void (**)(void))tsk;
        ((void (*)(void (*)(void), int, int))tsk[2])(func_0016BCA0, 1, 0);
    }

    _to_D_00597E30 = (ToRegVal *)func_0016BB88(1, 0x400);
    func_002EF0D0(_to_D_00597E30, 0, 0x400);
    _bce0_B8 = (void *)func_0016BB88(1, 0x4000);
    func_002EF0D0(_bce0_B8, 0, 0x4000);

    D_0030E0C0 = (ChrRec1D8 *)0;
    _bce0_D0 = 0;
    _bce0_D8 = 0;
    _bce0_D4 = 0;
    D_0057CB90 = 0;
    dvd_hdd_copy_system_cnf_buff = 0;
    D_0030E05C = 0;
    if (arg0 == 4) {
        D_0057CB94 = -1;
        D_0057CB88 = 0;
        D_0057CB8C = 0;
        size = ((int (*)(int))((s32 *)&D_0078E498)[5])(0xF);
        D_0057CB90 = size;
        _bce0_D8 = (void *)func_0016BB88(1, size);
        D_0078E498.f00(0xF, _bce0_D8, 0, 0);
        D_0078E498.f08(0);

        _bce0_D0 = (void *)func_0016BB88(1, D_0078E498.f14(0x10));
        D_0078E498.f00(0x10, _bce0_D0, 0, 0);
        D_0078E498.f08(0);

        _bce0_D4 = (void *)func_0016BB88(1, D_0078E498.f14(0x11));
        D_0078E498.f00(0x11, _bce0_D4, 0, 0);
        D_0078E498.f08(0);

        D_0078E498.f10(1);
        size = D_0078E498.f14(0xD);
        dvd_hdd_copy_system_cnf_buff = (u8 *)func_0016BB88(1, size + 4);
        D_0030E05C = size;
        dvd_hdd_copy_system_cnf_buff[0] = 0;
        D_0078E498.f00(0xD, dvd_hdd_copy_system_cnf_buff, 0, 0);
        D_0078E498.f08(0);
        dvd_hdd_copy_system_cnf_buff[D_0030E05C] = 0;
        D_0078E498.f10(_to_D_0030E070.w1C);
    } else {
        D_0030E0C0 = (ChrRec1D8 *)func_0016BB88(1, D_0078E498.f14(0));
        D_0078E498.f00(0, D_0030E0C0, 0, 0);
        D_0078E498.f08(0);
    }
    {
        int p = func_0016BB88(1, D_0078E498.f14(_to_D_0030E070.w14));
        int id = _to_D_0030E070.w14;
        _m2c_D_0030E0C8 = p;
        D_0078E498.f00(id, p, 0, 0);
    }
    D_0078E498.f08(0);
    D_0030E0BC = (s32)(void *)func_0016BB88(1, 0x42000);
    func_0016B7D8();
    if (arg0 == 4) {
        func_00162CD8(1);
        hdd_ins_size_check();
    }
    if (flag == 0) {
        func_0016B898();
    } else {
        func_0016BA00();
    }
}

int func_0016C318(void) {
    return D_0030E060;
}

typedef union {
    u_long128 q;
    struct {
        u64 d0;
        u64 d1;
    } ad;
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } w;
} ToGifQword;

#define SET_AD(p, d_val, r_val) \
    { \
        ToGifQword *_q = (p); \
        _q->ad.d0 = (d_val); \
        _q->ad.d1 = (r_val); \
    }

#define SET_W4(p, a, b, c, d) \
    { \
        ToGifQword *_q = (p); \
        _q->w.w0 = (a); \
        _q->w.w1 = (b); \
        _q->w.w2 = (c); \
        _q->w.w3 = (d); \
    }

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C328);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C688);

void func_0016C920(ToGifQword *p, int x, int y, int w, int h)
{
    p[0].q = 0;
    SET_AD(&p[1], 0x1000000000000004UL, 0xE);
    SET_AD(&p[2], 0x44, 0x42);
    SET_AD(&p[3], 0x5001D, 0x47);
    SET_AD(&p[4], 0, 0x49);
    SET_AD(&p[5], 0, 0x14);
    SET_AD(&p[6], 0x8022400000008001UL, 0x41414141);

    x += 0x700;
    y += 0x730;

    SET_W4(&p[7], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[8], (x - 4) << 4, (y - 4) << 4, 0xFFFFFF, 0);
    SET_W4(&p[9], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[10], (x + w + 4) << 4, (y - 4) << 4, 0xFFFFFF, 0);
    SET_W4(&p[11], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[12], (x - 4) << 4, (y + h + 6) << 4, 0xFFFFFF, 0);
    SET_W4(&p[13], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[14], (x + w + 4) << 4, (y + h + 6) << 4, 0xFFFFFF, 0);

    p[15].q = 0;
    p[15].w.w0 = 0x70000000;
    p[0].w.w0 = 0x1000000E;
}

PartySlot *func_0016CAC8(int id) {
    return MsGetSavePlayerPtr(id);
}

int func_0016CAE8(void) {
    int a = MsGetSaveBattleCount();

    return a - TkGetEncountCounterEventStart();
}

int func_0016CB18(void) {
    return MsGetSaveBattleCount();
}

int func_0016CB38(int id) {
    return func_0016CAC8(id)->v50;
}

int func_0016CB58(int id) {
    return func_0016CAC8(id)->v58;
}

int func_0016CB78(int id) {
    return func_0016CAC8(id)->v54;
}

/* Character-record accessors: MsGetSaveCommand(chr, id) flag tests (ids 0x30xx) and ChrRec1D8 field getters (D_0030E0C0[i]). */

int func_0016CB98(int a) {
    return func_001BFE30(a);
}

int func_0016CBB8(void) {
    return MsImportantGet();
}

int func_0016CBD8(void) {
    return MsGetGIL();
}

s8 func_0016CBF8(int i) {
    return ((s8 *)MsGetSaveEventFlag())[i];
}

s32 func_0016CC28(s32 arg0) {
    return ((s8) *(s8 *)(MsGetSaveEventFlag() + (((s32)arg0 / 8))) >> (arg0 & 7)) & 1;
}

int func_0016CC78(void) {
    return func_0014AC00();
}

int func_0016CC98(void) {
    return func_0014AF20();
}

int func_0016CCB8(int i) {
    return MsGetMonsterCapture(i);
}

int func_0016CCD8(void) {
    return hdd_rmode_get();
}

int func_0016CCF8(void) {
    if (D_00597A18 & 0x20) {
        return 1;
    }
    return 0;
}

/* DEBT(FAKE) */
s32 func_0016CD10(void) {
    register s32 var_2 __asm__("$2");

    var_2 = 0;
    if (D_0030E0C5 != 0) {
        var_2 = ((D_00597A18 | D_00597A1C) & 0xF000) != 0;
    }
    return var_2;
}

int func_0016CD48(int id) {
    return MsGetSavePlyJoin(id) == 1;
}

int func_0016CD70(void) {
    if (D_00597A18 & 0x40) {
        return 1;
    }
    return 0;
}

int func_0016CD88(void) {
    return D_00597A04;
}
