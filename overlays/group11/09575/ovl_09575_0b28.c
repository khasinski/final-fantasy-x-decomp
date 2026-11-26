extern float D_01B00738;
extern int D_01B008B8;

extern void func_00117F58(int, int, int, int);

int func_01B00B28(void)
{
    int t;
    D_01B008B8 = (int)((float)D_01B008B8 - (128.0f / D_01B00738));
    t = D_01B008B8;
    D_01B008B8 = (t < 0) ? 0 : ((t > 128) ? 128 : t);
    func_00117F58(0x60, 0x60, 0x60, D_01B008B8);
    return D_01B008B8 != 0;
}
