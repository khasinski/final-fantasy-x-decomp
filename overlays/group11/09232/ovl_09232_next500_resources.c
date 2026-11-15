/* Overlay 09232: allocate and release paired sprite resources. */
extern void *D_01B04C10[2];
void *func_002B3888(int);
void func_002B39C0(int);
void func_01B03158(void)
{
    D_01B04C10[0] = func_002B3888(0x90);
    D_01B04C10[1] = func_002B3888(0x90);
}
void func_01B03198(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}
