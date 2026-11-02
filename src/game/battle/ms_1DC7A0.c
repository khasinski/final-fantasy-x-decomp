/* tu_205 0x1dc7a0-0x1dd7b8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/r5.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DC7A0", MsBtlGetTerm);

void func_001DC968(int id, int n, R5Buf *s) {
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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DC7A0", MsGetItem);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DC7A0", func_001DD2D0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DC7A0", func_001DD5F8);
