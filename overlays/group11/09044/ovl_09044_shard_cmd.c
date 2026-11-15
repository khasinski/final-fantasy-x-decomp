#include "p4_overlay.h"

void func_01B01A60(P4SrcModel *src, P4Shards *dst, P4Param *prm);

s16 *func_01B01358(P4Thread *th, s16 *pc)
{
    P4Prm *prm = th->prm;
    P4Param *param;
    P4SrcModel *model;
    P4Shards *dst;

    if ((th->h21A & 0xF000) == 0) {
        param = (P4Param *)((u8 *)pc + pc[2]);
        model = op_oef2_a_get(th->res[prm->res_idx], 4, pc[1]);
        pc += 3;
        dst = op_malloc(th->heap, (model->count << 8) | 0x20);
        prm->param = param;
        dst->mode = param->h00;
        prm->shards = dst;
        func_01B01A60(model, dst, param);
        prm->state = 0x82;
        opus_draw_on(&th->draw_list, th->draw_id);
    }
    return pc;
}
