/* EE Battle-Effect Overlay: group 0x11, file 09643 (0x01B00EE0..0x01B00F80)
 * .text: 1 function (160 bytes)
 */
#include "common.h"

extern int D_01B09358;
extern int D_01B0935C;
extern u8 D_01B0EBE0[];
extern u8 D_01BDE0A0[];

void func_01B02830(void);
void func_01B04998(void);
void func_01B05080(void);
void func_01B05B00(void);
void func_002B22F8(int a0, int a1);
void func_002B4980(void *a0);
void func_01B04268(void *a0, int a1, int a2);
void func_01B04B30(void *a0, int a1, int a2);
void func_01B04B40(void *a0, int a1, int a2);

int func_01B00EE0(int a0)
{
    D_01B09358 = a0;
    func_01B02830();
    func_01B04998();
    func_01B05080();
    func_01B05B00();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0EBE0);
    func_01B04268(D_01B0EBE0, 0, 2);
    func_01B04B30(D_01B0EBE0, 0, 0x3E8);
    func_002B4980(D_01BDE0A0);
    func_01B04B40(D_01BDE0A0, 0, 0);
    D_01B0935C = 0;
    return 0;
}
