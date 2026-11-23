#include "p9_overlay.h"
#include "vu0.h"

typedef struct Ovl09328Part {
    u8 pad0[0x10];
    P9Vec pos;          /* 0x10 */
    void (*cb)(struct Ovl09328Part *); /* 0x20 */
    float unk24;
    float unk28;
    float unk2C;
    u32 unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    u32 unk44;
    u32 unk48;
    float unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u8 pad5C[7];
    u8 unk63;
    u8 pad64[4];
    u16 unk68;
} Ovl09328Part;

typedef struct Ovl09328Obj {
    u8 pad0[0x10];
    P9Vec unk10;        /* 0x10 */
    u32 unk20;
    float unk24;
    u8 pad28[8];
    u8 unk30[0x210];    /* 0x30 */
    u32 unk240;
    u32 unk244;
    u8 pad248[4];
    float unk24C;
    float unk250;
    u8 pad254[4];
    u32 unk258;
    u8 pad25C[4];
    P9Vec unk260;       /* 0x260 */
    float unk270;
    float unk274;
    float unk278;
    u8 pad27C[0x10];
    float unk28C;
    u8 pad290[8];
    u16 unk298;
} Ovl09328Obj;

extern u8 D_01B0B8E0[];

void *func_002B49A0(void *, int, int);
float func_002B3DB0(float);
void func_01B05458(void *, void *);
void func_01B05638(void *, void *, void *);
Ovl09328Part *func_01B05B50(void);
void func_01B060C0(Ovl09328Obj *, float);

void func_01B01348(Ovl09328Part *p);

void func_01B010D8(Ovl09328Obj *s)
{
    void *res;
    u8 *sub = s->unk30;

    res = func_002B49A0(D_01B0B8E0, 9, 0);
    func_01B05458(s, res);
    s->unk20 = 0x80808080;
    s->unk298 = 1;
    s->unk24 = 0.07f;
    s->unk28C = 0.07f;
    res = func_002B49A0(D_01B0B8E0, 9, 0);
    func_01B05638(sub, res, &s->unk10);
    s->unk240 = 0x40808080;
    s->unk244 = 0x00808080;
    s->unk258 = 8;
    s->unk250 = 3.0f;
    s->unk24C = 0.8f;
    func_01B060C0(s, 10.0f);
}

void func_01B011C0(Ovl09328Obj *s)
{
    Ovl09328Part *p;

    p = func_01B05B50();
    if (p != 0) {
        func_01B05458(p, func_002B49A0(D_01B0B8E0, 9, 0));
        MMI_COPY_LQ_A3(&p->pos, &s->unk260);
        MMI_COPY_SQ_A3(&p->pos);
        if (p->pos.y >= -0.5f) {
            p->pos.y = -0.5f;
        }
        p->cb = func_01B01348;
        p->unk24 = s->unk270 * (func_002B3DB0(0.02f) + 0.3f);
        p->unk28 = func_002B3DB0(0.2f) + (-3.8f);
        p->unk2C = s->unk278 * (func_002B3DB0(0.02f) + 0.3f);
        p->unk30 = 0;
        p->unk34 = func_002B3DB0(0.01f) + 0.5f;
        p->unk38 = 2.0f;
        p->unk3C = 0.9f;
        p->unk40 = -0.5f;
        p->unk44 = 0;
        p->unk48 = 0;
        p->unk4C = 0.07f;
        p->unk50 = 0x10;
        p->unk54 = 0x10;
        p->unk58 = 0;
        p->unk63 = 0;
        p->unk68 = 0;
    }
}

void func_01B01348(Ovl09328Part *p)
{
    if (p->pos.x <= -55.0f || p->pos.x >= 55.0f || p->pos.z <= -91.0f) {
        p->cb = 0;
        p->unk68 |= 1;
    }
}
