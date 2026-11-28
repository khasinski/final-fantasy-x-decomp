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
extern u8 D_01B1EB50[];
extern void *D_006A3924;
extern u8 D_01B00964;
extern u8 D_01B00D30[];
extern NodeTick D_01B00F58;
extern u8 D_01B00F70[];
extern NodeTick D_01B00FB0;
extern u32 D_01B00F50;
extern void *D_01B1FBD8;
extern void *D_01B00B80;

extern void func_01B0B488(void);
extern void func_01B19840(void *);
extern void func_01B1DBE8(void *);
extern void func_01B131F8(void *);
extern void func_002B2F20(void *);
extern void func_001CDDD8(void *);

void func_01B0F2D8(void)
{
    CtxTick ctx;
    void *m[4];

    if (D_01B00044 < 4) {
        return;
    }

    D_006A3924 = D_01B1EB50;
    func_01B0B488();

    ctx.node = D_01B00D30;
    ctx.tick = D_01B00964;
    func_01B19840(&ctx);

    m[0] = &D_01B00F58;
    func_01B1DBE8(m);

    ctx.node = D_01B00F70;
    ctx.tick = D_01B00964;
    func_01B131F8(&ctx);

    ctx.node = &D_01B00FB0;
    ctx.tick = D_01B00964;
    func_01B131F8(&ctx);

    if (D_01B00F58.f10 & D_01B00F50) {
        if (D_01B00FB0.f18 == 0) {
            func_002B2F20(D_01B1FBD8);
            func_001CDDD8(D_01B00B80);
        }
    }
}
