#include "common.h"

typedef struct {
    u8 pad0[0x2F80];
    float unk2F80[4];
    u8 pad2F90[0xBC70];
    float unkEC00;
    u8 padEC04[0xA8];
    s32 unkECAC;
    s32 unkECB0;
    s32 unkECB4;
} Unk6920Work;

extern s32 D_01B0DF6C;
extern Unk6920Work *D_01B0DF78;

extern void func_01B020B0(void);
extern float func_01B074D0(s32);
extern void func_01B075F8(s32, float *, s32);

void func_01B06920(void) {
    Unk6920Work *work = D_01B0DF78;
    float f;

    func_01B075F8(-1, work->unk2F80, 0);
    f = func_01B074D0(-1);
    work->unkECB4 = 0;
    work->unkECB0 = 0;
    work->unkECAC = 0;
    work->unkEC00 = f;
    D_01B0DF6C = 1;
    func_01B020B0();
}
