#include "common.h"

typedef struct {
    u8 pad0[0x2E50];
    float unk2E50[4];
    u8 pad2E60[0xEAD0 - 0x2E60];
    float unkEAD0;
    u8 padEAD4[0xA8];
    s32 unkEB7C;
    s32 unkEB80;
    s32 unkEB84;
} Unk6618Work;

extern s32 D_01B0DC9C;
extern Unk6618Work *D_01B0DCA8;

extern void func_01B02070(void);
extern float func_01B07200(s32);
extern void func_01B07328(s32, float *, s32);

void func_01B06618(void) {
    Unk6618Work *work = D_01B0DCA8;
    float f;

    func_01B07328(-1, work->unk2E50, 0);
    f = func_01B07200(-1);
    work->unkEB84 = 0;
    work->unkEB80 = 0;
    work->unkEB7C = 0;
    work->unkEAD0 = f;
    D_01B0DC9C = 1;
    func_01B02070();
}
