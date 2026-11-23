#include "common.h"

typedef struct {
    u8 pad0[0x74];
    s32 unk74;
    u8 pad78[4];
} Unk20C0Item;

typedef struct {
    Unk20C0Item items[4];
    s32 unk1F0;
    u8 pad1F4[0xC];
    s32 unk200;
    s32 unk204;
    s32 unk208;
} Unk20C0Work;

extern s32 D_01B00AE0[];
extern u8 D_01B036E0;
extern void *D_01B0DEA8;
extern Unk20C0Work D_01B0DF88;
extern s32 D_01B0E194;

extern s32 func_001E4A58(void *);
extern s32 func_002B2E10(void *, s32, s32, s32);
extern s32 func_01B073A8(s32);

void func_01B020C0(void) {
    Unk20C0Work *w = &D_01B0DF88;
    Unk20C0Item *it;
    s32 idx;
    s32 i;

    func_01B073A8(-1);
    idx = func_001E4A58(D_01B0DEA8);
    w->unk204 = 1;
    w->unk1F0 = D_01B00AE0[idx];
    w->unk200 = 0;
    w->unk208 = 0;
    it = w->items;
    for (i = 0; i < w->unk204; i++, it++) {
        it->unk74 = 0;
    }
    D_01B0E194 = func_002B2E10(&D_01B036E0, 0, 0, 0);
}
