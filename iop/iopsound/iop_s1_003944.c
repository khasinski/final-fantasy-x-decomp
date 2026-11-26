#include "iopsound.h"

typedef struct Track Track;

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x20];    /* 0x004 */
    u8 unk024;          /* 0x024 */
    u8 unk025;          /* 0x025 */
};

extern void func_002D50(void *, Track *);
extern void func_002E70(void *, Track *);

void func_003944(void *seq, void *q, Track *trk) {
    func_002D50(q, trk);
}

void func_003968(void *seq, void *q, Track *trk) {
    trk->unk024 = *trk->ptr++;
    trk->unk025 = *trk->ptr++;
    func_002D50(q, trk);
}

void func_0039B0(void *seq, void *q, Track *trk) {
    trk->unk024 = *trk->ptr++;
    func_002D50(q, trk);
}

void func_0039E8(void *seq, void *q, Track *trk) {
    trk->unk025 = *trk->ptr++;
    func_002D50(q, trk);
}

void func_003A20(void *seq, void *q, Track *trk) {
    func_002E70(q, trk);
}

void func_003A44(void *seq, void *q, Track *trk) {
    u8 n = *trk->ptr;

    trk->ptr += 2;
    trk->unk024 = n;
    func_002E70(q, trk);
}

void func_003A7C(void *seq, void *q, Track *trk) {
    trk->unk024 = *trk->ptr++;
    func_002E70(q, trk);
}

void func_003AB4(void *seq, void *q, Track *trk) {
    trk->ptr++;
    func_002E70(q, trk);
}
