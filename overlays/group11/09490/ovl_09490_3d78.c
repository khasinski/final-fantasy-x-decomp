#include "common.h"

typedef struct {
    u8 pad0[0x2F80];
    u8 unk2F80[0x10];
    u8 pad2F90[0xEC00 - 0x2F90];
    float unkEC00;
    s32 unkEC04;
    s32 unkEC08;
    s32 unkEC0C;
} State3D78;

extern u8 D_01B0B378[];
extern s32 D_01B0B38C;
extern State3D78 *D_01B0B398;

extern void func_01B03E70(void);
extern float func_01B04960(s32);
extern void func_01B04A88(s32, void *, s32);
extern void func_01B06770(void *, s32);

void func_01B03D78(void) {
    State3D78 *s = D_01B0B398;

    func_01B04A88(-1, s->unk2F80, 0);
    s->unkEC00 = func_01B04960(-1);
    s->unkEC08 = 0;
    s->unkEC04 = 0;
    s->unkEC0C = 0;
    D_01B0B38C = 1;
}

void func_01B03DD8(void) {
    func_01B06770(D_01B0B378, 0);
    func_01B03E70();
}
