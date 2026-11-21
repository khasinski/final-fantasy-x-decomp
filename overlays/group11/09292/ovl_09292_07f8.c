typedef unsigned char u8;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    int wD0;
    u8 padD4[0x5C];
} Ovl9292Item;

extern u8 g_ovl_buf[];
extern u8 *g_ovl_ptr_5150;
extern u8 *g_ovl_ptr_5154;
extern u8 g_ovl_mgr[];
extern Ovl9292Item g_ovl_items[3];
extern Ovl9292Item g_ovl_item3;
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_a5f0[];
extern u8 g_ovl_dat_0388[];
extern u8 g_ovl_dat_4c28[];
extern u8 g_ovl_dat_03b0[];
extern u8 g_ovl_dat_09c8[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3650(void *, void *, void *, int);
extern void fn_ovl_3728(void *, void *, int, int, int, int, float);
extern void fn_ovl_0e08(int, void *, int);
extern float fn_ovl_0ce0(int);
extern void fn_ovl_4ab0(void *, void *, void *, int);
extern void fn_ovl_27f0(int, void *, void *);
extern void *fn_ovl_33c8(void *);
extern void fn_ovl_3590(void *);

int ovl_09292_07f8(void) {
    u8 *base = g_ovl_buf;
    int delay;
    int i;
    int *p2;
    u8 *mgr = g_ovl_mgr;

    g_ovl_ptr_5154 = base + 0x40000;
    g_ovl_ptr_5150 = base;
    /* DEBT(CAST): raw byte offset store into opaque overlay manager struct */
    *(void **)(mgr + 0x2C) = func_002B49A0(g_ovl_dat_a5f0, 8, 0);
    fn_ovl_3650(mgr, g_ovl_dat_0040, g_ovl_ptr_5150, 0x40000);

    delay = 10;
    {
        Ovl9292Item *it0 = g_ovl_items;
        /* DEBT(CAST): step GIV at +0xD0 and write fC4 at -12(pd0) to match original loop GIV */
        u8 *pd0 = (u8 *)it0 + 0xD0;
        for (i = 0; i < 3; i++) {
            fn_ovl_3728(mgr, &it0[i], 0, delay, 0, 0, 0.4f);
            fn_ovl_0e08(-1, pd0, 0);
            *(float *)(pd0 - 12) = fn_ovl_0ce0(-1);
            if (i == 0) {
                delay += 30;
            } else {
                delay += 15;
            }
            pd0 += sizeof(Ovl9292Item);
        }
    }

    fn_ovl_3728(mgr, &g_ovl_item3, 1, 95, 0, 0, 0.5f);
    fn_ovl_0e08(-1, &g_ovl_item3.wD0, 0);
    g_ovl_item3.fC4 = fn_ovl_0ce0(-1);

    p2 = (int *)(base + 0x140000);
    fn_ovl_4ab0(p2, g_ovl_dat_a5f0, g_ovl_dat_0388, 1);
    p2[21] = -1;

    fn_ovl_27f0(-1, g_ovl_dat_4c28, g_ovl_dat_03b0);
    fn_ovl_3590(fn_ovl_33c8(g_ovl_dat_09c8));
    return 0;
}
