#include "common.h"

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    u8 pad2C[0x0C];
    float f38;
    float f3C;
    float f40;
    u16 h44;
    u16 h46;
    u16 h48;
} Node8458;

typedef struct {
    Node8458 *node; /* 0x00 */
    u8 *parent;     /* 0x04 */
    void *p08;      /* 0x08 */
    float f0C;      /* 0x0C */
    float f10;      /* 0x10 */
    void *p14;      /* 0x14 */
    float f18;      /* 0x18 */
    float *p1C;     /* 0x1C */
} Msg8458;

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
} St8458;

extern void func_01B08AA0(Msg8458 *);
extern void func_01B08A60(float *, void *, u8 *);
extern float func_01B08A00(float *);
extern float func_01B0EB20(float *);
extern int func_01B07FD8(void *, float, float, float, float *);

void func_01B08458(register Msg8458 *s0)
{
    Node8458 *n = s0->node;
    u8 *p = s0->parent;
    u8 pad08[0x40];
    St8458 st;
    float v70[4];
    int pad80;
    int i;

    (void)pad08;
    (void)pad80;

    func_01B08AA0(s0);
    func_01B08A60(v70, s0->p08, p + 0x20);
    st.f0C = func_01B08A00(v70);
    st.f14 = -func_01B0EB20(v70);
    st.f00 = 5.0f;

    for (i = 0; i < 32; i++) {
        if (func_01B07FD8(s0->p14, v70[1], s0->f10, st.f00, &st.f08) != 0) {
            if (st.f08 > s0->f18) {
                break;
            }
        }
        st.f00 -= 0.5f;
    }

    if (i == 32) {
        st.f08 = 1.0f;
    }

    *s0->p1C = st.f00;
    n->f20 = v70[0] / st.f08;
    n->f28 = v70[2] / st.f08;
    n->f24 = st.f00;
    n->f40 = st.f08;
    n->f38 = s0->f10;
    n->h44 = 0;
    n->h46 = 0;
    n->h48 = 0;
    n->f3C = s0->f0C;
}
