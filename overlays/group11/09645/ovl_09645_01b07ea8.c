#include "common.h"

extern s32 D_01B00740;
extern s32 D_01B00BAC;
extern u8 D_01B00BC0[];
extern s32 D_01B02400;
extern s32 D_01B02640;

void func_00101D08(s32, s32);
void func_00103208(s32);
void func_00104EF0(s32, s32);
void func_00110830(s32, s32);
void func_00118F70(s32, s32, s32, s32);
void func_001CE2F0(s32, s32);
void func_001CE4F8(s32);
void func_01B08F38(void *);

s32 func_01B07EA8(void)
{
    void *args[1];

    func_00118F70(0, 0, 0, 0);
    func_00103208(D_01B00BAC);
    func_00101D08(0x300F, 0);
    func_00104EF0(0x300F, 1);
    func_00110830(D_01B02400, 0);
    func_00110830(D_01B02640, 0);
    args[0] = D_01B00BC0;
    func_01B08F38(args);
    func_001CE4F8(D_01B00740);
    func_001CE2F0(D_01B00740, 0);
    return 0;
}
