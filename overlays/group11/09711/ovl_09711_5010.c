#include "common.h"

typedef struct ChrInfo {
    int id;            /* 0x00 */
    void *hnd;         /* 0x04 */
    u8 pad08[0x0C];
    s16 a14;           /* 0x14 */
    s16 a16;           /* 0x16 */
    u8 pad18[4];
    float w;           /* 0x1C */
    float h;           /* 0x20 */
    float s24;         /* 0x24 */
    float sz;          /* 0x28 */
    u8 pad2C[4];
    u_long128 pos0;    /* 0x30 */
    u_long128 pos1;    /* 0x40 */
    float mtx0[16];    /* 0x50 */
    float mtx1[16];    /* 0x90 */
} ChrInfo;

extern double D_01B0B060;

void *MsGetChrHandle(int);
void func_001B6790(int, void *);
void Ch_GetRootGlobalMatrix(void *, void *);
void func_002DD0C0(void *, void *);
float MsGetChrBtlDir(int);
float MsGetChrWidth(int);
float MsGetChrHeight(int);
void MsGetChrScale(int, float *);
float func_00110AF0(void *);

void func_01B05010(ChrInfo *c)
{
    float sc[4];
    int ang;

    if (c->id == 255) {
        return;
    }
    c->hnd = MsGetChrHandle(c->id);
    func_001B6790(c->id, &c->pos0);
    {
        register u_long128 tmp __asm__("$3") = c->pos0;
        c->pos1 = tmp;
    }
    Ch_GetRootGlobalMatrix(c->hnd, c->mtx0);
    func_002DD0C0(c->mtx1, c->mtx0);
    ang = (int)(MsGetChrBtlDir(c->id) * 32768.0f / 3.1415927f);
    c->a16 = ang;
    c->a14 = ang;
    c->w = MsGetChrWidth(c->id);
    c->h = MsGetChrHeight(c->id);
    if (c->h < c->w) {
        c->sz = c->w;
    } else {
        c->sz = c->h;
    }
    if (c->sz > 25.0f) {
        c->sz = (float)(0.025 / (double)c->sz);
    } else {
        c->sz = 0.001f;
    }
    MsGetChrScale(c->id, sc);
    c->s24 = c->sz = c->sz * (func_00110AF0(c->hnd) * sc[1]);
}
