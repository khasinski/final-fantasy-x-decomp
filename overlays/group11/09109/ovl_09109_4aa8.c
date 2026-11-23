#include "common.h"

typedef struct {
    u8 pad00[0x40];
    float f40;
    u8 pad44[0x4];
    int w48;
    u8 pad4c[0x8];
    int w54;
    int w58;
    u8 pad5c[0x4];
    int w60;
    u32 w64;
    u32 w68;
    int active;
    short h70;
    u8 pad72[0xE];
} PoolSlot;

extern PoolSlot *g_pool;
extern int g_pool_idx;
extern int g_pool_max;
extern int g_pool_cnt;

extern void *ovl_3860(void (*)(void));
extern void ovl_3a28(void *);
extern void ovl_73b8(void);

void *ovl_09732_7270(PoolSlot *buf, int count)
{
    int i;
    void *task;

    g_pool = buf;
    for (i = 0; i < count; i++, buf++) {
        buf->active = 0;
    }
    g_pool_idx = 0;
    g_pool_max = count;
    g_pool_cnt = 0;
    task = ovl_3860(ovl_73b8);
    ovl_3a28(task);
    return task;
}
