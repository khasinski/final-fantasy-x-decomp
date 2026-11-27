#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01BEC010[];
extern u8 D_01CD5A40[];
extern u8 D_01B0F920[];
extern u8 D_01B00040[];
extern u8 D_01B00848[];
extern u8 D_01B00C88[];
extern u8 D_01B0A0B8[];
extern u8 D_01B0A100[];
extern u8 D_01B0A160[];
extern u8 D_01B0A1C0[];
extern u32 D_01B0A0B0;
extern u32 D_01B0A0F8;
extern void *D_01B0A0FC;
extern u32 D_01B0A1D4;
extern u8 *D_01B0A1E0;
extern void *D_01B0A1E4;
extern void *D_01B0A1E8;
extern void *D_01B01244;

void func_002B4980(void *a0);
void *func_002B49A0(void *a0, int a1, int a2);
void func_01B06190(void *a0, void *a1, void *a2, int a3);
void func_01B017B8(void);
void func_01B01A70(void);
void func_01B018D0(void);
void func_01B097F8(void *a0, void *a1);
void func_01B05778(int a0);
void func_00293F10(int a0);
void func_001CF840(int a0);
u8 *func_01B05F08(void *fn);
void func_01B060D0(void *a0);
void func_01B01698(void *a0);
void func_01B01750(void);
void func_01B075F0(void);
int func_01B09818(void *a0);
void func_01B053E8(void *a0);
void func_01B019D8(void *a0);
void func_01B07E18(void);
void func_01B01940(void);
void func_01B05F88(void *a0);
int func_01B06348(void *a0, void *a1);
void func_001CDDD8(u32 a0);
void func_01B03948(int a0, void *a1, int a2);
float func_01B03820(int a0);
void func_01B04BB8(int a0, void *a1);
void func_01B05138(int a0, void *a1, void *a2);
void func_01B046B0(int a0, int a1);
void func_01B04610(int a0, int a1);
void func_01B019A8(void *a0, int a1);
void func_01B07CA0(int a0);
u8 *func_01B07FD0(int a0);
void func_002DD128(void *a0);
void func_002DD318(void *a0, void *a1, float a2);
void func_01B049E0(int a0, int a1);
void func_01B049B0(int a0, int a1);
void func_01B04B28(int a0, int a1, float a2);
void func_01B07DE0(void);
void func_01B044A0(int a0);
void func_01B05798(int a0);

int func_01B01548(void)
{
    u8 *s0;
    u8 *s1;
    u8 *p;

    func_002B4980(D_01BEC010);
    s0 = D_01CD5A40;
    D_01B0A0F8 = 0;
    D_01B0A0FC = s0 + 0x40000;
    D_01B0A1E8 = s0 + 0x140000;
    D_01B0A1E4 = s0 + 0x180000;
    D_01B0A1E0 = s0 + 0x1C0000;
    s1 = D_01B0A0B8;
    *(void **)(s1 + 0x2C) = func_002B49A0(D_01B0F920, 8, 0);
    func_01B06190(s1, D_01B00040, s0, 0x40000);
    func_01B017B8();
    func_01B01A70();
    func_01B018D0();
    func_01B097F8(D_01B0A100, D_01B00848);
    func_01B097F8(D_01B0A160, D_01B00C88);
    func_01B05778(1);
    func_00293F10(0);
    func_001CF840(0);
    p = func_01B05F08(func_01B01698);
    p[0x18] = 1;
    func_01B060D0(p);
    p = func_01B05F08(func_01B01750);
    p[0x18] = 2;
    func_01B060D0(p);
    return 0;
}

void func_01B01698(void *a0)
{
    u8 *s1 = D_01B0A1E0;
    int s0;

    func_01B075F0();
    D_01B01244 = D_01B0A1E8;
    s0 = func_01B09818(D_01B0A100);
    func_01B09818(D_01B0A160);
    if (s0 == 0) {
        {
            register u8 *dst __asm__("$2") = s1 + 0x9B0;
            register u8 *src __asm__("$3") = s1 + 0xA50;
            MMI_COPY_LQ_A3_V0(src, dst);
            MMI_COPY_SQ_A3_V1(dst);
        }
        func_01B053E8(D_01B0A1C0);
        func_01B019D8(s1 + 0xE40);
        func_01B07E18();
    } else {
        *(int *)(s1 + 0x3158) = 1;
        func_01B01940();
        func_01B05F88(a0);
    }
}

void func_01B01750(void)
{
    u8 *s0 = D_01B0A1E0;

    if (func_01B06348(D_01B0A0B8, D_01B0A0FC) == 1) {
        if (*(int *)(s0 + 0x3158) == 1) {
            func_001CDDD8(D_01B0A0B0);
        }
    }
}

void func_01B017B8(void)
{
    float v0[4];
    float v1[4];
    register u8 *s1 __asm__("$17") = D_01B0A1E0;
    u8 *s0;
    u8 *s3;
    u8 *p;

    func_01B03948(-1, v0, 0);
    {
        register u8 *dst __asm__("$2") = s1 + 0xA60;
        MMI_COPY_LQ_A3_V0(v0, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    v1[0] = 0.0f;
    v1[1] = func_01B03820(-1);
    v1[2] = 0.0f;
    v1[3] = 0.0f;
    {
        register u8 *dst __asm__("$2") = s1 + 0xA40;
        register float *src __asm__("$18") = v1;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    {
        register u8 *dst __asm__("$19") = s1 + 0xA50;
        MMI_COPY_LQ_A3_V0(v0, dst);
        MMI_COPY_SQ_A3_V1(dst);
        s3 = dst;
    }
    s0 = s1 + 0x980;
    func_01B04BB8(-1, s0);
    func_01B05138(-1, s0, v1);
    {
        register u8 *dst __asm__("$2") = s1 + 0x9B0;
        MMI_COPY_LQ_A3_V0(s3, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    func_01B046B0(-1, 1);
    func_01B04610(-1, 0);
    *(float *)(s1 + 0x3148) = v1[1];
    p = s1 + 0xE40;
    *(int *)(s1 + 0xE40) = 0;
    *(int *)(p + 0x04) = 0;
    *(int *)(p + 0x08) = 0;
    *(int *)(p + 0x0C) = 0x80;
    func_01B019A8(p, 1);
    *(int *)(s1 + 0x3140) = 0;
    *(int *)(s1 + 0x3144) = 0;
    *(int *)(s1 + 0x3158) = 0;
    D_01B0A1D4 = 1;
}

void func_01B018D0(void)
{
    u8 *s1 = D_01B0A1E0;
    u8 *s0;

    func_01B07CA0(0);
    s0 = func_01B07FD0(0);
    s0[0x146] = 1;
    func_002DD128(s0);
    func_002DD318(s0, s0, *(float *)(s1 + 0x3148));
    {
        u8 *dst = s0 + 0x30;
        u8 *src = s1 + 0xA50;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
}

void func_01B01940(void)
{
    func_01B049E0(-1, 0);
    func_01B049B0(-1, -1);
    func_01B04B28(-1, 1, 1.0f);
    func_01B07DE0();
    func_00293F10(1);
    func_001CF840(1);
    func_01B044A0(-1);
    func_01B05798(1);
}

void func_01B019A8(void *a0, int a1)
{
    u8 *v0 = D_01B0A1E0;
    u8 *a2 = v0 + 0xE40;

    {
        register u8 *dst __asm__("$3") = v0 + 0xE50;
        MMI_COPY_LQ_A3_V0(a2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    {
        register u8 *dst __asm__("$2") = v0 + 0xE60;
        MMI_COPY_LQ_A3_V0(a0, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    *(int *)(a2 + 0x34) = a1;
    *(int *)(a2 + 0x30) = a1;
}
