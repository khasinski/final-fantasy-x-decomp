#include "common.h"

typedef struct {
    u8 pad00[0xC80];
    u8 fC80[0x248];
    float fEC8;
} OvlWork;

extern OvlWork *D_01B0A480;

extern void func_0010D380(void *, int, int);
extern void func_0010D3A8(void *, int, int);
extern void func_0010D4A0(void *, int);
extern void func_0010D4D8(void *, int);
extern void *func_01B035F8(int);
extern void func_01B06F08(void *, void *, void *);

void func_01B031E8(void)
{
    void *s0 = func_01B035F8(2);

    func_0010D380(s0, -1, 0x3540);
    func_0010D3A8(s0, -1, 0x3BD0);
    func_0010D4A0(s0, -1);
    func_0010D4D8(s0, -1);
}

void func_01B03248(void)
{
    float sp00[4];
    float sp10[4];
    OvlWork *w = D_01B0A480;

    sp00[0] = 0.0f;
    sp00[1] = w->fEC8;
    sp10[0] = -20.0f;
    sp10[2] = -10.0f;
    sp10[3] = 1.0f;
    sp00[2] = 0.0f;
    sp00[3] = 0.0f;
    sp10[1] = 0.0f;
    func_01B06F08(sp00, w->fC80, sp10);
}
