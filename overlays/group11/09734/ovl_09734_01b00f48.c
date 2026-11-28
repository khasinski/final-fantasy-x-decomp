#include "common.h"

extern signed char *MsGetBattleList(int, int *);

int func_01B00F48(int a0)
{
    int n0;
    int n1;
    signed char *p;
    int i;

    p = MsGetBattleList(9, &n0);
    for (i = 0; i < n0; i++) {
        if (a0 == p[i]) {
            return 1;
        }
    }
    p = MsGetBattleList(11, &n1);
    for (i = 0; i < n1; i++) {
        if (a0 == p[i]) {
            return 0;
        }
    }
    return -1;
}
