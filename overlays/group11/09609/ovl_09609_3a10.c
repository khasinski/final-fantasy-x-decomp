#include "common.h"

typedef struct {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    u8 unk30[0xC];
    float unk3C;
    u8 pad40[0xC];
    s32 unk4C;
    s32 unk50;
    u8 pad54[0x17];
    u8 unk6B;
} Unk3A10Part;

extern u32 D_00307F2C;
extern u8 D_01B0DEB0[];
extern u8 D_01B17DF0[];

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, s32, s32);
extern void **func_01B0A4A8(void *, s32);
extern void func_01B0B458(void *, void *);
extern Unk3A10Part *func_01B0D948(void);

void func_01B03A10(float *pos) {
    Unk3A10Part *p;
    void *tex;

    p = func_01B0D948();
    if (p == 0) {
        return;
    }

    tex = func_002B49A0(D_01B17DF0, 9, 0);
    func_01B0B458(p->unk30, tex);
    p->unk00 = pos[0] + func_002B3DB0(2.0f);
    p->unk04 = pos[1];
    p->unk08 = pos[2] + func_002B3DB0(2.0f);
    p->unk0C = 1.0f;
    p->unk10 = func_002B3DB0(0.1f);
    p->unk14 = -func_002B3DF8(0.5f);
    p->unk18 = func_002B3DB0(0.1f);
    p->unk1C = func_002B3DB0(3.1415927f);
    p->unk20 = 0.0f;
    p->unk24 = 0.01f;
    p->unk28 = 0.0f;
    p->unk2C = 1.0f;
    p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.025f;
    p->unk6B = 0;
    p->unk4C = 32;
    p->unk50 = 32;

    if ((D_00307F2C & 3) == 0) {
        p = func_01B0D948();
        if (p == 0) {
            return;
        }
        tex = *func_01B0A4A8(D_01B0DEB0, 6);
        func_01B0B458(p->unk30, tex);
        p->unk00 = pos[0] + func_002B3DB0(2.0f);
        p->unk04 = pos[1];
        p->unk08 = pos[2] + func_002B3DB0(2.0f);
        p->unk0C = 1.0f;
        p->unk10 = func_002B3DB0(0.25f);
        p->unk14 = -func_002B3DF8(0.25f);
        p->unk18 = func_002B3DB0(0.25f);
        p->unk1C = func_002B3DB0(3.1415927f);
        p->unk20 = 0.0f;
        p->unk24 = 0.01f;
        p->unk28 = 0.0f;
        p->unk2C = 1.0f;
        p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.1f;
        p->unk4C = -1;
        p->unk50 = 0;
    }
}
