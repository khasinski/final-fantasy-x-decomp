#include "common.h"

typedef struct {
    u8 pad0[0x70];
    s16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
    u8 pad78[0x8C];
    s32 unk104;
    u8 pad108[0x18];
    s32 unk120;
} Unk5910Work;

void func_01B05910(Unk5910Work *arg0) {
    s32 t = --arg0->unk120;
    s32 v = (t << 12) / 60;

    arg0->unk76 = v;
    arg0->unk74 = v;
    arg0->unk72 = v;
    arg0->unk70 = v;
    if (t == 0) {
        arg0->unk104 = 0;
    }
}
