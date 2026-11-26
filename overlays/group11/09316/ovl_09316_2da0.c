#include "common.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} Ovl908;

typedef struct {
    void *p00;
    void *p04;
} Arg8;

typedef struct {
    void *p00;
} Arg4;

extern u8 D_01B00050[];
extern u8 D_01B008F0[];
extern Ovl908 D_01B00908;
extern u8 D_01B00928[];
extern u8 D_01B019E0[];
extern void *D_01B0004C;
extern void *D_01B00528;
extern u8 D_01B0E130[];
extern void *D_01B0E15C;
extern void *D_01B0E160;
extern u8 D_01BB60D0[];
extern u8 D_01DB60D0[];

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_01B022B0(void);
extern void func_01B02D48(void *);
extern void func_01B03C08(Arg8 *);
extern void func_01B0D098(Arg4 *);

int ovl_09316_2da0(void)
{
    Arg8 a0;
    Arg4 a1;
    u8 *p;

    func_01B022B0();
    p = D_01DB60D0;
    D_01B0E160 = p;
    D_01B0004C = p + 0x40000;
    a1.p00 = D_01B008F0;
    func_01B0D098(&a1);
    a0.p00 = &D_01B00908;
    a0.p04 = 0;
    func_01B03C08(&a0);
    D_01B00908.b1B = 1;
    a0.p00 = D_01B00928;
    a0.p04 = 0;
    func_01B03C08(&a0);
    func_002B4980(D_01B00528);
    D_01B0E15C = func_002B49A0(D_01B00528, 8, 0);
    func_002678E0(D_01B0E15C, D_01B00050);
    func_00267A68(D_01B0E130, D_01B0E15C, D_01BB60D0, 0x200000);
    func_002D02E8(D_01B00528, 0, 1000, 2);
    func_002944B0(D_01B00528, 0, 1000, 2);
    func_01B02D48(D_01B019E0);
    return 0;
}
