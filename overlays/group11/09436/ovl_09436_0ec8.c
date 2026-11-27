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
extern u8 D_01B007A0[];
extern u8 D_01B00FC8[];
extern u8 D_01B01078[];
extern OvlMgr D_01B09290;
extern void *D_01B092D0;
extern void *D_01B092D4;
extern u8 D_01B092D8[];
extern void *D_01B09358;
extern void *D_01B0935C;
extern u8 D_01B10360[];
extern u8 D_01BD9FC0[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B010E0(void);
extern void func_01B04A58(int);
extern OvlTask *func_01B051E8(void *);
extern void func_01B053B0(OvlTask *);
extern void func_01B05470(void *, void *, void *, int);
extern void func_01B08AD8(void *, void *);

int func_01B00EC8(void)
{
    u8 *p = D_01BD9FC0;
    register OvlMgr *mgr __asm__("$16") = &D_01B09290;
    OvlTask *t;

    D_01B092D0 = 0;
    D_01B092D4 = p + 0x40000;
    D_01B0935C = p + 0x140000;
    D_01B09358 = p + 0x1C0000;
    mgr->w2C = func_002B49A0(D_01B10360, 8, 0);
    func_01B05470(mgr, D_01B00040, p, 0x40000);
    func_01B010E0();
    func_01B08AD8(D_01B092D8, D_01B007A0);
    func_01B04A58(1);
    t = func_01B051E8(D_01B00FC8);
    t->b18 = 1;
    func_01B053B0(t);
    t = func_01B051E8(D_01B01078);
    t->b18 = 2;
    func_01B053B0(t);
    return 0;
}
