#include "common.h"

typedef struct {
    u8 pad0[0x1E];
    u16 unk1E;
    u8 pad20[4];
    u32 unk24;
    u32 unk28;
    u16 unk2C;
    u16 unk2E;
} UnkFD40Inner;

typedef struct {
    UnkFD40Inner *unk00;
    u16 unk04;
} UnkFD40Arg;

void func_01B0FD40(UnkFD40Arg *arg) {
    UnkFD40Inner *p = arg->unk00;
    s32 cnt = arg->unk04;

    if (cnt < p->unk2C) {
        p->unk2C -= cnt;
        p->unk24 += cnt * p->unk1E;
    } else {
        cnt -= p->unk2C;
        if (cnt >= p->unk2E) {
            p->unk2E = 0;
            p->unk2C = 0;
        } else {
            p->unk2C = p->unk2E - cnt;
            p->unk24 = cnt * p->unk1E;
            p->unk2E = 0;
            p->unk28 = p->unk24 + p->unk2C * p->unk1E;
        }
    }
}
