/* tu_201 0x1d48d0-0x1d8078: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#define MsActionRequest _hdr_MsActionRequest
#include "ffx/q4.h"
#undef MsActionRequest
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

extern int MsGetRamChrMonster(int);
extern void MsAtelRequestInit(void);
extern void MsAtelRequestAdd(int, int, int, int);
extern int MsAtelRequestExe(int, int, int, int, int, int);
extern void MsAtelParseSysTag(int, int, int);
extern GsEnt48 _ent_D_00662CC8 __asm__("D_00662CC8");

int MsActionRequest(int id_in, int a1, int a2, int a3, int a4, GsEnt48 *a5)
{
    u8 id = id_in;
    BtlChr *c = MsGetChr(id);
    int ret;

    if (a1 != 0xFF) {
        c->fAAD = a1;
    }
    ZanmatoSep = a4;
    func_001D4EC0(id);

    if (MsGetRamChrMonster(id) != 0) {
        MsAtelRequestInit();
        MsAtelRequestAdd(3, id, 0x3D, a2);
        ret = MsAtelRequestExe(3, id, 0x3D, 1, 0, 0);
        if (ret >= 0) {
            MsAtelParseSysTag(3, id, 0x3D);
        }
    } else {
        int tag = -1;
        if (a3 != 0) {
            switch (id) {
                case 0xE:
                    tag = 0x25;
                    break;
                case 0xF:
                    tag = 0x26;
                    break;
                case 0x10:
                    tag = 0x27;
                    break;
                case 0x11:
                    tag = 0x28;
                    break;
            }
        }
        MsAtelRequestInit();
        if (tag < 0) {
            tag = id + 0x29;
            MsAtelRequestAdd(2, 1, tag, a2);
            ret = MsAtelRequestExe(2, 1, tag, 1, 0, 0);
            if (ret >= 0) {
                MsAtelParseSysTag(2, 1, tag);
            }
        } else {
            MsAtelRequestAdd(2, 1, tag, a2);
            MsAtelRequestAdd(2, 0, tag, a2);
            ret = MsAtelRequestExe(2, 0, tag, 1, 0, 0);
            if (ret >= 0) {
                MsAtelParseSysTag(2, 0, tag);
            }
        }
    }

    if (_ent_D_00662CC8.f3 != 0 && (u32)a4 < 2) {
        if (a5 != 0) {
            *((u8 *)&_ent_D_00662CC8 + 4) = *((u8 *)a5 + 4); /* DEBT(CAST): GsEnt48 byte +4 */
            *a5 = _ent_D_00662CC8;
        } else if (a4 == 0) {
            MsSetBtlCommand(&_ent_D_00662CC8, 0, 0);
        } else {
            BtlChr *chr = 0;
            if (a1 != 0xFF && D_00662CBC == 0) {
                chr = MsGetChr(a1);
                if (chr != 0 && *((s8 *)chr + 0xAB1) == 0) { /* DEBT(CAST): BtlChr +0xAB1 */
                    if (MsCheckCommandCue(id, 1) != 0) {
                        chr = 0;
                    }
                }
            }
            if (chr == 0) {
                MsInsertBtlCommand(&_ent_D_00662CC8, D_00662CC0, a4, a1);
            }
        }
    }

    if (a2 < 9) {
        MsSetVoiceCheck(id, a2, 1, 0, 0);
    }
    ZanmatoSep = -1;
    return ret;
}

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

extern s8 D_00317327;
extern s8 D_0031732C;
extern s32 D_003188B0;
extern float MsGetChrCamWidth(int);
extern float MsGetChrCamHeight(int);
extern float MsGetChrHeight(int);
extern int MsGetYoujinbouCom(void);
extern int msCheckSameTarget(int, BtlChr *, int);
extern int MsGetChrVigor(int);
extern int MsCheckBtlPos(int, BtlChr *, int);
extern int MsAutoCommandStatusCheck(BtlChr *, int, int, int);
extern int MsGetRamChrHP(int);
extern int MsGetRamChrMP(int);
extern int MsGetRamChrHPmax(int);
extern int MsGetRamChrMPmax(int);
extern int MsGetChrStatDeath(int);
extern int func_001B6678(int);
extern int func_001B66A0(int);
extern int func_001B66B4(int);
extern int func_001B66C8(int);
extern int func_001B66DC(int);
extern int MsGetRamChrMonster(int);

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

extern int _m_MsGetChrStatPoison(int) __asm__("MsGetChrStatPoison");
extern int _m_MsGetChrStatStone(int) __asm__("MsGetChrStatStone");
extern int _m_func_001B65D8(int) __asm__("func_001B65D8");
extern int _m_func_001B6620(int) __asm__("func_001B6620");
extern int _m_func_00110B78(void *) __asm__("func_00110B78");

int MsGetChrStatInfo(int a0, int stat, int a2, int *out) {
    int sum = 0;
    int cnt = 0;
    int mask = MsGetChrBit(a0, a2, 0, 1);
    int i;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            BtlChr *c = MsGetChr(i);
            u8 *cp = (u8 *)c;
            u8 *sub = *(u8 **)(cp + 0xC48);
            switch (stat) {
            case 0:
                sum += MsGetRamChrHP(i); cnt++;
                break;
            case 1:
                sum += MsGetRamChrMP(i); cnt++;
                break;
            case 2:
                sum += MsGetRamChrHPmax(i); cnt++;
                break;
            case 3:
                sum += MsGetRamChrMPmax(i); cnt++;
                break;
            case 4:
                if (MsGetChrStatDeath(i) == 0) sum++;
                break;
            case 5:
                if (_m_MsGetChrStatPoison(i) == 1) sum++;
                break;
            case 6:
                if (_m_MsGetChrStatStone(i) == 1) sum++;
                break;
            case 7:
                if (_m_func_001B65D8(i) == 1) sum++;
                break;
            case 8:
                sum += _m_func_001B6620(i); cnt++;
                break;
            case 21:
                if (*(s8 *)(cp + 0xA88) != 0) sum++;
                break;
            case 22:
                if (*(u8 *)(cp + 0x250) & 1) sum++;
                break;
            case 23:
                if ((*(u8 *)(cp + 0x250) >> 1) & 1) sum++;
                break;
            case 24:
                if ((*(u8 *)(cp + 0x250) >> 2) & 1) sum++;
                break;
            case 25:
                if (MsGetRamChrMonster(i) != 0) sum++;
                break;
            case 26:
                if (*(s8 *)(cp + 0x1C5) != 0) sum++;
                break;
            case 27:
                if (D_00317327 == 0) { if (*(s8 *)(cp + 0xAAC) != 0) sum++; } else { if (*(s8 *)(cp + 0xAAC) == 0) sum++; }
                break;
            case 9:
                sum += *(u8 *)(cp + 0x268); cnt++;
                break;
            case 10:
                sum += *(u8 *)(cp + 0x269); cnt++;
                break;
            case 11:
                sum += *(u8 *)(cp + 0x26A); cnt++;
                break;
            case 12:
                sum += *(u8 *)(cp + 0x26B); cnt++;
                break;
            case 13:
                sum += *(u8 *)(cp + 0x26C); cnt++;
                break;
            case 14:
                sum += *(u8 *)(cp + 0x26D); cnt++;
                break;
            case 15:
                sum += *(u8 *)(cp + 0x26E); cnt++;
                break;
            case 16:
                sum += *(u8 *)(cp + 0x26F); cnt++;
                break;
            case 17:
                sum += *(u8 *)(cp + 0x27A); cnt++;
                break;
            case 18:
                sum += *(u8 *)(cp + 0x27B); cnt++;
                break;
            case 19:
                sum += *(u8 *)(cp + 0x27C); cnt++;
                break;
            case 20:
                sum += *(u8 *)(cp + 0x27D); cnt++;
                break;
            case 28:
                sum += *(s8 *)(cp + 0x1BC); cnt++;
                break;
            case 29:
                sum += *(s8 *)(cp + 0x1BE); cnt++;
                break;
            case 30:
                sum += *(s8 *)(cp + 0x1BF);
                break;
            case 31:
                sum += *(s8 *)(cp + 0x1C4); cnt++;
                break;
            case 32:
                sum += *(u16 *)(cp + 0x278) & 1;
                break;
            case 33:
                sum += (*(u16 *)(cp + 0x278) >> 1) & 1;
                break;
            case 34:
                sum += (*(u16 *)(cp + 0x278) >> 2) & 1;
                break;
            case 35:
                sum += (*(u16 *)(cp + 0x278) >> 3) & 1;
                break;
            case 36:
                sum += (*(u16 *)(cp + 0x278) >> 4) & 1;
                break;
            case 37:
                sum += (*(u16 *)(cp + 0x2C6) >> 4) & 1;
                break;
            case 38:
                sum += (*(u16 *)(cp + 0x2C6) >> 5) & 1;
                break;
            case 39:
                sum += (*(u16 *)(cp + 0x2C6) >> 6) & 1;
                break;
            case 40:
                sum += (*(u16 *)(cp + 0x2C6) >> 7) & 1;
                break;
            case 41:
                sum += (*(u16 *)(cp + 0x2C6) >> 8) & 1;
                break;
            case 42:
                sum += (*(u16 *)(cp + 0x2C6) >> 9) & 1;
                break;
            case 43:
                sum += (*(u16 *)(cp + 0x2C6) >> 10) & 1;
                break;
            case 44:
                sum += (*(u16 *)(cp + 0x2C6) >> 11) & 1;
                break;
            case 45:
                if (*(u8 *)(cp + 0x2C8) != 0) sum++;
                break;
            case 46:
                if (*(u8 *)(cp + 0x2C9) != 0) sum++;
                break;
            case 47:
                if (*(u8 *)(cp + 0x2CA) != 0) sum++;
                break;
            case 48:
                if (*(u8 *)(cp + 0x2CB) != 0) sum++;
                break;
            case 49:
                if (*(u8 *)(cp + 0x2CC) != 0) sum++;
                break;
            case 50:
                if (*(u8 *)(cp + 0x2CD) != 0) sum++;
                break;
            case 51:
                if (*(u8 *)(cp + 0x2CE) != 0) sum++;
                break;
            case 52:
                if (*(u8 *)(cp + 0x2CF) != 0) sum++;
                break;
            case 53:
                if (*(u8 *)(cp + 0x2D0) != 0) sum++;
                break;
            case 54:
                if (*(u8 *)(cp + 0x2D1) != 0) sum++;
                break;
            case 55:
                if (*(u8 *)(cp + 0x2D2) != 0) sum++;
                break;
            case 56:
                if (*(u8 *)(cp + 0x2D3) != 0) sum++;
                break;
            case 57:
                if (*(u8 *)(cp + 0x2D4) != 0) sum++;
                break;
            case 58:
                sum += *(u16 *)(cp + 0x37C) & 1;
                break;
            case 59:
                sum += (*(u16 *)(cp + 0x37C) >> 1) & 1;
                break;
            case 60:
                sum += (*(u16 *)(cp + 0x37C) >> 2) & 1;
                break;
            case 61:
                sum += (*(u16 *)(cp + 0x37C) >> 3) & 1;
                break;
            case 62:
                sum += (*(u16 *)(cp + 0x37C) >> 4) & 1;
                break;
            case 63:
                sum += (*(u16 *)(cp + 0x37C) >> 7) & 1;
                break;
            case 66:
                sum += (*(u16 *)(cp + 0x37C) >> 6) & 1;
                break;
            case 67:
                sum += (*(u16 *)(cp + 0x37C) >> 5) & 1;
                break;
            case 68:
                sum += (*(u16 *)(cp + 0x37C) >> 9) & 1;
                break;
            case 69:
                sum += (*(u16 *)(cp + 0x37C) >> 10) & 1;
                break;
            case 70:
                sum += (*(u16 *)(cp + 0x37C) >> 11) & 1;
                break;
            case 71:
                sum += (*(u16 *)(cp + 0x37C) >> 12) & 1;
                break;
            case 74:
                sum += (*(u16 *)(cp + 0x37C) >> 13) & 1;
                break;
            case 76:
                sum += *(u16 *)(cp + 0x37E) >> 15;
                break;
            case 77:
                sum += *(u16 *)(cp + 0x380) & 1;
                break;
            case 78:
                sum += (*(u16 *)(cp + 0x380) >> 1) & 1;
                break;
            case 79:
                sum += *(u8 *)(cp + 0xB5); cnt++;
                break;
            case 80:
                sum += *(s8 *)(cp + 0xA9D);
                break;
            case 81:
                sum += *(s8 *)(cp + 0xA96);
                break;
            case 82:
                sum += *(s8 *)(cp + 0xA99);
                break;
            case 83:
                sum += *(s8 *)(cp + 0xA97);
                break;
            case 84:
                sum += *(s8 *)(cp + 0x16);
                break;
            case 85:
                sum += *(s8 *)(cp + 0x1C9);
                break;
            case 86:
                sum += *(s8 *)(cp + 0x1CB);
                break;
            case 87:
                if (*(void **)cp != 0) sum += _m_func_00110B78(*(void **)cp);
                break;
            case 88:
                sum += *(s8 *)(cp + 0x24);
                break;
            case 89:
                sum += *(s8 *)(cp + 0xE2);
                break;
            case 90:
                sum += *(u8 *)(cp + 0xD6);
                break;
            case 91:
                sum += *(s8 *)(cp + 0xE0);
                break;
            case 93:
                sum += *(u8 *)(cp + 0xD2);
                break;
            case 94:
                sum += *(u8 *)(cp + 0xFE);
                break;
            case 95:
                sum += *(s8 *)(cp + 0x1C8);
                break;
            case 96:
                sum += *(s8 *)(cp + 0x1CD);
                break;
            case 97:
                sum += *(s8 *)(cp + 0x1CE);
                break;
            case 98:
                sum += *(u8 *)(cp + 0x29A) & 0x1;
                break;
            case 99:
                sum += (*(u8 *)(cp + 0x29A) >> 1) & 1;
                break;
            case 100:
                sum += (*(u8 *)(cp + 0x29A) >> 2) & 1;
                break;
            case 101:
                sum += (*(u8 *)(cp + 0x29A) >> 3) & 1;
                break;
            case 102:
                sum += (*(u8 *)(cp + 0x29A) >> 4) & 1;
                break;
            case 103:
                sum += *(u8 *)(cp + 0x29B) & 0x1;
                break;
            case 104:
                sum += (*(u8 *)(cp + 0x29B) >> 1) & 1;
                break;
            case 105:
                sum += (*(u8 *)(cp + 0x29B) >> 2) & 1;
                break;
            case 106:
                sum += (*(u8 *)(cp + 0x29B) >> 3) & 1;
                break;
            case 107:
                sum += (*(u8 *)(cp + 0x29B) >> 4) & 1;
                break;
            case 108:
                sum += *(u8 *)(cp + 0x29C) & 0x1;
                break;
            case 109:
                sum += (*(u8 *)(cp + 0x29C) >> 1) & 1;
                break;
            case 110:
                sum += (*(u8 *)(cp + 0x29C) >> 2) & 1;
                break;
            case 111:
                sum += (*(u8 *)(cp + 0x29C) >> 3) & 1;
                break;
            case 112:
                sum += (*(u8 *)(cp + 0x29C) >> 4) & 1;
                break;
            case 113:
                sum += *(u8 *)(cp + 0x29D) & 0x1;
                break;
            case 114:
                sum += (*(u8 *)(cp + 0x29D) >> 1) & 1;
                break;
            case 115:
                sum += (*(u8 *)(cp + 0x29D) >> 2) & 1;
                break;
            case 116:
                sum += (*(u8 *)(cp + 0x29D) >> 3) & 1;
                break;
            case 117:
                sum += (*(u8 *)(cp + 0x29D) >> 4) & 1;
                break;
            case 118:
                sum += *(u8 *)(cp + 0xE6);
                break;
            case 119:
                sum += *(u8 *)(cp + 0x107) & 0x1;
                break;
            case 120:
                sum += *(u8 *)(cp + 0x107) & 0x2;
                break;
            case 121:
                sum += *(u8 *)(cp + 0xAAB);
                break;
            case 122:
                sum += *(s8 *)(cp + 0x108);
                break;
            case 123:
                sum += *(u8 *)(cp + 0xCA);
                break;
            case 124:
                sum += *(u8 *)(cp + 0xCC); cnt++;
                break;
            case 125:
                sum += *(u8 *)(cp + 0xDE);
                break;
            case 126:
                sum += *(u8 *)(cp + 0xDF);
                break;
            case 127:
                sum += *(s8 *)(cp + 0x2D);
                break;
            case 128:
                sum += *(u8 *)(cp + 0xACC);
                break;
            case 129:
                if (sub != 0) sum += *(u16 *)(sub + 0x24);
                break;
            case 130:
                if (sub != 0) sum += *(u8 *)(sub + 0x28);
                break;
            case 131:
                if (sub != 0) sum += *(u16 *)(sub + 0x26);
                break;
            case 132:
                if (sub != 0) sum += *(u8 *)(sub + 0x29);
                break;
            case 133:
                sum += *(s8 *)(cp + 0x111);
                break;
            case 134:
                sum += *(s8 *)(cp + 0xFD);
                break;
            case 135:
                sum += *(s8 *)(cp + 0xAB9);
                break;
            case 136:
                sum += *(u8 *)(cp + 0x3D9);
                break;
            case 137:
                sum += *(u8 *)(cp + 0x3D8);
                break;
            case 138:
                if (sub != 0) sum += *(u8 *)(sub + 0x8);
                break;
            case 139:
                if (sub != 0) sum += *(u8 *)(sub + 0x9);
                break;
            case 140:
                if (sub != 0) sum += *(u8 *)(sub + 0xB);
                break;
            case 141:
                if (sub != 0) sum += *(u8 *)(sub + 0xA);
                break;
            case 142:
                sum += *(s8 *)(cp + 0xA92);
                break;
            case 143:
                sum += *(u16 *)(cp + 0x2D6) & 1;
                break;
            case 144:
                sum += (*(u16 *)(cp + 0x2D6) >> 1) & 1;
                break;
            case 145:
                sum += (*(u16 *)(cp + 0x2D6) >> 2) & 1;
                break;
            case 146:
                sum += (*(u16 *)(cp + 0x2D6) >> 3) & 1;
                break;
            case 147:
                sum += (*(u16 *)(cp + 0x2D6) >> 4) & 1;
                break;
            case 148:
                sum += (*(u16 *)(cp + 0x2D6) >> 5) & 1;
                break;
            case 149:
                sum += (*(u16 *)(cp + 0x2D6) >> 6) & 1;
                break;
            case 150:
                sum += (*(u16 *)(cp + 0x2D6) >> 7) & 1;
                break;
            case 151:
                sum += (*(u16 *)(cp + 0x2D6) >> 8) & 1;
                break;
            case 152:
                sum += (*(u16 *)(cp + 0x2D6) >> 9) & 1;
                break;
            case 153:
                sum += (*(u16 *)(cp + 0x2D6) >> 10) & 1;
                break;
            case 154:
                sum += (*(u16 *)(cp + 0x2D6) >> 11) & 1;
                break;
            case 155:
                sum += (*(u16 *)(cp + 0x2D6) >> 12) & 1;
                break;
            case 156:
                sum += (*(u16 *)(cp + 0x2D6) >> 13) & 1;
                break;
            case 157:
                sum += (*(u16 *)(cp + 0x2D6) >> 14) & 1;
                break;
            case 158:
                sum += func_001D5790(c);
                break;
            case 159:
                sum += *(u8 *)(cp + 0x289);
                break;
            case 160:
                sum += *(u8 *)(cp + 0x288);
                break;
            case 161:
                sum += *(s8 *)(cp + 0x10E);
                break;
            case 162:
                sum += *(u8 *)(cp + 0xDC);
                break;
            case 163:
                sum += *(u8 *)(cp + 0xDD);
                break;
            case 164:
                sum += *(u8 *)(cp + 0xDB);
                break;
            case 165:
                sum += *(s8 *)(cp + 0xF3);
                break;
            case 166:
                sum += *(s32 *)(cp + 0x9F4);
                break;
            case 167:
                sum += *(s32 *)(cp + 0x9F8);
                break;
            case 168:
                sum += *(s32 *)(cp + 0x9FC);
                break;
            case 169:
                sum += *(u8 *)(cp + 0xE3);
                break;
            case 170:
                sum += *(u8 *)(cp + 0xACE);
                break;
            case 171:
                sum += *(u8 *)(cp + 0xE5);
                break;
            case 172:
                sum += *(s8 *)(cp + 0xA93);
                break;
            case 173:
                sum += *(s8 *)(cp + 0xA8D);
                break;
            case 174:
                sum += (s8)(*(u8 *)(cp + 0x17) ^ 1);
                break;
            case 175:
                sum += *(u8 *)(cp + 0x301);
                break;
            case 178:
                sum += *(u8 *)(cp + 0x304);
                break;
            case 177:
                sum += *(u8 *)(cp + 0x303);
                break;
            case 176:
                sum += *(u8 *)(cp + 0x302);
                break;
            case 179:
                sum += *(u8 *)(cp + 0x305);
                break;
            case 180:
                sum += *(u8 *)(cp + 0x306);
                break;
            case 181:
                sum += *(u8 *)(cp + 0x307);
                break;
            case 182:
                sum += *(u8 *)(cp + 0x308);
                break;
            case 183:
                sum += *(u8 *)(cp + 0x309);
                break;
            case 184:
                sum += *(u8 *)(cp + 0x30A);
                break;
            case 185:
                sum += *(u8 *)(cp + 0x30B);
                break;
            case 186:
                sum += *(u8 *)(cp + 0x30C);
                break;
            case 187:
                sum += *(u8 *)(cp + 0x30D);
                break;
            case 188:
                sum += *(u8 *)(cp + 0x30E);
                break;
            case 189:
                sum += *(u8 *)(cp + 0x30F);
                break;
            case 190:
                sum += *(u8 *)(cp + 0x310);
                break;
            case 191:
                sum += *(u8 *)(cp + 0x311);
                break;
            case 192:
                sum += *(u8 *)(cp + 0x312);
                break;
            case 193:
                sum += *(u8 *)(cp + 0x313);
                break;
            case 194:
                sum += *(u8 *)(cp + 0x314);
                break;
            case 195:
                sum += *(u8 *)(cp + 0x315);
                break;
            case 196:
                sum += *(u8 *)(cp + 0x316);
                break;
            case 197:
                sum += *(u8 *)(cp + 0x317);
                break;
            case 198:
                sum += *(u8 *)(cp + 0x318);
                break;
            case 199:
                sum += *(u8 *)(cp + 0x319);
                break;
            case 200:
                sum += *(u16 *)(cp + 0x31A) & 1;
                break;
            case 201:
                sum += (*(u16 *)(cp + 0x31A) >> 1) & 1;
                break;
            case 202:
                sum += (*(u16 *)(cp + 0x31A) >> 2) & 1;
                break;
            case 203:
                sum += (*(u16 *)(cp + 0x31A) >> 3) & 1;
                break;
            case 204:
                sum += (*(u16 *)(cp + 0x31A) >> 4) & 1;
                break;
            case 205:
                sum += (*(u16 *)(cp + 0x31A) >> 5) & 1;
                break;
            case 206:
                sum += (*(u16 *)(cp + 0x31A) >> 6) & 1;
                break;
            case 207:
                sum += (*(u16 *)(cp + 0x31A) >> 7) & 1;
                break;
            case 208:
                sum += (*(u16 *)(cp + 0x31A) >> 9) & 1;
                break;
            case 209:
                sum += (*(u16 *)(cp + 0x31A) >> 8) & 1;
                break;
            case 210:
                sum += (*(u16 *)(cp + 0x31A) >> 10) & 1;
                break;
            case 211:
                sum += (*(u16 *)(cp + 0x31A) >> 11) & 1;
                break;
            case 212:
                sum += (*(u16 *)(cp + 0x31A) >> 12) & 1;
                break;
            case 213:
                sum += (*(u16 *)(cp + 0x31A) >> 13) & 1;
                break;
            case 214:
                sum += (*(u16 *)(cp + 0x31A) >> 14) & 1;
                break;
            case 215:
                sum += *(s8 *)(cp + 0xA98);
                break;
            case 216:
                sum += *(s8 *)(cp + 0x19);
                break;
            case 217:
                sum += *(s8 *)(cp + 0x1B);
                break;
            case 218:
                { int v = *(u16 *)(cp + 0x170); if (c->fC0 != 0) v = (v << 8) / c->fC0; sum += v; }
                break;
            case 219:
                { int v = *(u16 *)(cp + 0x172); if (c->fC0 != 0) v = (v << 8) / c->fC0; sum += v; }
                break;
            case 220:
                sum += *(s8 *)(cp + 0xFB);
                break;
            case 221:
                sum += MsGetChrVigor(i);
                break;
            case 222:
                sum += *(u8 *)(cp + 0x23);
                break;
            case 223:
                if (MsGetChrStatDeath(i) == 0 && _m_MsGetChrStatStone(i) == 0) sum++;
                break;
            case 224:
                sum += *(u8 *)(cp + 0x106);
                break;
            case 225:
                sum += *(s8 *)(cp + 0xA9A);
                break;
            case 226:
                sum += *(u8 *)(cp + 0xAD0);
                break;
            case 227:
                sum += *(u8 *)(cp + 0xAD1);
                break;
            case 228:
                sum += *(s8 *)(cp + 0x178);
                break;
            case 229:
                sum += *(u8 *)(cp + 0xC8);
                break;
            case 230:
                sum += *(u8 *)(cp + 0x179);
                break;
            case 231:
                sum += *(u8 *)(cp + 0x17A);
                break;
            case 232:
                sum += *(u8 *)(cp + 0x31C);
                break;
            case 233:
                sum += *(u8 *)(cp + 0xE4);
                break;
            case 234:
                sum += *(u8 *)(cp + 0x17B);
                break;
            case 235:
                sum += *(u8 *)(cp + 0xC34);
                break;
            case 236:
                sum += *(u8 *)(cp + 0xC35);
                break;
            case 237:
                sum += *(s8 *)(cp + 0x18);
                break;
            case 238:
                sum += *(s8 *)(cp + 0x21);
                break;
            case 239:
                sum += *(s8 *)(cp + 0x22);
                break;
            case 240:
                sum += (*(u16 *)(cp + 0x278) >> 8) & 1;
                break;
            case 241:
                sum += *(s8 *)(cp + 0x26);
                break;
            case 242:
                if (MsGetChrStatDeath(i) == 1) sum++;
                break;
            case 243:
                if (MsGetChrStatDeath(i) == 1 || _m_MsGetChrStatStone(i) == 1) sum++;
                break;
            case 244:
                if (MsCheckBtlPos(i, c, *(s8 *)(cp + 0x34)) != 0) sum++;
                break;
            case 245:
                sum += *(s8 *)(cp + 0xFC);
                break;
            case 246:
                sum += *(u8 *)(cp + 0x39B);
                break;
            case 247:
                sum += *(s8 *)(cp + 0x10A);
                break;
            case 248:
                if (*(s8 *)(cp + 0xA88) != 0 && MsGetChrStatDeath(i) == 0 && _m_MsGetChrStatStone(i) == 0 && *(u16 *)(cp + 0x2C8) == 0) sum++;
                break;
            case 249:
                if (*(s8 *)(cp + 0xA88) != 0 && MsGetChrStatDeath(i) == 0 && _m_MsGetChrStatStone(i) == 0 && *(u16 *)(cp + 0x2C8) == 0 && ((*(u16 *)(cp + 0x2C6) >> 8) & 1) == 0 && ((*(u16 *)(cp + 0x2C6) >> 9) & 1) == 0) sum++;
                break;
            case 250:
                sum += *(s8 *)(cp + 0x10B);
                break;
            case 251:
                sum += *(u16 *)(cp + 0xC0);
                break;
            case 252:
                sum += *(u8 *)(cp + 0xC5);
                break;
            case 253:
                sum += *(u8 *)(cp + 0x174);
                break;
            case 254:
                if (*(s8 *)(cp + 0xA88) != 0 && MsGetChrStatDeath(i) == 0 && _m_MsGetChrStatStone(i) == 0 && *(u16 *)(cp + 0x2C8) == 0 && ((*(u16 *)(cp + 0x2C6) >> 8) & 1) == 0 && ((*(u16 *)(cp + 0x2C6) >> 9) & 1) == 0 && MsGetChrVigor(i) != 0) sum++;
                break;
            case 255:
                sum += MsAutoCommandStatusCheck(c, 0, 0, 1);
                break;
            case 256:
                sum += *(u8 *)(cp + 0x28B);
                break;
            case 257:
                sum += *(u8 *)(cp + 0x284);
                break;
            case 258:
                sum += *(u8 *)(cp + 0x38E);
                break;
            case 259:
                sum += *(u8 *)(cp + 0x283);
                break;
            case 260:
                sum += *(s16 *)(cp + 0xADA);
                break;
            case 261:
                sum += (int)(*(float *)(cp + 0x1A8) * 100.0f);
                break;
            case 262:
                sum += *(u8 *)(cp + 0x391);
                break;
            case 263:
                sum += (*(u16 *)(cp + 0x278) >> 7) & 1;
                break;
            case 264:
                sum += (*(u16 *)(cp + 0x278) >> 6) & 1;
                break;
            case 265:
                sum += (*(u16 *)(cp + 0x278) >> 5) & 1;
                break;
            case 266:
                if (sub != 0) sum += *(u16 *)(sub + 0x6);
                break;
            case 267:
                sum += (*(u16 *)(cp + 0x278) >> 9) & 1;
                break;
            case 268:
                sum += *(s32 *)(cp + 0x264);
                break;
            case 269:
                sum += *(u8 *)(cp + 0xC9);
                break;
            case 270:
                sum += (int)MsGetChrCamWidth(i) * 100;
                break;
            case 271:
                sum += (int)MsGetChrCamHeight(i) * 100;
                break;
            case 272:
                sum += (int)MsGetChrHeight(i) * 100;
                break;
            case 273:
                sum += MsGetYoujinbouCom();
                break;
            case 274:
                sum += D_003188B0;
                break;
            case 275:
                if (sub != 0 && sum < *(u8 *)(sub + 0x112)) sum = *(u8 *)(sub + 0x112);
                break;
            case 276:
                sum += *(u8 *)(cp + 0x39F);
                break;
            case 277:
                sum += *(u8 *)(cp + 0x3A0);
                break;
            case 278:
                sum += *(u8 *)(cp + 0xCD);
                break;
            case 279:
                sum += *(u8 *)(cp + 0x3A1);
                break;
            case 280:
                sum += *(u8 *)(cp + 0x27C); cnt++;
                break;
            case 281:
                if (*(u32 *)(cp + 0x290) < (*(u32 *)(cp + 0x254) >> 1)) sum++;
                break;
            case 282:
                if ((u32)(i - 0xF) < 3 && (*(u8 *)(cp + 0x27C) >= *(u8 *)(cp + 0x27D) || D_0031732C != 0) && *(s8 *)(cp + 0xA8C) == 0 && ((*(u16 *)(cp + 0x2D6) >> 10) & 1) == 0 && MsAutoCommandStatusCheck(c, 1, 1, 1) != 0) sum++;
                break;
            case 283:
                if (*(u32 *)(cp + 0x290) >= *(u32 *)(cp + 0x254)) sum++;
                break;
            case 284:
                if (*(u32 *)(cp + 0x294) >= *(u32 *)(cp + 0x258)) sum++;
                break;
            case 285:
                if (*(u8 *)(cp + 0x2CE) != 0 && *(u8 *)(cp + 0x2CF) != 0 && *(u8 *)(cp + 0x2D0) != 0 && *(u8 *)(cp + 0x2D1) != 0) sum++;
                break;
            case 286:
                if (*(u8 *)(cp + 0x2CB) != 0 || *(u8 *)(cp + 0x2CD) != 0) sum++;
                break;
            case 287:
                if (*(u16 *)(cp + 0x2CC) != 0) sum++;
                break;
            case 288:
                if (*(u8 *)(cp + 0x2D3) != 0 || *(u8 *)(cp + 0x2CD) != 0) sum++;
                break;
            case 92:
                sum++;
                break;
            case 289:
                sum += *(u8 *)(cp + 0x10F);
                break;
            case 290:
                sum += (*(u16 *)(cp + 0x278) >> 10) & 1;
                break;
            case 291:
                sum += *(u8 *)(cp + 0xCE);
                break;
            case 292:
                sum += func_001D5790(c);
                break;
            case 293:
                sum += func_001D5790(c);
                break;
            case 294:
                sum += *(u8 *)(cp + 0x3C0);
                break;
            case 295:
                sum += *(s8 *)(cp + 0xA8A);
                break;
            case 296:
                sum += (int)(*(float *)(cp + 0x1AC)) * 100;
                break;
            case 297:
                sum += *(u8 *)(cp + 0xB8);
                break;
            case 298:
                if (msCheckSameTarget(i, c, *(s32 *)(cp + 0xA80)) == 0) sum++;
                break;
            case 299:
                if (sub != 0) sum = *(u16 *)(sub + 0x2);
                break;
            case 300:
                if (sub != 0) sum = *(u16 *)(sub + 0x4);
                break;
            case 301:
                if (sub != 0) sum = *(u16 *)(sub + 0x0);
                break;
            case 302:
                sum += *(u8 *)(cp + 0x270);
                break;
            case 303:
                sum += *(u8 *)(cp + 0x271);
                break;
            case 304:
                sum += *(u8 *)(cp + 0x272);
                break;
            case 305:
                sum += *(u8 *)(cp + 0x273);
                break;
            case 306:
                sum += *(u8 *)(cp + 0x274);
                break;
            case 307:
                sum += *(u8 *)(cp + 0x275);
                break;
            case 308:
                sum += *(u8 *)(cp + 0x276);
                break;
            case 309:
                sum += *(u8 *)(cp + 0x277);
                break;
            case 310:
                sum += *(u8 *)(cp + 0x38C);
                break;
            case 311:
                sum += *(u8 *)(cp + 0x38D);
                break;
            case 312:
                sum += *(u8 *)(cp + 0x38F);
                break;
            case 313:
                sum += *(u8 *)(cp + 0x390);
                break;
            case 314:
                if (sub != 0) sum += *(u16 *)(sub + 0xC);
                break;
            case 315:
                if (sub != 0) sum += *(u16 *)(sub + 0xE);
                break;
            case 316:
                if (sub != 0) sum += *(u16 *)(sub + 0x10);
                break;
            case 317:
                if (sub != 0) sum += *(u16 *)(sub + 0x12);
                break;
            case 318:
                if (sub != 0) sum += *(u16 *)(sub + 0x18);
                break;
            case 319:
                if (sub != 0) sum += *(u16 *)(sub + 0x1A);
                break;
            case 320:
                if (sub != 0) sum += *(u16 *)(sub + 0x1C);
                break;
            case 321:
                if (sub != 0) sum += *(u16 *)(sub + 0x1E);
                break;
            case 322:
                if (sub != 0) sum += *(u8 *)(sub + 0x14);
                break;
            case 323:
                if (sub != 0) sum += *(u8 *)(sub + 0x15);
                break;
            case 324:
                if (sub != 0) sum += *(u8 *)(sub + 0x16);
                break;
            case 325:
                if (sub != 0) sum += *(u8 *)(sub + 0x17);
                break;
            case 326:
                if (sub != 0) sum += *(u8 *)(sub + 0x20);
                break;
            case 327:
                if (sub != 0) sum += *(u8 *)(sub + 0x21);
                break;
            case 328:
                if (sub != 0) sum += *(u8 *)(sub + 0x22);
                break;
            case 329:
                if (sub != 0) sum += *(u8 *)(sub + 0x23);
                break;
            case 330:
                sum += *(u8 *)(cp + 0xB9);
                break;
            case 332:
                sum += *(s8 *)(cp + 0x2D);
                break;
            case 333:
                sum += MsGetSavePlyJoin(i);
                break;
            case 334:
                sum += *(u8 *)(cp + 0x3B);
                break;
            case 335:
                sum += *(u8 *)(cp + 0xF7);
                break;
            case 336:
                sum += *(s8 *)(cp + 0x1C);
                break;
            case 337:
                sum += *(s8 *)(cp + 0xA9B);
                break;
            case 338:
                sum += *(u8 *)(cp + 0x102);
                break;
            case 339:
                sum += *(s8 *)(cp + 0x39);
                break;
            case 340:
                sum += *(u8 *)(cp + 0xBB);
                break;
            case 341:
                if (*(s8 *)(cp + 0xA88) != 0 && _m_MsGetChrStatStone(i) == 0 && ((*(u16 *)(cp + 0x2D6) >> 8) & 1) == 0) sum++;
                break;
            case 342:
                sum += *(s8 *)(cp + 0xA91);
                break;
            case 343:
                sum += *(s8 *)(cp + 0x1C6);
                break;
            case 344:
                sum += *(s8 *)(cp + 0xA95);
                break;
            case 345:
                sum += *(u16 *)(cp + 0xA9E);
                break;
            }
        }
    }
    if (cnt > 0) {
        sum /= cnt;
    } else {
        cnt = sum;
    }
    if (out != 0) {
        *out = sum;
    }
    return cnt;
}

extern int MsCheckRange(int, int, int);
extern void func_001C7718(int, BtlChr *, int);
extern void Ch_EffectSetEffectLevel(Chr *, int);
extern int func_001B8198(int, int, int, int);
extern void MsBlowProcess(int, BtlChr *);
extern void func_001B57B0(int, int);
extern void func_001B5790(int, int);
extern void func_001B5770(int, int);
extern void func_00110958(Chr *, float);
extern void func_00110988(Chr *, float);
extern void func_001109B8(Chr *, float);
extern void MsAddYoujinbouCom(int);
extern void func_001D34A0(BtlChr *);
extern void MsSetChrImageDamageAttack(BtlChr *);
extern void MsSetChrImageDamageMagic(BtlChr *);
extern void MsStatusEffectCheck(int);
extern void MsDamageCheckDeath(int, int, int, int);
extern void MsResetAutoStatus(BtlChr *);
extern void MsSetRamChrParam(int);
extern void MsSetAutoStatus(BtlChr *);

typedef struct { u16 b0:1, b1:1, b2:1, b3:1, rest:12; } Bf2C6;
typedef struct { u8 b0:1, b1:1, b2:1, rest:5; } Bf250;
typedef struct { u16 low:8, b8:1, rest:7; } Bf278;

int MsSetChrStatInfo(int a0, int stat, int a2, int val) {
    int mask;
    int count = 0;
    int bit = val & 1;
    int r1_255 = MsCheckRange(val, 1, 255);
    int r0_255 = MsCheckRange(val, 0, 255);
    int r1_100 = MsCheckRange(val, 1, 100);
    int i;
    mask = MsGetChrBit(a0, a2, 0, 1);
    for (i = 0; i < 0x1F; i++) {
        int recalc = 0;
        int weak = 0;
        int eff = 0;
        if ((mask >> i) & 1) {
            BtlChr *c = MsGetChr(i);
            u8 *cp = (u8 *)c;
            Chr *chr = c->chr;
            u8 *sub = *(u8 **)(cp + 0xC48);
            switch (stat) {
            case 0:
                *(s32 *)(cp + 0x290) = val; weak = 1; if ((*(u16 *)(cp + 0x2C6) & 1) && val > 0) *(u16 *)(cp + 0x2C6) &= ~1;
                break;
            case 1:
                *(s32 *)(cp + 0x294) = val;
                break;
            case 2:
                *(s32 *)(cp + 0x254) = val;
                break;
            case 3:
                *(s32 *)(cp + 0x258) = val;
                break;
            case 4:
                ((Bf2C6 *)(cp + 0x2C6))->b0 = val; weak = 1; eff = 1; func_001C7718(i, c, i);
                break;
            case 5:
                ((Bf2C6 *)(cp + 0x2C6))->b3 = val; eff = 1;
                break;
            case 6:
                ((Bf2C6 *)(cp + 0x2C6))->b2 = val; eff = 1;
                break;
            case 7:
                ((Bf2C6 *)(cp + 0x2C6))->b1 = val; eff = 1;
                break;
            case 8:
                *(u8 *)(cp + 0x2FD) = val;
                break;
            case 9:
                *(u8 *)(cp + 0x268) = r1_255; MsSetChrImageDamageAttack(c);
                break;
            case 10:
                *(u8 *)(cp + 0x269) = r1_255;
                break;
            case 11:
                *(u8 *)(cp + 0x26A) = r1_255;
                break;
            case 12:
                *(u8 *)(cp + 0x26B) = r1_255;
                break;
            case 13:
                *(u8 *)(cp + 0x26C) = r1_255;
                break;
            case 14:
                *(u8 *)(cp + 0x26D) = r1_255;
                break;
            case 15:
                *(u8 *)(cp + 0x26E) = r0_255;
                break;
            case 16:
                *(u8 *)(cp + 0x26F) = r1_255;
                break;
            case 17:
                *(u8 *)(cp + 0x27A) = r0_255;
                break;
            case 18:
                *(u8 *)(cp + 0x27B) = r1_100;
                break;
            case 19:
                *(u8 *)(cp + 0x27C) = r1_100;
                break;
            case 20:
                *(u8 *)(cp + 0x27D) = r1_100;
                break;
            case 21:
                *(u8 *)(cp + 0xA88) = bit;
                break;
            case 22:
                ((Bf250 *)(cp + 0x250))->b0 = val;
                break;
            case 23:
                ((Bf250 *)(cp + 0x250))->b1 = val;
                break;
            case 24:
                ((Bf250 *)(cp + 0x250))->b2 = val;
                break;
            case 26:
                *(u8 *)(cp + 0x1C5) = bit;
                break;
            case 27:
                *(u8 *)(cp + 0xAAC) = bit;
                break;
            case 28:
                *(u8 *)(cp + 0x1BC) = val; *(u8 *)(cp + 0x1C9) = val; *(u8 *)(cp + 0x1C0) = val;
                break;
            case 29:
                *(u8 *)(cp + 0x1BE) = val; *(u8 *)(cp + 0x1CB) = val; *(u8 *)(cp + 0x1C2) = val;
                break;
            case 30:
                *(u8 *)(cp + 0x1BF) = val;
                break;
            case 31:
                *(u8 *)(cp + 0x1C4) = val & 7;
                break;
            case 32:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~1) | bit;
                break;
            case 33:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 1)) | (bit << 1);
                break;
            case 34:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 2)) | (bit << 2);
                break;
            case 35:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 3)) | (bit << 3);
                break;
            case 36:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 4)) | (bit << 4);
                break;
            case 37:
                *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 4)) | (bit << 4);
                break;
            case 38:
                *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 5)) | (bit << 5);
                break;
            case 39:
                *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 6)) | (bit << 6);
                break;
            case 40:
                *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 7)) | (bit << 7);
                break;
            case 41:
                eff = 1; *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 8)) | (bit << 8);
                break;
            case 42:
                eff = 1; *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 9)) | (bit << 9);
                break;
            case 43:
                eff = 1; *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 10)) | (bit << 10);
                break;
            case 44:
                eff = 1; *(u16 *)(cp + 0x2C6) = (*(u16 *)(cp + 0x2C6) & ~(1 << 11)) | (bit << 11);
                break;
            case 45:
                eff = 1; *(u8 *)(cp + 0x2C8) = val;
                break;
            case 46:
                eff = 1; *(u8 *)(cp + 0x2C9) = val;
                break;
            case 47:
                eff = 1; *(u8 *)(cp + 0x2CA) = val;
                break;
            case 48:
                eff = 1; *(u8 *)(cp + 0x2CB) = val;
                break;
            case 49:
                eff = 1; *(u8 *)(cp + 0x2CC) = val;
                break;
            case 50:
                eff = 1; *(u8 *)(cp + 0x2CD) = val;
                break;
            case 51:
                eff = 1; *(u8 *)(cp + 0x2CE) = val;
                break;
            case 52:
                eff = 1; *(u8 *)(cp + 0x2CF) = val;
                break;
            case 53:
                eff = 1; *(u8 *)(cp + 0x2D0) = val;
                break;
            case 54:
                eff = 1; *(u8 *)(cp + 0x2D1) = val;
                break;
            case 55:
                { u8 prev = *(u8 *)(cp + 0x2D2); *(u8 *)(cp + 0x2D2) = val; eff = 1; if (val != 0 && prev == 0) *(u8 *)(cp + 0x392) = 0; }
                break;
            case 56:
                eff = 1; *(u8 *)(cp + 0x2D3) = val;
                break;
            case 57:
                eff = 1; *(u8 *)(cp + 0x2D4) = val;
                break;
            case 58:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~1) | bit;
                break;
            case 59:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 1)) | (bit << 1);
                break;
            case 60:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 2)) | (bit << 2);
                break;
            case 61:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 3)) | (bit << 3);
                break;
            case 62:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 4)) | (bit << 4);
                break;
            case 63:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 7)) | (bit << 7);
                break;
            case 66:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 6)) | (bit << 6);
                break;
            case 67:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 5)) | (bit << 5);
                break;
            case 68:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 9)) | (bit << 9);
                break;
            case 69:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 10)) | (bit << 10);
                break;
            case 70:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 11)) | (bit << 11);
                break;
            case 71:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 12)) | (bit << 12);
                break;
            case 74:
                *(u16 *)(cp + 0x37C) = (*(u16 *)(cp + 0x37C) & ~(1 << 13)) | (bit << 13);
                break;
            case 76:
                *(u16 *)(cp + 0x37E) = (*(u16 *)(cp + 0x37E) & ~(1 << 15)) | (bit << 15);
                break;
            case 77:
                *(u16 *)(cp + 0x380) = (*(u16 *)(cp + 0x380) & ~1) | bit;
                break;
            case 78:
                *(u16 *)(cp + 0x380) = (*(u16 *)(cp + 0x380) & ~(1 << 1)) | (bit << 1);
                break;
            case 79:
                *(u8 *)(cp + 0xB5) = val; *(u8 *)(cp + 0xB6) = val;
                break;
            case 80:
                *(u8 *)(cp + 0xA9D) = bit;
                break;
            case 81:
                *(u8 *)(cp + 0xA96) = bit;
                break;
            case 82:
                *(u8 *)(cp + 0xA99) = bit;
                break;
            case 83:
                *(u8 *)(cp + 0xA97) = bit;
                break;
            case 84:
                func_001B57D0(i, bit);
                break;
            case 85:
                *(u8 *)(cp + 0x1C9) = val; *(u8 *)(cp + 0x1C0) = val;
                break;
            case 86:
                *(u8 *)(cp + 0x1CB) = val; *(u8 *)(cp + 0x1C2) = val;
                break;
            case 87:
                *(s32 *)(cp + 0xAEC) = val; if (chr != 0) Ch_EffectSetEffectLevel(chr, val);
                break;
            case 88:
                *(u8 *)(cp + 0x24) = bit;
                break;
            case 89:
                *(u8 *)(cp + 0xE2) = func_001B8198(i, val, 0, 1);
                break;
            case 90:
                *(u8 *)(cp + 0xD6) = func_001B8198(i, val, 0, 1);
                break;
            case 91:
                *(u8 *)(cp + 0xE0) = val;
                break;
            case 93:
                *(u8 *)(cp + 0xD2) = bit;
                break;
            case 94:
                *(u8 *)(cp + 0xFE) = bit;
                break;
            case 95:
                *(u8 *)(cp + 0x1C8) = bit;
                break;
            case 96:
                *(u8 *)(cp + 0x1CD) = bit;
                break;
            case 97:
                *(u8 *)(cp + 0x1CE) = bit; *(u8 *)(cp + 0x1CF) = 0;
                break;
            case 98:
                *(u8 *)(cp + 0x29A) = (*(u8 *)(cp + 0x29A) & ~1) | bit;
                break;
            case 99:
                *(u8 *)(cp + 0x29A) = (*(u8 *)(cp + 0x29A) & ~(1 << 1)) | (bit << 1);
                break;
            case 100:
                *(u8 *)(cp + 0x29A) = (*(u8 *)(cp + 0x29A) & ~(1 << 2)) | (bit << 2);
                break;
            case 101:
                *(u8 *)(cp + 0x29A) = (*(u8 *)(cp + 0x29A) & ~(1 << 3)) | (bit << 3);
                break;
            case 102:
                *(u8 *)(cp + 0x29A) = (*(u8 *)(cp + 0x29A) & ~(1 << 4)) | (bit << 4);
                break;
            case 103:
                *(u8 *)(cp + 0x29B) = (*(u8 *)(cp + 0x29B) & ~1) | bit;
                break;
            case 104:
                *(u8 *)(cp + 0x29B) = (*(u8 *)(cp + 0x29B) & ~(1 << 1)) | (bit << 1);
                break;
            case 105:
                *(u8 *)(cp + 0x29B) = (*(u8 *)(cp + 0x29B) & ~(1 << 2)) | (bit << 2);
                break;
            case 106:
                *(u8 *)(cp + 0x29B) = (*(u8 *)(cp + 0x29B) & ~(1 << 3)) | (bit << 3);
                break;
            case 107:
                *(u8 *)(cp + 0x29B) = (*(u8 *)(cp + 0x29B) & ~(1 << 4)) | (bit << 4);
                break;
            case 108:
                *(u8 *)(cp + 0x29C) = (*(u8 *)(cp + 0x29C) & ~1) | bit;
                break;
            case 109:
                *(u8 *)(cp + 0x29C) = (*(u8 *)(cp + 0x29C) & ~(1 << 1)) | (bit << 1);
                break;
            case 110:
                *(u8 *)(cp + 0x29C) = (*(u8 *)(cp + 0x29C) & ~(1 << 2)) | (bit << 2);
                break;
            case 111:
                *(u8 *)(cp + 0x29C) = (*(u8 *)(cp + 0x29C) & ~(1 << 3)) | (bit << 3);
                break;
            case 112:
                *(u8 *)(cp + 0x29C) = (*(u8 *)(cp + 0x29C) & ~(1 << 4)) | (bit << 4);
                break;
            case 113:
                *(u8 *)(cp + 0x29D) = (*(u8 *)(cp + 0x29D) & ~1) | bit;
                break;
            case 114:
                *(u8 *)(cp + 0x29D) = (*(u8 *)(cp + 0x29D) & ~(1 << 1)) | (bit << 1);
                break;
            case 115:
                *(u8 *)(cp + 0x29D) = (*(u8 *)(cp + 0x29D) & ~(1 << 2)) | (bit << 2);
                break;
            case 116:
                *(u8 *)(cp + 0x29D) = (*(u8 *)(cp + 0x29D) & ~(1 << 3)) | (bit << 3);
                break;
            case 117:
                *(u8 *)(cp + 0x29D) = (*(u8 *)(cp + 0x29D) & ~(1 << 4)) | (bit << 4);
                break;
            case 118:
                *(u8 *)(cp + 0xE6) = bit;
                break;
            case 119:
                if (bit != 0) *(u8 *)(cp + 0x107) |= 1; else *(u8 *)(cp + 0x107) &= ~1;
                break;
            case 120:
                if (bit != 0) *(u8 *)(cp + 0x107) |= 2; else *(u8 *)(cp + 0x107) &= ~2;
                break;
            case 121:
                *(u8 *)(cp + 0xAAB) = val;
                break;
            case 122:
                *(u8 *)(cp + 0x108) = bit;
                break;
            case 123:
                *(u8 *)(cp + 0xCA) = bit;
                break;
            case 124:
                *(u8 *)(cp + 0xCC) = val;
                break;
            case 125:
                *(u8 *)(cp + 0xDE) = bit;
                break;
            case 126:
                *(u8 *)(cp + 0xDF) = bit;
                break;
            case 127:
                msSetChrBodyHit(c, 0, bit);
                break;
            case 128:
                *(u8 *)(cp + 0xACC) = val;
                break;
            case 129:
                if (sub != 0) *(u16 *)(sub + 0x24) = val;
                break;
            case 130:
                if (sub != 0) *(u8 *)(sub + 0x28) = val;
                break;
            case 131:
                if (sub != 0) *(u16 *)(sub + 0x26) = val;
                break;
            case 132:
                if (sub != 0) *(u8 *)(sub + 0x29) = val;
                break;
            case 133:
                *(u8 *)(cp + 0x111) = val;
                break;
            case 134:
                *(u8 *)(cp + 0xFD) = val;
                break;
            case 135:
                *(u8 *)(cp + 0xAB9) = val;
                break;
            case 136:
                *(u8 *)(cp + 0x3D9) = bit;
                break;
            case 137:
                *(u8 *)(cp + 0x3D8) = bit;
                break;
            case 138:
                if (sub != 0) *(u8 *)(sub + 0x8) = val;
                break;
            case 139:
                if (sub != 0) *(u8 *)(sub + 0x9) = val;
                break;
            case 140:
                if (sub != 0) *(u8 *)(sub + 0xB) = val;
                break;
            case 141:
                if (sub != 0) *(u8 *)(sub + 0xA) = val;
                break;
            case 142:
                *(u8 *)(cp + 0xA92) = bit;
                break;
            case 143:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~1) | bit;
                break;
            case 144:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 1)) | (bit << 1);
                break;
            case 145:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 2)) | (bit << 2);
                break;
            case 146:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 3)) | (bit << 3);
                break;
            case 147:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 4)) | (bit << 4);
                break;
            case 148:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 5)) | (bit << 5);
                break;
            case 149:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 6)) | (bit << 6);
                break;
            case 150:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 7)) | (bit << 7);
                break;
            case 151:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 8)) | (bit << 8); MsBlowProcess(i, c);
                break;
            case 152:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 9)) | (bit << 9);
                break;
            case 153:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 10)) | (bit << 10);
                break;
            case 154:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 11)) | (bit << 11);
                break;
            case 155:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 12)) | (bit << 12);
                break;
            case 156:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 13)) | (bit << 13);
                break;
            case 157:
                *(u16 *)(cp + 0x2D6) = (*(u16 *)(cp + 0x2D6) & ~(1 << 14)) | (bit << 14);
                break;
            case 158:
                *(s32 *)(cp + 0x16C) = val;
                break;
            case 159:
                *(u8 *)(cp + 0x289) = val;
                break;
            case 160:
                *(u8 *)(cp + 0x288) = val;
                break;
            case 161:
                *(u8 *)(cp + 0x10E) = val;
                break;
            case 162:
                *(u8 *)(cp + 0xDC) = val;
                break;
            case 163:
                *(u8 *)(cp + 0xDD) = val;
                break;
            case 164:
                *(u8 *)(cp + 0xDB) = val;
                break;
            case 165:
                *(u8 *)(cp + 0xF3) = val;
                break;
            case 166:
                *(s32 *)(cp + 0x9F4) = val;
                break;
            case 167:
                *(s32 *)(cp + 0x9F8) = val;
                break;
            case 168:
                *(s32 *)(cp + 0x9FC) = val;
                break;
            case 169:
                *(u8 *)(cp + 0xE3) = val;
                break;
            case 170:
                *(u8 *)(cp + 0xACE) = val;
                break;
            case 171:
                *(u8 *)(cp + 0xE5) = val;
                break;
            case 172:
                *(u8 *)(cp + 0xA93) = bit;
                break;
            case 173:
                *(u8 *)(cp + 0xA8D) = bit;
                break;
            case 174:
                func_001B57F0(i, bit ^ 1);
                break;
            case 175:
                *(u8 *)(cp + 0x301) = val;
                break;
            case 178:
                *(u8 *)(cp + 0x304) = val;
                break;
            case 177:
                *(u8 *)(cp + 0x303) = val;
                break;
            case 176:
                *(u8 *)(cp + 0x302) = val;
                break;
            case 179:
                *(u8 *)(cp + 0x305) = val;
                break;
            case 180:
                *(u8 *)(cp + 0x306) = val;
                break;
            case 181:
                *(u8 *)(cp + 0x307) = val;
                break;
            case 182:
                *(u8 *)(cp + 0x308) = val;
                break;
            case 183:
                *(u8 *)(cp + 0x309) = val;
                break;
            case 184:
                *(u8 *)(cp + 0x30A) = val;
                break;
            case 185:
                *(u8 *)(cp + 0x30B) = val;
                break;
            case 186:
                *(u8 *)(cp + 0x30C) = val;
                break;
            case 187:
                *(u8 *)(cp + 0x30D) = val;
                break;
            case 188:
                *(u8 *)(cp + 0x30E) = val;
                break;
            case 189:
                *(u8 *)(cp + 0x30F) = val;
                break;
            case 190:
                *(u8 *)(cp + 0x310) = val;
                break;
            case 191:
                *(u8 *)(cp + 0x311) = val;
                break;
            case 192:
                *(u8 *)(cp + 0x312) = val;
                break;
            case 193:
                *(u8 *)(cp + 0x313) = val;
                break;
            case 194:
                *(u8 *)(cp + 0x314) = val;
                break;
            case 195:
                *(u8 *)(cp + 0x315) = val;
                break;
            case 196:
                *(u8 *)(cp + 0x316) = val;
                break;
            case 197:
                *(u8 *)(cp + 0x317) = val;
                break;
            case 198:
                *(u8 *)(cp + 0x318) = val;
                break;
            case 199:
                *(u8 *)(cp + 0x319) = val;
                break;
            case 200:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~1) | bit;
                break;
            case 201:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 1)) | (bit << 1);
                break;
            case 202:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 2)) | (bit << 2);
                break;
            case 203:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 3)) | (bit << 3);
                break;
            case 204:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 4)) | (bit << 4);
                break;
            case 205:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 5)) | (bit << 5);
                break;
            case 206:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 6)) | (bit << 6);
                break;
            case 207:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 7)) | (bit << 7);
                break;
            case 208:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 9)) | (bit << 9);
                break;
            case 209:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 8)) | (bit << 8);
                break;
            case 210:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 10)) | (bit << 10);
                break;
            case 211:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 11)) | (bit << 11);
                break;
            case 212:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 12)) | (bit << 12);
                break;
            case 213:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 13)) | (bit << 13);
                break;
            case 214:
                *(u16 *)(cp + 0x31A) = (*(u16 *)(cp + 0x31A) & ~(1 << 14)) | (bit << 14);
                break;
            case 215:
                *(u8 *)(cp + 0xA98) = bit;
                break;
            case 216:
                MsSetChrVisibleCamera(i, bit);
                break;
            case 217:
                *(u8 *)(cp + 0x1B) = bit;
                break;
            case 218:
                *(u16 *)(cp + 0x170) = val;
                break;
            case 219:
                *(u16 *)(cp + 0x172) = val;
                break;
            case 220:
                *(u8 *)(cp + 0xFB) = val;
                break;
            case 222:
                *(u8 *)(cp + 0x23) = bit;
                break;
            case 224:
                *(u8 *)(cp + 0x106) = val;
                break;
            case 225:
                *(u8 *)(cp + 0xA9A) = bit;
                break;
            case 226:
                *(u8 *)(cp + 0xAD0) = val;
                break;
            case 227:
                *(u8 *)(cp + 0xAD1) = val;
                break;
            case 228:
                *(u8 *)(cp + 0x178) = val;
                break;
            case 229:
                *(u8 *)(cp + 0xC8) = val;
                break;
            case 230:
                *(u8 *)(cp + 0x179) = val;
                break;
            case 231:
                *(u8 *)(cp + 0x17A) = val;
                break;
            case 232:
                *(u8 *)(cp + 0x31C) = val;
                break;
            case 233:
                *(u8 *)(cp + 0xE4) = val;
                break;
            case 234:
                *(u8 *)(cp + 0x17B) = val;
                break;
            case 235:
                *(u8 *)(cp + 0xC34) = val;
                break;
            case 236:
                *(u8 *)(cp + 0xC35) = val;
                break;
            case 237:
                MsSetChrVisible(i, bit);
                break;
            case 238:
                *(u8 *)(cp + 0x21) = bit;
                break;
            case 239:
                *(u8 *)(cp + 0x22) = bit;
                break;
            case 240:
                ((Bf278 *)(cp + 0x278))->b8 = val;
                break;
            case 241:
                MsSetChrShadowMode(i, 0, val);
                break;
            case 242:
                if (bit != 0) { weak = 2; *(s32 *)(cp + 0x290) = 0; }
                break;
            case 245:
                *(u8 *)(cp + 0xFC) = val;
                break;
            case 246:
                *(u8 *)(cp + 0x39B) = val;
                break;
            case 247:
                *(u8 *)(cp + 0x10A) = val;
                break;
            case 250:
                *(u8 *)(cp + 0x10B) = val;
                break;
            case 251:
                if (bit != 0) func_001D48D0(c); else func_001D48E8(c);
                break;
            case 252:
                *(u8 *)(cp + 0xC5) = bit;
                break;
            case 253:
                *(u8 *)(cp + 0x174) = bit;
                break;
            case 256:
                *(u8 *)(cp + 0x28B) = bit;
                break;
            case 257:
                *(u8 *)(cp + 0x284) = val;
                break;
            case 258:
                *(u8 *)(cp + 0x38E) = bit;
                break;
            case 259:
                *(u8 *)(cp + 0x283) = val;
                break;
            case 260:
                *(u16 *)(cp + 0xADA) = val;
                break;
            case 261:
                *(float *)(cp + 0x1A8) = (float)val / 100.0f; *(u8 *)(cp + 0x10D) = 1;
                break;
            case 262:
                *(u8 *)(cp + 0x391) = val;
                break;
            case 263:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 7)) | (bit << 7);
                break;
            case 264:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 6)) | (bit << 6);
                break;
            case 265:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 5)) | (bit << 5);
                break;
            case 266:
                if (sub != 0) *(u16 *)(sub + 0x6) = val;
                break;
            case 267:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 9)) | (bit << 9);
                break;
            case 268:
                *(s32 *)(cp + 0x264) = val;
                break;
            case 269:
                *(u8 *)(cp + 0xC9) = val;
                break;
            case 270:
                if (chr != 0) func_00110958(chr, ((float)val / 100.0f) / *(float *)(cp + 0x68));
                break;
            case 271:
                if (chr != 0) func_00110988(chr, ((float)val / 100.0f) / *(float *)(cp + 0x64));
                break;
            case 272:
                if (chr != 0) func_001109B8(chr, ((float)val / 100.0f) / *(float *)(cp + 0x64));
                break;
            case 273:
                MsAddYoujinbouCom(val);
                break;
            case 274:
                D_003188B0 = val;
                break;
            case 275:
                if (sub != 0) *(u8 *)(sub + 0x112) = val;
                break;
            case 276:
                *(u8 *)(cp + 0x39F) = val;
                break;
            case 277:
                *(u8 *)(cp + 0x3A0) = val;
                break;
            case 278:
                *(u8 *)(cp + 0xCD) = val;
                break;
            case 279:
                *(u8 *)(cp + 0x3A1) = MsCheckRange(*(u8 *)(cp + 0x3A1) + val, 0, 100);
                break;
            case 280:
                *(u8 *)(cp + 0x27C) = MsCheckRange(*(u8 *)(cp + 0x27C) + val, 0, *(u8 *)(cp + 0x27D));
                break;
            case 289:
                *(u8 *)(cp + 0x10F) = val;
                break;
            case 290:
                *(u16 *)(cp + 0x278) = (*(u16 *)(cp + 0x278) & ~(1 << 10)) | (bit << 10);
                break;
            case 291:
                *(u8 *)(cp + 0xCE) = val;
                break;
            case 292:
                *(u32 *)(cp + 0x16C) &= ~val;
                break;
            case 293:
                *(u32 *)(cp + 0x16C) |= val;
                break;
            case 294:
                *(u8 *)(cp + 0x3C0) = val;
                break;
            case 295:
                *(u8 *)(cp + 0xA8A) = bit;
                break;
            case 296:
                *(float *)(cp + 0x1AC) = (float)val / 100.0f;
                break;
            case 297:
                *(u8 *)(cp + 0xB8) = bit;
                break;
            case 299:
                if (sub != 0) *(u16 *)(sub + 0x2) = val;
                break;
            case 300:
                if (sub != 0) *(u16 *)(sub + 0x4) = val;
                break;
            case 301:
                if (sub != 0) *(u16 *)(sub + 0x0) = val;
                break;
            case 302:
                recalc = 1; *(u8 *)(cp + 0x270) = val;
                break;
            case 303:
                recalc = 1; *(u8 *)(cp + 0x271) = val;
                break;
            case 304:
                recalc = 1; *(u8 *)(cp + 0x272) = val;
                break;
            case 305:
                recalc = 1; *(u8 *)(cp + 0x273) = val;
                break;
            case 306:
                recalc = 1; *(u8 *)(cp + 0x274) = val;
                break;
            case 307:
                recalc = 1; *(u8 *)(cp + 0x275) = val;
                break;
            case 308:
                recalc = 1; *(u8 *)(cp + 0x276) = val;
                break;
            case 309:
                recalc = 1; *(u8 *)(cp + 0x277) = val;
                break;
            case 310:
                *(u8 *)(cp + 0x38C) = val;
                break;
            case 311:
                *(u8 *)(cp + 0x38D) = val;
                break;
            case 312:
                *(u8 *)(cp + 0x38F) = bit;
                break;
            case 313:
                *(u8 *)(cp + 0x390) = bit;
                break;
            case 314:
                if (sub != 0) *(u16 *)(sub + 0xC) = val;
                break;
            case 315:
                if (sub != 0) *(u16 *)(sub + 0xE) = val;
                break;
            case 316:
                if (sub != 0) *(u16 *)(sub + 0x10) = val;
                break;
            case 317:
                if (sub != 0) *(u16 *)(sub + 0x12) = val;
                break;
            case 318:
                if (sub != 0) *(u16 *)(sub + 0x18) = val;
                break;
            case 319:
                if (sub != 0) *(u16 *)(sub + 0x1A) = val;
                break;
            case 320:
                if (sub != 0) *(u16 *)(sub + 0x1C) = val;
                break;
            case 321:
                if (sub != 0) *(u16 *)(sub + 0x1E) = val;
                break;
            case 322:
                if (sub != 0) *(u8 *)(sub + 0x14) = val;
                break;
            case 323:
                if (sub != 0) *(u8 *)(sub + 0x15) = val;
                break;
            case 324:
                if (sub != 0) *(u8 *)(sub + 0x16) = val;
                break;
            case 325:
                if (sub != 0) *(u8 *)(sub + 0x17) = val;
                break;
            case 326:
                if (sub != 0) *(u8 *)(sub + 0x20) = val;
                break;
            case 327:
                if (sub != 0) *(u8 *)(sub + 0x21) = val;
                break;
            case 328:
                if (sub != 0) *(u8 *)(sub + 0x22) = val;
                break;
            case 329:
                if (sub != 0) *(u8 *)(sub + 0x23) = val;
                break;
            case 330:
                *(u8 *)(cp + 0xB9) = bit;
                break;
            case 331:
                if (bit != 0) { u8 v = *(u8 *)(cp + 0xD5); val = v & 0x7F; if (val != 7 && val != 0x10 && !(v & 0x80)) func_001D34A0(c); }
                break;
            case 332:
                if (bit == 0) bit = (*(s8 *)(cp + 0xA8C) == 0); msSetChrBodyHit(c, 3, bit);
                break;
            case 333:
                MsSetSavePlyJoin(i, bit);
                break;
            case 334:
                *(u8 *)(cp + 0x3B) = bit; MsSetEternalRelife(c);
                break;
            case 335:
                *(u8 *)(cp + 0xF7) = bit;
                break;
            case 336:
                *(u8 *)(cp + 0x1C) = bit;
                break;
            case 337:
                *(u8 *)(cp + 0xA9B) = bit;
                break;
            case 338:
                *(u8 *)(cp + 0x102) = val;
                break;
            case 339:
                *(u8 *)(cp + 0x39) = val;
                break;
            case 340:
                *(u8 *)(cp + 0xBB) = val;
                break;
            case 343:
                *(u8 *)(cp + 0x1C6) = bit;
                break;
            case 344:
                *(u8 *)(cp + 0xA95) = bit;
                break;
            case 345:
                *(u16 *)(cp + 0xA9E) = val;
                break;
            }
            count++;
            if (eff != 0) {
                MsStatusEffectCheck(i);
            }
            if (weak != 0) {
                MsSetChrWeak(i, -1);
                MsCheckAutoStatus(i, c);
                if (weak == 2) {
                    MsDamageCheckDeath(i, i, 0, 1);
                }
            }
            if (recalc != 0) {
                MsResetAutoStatus(c);
                MsSetRamChrParam(i);
                MsSetAutoStatus(c);
            }
        }
    }
    return count;
}

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
