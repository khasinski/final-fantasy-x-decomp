#include "common.h"

typedef struct {
    u8 pad00[0x22];
    u8 b22;
    u8 pad23[0x0D];
} EntryEB80;

extern u8 g_sym_1d1c6d0[];
extern void *g_ptr_1b2fbd0;
extern void *g_ptr_004c;
extern u8 g_sym_0f40[];
extern u8 g_sym_0f58[];
extern u8 g_sym_0f70[];
extern u8 g_sym_0f90[];
extern u8 g_sym_0fb0[];
extern u8 g_sym_0fd0[];
extern int g_word_0960;
extern int g_word_1b2eb7c;
extern u8 g_sym_0050[];
extern u8 g_sym_1b2eb50[];
extern u8 g_sym_1c1c6d0[];
extern EntryEB80 g_arr_1b2eb80[87];
extern void *g_ptrs_09c0[];
extern u8 g_tbl_0b20[];
extern u8 g_sym_1b1b538[];
extern int g_word_0b84;
extern u8 g_sym_1b1ace8[];
extern u8 g_sym_1b1aca8[];
extern u8 g_sym_1b1f2d8[];
extern int g_word_1b2fbd8;

extern void g_fn_b3b0(void);
extern void func_002B2C50(int);
extern void g_fn_1da90(void *);
extern void g_fn_13180(void *);
extern void func_002B4980(int);
extern int func_002B49A0(int, int, int);
extern void func_002678E0(int, void *);
extern void func_00267A68(void *, int, void *, int);
extern void func_002D02E8(int, int, int, int);
extern void func_002944B0(int, int, int, int);
extern void func_00294468(int, int, int);
extern void func_001B57F0(int, int);
extern void func_001B5810(int, int);
extern void g_fn_f278(void *);
extern void g_fn_d1f8(void *);
extern int func_001B4E58(int);
extern void func_0010C790(int, int);
extern int func_002B2E30(void *, int, int, int);

int func_01B0F3D0(void)
{
    u8 pad00[0x10];
    void *m1[4];
    void *m2_0;
    void *m2_1;
    int i;
    (void)pad00;

    g_fn_b3b0();
    {
        u8 *p = g_sym_1d1c6d0;
        g_ptr_1b2fbd0 = p;
        g_ptr_004c = p + 0x5190;
    }
    func_002B2C50(1);

    m2_0 = g_sym_0f40;
    g_fn_1da90(&m2_0);
    m2_1 = g_sym_0f58;
    g_fn_1da90(&m2_1);

    m1[0] = g_sym_0f70;
    m1[1] = 0;
    g_fn_13180(m1);
    g_sym_0f70[0x1B] = 1;

    m1[0] = g_sym_0f90;
    m1[1] = 0;
    g_fn_13180(m1);
    g_sym_0f90[0x1B] = 1;

    m1[0] = g_sym_0fb0;
    m1[1] = 0;
    g_fn_13180(m1);

    m1[0] = g_sym_0fd0;
    m1[1] = 0;
    g_fn_13180(m1);

    func_002B4980(g_word_0960);
    g_word_1b2eb7c = func_002B49A0(g_word_0960, 8, 0);
    func_002678E0(g_word_1b2eb7c, g_sym_0050);
    func_00267A68(g_sym_1b2eb50, g_word_1b2eb7c, g_sym_1c1c6d0, 0x100000);

    for (i = 86; i >= 0; i--) {
        g_arr_1b2eb80[i].b22 = 0;
        g_ptrs_09c0[g_tbl_0b20[i]] = g_sym_1b1b538;
    }

    func_002D02E8(g_word_0960, 0, 9, 2);
    func_002944B0(g_word_0960, 0, 1000, 2);
    func_00294468(func_002B49A0(g_word_0960, 6, 5), 0, 2);
    func_001B57F0(g_word_0b84, 1);
    func_001B5810(g_word_0b84, 0);
    g_fn_f278(g_sym_1b1ace8);
    g_fn_d1f8(g_sym_1b1aca8);
    func_0010C790(func_001B4E58(g_word_0b84), 255);
    g_word_1b2fbd8 = func_002B2E30(g_sym_1b1f2d8, 0, 0, 0);
    return 0;
}
