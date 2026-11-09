/* tu_190 0x1bc440-0x1bf978: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsSetSaveStartGame);

void func_001BCBA8(void) {
    int i;
    for (i = 0; i < 18; i++) {
        MsSetSavePlyJoin(i, 1);
    }
    MsSaveEncountCheck();
}

void func_001BCBE8(void) {
    int i;
    for (i = 0; i < 18; i++) {
        PartySlot *s = &D_0031EA9C[i];
        s->f04 = 99999;
        s->v1C = 99999;
        s->f08 = 9999;
        s->v20 = 9999;
        s->f0C[0] = 0xFF;
        s->f0C[1] = 0xFF;
        s->f0C[2] = 0xFF;
        s->f0C[3] = 0xFF;
        s->f0C[4] = 0xFF;
        s->f0C[5] = 0xFF;
        s->f0C[6] = 0xFF;
        s->f0C[7] = 0xFF;
    }
}

void func_001BCC50(void) {
    int i;
    for (i = 8; i < 18; i++) {
        MsSetSavePlyJoin(i, 1);
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsDebugFullCommand);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", func_001BCE30);

void func_001BCED0(void) {
    int i;
    for (i = 0; i < 0x70; i++) {
        D_003194D0.h3ECC[i] = 0x2000 + i;
        D_003194D0.b40CC[i] = 1;
    }
}

void func_001BCF10(void) {
    int i;
    for (i = 0; i < 0x70; i++) {
        D_003194D0.h3ECC[i] = 0xFF;
        D_003194D0.b40CC[i] = 0;
    }
}

void func_001BCF50(int d) {
    SaveData *s = &D_003194D0;
    int i;
    for (i = 0; i < 0x70; i++) {
        s->h3ECC[i] = 0x2000 + i;
        s->b40CC[i] = MsCheckRange(s->b40CC[i] + d, 0, 99);
    }
}

void func_001BCFD0(void) {
    int i;
    for (i = 0; i < 18; i++) {
        D_003194D0.slot[i].f3B = 0x62;
    }
}

void MsDebugFullGill(void) {
    D_0031D218 = 999999899;
}

void func_001BD028(void) {
    int i;
    if (MsGetChrTop() != 0) {
        for (i = 0; i < 0x1F; i++) {
            MsGetChr(i)->f290 = 1;
            MsSetChrWeak(i, -1);
        }
    }
}

void func_001BD088(int flag) {
    int i;
    if (MsGetChrTop() != 0) {
        for (i = 0; i < 0x12; i++) {
            BtlChr *c = MsGetChr(i);
            if (flag != 0) {
                c->f290 = 1;
            } else {
                c->f290 = c->f254;
            }
            MsSetChrWeak(i, -1);
        }
    }
}

void func_001BD108(int flag) {
    int i;
    if (MsGetChrTop() != 0) {
        for (i = 0x14; i < 0x1C; i++) {
            BtlChr *c = MsGetChr(i);
            if (flag != 0) {
                c->f290 = 1;
            } else {
                c->f290 = c->f254;
            }
            MsSetChrWeak(i, -1);
        }
    }
}

void func_001BD188(void) {
    int i;
    int j;
    PartySlot *s;
    for (i = 0; i < 7; i++) {
        s = &D_0031EA9C[i];
        for (j = 0; j < 20; j++) {
            if (s->h60[j] != 0) {
                s->h60[j] = 1;
            }
        }
    }
}

int func_001BD1E0(void) {
    return D_0031D1DC & 1;
}

void func_001BD1F0(int on) {
    D_0031D1DC = (D_0031D1DC & ~1U) | (on & 1);
}

int MsGetSaveConfigCursorSave(void) {
    return (D_0031D1DC >> 1) & 1;
}

void func_001BD230(int on) {
    D_0031D1DC = (D_0031D1DC & ~2U) | ((on & 1) << 1);
}

int func_001BD258(void) {
    return (D_0031D1DC >> 2) & 1;
}

void func_001BD270(int on) {
    D_0031D1DC = (D_0031D1DC & ~4U) | ((on & 1) << 2);
}

int MsGetSaveConfigHiragana(void) {
    return (D_0031D1DC >> 3) & 1;
}

void func_001BD2B0(int on) {
    D_0031D1DC = (D_0031D1DC & ~8U) | ((on & 1) << 3);
}

int MsGetCheckEnglish(void) {
    return (FFXGetLang() == 1) ? 0 : -1;
}

void func_001BD300(void) {
    D_003172F0.f2147 = (D_003172F0.f2147 + 1) & 1;
}

int func_001BD320(void) {
    int r = 0;
    if (MsGetCheckEnglish() != 0) {
        r = -1;
        if (D_00319437 != 0) {
            r = 0;
        }
    }
    return r;
}

int func_001BD360(void) {
    int a = FFXGetLang();
    s16 v;
    if (MsGetCheckEnglish() != 0 && a != 6) {
        v = D_0031D1DE;
        return v & 1;
    }
    return 0;
}

int MsSetSaveConfigEnglish(int a) {
    int mode = FFXGetLang();
    if (MsGetCheckEnglish() != 0 && mode != 6) {
        D_0031D1DC = (D_0031D1DC & 0xFFFEFFFF) | ((a & 1) << 16);
    } else {
        D_0031D1DC &= 0xFFFEFFFF;
    }
}

int func_001BD430(void) {
    return (D_0031D1DC >> 4) & 1;
}

void func_001BD448(int on) {
    D_0031D1DC = (D_0031D1DC & ~0x10U) | ((on & 1) << 4);
}

int MsGetSaveConfigCreditName(void) {
    return (D_0031D1DC >> 5) & 1;
}

void func_001BD488(int on) {
    D_0031D1DC = (D_0031D1DC & ~0x20U) | ((on & 1) << 5);
}

int func_001BD4B0(void) {
    return (D_0031D1DC >> 9) & 1;
}

void func_001BD4C8(int on) {
    D_0031D1DC = (D_0031D1DC & ~0x200U) | ((on & 1) << 9);
}

int func_001BD4F0(void) {
    return (D_0031D1DC >> 6) & 1;
}

void func_001BD508(int on) {
    D_0031D1DC = (D_0031D1DC & ~0x40U) | ((on & 1) << 6);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsGetSaveWindow);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1BC440/rodata", jtbl_0056E550);

Rec14 *MsGetSaveChrName(int id) {
    if (MsBtlChrNumCheck(id)) {
        return &D_0031F81C[id];
    }
    return 0;
}

int func_001BDDC8(int v) {
    return 0x14;
}

int MsGetSavePlyJoin(int id) {
    return D_0031EA9C[(u8)id].flags2C & 1;
}

int MsGetSavePlyJoined(int id) {
    return (D_0031EA9C[(u8)id].flags2C >> 4) & 1;
}

void func_001BDE20(u8 id, int on) {
    D_0031EA9C[id].flags2C = (D_0031EA9C[id].flags2C & ~0x10) | ((on & 1) << 4);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsSetSavePlyJoin);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsExchangeSaveParty);

int func_001BE1F8(u8 id) {
    return (D_0031EA9C[id].flags2C >> 1) & 1;
}

void func_001BE220(u8 id, int on) {
    D_0031EA9C[id].flags2C = (D_0031EA9C[id].flags2C & ~2) | ((on & 1) << 1);
}

int func_001BE258(u8 id) {
    return (D_0031EA9C[id].flags2C >> 2) & 1;
}

void func_001BE280(u8 id, int on) {
    D_0031EA9C[id].flags2C = (D_0031EA9C[id].flags2C & ~4) | ((on & 1) << 2);
}

void MsGetSavePartyMember(int *a, int *b, int *c) {
    if (a != 0) {
        *a = D_0031D228[0];
    }
    if (b != 0) {
        *b = D_0031D228[1];
    }
    if (c != 0) {
        *c = D_0031D228[2];
    }
}

void MsSetSavePartyMember(int a, int b, int c) {
    MsExchangeSaveParty(a, 0);
    MsExchangeSaveParty(b, 1);
    MsExchangeSaveParty(c, 2);
}

void *func_001BE338(void) {
    return &D_003194D0;
}

void func_001BE348(void) {
    int i;
    for (i = 0; i < 3; i++) {
        D_0031D228[i] = D_003192B5[i];
    }
}

void func_001BE388(void) {
    SaveData *s = &D_003194D0;
    u8 *d = s->b3D5B;
    int i;

    for (i = 0; i < 17; i++) {
        *d++ = D_003192C3[i];
    }
}

typedef struct {
    u8 pad0[0x52];
    u8 item52[2];
    u8 pad54[0x7B - 0x54];
    u8 f7B;
    u8 f7C;
    u8 f7D;
    u8 pad7E[0x90 - 0x7E];
    s32 f90;
    s32 f94;
    u8 pad98[0x198 - 0x98];
    u8 f198;
} BtlChrSub200;

void MsSetSaveData(void) {
    int i;
    PartySlot *s;

    MsReturnParty();
    func_001BE348();
    func_001BE388();
    s = D_0031EA9C;
    for (i = 0; i < 18; i++, s++) {
        BtlChrSub200 *c = (BtlChrSub200 *)((u8 *)MsGetChr(i) + 0x200);
        int cnt;
        s->f2D = c->item52[0];
        s->f2E = c->item52[1];
        cnt = c->f198;
        if (c->f90 > 0 || cnt != 0) {
            s->v1C = c->f90;
        } else {
            s->v1C = 1;
        }
        s->v20 = c->f94;
        if (cnt != 0) {
            if (--cnt <= 0) {
                cnt = 0;
                s->v1C = s->v24;
                s->v20 = s->v28;
            }
        }
        s->b3D = cnt;
        s->v1C = MsCheckRange(s->v1C, 0, s->v24);
        s->v20 = MsCheckRange(s->v20, 0, s->v28);
        s->b38 = c->f7B;
        s->b39 = c->f7C;
        s->b3A = c->f7D;
    }
    for (i = 8; i < 18; i++) {
        MsSetSaveParam(i);
    }
}

s32 MsGetSaveBattleCount(void) {
    return D_0031D1E4;
}

void *MsGetSaveAbilityMap(void) {
    return D_0031B6BC;
}

void *func_001BE510(void) {
    return D_0031C9DC;
}

s32 MsGetGIL(void) {
    return D_0031D218;
}

void MsSetGIL(s32 gil) {
    if (gil < 0) {
        gil = 0;
    }
    if (gil > 999999999) {
        gil = 999999999;
    }
    D_0031D218 = gil;
}

int MsPayGIL(int cost) {
    int r = -1;
    int left = D_003194D0.f3D48 - cost;
    if (left >= 0) {
        D_003194D0.f3D48 = left;
        r = 0;
    }
    MsSetGIL(D_003194D0.f3D48);
    return r;
}

s32 func_001BE5A0(u8 id) {
    return D_003194D0.slot[id].f14;
}

s32 func_001BE5C0(int id) {
    return D_003194D0.slot[(u8)id].f18;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsGetNextAP);

u32 func_001BE690(int a, int b) {
    u8 i = a;
    int add = MsCheckRange(b, 0, 999999999);
    u32 next;
    D_003194D0.slot[i].f14 = MsCheckRange(D_003194D0.slot[i].f14 + add, 0, 999999999);
    D_003194D0.slot[i].f18 = MsCheckRange(D_003194D0.slot[i].f18 + add, 0, 999999999);
    while (1) {
        next = MsGetNextAP(i);
        if ((u32)D_003194D0.slot[i].f18 >= next && (s32)next > 0 && D_003194D0.slot[i].f3B < 99) {
            D_003194D0.slot[i].f18 -= next;
            D_003194D0.slot[i].f3B = MsCheckRange(D_003194D0.slot[i].f3B + 1, 0, 99);
            continue;
        }
        break;
    }
    return next;
}

u8 func_001BE7B8(int id) {
    return D_003194D0.slot[(u8)id].f3B;
}

int func_001BE7D8(int a, int n) {
    u8 i = a;
    int v = D_003194D0.slot[i].f3B - n;

    if (v >= 0) {
        D_003194D0.slot[i].f3B = v;
        D_003194D0.slot[i].b3C = MsCheckRange(D_003194D0.slot[i].b3C + n, 0, 101);
        return 0;
    }
    return -1;
}

PartySlot *MsGetSavePlayerPtr(int id) {
    if ((u8)id < 0x12) {
        return &D_0031EA9C[(u8)id];
    }
    return 0;
}

void func_001BE878(void) {
    int i;
    D_003173F7 = 1;
    for (i = 0; i < 18; i++) {
        MsSetSaveParam(i);
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsSetSaveParam);

W5Bits *MsGetChrAbilityMap(int i, U2Stats *out) {
    PartySlot *p = &D_0031EA9C[i];
    W5Bits *e = func_001E0378(i);
    s32 w20 = p->f04;
    s32 w24;
    u8 b0, b1, b2, b3, b4, b5, b6, b7;

    out->w20 = w20;
    w24 = p->f08;
    out->w24 = w24;
    b0 = p->f0C[0];
    out->b[0] = b0;
    b1 = p->f0C[1];
    out->b[1] = b1;
    b2 = p->f0C[2];
    out->b[2] = b2;
    b3 = p->f0C[3];
    out->b[3] = b3;
    b4 = p->f0C[4];
    out->b[4] = b4;
    b5 = p->f0C[5];
    out->b[5] = b5;
    b6 = p->f0C[6];
    out->b[6] = b6;
    b7 = p->f0C[7];
    out->b[7] = b7;
    if (e != 0) {
        out->w20 = e->w0 * 50 + w20;
        out->w24 = w24 + e->w4 * 5;
        out->b[0] = b0 + e->b8[0];
        out->b[1] = b1 + e->b8[1];
        out->b[2] = b2 + e->b8[2];
        out->b[3] = b3 + e->b8[3];
        out->b[4] = b4 + e->b8[4];
        out->b[5] = b5 + e->b8[5];
        out->b[6] = b6 + e->b8[6];
        out->b[7] = b7 + e->b8[7];
    }
    return e;
}

u8 MsSaveEncountCheck(void) {
    int i;
    D_003172F0.f107 = 1;
    for (i = 0; i < 0x12; i++) {
        if (MsGetSavePlyJoin(i) != 0 && ((D_0031EA9C[i].h4E >> 1) & 1)) {
            D_003172F0.f107 = 0;
        }
    }
    return D_003172F0.f107;
}

void MsInitParamData(void) {
    MsStructClear(D_0031F988, 0x7C);
}

int func_001BF360(int a) {
    TblEnt *e = MsGetExcelData(a, D_00317358, 0);

    return e->flags10 & 1;
}

int func_001BF390(int a) {
    TblEnt *e = MsGetExcelData(a, D_00317358, 0);

    return (e->flags10 >> 1) & 1;
}

int MsGetSaveChrSummon(int a) {
    TblEnt *e = MsGetExcelData(a, D_00317358, 0);

    return (e->flags10 >> 2) & 1;
}

void *MsGetSaveMenu(void) {
    return &D_0031D1DC;
}

void *func_001BF400(void) {
    return D_0031D1F8;
}

void *MsGetSaveEventFlag(void) {
    return D_0031D29C;
}

void *func_001BF420(void) {
    return D_0031D31C;
}

u8 *MsGetSaveInParty(int *n) {
    if (n != 0) {
        *n = 3;
    }
    return D_0031D228;
}

u8 *MsGetSaveOutParty(int *n) {
    if (n != 0) {
        *n = 0x11;
    }
    return D_0031D22B;
}

void func_001BF470(int id, int add) {
    PartySlot *p = MsGetSavePlayerPtr(id);
    p->v1C += add;
    p->v1C = MsCheckRange(p->v1C, 0, p->v24);
}

void func_001BF4C0(int id, int add) {
    PartySlot *p = MsGetSavePlayerPtr(id);
    p->v20 += add;
    p->v20 = MsCheckRange(p->v20, 0, p->v28);
}

int MsSetSaveCommand(int id, int cmd, int on) {
    if ((cmd >> 12) == 3) {
        int i;
        int inv;
        int m;
        if (cmd < 0x3060) {
            PartySlot *p;
            cmd &= 0xFFF;
            p = &D_0031EA9C[id];
            i = cmd / 16;
            cmd &= 15;
            inv = (1 << cmd) ^ 0xFFFF;
            m = 1 << cmd;
            if (!on) {
                m = 0;
            }
            p->h3E[i] = (p->h3E[i] & inv) | m;
        } else {
            SaveData *p;
            cmd -= 0x3060;
            cmd &= 0xFFF;
            p = &D_003194D0;
            i = cmd / 16;
            cmd &= 15;
            inv = (1 << cmd) ^ 0xFFFF;
            m = 1 << cmd;
            if (!on) {
                m = 0;
            }
            p->h3D6C[i] = (p->h3D6C[i] & inv) | m;
        }
        if (MsGetChrTop() != 0) {
            MsSetRamChrAbility(id, MsGetChr(id));
        }
        return 1;
    }
    return 0;
}

int MsGetSaveCommand(int id, int cmd) {
    int r = 0;
    if ((cmd >> 12) == 3) {
        int i;
        int m;
        if (cmd < 0x3060) {
            PartySlot *p;
            cmd &= 0xFFF;
            p = &D_0031EA9C[id];
            i = cmd / 16;
            cmd &= 15;
            m = 1 << cmd;
            if (p->h3E[i] & m) {
                r = 1;
            }
        } else {
            SaveData *p;
            cmd -= 0x3060;
            cmd &= 0xFFF;
            p = &D_003194D0;
            i = cmd / 16;
            cmd &= 15;
            m = 1 << cmd;
            if (p->h3D6C[i] & m) {
                r = 1;
            }
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", MsSaveAddInfoData);

typedef struct {
    u16 a[6];
    u16 b[10];
} CmdMenuPanel;

int MsGetSaveCommandMenuPanel(int cmd) {
    int r = 0;
    if ((cmd >> 12) == 3) {
        CmdMenuPanel *p = func_001BF400();
        int i;
        int m;
        if (cmd < 0x3060) {
            cmd &= 0xFFF;
            i = cmd / 16;
            cmd &= 15;
            m = 1 << cmd;
            if (p->a[i] & m) {
                r = 1;
            }
        } else {
            cmd -= 0x3060;
            cmd &= 0xFFF;
            i = cmd / 16;
            cmd &= 15;
            m = 1 << cmd;
            if (i < 10) {
                if (p->b[i] & m) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BC440", func_001BF888);
