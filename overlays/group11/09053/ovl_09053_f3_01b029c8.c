#include "p7_overlay.h"

/* F3 TU rank 38. */

void func_01B029C8(int idx, float f, int a1)
{
    int chr;

    if (D_01B005A0.mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            MsSetChrTransparent(chr, f, a1);
            return;
        }
    }
    func_00110540(func_01B01630(idx), f, a1);
}

void func_01B02A58(int idx, void *m)
{
    void *h = func_01B01630(idx);
    int mode = D_01B005A0.mode;
    float pos[4];
    int chr;

    if (m != 0) {
        Ch_GetRootGlobalMatrix(h, m);
    } else if (mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            func_001B6790(chr, pos);
            MsSetChrPos(chr, pos);
        }
    }
    Ch_SetOrgMatrix(h, m);
}

void func_01B02AF8(int idx, int a1, int a2)
{
    int chr = func_01B01598(idx);

    MsSetChrDirTarget(D_01B005A0.chr, 2, 0, chr, a1, a2);
}
