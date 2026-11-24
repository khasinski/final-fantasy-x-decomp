#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 f18;
} TaskObj;

typedef struct {
    u8 pad00[0x2C];
    void *p2C;
} Env8FE0;

extern u8 D_01B00040[];
extern u8 D_01B006A8[];
extern u8 D_01B00820[];
extern Env8FE0 D_01B08FE0;
extern int D_01B09020;
extern u8 *D_01B09024;
extern u8 D_01B09028[];
extern u8 D_01B09088[];
extern u8 *D_01B09148;
extern u8 *D_01B0914C;
extern u8 D_01B0E8A0[];
extern u8 D_01BF7400[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B01058(void);
extern void func_01B01140(void);
extern void func_01B011A8(void);
extern void func_01B01358(void);
extern void func_01B03F08(int);
extern TaskObj *func_01B04698(void *);
extern void func_01B04860(TaskObj *);
extern void func_01B04920(void *, void *, void *, int);
extern void func_01B07F88(void *, void *);
extern void func_01B085A0(void *, int);

int func_01B00F30(void)
{
    u8 *mem = D_01BF7400;
    Env8FE0 *e = &D_01B08FE0;
    TaskObj *t;

    D_01B09024 = mem + 0x40000;
    D_01B09020 = 0;
    D_01B0914C = mem + 0x120000;
    D_01B09148 = mem + 0x180000;
    __asm__("" : "+r"(e));
    e->p2C = func_002B49A0(D_01B0E8A0, 8, 0);
    func_01B04920(e, D_01B00040, mem, 0x40000);
    func_01B011A8();
    func_01B01358();
    func_01B07F88(D_01B09028, D_01B006A8);
    func_01B07F88(D_01B09088, D_01B00820);
    func_01B03F08(1);
    t = func_01B04698(func_01B01058);
    t->f18 = 1;
    func_01B04860(t);
    func_01B085A0(mem + 0x160000, 0x400);
    t = func_01B04698(func_01B01140);
    t->f18 = 2;
    func_01B04860(t);
    return 0;
}
