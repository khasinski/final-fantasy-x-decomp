/* tu_366 0x2f0840-0x2f2150: medium; unk_2F0840 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0840);

int func_002F0978(const char *s1, const char *s2, u32 n)
{
    if (n == 0) {
        return 0;
    }
    while (n-- != 0 && v7_tolower(*s1) == v7_tolower(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0') {
            break;
        }
        s1++;
        s2++;
    }
    return v7_tolower(*(u8 *)s1) - v7_tolower(*(u8 *)s2);
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0A58);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0C10);

char *func_002F0DD0(char *s, int i)
{
    const char *last = 0;
    char c = i;

    while (*s) {
        if (*s == c) {
            last = s;
        }
        s++;
    }
    if (*s == c) {
        last = s;
    }
    return (char *)last;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0E20);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F0840/rodata", jtbl_005781E0);

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

double func_002F1D20(const char *s, char **end)
{
    return func_002F0E20(D_005681A4, s, end);
}

float func_002F1D50(const char *s, char **end)
{
    return (float)func_002F1D20(s, end);
}

char *func_002F1D78(char *s, const char *delim)
{
    return func_002F1DA0(s, delim, &D_005681A4->_strtok_last);
}

/* strtok_r; the gotos are those of the BSD source */
char *func_002F1DA0(char *s, const char *delim, char **lasts)
{
    char *spanp;
    int c, sc;
    char *tok;

    if (s == 0 && (s = *lasts) == 0) {
        return 0;
    }
cont:
    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
        if (c == sc) {
            goto cont;
        }
    }
    if (c == 0) {
        *lasts = 0;
        return 0;
    }
    tok = s - 1;
    for (;;) {
        c = *s++;
        spanp = (char *)delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0) {
                    s = 0;
                } else {
                    s[-1] = 0;
                }
                *lasts = s;
                return tok;
            }
        } while (sc != 0);
    }
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F1E40);

long func_002F2078(const char *s, char **end, int base)
{
    return func_002F1E40(D_005681A4, s, end, base);
}

int func_002F20B0(W11Reent *ptr, int fd)
{
    if (fd == 0) {
        return 0;
    }
    func_002ED118()->_errno = 0x58;
    return -1;
}

int func_002F20E8(int fd)
{
    return func_002F20B0(D_005681A4, fd);
}

int func_002F2110(int c)
{
    return (D_005780C9[c] & 1) ? c + 0x20 : c;
}

int func_002F2130(int c)
{
    return (D_005780C9[c] & 2) ? c - 0x20 : c;
}
