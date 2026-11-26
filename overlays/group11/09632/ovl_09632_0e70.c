#include "common.h"

extern int D_01B09550;
extern int D_01B09554;
extern u8 D_01B0EDE0[];
extern u8 D_01BDD340[];

extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B02650(void);
extern void func_01B04088(void *, int, int);
extern void func_01B047B8(void);
extern void func_01B04950(void *, int, int);
extern void func_01B04960(void *, int, int);
extern void func_01B04EA0(void);
extern void func_01B05920(void);

int func_01B00E70(int a0)
{
    D_01B09550 = a0;
    func_01B02650();
    func_01B047B8();
    func_01B04EA0();
    func_01B05920();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0EDE0);
    func_01B04088(D_01B0EDE0, 0, 0x12);
    func_01B04950(D_01B0EDE0, 0, 1000);
    func_002B4980(D_01BDD340);
    func_01B04950(D_01BDD340, 0, 1000);
    func_002B4980(D_01BDD340);
    func_01B04960(D_01BDD340, 2, 0);
    D_01B09554 = 0;
    return 0;
}
