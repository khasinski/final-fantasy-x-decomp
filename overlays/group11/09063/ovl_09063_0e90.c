typedef unsigned char u8;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x2CC];
    int idx;
    u8 pad39C[0x134];
    float f4D0;
    float f4D4;
    float f4D8;
    u8 pad4DC[0x14];
} OvlObj;

extern OvlObj *g_ptr_6008;

void ovl_09063_0e90(OvlObj *obj)
{
    OvlObj *p;
    float a;

    p = &g_ptr_6008[obj->idx];
    a = obj->fC0 + p->f4D0;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    obj->fC0 = a;

    a = obj->fC4 + p->f4D4;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    obj->fC4 = a;

    a = obj->fC8 + p->f4D8;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    obj->fC8 = a;
}
