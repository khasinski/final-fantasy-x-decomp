/* 09215 main update (148 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x28];
    int w28;
} OvlState;

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

extern OvlState g_ovl_6108;
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_938c;

extern void fn_ovl_09e0(void);
extern int fn_ovl_30c8(void *);
extern int fn_ovl_4028(void *, void *);

void ovl_09215_0fa0(OvlTask *task)
{
    int r = fn_ovl_30c8(&g_ovl_6108);

    if (fn_ovl_4028(g_ovl_mgr, g_ovl_ptr_938c) == 1 && r == 1 && g_ovl_6108.w28 == 1) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_09e0;
    }
}
