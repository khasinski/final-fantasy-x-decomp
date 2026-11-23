/* 09349 main update + tail-call helper (232 B + 20 B). */

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

typedef struct {
    u8 pad00[0xD0];
    u8 sD0[0x10];
} OvlObj;

extern u8 g_ovl_res[];
extern u8 g_ovl_6588[];
extern unsigned short g_ovl_694c;
extern int g_ovl_69d4;
extern int g_ovl_69d8;
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_7014;

extern void fn_ovl_0b30(void);
extern void fn_ovl_1b90(int, int, int, void *);
extern int fn_ovl_3190(void *);
extern void fn_ovl_39a0(void *, int, int);
extern int fn_ovl_40f0(void *, void *);

void ovl_09349_10a0(OvlTask *task)
{
    int r;

    if (g_ovl_69d4 > 0) {
        g_ovl_69d4--;
        if (g_ovl_69d4 == 0) {
            fn_ovl_39a0(g_ovl_res, 0, 0);
        }
    }
    if (g_ovl_69d8 > 0) {
        g_ovl_69d8--;
        if (g_ovl_69d8 == 0) {
            fn_ovl_39a0(g_ovl_res, 0, 1);
        }
    }
    r = fn_ovl_3190(g_ovl_6588);
    if (fn_ovl_40f0(g_ovl_mgr, g_ovl_ptr_7014) == 1 && (g_ovl_694c & 0x8000) && r == 1) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_0b30;
    }
}

void ovl_09349_1188(OvlObj *obj)
{
    fn_ovl_1b90(-1, 92, 0, obj->sD0);
}
