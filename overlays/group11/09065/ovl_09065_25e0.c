/* EE Battle-Effect Overlay: group 0x11, file 09065 (shared by ~131 p4 overlays)
 * .text: 0x01B025E0..0x01B026A4 (1 function, 196B).
 */
#include "p4_overlay.h"
#include "vu0.h"

extern void func_01B02B18(void *shards, P4Thread *th);
extern void func_01B02D98(P4Thread *th, P4Prm *prm, void *shards, float *v90, void *p328);

u16 *func_01B025E0(P4Thread *th, u16 *pc)
{
    P4Prm *prm;

    prm = th->prm;
    switch (th->h21A & 0xF000) {
    case 0x0000:
        prm->shards = op_malloc(th->heap, 0x27E20);
        MMI_SQ_ZERO(0, th);
        th->pos[0] = 0.0f;
        th->pos[1] = 0.0f;
        pc += 1;
        func_01B02B18(prm->shards, th);
        break;
    case 0x1000:
        MMI_SQ_ZERO(0, th);
        th->pos[0] = 2048.0f;
        th->pos[1] = 2048.0f;
        func_01B02D98(th, prm, prm->shards, (float *)((u8 *)prm + 0x90), *(void **)((u8 *)th + 0x328));
        pc += 1;
        break;
    }
    return pc;
}
