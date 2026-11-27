#include "common.h"

typedef struct S38Sub {
    u8 pad00[0x1E];
    u8 b1E;
    u8 pad1F[0x21];
    float f40;
    float f44;
} S38Sub;

typedef struct S38Th {
    float m00[4][4];
    float m40[4][4];
    u8 pad80[0x19A];
    s16 op;
    u8 pad21C[4];
    S38Sub *sub;
    u8 pad224[0xDC];
    u8 obj300[0x60];
    void *res360[18];
} S38Th;

extern S38Sub *opus_no_get(void *obj300, S38Sub *sub, int id);
extern void func_002D07A0(void *res, int id, void *buf);
extern void op_unit_m_scale(void *dst, float scale);
extern void *opus_local_get(S38Th *th, S38Sub *sub);
extern void func_002DD610(void *m40, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);
extern void func_01B03A08(void *obj, S38Sub *sub, S38Sub *other, void *buf, s16 *pc, S38Th *th, void *local, void *m40);

s16 *func_01B038B0(S38Th *th, s16 *pc)
{
    u8 buf[0x20];
    S38Sub *sub = th->sub;
    void *res = th->res360[sub->b1E];
    S38Sub *other;
    void *local;
    void *obj;

    if ((th->op & 0xF000) == 0x1000) {
        obj = th->obj300;
        other = opus_no_get(obj, sub, pc[1]);
        func_002D07A0(res, pc[2], buf);
        op_unit_m_scale(th, 0.0625f);
        local = opus_local_get(th, sub);
        func_002DD610(th->m40, 512.0f, 0.8f, 0.87285f, sub->f40 + 2048.0f, sub->f44 + 2048.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
        func_01B03A08(obj, sub, other, buf, pc + 3, th, local, th->m40);
        pc += 8;
    }
    return pc;
}
