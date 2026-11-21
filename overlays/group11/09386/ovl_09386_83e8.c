typedef unsigned char u8;
typedef struct {
    void *vtbl;
    u8 pad04[0x28];
    float f2c;
    int w30, w34, w38, w3c;
    void *p40;
    void *p44;
} Ovl9386Obj;
typedef struct {
    Ovl9386Obj *obj;
    void *p04;
    void *p08;
    void *p0c;
} Ovl9386Msg83e8;
extern void fn_ovl_8648(Ovl9386Msg83e8 *msg);
extern u8 g_ovl_vtbl_3060[];

void ovl_09386_83e8(Ovl9386Msg83e8 *msg) {
    fn_ovl_8648(msg);
    msg->obj->f2c = 1.0f;
    msg->obj->p40 = msg->p08;
    msg->obj->p44 = msg->p0c;
    msg->obj->w30 = 0;
    msg->obj->w34 = 0;
    msg->obj->w38 = 0;
    msg->obj->w3c = 0;
    msg->obj->vtbl = g_ovl_vtbl_3060;
}
