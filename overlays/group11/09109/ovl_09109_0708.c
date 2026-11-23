/* Shared buffer swap helper (44 B, 09109 @ 0x01B00708, 34 open containers). */

extern void fn_ovl_4f38(void);
extern void *g_ovl_ptr_5ab0;
extern void *g_ovl_ptr_0744;

void ovl_09109_0708(void)
{
    fn_ovl_4f38();
    g_ovl_ptr_0744 = g_ovl_ptr_5ab0;
}
