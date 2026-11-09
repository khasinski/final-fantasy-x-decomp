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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadManage);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1AF9E8/rodata", jtbl_0056E1E0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadCueManage);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1AF9E8/rodata", jtbl_0056E270);

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
