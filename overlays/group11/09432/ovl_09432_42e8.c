#include "common.h"

extern u8 D_01B00B50[];

void func_01B03FF8(void *);
void func_01B0E668(void *);
void func_01B0EA70(void *);

void func_01B042E8(u8 *a0, void *a1)
{
    struct { void *a, *b, *c; } arg;

    arg.a = a0;
    arg.c = a0;
    arg.b = (void *)func_01B03FF8;
    func_01B0E668(&arg);
    arg.b = a0;
    arg.a = D_01B00B50;
    func_01B0EA70(&arg);
    *(void **)(a0 + 0x2C) = a1;
    *(int *)(a0 + 0x18) = 0;
}
