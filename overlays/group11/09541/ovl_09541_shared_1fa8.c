/* Shared debug matrix print helper (Sub-family A: 9541, 9685, 9710, 9713, 9525, 9418).
 * .text in 9541: 0x01B01FA8..0x01B02070 (1 function).
 */
#include "common.h"

extern char D_01B02418[];
extern void func_002EF240(const char *, ...);

void func_01B01FA8(float (*m)[4], int n)
{
    int i;

    for (i = 0; i < n; i++, m++) {
        func_002EF240(D_01B02418, (*m)[0], (*m)[1], (*m)[2], (*m)[3], i);
    }
}
