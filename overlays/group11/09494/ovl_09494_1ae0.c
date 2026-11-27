#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} MgrA228;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

extern u8 D_01B00040[];
extern u8 D_01B007C8[];
extern MgrA228 D_01B0A228;
extern int D_01B0A268;
extern u8 *D_01B0A26C;
extern u8 D_01B0A270[];
extern u8 *D_01B0A310;
extern u8 *D_01B0A314;
extern u8 *D_01B0A318;
extern u8 D_01B12090[];
extern u8 D_01BF7380[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B01C18(void);
extern void func_01B01D00(void);
extern void func_01B01D80(void);
extern void func_01B05618(int);
extern TaskObj *func_01B05DA8(void *);
extern void func_01B05F70(TaskObj *);
extern void func_01B06030(void *, void *, void *, int);
extern void func_01B09698(void *, void *);
extern void func_01B09BA8(void *, int);
extern void func_01B0A140(void *, int);

int func_01B01AE0(void)
{
    u8 *p = D_01BF7380;
    MgrA228 *mgr;
    TaskObj *t;

    D_01B0A268 = 0;
    D_01B0A26C = p + 0x40000;
    D_01B0A318 = p + 0x140000;
    D_01B0A314 = p + 0x180000;
    D_01B0A310 = p + 0x1F5000;
    mgr = &D_01B0A228;
    mgr->w2C = func_002B49A0(D_01B12090, 8, 0);
    func_01B06030(mgr, D_01B00040, p, 0x40000);
    func_01B01D80();
    func_01B0A140(p + 0x1F0000, 0x40);
    func_01B09698(D_01B0A270, D_01B007C8);
    func_01B05618(1);
    t = func_01B05DA8((void *)func_01B01C18);
    t->b18 = 1;
    func_01B05F70(t);
    func_01B09BA8(p + 0x1E8000, 0x100);
    t = func_01B05DA8((void *)func_01B01D00);
    t->b18 = 2;
    func_01B05F70(t);
    return 0;
}
