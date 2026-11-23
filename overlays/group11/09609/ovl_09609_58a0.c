#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk04;
} Unk58A0Targets;

typedef struct {
    u8 pad0[0x5200];
    s32 unk5200;
    s32 unk5204;
    s32 unk5208;
    s32 unk520C;
    s32 unk5210;
} Unk58A0Block;

typedef struct {
    u8 pad0[0x8550];
    Unk58A0Block unk8550;
    u8 padD764[0xECA4 - 0xD764];
    Unk58A0Targets *unkECA4;
} Unk58A0Work;

extern Unk58A0Work *D_01B0DF78;
extern void func_01B069F0(void);

void func_01B058A0(void) {
    Unk58A0Work *work = D_01B0DF78;
    Unk58A0Block *blk = &work->unk8550;
    s32 cnt;

    if (blk->unk5208 == 1) {
        func_01B069F0();
    }
    blk->unk5200 = 0;
    blk->unk5204 = 0;
    cnt = work->unkECA4->unk04;
    blk->unk5210 = 0;
    blk->unk520C = cnt;
}
