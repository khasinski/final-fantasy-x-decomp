#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0xD0];
    float unkD0[4];
    u8 padE0[0x180];
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
} Unk4B80Item;

typedef struct {
    u8 pad0[0x14];
    Unk4B80Item *unk14;
} Unk4B80Task;

typedef struct {
    u8 pad0[0x2904];
    s32 unk2904;
    s32 unk2908;
    s32 unk290C;
} Unk4B80Block;

typedef struct {
    u8 pad0[0x5C30];
    Unk4B80Block unk5C30;
} Unk4B80Work;

extern u8 D_01B0DEB0;
extern Unk4B80Work *D_01B0DF78;

extern void func_01B04A88(Unk4B80Item *, float *, s32);
extern void func_01B06FA8(float *, float *, s32);
extern void func_01B09C38(Unk4B80Task *);
extern void func_01B0A388(void *, void *);

void func_01B04B80(Unk4B80Task *task) {
    float pos[4];
    Unk4B80Item *item = task->unk14;
    Unk4B80Block *blk = &D_01B0DF78->unk5C30;
    register float *p280 __asm__("$18");
    float t;
    float u;
    s32 i;

    if (item->unk510 > 0) {
        item->unk510--;
    }
    t = (float)item->unk510 / (float)item->unk514;
    u = 1.0f - t;
    p280 = item->unk280;
    for (i = 0; i < 3; i++) {
        pos[i] = item->unk270[i] * u + item->unk260[i] * t;
    }
    pos[3] = 1.0f;
    func_01B06FA8(p280, pos, 0x80);
    MMI_COPY_LQ_A3(item->unkD0, pos);
    MMI_COPY_SQ_A3(item->unkD0);
    if (item->unk510 <= 0) {
        register s32 c __asm__("$3");
        func_01B04A88(item, p280, blk->unk2904);
        func_01B0A388(&D_01B0DEB0, item);
        c = blk->unk290C;
        blk->unk290C = c + 1;
        func_01B09C38(task);
    }
}
