#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x14];
    void *unk018;       /* 0x018 */
    s32 unk01C;         /* 0x01C */
    u8 pad020[0x08];
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
    s32 unk058;         /* 0x058 */
    u8 pad05C[0x04];
    s32 unk060;         /* 0x060 */
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
    s32 unk0E4;         /* 0x0E4 */
    u32 unk0E8;         /* 0x0E8 */
    s32 unk0EC;         /* 0x0EC */
    s32 unk0F0;         /* 0x0F0 */
    s32 unk0F4;         /* 0x0F4 */
    s32 unk0F8;         /* 0x0F8 */
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
    s16 unk12C;         /* 0x12C */
    s16 unk12E;         /* 0x12E */
    u8 unk130;          /* 0x130 */
    u8 pad131[2];
    u8 unk133;          /* 0x133 */
    u8 pad134[3];
    u8 unk137;          /* 0x137 */
    u8 unk138;          /* 0x138 */
    u8 unk139;          /* 0x139 */
    u8 pad13A[2];
} Track; /* size 0x13C = 316 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x12];
    u8 unk16;           /* 0x16 */
    u8 pad17[0x05];
    s32 unk1C;          /* 0x1C */
    u8 pad20[0x0C];
    s32 unk2C;          /* 0x2C */
    u8 pad30[0x1C];
    u32 unk4C;          /* 0x4C */
    u8 pad50[0x08];
    u16 unk58;          /* 0x58 */
    u8 pad5A[0x06];
    u32 unk60;          /* 0x60 */
    u8 pad64[0x04];
    u32 unk68;          /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct Seq {
    u8 pad000[0x384];
    s32 unk384;         /* 0x384 */
    u8 pad388[0x08];
} Seq; /* size 0x390 = 912 */

extern Seq *D_01936C;
extern u32 D_018708;
extern Voice *D_0192F0;

extern char D_016080[];
extern char D_0160A8[];
extern char D_0160BC[];
extern char D_0160C4[];

extern s16 *func_006CC0(u32);
extern void func_00B5EC(s32, s32);
extern void func_00F0D4(s32);
extern Track *func_0071C8(s32, u32, u32);
extern s32 func_006118(Track *);
extern void func_00747C(s32);

s32 func_0075FC(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s16 *wave;
    u32 arg2;
    s32 vol_init;
    s32 pan;
    u8 *p5;
    u8 *p6;
    s32 count;
    u8 *data_ptr;

    D_01936C[2].unk384 = 0;
    count = (a0[2] << 8) + a0[1];
    wave = func_006CC0(count);
    if (wave != NULL) {
        func_00B5EC(2, wave[1]);
    } else {
        imp_sysmem_14(D_016080, D_0160A8, D_0160BC, count, D_0160C4);
        func_00F0D4(0);
    }

    p5 = a0 + 5;
    vol_init = 0x03FFF000;
    pan = (a3 + 64) << 12;
    p6 = a0 + 6;
    data_ptr = p5 + (a0[0] << 1);
    count = a0[0];
    arg2 = a0[4];

    do {
        s32 n;
        Track *trk;

        if (D_018708 & 0x10000) {
            n = count;
        } else {
            n = 1;
            if (p6[2] & 0x80) {
                u8 *q = p5 + 2;
                while (1) {
                    if (n >= count) {
                        break;
                    }
                    q += 2;
                    n++;
                    if (!(q[1] & 0x80)) {
                        break;
                    }
                }
            }
        }

        trk = func_0071C8(n, a0[3], arg2);
        arg2 = 0;
        if (trk != NULL) {
            Voice *v = &D_0192F0[trk->unk137];
            trk->unk0E8 = 16;
            for (;;) {
                trk->unk018 = wave;
                trk->ptr = data_ptr;
                data_ptr += ((p6[0] << 8) + p5[0]) & 0x7FFF;
                trk->unk0F4 = func_006118(trk) + 1;
                trk->unk0E0 = a2;
                trk->unk0E4 = a1;
                trk->unk12C = 0;
                trk->unk0F8 = 0;
                if (*trk->ptr != 0) {
                    trk->unk138 = a0[3];
                    trk->unk139 = a0[4];
                    trk->unk04C = a4 << 12;
                    trk->unk054 = 0;
                    trk->unk060 = 0;
                    trk->unk058 = 0;
                    trk->unk0EC = 0;
                    trk->unk028 = vol_init;
                    trk->unk034 = vol_init;
                    trk->unk040 = pan;
                    trk->unk048 = 0;
                    trk->unk03C = 0;
                    trk->unk030 = 0;
                    trk->unk100 = 0;
                    trk->unk0FC = 0;
                    trk->unk104 = 0;
                    trk->unk124 = 0;
                    trk->unk12A = 0;
                    trk->unk133 = 2;
                    trk->unk126 = 0;
                    trk->unk128 = 0;
                    trk->unk130 = 0;
                    trk->unk0A4 = 0;
                    trk->unk084 = 0;
                    trk->unk064 = 0;
                    trk->unk0BC = 0;
                    trk->unk0A0 = 0;
                    trk->unk080 = 0;
                    trk->unk0A2 = 0;
                    trk->unk082 = 0;
                    trk->unk01C = 0;
                    trk->unk0F0 = 0;
                    trk->unk10C = -1;
                    trk->unk122 = 0;
                    trk->unk120 = 0;
                    trk->unk0DC = 0;
                    trk->unk0D8 = 0;
                    trk->unk0D4 = 0;
                    trk->unk0D0 = 0;
                    trk->unk0CC = 0;
                    trk->unk12E = 1;
                    trk->unk0E8 |= 0xC00;

                    v->trk = trk;
                    v->unk16 = 17;
                    v->unk4C = 2;
                    v->unk2C = 0;
                    v->unk1C = 0;
                    v->unk68 = 0;
                    v->unk60 = (v->unk60 & 0xFFE0FFFF) | 0x00040000;
                    imp_libsd_5(v->unk58 | 0x400, v->unk60 >> 16);
                }
                count--;
                n--;
                p6 += 2;
                p5 += 2;
                if (n == 0) {
                    break;
                }
                trk++;
                v++;
                trk->unk0E8 = 0;
            }
        } else {
            func_00747C(a1);
            break;
        }
    } while (count != 0);

    return 0;
}
