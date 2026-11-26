#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0xC];
    float fD4;
    u8 padD8[0x58];
} Sub130_9394;

typedef struct {
    int w00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    int w1C;
    int w20;
    int w24;
    int w28;
    u16 h2C;
    u16 h2E;
} SubB18_9394;

typedef struct {
    u8 pad000[0x250];
    float f250;
    float f254;
    float f258;
} SubC30_9394;

typedef struct {
    u8 pad000[0x130];
    Sub130_9394 sub130;
    u8 pad260[0x724];
    float f984;
    u8 pad988[0x8];
    u_long128 q990;
    u8 pad9A0[0x178];
    SubB18_9394 subB18[3];
    u8 padBA8[0x8];
    u8 subBB0[0x80];
    SubC30_9394 subC30;
    u8 padE8C[0x14];
    int wEA0;
    int wEA4;
    int wEA8;
    int wEAC;
    int wEB0;
    int wEB4;
    int wEB8;
} Obj9394_2;

extern u8 D_01B096E0[];
extern Obj9394_2 *D_01B097A8;
extern void func_01B01928(void);

extern void func_01B04F98(void *, void *, int, int, int, int, float);
extern void func_01B08928(void *, int, int, float, float);
extern void func_01B08648(void *, int);
extern void func_01B09330(void *, int, float *, int);
extern void func_01B09360(void *, int, float *, int);
extern void *func_01B04C38(void *);
extern void func_01B04E00(void *);

void func_01B01AA0(void)
{
    float v3[4];
    float v2[2];
    Obj9394_2 *s0 = D_01B097A8;
    Sub130_9394 *s1 = &s0->sub130;
    SubB18_9394 *s3;
    SubC30_9394 *s2;

    func_01B04F98(D_01B096E0, s1, 1, 0, 0, 0, 0.23f);
    MMI_COPY_LQ_A3((u8 *)s0 + 0x200, &s0->q990);
    MMI_COPY_SQ_A3((u8 *)s0 + 0x200);
    s1->fC4 = s0->f984;
    s1->fD4 -= 0.5f;
    s3 = &s0->subB18[0];
    s2 = &s0->subC30;
    func_01B08928(s0->subBB0, 30, 0, 1.0f, 0.5f);

    func_01B08648(s3, 150);
    s3->f04 = 0.0f;
    s3->f08 = 0.2f;
    s3->f0C = 0.0f;
    s3->f10 = 0.0f;
    s3->f14 = 5.0f;
    s3->f18 = 0.5f;
    s3->h2C |= 3;

    s3 = &s0->subB18[1];
    func_01B08648(s3, 100);
    s3->f04 = 0.0f;
    s3->f08 = 0.2f;
    s3->f0C = 0.0f;
    s3->f10 = 0.5f;
    s3->f14 = 5.0f;
    s3->f18 = 0.0f;
    s3->h2C |= 3;
    s3->w24 = 150;

    s3 = &s0->subB18[2];
    func_01B08648(s3, 40);
    s3->f04 = 0.0f;
    s3->f08 = 0.2f;
    s3->f0C = 0.0f;
    s3->f10 = 4.0f;
    s3->f14 = 1.0f;
    s3->f18 = 0.0f;
    s3->h2C |= 3;
    s3->w24 = 352;

    v2[0] = 2.4434611797332764f;
    v2[1] = -3.071779727935791f;
    func_01B09330(s2, 2, v2, 60);

    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = 0.0f;
    func_01B09360(s2, 0, v3, 120);
    func_01B09360(s2, 1, v3, 120);

    v3[0] = 0.8f;
    v3[1] = 0.8352941274642944f;
    v3[2] = 1.0f;
    func_01B09360(s2, 2, v3, 120);

    v3[0] = s2->f250 * 0.5f;
    v3[1] = s2->f254 * 0.5f;
    v3[2] = s2->f258 * 0.5f;
    func_01B09360(s2, 3, v3, 120);
}

void func_01B01D20(void)
{
    Obj9394_2 *v0 = D_01B097A8;

    v0->wEA0 = 0;
    v0->wEA4 = 30;
    v0->wEA8 = 30;
    v0->wEAC = 222;
    v0->wEB0 = 222;
    func_01B04E00(func_01B04C38(func_01B01928));
}

void func_01B01D68(void)
{
    Obj9394_2 *v1 = D_01B097A8;

    v1->wEB4 = 100;
    v1->wEB8 = 100;
}
