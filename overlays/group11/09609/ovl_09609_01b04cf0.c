#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk4CF0Task;

typedef struct {
    u8 pad0[0xC0];
    float unkC0[4];
    u8 padD0[0x190];
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
    s32 unk518;
    s32 unk51C;
} Unk4CF0Item; /* size 0x520 */

typedef struct {
    Unk4CF0Item items[8];
    void *unk2900;
    s32 unk2904;
    s32 unk2908;
    s32 unk290C;
} Unk4CF0Block;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x20];
} Unk4CF0Slot;

typedef struct {
    u8 pad0[0x5C30];
    Unk4CF0Block unk5C30;
    u8 pad8540[0xECA4 - 0x8540];
    Unk4CF0Slot *unkECA4;
} Unk4CF0Work;

extern u8 D_01B04B80;
extern u8 D_01B0DEB0;
extern Unk4CF0Work *D_01B0DF78;

extern void func_00110540(s32, s32, float);
extern void func_01B04CB0(Unk4CF0Item *, s32);
extern s32 func_01B06880(void);
extern void func_01B069A8(float *);
extern void func_01B069F0(void);
extern void func_01B075F8(s32, float *, s32);
extern Unk4CF0Task *func_01B09BB8(void *);
extern void func_01B09D80(Unk4CF0Task *);
extern void func_01B0A388(void *, void *);
extern void func_01B0ADC0(float *, float *, float *);
extern float func_01B0AF68(float *, float *);

void func_01B04CF0(void) {
    float pos[4];
    Unk4CF0Work *work = D_01B0DF78;
    Unk4CF0Block *blk = &work->unk5C30;
    Unk4CF0Item *item = blk->items;
    s32 n = work->unkECA4->unk4;
    s32 i;

    func_01B069A8(pos);
    for (i = 0; i < n; i++, item++) {
        u8 id = work->unkECA4->unk8[i];
        Unk4CF0Task *task;

        MMI_COPY_LQ_A3(item->unk260, pos);
        MMI_COPY_SQ_A3(item->unk260);
        func_01B075F8(id, item->unk270, 4);
        func_01B0ADC0(item->unk280, item->unk260, item->unk270);
        item->unk510 = (s32)(func_01B0AF68(item->unk260, item->unk270) / 8.0f);
        if (item->unk510 < 0) {
            item->unk510 = 1;
        }
        item->unk514 = item->unk510;
        func_01B04CB0(item, blk->unk2904);
        MMI_COPY_LQ_A3(item->unkC0, item->unk280);
        MMI_COPY_SQ_A3(item->unkC0);
        item->unk51C = i;
        item->unk518 = id;
        task = func_01B09BB8(&D_01B04B80);
        task->unk14 = item;
        func_01B09D80(task);
    }
    blk->unk2908 = n;
    blk->unk290C = 0;
    func_01B0A388(&D_01B0DEB0, blk->unk2900);
    func_01B069F0();
    func_00110540(func_01B06880(), 1, 0.0f);
}
