#include "iopsound.h"

typedef struct ReverbArgs {
    s32 unk00;
    s8 *unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
} ReverbArgs;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x14];
    s32 unk018;         /* 0x018 */
    s32 unk01C;         /* 0x01C */
    u8 *unk020;         /* 0x020 */
    u8 pad024[1];
    u8 unk025;          /* 0x025 */
    u8 unk026;          /* 0x026 */
    u8 pad027[1];
    s32 unk028;         /* 0x028 */
    u8 pad02C[0x04];
    s32 unk030;         /* 0x030 */
    s32 unk034;         /* 0x034 */
    u8 pad038[0x04];
    s32 unk03C;         /* 0x03C */
    s32 unk040;         /* 0x040 */
    u8 pad044[0x04];
    s32 unk048;         /* 0x048 */
    s32 unk04C;         /* 0x04C */
    u8 pad050[0x04];
    s32 unk054;         /* 0x054 */
    u8 pad058[0x0C];
    s32 unk064;         /* 0x064 */
    u8 pad068[0x18];
    s16 unk080;         /* 0x080 */
    s16 unk082;         /* 0x082 */
    s32 unk084;         /* 0x084 */
    u8 pad088[0x18];
    s16 unk0A0;         /* 0x0A0 */
    s16 unk0A2;         /* 0x0A2 */
    s32 unk0A4;         /* 0x0A4 */
    u8 pad0A8[0x14];
    s32 unk0BC;         /* 0x0BC */
    u8 pad0C0[0x0C];
    s32 unk0CC;         /* 0x0CC */
    s32 unk0D0;         /* 0x0D0 */
    s32 unk0D4;         /* 0x0D4 */
    s32 unk0D8;         /* 0x0D8 */
    s32 unk0DC;         /* 0x0DC */
    s32 unk0E0;         /* 0x0E0 */
    u8 pad0E4[0x04];
    u32 unk0E8;         /* 0x0E8 */
    u8 pad0EC[0x04];
    u32 unk0F0;         /* 0x0F0 */
    s32 unk0F4;         /* 0x0F4 */
    u8 pad0F8[0x04];
    s32 unk0FC;         /* 0x0FC */
    s32 unk100;         /* 0x100 */
    s32 unk104;         /* 0x104 */
    u8 pad108[0x04];
    s32 unk10C;         /* 0x10C */
    u8 pad110[0x10];
    s16 unk120;         /* 0x120 */
    s16 unk122;         /* 0x122 */
    s16 unk124;         /* 0x124 */
    s16 unk126;         /* 0x126 */
    s16 unk128;         /* 0x128 */
    s16 unk12A;         /* 0x12A */
    u8 pad12C[0x04];
    u8 unk130;          /* 0x130 */
    u8 pad131[2];
    u8 unk133;          /* 0x133 */
    u8 pad134[3];
    u8 unk137;          /* 0x137 */
    u8 pad138[4];
} Track; /* size 0x13C = 316 */

typedef struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x04];
    u8 *unk008;         /* 0x008 */
    s32 unk00C;         /* 0x00C */
    s32 unk010;         /* 0x010 */
    s32 unk014;         /* 0x014 */
    u8 pad018[0x340];
    s32 unk358;         /* 0x358 */
    u8 pad35C[0x08];
    s32 unk364;         /* 0x364 */
    s32 unk368;         /* 0x368 */
    s32 unk36C;         /* 0x36C */
    u32 unk370;         /* 0x370 */
    s32 unk374;         /* 0x374 */
    s32 unk378;         /* 0x378 */
    s32 unk37C;         /* 0x37C */
    s32 unk380;         /* 0x380 */
    s32 unk384;         /* 0x384 */
    s16 unk388;         /* 0x388 */
    s16 unk38A;         /* 0x38A */
    u8 unk38C;          /* 0x38C */
    u8 unk38D;          /* 0x38D */
    u8 unk38E;          /* 0x38E */
    u8 pad38F[1];
} Seq; /* size 0x390 = 912 */

extern u32 D_018708;
extern Seq *D_01936C;
extern s32 *D_0193A4;
extern s32 D_018748;
extern u32 D_01931C[];
extern s32 D_01871C;
extern u8 D_018C4B[];
extern u32 D_018740;
extern u32 D_018744;
extern s32 D_019330;
extern volatile s32 D_019350;

extern void func_00FDF4(s32, void *, void *);
extern void *func_006CC0(s32);
extern Track *func_009948(s32);
extern s32 func_006118(Track *);
extern void func_00B5EC(s32, s32);
extern void func_00C1C8(s32, s32);
extern void func_00F084(s32);

s32 func_008214(s32 a0, ReverbArgs *a1) {
    s8 *hdr;
    s32 arg8;
    Seq *seq;
    Track *t = NULL;
    s32 i;
    u8 *p;

    if (a0 != 0) {
        if (a1->unk00 != 0) {
            func_00FDF4(0, NULL, NULL);
            func_00FDF4(1, NULL, NULL);
            if (!(D_018708 & 0x100)) {
                imp_libsd_11(2, 1);
                imp_libsd_11(3, 1);
            }
        }

        hdr = a1->unk04;
        arg8 = a1->unk08;
        if (func_006CC0(((s16 *)hdr)[3]) == NULL) {
            return -1;
        }

        seq = D_01936C;
        seq->unk374 = a1->unk0C;
        if (D_0193A4[seq->unk374] != 0) {
            D_018748 = D_0193A4[seq->unk374];
            D_0193A4[seq->unk374] = 0;
        } else {
            D_018748 = a1->unk10;
        }

        if (D_018748 != 0) {
            seq = &D_01936C[3];
        }

        t = func_009948(hdr[8] * sizeof(Track));
        seq->tracks = t;
        i = 0;
        do {
            t->unk137 = i - 1;
            t->ptr = NULL;
            t->unk0E0 = -1;
            if (*(u32 *)(hdr + 20) & 0x10000) {
                t->unk026 = 16;
                t->unk025 = 0;
            } else {
                t->unk026 = 0;
            }
            t++;
        } while (++i < hdr[8]);

        seq->unk37C = ((s16 *)hdr)[3];
        if (((s16 *)hdr)[5] != 0) {
            seq->unk364 = ((s16 *)hdr)[5] << 4;
        }
        p = (u8 *)hdr + 32;
        seq->unk368 = 0;
        seq->unk36C = 0;
        D_01931C[0] |= 4;

        t = seq->tracks;
        i = hdr[8];
        t->unk0E8 = 16;
        for (;;) {
            u32 len = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
            p += 4;
            t->unk018 = arg8;
            t->ptr = p;
            p += len;
            t->unk0F4 = func_006118(t) + 1;
            t->unk0E0 = 0;
            t->unk020 = D_01871C ? D_018C4B : NULL;
            t->unk04C = 0x7F000;
            t->unk040 = 0x80000;
            t->unk054 = 0;
            t->unk028 = 0x03FFF000;
            t->unk034 = 0x03FFF000;
            t->unk048 = 0;
            t->unk03C = 0;
            t->unk030 = 0;
            t->unk100 = 0;
            t->unk0FC = 0;
            t->unk104 = 0;
            t->unk124 = 0;
            t->unk12A = 0;
            t->unk133 = 2;
            t->unk126 = 0;
            t->unk128 = 0;
            t->unk130 = 0;
            t->unk0A4 = 0;
            t->unk084 = 0;
            t->unk064 = 0;
            t->unk0BC = 0;
            t->unk0A0 = 0;
            t->unk080 = 0;
            t->unk0A2 = 0;
            t->unk082 = 0;
            t->unk01C = 0;
            t->unk0F0 = ((*(u32 *)(hdr + 20) & 0x10000) == 0) << 21;
            t->unk122 = 0;
            t->unk120 = 0;
            t->unk0DC = 0;
            t->unk0D8 = 0;
            t->unk0D4 = 0;
            t->unk0D0 = 0;
            t->unk0CC = 0;
            t->unk10C = -1;
            t->unk0E8 |= 0xC00;
            if (t->unk137 != 255) {
                if (t->unk137 < 24) {
                    if (D_018740 & (1 << t->unk137)) {
                        t->unk0E8 |= 0x20;
                    }
                } else {
                    if (D_018744 & (1 << (t->unk137 - 24))) {
                        t->unk0E8 |= 0x20;
                    }
                }
                if (seq->unk370 & 0x10) {
                    t->unk0E8 |= 8;
                }
            }
            if (--i == 0) {
                break;
            }
            t++;
            t->unk0E8 = 0;
        }

        {
            u32 flags;
            seq->unk378 = 1;
            seq->unk38C = 0;
            seq->unk380 = 0;
            seq->unk008 = D_018C4B;
            seq->unk38D = hdr[8];
            flags = seq->unk370 & 0x10;
            seq->unk38A = (s8)hdr[8];
            seq->unk38E = hdr[12] & 0x7F;
            seq->unk358 = 4096;
            seq->unk014 = 10000;
            seq->unk388 = 1;
            seq->unk010 = -1;
            seq->unk00C = 1;
            seq->unk384 = 0;
            seq->unk370 = flags;
            if (*(u32 *)(hdr + 20) & 0x10000) {
                seq->unk370 = flags | 0x40000;
            }
        }

        func_00B5EC(2, seq->unk37C);
        func_00C1C8(2, a1->unk0C);
        if (D_018748 != 0) {
            imp_thsemap_7(D_019330);
        }

        D_019350 &= ~1;
        func_00F084(16);
    }

    return (s32)t;
}
