#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk2468Task;

typedef struct {
    u8 pad0[0xC0];
    float unkC0;
    float unkC4;
    u8 padC8[0x58];
    s32 unk120;
    u8 pad124[0xC];
} Unk2468Sub;

typedef struct {
    u8 pad0[0xD0];
    float unkD0[4];
    u8 padE0[0x50];
    Unk2468Sub unk130;
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
    s32 unk518;
} Unk2468Item;

typedef struct {
    u8 pad0[0x2904];
    s32 unk2904;
    s32 unk2908;
    s32 unk290C;
} Unk2468Block;

typedef struct {
    u8 pad0[0x5C30];
    Unk2468Block unk5C30;
} Unk2468Work;

extern s32 D_01B00A40[];
extern float D_01B00A50[];
extern u8 D_01B07978;
extern u8 D_01B0B2D0;
extern Unk2468Work *D_01B0B398;

extern s32 func_00116068(void);
extern void func_01B04478(void *, float *, s32);
extern s32 func_01B04838(s32);
extern void func_01B07080(Unk2468Task *);
extern s32 func_01B07360(void *, void *, s32, s32, s32, void *, float);
extern s32 func_01B07828(void *, void *);

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02468(Unk2468Item *item, float *rot, s32 idx) {
    Unk2468Sub *sub = &item->unk130;

    func_01B07360(&D_01B0B2D0, sub, D_01B00A40[idx], 0, 0, &D_01B07978, D_01B00A50[idx]);
    copy_vec((u8 *)item + 0x200, item->unk270);
    sub->unkC0 = rot[0];
    sub->unkC4 = rot[1];
    sub->unk120 = func_01B04838(item->unk518);
}

void func_01B02510(Unk2468Task *arg0) {
    float pos[4];
    Unk2468Item *item = (Unk2468Item *)arg0->unk14;
    Unk2468Block *blk = &D_01B0B398->unk5C30;
    float t;
    s32 i;

    if (item->unk510 > 0) {
        if (func_00116068() != 0) {
            item->unk510--;
        }
    }

    t = (float)item->unk510 / (float)item->unk514;
    for (i = 0; i < 3; i++) {
        pos[i] = item->unk270[i] * (1.0f - t) + item->unk260[i] * t;
    }
    pos[3] = 1.0f;

    func_01B04478(item->unk280, pos, 0x80);
    MMI_COPY_LQ_A3(pos, pos);
    MMI_COPY_SQ_A3(item->unkD0);

    if (item->unk510 <= 0) {
        func_01B02468(item, item->unk280, blk->unk2904);
        func_01B07828(&D_01B0B2D0, item);
        blk->unk290C++;
        func_01B07080(arg0);
    }
}
