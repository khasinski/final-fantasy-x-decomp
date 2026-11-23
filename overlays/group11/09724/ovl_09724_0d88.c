/* 09724 main update (236 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x10];
    int w10;
} OvlSubTask;

typedef struct {
    u8 pad00[0x08];
    OvlSubTask *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

extern int g_ovl_52fc;
extern void *g_ovl_ptr_5310;
extern float g_ovl_ang;
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_7964;

extern void fn_ovl_09d0(void);
extern int fn_ovl_3d50(void *, void *);
extern void fn_ovl_4758(void *);

static inline void add_angle(float *p, float d)
{
    float ang = *p + d;
    if (ang > 3.1415927410125732f) {
        ang -= 6.2831854820251465f;
    } else if (ang < -3.1415927410125732f) {
        ang += 6.2831854820251465f;
    }
    *p = ang;
}

void ovl_09724_0d88(OvlTask *task)
{
    add_angle(&g_ovl_ang, 0.15707963705062866f);
    fn_ovl_4758(g_ovl_ptr_5310);
    if (fn_ovl_3d50(g_ovl_mgr, g_ovl_ptr_7964) == 1 && g_ovl_52fc <= 0) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_09d0;
    }
}
