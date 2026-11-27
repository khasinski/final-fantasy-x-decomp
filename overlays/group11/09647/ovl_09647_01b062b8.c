#include "common.h"

extern u8 g_sym_1538[];
extern u8 g_sym_57a0[];
extern u8 g_sym_0a48[];
extern u8 g_sym_1550[];
extern u8 g_sym_0ab8[];
extern u8 g_sym_1220[];
extern u8 g_sym_0ad8[];
extern int g_word_1574;
extern int g_word_157c;

extern void g_fn_15fb8(void *);
extern void g_fn_163c0(void *);
extern void g_fn_072f0(void *);
extern void g_fn_0ef80(void *);
extern void g_fn_0f0b0(void *);

void func_01B062B8(void)
{
    void *msg[3];

    msg[0] = g_sym_1538;
    msg[1] = g_sym_57a0;
    msg[2] = 0;
    g_fn_15fb8(msg);

    msg[0] = g_sym_0a48;
    msg[1] = g_sym_1538;
    g_fn_163c0(msg);

    msg[0] = g_sym_1550;
    msg[1] = g_sym_0ab8;
    g_word_1574 = 0;
    g_fn_072f0(msg);

    g_sym_1550[0x1C] = 1;
    g_word_157c = 1;
    msg[0] = g_sym_1220;
    msg[1] = g_sym_0ad8;
    g_fn_0ef80(msg);

    *(float *)(g_sym_1220 + 0x6C) = 0.5f;
    *(float *)(g_sym_1220 + 0x68) = 0.5f;
    *(float *)(g_sym_1220 + 0x64) = 0.5f;
    *(float *)(g_sym_1220 + 0x60) = 0.5f;
    *(float *)(g_sym_1220 + 0x38) = 0.5f;
    *(float *)(g_sym_1220 + 0x34) = 0.5f;
    *(float *)(g_sym_1220 + 0x30) = 0.5f;
    msg[0] = g_sym_1220;
    msg[1] = 0;
    *(float *)&msg[2] = 1.0f;
    g_fn_0f0b0(msg);
}
