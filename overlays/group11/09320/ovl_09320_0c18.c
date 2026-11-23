/* 09320 fade task (572 B, 09320 @ 0x01B00C18). */

#include "common.h"

typedef struct {
    int delay;
    int timer;
    int state;
} FadeState;

extern FadeState g_fade_6060;
extern int g_fade_done_606c;

extern void func_01B00E58(int, int, int, int, int, int, int, int);

static inline int lerp_chan(int a, int b, int t, int d)
{
    return ((t * a + (d - t) * b) / d) & 0xFF;
}

void ovl_09320_0c18(void)
{
    int r, g, b, a;

    if (g_fade_6060.delay > 0) {
        g_fade_6060.delay--;
        return;
    }

    r = 0x80;
    g = 0x80;
    b = 0x80;
    a = 0;

    switch (g_fade_6060.state) {
    case 0:
        g_fade_6060.timer--;
        r = lerp_chan(0x80, 0x80, g_fade_6060.timer, 0x18);
        g = lerp_chan(0x80, 0x40, g_fade_6060.timer, 0x18);
        b = lerp_chan(0x80, 0x80, g_fade_6060.timer, 0x18);
        a = lerp_chan(0x00, 0x40, g_fade_6060.timer, 0x18);
        if (g_fade_6060.timer <= 0) {
            g_fade_6060.state = 1;
            g_fade_6060.timer = 0x20;
        }
        break;
    case 1:
        g_fade_6060.timer--;
        r = lerp_chan(0x80, 0x50, g_fade_6060.timer, 0x20);
        g = lerp_chan(0x40, 0x46, g_fade_6060.timer, 0x20);
        b = lerp_chan(0x80, 0x80, g_fade_6060.timer, 0x20);
        a = 0x40;
        if (g_fade_6060.timer <= 0) {
            g_fade_6060.timer = 0x20;
            g_fade_6060.state = 2;
        }
        break;
    case 2:
        g_fade_6060.timer--;
        r = lerp_chan(0x50, 0x80, g_fade_6060.timer, 0x20);
        g = lerp_chan(0x46, 0x80, g_fade_6060.timer, 0x20);
        b = lerp_chan(0x80, 0x80, g_fade_6060.timer, 0x20);
        a = lerp_chan(0x40, 0x00, g_fade_6060.timer, 0x20);
        if (g_fade_6060.timer <= 0) {
            g_fade_6060.state = 3;
        }
        break;
    default:
        g_fade_done_606c = 1;
        break;
    }

    if (g_fade_done_606c == 0) {
        func_01B00E58(0xC, 2, 0x80, 0x40, r, g, b, a);
    }
}
