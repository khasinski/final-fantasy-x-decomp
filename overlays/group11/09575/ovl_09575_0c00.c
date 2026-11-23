/* Twin functions 0x01B00C00..0x01B00CC4 in 09575 (0x01B00C60..0x01B00D24 in 09574). */
extern int D_01B008A4;
extern int func_001D3A70(int);
extern void func_001CE050(int, int);
extern int func_001CE1A8(int);
extern void func_001CE2F0(int, int);

int func_01B00C00(void)
{
    int r = func_001D3A70(D_01B008A4);
    if ((unsigned int)(r - 177) < 2) {
        func_001CE050(D_01B008A4, 178);
    } else if ((unsigned int)(r - 185) < 2) {
        func_001CE050(D_01B008A4, 186);
    }
    return 1;
}

int func_01B00C70(void)
{
    if (func_001CE1A8(D_01B008A4) == -1) {
        func_001CE2F0(D_01B008A4, 0);
        return 0;
    }
    return 1;
}
