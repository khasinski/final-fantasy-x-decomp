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
extern u8 D_01B00580[];
extern u8 D_01B00C18[];
extern u8 D_01B00CA0[];
extern OvlMgr D_01B087A0;
extern void *D_01B087E0;
extern void *D_01B087E4;
extern u8 D_01B087E8[];
extern void *D_01B08868;
extern u8 D_01B0EB10[];
extern u8 D_01BB2580[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B00D08(void);
extern void func_01B03CA0(int);
extern OvlTask *func_01B04430(void *);
extern void func_01B045F8(OvlTask *);
extern void func_01B046B8(void *, void *, void *, int);
extern void func_01B08280(void *, void *);
extern void func_01B086B8(void *, int);

int ovl_09476_0b18(void)
{
    u8 *p = D_01BB2580;
    register OvlMgr *mgr __asm__("$16") = &D_01B087A0;
    OvlTask *t;

    D_01B087E0 = 0;
    D_01B087E4 = p + 0xE0000;
    D_01B08868 = p + 0x29F400;
    mgr->w2C = func_002B49A0(D_01B0EB10, 8, 0);
    func_01B046B8(mgr, D_01B00040, p, 0xE0000);
    func_01B00D08();
    func_01B086B8(p + 0x280000, 0x190);
    func_01B08280(D_01B087E8, D_01B00580);
    func_01B03CA0(1);
    t = func_01B04430(D_01B00C18);
    t->b18 = 1;
    func_01B045F8(t);
    t = func_01B04430(D_01B00CA0);
    t->b18 = 2;
    func_01B045F8(t);
    return 0;
}
