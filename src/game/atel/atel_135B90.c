/* tu_062 0x135b90-0x135e88: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

void func_00135B90(int i) {
    CbEnt *e = D_0058CF48[i];
    int j;

    for (j = 15; j >= 0; j--) {
        e->fn = 0;
        e->w4 = 0;
        e->name[0] = 0;
        e++;
    }
}

void func_00135BD0(void) {
    int i;

    for (i = 0; i < 2; i++) {
        func_00135B90(i);
    }
}

void AtelRegistCallbackQue2(int i, int (*fn)(int *arg), char *name) {
    int n;

    for (n = 0; n < 15; n++) {
        if (D_0058CF48[i][n].fn == 0) {
            D_0058CF48[i][n].fn = fn;
            D_0058CF48[i][n].w4 = 0;
            func_002F0C10(D_0058CF48[i][n].name, name, 7);
            D_0058CF48[i][n].name[7] = 0;
            D_0058CF48[i][n + 1].fn = 0;
            break;
        }
    }
}

void func_00135C80(int i, int (*fn)(int *arg)) {
    AtelRegistCallbackQue2(i, fn, D_0056A510);
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 AtelExecCallbackQue(s32 i) {
    CbEnt *var_17;
    s32 (*temp_2)(s32 *);
    s32 temp_19;
    s32 var_18;
    CbEnt *var_16;
    register CbEnt *p __asm__("$2");
    register s32 fn_val __asm__("$3");

    temp_19 = i << 8;
    var_17 = D_0058CF48[i];
    temp_2 = var_17->fn;
    if (temp_2 != 0) {
        if (temp_2((s32 *)(temp_19 + ((u8 *)&D_0058CF48[0][0].w4))) != 0) {
            var_16 = (CbEnt *)(temp_19 + ((u8 *)&D_0058CF48[0][1]));
            for (var_18 = 0; var_18 < 0xF; var_18++) {
                var_17->fn = var_16->fn;
                var_17->w4 = var_16->w4;
                func_002F072C(var_17->name, var_16->name);
                var_16++;
                var_17++;
            }
            D_0058CF48[i][0xF].fn = 0;
        }
        p = D_0058CF48[i];
        __asm__("" : "+r"(p));
        fn_val = (s32)p->fn;
        __asm__("" : "+r"(fn_val));
        return fn_val == 0;
    }
    return 1;
}

int AtelCheckCallbackQue(int i) {
    return D_0058CF48[i][0].fn != 0;
}

int func_00135D70(int i) {
    if (D_0058CF48[i][0].fn != 0) {
        return D_0058CF48[i][0].w4;
    }
    return 0;
}

char *func_00135DA0(int i) {
    if (D_0058CF48[i][0].fn != 0) {
        return D_0058CF48[i][0].name;
    }
    return D_0056A518;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_00135DD0(s32 arg0) {
    register CbEnt *var_4 __asm__("$4");
    register s32 var_3 __asm__("$3");
    s32 var_5;

    var_5 = 0;
    var_4 = D_0058CF48[arg0];
    __asm__ volatile("" : "+r"(var_5));
    if (var_4->fn != 0) {
        var_3 = 0;
        var_5 = 1;
        do {
            var_3 += 1;
            if (var_3 >= 0x10) {
                break;
            }
            var_4 = (CbEnt *)((u8 *)var_4 + 0x10);
            if (var_4->fn == 0) {
                break;
            }
            var_5 += 1;
        } while (1);
    }
    return var_5;
}

void func_00135E28(s32 a)
{
    s32 remaining;

    remaining = func_00135DD0(a);
    if (remaining > 0)
    {
        do
        {
            remaining -= 1;
        } while (remaining != 0);
    }
}

int AtelIsCallbackQue(void) {
    return AtelCheckCallbackQue(0);
}
