#include "common.h"

typedef struct {
    u8 pad00[0x14];
    int w14;
} Timer9360;

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    int w10;
    int w14;
    int w18;
    float f1C;
    int w20;
    int w24;
    int w28;
    float f2C;
    u8 sub30[0xC];
    float f3C;
    u8 pad40[0xC];
    int w4C;
    int w50;
} Part10F0_9360;

typedef struct {
    u8 pad000[0x100];
    void *p100;
    u8 pad104[0x18];
    int w11C;
} Part1270_9360;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x8];
    int w94;
    u8 b98;
    u8 b99;
} Obj9360_2;

extern Obj9360_2 *D_01B0839C;
extern u8 D_01B0DBB0[];

extern void func_01B03FE8(void *);
extern Part10F0_9360 *func_01B07E00(void);
extern void func_01B019A8(int, float *, int);
extern int func_002B49A0(void *, int, int);
extern void func_01B05690(void *, int);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B02B28(int, int, float, float, float);
extern void func_01B02B88(int, int, float);
extern void func_01B02670(int, int);
extern void func_01B07978(void *, int);

void func_01B012B8(void);

void func_01B010F0(Timer9360 *a0)
{
    float pos[4];

    if (--a0->w14 <= 0) {
        func_01B03FE8(a0);
    }
    if ((a0->w14 & 1) == 0) {
        Part10F0_9360 *s1 = func_01B07E00();
        if (s1 != 0) {
            void *s0 = s1->sub30;
            func_01B019A8(-1, pos, 3);
            func_01B05690(s0, func_002B49A0(D_01B0DBB0, 9, 0));
            s1->f00 = pos[0] + func_002B3DB0(35.0f);
            s1->f04 = pos[1] - func_002B3DF8(50.0f) - 8.0f;
            s1->f08 = pos[2] + func_002B3DB0(35.0f);
            s1->f0C = 1.0f;
            s1->w20 = 0;
            s1->w24 = 0;
            s1->w28 = 0;
            s1->f2C = 1.0f;
            s1->w10 = 0;
            s1->w14 = 0;
            s1->w18 = 0;
            s1->f1C = func_002B3DB0(3.1415927410125732f);
            s1->f3C = (func_002B3DF8(1.0f) + 1.0f) * 0.17f;
            s1->w50 = 0;
            s1->w4C = -1;
        }
    }
}

void func_01B01250(void)
{
    func_01B02B28(-1, 0x10, 2.0f, 2.0f, 2.0f);
}

void func_01B01270(Part1270_9360 *a0)
{
    func_01B02B88(-1, 0x1E, 0.0f);
    a0->w11C = 0x5A;
    a0->p100 = func_01B012B8;
}

void func_01B012B8(void)
{
    func_01B02670(-1, 0);
}

void func_01B012C8(void)
{
    Obj9360_2 *s0 = D_01B0839C;

    func_01B07978(s0, 0x10);
    s0->b83 = 0x80;
    s0->b82 = 0x80;
    s0->b81 = 0x80;
    s0->b80 = 0x80;
    s0->b87 = 0;
    s0->b86 = 0;
    s0->b85 = 0;
    s0->b84 = 0;
    s0->w88 = 0;
    s0->w94 = 0;
    s0->b98 = 0x48;
    s0->b99 = 0;
}
