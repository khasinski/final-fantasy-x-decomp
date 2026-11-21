typedef unsigned char u8;
typedef unsigned short u16;

extern int g_ovl_state;
extern int g_ovl_arg0;
extern int g_ovl_arg1;
extern void *g_ovl_handle;
extern void *g_ovl_table;
extern void *g_sys_table_ptr;
extern u8 g_ovl_obj_720[];
extern u8 g_ovl_obj_930[];
extern u8 g_ovl_cnt_944;
extern u8 g_ovl_obj_948[];
extern u8 g_ovl_obj_968[];

extern void fn_ovl_2848(void);
extern void fn_ovl_be20(void *msg);
extern void fn_ovl_88f0(void *msg);
extern void fn_ovl_3b88(void *msg);
extern void fn_sys_1cddd8(void *handle);

typedef struct {
    void *obj;
    u8 pad4;
    u8 cnt;
    u8 pad6[2];
} P6Msg8;

int ovl_09539_p6_3278(void) {
    if (g_ovl_state < 4) {
        return 0;
    }
    {
        P6Msg8 m0;
        void *m1[4];
        g_sys_table_ptr = &g_ovl_table;
        g_ovl_arg0 = g_ovl_arg1;
        fn_ovl_2848();

        g_ovl_cnt_944 = (u8)(g_ovl_cnt_944 + 1);
        m1[0] = g_ovl_obj_930;
        fn_ovl_be20(m1);

        m0.obj = g_ovl_obj_720;
        m0.cnt = g_ovl_cnt_944;
        fn_ovl_88f0(&m0);

        m0.obj = g_ovl_obj_948;
        m0.cnt = g_ovl_cnt_944;
        fn_ovl_3b88(&m0);

        m0.obj = g_ovl_obj_968;
        m0.cnt = g_ovl_cnt_944;
        fn_ovl_3b88(&m0);

        if ((*(int *)(g_ovl_obj_930 + 16) & 1) != 0) {
            if (*(u16 *)(g_ovl_obj_968 + 24) == 0) {
                fn_sys_1cddd8(g_ovl_handle);
            }
        }
        return 0;
    }
}
