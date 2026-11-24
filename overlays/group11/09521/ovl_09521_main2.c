#include "common.h"

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

typedef struct PPool {
    u8 data[0x70];
} PPool;

typedef struct PBuf {
    u8 data[0xBB80];
} PBuf;

typedef struct RenderCfg {
    union {
        struct {
            u16 h00;
            u16 h02;
            u32 w04;
        } s;
        u8 raw[0x30];
    } u;
} RenderCfg;

extern u8 D_01B00040[];
extern u8 D_01B00428[];
extern u8 D_01B00440[];
extern u8 D_01B00470[];
extern u8 D_01B004A0[];
extern u8 D_01B004D0[];
extern void *D_01B004F4;
extern void *D_01B004F8;
extern void *D_01B004FC;
extern int D_01B00504;
extern void *D_01B00508;
extern TtCfg *D_01B0050C;
extern TtHeap D_01B00510;
extern void *D_01B009C0;
extern RenderCfg D_01B009D0;
extern PBuf D_01B00A00[2];

extern PPool D_01B18100[2];
extern int D_01B181E0;
extern int D_01B181E4;
extern u8 D_01B181F0[];
extern u8 D_01B18300[];
extern u8 D_01B18410[];
extern u8 D_01B18520[];
extern u8 D_01B18630[];

extern char D_01B1B0D8[];
extern char D_01B1B0E8[];
extern char D_01B1B0F8[];
extern u8 D_01B1B260[];
extern u8 D_01B5E7D0[];

void func_01B18968(void *, void *, float *);
int func_01B1A348(char *, ...);
void func_01B1A378(char *);
void func_01B1A8D8(void *, void *, int);
void func_01B1ABC0(void *, int, float, float);
void func_01B1AC68(void *, void *, int);
void func_00107428(int, int, int, float *);
int func_0013B150(int);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, int);
void func_002B4980(void *);
void *func_002B49A0(void *, int, int);
void func_002D02E8(void *, int, int, int);
void *func_002EF0D0(void *, int, int);

int func_01B19C58(void)
{
    float v[4];
    int i;

    func_00107428(D_01B181E4, 0, 0, v);
    for (i = 0; i < 83; i++) {
        func_01B18968(&D_01B18100[1], D_01B009C0, v);
    }
    return 1;
}

int func_01B19CD0(int a0)
{
    u8 *mem = D_01B5E7D0;
    int i;

    D_01B004F4 = mem;
    D_01B004F8 = mem + 0x80000;
    D_01B004FC = (u8 *)D_01B004F8 + 0x80000;
    func_01B1A348(D_01B1B0D8);
    D_01B00504 = a0;
    D_01B00508 = D_01B1B260;
    func_002B4980(D_01B1B260);
    func_002D02E8(D_01B00508, 0, 1000, 0x2000);
    D_01B0050C = func_002B49A0(D_01B00508, 8, 0);
    func_002678E0(D_01B0050C, D_01B00040);
    func_00267A68(&D_01B00510, D_01B0050C, D_01B004F4, 0x80000);
    D_01B00510.w20 = D_01B0050C->w14;
    D_01B00510.w24 = D_01B0050C->w18;
    D_01B00510.w28 = D_01B0050C->w1c;
    func_01B1AC68(D_01B181F0, D_01B00428, 1);
    func_01B1AC68(D_01B18300, D_01B00440, 2);
    func_01B1AC68(D_01B18410, D_01B00470, 2);
    func_01B1AC68(D_01B18520, D_01B004A0, 2);
    func_01B1AC68(D_01B18630, D_01B004D0, 1);
    D_01B181E0 = func_0013B150(0);
    if (D_01B181E0 == 0) {
        func_01B1A378(D_01B1B0E8);
    }
    D_01B181E4 = func_0013B150(0x14);
    if (D_01B181E4 == 0) {
        func_01B1A378(D_01B1B0F8);
    }
    D_01B009C0 = func_002B49A0(D_01B00508, 4, 0);
    func_002EF0D0(&D_01B009D0, 0, 0x30);
    D_01B009D0.u.s.h02 = 0x80;
    D_01B009D0.u.s.w04 = 0x80808080;
    for (i = 0; i < 2; i++) {
        func_01B1A8D8(&D_01B18100[i], &D_01B00A00[i], 0xFA);
        func_01B1ABC0(&D_01B18100[i], 0, 0.1f, 0.0f);
    }
    func_01B1ABC0(&D_01B18100[1], 0, 0.0f, 0.0f);
    return 1;
}
