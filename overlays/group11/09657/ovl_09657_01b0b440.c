#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int w18;
    u8 pad1C[0x18];
    int w34;
} ObjB440;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
} Msg3;

extern u8 D_01B00CD0[];
extern void func_01B0AA28(void);
extern void func_01B19FF0(void *);
extern void func_01B1A3F8(void *);

void func_01B0B440(ObjB440 *o)
{
    Msg3 m;
    m.p0 = o;
    m.p4 = (void *)func_01B0AA28;
    m.p8 = o;
    func_01B19FF0(&m);
    m.p0 = D_01B00CD0;
    m.p4 = o;
    func_01B1A3F8(&m);
    o->w34 = 0;
    o->w18 = 410;
}
