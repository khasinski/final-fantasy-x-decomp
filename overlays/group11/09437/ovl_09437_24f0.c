#include "common.h"

typedef struct {
    u8 pad00[0xD0];
    u8 vD0[0x10];
    u8 padE0[0x24];
    void *p104;
} Sub24F0;

extern void func_01B03FC8(int, int, void *);

void func_01B024F0(Sub24F0 *o)
{
    func_01B03FC8(-1, 8, o->vD0);
    o->p104 = 0;
}
