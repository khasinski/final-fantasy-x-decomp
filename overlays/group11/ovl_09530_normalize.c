/* Scalar vector normalization in battle effect overlay 9530. */
double func_002ED038(float f);
double func_002E9290(double d);
float func_002EC440(double d);

float func_01B015E0(float *v)
{
    float len;
    float inv;

    len = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    func_002ED038(len);
    len = func_002EC440(func_002E9290(func_002ED038(len)));
    if (len != 0.0f) {
        inv = 1.0f / len;
        v[0] = v[0] * inv;
        v[1] = v[1] * inv;
        v[2] = v[2] * inv;
    }
    return len;
}

int func_01B016A0(char *fmt, ...)
{
    return 0;
}

void func_01B016D0(char *fmt, ...)
{
}

int func_01B016F8(char *fmt, ...)
{
    return 0;
}

void func_01B01728(void)
{
}

void func_01B01730(void)
{
}

void func_01B01738(int a, int b)
{
}
