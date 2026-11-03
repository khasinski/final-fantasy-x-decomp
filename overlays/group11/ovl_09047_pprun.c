#include "p6_overlay.h"

/* F2 TU rank 124: run a ppp part on a given heap. Compiled with -O0. */

extern int D_006A3924;

int _pppRunPart(void *part, void *arg);

int func_01B0B568(register int heap, register void *part, register void *arg)
{
    D_006A3924 = heap;
    return _pppRunPart(part, arg);
}
