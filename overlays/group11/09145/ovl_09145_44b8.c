/* Shared 09145-family color fade spawner (76 B). */

typedef struct {
    float r0, g0, b0;
    float r1, g1, b1;
    int t0, d0, t1, d1, id, d2;
    unsigned short flags;
} OvlFade;
typedef struct { int pad[5]; void *arg; } OvlTask;

extern OvlTask *fn_ovl_33f0(void *);
extern void fn_ovl_35b8(OvlTask *);
extern void fn_ovl_4508(void);

void ovl_09145_44b8(OvlFade *f)
{
    OvlTask *t;

    f->flags = 0;
    f->r1 = 1.0f;
    f->g1 = 1.0f;
    f->b1 = 1.0f;
    t = fn_ovl_33f0((void *)fn_ovl_4508);
    t->arg = f;
    fn_ovl_35b8(t);
}
