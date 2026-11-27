#include "common.h"

typedef struct OvlR6Obj {
    u8 pad00[0x54];
    int w54;
    int w58;
} OvlR6Obj;

extern int D_003F3944;
extern OvlR6Obj *D_0054D5E8[];
extern u16 D_00551C98;
extern char D_01B08588[];

extern void func_00294CD8(int, int);
extern void func_002EA328(int) __attribute__((noreturn));
extern void func_002EF240(char *, ...);

void func_01B00988(void)
{
    OvlR6Obj *o = D_0054D5E8[1];
    u16 t0 = *(volatile u32 *)0x10000000;

    if (o->w58 != 0) {
        o->w54 = o->w58;
    } else {
        o->w54 = D_003F3944;
    }
    func_00294CD8(1, 0);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    } else if (o->w58 != o->w54) {
        func_002EF240(D_01B08588);
        func_002EA328(1);
    }
    D_00551C98 = *(volatile u32 *)0x10000000 - t0;
}
