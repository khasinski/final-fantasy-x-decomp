#include "common.h"

typedef struct {
    void *node;
    u8 dirty;
    u8 tick;
    u16 pad06;
    u32 pad08;
    u32 pad0C;
} CtxTick;

extern int D_01B00044;
extern void *D_01B00048;
extern void *D_01B0004C;
extern void *D_01B00678;
extern u8 D_01B00A74;
extern u8 D_01B17448[];
extern void *D_006A3924;
extern u8 D_01B00A48[];
extern u8 D_01B00A98[];
extern u8 D_01B00AD8[];

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(void *, int);
extern void func_01B16460(void *);
extern void func_01B0B428(void *);

int func_01B070B0(void)
{
    CtxTick ctx;
    void *m[4];

    for (;;) {
        switch (D_01B00044) {
        case 0:
            if (func_0029B830(2) == 0) {
                D_01B00044++;
                continue;
            }
            return 0;
        case 1:
            if (func_002D0570(2) != 0) {
                return 0;
            }
            D_01B00044++;
            continue;
        case 2:
            if (func_00294578(2) != 0) {
                return 0;
            }
            func_001CDC58(D_01B00678, 0);
            D_01B00044 = 4;
            break;
        }
        break;
    }

    D_006A3924 = D_01B17448;
    D_01B00048 = D_01B0004C;
    D_01B00A74++;

    m[0] = D_01B00A48;
    func_01B16460(m);

    ctx.node = D_01B00A98;
    ctx.tick = D_01B00A74;
    func_01B0B428(&ctx);

    ctx.node = D_01B00AD8;
    ctx.tick = D_01B00A74;
    func_01B0B428(&ctx);

    return 0;
}
