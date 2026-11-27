#include "common.h"

extern s32 D_01B0C6F8;
extern s32 D_01B0C6FC;
extern u8 D_01B11E30[];
extern u8 D_01BCD960[];

extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B051A0(void);
extern void func_01B06BD8(void *, s32, s32);
extern void func_01B07308(void);
extern void func_01B074A0(void *, s32, s32);
extern void func_01B074B0(void *, s32, s32);
extern void func_01B079F0(void);
extern void func_01B08470(void);

s32 func_01B01090(s32 a0)
{
    D_01B0C6F8 = a0;
    func_01B051A0();
    func_01B07308();
    func_01B079F0();
    func_01B08470();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B11E30);
    func_01B06BD8(D_01B11E30, 0, 1000);
    func_01B074A0(D_01B11E30, 0, 1000);
    func_002B4980(D_01BCD960);
    func_01B074A0(D_01BCD960, 0, 1000);
    func_002B4980(D_01BCD960);
    func_01B074B0(D_01BCD960, 4, 0);
    func_01B074B0(D_01BCD960, 5, 1);
    D_01B0C6FC = 0;
    return 0;
}
