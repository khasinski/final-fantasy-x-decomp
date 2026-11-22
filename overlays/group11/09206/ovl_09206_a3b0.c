#include "common.h"
#include "vu0.h"

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct TrackA3B0 {
    u8 pad00[0x20];
    Vec3 *pts;          /* 0x20 */
    float *base;        /* 0x24 */
    float *curve;       /* 0x28 */
    float t;            /* 0x2C */
    float dt;           /* 0x30 */
    s32 rem;            /* 0x34 */
    s32 n;              /* 0x38 */
    s32 active;         /* 0x3C */
} TrackA3B0;

void func_002DD128(void *m);
void func_002DCE08(float *dst, void *m, float *src);
float func_01B089F8(float a, float b, float c, float d, float e, float t);
float func_01B08A60(float t, float *p, s32 n, int stride);
void func_01B08DD8(void *m, float *rot);
float func_01B08F88(float t, float *p, s32 n, int stride);

void func_01B0A3B0(TrackA3B0 *tr, float *dst)
{
    float m[4][4];
    float rot[4];
    float vec[4];
    Vec3 *p = tr->pts;
    float z;

    if (--tr->rem != 0) {
        tr->t += tr->dt;
        rot[0] = func_01B08F88(tr->t, &p->x, tr->n, 3);
        rot[1] = func_01B08F88(tr->t, &p->y, tr->n, 3);
        z = func_01B08A60(tr->t, &p->z, tr->n, 3);
    } else {
        tr->active = 0;
        p += tr->n - 1;
        rot[0] = p->x;
        rot[1] = p->y;
        z = p->z;
    }

    rot[2] = 0.0f;
    rot[3] = 0.0f;
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = z;
    vec[3] = 1.0f;

    func_002DD128(m);
    func_01B08DD8(m, rot);
    func_002DCE08(vec, m, vec);

    VU0_LQC2(1, 0, tr->base);
    VU0_LQC2(2, 0, vec);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, dst);
}

void func_01B0A4E0(TrackA3B0 *tr, float *dst)
{
    float m[4][4];
    float rot[4];
    float vec[4];
    Vec3 *p = tr->pts;
    float z;
    float t;

    if (--tr->rem != 0) {
        float *c = tr->curve;
        tr->t += tr->dt;
        t = func_01B089F8(c[0], c[1], c[2], c[3], c[4], tr->t);
        rot[0] = func_01B08F88(t, &p->x, tr->n, 3);
        rot[1] = func_01B08F88(t, &p->y, tr->n, 3);
        z = func_01B08A60(t, &p->z, tr->n, 3);
    } else {
        tr->active = 0;
        p += tr->n - 1;
        rot[0] = p->x;
        rot[1] = p->y;
        z = p->z;
    }

    rot[2] = 0.0f;
    rot[3] = 0.0f;
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = z;
    vec[3] = 1.0f;

    func_002DD128(m);
    func_01B08DD8(m, rot);
    func_002DCE08(vec, m, vec);

    VU0_LQC2(1, 0, tr->base);
    VU0_LQC2(2, 0, vec);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, dst);
}
