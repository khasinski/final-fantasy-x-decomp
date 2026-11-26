#include "common.h"

typedef struct {
    void *p0;
    int w4;
} Arg35F0;

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} ObjAE8;

extern void *D_01B0004C;
extern void *D_01B00708;
extern u8 D_01B00AD0[];
extern ObjAE8 D_01B00AE8;
extern u8 D_01B00B08[];
extern u8 D_01B00050[];
extern u8 D_01B01760[];
extern void *D_01B0DBFC;
extern u8 D_01B0DBD0[];
extern u8 D_01BC70C0[];
extern u8 D_01CC70C0[];

extern void func_01B01CE0(void);
extern void func_01B0CB30(void *);
extern void func_01B035F0(Arg35F0 *);
extern void op_oef2_set2(void *);
extern void *op_oef2_a_get(void *, int, int);
extern void _pppInitData(void *, void *);
extern void pppInitEnv(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void func_01B02788(void *);
extern void func_0029A878(void);

int ovl_09150_27e0(void)
{
    Arg35F0 arg;
    void *p;

    func_01B01CE0();
    D_01B0004C = D_01CC70C0;
    p = D_01B00AD0;
    func_01B0CB30(&p);
    arg.p0 = &D_01B00AE8;
    arg.w4 = 0;
    func_01B035F0(&arg);
    D_01B00AE8.b1B = 1;
    arg.p0 = D_01B00B08;
    arg.w4 = 0;
    func_01B035F0(&arg);
    op_oef2_set2(D_01B00708);
    D_01B0DBFC = op_oef2_a_get(D_01B00708, 8, 0);
    _pppInitData(D_01B0DBFC, D_01B00050);
    pppInitEnv(D_01B0DBD0, D_01B0DBFC, D_01BC70C0, 0x00100000);
    func_002D02E8(D_01B00708, 0, 1000, 2);
    func_002944B0(D_01B00708, 0, 1000, 2);
    func_00294468(op_oef2_a_get(D_01B00708, 6, 3), 0, 2);
    func_01B02788(D_01B01760);
    func_0029A878();
    return 0;
}
