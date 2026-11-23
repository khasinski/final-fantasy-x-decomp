/* 09535 rank helper (112 B). */

extern int g_ovl_64a0;

extern int func_001BB7F8(int, int, int, int *, int);
extern int fn_ovl_16d0(int);

int ovl_09535_0d40(void)
{
    int dmg;

    func_001BB7F8(g_ovl_64a0, fn_ovl_16d0(-1), 0, &dmg, 0);
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
