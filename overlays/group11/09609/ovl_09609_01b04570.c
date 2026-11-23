#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x22C];
    s32 unk22C;
} Unk4570Sub;

typedef struct {
    u8 pad0[0xD0];
    float unkD0[4];
    u8 padE0[0x180];
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x30];
    Unk4570Sub unk2C0;
    u8 pad4F0[0x20];
    s32 unk510;
    s32 unk514;
} Unk4570Item;

typedef struct {
    u8 pad0[0x14];
    Unk4570Item *unk14;
} Unk4570Task;

typedef struct {
    u8 pad0[0x2B68];
    s32 unk2B68;
    s32 unk2B6C;
    s32 unk2B70;
} Unk4570Block;

typedef struct {
    u8 pad0[0x30B0];
    Unk4570Block unk30B0;
} Unk4570Work;

extern u8 D_01B0DEB0;
extern Unk4570Work *D_01B0DF78;

extern void func_002DD128(float (*)[4]);
extern void func_01B04188(s32, float *);
extern void func_01B04478(Unk4570Item *, float *, s32);
extern void func_01B06AC0(Unk4570Sub *, float (*)[4], float *);
extern void func_01B06FA8(float *, float *, s32);
extern void func_01B09C38(Unk4570Task *);
extern void func_01B0A388(void *, void *);

void func_01B04570(Unk4570Task *task) {
    float mat[4][4];
    float pos[4];
    Unk4570Item *item = task->unk14;
    Unk4570Block *blk = &D_01B0DF78->unk30B0;
    Unk4570Sub *sub = &item->unk2C0;

    if (item->unk510 > 0) {
        item->unk510--;
    }
    if (item->unk510 >= 0) {
        float t = (float)item->unk510 / (float)item->unk514;
        float u = 1.0f - t;
        register float *p280 __asm__("$21");
        s32 i;

        for (i = 0; i < 3; i++) {
            pos[i] = item->unk270[i] * u + item->unk260[i] * t;
        }
        pos[3] = 1.0f;
        func_01B04188(blk->unk2B68, pos);
        p280 = item->unk280;
        func_01B06FA8(p280, pos, 0x80);
        MMI_COPY_LQ_A3(item->unkD0, pos);
        MMI_COPY_SQ_A3(item->unkD0);
        if (item->unk510 == 0) {
            register s32 mode __asm__("$3");
            func_01B04478(item, p280, blk->unk2B68);
            func_01B0A388(&D_01B0DEB0, item);
            mode = blk->unk2B68;
            if (mode != 0) {
                blk->unk2B70++;
                func_01B09C38(task);
                return;
            }
            item->unk510--;
        }
    } else {
        if (sub->unk22C <= 0) {
            blk->unk2B70++;
            func_01B09C38(task);
            return;
        }
        sub->unk22C--;
        MMI_COPY_LQ_A3(pos, item->unk270);
        MMI_COPY_SQ_A3(pos);
    }

    if (blk->unk2B68 == 0) {
        func_002DD128(mat);
        mat[2][2] = 0.2f;
        mat[1][1] = 0.2f;
        mat[0][0] = 0.2f;
        func_01B06AC0(sub, mat, pos);
    }
}
