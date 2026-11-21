typedef struct OvlBlur OvlBlur;

struct OvlBlur {
    void (*cb)(OvlBlur *);
    int v0;
    int v1;
    int delay;
    int cur;
    int total;
    unsigned short flags;
};

typedef struct {
    unsigned char pad0[0x14];
    OvlBlur *data;
    unsigned char b18;
} OvlTask;

extern void func_00117E58(int);
extern void fn_ovl_37a0(OvlTask *);

void ovl_09343_4e50(OvlTask *t) {
    OvlBlur *b = t->data;

    if (b->delay > 0) {
        b->delay--;
        return;
    }
    func_00117E58((b->v0 * b->cur + b->v1 * (b->total - b->cur)) / b->total);
    if (b->cur == 0) {
        if (b->cb != 0) {
            b->cb(b);
        }
        if ((b->flags & 1) == 0) {
            b->flags |= 0x8000;
            fn_ovl_37a0(t);
        }
    } else {
        b->cur--;
    }
}
