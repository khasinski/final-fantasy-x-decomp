#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0xC0];
    float unkC0;
    float unkC4;
    u8 padC8[0x58];
    s32 unk120;
    u8 pad124[0xC];
} Unk4A88Sub;

typedef struct {
    u8 pad0[0x130];
    Unk4A88Sub unk130;
    u8 pad260[0x10];
    float unk270[4];
    u8 pad280[0x298];
    s32 unk518;
    s32 unk51C;
} Unk4A88Item;

extern s32 D_01B00CB0[];
extern float D_01B00CC0[];
extern s32 D_01B00CD0[];
extern u8 D_01B0A4D8;
extern u8 D_01B0DEB0;
extern u8 D_01B17DF0;
extern u8 D_01C03DD0;

extern s32 func_01B073A8(s32);
extern void func_01B09608(void *, s32, void *, s32);
extern void func_01B098A8(void *, s32, s32);
extern s32 func_01B09F18(void *, void *, s32, s32, s32, void *, float);

void func_01B04A88(Unk4A88Item *item, float *rot, s32 idx) {
    Unk4A88Sub *sub = &item->unk130;
    void *dst;

    func_01B09F18(&D_01B0DEB0, sub, D_01B00CB0[idx], 0, 0, &D_01B0A4D8, D_01B00CC0[idx]);
    dst = (u8 *)item + 0x200;
    MMI_COPY_LQ_A3(item->unk270, item->unk270);
    MMI_COPY_SQ_A3(dst);
    sub->unkC0 = rot[0];
    sub->unkC4 = rot[1];
    sub->unk120 = func_01B073A8(item->unk518);
    if (item->unk51C == 0) {
        func_01B09608(&D_01C03DD0, D_01B00CD0[idx], dst, 0x100);
    }
    func_01B098A8(&D_01B17DF0, 1, 1);
}
