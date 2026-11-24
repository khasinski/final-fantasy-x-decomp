/* tu_205 0x1dc7a0-0x1dd7b8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/r5.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))

int func_001DC7A0(void)
{
    return func_001CE050();
}

int func_001DC7C0(int v)
{
    return MsEffectCheckMotion(v);
}

void MsBtlGetInit(void) {
    func_001DC7F0(&btlgetdata, 7);
}

void func_001DC7F0(W5Buf *b, int n)
{
    int i;

    MsStructClear(b, 0x1B0);
    for (i = 0; i < 8; i++) {
        b->h[i] = (n << 12) + i;
    }
}

void func_001DC850(void)
{
    int i;

    for (i = 0; i < 18; i++) {
        btlgetdata.cur[i] = btlgetdata.next[i];
    }
}

typedef struct W5BufTerm {
    s8 b0[18];
    s8 b12[18];
    s8 b24[18];
    u8 pad36[2];
    s32 cur[18];
    s32 next[18];
    s32 wC8;
} W5BufTerm;

extern W5BufTerm _btlgetdata_term __asm__("btlgetdata");

void MsBtlGetTerm(void) {
    int i;
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        if (_btlgetdata_term.b24[i] == 0 || c->fA8C != 0 || c->fA8E != 0) {
            _btlgetdata_term.next[i] = _btlgetdata_term.cur[i];
        }
        if (_btlgetdata_term.b0[i] != 0) {
            MsSaveAddInfoData(i, 0);
        }
    }
    for (i = 0; i < 8; i++) {
    }
    _btlgetdata_term.wC8 = 0;
}

void func_001DC968(int id, int n, W5Buf *s) {
    if (id != 0 && n > 0) {
        int cnt = s->bD0;
        int i;
        for (i = 0; i < cnt; i++) {
            if (id == s->hD4[i]) {
                s->bE4[i] = MsCheckRange(s->bE4[i] + n, 0, 99);
                return;
            }
        }
        if (cnt < 8) {
            s->hD4[cnt] = id;
            s->bE4[cnt] = MsCheckRange(n, 0, 99);
            s->bD0++;
        }
    }
}

int func_001DCA38(BtlChr *c) {
    int n = (s8)c->fD2;
    if (n < 8) {
        MsStructClear((u8 *)c + (n * 0x16 + 0xFE), 0x16);
        c->fD2++;
        return n;
    }
    return -1;
}

int func_001DCAA0(int id)
{
    if (id != 0) {
        OfsTbl *e = MsGetExcelData(id & 0xFFF, D_00317364, 0);

        return e->f69;
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DC7A0", func_001DCAD8);

void MsSetWeaponName(W5Rec *r)
{
    r->h0 = MsWeaponNameNum(r);
    MsWeaponName(r->h0, r->b4, 0, &r->h0C);
}

int MsApUp(int idx, BtlChr *c, int v, int r) {
    if (c->fA8D == 0) {
        int add = 0;
        if (!((c->f37E >> 6) & 1)) add = v;
        if (c->fA88 != 0 && c->fA8C == 0) {
            if ((c->f37E >> 14) & 1) r = 2;
            if ((c->f37E >> 5) & 1) {
                add *= 3;
            } else {
                add <<= (c->f37E >> 4) & 1;
            }
        }
        btlgetdata.next[idx] = MsCheckRange(btlgetdata.next[idx] + add, 0, 999999999);
    }
    return r;
}

float sqrtf(float x);

typedef struct {
    u8 pad0[0x3A];
    s8 f3A;
    u8 pad3B[6];
    s8 f41;
    s8 f42;
    s8 f43;
} ItemGS;

typedef struct {
    u8 pad0[0xCC];
    s32 fCC;
} W5BufGil;

typedef struct {
    u16 gil;
    u16 ap;
    u16 ap_ok;
    u8 pad6[2];
    u8 rate[2];
    u8 padA;
    u8 wep_rate;
    u16 item[4];
    u8 cnt[4];
    u16 item_ok[4];
    u8 cnt_ok[4];
    u8 pad24[6];
    u16 bribe_item;
    u8 bribe_cnt;
} MonDropData;

void MsGetItem(int a0, BtlChr *a1, MonDropData *a2, int a3, int a4) {
    u16 *item_id;
    u8 *item_cnt;
    int ap;
    int gil;
    int r;
    int i;

    if (a2 != 0) {
        if (a3 != 0) {
            ap = a2->ap_ok;
            item_id = a2->item_ok;
            item_cnt = a2->cnt_ok;
        } else {
            ap = a2->ap;
            item_id = a2->item;
            item_cnt = a2->cnt;
        }
        if (((ItemGS *)&D_003172F0)->f42 != 0) {
            ap *= 100;
        }
        gil = a2->gil;
        r = 1;
        if (((ItemGS *)&D_003172F0)->f43 != 0) {
            gil *= 100;
        }
        for (i = 0; i < 18; i++) {
            r = MsApUp(i, MsGetChr(i), ap, r);
        }
        if (((u8 *)a1)[0x3C1] == 2) {
            int r1 = brnd(MsGetRndChr(a0, 0));
            int r2 = brnd(MsGetRndChr(a0, 0));
            int cnt = MsCheckRange((int)((a2->bribe_cnt * sqrtf((float)*(s32 *)((u8 *)a1 + 0x3C8)) * 0.0625f * ((r1 % 11) + 20)) / 25.0f + (r2 & 1)), 1, 99);
            func_001DC968(a2->bribe_item, cnt, &btlgetdata);
        } else {
            W5BufGil *bg = (W5BufGil *)&btlgetdata;
            bg->fCC = MsCheckRange(bg->fCC + gil * r, 0, 999999999);
            for (i = 0; i < 2; i++) {
                if (brnd(10) % 255 < a2->rate[i] || (((ItemGS *)&D_003172F0)->f3A != 0 && a2->rate[i] != 0)) {
                    int rare;
                    int idx;
                    u16 id;
                    int cnt;
                    if ((brnd(11) & 0xFF) < 0x20 || ((ItemGS *)&D_003172F0)->f41 != 0) {
                        rare = 1;
                    } else {
                        rare = 0;
                    }
                    idx = i * 2 + rare;
                    id = item_id[idx];
                    cnt = item_cnt[idx];
                    if ((a4 >> 1) & 1) {
                        id = 0x2046;
                    } else if ((a4 >> 2) & 1) {
                        id = 0x2047;
                    } else if ((a4 >> 3) & 1) {
                        id = 0x2048;
                    } else if ((a4 >> 4) & 1) {
                    } else if ((a4 >> 5) & 1) {
                        id = 0x2049;
                    }
                    func_001DC968(id, cnt, &btlgetdata);
                }
            }
        }
        if (brnd(10) % 255 < a2->wep_rate || (((ItemGS *)&D_003172F0)->f3A != 0 && a2->wep_rate != 0)) {
            func_001DCAD8(a0, (u8 *)a2, &btlgetdata);
        }
    }
}

s32 func_001DD2D0(s32 arg0, s32 arg1, s32 arg2) {
    W5Ent16 *var_16;
    s32 temp_2;
    s32 var_5;

    var_16 = NULL;
    if (arg0 != 0) {
        temp_2 = func_001DCA38(&btlgetdata);
        if (temp_2 >= 0) {
            var_16 = (void *)((temp_2 * 0x16) + btlgetdata.padFE);
        }
    } else {
        for (var_5 = 0; var_5 < 0xC8; var_5++) {
            W5Ent16 *temp_2_2 = &D_0031D96C[var_5];
            if (temp_2_2->b2 == 0) {
                var_16 = temp_2_2;
                break;
            }
        }
    }
    if (var_16 != NULL) {
        M2C_FIELD(var_16, s16 *, 0) = arg2;
        var_16->b2 = 1;
        var_16->b3 = 0;
        var_16->b4 = arg1;
        var_16->b5 = 0;
        var_16->pad6[0] = 0xFF;
        var_16->pad6[2] = 1;
        var_16->pad6[3] = 1;
        var_16->pad6[4] = 0;
        var_16->pad6[5] = 1;
        for (var_5 = 0; var_5 < 4; var_5++) {
            ((s16 *)&var_16->pad6[8])[var_5] = 0xFF;
        }
        return 0;
    }
    return -1;
}

void MsFieldItemRead(void) {
    GetCD()->f10(0xD);
    D_00662DFC = GetCD()->f14(0x19);
    func_0011C348(0x40);
    D_00662E00 = (s32)user_malloc(D_00662DFC, 5, D_0056F7B8, -1);
    MsMemCheckRegist((void *)D_00662E00, D_00662DFC);
    GetCD()->f0(0x19, D_00662E00, 0, 0);
    D_00662E04 = GetCD()->f14(0x1A);
    func_0011C348(0x40);
    D_00662E08 = (s32)user_malloc(D_00662E04, 5, D_0056F7C0, -1);
    MsMemCheckRegist((void *)D_00662E08, D_00662E04);
    GetCD()->f0(0x1A, D_00662E08, 0, 0);
}

void func_001DD520(void) {
    if (D_00662E00 != 0) {
        func_0011D590(D_00662E00, 5);
        D_00662E00 = 0;
    }
    if (D_00662E08 != 0) {
        func_0011D590(D_00662E08, 5);
        D_00662E08 = 0;
    }
}

W5Buf *func_001DD578(int a)
{
    func_001DD5F8(a, &btlgetdata);
    return &btlgetdata;
}

W5Buf *MsFieldItemGetMes(int a)
{
    func_001DC7F0(&btlgetdata_mes, 0xB);
    func_001DD5F8(a, &btlgetdata_mes);
    return &btlgetdata_mes;
}

void func_001DD5F8(int idx, W5Buf *buf)
{
    u8 *ent;
    int slot;

    ent = (u8 *)MsGetExcelData(idx, (void *)D_00662E00, 0); /* DEBT(CAST): table ptr as s32 */
    switch (ent[0]) {
    case 2:
        func_001DC968(*(u16 *)(ent + 2), ent[1], buf);
        break;
    case 10:
        ((u8 *)buf)[0xD1] = 1; /* DEBT(CAST): untyped W5Buf fields */
        *(u16 *)((u8 *)buf + 0xEC) = *(u16 *)(ent + 2);
        break;
    case 5:
        slot = func_001DCA38(buf);
        if (slot >= 0) {
            u8 *wrom = (u8 *)MsGetExcelData(*(u16 *)(ent + 2), (void *)D_00662E08, 0);
            Unk1BFED8 *w = (Unk1BFED8 *)((u8 *)buf + 0xFE + slot * 0x16);
            int slots;
            int n;
            int i;

            w->b2 = 1;
            w->b3 = wrom[0];
            w->b4 = wrom[1];
            w->b5 = wrom[2];
            w->b6 = 0xFF;
            w->pad7[1] = wrom[4];
            w->pad7[2] = wrom[5];
            w->pad7[3] = wrom[6];
            slots = wrom[7];
            n = 0;
            for (i = 0; i < 4; i++) {
                int ab = ((u16 *)(wrom + 8))[i];
                if (ab == 0) {
                    ab = 0xFF;
                }
                w->fE[i] = ab;
                if (ab != 0xFF) {
                    n++;
                }
            }
            if (slots < n) {
                slots = n;
            }
            w->pad7[4] = slots;
            w->h0 = MsWeaponNameNum(w);
            MsWeaponName(w->h0, w->b4, 0, &w->fC);
        }
        break;
    default:
        *(s32 *)((u8 *)buf + 0xCC) += ent[1] * 100;
        break;
    }
}
