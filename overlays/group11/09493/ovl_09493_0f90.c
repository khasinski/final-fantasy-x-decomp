#include "common.h"

typedef struct {
    u8 pad00[0xF70];
    float fF70[4];
    u8 padF80[0x4790];
    float f5710;
    u8 pad5714[0x14];
    int w5728;
    int w572C;
    int w5730;
} OvlWork;

extern int D_01B08D58;
extern int D_01B08E1C;
extern OvlWork *D_01B08E28;

extern int func_001BBCF8(int, int);
extern int func_01B024A8(int);
extern float func_01B025D0(int);
extern void func_01B026F8(int, void *, int);

void ovl_09493_0f90(void)
{
    OvlWork *s0 = D_01B08E28;

    func_01B026F8(-1, s0->fF70, 0);
    s0->f5710 = func_01B025D0(-1);
    s0->w572C = func_001BBCF8(D_01B08D58, func_01B024A8(0));
    s0->w5728 = -1;
    s0->w5730 = 0;
    D_01B08E1C = 1;
}
