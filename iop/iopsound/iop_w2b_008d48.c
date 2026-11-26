#include "iopsound.h"

typedef struct SeqHeader {
    u8 pad00[6];
    s16 wave_id;
} SeqHeader;

typedef struct SeqSlot {
    s32 unk00;
    s32 id;
    s32 unk08;
    SeqHeader *data;
    s32 unk10;
    s32 unk14;
} SeqSlot; /* size 0x18 = 24 */

typedef struct SeqCtrl {
    u8 pad000[0x370];
    u32 flags;
    s32 id;
} SeqCtrl;

extern SeqSlot *D_019338;
extern SeqCtrl *D_01936C;

extern void func_00C1C8(s32, s32);
extern void *func_006CC0(s32);
extern void func_008AC4(s32);
extern void func_008824(SeqHeader *, void *, s32, s32);

s32 func_008D48(s32 seq_id, s32 arg1) {
    SeqSlot *slot;
    SeqHeader *hdr;
    void *wave;
    SeqCtrl *ctrl;

    slot = D_019338;
    while (slot->id != seq_id) {
        if (++slot >= D_019338 + 2) {
            return 0;
        }
    }

    if (slot < D_019338 + 2) {
        func_00C1C8(2, seq_id);
        hdr = slot->data;
        wave = func_006CC0(hdr->wave_id);
        if (wave == NULL) {
            return -1;
        }
        ctrl = D_01936C;
        if (ctrl->id != -1) {
            func_008AC4(ctrl->id);
        }
        ctrl->id = seq_id;
        ctrl->flags &= ~0x10000;
        func_008824(hdr, wave, seq_id, arg1);
    }

    return 0;
}
