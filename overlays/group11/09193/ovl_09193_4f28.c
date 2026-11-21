/* Shared 09193-family follower task update (272 B, ~35 containers). */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x10];
    u8 sub10[0x30];
    u16 flag40;
    u8 pad42[0x0E];
    int mode;
    int target;
    u16 flag58;
} OvlObj;

typedef struct {
    u8 pad00[0x14];
    OvlObj *obj;
} OvlTask;

extern void fn_ovl_1230(int, float *, int);
extern float fn_ovl_1108(int);
extern void fn_ovl_4988(float *, float *, OvlObj *);
extern void fn_ovl_34d0(void *, float *);
extern void fn_ovl_1878(float *);
extern int fn_ovl_3330(void *);
extern void fn_ovl_3870(OvlTask *);

void ovl_09193_4f28(OvlTask *t)
{
    OvlObj *obj = t->obj;
    float rot[4];
    float pos[4];

    switch (obj->mode) {
    case 0:
        break;
    case 1:
        fn_ovl_1230(obj->target, pos, 0);
        if (obj->flag40 & 1) {
            rot[0] = 0.0f;
            rot[1] = fn_ovl_1108(obj->target);
            rot[2] = 0.0f;
            fn_ovl_4988(rot, pos, obj);
        }
        fn_ovl_34d0(obj->sub10, pos);
        break;
    case 2:
        fn_ovl_1878(pos);
        fn_ovl_34d0(obj->sub10, pos);
        break;
    }
    if (fn_ovl_3330(obj->sub10) == 1 && (obj->flag40 & 0x4000)) {
        obj->flag58 |= 0x8000;
        fn_ovl_3870(t);
    }
}
