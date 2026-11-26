#include "iopsound.h"

extern s32 D_06CE70[32];
extern s32 *D_06CEF0;

void func_014004(s32 id) {
    s32 *p;
    if (id == -1) {
        return;
    }
    p = D_06CE70;
    do {
        if (*p == id) {
            s32 *q = p;
            do {
                q[0] = q[1];
                q++;
            } while (q < &D_06CE70[32]);
            D_06CE70[31] = -1;
            if (p < D_06CEF0) {
                D_06CEF0--;
            }
        }
        p++;
    } while (p < &D_06CE70[32]);
}
