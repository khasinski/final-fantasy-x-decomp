#include "p1_overlay.h"

typedef struct P1PartHdr {
    s8 b0;
    s8 term;            /* -1 ends the list */
    s16 count;
    u8 pad4[0x1C];
} P1PartHdr;

typedef struct P1ModelRef {
    u8 *data;
    u8 pad4[0xC];
} P1ModelRef;

struct P1Model {
    u8 pad0[4];
    u16 count;
    u8 pad6[0xA];
    P1ModelRef ref[1];
};

int func_01B08988(struct P1Model *m)
{
    int size = 0;
    int i;
    P1ModelRef *ref = m->ref;

    for (i = 0; i < m->count; ref++, i++) {
        P1PartHdr *h = (P1PartHdr *)(ref->data + 32);
        while (h->term != -1) {
            size += h->count * 768;
            h = (P1PartHdr *)((u8 *)h + (h->count * 28 + 32));
        }
    }
    return size + 64;
}
