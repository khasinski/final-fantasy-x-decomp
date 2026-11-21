/* Shared 09193-family follower task spawner (80 B, ~35 containers). */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x10];
    u8 sub10[0x40];
    int mode;
    int target;
    u16 flag58;
} OvlObj;

typedef struct {
    u8 pad00[0x14];
    OvlObj *obj;
} OvlTask;

extern void fn_ovl_32d8(void *, void *, void *);
extern OvlTask *fn_ovl_37f0(void *);
extern void fn_ovl_39b8(OvlTask *);
extern void fn_ovl_4f28(void);

void ovl_09193_4ed8(OvlObj *obj, void *a1, void *a2, int mode)
{
    OvlTask *t;

    fn_ovl_32d8(obj->sub10, a1, a2);
    obj->mode = mode;
    obj->flag58 = 0;
    t = fn_ovl_37f0((void *)fn_ovl_4f28);
    t->obj = obj;
    fn_ovl_39b8(t);
}
