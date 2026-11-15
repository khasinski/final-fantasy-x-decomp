/* Scale the effect direction and translate it to the target position. */
extern void func_002DD068(float *, float *, float);
extern float D_01D01510;
extern float D_01D01520[4];
extern float D_01D01530[4];

void func_01B00938(float *p, float scale)
{
    func_002DD068(p, D_01D01520, scale);
    p[0] += D_01D01530[0];
    p[1] += D_01D01530[1] + D_01D01510;
    p[2] += D_01D01530[2];
}
