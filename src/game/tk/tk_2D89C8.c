/* tu_345 0x2d89c8-0x2d9188: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"

void func_002D89C8(int v)
{
    D_0078BC0C = v;
}

int func_002D89D8(void)
{
    return D_0078BC0C;
}

void func_002D89E8(int i, int v)
{
    D_0078BC10[i] = v;
}

int func_002D8A00(int i)
{
    return D_0078BC10[i];
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D89C8", func_002D8A18);

int func_002D8AC8(int mode, int a, int b)
{
    int r;

    if (mode == 0) {
        do {
            r = func_002D8A18(1, a, b);
            func_002D1D68(1000000);
        } while (r == 0);
        return r;
    }
    return func_002D8A18(mode, a, b);
}

int func_002D8B40(const char *name, McTblGetDir *info, u32 flags)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002E0188(D_0078BC04, 0, name, info, flags);
}

int func_002D8BB8(int a, int b, int c)
{
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF478(a, b, c);
}

int func_002D8C10(int a, int b)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002E0360(D_0078BC04, 0, a, b);
}

int func_002D8C78(int a, int b, int c)
{
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF700(a, b, c);
}

int func_002D8CD0(int a, int b, int c)
{
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF5E0(a, b, c);
}

int func_002D8D28(int a, int b)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF250(D_0078BC04, 0, a, b);
}

int func_002D8D90(int a)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF388(D_0078BC04, 0, a);
}

int func_002D8DE8(int a)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002E0590(D_0078BC04, 0, a);
}

int func_002D8E40(const char *name, int flags, int maxent, McTblGetDir *table)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DFBB0(D_0078BC04, 0, name, flags, maxent, table);
}

int func_002D8EC8(void)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DFEE0(D_0078BC04, 0);
}

int func_002D8F10(int a)
{
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002E00D0(a);
}

int func_002D8F48(int a)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DFFA8(D_0078BC04, 0, a);
}

int func_002D8FA0(int a)
{
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DF3C0(a);
}

int func_002D8FD8(int a)
{
    D_0078BC08 = D_0078BC04;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DFD90(D_0078BC04, 0, a, 0);
}

void func_002D9030(int v)
{
    D_0078BC04 = v;
}

int func_002D9040(void)
{
    return D_0078BC04;
}

int func_002D9050(int port, u32 *type, u32 *free, u32 *format)
{
    D_0078BC08 = port;
    if (TkGetTGS() != 0) {
        return 0;
    }
    return func_002DFA28(port, 0, type, free, format);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D89C8", func_002D90C0);

void func_002D9118(void)
{
    func_002D9030(0);
    D_0078BC00 = 0;
    func_002D89C8(0);
}

void TkInitMc(void)
{
    if (TkGetTGS() == 0) {
        func_002DEEF0();
        func_002D9118();
        func_002EF240(D_00576350);
    }
}
