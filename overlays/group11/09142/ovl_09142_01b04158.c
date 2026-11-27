/* Shared 09142 (0x01B04158..0x01B042AC) & 09395 (0x01B05460..0x01B055B4). */
extern char D_01B047A8[];
extern int func_002EF240(char *, ...);
extern void func_002B5C18(void *, float (*)[4], int);

void func_01B04158(float (*v)[4], int n)
{
    int i;
    for (i = 0; i < n; i++, v++) {
        func_002EF240(D_01B047A8, (*v)[0], (*v)[1], (*v)[2], (*v)[3], i);
    }
}

void func_01B04218(void *a0, float (*dst)[4], int n, float x0, float y0, float z0, float x1, float y1, float z1)
{
    int i;
    float (*p)[4] = dst;
    for (i = 0; i < n; i++, p++) {
        float t = (float)i / (float)(n - 1);
        (*p)[0] = x0 + (x1 - x0) * t;
        (*p)[1] = y0 + (y1 - y0) * t;
        (*p)[2] = z0 + (z1 - z0) * t;
        (*p)[3] = 1.0f;
    }
    func_002B5C18(a0, dst, n);
}
