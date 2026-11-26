#include "iopsound.h"

typedef struct Voice Voice;
typedef struct Tone Tone;

struct Tone {
    u32 flags;          /* 0x00 */
    u8 pad04[0x10];     /* 0x04 */
    s8 key_max;         /* 0x14 */
    u8 vel_max;         /* 0x15 */
    u8 pad16[0x0a];     /* 0x16 */
}; /* size 0x20 = 32 */

struct Voice {
    u8 pad00[0x4c];     /* 0x00 */
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x0c];     /* 0x50 */
    u32 voice_bit;      /* 0x5c */
    u8 pad60[0x14];     /* 0x60 */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_0019D0(Voice *v) {
    u32 pmon, non, vmixl, vmixr, vmixel, vmixer;
    Voice *end = D_0192F0 + 24;

    pmon = non = vmixl = vmixr = vmixel = vmixer = 0;
    do {
        if (v->unk4c & 0x100) {
            pmon |= v->voice_bit;
        }
        if (v->unk4c & 0x200) {
            if (!(v->unk4c & 0x10)) {
                non |= v->voice_bit;
            }
        }
        if (!(v->unk4c & 0x28)) {
            if (v->unk4c & 0x400) {
                vmixl |= v->voice_bit;
            }
            if (v->unk4c & 0x800) {
                vmixr |= v->voice_bit;
            }
            if (v->unk4c & 0x1000) {
                vmixel |= v->voice_bit;
            }
            if (v->unk4c & 0x2000) {
                vmixer |= v->voice_bit;
            }
        }
        v++;
    } while (v < end);

    imp_libsd_7(0x1400, pmon);
    imp_libsd_7(0x1300, non);
    imp_libsd_7(0x1800, vmixl);
    imp_libsd_7(0x1a00, vmixr);
    imp_libsd_7(0x1900, vmixel);
    imp_libsd_7(0x1b00, vmixer);

    pmon = non = vmixl = vmixr = vmixel = vmixer = 0;
    end = D_0192F0 + 48;
    do {
        if (v->unk4c & 0x100) {
            pmon |= v->voice_bit;
        }
        if (v->unk4c & 0x200) {
            if (!(v->unk4c & 0x10)) {
                non |= v->voice_bit;
            }
        }
        if (!(v->unk4c & 0x28)) {
            if (v->unk4c & 0x400) {
                vmixl |= v->voice_bit;
            }
            if (v->unk4c & 0x800) {
                vmixr |= v->voice_bit;
            }
            if (v->unk4c & 0x1000) {
                vmixel |= v->voice_bit;
            }
            if (v->unk4c & 0x2000) {
                vmixer |= v->voice_bit;
            }
        }
        v++;
    } while (v < end);

    imp_libsd_7(0x1401, pmon);
    imp_libsd_7(0x1301, non);
    imp_libsd_7(0x1801, vmixl);
    imp_libsd_7(0x1a01, vmixr);
    imp_libsd_7(0x1901, vmixel);
    imp_libsd_7(0x1b01, vmixer);
}

Tone *func_001C70(Tone *tone, s8 *note_vel) {
    s8 key;

    if (tone->flags & 0x30000) {
        for (;;) {
            if ((tone->flags & 0x200) || note_vel[0] <= tone->key_max) {
                break;
            }
            if (tone->flags & 1) {
                tone++;
            }
            tone++;
        }
        key = tone->key_max;
        for (;;) {
            if ((tone->flags & 0x200) || note_vel[1] <= tone->vel_max || key != tone->key_max) {
                break;
            }
            if (tone->flags & 1) {
                tone++;
            }
            tone++;
        }
    }
    return tone;
}
