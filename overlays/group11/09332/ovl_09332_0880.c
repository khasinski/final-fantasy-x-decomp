/* 09332 effect initializer (280 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x20]; } OvlSnd;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0400[];
extern u8 g_ovl_dat_0430[];
extern u8 g_ovl_dat_0440[];
extern OvlSnd g_ovl_snd[];
extern u8 g_ovl_dat_4420[];
extern int g_ovl_w4460;
extern int g_ovl_w4464;
extern int g_ovl_w4468;
extern int g_ovl_w446c;
extern int g_ovl_w4470;
extern OvlMgr g_ovl_mgr;
extern void *g_ovl_ptr_4720;
extern void *g_ovl_ptr_4724;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3808(void *, void *, void *, int);
extern void fn_ovl_3068(void *, void *, void *);
extern void fn_ovl_29a8(int, void *, void *);
extern void *fn_ovl_3580(void *);
extern void fn_ovl_3748(void *);
extern void fn_ovl_0998(void);

int ovl_09332_0880(void)
{
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlSnd *snd;

    g_ovl_ptr_4720 = p;
    g_ovl_ptr_4724 = p + 0x40000;
    res = g_ovl_res;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3808(mgr, g_ovl_dat_0040, g_ovl_ptr_4720, 0x40000);
    g_ovl_w4460 = 410;
    g_ovl_w4464 = 440;
    g_ovl_w4468 = 440;
    g_ovl_w446c = 0;
    g_ovl_w4470 = 0;
    fn_ovl_3068(g_ovl_dat_4420, res, g_ovl_dat_0400);
    snd = g_ovl_snd;
    fn_ovl_29a8(0, &snd[0], g_ovl_dat_0430);
    fn_ovl_29a8(-1, &snd[1], g_ovl_dat_0440);
    fn_ovl_3748(fn_ovl_3580((void *)fn_ovl_0998));
    return 0;
}
