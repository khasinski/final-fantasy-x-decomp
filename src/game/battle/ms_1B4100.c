/* tu_183 0x1b4100-0x1b5298: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void func_001B4100(void) {
    D_00662570 = 0;
    D_00662574 = 0;
    D_00662578 = 0;
}

void MsBtlChrGetMem(void) {
    void *p = user_malloc(0x17DB0, 5, D_0056E370, -1);

    D_00662570 = (s32)p; /* DEBT(TYPE): D_00662570 is declared s32 */
    D_00662574 = (BtlChr *)((u8 *)p + 0xF640);
    D_00662578 = (s32)user_malloc(0x1360, 5, D_0056E378, -1); /* DEBT(TYPE): D_00662578 is declared s32 */
    MsBtlChrInit();
}

s32 MsGetChrTop(void) {
    return D_00662570;
}

void func_001B41A0(void) {
    if (D_00662570 != 0) {
        func_0011D590(D_00662570, 5);
    }
    if (D_00662578 != 0) {
        func_0011D590(D_00662578, 5);
    }
    func_001B4100();
}

void MsBtlChrInit(void) {
    int off = 0;
    int i = 0x1E;

    do {
        MsStructClear((void *)(D_00662570 + off), 0xC50); /* DEBT(CAST): D_00662570 is declared s32 */
        i--;
        off += 0xC50;
    } while (i >= 0);
    MsStructClear(D_00661920, 0xC50);
    off = 0;
    i = 0x3D;
    do {
        MsStructClear((void *)(D_00662578 + off), 0x50); /* DEBT(CAST): D_00662578 is declared s32 */
        i--;
        off += 0x50;
    } while (i >= 0);
}

int MsBtlChrNumCheck(int id) {
    return (u8)id < 0x1F;
}

BtlChr *MsGetChr(int id) {
    id &= 0xFF;
    if (id < 0x1F) {
        return (BtlChr *)((u8 *)D_00662570 + id * 0xC50);
    }
    if (id < 0x5D) {
        return (BtlChr *)((u8 *)D_00662578 + (id * 0x50 - 0x9B0));
    }
    return (BtlChr *)D_00661920;
}

BtlChr *MsGetMon(u8 id) {
    return &D_00662574[id];
}

BtlChr *MsGetWeapon(int id, int flag) {
    id &= 0xFF;
    if (id < 0x1F) {
        if (flag == 0) {
            return (BtlChr *)((u8 *)D_00662578 + id * 0x50); /* DEBT(CAST): D_00662578 is a memory handle used as a table pointer */
        }
        return (BtlChr *)((u8 *)D_00662578 + (id * 0x50 + 0x9B0));
    }
    return 0;
}

int func_001B4350(int id, BtlChr *p, int flags) {
    int r = 0;
    Chr *chr = p->chr;
    s32 a;
    int b;
    int m;

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
    if (p->f11 != 0 && p->f12 == 0) {
        r = 1;
        MsEffectWeaponFree(id);
        m = p->f04;
        a = p->f08;
        b = p->f20;
        if (a != 0 && (flags & 4) && p->f3E == 0) {
            ChN_DisposeSystemMGRP(a, b);
            p->f38 = 0;
        }
        if (m != 0 && (flags & 2) && p->f3E == 0) {
            ChN_DataDispose(m, 0);
        }
        if (p->p48 != 0) {
            func_0011D590((s32)p->p48, 5); /* DEBT(CAST): p48 is a memory handle */
            p->p48 = 0;
        }
        if (id < 31) {
            MsSEPchrClear(p, 0);
        }
    }
    return r;
}

void MsBtlChrFreeAll(void)
{
    BtlChr *c;
    int flags;
    int i;

    for (i = 0; i < 0x5D; i++) {
        c = MsGetChr(i);
        if (c->chr != 0 && c->f12 == 0) {
            Ch_Dispose((int)c->chr); /* DEBT(TYPE): s2.h takes the Chr as int */
        }
    }
    for (i = 0; i < 0x5D; i++) {
        c = MsGetChr(i);
        flags = 0;
        if (c->f22 != 0) {
            flags |= 2;
        }
        if (c->f21 != 0) {
            flags |= 4;
        }
        c->f3E = 0;
        func_001B4350(i, c, flags);
    }
}

int func_001B4538(BtlChr *c) {
    Chr *chr = c->chr;
    int r = 0;

    if (c->f3A != 0 && chr != 0) {
        r = 1;
        Ch_ModelCreatePacket(chr);
    }
    c->f3A = 0;
    return r;
}

void MsBtlChrFree(s32 id, s32 v)
{
    BtlChr *chr;
    s32 i;

    i = 0;
    chr = MsGetChr(id);
    func_001B57F0(id, 0);
    MsResetBindEffect(id);
    MsStatusEffectClear(id);
    MsAtelRequestCancel(2, 0, id + 5);
    func_001B4350(id, chr, v);
    do
    {
        MsWeaponDispose(id, i, v, MsGetWeapon(id, i));
        i += 1;
    } while (i < 2);
    MsBtlChrInfoFree(chr);
}

void MsBtlChrInfoFree(BtlChr *chr) {
    chr->f1C8 = 0;
    chr->fF2 = 0;
    chr->fEE = 0;
    chr->fDC = 0;
    chr->fD5 = 0;
    chr->f4C = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B4100", MsBtlChrRegist);

int func_001B4900(Obj4900 *p) {
    int r = p->f3C != 0;
    if (p->p0 != 0) {
        func_00107C20(p->p0, r);
    }
    return r;
}

int MsResetNormalCalc(void) {
    int n = 0;
    int i;
    for (i = 0; i < 31; i++) {
        BtlChr *c = MsGetChr(i);
        if (c->f3D != 0) {
            n++;
            c->f3D = 0;
            func_001B4900((Obj4900 *)c);
        }
    }
    return n;
}

BtlChr *MsGetWeaponSpecial(int kind, int flag) {
    BtlChr *r = 0;

    if (flag == 0) {
        switch (kind) {
        case 4:
            r = MsGetChr(0x1C);
            break;
        case 5:
            r = MsGetChr(0x1D);
            break;
        case 14:
            r = MsGetChr(0x1E);
            break;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B4100", MsBtlWeaponRegist);

void func_001B4D48(Chr *chr, BtlChr *c)
{
    Ch_SetOffset(chr, 0, 0, 0);
    Ch_SetHideCalc(chr, c->f37);
    Ch_SetMotionType(chr, c->f20);
    Ch_SetFieldMode(chr, c->f20);
    Ch_EnMapID(chr, (s8)c->f32);
    Ch_SetGravMode(chr, c->f34);
    Ch_SetCalcNorm(chr, c->f33);
    ((void (*)(Chr *, int))func_0010C098)(chr, c->f23); /* DEBT(TYPE): funcs.h declares func_0010C098 (void) */
    Ch_EnClip(chr, 0);
    Ch_SetClipZ(chr, 5000.0f);
    msSetChrBodyHit(c, 2, 1);
    func_001B6310(c, 2, -1);
}

s32 func_001B4E18(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f04;
    }
    return 0;
}

Chr *MsGetChrHandle(int arg) {
    u8 id = arg;
    Chr *r = 0;
    if (MsBtlChrNumCheck(id)) {
        r = MsGetChr(id)->chr;
    }
    return r;
}

int MsGetWeaponHandle(int id, int n)
{
    BtlChr *s;
    BtlChr *b;
    Chr *chr;
    int cnt;
    int i;

    id &= 0xFF;
    chr = 0;
    s = MsGetWeapon(id, n);
    if (s != 0 && (chr = s->chr) == 0 && s->f100 != 0) {
        cnt = 0;
        for (i = 0; i < 0x1F; i++) {
            b = MsGetChr(i);
            if (b->fFF == id) {
                cnt++;
                chr = b->chr;
                if (cnt > n) {
                    break;
                }
            }
        }
    }
    return (int)chr;
}

int MsAttachWeapon(int id, int i)
{
    BtlChr *c;
    BtlChr *s;
    BtlChr *b;
    Chr *chr;
    Chr *t;
    int out;

    id &= 0xFF;
    c = MsGetChr(id);
    s = MsGetWeapon(id, i);
    chr = s->chr;
    t = MsGetChrHandle(id);
    if (chr != 0 && t != 0 && c->f175 != 0) {
        func_001B51A0(id, 1);
        Ch_BindToElem(chr, t, s->fD);
        if (c->f176[i] != 0) {
            c->f176[i] = 0;
            if (id == 5) {
                b = MsGetWeaponSpecial(5, i);
                if (b != 0) {
                    MsGetChrStatInfo(5, 0xDB, -0xD, &out);
                    MsSetChrDirTarget(5, 1, 0, -1, out, 0);
                    b->fE0 = 2;
                }
            }
        }
        return 1;
    }
    return 0;
}

int MsDetachWeapon(int id, int i)
{
    BtlChr *c;
    BtlChr *s;
    Chr *chr;
    Chr *t;
    float pos[4];
    float f;

    id &= 0xFF;
    c = MsGetChr(id);
    s = MsGetWeaponSpecial(id, i);
    if (s != 0) {
        s->f15C = c->f15C;
    }
    s = MsGetWeapon(id, i);
    chr = s->chr;
    t = MsGetChrHandle(id);
    if (chr != 0 && c->f175 != 0) {
        c->f176[i] = 1;
        func_001B51A0(id, 0);
        Ch_OptposGet(t, s->fD, pos);
        f = func_00110288(t);
        Ch_BindToElem(chr, 0, 0);
        Ch_SetPos3(chr, pos[0], pos[1], pos[2]);
        Ch_SetDirF(chr, f);
        return 1;
    }
    return 0;
}

void func_001B51A0(int id, int a) {
    Chr *p;

    if (id == 6) {
        if (MsGetChr(6)->f04 == 7) {
            p = MsGetChrHandle(6);
            if (p) {
                graphicCharacterInstanceSetMeshSegmentAlpha((int)p, 1, a); /* DEBT(CAST): Chr pointer passed as int */
            }
        }
    }
}

int func_001B5208(u8 id) {
    BtlChr *c;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        if (c->f10 != 0) {
            return c->fA88;
        }
    }
    return 0;
}

s8 func_001B5258(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f1BC.a;
    }
    return 0;
}
