#include "iopsound.h"

typedef struct Tone {
    u8 pad00[0x0c];
    u32 adsr;           /* 0x0c */
} Tone;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xc0];
    s32 adsr_ov[2];     /* 0x0c4 */
} Track;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    Tone *tone;         /* 0x04 */
    u8 pad08[0x50];
    u16 voice_id;       /* 0x58 */
    u16 unk5a;          /* 0x5a */
    u32 voice_bit;      /* 0x5c */
    u32 adsr;           /* 0x60 */
    u8 pad64[0x10];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_003FA8(void *seq, void *q, Track *trk) {
    Voice *v;

    *(s32 *)((u8 *)trk + 0xc4) = -1;
    trk->adsr_ov[1] = -1;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr = v->tone->adsr;
            imp_libsd_5(v->voice_id | 0x300, *(u16 *)&v->adsr);
            imp_libsd_5(v->voice_id | 0x400, v->adsr >> 16);
        }
        v++;
    } while (v < D_0192F0 + 48);
}
