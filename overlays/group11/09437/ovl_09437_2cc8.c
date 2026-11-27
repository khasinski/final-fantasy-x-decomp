#include "common.h"

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x3C];
    void *p104;
} Sub5F0;

typedef struct {
    u8 pad00[0x5F0];
    Sub5F0 s5F0;
    u8 pad6F8[0x1818];
    float f1F10;
} Work2CC8;

extern u8 D_01B0A508[];
extern Work2CC8 *D_01B0A5F0;
extern void func_01B02C90(void *);
extern void func_01B063E8(void *, void *, int, int, int, int, float);

void func_01B02CC8(void)
{
    Work2CC8 *w = D_01B0A5F0;
    Sub5F0 *s = &w->s5F0;

    func_01B063E8(D_01B0A508, s, 5, 13, 0, 0, 0.00700000022f);
    s->fC0 = 0.785398185f;
    s->p104 = (void *)func_01B02C90;
    s->fC4 = w->f1F10;
}
