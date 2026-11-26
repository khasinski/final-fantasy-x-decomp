#include "iopsound.h"

typedef struct Track {
    u8 pad000[0x26];
    u8 unk026;          /* 0x026 */
    u8 pad027[0x110];
    u8 unk137;          /* 0x137 */
    u8 pad138[0x04];
} Track;

typedef struct Seq {
    u8 pad000[0x384];
    u32 unk384;         /* 0x384 */
    u8 pad388[0x04];
    s8 unk38c;          /* 0x38c */
    u8 pad38d[3];
} Seq;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x6c];
    s16 env;            /* 0x70 */
    u8 pad72[2];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern Seq *D_019374;

Voice *func_001140(Track *trk) {
    Voice *best = NULL;
    Voice *v;

    if (trk->unk026 & 0x11) {
        if ((trk->unk026 & 1) || D_0192F0[trk->unk137].trk == NULL || D_0192F0[trk->unk137].trk == trk) {
            v = &D_0192F0[trk->unk137];
        } else {
            v = NULL;
        }
    } else {
        u32 min_env;

        if (trk->unk026 & 0x20) {
            v = D_0192F0;
        } else {
            v = &D_0192F0[D_019374->unk38c];
        }
        min_env = 0x7fff;
        do {
            if (v->env <= 0) {
                break;
            }
            if ((u32)v->env < min_env) {
                best = v;
                min_env = v->env;
            }
            v++;
        } while (v < D_0192F0 + 48);
        if (v == D_0192F0 + 48) {
            D_019374->unk384 |= 2;
            if (min_env != 0x7fff) {
                v = best;
            } else {
                v = NULL;
            }
        }
    }
    if (v != NULL) {
        v->env = 0x7fff;
    }
    return v;
}
