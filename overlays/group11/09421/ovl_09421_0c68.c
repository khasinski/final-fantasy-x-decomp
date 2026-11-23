/* 09421 main update (148 B). */

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

extern u8 g_ovl_5578[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_62d4;

extern void fn_ovl_0930(void);
extern int fn_ovl_2fb8(void *);
extern int fn_ovl_3f18(void *, void *);
extern int fn_ovl_5108(void);

void ovl_09421_0c68(OvlTask *task)
{
    int r = fn_ovl_2fb8(g_ovl_5578);

    if (fn_ovl_3f18(g_ovl_mgr, g_ovl_ptr_62d4) == 1 && fn_ovl_5108() == 0 && r == 1) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_0930;
    }
}
