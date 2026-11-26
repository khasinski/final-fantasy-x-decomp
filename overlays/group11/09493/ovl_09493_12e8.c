#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x3C];
    void *fn104;
    u8 pad108[0x08];
    void *p110;
} OvlSub;

typedef struct {
    u8 pad00[0x4C0];
    OvlSub sub;
    u8 pad5D4[0xBBC];
    u8 f1190[0x4500];
    u8 f5690[0x80];
    float f5710;
} OvlWork;

extern u8 D_01B00760[];
extern u8 D_01B01218[];
extern u8 D_01B08D60[];
extern OvlWork *D_01B08E28;
extern u8 D_01B0F3A0[];

extern void func_01B047A0(void *, void *, void *);
extern void func_01B05018(void *, void *, int, int, float, int, int);
extern void func_01B08B18(void *, int, int, float, float);

void ovl_09493_12e8(void)
{
    OvlWork *s1 = D_01B08E28;
    OvlSub *s0 = &s1->sub;

    func_01B05018(D_01B08D60, s0, 4, 0, 0.09f, 0, 0);
    s0->fC4 = s1->f5710;
    s0->fn104 = D_01B01218;
    func_01B047A0(s1->f5690, D_01B0F3A0, D_01B00760);
    s0->p110 = s1->f5690;
    func_01B08B18(s1->f1190, 0x32, 0, 1.0f, 0.5f);
}
