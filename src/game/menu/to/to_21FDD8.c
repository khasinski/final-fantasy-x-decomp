/* tu_246 0x21fdd8-0x2207e8: low; ~TOMenuInit (config/tu_map.tsv) */
#define func_0021FF58 _hdr_func_0021FF58
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#undef func_0021FF58

void TOMenuInit(void)
{
    D_00323950 = 0;
    D_00323954 = 0;
    D_00693088 = 0;
    D_00692C00.n = 0;
    D_00692C20.n = 0;
    func_002202D0();
}

int TOMenuOpen(int a)
{
    u8 pad[0x90]; /* DEBT(PADDING): unused local area */

    if (AtelGetHyoukaMenuEnable() != 1 && a == 0) {
        return 1;
    }
    if (MsBattleGetStatus() != 0) {
        return 1;
    }
    D_00325798 = func_001BD360();
    D_00323950 = 1;
    func_002202D0();
    TOSetExeMessageWindowArea(2);
    D_00693088 = a;
    func_0020CA38();
    TOSeqBuffFlashScene(1);
    TkMenuStart(a);
    func_002202D0();
    TOSetExeMessageWindowArea(0);
    if (D_00325798 != func_001BD360()) {
        TOSwapInternationalMessageWindow();
    }
    D_00323950 = 0;
    return 0;
}

void func_0021FED8(void) {
}

void TODrawMenu(void)
{
    TOSetAddPkt();
    func_001EF940();
    D_00325678[D_00325694]();
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    func_001EF978();
    TODrawKick();
    func_002DA610(0, 0);
    TOInitAddPkt();
}

extern s32 _m2c_func_0021FF58_D_00692CF0 __asm__("D_00692CF0");
extern s32 _m2c_func_0021FF58_D_00693030 __asm__("D_00693030");
void func_0021FF58(void) {
    _m2c_func_0021FF58_D_00692CF0 = Sg_GetDBuffDC(&_m2c_func_0021FF58_D_00693030);
}

void func_0021FF88(void)
{
    func_002DA610(0, 0);
    func_002D3FF0(0);
    func_002F8660(0);
    func_002DB640((u8 *)D_00692CF0, D_00693030); /* DEBT(CAST): D_00692CF0 is s32 * */
    D_00693030++;
}

typedef struct {
    u8 pad00[2];
    s8 rep[16];
    u16 h12;
    u16 h14;
    u16 h16;
    u16 h18;
    u16 h1A;
    u16 h1C;
    u8 b1E;
    u8 b1F;
    u8 b20;
    u8 b21;
    u16 h22;
    u16 h24;
    u16 h26;
    u8 pad28[0x18];
} PadBlockFull;

extern PadBlockFull _pad_D_003238D0 __asm__("D_003238D0");

void TOMenuGetPadStatus(void)
{
    u16 prev = _pad_D_003238D0.h22;
    int i;

    _pad_D_003238D0.h12 = 0;
    _pad_D_003238D0.h14 = 0;
    _pad_D_003238D0.h16 = 0;
    _pad_D_003238D0.h22 = 0;
    _pad_D_003238D0.h24 = 0;
    _pad_D_003238D0.h26 = 0;
    if (TkMenuGetDummyControlerFlag() == 1) {
        TkMenuFlushDummyControler();
    }
    if (TkMenuGetDummyControlerFlag() == 1) {
        _pad_D_003238D0.h12 = TkMenuGetDummyControler();
        _pad_D_003238D0.h18 = TkMenuGetDummyControler();
        _pad_D_003238D0.h14 = TkMenuGetDummyControlerT();
        _pad_D_003238D0.h1A = TkMenuGetDummyControlerT();
        _pad_D_003238D0.h16 = TkMenuGetDummyControlerR();
        _pad_D_003238D0.h1C = TkMenuGetDummyControlerR();
        _pad_D_003238D0.b1E = TOMenuGetDummyAnalogControler(2);
        _pad_D_003238D0.b1F = TOMenuGetDummyAnalogControler(3);
    } else {
        _pad_D_003238D0.h12 = TkGetControlerHist(0, 0, 0);
        _pad_D_003238D0.h14 = TkGetControlerTrigHist(0, 0, 0);
        _pad_D_003238D0.h16 = TkGetControlerReptHist(0, 0, 0);
        _pad_D_003238D0.h18 = TkGetControlerHist(0, 0, 0);
        _pad_D_003238D0.h18 |= TkGetControlerHist(0, 0, -1);
        _pad_D_003238D0.h1A = TkGetControlerTrigHist(0, 0, 0);
        _pad_D_003238D0.h1A |= TkGetControlerTrigHist(0, 0, -1);
        _pad_D_003238D0.h1C = TkGetControlerReptHist(0, 0, 0);
        _pad_D_003238D0.h1C |= TkGetControlerReptHist(0, 0, -1);
        _pad_D_003238D0.b1E = TkGetControlerAnalogHist(0, 0, 2, 0);
        _pad_D_003238D0.b1F = TkGetControlerAnalogHist(0, 0, 3, 0);
        _pad_D_003238D0.h22 = _pad_D_003238D0.h12 & 0xFFF;
        if (_pad_D_003238D0.b1F < 0x18) {
            _pad_D_003238D0.h22 |= 0x1000;
        }
        if (_pad_D_003238D0.b1F >= 0xE9) {
            _pad_D_003238D0.h22 |= 0x4000;
        }
        if (_pad_D_003238D0.b1E < 0x18) {
            _pad_D_003238D0.h22 |= 0x8000;
        }
        if (_pad_D_003238D0.b1E >= 0xE9) {
            _pad_D_003238D0.h22 |= 0x2000;
        }
        _pad_D_003238D0.h24 = _pad_D_003238D0.h22 & (prev ^ _pad_D_003238D0.h22);
        for (i = 0; i < 16; i++) {
            u16 bit = 1 << i;

            if (bit == 0x800 || bit == 0x100) {
                continue;
            }
            if (_pad_D_003238D0.h24 & bit) {
                if (_pad_D_003238D0.rep[i] == 0) {
                    _pad_D_003238D0.h26 |= bit;
                }
            } else {
                _pad_D_003238D0.rep[i]++;
            }
            if ((_pad_D_003238D0.h22 & bit) == 0) {
                _pad_D_003238D0.rep[i] = 0;
            }
            if (_pad_D_003238D0.rep[i] == 14) {
                _pad_D_003238D0.h26 |= bit;
                _pad_D_003238D0.rep[i] = 9;
            }
        }
    }
}

void func_002202D0(void)
{
    func_002EF0D0(&D_003238D0, 0, 0x40);
    D_003238D0.b1E = 0x80;
    D_003238D0.b1F = 0x80;
    D_003238D0.b20 = 0x80;
    D_003238D0.b21 = 0x80;
}

u16 func_00220318(void)
{
    if (TkMenuGetDummyControlerFlag() == 1) {
        return D_003238E2;
    }
    if (D_003238D0.h12 & 0xF000) {
        return D_003238D0.h12;
    }
    return D_003238D0.h22;
}

u16 TOMenuGetControlPadTrg(void)
{
    if (TkMenuGetDummyControlerFlag() == 1) {
        return D_003238E4;
    }
    if (D_003238D0.h12 & 0xF000) {
        return D_003238D0.h14;
    }
    return D_003238D0.h24;
}

u16 TOMenuGetControlPadRep(void)
{
    if (TkMenuGetDummyControlerFlag() == 1) {
        return D_003238E6;
    }
    if (D_003238D0.h12 & 0xF000) {
        return D_003238D0.h16;
    }
    return D_003238D0.h26;
}

u16 func_00220408(void)
{
    return D_003238E2;
}

u16 func_00220418(void)
{
    return D_003238E4;
}

u16 func_00220428(void)
{
    return D_003238E6;
}

u16 TOMenuGetControlPad2(void)
{
    return D_003238E8;
}

u16 func_00220448(void)
{
    return D_003238EA;
}

u16 func_00220458(void)
{
    return D_003238EC;
}

int func_00220468(int a, int b, int c, int d)
{
    if (TkMenuGetDummyControlerFlag() == 1) {
        return TOMenuGetDummyAnalogControler(c) & 0xFF;
    }
    return TkGetControlerAnalogHist(a, b, c, d);
}

void func_002204E0(void)
{
    char buf[0x230]; /* DEBT(PADDING): unused local keeps the original frame size */

    func_001F2F68();
}

void TOGetMainMenuDataP(void)
{
    if (D_003238D0.h14 & 0x40) {
        D_00693088 = 0;
        func_002D70D8(4);
    }
    if (D_003238D0.h14 & 1) {
        func_002D70D8(1);
        D_00692C3C = 1;
        TOInitMessageWindow(7);
        D_00325694 = 2;
    } else {
        if (TOMenuGetControlPadRep() & 0x1000) {
            func_002D70D8(1);
        }
        if (TOMenuGetControlPadRep() & 0x4000) {
            func_002D70D8(1);
        }
    }
}

void TODrawMenuBack(void)
{
    func_001EF940();
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    func_001EF978();
    TODrawKick();
    func_002DA610(0, 0);
}

void func_00220608(void) {
}

void func_00220610(void) {
}

void func_00220618(int a)
{
    if (a == 0) {
        D_00692C3C = 0;
        D_00325694 = 0;
    }
}

void TOMenuAtelStart(void)
{
    AtelCommonSetUp(6, 0x1D34B00, 0x1D36B00, 0x1D3EB00, 0, 0);
    D_00693090 = 1;
}

void TOMenuAtelFree(void)
{
    if (D_00693090 != 0) {
        AtelCtrlRemove(6);
        D_00693090 = 0;
    }
}

void TOMenuAtelReq(int a, int b, int c)
{
    int h = AtelChangeCurrentCtrl(6);

    func_00142688(0xFFFF, b, 0, a, c);
    AtelSetCurrentCtrl(h);
}

s32 func_00220718(void)
{
    return D_00693088;
}

void func_00220728(s32 v)
{
    D_00693088 = (v ^ D_00693088) & 0xFFFF0000;
}

int func_00220748(int a, int b)
{
    if (D_00692C00.n >= 4) {
        return 0;
    }
    D_00692C00.h[D_00692C00.n] = b;
    D_00692C00.w[D_00692C00.n] = a;
    D_00692C00.n++;
    return 1;
}

int func_00220798(int a, int b)
{
    if (D_00692C20.n >= 4) {
        return 0;
    }
    D_00692C20.h[D_00692C20.n] = b;
    D_00692C20.w[D_00692C20.n] = a;
    D_00692C20.n++;
    return 1;
}
