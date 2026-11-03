#include "p4_overlay.h"

void func_01B0A008(u_long64 *tex, int alpha);
void func_01B0A2E8(P4Prm *prm, int alpha);

s16 *func_01B09F78(P4Thread *th, s16 *pc)
{
    P4Prm *prm = th->prm;
    void *res = th->res[prm->res_idx];

    switch (th->h21A & 0xF000) {
    case 0x1000:
        func_01B0A008(op_oef2_a_get(res, 2, pc[1]), pc[2]);
        pc += 3;
        break;
    case 0x2000:
        func_01B0A2E8(prm, pc[1]);
        pc += 2;
        break;
    }
    return pc;
}
