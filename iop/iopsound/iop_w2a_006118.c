#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
} Track;

u32 func_006118(Track *trk) {
    u32 val = 0;

    if (trk != NULL) {
        val = *trk->ptr & 0x7f;
        while (*trk->ptr & 0x80) {
            val <<= 7;
            trk->ptr++;
            val |= *trk->ptr & 0x7f;
        }
        trk->ptr++;
    }
    return val;
}
