#include "common.h"

typedef struct {
    u8 pad00[0x6274];
    void *p6274;
    u8 pad6278[0x30];
    int w62A8;
} OvlState;

extern OvlState *D_01B0BD58;

extern void func_01B02D20(void);
extern void *func_01B072E8(void *);
extern void func_01B07368(void *);
extern void func_01B074B0(void *);

void func_01B034A0(void)
{
    func_01B02D20();
}

void func_01B034A8(void)
{
    OvlState *s = D_01B0BD58;

    s->w62A8 = 20;
    s->p6274 = func_01B072E8(func_01B034A0);
    func_01B074B0(s->p6274);
}

void func_01B034E8(void)
{
    OvlState *s = D_01B0BD58;

    if (s->p6274 != 0) {
        func_01B07368(s->p6274);
        s->p6274 = 0;
    }
}
