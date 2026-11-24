#include "common.h"

typedef struct {
    u8 pad00[0x110];
    u32 state110;
} OvlA;

extern u8 D_01B00B40;

extern void func_01B03C58(void *);
extern void func_01B0CFF8(void *);
extern void func_01B0D400(void *);

void func_01B040C8(OvlA *a0) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg;

    arg.p00 = a0;
    arg.p04 = func_01B03C58;
    arg.p08 = a0;
    func_01B0CFF8(&arg);

    arg.p00 = &D_01B00B40;
    arg.p04 = a0;
    func_01B0D400(&arg);

    a0->state110 = 0;
}
