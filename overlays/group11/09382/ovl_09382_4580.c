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

OvlPoolItem *ovl_09382_4580(void) {
    int i;
    int idx = g_ovl_pool_idx;

    for (i = 0; i < g_ovl_pool_max; i++) {
        OvlPoolItem *it = &g_ovl_pool[idx];

        idx++;
        if (idx >= g_ovl_pool_max) {
            idx = 0;
        }
        if (it->used == 0) {
            it->used = 1;
            g_ovl_pool_idx = idx;
            return it;
        }
        if ((it->flags & 0x8000) == 0) {
            g_ovl_pool_idx = idx;
            return it;
        }
    }
    return 0;
}
