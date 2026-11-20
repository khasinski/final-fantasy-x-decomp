/* Battle-effect overlay 09705: 0x01B02240..0x01B025B4 */
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
} TtCfg;

typedef struct SlotPair {
    int a;
    int b;
} SlotPair;

typedef struct TtTask {
    u8 pad[0x110];
} TtTask;

extern void *D_006A3924;
extern int D_01B006A8;
extern float D_01B008B0[][4];
extern float D_01B00990[][4];
extern TtCfg *D_01B01064;
extern u8 D_01B01068[];
extern PppObj D_01B011A0[];
extern int D_01B012A0;
extern int D_01B012A8[28];
extern int D_01B01318[14];
extern int D_01B01350;
extern TtTask D_01B01358[14];
extern char D_01B03AE0[];
extern char D_01B03AF8[];
extern char D_01B03B10[];
extern char D_01B03B28[];

int func_0014AA50(int);
void func_00117D78(int, int, int, int);
void func_00267658(PppObj *, int, int, int);
void func_002DD0B0(float *, float *);
int func_01B03748(char *, ...);
void func_01B03778(char *);
void func_01B038B0(void *);
int func_01B03A08(void *);

int func_01B02240(void)
{
    int i;
    for (i = 0; i < 14; i++) {
        if (D_01B012A8[i * 2] == 1 && D_01B012A8[i * 2 + 1] == 0) {
            return i;
        }
    }
    return -1;
}

void func_01B02288(void)
{
    int i, k;

    for (i = 0; i < 28; i++) {
        D_01B012A8[i] = func_0014AA50(i);
    }
    for (i = 0, k = 0; i < 14; i++, k += 2) {
        if (D_01B012A8[k] != 0 && D_01B01318[i] == 0) {
            func_01B038B0(&D_01B01358[i]);
        }
    }
    for (i = 0, k = 0; i < 14; i++, k += 2) {
        if (D_01B012A8[k + 1] != 0 && D_01B01318[i] == 0) {
            func_01B03A08(&D_01B01358[i]);
            D_01B01318[i]++;
        }
    }
    D_01B006A8 = func_01B02240();
}

int func_01B023B0(void)
{
    func_01B03748(D_01B03AE0, D_01B012A0);
    D_01B01350 = 0x80;
    func_00117D78(0x2C, 0xDC, 0xF2, 0xFF);
    return 1;
}

int func_01B02400(void)
{
    u32 *p = (u32 *)&D_01B01350; /* DEBT(CAST): u32 alias forces reload of D_01B01350 */

    D_01B01350 -= 2;
    *p = (D_01B01350 < 0) ? 0 : (D_01B01350 > 0x80) ? 0x80 : D_01B01350;
    return D_01B01350 != 0;
}

int func_01B02440(void)
{
    func_01B03748(D_01B03AF8, D_01B012A0);
    return 1;
}

int func_01B02470(PppObj *p)
{
    int idx;
    int slot;

    func_01B03748(D_01B03B10, D_01B012A0);
    idx = p - D_01B011A0;
    slot = func_01B02240();
    if (slot == -1) {
        func_01B03778(D_01B03B28);
    }
    D_006A3924 = D_01B01068;
    func_00267658(p, 0x1000, D_01B01064->w10[5], 1);
    if (idx == 0) {
        func_002DD0B0(p->pos, D_01B008B0[slot]);
    } else {
        func_002DD0B0(p->pos, D_01B00990[slot]);
    }
    if ((u32)(slot - 2) < 4) {
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = -0x4000;
        p->rot[3] = 1;
    } else {
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
    }
    p->scale[2] = p->scale[1] = p->scale[0] = 0.127597004f;
    p->scale[3] = 1.0f;
    return 1;
}
