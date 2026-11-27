#include "common.h"

typedef struct {
    u8 pad00[0x22];
    u8 b22;
    u8 pad23[0x0D];
} SlotEB50;

extern u8 g_sym_1d04720[];
extern void *g_ptr_004c;
extern void *g_ptr_1b1e640;
extern u8 g_sym_0f40[];
extern u8 g_sym_0f58[];
extern u8 g_sym_0f70[];
extern u8 g_sym_0f90[];
extern u8 g_sym_0fb0[];
extern u8 g_sym_0fd0[];
extern int g_word_0960;
extern u8 g_sym_0050[];
extern int g_word_1b1d5ec;
extern u8 g_sym_1b1d5c0[];
extern u8 g_sym_1c04720[];
extern void *g_ptrs_09c0[];
extern SlotEB50 g_arr_1b1d5f0[];
extern u8 g_tbl_0b20[];
extern u8 g_sym_1b0b4b8[];
extern int g_word_0b84;
extern u8 g_sym_1b0ace8[];
extern u8 g_sym_1b0aca8[];

extern void g_fn_b330(void);
extern void g_fn_1c508(void *);
extern void g_fn_12188(void *);
extern void func_002B4980(int);
extern int func_002B49A0(int, int, int);
extern void func_002678E0(int, void *);
extern void func_00267A68(void *, int, void *, int);
extern void func_002D02E8(int, int, int, int);
extern void func_002944B0(int, int, int, int);
extern void func_00294468(int, int, int);
extern void func_001B57F0(int, int);
extern void func_001B5810(int, int);
extern void g_fn_eaf0(void *);
extern void g_fn_d1e8(void *);
extern int func_001B4E58(int);
extern void func_0010C790(int, int);

int func_01B0EB50(void)
{
    void *msg[4];
    void *p1;
    void *p2;
    int i;

    g_fn_b330();

    g_ptr_1b1e640 = g_sym_1d04720;
    g_ptr_004c = g_sym_1d04720 + 0x5190;

    p1 = g_sym_0f40;
    g_fn_1c508(&p1);
    p2 = g_sym_0f58;
    g_fn_1c508(&p2);

    msg[0] = g_sym_0f70;
    msg[1] = 0;
    g_fn_12188(msg);
    g_sym_0f70[27] = 1;

    msg[0] = g_sym_0f90;
    msg[1] = 0;
    g_fn_12188(msg);
    g_sym_0f90[27] = 1;

    msg[0] = g_sym_0fb0;
    msg[1] = 0;
    g_fn_12188(msg);

    msg[0] = g_sym_0fd0;
    msg[1] = 0;
    g_fn_12188(msg);

    func_002B4980(g_word_0960);
    g_word_1b1d5ec = func_002B49A0(g_word_0960, 8, 0);
    func_002678E0(g_word_1b1d5ec, g_sym_0050);
    func_00267A68(g_sym_1b1d5c0, g_word_1b1d5ec, g_sym_1c04720, 0x100000);

    for (i = 86; i >= 0; i--) {
        g_arr_1b1d5f0[i].b22 = 0;
        g_ptrs_09c0[g_tbl_0b20[i]] = g_sym_1b0b4b8;
    }

    func_002D02E8(g_word_0960, 0, 9, 2);
    func_002944B0(g_word_0960, 0, 1000, 2);
    func_00294468(func_002B49A0(g_word_0960, 6, 5), 0, 2);

    func_001B57F0(g_word_0b84, 1);
    func_001B5810(g_word_0b84, 0);
    g_fn_eaf0(g_sym_1b0ace8);
    g_fn_d1e8(g_sym_1b0aca8);
    func_0010C790(func_001B4E58(g_word_0b84), 255);

    return 0;
}
