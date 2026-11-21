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

extern OvlTask *fn_ovl_3720(void (*)(OvlTask *));
extern void fn_ovl_38e8(OvlTask *);
extern void fn_ovl_4e50(OvlTask *);

void ovl_09343_4e08(OvlBlur *b, int dur) {
    OvlTask *t;

    b->flags = 0;
    b->total = dur;
    b->cur = dur;
    t = fn_ovl_3720(fn_ovl_4e50);
    t->data = b;
    t->b18 = 1;
    fn_ovl_38e8(t);
}
