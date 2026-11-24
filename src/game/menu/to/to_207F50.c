/* tu_229 0x207f50-0x208448: low; ~TOGetButtonIconWidth (config/tu_map.tsv) */
#include "common.h"
#define func_00207F70 _hdr_func_00207F70
#include "ffx/q5.h"
#undef func_00207F70
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"

void func_00207F70(u8 *str, int x, int y, u8 a3, u8 a4);

void func_00207F50(int a, int b, int c)
{
    func_00207F70((u8 *)a, b, c, 0, 0x80);
}

void func_00207F60(int a, int b, int c, u8 d)
{
    func_00207F70((u8 *)a, b, c, d, 0x80);
}

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s16 x;
    s16 y;
    u8 pad[10];
    u8 b12;
    u8 b13;
} ToFont207F70;

extern ToFont207F70 D_00323918;
extern u8 D_00323930[];
u8 *func_00204CA8(u8 *s, void *q);
void TOMakePktFont1612(void *p, void *q);

void func_00207F70(u8 *str, int x, int y, u8 a3, u8 a4)
{
    ToFont207F70 *p = &D_00323918;
    u8 *q = D_00323930;

    func_002EF0D0(q, 0, 0x20);
    func_002EF0D0(p, 0, 0x14);
    p->x = x;
    p->y = y;
    p->r = 0x80;
    p->g = 0x80;
    p->b = 0x80;
    p->a = a4;
    p->b12 = 0;
    p->b13 = a3;
    while (*str != 0) {
        str = func_00204CA8(str, q);
        TOMakePktFont1612(p, q);
    }
}

int func_00208060(void)
{
    return 20;
}

int func_00208068(int id)
{
    int base;
    OfsTbl *e = MsGetRomItem(id, &base);

    return base + e->a[0].x;
}

int func_00208090(void)
{
    return func_001C0040();
}

int func_002080B0(int id)
{
    int base;
    OfsTbl *e = MsGetComData(id, &base);

    return base + e->a[0].x;
}

s32 func_002080D8(int a)
{
    s32 pos;
    OfsTbl *t = MsGetRomAbility(a, &pos);

    return pos + t->a[0].x;
}

void func_002082B8(s32 arg0, u8 *arg1, TextItem *arg2);

void func_00208100(s32 a0, u8 *s, int x, int y, int b13)
{
    ToFont207F70 *p = &D_00323918;
    u8 *q = D_00323930;

    func_002EF0D0(q, 0, 0x20);
    func_002EF0D0(p, 0, 0x14);
    p->x = x;
    p->y = y;
    D_00323918.r = 0x80;
    p->g = 0x80;
    p->b = 0x80;
    p->a = 0x80;
    p->b13 = b13;
    p->b12 = 0;
    while (*s != 0) {
        switch (TOGetGroup(*s)) {
        case 4:
            func_00204CA8(s, q);
            TOMakePktFont1612(p, q);
            break;
        case 2:
            if (*s == 0x10 && (u32)(s[1] - 0x50) < 8) {
                func_002082B8(a0, s, (TextItem *)p);
            } else if (*s == 0x0B) {
                func_001FABF0(s[1], p->x, p->y);
                p->x += func_002083E8(s[1]);
            }
            break;
        case 3:
            func_002082B8(a0, s, (TextItem *)p);
            break;
        }
        s = (u8 *)TOSkipCode(s);
    }
}

extern s32 _m2c_func_002082B8_D_00323930 __asm__("D_00323930");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002082B8(s32 arg0, u8 *arg1, TextItem *arg2) {
    register u8 *var_16 __asm__("$16");
    u8 var_2;

    func_002EF0D0(&_m2c_func_002082B8_D_00323930, 0, 0x20);
    var_16 = TOGetChangeMacroAddress(arg0, arg1);
    if (var_16 != 0) {
    __asm__ volatile("" : "+r"(var_16));
        var_2 = *var_16;
        if (var_2 != 0) {
            do {
                if (var_2 == 7) {
                    if ((u32) (((*(u8 *)((u8 *)(var_16) + (1))) + 0x20) & 0xFF) < 0x10U) {
                        arg2->x += (*(u8 *)((u8 *)(var_16) + (1))) + 0xFF20;
                    }
                } else if (TOGetGroup((*(u8 *)((u8 *)(var_16) + (0)))) == 3) {
                    { register u8 *_a1 __asm__("$5") = var_16; __asm__ volatile("" : "+r"(_a1)); func_002082B8(arg0, _a1, arg2); }
                } else {
                    func_00204CA8(var_16, &_m2c_func_002082B8_D_00323930);
                    TOMakePktFont1612(arg2, &_m2c_func_002082B8_D_00323930);
                }
                var_16 = TOSkipCode(var_16);
                var_2 = *var_16;
            } while (var_2 != 0);
        }
    }
}

int func_002083E8(u32 id)
{
    int r = 0;

    if (id - 0x40 <= 15) {
        r = 0x11;
    }
    if (id - 0x30 <= 3) {
        r = 0x12;
    }
    if (id - 0x34 <= 3) {
        r = 0x14;
    }
    if (id - 0x38 <= 1) {
        r = 0x2A;
    }
    if (id == 0x60) {
        r = 0x37;
    }
    return r + 2;
}
