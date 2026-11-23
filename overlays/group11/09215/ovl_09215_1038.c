/* 09215 particle burst callback (560 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x10];
    float x;
    float y;
    float z;
    float w;
    float vx;
    float vy;
    float vz;
    float f2C;
    float f30;
    int pad34;
    int w38;
    int w3C;
    u8 pad40[0x0B];
    u8 b4B;
} OvlPart;

typedef struct {
    u8 pad00[0xD0];
    u8 pos[0x10];
    u8 padE0[0x290];
    float sx;
    float sy;
    float sz;
} OvlObj;

extern u8 g_ovl_mgr[];

extern float func_001ACED8(void);
extern float func_002B3DB0(float);
extern void func_002DD0B0(void *, void *);
extern void **fn_ovl_44d8(void *, int);
extern void fn_ovl_5310(void *, void *);
extern OvlPart *fn_ovl_5d30(void);

void ovl_09215_1038(OvlObj *obj)
{
    int i;

    for (i = 0; i < 6; i++) {
        OvlPart *part = fn_ovl_5d30();
        if (part == 0) {
            return;
        }
        fn_ovl_5310(part, *fn_ovl_44d8(g_ovl_mgr, 0));
        func_002DD0B0(&part->x, obj->pos);
        part->vx = (func_001ACED8() - 1.5f) * 0.6f;
        part->vy = (func_001ACED8() - 1.5f) * 0.6f;
        part->vz = (func_001ACED8() - 1.5f) * 0.6f;
        part->f2C = 0.0f;
        part->f30 = 0.008f;
        part->w38 = 16;
        part->w3C = 16;
        part->b4B = 0;
    }

    for (i = 0; i < 6; i++) {
        OvlPart *part = fn_ovl_5d30();
        if (part == 0) {
            return;
        }
        fn_ovl_5310(part, *fn_ovl_44d8(g_ovl_mgr, 1));
        func_002DD0B0(&part->x, obj->pos);
        part->x += obj->sx * (func_001ACED8() - 1.5f);
        part->y += obj->sy * (func_001ACED8() - 1.5f);
        part->z += obj->sz * (func_001ACED8() - 1.5f);
        part->vx = (func_001ACED8() - 1.5f) * 0.6f;
        part->vy = (func_001ACED8() - 1.5f) * 0.6f;
        part->vz = (func_001ACED8() - 1.5f) * 0.6f;
        part->f2C = func_002B3DB0(3.1415927410125732f);
        part->f30 = 0.15f;
        part->w38 = 16;
        part->w3C = 16;
        part->b4B = 0;
    }
}
