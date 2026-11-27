#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int w18;
    u8 pad1C[0x34];
    int w50;
} Obj5FD8;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
} Msg3;

extern u8 D_01B008D0[];
extern void func_01B05990(void);
extern void func_01B108C0(void *);
extern void func_01B10CC8(void *);

void func_01B05FD8(Obj5FD8 *o)
{
    Msg3 m;
    m.p0 = o;
    m.p4 = (void *)func_01B05990;
    m.p8 = o;
    func_01B108C0(&m);
    m.p0 = D_01B008D0;
    m.p4 = o;
    func_01B10CC8(&m);
    o->w50 = 0;
    o->w18 = 0;
}
