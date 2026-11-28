#include "common.h"

extern signed char *MsGetBattleList(int, int *);

int func_01B02510(int a0)
{
    int n0;
    int n1;
    signed char *p0;
    signed char *p1;
    int i;

    p0 = MsGetBattleList(9, &n0);
    for (i = 0; i < n0; i++) {
        if (a0 == p0[i]) {
            return 1;
        }
    }
    p1 = MsGetBattleList(11, &n1);
    for (i = 0; i < n1; i++) {
        if (a0 == p1[i]) {
            return 0;
        }
    }
    return -1;
}
