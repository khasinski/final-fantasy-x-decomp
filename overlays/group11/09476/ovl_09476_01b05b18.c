#include "p9_overlay.h"

void func_01B05DC0(float (*pts)[4], float *t, float *z, float *h, float *d, int axis, int n);
float func_01B05F80(float u, float (*pts)[4], float *t, float *z, int axis, int n);

void func_01B05B18(float *work, float (*pts)[4], float *t, float *bx, float *by, float *bz, int n)
{
    int i;

    t[0] = 0.0f;
    for (i = 1; i < n; i++) {
        float dx = pts[i][0] - pts[i - 1][0];
        float dy = pts[i][1] - pts[i - 1][1];
        float dz = pts[i][2] - pts[i - 1][2];
        double prev = t[i - 1];
        t[i] = prev + func_002E9290((double)(dx * dx + dy * dy + dz * dz));
    }
    {
        float total = t[n - 1];
        for (i = 1; i < n; i++) {
            t[i] /= total;
        }
    }
    func_01B05DC0(pts, t, bx, work, work + n, 0, n);
    func_01B05DC0(pts, t, by, work, work + n, 1, n);
    func_01B05DC0(pts, t, bz, work, work + n, 2, n);
}

void func_01B05CF0(P9Vec *out, P9Vec *pts, float *t, float *bx, float *by, float *bz, int n, float u)
{
    out->x = func_01B05F80(u, (float (*)[4])pts, t, bx, 0, n);
    out->y = func_01B05F80(u, (float (*)[4])pts, t, by, 1, n);
    out->z = func_01B05F80(u, (float (*)[4])pts, t, bz, 2, n);
    out->w = 1.0f;
}

void func_01B05DC0(float (*pts)[4], float *t, float *z, float *h, float *d, int axis, int n)
{
    int i;
    int m = n - 1;

    z[0] = 0.0f;
    z[m] = 0.0f;
    for (i = 0; i < m; i++) {
        h[i] = t[i + 1] - t[i];
        d[i + 1] = (pts[i + 1][axis] - pts[i][axis]) / h[i];
    }
    z[1] = d[2] - d[1];
    d[1] = 2.0f * (t[2] - t[0]);
    for (i = 1; i < n - 2; i++) {
        float r = h[i] / d[i];
        z[i + 1] = d[i + 2] - d[i + 1] - z[i] * r;
        d[i + 1] = 2.0f * (t[i + 2] - t[i]) - h[i] * r;
    }
    z[m - 1] -= h[m - 1] * z[m];
    for (i = n - 2; i > 0; i--) {
        z[i] = (z[i] - h[i] * z[i + 1]) / d[i];
    }
}

float func_01B05F80(float u, float (*pts)[4], float *t, float *z, int axis, int n)
{
    int i;
    int j;
    int k;
    float h;
    float d;

    i = 0;
    j = n - 1;
    while (i < j) {
        k = (i + j) / 2;
        if (t[k] < u) {
            i = k + 1;
        } else {
            j = k;
        }
    }
    if (i > 0) {
        i--;
    }
    h = t[i + 1] - t[i];
    d = u - t[i];
    return (((z[i + 1] - z[i]) * d / h + z[i] * 3.0f) * d + ((pts[i + 1][axis] - pts[i][axis]) / h - (z[i] * 2.0f + z[i + 1]) * h)) * d + pts[i][axis];
}
