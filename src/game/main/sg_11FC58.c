/* tu_037 0x11fc58-0x1201b0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"

typedef struct {
    u64 dispfb1;
    u64 pad08;
    u64 display1;
    u64 dispfb2;
} GsDispEnv;

void func_0011FC58(GsDispEnv *env)
{
    u64 dispfb2 = env->dispfb2;
    u64 dispfb1 = env->dispfb1;

    if (D_00580B24 != 0) {
        dispfb1 |= (D_00580B20 << 8) | 0x21;
        *(volatile u64 *)0x12000000 = dispfb1;
        *(volatile u64 *)0x12000070 = env->display1;
        *(volatile u64 *)0x12000090 = env->display1;
        *(volatile u64 *)0x120000A0 = dispfb2;
        dispfb2 -= (D_00580B1C << 12) | D_00580B18;
        *(volatile u64 *)0x12000080 = dispfb2;
    }
}

void func_0011FCE8(void)
{
    D_00580B24 = ((u8)D_00580B24 + 1) & 1;
}

s8 func_0011FD00(s32 v)
{
    s8 old = D_00580B24;

    D_00580B24 = v & 1;
    return old;
}

int Sg_SetTkAntiXYB(int a, int b, int c)
{
    D_00580B18 = a;
    D_00580B1C = b;
    D_00580B20 = c;
}

int func_0011FD38(int *a, int *b, int *c)
{
    if (a != 0) {
        *a = D_00580B18;
    }
    if (b != 0) {
        *b = D_00580B1C;
    }
    if (c != 0) {
        *c = D_00580B20;
    }
}

u16 func_0011FD70(u16 c)
{
    int hi = c >> 8;
    int lo = c & 0xFF;

    if (hi < 0xF0 && (D_00307FF9[hi] & 4) && (D_00307FF9[lo] & 8)) {
        if (hi >= 0xE0) {
            hi -= 0x40;
        }
        hi -= 0x70;
        hi <<= 1;
        if (lo < 0x9F) {
            lo -= 0x1F;
            hi--;
            if (lo >= 0x61) {
                lo--;
            }
        } else {
            lo -= 0x7E;
        }
        return (hi << 8) | lo;
    }
    return 0;
}

void func_0011FE00(s32 a0, s32 a1)
{
    u8 *d = (u8 *)a1;
    u8 *s = (u8 *)a0;

    while (*s != 0) {
        u8 b = *s;
        u8 f = D_00307FF9[b];

        if (!(f & 3)) {
            if (!(f & 4) || !(D_00307FF9[s[1]] & 8)) {
                *d = b;
                s++;
            } else {
                u16 c = s[1] | (b << 8);
                s += 2;
                c = func_0011FD70(c) + 0x8080;
                *d++ = c >> 8;
                *d = c;
            }
        } else {
            *d = 0x20;
        }
        d++;
    }
    *d = 0;
}

void func_0011FEC8(s32 a, s32 b)
{
    func_0011FE00(a, b);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11FC58", Sg_Assert);

void func_00120080(int a, int b, int c, int d, char *fmt, int f, ...)
{
    char buf[0x400];
    va_list ap;

    ap = (char *)__builtin_next_arg(f) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_002F46B0(buf, fmt, ap);
    va_end(ap);
    Sg_Assert(a, b, c, d, buf, f);
}

void func_00120108(char *fmt, ...)
{
    char buf[0x400];
    va_list ap;

    va_start(ap, fmt);
    func_002F46B0(buf, fmt, ap);
    va_end(ap);
    func_002EF240(buf);
}

void func_00120150(char *fmt, ...)
{
    char buf[0x400];
    char out[0x400];
    va_list ap;

    va_start(ap, fmt);
    func_002F46B0(buf, fmt, ap);
    va_end(ap);
    func_0011FE00((s32)buf, (s32)out); /* DEBT(TYPE): q0.h declares two ints */
    func_002EF240(out);
}
