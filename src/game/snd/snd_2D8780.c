/* tu_344 0x2d8780-0x2d89c8: low; ~Sqs (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"

void func_002D8780(int a)
{
    D_0078BBA2 = a;
    func_00251B08(a);
}

u8 func_002D8790(void)
{
    return D_0078BBA2;
}

int func_002D87A0(void)
{
    return func_00251A00();
}

int func_002D87C0(int i)
{
    return D_0078BA58[i];
}

int func_002D87D8(void)
{
    int mask = func_00251A10();
    int i;
    int bit;

    for (i = 0; i < 16; i++) {
        bit = 1 << i;
        if ((mask & bit) && !(D_0078BA54 & bit)) {
            D_0078BA58[i] = func_00251A20(i);
        }
    }
    D_0078BA54 = mask;
    return mask;
}

void func_002D8870(int a, int b)
{
    func_00251BA8(a, b);
}

int func_002D8878(void)
{
    return func_00251A38();
}

int func_002D8898(void)
{
    return func_00251A48();
}

int func_002D88B8(void)
{
    if (func_00251A48() < 0) {
        return 1;
    }
    return 0;
}

void func_002D88D8(void)
{
    func_00251A58();
}

int func_20645B0(void);
int func_2064500(W11SoundDevice *state, int len);

void func_002D88E0(char *s)
{
    int i;

    if (TkIsDebug()) {
        W11SoundDevice *p;
        func_002F072C(D_00565F50.buf0C, s);
        p = &D_00565F50;
        p->h0A = func_002F0840(D_00565F50.buf0C);
        while (func_20645B0() != 0)
            ;
        for (i = 0; i < 0x80; i++) {
            if (func_2064500(&D_00565F50, 0x10C) >= 0) {
                break;
            }
            while (func_20645B0() != 0)
                ;
        }
    }
}

/* DEBT(ORDER): independent byte clears retain the original instruction schedule. */
void func_002D8978(void)
{
    if (TkIsDebug()) {
        func_2064278(&D_00565F50, 0x10C, 0xEFFA, 0x45, 0x48);
        D_00565F50.b08 = 0;
        D_00565F50.b09 = 0;
    }
}
