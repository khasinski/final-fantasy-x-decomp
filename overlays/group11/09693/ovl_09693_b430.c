#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int state;
    u8 pad1C[0x04];
    int w20;
    void *p24;
    u8 pad28[0x68];
    void *p90;
    u8 pad94[0x36C];
    void *p400;
} WorkB430;

extern u8 D_01B00960[];
extern void func_01B0B0C8(void *);
extern void func_01B16C58(void *);
extern void func_01B17060(void *);

void func_01B0B430(WorkB430 *w, void *a1, int a2, void *a3, void *a4)
{
    void *m[3];
    m[0] = w;
    m[1] = (void *)func_01B0B0C8;
    m[2] = w;
    func_01B16C58(m);
    m[0] = D_01B00960;
    m[1] = w;
    func_01B17060(m);
    w->p400 = a4;
    w->p90 = a3;
    w->w20 = a2;
    w->p24 = a1;
    w->state = 0;
}
