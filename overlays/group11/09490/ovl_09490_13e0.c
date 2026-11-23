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
} Part13E0;

extern u32 D_00307F2C;
extern u8 D_01B0B2D0[];
extern u8 D_01B10AB0[];

extern void *op_oef2_a_get(void *, s32, s32);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void **func_01B07948(void *, s32);
extern void func_01B08760(void *, void *);
extern Part13E0 *func_01B0AD18(void);

void func_01B013E0(float *pos) {
    Part13E0 *p;
    void *tex;

    p = func_01B0AD18();
    if (p == 0) {
        return;
    }

    tex = op_oef2_a_get(D_01B10AB0, 9, 0);
    func_01B08760(p->unk30, tex);
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
    p->unk4C = 0x20;
    p->unk50 = 0x20;

    if ((D_00307F2C & 3) == 0) {
        p = func_01B0AD18();
        if (p != 0) {
            tex = *func_01B07948(D_01B0B2D0, 8);
            func_01B08760(p->unk30, tex);
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
}
