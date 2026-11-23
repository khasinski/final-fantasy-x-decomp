/* Overlay 09559: rank 64 control track/ramp configuration helpers (0x01B02928..0x01B02D10). */
#include "common.h"

typedef struct Track {
    u8 pad0[0x20];
    void *unk20;
    void *unk24;
    void *unk28;
    float unk2C;
    float unk30;
    int unk34;
    int unk38;
    int unk3C;
} Track;

typedef struct Sub130 {
    void *unk00;
    float unk04;
    float unk08;
    float unk0C;
    int unk10;
    int unk14;
    int unk18;
} Sub130;

typedef struct Sub14C {
    void *unk00;
    void *unk04;
    float unk08;
    float unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} Sub14C;

typedef struct Control {
    u8 pad0[0x90];
    u8 unk90[0x10];
    u8 unkA0[0x10];
    u8 padB0[0x80];
    Sub130 unk130;
    Sub14C unk14C;
} Control;

Track *func_01B03AA8(Control *, int);
float func_01B01F28(float, float);

void func_01B02928(Control *a0, int a1, void *a2, int a3, int a4) {
    Track *t = func_01B03AA8(a0, a1);
    t->unk20 = a2;
    t->unk34 = a4;
    t->unk38 = a3;
    t->unk3C = 3;
    t->unk2C = 0.0f;
    t->unk30 = 1.0f / ((float)a4 / (float)a3);
}

void func_01B029B0(Control *a0, int a1, void *a2, void *a3, int a4, int a5) {
    Track *t = func_01B03AA8(a0, a1);
    t->unk20 = a2;
    t->unk28 = a3;
    t->unk30 = 1.0f / (float)a5;
    t->unk34 = a5;
    t->unk38 = a4;
    t->unk3C = 4;
    t->unk2C = 0.0f;
}

void func_01B02A38(Control *a0, int a1, void *a2, int a3, int a4) {
    Track *t = func_01B03AA8(a0, a1);
    if (a1 == 0) {
        t->unk24 = a0->unkA0;
    } else {
        t->unk24 = a0->unk90;
    }
    t->unk20 = a2;
    t->unk38 = a3;
    t->unk3C = 5;
    t->unk34 = a4 * a3;
    t->unk2C = 0.0f;
    t->unk30 = 1.0f / (float)a4;
}

void func_01B02AE0(Control *a0, int a1, void *a2, void *a3, int a4, int a5) {
    Track *t = func_01B03AA8(a0, a1);
    if (a1 == 0) {
        t->unk24 = a0->unkA0;
    } else {
        t->unk24 = a0->unk90;
    }
    t->unk20 = a2;
    t->unk28 = a3;
    t->unk38 = a4;
    t->unk3C = 6;
    t->unk34 = a5 * a4;
    t->unk2C = 0.0f;
    t->unk30 = 1.0f / (float)(a5 * a4);
}

void func_01B02B98(Control *a0, float a1, float a2, int a3) {
    Sub130 *s = &a0->unk130;
    s->unk04 = func_01B01F28(a1, a2);
    s->unk08 = a1;
    s->unk0C = a2;
    s->unk14 = a3;
    s->unk10 = a3;
    s->unk18 = 1;
}

void func_01B02C00(Control *a0, void *a1, int a2, int a3) {
    Sub130 *s = &a0->unk130;
    s->unk00 = a1;
    s->unk18 = 2;
    s->unk14 = a2;
    s->unk10 = a3 * a2;
    s->unk04 = 0.0f;
    s->unk08 = 1.0f / (float)a3;
}

void func_01B02C48(Control *a0, float a1, float a2, int a3) {
    Sub14C *r = &a0->unk14C;
    r->unk1C = 1;
    r->unk14 = a3;
    r->unk08 = a1;
    r->unk18 = 0;
    r->unk0C = (a2 - a1) / (float)a3;
}

void func_01B02C80(Control *a0, void *a1, int a2, int a3) {
    Sub14C *r = &a0->unk14C;
    r->unk00 = a1;
    r->unk1C = 2;
    r->unk18 = a2;
    r->unk14 = a3 * a2;
    r->unk08 = 0.0f;
    r->unk0C = 1.0f / (float)a3;
}

void func_01B02CC8(Control *a0, void *a1, void *a2, int a3, int a4) {
    Sub14C *r = &a0->unk14C;
    r->unk00 = a1;
    r->unk1C = 3;
    r->unk04 = a2;
    r->unk14 = a4 * a3;
    r->unk18 = a3;
    r->unk08 = 0.0f;
    r->unk0C = 1.0f / (float)a4;
}
