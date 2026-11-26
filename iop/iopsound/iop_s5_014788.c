#include "iopsound.h"

typedef struct {
    u8 pad00[0x370];
    u32 f370;
    s32 f374;
    u8 pad378[0x12];
    s16 f38a;
    u8 pad38c[0x04];
} S_MusicSlot; /* size 0x390 = 912 */

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
} S_122460;

extern s32 D_01937C;
extern S_MusicSlot *D_01936C;
extern u8 *D_018FB4;
extern S_122460 D_122460;
extern s32 D_019378;
extern s32 D_019310;

extern void func_00F038(s32);
extern void func_00F084(s32);
extern void func_00C43C(void *);
extern s32 func_00C564(s32);

void func_014788(void) {
    while (1) {
        S_MusicSlot *slot;
        u8 *buf;
        imp_thsemap_8(D_01937C);
        func_00F038(8);
        slot = D_01936C;
        buf = D_018FB4;
        if (slot->f38a != 0 && slot->f374 == *(s16 *)(buf + 4)) {
            if (slot->f370 & 0x10000) {
                slot->f370 |= 0x20000;
            }
        }
        slot++;
        if (slot->f38a != 0 && slot->f374 == *(s16 *)(buf + 4)) {
            S_122460 *p122460 = &D_122460;
            if (p122460->f08 != 0 || (slot->f370 & 0x10000)) {
                slot->f370 |= 0x20000;
            }
        }
        func_00C43C(D_018FB4);
        func_00F084(8);
    }
}

void func_01488C(void) {
    while (1) {
        S_MusicSlot *slot;
        imp_thsemap_8(D_019378);
        func_00F038(9);
        slot = D_01936C;
        if (slot->f38a != 0 && slot->f374 == D_019310) {
            if (slot->f370 & 0x10000) {
                slot->f370 |= 0x20000;
            }
        }
        slot++;
        if (slot->f38a != 0 && slot->f374 == D_019310) {
            S_122460 *p122460 = &D_122460;
            if (p122460->f08 != 0 || (slot->f370 & 0x10000)) {
                slot->f370 |= 0x20000;
            }
        }
        while (func_00C564(D_019310) < 0) {
        }
        func_00F084(9);
    }
}
