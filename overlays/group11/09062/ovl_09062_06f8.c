/* Shared 09062-family effect ready gate (148 B, 160 containers, zero debt). */

extern int func_0029B830(int);
extern void MsEffectReady(int, int);
extern int MsEffectMotionLevel(int);
extern void fn_ovl_init(void);
extern int fn_ovl_end(void);
extern int fn_ovl_tick(void);

extern int g_ovl_id;
extern int g_ovl_flag;
extern int (*g_ovl_hdr[])(void);

int ovl_09062_06f8(void)
{
    if (func_0029B830(1) != 0) {
        return 0;
    }
    if (g_ovl_flag == 0) {
        MsEffectReady(g_ovl_id, 0);
        g_ovl_flag = 1;
    }
    if (MsEffectMotionLevel(g_ovl_id) <= 0) {
        return 0;
    }
    fn_ovl_init();
    g_ovl_hdr[3] = fn_ovl_end;
    g_ovl_hdr[4] = fn_ovl_tick;
    return 0;
}
