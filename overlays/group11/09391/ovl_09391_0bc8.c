/* Shared 09391/09535 main update (152 B). */

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

extern u8 g_ovl_6438[];
extern int g_ovl_64cc;
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_652c;

extern void fn_ovl_0940(void);
extern int fn_ovl_3350(void *);
extern int fn_ovl_42b0(void *, void *);
extern int fn_ovl_5fc0(void);

void ovl_09391_0bc8(OvlTask *task)
{
    int r = fn_ovl_3350(g_ovl_6438);

    if (fn_ovl_42b0(g_ovl_mgr, g_ovl_ptr_652c) == 1 && r == 1 && g_ovl_64cc <= 0 && fn_ovl_5fc0() == 0) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_0940;
    }
}
