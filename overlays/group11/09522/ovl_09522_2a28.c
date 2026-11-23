/* Shared 09522-family frame tick (256 B, 11 containers). */
#include "common.h"

extern int g_ovl_44;
extern int g_ovl_48;
extern int g_ovl_4c;
extern int g_ovl_75c;
extern u8 g_ovl_910[];
extern u8 g_ovl_b20[];
extern u8 g_ovl_b34;
extern u8 g_ovl_b38[];
extern u8 g_ovl_b58[];
extern u8 g_ovl_d1d0[];
extern void *D_006A3924;

extern void func_002B37A0(void);
extern void fn_ovl_1e98(void);
extern void fn_ovl_c288(void *);
extern void fn_ovl_8d58(void *);
extern void fn_ovl_3338(void *);
extern void MsEffectTerminate(int);

int ovl_09522_2a28(void)
{
    struct {
        void *p00;
        u8 pad04;
        u8 b05;
        u8 pad06[2];
    } a00;
    void *a10;

    if (g_ovl_44 < 4) {
        return 0;
    }
    func_002B37A0();
    D_006A3924 = g_ovl_d1d0;
    g_ovl_48 = g_ovl_4c;
    fn_ovl_1e98();

    g_ovl_b34++;
    a10 = g_ovl_b20;
    fn_ovl_c288(&a10);

    a00.p00 = g_ovl_910;
    a00.b05 = g_ovl_b34;
    fn_ovl_8d58(&a00);

    a00.p00 = g_ovl_b38;
    a00.b05 = g_ovl_b34;
    fn_ovl_3338(&a00);

    a00.p00 = g_ovl_b58;
    a00.b05 = g_ovl_b34;
    fn_ovl_3338(&a00);

    if ((*(u32 *)(g_ovl_b20 + 0x10) & 1) && *(u16 *)(g_ovl_b58 + 0x18) == 0) {
        MsEffectTerminate(g_ovl_75c);
    }
    return 0;
}
