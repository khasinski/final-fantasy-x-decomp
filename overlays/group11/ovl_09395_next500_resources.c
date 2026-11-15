/* Overlay 09395: allocate and release paired sprite resources. */
extern void *D_01B06B90[2];
void *func_002B3888(int);
void func_002B39C0(int);
void func_01B04E30(void)
{
    D_01B06B90[0] = func_002B3888(0x90);
    D_01B06B90[1] = func_002B3888(0x90);
}
void func_01B04E70(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}
