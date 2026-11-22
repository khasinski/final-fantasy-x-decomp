/* Shared 09427-cluster track selector & mode dispatcher (116 B, 2 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x3C];
    int mode;
} TrackObj;

extern void fn_case1(void *, void *);
extern void fn_case2(void *, void *);
extern void fn_case3(void *, void *);
extern void fn_case4(void *, void *);
extern void fn_case5(void *, void *);
extern void fn_case6(void *, void *);

void *ovl_09427_53f0(u8 *p, int sel)
{
    return p + (sel == 0 ? 112 : 176);
}

void ovl_09427_5400(TrackObj *p, void *out)
{
    switch (p->mode) {
    case 0:
        break;
    case 1:
        fn_case1(p, out);
        break;
    case 2:
        fn_case2(p, out);
        break;
    case 3:
        fn_case3(p, out);
        break;
    case 4:
        fn_case4(p, out);
        break;
    case 5:
        fn_case5(p, out);
        break;
    case 6:
        fn_case6(p, out);
        break;
    }
}
