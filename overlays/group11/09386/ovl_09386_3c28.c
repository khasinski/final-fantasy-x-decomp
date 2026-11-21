extern int g_ovl_state_44;
extern void *g_ovl_ptr_374;
extern int fn_sys_29b830(int);
extern int fn_sys_2d0570(int);
extern int fn_sys_294578(int);
extern void fn_sys_1cdc58(void *, int);
extern int fn_sys_1cdaf8(void *);

int ovl_09386_3c28(void) {
retry:
    switch (g_ovl_state_44) {
    case 0:
        if (fn_sys_29b830(2) == 0) {
            g_ovl_state_44 += 1;
            goto retry;
        }
        return 0;
    case 1:
        if (fn_sys_2d0570(2) == 0) {
            g_ovl_state_44 += 1;
            goto retry;
        }
        return 0;
    case 2:
        if (fn_sys_294578(2) != 0) {
            return 0;
        }
        fn_sys_1cdc58(g_ovl_ptr_374, 1);
        g_ovl_state_44 += 1;
        goto retry;
    case 3:
        if (fn_sys_1cdaf8(g_ovl_ptr_374) > 0) {
            g_ovl_state_44 += 1;
        }
        break;
    }
    return 0;
}
