#include "common.h"

typedef struct {
    u8 pad00[0x58];
    int f58;
} Sub5F48;

typedef struct {
    u8 pad00[0x68];
    Sub5F48 *p68;
} Obj5F48;

typedef struct {
    Obj5F48 *obj;
} Arg5F48;

extern int func_00107BE8(int, int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);

void func_01B05F48(Arg5F48 *a0)
{
    int h = a0->obj->p68->f58;
    int r;

    func_0010D380(h, -1, -1);
    func_0010D3A8(h, -1, -1);
    r = func_00107BE8(h, 0);
    __asm__("" : : "r"(r));
}
