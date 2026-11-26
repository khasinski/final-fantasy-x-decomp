#include "common.h"

typedef struct {
    u8 pad00[0x58];
    void *p58;
} OvlSub;

typedef struct {
    u8 pad00[0x88];
    OvlSub *sub;
} OvlObj;

typedef struct {
    OvlObj *obj;
} Arg4;

extern void func_0010D380(void *, int, int);
extern int func_0010D3A8(void *, int, int);

void ovl_09341_2ae0(Arg4 *a)
{
    void *s0 = a->obj->sub->p58;

    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
    __asm__("" : : : "memory");
}
