/* Battle-effect overlay 09301: 0x01B01DD8..0x01B02234 */
#include "common.h"

extern u32 D_01B00758;
extern u32 D_01B0075C;
extern u32 D_01B00760;
extern u8 D_01B00880[];
extern u8 D_01B008E0[];
extern u8 D_01B00910[];
extern u8 D_01B00B38[];
extern u8 D_01B00B58[];
extern u8 D_01B00B80[];
extern u8 D_01B010C0[];
extern u8 D_01B01160[];
extern u8 D_01B011C0[];
extern u8 D_01B01220[];
extern u8 D_01B01370[];
extern u8 D_01B014C0[];
extern u8 D_01B015C0[];
extern u8 D_01B016C0[];
extern u8 D_01B0C090[];
extern u32 D_01B0C0BC;

void func_001CE050(u32 a0, int a1);
s32 func_00110B78(u32 a0);
void func_00110B80(u32 a0, s32 a1);

void func_01B026C0(void *arg);
void func_01B036F8(void *arg);
void func_01B03960(void *arg);
void func_01B03C70(void *arg);
void func_01B03D10(void *arg);
void func_01B03E18(void *arg);
void func_01B06A10(void *arg);
void func_01B07B98(void *arg);
void func_01B09450(void *arg);
void func_01B09488(void *arg);
void func_01B09CF8(void *arg);
void func_01B0AD50(void *arg);

typedef struct {
    u8 pad00[0x18];
    u32 state;
    u8 pad1C[0x10];
    s32 timer;
} Ovl09301State;

typedef struct {
    void *unk00;
    Ovl09301State *st;
} Ovl09301Arg;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    void *a3;
    void *a4;
    void *a5;
} CallArgs6;

typedef struct {
    void *a0;
    void *a1;
    u32 a2;
    u32 a3;
    u8 a4;
} CallArgs26C0;

typedef struct {
    void *a0;
    void *a1;
    u32 a2;
    u8 a3;
} CallArgs3C70;

typedef struct {
    void *a0;
    void *a1;
    s32 a2;
} CallArgs36F8;

void func_01B01DD8(Ovl09301Arg *a0)
{
    union {
        CallArgs6 c6;
        CallArgs26C0 c26c0;
        CallArgs3C70 c3c70;
        CallArgs36F8 c36f8;
    } arg;
    void *p32;
    void *p36;
    void *p40;
    Ovl09301State *st = a0->st;

    switch (st->state) {
    case 0:
        arg.c26c0.a0 = D_01B00B80;
        arg.c26c0.a1 = D_01B00B38;
        arg.c26c0.a2 = D_01B0075C;
        arg.c26c0.a3 = 0;
        arg.c26c0.a4 = 1;
        func_01B026C0(&arg);

        {
            u8 *p = D_01B010C0;
            u32 t = D_01B00760;
            arg.c3c70.a0 = p;
            arg.c3c70.a1 = D_01B00B38;
            arg.c3c70.a2 = t;
            arg.c3c70.a3 = 0;
            func_01B03C70(&arg);
        }

        st->state = 10;
        /* fallthrough */
    case 10: {
        u8 *s0;
        u8 *s1;
        u8 *s2;
        u8 *s3;
        u8 *s4;
        u8 *s5;

        s5 = D_01B010C0;
        func_001CE050(D_01B00760, 74);
        s4 = D_01B00B38;
        s0 = D_01B01160;
        s2 = D_01B01220;
        s3 = D_01B014C0;
        s1 = s0 + 0x30;

        arg.c6.a0 = s0;
        arg.c6.a1 = s4;
        func_01B06A10(&arg);

        arg.c6.a0 = s5;
        arg.c6.a1 = s0 + 0x20;
        func_01B03960(&arg);

        *(float *)(s0 + 0x2C) = 1.0f;

        arg.c6.a0 = s1;
        arg.c6.a1 = s4;
        func_01B06A10(&arg);

        *(float *)(s1 + 0x20) = 1.0f;
        *(float *)(s1 + 0x24) = 1.0f;
        *(float *)(s1 + 0x28) = 1.0f;
        *(float *)(s1 + 0x2C) = 0.26f;

        arg.c6.a0 = s2;
        arg.c6.a1 = s4;
        arg.c6.a2 = D_01B00910;
        arg.c6.a3 = s0;
        arg.c6.a4 = D_01B008E0;
        arg.c6.a5 = s1;
        func_01B07B98(&arg);

        s2[0x14C] = 1;

        arg.c6.a0 = s3;
        arg.c6.a1 = D_01B00B58;
        arg.c6.a2 = s2;
        arg.c6.a3 = (void *)D_01B0C0BC;
        arg.c6.a4 = D_01B0C090;
        arg.c6.a5 = 0;
        func_01B09CF8(&arg);

        func_00110B80(*(u32 *)(s5 + 0x58), func_00110B78(*(u32 *)(s5 + 0x58)) & ~3);

        arg.c6.a0 = D_01B016C0;
        arg.c6.a1 = s4;
        arg.c6.a2 = s2;
        arg.c6.a3 = D_01B00880;
        arg.c6.a4 = (void *)D_01B00758;
        arg.c6.a5 = 0;
        func_01B09488(&arg);

        arg.c6.a0 = D_01B016C0;
        arg.c6.a1 = 0;
        func_01B09450(&arg);

        st->timer = 0;
        st->state = 30;
        break;
    }
    case 30:
        if (st->timer >= 170) {
            arg.c36f8.a0 = D_01B010C0;
            arg.c36f8.a1 = 0;
            arg.c36f8.a2 = 10;
            func_01B036F8(&arg);
            st->timer = 0;
            st->state = 60;
        }
        break;
    case 60:
        if (st->timer >= 0) {
            u8 *s0 = D_01B011C0;
            u8 *s1 = s0 + 0x30;
            u8 *s2 = D_01B00B38;
            u8 *s3 = D_01B01370;
            u8 *s4 = D_01B015C0;

            arg.c6.a0 = s0;
            arg.c6.a1 = s2;
            func_01B06A10(&arg);

            arg.c6.a0 = D_01B010C0;
            arg.c6.a1 = s0 + 0x20;
            func_01B03960(&arg);

            *(float *)(s0 + 0x24) += 10.0f;
            *(float *)(s0 + 0x2C) = 1.0f;

            arg.c6.a0 = s1;
            arg.c6.a1 = s2;
            func_01B06A10(&arg);

            *(float *)(s1 + 0x20) = 1.0f;
            *(float *)(s1 + 0x24) = 1.0f;
            *(float *)(s1 + 0x28) = 1.0f;
            *(float *)(s1 + 0x2C) = 1.8f;

            arg.c6.a0 = s3;
            arg.c6.a1 = s2;
            arg.c6.a2 = D_01B00910;
            arg.c6.a3 = s0;
            arg.c6.a4 = D_01B008E0;
            arg.c6.a5 = s1;
            func_01B07B98(&arg);

            s3[0x14C] = 1;

            arg.c6.a0 = s4;
            arg.c6.a1 = D_01B00B58;
            arg.c6.a2 = s3;
            arg.c6.a3 = (void *)D_01B0C0BC;
            arg.c6.a4 = D_01B0C090;
            arg.c6.a5 = (void *)1;
            func_01B09CF8(&arg);

            st->timer = 0;
            st->state++;
        }
        break;
    case 61:
        if (st->timer >= 200) {
            st->state = 10000;
        }
        break;
    case 10000:
        p32 = D_01B010C0;
        func_01B03E18(&p32);
        p36 = D_01B010C0;
        func_01B03D10(&p36);
        p40 = a0->unk00;
        func_01B0AD50(&p40);
        break;
    }

    st->timer++;
}
