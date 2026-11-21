/* Shared 09193-family spline interpolation (336 B, 159 containers). */

float ovl_09193_4730(float *arr, int count, int stride, float t)
{
    int idx = (int)t;
    float a = arr[idx * stride];
    float b;
    float c;

    if (idx == count - 1) {
        b = a;
    } else {
        b = arr[(idx + 1) * stride];
    }
    t -= (float)idx;
    if (t < 0.5f) {
        if (idx != 0) {
            /* DEBT(FAKE): pin v1/v0 to match original temp-register allocation on idx-1. */
            register int prev __asm__("v1") = idx - 1;
            register int off __asm__("v0") = prev * stride;
            c = (b + arr[off]) * 0.5f;
            a += (c - a) / (1.51f / (0.5f - t));
        }
    } else {
        int next;
        /* DEBT(FAKE): pin v0 to match original temp-register allocation on count-2 and next*stride. */
        register int last2 __asm__("v0") = count - 2;
        if (idx < last2) {
            next = idx + 2;
        } else {
            next = count - 1;
        }
        {
            register int off __asm__("v0") = next * stride;
            c = (a + arr[off]) * 0.5f;
        }
        b += (c - b) / (1.51f / (t - 0.499999f));
    }
    c = 0.0f;
    if (t != 0.0f) {
        c = (b - a) / (1.0f / t);
    }
    return a + c;
}
