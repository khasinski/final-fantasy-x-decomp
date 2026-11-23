#include "p9_overlay.h"
#include "vu0.h"

typedef struct Ovl09224Item {
    P9MotHead head;     /* 0x00 */
    P9Vec pos;          /* 0x10 */
    float vel[3];       /* 0x20 */
    float rotZ;         /* 0x2C */
    float scale;        /* 0x30 */
    float zofs;         /* 0x34 */
    int life;           /* 0x38 */
    int fadeMax;        /* 0x3C */
    int fadeCur;        /* 0x40 */
    u8 col0[4];         /* 0x44 */
    union {
        int word;
        u8 rgba[4];
    } col1;             /* 0x48 */
    int used;           /* 0x4C */
    u16 flags;          /* 0x50 */
    u8 pad52[0xE];      /* 0x52 */
} Ovl09224Item;

extern P9MotCtx D_01B00670;
extern Ovl09224Item *D_01B0AFF0;
extern int D_01B0AFF8;
extern int D_01B0AFFC;

void func_01B02930(float m1[4][4], float m2[4][4]);
void func_002DD0C0(float dst[4][4], float src[4][4]);

void func_01B056E8(void)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float m3[4][4];
    float m4[4][4];
    Ovl09224Item *item;
    P9MotCtx *ctx;
    int i;
    int active;

    item = D_01B0AFF0;
    active = 0;
    func_01B02930(m1, m2);
    ctx = &D_01B00670;
    ctx->mtx = m3;
    func_002DD128(m0);

    for (i = 0; i < D_01B0AFF8; i++, item++) {
        if (item->used != 0) {
            P9MotData *data;
            P9MotKey *key;
            float sc;

            active++;
            VU0_LQC2_INPUTS(1, &item->pos, item->vel, &item->pos);
            VU0_LQC2(2, 0, item->vel);
            VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
            VU0_SQC2(1, 0, &item->pos);

            sc = item->scale;
            m0[2][2] = sc;
            m0[1][1] = sc;
            m0[0][0] = sc;
            func_002DD1C8(m3, m0, item->rotZ);
            func_002DCE08(m3[3], m2, (float *)&item->pos);

            ctx->unk1C = 0;
            if (item->flags & 1) {
                func_002DD0C0(m4, m3);
                m4[3][2] += item->zofs;
                func_002DCE38(m4, m1, m4);
                ctx->unk1C = (int)m4;
            }
            func_002DCE38(m3, m1, m3);

            if (item->fadeMax > 0) {
                int t = item->fadeCur;
                if (t < 0) {
                    t = -t;
                }
                ctx->col.rgba[0] = (item->col1.rgba[0] * t + item->col0[0] * (item->fadeMax - t)) / item->fadeMax;
                ctx->col.rgba[1] = (item->col1.rgba[1] * t + item->col0[1] * (item->fadeMax - t)) / item->fadeMax;
                ctx->col.rgba[2] = (item->col1.rgba[2] * t + item->col0[2] * (item->fadeMax - t)) / item->fadeMax;
                ctx->col.rgba[3] = (item->col1.rgba[3] * t + item->col0[3] * (item->fadeMax - t)) / item->fadeMax;
                if (++item->fadeCur > item->fadeMax) {
                    item->fadeMax = 0;
                }
            } else {
                ctx->col.word = item->col1.word;
            }

            data = item->head.data;
            key = &data->key[item->head.frame];
            if (item->head.active != 0) {
                item->head.timer -= 0x200;
                if (item->head.timer <= 0) {
                    item->head.frame++;
                    if (item->head.frame >= data->count) {
                        if (key->flags & 0x80) {
                            item->head.frame = 0;
                        } else {
                            item->head.frame--;
                            item->head.active = 0;
                            goto done_key;
                        }
                    }
                    key = &data->key[item->head.frame];
                    item->head.timer = key->dur;
                }
            }
        done_key:
            {
                int draw = 1;
                if (item->life < 0) {
                    draw = item->head.active;
                }
                if (draw == 1) {
                    ctx->result = func_002CD590((u8 *)data + key->ofs, ctx);
                } else {
                    item->life = 1;
                }
            }
            if (item->life > 0) {
                if (--item->life == 0) {
                    item->used = 0;
                }
            }
        }
    }
    D_01B0AFFC = active;
}
