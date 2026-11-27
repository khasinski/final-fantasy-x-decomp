#include "common.h"

typedef struct {
    u8 pad00[0xE0C];
    int wE0C;
    int wE10;
} OvlState;

extern OvlState *D_01B096A0;
extern int D_01B096A8;

extern void func_002B2F18(int);
extern void func_01B01360(float, int);

void func_01B01DE8(void)
{
    OvlState *s = D_01B096A0;
    float f = 0.0f;
    int val = 128;

    if (s->wE0C > 0) {
        s->wE0C--;
    }

    switch (s->wE10) {
    case 0: {
        int c = s->wE0C;
        int n = 50;
        float t;

        val = (c * 128) / n;
        t = (float)c / 50.0f;
        f = (1.0f - t) * 1.5707963705062866f + t * f;
        if (c == 0) {
            s->wE0C = n;
            s->wE10 = 1;
        }
        break;
    }
    case 1: {
        int c = s->wE0C;
        int n = 50;
        float t;

        val = ((n - c) * 128) / n;
        t = (float)c / 50.0f;
        f = (1.0f - t) * f + t * 1.5707963705062866f;
        if (c == 0) {
            func_002B2F18(D_01B096A8);
            D_01B096A8 = -1;
            s->wE10++;
        }
        break;
    }
    }

    func_01B01360(f, val);
}
