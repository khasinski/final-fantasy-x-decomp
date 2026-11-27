#include "common.h"

typedef struct CamSeq {
    u8 pad00[0x24];
    int target;
} CamSeq;

extern CamSeq *D_01B1DBA0;
extern int D_01B1DBA4;
extern int D_01B1DBA8;

int func_01B06498(void);
void func_01B06878(CamSeq *);

void func_01B06968(void)
{
    int cur = func_01B06498();
    CamSeq *p = D_01B1DBA0;

    if (p != 0) {
        D_01B1DBA4++;
        if (cur == p->target) {
            D_01B1DBA0 = p + 1;
            D_01B1DBA4 = 0;
            D_01B1DBA8++;
            func_01B06878(p + 1);
            __asm__ volatile("");
        }
    }
}
