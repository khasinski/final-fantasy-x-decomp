#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int f18;
    int f1C;
    void *p20;
} Obj3E30;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    void *a3;
} Msg3E30;

extern u8 D_01B00B80[];
extern void func_01B03D08(void *);
extern void func_01B0FBF0(Msg3E30 *);
extern void func_01B0FFF8(Msg3E30 *);

void func_01B03E30(Obj3E30 *a0, void *a1)
{
    Msg3E30 m;

    m.a0 = a0;
    m.a1 = func_01B03D08;
    m.a2 = a0;
    func_01B0FBF0(&m);

    m.a0 = D_01B00B80;
    m.a1 = a0;
    func_01B0FFF8(&m);

    a0->p20 = a1;
    a0->f18 = 0;
}
