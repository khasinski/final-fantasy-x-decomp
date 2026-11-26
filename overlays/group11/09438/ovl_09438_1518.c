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
extern u8 D_01B00458[];
extern u8 D_01B01648[];
extern u8 D_01B016F0[];
extern OvlMgr D_01B08F90;
extern void *D_01B08FD0;
extern void *D_01B08FD4;
extern u8 D_01B08FD8[];
extern void *D_01B09058;
extern void *D_01B0905C;
extern void *D_01B09060;
extern u8 D_01B0F660[];
extern u8 D_01B84980[];

extern void *func_002B49A0(void *, int, int);
extern void func_01B01760(void);
extern void func_01B04578(int);
extern OvlTask *func_01B04D08(void *);
extern void func_01B04ED0(OvlTask *);
extern void func_01B04F90(void *, void *, void *, int);
extern void func_01B085F8(void *, void *);
extern void func_01B08888(void *, int);

int ovl_09438_1518(void)
{
    u8 *p = D_01B84980;
    register OvlMgr *mgr __asm__("$16") = &D_01B08F90;
    OvlTask *t;

    D_01B08FD0 = p;
    D_01B08FD4 = p + 0x40000;
    D_01B09060 = p + 0x140000;
    D_01B0905C = p + 0x180000;
    D_01B09058 = p + 0x1F8000;
    mgr->w2C = func_002B49A0(D_01B0F660, 8, 0);
    func_01B04F90(mgr, D_01B00040, D_01B08FD0, 0x40000);
    func_01B01760();
    func_01B085F8(D_01B08FD8, D_01B00458);
    func_01B04578(1);
    t = func_01B04D08(D_01B01648);
    t->b18 = 1;
    func_01B04ED0(t);
    func_01B08888(p + 0x1E8000, 0x200);
    t = func_01B04D08(D_01B016F0);
    t->b18 = 2;
    func_01B04ED0(t);
    return 0;
}
