#include "common.h"

typedef struct {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
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
    u8 pad54[0x13];
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    u8 unk6B;
} Unk1638Part;

extern s32 D_00307F2C;
extern u8 D_01B0B2D0;

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern s32 *func_01B07948(void *, s32);
extern void func_01B08760(void *, s32);
extern Unk1638Part *func_01B0AD18(void);

void func_01B01638(float *arg0) {
    s32 val;
    Unk1638Part *p;

    val = *func_01B07948(&D_01B0B2D0, 0);
    p = func_01B0AD18();
    if (p != 0) {
        func_01B08760(p->unk30, val);
        p->unk0 = arg0[0] + func_002B3DB0(2.0f);
        p->unk4 = arg0[1];
        p->unk8 = arg0[2] + func_002B3DB0(2.0f);
        p->unkC = 1.0f;
        p->unk10 = func_002B3DB0(0.1f);
        p->unk14 = -(func_002B3DF8(0.1f) + 0.2f);
        p->unk18 = func_002B3DB0(0.1f);
        p->unk1C = func_002B3DB0(3.1415927f);
        p->unk20 = 0.0f;
        p->unk24 = 0.01f;
        p->unk28 = 0.0f;
        p->unk2C = 1.0f;
        p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.2f;
        p->unk4C = -1;
        p->unk50 = 0;
        p->unk68 = 0x8C;
        p->unk69 = 0x96;
        p->unk6A = 0xB4;
        p->unk6B = 0x18;

        if ((D_00307F2C & 7) == 0) {
            p = func_01B0AD18();
            if (p != 0) {
                val = *func_01B07948(&D_01B0B2D0, 10);
                func_01B08760(p->unk30, val);
                p->unk0 = arg0[0] + func_002B3DB0(2.0f);
                p->unk4 = arg0[1];
                p->unk8 = arg0[2] + func_002B3DB0(2.0f);
                p->unkC = 1.0f;
                p->unk10 = func_002B3DB0(0.25f);
                p->unk14 = -func_002B3DF8(0.5f);
                p->unk18 = func_002B3DB0(0.25f);
                p->unk1C = func_002B3DB0(3.1415927f);
                p->unk20 = 0.0f;
                p->unk24 = 0.025f;
                p->unk28 = 0.0f;
                p->unk2C = 1.0f;
                p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.02f;
                p->unk4C = -1;
                p->unk50 = 0;
            }
        }
    }
}

void func_01B018B8(float *arg0) {
    Unk1638Part *p;
    s32 val;

    if ((D_00307F2C & 3) == 0) {
        p = func_01B0AD18();
        if (p != 0) {
            val = *func_01B07948(&D_01B0B2D0, 14);
            func_01B08760(p->unk30, val);
            p->unk0 = arg0[0] + func_002B3DB0(2.0f);
            p->unk4 = arg0[1];
            p->unk8 = arg0[2] + func_002B3DB0(2.0f);
            p->unkC = 1.0f;
            p->unk10 = func_002B3DB0(0.25f);
            p->unk14 = -(func_002B3DF8(0.5f) + 0.5f);
            p->unk18 = func_002B3DB0(0.25f);
            p->unk1C = func_002B3DB0(3.1415927f);
            p->unk20 = 0.0f;
            p->unk24 = 0.05f;
            p->unk28 = 0.0f;
            p->unk2C = 1.0f;
            p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.08f;
            p->unk6B = 0;
            p->unk67 = 0xA0;
            p->unk4C = 0x20;
            p->unk50 = 0x20;

            p = func_01B0AD18();
            if (p != 0) {
                val = *func_01B07948(&D_01B0B2D0, 15);
                func_01B08760(p->unk30, val);
                p->unk0 = arg0[0] + func_002B3DB0(2.0f);
                p->unk4 = arg0[1];
                p->unk8 = arg0[2] + func_002B3DB0(2.0f);
                p->unkC = 1.0f;
                p->unk10 = func_002B3DB0(0.1f);
                p->unk14 = -(func_002B3DF8(0.3f) + 0.2f);
                p->unk18 = func_002B3DB0(0.1f);
                p->unk1C = func_002B3DB0(3.1415927f);
                p->unk20 = 0.0f;
                p->unk24 = 0.01f;
                p->unk28 = 0.0f;
                p->unk2C = 1.0f;
                p->unk3C = (func_002B3DB0(0.2f) + 1.0f) * 0.1f;
                p->unk50 = 0;
                p->unk4C = -1;
                p->unk68 = 0xA0;
                p->unk69 = 0xC8;
                p->unk6A = 0xB4;
                p->unk6B = 0x40;
            }
        }
    }
}
