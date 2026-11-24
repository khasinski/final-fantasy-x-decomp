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
extern PppObj D_01B00840;
extern PppObj D_01B00940;
extern void *D_01B009C0;

extern u8 D_01B18100[];
extern int D_01B181E0;
extern float D_01B187A0[4];

extern char D_01B1B060[];
extern char D_01B1B078[];
extern char D_01B1B090[];
extern Vec4 D_01B1B0B0;
extern char D_01B1B0C0[];

void func_01B187C0(void *, void *, float *);
int func_01B1A348(char *, ...);
void func_00267530(void *);
void func_002675B0(void *);
void func_00267658(void *, int, int, int);
void func_00267FA0(void *, int);
void func_00107428(int, int, int, float *);
void func_00108910(int, int, float *);
void func_001AACA0(void *);
void func_001A9EE0(void *);
void func_002DCE38(void *, void *, void *);

int func_01B197F8(void)
{
    float v[4];
    int i;

    func_00108910(D_01B181E0, 6, v);
    for (i = 0; i < 5; i++) {
        func_01B187C0(D_01B18100, D_01B009C0, v);
    }
    return 1;
}

int func_01B19868(void)
{
    func_01B1A348(D_01B1B060);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B00840, 0x1000, D_01B0050C->w10[3], 1);
    D_01B00840.pos[0] = 0.0f;
    D_01B00840.pos[1] = 0.0f;
    D_01B00840.pos[2] = 0.0f;
    D_01B00840.pos[3] = 1.0f;
    D_01B00840.rot[0] = 0;
    D_01B00840.rot[1] = 0;
    D_01B00840.rot[2] = 0;
    D_01B00840.rot[3] = 1;
    D_01B00840.scale[2] = D_01B00840.scale[1] = D_01B00840.scale[0] = 0.0625f;
    D_01B00840.scale[3] = 1.0f;
    func_00107428(D_01B181E0, 0x55, 0, D_01B187A0);
    return 1;
}

int func_01B19930(void)
{
    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00840.pos[0] = D_01B187A0[0];
    D_01B00840.pos[1] = D_01B187A0[1];
    D_01B00840.pos[2] = D_01B187A0[2];
    func_002675B0(&D_01B00840);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    func_00267FA0(&D_01B00840, 0x30);
    return 1;
}

int func_01B19A18(void)
{
    D_006A3924 = &D_01B00510;
    func_00267530(&D_01B00840);
    func_01B1A348(D_01B1B078);
    return 1;
}

int func_01B19A58(void)
{
    func_01B1A348(D_01B1B090);
    D_006A3924 = &D_01B00510;
    func_00267658(&D_01B00940, 0x1000, D_01B0050C->w10[2], 1);
    D_01B00940.pos[0] = 0.0f;
    D_01B00940.pos[1] = 0.0f;
    D_01B00940.pos[2] = 0.0f;
    D_01B00940.pos[3] = 1.0f;
    D_01B00940.rot[0] = 0;
    D_01B00940.rot[1] = 0;
    D_01B00940.rot[2] = 0;
    D_01B00940.rot[3] = 1;
    D_01B00940.scale[2] = D_01B00940.scale[1] = D_01B00940.scale[0] = 0.05f;
    D_01B00940.scale[3] = 1.0f;
    return 1;
}

int func_01B19B08(void)
{
    Vec4 v = D_01B1B0B0;

    D_006A3924 = &D_01B00510;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00940.pos[0] = v.x;
    D_01B00940.pos[1] = v.y + 5.0f;
    D_01B00940.pos[2] = v.z;
    func_002675B0(&D_01B00940);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00510;
    func_00267FA0(&D_01B00940, 0x30);
    return 1;
}

int func_01B19C10(void)
{
    D_006A3924 = &D_01B00510;
    func_00267530(&D_01B00940);
    func_01B1A348(D_01B1B0C0);
    return 1;
}
