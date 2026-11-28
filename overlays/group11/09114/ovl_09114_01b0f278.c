#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int f18;
    u8 pad1C[0x10];
    int f2C;
} ObjF278;

extern void func_01B0D258(void);
extern u8 D_01B00F58[];
extern void func_01B1D740(void *);
extern void func_01B1DB48(void *);

void func_01B0F278(ObjF278 *a0)
{
    void *m[4];

    m[0] = a0;
    m[1] = (void *)func_01B0D258;
    m[2] = a0;
    func_01B1D740(m);

    m[0] = D_01B00F58;
    m[1] = a0;
    func_01B1DB48(m);

    a0->f2C = 0;
    a0->f18 = 0;
}
