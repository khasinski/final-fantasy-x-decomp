#include "iopsound.h"

typedef struct {
    s16 f0;
    s16 f2;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} WaveHdr;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    WaveHdr *fC;
    s32 f10;
    s32 f14;
} WaveSlot;

extern char D_016168[];
extern char D_016184[];
extern char D_016200[];
extern char D_0162D4[];
extern char D_016314[];
extern s32 D_018718;
extern s32 *D_018FB4;
extern WaveSlot *D_019308;
extern volatile s32 D_019350;
extern s32 D_05A050;

extern s32 func_009BB0(s32);
extern void func_009B74(WaveSlot *);
extern void func_00F0D4(s32);
extern void func_00EFBC(s32, s32);
extern s32 func_00A7A0(s32, WaveHdr *, s32);
extern void func_00B160(void);
extern void func_00FDF4(s32, void *, s32);
extern s32 func_00FC2C(s32, s32, u8 *, s32, s32);
extern void func_014004(s32);

s32 func_00B1E0(void *arg) {
    WaveHdr *hdr = (WaveHdr *)arg;
    u8 *buf = (u8 *)arg;
    s32 res;
    s32 off;
    s32 half1;
    s32 half2;

    off = func_009BB0(hdr->f2);
    if (off >= 0) {
        func_009B74(&D_019308[off]);
        res = D_019308[off].fC->f10;
        D_018718++;
    } else {
        while (D_019350 != 0) {
            imp_thbase_33(500);
        }
        D_019350 |= 2;
        if (*(s16 *)hdr != 0x4457) {
            imp_sysmem_14(D_016314, D_016168, D_016200, hdr->f2, *D_018FB4, D_016184);
            func_00F0D4(5);
            func_00EFBC(13, *D_018FB4);
        }
        hdr->f4 = (hdr->f4 + 63) & ~63;
        res = func_00A7A0(-1, hdr, hdr->f2);
        if (res != 0) {
            s32 f8_sz = ((hdr->f8 + 3) & ~3) << 2;
            s32 fC_sz = (hdr->fC << 5) + 32;
            off = f8_sz + fC_sz;
            if (off + hdr->f4 > 0x31000) {
                func_00F0D4(6);
            }
            D_05A050 = 3;
            half2 = (hdr->f4 >> 1) & ~63;
            half1 = hdr->f4 - half2;
            if ((half1 | half2) == 0) {
                imp_sysmem_14(D_0162D4, half1, half2);
            }
            while (1) {
                func_00FDF4(0, (void *)func_00B160, 0);
                if (func_00FC2C(0, 0, buf + off, res, half1) > 0) {
                    break;
                }
                imp_thbase_33(1000);
            }
            res += half1;
            off += half1;
            while (1) {
                func_00FDF4(1, (void *)func_00B160, 0);
                if (func_00FC2C(1, 0, buf + off, res, half2) > 0) {
                    break;
                }
                imp_thbase_33(1000);
            }
        } else {
            D_018718++;
        }
        D_019350 &= ~2;
    }

    func_014004(hdr->f2);
    return res;
}
