#include "common.h"

typedef struct {
    u8 pad00[0x18];
    s32 state18;
    u8 pad1C[0x14];
    s32 w30;
    void *p34;
} Ovl09317A;

extern u8 D_01B00990[];
extern void func_01B03150(void);

extern void func_01B0DA80(void *);
extern void func_01B0DE88(void *);

void func_01B03268(Ovl09317A *a0, void *a1, s32 a2) {
    void *args[3];

    args[0] = a0;
    args[1] = func_01B03150;
    args[2] = a0;
    func_01B0DA80(args);

    args[0] = D_01B00990;
    args[1] = a0;
    func_01B0DE88(args);

    a0->w30 = a2;
    a0->p34 = a1;
    a0->state18 = 0;
}
