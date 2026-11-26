#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x20];
    union {
        u32 w;
        u8 b[4];
    } unk024;           /* 0x024 */
    u8 pad028[0xc0];
    u32 unk0e8;         /* 0x0e8 */
    u8 pad0ec[0x4b];
    u8 unk137;          /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13c = 316 */

typedef struct QueueEntry {
    Track *trk;         /* 0x00 */
    u32 w;              /* 0x04 */
} QueueEntry; /* size 8 */

extern s32 D_01874C;
extern s32 D_018724;

void func_002D50(QueueEntry *q, Track *trk) {
    QueueEntry *e;

    if (trk->unk024.b[2] & 0x11) {
        e = &q[trk->unk137];
        if (e->trk == NULL || e->trk == trk) {
            e->trk = trk;
            *(u32 *)((u8 *)e + 4) = trk->unk024.w;
            D_01874C++;
        }
    } else if (trk->unk024.b[2] & 0x20) {
        e = q + 48;
        while (e->trk != NULL) {
            if (++e >= q + 96) {
                goto done;
            }
        }
        if (e < q + 96) {
            e->trk = trk;
            *(u32 *)((u8 *)e + 4) = trk->unk024.w;
            D_01874C++;
        }
    } else {
        e = q + 96;
        while (e->trk != NULL) {
            if (++e >= q + 144) {
                goto done;
            }
        }
        if (e < q + 144) {
            e->trk = trk;
            *(u32 *)((u8 *)e + 4) = trk->unk024.w;
            D_01874C++;
        }
    }
done:
    D_018724++;
    trk->unk0e8 |= 1;
}
