#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk21B0Task;

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
} Unk21B0Item;

typedef struct {
    u8 pad0[0x10];
    Unk21B0Item items[8];
    u8 pad2910[0x258];
    s32 unk2B68;
    s32 unk2B6C;
    s32 unk2B70;
} Unk21B0Block;

typedef struct {
    u8 pad0[0x30B0];
    Unk21B0Block unk30B0;
} Unk21B0Work;

extern s32 D_01B00D2C;
extern u8 D_01B01F38;
extern Unk21B0Work *D_01B0B398;

extern void func_01B01CE8(void *);
extern void func_01B02170(Unk21B0Item *, s32);
extern void func_01B03E00(float *);
extern void func_01B03E48(void);
extern void func_01B04A88(s32, float *, s32);
extern Unk21B0Task *func_01B07000(void *);
extern void func_01B071C8(Unk21B0Task *);
extern void func_01B080C8(void *, float *, float *);
extern float func_01B08270(float *, float *);

void func_01B021B0(void) {
    float pos[4];
    Unk21B0Block *blk = &D_01B0B398->unk30B0;
    Unk21B0Item *item = blk->items;
    s32 count = D_01B00D2C;
    s32 i;

    func_01B03E00(pos);

    for (i = 0; i < count; i++, item++) {
        Unk21B0Task *task;
        MMI_COPY_LQ_A3(item->unk260, pos);
        MMI_COPY_SQ_A3(item->unk260);
        func_01B04A88(i, item->unk270, 4);
        func_01B080C8(item->unk280, item->unk260, item->unk270);
        item->unk510 = (s32)(func_01B08270(item->unk260, item->unk270) / 6.0f);
        if (item->unk510 < 0) {
            item->unk510 = 1;
        }
        item->unk514 = item->unk510;
        {
            s32 kind = blk->unk2B68;
            if (kind == 0) {
                func_01B01CE8(item->unk2C0);
            } else {
                func_01B02170(item, kind);
                MMI_COPY_LQ_A3(item->unkC0, item->unk280);
                MMI_COPY_SQ_A3(item->unkC0);
            }
        }
        item->unk518 = i;
        task = func_01B07000(&D_01B01F38);
        task->unk14 = item;
        func_01B071C8(task);
    }

    blk->unk2B6C = count;
    blk->unk2B70 = 0;
    func_01B03E48();
}
