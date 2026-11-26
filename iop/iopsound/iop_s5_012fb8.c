#include "iopsound.h"

typedef struct {
    s32 f00;
    s32 f04;
} S_Pair;

typedef struct {
    s32 f00;
    u8 pad04[0x3c];
    s32 f40;
    u8 pad44[0x08];
    s32 f4c;
    u8 pad50[0x90];
    s32 fe0;
    s32 fe4;
    u8 padE8[0x10];
    s32 ff8;
    u8 padFC[0x30];
    s16 f12c;
    u8 pad12e[0x09];
    u8 f137;
    u8 f138;
    u8 f139;
    u8 pad13a[0x02];
} S_Voice; /* size 0x13c = 316 */

typedef struct {
    u8 pad00[0x1c];
    s32 f1c;
    u8 pad20[0x354];
    s32 f374;
    u8 pad378[0x18];
} S_MusicSlot; /* size 0x390 = 912 */

typedef struct {
    S_MusicSlot slot[2];
    S_Voice *voices; /* 0x720 = 1824 */
} S_01936C;

typedef struct {
    s32 f00;
    s32 f04;
    u8 *f08;
    s32 f0c;
} S_SeSep; /* size 16 */

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

extern S_Pair *D_019334;
extern void *D_018730;
extern s32 D_01872C;
extern u8 D_05A220[];
extern S_SeSep *D_01938C;
extern S_01936C *D_01936C;
extern S_WaveInfo *D_019308;
extern S_MusicInfo *D_019338;
extern s32 D_06D26C;
extern u8 *D_018FB0;
extern u8 *D_018FAC;
extern u8 *D_018FA8;
extern CmdFunc D_0190BC[];
extern RpcFunc D_019014[];
extern CmdFunc D_0190B4[];
extern s32 D_06CE70[];
extern s32 *D_06CEF0;

extern char D_0165F0[];
extern char D_01667C[];
extern char D_0166A8[];
extern char D_0166E4[];
extern char D_01672C[];
extern char D_01676C[];
extern char D_0167A8[];
extern char D_0167AC[];
extern char D_0167DC[];
extern char D_016814[];
extern char D_016848[];
extern char D_01687C[];
extern char D_016890[];
extern char D_0168BC[];
extern char D_0168F4[];
extern char D_016928[];
extern char D_016958[];
extern char D_016988[];
extern char D_0169C4[];
extern char D_0169F0[];
extern char D_016A1C[];
extern char D_016A6C[];
extern char D_016ABC[];
extern char D_016B0C[];
extern char D_016B5C[];

extern void func_009360(void *, void *, s32);
extern void func_00FDF4(s32, void *, s32);
extern void func_00FC2C(s32, s32, void *, s32, s32);
extern s32 func_00FE3C(s32, s32);
extern s32 func_00EFB0(void);
extern void func_015AA0(void);
extern s32 func_009BB0(s32);
extern void func_009B74(void *);
extern s32 func_0105F4(void *, s32);
extern s32 func_012504(void *);
extern s32 func_011070(void *);

s32 func_012FB8(s32 *arg) {
    func_009360(D_019334, arg, 1024);
    return arg[0];
}

s32 func_012FF0(s32 *arg) {
    S_Pair *p;
    s32 i;
    s32 base;

    func_009360(D_018730, arg, 512);
    p = (S_Pair *)arg;
    base = D_01872C;
    for (i = 256; i != 0; i--, p++) {
        if (p->f04 == 0) {
            break;
        }
        p->f00 -= base;
    }
    return arg[0];
}

s32 func_013060(void) {
    s32 ret;

    func_00FDF4(1, NULL, 0);
    func_00FC2C(1, 1, D_05A220, 6144, 2048);
    ret = imp_libsd_20(1, 0);
    while (func_00FE3C(1, 0) == 0) {
        imp_thbase_33(100);
    }
    return ret;
}

s32 func_0130E0(s32 *arg) {
    s32 vol;
    s32 mask;

    imp_libsd_7(0x1601, 0x00FFFFFF);
    vol = arg[8] << 7;
    if (arg[4] != 0) {
        imp_libsd_9(0x2043, arg[0]);
        mask = 10;
        imp_libsd_9(0x2143, arg[1]);
        imp_libsd_5(0x0003, vol & 0xFFFF);
        imp_libsd_5(0x0103, 0);
        imp_libsd_5(0x0203, ((u16 *)arg)[4]);
        imp_libsd_5(0x0303, ((u16 *)arg)[6]);
        imp_libsd_5(0x0403, ((u16 *)arg)[7]);
        imp_libsd_9(0x2047, arg[4]);
        imp_libsd_9(0x2147, arg[5]);
        imp_libsd_5(0x0007, 0);
        imp_libsd_5(0x0107, vol & 0xFFFF);
        imp_libsd_5(0x0207, ((u16 *)arg)[12]);
        imp_libsd_5(0x0307, ((u16 *)arg)[14]);
        imp_libsd_5(0x0407, ((u16 *)arg)[15]);
    } else {
        imp_libsd_9(0x2043, arg[0]);
        mask = 2;
        imp_libsd_9(0x2143, arg[1]);
        imp_libsd_5(0x0003, vol & 0xFFFF);
        imp_libsd_5(0x0103, vol & 0xFFFF);
        imp_libsd_5(0x0203, ((u16 *)arg)[4]);
        imp_libsd_5(0x0303, ((u16 *)arg)[6]);
        imp_libsd_5(0x0403, ((u16 *)arg)[7]);
    }
    imp_libsd_7(0x1501, mask);
    return mask;
}

s32 func_013254(s32 *arg) {
    if (arg[4] != 0) {
        imp_libsd_9(0x2043, arg[0]);
        imp_libsd_9(0x2143, arg[1]);
        imp_libsd_5(0x0003, 0x3FFF);
        imp_libsd_5(0x0103, 0);
        imp_libsd_5(0x0203, ((u16 *)arg)[4]);
        imp_libsd_5(0x0303, ((u16 *)arg)[6]);
        imp_libsd_5(0x0403, ((u16 *)arg)[7]);
        imp_libsd_9(0x2047, arg[4]);
        imp_libsd_9(0x2147, arg[5]);
        imp_libsd_5(0x0007, 0);
        imp_libsd_5(0x0107, 0x3FFF);
        imp_libsd_5(0x0207, ((u16 *)arg)[12]);
        imp_libsd_5(0x0307, ((u16 *)arg)[14]);
        imp_libsd_5(0x0407, ((u16 *)arg)[15]);
    } else {
        imp_libsd_9(0x2043, arg[0]);
        imp_libsd_9(0x2143, arg[1]);
        imp_libsd_5(0x0003, 0x3FFF);
        imp_libsd_5(0x0103, 0x3FFF);
        imp_libsd_5(0x0203, ((u16 *)arg)[4]);
        imp_libsd_5(0x0303, ((u16 *)arg)[6]);
        imp_libsd_5(0x0403, ((u16 *)arg)[7]);
    }
    return 0;
}

s32 func_013388(void) {
    imp_libsd_7(0x1601, 0x00FFFFFF);
    return 3;
}

s32 func_0133B0(s32 *arg) {
    volatile s32 v0;
    volatile s32 v1;
    volatile s32 v2;
    volatile s32 v3;

    v3 = 0;
    v1 = 0;
    v2 = 0;
    v0 = 0;
    if (arg[0] < 3) {
        if (arg[0] > 0) {
            v2 = 10;
        }
    }
    if (arg[0] != 1) {
        v0 = 10;
    }
    if (arg[1] < 3) {
        if (arg[1] > 0) {
            v3 = 10;
        }
    }
    if (arg[1] != 1) {
        v1 = 10;
    }
    imp_libsd_7(0x1801, v0);
    imp_libsd_7(0x1A01, v1);
    imp_libsd_7(0x1901, v2);
    imp_libsd_7(0x1B01, v3);
    return arg[0];
}

s32 func_01347C(s32 *arg) {
    s32 i;

    arg[0] += 0x80000000;
    if (D_01938C->f04 == arg[0]) {
        S_Voice *v = D_01936C->voices;
        for (i = 0; i < 24; i++) {
            arg[i] = v->f12c;
            v++;
        }
    } else {
        for (i = 23; i >= 0; i--) {
            arg[i] = 0;
        }
    }
    return arg[0];
}

s32 func_013504(s32 *arg) {
    S_Voice *v = D_01936C->voices;

    do {
        v->f12c = 0;
        v++;
    } while (v < D_01936C->voices + 24);
    return arg[0];
}

s32 func_013544(void) {
    S_Voice *v = &D_01936C->voices[23];
    s32 ret = -1;

    do {
        if (v->f00 != 0) {
            ret = v->ff8;
            break;
        }
        v--;
    } while (v >= D_01936C->voices);
    return ret;
}

s32 func_0135A4(void) {
    imp_libsd_6(0);
    imp_libsd_6(256);
    return 0;
}

s32 func_0135CC(void) {
    S_Voice *v;

    imp_sysmem_14(D_01667C, D_0165F0);
    imp_sysmem_14(D_0166A8, D_0165F0);
    v = D_01936C->voices;
    do {
        if (v->f00 != 0) {
            if (v->fe0 < 0) {
                imp_sysmem_14(D_0166E4, D_0165F0, v->f137, v->fe0 & 0x7FFFFFFF,
                              (v->f4c << 10) >> 24, v->f40 >> 12, v->f138, v->f139, v->fe4);
            } else {
                imp_sysmem_14(D_01672C, D_0165F0, v->f137, v->fe0,
                              (v->f4c << 10) >> 24, v->f40 >> 12, v->f138, v->f139, v->fe4);
            }
        } else {
            imp_sysmem_14(D_01676C, D_0165F0, v->f137);
        }
        v++;
    } while (v < D_01936C->voices + 24);
    imp_sysmem_14(D_0167A8);
    return 0;
}

s32 func_01375C(void) {
    S_SeSep *s;
    s32 total = 0;

    imp_sysmem_14(D_0167AC, D_0165F0);
    imp_sysmem_14(D_0167DC, D_0165F0);
    for (s = D_01938C; s < D_01938C + 192; s++) {
        if (s->f0c != 0) {
            S_Voice *v;
            u8 *p;

            v = D_01936C->voices;
            do {
                if (v->f00 != 0 && v->fe0 == s->f04) {
                    break;
                }
                v++;
            } while (v < D_01936C->voices + 24);
            p = s->f08 + 16;
            if (v < D_01936C->voices + 24 && v->f00 != 0) {
                imp_sysmem_14(D_016814, D_0165F0, s->f04 & 0x7FFFFFFF, s->f08, s->f0c,
                              p[1] + (p[2] << 8));
            } else {
                imp_sysmem_14(D_016848, D_0165F0, s->f04 & 0x7FFFFFFF, s->f08, s->f0c,
                              p[1] + (p[2] << 8));
            }
            total++;
        }
    }
    imp_sysmem_14(D_01687C, D_0165F0, D_0165F0, total);
    return total;
}

