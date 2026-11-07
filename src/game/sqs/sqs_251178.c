/* tu_276 0x251178-0x254028: medium; ~Sqs (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#define func_00252AB8 func_00252AB8_orig /* DEBT(TYPE): funcs.h has u8 d */
#include "ffx/v6.h"
#include "ffx/g4.h"
#undef func_00252AB8

int func_00251178(int cmd, int nowait)
{
    int i;

    while (func_002FB6B8(D_0069BF20) != 0) {
        for (i = 0x10000; i != -1; i--) {
        }
    }
    while (func_002FB4C8(D_0069BF20, cmd, nowait == 0, D_00327018, 0x40, D_00327020, 0x400, 0, 0) < 0) {
        for (i = 0x10000; i != -1; i--) {
        }
    }
}

void func_00251260(int cmd, int nowait, void *endfunc, int efarg)
{
    int i;

    while (func_002FB6B8(D_0069BF48) != 0) {
        for (i = 0x10000; i != -1; i--) {
        }
    }
    while (func_002FB4C8(D_0069BF48, cmd, nowait == 0, D_0032701C, 0x40, D_00327024, 0x40, endfunc, (void *)efarg) < 0) {
        for (i = 0x10000; i != -1; i--) {
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00251360);

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", SqsIopCommandSend);

int func_00251720(int unused, int a, int b, int c)
{
    int r;

    func_002F8660(0);
    D_0069BF00.w0 = a;
    D_0069BF00.w4 = b;
    D_0069BF00.w8 = c;
    D_0069BF00.wC = 0;
    do {
        r = func_002F87A0(&D_0069BF00, 1);
    } while (r == 0);
    D_0069C8C0 = r;
    return r;
}

int func_002517A8(int a, int wait)
{
    int i;
    int r;

    func_002F8660(0);
    i = 1;
    do {
        if (i != 0) { /* no delay before the first poll */
            i = 0;
        } else {
            for (i = 0x10000; i != -1; i--) {
            }
        }
        r = func_002F8780(D_0069C8C0);
    } while (wait != 0 && r >= 0);
    return r;
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00251828);

int SqsDataSendingCompleted(int a)
{
    int r = func_002517A8(1, a);

    if (r < 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

void (*func_002518B0(void (*a0)(int), int a1))(int)
{
    void (*old)(int) = D_0069C8F4;

    D_0069C8F4 = a0;
    D_0069C8F8 = a1;
    return old;
}

int func_002518C8(int wait)
{
    int i;

    if (wait != 0 && T6_REQ_CNT[0] != T6_REQ_CNT[1]) {
        if (D_0032702C > D_00327028) {
            SqsIopCommandSend();
        }
        if (D_0069C8F4 == 0) {
            while (T6_REQ_CNT[0] != T6_REQ_CNT[1]) {
                for (i = 0x10000; i != -1; i--) {
                }
            }
        }
    }
    return T6_REQ_CNT[0] - T6_REQ_CNT[1];
}

void func_002519A0(void)
{
    func_002518C8(1);
    D_00327010[0]++;
    D_0032701C[0] = 1;
    D_0032701C[1] = D_00327010[0];
    func_00251260(0, 0, func_00251828, 0);
}

int func_00251A00(void)
{
    return D_0069BF80[0];
}

int func_00251A10(void)
{
    return D_0069BF80[1];
}

int func_00251A20(int i)
{
    return D_0069BF80[i];
}

int func_00251A38(void)
{
    return D_0069BF74;
}

int func_00251A48(void)
{
    return D_0069BF78;
}

void func_00251A58(void)
{
    func_00251360(0x0, 0, 0, 0, 0, 0, 0, 0);
}

void func_00251A80(int a)
{
    func_00251360(0x1, a & 1, 0, 0, 0, 0, 0, 0);
}

void func_00251AA8(int a)
{
    func_00251360(0x2, a, 0, 0, 0, 0, 0, 0);
}

void func_00251AD0(int a)
{
    int v = (a > 2) ? 0 : a;

    D_00327004 = v;
    func_00251360(3, v, 0, 0, 0, 0, 0, 0);
}

void func_00251B08(int a)
{
    func_00251360(0x5, a, 0, 0, 0, 0, 0, 0);
}

void func_00251B30(int a)
{
    func_00251360(0x6, a, 0, 0, 0, 0, 0, 0);
}

void func_00251B58(int a)
{
    func_00251360(0x7, a, 0, 0, 0, 0, 0, 0);
}

void func_00251B80(int a)
{
    func_00251360(0x8, a, 0, 0, 0, 0, 0, 0);
}

void func_00251BA8(int a, int b)
{
    func_00251360(0x9, a, b, 0, 0, 0, 0, 0);
}

void func_00251BD0(int a, int b, int c, int d, int e)
{
    func_002519A0();
    if (c > 0) {
        c++;
        c <<= 8;
        c--;
    } else {
        c = c << 8;
    }
    func_00251360(10, a, b, c & 0xFFFF, d & 0x7F, e & 0x7F, 0, 0);
    SqsIopCommandSend();
}

void func_00251C60(int a, int b)
{
    if (b > 0) {
        /* DEBT(ORDER): separate steps keep gcc from folding this to (b << 8) | 0xFF */
        b++;
        b <<= 8;
        b--;
    } else {
        b <<= 8;
    }
    func_00251360(0xB, a, (u16)b, 0, 0, 0, 0, 0);
}

void func_00251CA0(int a)
{
    func_00251360(0xC, a, 0, 0, 0, 0, 0, 0);
}

int func_00251CC8(int a)
{
    func_00251360(0xD, a, 0, 0, 0, 0, 0, 0);
    return *D_00327020;
}

int func_00251D10(int a)
{
    func_00251360(0xE, a, 0, 0, 0, 0, 0, 0);
    return *D_00327020;
}

int func_00251D58(int a, int b)
{
    func_002519A0();
    func_00251360(0xF, a, b, 0, 0, 0, 0, 0);
    SqsIopCommandSend();
    func_002518C8(1);
    return *D_00327020;
}

void func_00251DC8(void)
{
    func_002519A0();
    func_00251360(0x10, 0, 0, 0, 0, 0, 0, 0);
    SqsIopCommandSend();
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00251E08);

void func_00251EE8(int src, int unused, int v)
{
    if (D_00327000 == 0) {
        if (src != 0) {
            func_00251720(1, src, D_0069CD40, 0x5000);
            func_002517A8(1, 1);
        }
        *D_00327018 = v;
        func_00251178(4, 0);
    }
}

void func_00251F60(int a, int b, int c) {
    if (D_00327000 == 0) {
        if (a != 0) {
            func_00251720(1, a, D_0069CD44, 0x800);
            func_002517A8(1, 1);
        }
        D_00327018[0] = c;
        func_00251178(5, 0);
    }
}

void SqsInitWaveInfoHdd(const char *a)
{
    func_002F072C((char *)D_00327018, a); /* DEBT(CAST): D_00327018 is an int argument block that also receives string arguments */
    func_00251178(6, 0);
}

void SqsInitMusicInfoHdd(const char *a)
{
    func_002F072C((char *)D_00327018, a); /* DEBT(CAST): see SqsInitWaveInfoHdd */
    func_00251178(7, 0);
}

void iMusicClear(int a)
{
    func_00251360(0x13, a, 0, 0, 0, 0, 0, 0);
}

int SqsMusicDataSend(T6_Music *m)
{
    u8 *head = m->head;
    int size = m->size;

    if ((int)head != 0x204D4742) { /* DEBT(TYPE): the first word is tested against "BGM " but dumped through as a pointer */
        if (D_00327008 & 1) {
            func_002EF240(D_00573700, head[0], head[1], head[2], head[3]);
        }
        size = -1;
    } else if (size > 0 && size <= 0x10000) {
        func_002519A0();
        func_00251720(1, (int)m, D_0069BFC0, size); /* DEBT(TYPE): s6.h declares the source as int */
        func_00251360(0x14, 0, 0, 0, 0, 0, 0, 0);
        SqsIopCommandSend();
    } else if (D_00327008 & 1) {
        func_002EF240(D_00573740, size);
    }
    return size;
}

void SqsMusicDataRead(int a)
{
    func_002519A0();
    func_00251360(0x15, a, 0, 0, 0, 0, 0, 0);
    SqsIopCommandSend();
}

void iMusicStop(int a)
{
    func_00251360(0x12, a, 0, 0, 0, 0, 0, 0);
}

void iMusicStart(int a)
{
    func_00251360(0x16, a, 0, 0, 0, 0, 0, 0);
    D_0069C90C = 1;
}

void func_00252210(int a, int b)
{
    func_00251360(0x17, a, b, 0, 0, 0, 0, 0);
    D_0069C90C = 1;
}

void func_00252258(int a)
{
    func_00251360(0x18, a, 0, 0, 0, 0, 0, 0);
    D_0069C90C = 1;
}

void func_002522A0(int a, int b)
{
    func_00251360(0x19, a, b, 0, 0, 0, 0, 0);
    D_0069C90C = 1;
}

void func_002522E8(int a)
{
    func_00251360(0x23, a, 0, 0, 0, 0, 0, 0);
}

void func_00252310(int a, int b)
{
    func_00251360(0x22, a, b, 0, 0, 0, 0, 0);
}

void iMusicVolumeDirect(int a, int b)
{
    func_00251360(0x1C, a, b & 0x7F, 0, 0, 0, 0, 0);
}

void iMusicVolumeTranslate(int a, int b, int c)
{
    func_00251360(0x1D, a, b, c & 0x7F, 0, 0, 0, 0);
}

void iMusicVolumeFadeOut(int a, int b)
{
    func_00251360(0x24, a, b, 0, 0, 0, 0, 0);
}

void iMusicTempoDirect(u8 a)
{
    func_00251360(0x1E, a, 0, 0, 0, 0, 0, 0);
}

void iMusicTempoTranslate(int a, u8 b)
{
    func_00251360(0x1F, a, b, 0, 0, 0, 0, 0);
}

void iMusicPitchDirect(int a, int b)
{
    func_00251360(0x20, ((a << 8) | b) & 0xFFFF, 0, 0, 0, 0, 0, 0);
}

void func_00252430(int a, int b, int c)
{
    func_00251360(0x21, a, ((b << 8) | c) & 0xFFFF, 0, 0, 0, 0, 0);
}

void func_00252460(void)
{
    func_00251360(0x1B, 0, 0, 0, 0, 0, 0, 0);
}

void func_00252488(int a)
{
    func_00251360(0x1A, a > 0xFF ? -1 : a, 0, 0, 0, 0, 0, 0);
}

int func_002524B8(int shift)
{
    if (shift != 0) {
        D_0069C900.w0 = D_0069C900.w4;
        D_0069C900.w4 = D_0069C900.w8;
        D_0069C900.w8 = D_0069C900.wC;
        func_00251178(8, 1);
        D_0069C900.wC = *D_00327020;
    }
    return D_0069C900.w0 | D_0069C900.w4 | D_0069C900.w8 | D_0069C900.wC;
}

void func_00252548(int a0)
{
    *D_00327018 = a0;
    func_00251178(9, 0);
}

void func_00252560(int a, int b, int c, int d, int e, int f, int g, int h)
{
    D_00327018[0] = a;
    D_00327018[1] = b;
    D_00327018[2] = c;
    D_00327018[3] = d;
    D_00327018[4] = e;
    D_00327018[5] = f;
    D_00327018[6] = g;
    D_00327018[7] = h;
    func_00251178(0xA, 0);
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00252598);

int func_00252650(int a)
{
    *D_00327018 = a;
    func_00251178(0xB, 1);
    return *D_00327020;
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", SqsSeSeparateDataSend);

void func_00252768(int a, int b)
{
    if (b == 1) {
        func_002519A0();
    }
    func_00251360(0x28, a, b, 0, 0, 0, 0, 0);
    SqsIopCommandSend();
    if (b == 1) {
        func_002518C8(1);
    }
}

int func_002527F8(int a)
{
    *D_00327018 = a;
    func_00251178(0xC, 1);
    return *D_00327020;
}

int func_00252830(u32 a)
{
    int r = 0;

    if ((a | 0x80000000) != 0xFFFFFFFF) {
        *D_00327018 = a;
        func_00251178(0xD, 1);
        r = *D_00327020;
    }
    return r;
}

int func_00252888(s32 a, s32 b, s32 c, s32 d)
{
    D_0069BF7C++;
    if (D_0069BF7C == 0) {
        D_0069BF7C = 1;
    }
    func_00251360(0x29, a, D_0069BF7C, b, c & 0x7F, d & 0x7F, 0, 0);
    D_0069C910[3] |= 1;
    return D_0069BF7C;
}

int func_00252908(int a, int b, int c, int d, int e) {
    D_0069BF7C++;
    if (D_0069BF7C == 0) {
        D_0069BF7C = 1;
    }
    func_00251360(0x2A, a, D_0069BF7C, b, c & 0x7F, d & 0x7F, e, 0);
    D_0069C910[3] |= 1;
    return D_0069BF7C;
}

void func_00252988(int a, int b)
{
    func_00251360(0x25, a, b, 0, 0, 0, 0, 0);
}

void SqsSeVolumeDirect(int a, int b, int c)
{
    func_00251360(0x2B, a, b, c & 0x7F, 0, 0, 0, 0);
}

void SqsSeVolumeTranslate(int a, int b, int c, int d)
{
    func_00251360(0x2C, a, b, c, d & 0x7F, 0, 0, 0);
}

void SqsSeVolumeFadeOut(int a, int b, int c)
{
    func_00251360(0x31, a, b, c, 0, 0, 0, 0);
}

void SqsSePanDirect(int a, int b, int c)
{
    func_00251360(0x2D, a, b, c & 0x7F, 0, 0, 0, 0);
}

void func_00252A58(int a, int b, int c, int d)
{
    func_00251360(0x2E, a, b, c, d & 0x7F, 0, 0, 0);
}

void func_00252A88(int a, int b, int c, int d)
{
    func_00251360(0x2F, a, b, ((c << 8) | d) & 0xFFFF, 0, 0, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00252AB8);

int func_00252AE8(int shift)
{
    if (shift != 0) {
        D_0069C910[0] = D_0069C910[1];
        D_0069C910[1] = D_0069C910[2];
        D_0069C910[2] = D_0069C910[3];
        func_00251178(0xE, 1);
        D_0069C910[3] = *D_00327020;
    }
    return D_0069C910[0] | D_0069C910[1] | D_0069C910[2] | D_0069C910[3];
}

void func_00252B78(void)
{
    func_00251360(0x32, 0, 0, 0, 0, 0, 0, 0);
}

int iVoicePlayStatus(int a)
{
    return D_0069BF98;
}

void func_00252BB0(int a, int b, int c)
{
    func_002519A0();
    func_00251360(0x34, a, b, c, 0, 0, 0, 0);
    SqsIopCommandSend();
}

void func_00252C10(int a, int b)
{
    func_00251360(0x35, a & 0x7F, b & 0x7F, 0, 0, 0, 0, 0);
    D_0069C92C = 1;
    D_0069BF98 = 1;
}

void iVoiceVolumeDirect(int a)
{
    func_00251360(0x3A, a & 0x7F, 0, 0, 0, 0, 0, 0);
}

void iVoiceVolumeTranslate(int a, int b)
{
    func_00251360(0x3B, a, b & 0x7F, 0, 0, 0, 0, 0);
}

void func_00252CB0(int a)
{
    func_00251360(0x3C, a & 0x7F, 0, 0, 0, 0, 0, 0);
}

void func_00252CD8(int a, int b)
{
    func_00251360(0x3D, a, b & 0x7F, 0, 0, 0, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00252D00);

void func_00252EF0(int a, int b) {
    D_00327018[0] = a;
    D_00327018[1] = b;
    func_00251178(0x11, 0);
}

void func_00252F10(int a, int b) {
    D_00327018[0] = a;
    D_00327018[1] = b;
    func_00251178(0x13, 0);
}

void SqsStraightStreamingStop(void)
{
    func_00251360(0x33, 0, 0, 0, 0, 0, 0, 0);
    D_0069C8EC = 3;
    D_0069C8CC = 0;
}

void func_00252F80(void)
{
    func_00251360(0x33, 1, 0, 0, 0, 0, 0, 0);
}

int func_00252FA8(void)
{
    int b;

    D_0069C8C4 = D_0069BF80[4];
    if (D_00327008 & 2) {
        func_002EF240(D_005737C8, D_005736D8, D_0069C8C4);
    }
    D_0069C8D0 = D_0069C8C4;
    if (D_0069C8CC != 0) {
        b = D_0069C8C4 & 1;
        if (!((D_0069C8EC >> b) & 1)) {
            D_0069C8EC |= 1 << b;
        }
    }
    return D_0069BF80[4];
}

int func_00253050(int a)
{
    SqsIopCommandSend();
    func_002519A0();
    func_00251360(0x39, a, 0, 0, 0, 0, 0, 0);
    SqsIopCommandSend();
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", SqsStraightStreamingDataEnableStatus);

int *func_002531B0(void)
{
    int *p = &D_0069C8D0; /* DEBT(TYPE): D_0069C8D0 is a block of words, layout unknown */

    p[5] = D_0069BFA0;
    return p;
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", SqsStraightStreamingDataSend);

void func_00253580(void)
{
    func_00251360(0x38, D_0069BF70, 0, 0, 0, 0, 0, 0);
    D_0069BF90 = 0;
    D_0069C8CC = 1;
    D_0069C8E8 = 0;
}

void func_002535D8(int a)
{
    func_00251360(0x3E, a & 0x7F, 0, 0, 0, 0, 0, 0);
}

void func_00253600(int a, int b)
{
    func_00251360(0x3F, a, b & 0x7F, 0, 0, 0, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00253628);

void SqsBattleStreamingStart(int a, int b, int c)
{
    func_00251360(0x36, a & 1, b & 0x7F, c & 0x7F, 0, 0, 0, 0);
    D_0069C92C = 1;
    D_0069BF98 = 1;
}

extern s32 _m2c_func_00253788_D_0069BFCC __asm__("D_0069BFCC");
/* DEBT(CAST) */
void func_00253788(s32 a, s32 b) {
    S6Rpc *var_6;
    s32 temp_2;
    s32 var_16;

    if (a != 0) {
        func_002F8660(0);
        var_6 = &D_0069BF00;
        if (b > 0xA0000) {
            D_0069BF00.w0 = a;
            D_0069BF00.w8 = 0x80000;
            D_0069BF00.w4 = _m2c_func_00253788_D_0069BFCC;
            D_0069BF00.wC = 0;
            var_6 = ((void *)&D_0069BF00) + 0x10;
            var_16 = 2;
            (*(s32 *)((u8 *)(&D_0069BF00) + (0x10))) = (s32) (a + 0x80000);
            var_6->w4 = _m2c_func_00253788_D_0069BFCC + 0x80000;
            var_6->w8 = b - 0x80000;
        } else {
            D_0069BF00.w0 = a;
            var_16 = 1;
            D_0069BF00.w8 = b;
            D_0069BF00.w4 = _m2c_func_00253788_D_0069BFCC;
        }
        var_6->wC = 0;
        do {
            temp_2 = func_002F87A0(&D_0069BF00, var_16);
        } while (temp_2 == 0);
        D_0069C8C0 = temp_2;
    }
}

void func_00253860(int a)
{
    func_00251360(0x37, a, 0x40, 0x7F, 0, 0, 0, 0);
    D_0069C93C = 1;
    D_0069BF94 = 1;
}

int func_002538B0(int a)
{
    return D_0069BF94;
}

int SqsSetProjectBase(const char *a)
{
    func_002F072C((char *)D_00327018, a); /* DEBT(CAST): see SqsInitWaveInfoHdd */
    func_00251178(2, 1);
    return *D_00327020;
}

int *func_00253900(void)
{
    func_00251178(3, 1);
    return D_00327020;
}

void func_00253928(char *buf) {
    func_002F0008(buf, D_005737F0, D_005737F8);
}

void func_00253940(int bit, int set)
{
    if (set) {
        D_00327008 |= 1 << bit;
    } else {
        D_00327008 &= ~(1 << bit);
    }
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00253988);

int func_00253A60(int a)
{
    *D_00327018 = a;
    func_00251178(0x19, 1);
    return *D_00327020;
}

int func_00253A98(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    D_00327018[0] = a;
    D_00327018[1] = b;
    D_00327018[2] = c;
    D_00327018[3] = d;
    D_00327018[4] = e;
    D_00327018[5] = f;
    D_00327018[6] = g;
    D_00327018[7] = h;
    D_00327018[8] = i;
    func_00251178(0x1A, 1);
    return *D_00327020;
}

int func_00253AF8(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    D_00327018[0] = a;
    D_00327018[1] = b;
    D_00327018[2] = c;
    D_00327018[3] = d;
    D_00327018[4] = e;
    D_00327018[5] = f;
    D_00327018[6] = g;
    D_00327018[7] = h;
    D_00327018[8] = i;
    func_00251178(0x1B, 1);
    return *D_00327020;
}

int func_00253B58(void)
{
    func_00251178(0x1C, 1);
    return *D_00327020;
}

int func_00253B88(int a, int b)
{
    D_00327018[0] = a;
    D_00327018[1] = b;
    func_00251178(0x1D, 1);
    return *D_00327020;
}

int *func_00253BC8(int a)
{
    *D_00327018 = a;
    func_00251178(0x1F, 1);
    return D_00327020;
}

int func_00253C00(void)
{
    func_00251178(0x20, 1);
    return *D_00327020;
}

int func_00253C30(void)
{
    func_00251178(0x21, 1);
    return *D_00327020;
}

int func_00253C60(int a)
{
    *D_00327018 = a;
    func_00251178(0x22, 1);
    return *D_00327020;
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00253C98);

int func_00253D58(int a)
{
    if (func_002517A8(1, 0) < 0) {
        *D_00327018 = a;
        func_00251178(0x15, 0);
    }
    return *D_00327020;
}

int *func_00253DB0(void)
{
    func_00251178(0x16, 1);
    return D_00327020;
}

int *func_00253DD8(void)
{
    func_00251178(0x17, 1);
    return D_00327020;
}

void func_00253E00(void)
{
    func_00251178(0x23, 0);
}

void func_00253E10(void)
{
    func_00251178(0x24, 0);
}

void func_00253E20(void)
{
    func_00251178(0x25, 0);
}

void func_00253E30(void)
{
    func_00251178(0x26, 0);
}

void func_00253E40(int a)
{
    func_00251360(0x4, a, 0, 0, 0, 0, 0, 0);
}

void SqsSetStraightStreamAreaSize(int a)
{
    D_0069BFC8 = a;
    func_00251360(0x40, a, 0, 0, 0, 0, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_251178", func_00253E98);
