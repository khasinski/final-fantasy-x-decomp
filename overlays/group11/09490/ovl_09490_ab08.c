#include "common.h"

typedef struct {
    u8 pad0[0x80];
    u8 unk80[4];
    u8 unk84[4];
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    u8 unk98;
    u8 unk99;
} UnkAB08Fade;

typedef struct {
    u8 pad0[0x14];
    UnkAB08Fade *unk14;
} UnkAB08Task;

extern s32 func_00116068(void);
extern void func_002B2F30(UnkAB08Fade *, u32, u8, u8);
extern void func_01B07080(UnkAB08Task *);

void func_01B0AB08(UnkAB08Task *task) {
    UnkAB08Fade *fade = task->unk14;
    union {
        u32 w;
        u8 b[4];
    } col;

    if (fade->unk88 > 0) {
        if (func_00116068() != 0) {
            fade->unk88--;
        }
        return;
    }

    if (fade->unk8C == 0) {
        if (fade->unk94 == 0) {
            func_01B07080(task);
            return;
        }
        if (func_00116068() != 0) {
            fade->unk94--;
        }
    } else {
        if (func_00116068() != 0) {
            fade->unk8C--;
        }
    }

    {
        u8 col[4];
        col[0] = (fade->unk80[0] * fade->unk8C + fade->unk84[0] * (fade->unk90 - fade->unk8C)) / fade->unk90;
        col[1] = (fade->unk80[1] * fade->unk8C + fade->unk84[1] * (fade->unk90 - fade->unk8C)) / fade->unk90;
        col[2] = (fade->unk80[2] * fade->unk8C + fade->unk84[2] * (fade->unk90 - fade->unk8C)) / fade->unk90;
        col[3] = (fade->unk80[3] * fade->unk8C + fade->unk84[3] * (fade->unk90 - fade->unk8C)) / fade->unk90;
        func_002B2F30(fade, *(u32 *)col, fade->unk98, fade->unk99);
    }
}
