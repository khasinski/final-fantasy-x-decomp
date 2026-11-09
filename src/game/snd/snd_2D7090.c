/* tu_341 0x2d7090-0x2d7c20: low; ~Snd (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad/event glue (see w10.h). */
#define SndStartShoutStream _hdr_SndStartShoutStream
#define func_002D72F8 _hdr_func_002D72F8
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/w11.h"
#undef SndStartShoutStream
#undef func_002D72F8

s32 func_002D7090(s32 a) {
    u32 m = a & 0x80000000;
    return m == 0;
}

u32 func_002D70A0(u32 v) {
    return v & 0x7FFFFFFF;
}

void SndPlay(s32 a, s32 b, s32 c, s32 d) {
    if (D_0078BB9D == 0) {
        func_00252888(a, b, c, d);
    }
}

void func_002D70D0(int a, int b) {
    func_00252988(a, b);
}

void func_002D70D8(u32 a) {
    func_00252888(0, a & 0x7FFFFFFF, 0x3F, 0x7F);
}

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", func_002D70F8);

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", func_002D71C0);

/* Module: sound driver wrappers (calls into the 0x25xxxx sound library; handle = bit31 flag + 31 bit id) */

void *_m2c_func_002D72F8_GetCD() __asm__("GetCD");
s32 _m2c_func_002D72F8_func_002D5CB0(s8 *) __asm__("func_002D5CB0");
s32 _m2c_func_002D72F8_func_002D70F8(s32, s32 *) __asm__("func_002D70F8");
u32 _m2c_func_002D72F8_func_002D71C0(s32) __asm__("func_002D71C0");
s32 _m2c_func_002D72F8_func_002F072C(s8 *, s32 *) __asm__("func_002F072C");
/* DEBT(CAST) */
s32 func_002D72F8(s32 *arg0, s32 *arg1, s32 *arg2, s32 arg3, u32 arg4) {
    u8 sp[0x10];
    u8 sp10[0x10];
    s32 temp_18;
    s32 temp_2;
    s32 var_20;
    u32 var_17;
    void *temp_2_2;

    var_17 = arg4;
    var_20 = 1;
    if (arg1 != 0) {
        var_20 = *arg1;
    }
    if (var_17 == 0xFFFFFFFF) {
        var_20 = 1;
        _m2c_func_002D72F8_func_002D70F8(arg3, sp);
        D_0078BBA4 = 0x78;
        _m2c_func_002D72F8_func_002F072C(D_0078BBB0, sp);
        _m2c_func_002D72F8_func_002F072C(D_0078BBD0, sp);
        _m2c_func_002D72F8_func_002D5CB0(D_0078BBB0);
        var_17 = _m2c_func_002D72F8_func_002D71C0(0x504);
        *arg2 = 0x19;
    } else {
        _m2c_func_002D72F8_func_002D70F8(arg3, sp10);
        _m2c_func_002D72F8_func_002F072C(D_0078BBD0, sp10);
    }
    temp_2_2 = _m2c_func_002D72F8_GetCD();
    (*(s32 (**)(s32))((u8 *)(temp_2_2) + (0x10)))(*arg2);
    temp_18 = (var_17 >> 0x10) + var_20;
    (*(s32 (**)(s32))((u8 *)(temp_2_2) + (4)))(0);
    temp_2 = (*(s32 (**)(s32))((u8 *)(temp_2_2) + (4)))(temp_18) + (var_17 & 0xFFFF);
    if (arg0 != 0) {
        *arg0 = temp_18;
    }
    if (arg1 != 0) {
        *arg1 = var_20;
    }
    return temp_2;
}

void func_002D7430(u32 a, int *b, int *c)
{
    u32 v = a >> 12;

    if (v / 10000 % 100 < 21) {
        *b = 25;
        *c = 1;
    } else {
        *b = 27;
        *c = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", func_002D7480);

void SndStandbyStream(s32 v)
{
    int first;
    s32 second;

    func_002D7430((u32) v, &first, &second);
    func_002D7480((u32) v, first, second);
    D_0078BA14 = 1;
}

void func_002D76A8(void)
{
    func_00253580();
}

void func_002D76B0(void)
{
    SqsStraightStreamingStop();
}

void func_002D76B8(int a, int b)
{
    SqsStraightStreamingDataSend(a, b);
}

int func_002D76C0(void)
{
    return func_00252FA8();
}

void SndSetStraightStreamVolumeDirect(int a)
{
    func_002535D8(a);
}

void func_002D76E8(int a, int b)
{
    func_00253600(a, b);
}

void func_002D76F0(int a, int b)
{
    func_00253628(a, b);
}

void SndStartBattleStream(int a, int b, int c)
{
    SqsBattleStreamingStart(a, b, c);
    D_0078BB70.pend |= 1;
    D_0078BA1C |= D_0078BB70.pend;
}

void func_002D7738(int a, int b)
{
    func_00253788(a, b);
}

s32 _m2c_SndStartShoutStream_func_0014AC20() __asm__("func_0014AC20");
s32 _m2c_SndStartShoutStream_func_00253860(s32, s32, s32) __asm__("func_00253860");
void SndStartShoutStream(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_2;

    _m2c_SndStartShoutStream_func_00253860(arg0, arg1, (_m2c_SndStartShoutStream_func_0014AC20() != 0) ? arg2 : 0);
    temp_2 = D_0078BB80.pend | 1;
    D_0078BB80.pend = temp_2;
    D_0078BA0C |= temp_2;
}

void SndStartStream(void) {
    u32 temp_3;
    u32 temp_5;

    D_0078BA08 |= 1;
    D_0078BA10 |= 1;
    D_0078BA14 = 0;
    func_00252C10(0x3F, (func_0014AC20() == 0) ? 0 : 0x7F);
    temp_3 = D_0078BB70.pend | 1;
    temp_5 = D_0078BB90.pend | 1;
    D_0078BB90.pend = temp_5;
    D_0078BA1C |= temp_3;
    D_0078BA10 |= temp_5;
    D_0078BB70.pend = temp_3;
}

void SndStartStream2(s32 a, s32 b) {
    u32 temp_3;
    u32 temp_5;

    D_0078BA10 |= 1;
    D_0078BA08 = 1;
    D_0078BA14 = 0;
    func_00252C10(a, (func_0014AC20() != 0) ? b : 0);
    temp_3 = D_0078BB70.pend | 1;
    temp_5 = D_0078BB90.pend | 1;
    D_0078BB90.pend = temp_5;
    D_0078BA1C |= temp_3;
    D_0078BA10 |= temp_5;
    D_0078BB70.pend = temp_3;
}

void SndStopStream(void)
{
    func_002D67F8(0);
    func_00252B78();
}

void SndStopBattleStream(void)
{
    func_002D67F8(0);
    func_00252B78();
}

int SndGetStreamState(void)
{
    int a = D_0078BA0C;
    int b = D_0078BA08;
    int c = b | a;

    D_0078BA08 = c;
    return (c | b) | a;
}

u32 func_002D7970(void)
{
    return D_0078BA1C;
}

void SndSepPlaySimple(int handle)
{
    SndPlay(func_002D7090(handle), func_002D70A0(handle), 0x3F, 0x7F);
}

void SndSepPlay(int handle, int a, int b)
{
    SndPlay(func_002D7090(handle), func_002D70A0(handle), a, b);
}

void SndSepVolumeDirect(int handle, int a)
{
    SqsSeVolumeDirect(func_002D7090(handle), func_002D70A0(handle), a);
}

void SndSepPanDirect(int handle, int a)
{
    SqsSePanDirect(func_002D7090(handle), func_002D70A0(handle), a);
}

void SndSepVolumeTranslate(int handle, int a, int b)
{
    SqsSeVolumeTranslate(func_002D7090(handle), func_002D70A0(handle), a, b);
}

void func_002D7B28(int handle, int a)
{
    SqsSeVolumeTranslate(func_002D7090(handle), func_002D70A0(handle), a, 0);
}

void func_002D7B80(int handle, int a, int b)
{
    func_00252A58(func_002D7090(handle), func_002D70A0(handle), a, b);
}

void SndSepStop(int handle)
{
    func_002D70D0(func_002D7090(handle), func_002D70A0(handle));
}
