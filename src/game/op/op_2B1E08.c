/* tu_327 0x2b1e08-0x2b33f8: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: wrappers (see w10.h). */
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_002B1E08(void)
{
    func_002B1E30();
    func_002B1F88();
    func_002B37C0();
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B1E30);

void func_002B1F88(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B1F90);

void func_002B21E0(s32 a) {
    func_002B1F90(a);
}

extern u_long128 D_006F2CE0[];
extern void *D_003F395C;

void op_gs1_transfer(void)
{
    u_long128 buf[11];
    u_long128 *s = D_006F2CE0;

    buf[0] = 0x7000000A;
    buf[1] = s[1];
    buf[2] = s[2];
    buf[3] = s[3];
    buf[4] = s[4];
    buf[5] = s[5];
    buf[6] = s[6];
    buf[7] = s[7];
    buf[8] = s[8];
    buf[9] = s[9];
    buf[10] = s[10];
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, (int)buf);
    func_002DA610(0, 0);
}

void func_002B2298(void)
{
    register int seed __asm__("$3") = func_002EFD78();

    VU0_QMTC2_NI(31, seed);
    VU0_OP("vrinit R, $vf31x");
}

int func_002B22C0(int n)
{
    int i = 0;
    int v;

    for (v = 1; v < n; v <<= 1) {
        i++;
    }
    return i;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B22F8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B24F8);

void func_002B2730(s32 a) {
    func_002B24F8(0x2100, 0xD00, a, 0x31);
}

extern u64 D_006F2D00;

void func_002B2748(s32 a, s32 b)
{
    s32 v = D_006F2D00 & 0x1FF;

    if (b == 0) {
        if (v != 0) {
            v = 0xD00;
        }
    } else {
        if (v != 0) {
            v = 0;
        } else {
            v = 0xD00;
        }
    }
    func_002B24F8(v, 0xD00, a, 1);
}

void *func_002B3888(s32);
void func_002B39C0(s32);

void func_002B2788(void)
{
    u64 *p = (u64 *)func_002B3888(0x100);

    p[0] = 0x70000002UL;
    p[2] = 0x1000000000008001UL;
    p[3] = 0xEUL;
    p[4] = 0;
    p[5] = 0x3FUL;
    func_002DA610(0, 0);
    func_002DBA28(D_003F395C, (s32)p | 0x80000000);
    func_002DA610(0, 0);
    func_002B39C0(0x100);
}

s32 _m2c_func_002B2810_func_002B2D50() __asm__("func_002B2D50");
s32 _m2c_func_002B2810_func_002B2D48() __asm__("func_002B2D48");
extern s32 _m2c_func_002B2810_D_003F3824 __asm__("D_003F3824");
extern s32 _m2c_func_002B2810_D_003F3828 __asm__("D_003F3828");
extern s16 _m2c_func_002B2810_D_00551C88 __asm__("D_00551C88");
extern s32 _m2c_func_002B2810_D_006F3960 __asm__("D_006F3960");
extern s32 _m2c_func_002B2810_D_006F3A20 __asm__("D_006F3A20");
extern s32 _m2c_func_002B2810_D_00703B60 __asm__("D_00703B60");
extern s32 _m2c_func_002B2810_D_00703C60 __asm__("D_00703C60");
void func_002B2810(void) {
    s32 temp_18;

    _m2c_func_002B2810_D_003F3828 = 0;
    _m2c_func_002B2810_D_003F3824 = 0;
    func_002B2D38();
    temp_18 = *(volatile s32 *)0x10000000 & 0xFFFF;
    func_002D0940();
    func_002D09E0();
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, (s32) &_m2c_func_002B2810_D_006F3960);
    func_002DA610(0, 0);
    func_00266E08(&D_0036F1F0);
    func_002B2D40();
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, (s32) &_m2c_func_002B2810_D_00703B60);
    if (D_00703FF0.b[7] != 0) {
        func_002B29D8();
    }
    _m2c_func_002B2810_func_002B2D48();
    if (D_00703FF0.b[7] != 0) {
        func_002DA610(0, 0);
        func_002F8660(0);
        func_002DBA28(D_003F395C, (s32) &_m2c_func_002B2810_D_006F3A20);
    }
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, (s32) &_m2c_func_002B2810_D_00703C60);
    func_002DA610(0, 0);
    _m2c_func_002B2810_func_002B2D50();
    _m2c_func_002B2810_D_00551C88 = *(volatile s32 *)0x10000000 - temp_18;
}

extern s32 _m2c_func_002B29D8_D_006F3A20 __asm__("D_006F3A20");
extern u_long128 _m2c_func_002B2970_D_00703B20 __asm__("D_00703B20");
extern u_long128 _m2c_func_002B29D8_D_00703C50 __asm__("D_00703C50");
extern u_long128 _m2c_func_002B2970_D_00703D10 __asm__("D_00703D10");

void func_002B2970(void)
{
    s32 *temp_2;
    s32 *var_3;
    register s32 var_4 __asm__("$4");
    register u_long128 val __asm__("$5");
    register u_long128 *p1 __asm__("$3");
    register u_long128 end __asm__("$4");
    register u_long128 *p2 __asm__("$2");
    register u_long128 *p3 __asm__("$3");

    var_3 = &_m2c_func_002B2810_D_006F3960;
    val = 0x20000000;
    __asm__("" : "+r"(val), "+r"(var_3));
    var_4 = 0x103A;
    do {
        __asm__ volatile("");
        (*(u_long128 *)((u8 *)(var_3) + (0))) = val;
        __asm__ volatile("" : : : "memory");
        temp_2 = (s32 *)((u8 *)var_3 + 0x10);
        (*(s32 **)((u8 *)(var_3) + (8))) = var_3;
        (*(s32 **)((u8 *)(var_3) + (4))) = temp_2;
        var_4 -= 1;
        __asm__ volatile("" : "+r"(var_4));
        var_3 = temp_2;
        __asm__ volatile("");
    } while (var_4 >= 0);
    p1 = &_m2c_func_002B2970_D_00703B20;
    end = 0x70000000;
    __asm__ volatile("" : "+r"(p1), "+r"(end));
    *p1 = end;
    __asm__ volatile("" : : : "memory");
    p2 = &_m2c_func_002B29D8_D_00703C50;
    __asm__ volatile("" : "+r"(p2));
    *p2 = end;
    __asm__ volatile("" : : : "memory");
    p3 = &_m2c_func_002B2970_D_00703D10;
    __asm__ volatile("" : "+r"(p3));
    *p3 = end;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002B29D8(void) {
    s32 *temp_2;
    s32 *var_3;
    register s32 var_4 __asm__("$4");
    register u_long128 val __asm__("$5");

    var_3 = &_m2c_func_002B29D8_D_006F3A20;
    val = 0x20000000;
    __asm__("" : "+r"(val), "+r"(var_3));
    var_4 = 0x1022;
    do {
        __asm__ volatile("");
        (*(u_long128 *)((u8 *)(var_3) + (0))) = val;
        __asm__ volatile("" : : : "memory");
        temp_2 = (s32 *)((u8 *)var_3 + 0x10);
        (*(s32 **)((u8 *)(var_3) + (4))) = temp_2;
        (*(s32 **)((u8 *)(var_3) + (8))) = var_3;
        var_4 -= 1;
        __asm__ volatile("" : "+r"(var_4));
        var_3 = temp_2;
        __asm__ volatile("");
    } while (var_4 >= 0);
    _m2c_func_002B29D8_D_00703C50 = 0x70000000;
}

typedef struct OpChain10 {
    u32 tag;
    void *next;
    struct OpChain10 *last;
    u32 padC;
} OpChain10;

extern OpChain10 _chain_D_006F3A20[] __asm__("D_006F3A20");
extern OpChain10 _chain_D_00703B60[] __asm__("D_00703B60");
extern OpChain10 _chain_D_006F3B20[] __asm__("D_006F3B20");
extern OpChain10 _chain_D_006F3960[] __asm__("D_006F3960");

void func_002B2A28(OpChain10 *pkt, int qwc, int prio)
{
    register int p __asm__("$3") = prio;
    register int r_prio __asm__("$6") = prio;
    register OpChain10 *head __asm__("$2");
    register OpChain10 *last __asm__("$5");

    __asm__("" : "+r"(p), "+r"(r_prio));
    MMI_SQ_ZERO(0x0, pkt);
    pkt->tag = (qwc - 1) | 0x20000000;
    __asm__ volatile("" : : : "memory");
    if (p <= 0) {
        r_prio = 0;
    }
    p = r_prio;
    __asm__("" : "+r"(p));
    head = _chain_D_006F3A20;
    if (p >= 0x10) {
        p = 0xF;
    }
    p <<= 4;
    head = (OpChain10 *)(p + (int)head);
    __asm__("" : : "r"(p));
    last = head->last;
    last->next = pkt;
    __asm__ volatile("" : : : "memory");
    pkt->next = head + 1;
    __asm__ volatile("" : : : "memory");
    head->last = pkt;
}

void func_002B2A80(OpChain10 *pkt, int qwc, int prio)
{
    register int p __asm__("$3") = prio;
    register int r_prio __asm__("$6") = prio;
    register OpChain10 *head __asm__("$2");
    register OpChain10 *last __asm__("$5");

    __asm__("" : "+r"(p), "+r"(r_prio));
    MMI_SQ_ZERO(0x0, pkt);
    pkt->tag = (qwc - 1) | 0x20000000;
    __asm__ volatile("" : : : "memory");
    if (p <= 0) {
        r_prio = 0;
    }
    p = r_prio;
    __asm__("" : "+r"(p));
    head = _chain_D_00703B60;
    if (p >= 0xF) {
        p = 0xE;
    }
    p <<= 4;
    head = (OpChain10 *)(p + (int)head);
    __asm__("" : : "r"(p));
    last = head->last;
    last->next = pkt;
    __asm__ volatile("" : : : "memory");
    pkt->next = head + 1;
    __asm__ volatile("" : : : "memory");
    head->last = pkt;
}

void func_002B2AD8(OpChain10 *pkt, int qwc, int prio)
{
    register int p __asm__("$3") = prio;
    register int r_prio __asm__("$6") = prio;
    register OpChain10 *head __asm__("$2");
    register OpChain10 *last __asm__("$5");

    __asm__("" : "+r"(p), "+r"(r_prio));
    MMI_SQ_ZERO(0x0, pkt);
    pkt->tag = (qwc - 1) | 0x20000000;
    __asm__ volatile("" : : : "memory");
    if (p <= 0) {
        r_prio = 0;
    }
    p = r_prio;
    __asm__("" : "+r"(p));
    head = _chain_D_006F3B20;
    if (p >= 0x1000) {
        p = 0xFFF;
    }
    p <<= 4;
    head = (OpChain10 *)(p + (int)head);
    __asm__("" : : "r"(p));
    last = head->last;
    last->next = pkt;
    __asm__ volatile("" : : : "memory");
    pkt->next = head + 1;
    __asm__ volatile("" : : : "memory");
    head->last = pkt;
}

void func_002B2B30(OpChain10 *pkt, int qwc, int prio)
{
    register int p __asm__("$3") = prio;
    register int r_prio __asm__("$6") = prio;
    register OpChain10 *head __asm__("$2");
    register OpChain10 *last __asm__("$5");

    __asm__("" : "+r"(p), "+r"(r_prio));
    MMI_SQ_ZERO(0x0, pkt);
    pkt->tag = (qwc - 1) | 0x20000000;
    __asm__ volatile("" : : : "memory");
    if (p <= 0) {
        r_prio = 0;
    }
    p = r_prio;
    __asm__("" : "+r"(p));
    head = _chain_D_006F3960;
    if (p >= 0x103C) {
        p = 0x103B;
    }
    p <<= 4;
    head = (OpChain10 *)(p + (int)head);
    __asm__("" : : "r"(p));
    last = head->last;
    last->next = pkt;
    __asm__ volatile("" : : : "memory");
    pkt->next = head + 1;
    __asm__ volatile("" : : : "memory");
    head->last = pkt;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2B88);

void op_wot_triger(s32 on) {
    if (on) {
        D_00703FF7 = 1;
    } else {
        D_00703FF7 = 0;
    }
}

void func_002B2C70(s32 bank) {
    W10Callback *e;
    void (*fn)(s32, s32);
    s8 *list = &D_006F2F60[bank];
    s8 id;
    s32 i = 0;

    do {
        id = list[i];
        if (id < 0) {
            break;
        }
        e = &D_006F2FE0[bank + id];
        fn = e->fn;
        fn(e->arg0, e->arg1);
        if (e->count != 0) {
            if (--e->count == 0) {
                func_002B2E70(id, bank);
                i--;
            }
        }
        i++;
    } while (i < 0x20);
}

void func_002B2D38(void) {
    func_002B2C70(0);
}

void func_002B2D40(void) {
    func_002B2C70(0x20);
}

void func_002B2D48(void) {
    func_002B2C70(0x40);
}

void func_002B2D50(void) {
    func_002B2C70(0x60);
}

s32 func_002B2D58(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count, s32 bank)
{
    s8 *p = &D_006F2F60[bank];
    s8 *end = p + 0x20;
    W10Callback *e;
    s8 id;

    do {
        if (*p < 0) {
            goto search;
        }
        p++;
    } while ((int)p < (int)end);
    return -1;
found:
    e->fn = fn;
    e->arg0 = arg0;
    e->arg1 = arg1;
    e->count = count;
    *p = id;
    return id;
search:
    e = &D_006F2FE0[bank];
    for (id = 0; id < 0x20; id++, e++) {
        if (e->fn == 0) {
            goto found;
        }
    }
    return -1;
}

s32 func_002B2DF0(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0);
}

s32 func_002B2E10(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x20);
}

s32 func_002B2E30(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x40);
}

s32 func_002B2E50(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x60);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2E70);

void func_002B2F10(u32 id) {
    func_002B2E70(id, 0);
}

void func_002B2F18(u32 id) {
    func_002B2E70(id, 0x20);
}

void func_002B2F20(u32 id) {
    func_002B2E70(id, 0x40);
}

void func_002B2F28(u32 id) {
    func_002B2E70(id, 0x60);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2F30);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2FF0);

void func_002B3120(int a, u8 b, u8 c)
{
    op_gs1_transfer();
    func_002B2FF0(a, b, c);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B3168);
