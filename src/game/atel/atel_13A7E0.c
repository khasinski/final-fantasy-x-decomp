/* tu_071 0x13a7e0-0x13a940: low; ~TOSetHideSubtitleFlag (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

char *func_0013A7E0(char *p, int i) {
    Ofs8 *e = &((Ofs8 *)p)[i];

    return p + e->off;
}

char *func_0013A7F8(char *p, int i) {
    return p + *(u16 *)(p + (i * 8 | 4));
}

int func_0013A810(char *p, int i) {
    Ofs8 *e = &((Ofs8 *)p)[i];

    return e->h2;
}

char *func_0013A820(int idx, int mode, int which) {
    Sys3D8 *g = (Sys3D8 *)AtelGetCurCtrlWork(); /* DEBT(CAST): same block seen through Sys3D8 */
    char *t = which ? g->p38 : g->p34;

    if (t != 0) {
        t = mode ? func_0013A7F8(t, idx) : func_0013A7E0(t, idx);
    } else {
        t = D_0030B8C0;
    }
    return t;
}

int func_0013A8A0(int a) {
    return (int)func_0013A820(a, 0, 0); /* DEBT(CAST): string pointer returned as int */
}

int func_0013A8C0(int a) {
    return (int)func_0013A820(a, 1, 0); /* DEBT(CAST): string pointer returned as int */
}

int func_0013A8E0(int a) {
    return (int)func_0013A820(a, 0, 1); /* DEBT(CAST): string pointer returned as int */
}

int func_0013A900(int i, int unused) { /* DEBT(TYPE): funcs.h declares (v, w) */
    Sys3D8 *g = (Sys3D8 *)AtelGetCurCtrlWork(); /* DEBT(CAST): same block seen through Sys3D8 */

    return g->p34 ? func_0013A810(g->p34, i) : 0;
}
