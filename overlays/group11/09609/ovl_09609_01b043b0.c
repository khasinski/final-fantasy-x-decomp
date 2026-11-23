#include "common.h"

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
    u8 padE0[0x4];
    float unkE4;
    float unkE8;
    u8 padEC[0x44];
} Unk43B0Item; /* size 0x130 */

typedef struct {
    u8 pad0[0x2B60];
    void *unk2B60;
    s32 unk2B64;
    s32 unk2B68;
} Unk43B0Block;

typedef struct {
    Unk43B0Item items[41];
    u8 pad30B0[0x30B0 - 41 * 0x130];
    Unk43B0Block unk30B0;
    u8 pad5C1C[0xEC00 - 0x5C1C];
    float unkEC00;
} Unk43B0Work;

extern s32 D_01B00B48[];
extern u8 D_01B0DEB0;
extern Unk43B0Work *D_01B0DF78;

extern void func_01B069A8(float *);
extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);
extern void func_01B0A388(void *, void *);

void func_01B043B0(void) {
    register Unk43B0Work *work __asm__("$17") = D_01B0DF78;
    Unk43B0Block *blk = &work->unk30B0;
    s32 id;
    Unk43B0Item *item;

    func_01B0A388(&D_01B0DEB0, blk->unk2B60);
    id = D_01B00B48[blk->unk2B68];
    item = &work->items[id];
    func_01B09F18(&D_01B0DEB0, item, id, 0, 0, 0, 0.2f);
    func_01B069A8(item->unkD0);
    item->unkC4 = work->unkEC00;
    item->unkE4 = 3.0f;
    item->unkE8 = -3.0f;
}
