#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct TtPart {
    u8 pad00[0x40];
    float pos[4];
    int rot[4];
    float scale[4];
} TtPart;

typedef struct Particle {
    int active;         /* 0x00 */
    u8 pad04[0xC];
    float pos[3];       /* 0x10 */
    float f1c;          /* 0x1C */
    float vel[3];       /* 0x20 */
    float f2c;          /* 0x2C */
    int w30;            /* 0x30 */
    int w34;            /* 0x34 */
    u8 pad38[0x38];
    float f70;          /* 0x70 */
    float f74;          /* 0x74 */
    int c78;            /* 0x78 */
    int c7c;            /* 0x7C */
    int c80;            /* 0x80 */
    float f84;          /* 0x84 */
    u8 pad88[0x38];     /* total 0xC0 */
} Particle;

typedef struct PPool {
    int count;          /* 0x00 */
    Particle *items;    /* 0x04 */
    u8 pad08[0x68];
} PPool;

extern void *D_006A3924;
extern float D_01B007D0[];
extern void *D_01B00868;
extern void *D_01B00874;
extern TtCfg *D_01B00878;
extern u8 D_01B00880[];
extern u8 D_01B01130[];
extern int D_01B01164;
extern void *D_01B01168;
extern void *D_01B0116C;
extern PPool D_01B01170;
extern PPool D_01B011E0;
extern int D_01B01250;
extern int D_01B01254;
extern int D_01B01258;
extern int D_01B01260;
extern int D_01B01590;

extern char D_01B04580[];
extern char D_01B04590[];
extern char D_01B045A0[];
extern char D_01B045B0[];
extern char D_01B045C0[];
extern char D_01B045C8[];

int func_01B03858(char *, ...);
void func_01B03888(char *, ...);
void func_01B03DE8(void *, void *, int);
void func_01B03E60(void *);
Particle *func_01B03F98(void *, void *);
void *func_01B03FF8(void *, void *, void *, float);
void func_01B040D0(void *, int, float, float);
void func_00107428(int, int, int, float *);
void func_00267658(void *, int, int, int);
void *func_002B49A0(void *, int, int);
int func_002EFD78(void);

Particle *func_01B024D0(void *a0, int a1, float *a2)
{
    Particle *p = func_01B03F98(a0, (void *)a1);

    if (p == 0) {
        func_01B03858(D_01B04580);
        return 0;
    }
    p->w34 = 0x20;
    p->pos[0] = a2[0] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 5.0f;
    p->pos[1] = a2[1] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 5.0f;
    p->pos[2] = a2[2] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 5.0f;
    p->vel[0] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.3f;
    p->vel[1] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.3f;
    p->vel[2] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.3f;
    p->f70 = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.5f + 1.0f;
    p->c78 = 0x12;
    p->c7c = 0x13;
    p->c80 = 0x10;
    return p;
}

int func_01B026D8(void)
{
    func_01B03858(D_01B04590);
    D_01B01164 = (int)func_002B49A0(D_01B00874, 4, 0);
    func_01B03DE8(&D_01B011E0, D_01B0116C, 100);
    func_01B040D0(&D_01B011E0, 0, 0.0f, 0.0f);
    return 1;
}

int func_01B02758(PPool *pool)
{
    float pos[4];
    int i;
    Particle *p;

    func_00107428(D_01B01250, 0x85, 0, pos);
    if (D_01B01590 < 100) {
        p = func_01B024D0(pool, D_01B01164, pos);
        if (p == 0) {
            func_01B03888(D_01B045A0);
        }
        p->f70 *= 0.5f;
        p->pos[0] = pos[0] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 2.0f;
        p->pos[1] = pos[1] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 2.0f;
        p->pos[2] = pos[2] + ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 2.0f;
        p->c78 = 0x46;
        p->c7c = 0x50;
        p->c80 = 0x5A;
    }
    p = pool->items;
    for (i = 0; i < pool->count; i++, p++) {
        if (p->active != 0) {
            p->f84 = (float)((double)D_01B007D0[0x20 - p->w34] * 0.0390625);
        }
    }
    func_01B03E60(pool);
    {
        void *tmp = D_01B00868;
        D_01B00868 = func_01B03FF8(pool, D_01B01130, tmp, 0.0f);
    }
    return 1;
}

int func_01B02978(void)
{
    func_01B03858(D_01B045B0);
    D_01B01164 = (int)func_002B49A0(D_01B00874, 4, 0);
    func_01B03DE8(&D_01B01170, D_01B01168, 100);
    func_01B040D0(&D_01B01170, 0, 0.0f, 0.0f);
    return 1;
}

int func_01B029F8(PPool *pool)
{
    float pos[4];
    int i;
    Particle *p;

    func_00107428(D_01B01254, 0xA, 0, pos);
    if (D_01B01260 < 0x235 && D_01B01260 % 5 == 0) {
        func_01B024D0(pool, D_01B01164, pos);
    }
    p = pool->items;
    for (i = 0; i < pool->count; i++, p++) {
        if (p->active != 0) {
            int idx = 0x20 - p->w34;
            p->f84 = D_01B007D0[idx];
            if (idx >= 0x20) {
                func_01B03888(D_01B045C0);
            } else if (idx < 0) {
                func_01B03888(D_01B045C0);
            }
        }
    }
    func_01B03E60(pool);
    {
        void *tmp = D_01B00868;
        D_01B00868 = func_01B03FF8(pool, D_01B01130, tmp, 100.0f);
    }
    return 1;
}

void func_01B02B48(TtPart *p)
{
    func_01B03858(D_01B045C8, D_01B01258);
    D_006A3924 = D_01B00880;
    func_00267658(p, 0x1000, D_01B00878->w10[5], 1);
    p->scale[2] = p->scale[1] = p->scale[0] = 0.03114929982f;
    p->scale[3] = 1.0f;
    p->pos[0] = -29.0f;
    p->pos[1] = -121.0f;
    p->pos[2] = -6.0f;
    p->pos[3] = 0.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
}
