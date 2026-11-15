#include "p7_overlay.h"

/* F3 TU rank 26: per-target forwarding wrappers. */

void func_01B02310(int idx, int a1)
{
    MsSetChrMoveFlag(func_01B01598(idx), a1);
}

void func_01B02340(int idx)
{
    op_et_bindeff(func_01B01630(idx));
}

void func_01B02360(int idx)
{
    func_00299218(func_01B01630(idx));
}

void func_01B02380(int idx)
{
    func_002994B8(func_01B01630(idx));
}

void func_01B023A0(int idx)
{
    func_002994D8(func_01B01630(idx));
}

void func_01B023C0(int idx)
{
    func_002985C0(func_01B01630(idx));
}

void func_01B023E0(int idx)
{
    func_002985E0(func_01B01630(idx));
}

int func_01B02400(int idx)
{
    return func_00110B78(func_01B01630(idx));
}

void func_01B02428(int idx, int a1)
{
    Ch_EffectSetEffectLevel(func_01B01630(idx), a1);
}

int func_01B02458(int idx)
{
    return func_001B6FB8(func_01B01598(idx));
}

void func_01B02480(int idx, int a1)
{
    func_001B6FD8(func_01B01598(idx), a1);
}

void func_01B024B0(int idx, int visible)
{
    int chr;

    if (D_01B005A0.mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            MsSetChrVisible(chr, visible);
            return;
        }
    }
    func_01B02520(idx, visible == 0);
}

void func_01B02520(int idx, int a1)
{
    func_00110718(func_01B01630(idx), a1);
}

void func_01B02550(int idx, int a1)
{
    func_001B57F0(func_01B01598(idx), a1);
}
