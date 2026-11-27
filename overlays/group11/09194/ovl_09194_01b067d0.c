#include "common.h"

extern u8 g_sym_1538[];
extern u8 g_sym_58f0[];
extern u8 g_sym_0a48[];
extern u8 g_sym_1550[];
extern u8 g_sym_0ab8[];
extern u8 g_sym_1220[];
extern int g_word_1574;
extern int g_word_157c;

extern void g_fn_166c8(void *);
extern void g_fn_16ad0(void *);
extern void g_fn_07a00(void *);
extern void g_fn_0f690(void *);

void func_01B067D0(void)
{
    void *msg[3];

    msg[0] = g_sym_1538;
    msg[1] = g_sym_58f0;
    msg[2] = 0;
    g_fn_166c8(msg);

    msg[0] = g_sym_0a48;
    msg[1] = g_sym_1538;
    g_fn_16ad0(msg);

    msg[0] = g_sym_1550;
    msg[1] = g_sym_0ab8;
    g_word_1574 = 0;
    g_fn_07a00(msg);

    g_sym_1550[0x1C] = 1;
    g_word_157c = 1;
    msg[0] = g_sym_1220;
    msg[1] = g_sym_0ab8;
    g_fn_0f690(msg);
}
