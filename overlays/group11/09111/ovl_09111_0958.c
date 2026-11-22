#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *f2c;
} OvlMgr9111;

typedef struct {
    u8 pad00[0x14];
    int f14;
    u8 pad18[0x90];
    int fa8;
} Sub5610;

extern u8 g_heap_buf[];
extern void *g_5bc0;
extern void *g_5bc4;
extern OvlMgr9111 g_57e8;
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern int g_400[];
extern Sub5610 g_5610;
extern int g_57d4;
extern int g_55fc;
extern int g_57e0;
extern u8 g_55c8[];
extern u8 g_508[];

extern void *func_002B49A0(void *, int, int);
extern void ovl_3cc8(void *, void *, void *, int);
extern void ovl_1480(int, void *, int);
extern void ovl_4ad0(void *, void *, void *);
extern float ovl_17f0(int);
extern void ovl_4bd8(void *, void *, void *);
extern float ovl_4c78(void *, void *);
extern int ovl_0d20(void);
extern void ovl_5128(void *, int, void *, int, float, float, float);
extern void ovl_2e68(int, void *, void *);
extern void *ovl_3a40(void (*)(void));
extern void ovl_3c08(void *);
extern void ovl_0b20(void);

int ovl_09111_0958(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    u8 *heap = g_heap_buf;
    OvlMgr9111 *mgr = &g_57e8;
    int dist;
    int t;
    int d;

    g_5bc4 = heap + 0x40000;
    g_5bc0 = heap;
    mgr->f2c = func_002B49A0(g_res_data, 8, 0);
    ovl_3cc8(mgr, g_hdr_40, g_5bc0, 0x40000);

    ovl_1480(-1, v0, 0);
    ovl_1480(0, v1, 0);
    ovl_4ad0(v2, v0, v1);
    v2[0] = 0.0f;
    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = ovl_17f0(0) + 12.0f;
    ovl_4bd8(v2, v1, v3);

    dist = (int)(ovl_4c78(v0, v1) * 0.5f);
    {
        int idx = ovl_0d20();
        t = g_400[idx];
    }
    ovl_5128(&g_5610, -1, v1, dist, 0.2f, 1.1f, 1.0f);
    g_5610.f14 = 1;
    g_5610.fa8 = t;
    d = dist + t - 7;
    g_57d4 = d;
    if (d <= 0) {
        g_57d4 = 1;
    }
    g_55fc = 1;
    g_57e0 = 0;
    ovl_2e68(-1, g_55c8, g_508);
    ovl_3c08(ovl_3a40(ovl_0b20));
    return 0;
}
