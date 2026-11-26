#include "iopsound.h"

typedef struct {
    u8 pad00[0x1c];
    s32 f1c;
    u8 pad20[0x354];
    s32 f374;
    u8 pad378[0x18];
} S_MusicSlot; /* size 0x390 = 912 */

typedef struct {
    S_MusicSlot slot[2];
} S_01936C;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    u8 *f0c;
    s32 f10;
    s32 f14;
} S_WaveInfo; /* size 24 */

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    u8 *f0c;
    s32 f10;
    s32 f14;
} S_MusicInfo; /* size 24 */

typedef s32 (*CmdFunc)(void *);
typedef s32 (*RpcFunc)(void *, s32);

extern S_01936C *D_01936C;
extern S_WaveInfo *D_019308;
extern S_MusicInfo *D_019338;
extern u8 *D_018FB0;
extern u8 *D_018FAC;
extern u8 *D_018FA8;
extern CmdFunc D_0190BC[];
extern RpcFunc D_019014[];
extern CmdFunc D_0190B4[];
typedef struct {
    s32 buf[32];
    s32 *ptr;
} S_WaveQueue;

extern S_WaveQueue D_06CE70;

extern char D_0165F0[];
extern char D_01687C[];
extern char D_0169F0[];
extern char D_016A1C[];
extern char D_016A6C[];
extern char D_016ABC[];
extern char D_016B0C[];
extern char D_016B5C[];

extern s32 func_009BB0(s32);
extern void func_009B74(void *);
extern s32 func_0105F4(void *, s32);
extern s32 func_012504(void *);
extern s32 func_011070(void *);

s32 func_013B80(void) {
    S_MusicInfo *m;
    s32 total = 0;

    imp_sysmem_14(D_0169F0, D_0165F0);
    imp_sysmem_14(D_016A1C, D_0165F0);
    for (m = D_019338; m < D_019338 + 2; m++) {
        if (m->f10 != 0) {
            s32 wave_idx = func_009BB0(*(s16 *)(m->f0c + 6));
            S_01936C *drv = D_01936C;
            if (m->f04 == drv->slot[0].f374 || m->f04 == drv->slot[1].f374) {
                S_MusicSlot *slot = (m->f04 == drv->slot[0].f374) ? &drv->slot[0] : &drv->slot[1];
                if (wave_idx < 0) {
                    imp_sysmem_14(D_016A6C, D_0165F0, m->f04, *(s16 *)(m->f0c + 6),
                                  m->f0c, m->f10, m->f08, slot->f1c >> 13);
                } else {
                    imp_sysmem_14(D_016ABC, D_0165F0, m->f04, *(s16 *)(m->f0c + 6),
                                  m->f0c, m->f10, m->f08, slot->f1c >> 13);
                }
            } else {
                if (wave_idx < 0) {
                    imp_sysmem_14(D_016B0C, D_0165F0, m->f04, *(s16 *)(m->f0c + 6),
                                  m->f0c, m->f10, m->f08);
                } else {
                    imp_sysmem_14(D_016B5C, D_0165F0, m->f04, *(s16 *)(m->f0c + 6),
                                  m->f0c, m->f10, m->f08);
                }
            }
            total++;
        }
    }
    imp_sysmem_14(D_01687C, D_0165F0, D_0165F0, total);
    return total;
}

void func_013D8C(void) {
    while (D_018FB0 != D_018FAC) {
        CmdFunc fn = D_0190BC[*(s32 *)D_018FB0];
        fn(D_018FB0 + 4);
        if (D_0190BC[*(s32 *)D_018FB0] == func_012504) {
            D_018FB0 += 128;
        } else if (D_0190BC[*(s32 *)D_018FB0] == func_011070) {
            D_018FB0 += 64;
        } else {
            D_018FB0 += 32;
        }
        if (D_018FB0 >= D_018FA8 + 8448) {
            D_018FB0 -= 8448;
        }
    }
}

