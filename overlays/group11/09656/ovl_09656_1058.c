#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01BABFD0[];
extern u8 D_01BC7140[];
extern u8 D_01B100E0[];
extern u8 D_01B00040[];
extern u8 D_01B00810[];
extern u8 D_01B009B0[];
extern u8 D_01B0A860[];
extern u32 D_01B0A8A0;
extern void *D_01B0A8A4;
extern u8 D_01B0A8A8[];
extern u8 D_01B0A908[];
extern u8 D_01B0A968[];
extern u8 *D_01B0A988;
extern void *D_01B0A98C;
extern void *D_01B0A990;
extern void *D_01B00D64;

void func_002B4980(void *a0);
void *func_002B49A0(void *a0, int a1, int a2);
void func_01B06010(void *a0, void *a1, void *a2, int a3);
void func_01B012B8(void);
void func_01B01A90(void);
void func_01B055F8(int a0);
void func_01B09678(void *a0, void *a1);
u8 *func_01B05D88(void *fn);
void func_01B05F50(void *a0);
void func_01B09E20(void *a0, int a1);
void func_01B011A0(void *a0);
void func_01B01250(void);
void func_01B07470(void);
int func_01B09698(void *a0);
void func_01B05268(void *a0);
void func_01B07C98(void);
void func_01B01D88(void);
void func_01B05E08(void *a0);

int func_01B01058(void)
{
    u8 *s1;
    u8 *s0;
    u8 *p;

    func_002B4980(D_01BABFD0);
    s1 = D_01BC7140;
    D_01B0A8A0 = 0;
    D_01B0A8A4 = s1 + 0x40000;
    D_01B0A990 = s1 + 0x140000;
    D_01B0A98C = s1 + 0x170000;
    D_01B0A988 = s1 + 0x200000;
    s0 = D_01B0A860;
    *(void **)(s0 + 0x2C) = func_002B49A0(D_01B100E0, 8, 0);
    func_01B06010(s0, D_01B00040, s1, 0x40000);
    func_01B012B8();
    func_01B01A90();
    func_01B055F8(1);
    func_01B09678(D_01B0A8A8, D_01B00810);
    func_01B09678(D_01B0A908, D_01B009B0);
    p = func_01B05D88(func_01B011A0);
    p[0x18] = 1;
    func_01B05F50(p);
    func_01B09E20(s1 + 0x1F0000, 0x200);
    p = func_01B05D88(func_01B01250);
    p[0x18] = 2;
    func_01B05F50(p);
    return 0;
}
