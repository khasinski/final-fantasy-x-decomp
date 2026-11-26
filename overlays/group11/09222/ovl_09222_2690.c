#include "common.h"

typedef struct {
    void *p00;
    void *p04;
    void *p08;
} Arg12;

extern u8 D_01B007E0[];
extern u8 D_01B016C0[];
extern s16 D_01B016D8;
extern u8 D_01B02588[];

extern void func_01B0E2E0(Arg12 *);
extern void func_01B0E6E8(Arg12 *);

void ovl_09222_2690(void)
{
    Arg12 arg;

    arg.p00 = D_01B016C0;
    arg.p04 = D_01B02588;
    arg.p08 = 0;
    func_01B0E2E0(&arg);
    arg.p00 = D_01B007E0;
    arg.p04 = D_01B016C0;
    func_01B0E6E8(&arg);
    D_01B016D8 = 0;
}
