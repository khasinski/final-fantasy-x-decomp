#include "iopsound.h"

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} S00D818_Block;

typedef struct {
    u32 unk00;
    u8 *unk04;
    u8 pad08[0x8];
    s32 unk10;
    u8 pad14[0x8];
    s32 unk1C;
    u8 pad20[0x4];
    u16 unk24;
    u16 pad26;
    u8 pad28[0x4];
    u32 unk2C;
    u32 unk30;
    u8 pad34[0x8];
    u8 *unk3C;
    u8 pad40[0x4];
    u32 unk44;
    u8 pad48[0x24];
    u32 unk6C;
} S00D818_Stream; /* size 0x70 */

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 pad08[0xF8];
    u8 *unk100;
    u32 unk104;
    u32 unk108;
    u32 unk10C;
} S00D818_Req;

extern S00D818_Stream *D_018754;
extern s8 *D_018758;
extern s32 D_018F98;
extern u32 D_019354;
extern u8 *D_019384;
extern S00D818_Req D_06D2E0;

extern void func_00C938(void);
extern void func_00CFB4(S00D818_Stream *, u32 *);
extern void func_00D760(void);
extern void func_00DAC4(void);
extern void func_00FC2C(s32, s32, void *, u32, u32);
extern void func_00FDF4(s32, void *, void *);

u32 func_00D818(s32 ch, u32 *a1) {
    S00D818_Stream *s = D_018754;
    S00D818_Block *blk;

    if (ch != 0) {
        s = &s[1];
    }
    if (s->unk1C == 0) {
        return a1[0];
    }

    blk = (S00D818_Block *)s->unk04;
    if (s->unk10 == 0) {
        func_00CFB4(s, &s->unk44);
    }

    func_00FDF4(ch, func_00D760, 0);
    func_00FC2C(ch, 0, s->unk04, a1[0], a1[2]);
    D_018F98++;
    if (a1[3] == 0) {
        s->unk30 = blk->unk08;
    }

    a1[4] = (u32)func_00DAC4;
    s->unk04 += a1[2];
    if (s->unk10 == 0 && s->unk44 == 0) {
        s->unk04 = s->unk3C;
    }

    a1[0] += 32;
    a1[1] += 32;
    if (a1[3] != 0) {
        a1[4] = (u32)func_00C938;
        a1[1] = 0x5030;
        a1[0] = 0x5030;
    } else {
        if (blk->unk0C < 2U || blk->unk0C >= s->unk2C) {
            a1[3] = 1;
            if (s->unk10 == 0) {
                D_06D2E0.unk00 = 0;
                D_06D2E0.unk04 = 0;
            }
        }
        s->unk2C = blk->unk0C;
    }

    imp_libsd_9((u16)(ch | (s->unk24 << 1) | 0x2140), a1[0]);
    imp_libsd_9((u16)(ch | ((s->unk24 + 1) << 1) | 0x2140), a1[1]);

    if (a1[3] == 0 && s->unk10 == 0 && (s->unk44 & 7) == 0) {
        if (*D_018758 == 0) {
            S00D818_Req *req = &D_06D2E0;
            req->unk04 = 0;
            req->unk00 = D_019354;
            req->unk104 = D_019354;
        } else {
            imp_sysclib_23(&D_06D2E0, D_018758);
        }
        {
            S00D818_Req *req = &D_06D2E0;
            u32 x = (s->unk44 ^ 8) << 11;
            u32 y = (u32)D_019384;
            y += x;
            req->unk100 = (u8 *)y;
            req->unk108 = s->unk6C;
            req->unk10C = 0x4000;
        }
        s->unk6C += 0x4000;
    }

    return a1[0];
}
