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
extern u8 D_01B1E340[];
extern void *D_006A3924;
extern u8 D_01B00CEC;
extern u8 D_01B00AB0[];
extern NodeTick D_01B00CD8;
extern u8 D_01B00CF0[];
extern NodeTick D_01B00D30;
extern u32 D_01B00CD0;
extern void *D_01B00900;

extern void func_01B0C3A8(void);
extern void func_01B19038(void *);
extern void func_01B1D3E0(void *);
extern void func_01B12F80(void *);
extern void func_001CDDD8(void *);

int func_01B0FBB8(void)
{
    CtxTick ctx;
    void *m[4];

    if (D_01B00044 < 4) {
        return 0;
    }

    D_006A3924 = D_01B1E340;
    func_01B0C3A8();

    {
        register u32 t __asm__("$5") = (u8)++D_01B00CEC;
        __asm__("" : "+r"(t));
        ctx.node = D_01B00AB0;
        ctx.tick = t;
        func_01B19038(&ctx);
    }

    m[0] = &D_01B00CD8;
    func_01B1D3E0(m);

    ctx.node = D_01B00CF0;
    ctx.tick = D_01B00CEC;
    func_01B12F80(&ctx);

    ctx.node = &D_01B00D30;
    ctx.tick = D_01B00CEC;
    func_01B12F80(&ctx);

    if (D_01B00CD8.f10 & D_01B00CD0) {
        if (D_01B00D30.f18 == 0) {
            func_001CDDD8(D_01B00900);
        }
    }
    return 0;
}
