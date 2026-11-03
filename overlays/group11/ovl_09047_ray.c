#include "p6_overlay.h"

/* F7 TU rank 5: ray / sphere intersection, direction angles and an orbit solver. Compiled
 * with -O0. The TU's next function func_01B0CBD0 (sqrtf through VU0 vsqrt, inline asm in the
 * original; TU rank 172) is not part of this unit. */

typedef struct P6Ray {
    P6Vec org;              /* 0x00 */
    P6Vec dir;              /* 0x10 */
    float radius;           /* 0x20 */
    float t;                /* 0x24 out: nearest hit distance */
} P6Ray;

float func_01B0CBD0(float x);               /* sqrtf (VU0) */
double func_002E76D0(double x);             /* atan */
double func_002E8C28(double y, double x);   /* atan2 */
void func_002DD038(void *dst, void *a, void *b);
float func_01B0C0E8(float *v);

int func_01B0BE70(P6Ray *ray)
{
    float a;
    float b;
    float c;
    float d;

    a = ray->dir.x * ray->dir.x;
    a = a + ray->dir.y * ray->dir.y;
    a = a + ray->dir.z * ray->dir.z;
    b = ray->dir.x * ray->org.x;
    b = b + ray->dir.y * ray->org.y;
    b = b + ray->dir.z * ray->org.z;
    b = b * 2.0f;
    c = ray->org.x * ray->org.x;
    c = c + ray->org.y * ray->org.y;
    c = c + ray->org.z * ray->org.z;
    c = c - ray->radius * ray->radius;
    d = b * b - 4.0f * a * c;
    c = -b;
    b = a * 2.0f;
    if (d < 0.0f) {
        return 0;
    }
    ray->t = (c - func_01B0CBD0(d)) / b;
    return 1;
}

float func_01B0C080(P6Vec *a, P6Vec *b)
{
    P6Vec d;

    func_002DD038(&d, a, b);
    return func_01B0C0E8(&d.x);
}

float func_01B0C0E8(float *v)
{
    float s;

    s = v[0] * v[2];
    if (s > 0.0f) {
        s = (v[0] > 0.0f) ? 0.0f : -3.1415927f;
        s = s + func_002E76D0(v[2] / v[0]);
    } else if (s < 0.0f) {
        s = (v[2] > 0.0f) ? 1.5707964f : -1.5707964f;
        s = s - func_002E76D0(v[0] / v[2]);
    } else if (v[0] != 0.0f) {
        s = (v[0] > 0.0f) ? 0.0f : 3.1415927f;
    } else if (v[2] != 0.0f) {
        s = (v[2] > 0.0f) ? 1.5707964f : -1.5707964f;
    } else {
        return 6.2831855f;
    }
    return s;
}

float func_01B0C390(float *v)
{
    float s;

    s = v[1] * v[3];
    if (s > 0.0f) {
        s = (v[1] > 0.0f) ? 0.0f : -3.1415927f;
        s = s + func_002E76D0(v[3] / v[1]);
    } else if (s < 0.0f) {
        s = (v[3] > 0.0f) ? 1.5707964f : -1.5707964f;
        s = s - func_002E76D0(v[1] / v[3]);
    } else if (v[1] != 0.0f) {
        s = (v[1] > 0.0f) ? 0.0f : 3.1415927f;
    } else if (v[3] != 0.0f) {
        s = (v[3] > 0.0f) ? 1.5707964f : -1.5707964f;
    } else {
        return 6.2831855f;
    }
    return s;
}

float func_01B0C650(float *v)
{
    float s;

    s = v[3] * v[1];
    if (s > 0.0f) {
        s = (v[3] > 0.0f) ? 0.0f : -3.1415927f;
        s = s + func_002E76D0(v[1] / v[3]);
    } else if (s < 0.0f) {
        s = (v[1] > 0.0f) ? 1.5707964f : -1.5707964f;
        s = s - func_002E76D0(v[3] / v[1]);
    } else if (v[3] != 0.0f) {
        s = (v[3] > 0.0f) ? 0.0f : 3.1415927f;
    } else if (v[1] != 0.0f) {
        s = (v[1] > 0.0f) ? 1.5707964f : -1.5707964f;
    } else {
        return 6.2831855f;
    }
    return s;
}

int func_01B0C910(int far, float a, float b, float c, float d, float *dist, float *angle)
{
    float d2;
    float c2;
    float bc;
    float disc;
    float t0;
    float r;
    float t1;
    float t2;
    float t;
    float x;
    float y;

    d2 = d * d;
    c2 = c * c;
    bc = b * c;
    disc = d2 * d2 - c2 * a * a - d2 * bc;
    if (disc < 0.0f) {
        return 0;
    }
    disc = func_01B0CBD0(disc);
    t0 = d2 - bc;
    t1 = (t0 + disc) / c2;
    t2 = (t0 - disc) / c2;
    if (t1 <= 0.0f && t2 <= 0.0f) {
        return 0;
    }
    if (far) {
        if (t1 >= t2) {
            t = t1;
        } else {
            t = t2;
        }
    } else if (t1 > 0.0f && t1 <= t2) {
        t = t1;
    } else {
        t = t2;
    }
    r = func_01B0CBD0(t);
    *dist = r;
    x = a / d / r;
    y = (b - c * t) / d / r;
    *angle = -func_002E8C28(y, x);
    return 1;
}
