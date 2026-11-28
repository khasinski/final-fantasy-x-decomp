#include "common.h"

typedef struct {
    void *node;
    u8 dirty;
    u8 tick;
    u16 pad06;
    u32 pad08;
    u32 pad0C;
} CtxTick;

typedef struct {
    u8 pad00[0x10];
    u32 f10 : 1;
    u32 pad10 : 31;
    u32 pad14;
    u16 f18;
} NodeTick;

extern int D_01B00044;
extern u8 D_01B17448[];
extern void *D_006A3924;
extern u8 D_01B00A74;
extern u8 D_01B00830[];
extern NodeTick D_01B00A60;
extern u8 D_01B00A78[];
extern NodeTick D_01B00AB8;
extern u32 D_01B00A58;
extern void *D_01B00678;

extern void func_002B37A0(void);
extern void func_01B04E08(void);
extern void func_01B16460(void *);
extern void func_01B120B8(void *);
extern void func_01B0B428(void *);
extern void func_001CDDD8(void *);

int func_01B071E8(void)
{
    CtxTick ctx;
    void *m[4];

    if (D_01B00044 < 4) {
        return 0;
    }

    func_002B37A0();
    D_006A3924 = D_01B17448;
    func_01B04E08();

    m[0] = &D_01B00A60;
    func_01B16460(m);

    ctx.node = D_01B00830;
    ctx.tick = D_01B00A74;
    func_01B120B8(&ctx);

    ctx.node = D_01B00A78;
    ctx.tick = D_01B00A74;
    func_01B0B428(&ctx);

    ctx.node = &D_01B00AB8;
    ctx.tick = D_01B00A74;
    func_01B0B428(&ctx);

    if (D_01B00A60.f10 & D_01B00A58) {
        if (D_01B00AB8.f18 == 0) {
            func_001CDDD8(D_01B00678);
        }
    }
    return 0;
}
