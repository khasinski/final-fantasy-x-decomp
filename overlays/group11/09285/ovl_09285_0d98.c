/* Shared 09285-family target position getter (36 B, 5 containers). */

extern int g_ovl_tbl[];
extern void fn_ovl_1620(int, int, int, void *);

void ovl_09285_0d98(int idx, void *dst)
{
    fn_ovl_1620(-1, g_ovl_tbl[idx], 0, dst);
}
