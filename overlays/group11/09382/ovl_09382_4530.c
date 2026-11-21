typedef struct {
    unsigned char pad0[0x124];
    unsigned short flags;
    unsigned char pad126[0x0A];
    int used;
    unsigned char pad134[0x0C];
} OvlPoolItem;

extern OvlPoolItem *g_ovl_pool;
extern int g_ovl_pool_idx;
extern int g_ovl_pool_max;

void ovl_09382_4530(OvlPoolItem *pool, int count) {
    int i;

    g_ovl_pool = pool;
    for (i = 0; i < count; i++, pool++) {
        pool->used = 0;
    }
    g_ovl_pool_idx = 0;
    g_ovl_pool_max = count;
}
