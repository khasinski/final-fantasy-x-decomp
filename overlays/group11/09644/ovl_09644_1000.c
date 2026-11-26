#include "common.h"

typedef struct {
    u8 pad00[0x4];
    s32 w04;
    u8 pad08[0xD];
    u8 b15;
    u8 pad16[0xA6];
    void *pBC;
} WorkA90;

typedef struct {
    u8 pad00[0x2C];
    void *p2C;
} Work8948;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

extern u8 D_01BFADC0[];
extern u8 D_01B00040[];
extern u8 D_01B00810[];
extern u8 D_01B00938[];
extern WorkA90 D_01B00A90;
extern Work8948 D_01B08948;
extern s32 D_01B08988;
extern void *D_01B0898C;
extern u8 D_01B08990[];
extern u8 D_01B089F0[];
extern void *D_01B08A90;
extern void *D_01B08A94;
extern u8 D_01B0E1E0[];

extern void *MsGetChrHandle(int);
extern void *op_oef2_a_get(void *, int, int);
extern void func_01B04648(void *, void *, void *, int);
extern void func_01B012C8(void);
extern void func_01B01408(void);
extern void func_01B07CB0(void *, void *);
extern void func_01B03C30(int);
extern void func_01B08860(void *, int);
extern TaskObj *func_01B043C0(void *);
extern void func_01B04588(TaskObj *);
extern void func_01B082C8(void *, int);
extern void func_01B01170(void);
extern void func_01B01260(void);

int func_01B01000(void)
{
    u8 *base = D_01BFADC0;
    TaskObj *t;
    Work8948 *w;

    D_01B08988 = 0;
    D_01B0898C = base + 0x40000;
    D_01B08A94 = base + 0x140000;
    D_01B08A90 = base + 0x1D1400;

    D_01B00A90.b15 = 0x1E;
    {
        void *h = MsGetChrHandle(0x1E);
        w = &D_01B08948;
        __asm__("" : "+r"(w) : "r"(h));
        D_01B00A90.w04 = 2;
        D_01B00A90.pBC = h;
    }
    w->p2C = op_oef2_a_get(D_01B0E1E0, 8, 0);
    func_01B04648(w, D_01B00040, base, 0x40000);
    func_01B012C8();
    func_01B01408();
    func_01B07CB0(D_01B08990, D_01B00810);
    func_01B07CB0(D_01B089F0, D_01B00938);
    func_01B03C30(1);
    func_01B08860(base + 0x1D0000, 0x10);

    t = func_01B043C0((void *)func_01B01170);
    t->b18 = 1;
    func_01B04588(t);

    func_01B082C8(base + 0x1B0000, 0x400);

    t = func_01B043C0((void *)func_01B01260);
    t->b18 = 2;
    func_01B04588(t);
    return 0;
}
