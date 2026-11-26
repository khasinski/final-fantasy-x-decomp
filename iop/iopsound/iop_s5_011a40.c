#include "iopsound.h"

typedef struct {
    s32 f00;
    u8 pad04[0xdc];
    s32 fe0;
    u8 padE4[0x58];
} S_Voice; /* size 0x13c = 316 */

typedef struct {
    u8 pad00[0x0c];
    s32 f0c;
    u8 pad10[0x360];
    s32 f370;
    s32 f374;
    u8 pad378[0x12];
    s16 f38a;
    u8 pad38c[0x38e];
    s16 f71a;
    u8 pad71c[0x04];
    S_Voice *voices; /* 0x720 = 1824 */
    u8 pad724[0x374];
    s32 fa98; /* 0xa98 = 2712 */
} S_01936C;

extern s32 *D_018750;
extern S_01936C *D_01936C;
extern s32 *D_0193A4;
extern u32 *D_018FA8;
extern u32 D_122410[];
extern s32 D_05A120;
extern s32 D_05A124;
extern u8 *D_01873C;
extern s32 D_019320;
extern s32 D_01870C;
extern s32 D_019358[];
extern s32 D_018718;
extern s32 D_018FCC;
extern s32 D_018FD0;
extern u32 *D_018FC0;
extern s32 D_06D240;
extern volatile s32 D_06D244;
extern volatile s32 D_06D248;
extern s32 D_01934C;
extern s32 D_019300[];
extern s32 D_122400[];
extern s32 D_122408;
extern s32 D_06D238;
extern volatile s32 D_06D23C;
extern s32 D_018FC8;
extern u32 D_018704;
extern s32 D_06D3F0[2][0x1900];
extern u8 D_017700[];
extern s32 D_019368;
extern char D_016654[];
extern char D_0165F0[];
extern s32 D_06D24C;
extern volatile s32 D_06D250;
extern volatile s32 D_06D254;
extern volatile s32 D_06D258;
extern s32 D_06D25C;
extern volatile s32 D_06D260;
extern volatile s32 D_06D264;
extern volatile s32 D_06D268;
extern s32 D_0193A8;

extern void func_008E60(s32, s32);
extern void func_008F64(s32, s32, s32);
extern void func_009040(s32, s32);
extern void func_009120(s32);
extern void func_009148(s32, s32);
extern void func_0091E4(s32);
extern void func_009298(s32, s32);
extern void func_0093C8(void *, s32, s32);
extern void func_00BC2C(s32, s32);
extern s32 func_00BEC4(s32);
extern void func_013F30(s32);
extern s32 func_007A84(s32, s32, s32, s32);
extern s32 func_0079A0(s32, s32, s32, s32);
extern void func_0072F4(s32);
extern void func_007B8C(s32, s32);
extern void func_007C30(s32, s32, s32);
extern void func_007D38(s32, s32);
extern void func_007E44(s32, s32);
extern void func_007EEC(s32, s32, s32);
extern void func_007FF8(s32, s32);
extern void func_00810C(s32, s32, s32);
extern void func_00C938(s32, s32);
extern s32 func_00C908(void);
extern void func_00DDA0(void *, s32, s32);
extern void func_00E260(s32);
extern void func_00E2A8(s32, s32);
extern void func_00E308(s32);
extern void func_00E344(s32, s32);
extern void func_00E9A0(s32);
extern s32 func_00EE2C(void);
extern void func_00EECC(s32);
extern void func_00EF44(s32, s32);
extern void func_00FDF4(s32, void *, s32);
extern void func_00FD60(s32, s32, void *, s32, s32);
extern s32 func_00C920(void);
extern s32 func_00B818(s32);

s32 func_011A40(s32 *arg) {
    *D_018750 = arg[0];
    return arg[0];
}

s32 func_011A60(s32 *arg) {
    func_008E60(arg[0], arg[1]);
    return 0;
}

s32 func_011A8C(s32 *arg) {
    if (arg[1] != 0) {
        func_008F64(arg[0], arg[1], arg[2]);
    } else {
        func_008E60(arg[0], arg[2]);
    }
    return 0;
}

s32 func_011AE0(s32 *arg) {
    if (arg[1] == 0) {
        arg[1] = 1;
    }
    func_009040(arg[0], arg[1]);
    return 0;
}

s32 func_011B20(s8 *arg) {
    func_009120(arg[0]);
    return 0;
}

s32 func_011B44(s32 *arg) {
    if (arg[0] != 0) {
        func_009148(arg[0], ((s8 *)arg)[4]);
    } else {
        func_009120(((s8 *)arg)[4]);
    }
    return 0;
}

s32 func_011B8C(s16 *arg) {
    func_0091E4(arg[0]);
    return 0;
}

s32 func_011BB0(s32 *arg) {
    if (arg[0] != 0) {
        func_009298(arg[0], ((s16 *)arg)[2]);
    } else {
        func_0091E4(((s16 *)arg)[2]);
    }
    return 0;
}

s32 func_011BF8(void) {
    S_01936C *p = D_01936C;
    if (p->f38a != 0 && !(p->f370 & 0x40000)) {
        D_0193A4[p->f374] = p->f0c;
    }
    return 0;
}

s32 func_011C4C(s32 *arg) {
    s32 idx = arg[0];
    if (idx < 0) {
        func_0093C8(D_0193A4, 1024, 0);
    } else {
        D_0193A4[idx] = 0;
    }
    return 0;
}

s32 func_011CA4(void) {
    S_01936C *p = D_01936C;
    return (s16)((u16)p->f38a | (u16)p->f71a);
}

s32 func_011CCC(s32 *arg) {
    s32 oldstat;
    s32 res;

    res = imp_intrman_17(&oldstat);
    func_00BC2C(arg[0], 0);
    if (res == 0) {
        imp_intrman_18(oldstat);
    }
    return 0;
}

s32 func_011D1C(u32 *arg) {
    s32 oldstat;
    s32 res;

    res = imp_intrman_17(&oldstat);
    if (arg >= D_018FA8 + 0x2100 / 4) {
        arg = D_018FA8;
    }
    D_122410[0] = arg[0] | 0x80000000;
    D_122410[1] = arg[1] | 0x80000000;
    D_122410[2] = arg[2] | 0x80000000;
    D_122410[3] = arg[3] | 0x80000000;
    D_122410[4] = arg[4] | 0x80000000;
    D_122410[5] = arg[5] | 0x80000000;
    D_122410[6] = arg[6] | 0x80000000;
    D_122410[7] = arg[7] | 0x80000000;
    func_00BC2C(0, 1);
    if (res == 0) {
        imp_intrman_18(oldstat);
    }
    return 0;
}

s32 func_011E14(s32 *arg) {
    imp_thsemap_7(D_05A120);
    return arg[0];
}

s32 func_011E48(s32 *arg) {
    return func_00BEC4(arg[0]);
}

s32 func_011E6C(s32 *arg) {
    u8 *p = D_01873C;
    s32 n = *(s16 *)(p + 10);
    if (arg[0] < n) {
        s32 *tbl = (s32 *)(p + 16);
        s32 off = tbl[arg[0]];
        if (off != -1) {
            u8 *entry = (u8 *)(tbl + n) + off;
            s32 val = (entry[2] << 8) + entry[1];
            if (arg[1] != 0) {
                D_01870C = 1;
                D_019358[0] = -1;
                D_019358[1] = val;
                imp_thsemap_7(D_019320);
            } else {
                func_013F30(val);
            }
        } else if (arg[1] != 0) {
            D_018718++;
        }
    }
    return 0;
}

s32 func_011F44(s32 *arg) {
    if (arg[0] > 0) {
        D_018FCC = arg[0];
        D_018FD0 = arg[1];
        imp_thsemap_7(D_05A124);
    }
    return arg[0];
}

s32 func_011F98(s32 *arg) {
    S_Voice *v = D_01936C->voices;
    s32 i = 24;

    do {
        if (v->f00 != 0 && v->fe0 == arg[0]) {
            break;
        }
        v++;
    } while (--i != 0);
    return i;
}

s32 func_011FF4(s32 *arg) {
    S_Voice *v;
    s32 i;

    arg[0] |= 0x80000000;
    v = D_01936C->voices;
    i = 24;
    do {
        if (v->f00 != 0 && v->fe0 == arg[0]) {
            break;
        }
        v++;
    } while (--i != 0);
    return i;
}

s32 func_012078(s32 *arg) {
    if (arg[0] & 1) {
        func_007A84(arg[1], arg[2], arg[3], arg[4]);
    } else {
        func_0079A0(arg[1], arg[2], arg[3], arg[4]);
    }
    D_01936C->fa98 = 1;
    return 0;
}

s32 func_0120F0(s32 *arg) {
    if (arg[0] & 1) {
        func_007A84(arg[1], arg[2], arg[3], arg[4]);
    } else {
        func_0079A0(arg[1], arg[2], arg[3], arg[4]);
    }
    D_01936C->fa98 = arg[5] + 1;
    return 0;
}

s32 func_012174(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    func_0072F4(arg[1]);
    return 0;
}

s32 func_0121BC(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    func_007B8C(arg[1], arg[2]);
    return 0;
}

s32 func_01220C(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    if (arg[2] != 0) {
        func_007C30(arg[1], arg[2], arg[3]);
    } else {
        func_007B8C(arg[1], arg[3]);
    }
    return 0;
}

s32 func_012284(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    if (arg[2] == 0) {
        arg[2] = 1;
    }
    func_007D38(arg[1], arg[2]);
    return 0;
}

s32 func_0122E8(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    func_007E44(arg[1], arg[2]);
    return 0;
}

s32 func_012338(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    if (arg[2] != 0) {
        func_007EEC(arg[1], arg[2], arg[3]);
    } else {
        func_007E44(arg[1], arg[3]);
    }
    return 0;
}

s32 func_0123B0(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    func_007FF8(arg[1], ((s16 *)arg)[4]);
    return 0;
}

s32 func_012400(s32 *arg) {
    if (arg[0] & 1) {
        arg[1] |= 0x80000000;
    }
    if (arg[2] != 0) {
        func_00810C(arg[1], arg[2], ((s16 *)arg)[6]);
    } else {
        func_007FF8(arg[1], ((s16 *)arg)[6]);
    }
    return 0;
}

s32 func_012478(void) {
    s32 i = 0;
    s32 mask = 0;
    S_Voice *v = D_01936C->voices;

    for (; i < 24; i++, v++) {
        if (v->f00 != 0) {
            mask |= 1 << i;
        }
    }
    return mask;
}

s32 func_0124C0(void) {
    func_00C938(2, 0);
    return 0;
}

s32 func_0124E4(void) {
    return func_00C908();
}

s32 func_012504(u32 *arg) {
    u32 *src = arg + 2;
    u32 *dst = D_018FC0;
    s32 i;

    for (i = 29; i != 0; i--) {
        *dst++ = *src++;
        if (src >= D_018FA8 + 0x2100 / 4) {
            src = D_018FA8;
        }
    }
    func_00DDA0(D_018FC0, arg[0], arg[1]);
    return 0;
}

