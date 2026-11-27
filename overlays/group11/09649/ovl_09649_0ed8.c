#include "common.h"

extern u8 D_01B88370[];
extern u8 D_01BA4000[];
extern u8 D_01B00040[];
extern u8 D_01B006B8[];
extern u8 D_01B0B130[];
extern s32 D_01B0B170;
extern u8 *D_01B0B174;
extern u8 D_01B0B178[];
extern u8 *D_01B0B1F8;
extern u8 *D_01B0B1FC;
extern u8 *D_01B0B204;
extern u8 D_01B10960[];

extern void func_002B4980(void *);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B01008(void);
extern void func_01B010B8(void);
extern void func_01B01120(void);
extern void func_01B019D0(void);
extern void func_01B05EC8(s32);
extern u8 *func_01B06658(void (*)(void));
extern void func_01B06820(void *);
extern void func_01B068E0(void *, void *, void *, s32);
extern void func_01B09F48(void *, void *);
extern void func_01B0A6F0(void *, s32);

s32 func_01B00ED8(void)
{
    u8 *s1;
    u8 *s0;
    u8 *p;

    func_002B4980(D_01B88370);
    s1 = D_01BA4000;
    D_01B0B170 = 0;
    D_01B0B174 = s1 + 0x40000;
    D_01B0B204 = s1 + 0x160000;
    D_01B0B1FC = s1 + 0x190000;
    D_01B0B1F8 = s1 + 0x220000;
    s0 = D_01B0B130;
    *(s32 *)(s0 + 0x2C) = func_002B49A0(D_01B10960, 8, 0);
    func_01B068E0(s0, D_01B00040, s1, 0x40000);
    func_01B01120();
    func_01B019D0();
    func_01B05EC8(1);
    func_01B09F48(D_01B0B178, D_01B006B8);
    p = func_01B06658(func_01B01008);
    p[0x18] = 1;
    func_01B06820(p);
    func_01B0A6F0(s1 + 0x210000, 0x200);
    p = func_01B06658(func_01B010B8);
    p[0x18] = 2;
    func_01B06820(p);
    return 0;
}
