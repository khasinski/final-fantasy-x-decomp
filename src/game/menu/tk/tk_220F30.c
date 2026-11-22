/* tu_248 0x220f30-0x224430: medium; ~Tk (config/tu_map.tsv) */
#define func_002238D8 _hdr_func_002238D8
#define func_00223140 _hdr_func_00223140
#define D_003257A4 _hdr_D_003257A4
#define D_003257A8 _hdr_D_003257A8
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/s5.h"
#include "ffx/v5.h"
#include "ffx/w7.h"
#undef func_00223140
#undef func_002238D8
#undef D_003257A4
#undef D_003257A8
extern u8 *D_003257A4;
extern u8 *D_003257A8;

int func_00220F30(void)
{
    s32 buf;
    int i;
    int text;
    int n = 0;
    Unk1BFED8 *e;

    for (i = 0; i < 8; i++) {
        e = MsGetSaveWeapon(btlgetdata.h[i], &buf);
        if (e->b2 != 0 && ((e->b3 >> 2) & 1 || e->b3 & 1 || (e->b3 >> 3) & 1)) {
            n++;
            text = func_001C0040(btlgetdata.h[i]);
        }
    }
    if (n == 1) {
        func_00206860(7, 0, 0);
        func_00206888(7, 0, text);
        func_002040F8(7);
        D_003257A8 = (u8 *)TkBtlEndGetText(0x401B);
    } else {
        D_003257A8 = (u8 *)TkBtlEndGetText(0x401C);
    }
    return n;
}

void func_00221040(int a, int b)
{
    if (a == 0) {
        D_003257B0 = D_003257AC;
    } else {
        D_003257B0 = a;
    }
    D_003257AC = b;
    if (D_003257B0 == b) {
        D_00693310 = 0x1000;
    } else {
        D_00693310 = 0;
    }
}

int TkBtlEndGetText(int a)
{
    return MsMenuGetBtlEndText(a, MsGetSaveConfigHiragana());
}

void func_002210B8(void)
{
    D_006932F8 = 1;
}

void func_002210C8(int a0, int a1)
{
    Rec0E *r;

    func_002210B8();
    r = D_006930B8 + a1;
    r->b0A = 0xF;
}

int func_00221108(int id)
{
    return func_001BE7B8(id);
}

s32 func_00221128(s32 i)
{
    return btlgetdata.next[i];
}

void func_00221140(s32 i, s32 v)
{
    btlgetdata.next[i] = v;
}

int func_00221158(void)
{
    return func_001BE690();
}

int func_00221178(int a)
{
    return MsGetNextAP(a);
}

s32 func_00221198(int id)
{
    return func_001BE5C0(id);
}

s32 func_002211B8(void)
{
    return MsGetGIL();
}

void func_002211D8(s32 cost)
{
    MsPayGIL(-cost);
}

u32 func_002211E0(int a)
{
    u32 r = (u32)func_00221178(a) / 0xBD | 1;

    if (r % 5 == 0) {
        r += 2;
    }
    return r;
}

s32 func_00221228(void)
{
    return D_0031FCBC;
}

s32 _m2c_func_00221238_func_00221198() __asm__("func_00221198");
void _m2c_func_00221238_func_002210C8(s32, s32) __asm__("func_002210C8");
void _m2c_func_00221238_func_00221158(s32, s32) __asm__("func_00221158");
s32 _m2c_func_00221238_func_00221178(s32) __asm__("func_00221178");
/* DEBT(FAKE) */
void func_00221238(s32 id, s32 pos, s32 c) {
    register s32 temp_17 __asm__("$17");
    register s32 temp_2 __asm__("$16");
    register s32 var_19 __asm__("$19");
    register s32 cmp __asm__("$2");

    var_19 = pos;
    temp_17 = _m2c_func_00221238_func_00221198(id);
    temp_2 = _m2c_func_00221238_func_00221178(id);
    {
        register s32 sum1 __asm__("$3") = temp_17 + var_19;
        cmp = sum1 < temp_2;
    }
    if (!cmp) {
        s32 r = func_00221108(id);
        register s32 diff __asm__("$3") = temp_2 - temp_17;
        __asm__("" : "+r"(diff));
        var_19 = ((r ^ 0x62) == 0) ? diff : var_19;
        {
            register s32 sum2 __asm__("$3") = temp_17 + var_19;
            cmp = sum2 < temp_2;
        }
        if (!cmp) {
            _m2c_func_00221238_func_002210C8(id, c);
        }
    }
    _m2c_func_00221238_func_00221158(id, var_19);
}

int func_002212E0(int id, int c)
{
    int r = 1;
    int n = func_002211E0(id);
    int left = func_00221128(id);

    if (func_00221108(id) >= 0x63) {
        func_00221140(id, 0);
        return 0;
    }
    if (n >= left) {
        n = left;
        r = 0;
    }
    left -= n;
    func_00221238(id, n, c);
    func_00221140(id, left);
    return r;
}

int func_00221398(void)
{
    int r = 0;
    int i;

    for (i = 0; i < D_006930B0; i++) {
        r |= func_002212E0(D_006930B8[i].h6, i);
    }
    return r;
}

int func_00221418(void)
{
    u32 a = D_006930A8;
    u32 b = D_006930AC;
    int r = 1;

    if (a >= b) {
        a = b;
        r = 0;
    }
    D_006930AC = b - a;
    func_002211D8(a);
    return r;
}

void func_00221468(int v)
{
    int i;
    Rec0E *e;

    for (i = 0; i < D_006930B0; i++) {
        e = &D_006930B8[i];
        e->h4 = v;
        if (v == 3) {
            e->h2 = (D_006930B0 - i - 1) * 2;
        }
    }
}

int func_002214D8(int idx)
{
    Rec0E *r = &D_006930B8[idx];
    int ret = 0;

    switch (r->h4) {
    case 0:
        r->h2 -= 1;
        if ((s16)r->h2 < 0) {
            r->h2 = 0;
            r->h4 = 1;
        }
        return 0;
    case 1:
        r->h2 += 0xE3;
        if ((s16)r->h2 >= 0x1000) {
            r->h2 = 0x1000;
            r->h4 = 2;
        }
        break;
    case 2:
        r->h2 = 0x1000;
        r->h4 = 2;
        ret = 1;
        break;
    case 3:
        r->h2 -= 1;
        if ((s16)r->h2 < 0) {
            r->h2 = 0;
            r->h4 = 4;
        }
        break;
    case 4:
        r->h2 += 0xE3;
        if ((s16)r->h2 >= 0x1000) {
            r->h2 = 0x1000;
            r->h4 = 5;
        }
        break;
    case 5:
        ret = 1;
        break;
    }
    if (func_00221108(r->h6) >= 0x63) {
        func_00221140(r->h6, 0);
    }
    return ret;
}

void func_00221620(void)
{
    func_001C03B0(D_003257B4[D_00693328 + D_00693338[0]], btlgetdata.h[D_00693338[1]]);
}

void func_00221668(void)
{
    s32 pos;
    int id = D_00693334;

    if (D_00693340 != 0) {
        id = !id;
    }
    if (id == 0) {
        id = D_003257B4[D_00693328 + D_00693338[0]];
    } else {
        id = btlgetdata.h[D_0069333C];
    }
    MsGetSaveWeapon(id, &pos);
}

void func_002216F0(void)
{
    int cur;

    if (func_00147DD0() == 0) {
        if (func_00147E00() != 0) {
            if (AtelGetMusicNumber() >= 0) {
                cur = AtelGetMusicNumber();
                if (cur != SndGetNowPlayMusic()) {
                    SndMusicCrossStart(AtelGetMusicNumber(), 0x78);
                }
            } else {
                SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
            }
        } else {
            AtelRegistMusicNumber(-1);
            SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
        }
    }
}

typedef struct {
    s32 w0;
    s32 w4;
    int (*fn8)(int);
} CdObj;

extern s16 D_00693300;
extern s16 D_00693302;
extern s16 D_00693304;
extern s16 D_00693306;
extern s16 D_00693308;
extern s16 D_0069330A;
extern s16 D_0069330C;
extern s16 D_0069330E;
extern s32 D_00693314;
extern s32 D_00693318;
extern s32 D_0069331C;
extern s32 D_00693320;
extern s32 D_00693324;
extern s32 D_0069332C;
extern s32 D_00693330;
extern u8 D_006930B1;
extern u32 D_0031FCC0;
extern char D_005711B8[];
extern char D_005711C0[];
extern char D_005711C8[];
void func_0020D530(void);
int func_00147DB8(void);
int TkSndReportStatus(void);
int SndSyncMusicStandby(int a);
int func_0014F158(void);
int func_00147E38(void);
void func_00117E38(int a);

void TkBtlEndCtrl(void)
{
    s32 buf;
    int pad_type;
    int rep;
    int trg;
    s32 *state;
    int st;
    int i;
    int ok;

    pad_type = func_00220318();
    rep = TOMenuGetControlPadRep();
    trg = TOMenuGetControlPadTrg();

    D_00693300 += D_00693302;
    if (D_00693300 > 0x1000) {
        D_00693300 = 0x1000;
    }
    if (D_00693300 < 0) {
        D_00693300 = 0;
    }

    D_00693304 += D_00693306;
    if (D_00693304 > 0x1000) {
        D_00693304 = 0x1000;
    }
    if (D_00693304 < 0) {
        D_00693304 = 0;
    }

    D_00693308 += D_0069330A;
    if (D_00693308 > 0x1000) {
        D_00693308 = 0x1000;
    }
    if (D_00693308 < 0) {
        D_00693308 = 0;
    }

    D_00693310 += 0x100;
    if (D_00693310 > 0x1000) {
        D_00693310 = 0x1000;
    }

    D_0069330C += D_0069330E;
    if (D_0069330C > 0x1000) {
        D_0069330C = 0x1000;
    }
    if (D_0069330C < 0) {
        D_0069330C = 0;
    }

    if (trg == 0x100) {
        func_0020D530();
    }

    st = D_006930A0;
    state = &D_006930A0;
again:
    switch (st) {
    case 0:
        *state = 9;
        st = 9;
        goto again;
    case 1:
        if (func_00147DB8() != 0) {
            *state = 2;
        } else {
            *state = 0;
        }
        break;
    case 2:
        *state = 3;
        break;
    case 3: {
        CdObj *cd = (CdObj *)GetCD();
        if (TkSndReportStatus() == 0 && cd->fn8(1) == 0) {
            *state = 4;
        }
        break;
    }
    case 4:
        if (SndGetNowPlayMusic() != 0x8A) {
            SndMusicRead(0x8A);
            *state = 5;
        } else {
            *state = 0;
        }
        break;
    case 5:
        if (SndSyncMusicStandby(0) == 0) {
            SndMusicStart(0x8A);
            *state = 0;
        }
        break;
    case 9:
        TOSeqStartScene(1, D_005711B8);
        if (D_006930B1 == 0) {
            st = 0x10;
            goto again;
        }
        *state = 0xA;
    case 10:
        ok = 1;
        for (i = 0; i < D_006930B0; i++) {
            ok &= func_002214D8(i);
        }
        if (ok != 0) {
            *state = 0xB;
        }
        break;
    case 11:
        *state = 0xC;
        for (i = 0; i < D_006930B0; i++) {
            if (func_00221108(D_006930B8[i].h6) < 0x63) {
                SndSepPlaySimple(0x80000018);
                break;
            }
        }
    case 12:
        if (func_00221398() == 0) {
            *state = 0xD;
        }
        if (rep & 0x20) {
            SndSepPlaySimple(0x80000001);
            while (func_00221398() != 0) {
            }
            *state = 0xD;
        }
        break;
    case 13:
        SndSepStop(0x80000018);
        *state = 0xE;
        break;
    case 14:
        if (rep & 0x20) {
            SndSepPlaySimple(0x80000001);
            func_00221468(3);
            *state = 0xF;
        }
        break;
    case 15:
        ok = 1;
        for (i = 0; i < D_006930B0; i++) {
            int r = func_002214D8(i);
            if (i == D_006930B0 - 1) {
                if (r != 0) {
                    D_00693306 = 0x80;
                }
            }
            ok &= r;
        }
        if (ok != 0) {
            *state = 0x14;
        }
        break;
    case 16:
        *state = 0x11;
        break;
    case 17:
        if (D_00693300 == 0x1000) {
            D_0069330E = 0x200;
            *state = 0x12;
        }
        break;
    case 18:
        if (D_0069330C == 0x1000) {
            *state = 0x13;
        }
        break;
    case 19:
        if (rep & 0x20) {
            SndSepPlaySimple(0x80000001);
            D_0069330E = -0x200;
            D_00693306 = 0x80;
            *state = 0x14;
        }
        break;
    case 20:
        *state = 0x15;
        D_00693314 = 0;
        func_00221040(0, TkBtlEndGetText(0x4006));
        break;
    case 21:
        TOSeqStartScene(1, D_005711C0);
        if (D_0069330C == 0) {
            D_00693314++;
            D_003257A8 = (u8 *)TkBtlEndGetText(0x4014);
            D_00693318 = 0x105;
            if (D_00693314 >= 7) {
                if ((D_0031FCC0 & 0xFF00FF) == 0) {
                    D_0069330E = 0x200;
                }
                *state = 0x16;
            }
        }
        break;
    case 22:
        if (D_00693304 == 0x1000) {
            *state = 0x17;
        }
        break;
    case 23:
        if (D_006930AC != 0) {
            SndSepPlaySimple(0x80000018);
        }
        *state = 0x18;
    case 24:
        if (func_00221418() == 0) {
            *state = 0x19;
            st = 0x19;
            goto again;
        }
        if (rep & 0x20) {
            SndSepPlaySimple(0x80000001);
            while (func_00221418() != 0) {
            }
            *state = 0x19;
        }
        break;
    case 25:
        SndSepStop(0x80000018);
        if (D_0069331C == 0) {
            D_003257A4 = (u8 *)TkBtlEndGetText(0x4005);
        }
        *state = 0x1A;
        break;
    case 26:
        if (rep & 0x20) {
            SndSepPlaySimple(0x80000001);
            D_0069330E = -0x200;
            D_00693306 = -0x80;
            if (D_0069331C == 0) {
                *state = 0x1B;
                D_00693302 = -0x80;
            } else {
                *state = 0x1C;
            }
        }
        break;
    case 27:
        if (D_00693304 == 0) {
            *state = 6;
        }
        break;
    case 28:
        TOSeqStartScene(1, D_005711C8);
        D_0069330A = 0x80;
        func_00221040(0, TkBtlEndGetText(0x4009));
        *state = 0x1E;
        break;
    case 29: {
        int t0, t1;
        TOSeqStartScene(1, D_005711C0);
        TOSeqStartScene(1, D_005711C8);
        D_0069330A = 0x80;
        t0 = TkBtlEndGetText(0x4009);
        t1 = TkBtlEndGetText(0x4009);
        func_00221040(t0, t1);
        *state = 0x1E;
        break;
    }
    case 30:
        if (D_00693308 == 0x1000) {
            *state = 0x1F;
        }
        break;
    case 31:
        D_003257A4 = (u8 *)TkBtlEndGetText(0x400A);
        *state = 0x20;
        break;
    case 32:
        if (trg & 0x100) {
            if (func_00220F30() == 0) {
                SndSepPlaySimple(0x80000001);
                *state = 0x2A;
                st = 0x2A;
                goto again;
            }
            SndSepPlaySimple(0x80000003);
            *state = 0x22;
            st = 0x22;
            goto again;
        }
        if (trg & 0x20) {
            if (((u8 *(*)(void))func_00221668)()[6] != 0xFF) {
                SndSepPlaySimple(0x80000003);
            } else {
                SndSepPlaySimple(0x80000001);
                *state = 0x24;
            }
        } else if (trg & 0x40) {
            SndSepPlaySimple(0x80000003);
        } else if (rep & 0x1000) {
            if (D_00693334 == 0) {
                D_00693338[0]--;
                if (D_00693338[0] >= 0) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[0] = 0;
                    if (D_00693328 > 0) {
                        D_00693328--;
                        D_00693324 = -0x1000;
                        D_0069332C = D_00693328;
                        D_00693330 = 0x333;
                        SndSepPlaySimple(0x80000001);
                        *state = 0x21;
                        st = 0x21;
                        goto again;
                    }
                }
            } else {
                D_00693338[D_00693334]--;
                if (D_00693338[D_00693334] >= 0) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[D_00693334] = 0;
                }
            }
        } else if (rep & 0x4000) {
            if (D_00693334 == 0) {
                D_00693338[0]++;
                if (D_00693338[0] < 6) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[0] = 5;
                    if (D_00693328 <= D_00693320 - 7) {
                        D_00693328++;
                        D_00693324 = 0x1000;
                        D_0069332C = D_00693328;
                        D_00693330 = 0x333;
                        SndSepPlaySimple(0x80000001);
                        *state = 0x21;
                        st = 0x21;
                        goto again;
                    }
                }
            } else {
                D_00693338[D_00693334]++;
                if (D_00693338[D_00693334] < 8) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[D_00693334] = 7;
                }
            }
        } else if (trg & 0x8000) {
            if (D_00693334 == 1) {
                D_00693334 = 0;
                SndSepPlaySimple(0x80000001);
            }
        } else if (trg & 0x2000) {
            if (D_00693334 == 0) {
                D_00693334 = 1;
                SndSepPlaySimple(0x80000001);
            }
        } else {
            if ((rep & 1) && pad_type == 1 && D_00693334 == 0) {
                D_0069332C = D_00693328 - 6;
                if (D_0069332C < 0) {
                    D_0069332C = 0;
                }
                if (D_0069332C != D_00693328) {
                    SndSepPlaySimple(0x80000001);
                    D_00693324 = -0x1000;
                    D_00693330 = 0x111;
                    *state = 0x21;
                    st = 0x21;
                    goto again;
                }
            }
            if (rep & 2) {
                if (pad_type != 2) {
                    break;
                }
                if (D_00693334 != 0) {
                    break;
                }
                D_0069332C = D_00693328 + 6;
                if (D_0069332C >= D_00693320 - 6) {
                    D_0069332C = D_00693320 - 6;
                    if (D_0069332C < 0) {
                        D_0069332C = 0;
                    }
                }
                if (D_0069332C != D_00693328) {
                    SndSepPlaySimple(0x80000001);
                    D_00693330 = 0x111;
                    D_00693324 = 0x1000;
                    *state = 0x21;
                    st = 0x21;
                    goto again;
                }
            }
        }
        break;
    case 33:
        if (D_00693324 > 0) {
            D_00693324 -= D_00693330;
            if (D_00693324 <= 0) {
                D_00693324 = 0;
                D_00693328 = D_0069332C;
                *state = 0x20;
                st = 0x20;
                goto again;
            }
        } else {
            D_00693324 += D_00693330;
            if (D_00693324 >= 0) {
                D_00693324 = 0;
                D_00693328 = D_0069332C;
                *state = 0x20;
                st = 0x20;
                goto again;
            }
        }
        break;
    case 34:
        D_0069330E = 0x200;
        *state = 0x23;
        break;
    case 35:
        if (trg != 0 && D_0069330C == 0x1000) {
            D_0069330E = -0x200;
            D_00693328 = D_0069332C;
            *state = 0x20;
        }
        break;
    case 36:
        D_00693340 = 1;
        *state = 0x25;
    case 37:
        if (trg & 0x100) {
            if (func_00220F30() == 0) {
                SndSepPlaySimple(0x80000001);
                *state = 0x2A;
                st = 0x2A;
                goto again;
            }
            SndSepPlaySimple(0x80000003);
            *state = 0x28;
            st = 0x28;
            goto again;
        }
        if (trg & 0x40) {
            SndSepPlaySimple(0x80000004);
            st = 0x27;
            goto again;
        }
        if (trg & 0x20) {
            u8 *w = (u8 *)MsGetSaveWeapon(D_003257B4[D_00693328 + D_00693338[0]], &buf);
            if (w[6] == 0xFF || w[2] == 0) {
                SndSepPlaySimple(0x80000001);
                func_00221620();
                st = 0x27;
                goto again;
            }
            SndSepPlaySimple(0x80000003);
        } else if (rep & 0x1000) {
            if (D_00693334 != 0) {
                D_00693338[0]--;
                if (D_00693338[0] >= 0) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[0] = 0;
                    if (D_00693328 > 0) {
                        SndSepPlaySimple(0x80000001);
                        D_00693328--;
                        D_00693324 = -0x1000;
                        D_0069332C = D_00693328;
                        D_00693330 = 0x333;
                        *state = 0x26;
                        st = 0x26;
                        goto again;
                    }
                }
            } else {
                D_00693338[1]--;
                if (D_00693338[1] >= 0) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[1] = 0;
                }
            }
        } else if (rep & 0x4000) {
            if (D_00693334 != 0) {
                D_00693338[0]++;
                if (D_00693338[0] < 6) {
                    SndSepPlaySimple(0x80000001);
                } else {
                    D_00693338[0] = 5;
                    if (D_00693328 <= D_00693320 - 7) {
                        D_00693328++;
                        D_00693324 = 0x1000;
                        D_0069332C = D_00693328;
                        D_00693330 = 0x333;
                        SndSepPlaySimple(0x80000001);
                        *state = 0x26;
                        st = 0x26;
                        goto again;
                    }
                }
            } else {
                D_00693338[1]++;
                if (D_00693338[1] >= 8) {
                    D_00693338[1] = 7;
                } else {
                    SndSepPlaySimple(0x80000001);
                }
            }
        } else {
            if ((rep & 1) && D_00693334 != 0) {
                D_0069332C = D_00693328 - 6;
                if (D_0069332C < 0) {
                    D_0069332C = 0;
                }
                if (D_0069332C != D_00693328) {
                    SndSepPlaySimple(0x80000001);
                    D_00693324 = -0x1000;
                    D_00693330 = 0x111;
                    *state = 0x26;
                    st = 0x26;
                    goto again;
                }
            }
            if ((rep & 2) && D_00693334 != 0) {
                D_0069332C = D_00693328 + 6;
                if (D_0069332C >= D_00693320 - 6) {
                    D_0069332C = D_00693320 - 6;
                    if (D_0069332C < 0) {
                        D_0069332C = 0;
                    }
                }
                if (D_0069332C != D_00693328) {
                    SndSepPlaySimple(0x80000001);
                    D_00693330 = 0x111;
                    D_00693324 = 0x1000;
                    *state = 0x26;
                    st = 0x26;
                    goto again;
                }
            }
        }
        break;
    case 38:
        if (D_00693324 > 0) {
            D_00693324 -= D_00693330;
            if (D_00693324 <= 0) {
                D_00693324 = 0;
                D_00693328 = D_0069332C;
                *state = 0x25;
                st = 0x25;
                goto again;
            }
        } else {
            D_00693324 += D_00693330;
            if (D_00693324 >= 0) {
                D_00693324 = 0;
                D_00693328 = D_0069332C;
                *state = 0x25;
                st = 0x25;
                goto again;
            }
        }
        break;
    case 39:
        *state = 0x20;
        D_00693340 = 0;
        break;
    case 40:
        D_0069330E = 0x200;
        *state = 0x29;
        break;
    case 41:
        if (trg != 0 && D_0069330C == 0x1000) {
            D_0069330E = -0x200;
            *state = 0x25;
        }
        break;
    case 42:
        D_00693302 = -0x80;
        D_0069330A = -0x80;
        *state = 0x2B;
        break;
    case 43:
        if (D_00693308 == 0) {
            *state = 6;
        }
        break;
    case 6:
        *state = 7;
    case 7:
        if (func_0014F158() == 0) {
            func_002216F0();
            *state = 8;
        }
        break;
    case 8:
        if (D_00693300 == 0) {
            D_006930B2 = 1;
            if (func_00147E38() != 0) {
                func_00117E38(0xF);
            }
        }
        break;
    }
}

void func_00222778(void)
{
    TkMenuDrawRect(0, 0, 0x200, 0x1A0, 0x80BA8C00, 0x80832400);
}

void func_002227A0(void)
{
    int i;

    for (i = 0; i < btlgetdata.bD0; i++) {
        MsSaveItemUse(btlgetdata.hD4[i], btlgetdata.bE4[i]);
    }
}

int func_001C0598(void *a);
void func_002416C0(void *a, int b, int c);
int MsGetSaveWeaponAmount(s32 *a);
extern s32 D_00693344;
extern s32 D_00693348;
extern s32 D_0069334C;
extern s32 D_00693350;
extern s32 D_00693354;
extern s32 D_00693358;
extern s32 D_0069335C;
extern u8 D_00693128[];
extern u8 D_00693158[];
extern u8 D_00693250[];
extern u8 D_006932B0[];

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00222820);

void func_00222910(s16 *rec, int y)
{
    int py;
    int px;

    py = y + 0x1C6;
    px = rec[0] + 6;
    func_00246670(func_00221128(rec[3]), py, px, 0);
    py = y + 0x14A;
    px = rec[0] + 6;
    func_00246670(abs(MsGetNextAP(rec[3]) - func_001BE5C0(rec[3])), py, px, 0);
}

void func_002229B0(int i)
{
    Rec0E *r;
    int s0;
    int s2;
    int s3;
    int n;
    int a;

    r = &D_006930B8[i];
    s3 = 0;
    s2 = 0;
    switch (r->h4) {
    case 0:
    case 5:
        return;
    case 1:
        s0 = -(func_00125D90((s16)r->h2) << 9) / 4096;
        s3 = s0 * 2 / 3;
        s2 = s0;
        break;
    case 2:
    case 3:
        s3 = 0;
        s2 = 0;
        break;
    case 4:
        s0 = 0x1000 - func_00125D60(0x1000 - (s16)r->h2);
        s0 = -(s0 << 9) / 4096;
        s3 = s0 * 2 / 3;
        s2 = s0;
        break;
    }
    TOMenuOpenPktBuffTmp();
    TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, s3, r->h0, D_00324208, D_0032420C, D_00324210);
    func_001F37C8(TOGetSaveChrName(r->h6), s3 + D_00324214, r->h0 + D_00324216);
    TOMkpShapeXY(0xEB, s3 + 0x111, r->h0 + 0xB);
    func_001F63B8(func_00221128(r->h6), s3 + 0x10C, r->h0 + 0xC, 0x25);
    func_001FE298(0xE7, 0, r->h0, 0x200, 0, 0x80808080, 0x80808080);
    TOMkpShapeXY(0x107, s2 + D_00324228 + 0x68, r->h0 + D_0032422A);
    func_001F5E80(func_00242468(r->h6), s2 + D_00324228 + D_0032422C, r->h0 + D_0032422A + D_0032422E, 0);
    if (func_00221108(r->h6) >= 99) {
        func_001F64F8(D_00571280, s2 + D_00324228 + 0x59, r->h0 + D_0032422A - 13, 0x25);
    } else {
        s0 = MsGetNextAP(r->h6);
        func_001F63B8(s0 - func_001BE5C0(r->h6), s2 + D_00324228 + 0x8B, r->h0 + D_0032422A - 13, 0x25);
    }
    if (r->b0A > 0) {
        a = 15 - r->b0A;
        if (a >= 3) {
            a = 2;
        }
        if (a < 0) {
            a = 0;
        }
        TOMkpShapeXY(0xFA + a, s3 + (D_0032422C + D_00324228) + 3, r->h0 + D_0032422A + D_0032422E - 2);
        r->b0A--;
    }
    TOMenuDrawKickTmp();
}

void func_00222D20(int a)
{
    func_00246CB8(0x10, a, 0x1E0);
}

void func_00222D30(void)
{
    Rec0E *r;

    r = D_006930B8;
    switch (r->h4) {
    case 0:
    case 5:
        return;
    case 1:
        func_00125D90((s16)r->h2);
        break;
    case 2:
    case 3:
        break;
    case 4:
        func_00125D60(0x1000 - (s16)r->h2);
        break;
    }
    func_002243C0(10, 0x94, 0x2D);
}

s32 _m2c_func_00222DB0_func_001F5580() __asm__("func_001F5580");
/* DEBT(CAST) */
void func_00222DB0(s32 arg0) {
    s32 temp_20;
    s32 var_17;
    s32 var_18;
    u8 temp_4;

    temp_20 = arg0 + 0x1E;
    var_18 = 0x46;
    var_17 = 0;
    TOMenuOpenPktBuffTmp();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    TOMenuDrawKickTmp();
    func_002243C0(0xB, arg0 + 0x1C, 0x2D);
    TOMenuOpenPktBuffTmp();
    if ((s8) btlgetdata.padC8[8] > 0) {
        do {
            func_001F4EB0(temp_20, var_18, 0xA);
            _m2c_func_00222DB0_func_001F5580((((struct { u8 _pad[0xD4]; u16 a[1]; } *)(&btlgetdata))->a[var_17]), temp_20, var_18, 0);
            temp_4 = (*(u8 *)((u8 *)(&btlgetdata.pad0[var_17]) + (0xE4)));
            var_17 += 1;
            func_001F5E80(temp_4, arg0 + 0xF1, var_18 + 6, 0);
            var_18 += 0x20;
        } while (var_17 < (s8) btlgetdata.padC8[8]);
    }
    TOMenuDrawKickTmp();
}

void func_00222EB0(int x)
{
    s32 buf[4];
    int i;
    int px = x + 0x118;
    int py = 0x46;
    Unk1BFED8 *e;

    TOMenuOpenPktBuffTmp();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    TOMenuDrawKickTmp();
    func_002243C0(6, x + 0x115, 0x2D);
    TOMenuOpenPktBuffTmp();
    for (i = 0; i < 8; i++, py += 0x20) {
        e = MsGetSaveWeapon(btlgetdata.h[i], buf);
        if (e->b2 != 0) {
            func_001F4EB0(px, py, 1);
            func_001F55C8(btlgetdata.h[i], px, py, 0);
        }
    }
    TOMenuDrawKickTmp();
}

void func_00222F90(int y)
{
    s32 w[2];

    func_002243C0(12, y + 0x1C, 0x14A);
    TOMenuOpenPktBuffTmp();
    TOSeqGetPoint(1, D_005712C8, (s16 *)&w[0], (s16 *)&w[1]); /* DEBT(CAST): filled as words here */
    TOMkpShapeXY(0xD5, y + 0xB8, 0x163);
    TOMkpShapeXY(0xD6, y + w[0] + 0xB8, 0x163);
    func_001F63B8(D_006930AC, y + 0xB8, 0x167, 0x25);
    TOMkpShapeXY(0xD5, y + 0xB8, 0x175);
    TOMkpShapeXY(0xD6, y + w[0] + 0xB8, 0x175);
    func_001F63B8(func_002211B8(), y + 0xB8, 0x179, 0x25);
    TOMenuDrawKickTmp();
}

void func_00223078(void)
{
    extern s16 D_00693304, D_00693306;
    int v;
    int y;

    if (D_00693304 != 0) {
        if (D_00693304 != 0x1000) {
            if (D_00693306 > 0) {
                v = func_00125D90(D_00693304);
            } else {
                v = 0x1000 - func_00125D60(D_00693304);
                v = (v * 5) / 4;
            }
        } else {
            v = 0;
        }
        y = v / 8;
        func_00222DB0(-y);
        func_00222EB0(y);
        func_00222F90(-y);
    }
}

void *_m2c_func_00223140_MsGetSaveWeapon(u16, void *) __asm__("MsGetSaveWeapon");
void _m2c_func_00223140_func_001F4EB0(s32, s32, s32) __asm__("func_001F4EB0");
void _m2c_func_00223140_func_001F55C8(u16, s32, s32, s32) __asm__("func_001F55C8");
extern s32 _m2c_func_00223140_D_00693320 __asm__("D_00693320");
extern s32 _m2c_func_00223140_D_00693324 __asm__("D_00693324");
/* DEBT(CAST) */
void func_00223140(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x10];
    u16 temp_17;
    void *temp_2;

    if ((arg0 < _m2c_func_00223140_D_00693320) && (arg0 >= 0)) {
        temp_17 = D_003257B4[arg0];
        if (arg3 == 0) {
            arg2 += ((s32)_m2c_func_00223140_D_00693324 / 128);
        }
        temp_2 = _m2c_func_00223140_MsGetSaveWeapon(temp_17, sp);
        if ((*(u8 *)((u8 *)(temp_2) + (2))) != 0) {
            _m2c_func_00223140_func_001F4EB0(arg1, arg2, 1);
            if ((*(u8 *)((u8 *)(temp_2) + (6))) != 0xFF) {
                _m2c_func_00223140_func_001F55C8(temp_17, arg1, arg2, 1);
                return;
            }
            _m2c_func_00223140_func_001F55C8(temp_17, arg1, arg2, 0);
        }
    }
}

extern s32 D_00693320;
extern s32 D_00693324;
extern s32 D_0069332C;

void func_00223228(int y)
{
    int x = y + 0x1E;
    int i;
    int py;

    TOMenuOpenPktBuffTmp();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    TOMenuDrawKickTmp();
    func_002243C0(0xD, x, 0x2D);
    TOMenuOpenPktBuffTmp();
    if (D_00693334 == 0) {
        if (D_00693340 == 0 || ((func_00242040() / 2) & 1) != 0) {
            func_001FE7F8(0, x, D_00693338[0] * 32 + 0x46);
        }
    } else {
        if (D_00693340 != 0) {
            func_001FE7F8(0, x, D_00693338[0] * 32 + 0x46);
        }
    }
    TODrawScissorXYWH(0x1E, 0x46, 0xDB, 0xC0);
    py = 0x26;
    if (D_00693328 == D_0069332C) {
        for (i = -1; i < 7; i++, py += 0x20) {
            func_00223140(D_00693328 + i, x, py, 0);
        }
    } else {
        py = 0x46;
        for (i = 0; i < 6; i++, py += 0x20) {
            func_00223140(D_00693328 + i, x, py, 2);
        }
        py = (D_00693324 * 0xC0) / 0x1000 + 0x46;
        for (i = 0; i < 6; i++, py += 0x20) {
            func_00223140(D_0069332C + i, x, py, 1);
        }
    }
    if (y == 0) {
        TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
        func_00200A58(0x100, 0x36, 0xA, 0xD0, D_00693328, 6, D_00693320);
    }
    TOMenuDrawKickTmp();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223468);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223620);

void func_002237B0(void)
{
    extern s16 D_00693308, D_0069330A;
    int v;
    int y;

    if (D_00693308 != 0) {
        if (D_00693308 != 0x1000) {
            if (D_0069330A > 0) {
                v = func_00125D90(D_00693308);
            } else {
                v = 0x1000 - func_00125D60(D_00693308);
                v = (v * 5) / 4;
            }
        } else {
            v = 0;
        }
        y = v / 8;
        func_00223228(-y);
        func_00223468(y);
        func_00223620(-y);
    }
}

void func_00223878(void)
{
    TOMenuOpenPktBuffTmp();
    func_001FA548(0x10B, 0xC4, 0xE8, 0x16);
    if (D_003257A4 != 0) {
        func_001F37C8(D_003257A4, 0x11F, 0xC8);
    }
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    TOMenuDrawKickTmp();
}

void _m2c_func_002238D8_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
void _m2c_func_002238D8_TOMenuDrawKickTmp() __asm__("TOMenuDrawKickTmp");
void _m2c_func_002238D8_TOMenuOpenPktBuffTmp() __asm__("TOMenuOpenPktBuffTmp");
void _m2c_func_002238D8__TOGetMessageWH(s32, s32, void *, u16 *, s32, s32) __asm__("_TOGetMessageWH");
void _m2c_func_002238D8_func_001F37C8(s32, s32, s32) __asm__("func_001F37C8");
void _m2c_func_002238D8_func_001FA548(s32, s32, s16, s16) __asm__("func_001FA548");
void func_002238D8(void) {
    s16 sp0;
    u16 sp2;
    s32 temp_17;
    s32 temp_3;

    _m2c_func_002238D8_TOMenuOpenPktBuffTmp();
    _m2c_func_002238D8__TOGetMessageWH(7, D_003257A4, (&sp0), &sp2, 0, 0);
    sp0 = 0xE8;
    temp_3 = sp2 + 0x10;
    sp2 = temp_3;
    temp_17 = 0x198 - (s16) temp_3;
    _m2c_func_002238D8_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_func_002238D8_func_001FA548(0x118, temp_17, sp0, (s16) sp2);
    if (D_003257A4 != 0) {
        _m2c_func_002238D8_func_001F37C8(D_003257A4, 0x128, temp_17 + 8);
    }
    _m2c_func_002238D8_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_func_002238D8_TOMenuDrawKickTmp();
}

extern s16 D_0069330C;
void func_001F3910(int font, u8 *text, int x, int y);

void func_002239A8(void)
{
    s16 size[2];
    int textx, y, x;
    if(D_0069330C && D_003257A8) {
        TOMenuOpenPktBuffTmp();
        size[0]=0;
        size[1]=0;
        _TOGetMessageWH(7,(u8 *)D_003257A8,&size[0],&size[1],0,0);
        size[0]+=36;
        size[1]+=10;
        textx=(512-size[0])/2;
        y=(416-size[1])/2;
        size[0]=size[0]*D_0069330C/4096;
        x=(512-size[0])/2;
        func_001FA548(x,y,size[0],size[1]);
        TODrawScissorXYWH(x,y,size[0],size[1]);
        func_001F3910(7,(u8 *)D_003257A8,textx+18,y+5);
        TODrawScissorXYWH(0,0,511,415);
        TOMenuDrawKickTmp();
    }
}

void func_00223B00(void)
{
    TOMenuOpenPktBuffTmp();
    ((int (*)())TODrawMenuPlateXYWC2_Rfix)(0x45, 0x46, D_00324248, D_0032424A, D_0032424C, D_00324250, D_00324254); /* DEBT(TYPE): called as returning int */
    TODrawMenuPlateXYWC2_Rfix(6, 7, D_0032425C, D_0032425E, D_00324260, D_00324264, D_00324268);
    TOMkpShapeXY(0x3E, D_00324248 + 0x50, D_0032424A);
    if (D_003257AC != 0) {
        func_001F37C8(D_003257AC, D_0032425C + D_0032426C, D_0032425E + D_0032426E);
    }
    TOMenuDrawKickTmp();
}

extern s16 D_00693300;

void TkBtlEndDraw(void)
{
    func_00124F08();
    TkMenuDrawScissorClear();
    switch (D_006930A4) {
    case 0:
        D_006930A4 = 1;
    case 1: {
        int i;
        for (i = 0; i < D_006930B0; i++) {
            func_002229B0(i);
        }
        if (D_006930B0 != 0) {
            func_00222D30();
        }
        func_00223078();
        func_002237B0();
        break;
    }
    }
    if (D_006932F8 != 0) {
        SndSepStop(0x80000017);
        SndSepPlaySimple(0x80000017);
    }
    D_006932F8 = 0;
    func_002238D8();
    func_002239A8();
    func_00223B00();
    if (D_00693300 != 0x1000) {
        u32 col = (0x1000 - D_00693300) / 32;
        col <<= 24;
        if (func_00147E50() != 0) {
            col |= 0xFFFFFF;
        }
        TkMenuDrawRect(0, 0, 0x200, 0x1A0, col, col);
    }
    TkMenuDrawScissorClear();
    func_002492F0();
    func_002492F0();
    if (D_006930B2 != 0) {
        func_00220728(0x10000);
        func_002227A0();
        MsBtlGetInit();
        TkMenuMainRemoveMenu(0x11);
    }
}

int func_00223DC0(int v) {
    int a[3];
    int i;

    MsGetSavePartyMember(&a[0], &a[1], &a[2]);
    for (i = 0; i < 3; i++) {
        if (v == a[i] && v != 0xFF) {
            return 1;
        }
    }
    return 0;
}

int func_00223E28(int id) { return func_00242C58(); }

int func_00223E48(int a0, int a1) {
    return ((140 - a1 * 20) >> 1) + (a0 * 20 + 46);
}

int func_00223E70(int a0, int a1) {
    return ((308 - a1 * 44) >> 1) + (a0 * 44 + 76);
}

extern u8 D_006930B1;
void func_00223E98(void)
{
    int total = 0;
    int i;
    int row;
    Rec0E *entry;
    D_006930B1 = 0;
    for (i = 0; i < 8; i++) {
        if ((s8)btlgetdata.pad0[i] != 0) {
            if (btlgetdata.next[i] != 0) {
                D_006930B1 = 1;
            }
            total++;
        }
    }
    row = 0;
    for (i = 0; i < 8; i++) {
        if ((s8)btlgetdata.pad0[i] != 0) {
            entry = &D_006930B8[row];
            entry->h2 = row * 6;
            entry->h4 = 0;
            entry->h6 = i;
            entry->pad8[0] = func_00223E28(i);
            entry->pad8[1] = func_00223DC0(i);
            entry->h0 = func_00223E70(row, total);
            entry->b0A = 0;
            row++;
        }
    }
    D_006930B0 = total;
}

void func_00223FB8(int a)
{
    switch ((u8)a) {
    default:
        AtelSetBattleEndKeepRecoverType(a);
        D_006930A0 = 1;
        break;
    case 1:
        D_006930A0 = 0x1D;
        break;
    case 2:
        D_006930A0 = 0;
        break;
    }
    D_006930A4 = 0;
    D_006932F8 = 0;
    D_006930B2 = 0;
    func_00223E98();
}

void func_00224030(void)
{
    D_006930AC = func_00221228();
    D_006930A8 = (D_006930AC / 189) | 1;
    if (D_006930A8 % 5 == 0) {
        D_006930A8 += 2;
    }
}

void TkBtlEndInit(int a0, int a1)
{
    s32 buf0;
    s32 amount;
    s32 buf1;
    s32 buf2;
    int i;
    int found = 0;
    int top;
    int t0;
    int t1;

    D_003257A4 = (u8 *)TkBtlEndGetText(0x4004);
    D_003257A8 = (u8 *)TkBtlEndGetText(0x4013);
    D_00693318 = 0xD0;
    D_00693334 = 0;
    D_00693338[1] = 0;
    D_00693338[0] = 0;
    D_00693344 = 0;
    D_00693348 = 0;
    D_0069334C = 0;
    D_00693350 = 0;
    D_00693354 = 0;
    D_00693358 = 0;
    D_0069335C = 0;
    func_00223FB8(a1);
    func_00224030();
    D_00693300 = 0;
    D_00693302 = 0x80;
    D_00693304 = 0;
    D_00693306 = 0;
    D_00693308 = 0;
    D_0069330A = 0;
    D_0069330C = 0;
    D_0069330E = 0;
    D_00693324 = 0;
    D_00693340 = 0;
    D_003257B4 = (u16 *)MsGetSaveWeaponList(-1, -1, 0, &D_00693320);
    top = 0;
    for (i = 0; i < D_00693320; i++) {
        if (MsGetSaveWeapon(D_003257B4[i], &buf0)->b2 == 0) {
            found = i;
            top = found - 3;
            break;
        }
    }
    if (top + 6 >= D_00693320) {
        top = D_00693320 - 7;
    }
    if (top < 0) {
        top = 0;
    }
    D_00693328 = top;
    D_0069332C = top;
    D_00693338[0] = found - top;
    if (D_00693338[0] < 0) {
        D_00693338[0] = 0;
    }
    if (D_00693338[0] >= 6) {
        D_00693338[0] = 5;
    }
    MsGetSaveWeaponAmount(&amount);
    for (i = (s8)btlgetdata.padC8[10]; i < 8; i++) {
        MsGetSaveWeapon(btlgetdata.h[i], &buf1)->b2 = 0;
    }
    if (amount < (s8)btlgetdata.padC8[10]) {
        D_0069331C = 1;
    } else {
        D_0069331C = 0;
        for (i = 0; i < (s8)btlgetdata.padC8[10]; i++) {
            func_001C0598(MsGetSaveWeapon(btlgetdata.h[i], &buf2));
        }
    }
    t0 = TkBtlEndGetText(0x4000);
    t1 = TkBtlEndGetText(0x4000);
    func_00221040(t0, t1);
    func_002416C0(D_00693128, 0x15, 0xC);
    func_002416C0(D_00693158, 0x79, 0xC);
    func_002416C0(D_00693250, 0x2C, 0xC);
    func_002416C0(D_006932B0, 0x22, 0xC);
}

void func_002243C0(int a0, int a1, int a2) {
    TOMenuOpenPktBuffTmp();
    func_001FF1D8(0xDA, 0xDB, a1, a2, 0xD5, 0x80000000, 0x80000000);
    func_002018D8(a0, a1 + 0x15, a2 + 5);
    TOMenuDrawKickTmp();
}
