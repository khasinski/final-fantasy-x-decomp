/* Shared 09518-family task spawner (64 B). */

typedef struct { char pad[0x8C]; int w8C; int w90; int w94; } OvlObj;
typedef struct { int pad[5]; void *arg; } OvlTask;

extern OvlTask *fn_ovl_36c0(void *);
extern void fn_ovl_3888(OvlTask *);
extern void fn_ovl_4548(void);

void ovl_09518_4508(OvlObj *obj, int val)
{
    OvlTask *t;

    obj->w94 = 0;
    obj->w90 = val;
    obj->w8C = val;
    t = fn_ovl_36c0((void *)fn_ovl_4548);
    t->arg = obj;
    fn_ovl_3888(t);
}
