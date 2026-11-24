#include "common.h"

typedef struct {
    u8 pad00[0x58];
    int f58;
} Sub5C78;

typedef struct {
    u8 pad00[0x68];
    Sub5C78 *p68;
    u8 pad6C[0x0C];
    int f78;
} Obj5C78;

typedef struct {
    Obj5C78 *obj;
    int f04;
    int f08;
    int pad0C;
    int pad10;
    int f14;
    int f18;
    int f1C;
} Arg5C78;

extern void func_0010D380(int, int, int);
extern int func_0010D3A8(int, int, int);
extern int func_002A7120(int, int, int);
extern void func_002A72F8(int, int, int, int);
extern void func_002A7308(int, int, int, int);

void func_01B05C78(Arg5C78 *a0)
{
    Obj5C78 *o = a0->obj;
    int h = o->p68->f58;
    int sz;
    int r;
    int flag;

    sz = func_002A7120(h, a0->f14, a0->f1C);
    if (a0->f08 < sz) {
        return;
    }
    a0->f08 = sz;
    o->f78 = a0->f04;
    func_0010D380(h, -1, 0x3C00);
    r = func_0010D3A8(h, -1, 0x2EE0);
    flag = a0->f1C;
    __asm__("" : : "r"(r));
    if (flag != 0) {
        func_002A7308(a0->f04, h, a0->f14, a0->f18);
    } else {
        func_002A72F8(a0->f04, h, a0->f14, a0->f18);
    }
}
