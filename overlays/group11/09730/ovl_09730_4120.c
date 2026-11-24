extern float D_01B00A80;

extern void func_01B036A0(void);
extern void func_00173A70(int);

int func_01B04120(void)
{
    func_01B036A0();
    return 1;
}

int func_01B04140(void)
{
    func_00173A70(4);
    D_01B00A80 = 1.0f;
    return 1;
}
