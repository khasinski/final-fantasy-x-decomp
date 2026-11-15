#include "p7_overlay.h"

/* F3 TU rank 16: target visibility / draw helpers. */

void func_01B025F0(int visible)
{
    u8 *list;
    int n;
    int i;
    int self;

    if (func_01B021E8(-1) == 1) {
        MsSetChrVisible(1, visible);
        return;
    }
    list = MsGetBattleList(11, &n);
    self = func_01B01598(-1);
    for (i = 0; i < n; i++) {
        if (list[i] != self) {
            MsSetChrVisible(list[i], visible);
        }
    }
}

void func_01B026A8(int visible)
{
    u8 *list;
    int n;
    int i;

    if (func_01B021E8(-1) == 0) {
        func_01B02798(visible);
        return;
    }
    list = MsGetBattleList(11, &n);
    for (i = 0; i < n; i++) {
        MsSetChrVisible(list[i], visible);
    }
}

void func_01B02738(void)
{
    int v = func_001AF358();
    int *p;

    for (p = D_01B00598; *p != -1; p++) {
        if (*p == v) {
            return;
        }
    }
    func_01B026A8(0);
}

void func_01B02798(int visible)
{
    u8 *list;
    int n;
    int i;

    list = MsGetBattleList(9, &n);
    for (i = 0; i < n; i++) {
        MsSetChrVisible(list[i], visible);
    }
}

int func_01B02810(int idx, int a1, int a2)
{
    return graphicCharacterInstanceSetMeshSegmentAlpha(func_01B01630(idx), a1, a2);
}

void func_01B02850(int idx, int a1)
{
    MsSetChrShadow(func_01B01598(idx), a1);
}

void func_01B02880(int idx, int a1)
{
    void *h = func_01B01630(idx);

    Ch_DrawEnEffect(h, a1);
    if (a1 == 0) {
        func_002985E0(h);
    } else {
        func_002985C0(h);
    }
}

int func_01B028D8(int idx, int a1)
{
    return Ch_SetCalcNorm(func_01B01630(idx), a1);
}

void func_01B02908(int idx, int a1)
{
    MsChrSEfoot(func_01B01598(idx), a1);
}

void func_01B02938(int idx, int a1)
{
    func_001B7498(func_01B01598(idx), a1);
}
