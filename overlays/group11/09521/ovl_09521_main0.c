#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct Particle {
    u8 pad00[0x10];
    float pos[3];       /* 0x10 */
    float f1c;          /* 0x1C */
    float vel[3];       /* 0x20 */
    float f2c;          /* 0x2C */
    int w30;            /* 0x30 */
    int w34;            /* 0x34 */
    int w38;            /* 0x38 */
    u8 pad3c[0x34];
    float f70;          /* 0x70 */
    float f74;          /* 0x74 */
    u8 pad78[0xC];
    float f84;          /* 0x84 */
} Particle;

typedef struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(8))) Vec4;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

extern TtCfg *D_01B0050C;
extern TtHeap D_01B00510;
extern PppObj D_01B00540;
extern PppObj D_01B005C0;
extern PppObj D_01B00640;
extern PppObj D_01B006C0;
extern PppObj D_01B00740;
extern PppObj D_01B007C0;

extern int D_01B181E0;
extern int D_01B181E8;
extern float D_01B18740[4];
extern float D_01B18750[4];
extern float D_01B18760[4];
extern float D_01B18770[4];
extern float D_01B18780[4];
extern float D_01B18790[4];

extern double D_01B1AF40;
extern char D_01B1AF48[];
extern char D_01B1AF58[];
extern char D_01B1AF70[];
extern char D_01B1AF88[];
extern char D_01B1AFA0[];
extern char D_01B1AFB0[];
extern Vec4 D_01B1AFC0;
extern char D_01B1AFD0[];
extern char D_01B1AFE8[];
extern char D_01B1B000[];
extern char D_01B1B018[];
extern char D_01B1B030[];
extern char D_01B1B048[];

Particle *func_01B1AA88(void *, void *);
int func_01B1A348(char *, ...);
int func_002EFD78(void);
float func_002D56C0(float);
void func_002DCEC8(float *, float *);
void func_00267530(void *);
void func_002675B0(void *);
void func_00267658(void *, int, int, int);
int func_00267FA0(void *, int);
void func_00107428(int, int, int, float *);
void func_00108910(int, int, float *);
void func_001AACA0(void *);
void func_001A9EE0(void *);
void func_002DCE38(void *, void *, void *);

int func_01B187B8(void)
{
    return 1;
}

void func_01B187C0(void *a0, void *a1, float *a2)
{
    Particle *p = func_01B1AA88(a0, a1);

    if (p == 0) {
        return;
    }
    p->w34 = 0x19;
    p->w30 = 0x19;
    p->w38 = 2;
    p->pos[0] = a2[0] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 7.0f;
    p->pos[1] = a2[1] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 7.0f;
    p->pos[2] = a2[2] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 7.0f;
    p->vel[1] = (float)(func_002EFD78() & 0x7FFF) / 32767.0f;
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->f70 = (float)((double)((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.02);
}

void func_01B18968(void *a0, void *a1, float *a2)
{
    float v[4];
    Particle *p = func_01B1AA88(a0, a1);
    float r;

    if (p == 0) {
        return;
    }
    p->w34 = 3;
    r = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.5f + 2.0f;
    v[0] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
    p->pos[0] = a2[0] + v[0] * r;
    p->pos[1] = a2[1] + v[1] * r;
    p->pos[2] = a2[2] + v[2] * r;
    p->vel[0] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.01f;
    p->vel[1] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.01f;
    p->vel[2] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.01f;
    p->f74 = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f + 0.3f) * (1.0f / 150.0f);
    p->f84 = 1.0f / 3.0f;
}

int func_01B18BE0(void)
{
    func_01B1A348(D_01B1AF48);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B00540, 0x1000, D_01B0050C->w10[0], 1);
    D_01B00540.pos[0] = 0.0f;
    D_01B00540.pos[1] = 0.0f;
    D_01B00540.pos[2] = 0.0f;
    D_01B00540.pos[3] = 1.0f;
    D_01B00540.rot[0] = 0;
    D_01B00540.rot[1] = 0;
    D_01B00540.rot[2] = 0;
    D_01B00540.rot[3] = 1;
    D_01B00540.scale[2] = D_01B00540.scale[1] = D_01B00540.scale[0] = 0.0125f;
    D_01B00540.scale[3] = 1.0f;
    return 1;
}

int func_01B18C90(void)
{
    func_00107428(D_01B181E0, 0x66, 0, D_01B18740);
    D_01B18740[1] -= 0.2f;
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00540.pos[0] = D_01B18740[0];
    D_01B00540.pos[1] = D_01B18740[1];
    D_01B00540.pos[2] = D_01B18740[2];
    func_002675B0(&D_01B00540);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    func_00267FA0(&D_01B00540, 0x30);
    return 1;
}

int func_01B18DB0(void)
{
    D_006A3924 = &D_01B00510;
    func_00267530(&D_01B00540);
    func_01B1A348(D_01B1AF58, D_01B181E8);
    return 1;
}

int func_01B18DF8(void)
{
    func_01B1A348(D_01B1AF70, D_01B181E8);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B005C0, 0x1000, D_01B0050C->w10[6], 1);
    D_01B005C0.pos[0] = 0.0f;
    D_01B005C0.pos[1] = 0.0f;
    D_01B005C0.pos[2] = 0.0f;
    D_01B005C0.pos[3] = 1.0f;
    D_01B005C0.rot[0] = 0;
    D_01B005C0.rot[1] = 0;
    D_01B005C0.rot[2] = 0;
    D_01B005C0.rot[3] = 1;
    D_01B005C0.scale[2] = D_01B005C0.scale[1] = D_01B005C0.scale[0] = 0.03125f;
    D_01B005C0.scale[3] = 1.0f;
    func_00108910(D_01B181E0, 6, D_01B18750);
    return 1;
}

int func_01B18EC0(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B005C0.pos[0] = D_01B18750[0];
    D_01B005C0.pos[1] = D_01B18750[1] - 0.5f + 0.2f;
    D_01B005C0.pos[2] = D_01B18750[2] + 1.0f;
    func_002675B0(&D_01B005C0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    if (func_00267FA0(&D_01B005C0, 0x30) != 0) {
        D_006A3924 = &D_01B00510;
        func_00267530(&D_01B005C0);
        func_01B1A348(D_01B1AF88);
        return 0;
    }
    return 1;
}

int func_01B18FF0(void)
{
    func_01B1A348(D_01B1AFA0);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B00640, 0x1000, D_01B0050C->w10[4], 1);
    D_01B00640.pos[0] = 0.0f;
    D_01B00640.pos[1] = 0.0f;
    D_01B00640.pos[2] = 0.0f;
    D_01B00640.pos[3] = 1.0f;
    D_01B00640.rot[0] = 0;
    D_01B00640.rot[1] = 0;
    D_01B00640.rot[2] = 0;
    D_01B00640.rot[3] = 1;
    D_01B00640.scale[2] = D_01B00640.scale[1] = D_01B00640.scale[0] = 0.0234375f;
    D_01B00640.scale[3] = 1.0f;
    func_00108910(D_01B181E0, 6, D_01B18760);
    return 1;
}

int func_01B190B0(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00640.pos[0] = D_01B18760[0];
    D_01B00640.pos[1] = D_01B18760[1] - 0.2f - 0.1f;
    D_01B00640.pos[2] = D_01B18760[2] + 1.0f;
    func_002675B0(&D_01B00640);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    if (func_00267FA0(&D_01B00640, 0x30) != 0) {
        D_006A3924 = &D_01B00510;
        func_00267530(&D_01B00640);
        func_01B1A348(D_01B1AFB0);
        return 0;
    }
    return 1;
}

int func_01B191E8(void)
{
    float v0[4];
    float v1[4];
    Vec4 v2 = D_01B1AFC0;

    func_01B1A348(D_01B1AFD0);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B00740, 0x1000, D_01B0050C->w10[7], 1);
    D_01B00740.pos[0] = 0.0f;
    D_01B00740.pos[1] = 0.0f;
    D_01B00740.pos[2] = 0.0f;
    D_01B00740.pos[3] = 1.0f;
    D_01B00740.rot[0] = 0;
    D_01B00740.rot[1] = 0;
    D_01B00740.rot[2] = 0;
    D_01B00740.rot[3] = 1;
    D_01B00740.scale[2] = D_01B00740.scale[1] = D_01B00740.scale[0] = 0.038000003f;
    D_01B00740.scale[3] = 1.0f;
    func_00108910(D_01B181E0, 6, v1);
    func_00108910(D_01B181E0, 4, v0);
    D_01B18770[0] = v2.x;
    D_01B18770[1] = v1[1] - 0.5f;
    D_01B18770[2] = v2.z;
    return 1;
}

int func_01B19308(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00740.pos[0] = D_01B18770[0];
    D_01B00740.pos[1] = D_01B18770[1] - 0.5f;
    D_01B00740.pos[2] = D_01B18770[2];
    func_002675B0(&D_01B00740);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    if (func_00267FA0(&D_01B00740, 0x30) != 0) {
        D_006A3924 = &D_01B00510;
        func_00267530(&D_01B00740);
        func_01B1A348(D_01B1AFE8);
        return 0;
    }
    return 1;
}

int func_01B19420(void)
{
    func_01B1A348(D_01B1B000);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B006C0, 0x1000, D_01B0050C->w10[1], 1);
    D_01B006C0.pos[0] = 0.0f;
    D_01B006C0.pos[1] = 0.0f;
    D_01B006C0.pos[2] = 0.0f;
    D_01B006C0.pos[3] = 1.0f;
    D_01B006C0.rot[0] = 0;
    D_01B006C0.rot[1] = 0;
    D_01B006C0.rot[2] = 0;
    D_01B006C0.rot[3] = 1;
    D_01B006C0.scale[2] = D_01B006C0.scale[1] = D_01B006C0.scale[0] = 0.03125f;
    D_01B006C0.scale[3] = 1.0f;
    func_00108910(D_01B181E0, 1, D_01B18780);
    D_01B18780[1] += 1.0f;
    return 1;
}

int func_01B19500(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B006C0.pos[0] = D_01B18780[0];
    D_01B006C0.pos[1] = D_01B18780[1];
    D_01B006C0.pos[2] = D_01B18780[2];
    func_002675B0(&D_01B006C0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    if (func_00267FA0(&D_01B006C0, 0x30) != 0) {
        D_006A3924 = &D_01B00510;
        func_00267530(&D_01B006C0);
        func_01B1A348(D_01B1B018);
        return 0;
    }
    return 1;
}

int func_01B19608(void)
{
    func_01B1A348(D_01B1B030);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B007C0, 0x1000, D_01B0050C->w10[2], 1);
    D_01B007C0.pos[0] = 0.0f;
    D_01B007C0.pos[1] = 0.0f;
    D_01B007C0.pos[2] = 0.0f;
    D_01B007C0.pos[3] = 1.0f;
    D_01B007C0.rot[0] = 0;
    D_01B007C0.rot[1] = 0;
    D_01B007C0.rot[2] = 0;
    D_01B007C0.rot[3] = 1;
    D_01B007C0.scale[2] = D_01B007C0.scale[1] = D_01B007C0.scale[0] = 0.03125f;
    D_01B007C0.scale[3] = 1.0f;
    func_00108910(D_01B181E0, 1, D_01B18790);
    D_01B18790[1] -= 5.0f;
    return 1;
}

int func_01B196E8(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B007C0.pos[0] = D_01B18790[0];
    D_01B007C0.pos[1] = D_01B18790[1];
    D_01B007C0.pos[2] = D_01B18790[2];
    func_002675B0(&D_01B007C0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    if (func_00267FA0(&D_01B007C0, 0x30) != 0) {
        D_006A3924 = &D_01B00510;
        func_00267530(&D_01B007C0);
        func_01B1A348(D_01B1B048);
        return 0;
    }
    return 1;
}
