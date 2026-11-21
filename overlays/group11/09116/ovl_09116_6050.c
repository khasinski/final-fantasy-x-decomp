/* Shared 09116-family fade task starter (68 B, 91 containers). */

typedef unsigned char u8;
typedef struct {
    u8 pad00[0x14];
    void *w14;
    u8 b18;
} OvlTask;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
    int w30;
} OvlFade;

extern OvlTask *fn_ovl_alloc(void *);
extern void fn_ovl_add(OvlTask *);
extern void fn_ovl_cb(void *);

void ovl_09116_6050(OvlFade *f, int frames)
{
    OvlTask *t;
    f->w30 = frames;
    f->w2C = frames;
    t = fn_ovl_alloc((void *)fn_ovl_cb);
    t->w14 = f;
    t->b18 = 1;
    fn_ovl_add(t);
}
