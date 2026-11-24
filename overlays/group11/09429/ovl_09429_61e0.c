#include "common.h"

typedef struct {
    u8 pad00[0x20];
    float f20;
    u8 pad24[0x8];
    float f2C;
    u8 pad30[0x10];
    s32 w40;
    s32 w44;
    u8 pad48[0xC];
    s32 w54;
    u32 w58;
    u32 w5C;
    s32 w60;
    s16 h64;
    u8 pad66[0xA];
} Entry70;

extern Entry70 *D_01B0B5FC;
extern s32 D_01B0B600;
extern s32 D_01B0B604;

Entry70 *ovl_09429_61e0(void)
{
    s32 i;
    s32 idx = D_01B0B600;

    for (i = 0; i < D_01B0B604; i++) {
        Entry70 *e = &D_01B0B5FC[idx];
        idx++;
        if (idx >= D_01B0B604) {
            idx = 0;
        }
        if (e->w60 == 0) {
            e->w58 = 0x80808080;
            e->w5C = 0x80808080;
            e->w54 = 0;
            e->w40 = 0;
            e->w44 = 0;
            e->f20 = 1.0f;
            e->h64 = 0;
            e->f2C = 0.0f;
            e->w60 = 1;
            D_01B0B600 = idx;
            return e;
        }
    }
    return 0;
}
