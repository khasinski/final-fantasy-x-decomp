#include "iopsound.h"

typedef struct Track Track;
typedef struct Voice Voice;
typedef struct Tone Tone;

struct Tone {
    u32 flags;          /* 0x00 */
    u8 pad04[0x1c];     /* 0x04 */
}; /* size 0x20 = 32 */

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x18];    /* 0x004 */
    Tone *unk01c;       /* 0x01c */
    u8 pad020[0x06];    /* 0x020 */
    u8 unk026;          /* 0x026 */
    u8 pad027[0xc9];    /* 0x027 */
    u32 flags;          /* 0x0f0 */
};

struct Voice {
    Track *trk;         /* 0x00 */
    Tone *tone;         /* 0x04 */
    u8 pad08[0x44];     /* 0x08 */
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x24];     /* 0x50 */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern u32 D_01931C;

extern Voice *func_001140(Track *);
extern Tone *func_001C70(Tone *, void *);
extern void func_001D20(Track *, Voice *, void *, void *);

Voice *func_002468(Track *trk, void *a1, void *a2) {
    Voice *v;

    if (trk->flags & 0x80000) {
        v = D_0192F0;
        while (v->trk != trk) {
            v++;
            if (v >= D_0192F0 + 48) {
                break;
            }
        }
        if (v >= D_0192F0 + 48) {
            v = func_001140(trk);
        }
    } else {
        v = func_001140(trk);
    }

    if (v != NULL) {
        Tone *tone;

        v->tone = func_001C70(trk->unk01c, a1);
        func_001D20(trk, v, a1, a2);
        tone = v->tone;
        if ((tone->flags & 1) && !(trk->unk026 & 0x11)) {
            v->unk4c |= 0x40;
            v = func_001140(trk);
            if (v != NULL) {
                v->tone = tone + 1;
                v->unk4c |= 0x80;
                func_001D20(trk, v, a1, a2);
            }
        }
        (*(volatile u32 *)&D_01931C) |= 1;
    }
    return v;
}
