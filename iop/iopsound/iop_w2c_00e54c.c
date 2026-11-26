#include "iopsound.h"

typedef struct {
    u8 *f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s8 *f3C;
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
    s32 f68;
    s32 f6C;
} StreamCh;

extern s32 D_019350;
extern StreamCh *D_018754;
extern s8 D_06D3F0[];
extern s8 D_09E3F0[];

extern char D_016418[];
extern char D_016444[];
extern char D_016458[];
extern char D_016460[];
extern char D_0164A8[];
extern char D_0164B0[];
extern char D_0164F4[];

extern void func_00C938(s32, s32);
extern void func_00D014(s32, void *);
extern void func_00EFBC(s32, s32);

void func_00E54C(s32 idx, s32 pan, s32 vol) {
    s8 *buf;

    if (D_019350 & 3) {
        imp_sysmem_14(D_016418, D_016444, D_016458, D_016460);
        return;
    }
    buf = &D_06D3F0[(idx & 1) << 16];
    if (buf[0] == 'V' && buf[1] == 'S') {
        StreamCh *s;
        func_00C938(2, 1);
        D_019350 |= 8;
        s = &D_018754[1];
        s->fC = 10000;
        s->f44 = -1;
        s->f30 = 0;
        s->f34 = 0;
        s->f38 = 0;
        s->f48 = 0;
        s->f4C = 16;
        s->f18 = 0;
        s->f3C = buf;
        s->f40 = 0;
        s->f6C = 0;
        if (vol != 0) {
            vol++;
            vol <<= 7;
            vol--;
            vol <<= 12;
        }
        s->f50 = vol;
        s->f5C = (pan + 64) << 12;
        s->f64 = 0;
        s->f58 = 0;
        func_00D014(1, s->f3C);
    } else {
        imp_sysmem_14(D_0164B0, D_016444, D_0164A8, D_016460);
    }
    func_00EFBC(6, D_018754[1].f1C);
}

void func_00E6D0(s32 idx, s32 pan, s32 vol) {
    s8 *buf;

    if (D_019350 & 3) {
        imp_sysmem_14(D_016418, D_016444, D_016458, D_016460);
        return;
    }
    buf = D_09E3F0 + ((s32 *)D_09E3F0)[idx];
    if (buf[0] == 'V' && buf[1] == 'S') {
        StreamCh *s;
        func_00C938(1, 1);
        D_019350 |= 4;
        s = &D_018754[0];
        s->fC = 10000;
        s->f44 = -1;
        s->f30 = 0;
        s->f34 = 0;
        s->f38 = 0;
        s->f48 = 0;
        s->f4C = 16;
        s->f18 = 0;
        s->f3C = buf;
        s->f40 = 0;
        s->f6C = 0;
        if (vol != 0) {
            vol++;
            vol <<= 7;
            vol--;
            vol <<= 12;
        }
        s->f50 = vol;
        s->f5C = (pan + 64) << 12;
        s->f64 = 0;
        s->f58 = 0;
        func_00D014(2, s->f3C);
    } else {
        imp_sysmem_14(D_0164F4, D_016444, D_0164A8, D_016460);
    }
    func_00EFBC(5, D_018754[0].f1C);
}
