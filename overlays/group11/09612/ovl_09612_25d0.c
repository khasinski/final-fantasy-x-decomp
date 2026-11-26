#include "common.h"

typedef struct {
    u8 pad00[0x0E];
    u8 b0E;
} SubInfo;

typedef struct {
    u8 pad00[0x08];
    SubInfo *p08;
    u8 pad0C[0x94];
    u8 fA0[0x30];
    u8 fD0[0x30];
} CallbackArg;

typedef struct {
    u8 pad00[0x30];
} Elem30;

typedef struct {
    u8 pad00[0xAC0];
    Elem30 arrAC0[26];
    Elem30 arrFA0[27];
} OvlState;

extern OvlState *D_01B0A568;
extern void func_01B023B8(void *, void *, void *);

void func_01B025D0(CallbackArg *a0)
{
    OvlState *s = D_01B0A568;
    int idx = a0->p08->b0E - 0x16;
    __asm__("" : "+r"(idx));
    func_01B023B8(&s->arrAC0[idx], a0->fA0, a0->fD0);
}

void func_01B02600(CallbackArg *a0)
{
    OvlState *s = D_01B0A568;
    int idx = a0->p08->b0E - 4;
    __asm__("" : "+r"(idx));
    func_01B023B8(&s->arrFA0[idx], a0->fA0, a0->fD0);
}
