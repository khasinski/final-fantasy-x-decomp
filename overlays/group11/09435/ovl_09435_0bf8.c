#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u8 b18;
} Task9435;

typedef struct {
    u8 pad0[0x2C];
    int w2C;
} Ctx9180;

typedef struct {
    u8 pad0[0xD38];
    int wD38;
} Work9435;

extern u8 D_01B00040[];
extern u8 D_01B00628[];
extern void *D_01B00924;
extern int D_01B09178;
extern Ctx9180 D_01B09180;
extern int D_01B091C0;
extern void *D_01B091C4;
extern u8 D_01B091C8[];
extern u8 D_01B09228[];
extern Work9435 *D_01B09248;
extern void *D_01B0924C;
extern u8 D_01B0ED00[];
extern u8 D_01B6F700[];

extern void func_001CDDD8(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B00E28(void);
extern void func_01B01030(void);
extern int func_01B04678(void *);
extern void func_01B04A08(int);
extern Task9435 *func_01B05198(void *);
extern void func_01B05218(void *);
extern void func_01B05360(Task9435 *);
extern void func_01B05420(Ctx9180 *, void *, void *, int);
extern int func_01B055D8(Ctx9180 *, void *);
extern void func_01B06880(void);
extern void func_01B08A88(void *, void *);
extern int func_01B08AA8(void *);
extern void func_01B08BA8(void *, int);
extern int func_01B08CE0(void);

void func_01B00D08(void *);
void func_01B00DA8(void);

int func_01B00BF8(void)
{
    u8 *base = D_01B6F700;
    Ctx9180 *ctx = &D_01B09180;
    Task9435 *t;

    D_01B091C4 = base + 0x40000;
    D_01B091C0 = 0;
    D_01B0924C = base + 0x140000;
    D_01B09248 = (Work9435 *)(base + 0x190000);
    ctx->w2C = func_002B49A0(D_01B0ED00, 8, 0);
    func_01B05420(ctx, D_01B00040, base, 0x40000);
    func_01B00E28();
    func_01B08A88(D_01B091C8, D_01B00628);
    func_01B04A08(1);
    t = func_01B05198((void *)func_01B00D08);
    t->b18 = 1;
    func_01B05360(t);
    func_01B08BA8(base + 0x180000, 0x200);
    t = func_01B05198((void *)func_01B00DA8);
    t->b18 = 2;
    func_01B05360(t);
    return 0;
}

void func_01B00D08(void *a0)
{
    Work9435 *w = D_01B09248;
    int r0;
    int r1;

    func_01B06880();
    D_01B00924 = D_01B0924C;
    r0 = func_01B08AA8(D_01B091C8);
    r1 = func_01B04678(D_01B09228);
    if (r0 != 0 && r1 != 0) {
        w->wD38 = 1;
        func_01B01030();
        func_01B05218(a0);
    }
}

void func_01B00DA8(void)
{
    Work9435 *w = D_01B09248;
    int r = func_01B055D8(&D_01B09180, D_01B091C4);

    if (r == 1 && func_01B08CE0() == 0 && w->wD38 == 1) {
        func_001CDDD8(D_01B09178);
    }
}
