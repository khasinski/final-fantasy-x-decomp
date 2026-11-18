/* tu_182 0x1b3388-0x1b4100: medium; ~Ms (config/tu_map.tsv) */
#define func_001B34B8 _hdr_func_001B34B8
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#undef func_001B34B8

void func_001B3388(void) {
    GsTbl *t = D_003172F0.pF4;

    D_003172F0.h100 = (u32)(t->off8 - t->off4) / sizeof(GsEnt14);
    D_003172F0.pF8 = (GsEnt14 *)((u8 *)t + t->off4);
    D_003172F0.pFC = (u8 *)t + t->off8;
}

Unk33D0 *MsBtlListField(int i) {
    if (i < 0 || i >= D_003172F0.h100) {
        i = 0;
    }
    return (Unk33D0 *)(D_003172F0.pF8 + i); /* DEBT(CAST): the record is viewed as Unk33D0 by its caller */
}

int MsBtlListEncount(void) {
    return D_003173EC + ((Unk33D0 *(*)(void))MsBtlListField)()->f2; /* DEBT(CAST): the original caller passes no index */
}

u8 *func_001B3448(int a, int n) {
    u8 *p = (u8 *)MsBtlListEncount(); /* DEBT(CAST): returns a record pointer as int */
    int i;
    int len;

    if (n < 0 || n >= p[1]) {
        n = 0;
    }
    p += 2;
    for (i = 0; i < n; i++) {
        len = p[0];
        p += 5;
        p += len * 2;
    }
    return p;
}

void *_m2c_func_001B34B8_MsBtlListEncount(s32) __asm__("MsBtlListEncount");
void *_m2c_func_001B34B8_MsBtlListField() __asm__("MsBtlListField");
u8 *_m2c_func_001B34B8_func_001B3448(s32, s32) __asm__("func_001B3448");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_001B34B8(s32 arg0, s32 *arg1, s32 *arg2) {
    register s32 _cond __asm__("$2");
    register s32 var_16 __asm__("$16");
    register s32 var_17 __asm__("$17");
    s32 var_3;
    s32 var_3_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    register void * temp_21 __asm__("$21");
    void *temp_2;

    temp_21 = _m2c_func_001B34B8_MsBtlListField(arg0);
    temp_2 = _m2c_func_001B34B8_MsBtlListEncount(arg0);
    var_3_2 = *arg1;
    if ((var_3_2 < 0) || (var_16 = 0, ((var_3_2 < (s32) (*(u8 *)((u8 *)(temp_2) + (1)))) == 0))) {
        *arg1 = 0;
        var_3_2 = 0;
        var_16 = 0;
    }
    var_17 = 0;
    if (var_3_2 > 0) {
        do {
            temp_2_2 = _m2c_func_001B34B8_func_001B3448(arg0, var_16);
            var_16 += 1;
            var_17 += *temp_2_2;
        } while ((_cond = (var_16 < *arg1)) != 0);
    }
    temp_2_3 = _m2c_func_001B34B8_func_001B3448(arg0, *arg1);
    var_3 = *arg2;
    if ((var_3 < 0) || (var_3 >= (s32) *temp_2_3)) {
        *arg2 = 0;
        var_3 = 0;
    }
    return (*(s16 *)((u8 *)(temp_21) + (4))) + var_17 + var_3;
}

int MsBtlListFieldNum(int id) {
    int r = -1;
    int i;
    for (i = 0; i < D_003172F0.h100; i++) {
        if (D_003172F0.pF8[i].h0 == id && id > 0) {
            r = i;
            break;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", MsBtlGetPos);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1B3388/rodata", jtbl_0056E300);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", func_001B38E8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", func_001B39A8);

void func_001B3A80(void) {
    s8 *p;
    int r;
    func_001B38E8(3);
    p = D_003173D0;
    if (p[9] > 0) {
        r = func_001ACEA0() % p[9];
    }
}

s8 func_001B3AD0(void) {
    return D_003173D0[1];
}

void MsPushBtlPosAll(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsPushBtlPos(MsGetChr(i));
    }
}

void MsPushBtlPos(BtlChr *chr) {
    chr->f1C9.a = chr->f1BC.a;
    chr->f1C9.b = chr->f1BC.b;
    chr->f1C9.c = chr->f1BC.c;
}

void func_001B3B40(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsPopBtlPos(MsGetChr(i));
    }
}

void MsPopBtlPos(BtlChr *chr) {
    chr->f1BC.a = chr->f1C9.a;
    chr->f1BC.b = chr->f1C9.b;
    chr->f1BC.c = chr->f1C9.c;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", MsGetSummonerPos);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1B3388/rodata", jtbl_0056E340);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", MsSetChrPosAfterSummon);
