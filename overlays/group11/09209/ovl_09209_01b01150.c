#include "common.h"

extern int D_01B0BC28;
extern int D_01B0BC2C;
extern u8 D_01B123A0[];
extern u8 D_01BEEE00[]; /* 0x01BEEEF0 */

extern void func_01B04968(void);
extern void func_01B06AD0(void);
extern void func_01B071B8(void);
extern void func_01B07C38(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B063A0(void *, int, int);
extern void func_01B06C68(void *, int, int);
extern void func_01B06C78(void *, int, int);

int func_01B01150(int a0)
{
    D_01B0BC28 = a0;
    func_01B04968();
    func_01B06AD0();
    func_01B071B8();
    func_01B07C38();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B123A0);
    func_01B063A0(D_01B123A0, 0, 0x3E8);
    func_01B06C68(D_01B123A0, 0, 0x3E8);
    func_002B4980(D_01BEEE00);
    func_01B06C68(D_01BEEE00, 0, 0x3E8);
    func_002B4980(D_01BEEE00);
    func_01B06C78(D_01BEEE00, 3, 0);
    func_01B06C78(D_01BEEE00, 4, 1);
    D_01B0BC2C = 0;
    return 0;
}
