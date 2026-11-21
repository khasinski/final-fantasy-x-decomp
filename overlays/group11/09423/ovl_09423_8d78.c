typedef unsigned char u8;
typedef struct {
    void *vtbl;
    u8 pad04[0x2c];
    float f30, f34, f38, f3c;
    void *p40;
} Ovl9423Obj;
typedef struct {
    Ovl9423Obj *obj;
    void *p04;
    void *p08;
} Ovl9423Msg;
extern u8 g_ovl_vtbl_18a0[];
extern void fn_ovl_8fe8(Ovl9423Msg *msg);
void ovl_09423_8d78(Ovl9423Msg *msg) {
    msg->obj->vtbl = g_ovl_vtbl_18a0;
    fn_ovl_8fe8(msg);
    msg->obj->p40 = msg->p08;
    msg->obj->f30 = 1.0f;
    msg->obj->f34 = 1.0f;
    msg->obj->f38 = 1.0f;
    msg->obj->f3c = 1.0f;
}
