#include "common.h"

typedef struct {
    u8 pad00[0x04];
    int w04;
    int w08;
    u8 pad0C[0x32];
    s16 h3E;
    u8 pad40[0x60];
} Elem4460;

typedef struct {
    int w00;
    s16 h04;
} Info4498;

extern float func_00110288(int);
extern int func_00298E38(int);

void func_01B04460(u8 *base)
{
    Elem4460 *e = (Elem4460 *)(base + 0x10);
    int i;
    for (i = 0; i < 12; i++) {
        e->w08 = -1;
        e->w04 = -1;
        e->h3E = 0;
        e++;
    }
}

void func_01B04498(Info4498 *s, int a1)
{
    int h = func_00298E38(a1);
    s->w00 = h;
    s->h04 = (s16)(func_00110288(h) * 32768.0f / 3.1415927f);
}
