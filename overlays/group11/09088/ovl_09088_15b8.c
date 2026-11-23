#include "common.h"

extern void *func_002B49A0(void *, int, int);
extern void func_002CF528(void *, int);
extern void func_002CF810(void *, int);

void func_01B015B8(void *a0, int n1, int n2)
{
    int i;
    for (i = 0; i < n1; i++) {
        func_002CF528(func_002B49A0(a0, 2, i), 0);
    }
    for (i = 0; i < n2; i++) {
        func_002CF810(func_002B49A0(a0, 3, i), 0);
    }
}

void func_01B01668(void *a0, int base, int n1, int n2)
{
    int i;
    for (i = 0; i < n1; i++) {
        func_002CF528(func_002B49A0(a0, 2, base + i), 0);
    }
    for (i = 0; i < n2; i++) {
        func_002CF810(func_002B49A0(a0, 3, base + i), 0);
    }
}

void func_01B01720(void *a0, s16 *p1, s16 *p2)
{
    if (p1 != 0) {
        while (*p1 != -1) {
            func_002CF528(func_002B49A0(a0, 2, *p1++), 0);
        }
    }
    if (p2 != 0) {
        while (*p2 != -1) {
            func_002CF810(func_002B49A0(a0, 3, *p2++), 0);
        }
    }
}
