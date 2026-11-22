#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *f2c;
} OvlMgr9099;

typedef struct {
    u8 pad00[0x14];
    int f14;
    u8 pad18[0x90];
    int fa8;
} Sub5740;

extern u8 g_heap_buf[];
extern void *g_5cf0;
extern void *g_5cf4;
extern OvlMgr9099 g_5918;
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern int g_400[];
extern Sub5740 g_5740;
extern int g_5904;
extern int g_572c;
extern int g_5914;
extern u8 g_56f8[];
extern u8 g_568[];

extern void *func_002B49A0(void *, int, int);
extern void ovl_3df8(void *, void *, void *, int);
extern void ovl_15b0(int, void *, int);
extern void ovl_4c00(void *, void *, void *);
extern float ovl_1920(int);
extern void ovl_4d08(void *, void *, void *);
extern float ovl_4da8(void *, void *);
extern int ovl_0d88(void);
extern void ovl_5258(void *, int, void *, int, float, float, float);
extern void ovl_2f98(int, void *, void *);
extern void *ovl_3b70(void (*)(void));
extern void ovl_3d38(void *);
extern void ovl_0b88(void);

int ovl_09099_09b8(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    u8 *heap = g_heap_buf;
    OvlMgr9099 *mgr = &g_5918;
    int dist;
    int t;
    int d;

    g_5cf4 = heap + 0x40000;
    g_5cf0 = heap;
    mgr->f2c = func_002B49A0(g_res_data, 8, 0);
    ovl_3df8(mgr, g_hdr_40, g_5cf0, 0x40000);

    ovl_15b0(-1, v0, 0);
    ovl_15b0(0, v1, 0);
    v1[1] = v0[1];
    ovl_4c00(v2, v0, v1);
    v2[0] = 0.0f;
    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = ovl_1920(0) + 12.0f;
    ovl_4d08(v2, v1, v3);

    dist = (int)(ovl_4da8(v0, v1) * 0.5f);
    {
        int idx = ovl_0d88();
        t = g_400[idx];
    }
    ovl_5258(&g_5740, -1, v1, dist, 0.2f, 1.1f, 1.0f);
    g_5740.f14 = 1;
    g_5740.fa8 = t;
    d = dist + t - 7;
    g_5904 = d;
    if (d <= 0) {
        g_5904 = 1;
    }
    g_572c = 1;
    g_5914 = 0;
    ovl_2f98(-1, g_56f8, g_568);
    ovl_3d38(ovl_3b70(ovl_0b88));
    return 0;
}
