#include "iopsound.h"

typedef struct Bank {
    u8 pad00[0x08];
    u32 num_tones;      /* 0x08 */
    u8 pad0c[0x04];
    u32 spu_addr;       /* 0x10 */
    u8 pad14[0x0c];
    u32 tone_off[1];    /* 0x20 */
} Bank;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x14];
    Bank *bank;         /* 0x018 */
    void *unk01c;       /* 0x01c */
    u8 pad020[0xa4];
    s32 adsr_ov[2];     /* 0x0c4 */
    u8 pad0cc[0x3c];
    u32 bank_addr;      /* 0x108 */
    u8 pad10c[0x29];
    u8 unk135;          /* 0x135 */
    u8 unk136;          /* 0x136 */
} Track;

typedef struct Seq {
    u8 pad000[0x384];
    u32 unk384;         /* 0x384 */
} Seq;

void func_003AE4(Seq *seq, void *q, Track *trk) {
    u32 prog = *trk->ptr++;

    if (trk->bank != NULL) {
        if (prog < trk->bank->num_tones) {
            trk->unk01c = (u8 *)trk->bank + trk->bank->tone_off[prog];
            trk->bank_addr = trk->bank->spu_addr;
            trk->adsr_ov[0] = -1;
            trk->adsr_ov[1] = -1;
        } else {
            trk->unk01c = NULL;
            seq->unk384 |= 1;
        }
    } else {
        trk->bank_addr = 0;
    }
    trk->unk135 = 16;
    trk->unk136 = prog;
}
