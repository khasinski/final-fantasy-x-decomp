#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk4790Task;

typedef struct {
    u8 pad0[0xC0];
    float unkC0[4];
    u8 padD0[0x190];
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x30];
    u8 unk2C0[0x250];
    s32 unk510;
    s32 unk514;
    s32 unk518;
    s32 unk51C;
} Unk4790Item; /* size 0x520 */

typedef struct {
    u8 pad0[0x10];
    Unk4790Item items[8];
    u8 pad2910[0x2B68 - 0x2910];
    s32 unk2B68;
    s32 unk2B6C;
    s32 unk2B70;
} Unk4790Block;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x20];
} Unk4790Slot;

typedef struct {
    u8 pad0[0x30B0];
    Unk4790Block unk30B0;
    u8 pad5C24[0xECA4 - 0x5C24];
    Unk4790Slot *unkECA4;
} Unk4790Work;

extern u8 D_01B04570;
extern Unk4790Work *D_01B0DF78;

extern void func_00110540(s32, s32, float);
extern void func_01B042D8(void *);
extern void func_01B04750(Unk4790Item *, s32);
extern s32 func_01B06880(void);
extern void func_01B069A8(float *);
extern void func_01B069F0(void);
extern void func_01B075F8(s32, float *, s32);
extern Unk4790Task *func_01B09BB8(void *);
extern void func_01B09D80(Unk4790Task *);
extern void func_01B0ADC0(float *, float *, float *);
extern float func_01B0AF68(float *, float *);

void func_01B04790(void) {
    float pos[4];
    Unk4790Work *work = D_01B0DF78;
    Unk4790Block *blk = &work->unk30B0;
    Unk4790Item *item = blk->items;
    s32 n = work->unkECA4->unk4;
    s32 i;

    func_01B069A8(pos);
    for (i = 0; i < n; i++, item++) {
        u8 id = work->unkECA4->unk8[i];
        Unk4790Task *task;

        MMI_COPY_LQ_A3(item->unk260, pos);
        MMI_COPY_SQ_A3(item->unk260);
        func_01B075F8(id, item->unk270, 4);
        func_01B0ADC0(item->unk280, item->unk260, item->unk270);
        item->unk510 = (s32)(func_01B0AF68(item->unk260, item->unk270) / 6.0f);
        if (item->unk510 < 0) {
            item->unk510 = 1;
        }
        item->unk514 = item->unk510;
        if (blk->unk2B68 == 0) {
            func_01B042D8(item->unk2C0);
        }
        func_01B04750(item, blk->unk2B68);
        MMI_COPY_LQ_A3(item->unkC0, item->unk280);
        MMI_COPY_SQ_A3(item->unkC0);
        item->unk51C = i;
        item->unk518 = id;
        task = func_01B09BB8(&D_01B04570);
        task->unk14 = item;
        func_01B09D80(task);
    }
    blk->unk2B6C = n;
    blk->unk2B70 = 0;
    func_01B069F0();
    func_00110540(func_01B06880(), 1, 0.0f);
}
