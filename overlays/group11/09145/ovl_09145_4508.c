/* Shared 09145-family color fade task update (212 B). */

typedef struct {
    float r0, g0, b0;
    float r1, g1, b1;
    int t0, d0, t1, d1, id, d2;
    unsigned short flags;
} OvlFade;
typedef struct { int pad[5]; OvlFade *arg; } OvlTask;

extern void fn_ovl_1fb0(int, float, float, float, int);
extern void fn_ovl_3470(void);

void ovl_09145_4508(OvlTask *t)
{
    OvlFade *f = t->arg;

    if (f->d0 > 0) {
        f->d0--;
    } else if (f->d0 == 0) {
        fn_ovl_1fb0(f->id, f->r0, f->g0, f->b0, f->t0);
        f->d0--;
    } else if (f->d1 > 0) {
        f->d1--;
    } else if (f->d1 == 0) {
        fn_ovl_1fb0(f->id, f->r1, f->g1, f->b1, f->t1);
        f->d2 = f->t1;
        f->d1--;
    } else if (f->d2 > 0) {
        f->d2--;
    } else {
        f->flags |= 0x8000;
        fn_ovl_3470();
    }
}
