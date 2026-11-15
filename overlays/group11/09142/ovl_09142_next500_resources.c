/* Overlay 09142: allocate and release paired sprite resources. */
extern void *D_01B057F0[2];
void *func_002B3888(int);
void func_002B39C0(int);
void func_01B03B28(void)
{
    D_01B057F0[0] = func_002B3888(0x90);
    D_01B057F0[1] = func_002B3888(0x90);
}
void func_01B03B68(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}
