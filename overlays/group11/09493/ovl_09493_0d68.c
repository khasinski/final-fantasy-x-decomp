#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

extern u8 D_01B00040[];
extern u8 D_01B007A8[];
extern u8 D_01B00E68[];
extern u8 D_01B00F18[];
extern OvlMgr D_01B08D60;
extern void *D_01B08DA0;
extern void *D_01B08DA4;
extern u8 D_01B08DA8[];
extern void *D_01B08E28;
extern void *D_01B08E2C;
extern u8 D_01B0F3A0[];
extern u8 D_01BD8DC0[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B00F90(void);
extern void func_01B04528(int);
extern OvlTask *func_01B04CB8(void *);
extern void func_01B04E80(OvlTask *);
extern void func_01B04F40(void *, void *, void *, int);
extern void func_01B085A8(void *, void *);

int ovl_09493_0d68(void)
{
    u8 *p = D_01BD8DC0;
    register OvlMgr *mgr __asm__("$16") = &D_01B08D60;
    OvlTask *t;

    D_01B08DA0 = 0;
    D_01B08DA4 = p + 0x40000;
    D_01B08E2C = p + 0x140000;
    D_01B08E28 = p + 0x1C0000;
    mgr->w2C = func_002B49A0(D_01B0F3A0, 8, 0);
    func_01B04F40(mgr, D_01B00040, p, 0x40000);
    func_01B00F90();
    func_01B085A8(D_01B08DA8, D_01B007A8);
    func_01B04528(1);
    t = func_01B04CB8(D_01B00E68);
    t->b18 = 1;
    func_01B04E80(t);
    t = func_01B04CB8(D_01B00F18);
    t->b18 = 2;
    func_01B04E80(t);
    return 0;
}
