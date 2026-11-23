/* Shared 09097 pre-start / sound trigger (176 B, 10 open containers). */

#include "common.h"

extern void *g_hdr[];
extern int g_53f0;
extern int g_53f4;

extern int func_0029B830(int);
extern int fn_0590(void);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);
extern void fn_05d0(void);
extern void fn_04a0(void);
extern void fn_04f0(void);

int ovl_09097_03f0(void)
{
    if (func_0029B830(1) != 0) {
        return 0;
    }
    if (fn_0590() != 1) {
        return 0;
    }
    if (g_53f4 == 0) {
        func_001CDC58(g_53f0, 0);
        g_53f4 = 1;
    }
    if (func_001CDAF8(g_53f0) <= 0) {
        return 0;
    }
    fn_05d0();
    g_hdr[3] = fn_04a0;
    g_hdr[4] = fn_04f0;
    return 0;
}
