/* Battle-effect overlay 09540: 0x01B021F0..0x01B0232C */
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

extern void *D_006A3924;
extern TtCfg *D_01B00AF4;
extern u8 D_01B00AF8[];
extern PppObj D_01B01DB0[];
extern float D_01B00710[][4];
extern int D_01B01EB4;
extern char D_01B03350[];

int func_01B02FE0(char *, ...);
void func_00267658(PppObj *, int, int, int);

int func_01B021F0(void)
{
    return 1;
}

int func_01B021F8(PppObj *p)
{
    int idx;
    register float s __asm__("$f1"); /* DEBT(FAKE): pin $f1 to match scale register */

    func_01B02FE0(D_01B03350, D_01B01EB4);
    idx = p - D_01B01DB0;
    if (idx == 0) {
        register float one __asm__("$f0"); /* DEBT(FAKE): pin $f0 to match 1.0f reg */
        D_006A3924 = D_01B00AF8;
        func_00267658(p, 0x1000, D_01B00AF4->w10[0], 1);
        s = 0.1875f;
        one = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = s;
        p->scale[3] = one;
    } else {
        register float one __asm__("$f0"); /* DEBT(FAKE): pin $f0 to match 1.0f reg */
        D_006A3924 = D_01B00AF8;
        func_00267658(p, 0x1000, D_01B00AF4->w10[1], 1);
        s = 0.209500998f;
        one = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = s;
        p->scale[3] = one;
    }
    p->pos[0] = D_01B00710[idx][0];
    p->pos[1] = D_01B00710[idx][1];
    p->pos[2] = D_01B00710[idx][2];
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
