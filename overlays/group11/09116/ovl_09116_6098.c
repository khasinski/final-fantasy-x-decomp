/* Shared 09116-family fade color initializer & task starter (116 B, 91 containers). */

typedef unsigned char u8;
typedef struct {
    u8 pad00[0x14];
    void *w14;
    u8 b18;
} OvlTask;

typedef struct {
    float c0[4];
    float c1[4];
    u8 pad20[8];
    int w28;
    int w2C;
    int w30;
    int w34;
} OvlFade;

extern OvlTask *fn_ovl_alloc(void *);
extern void fn_ovl_add(OvlTask *);
extern void fn_ovl_cb(void *);

void ovl_09116_6098(OvlFade *f, float a, float b, int frames, int mode)
{
    OvlTask *t;
    f->w34 = 0;
    f->c0[2] = a;
    f->c0[1] = a;
    f->c0[0] = a;
    f->c0[3] = 1.0f;
    f->c1[2] = b;
    f->c1[1] = b;
    f->c1[0] = b;
    f->c1[3] = 1.0f;
    f->w28 = mode;
    f->w30 = frames;
    f->w2C = frames;
    t = fn_ovl_alloc((void *)fn_ovl_cb);
    t->w14 = f;
    t->b18 = 1;
    fn_ovl_add(t);
}
