typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { void *a; } Msg1;
typedef struct { void *a; u8 b04; u8 b05; u8 pad[2]; } MsgStep;

extern int g_ovl_state_44;
extern void *g_ovl_ptr_48;
extern void *g_ovl_ptr_4c;
extern void *g_ovl_ptr_374;
extern u8 g_ovl_b_754;
extern u8 g_ovl_dat_740[];
extern u8 g_ovl_dat_530[];
extern u8 g_ovl_dat_758[];
extern u8 g_ovl_dat_778[];

extern void fn_ovl_3528(void);
extern void fn_ovl_cc08(void *);
extern void fn_ovl_96d8(void *);
extern void fn_ovl_43c0(void *);
extern void fn_sys_1cddd8(void *);

static __inline__ void call_cc08(void *a) { void *pad[4]; Msg1 m; m.a = a; fn_ovl_cc08(&m); }
static __inline__ void call_96d8(void *a, u8 b5) { MsgStep m; m.a = a; m.b05 = b5; fn_ovl_96d8(&m); }
static __inline__ void call_43c0(void *a, u8 b5) { MsgStep m; m.a = a; m.b05 = b5; fn_ovl_43c0(&m); }

int ovl_09386_3d08(void) {
    if (g_ovl_state_44 < 4) {
        return 0;
    }
    g_ovl_ptr_48 = g_ovl_ptr_4c;
    fn_ovl_3528();
    g_ovl_b_754 += 1;
    call_cc08(g_ovl_dat_740);
    call_96d8(g_ovl_dat_530, g_ovl_b_754);
    call_43c0(g_ovl_dat_758, g_ovl_b_754);
    call_43c0(g_ovl_dat_778, g_ovl_b_754);
    if ((*(int *)(g_ovl_dat_740 + 16) & 1) != 0 && *(u16 *)(g_ovl_dat_778 + 24) == 0) {
        fn_sys_1cddd8(g_ovl_ptr_374);
    }
    return 0;
}
