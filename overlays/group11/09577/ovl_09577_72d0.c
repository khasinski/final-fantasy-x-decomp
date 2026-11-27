#include "common.h"

typedef struct {
    u8 pad00[0x18];
    float f18;
    float f1C;
} Work72D0;

extern u8 D_01B00B00[];
extern int D_01B00B30;
extern void func_01B06218(void *);
extern void func_01B17540(void *);
extern void func_01B17948(void *);

void func_01B072D0(Work72D0 *w)
{
    void *m[3];

    m[0] = w;
    m[1] = (void *)func_01B06218;
    m[2] = w;
    func_01B17540(m);
    m[0] = D_01B00B00;
    m[1] = w;
    func_01B17948(m);
    w->f18 = w->f1C = 0.0f;
    D_01B00B30 = 0;
}
