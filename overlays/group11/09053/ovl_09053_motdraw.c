#include "p9_overlay.h"

/* Draw a list of keyframed primitives under one parent matrix (family F11, TU rank 58). */

typedef struct P9MotObj {
    P9MotHead head;
    P9Vec pos;
    int col;
    float scale;
    u8 pad[8];
} P9MotObj;

extern P9MotCtx D_01B007A0;

void func_01B02EB8(float a[4][4], float b[4][4]);

void func_01B054F0(P9MotObj *obj, float mtx[4][4], int count)
{
    float m[4][4] __attribute__((aligned(16)));
    float rot[4][4] __attribute__((aligned(16)));
    float wld[4][4] __attribute__((aligned(16)));
    P9MotCtx *ctx;
    int i;

    func_01B02EB8(rot, wld);
    ctx = &D_01B007A0;
    ctx->mtx = m;
    ctx->unk1C = 0;
    for (i = 0; i < count; i++, obj++) {
        P9MotData *data;
        P9MotKey *key;

        {
            int col = obj->col;
            float s = obj->scale; /* DEBT(ORDER): loads hoisted above the colour store */

            ctx->col.word = col;
            func_002DD998(m[0], mtx[0], s);
        }
        func_002DD998(m[1], mtx[1], obj->scale);
        func_002DD998(m[2], mtx[2], obj->scale);
        func_002DCE08(m[3], wld, &obj->pos.x);
        func_002DCE38(m, rot, m);
        data = obj->head.data;
        key = &data->key[obj->head.frame];
        if (obj->head.active) {
            obj->head.timer -= 0x200;
            if (obj->head.timer <= 0) {
                obj->head.frame++;
                if (obj->head.frame >= data->count) {
                    if (key->flags & 0x80) {
                        obj->head.frame = 0;
                    } else {
                        obj->head.frame--;
                        obj->head.active = 0;
                        goto submit;
                    }
                }
                key = &data->key[obj->head.frame];
                obj->head.timer = key->dur;
            }
        }
    submit:
        ctx->result = func_002CD590((u8 *)data + key->ofs, ctx);
    }
}
