#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad0[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x50];
} OvlObj;

typedef struct {
    float pos[4];
    float vx;
    float vy;
    float vz;
    float vw;
    float ax;
    float ay;
    float az;
    float aw;
    u8 pad30[0x0C];
    float scale;
    int f40;
    int f44;
    float f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
} OvlPtcl;

typedef struct {
    u8 pad0[0x720];
    OvlObj obj720;
    u8 pad850[0xC90];
    float f14E0;
    float f14E4;
    u8 pad14E8[0x4C];
    float f1534;
    u8 pad1538[0x08];
    float f1540;
    float f1544;
    u8 pad1548[0x18];
    float vec1560[4];
    float vec1570[4];
    u8 pad1580[0x2C0];
    float f1840;
} OvlState;

extern u8 D_01B0AA08;
extern u8 D_01B0AA48;
extern OvlState *D_01B0AB88;

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_01B062B0(void *, void *, int, int, int, int, float);
extern int *func_01B06840(void *, int);
extern void func_01B07678(void *, int);
extern OvlPtcl *func_01B0A018(void);

void func_01B02D98(void) {
    float mat0[16];
    float mat1[16];
    float v80[4];
    float v90[4];
    OvlState *s = D_01B0AB88;
    int i, j;

    func_002DD128(mat0);
    v90[0] = 0.0f;
    v90[1] = 0.0f;
    v90[3] = 1.0f;

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 8; j++) {
            OvlPtcl *p = func_01B0A018();
            int *tex;
            float r;
            if (p == 0) {
                break;
            }
            tex = func_01B06840(&D_01B0AA08, 2);
            func_01B07678((u8 *)p + 0x30, *tex);
            copy_vec(p->pos, s->vec1560);
            p->pos[1] += func_002B3DB0(20.0f) - 30.0f;
            r = func_002B3DB0(3.14159274f);
            func_002DD318(mat1, mat0, r);
            v90[2] = func_002B3DB0(25.0f);
            func_002DCE08(v80, mat1, v90);
            p->pos[0] += v80[0];
            p->pos[2] += v80[2];
            p->vx = v80[0] * 0.015f + func_002B3DB0(0.02f);
            p->vy = -func_002B3DF8(2.0f);
            p->vz = v80[2] * 0.015f + func_002B3DB0(0.02f);
            p->vw = func_002B3DB0(3.14159274f);
            p->ax = 0.0f;
            p->ay = func_002B3DB0(0.01f) + 0.035f;
            p->az = 0.0f;
            p->aw = 1.0f;
            p->scale = (func_002B3DB0(0.2f) + 1.0f) * 0.03f;
            p->f40 = 0;
            p->f58 = 140;
            p->f5C = 0;
            p->f4C = 140;
            p->f50 = 0;
            p->f60 = i;
        }
    }
}

void func_01B03020(void) {
    OvlState *s = D_01B0AB88;
    float y = s->f1544 - 1.0f;
    s->f1544 = y;
    s->f14E4 = y;
}

void func_01B03048(void) {
    float mat[16];
    float v[4];
    OvlState *s = D_01B0AB88;
    float y;

    func_002DD128(mat);
    func_002DD318(mat, mat, s->f1534);
    v[0] = -10.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(v, mat, v);
    s->f14E0 = s->f1540 + v[0];
    y = s->vec1570[1] - 80.0f;
    s->f1544 = y;
    s->f14E4 = y;
}

void func_01B030E0(void) {
    OvlState *s = D_01B0AB88;
    float y;
    s->vec1560[1] -= 1.0f;
    y = s->f1544 - 0.5f;
    s->f1544 = y;
    s->f14E4 = y;
}

void func_01B03118(void) {
    OvlState *s = D_01B0AB88;
    OvlObj *obj = &s->obj720;
    func_01B062B0(&D_01B0AA48, obj, 1, 0, 0, 0, 0.055f);
    copy_vec(obj->pos, s->vec1560);
    obj->fC4 = s->f1840;
    obj->pos[1] += 20.0f;
}
