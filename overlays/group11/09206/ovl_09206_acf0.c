#include "common.h"

typedef struct CamSlot {
    u8 pad00[0x48];
    float f48;          /* 0x48 */
    u32 pad4C;
    float v50[3];       /* 0x50 */
    u32 pad5C;
    float v60[3];       /* 0x60 */
    u8 pad6C[0xD0];
    float f13C;         /* 0x13C */
} CamSlot;

void func_01B09BA0(u32 id);
CamSlot *func_01B09BE8(u32 id);
void func_01B09D00(CamSlot *slot, u32 a, u32 b, u32 c, u32 d);

u8 *func_01B0ACF0(void *vm, u8 *pc)
{
    func_01B09BA0(*(u16 *)(pc + 2));
    return pc + 4;
}

u8 *func_01B0AD20(void *vm, u8 *pc)
{
    CamSlot *s = func_01B09BE8(*(u16 *)(pc + 2));
    s->f13C = **(float **)(pc + 4);
    return pc + 8;
}

u8 *func_01B0AD58(void *vm, u8 *pc)
{
    CamSlot *s = func_01B09BE8(*(u16 *)(pc + 2));
    float *v = *(float **)(pc + 4);
    float x = v[0];
    float y = v[1];
    float z = v[2];
    s->v50[0] = x;
    s->v50[1] = y;
    s->v50[2] = z;
    return pc + 8;
}

u8 *func_01B0ADA8(void *vm, u8 *pc)
{
    CamSlot *s = func_01B09BE8(*(u16 *)(pc + 2));
    float *v = *(float **)(pc + 4);
    float x = v[0];
    float y = v[1];
    float z = v[2];
    s->v60[0] = x;
    s->v60[1] = y;
    s->v60[2] = z;
    return pc + 8;
}

u8 *func_01B0ADF8(void *vm, u8 *pc)
{
    CamSlot *s = func_01B09BE8(*(u16 *)(pc + 2));
    s->f48 = **(float **)(pc + 4);
    return pc + 8;
}

u8 *func_01B0AE30(void *vm, u8 *pc)
{
    CamSlot *s = func_01B09BE8(*(u16 *)(pc + 2));
    func_01B09D00(s, *(u32 *)(pc + 4), *(u32 *)(pc + 8), *(u32 *)(pc + 12), *(u32 *)(pc + 16));
    return pc + 20;
}
