#include "common.h"

typedef struct ChrInfo {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    u8 pad08[0x0C];
    short a14;         /* 0x14 */
    short a16;         /* 0x16 */
    u8 pad18[4];
    float width;       /* 0x1C */
    float height;      /* 0x20 */
    float scale24;     /* 0x24 */
    float scale28;     /* 0x28 */
    u8 pad2C[4];
    u_long128 pos30;   /* 0x30 */
    u_long128 pos40;   /* 0x40 */
    float mtx50[16];   /* 0x50 */
    float mtx90[16];   /* 0x90 */
} ChrInfo;

extern int D_01B0D280;
extern int D_01B0D284;
extern int D_01B0D294;

void *MsGetChrHandle(int);
void func_001B6790(int, void *);
void Ch_GetRootGlobalMatrix(void *, void *);
void func_002DD0C0(void *, void *);
float MsGetChrBtlDir(int);
float MsGetChrWidth(int);
float MsGetChrHeight(int);
void MsGetChrScale(int, float *);
float func_00110AF0(void *);

void func_01B05268(ChrInfo *c)
{
    float sc[4];

    if (c->chr != 0xFF) {
        c->hnd = MsGetChrHandle(c->chr);
        func_001B6790(c->chr, &c->pos30);
        {
            register u_long128 tmp __asm__("$3") = c->pos30;
            c->pos40 = tmp;
        }
        Ch_GetRootGlobalMatrix(c->hnd, c->mtx50);
        func_002DD0C0(c->mtx90, c->mtx50);
        c->a14 = c->a16 = (int)(MsGetChrBtlDir(c->chr) * 32768.0f / 3.1415927f);
        c->width = MsGetChrWidth(c->chr);
        c->height = MsGetChrHeight(c->chr);
        if (c->height < c->width) {
            c->scale28 = c->width;
        } else {
            c->scale28 = c->height;
        }
        if (c->scale28 > 25.0f) {
            if (D_01B0D280 != 0) {
                c->scale28 = 0.025 / (double)c->scale28;
            } else if (D_01B0D284 != 0) {
                c->scale28 = 0.025 / (double)c->scale28;
            } else if (D_01B0D294 != 0) {
                c->scale28 = 0.0005f;
            } else {
                c->scale28 = (0.025 / (double)c->scale28) * 0.66f;
            }
        } else {
            c->scale28 = 0.001f;
        }
        MsGetChrScale(c->chr, sc);
        c->scale24 = c->scale28 = c->scale28 * (func_00110AF0(c->hnd) * sc[1]);
    }
}
