/* Shared 09147-family motion-ready dispatch (156 B). */

extern int g_ovl_id;
extern int g_ovl_flag;
extern int (*g_ovl_hdr[])(void);

extern int func_0029B830(int);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);
extern void fn_ovl_init(void);
extern int fn_ovl_a(void);
extern int fn_ovl_b(void);

int ovl_09147_09d8(void)
{
    if (func_0029B830(1) != 0) {
        return 0;
    }
    if (g_ovl_flag == 0) {
        int one = 1;
        func_001CDC58(g_ovl_id, one);
        g_ovl_flag = one;
    }
    if (func_001CDAF8(g_ovl_id) <= 0) {
        return 0;
    }
    fn_ovl_init();
    g_ovl_hdr[3] = fn_ovl_a;
    g_ovl_hdr[4] = fn_ovl_b;
    return 0;
}
