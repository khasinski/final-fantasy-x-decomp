/* tu_180 0x1af9e8-0x1b15c8: low; ~Ms (config/tu_map.tsv) */
#define func_001B0290 _hdr_func_001B0290
#define func_001B0480 _hdr_func_001B0480
#define func_001B0528 _hdr_func_001B0528
#define func_001B0940 _hdr_func_001B0940
#define MsBtlReadSetScene _hdr_MsBtlReadSetScene
#define MsBtlReadMonsterProcess _hdr_MsBtlReadMonsterProcess
#define MsGetChrEscapePos _hdr_MsGetChrEscapePos
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"
#undef MsGetChrEscapePos
#undef MsBtlReadMonsterProcess
#undef MsBtlReadSetScene
#undef func_001B0940
#undef func_001B0528
#undef func_001B0480
#undef func_001B0290

int func_001B0940(void);
int func_001B0290(void);
void func_001B0480();
void func_001B0528(void);
void func_001B1598(void);

s8 func_001AF9E8(int flag) {
    s8 old = D_003172F0.f30;
    D_003172F0.f30 = flag & 1;
    return old;
}

int func_001AFA00(void) {
    return func_002D9880();
}

void func_001AFA20(int n) {
    if (func_0020D540()) {
        if (n < 0) {
            D_00319464 = (D_00319464 + 1) & 7;
            n = D_00319464;
        }
        func_0011BFD0();
        Sg_DebugFill(n);
    }
}

void func_001AFA80(void) {
    D_0065FF70 = 0;
    D_003172F0.f59 = D_003172F0.f5A = 0;
    D_0065FF74 = 0;
}

void MsBtlReadCueManage(void);
void func_001B0100(void);
int AtelIsCallbackQue(void);
void func_001AE4A8(int, int);
void func_002F8660(int);
void func_00173068(int, int);
void func_00173010(int, int);
int yiGetRenderStatus(void);
void MsCalcChrDirAll(void);
int MsGetFirstAttack(int);
void func_002D8778(int);
int MsAtelRequestCamera(int, int, int, int, int, int, int, int);
int MsSetChrVisibleEvent(int, int);
void func_001B1490(int id, int mask);
int func_001B1058(void);
u8 MsBtlReadCueLevel(void);
void func_001B0AB0(int arg);
void MsMessageCueRegist(int, int, int, int, int);
int MsSEPtransCheck(void);
int func_001B0FE8(void);
int _m_func_0010AE48(void) __asm__("func_0010AE48");
void MsAtelRequestSystemCheckExe(int, int, int, int);

typedef struct {
    u8 pad00[0x10];
    s8 f10;
    u8 pad11[0x1C - 0x11];
    s32 f1C;
    u8 pad20[0x48 - 0x20];
    s8 f48;
    u8 f49;
    u8 pad4A[0x53 - 0x4A];
    u8 f53;
    u8 pad54[0xBC - 0x54];
    void *pBC;
    u8 padC0[0xD4 - 0xC0];
    u8 scene[0x1C];
    void *pF0;
    u8 padF4[0x1752 - 0xF4];
    s8 f1752;
    u8 pad1753[0x1984 - 0x1753];
    u16 f1984;
    u8 pad1986[4];
    u8 f198A[0x2040 - 0x198A];
    s32 w2040;
    u8 pad2044[0x20FC - 0x2044];
    s8 f20FC;
    u8 pad20FD[0x2109 - 0x20FD];
    s8 f2109;
    s8 f210A;
    u8 pad210B;
    s8 f210C;
    u8 pad210D[0x2115 - 0x210D];
    u8 f2115;
} GsReadView;

typedef struct {
    u8 pad0[0x3D14];
    u32 w3D14;
} Save3D14;

extern GsReadView _gs_read __asm__("D_003172F0");
extern Save3D14 _save_3d14 __asm__("D_003194D0");
extern int D_0065FF78;
extern int D_0065FF7C;
extern int D_0065FF80;
void MsBtlReadCueRegist(int a, int b, int c, int d, int e);

void MsBtlReadManage(void)
{
    u8 *s;
    int i;
    BtlChr *c;
    int id;

    if (_gs_read.f48 != 0 && (s8)_gs_read.f49 != 0) {
        _gs_read.f49--;
        return;
    }
    s = _gs_read.scene;
    switch (_gs_read.f10) {
    case 4:
        if (AtelIsCallbackQue() != 0) {
            break;
        }
        _gs_read.f10 = 5;
    case 5:
        {
            void *p = *(void **)(s + 4);
            _gs_read.f10 = 6;
            func_001AE4A8(_gs_read.f2109, _gs_read.f1C);
            GetCD()->f0(_gs_read.f1C, p, func_001B0100, 0);
        }
        break;
    case 7:
        func_002F8660(0);
        if (MsBtlReadSetScene() == 10) {
            goto state_10;
        }
    case 8:
        _gs_read.f10 = 9;
        _gs_read.f210A = 1;
        {
            int fld = _gs_read.f1984 & 0x3FF;
            if (_gs_read.f1984 & 0x400) {
                func_00173068(fld, 0);
            } else {
                func_00173010(fld, 0);
            }
        }
        break;
    case 9:
        if ((yiGetRenderStatus() & 0x20) != 0) {
            break;
        }
        if ((yiGetRenderStatus() & 0x40) != 0) {
            break;
        }
        _gs_read.f10 = 10;
    case 10:
    state_10:
        _gs_read.f20FC = 1;
        MsCalcChrDirAll();
        _gs_read.f210C = MsGetFirstAttack(0x20);
        MsAtelRegist(0, _gs_read.f198A, _gs_read.pBC);
        MsAtelRegist(0, _gs_read.f198A, *(void **)(s + 8));
        func_001B1700(0);
        if (_gs_read.f53 != 0xFF) {
            _gs_read.f210C = _gs_read.f53;
        }
        func_002D8778(((s8 *)_gs_read.pF0)[1] == 1);
        if (_save_3d14.w3D14 < 0xFFFFFFF && _gs_read.f2115 != 2) {
            _save_3d14.w3D14++;
        }
        MsAtelRequestCamera(0, 0xFF, 0x18, 0xFFFF, 0, 1, 0, 0);
        _gs_read.f49 = 0x3C;
        for (i = 0; i < 18; i++) {
            c = MsGetChr(i);
            MsSetChrVisibleEvent(i, 0);
            if (c->fA88 == 0) {
                func_001B57F0(i, 0);
            } else {
                MsSetMotion(i, 0x3F, 0, 0, 1, 0, 0);
            }
        }
        if (_gs_read.f210A != 0) {
            func_001B1058();
        }
        _gs_read.f10 = 11;
    case 11:
        for (i = 0; i < 18; i++) {
            c = MsGetChr(i);
            id = c->f0C;
            if (c->fA88 != 0) {
                ((u8 *)&btlgetdata)[id] = 1;
                MsBtlReadCueRegist(0, id, id, c->f04, 1);
            }
        }
        for (i = 0; i < 18; i++) {
            c = MsGetChr(i);
            id = c->f0C;
            if (c->fA88 != 0) {
                func_001B1490(id, 3);
            }
        }
        _gs_read.f10 = 12;
    case 12:
        if (MsBtlReadCueLevel() != 0) {
            break;
        }
        MsAtelRequestCamera(0, 0xFF, 0x75, 0xFFFF, 0, 1, 0, 0);
        _gs_read.f49 = 0x3C;
        func_001B0290();
        break;
    case 14:
        D_0065FF78 = 0;
        D_0065FF7C = 0;
        D_0065FF80 = 0;
        for (i = 0; i < 8; i++) {
            id = i + 20;
            c = MsGetChr(id);
            if (c->fE != 0xFFFF && ((s8 *)c)[0x24] != 0) {
                s32 f04 = c->f04;
                s32 f08 = c->f08;
                MsBtlReadCueRegist(0, id, id, f04, 0);
                MsBtlReadCueRegist(2, id, id, f08, 3);
            }
        }
        _gs_read.f10 = 15;
        break;
    case 15:
        if (MsBtlReadCueLevel() != 0) {
            break;
        }
        MsAtelRequestCamera(0, 0xFF, 0x76, 0xFFFF, 0, 1, 0, 0);
        _gs_read.f49 = 0x3C;
        _gs_read.f10 = 16;
    case 16:
        _gs_read.f10 = 17;
        func_001B0AB0(((s8 *)(*(void **)(s + 0x1C)))[2]);
        break;
    case 19:
        for (i = 0; i < 18; i++) {
            c = MsGetChr(i);
            id = c->f0C;
            if (c->fA88 != 0) {
                MsBtlReadCueRegist(2, id, id, c->f08, 2);
            }
        }
        _gs_read.f10 = 20;
    case 20:
        if (MsBtlReadCueLevel() != 0) {
            break;
        }
        _gs_read.f10 = 21;
    case 21:
        switch (_gs_read.f210C) {
        case 0:
            break;
        case 1:
            MsMessageCueRegist(2, 0, 0, 0x11, 0x19);
            break;
        case 2:
            MsMessageCueRegist(3, 0, 0, 0x11, 0x19);
            break;
        }
        _gs_read.f10 = 22;
    case 22:
        if (_gs_read.w2040 != 0) {
            break;
        }
        if (MsSEPtransCheck() != 0) {
            break;
        }
        if (func_001B0FE8() != 0) {
            break;
        }
        _m_func_0010AE48();
        _gs_read.f10 = 1;
        _gs_read.f1752 = 1;
        MsAtelRequestSystemCheckExe(5, 1, 0, 0);
        MsAtelRequestCamera(0, 0xFF, 0x7C, 0xFFFF, 0, 1, 0, 0);
        break;
    }
    MsBtlReadCueManage();
}

void func_001B0100(void) {
    D_00317300 = 7;
}

typedef struct {
    int w0;
    int w4;
    int w8;
    int wC;
    int w10;
    int w14;
    int w18;
    int w1C;
} SceneBlob;

typedef struct {
    u8 b0;
    u8 pad1[3];
    SceneBlob *p4;
    u8 *p8;
    u8 *pC;
    u8 *p10;
    u8 *p14;
    u8 *p18;
    u8 *p1C;
} SceneState;

typedef struct {
    u8 pad0[0x10];
    s8 f10;
    u8 pad11[0x5A - 0x11];
    s8 f5A;
    u8 pad5B[0xD4 - 0x5B];
    SceneState scene;
    u8 padF4[0x1984 - 0xF4];
    s16 f1984;
    u8 pad1986[0x20FE - 0x1986];
    u8 f20FE;
    u8 pad20FF[0x2109 - 0x20FF];
    s8 f2109;
} GsScene_View;
extern GsScene_View _gs_scene __asm__("D_003172F0");

void TOFTCTransfer(void *p);
void func_20471E0(void);
void MsActionInit(void);
void MsSetRamChrData(void);
void MsBtlBridgeEvent2Btl(void);
void AtelEventRemoveForBattle(int v);
extern char D_0056E230[];
extern char D_0056E248[];
int MsGetChrID(BtlChr *c);
void func_001B0460(Q4Link *p);

int MsBtlReadSetScene(void) {
    s8 flag = _gs_scene.f2109;
    SceneState *s = &_gs_scene.scene;
    SceneBlob *p = s->p4;
    int off1;
    int off2;
    int next;

    s->p8 = (u8 *)p + p->w4;
    s->p10 = (u8 *)p + p->w8;
    s->p1C = (u8 *)p + p->wC;
    s->pC = (u8 *)p + p->w10;
    s->p14 = 0;
    s->p18 = 0;
    off1 = p->w14;
    off2 = p->w18;
    if (flag == 0 && func_001BD360() != 0) {
        off1 = p->w1C;
        off2 = 0;
    }
    if (off1 != 0) {
        s->p14 = (u8 *)p + off1;
        if (off2 != 0 && flag == 0) {
            u8 *ptr = (u8 *)p + off2;
            s->p18 = ptr;
            TOFTCTransfer(ptr);
        }
    }
    s->b0 = *s->p10;
    _gs_scene.f20FE = s->p1C[3];
    if (flag == 0 && FFXIsDebug() != 0) {
        func_20471E0();
    }
    next = 0;
    if (flag == 0) {
        MsActionInit();
        MsSetRamChrData();
        MsPushBtlPosAll();
        MsBtlBridgeEvent2Btl();
        AtelEventRemoveForBattle(_gs_scene.f1984);
        Sg_SetPlayer(0);
        Sg_IdSetEffectTableIndex(1);
        if (func_0013A278() != _gs_scene.f1984) {
            next = 8;
        } else {
            next = 10;
        }
    }
    _gs_scene.f10 = next;
    return next;
}

typedef struct {
    int f0[3];
    int fC;
    int f10;
    int f14[3];
} CdMonArg;

int func_001B0290(void) {
    int i = _gs_scene.f5A;
    CdMonArg sp0;

    _gs_scene.f10 = 0xD;
    for (; i < 8; i++) {
        BtlChr *m = S2_MsGetMon(i);
        if (m->fE != 0xFFFF) {
            int id;
            int sz;
            GetCD()->f10(0x10);
            id = MsGetChrID(m);
            sz = GetCD()->f14(id);
            if (sz != 0) {
                void *buf = 0;
                int j;
                for (j = 0; j < i; j++) {
                    BtlChr *m2 = S2_MsGetMon(j);
                    void *p48;
                    if (m2->fE == m->fE && (p48 = m2->p48) != 0) {
                        m->f11 = 0;
                        m->f14 = j + 20;
                        buf = p48;
                        break;
                    }
                }
                if (buf == 0) {
                    func_0011C348(0x40);
                    buf = user_malloc(sz, 5, D_0056E230, -1);
                    sp0.fC = i;
                    m->p48 = buf;
                    _gs_scene.f5A = i + 1;
                    GetCD()->f0(id, buf, func_001B0460, &sp0);
                    return -1;
                } else {
                    m->p48 = buf;
                    func_001B0480(i);
                }
            }
        }
    }
    func_001B0528();
    _gs_scene.f10 = 0xE;
    return 0;
}

void func_001B0460(Q4Link *p) {
    func_001B0480(p->fC);
    func_001B0290();
}

void *_m2c_func_001B0480_MsGetMon() __asm__("MsGetMon");
s32 _m2c_func_001B0480_MsRegistSEdata(void *, void *, s8, void *, s32) __asm__("MsRegistSEdata");
/* DEBT(CAST) */
void func_001B0480(void) {
    s32 temp_3;
    s32 temp_8;
    s8 temp_6;
    void *temp_2;
    void *temp_7;

    temp_2 = _m2c_func_001B0480_MsGetMon();
    temp_7 = (*(void **)((u8 *)(temp_2) + (0x48)));
    temp_6 = (*(s8 *)((u8 *)(temp_2) + (0x11)));
    temp_8 = (*(s32 *)((u8 *)(temp_7) + (0)));
    (*(void **)((u8 *)(temp_2) + (0xC38))) = (void *) (temp_7 + (*(s32 *)((u8 *)(temp_7) + (4))));
    (*(u8 **)((u8 *)(temp_2) + (0xC3C))) = (u8 *) (temp_7 + (*(s32 *)((u8 *)(temp_7) + (8))));
    (*(void **)((u8 *)(temp_2) + (0xC40))) = (void *) (temp_7 + (*(s32 *)((u8 *)(temp_7) + (0xC))));
    (*(void **)((u8 *)(temp_2) + (0xC44))) = (void *) (temp_7 + (*(s32 *)((u8 *)(temp_7) + (0x1C))));
    if (temp_6 != 0) {
        temp_3 = (*(s32 *)((u8 *)(temp_7) + (0x18)));
        if ((temp_8 >= 7) && (temp_3 != 0)) {
            _m2c_func_001B0480_MsRegistSEdata(temp_2, temp_7 + temp_3, temp_6, temp_7, temp_8);
        }
    }
    (*(u8 *)((u8 *)(temp_2) + (0xAB6))) = (u8) *(*(u8 **)((u8 *)(temp_2) + (0xC3C)));
    (*(u8 *)((u8 *)(temp_2) + (0xAB5))) = (u8) D_0065FF70;
    D_0065FF70 += 1;
}

void _m2c_func_001B0528_MsCheckStatus() __asm__("MsCheckStatus");
void *_m2c_func_001B0528_MsGetMon(s32) __asm__("MsGetMon");
void _m2c_func_001B0528_MsSetFirstCTB(s8) __asm__("MsSetFirstCTB");
void _m2c_func_001B0528_MsSetRamMonData() __asm__("MsSetRamMonData");
void _m2c_func_001B0528_func_001B05F8() __asm__("func_001B05F8");
void _m2c_func_001B0528_func_002F0008(void *, s32 *, s32) __asm__("func_002F0008");
extern s32 _m2c_func_001B0528_D_0056E240 __asm__("D_0056E240");
/* DEBT(CAST) */
void func_001B0528(void) {
    u8 sp[0x10];
    s32 var_17;
    s32 var_18;
    void *temp_2;

    var_18 = 0;
    var_17 = 0;
    _m2c_func_001B0528_MsSetRamMonData();
    do {
        temp_2 = _m2c_func_001B0528_MsGetMon(var_17);
        if ((*(s32 *)((u8 *)(temp_2) + (0x48))) != 0) {
            var_18 += 1;
            _m2c_func_001B0528_func_002F0008(sp, &_m2c_func_001B0528_D_0056E240, (*(u16 *)((u8 *)(temp_2) + (0xE))) & 0x3FF);
            MsAtelRegist(1, (s32) sp, (*(s32 *)((u8 *)(temp_2) + (0xC38))));
        }
        var_17 += 1;
    } while (var_17 < 8);
    if (var_18 > 0) {
        D_003172F0.pad2108[3] = 1;
        func_001B1700(1);
    }
    _m2c_func_001B0528_func_001B05F8();
    _m2c_func_001B0528_MsSetFirstCTB((s8) D_003172F0.pad2108[4]);
    _m2c_func_001B0528_MsCheckStatus();
}

void func_001B05F8(void) {
    u8 arr[16];
    int i;

    for (i = 20; i < 28; i++) {
        BtlChr *c = MsGetChr(i);
        if (c->f10 != 0 && c->f11 != 0) {
            int count = 1;
            int j;
            for (j = i + 1; j < 28; j++) {
                if (i == MsGetChr(j)->f14) {
                    count++;
                }
            }
            if (count >= 2) {
                for (j = 0; j < count; j++) {
                    arr[j] = j * 8 + (brnd(MsGetRndChr(i, 0)) & 3);
                }
                for (j = i; j < 28; j++) {
                    BtlChr *t = MsGetChr(j);
                    if (i == t->f14) {
                        int idx = brnd(MsGetRndChr(j, 0)) % count;
                        int k;
                        count--;
                        t->padE4[0] = arr[idx];
                        for (k = idx; k < count; k++) {
                            arr[k] = arr[k + 1];
                        }
                    }
                }
            }
        }
    }
}

void func_001B07A8(Q4Link2 *p) {
    int m = p->f10;
    func_001B09F0(p->fC);
    switch (m) {
    case 0:
        func_001B0940();
        break;
    case 2:
        func_001B1598();
        break;
    }
}

int MsCDreadWeapon(int id, BtlChr *c, int mode) {
    CdMonArg sp0;

    if (c->p48 == 0) {
        int file;
        int sz;
        void *buf;

        if (id < 7) {
            int val;
            int q;
            GetCD()->f10(0x28);
            val = (u8)MsGetSaveWeapon(c->item252[0], 0)->fC;
            q = (val / 10) * 8 - 1;
            file = q + (val % 10);
        } else {
            file = id - 7;
            GetCD()->f10(0x2B);
        }
        sz = GetCD()->f14(file);
        func_0011C348(0x40);
        buf = user_malloc(sz, 5, D_0056E248, id);
        sp0.fC = id;
        c->p48 = buf;
        sp0.f10 = mode;
        GetCD()->f0(file, buf, func_001B07A8, &sp0);
        return 0;
    } else {
        func_001B09F0(id);
        return -1;
    }
}

int func_001B0940(void) {
    int i = (s8)D_003172F0.f59;
    D_003172F0.f10 = 0x12;
    for (; i < 0x12; i++) {
        BtlChr *c = MsGetChr(i);
        if (i < 0x12 && c->fA88 != 0) {
            if (MsCDreadWeapon(i, c, 0) == 0) {
                D_003172F0.f59 = i + 1;
                return -1;
            }
        }
    }
    D_003172F0.f10 = 0x13;
    return 0;
}

void func_001B09F0(int id) {
    BtlChr *c = MsGetChr(id);
    R2Hdr0 *p = c->p48;
    s8 f11 = c->f11;
    int n = p->w0;

    if (f11 != 0) {
        int off;
        if (c->f4C == 0) {
            off = p->w8;
            if (n < 3 || off == 0) {
                c->f4C = 0;
            } else {
                void *ptr = (u8 *)p + off;
                c->f4C = (s32)ptr;
                func_001CCC78(ptr, id);
            }
        }
        off = p->w4;
        if (n >= 2 && off != 0) {
            MsRegistSEdata(c, (u8 *)p + off);
        }
    }
}

void func_001B0B50(void);

void func_001B0AB0(int arg) {
    int sz;

    GetCD()->f10(0x29);
    sz = GetCD()->f14(arg);
    func_0011C348(0x40);
    D_0065FF74 = user_malloc(sz, 5, D_0056E258, -1);
    GetCD()->f0(arg, D_0065FF74, func_001B0B50, 0);
}

void func_001B0B50(void) {
    R2Hdr0 *p = D_0065FF74;
    int off = p->w4;

    if (p->w0 >= 2 && off != 0) {
        MsRegistSEdata(0, (u8 *)p + off);
    } else {
        MsBtlReadSceneFree();
    }
    func_001B0940();
}

void MsBtlReadSceneFree(void) {
    if (D_0065FF74 != 0) {
        func_0011D590(D_0065FF74, 5);
        D_0065FF74 = 0;
    }
}

void MsBtlReadPlayerModelProcess(int id) {
    MsBtlChrRegist(id, MsGetChr(id)->f04);
    MsStatusEffectCheck(id);
}

int MsGetChrEscapePos(int id, float *pos);
extern int D_0065FF78;
extern int D_0065FF7C;
extern int D_0065FF80;

void MsBtlReadPlayerProcess(int id, int mode) {
    float pos[4];
    BtlChr *c = MsGetChr(id);
    int mot;
    int f04;
    Chr *chr;

    c->f38 = 1;
    c->fABC = 0;
    c->f40 = 1.0f;
    c->f3BC = -1;
    MsEffectResetMotionDisable(c);
    f04 = c->f04;
    if (mode != 2) {
        MsBtlChrRegist(id, f04);
    }
    chr = c->chr;
    if (id < 8) {
        ((void (*)(Chr *))op_et_bindeff2)(chr);
    }
    MsActionRequest(id, 0xFF, 5, 0, 2, 0);
    mot = 0x31;
    MsSetMotion(id, 0x27, 0, 0, 1, 0, 0);
    switch (mode) {
    case 10:
        c->fB0 = 0xFF;
        mot = 0x39;
        c->fC0 = 0xFFFF;
        break;
    case 6:
        c->fDC = 1;
        c->fB0 = 0xFF;
        c->fC0 = 0xFFFF;
        mot = 0x32;
        MsGetChrEscapePos(id, pos);
        MsSetChrPosReset(id, pos);
        break;
    case 8:
        c->fB0 = 0xFF;
        mot = 0;
        msSetChrBodyHit(c, 2, 0);
        MsGetChrBtlPos(id, pos);
        MsSetChrPosReset(id, pos);
        break;
    }
    if (mode != 8) {
        MsStatusEffectCheck(id);
    }
    c->f10F = 0;
    MsSetChrWeak(id, -1);
    if (c->fA8E != 0) {
        c->f1C8 = 0;
        if (mode == 10) {
            func_001B57F0(id, 0);
        }
    } else {
        c->f1C8 = MsCheckBtlPos(id, c, c->f34);
        MsSetMotion(id, mot, 0, 0, 1, 0, 0);
    }
}

void MsBtlReadMonsterProcess(int id) {
    BtlChr *c = MsGetChr(id);
    int f04 = c->f04;
    if (c->fE != 0xFFFF && (s8)c->pad24[0] != 0) {
        int mot;
        c->f38 = 1;
        MsEffectResetMotionDisable(c);
        if ((s8)c->padA96[1] != 0) {
            switch (c->f282) {
            case 0x14:
                c->f283 = D_0065FF78;
                D_0065FF78++;
                break;
            case 0x15:
                c->f283 = D_0065FF7C;
                D_0065FF7C++;
                break;
            case 0x16:
                c->f283 = D_0065FF80;
                D_0065FF80++;
                break;
            case 0x17:
                c->f283 = 0;
                break;
            default:
                c->f283 = 1;
                break;
            }
        }
        MsBtlChrRegist(id, f04);
        MsActionRequest(id, 0xFF, 5, 0, 2, 0);
        MsSetMotion(id, 0x27, 0, 0, 1, 0, 0);
        if (c->fFD & 2) {
            c->fB0 = 0xFF;
            c->fF3 = 1;
            mot = 0x31;
        } else {
            MsSetChrTransparentVisible(id, 0.0f, 1.0f, 8, c->fE3);
            mot = 0;
        }
        MsSetMotion(id, mot, 0, 0, 1, 0, 0);
        MsStatusEffectCheck(id);
    }
}

int func_001B0FE8(void) {
    GameState *g = &D_003172F0;
    int i;

    for (i = 0; i < 31; i++) {
        if (MsGetChr(i)->fF3 != 0) {
            g->f2138 = i;
            g->f2139 = 0xD0;
            return -1;
        }
    }
    return 0;
}

int func_001B1058(void) {
    int n = 0;
    int i;
    BtlChr *c;
    Chr *chr;
    float v[3];
    for (i = 20; i < 28; i++) {
        c = MsGetChr(i);
        chr = c->chr;
        if (chr != 0) {
            MsGetChrBtlPos(i, v);
            n++;
            graphicLevelGetNameHash(chr, 0);
            Ch_SetPos3(chr, v[0], v[1], v[2]);
            if (c->fC7 == 0) {
                func_001B57F0(i, 0);
            }
        }
    }
    return n;
}

u8 MsBtlReadCueLevel(void) {
    return D_00318A41;
}

void Ch_DataRead(int id);
int Ch_DataReadSync(int id);
void ChN_ReadSystemMGRPstart(int id, int a1);
int ChN_ReadSystemMGRPsync(int id, int a1);
void ChN_ReadSystemMGRP(int id, int a1);
void MsBtlWeaponRegist(int a, int b, int c);
int MsGetSaveWeaponModel(int id);
BtlChr *MsGetWeapon(int id, int slot);
int MsBtlReadCueRegistWeapon(int id);
void MsBtlReadCueRegist(int a, int b, int c, int d, int e);

void MsBtlReadCueManage(void)
{
    int cont;

    if (D_003172F0.f1751 == 0) {
        return;
    }
    cont = 1;
    do {
        int idx = D_003172F0.f1750;
        S2Cmd *q = &S2_CMDQ[idx];
        int id = q->b1;
        BtlChr *c = MsGetChr(id);

        switch (q->b2) {
        case 0:
            switch (q->b0) {
            case 0:
                if (c->chr != 0) {
                    q->b2 = 2;
                } else {
                    Ch_DataRead(q->h6);
                    q->b2 = 1;
                }
                break;
            case 1:
                break;
            case 2:
                if (c->f11 != 0 && q->h6 != 0) {
                    ChN_ReadSystemMGRPstart(q->h6, c->f20);
                    q->b2 = 1;
                } else {
                    q->b2 = 2;
                }
                break;
            case 3:
                if (MsCDreadWeapon(id, c, 2) == 0) {
                    q->b2 = 1;
                    cont = 0;
                } else {
                    q->b2 = 2;
                }
                break;
            }
            break;
        case 1:
            switch (q->b0) {
            case 0:
                if (Ch_DataReadSync(q->h6) != 0) {
                    cont = 0;
                } else {
                    q->b2 = 2;
                }
                break;
            case 1:
                cont = 0;
                break;
            case 2:
                if (ChN_ReadSystemMGRPsync(q->h6, c->f20) != 0) {
                    cont = 0;
                } else {
                    q->b2 = 2;
                }
                break;
            case 3:
                cont = 0;
                break;
            }
            break;
        case 2:
            {
                BtlChr *c2;
                int mode;
                if (q->b0 == 2 && q->h6 != 0) {
                    ChN_ReadSystemMGRP(q->h6, c->f20);
                }
                mode = q->b3;
                c2 = MsGetChr(q->b4);
                switch (mode) {
                case 1:
                    MsBtlReadPlayerModelProcess(id);
                    break;
                case 2:
                case 6:
                case 8:
                case 10:
                    MsBtlReadPlayerProcess(id, mode);
                    break;
                case 3:
                case 7:
                    ((void (*)(int, int))MsBtlReadMonsterProcess)(id, mode);
                    break;
                case 4:
                    MsBtlWeaponRegist(q->b4, ((s8 *)c2)[0xABD], 0);
                    ((s8 *)c2)[0xABD] = 0;
                    break;
                case 5:
                    MsBtlWeaponRegist(q->b4, ((s8 *)c2)[0xABD], 1);
                    ((s8 *)c2)[0xABD] = 0;
                    break;
                case 0:
                case 9:
                    break;
                }
                D_003172F0.f1750 = (idx + 1) % 32;
                D_003172F0.f1751--;
                if (D_003172F0.f1751 == 0) {
                    cont = 0;
                }
            }
            break;
        }
    } while (cont != 0);
}

void MsBtlReadCueRegist(int a, int b, int c, int d, int e) {
    if (D_003172F0.f1751 < 0x20) {
        S2Cmd *q = &S2_CMDQ[(D_003172F0.f1750 + D_003172F0.f1751) % 32];

        q->b0 = a;
        q->b1 = b;
        q->b4 = c;
        q->h6 = d;
        q->b3 = e;
        q->b2 = 0;
        q->w8 = 0;
        D_003172F0.f1751++;
        MsBtlReadCueManage();
    }
}

int MsBtlReadCueRegistWeapon(int id) {
    u16 *p;
    u16 v;
    int r = 0;
    for (p = D_00319468; (v = *p) != 0; p++) {
        if (id == v) {
            r = 1;
            break;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B1490);

void func_001B1598(void) {
    if (D_003172F0.f1751 != 0) {
        D_003172F0.ent[D_003172F0.f1750].fA = 2;
    }
}
