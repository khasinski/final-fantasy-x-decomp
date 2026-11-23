/* Shared ring-buffer slot allocator (156 B, 64 containers). */

#include "common.h"

typedef struct {
    u8 pad00[0x40];
    float f40;
    int pad44;
    float w48;
    u8 pad4C[0x08];
    int w54;
    int w58;
    int pad5C;
    int w60;
    u32 w64;
    u32 w68;
    int active;
    u16 h70;
    u8 pad72[0x0E];
} OvlSlot5E10;

extern OvlSlot5E10 *g_pool;
extern int g_idx;
extern int g_count;

OvlSlot5E10 *ovl_09176_5e10(void)
{
    int i;
    int idx = g_idx;

    for (i = 0; i < g_count; i++) {
        OvlSlot5E10 *p = &g_pool[idx++];
        if (idx >= g_count) {
            idx = 0;
        }
        if (p->active == 0) {
            p->w64 = 0x80808080U;
            p->w68 = 0x80808080U;
            p->f40 = 1.0f;
            p->w60 = 0;
            p->w54 = 0;
            p->w58 = 0;
            p->active = 1;
            g_idx = idx;
            p->h70 = 0;
            p->w48 = 0.0f;
            return p;
        }
    }
    return 0;
}
