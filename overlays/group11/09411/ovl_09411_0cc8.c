/* 09411 bone position copy helper (84 B, 09411 @ 0x01B00CC8). */

#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x80];
    u8 b80[0x30];
    u8 bB0[0x20];
    u8 bD0[0x56];
    u8 b126;
} EffObj;

extern int func_01B01430(int);
extern void func_001089E0(int, int, int, void *);

void ovl_09411_0cc8(EffObj *o)
{
    func_001089E0(func_01B01430(-1), 2, 0, o->b80);
    o->b126 = 2;
    MMI_COPY_LQ_A3(o->bD0, o->bB0);
    MMI_COPY_SQ_A3(o->bD0);
}
