/* Shared pool count getter (12 B, 09109 @ 0x01B04BE0, 74 open containers). */

extern int g_pool_cnt;

int ovl_09109_4be0(void)
{
    return g_pool_cnt;
}
