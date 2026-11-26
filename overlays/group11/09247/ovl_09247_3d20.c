#include "common.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} NodeC38;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B00848;
extern u8 D_01B00C20[];
extern NodeC38 D_01B00C38;
extern u8 D_01B00C58[];
extern u8 D_01B01A40[];
extern u8 D_01B0F750[];
extern void *D_01B0F77C;
extern void *D_01B0F780;
extern u8 D_01C05DC0[];
extern u8 D_01D05DC0[];

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_01B02510(void);
extern void func_01B03CC8(void *);
extern void func_01B05840(void *);
extern void func_01B0E6B0(void **);

int func_01B03D20(void)
{
    void *args[2];
    void *p;
    u8 *base;

    func_01B02510();
    base = D_01D05DC0;
    D_01B0F780 = base;
    D_01B0004C = base + 0x40000;

    p = D_01B00C20;
    func_01B0E6B0(&p);

    args[0] = &D_01B00C38;
    args[1] = 0;
    func_01B05840(args);
    D_01B00C38.b1B = 1;

    args[0] = D_01B00C58;
    args[1] = 0;
    func_01B05840(args);

    func_002B4980(D_01B00848);
    D_01B0F77C = func_002B49A0(D_01B00848, 8, 0);
    func_002678E0(D_01B0F77C, D_01B00050);
    func_00267A68(D_01B0F750, D_01B0F77C, D_01C05DC0, 0x100000);
    func_002D02E8(D_01B00848, 0, 0x10, 2);
    func_002944B0(D_01B00848, 0, 1000, 2);
    func_01B03CC8(D_01B01A40);
    return 0;
}
