#include "common.h"

typedef struct {
    u8 pad00[0x2B60];
    u8 sub[0x18];
    int w2B78;
    float f2B7C;
    float f2B80;
} Work7DF8;

extern u8 D_01B00B00[];
extern void func_01B06C38(void *);
extern void func_01B15F98(void *);
extern void func_01B163A0(void *);

void func_01B07DF8(Work7DF8 *w)
{
    void *m[3];

    m[0] = w->sub;
    m[1] = (void *)func_01B06C38;
    m[2] = w;
    func_01B15F98(m);
    m[0] = D_01B00B00;
    m[1] = w->sub;
    func_01B163A0(m);
    w->w2B78 = 0;
    w->f2B7C = w->f2B80 = 0.0f;
}
