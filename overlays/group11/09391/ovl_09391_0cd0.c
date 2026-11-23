/* 09391 rank helper (112 B). */

extern int g_ovl_6430;

extern int func_001BB7F8(int, int, int *, int, int);
extern int fn_ovl_1660(int);

int ovl_09391_0cd0(void)
{
    int dmg;

    func_001BB7F8(g_ovl_6430, fn_ovl_1660(-1), &dmg, 0, 0);
    if (dmg >= 0) {
        return 0;
    }
    dmg = -dmg;
    if (dmg < 100) {
        return 0;
    }
    if (dmg < 500) {
        return 1;
    }
    return 2;
}
