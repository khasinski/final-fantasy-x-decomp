#include "iopsound.h"

extern s32 D_01871C;
extern u8 *D_01936C;

typedef struct {
    u8 pad0[0x13c];
} Track316;

typedef struct {
    Track316 *tracks;
    u8 pad4[4];
    s32 field_08;
    u8 padC[906 - 12];
    s16 active;
    u8 pad38C;
    u8 num_tracks;
    u8 pad38E[2];
} SeqSlot;

s32 func_010A58(s32 *arg) {
    SeqSlot *slot = (SeqSlot *)D_01936C;
    SeqSlot *end = slot + 2;

    D_01871C = *arg;
    do {
        if (slot->active != 0) {
            Track316 *tr = slot->tracks;
            do {
                *(s32 *)((u8 *)tr + 32) = D_01871C ? slot->field_08 : 0;
                tr++;
            } while (tr < slot->tracks + slot->num_tracks);
        }
        slot++;
    } while (slot < end);
    return *arg;
}
