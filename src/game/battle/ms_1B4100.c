/* tu_183 0x1b4100-0x1b5298: low; ~Ms (config/tu_map.tsv) */
#define MsBtlChrRegist _hdr_MsBtlChrRegist
#define MsBtlWeaponRegist _hdr_MsBtlWeaponRegist
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"
#undef MsBtlChrRegist
#undef MsBtlWeaponRegist

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

extern s8 D_003193FA;
extern void func_001B4D48(Chr *chr, BtlChr *c);

typedef struct {
    Chr *chr;
    u8 pad04[0x1A];
    s8 f1E;
    u8 f1F;
    u8 pad20[0x2C];
    s32 f4C;
    u8 pad50[0x10];
    float f60;
    float f64;
    float f68;
    float f6C;
    u8 pad70[0x50];
    u16 fC0;
    u8 padC2[0x21];
    u8 fE3;
    u8 padE4[0x19];
    s8 fFD;
    u8 padFE[0xE];
    s8 f10C;
    s8 f10D;
    u8 pad10E[0x6D];
    u8 f17B;
    u8 pad17C[0x20];
    float f19C;
    u8 pad1A0[4];
    float f1A4;
    float f1A8;
    u8 pad1AC[0x1A];
    s8 f1C6;
    u8 pad1C7[0xA];
    s8 f1D1;
    u8 pad1D2[2];
    float f1D4[8];
    u8 pad1F4[0x89A];
    s8 fA8E;
    u8 padA8F[0x5D];
    s32 fAEC;
} BtlChrReg; /* DEBT(NAME): offset view of BtlChr for MsBtlChrRegist */

Chr *MsBtlChrRegist(int a, s32 model)
{
    u8 id = a;
    float pos[3];
    int created = 0;
    BtlChrReg *c = (BtlChrReg *)MsGetChr(id); /* DEBT(CAST): offset view of BtlChr */
    Chr *chr;
    float weight;
    int show;

    func_001B4538((BtlChr *)c);
    chr = c->chr;
    if (chr == 0) {
        created = 1;
        c->chr = (Chr *)func_00102B98(model);
        chr = c->chr;
    }
    Ch_SetBattleChrNum(chr, id);
    MsSetChrHeight(id);
    if (created != 0 || D_003193FA != 0 || c->f1C6 != 0) {
        MsGetChrBtlPos(id, pos);
        Ch_SetPos3(chr, pos[0], pos[1], pos[2]);
        Ch_ClothReset(chr);
    } else {
        Ch_GetPos(chr, &pos[0], &pos[1], &pos[2]);
    }
    if (c->f10C == 0) {
        c->f1A4 = func_001109E0(chr);
    }
    if (c->f10D == 0) {
        c->f1A8 = (MsGetChrHeight(id) * 13.0f) / 14.0f;
    }
    weight = c->f19C;
    if (c->fA8E != 0) {
        weight = -1.0f;
    }
    ((void (*)(Chr *, int))Ch_SetMotionSpeed)(chr, c->fC0); /* DEBT(CAST): header takes s16, original passes u16 zero-extended */
    Ch_SetThickness(chr, c->f1A4);
    Ch_SetWeight(chr, weight);
    Ch_SetDirF(chr, c->f1D4[c->f1D1]);
    Ch_SetScale(chr, 7, c->f60, c->f64, c->f68);
    Ch_BindSetScale(chr, c->f6C);
    Ch_SetSp(chr, 0.0f);
    func_00110540(chr, 0, 1.0f);
    Ch_EffectSetEffectLevel(chr, c->fAEC);
    func_001B4900(c);
    MsSetMotBinAddress((BtlChr *)c, c->f17B);
    func_001B4D48(chr, (BtlChr *)c);
    if (c->f4C == 0) {
        c->f4C = Ch_EffectGetResidentPtr(chr);
    }
    func_00298E30();
    show = 1;
    {
        int fd = c->fFD;
        if (fd & 1) {
            c->fE3 |= 1;
            show = 0;
        }
        if (fd & 4) {
            show = 0;
        }
        if (created != 0 && (fd & 8)) {
            c->fE3 |= 1;
            show = 0;
        }
    }
    if (c->f1E != 0) {
        c->f1F = 1;
        op_et_bindeff(chr);
    }
    func_001B57F0(id, show);
    return chr;
}

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

extern int MsGetSaveWeaponModel(int);
extern void MsGetChrBtlPos(int, float *);
extern void MsSetChrPosReset(int, float *);
extern void MsSetChrDirF(int, float);
extern void func_001B4D48(Chr *, BtlChr *);
extern void MsSetWeaponEffectAttribute(int, void *);

void *MsBtlWeaponRegist(int chr_id, int a1, int slot)
{
    float pos[4];
    u8 *chr = (u8 *)MsGetChr(chr_id);
    int f2E;
    int f2B;
    int f175;
    int f34;
    int f32;
    int created = 0;
    u8 *wep = (u8 *)MsGetWeapon(chr_id, slot);
    int model = MsGetSaveWeaponModel((chr + slot)[0x252]);
    void *hdl;

    if (*(int *)(wep + 4) != model) {
        *(int *)(wep + 4) = model;
        if (*(void **)wep != 0) {
            Ch_Dispose(*(void **)wep);
            ChN_DataDispose(*(int *)(wep + 4), 0);
            *(void **)wep = 0;
        }
    }
    hdl = *(void **)wep;
    func_001B4538(wep);
    if (model != 0 && hdl == 0) {
        created = 1;
        hdl = func_00102B98(model);
        *(void **)wep = hdl;
    }
    if (hdl != 0) {
        u8 *sp = (u8 *)MsGetWeaponSpecial(chr_id, slot);

        f175 = 1;
        f32 = 0;
        f34 = 1;
        f2E = 0;
        f2B = 0;

        if (sp != 0) {
            u8 sp_id = sp[0xC];
            *(void **)sp = hdl;
            switch (sp_id) {
            case 0x1C:
                f34 = 0;
                break;
            case 0x1E:
                sp[0x1BC] = 0;
                sp[0x1BE] = chr_id;
                sp[0x1BD] = 0xE;
                f175 = 0;
                MsPushBtlPos(sp);
                MsGetChrBtlPos(0x1E, pos);
                MsSetChrPosReset(0x1E, pos);
                *(float *)(sp + 0x1D4) = *(float *)(chr + 0x1D4);
                *(float *)(sp + 0x1D8) = *(float *)(chr + 0x1D8);
                MsSetChrDirF(0x1E, ((BtlChr *)sp)->f1D4[((s8 *)sp)[0x1D1]]);
            case 0x1D:
                f2E = 1;
                f2B = 1;
                f32 = 1;
                break;
            }
            chr[0x13] = sp_id;
            sp[0x14] = chr_id;
            sp[0x12] = 1;
            sp[0x15] = 1;
            sp[0x2B] = f2B;
            sp[0x2E] = f2E;
            sp[0x32] = f32;
            sp[0x34] = f34;
            MsSetMotBinAddress(sp, sp[0x17B]);
            Ch_SetBattleChrNum(hdl, sp_id);
            Ch_SetWeight(hdl, *(float *)(sp + 0x19C));
            if (*(int *)(wep + 8) != 0) {
                sp[0x38] = 1;
                MsSetMotion(sp_id, 0x27, 0, 0, 1, 0, 0);
                MsSetMotion(sp_id, 0, 0, 0, 1, 0, 0);
            }
        }
        wep[0x2B] = f2B;
        wep[0x2E] = f2E;
        wep[0x32] = f32;
        wep[0x34] = f34;
        func_001B4D48((Chr *)hdl, (BtlChr *)wep);
        chr[0x175] = f175;
        if (f175 == 0 || ((s8 *)chr)[0x1D] == 0) {
            func_00110738(hdl, 1);
            func_00110718(hdl, 1);
        } else if (created != 0) {
            func_00110540(hdl, 0, 0.0f);
            func_00110540(hdl, 8, 1.0f);
        }
        MsAttachWeapon(chr_id, slot);
        if (a1 == 0) {
            MsSetWeaponEffectAttribute(chr_id, chr);
        }
    }
    return hdl;
}

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
