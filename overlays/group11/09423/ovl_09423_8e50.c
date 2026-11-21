typedef unsigned char u8;
typedef void (*VtblFn)(void *);
typedef struct { void *pad[7]; VtblFn fn7; } Ovl9423Vtbl;
typedef struct {
    Ovl9423Vtbl *vtbl;
    u8 pad04[0x1c];
    u8 b20[0x10];
    u8 b30[0x10];
    void *p40;
} Ovl9423Node;
typedef struct {
    Ovl9423Node *obj;
    u8 b04;
    u8 b05;
} Ovl9423Msg;
typedef struct {
    Ovl9423Node *obj;
    u8 b04;
    u8 b05;
    u8 pad06[2];
} Ovl9423Call;
extern void fn_ovl_9120(Ovl9423Msg *msg);
extern void fn_sys_2dd050(void *, void *, void *);
void ovl_09423_8e50(Ovl9423Msg *msg) {
    Ovl9423Node *obj;
    Ovl9423Call call;
    fn_ovl_9120(msg);
    if ((u8)(msg->b04 & 1) == 0) {
        return;
    }
    obj = msg->obj;
    call.b05 = msg->b05;
    call.obj = (Ovl9423Node *)obj->p40;
    call.obj->vtbl->fn7(&call);
    fn_sys_2dd050(obj->b20, ((Ovl9423Node *)obj->p40)->b20, obj->b30);
}
