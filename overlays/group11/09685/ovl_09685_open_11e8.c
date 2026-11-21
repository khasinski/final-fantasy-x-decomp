/* EE Battle-Effect Overlay: group 0x11, file 09685
 * .text: 0x01B011E8..0x01B01778 (7 functions).
 */
#include "common.h"

typedef struct PObj9685 {
    u8 pad00[0x10];
    float x, y, z, w;
    float vx, vy, vz, vw;
    s32 w30, w34, w38;
    u8 pad3c[0x34];
    float f70, f74;
    u8 pad78[0x18];
    s32 c90, c94, c98, c9c;
    s32 ca0, ca4, ca8, cac;
    float fb0, fb4;
} PObj9685;

typedef struct DrawCtx {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[0x28];
} DrawCtx;

extern u8 *D_01B00460;
extern u8 *D_01B00464;
extern void *D_01B00470;
extern void *D_01B00DB0;
extern DrawCtx D_01B00DC0;
extern void *D_01B00DF0;
extern u8 D_01B00E00[];
extern void *D_01B00E78;
extern s32 D_01B00E80[9];
extern s32 D_01B00EA8[9];
extern u8 D_01B00F98[];
extern char D_01B043A0[];
extern char D_01B043B0[];
extern char D_01B043C0[];
extern char D_01B043C8[];
extern char D_01B043E8[];

extern void func_01B016A0(void);
extern void func_01B016E0(void);
extern void func_01B01778(int);
extern void func_01B02910(const char *);
extern void func_01B02940(const char *);
extern void func_01B02EB8(void *, void *, int);
extern void func_01B02F30(void *);
extern PObj9685 *func_01B03068(void *, void *);
extern u8 *func_01B030C8(void *, void *, void *, float);
extern void func_01B031A0(void *, int, float, float);
extern void func_01B032F8(void *);

extern void func_00107428(void *, int, int, float *);
extern void *func_0013B150(int);
extern int func_0014AA50(int);
extern void func_002B2730(int);
extern void *func_002B49A0(void *, int, int);
extern float func_002D56C0(float);
extern void func_002DA610(int, int);
extern void *func_002EF0D0(void *, int, int);
extern int func_002EFD78(void);

void func_01B011E8(void *a0, void *a1, float *pos)
{
    PObj9685 *p;
    float f;

    p = func_01B03068(a0, a1);
    if (p == 0) {
        func_01B02910(D_01B043A0);
        return;
    }
    p->w34 = 0x10;
    p->w30 = 0x10;
    p->w38 = 0xC;
    p->x = pos[0] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->y = pos[1] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->z = pos[2] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->vx = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->vy = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->vz = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.0625f;
    f = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.0625f;
    p->c90 = 0x62;
    p->c94 = 0x74;
    p->c98 = 0xBA;
    p->c9c = 0x10;
    p->ca0 = 0x2B;
    p->ca4 = 0x2A;
    p->ca8 = 0x6B;
    p->cac = 0;
    p->fb0 = f;
    p->fb4 = f * 4.0f;
}

int func_01B01460(void)
{
    func_01B02910(D_01B043B0);
    D_01B00E78 = func_0013B150(0x14);
    if (D_01B00E78 == 0) {
        func_01B02940(D_01B043C0);
    }
    D_01B00DB0 = func_002B49A0(D_01B00470, 4, 0);
    func_002EF0D0(&D_01B00DC0, 0, 0x30);
    D_01B00DC0.h02 = 0x80;
    D_01B00DC0.w04 = 0x80808080;
    func_01B02EB8(D_01B00E00, D_01B00DF0, 0x64);
    func_01B031A0(D_01B00E00, 0, 0.0f, 0.0f);
    return 1;
}

int func_01B01530(void)
{
    float pos[4];

    func_00107428(D_01B00E78, 0, 0, pos);
    func_01B011E8(D_01B00E00, D_01B00DB0, pos);
    func_01B011E8(D_01B00E00, D_01B00DB0, pos);
    func_01B02F30(D_01B00E00);
    D_01B00464 = func_01B030C8(D_01B00E00, &D_01B00DC0, D_01B00464, 0.0f);
    if (D_01B00464 >= D_01B00460 + 0x80000) {
        func_01B02940(D_01B043C8);
    }
    func_002DA610(0, 0);
    return 1;
}

int func_01B01600(void)
{
    func_01B02910(D_01B043E8);
    return 1;
}

void func_01B01628(void)
{
    if (func_0014AA50(9) == 0) {
        return;
    }
    func_002B2730(0);
    if (func_0014AA50(10) != 0) {
        func_01B016A0();
        func_01B01778(0);
    } else {
        func_01B016E0();
        func_01B01778(1);
    }
    func_01B032F8(D_01B00F98);
}

void func_01B016A0(void)
{
    int i;

    for (i = 0; i < 9; i++) {
        D_01B00EA8[i] = D_01B00E80[i];
        D_01B00E80[i] = 0;
    }
}

void func_01B016E0(void)
{
    int i;

    for (i = 0; i < 9; i++) {
        D_01B00EA8[i] = D_01B00E80[i];
    }
    for (i = 0; i < 9; i++) {
        if (func_0014AA50(i) != 0) {
            D_01B00E80[i] = 1;
        } else {
            D_01B00E80[i] = 0;
        }
    }
}
