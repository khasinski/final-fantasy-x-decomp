#include "common.h"

typedef struct {
    u8 pad00[0xE0C];
    int wE0C;
    int wE10;
} OvlState;

extern OvlState *D_01B096A0;
extern int D_01B096A8;

extern int func_002B2E10(void *, int, int, int);
extern void func_01B01DE8(void);

void func_01B01F58(void)
{
    OvlState *s = D_01B096A0;

    D_01B096A8 = func_002B2E10(func_01B01DE8, 0, 0, 0);
    s->wE0C = 0x32;
    s->wE10 = 0;
}
