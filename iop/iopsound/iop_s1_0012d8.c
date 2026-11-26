#include "iopsound.h"

typedef struct Track Track;
typedef struct Voice Voice;
typedef struct Tone Tone;

struct Tone {
    u32 flags;          /* 0x00 */
    u8 pad04[0x1c];     /* 0x04 */
}; /* size 0x20 = 32 */

struct Voice {
    Track *trk;         /* 0x00 */
    Tone *tone;         /* 0x04 */
    u8 pad08[0x0e];     /* 0x08 */
    u8 unk16;           /* 0x16 */
    u8 pad17[0x41];     /* 0x17 */
    u16 voice_id;       /* 0x58 */
    u8 pad5a[0x16];     /* 0x5a */
    s16 envx;           /* 0x70 */
    s16 unk72;          /* 0x72 */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_0012D8(void) {
    Voice *v = D_0192F0;

    do {
        if (v->unk16 & 0x13) {
            v->envx = 0x7fff;
        } else if (v->envx > 0) {
            v->envx = imp_libsd_6(v->voice_id | 0x500);
            if (v->envx <= 0) {
                v->trk = NULL;
            } else if (v->tone->flags & 0x10) {
                s32 nax = imp_libsd_10(v->voice_id | 0x2240);
                s32 lsax = imp_libsd_10(v->voice_id | 0x2140);
                s32 next = lsax + 0x2000;
                if (nax >= lsax && nax < next) {
                    imp_libsd_9(v->voice_id | 0x2140, next);
                }
            }
        }
        v++;
    } while (v < D_0192F0 + 48);
}
