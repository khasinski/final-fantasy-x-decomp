/* Shared 09176/09178/09177/09179 update + rank helper (116 B + 92 B). */

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

extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_641c;
extern int g_ovl_63bc;
extern int g_ovl_6328;
extern int g_ovl_06fc;

extern void fn_ovl_0928(void);
extern int fn_ovl_41a0(void *, void *);
extern int fn_ovl_5eb0(void);

void ovl_09176_0b58(OvlTask *task)
{
    if (fn_ovl_41a0(g_ovl_mgr, g_ovl_ptr_641c) == 1 && g_ovl_63bc <= 0 && fn_ovl_5eb0() == 0) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_0928;
    }
}

int ovl_09176_0bd0(void)
{
    int dmg = g_ovl_6328;
    int maxhp = g_ovl_06fc;
    int ratio;

    if (dmg > 0 || maxhp <= 0) {
        return 0;
    }
    ratio = -dmg / maxhp;
    if (ratio < 100) {
        return 0;
    }
    if (ratio < 500) {
        return 1;
    }
    return 2;
}
