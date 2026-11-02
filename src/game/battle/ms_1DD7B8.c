/* tu_206 0x1dd7b8-0x1df1c0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"

void MsImportantInit(void) {
    D_00662E0C = 0;
    D_00662E10 = 0;
}

int MsImportantRead(void) {
    D_00662E0C = MsGetFileSize(0xD, 7, 0x18);
    if (D_00662E10 == 0) {
        func_0011C348(0x40);
        D_00662E10 = (s32)user_malloc(D_00662E0C, 5, D_0056F7D0, -1); /* DEBT(TYPE): handle/pointer kept as int */
        MsMemCheckRegist((void *)D_00662E10, D_00662E0C); /* DEBT(TYPE): handle/pointer kept as int */
    }
    GetCD()->f0(0x18, D_00662E10, 0, 0);
    return 0;
}

OfsTbl *MsImportantPtr(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, (void *)D_00662E10, pos);
}

int MsImportantName(int a) {
    s32 pos;
    u8 *t = MsGetExcelData(a & 0xFFF, (void *)D_00662E10, &pos);
    t += MsGetSaveConfigHiragana() * 4;
    return pos + *(u16 *)t;
}

int MsImportantGet(int i) {
    i &= 0xFFF;
    if (i < 0x80) {
        int w = i / 16;
        int m = 1 << (i & 0xF);
        if (D_003194D0.bits[w] & m) {
            return 1;
        }
    }
    return 0;
}

void MsImportantSet(int i)
{
    i &= 0xFFF;
    if (i < 0x80) {
        D_003194D0.bits[i / 16] |= 1 << (i & 0xF);
    }
}

void func_001DD998(int i)
{
    i &= 0xFFF;
    if (i < 0x80) {
        D_003194D0.bits[i / 16] &= ~(1 << (i & 0xF));
    }
}

int func_001DD9F0(void) {
    if (D_00662E10 != 0) {
        func_0011D590(D_00662E10, 5);
        D_00662E10 = 0;
    }
    return 0;
}

void func_001DDA30(void) {
    D_00662E14 = 0;
    D_00662E18 = 0;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void MsWeaponNameRead(void)
{
    s32 value0;

    D_00662E14 = MsGetFileSize(0xD, 7, 0x1B);
    if (D_00662E18 == 0)
    {
        func_0011C348(0x40);
        value0 = user_malloc(D_00662E14, 5, D_0056F7E0, -1);
        D_00662E18 = value0;
        MsMemCheckRegist((void *) value0, D_00662E14);
    }
    GetCD()->f0(0x1B, D_00662E18, 0, 0);
}

void MsWeaponNameFree(void) {
    if (D_00662E18 != 0) {
        func_0011D590(D_00662E18, 5);
        D_00662E18 = 0;
    }
}

int func_001DDB18(W5Rec *r, u16 key)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (r->h0E[i] == key) {
            return 1;
        }
    }
    return 0;
}

int MsWeaponNameNum(W5Rec *r)
{
    if (r->b5 == 0) {
        return func_001DDC18(r);
    }
    return func_001DE468(r);
}

int MsWeaponName(int a, int b, int alt, u16 *len) {
    s32 pos;
    u8 lang = b;
    V3TxtEnt *t = MsGetExcelData(a & 0xFFF, (void *)D_00662E18, &pos); /* DEBT(TYPE): handle/pointer kept as int */
    if (len != 0) {
        *len = t->n[lang];
    }
    if (alt != 0) {
        return pos + t->b[lang].ofs;
    }
    return pos + t->a[lang].ofs;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DD7B8", func_001DDC18);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DD7B8", func_001DE468);
