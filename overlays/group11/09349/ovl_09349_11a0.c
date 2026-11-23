/* 09349 particle spawner callback (400 B). */

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
} OvlPart;

typedef struct {
    u8 pad00[0xD0];
    u8 pos[0x10];
} OvlObj;

extern u8 g_ovl_mgr[];

extern float func_002B3DB0(float);
extern void **fn_ovl_45a0(void *, int);
extern void fn_ovl_53d8(void *, void *);
extern OvlPart *fn_ovl_6078(void);

void ovl_09349_11a0(OvlObj *obj)
{
    u8 *pos = obj->pos;
    int i;

    for (i = 0; i < 4; i++) {
        OvlPart *part = fn_ovl_6078();
        if (part == 0) {
            break;
        }
        fn_ovl_53d8(part->s30, *fn_ovl_45a0(g_ovl_mgr, 3));
        MMI_COPY_LQ_A3(part, pos);
        MMI_COPY_SQ_A3(part);
        part->x += func_002B3DB0(4.0f);
        part->y += func_002B3DB0(4.0f);
        part->z += func_002B3DB0(4.0f);
        part->vx = func_002B3DB0(0.5f);
        part->vy = func_002B3DB0(0.5f);
        part->vz = func_002B3DB0(0.5f);
        part->f1C = func_002B3DB0(3.1415927410125732f);
        part->f20 = 0.0f;
        part->f24 = -0.05f;
        part->f28 = 0.0f;
        part->f2C = 1.0f;
        part->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.06f;
        part->f40 = 0.0f;
        part->w58 = 16;
        part->w5C = 0;
        part->w4C = 16;
        part->w50 = 0;
    }
}
