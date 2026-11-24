#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Unk4870Arg;

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x3C];
    void (*unk104)(void);
    u8 pad108[0x28];
} Unk4870Slot; /* size 0x130 */

typedef struct {
    u8 pad0[0x2900];
    Unk4870Slot *unk2900;
    s32 unk2904;
} Unk4870Sub;

typedef struct {
    Unk4870Slot slots[76]; /* 76 * 0x130 = 0x5A40 */
    u8 pad5A40[0xC0];
    Unk4870Sub unk5B00;
    u8 pad8408[0xEAD0 - 0x8408];
    float unkEAD0;
} Unk4870Work;

extern s32 D_01B00C78[];
extern u8 D_01B0DBE0[];
extern Unk4870Work *D_01B0DCA8;

extern void func_01B06F08(void);
extern void func_01B09C48(void *, void *, s32, s32, s32, void *, float);

void func_01B04870(Unk4870Arg *arg0) {
    Unk4870Work *work = D_01B0DCA8;
    Unk4870Sub *sub = &work->unk5B00;
    s32 idx;
    s32 slotIdx;
    Unk4870Slot *slot;

    idx = arg0->unk2C;
    sub->unk2904 = idx;
    slotIdx = D_01B00C78[idx];
    slot = &work->slots[slotIdx];
    func_01B09C48(D_01B0DBE0, slot, slotIdx, 0, 0, 0, 0.12f);
    sub->unk2900 = slot;
    slot->unk104 = func_01B06F08;
    slot->unkC4 = work->unkEAD0;
}
