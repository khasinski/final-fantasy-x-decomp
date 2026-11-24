#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
    u8 pad30[0x10];
} Mgr9288;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x50];
} Sub130;

extern u8 D_01B00040[];
extern u8 D_01B00428[];
extern void func_01B00E18(void);
extern Mgr9288 D_01B04688[];
extern Sub130 D_01B04710[];
extern u8 *D_01B04970[2];
extern void *D_01B04978[2];
extern u8 D_01B09CA0[];
extern u8 D_01B93CC0[];
extern u8 D_01C13CC0[];
extern u8 D_01C93CC0[];
extern u8 D_01D13CC0[];

extern s32 op_oef2_a_get(void *, s32, s32);
extern void func_01B03AB8(void *, void *, void *, s32);
extern void func_01B03B90(void *, void *, s32, s32, s32, void *, float);
extern void *func_01B03830(void (*)(void));
extern void func_01B039F8(void *);

s32 func_01B00C60(void)
{
    Mgr9288 *mgr = D_01B04688;
    Sub130 *sub;

    D_01B04970[0] = D_01B93CC0;
    D_01B04978[0] = D_01C13CC0;
    D_01B04970[1] = D_01C93CC0;
    D_01B04978[1] = D_01D13CC0;

    mgr->w2C = op_oef2_a_get(D_01B09CA0, 8, 0);
    func_01B03AB8(mgr, D_01B00040, D_01B04970[0], 0x80000);
    sub = D_01B04710;
    func_01B03B90(mgr, sub, 0, 0, 0, 0, 0.01f);
    sub->pos[0] = -90.0f;
    sub->pos[1] = -159.3f;
    sub->pos[2] = 566.0f;

    mgr++;
    mgr->w2C = op_oef2_a_get(D_01B09CA0, 8, 1);
    sub++;
    func_01B03AB8(mgr, D_01B00428, D_01B04970[1], 0x80000);
    func_01B03B90(mgr, sub, 0, 0x8C, 0, 0, 0.09f);
    sub->pos[2] = 566.0f;
    sub->pos[0] = -90.0f;
    sub->pos[1] = -159.3f;
    sub->fC4 = -1.5707963705062866f;

    func_01B039F8(func_01B03830(func_01B00E18));
    return 0;
}
