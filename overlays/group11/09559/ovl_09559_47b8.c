#include "oef_overlay.h"

void func_002B2A80(void *p, int a, int b, int c);

void func_01B047B8(int cur, int start, int fin, u8 r, u8 g, u8 b)
{
    int t = cur - start;
    u8 alpha;
    unsigned long long col;
    register unsigned long long *p __asm__("$14");

    if (t > 0) {
        p = (unsigned long long *)D_006A3BCC;
        D_006A3BCC = (u8 *)p + 0x60;
        if (t >= fin) {
            alpha = 128;
        } else {
            alpha = (t << 7) / fin;
        }
        col = (((unsigned long long)alpha << 24) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8))) | (unsigned long long)r;
        ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
        ((unsigned long long *)p)[3] = 21998;
        ((unsigned long long *)p)[4] = 0x44;
        ((unsigned long long *)p)[5] = 0x42;
        ((unsigned long long *)p)[6] = col;
        ((unsigned long long *)p)[7] = 1;
        ((int *)p)[16] = 0x7000;
        ((int *)p)[17] = 0x7300;
        ((int *)p)[20] = 0x9000;
        ((int *)p)[21] = 0x8d00;
        ((int *)p)[18] = 0xffff00;
        ((int *)p)[22] = 0xffff00;
        ((int *)p)[19] = 0;
        ((int *)p)[23] = 0;
        func_002B2A80(p, 6, 1, 0);
    }
}
