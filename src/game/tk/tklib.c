/* tu_043 0x124440-0x126108: medium; tklib (config/tu_map.tsv) */
#include "common.h"
#define func_00125268 q0_func_00125268 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/q0.h"
#undef func_00125268
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#define func_00124530 q1_func_00124530 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124550 q1_func_00124550 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TkMalloc q1_TkMalloc /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TkFree q1_TkFree /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124BC8 q1_func_00124BC8 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124BE8 q1_func_00124BE8 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124C08 q1_func_00124C08 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124C28 q1_func_00124C28 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124C48 q1_func_00124C48 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TkGetNowEventJumpMapNo q1_TkGetNowEventJumpMapNo /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124C88 q1_func_00124C88 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00124CA8 q1_func_00124CA8 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define func_00125268 q1_func_00125268 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TkCdReadSync q1_TkCdReadSync /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TOSetAlbhedFlg q1_TOSetAlbhedFlg /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/q1.h"
#undef func_00124530
#undef func_00124550
#undef TkMalloc
#undef TkFree
#undef func_00124BC8
#undef func_00124BE8
#undef func_00124C08
#undef func_00124C28
#undef func_00124C48
#undef TkGetNowEventJumpMapNo
#undef func_00124C88
#undef func_00124CA8
#undef func_00125268
#undef TkCdReadSync
#undef TOSetAlbhedFlg

void func_00124440(void)
{
    D_00580E68 = FFXGetLang();
}

u8 func_00124468(void)
{
    return D_00580E68;
}

void func_00124478(u8 v)
{
    D_00580E67 = v;
}

u8 func_00124488(void)
{
    return D_00580E67;
}

s32 *func_00124498(void)
{
    return &D_00588EC0;
}

void func_001244A8(u8 v)
{
    D_00567EB2 = v;
}

void func_001244B8(void)
{
    func_002D9880();
}

u8 TkGetTGS(void)
{
    return D_00567EB2;
}

s32 *TkGetFFXCofingAdrs(void)
{
    return &D_00588E80;
}

int TkMsImportantSet(int a) /* DEBT(TYPE): returns nothing */
{
    MsImportantSet(a);
    if ((u32)(a - 0xA004) < 0x1A) {
        TOSetAlbhedFlg(a - 0xA004);
    }
}

void func_00124528(int i)
{
    func_001DD998(i);
}

u8 func_00124530(void)
{
    u8 old = D_00308935;
    D_00308935 = 0;
    return old;
}

u8 func_00124540(void)
{
    return D_00308935;
}

void func_00124550(RecBackup *r)
{
    r->hC0 = r->h00;
    r->hC2 = r->h02;
    r->hC4 = r->h04;
    r->hC6 = r->h06;
    r->hC8 = r->h08;
    r->hCA = r->h0A;
    r->hCC = r->b0C;
    r->vCE.h = r->b0D;
}

void TkSetEvSaveStatus(Rec124828 *r)
{
    r->x2A = 1;
}

void func_001245A8(RecBackup *r)
{
    r->h02 = r->hC2;
    r->b0D = r->vCE.b;
}

void func_001245C0(RecBackup *r)
{
    r->h06 = r->hC6;
    r->h0A = r->hCA;
}

s32 *func_001245D8(void)
{
    return &D_00580E80;
}

s32 func_001245E8(void)
{
    return D_0058CEC0;
}

void func_001245F8(u8 v)
{
    D_00580E66 = v;
}

u8 func_00124608(void)
{
    return D_00580E66;
}

void func_00124618(u8 v)
{
    D_00580E65 = v;
}

u8 func_00124628(void)
{
    return D_00580E65;
}

s32 TkGetEncountCounterEventStart(void)
{
    return D_00580E60;
}

int func_00124648(void)
{
    return func_00124828()->x2B;
}

int func_00124668(int v)
{
    ((RecBackup *)func_00124828(v))->b2B = v; /* DEBT(CAST) */
}

void func_00124690(s32 v)
{
    D_00580E64 = (v != 0);
}

u8 func_001246A0(void)
{
    return D_00580E64;
}

void *TkMalloc(s32 size)
{
    s32 n = (size + 0x7FF) / 0x800 * 0x800;

    func_0011C348(0x40);
    return user_malloc(n, 4, 0, -1);
}

void func_00124708(void)
{
    func_0011C328(0, D_0056A080, 0x173);
    func_0011C328(1, D_0056A080, 0x174);
}

void func_00124748(void)
{
    func_0011C328(0, D_0056A080, 0x17E);
    func_0011C328(1, D_0056A080, 0x17F);
}

void TkFree(s32 h)
{
    func_0011D590(h, 4);
    func_0011C328(0, D_0056A080, 0x18E);
    func_0011C328(1, D_0056A080, 0x18F);
}

void TkSetMapGroupDrawStatus(s32 bit, s32 on)
{
    u32 m = yiGetDrawMask();

    if (on != 0) {
        m |= 1 << bit;
    } else {
        m &= ~(1 << bit);
    }
    yiSetDrawMask(m);
}

Rec124828 *func_00124828(int idx)
{
    return func_001BE338();
}

void func_00124848(s32 v)
{
    D_00580E48 = v;
}

void func_00124858(s32 a, s32 b)
{
    D_00580E50 = a;
    D_00580E54 = b;
}

void func_00124870(s32 a, s32 b)
{
    D_00580E58 = a;
    D_00580E5C = b;
}

s32 func_00124888(void)
{
    return D_00580E50;
}

s32 func_00124898(void)
{
    return D_00580E54;
}

s32 func_001248A8(void)
{
    return D_00580E58;
}

s32 func_001248B8(void)
{
    return D_00580E5C;
}

INCLUDE_ASM("build/ee_asm/game/tk/tklib", func_001248C8);

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void func_00124A98(void)
{
    s32 value0;
    s32 value1;
    s32 value2;
    void *value3;

    value1 = func_2058460(&D_00308918);
    if (value1 >= 0)
    {
        value2 = func_2058630(value1);
        value0 = value2 + 4;
        value3 = TkMalloc(value0);
        func_002EF0D0(value3, 0, value0);
        func_20585B8(value1, value3, value2);
        func_2058698(value1);
        func_001248C8(value3);
        TkFree((s32) value3);
    }
}

s32 func_00124B50(void)
{
    return D_00580E40;
}

void TkSetEventJumpMapNo(int a, int b)
{
    Rec124828 *r = CALL0_func_00124828();

    r->x06 = r->x04;
    r->x0A = r->x08;
    if (r->x2A) {
        func_001245C0(r);
    }
    r->x08 = b;
    r->x04 = a;
    r->x2A = 0;
}

u16 func_00124BC8(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h02; /* DEBT(CAST) */
}

u16 func_00124BE8(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h06; /* DEBT(CAST) */
}

u16 func_00124C08(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h0A; /* DEBT(CAST) */
}

u8 func_00124C28(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->b0D; /* DEBT(CAST) */
}

u16 func_00124C48(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h00; /* DEBT(CAST) */
}

u16 TkGetNowEventJumpMapNo(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h04; /* DEBT(CAST) */
}

u16 func_00124C88(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->h08; /* DEBT(CAST) */
}

u8 func_00124CA8(s32 idx)
{
    return ((RecBackup *)func_00124828(idx))->b0C; /* DEBT(CAST) */
}

void func_00124CC8(int a, int b)
{
    Rec124828 *r = CALL0_func_00124828();
    int old_a = a;

    if (old_a < 0) {
        b = r->xB8;
        a = r->xBA;
        r->xB8 = 0;
    }
    r->x0D = r->x0C;
    r->x02 = r->x00;
    r->x00 = a;
    r->x0C = b;
    if (old_a < 0) {
        func_001245A8((RecBackup *)r); /* DEBT(CAST) */
    }
    D_00580E44 = 1;
}

void func_00124D40(void)
{
    D_00580E48 = 0;
    func_00124CC8(-1, 0);
    D_00580E4C = 0;
}

void func_00124D70(s32 prio)
{
    func_002F8270(func_002F82D0(), prio);
}

void func_00124DA0(void)
{
    if (D_00580E4C != 0) {
        func_0020A7B8();
        AtelEventRemove();
        D_00580E4C = 0;
    }
}

u32 func_00124DE0(u32 a, u32 b)
{
    return (a + b - 1) / b * b;
}

void func_00124E00(int v)
{
    MsCameraInit();
    TOAllCloseMessageWindow();
    func_0020A7B8();
    func_00124DA0();
    AtelEventSetUp(v);
    D_00580E44 = 0;
    D_00580E4C = 1;
    D_00580E48 = 0;
    D_00580E60 = MsGetSaveBattleCount();
}

void func_00124E70(void)
{
    func_0014E6F8();
    D_00580E40 = 1;
}

s32 func_00124E98(void)
{
    return 0;
}

void TkCtrl(void)
{
    if (D_00580E44) {
        if (D_00580E48 <= 0) {
            func_00124E00(CALL0_func_00124828()->x00);
        } else {
            D_00580E48--;
        }
    }
    func_0014E638();
    D_00580E40 = 0;
    func_00124E70();
    func_0013ABD0(1);
    TkSndUpdate2();
}

void func_00124F08(void)
{
    func_00124FE8(0, 0);
}

void func_00124F18(int a)
{
    u32 *p;

    func_00124F08();
    func_002F8660(0);
    SYNC();
    SYNC_P();
    p = func_002DB6D8(1);
    *p |= 0x40;
    func_002DBA28(p, a);
}

void func_00124F68(void)
{
    int r;

    func_0014E7F8();
    r = func_2065BA8(0, 0, 0);
    if (func_00124608()) {
        func_00124F18(r);
        func_00124FE8(0, 0);
    }
    func_001245F8(0);
}

void TkDrawNoTrans(void)
{
    AtelDrawNoTrans();
    TkSndUpdate2();
}

int func_00124FE8(int a, u16 b)
{
    return func_002DA610(a, b);
}

void func_00125008(void) {
}

void func_00125010(void)
{
    AtelDrawSemiTrans();
}

void func_00125018(void) {
}

void func_00125020(void) {
}

void func_00125028(void)
{
    func_002D41D8();
    func_002D3D00();
    func_00124D40();
    D_00580E40 = 1;
}

void func_00125060(void)
{
    func_002D3D00();
}

void func_00125068(void)
{
    func_00125060();
    func_00125028();
}

void TkRemove(void)
{
    func_001458A8();
    func_002D9188();
    func_002D3AA8(-1, 0);
    func_002D24F8();
    if (TkIsDebug()) {
        func_2064640();
    }
    func_002DDE58();
    func_00124D70(0);
    func_0020A818();
}

/* DEBT(CAST): allocation and I/O APIs expose buffer addresses as integer handles. */
int func_001250E8(int a, int b)
{
    SysVt *api = GetCD();
    u8 *buffer;

    api->f10(a);
    buffer = (u8 *)TkMalloc(api->f14(b));
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 0;
    buffer[3] = 0;
    func_002F8660(0);
    api->f0(b, (int)buffer, 0, 0);
    api->f8(0);
    return (int)buffer;
}

/* DEBT(CAST): allocation and I/O APIs expose buffer addresses as integer handles. */
int TkCdReadWithMallocWithMessage(int a, int b)
{
    SysVt *api = GetCD();
    int buffer;
    int size;

    api->f10(a);
    size = api->f14(b);
    AtelPs2DebugString(D_0056A088);
    buffer = TkMalloc(size);
    AtelPs2DebugString(D_0056A098);
    ((u8 *)buffer)[0] = 0;
    ((u8 *)buffer)[1] = 0;
    ((u8 *)buffer)[2] = 0;
    ((u8 *)buffer)[3] = 0;
    func_002F8660(0);
    AtelPs2DebugString(D_0056A0B0);
    api->f0(b, buffer, 0, 0);
    AtelPs2DebugString(D_0056A0C0);
    api->f8(0);
    func_002F8660(0);
    return buffer;
}

void func_00125268(s32 a, s32 b, s32 c)
{
    SysVt *api;

    api = GetCD();
    api->f10(a);
    api->f14(b);
    func_002F8660(0);
    api->f0(b, c, 0, 0);
    api->f8(0);
    func_002F8660(0);
}

int TkCdReadNB(int a, int b, int c)
{
    SysVt *vt = GetCD();

    vt->f10(a);
    func_002F8660(0);
    return vt->f0(b, c, 0, 0);
}

int TkCdReadSync(int v)
{
    return GetCD()->f8(v);
}

/* DEBT(CAST): allocation and I/O APIs expose buffer addresses as integer handles. */
int func_001253A0(int a, int b, int minimum)
{
    SysVt *api = GetCD();
    int size;
    u8 *buffer;

    api->f10(a);
    size = api->f14(b);
    buffer = (u8 *)TkMalloc(size >= minimum ? size : minimum);
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 0;
    buffer[3] = 0;
    func_002F8660(0);
    api->f0(b, (int)buffer, 0, 0);
    api->f8(0);
    func_002F8660(0);
    return (int)buffer;
}

s32 TkCdSize(int a, int b)
{
    SysVt *vt = GetCD();

    vt->f10(a);
    return vt->f14(b);
}

void func_001254B8(void)
{
    D_0030893C = func_001250E8(0x18, 4);
}

void func_001254E0(void) {
}

void func_001254E8(s32 v)
{
    ((u8 *)TkGetFFXCofingAdrs())[0xC] = v; /* DEBT(CAST) */
}

void func_00125510(void)
{
    D_00580E6C = 0;
}

void func_00125520(void)
{
    D_00580E70++;
    if (D_00580E6C < 0x14C) {
        D_00580E6C += 0x14;
    } else {
        D_00580E6C = 0;
    }
}

void func_00125558(const char *msg) {
}

void func_00125560(void)
{
    if (D_00308938 != 0) {
        TkFree(D_00308938);
    }
    D_00308938 = func_001253A0(0x19, 0, 0x8000);
}

void func_001255A8(void)
{
    Rec124828 *save;

    func_00125510();
    D_00580E70 = 0;
    func_002D4210();
    func_002D3B88();
    func_002D4148();
    D_00580E64 = 1;
    D_00580E65 = 0;
    D_00308938 = 0;
    func_00124478(0);
    func_00124668(0);
    func_001245F8(0);
    save = CALL0_func_00124828();
    save->control10.flags = (save->control10.flags | 0x2000000) & ~0x4000000;
}

INCLUDE_ASM("build/ee_asm/game/tk/tklib", func_00125638);

void func_001256F0(void)
{
    s32 value0;
    s32 value1;

    func_00125558(D_0056A158);
    value0 = TkCdSize(0x18, 5);
    value1 = func_001250E8(0x18, 5);
    func_00125558(D_0056A160);
    func_002D7738(value1, value0);
    func_00125558(D_0056A168);
    SndDataSendSync(1);
    if (value1 != 0)
    {
        TkFree(value1);
    }
    func_00125558(D_0056A170);
}

void func_00125788(void)
{
    s32 r;

    func_00125558(D_0056A178);
    r = TkCdSize(0x26, 0x10);
    func_00125558(D_0056A188);
    func_00125268(0x26, 0x10, func_001245D8());
    D_0058CEC0 = r;
}

void func_001257F0(void)
{
    s32 value0;

    func_00125558(D_0056A198);
    TkCdSize(0x18, 0);
    value0 = func_001250E8(0x18, 0);
    func_00125558(D_0056A1A8);
    func_00252598(value0);
    func_00125558(D_0056A1B8);
    SndDataSendSync(1);
    func_002518C8(1);
    func_00125558(D_0056A1C8);
    TkFree(value0);
}

void func_00125878(void)
{
    int i;

    func_00125558(D_0056A1D8);
    for (i = 0; i < 0x62; i++) {
        func_00252768(i, 1);
        func_002518C8(1);
    }
    func_00125558(D_0056A1E8);
}

INCLUDE_ASM("build/ee_asm/game/tk/tklib", func_001258D0);

INCLUDE_ASM("build/ee_asm/game/tk/tklib", func_001259B8);

void WMainProc(void)
{
    func_00125558(D_0056A2B0);
    SndInitWork();
    func_00125558(D_0056A2C0);
    func_001258D0(1);
    func_00125558(D_0056A2D0);
    func_002D8008(0);
    func_00125558(D_0056A2E0);
    func_001257F0();
    func_00125558(D_0056A2F0);
    func_00125878();
    func_00125558(D_0056A300);
    func_001259B8(1);
    func_00125558(D_0056A310);
    func_001256F0();
    func_00125558(D_0056A318);
    func_00125788();
}

void TkRefreshHDDMode(void)
{
    char *s = D_0056A320;

    if (D_005661F4) {
        s = get_hdd_name(0x2C);
    }
    SqsInitWaveInfoHdd(s);
    s = D_0056A320;
    if (D_005661F4) {
        s = get_hdd_name(0x2D);
    }
    SqsInitMusicInfoHdd(s);
}

void func_00125BA8(void)
{
    func_001258D0(0);
}

void func_00125BB0(void)
{
    func_00125BA8();
}

INCLUDE_ASM("build/ee_asm/game/tk/tklib", TkInitSaveWork);

u16 func_00125D60(s32 i)
{
    return D_00308940[i / 64];
}

int func_00125D90(int a)
{
    return D_00308940[(0x1000 - a) / 64];
}

void func_00125DC8(void)
{
    u16 *p = D_00308940;
    int v;
    int i;

    p += 64;
    v = 0x1000;
    *p = v;
    for (i = 0; i < 64; i++) {
        p--;
        *p = v;
        v = (v * 9) / 10;
    }
    p--;
    *p = 0;
}

void func_00125E20(void)
{
    func_00125268(0x18, 8, &D_00588EC0);
}

void func_00125E38(void)
{
    func_00125E20();
}

INCLUDE_ASM("build/ee_asm/game/tk/tklib", func_00125E40);
