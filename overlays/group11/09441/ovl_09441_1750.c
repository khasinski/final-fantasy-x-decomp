#include "common.h"

typedef struct OvlMgr {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

extern u8 D_01B00040[];
extern u8 D_01B005B0[];
extern OvlMgr D_01B092E0;
extern void *D_01B09320;
extern void *D_01B09324;
extern u8 D_01B09328[];
extern void *D_01B093A8;
extern void *D_01B093AC;
extern u8 D_01B10250[];
extern u8 D_01C01380[];

extern void func_01B01850(void);
extern void func_01B018E8(void);

void *op_oef2_a_get(void *, int, int);
void func_01B05B70(void *, void *, void *, int);
void func_01B01958(void);
void func_01B08B28(void *, void *);
void func_01B05158(int);
u8 *func_01B058E8(void *);
void func_01B05AB0(void *);

int func_01B01750(void)
{
    u8 *buf = D_01C01380;
    OvlMgr *mgr = &D_01B092E0;
    u8 *t;

    D_01B09324 = buf + 0x40000;
    D_01B093AC = buf + 0x140000;
    D_01B093A8 = buf + 0x1A8000;
    D_01B09320 = buf;
    mgr->w2C = op_oef2_a_get(D_01B10250, 8, 0);
    func_01B05B70(mgr, D_01B00040, D_01B09320, 0x40000);
    func_01B01958();
    func_01B08B28(D_01B09328, D_01B005B0);
    func_01B05158(1);
    t = func_01B058E8(func_01B01850);
    t[0x18] = 1;
    func_01B05AB0(t);
    t = func_01B058E8(func_01B018E8);
    t[0x18] = 2;
    func_01B05AB0(t);
    return 0;
}
