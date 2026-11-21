/* Shared 09518-family RGBA color lerp task update (300 B, 68 containers). */

typedef unsigned char u8;
typedef struct {
    u8 r, g, b, a;
} OvlRgba;
typedef struct {
    u8 pad[0x80];
    OvlRgba c0;
    OvlRgba c1;
    int delay;
    int cur;
    int total;
    int hold;
    u8 b98;
    u8 b99;
} OvlObj;
typedef struct { int pad[5]; OvlObj *arg; } OvlTask;

extern void fn_ovl_3740(void);
extern void func_002B2F30(OvlObj *, unsigned int, int, int);

void ovl_09518_4548(OvlTask *t)
{
    OvlObj *obj = t->arg;
    u8 c[4];

    if (obj->delay > 0) {
        obj->delay--;
        return;
    }
    if (obj->cur == 0) {
        if (obj->hold == 0) {
            fn_ovl_3740();
            return;
        }
        obj->hold--;
    } else {
        obj->cur--;
    }
    c[0] = (obj->c0.r * obj->cur + obj->c1.r * (obj->total - obj->cur)) / obj->total;
    c[1] = (obj->c0.g * obj->cur + obj->c1.g * (obj->total - obj->cur)) / obj->total;
    c[2] = (obj->c0.b * obj->cur + obj->c1.b * (obj->total - obj->cur)) / obj->total;
    c[3] = (obj->c0.a * obj->cur + obj->c1.a * (obj->total - obj->cur)) / obj->total;
    /* DEBT(CAST): type-pun 4-byte RGBA array on stack as u32 arg for func_002B2F30. */
    func_002B2F30(obj, *(unsigned int *)c, obj->b98, obj->b99);
}
