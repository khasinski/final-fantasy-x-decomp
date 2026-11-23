/* EE Battle-Effect Overlay: group 0x11, file 09526 (0x01B08508, -O0, shared across 19 containers)
 * Load base: 0x01B00000, .text: 0x01B08508..0x01B085C8 (1 function)
 */
#include "common.h"

typedef struct Msg8508 Msg8508;
typedef struct Vtbl8508 {
    void *fn[7];
    void (*update)(Msg8508 *);
} Vtbl8508;

typedef struct Parent8508 {
    Vtbl8508 *vtable;
    u8 pad04[0x9C];
    float mtxA0[4][4];
} Parent8508;

typedef struct Obj8508 {
    u8 pad00[0x20];
    float pos20[4];
    float pos30[4];
    Parent8508 *parent;
} Obj8508;

struct Msg8508 {
    Obj8508 *obj;
    u8 f4;
    u8 f5;
};

void func_002DCE08(void *dst, void *m, void *v);
void func_01B087D0(Msg8508 *m);

void func_01B08508(register Msg8508 *m)
{
    func_01B087D0(m);
    if (!(m->f4 & 1)) {
        return;
    }
    {
        Obj8508 *p = m->obj;
        struct {
            Parent8508 *obj;
            u8 f4;
            u8 f5;
        } sub;

        sub.obj = p->parent;
        sub.f5 = m->f5;
        sub.obj->vtable->update((Msg8508 *)&sub);
        func_002DCE08(p->pos20, p->parent->mtxA0, p->pos30);
    }
}
