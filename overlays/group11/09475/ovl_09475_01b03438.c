#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0xC4];
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
    float unkE0;
    u8 padE4[0x4C];
} Unk3438Sub; /* size 0x130 */

typedef struct {
    Unk3438Sub unk000;
    Unk3438Sub unk130;
    u8 pad260[0x5C0];
    float unk820[4];
    u8 pad830[0x494];
    void *unkCC4;
    u8 padCC8[0x9C];
    float unkD64;
} Work3438;

extern u8 D_01B09F20[];
extern Work3438 *D_01B0A068;

extern void func_01B03E48(s32, s32, float *, void *);
extern void func_01B05FE8(void *);
extern void func_01B062C8(void *, void *, s32, s32, s32, void *, float);

void func_01B03438(void) {
    float vec[4];
    Work3438 *work = D_01B0A068;
    Unk3438Sub *sub = &work->unk130;
    float ang;

    func_01B062C8(D_01B09F20, sub, 1, 0, 0, 0, 0.01f);
    sub->unkC4 = work->unkD64;
    vec[0] = -30.0f;
    vec[1] = 0.0f;
    vec[2] = 0.0f;
    vec[3] = 1.0f;
    func_01B03E48(-1, 0x73, vec, sub->unkD0);

    func_01B062C8(D_01B09F20, &work->unk000, 0, 0, 0, 0, 0.05f);
    ang = work->unkD64 - 1.5707964f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    work->unk000.unkC4 = ang;
    MMI_COPY_LQ_A3(work->unk000.unkD0, work->unk820);
    MMI_COPY_SQ_A3(work->unk000.unkD0);
    work->unk000.unkD0[1] -= 20.0f;
    work->unk000.unkE0 = -20.0f;
}

void func_01B035A8(void) {
    Work3438 *work = D_01B0A068;

    if (work->unkCC4 != 0) {
        func_01B05FE8(work->unkCC4);
        work->unkCC4 = 0;
    }
}
