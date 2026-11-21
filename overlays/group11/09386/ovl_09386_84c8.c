typedef unsigned char u8;
typedef struct {
    u8 pad00[0x20];
    u8 b20[0x10];
    u8 b30[0x10];
    void *p40;
    void *p44;
} Ovl9386Obj84c8;
typedef struct {
    Ovl9386Obj84c8 *obj;
    u8 b04;
} Ovl9386Msg84c8;
extern void fn_ovl_8780(Ovl9386Msg84c8 *msg);
extern void fn_sys_107428(void *, void *, int, void *);
extern void fn_sys_2dd020(void *, void *, void *);

void ovl_09386_84c8(Ovl9386Msg84c8 *msg) {
    Ovl9386Obj84c8 *obj;
    fn_ovl_8780(msg);
    if ((u8)(msg->b04 & 1) == 0) {
        return;
    }
    obj = msg->obj;
    fn_sys_107428(obj->p40, obj->p44, 0, obj->b20);
    fn_sys_2dd020(obj->b20, obj->b20, obj->b30);
}
