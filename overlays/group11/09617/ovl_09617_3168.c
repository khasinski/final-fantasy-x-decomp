#include "common.h"

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} ChrWork;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    s32 timer1C;
    s32 cnt20;
    s32 idx24;
    float f28;
    ChrWork *chr2C;
    u8 f30[0x150];
    u8 f180[0x20];
    float f1A0;
    float f1A4;
    float f1A8;
    float f1AC;
    u8 f1B0[0x20];
    u8 f1D0[0x10];
    u8 f1E0[0x20];
    u8 f200[0x10];
} Ovl09617Work;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
} Args10;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
    void *p18;
    void *p1C;
} Args20;

extern u8 D_01B008F0[];
extern u8 D_01B00B00[];
extern u8 D_01B00B18[];
extern void func_01B02EE0(void);

extern void func_01B0E9E0(void *);
extern void func_01B0EDE8(void *);
extern void func_01B08CA8(void *);
extern void func_01B05B50(void *);
extern void func_01B09DA0(void *);
extern void func_01B05E98(void *);
extern void func_01B05610(void *);
extern void func_01B0AA58(void *);
extern void func_01B05808(void *);
extern s32 func_001D3A70(s32);

void func_01B03168(Ovl09617Work *a0, ChrWork *a1) {
    u8 pad00[0x10];
    Args10 a10;
    Args20 a20;
    Args10 *s0 = &a10;

    s0->p04 = func_01B02EE0;
    a10.p00 = a0;
    a10.p08 = a0;
    func_01B0E9E0(s0);

    a10.p00 = D_01B00B00;
    a10.p04 = a0;
    func_01B0EDE8(s0);

    a10.p00 = a0->f180;
    s0->p04 = D_01B00B18;
    func_01B08CA8(s0);

    a10.p00 = a1;
    a10.p04 = &a0->f1A0;
    func_01B05B50(s0);

    *(volatile float *)&a0->f28 = a0->f1A4;
    a0->f1AC = 1.0f;
    *(volatile void **)&a10.p00 = a0->f1E0;
    a0->f1A4 += 25.0f;
    s0->p04 = D_01B00B18;
    func_01B09DA0(s0);

    a10.p00 = a1;
    a10.p04 = a0->f200;
    func_01B05E98(s0);

    a10.p00 = a0->f1B0;
    s0->p04 = D_01B00B18;
    func_01B08CA8(s0);

    a10.p00 = a1;
    a10.p04 = a0->f1D0;
    func_01B05610(s0);

    {
        Args20 *p = &a20;
        a20.p00 = a0->f30;
        p->p04 = D_01B00B18;
        p->p08 = D_01B008F0;
        a20.p0C = a0->f180;
        a20.p10 = a0->f1E0;
        a20.p14 = a0->f1B0;
        func_01B0AA58(p);
    }

    a10.p00 = a1;
    a10.p04 = a0->f30;
    func_01B05808(s0);

    if (func_001D3A70(a1->w54) == 201) {
        a0->idx24 = 0;
    } else {
        a0->idx24 = 1;
    }
    a0->chr2C = a1;
    a0->cnt20 = 0;
    a0->state18 = 0;
}
