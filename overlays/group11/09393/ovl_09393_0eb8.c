/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B00EB8..0x01B0113C, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B00EB8..0x01B0113C (4 functions)
 */
#include "common.h"

typedef struct Sub20 {
    u8 pad00[0x14];
    int unk14;
    u8 pad18[0x08];
} Sub20;

typedef struct Work09393 {
    u8 pad0000[0x18F0];
    u8 unk18F0[3][0x40]; /* 0x18F0 */
    float unk19B0[3][4]; /* 0x19B0 */
    float unk19E0[3][4]; /* 0x19E0 */
    int unk1A10;         /* 0x1A10 */
    float unk1A14;       /* 0x1A14 */
    int unk1A18;         /* 0x1A18 */
    int unk1A1C;         /* 0x1A1C */
    u8 unk1A20[0x240];   /* 0x1A20 */
    int unk1C60;         /* 0x1C60 */
} Work09393;

typedef struct Cfg09393 {
    int unk00;
    int count;
    u8 pad08[0x0C];
    u8 ids[0xB0];
    void *chrs[3];
} Cfg09393;

extern Cfg09393 D_01B00740;
extern int D_01B07AE0;
extern u8 D_01B07AE8[];
extern void *D_01B07B2C;
extern int D_01B07BA4;
extern Sub20 D_01B07BB0[3];
extern Work09393 *D_01B07C10;

void Ch_Dispose(void *chr);
void Ch_EnClip(void *chr, int enable);
void MsEffectTerminate(int eff_id);

void *func_01B01AE8(int idx);
float func_01B01B78(int a0);
void func_01B01CA0(int a0, void *a1, int a2);
void func_01B029D8(int idx, int val);
void func_01B02F10(int idx, void *dst);
void *func_01B032A8(int id);
void func_01B032E8(int id);
int func_01B046A0(void *a0, void *a1);

void func_01B00EB8(void)
{
    Work09393 *w = D_01B07C10;

    if (func_01B046A0(D_01B07AE8, D_01B07B2C) == 1 && w->unk1C60 == 1) {
        MsEffectTerminate(D_01B07AE0);
    }
}

void func_01B00F20(void)
{
    Work09393 *w = D_01B07C10;
    int i;

    w->unk1A10 = 0;
    w->unk1A14 = func_01B01B78(-1);
    w->unk1A18 = 0;
    w->unk1A1C = 0;
    func_01B01CA0(-1, w->unk1A20, 3);
    w->unk1C60 = 0;
    D_01B07BA4 = 1;
    for (i = 2; i >= 0; i--) {
        D_01B07BB0[i].unk14 = 1;
    }
}

void func_01B00FB0(void)
{
    func_01B029D8(0, 1);
    func_01B029D8(1, 1);
    func_01B029D8(2, 1);
    Ch_Dispose(func_01B01AE8(0));
    Ch_Dispose(func_01B01AE8(1));
    Ch_Dispose(func_01B01AE8(2));
    func_01B032E8(0x10AF);
}

void func_01B01020(void)
{
    Work09393 *w = D_01B07C10;
    Cfg09393 *p = &D_01B00740;
    void *c;
    int i;

    c = func_01B032A8(0x10AF);
    p->chrs[0] = c;
    p->ids[0] = 0x20;
    Ch_EnClip(c, 0);

    c = func_01B032A8(0x10AF);
    p->chrs[1] = c;
    p->ids[1] = 0x21;
    Ch_EnClip(c, 0);

    c = func_01B032A8(0x10AF);
    p->chrs[2] = c;
    p->ids[2] = 0x22;
    Ch_EnClip(c, 0);

    for (i = 0; i < 3; i++) {
        func_01B02F10(i, w->unk18F0[i]);
        *(int *)&w->unk19B0[i][0] = 0;
        *(int *)&w->unk19B0[i][1] = 0;
        *(int *)&w->unk19B0[i][2] = 0;
        *(int *)&w->unk19B0[i][3] = 0;
        *(int *)&w->unk19E0[i][0] = 0;
        *(int *)&w->unk19E0[i][1] = 0;
        *(int *)&w->unk19E0[i][2] = 0;
        *(float *)((u8 *)w + 0x19EC + i * 0x10) = 1.0f;
        func_01B029D8(i, 1);
    }
}
