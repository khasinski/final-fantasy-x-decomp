#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    float vx, vy, vz;
    float rot;
    float f30;
    u8 pad34[0x4];
    s32 w38;
    s32 w3C;
    u8 pad40[0x5];
    u8 b45;
    u8 pad46;
    u8 b47;
    u8 pad48;
    u8 b49;
    u8 pad4A;
    u8 b4B;
} Part5AB0;

extern s32 D_01B069F4;
extern u8 D_01B069F8[];

extern void func_01B01B60(s32, s32, void *, void *);
extern Part5AB0 *func_01B05AB0(void);
extern void **func_01B04570(void *, s32);
extern void func_01B053A8(void *, void *);
extern float func_002B3DB0(float);
extern float func_001ACED8(void);
extern s32 func_002EFD78(void);

void ovl_09287_0df0(void)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    s32 i;

    if (D_01B069F4 <= 0) {
        return;
    }
    D_01B069F4--;
    func_01B01B60(-1, 6, 0, &v10);
    v10.y += 5.0f;
    v30.x = -800.0f;
    v30.y = 0.0f;
    v30.z = 0.0f;
    v30.w = 1.0f;
    func_01B01B60(-1, 6, &v30, &v20);

    i = 0;
    do {
        Part5AB0 *s0 = func_01B05AB0();
        s32 sz;

        if (s0 == 0) {
            return;
        }
        if ((i & 1) == 0) {
            MMI_COPY_LQ_A3(&v00, &v10);
            MMI_COPY_SQ_A3(&v00);
        } else {
            MMI_COPY_LQ_A3(&v00, &v20);
            MMI_COPY_SQ_A3(&v00);
        }
        func_01B053A8(s0, *func_01B04570(D_01B069F8, 1));
        s0->pos.x = v00.x + func_002B3DB0(5.0f);
        s0->pos.y = v00.y + func_002B3DB0(5.0f);
        s0->pos.z = v00.z + func_002B3DB0(5.0f);
        s0->pos.w = 1.0f;
        s0->vx = (func_001ACED8() - 1.5f) * 0.6f;
        s0->vy = (func_001ACED8() - 1.5f) * 0.8f - 0.38f;
        s0->vz = (func_001ACED8() - 1.5f) * 0.6f;
        s0->rot = func_002B3DB0(3.1415927f);
        s0->f30 = (func_002B3DB0(1.0f) + 1.0f) * 0.03f;
        sz = (func_002EFD78() % 16) + 16;
        s0->b4B = 0;
        s0->w38 = sz;
        s0->w3C = sz;
        i++;
    } while (i < 8);

    i = 0;
    do {
        Part5AB0 *s0 = func_01B05AB0();
        s32 sz;

        if (s0 == 0) {
            return;
        }
        if ((i & 1) == 0) {
            MMI_COPY_LQ_A3(&v00, &v10);
            MMI_COPY_SQ_A3(&v00);
        } else {
            MMI_COPY_LQ_A3(&v00, &v20);
            MMI_COPY_SQ_A3(&v00);
        }
        func_01B053A8(s0, *func_01B04570(D_01B069F8, 0));
        s0->pos.x = v00.x + func_002B3DB0(5.0f);
        s0->pos.y = v00.y + func_002B3DB0(5.0f);
        s0->pos.z = v00.z + func_002B3DB0(5.0f);
        s0->pos.w = 1.0f;
        s0->vx = (func_001ACED8() - 1.5f) * 0.6f;
        s0->vy = (func_001ACED8() - 1.5f) * 0.8f - 0.38f;
        s0->vz = (func_001ACED8() - 1.5f) * 0.6f;
        s0->rot = func_002B3DB0(3.1415927f);
        s0->f30 = (func_002B3DB0(1.0f) + 1.0f) * 0.15f;
        sz = (func_002EFD78() % 16) + 16;
        s0->b47 = 64;
        s0->b4B = 0;
        s0->b45 = 160;
        s0->b49 = 160;
        s0->w38 = sz;
        s0->w3C = sz;
        i++;
    } while (i < 2);
}
