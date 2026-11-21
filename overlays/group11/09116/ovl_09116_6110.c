/* Shared 09116-family fade task tick (448 B, 91 containers). */

typedef unsigned char u8;
typedef struct {
    u8 pad00[0x14];
    void *w14;
} OvlTask;

typedef struct {
    float c0[4];
    float c1[4];
    u8 b20[4];
    u8 b24[4];
    int w28;
    int w2C;
    int w30;
    int w34;
} OvlFade;

extern void func_00173720(float *);
extern void func_00173740(int *);
extern void fn_ovl_free(OvlTask *);

void ovl_09116_6110(OvlTask *t)
{
    OvlFade *f = (OvlFade *)t->w14;
    float col[4];
    int bg[4];
    float ratio;
    float inv;

    if (f->w28 > 0) {
        f->w28--;
        return;
    }
    f->w2C--;
    ratio = (float)f->w2C / (float)f->w30;
    inv = 1.0f - ratio;
    col[0] = f->c1[0] * inv + f->c0[0] * ratio;
    col[1] = f->c1[1] * inv + f->c0[1] * ratio;
    col[2] = f->c1[2] * inv + f->c0[2] * ratio;
    col[3] = f->c1[3] * inv + f->c0[3] * ratio;
    func_00173720(col);
    if (f->w34 == 1) {
        bg[0] = (f->b20[0] * f->w2C + f->b24[0] * (f->w30 - f->w2C)) / f->w30;
        bg[1] = (f->b20[1] * f->w2C + f->b24[1] * (f->w30 - f->w2C)) / f->w30;
        bg[2] = (f->b20[2] * f->w2C + f->b24[2] * (f->w30 - f->w2C)) / f->w30;
        bg[3] = (f->b20[3] * f->w2C + f->b24[3] * (f->w30 - f->w2C)) / f->w30;
        func_00173740(bg);
    }
    if (f->w2C <= 0) {
        fn_ovl_free(t);
    }
}
