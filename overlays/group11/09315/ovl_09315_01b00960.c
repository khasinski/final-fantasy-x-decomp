#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 unk18;
} Ovl09315Proc;

typedef struct {
    u8 pad00[0x2C];
    int unk2C;
} Ovl09315G6320;

typedef struct {
    u8 pad00[0xC4];
    float unkC4;
    u8 padC8[0x08];
    u8 unkD0[0x34];
    void (*unk104)(void);
} Ovl09315G6360;

extern u8 D_01B9A340[];
extern u8 D_01B0BCC0[];
extern u8 D_01B00040[];
extern u8 D_01B004E0[];
extern u8 D_01B062F8[];
extern u8 *D_01B06318;
extern u8 *D_01B0631C;
extern Ovl09315G6320 D_01B06320;
extern Ovl09315G6360 D_01B06360;
extern u8 *D_01B066F0;
extern u8 *D_01B066F4;

extern void func_01B00B78(void);
extern void func_01B00BA8(void);
extern void func_01B00C28(void);
extern void func_01B01248(void);

extern int func_002B49A0(void *, int, int);
extern void func_01B04558(void *, void *, void *, int);
extern void func_01B04630(void *, void *, int, int, int, int, float);
extern void func_01B01D10(int, void *, int);
extern float func_01B01BE8(int);
extern void func_01B05360(float *, float *, float *);
extern void func_01B060B0(void *, int, int, float, float);
extern void func_01B03B40(int);
extern void func_01B03CD8(void *, int, int, int);
extern void func_01B036F8(int, void *, void *);
extern Ovl09315Proc *func_01B042D0(void (*)(void));
extern void func_01B04498(Ovl09315Proc *);

int func_01B00960(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *p;
    u8 *s1;
    u8 *s2;
    Ovl09315Proc *proc;
    Ovl09315G6320 *g6320;

    p = D_01B9A340;
    D_01B066F0 = p;
    D_01B066F4 = p + 0x40000;
    D_01B0631C = p + 0x140000;
    D_01B06318 = p + 0x180000;

    g6320 = &D_01B06320;
    g6320->unk2C = func_002B49A0(D_01B0BCC0, 8, 0);
    func_01B04558(g6320, D_01B00040, D_01B066F0, 0x40000);
    func_01B04630(g6320, &D_01B06360, 0, 0x1E, 0, 0, 0.055f);
    func_01B01D10(-1, D_01B06360.unkD0, 0);
    D_01B06360.unkC4 = func_01B01BE8(-1);
    D_01B06360.unk104 = func_01B01248;

    s1 = D_01B06318;
    func_01B01D10(-1, v0, 0);
    s2 = s1 + 0x1E80;
    func_01B01D10(0, v1, 0);
    func_01B05360(v2, v1, v0);

    *(float *)(s1 + 0x1F40) = v2[1];
    *(int *)(s1 + 0x1F44) = 0x32;
    *(int *)(s1 + 0x1F48) = 8;
    *(int *)(s1 + 0x1F4C) = 0;

    func_01B060B0(s2, 0x3C, 0, 1.0f, 0.5f);
    *(float *)(s2 + 0x10) = 0.7f;
    *(float *)(s2 + 0x18) = 0.7f;
    func_01B03B40(1);
    func_01B03CD8(D_01B0BCC0, 0, 0x40, 0x100);
    func_01B036F8(-1, D_01B062F8, D_01B004E0);

    proc = func_01B042D0(func_01B00B78);
    proc->unk18 = 1;
    func_01B04498(proc);

    proc = func_01B042D0(func_01B00C28);
    func_01B04498(proc);

    proc = func_01B042D0(func_01B00BA8);
    proc->unk18 = 2;
    func_01B04498(proc);

    return 0;
}
