#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int f10;
} TaskSub9111;

typedef struct {
    u8 pad00[0x8];
    TaskSub9111 *f8;
    u8 pad0c[0x8];
    int f14;
} OvlTask9111;

typedef struct {
    u8 pad00[0xC4];
    float fc4;
    u8 padc8[0x3C];
    void *f104;
    u8 pad108[0x8];
    void *f110;
} SubObj9111;

extern int g_57d4;
extern int g_57d8;
extern int g_57e0;
extern int g_67c;
extern u8 g_55c8[];
extern u8 g_55e8[];
extern u8 g_518[];
extern int g_420[];
extern int g_440[];
extern u8 g_57e8[];
extern SubObj9111 g_5830;
extern u8 g_5730[];
extern u8 g_res_data[];
extern u8 g_460[];
extern void *g_5bc4;

extern void ovl_2e68(int, void *, void *);
extern int ovl_0d20(void);
extern void ovl_3da0(void *, void *, int, int, int, int, float);
extern float ovl_1358(int);
extern void ovl_0d68(void);
extern void ovl_3528(void *, void *, void *);
extern void ovl_0da0(void);
extern void ovl_27e0(int, int);
extern int ovl_2f20(void *);
extern int ovl_3e80(void *, void *);
extern void ovl_0938(void);

void ovl_09111_0b20(OvlTask9111 *task)
{
    int a;
    int b;

    if (g_57d4 > 0) {
        if (--g_57d4 == 0) {
            int idx;
            ovl_2e68(-1, g_55c8, g_518);
            idx = g_420[ovl_0d20()];
            ovl_3da0(g_57e8, &g_5830, 0, idx, 0, 0, 0.02f);
            g_5830.fc4 = ovl_1358(-1);
            g_5830.f104 = (void *)ovl_0d68;
            ovl_3528(g_5730, g_res_data, g_460);
            g_5830.f110 = g_5730;
            g_57d8 = g_440[ovl_0d20()] + idx;
        }
    } else if (g_57d8 > 0) {
        if (--g_57d8 == 0) {
            if ((g_67c >> 8) & 1) {
                ovl_0da0();
            } else {
                ovl_27e0(-5, 0);
                g_57e0 = 1;
            }
        }
    }

    a = ovl_2f20(g_55c8);
    ovl_2f20(g_55e8);
    b = ovl_3e80(g_57e8, g_5bc4);
    if (b == 1 && g_57e0 == 1 && a == 1) {
        TaskSub9111 *sub = task->f8;
        task->f14 = 3;
        sub->f10 = (int)ovl_0938;
    }
}
