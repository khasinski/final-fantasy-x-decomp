#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x20];
    s8 note;            /* 0x024 */
    u8 pad025[0xc3];
    u32 unk0e8;         /* 0x0e8 */
    u8 pad0ec[0x04];
    u32 flags;          /* 0x0f0 */
    u8 pad0f4[0x08];
    s32 porta_cnt;      /* 0x0fc */
} Track;

typedef struct QueueEntry {
    Track *trk;         /* 0x00 */
    s8 note;            /* 0x04 */
    u8 pad05[3];
} QueueEntry; /* size 8 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x10];
    s8 note;            /* 0x14 */
    u8 pad15[0x37];
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x24];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_002E70(QueueEntry *q, Track *trk) {
    if (!(trk->flags & 0x80000)) {
        u8 unote = *(u8 *)&trk->note;
        QueueEntry *e = q;
        Voice *v;

        trk->porta_cnt = 0;
        {
            s8 snote = trk->note;
            do {
                if (e->trk == trk && e->note == snote) {
                    e->trk = NULL;
                }
                e++;
            } while (e < q + 144);
        }

        v = D_0192F0;
        do {
            if (v->trk == trk && v->note == (s8)unote) {
                v->unk4c |= 2;
            }
            v++;
        } while (v < D_0192F0 + 48);

        trk->unk0e8 &= ~1;
    }
}
