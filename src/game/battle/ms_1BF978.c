/* tu_191 0x1bf978-0x1c0720: low; ~Ms (config/tu_map.tsv) */
#define GameState _hdr_GameState
#define D_003172F0 _hdr_D_003172F0
#define D_0031D96C _hdr_D_0031D96C
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"
#undef GameState
#undef D_003172F0
#undef D_0031D96C

typedef struct GameState {
    u8 pad0[0x1C56];
    u16 h1C56[0xC8];
    u16 h1DE6[0x70];
    u16 h1EC6[0x70];
    u8 pad1FA6[0x2078 - 0x1FA6];
    u16 h2078;
} GameState;

extern GameState D_003172F0;
extern Unk1BFED8 D_0031D96C[200];
extern u16 D_00318F46[];

int MsSetSaveCommandUse(int id, int cmd, int on) {
    if ((cmd >> 12) == 3 && id < 18) {
        int i;
        Q4Bits2C *p;
        int inv;
        int m;
        cmd &= 0xFFF;
        i = cmd / 16;
        p = &D_0031F504[id];
        cmd &= 15;
        inv = (1 << cmd) ^ 0xFFFF;
        m = 1 << cmd;
        if (!on) {
            m = 0;
        }
        p->bits[i] = (p->bits[i] & inv) | m;
    }
    return 0;
}

int MsGetSaveCommandUse(int id, int cmd) {
    int r = 0;

    if ((cmd >> 12) == 3 && id < 18) {
        int i;
        Q4Bits2C *p;
        int m;
        cmd &= 0xFFF;
        i = cmd / 16;
        p = &D_0031F504[id];
        cmd &= 15;
        m = 1 << cmd;
        if (p->bits[i] & m) {
            r = 1;
        }
    }
    return r;
}

u32 MsAddLoveParam(int i, u32 add) {
    u32 v = 0;

    if ((u32)(i - 1) < 7) {
        v = D_003194D0.w2C[i];
        v += add;
        if (v < 0xFFFFFFF) {
            D_003194D0.w2C[i] = v;
        }
    }
    return v;
}

u8 *MsSaveItemTypeBuffer(int *n) {
    if (n != 0) {
        *n = 0x70;
    }
    return D_0031D39C;
}

void MsSetItemCheck(int n, u16 *bits) {
    int mask;
    n &= 0xFFF;
    mask = 1 << (n & 15);
    bits[n / 16] |= mask;
}

u8 *MsSaveItemNumBuffer(int *n) {
    if (n != 0) {
        *n = 0x70;
    }
    return D_0031D59C;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BF978", MsSaveItemUse);

void MsSetItemWindow(void) {
    int n;
    u16 *list = (u16 *)MsSaveItemTypeBuffer(&n); /* DEBT(CAST): the table holds u16 ids */
    int a = 0;
    int b = 0;
    int i;
    int k;
    u32 f;

    for (i = 0; i < n; i++) {
        k = list[i];
        if (k == 0xFF) {
            continue;
        }
        f = MsGetRomItem(k, 0)->flags;
        if ((f >> 1) & 1) {
            if ((f >> 10) & 1) {
                D_003172F0.h1EC6[a++] = k;
            } else {
                D_003172F0.h1DE6[b++] = k;
            }
        }
    }
    for (; a < 0x70; a++) {
        D_003172F0.h1EC6[a] = 0xFF;
    }
    for (; b < 0x70; b++) {
        D_003172F0.h1DE6[b] = 0xFF;
    }
}

int func_001BFE30(int id) {
    int r = 0;
    int i;
    for (i = 0; i < 0x70; i++) {
        if (id == D_003194D0.h3ECC[i] && D_003194D0.b40CC[i] != 0) {
            r = D_003194D0.b40CC[i];
            if (id == D_003172F0.h2078) {
                r--;
            }
            if (r < 0) {
                r = 0;
            }
            break;
        }
    }
    return r;
}

void func_001BFEA8(s16 v) {
    D_00319368 = v;
}

void *func_001BFEB8(void) {
    return D_0031D69C;
}

void *func_001BFEC8(void) {
    return D_0031D6BC;
}

Unk1BFED8 *MsGetSaveWeapon(int id, s32 *name_out) {
    Unk1BFED8 *p;
    int raw;
    if (id == 0xFF) {
        return 0;
    }
    raw = id;
    id &= 0xFFF;
    switch (raw >> 12) {
    case 7:
        if ((u32)id >= 8) {
            id = 0;
        }
        p = &D_0031FCEE[id];
        break;
    case 0xB:
        if ((u32)id >= 8) {
            id = 0;
        }
        p = &D_0031FE9E[id];
        break;
    default:
        if ((u32)id >= 200) {
            id = 0;
        }
        p = &D_0031D96C[id];
        break;
    }
    if (name_out != 0) {
        *name_out = func_001C0040(raw);
    }
    return p;
}

void MsEquipSaveWeapon(int arg, int which, int id) {
    u8 slot = arg;
    PartySlot *p = &D_0031EA9C[slot];
    u8 old;
    id &= 0xFFF;
    if (which == 0) old = p->f2D; else old = p->f2E;
    if (old != 0xFF) MsGetSaveWeapon(old, 0)->b6 = 0xFF;
    if (id != 0xFF) MsGetSaveWeapon(id, 0)->b6 = slot;
    if (which == 0) p->f2D = id; else p->f2E = id;
}

int func_001C0040(int a) {
    int k = MsGetSaveConfigHiragana();
    Unk1BFED8 *p = MsGetSaveWeapon(a, 0);
    if (p != 0) {
        return MsWeaponName(p->h0, p->b4, k, 0);
    }
    return 0;
}

int MsGetSaveChrWeaponModel(int id) {
    Unk1BFED8 *p = MsGetSaveWeapon(D_0031EA9C[id].f2D, 0);
    if (p != 0) {
        return p->fC;
    }
    return 0;
}

int MsGetSaveChrArmorModel(int id) {
    Unk1BFED8 *p = MsGetSaveWeapon(D_0031EA9C[id].f2E, 0);
    if (p != 0) {
        return p->fC;
    }
    return 0;
}

int MsGetSaveWeaponModel(int id) {
    Unk1BFED8 *p;
    if (id != 0xFF) {
        p = MsGetSaveWeapon(id, 0);
        if (p != 0) {
            return p->fC;
        }
    }
    return 0;
}

int MsGetSaveWeaponAmount(int *out) {
    SaveData *s = &D_003194D0;
    u8 *p = &s->flag2[3]; /* DEBT(CAST): 200 records of 0x16 bytes at flag2+2; p points at the 2nd byte of a record */
    int used = 0;
    int n = 0;
    int i;
    for (i = 0; i < 200; i++, p += 0x16) {
        if (p[-1] != 0) {
            used++;
            if (((p[0] >> 1) & 1) == 0) {
                n++;
            }
        }
    }
    if (out != 0) {
        *out = 200 - used;
    }
    return n;
}

typedef struct SaveData1C01B8 {
    u8 pad0[0x449C];
    Unk1BFED8 wep[200];
    PartySlot slot[18];
} SaveData1C01B8;

void MsInitSaveWeaponEquipFlag(void) {
    int i;
    for (i = 0; i < 200; i++) {
        ((SaveData1C01B8 *)&D_003194D0)->wep[i].b6 = 0xFF;
    }
    for (i = 0; i < 18; i++) {
        SaveData1C01B8 *s = (SaveData1C01B8 *)&D_003194D0;
        if (s->slot[i].f2D != 0xFF) {
            s->wep[s->slot[i].f2D].b6 = i;
        }
        if (s->slot[i].f2E != 0xFF) {
            s->wep[s->slot[i].f2E].b6 = i;
        }
    }
}

u16 *MsGetSaveWeaponList(int chr, int kind, int unequipped, int *out) {
    Unk1BFED8 *p = D_0031D96C;
    int n = 0;
    int i;
    for (i = 0; i < 200; i++, p++) {
        int ok = 1;
        if (p->b2 != 0) {
            if (((p->b3 >> 1) & 1) && chr < 8) {
                continue;
            }
            if (p->b4 != chr && chr >= 0) {
                ok = 0;
            }
            if (unequipped != 0 && p->b6 != 0xFF) {
                ok = 0;
            }
            if (kind == 0 && p->b5 != 0) {
                ok = 0;
            }
            if (kind == 1 && p->b5 != 1) {
                ok = 0;
            }
        }
        if (ok != 0) {
            D_003172F0.h1C56[n++] = 0x5000 + i;
        }
    }
    if (out != 0) {
        *out = n;
    }
    return D_00318F46;
}

int func_001C0318(int id) {
    Unk1BFED8 *e;
    if (id != 0xFF) {
        e = MsGetSaveWeapon(id, 0);
        if (e->b2 != 0) {
            e->b2 = 0;
            if ((id >> 12) != 7) {
                int i;
                id &= 0xFFF;
                for (i = 0; i < 18; i++) {
                    if (D_003194D0.slot[i].f2D == id) D_003194D0.slot[i].f2D = 0xFF;
                    if (D_003194D0.slot[i].f2E == id) D_003194D0.slot[i].f2E = 0xFF;
                }
            }
            return 0;
        }
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BF978", func_001C03B0);

int func_001C0598(Unk1BFED8 *src) {
    Unk1BFED8 *p = D_0031D96C;
    int i;
    for (i = 0; i < 200; i++, p++) {
        if (p->b2 == 0) {
            *p = *src;
            p->b2 = 1;
            p->b6 = 0xFF;
            return 0x5000 + i;
        }
    }
    return 0;
}

int func_001C0618(int a, int b) {
    int i = 0;
    while (func_001C0680(a, i + 1) <= b) {
        i++;
    }
    return i;
}

int func_001C0680(int a, int x) {
    TblEnt *e = MsGetExcelData(a, D_00317358, 0);
    int sq = x * x;
    return (x * e->f11 + e->f12) * sq - e->f13;
}

int func_001C06D0(int a) {
    MsGetExcelData(a, D_00317358, 0);
    return 100;
}

int func_001C06F8(int a) {
    MsGetExcelData(a, D_00317358, 0);
    return 100;
}
