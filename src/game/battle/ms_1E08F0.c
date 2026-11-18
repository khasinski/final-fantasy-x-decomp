/* tu_209 0x1e08f0-0x1e1f40: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#define MsMessageCueRegist _hdr_MsMessageCueRegist
#include "ffx/r3.h"
#undef MsMessageCueRegist
#define MsSystemMessageOpen u2_MsSystemMessageOpen /* DEBT(TYPE): u2.h declares void return */
#include "ffx/u2.h"
#undef MsSystemMessageOpen
#include "ffx/v3.h"
#include "ffx/g2.h"
#include "ffx/g3.h"

void MsWeaponDispose(int kind, int i, int flags, BtlChr *p) {
    BtlChr *q;
    Chr *chr;

    if (p == 0) {
        return;
    }
    chr = p->chr;
    if (chr != 0) {
        if (flags & 8) {
            Ch_ModelPurgePacket(chr, 1);
            p->f3A = 1;
        }
        if (flags & 1) {
            Ch_Dispose((int)chr); /* DEBT(CAST): prototype takes the character as int */
            p->chr = 0;
        }
    }
    if (p->f08 != 0 && (flags & 4) && p->f3E == 0) {
        ChN_DisposeSystemMGRP(p->f08, p->f20);
        p->f08 = 0;
        p->f38 = 0;
    }
    if (p->f04 != 0 && (flags & 2) && p->f3E == 0) {
        ChN_DataDispose(p->f04, 0);
        p->f04 = 0;
    }
    q = MsGetWeaponSpecial(kind, i);
    if (q != 0) {
        MsBtlChrInfoFree(q);
        *(s32 *)&q->chr = *(s32 *)&p->chr; /* DEBT(CAST): copied as a plain word */
        q->f04 = p->f04;
        q->f08 = p->f08;
        q->f38 = p->f38;
    }
}

void func_001E0A18(BtlChr *c, int a, int b) {
    if (c->fABB == 0) {
        c->fABB = 8;
        c->fC24 = a;
        c->fC26 = b & 0xFFF;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E08F0", func_001E0A40);

void func_001E0BF0(int id, int a, int b) {
    BtlChr *c = MsGetWeapon(id, a);
    if (c->chr != 0) {
        func_00110540(c->chr, b, 0.0f);
    }
}

void func_001E0C30(int a, int b, int c) {
    Chr *w = MsGetWeapon(a, b)->chr;
    if (w != 0) {
        func_00110540(w, 0, 0.0f);
        func_00110540(w, c, 1.0f);
    }
}

int func_001E0C98(void)
{
    W5Ent16 *p;
    int i;

    for (i = 0; i < 200; i++) {
        p = &D_0031D96C[i];
        if (p->b2 != 0 && ((p->b3 >> 3) & 1) && !((p->b3 >> 1) & 1)) {
            return 1;
        }
    }
    return 0;
}

int func_001E0CF0(int clear)
{
    W5Ent16 *p;
    int i;

    for (i = 0; i < 200; i++) {
        p = &D_0031D96C[i];
        if (p->b2 != 0 && ((p->b3 >> 3) & 1)) {
            if (clear != 0) {
                p->b3 &= 0xFD;
            } else {
                p->b3 |= 2;
            }
            return 1;
        }
    }
    return 0;
}

void MsChangeWeaponInvisible(int arg, int flag) {
    int slot = (u8)arg;
    if (slot < 7) {
        PartySlot *p = &D_0031EA9C[slot];
        int i;
        for (i = 0; i < 2; i++) {
            u8 id = i == 0 ? p->f2D : p->f2E;
            if (id != 0xFF) {
                Unk1BFED8 *e = MsGetSaveWeapon(id, 0);
                e->b3 = (e->b3 & ~2) | ((flag & 1) << 1);
            }
        }
    }
}

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7[15];
} W5Ent16Local;

typedef struct {
    u8 pad0[0xD2];
    s8 fD2;
    u8 padD3[0xFE - 0xD3];
    W5Ent16Local entFE;
    u8 pad114[0x1B0 - 0x114];
} W5BufLocal;

int func_001E0DE8(int a) {
    W5Ent16Local *p;
    int i;
    u16 h0;
    u8 b2;
    u8 b6;

    for (i = 0; i < 200; i++) {
        p = &((W5Ent16Local *)D_0031D96C)[i];
        if (p->b2 != 0 && ((p->b3 >> 3) & 1) && !((p->b3 >> 1) & 1)) {
            MsFieldItemGetMes(a);
            if (((W5BufLocal *)&btlgetdata_mes)->fD2 > 0) {
                h0 = p->h0;
                b2 = p->b2;
                b6 = p->b6;
                *p = ((W5BufLocal *)&btlgetdata_mes)->entFE;
                p->h0 = h0;
                p->b2 = b2;
                p->b6 = b6;
            }
            return 1;
        }
    }
    return 0;
}

void MsMemCheckInit(void) {
    D_00662FE0 = 0x40;
    D_00662FE4 = 0;
}

void MsMemCheckRegist(int a, int size) {
    size += 0x10;
    D_00662FE0 += ((size + 0x3F) / 64) * 64;
}

void MsMemCheckSum(int n) {
    int sz = n - D_00662FE0 - 0x10;
    if (sz > 0) {
        D_00662FE4 = (s32)user_malloc(sz / 64 * 64, 5, D_0056F7F8, -1); /* DEBT(TYPE): handle/pointer kept as int */
    }
    if (n < D_00662FE0) {
        MsBattleError(D_0056F800);
    }
}

void MsMemCheckFree(void) {
    if (D_00662FE4 != 0) {
        func_0011D590(D_00662FE4, 5);
        D_00662FE4 = 0;
    }
}

void func_001E0FF0(u8 id, int v)
{
    MsGetChr(id)->f106 = v;
}

int func_001E1020(int id, int a, int b) {
    int ch = id & 0xFF;
    BtlChr *c;

    if (MsBtlChrNumCheck(ch) != 0 && MsGetChrTop() != 0) {
        c = MsGetChr(ch);
        if (c->f12 != 0) {
            ch = c->f14;
            c = MsGetChr(ch);
        }
        c->f5C |= 1 << a;
        switch (a) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            func_001E1418(ch, c, a);
            break;
        case 0:
            c->fE9++;
        case 9:
            func_001E1120(ch, c, a);
            break;
        case 1:
            func_001E12C8(ch, c);
            break;
        case 2:
            func_001E13D0(ch, c);
            break;
        }
    }
    return 0;
}

void func_001E1120(int id, BtlChr *c, int a) {
    int t = c->f106;
    int fl;
    int x4;
    int has;
    int r;
    int k;
    u8 s;

    switch (t) {
    case 1:
    case 4:
        r = MsGetDamageResult(id, func_001B8198(id, -16, 0, 1), &fl, &x4, &has);
        if (has != 0) {
            k = 0xFF;
            switch (r) {
            case 6:
                k = 0;
                break;
            case 4:
                k = 2;
                break;
            case 0:
            case 1:
            case 17:
                break;
            default:
                k = 1;
                break;
            }
            if (k != 0xFF && c->fAD9 != 0) {
                if (c->fADA >= 0) {
                    k = c->fADA;
                }
                if (k != 0xFF) {
                    func_001DFFA0(id, k);
                }
            }
            if ((fl & 7) != 0 && c->fAD6 != 0) {
                s = c->fACE;
                if (s != 0) {
                    if (fl & 0x100) {
                        func_001CF0C0(id, 0);
                    }
                    func_001CF458(id, 0, s, 1);
                }
            }
        }
        if (a != 0) {
            if (a == 9) {
                c->fAD9 = 0;
                c->fAD6 = 0;
            }
        } else if (t == 1) {
            func_001C5E90(id, -5, 0);
        }
        break;
    case 2:
        break;
    }
}

void func_001E12C8(int id, BtlChr *c) {
    int k;
    int t;
    int r;
    int out[2];

    switch (c->f106) {
    case 1:
    case 4:
        k = func_001B8198(id, -16, 0, 1);
        r = 1;
        t = MsGetDamageResult(id, k, 0, &out[0], &out[1]);
        if (out[1] != 0 && (t == 1 || t == 0x11)) {
            r = 0;
            if (c->f10A != 0) {
                func_001DFFA0(id, 0x1F);
            } else {
                func_001DFFA0(id, 3);
            }
            func_001C5E90(id, -5, -3);
        }
        if (r) {
            func_001B60F8(c->fA80);
        }
        break;
    case 2:
        break;
    }
}

void func_001E13D0(int a, BtlChr *c) {
    switch (c->f106) {
    case 1:
    case 4:
        func_001C5A80(a, -5);
        break;
    case 2:
        break;
    }
}

void func_001E1418(int id, BtlChr *c, int a) {
    int t = c->f106;
    int x;
    int r;
    int v;

    switch (t) {
    case 1:
    case 4:
        r = MsGetDamageResult(id, func_001B8198(id, -16, 0, 1), 0, 0, &x);
        v = -1;
        if (r < 0 || (r > 1 && r != 17)) {
            switch (a) {
            case 3:
                v = 5;
                break;
            case 4:
                v = 6;
                break;
            case 5:
                v = 13;
                break;
            case 6:
                v = 14;
                break;
            case 7:
                v = 15;
                break;
            case 8:
                v = 16;
                break;
            }
        }
        if (v >= 0) {
            MsSetDamageMotion(id, -5, v);
        }
        break;
    case 2:
        break;
    }
}

void func_001E1528(void)
{
    D_003172F0.f2040 = 0;
    D_003172F0.f2074 = 0;
    D_003172F0.f2075 = 0;
    D_003172F0.f2076 = 0;
    D_003172F0.f2077 = 0;
}

int MsMessageCueRegist(int op, int a, int b, int b1, int b2) {
    int r = 0;
    if (D_003172F0.f2074 < 4) {
        CmdEnt *c;
        MsMenuCloseTitleWindow(0);
        r = 1;
        c = &D_003172F0.f2044[(D_003172F0.f2075 + D_003172F0.f2074) % 4];
        c->op = op;
        c->a = a;
        c->b = b;
        c->b1 = b1;
        c->b2 = b2;
        D_003172F0.f2074++;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E08F0", MsMessageCueProcess);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1E08F0/rodata", jtbl_0056F8B0);

int MsSystemMessageOpen(int a) {
    int p = D_003172F0.h32[0].w14;
    D_003172F0.f1980 = a;
    if (p != 0 && func_001BD320() != 0) {
        TODrawAMES_CENTERMES(7, p + *(u16 *)(p + (a * 2 + MsGetSaveConfigHiragana()) * 4)); /* DEBT(CAST): pointer/offset table kept as int */
    }
    return 0;
}

int MsSystemMessageCheck(void) {
    int r = 0;
    int a = TOGetMessageStatus(7);
    if (a != 0) {
        int b = TOGetWindowStatus(7);
        if (a == 3 && b == 2) {
            TOCloseMessageWindow(7);
        } else {
            r = -1;
        }
    }
    return r;
}

u8 MsGetMonsterCapture(int i)
{
    return D_003194D0.flag[i & 0xFFF];
}

void MsSetMonsterCheck(int i, u16 *bits)
{
    i &= 0xFFF;
    bits[i / 16] |= 1 << (i & 0xF);
}

u8 *MsGetSaveMonsterMeet(void)
{
    return D_0031D8DC;
}

u8 *MsGetSaveMonsterDefeat(void)
{
    return D_0031D91C;
}

int func_001E19A8(int idx, int delta)
{
    int i = idx & 0xFFF;
    int v = 0;

    if (i != 0xFF) {
        v = MsGetMonsterCapture(i) + delta;
        if (v < 0) {
            v = 0;
        }
        if (v > 10) {
            v = 10;
        }
        D_003194D0.flag[i] = v;
    }
    return v;
}

int MsMonsterCapture(int a, int id) {
    int r = 0;
    int msg;
    if (id == 0xFF) {
        msg = 0x300C;
    } else if (((int (*)(int))MsGetMonsterCapture)(id) >= 10) { /* DEBT(TYPE): this caller saw MsGetMonsterCapture as returning int */
        msg = 0x300B;
    } else {
        r = 1;
        msg = 0x300A;
        func_001E19A8(id, 1);
    }
    MsMessageCueRegist(5, a, msg, 0x1B, 0x23);
    return r;
}

void func_001E1AA8(void) {
    D_003193EF = 1;
    Ch_RegMotionSetup(D_00662FE8);
}

void func_001E1AC0(void) {
    D_00662FE8 = 0;
    D_003193EF = 0;
}

int MsRegMotionRead(int a) {
    int size;

    if (func_00104E20()) {
        D_003172F0.f20FF = 1;
    } else if (Ch_RegMotionGetExistMem() == 0) {
        D_003172F0.f20FF = 0;
        GetCD()->f10(0x2E);
        size = ((GetCD()->f14(0) + 0x8F) & 0xFFFFFF80) - 0x10;
        func_0011C348(0x40);
        D_00662FE8 = (s32)user_malloc(size, 5, D_0056F8D0, -1);
        Ch_RegMotionEntryCache(D_00662FE8);
        GetCD()->f0(0, D_00662FE8, func_001E1AA8, 0);
    }
    return D_003172F0.f20FF;
}

void MsRegMotionDispose(void) {
    D_003193EF = 0;
    if (D_00662FE8 != 0) {
        if (func_00104E20() != 0) {
            D_00662FE8 = 0;
            func_00104EA8();
        }
    }
}

W5OffTbl *MsSetMotBinAddress(BtlChr *c, int idx)
{
    u16 *t = (u16 *)D_00317374;
    void *p = 0;

    if (t != 0 && idx >= 0 && idx < t[0]) {
        p = (u8 *)t + t[1 + idx];
    }
    c->f1B8 = p;
    return (W5OffTbl *)t;
}

void func_001E1C68(void) {
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E08F0", func_001E1C70);

int msVoiceCheckStanby(int a)
{
    if (GetCD()->f8(1) != 0 ||
        TkSndReportStatus() == 1 ||
        (func_002D6730() != 0 && a != 0) ||
        SndGetStreamState() != 0 ||
        SndIsReadShoutVoiceStatus() != 0) {
        return -1;
    }
    return 0;
}

int func_001E1E18(void) {
    if (D_003172F0.f2020 == 0) {
        return 0;
    }
    if (msVoiceCheckStanby(1) != 0) {
        return -1;
    }
    SndStandbyStream(D_003172F0.f2020);
    return 0;
}

int MsVoiceStart(void)
{
    if (D_003172F0.f2020 != 0) {
        if (msVoiceCheckStanby(0) != 0) {
            return -1;
        }
        SndStartStream();
        if (D_003172F0.f2024 >= 0) {
            ((int (*)(int))MsSystemMessageOpen)(D_003172F0.f2024); /* DEBT(CAST): u2.h declares void, returns int */
            D_003172F0.f2024 = -1;
        }
    }
    return 0;
}

int func_001E1ED0(void)
{
    SndStopStream();
    return 0;
}

int MsVoiceStatus(void) {
    if (SndGetStreamState() != 0) {
        return 1;
    }
    return MsSystemMessageCheck() != 0;
}

int func_001E1F20(int v)
{
    return D_00319310 = v;
}

int func_001E1F30(int v)
{
    return D_00319314 = v;
}
