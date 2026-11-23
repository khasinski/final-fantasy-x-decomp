#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk2698Task;

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
} Unk2698Item;

typedef struct {
    Unk2698Item items[8];
    void *unk2900;
    s32 unk2904;
    s32 unk2908;
    s32 unk290C;
} Unk2698Block;

typedef struct {
    u8 pad0[0x5C30];
    Unk2698Block unk5C30;
} Unk2698Work;

extern s32 D_01B00D2C;
extern u8 D_01B02510;
extern u8 D_01B0B2D0;
extern Unk2698Work *D_01B0B398;

extern void func_01B02658(Unk2698Item *, s32);
extern void func_01B03E00(float *);
extern void func_01B03E48(void);
extern void func_01B04A88(s32, float *, s32);
extern Unk2698Task *func_01B07000(void *);
extern void func_01B071C8(Unk2698Task *);
extern s32 func_01B07828(void *, void *);
extern void func_01B080C8(void *, float *, float *);
extern float func_01B08270(float *, float *);

void func_01B02698(void) {
    float pos[4];
    Unk2698Block *blk = &D_01B0B398->unk5C30;
    Unk2698Item *item = blk->items;
    s32 count = D_01B00D2C;
    s32 i;

    func_01B03E00(pos);

    for (i = 0; i < count; i++, item++) {
        Unk2698Task *task;
        MMI_COPY_LQ_A3(item->unk260, pos);
        MMI_COPY_SQ_A3(item->unk260);
        func_01B04A88(i, item->unk270, 4);
        func_01B080C8(item->unk280, item->unk260, item->unk270);
        item->unk510 = (s32)(func_01B08270(item->unk260, item->unk270) * 0.125f);
        if (item->unk510 < 0) {
            item->unk510 = 1;
        }
        item->unk514 = item->unk510;
        func_01B02658(item, blk->unk2904);
        MMI_COPY_LQ_A3(item->unkC0, item->unk280);
        MMI_COPY_SQ_A3(item->unkC0);
        item->unk518 = i;
        task = func_01B07000(&D_01B02510);
        task->unk14 = item;
        func_01B071C8(task);
    }

    blk->unk2908 = count;
    blk->unk290C = 0;
    func_01B07828(&D_01B0B2D0, blk->unk2900);
    func_01B03E48();
}
