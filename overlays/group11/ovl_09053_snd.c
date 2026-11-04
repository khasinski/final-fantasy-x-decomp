#include "p8_overlay.h"

typedef struct P8Group {
    u8 pad00[0x10];
    P8List list;       /* 0x10 */
    int w20;           /* 0x20 */
    int w24;           /* 0x24 */
    int w28;           /* 0x28 */
    int w2C;           /* 0x2C */
    u16 h30;           /* 0x30 */
} P8Group;

void yiRenderEnable(int a);
void yiRenderDisable(int a);
int yiGetDrawMask(void);
void yiSetDrawMask(int mask);
void func_00173828(float *a, float *b, float *c);
void func_00173888(void *a);
void *op_oef2_a_get(void *res, int type, int idx);
void op_oef2_stream_cue(void *se, int a, int b);
void op_oef2_sound_cue_multi(void *res, int from, int to, int flags);
int op_oef2_sound_cue_check(int a);
void op_oef2_sound_cue_trans(int a);
int op_oef2_se_on(void *se, int a, int b);
int op_oef2_se_3d_on(void *se, int a, int b);
int op_oef2_se_3d_move(void *se, int a, int b);

void func_01B03638(int on)
{
    if (on == 1) {
        yiRenderEnable(1);
    } else {
        yiRenderDisable(1);
    }
}

void func_01B03658(int on)
{
    if (on == 1) {
        yiSetDrawMask(yiGetDrawMask() | 4);
    } else {
        yiSetDrawMask(yiGetDrawMask() & 0xFFFFFFFB);
    }
}

void func_01B036A0(float *out, void *a1)
{
    float t[3];

    func_00173828(&t[0], &t[1], &t[2]);
    out[3] = 0.0f;
    out[2] = -t[0];
    out[1] = 255.0f - t[2];
    out[0] = -(255.0f / (t[1] - t[0]));
    func_00173888(a1);
}

void func_01B03728(void *res, int from, int to)
{
    op_oef2_sound_cue_multi(res, (u16)from, (u16)to, 1);
}

void func_01B03738(void *res, int idx, int a2)
{
    op_oef2_stream_cue(op_oef2_a_get(res, 6, idx), a2, 1);
}

int func_01B03770(void)
{
    int r = 1;

    if (op_oef2_sound_cue_check(1) != 0) {
        op_oef2_sound_cue_trans(1);
        r = 0;
    }
    return r;
}

void func_01B037B0(void *res, int idx, int a, int b)
{
    op_oef2_se_on(op_oef2_a_get(res, 6, idx), a, b);
}

void func_01B037F8(void *res, int idx, int a, int b)
{
    op_oef2_se_3d_on(op_oef2_a_get(res, 6, idx), a, b);
}

int func_01B03840(void *res, int idx, int a, int b)
{
    return op_oef2_se_3d_move(op_oef2_a_get(res, 6, idx), a, b) == 0;
}

void func_01B03890(P8Group *g, int a, int b)
{
    func_01B04750(&g->list);
    g->w20 = a;
    g->w24 = b;
    g->w28 = 0;
    g->w2C = 0;
    g->h30 = 0;
}
