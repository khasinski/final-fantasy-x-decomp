#include "common.h"

typedef struct {
    void *p00;
    u8 pad04;
    u8 b05;
} CallArg0;

typedef struct {
    void *p00;
} CallArg1;

typedef struct {
    u8 pad00[0x10];
    u32 w10;
} Obj880;

typedef struct {
    u8 pad00[0x18];
    u16 h18;
} Obj8B8;

extern void func_002B37A0(void);
extern void func_1B03438(void);
extern void func_1B0F250(CallArg1 *);
extern void func_1B0BD20(CallArg0 *);
extern void func_1B05728(CallArg0 *);
extern void func_001CDDD8(u32);

extern s32 D_01B00044;
extern u32 D_01B00048;
extern u32 D_01B0004C;
extern u32 D_006A3924;
extern u8 D_01B101A0;
extern Obj880 D_01B00880;
extern u8 D_01B00894;
extern u8 D_01B00670;
extern u8 D_01B00898;
extern Obj8B8 D_01B008B8;
extern u32 D_01B004B4;

s32 ovl_09470_3e20(void)
{
    CallArg0 c0;
    CallArg1 c1;

    func_002B37A0();
    if (D_01B00044 < 4) {
        return 0;
    }
    D_006A3924 = (u32)&D_01B101A0;
    D_01B00048 = D_01B0004C;
    func_1B03438();
    D_01B00894++;
    c1.p00 = &D_01B00880;
    func_1B0F250(&c1);
    c0.p00 = &D_01B00670;
    c0.b05 = D_01B00894;
    func_1B0BD20(&c0);
    c0.p00 = &D_01B00898;
    c0.b05 = D_01B00894;
    func_1B05728(&c0);
    c0.p00 = &D_01B008B8;
    c0.b05 = D_01B00894;
    func_1B05728(&c0);
    if ((D_01B00880.w10 & 1) && D_01B008B8.h18 == 0) {
        func_001CDDD8(D_01B004B4);
    }
    return 0;
}
