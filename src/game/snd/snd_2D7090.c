/* tu_341 0x2d7090-0x2d7c20: low; ~Snd (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad/event glue (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/w11.h"

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

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", func_002D72F8);

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

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", SndStartShoutStream);

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", SndStartStream);

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D7090", SndStartStream2);

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
