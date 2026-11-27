#include "oef_overlay.h"

void func_002B2A80(void *p, int a, int b, int c);

void func_01B048A8(int cur, int start, int fin, int fout, u8 r, u8 g, u8 b, int prio)
{
    int t = cur - start;
    register int total __asm__("$8");
    u8 alpha;
    register int pr __asm__("$24") = prio;
    register int rr __asm__("$11") = r;
    unsigned long long col;
    register unsigned long long *p __asm__("$15");

    if (t > 0) {
        total = fin + fout;
        if (t < total) {
            p = (unsigned long long *)D_006A3BCC;
            D_006A3BCC = (u8 *)p + 0x60;
            if (t <= fin) {
                alpha = (t << 7) / fin;
            } else {
                t = total - t;
                alpha = (t << 7) / fout;
            }
            col = (((unsigned long long)alpha << 24) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8))) | (unsigned long long)rr;
            ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
            ((unsigned long long *)p)[3] = 21998;
            ((unsigned long long *)p)[4] = pr;
            ((unsigned long long *)p)[5] = 66;
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
}
