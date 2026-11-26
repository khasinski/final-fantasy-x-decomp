#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

typedef struct {
    u8 pad00[0xEC0];
    OvlTask *pEC0;
    u8 padEC4[0x10];
    int wED4;
} OvlWork;

extern u8 D_01B01620[];
extern OvlWork *D_01B08A90;

extern OvlTask *func_01B043C0(void *);
extern void func_01B04588(OvlTask *);

void ovl_09644_1710(void)
{
    OvlWork *s2 = D_01B08A90;
    OvlTask *s0;

    s2->wED4 = 1;
    s0 = func_01B043C0(D_01B01620);
    s0->b18 = 1;
    func_01B04588(s0);
    s2->pEC0 = s0;
}
