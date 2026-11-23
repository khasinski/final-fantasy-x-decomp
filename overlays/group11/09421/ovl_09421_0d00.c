/* 09421 particle spawner callback (512 B). */

#include "vu0.h"

typedef struct {
    float x;
    float y;
    float z;
    float w;
    float vx;
    float vy;
    float vz;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 s30[0x0C];
    float f3C;
    float f40;
    u8 pad44[0x08];
    int w4C;
    int w50;
    int pad54;
    int w58;
    int w5C;
    int w60;
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} OvlPart;

typedef struct {
    u8 pad00[0xD0];
    u8 pos[0x10];
    u8 padE0[0x24];
    int w104;
    u8 pad108[0x10];
    int w118;
} OvlObj;

extern u8 g_ovl_mgr[];

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern int func_002EFD78(void);
extern void **fn_ovl_43c8(void *, int);
extern void fn_ovl_4960(void *, void *);
extern OvlPart *fn_ovl_5068(void);

void ovl_09421_0d00(OvlObj *obj)
{
    u8 *pos;
    int i;

    if (obj->w118 >= 26) {
        obj->w104 = 0;
    }
    pos = obj->pos;
    for (i = 0; i < 4; i++) {
        OvlPart *part = fn_ovl_5068();
        int r;
        if (part == 0) {
            break;
        }
        fn_ovl_4960(part->s30, *fn_ovl_43c8(g_ovl_mgr, 0));
        MMI_COPY_LQ_A3(part, pos);
        MMI_COPY_SQ_A3(part);
        part->x += func_002B3DB0(4.0f);
        part->y += func_002B3DB0(2.0f) + 4.0f;
        part->z += func_002B3DB0(4.0f);
        part->vx = func_002B3DB0(0.6f);
        part->vy = func_002B3DF8(0.2f);
        part->vz = func_002B3DB0(0.6f);
        part->f1C = func_002B3DB0(3.1415927410125732f);
        part->f20 = 0.0f;
        part->f24 = -0.03f;
        part->f28 = 0.0f;
        part->f2C = 1.0f;
        part->f3C = 0.07f;
        part->f40 = 10.0f;
        part->w5C = 0;
        part->w4C = 80;
        part->w50 = 80;
        part->w58 = 32;
        part->b64 = 176;
        part->b65 = 176;
        r = func_002EFD78() % 16 + 56;
        part->b66 = r;
        part->b67 = 96;
        part->b68 = part->b64;
        part->b69 = part->b65;
        part->b6A = r;
        part->b6B = 0;
        part->w60 = 0;
    }
}
