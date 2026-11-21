/* Shared 09147-family draw/camera callback (76 B). */

extern float g_ovl_f1;
extern float g_ovl_f2;

extern void fn_ovl_3608(int);
extern void func_001AAC18(float, float);

int ovl_09147_0a78(void)
{
    g_ovl_f2 = 0.0f;
    g_ovl_f1 = 0.0f;
    fn_ovl_3608(1);
    func_001AAC18(g_ovl_f1, g_ovl_f2);
    return 0;
}
