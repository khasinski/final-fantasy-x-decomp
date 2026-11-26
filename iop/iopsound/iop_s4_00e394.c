#include "iopsound.h"

extern void func_00C938(s32, s32);
extern void func_00D014(s32, void *);
extern void func_00EFBC(s32, s32);

extern char D_016418[];
extern char D_016444[];
extern char D_016458[];
extern char D_016460[];
extern char D_0164A8[];
extern char D_0164B0[];
extern char D_0164F4[];

extern s32 D_018720;
extern s32 D_018724;
extern u8 *D_018754;
extern u8 *D_0192F0;
extern s32 D_019350;
extern u8 D_06D3F0[];
extern u8 D_09E3F0[];

typedef struct {
    u8 *f0;
    u8 pad4[8];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
    u8 pad20[16];
    s32 f30;
    s32 f34;
    s32 f38;
    u8 *f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    u16 f68;
    u16 f6A;
    s32 f6C;
} StreamInfo;

typedef struct {
    u8 pad0[76];
    s32 f4C;
    u8 pad50[8];
    u16 f58;
    u8 pad5A[116 - 0x5A];
} VoiceInfo;

void func_00E394(s32 ch, s32 pause) {
    StreamInfo *s;
    VoiceInfo *v;

    ch &= 1;
    s = (StreamInfo *)D_018754 + ch;
    if (s->f1C == 0) {
        return;
    }
    D_018724++;
    v = (VoiceInfo *)D_0192F0 + *(u8 *)(s->f0 + 311);
    if (pause != 0) {
        v->f4C |= 8;
        imp_libsd_5(v->f58 | 0x0300, 0x7fff);
        imp_libsd_5(v->f58 | 0x0400, 0x5fff);
        imp_libsd_5(v->f58 | 0x0200, 0);
        if (ch != 0) {
            D_018720 = 0;
        }
    } else {
        v->f4C &= ~8;
        imp_libsd_5(v->f58 | 0x0300, 0x00ff);
        imp_libsd_5(v->f58 | 0x0400, 0x1fc8);
        imp_libsd_5(v->f58 | 0x0200, s->f68);
    }
    v++;
    if (pause != 0) {
        v->f4C |= 8;
        imp_libsd_5(v->f58 | 0x0300, 0x7fff);
        imp_libsd_5(v->f58 | 0x0400, 0x5fff);
        imp_libsd_5(v->f58 | 0x0200, 0);
    } else {
        v->f4C &= ~8;
        imp_libsd_5(v->f58 | 0x0300, 0x00ff);
        imp_libsd_5(v->f58 | 0x0400, 0x1fc8);
        imp_libsd_5(v->f58 | 0x0200, s->f68);
    }
}
