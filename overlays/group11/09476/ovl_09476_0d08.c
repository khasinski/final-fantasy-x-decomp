#include "common.h"

typedef struct {
    u8 pad00[0xF70];
    float fF70[4];
    u8 padF80[0x2400];
    float f3380;
    int w3384;
    int w3388;
} OvlWork;

extern int D_01B0063C;
extern int D_01B0885C;
extern OvlWork *D_01B08868;

extern float func_01B01D48(int);
extern void func_01B01E70(int, void *, int);
extern void func_01B054C0(void *, void *, void *);

void ovl_09476_0d08(void)
{
    float sp00[4];
    float sp10[4];
    float sp20[4];
    int s2;
    OvlWork *s1;

    if (D_01B0063C == 1) {
        s2 = 0;
    } else {
        s2 = 1;
    }
    s1 = D_01B08868;

    func_01B01E70(-1, sp00, 0);
    func_01B01E70(0, sp10, 0);
    func_01B054C0(sp20, sp00, sp10);
    func_01B01E70(-1, s1->fF70, 0);
    s1->f3380 = func_01B01D48(-1);
    s1->w3384 = s2;
    s1->w3388 = 0;
    D_01B0885C = 1;
}
