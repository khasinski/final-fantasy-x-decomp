#include "common.h"

extern u32 D_01B0A2F0;
extern u32 D_01B0A2F4;
extern u8 D_01B0FA30[];
extern u8 D_01BDDF90[];

void func_01B033F0(void);
void func_01B05558(void);
void func_01B05C40(void);
void func_01B066C0(void);
void func_002B22F8(int a0, int a1);
void func_002B4980(void *a0);
void func_01B04E28(void *a0, int a1, int a2);
void func_01B056F0(void *a0, int a1, int a2);
void func_01B05700(void *a0, int a1, int a2);

int func_01B011B0(u32 a0)
{
    D_01B0A2F0 = a0;
    func_01B033F0();
    func_01B05558();
    func_01B05C40();
    func_01B066C0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0FA30);
    func_01B04E28(D_01B0FA30, 0, 0x12);
    func_01B056F0(D_01B0FA30, 0, 0x3E8);
    func_002B4980(D_01BDDF90);
    func_01B056F0(D_01BDDF90, 0, 0x3E8);
    func_002B4980(D_01BDDF90);
    func_01B05700(D_01BDDF90, 3, 0);
    func_01B05700(D_01BDDF90, 4, 1);
    D_01B0A2F4 = 0;
    return 0;
}
