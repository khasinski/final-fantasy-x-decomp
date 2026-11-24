/* tu_102 0x15a560-0x15b340: low; ~audio (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

int func_0015A560(void) {
    return 0;
}

void func_0015A568(u8 *out, int ch)
{
    u8 *src = (u8 *)func_00186C00 + (ch - 0x20) * 16; /* DEBT(CAST): 8x16 font bitmap, mis-labelled as a function */
    int off = 0;
    int y;
    int x;
    u8 bits;
    u32 mask;

    for (y = 0; y < 16; y++) {
        bits = *src++;
        mask = 0x80;
        for (x = 0; x < 8; x++) {
            if (mask & bits) {
                out[off + 0] = 0xFF;
                out[off + 1] = 0xFF;
                out[off + 2] = 0xFF;
                out[off + 3] = 0x80;
                out[off + 4] = 0xFF;
                out[off + 5] = 0xFF;
                out[off + 6] = 0xFF;
                out[off + 7] = 0x80;
            } else {
                out[off + 0] = 0;
                out[off + 1] = 0;
                out[off + 2] = 0;
                out[off + 3] = 0;
                out[off + 4] = 0;
                out[off + 5] = 0;
                out[off + 6] = 0;
                out[off + 7] = 0;
            }
            off += 8;
            mask >>= 1;
        }
    }
}

void func_0015A628(void) {
    D_0030E070();
}

void audioInit(S58FE54 *s)
{
    D_00591E70 = 0;
    s->w50750 = 1;
    s->b50765 = 0;
    s->w506CC = 0;
    s->w506D0 = 0;
    s->w506D4 = -1;
    s->b5076A = 0;
    s->b5076B = 0;
    s->b50768 = 0;
    s->b50769 = 0;
    s->b50766 = 0;
    s->w50720 = 0;
    s->w50724 = -1;
    s->w50728 = -1;
    s->w5072C = -1;
    SqsSetStraightStreamAreaSize(s->w50758 * 2);
    SndSetStraightStreamVolumeDirect(0);
}

void audioStop(S58FE54 *s)
{
    if (D_00591E70 != 0) {
        s->w506D4 = -1;
        s->w506D0 = 0;
        s->w506CC = 0;
        s->b50765 = 0;
        s->w50750 = 2;
        SndSetStraightStreamVolumeDirect(0);
        SqsStraightStreamingStop();
        D_00591E70 = 0;
        SndDataSendSync(1);
    }
}

void func_0015A740(S58FE54 *s)
{
    if (s->b50766 == 0) {
        func_00253580();
        s->b50765 = 1;
        s->w506D4 = -1;
        s->w506D0 = 0;
        s->w506CC = 0;
    }
}

void func_0015A790(int a, int b, int c, int d, S58FE54 *s)
{
    func_002F8660(0);
    func_002D76B8(a, b, c, d);
    if (s->w5072C + 1 != d) {
        s->b5076F++;
    }
    s->w5072C = d;
}

void func_0015A828(int a) {
    if (D_00591E70 < *(int *)(a + 0x50750)) { /* DEBT(CAST): raw address arithmetic, base object unknown */
        D_00591E70++;
    }
}

void func_0015A858(S58FE54 *s)
{
    if (D_00591E70 == s->w50750) {
        func_0015A740(s);
        D_00591E70 = s->w50750 + 1;
    }
}

typedef struct {
    u8 b[0x2300];
} AudioSubBlk;

typedef struct {
    u8 pad0[0x3CDC0];
    u8 buf3CDC0[2][0x7800];
    AudioSubBlk buf4BDC0[2];
    u8 pad503C0[0x50714 - 0x503C0];
    s32 w50714;
    u8 pad50718[8];
    s32 w50720;
    s32 w50724[2];
    u8 pad5072C[0x50758 - 0x5072C];
    s32 w50758;
    u8 pad5075C[10];
    s8 b50766;
    s8 b50767;
    s8 b50768[2];
    s8 b5076A[2];
    u8 pad5076C[4];
    u8 b50770;
} __attribute__((aligned(8))) AudioDmaCtx;

int SqsStraightStreamingDataEnableStatus(void);
void SndDataSendSync(int);

void audioDma(s16 *buf, int sub, S58FE54 *s0)
{
    AudioDmaCtx *s = (AudioDmaCtx *)s0;
    int idx;
    void *sub_ptr;

    if (s->b50766 != 0) {
        return;
    }
    func_0015A828((int)s);
    if (SqsStraightStreamingDataEnableStatus() == 0) {
        if (s->b5076A[0] != 0 && s->b5076A[1] != 0) {
            s->b50770++;
        }
        idx = (s->w50724[0] > s->w50724[1]);
        s->b5076A[idx] = 1;
        func_002EEF1C((u8 *)s + idx * 0x7800 + 0x3CDC0, buf, s->w50758);
        if (s->w50714 != 0 && sub != 0) {
            s->buf4BDC0[idx] = *(AudioSubBlk *)sub;
            s->b50768[idx] = 1;
        }
        s->w50724[idx] = s->w50720;
        return;
    }
    sub_ptr = 0;
    if (s->b5076A[0] != 0 || s->b5076A[1] != 0) {
        idx = 0;
        if (s->w50724[0] == -1) {
            idx = 1;
        } else if (s->w50724[1] < s->w50724[0] && s->w50724[1] >= 0) {
            idx = 1;
        }
        if (s->w50714 != 0 && sub != 0) {
            sub_ptr = &s->buf4BDC0[idx];
        }
        func_0015A790((int)s->buf3CDC0[idx], (int)sub_ptr, 0, s->w50724[idx], s0);
        func_002EEF1C((void *)((idx * 0x7800 + (u32)s) + 0x3CDC0), buf, s->w50758);
        if (s->w50714 != 0 && sub != 0) {
            s->buf4BDC0[idx] = *(AudioSubBlk *)sub;
            s->b50768[idx] = 1;
        }
        s->w50724[idx] = s->w50720;
    } else {
        if (s->w50714 != 0) {
            sub_ptr = (void *)sub;
        }
        func_0015A790((int)buf, (int)sub_ptr, 0, s->w50720, s0);
    }
    SndDataSendSync(1);
}

INCLUDE_ASM("build/ee_asm/game/movie/audio_15A560", func_0015ACC0);

INCLUDE_ASM("build/ee_asm/game/movie/audio_15A560", func_0015ADB8);

void func_0015AF10(s16 *buf, int n, S58FE54 *s)
{
    int i;
    int j;
    s16 *p;
    int v;

    if (s->b50767 != 0) {
        p = buf;
        for (i = 0; i < 25; i++) {
            for (j = 0; j < 256; j++) {
                v = (p[j] + p[j + 256]) / 2;
                p[j] = v;
                p[j + 256] = v;
            }
            p += 512;
        }
    }
    audioDma(buf, n, s);
}

INCLUDE_ASM("build/ee_asm/game/movie/audio_15A560", func_0015AF88);

INCLUDE_ASM("build/ee_asm/game/movie/audio_15A560", func_0015B008);

INCLUDE_ASM("build/ee_asm/game/movie/audio_15A560", null_ac3_data_ten);
