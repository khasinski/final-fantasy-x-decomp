#include "common.h"

extern u32 *D_01B06320;
extern u32 *D_01B06324;
extern u32 *D_01B06328;
extern char D_01B04600[];
extern char D_01B04620[];
extern char D_01B04628[];

extern void func_002B4980(void *);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002EF240(const char *, ...);

void func_01B01E68(void *res)
{
    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
}

void func_01B01EB0(u32 *a0, u32 *a1, u32 *a2)
{
    register int cond __asm__("$3");

    D_01B06320 = a0;
    D_01B06324 = a1;
    D_01B06328 = a2;
    func_002EF240(D_01B04600, a0, a1, a2);
    cond = (a0 < a1);
    if (cond) {
        do {
            *a2++ = *a0++;
        } while (a0 < a1);
    }
}

void func_01B01F48(int a0)
{
    u32 *p = D_01B06320;
    u32 *end = D_01B06324;
    u32 *q = D_01B06328;

    while (p < end) {
        if (*q != *p) {
            if (a0 != 0) {
                func_002EF240(D_01B04620);
            }
            func_002EF240(D_01B04628, p, *q, *p);
        }
        p++;
        q++;
    }
}
