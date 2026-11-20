/* tu_137 0x18b680-0x18d0f8: low; unk_18B680 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/v2.h"
#include "ffx/s2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018B680);

void func_0018B7A0(void *p, s32 a, s32 b) {
    s32 var_17;
    void *var_16;

    var_16 = p + 0x70;
    for (var_17 = 0; var_17 < 0x48; var_17++) {
        func_0018C468(var_16, var_16, a, b, 0x100);
        var_16 += 0x460;
    }
}

typedef struct {
    int a[8];
} YiTbl8;

extern YiTbl8 D_0056D190;
void func_0018BC00(void *, void *, int);
void func_0018C008(void *, void *, int);
void func_0018C248(void *, void *, int);

void func_0018B810(void)
{
    YiTbl8 tbl = D_0056D190;
    u8 buf1[0x80];
    u8 buf2[0x20];
    int i;
    int j;

    func_0018BC00(buf1, &tbl, 8);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
        }
    }
    func_0018C008(buf1, &tbl, 8);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
        }
    }
    func_0018C248(buf2, buf1, 8);
    for (i = 0; i < 8; i++) {
    }
}

void func_0018B950(u8 *p)
{
    u8 unused[0x1000];
    float a[4];
    float b[4];
    u8 *q;
    int i;

    func_002EF0D0(a, 0, 0x10);
    q = p + 0x70;
    i = 0x47;
    a[0] = 1.0f;
    func_002EF0D0(b, 0, 0x10);
    {
        register volatile int *reg __asm__("$2") = (volatile int *)0x10000000;
        __asm__("" : "+r"(reg));
        b[2] = 64.0f;
        *reg = 0;
    }
    do {
        func_0018C468(q, q, a, b, 0x100);
        q += 0x460;
        i--;
    } while (i >= 0);
    *(volatile int *)0x10000000;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BA08);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BC00);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BD98);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C008);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C248);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_18B680/rodata", jtbl_0056D1B0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C468);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C6D8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C9D0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018CB90);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018CEC8);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_18B680/rodata", jtbl_0056D2A0);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_18B680/rodata", jtbl_0056D310);
