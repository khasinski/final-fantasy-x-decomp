#include "p1_overlay.h"

s16 *func_01B07F28(P1Th *th, s16 *pc)
{
    P1Sub *sub = th->sub;
    P1Chr *chr = owu_chr_hd[sub->chr];
    P1Obj300 *obj = &th->obj300;
    P1Sub *other;
    void *work;
    int n;
    u8 *model;
    P1Ring *ring;
    P1Th *self;
    struct P1SlotList *list;

    switch (th->op & 0xF000) {
    case 0x0000:
        n = pc[1];
        pc += 2;
        ring = op_malloc(th->heap, n * sizeof(P1RingEnt) + 16);
        sub->work = ring;
        ring->count = n;
        ring->head = 0;
        break;
    case 0x1000:
        th->m00[0][0] = th->m00[0][1] = pc[1] * 0.00390625f;
        pc += 2;
        th->m00[0][2] = sub->f3C * 0.00390625f;
        op_unit_m_scale2(th->m40, th->m00);
        func_002B5318(th->m40, th->m40, sub->rot);
        func_002B56D8(th->m00, opus_local_get(th, sub), th->m40);
        func_002B56D8(th->m00, th->m2C0, th->m00);
        func_01B08430(sub->work, sub, th, th->h212);
        break;
    case 0x2000:
        if (th->h212 == 0) {
            func_01B08330(opus_no_get(obj, sub, pc[1])->work, sub);
        }
        pc += 2;
        break;
    case 0x4000:
        model = obj->model;
        Ch_TextureSetImageBase(chr, -1, 0x3C00);
        Ch_TextureSetClutBase(chr, -1, 12000);
        pc += 1;
        func_002A72F8(model, chr, 0, obj->model + 0x80000);
        work = sub->work = op_malloc(th->heap, func_01B08988((struct P1Model *)model)); /* DEBT(CAST): model data typed as bytes for the texture upload */
        self = th;
        opus_rt_m_chara(self, sub->chr, sub->pos, sub->rot, 256.0f, self->b21E);
        func_01B08A10(work, model, self);
        break;
    case 0x5000:
        other = opus_no_get(obj, sub, pc[1]);
        pc += 2;
        self = th;
        opus_rt_m_chara(self, sub->chr, sub->pos, sub->rot, 256.0f, self->b21E);
        Ch_TextureLoadImage(chr, -1);
        func_0010D4D8(chr, -1);
        func_01B08E08(sub->work, sub, other, self, self->m280, self->m2C0);
        break;
    case 0x6000:
        n = pc[1];
        pc += 2;
        list = op_malloc(th->heap, n * 48 + 16);
        sub->work = list;
        func_01B09498(list, n);
        break;
    case 0x7000:
        other = opus_no_get(obj, sub, pc[1]);
        self = th;
        opus_rt_m_chara(self, sub->chr, other->pos, other->rot, 256.0f, self->b21E);
        work = other->work;
        op_unit_m(self->m40);
        func_002B56D8(self->mC0, opus_local_get(self, sub), self->m40);
        func_002B56D8(self->mC0, self->m2C0, self->mC0);
        func_01B094D8(sub->work, work, sub, opus_no_get(obj, sub, pc[2]), self, self->mC0, self->h212);
        pc += 3;
        break;
    case 0x8000:
        func_00117E08(1);
        pc += 1;
        break;
    }
    return pc;
}
