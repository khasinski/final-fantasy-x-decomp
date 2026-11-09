/* tu_342 0x2d7c20-0x2d81e8: low; ~Snd (config/tu_map.tsv) */
#define func_002D7F88 _hdr_func_002D7F88
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#undef func_002D7F88

void SndSepClearAll(void)
{
    func_00252548(-1);
}

void func_002D7C28(void) {
}

void SndSepClear(int handle)
{
    int id;

    if (handle != -1) {
        id = func_002D70A0(handle);
        if (func_002D7090(handle) == 0) {
            return;
        }
    } else {
        id = -1;
    }
    func_00252548(id);
}

void func_002D7CA0(int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_00252560(a, b, c, d, e, f, g, h);
}

int SndSyncTrans(int a)
{
    int r;

    r = func_002D5EA8(a);
    if (a == 0) {
        D_0078BA1C |= r;
    }
    return r;
}

int SndSyncWaveTrans(int a)
{
    return SndSyncTrans(a);
}

void func_002D7D08(int a, int b)
{
    SqsSeSeparateDataSend(a, b, 1);
    func_002D5EA8(1);
}

void SndSepTransNonblock(int a, int b)
{
    SqsSeSeparateDataSend(a, b, 1);
    D_0078BB70.pend |= 1;
    D_0078BA1C |= D_0078BB70.pend;
}

void SndSepTransSepOnly(void *a, int b)
{
    SqsSeSeparateDataSend((int)a, b, 0);
    D_0078BB70.pend |= 1;
    D_0078BA1C |= D_0078BB70.pend;
}

void SndStandbySepWave(void)
{
    D_0078BA1C = 1;
    func_00251DC8();
}

void SndStandbyBattleWaveBlock(s32 handle, u8 *end)
{
    D_0078BA1C = 1;
    D_0078BA18 = 1;
    if ((s32)end <= 0x2FFFF)
    {
        if ((D_0078BA10 | D_0078BA0C) != 0)
        {
            do
            {
                TkSndUpdateMain();
                CALL_func_002D3FF0_INT(0);
            } while ((D_0078BA10 | D_0078BA0C) != 0);
        }
        func_00251E08((void *)handle, (s32)end);
        func_002D5DB8();
        SndSyncWaveTrans(1);
    }
}

/* DEBT(ORDER): the two busy flags share the original chained assignment. */
/* DEBT(CAST): the sound handle carries the 32-bit address passed to the transfer helper. */
void SndStandbyBattleWave(s32 handle, u8 *end)
{
    u32 pending;

    D_0078BA18 = D_0078BA1C = 1;
    if ((s32)end <= 0x2FFFF)
    {
        if ((D_0078BA10 | D_0078BA0C) != 0)
        {
            do
            {
                TkSndUpdateMain();
                CALL_func_002D3FF0_INT(0);
            } while ((D_0078BA10 | D_0078BA0C) != 0);
        }
        func_00251E08((void *) handle, (s32)end);
        func_002D5DB8();
        pending = D_0078BB70.pend | 1;
        D_0078BB70.pend = pending;
        D_0078BA1C |= pending;
    }
}

void func_002D7F70(void *p)
{
    if (p == 0) {
        p = D_00565F28;
    }
    func_00251D10((int)p); /* DEBT(CAST): the RPC argument slots of func_00251360 are plain ints */
}

void func_002D7F88(s16 *arg0)
{
    int i;
    s16 *p;

    if (arg0 == 0) {
        arg0 = (s16 *)D_00565F28;
    }
    D_0078BA1C = 1;
    p = arg0;
    for (i = 0; i < 16; i++, p++) {
        if (*p != -1) {
            func_00251D58(i, *p);
        }
    }
}

void func_002D8008(void *p)
{
    func_002D7F70(p);
    func_002D7F88(p);
}

int func_002D8030(int *p)
{
    return p[2];
}

int func_002D8038(int *p)
{
    return p[3];
}

u8 *func_002D8040(W11Grid *g)
{
    u8 *p = g->base;

    p += g->cols * 4;
    p += g->rows * 32;
    return p + 0x20;
}

/* DEBT(ORDER): independent event-word clears retain the original schedule. */
void SndInitWork(void)
{
    func_002D6B88();
    D_0078BA1C = 0;
    D_0078BA08 = 0;
    D_0078BA14 = 0;
    func_002D6280();
    func_002D6040();
    func_002D8780(0);
    D_0078BB70.cur = 0;
    D_0078BB80.cur = 0;
    D_0078BB90.cur = 0;
    D_0078BB70.pend = 0;
    D_0078BB80.pend = 0;
    D_0078BB90.pend = 0;
    D_0078BB80.w8 = 0;
    D_0078BB90.w8 = 0;
}

void SndMusicStandby(int a, int b)
{
    D_0078BBA8 = SqsMusicDataSend();
}

int func_002D8110(void)
{
    return D_0078BBA8;
}

/* DEBT(CAST): integer-width views follow the existing shared interfaces. */
void SndMusicRead(u32 id)
{
    u32 pending;

    if (id < 0x100U)
    {
        func_002D6260((s32) id);
        if ((D_0078BA10 | D_0078BA0C) != 0)
        {
            do
            {
                TkSndUpdateMain();
                CALL_func_002D3FF0_INT(0);
            } while ((D_0078BA10 | D_0078BA0C) != 0);
        }
        SqsMusicDataRead((s32) id);
        pending = D_0078BB70.pend | 1;
        D_0078BB70.pend = pending;
        D_0078BA1C |= pending;
    }
}
