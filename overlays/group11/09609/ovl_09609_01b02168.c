#include "common.h"

typedef struct {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Unk2168Entry; /* size 0x1C */

typedef struct {
    Unk2168Entry unk0[3];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
} Unk2168Slot; /* size 0x7C */

typedef struct {
    Unk2168Slot slots[4];
    s32 unk1F0[4];
    s32 unk200;
} Unk2168Work;

extern u8 D_01B009F8[];
extern u8 D_01B00A40[];

void func_01B02168(Unk2168Work *work) {
    s32 idx = work->unk200;
    Unk2168Slot *slot = &work->slots[idx];
    Unk2168Entry *e;
    u8 *p;
    s32 val;
    s32 i;

    switch (work->unk1F0[idx]) {
    case 0:
    default:
        p = D_01B009F8;
        val = 0x3000;
        break;
    case 1:
        p = D_01B009F8 + 0x18;
        val = 0x3000;
        break;
    case 2:
        p = D_01B009F8 + 0x30;
        val = 0x3000;
        break;
    case 3:
        p = D_01B00A40;
        val = 0x3000;
        break;
    }

    e = slot->unk0;
    for (i = 0; i < 3; i++, e++) {
        e->unk0 = p;
        e->unk4 = 0;
        e->unk10 = 0;
        e->unk14 = 0;
        e->unk18 = 0;
        p += 8;
    }

    slot->unk54 = val;
    slot->unk58 = 0x200;
    slot->unk5C = 0xA2;
    slot->unk60 = 0xF;
    slot->unk64 = 0;
    slot->unk68 = 0;
    slot->unk74 = 1;
}
