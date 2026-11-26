/* EE Battle-Effect Overlay: group 0x11, file 09440 (0x01B00A70..0x01B00B00)
 * .text: 1 function (144 bytes)
 */
#include "common.h"

extern int D_01B0A1F0;
extern int D_01B0A1F4;
extern u8 D_01B10910[];

void func_01B034D0(void);
void func_01B05638(void);
void func_01B05D20(void);
void func_01B067A0(void);
void func_002B22F8(int a0, int a1);
void func_002B4980(void *a0);
void func_01B04F08(void *a0, int a1, int a2);
void func_01B057D0(void *a0, int a1, int a2);
void func_01B057E0(void *a0, int a1, int a2);

int func_01B00A70(int a0)
{
    D_01B0A1F0 = a0;
    func_01B034D0();
    func_01B05638();
    func_01B05D20();
    func_01B067A0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B10910);
    func_01B04F08(D_01B10910, 0, 0x3E8);
    func_01B057D0(D_01B10910, 0, 0x3E8);
    func_01B057E0(D_01B10910, 5, 0);
    D_01B0A1F4 = 0;
    return 0;
}
