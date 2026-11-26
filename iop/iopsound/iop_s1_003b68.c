#include "iopsound.h"

typedef struct Track Track;
typedef struct Bank Bank;
typedef struct BankSlot BankSlot;

struct Bank {
    u8 pad00[0x10];     /* 0x00 */
    s32 unk10;          /* 0x10 */
    u8 pad14[0x0c];     /* 0x14 */
    u32 unk20[1];       /* 0x20 */
};

struct BankSlot {
    u8 pad00[0x0c];     /* 0x00 */
    Bank *bank;         /* 0x0c */
    s32 unk10;          /* 0x10 */
    s32 unk14;          /* 0x14 */
}; /* size 0x18 = 24 */

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x18];    /* 0x004 */
    void *unk01c;       /* 0x01c */
    u8 pad020[0xa4];    /* 0x020 */
    s32 unk0c4;         /* 0x0c4 */
    s32 unk0c8;         /* 0x0c8 */
    u8 pad0cc[0x3c];    /* 0x0cc */
    s32 unk108;         /* 0x108 */
    u8 pad10c[0x29];    /* 0x10c */
    u8 unk135;          /* 0x135 */
    u8 unk136;          /* 0x136 */
};

extern BankSlot *D_019308;

void func_003B68(void *seq, void *q, Track *trk) {
    u32 slot = *trk->ptr++;
    u32 prog = *trk->ptr++;

    if (D_019308[slot].unk10 != 0) {
        Bank *bank = D_019308[slot].bank;
        trk->unk01c = (u8 *)bank + bank->unk20[prog];
        trk->unk108 = bank->unk10;
        trk->unk0c4 = -1;
        trk->unk0c8 = -1;
    } else {
        trk->unk108 = 0;
    }
    trk->unk135 = slot;
    trk->unk136 = prog;
}
