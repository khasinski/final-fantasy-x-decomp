#include "common.h"

typedef struct {
    int w00;
    int count;
} InfoE48;

typedef struct {
    u8 pad00[0x124];
    u16 flags124;
    u8 pad126[0x0A];
} Item130;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float vecD0[4];
} Sub720;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x04];
    float fF8;
    float fFC;
    int w100;
    u8 pad104[0x0C];
    int w110;
    u8 pad114[0x0C];
    int w120;
    u16 h124;
    u8 pad126[0x02];
} Sub5DC0;

typedef struct {
    Item130 items[6];
    Sub720 sub720;
    u8 pad800[0x5560];
    u8 sub5D60[0x60];
    Sub5DC0 sub5DC0;
    u8 pad5EE8[0x390];
    float f6278;
    int arr627C[12];
    int idx62AC;
} OvlState;

typedef struct {
    u8 pad00[0x30];
    int w30;
} Work38B8;

extern InfoE48 D_01B00E48;
extern u8 D_01B0BC30[];
extern OvlState *D_01B0BD58;

extern void func_01B02FF0(void *);
extern void func_01B05750(int, int);
extern void func_01B05EA8(int, float, float, float, int);
extern void func_01B07648(void *, void *, int, int, int, int, float);
extern void func_01B07AB8(void *, void *);
extern void func_01B0AFB8(void *, int, int, float, float);
extern void func_01B0B788(void *, int, int);

void func_01B03780(void)
{
    int i;

    for (i = 0; i < D_01B00E48.count; i++) {
        func_01B05EA8(i, 0.7f, 0.7f, 1.4f, 0x3C);
    }
}

void func_01B03808(void)
{
    OvlState *s = D_01B0BD58;
    int i;

    for (i = 0; i < D_01B00E48.count; i++) {
        func_01B05EA8(i, 1.0f, 1.0f, 1.0f, 0x3C);
    }
    func_01B0AFB8(s->sub5D60, 0x1E, 0x32, 0.5f, 1.0f);
}

void func_01B038B8(Work38B8 *w)
{
    OvlState *s = D_01B0BD58;
    int t = w->w30;
    int i;

    if (t > 0) {
        t--;
        w->w30 = t;
    }
    for (i = 0; i < D_01B00E48.count; i++) {
        func_01B05750(i, (s->arr627C[i] * t) / 60);
    }
}

void func_01B03968(void)
{
    int i;

    for (i = 0; i < D_01B00E48.count; i++) {
        func_01B05750(i, -1);
    }
}

void func_01B039C8(void)
{
    OvlState *s = D_01B0BD58;
    Item130 *it = &s->items[s->idx62AC];

    it->flags124 |= 1;
    s->items[4].flags124 |= 1;
}

void func_01B03A00(void)
{
    OvlState *s = D_01B0BD58;
    Item130 *it = &s->items[s->idx62AC];

    it->flags124 &= ~1;
    s->items[4].flags124 &= ~1;
}
