#include "common.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} Ovl9A8;

typedef struct {
    void *p00;
    void *p04;
} Arg8;

typedef struct {
    void *p00;
} Arg4;

extern u8 D_01B00050[];
extern u8 D_01B00990[];
extern Ovl9A8 D_01B009A8;
extern u8 D_01B009C8[];
extern u8 D_01B02270[];
extern void *D_01B0004C;
extern void *D_01B005C8;
extern u8 D_01B0EE70[];
extern void *D_01B0EE9C;
extern void *D_01B0EEA0;
extern u8 D_01BC4920[];
extern u8 D_01DC4920[];

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_01B02D60(void);
extern void func_01B04440(void *);
extern void func_01B05C18(Arg8 *);
extern void func_01B0DDD0(Arg4 *);

int func_01B04498(void)
{
    Arg8 a0;
    Arg4 a1;
    u8 *p;

    func_01B02D60();
    p = D_01DC4920;
    D_01B0EEA0 = p;
    D_01B0004C = p + 0x40000;
    a1.p00 = D_01B00990;
    func_01B0DDD0(&a1);
    a0.p00 = &D_01B009A8;
    a0.p04 = 0;
    func_01B05C18(&a0);
    D_01B009A8.b1B = 1;
    a0.p00 = D_01B009C8;
    a0.p04 = 0;
    func_01B05C18(&a0);
    func_002B4980(D_01B005C8);
    D_01B0EE9C = func_002B49A0(D_01B005C8, 8, 0);
    func_002678E0(D_01B0EE9C, D_01B00050);
    func_00267A68(D_01B0EE70, D_01B0EE9C, D_01BC4920, 0x200000);
    func_002D02E8(D_01B005C8, 0, 1000, 2);
    func_002944B0(D_01B005C8, 0, 1000, 2);
    func_01B04440(D_01B02270);
    return 0;
}
