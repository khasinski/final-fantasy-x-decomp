/* EE Battle-Effect Overlay: group 0x11, file 09313 (0x01B007A8..0x01B01750)
 * .text: 10 functions (4,000 bytes)
 */
#include "common.h"
#include "vu0.h"

typedef struct Particle9313 {
    float rot[4];     /* 0x00 */
    float rvel[4];    /* 0x10 */
    float pos[4];     /* 0x20 */
    float vel[4];     /* 0x30 */
    float grav;       /* 0x40 */
    float gacc;       /* 0x44 */
    float floorY;     /* 0x48 */
    float drag;       /* 0x4C */
    float bounce;     /* 0x50 */
    float jitter;     /* 0x54 */
    int active;       /* 0x58 */
    int state;        /* 0x5C */
} Particle9313;

typedef struct Task9313 Task9313;
struct Task9313 {
    u8 pad00[8];
    Task9313 *p08;    /* 0x08 */
    u8 pad0C[4];
    int cb;           /* 0x10 */
    int timer;        /* 0x14 */
    u8 prio;          /* 0x18 */
};

typedef struct Spawner9313 {
    int idx;          /* 0x00 */
    int wait;         /* 0x04 */
    int count;        /* 0x08 */
} Spawner9313;

extern u8 D_01B88B40[];
extern u8 *D_01B06378;
extern u8 *D_01B0637C;
extern u8 *D_01B0632C;
extern u8 *D_01B06330;
extern Particle9313 *D_01B06328;
extern u8 D_01B06338[];
extern u8 D_01B0B6E0[];
extern u8 D_01B00040[];
extern u8 D_01B06240[];
extern u8 D_01B062C0[];
extern u8 D_01B00338[];
extern u8 D_01B05C88[];
extern u8 D_01B00350[];
extern u8 D_01B061D0[];
extern u8 D_01B05CB0[];
extern u8 D_01B06040[];
extern s8 D_01B06320[];
extern Spawner9313 D_01B06170;
extern int D_01B003B0[];
extern u8 D_01B049F0[];
extern void func_01B00788(void);

int func_002B49A0(void *a0, int a1, int a2);
void func_01B04358(void *a0, void *a1, void *a2, int a3);
void func_01B05800(void *a0, float f0, float f1, int a1, int a2);
void func_01B03940(int a0);
void func_01B05A38(void *a0, int a1);
void func_01B05B10(void *a0, void *a1, void *a2, int a3);
void func_01B034F8(int a0, void *a1, void *a2);
Task9313 *func_01B040D0(void *fn);
void func_01B04298(Task9313 *t);
int func_001038F8(void);
int func_01B035B0(void *a0);
float func_01B019E8(int a0);
void func_01B04430(void *a0, void *a1, int a2, float f0, int a3, int a4, void *a5);
void func_01B01B10(int a0, void *a1, int a2);
void func_01B02F00(void *a0);
int func_002EFD78(void);
int func_01B04510(void *a0, void *a1);
int func_01B018C0(int a0);
void func_001CE2F0(int a0, int a1);
void func_01B031E0(void *a0, void *a1);
void func_002DCE38(void *dst, void *a, void *b);
u8 *func_002B7B20(int a0, void *a1);
void func_01B04150(void *a0);
float func_002B3DB0(float a0);
float func_002B3DF8(float a0);
void func_01B05268(void *a0, void *a1, void *a2);
void func_002DD128(void *m);
void func_002DD318(void *dst, void *src, float a);
void func_002DCE08(void *dst, void *m, void *v);
void func_002DD270(void *dst, void *src, float a);
void func_002DD1C8(void *dst, void *src, float a);
u8 *func_01B05A88(void);

void func_01B00988(void);
void func_01B00A28(void);
void func_01B00A40(Task9313 *a0);
void func_01B00CF8(Task9313 *a0);
void func_01B00DD0(void *a0, u8 a1);
Particle9313 *func_01B00E98(void);
void func_01B00ED0(Task9313 *a0);
void func_01B01140(void);
void func_01B015D0(Task9313 *a0);

int func_01B007A8(void)
{
    u8 *base = D_01B88B40;
    u8 *s0 = D_01B06338;
    int i;
    Task9313 *t;

    D_01B0637C = base + 0x40000;
    D_01B0632C = base + 0x140000;
    D_01B06328 = (Particle9313 *)(base + 0x165000);
    D_01B06378 = base;
    *(int *)(s0 + 0x2C) = func_002B49A0(D_01B0B6E0, 8, 0);
    func_01B04358(s0, D_01B00040, D_01B06378, 0x40000);
    func_01B05800(D_01B06240, 1.0f, 0.75f, 0x10, 0);
    func_01B05800(D_01B06240 + 0x40, 0.75f, 1.0f, 0x10, 0xBD);
    func_01B03940(1);
    func_01B00988();
    for (i = 0x7F; i >= 0; i--) {
        D_01B06328[i].active = 0;
    }
    func_01B05A38(base + 0x160000, 0x40);
    func_01B05B10(D_01B062C0, D_01B0B6E0, D_01B00338, 1);
    *(int *)(D_01B062C0 + 0x54) = -1;
    func_01B034F8(-1, D_01B05C88, D_01B00350);
    t = func_01B040D0(func_01B00A28);
    t->prio = 1;
    func_01B04298(t);
    t = func_01B040D0(func_01B00A40);
    t->timer = 0x55;
    t->prio = 2;
    func_01B04298(t);
    return 0;
}

void func_01B00988(void)
{
    u8 *p = D_01B061D0;

    *(int *)(p + 0x00) = 0x80;
    *(int *)(p + 0x04) = func_001038F8();
    p[0x09] = 0x80;
    p[0x18] = 0x80;
    p[0x19] = 0x80;
    p[0x1A] = 0x80;
    p[0x1B] = 0x80;
    p[0x08] = 0x44;
    *(u16 *)(p + 0x42) = 9;
    p[0x0A] = 0;
    *(u16 *)(p + 0x0C) = 0;
    *(u16 *)(p + 0x0E) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    p[0x1C] = 0;
    p[0x1D] = 0;
    p[0x1E] = 0;
    p[0x1F] = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(u16 *)(p + 0x40) = 0;
    *(int *)(p + 0x44) = 0;
    *(int *)(p + 0x48) = 0;
}

void func_01B00A28(void)
{
    D_01B06330 = D_01B0632C;
}

void func_01B00A40(Task9313 *a0)
{
    u8 *s0;
    float ang;
    u8 *s1;
    Task9313 *t;

    func_01B035B0(D_01B05C88);
    if (--a0->timer > 0) {
        return;
    }
    s0 = D_01B06338;
    ang = func_01B019E8(-1);
    s1 = D_01B05CB0;
    func_01B04430(s0, s1, 3, 0.12f, 0, 0, 0);
    func_01B01B10(-1, s1 + 0xD0, 0);
    *(float *)(s1 + 0xC4) = ang;
    *(float *)(s1 + 0xD4) -= 21.6f;
    *(float *)(s1 + 0xE8) = -19.2f;
    s1 += 0x130;

    func_01B04430(s0, s1, 3, 0.07f, 0, 0, 0);
    func_01B01B10(-1, s1 + 0xD0, 0);
    *(float *)(s1 + 0xC4) = ang;
    *(float *)(s1 + 0xD4) -= 19.2f;
    *(float *)(s1 + 0xE0) = -8.4f;
    *(float *)(s1 + 0xE8) = -10.8f;
    s1 += 0x130;

    func_01B04430(s0, s1, 3, 0.07f, 0, 0, 0);
    func_01B01B10(-1, s1 + 0xD0, 0);
    *(float *)(s1 + 0xC4) = ang;
    *(float *)(s1 + 0xD4) -= 19.2f;
    *(float *)(s1 + 0xE0) = 8.4f;
    *(float *)(s1 + 0xE8) = -10.8f;

    s1 = D_01B06040;
    func_01B04430(s0, s1, 0, 0.2f, 0, 0, 0);
    func_01B01B10(-1, s1 + 0xD0, 3);
    *(float *)(s1 + 0xC4) = ang;
    *(float *)(s1 + 0xD4) -= 1.0f;
    *(float *)(s1 + 0xE8) = -19.2f;

    func_01B02F00(D_01B06320);
    D_01B06170.idx = 0;
    D_01B06170.wait = func_002EFD78() % 7;
    D_01B06170.count = 8;

    t = func_01B040D0(func_01B015D0);
    t->timer = (int)&D_01B06170;
    func_01B04298(t);

    t = func_01B040D0(func_01B00ED0);
    t->timer = 0x68;
    func_01B04298(t);

    t = func_01B040D0(func_01B01140);
    func_01B04298(t);

    a0->p08->cb = (int)func_01B00CF8;
}

void func_01B00CF8(Task9313 *a0)
{
    int r0 = func_01B035B0(D_01B05C88);
    int r1 = func_01B04510(D_01B06338, D_01B0637C);
    int i;

    if (r1 == 1 && r0 == 1) {
        for (i = 0; i < D_01B003B0[1]; i++) {
            func_001CE2F0(func_01B018C0(i), 0);
        }
        a0->timer = 3;
        a0->p08->cb = (int)func_01B00788;
    }
}

void func_01B00DD0(void *a0, u8 a1)
{
    float m0[16];
    float m1[16];
    float m2[16];
    int h = func_002B49A0(D_01B0B6E0, 4, 0);
    u8 *p;

    func_01B031E0(m1, m2);
    func_002DCE38(m0, m2, a0);
    func_002DCE38(m0, m1, m0);
    p = D_01B061D0;
    p[0x1B] = a1;
    *(u8 **)(p + 0x34) = D_01B06330;
    *(void **)(p + 0x20) = m0;
    *(void **)(p + 0x44) = m0;
    D_01B06330 = func_002B7B20(h, p);
}

Particle9313 *func_01B00E98(void)
{
    Particle9313 *p = D_01B06328;
    int i;

    for (i = 0; i < 0x80; i++, p++) {
        if (p->active == 0) {
            return p;
        }
    }
    return 0;
}

void func_01B00ED0(Task9313 *a0)
{
    float m[16];
    float v[4];
    float rot[4];
    Particle9313 *p;

    if (--a0->timer <= 0) {
        func_01B04150(a0);
        return;
    }
    p = func_01B00E98();
    if (p == 0) {
        return;
    }
    p->rot[0] = 0.0f;
    p->rot[1] = func_01B019E8(-1);
    p->rot[2] = 0.0f;
    p->rot[3] = 0.0f;
    p->rvel[0] = func_002B3DB0(0.1f);
    p->rvel[1] = func_002B3DB0(0.1f);
    p->rvel[2] = func_002B3DB0(0.1f);
    p->rvel[3] = 0.0f;

    func_01B01B10(-1, p->pos, 0);
    rot[0] = 0.0f;
    rot[1] = func_01B019E8(-1);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    v[0] = 2.4f;
    v[1] = 0.0f;
    v[2] = -9.6f;
    v[3] = 1.0f;
    func_01B05268(rot, p->pos, v);

    p->pos[1] -= 22.0f;
    {
        float ry = rot[1] + func_002B3DB0(0.15f);
        if (ry > 3.1415927f) {
            ry -= 6.2831855f;
        } else if (ry < -3.1415927f) {
            ry += 6.2831855f;
        }
        rot[1] = ry;
    }

    v[0] = func_002B3DB0(0.15f) + 3.6f;
    v[2] = 0.0f;
    func_002DD128(m);
    func_002DD318(m, m, rot[1]);
    func_002DCE08(v, m, v);

    p->vel[0] = v[0];
    p->vel[1] = -func_002B3DF8(1.0f);
    p->vel[2] = v[2];
    p->vel[3] = 0.0f;
    p->grav = 0.0f;
    p->gacc = 0.2f;
    p->floorY = 0.0f;
    p->drag = 0.85f;
    p->bounce = 0.6f;
    p->jitter = func_002B3DF8(2.0f);
    p->active = 0x14;
    p->state = 0;
}

static inline void wrap_angle(float *dst, float delta)
{
    float r = *dst + delta;
    if (r > 3.1415927f) {
        r -= 6.2831855f;
    } else if (r < -3.1415927f) {
        r += 6.2831855f;
    }
    *dst = r;
}

void func_01B01140(void)
{
    float base[16];
    float mat[16];
    Particle9313 *p = D_01B06328;
    int max_life = 0x14;
    int i;
    float *mat3;

    func_002DD128(base);
    mat3 = &mat[12];
    base[10] = 0.4f;
    base[5] = 0.4f;
    base[0] = 0.4f;
    for (i = 0x7F; i >= 0; i--, p++) {
        u8 alpha;
        if (p->active == 0) {
            continue;
        }
        if (p->state == 1) {
            p->active--;
            alpha = (p->active << 7) / max_life;
        } else {
            alpha = 0x80;
        }
        wrap_angle(&p->rot[0], p->rvel[0]);
        wrap_angle(&p->rot[1], p->rvel[1]);
        wrap_angle(&p->rot[2], p->rvel[2]);

        {
            float vy = p->vel[1];
            float g = p->grav + p->gacc;
            float nvy = vy + g;
            p->grav = g;
            p->pos[0] += p->vel[0];
            p->pos[1] += nvy;
            p->pos[2] += p->vel[2];
            p->vel[0] *= p->drag;
            p->vel[2] *= p->drag;
            if (p->pos[1] >= p->floorY) {
                if (vy != 0.0f && nvy != 0.0f) {
                    double d0 = p->pos[1] - p->floorY;
                    double d1;
                    float t;
                    if (d0 < 0.0) d0 = -d0;
                    d1 = nvy;
                    if (d1 < 0.0) d1 = -d1;
                    t = (float)(1.0 - (d0 / d1));
                    p->pos[0] -= p->vel[0] * t;
                    p->pos[2] -= p->vel[2] * t;
                }
                p->pos[1] = p->floorY;
                {
                    double dj = p->jitter;
                    if (dj < 0.0) dj = -dj;
                    if (dj > 0.01) {
                        p->vel[0] += func_002B3DB0(p->jitter);
                        p->vel[2] += func_002B3DB0(p->jitter);
                        p->jitter *= 0.5f;
                    }
                }
                p->rvel[0] = func_002B3DB0(0.47123894f);
                p->rvel[1] = func_002B3DB0(0.47123894f);
                p->rvel[2] = func_002B3DB0(0.47123894f);
                p->vel[1] = -nvy * p->bounce;
                {
                    double dv = p->vel[1];
                    if (dv < 0.0) dv = -dv;
                    if (dv < (double)p->gacc) {
                        p->vel[0] *= 0.5f;
                        p->vel[2] *= 0.5f;
                        p->vel[1] = 0.0f;
                        p->gacc = 0.0f;
                    }
                    p->grav = 0.0f;
                    p->state = 1;
                }
            }
        }

        func_002DD270(mat, base, p->rot[0]);
        func_002DD318(mat, mat, p->rot[1]);
        func_002DD1C8(mat, mat, p->rot[2]);
        MMI_COPY_LQ_A3(mat, p->pos);
        MMI_COPY_SQ_A3(mat3);
        func_01B00DD0(mat, alpha);
    }
}

void func_01B015D0(Task9313 *a0)
{
    Spawner9313 *sp = (Spawner9313 *)a0->timer;
    s8 id;
    u8 *s0;

    if (sp->wait > 0) {
        sp->wait--;
        return;
    }
    if (sp->count == 0) {
        func_01B04150(a0);
        return;
    }
    id = D_01B06320[sp->idx];
    {
        int r = (int)func_01B05A88();
        if (r != 0) {
            s0 = (u8 *)r;
            func_01B04430(D_01B06338, s0, 1, 0.2f, 0, 0, D_01B049F0);
            func_01B01B10(id, s0 + 0xD0, 1);
            *(float *)(s0 + 0xC4) = func_01B019E8(id);
            *(int *)(s0 + 0x120) = func_01B018C0(id);
        }
        r = (int)func_01B05A88();
        if (r != 0) {
            s0 = (u8 *)r;
            func_01B04430(D_01B06338, s0, 2, 0.15f, 2, 0, 0);
            func_01B01B10(id, s0 + 0xD0, 3);
            *(float *)(s0 + 0xC4) = func_01B019E8(id);
            *(float *)(s0 + 0xD4) -= 1.0f;
        }
    }
    sp->idx++;
    sp->wait = (func_002EFD78() % 7) + 7;
    sp->count--;
}
