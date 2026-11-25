/* tu_105 0x15c5a8-0x160780: low; movie_str (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

void func_0015C5A8(int v) {
    D_0030DDF4 = v;
}

void func_0015F800(int a, int b, int c, int d);
void audioInit(int a);

typedef struct {
    u8 pad0[0x503C0];
    s32 w503C0;
    s32 w503C4;
    s32 w503C8;
    s32 w503CC;
    s32 w503D0;
    s32 w503D4;
    u8 pad503D8[0x50514 - 0x503D8];
    s32 w50514;
    s32 w50518;
    u8 pad5051C[0x505C4 - 0x5051C];
    char b505C4[0x80];
    char b50644[0xA0];
    s32 w506E4;
    s32 w506E8;
    s32 w506EC;
    s32 w506F0;
    s32 w506F4;
    u8 pad506F8[0x5075C - 0x506F8];
    s8 b5075C;
    u8 pad5075D[2];
    s8 b5075F;
} MovieStrWork;

extern MovieStrWork *_mov_D_0030DDF0 __asm__("D_0030DDF0");

int func_0015C5B8(char *a, char *b, int e, int f)
{
    int i;

    if (f == 0) {
        func_0015F800(e, 0x200, 0x1A0, 0);
    } else {
        func_0015F800(e, 0x280, 0x1C0, f);
    }
    audioInit(e);
    _mov_D_0030DDF0->b5075C = 0;
    for (i = 0; ; i++) {
        _mov_D_0030DDF0->b505C4[i] = a[i];
        if (a[i] == 0) {
            break;
        }
    }
    for (i = 0; ; i++) {
        _mov_D_0030DDF0->b50644[i] = b[i];
        if (b[i] == 0) {
            break;
        }
    }
    _mov_D_0030DDF0->w506E4 = 0;
    _mov_D_0030DDF0->w506E8 = 0;
    _mov_D_0030DDF0->w506EC = 0;
    _mov_D_0030DDF0->w506F0 = 0;
    _mov_D_0030DDF0->w503C0 = 0;
    _mov_D_0030DDF0->w503C4 = 0;
    _mov_D_0030DDF0->w503C8 = 0;
    _mov_D_0030DDF0->w503CC = 0;
    _mov_D_0030DDF0->w503D0 = 0;
    return 0;
}

int func_0015C718(int a, int b, int c, int d, int e, int f)
{
    if (f == 0) {
        func_0015F800(e, 0x200, 0x1A0, 0);
    } else {
        func_0015F800(e, 0x280, 0x1C0, f);
    }
    audioInit(e);
    _mov_D_0030DDF0->b5075C = 1;
    _mov_D_0030DDF0->b505C4[0] = 0;
    _mov_D_0030DDF0->b50644[0] = 0;
    _mov_D_0030DDF0->w506E4 = a;
    _mov_D_0030DDF0->w506E8 = b;
    _mov_D_0030DDF0->w506EC = c;
    _mov_D_0030DDF0->w506F0 = d;
    _mov_D_0030DDF0->w503C0 = 0;
    _mov_D_0030DDF0->w503C4 = 0;
    _mov_D_0030DDF0->w503C8 = 0;
    _mov_D_0030DDF0->w503CC = 0;
    _mov_D_0030DDF0->w503D0 = 0;
    return 0;
}

void func_0015C808(void) {
    func_0017135C(1);
}

void func_0015C810(void)
{
    S58FE54 *s = (S58FE54 *)D_0030DDF0;
    u8 *p = s->p5059C;
    int sz = *(int *)p;
    u8 *data = p + 0x10;
    int n = sz + 0x10;

    s->p5059C = p + n;
    if (n != 0x10) {
        ((void (*)(u8 *, int, int, S58FE54 *))func_00254730)(data, s->w5051C, 0x1C0, s);
        ((S58FE54 *)D_0030DDF0)->b5076D = 1;
    }
}

int func_0015C888(int fd, int n, u8 *buf, int *out, S58FE54 *s)
{
    func_002F8660(0);
    if (s->b5075C != 0) {
        return func_0015B918(n, buf, out, s);
    }
    func_002FCB20(fd, buf, n);
    *out = 0;
    return 1;
}

int func_0015C928(int unused, int a, S58FE54 *s)
{
    if (s->b5075C != 0) {
        return func_0015B9E8(a, s);
    }
    return func_206C650(a, s);
}

int func_0015C968(S58FE54 *s)
{
    int busy = -1;

    if (s->w50544 < 0) {
        return 0;
    }
    func_002FD050(s->w50544, 1, &busy);
    return busy != 0;
}

int func_0015C9B0(S58FE54 *s)
{
    if (s->b5075C != 0) {
        return func_0015BBA8(s);
    }
    return func_0015C968(s);
}

extern char D_0056B820[];
extern char D_0056B848[];
extern char D_0056B858[];

void func_0015C9F0(void)
{
    int a = _mov_D_0030DDF0->w50514;
    int b = _mov_D_0030DDF0->w50518;
    int base = _mov_D_0030DDF0->w506F4;
    int step = a << 10;
    int prod = a * b;
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    u32 end;

    _mov_D_0030DDF0->w503C0 = base;
    p1 = base + step;
    _mov_D_0030DDF0->w503C4 = p1;
    p2 = p1 + step;
    _mov_D_0030DDF0->w503C8 = p2;
    p3 = (prod * 0x300) + p2;
    _mov_D_0030DDF0->w503CC = p3;
    p4 = (prod * 0x180) + p3;
    _mov_D_0030DDF0->w503D0 = p4;
    p5 = p4 + (((a * 6) + 5) << 4);
    _mov_D_0030DDF0->w503D4 = p5;
    *(s32 *)p5 = 0x12345678;
    end = _mov_D_0030DDF0->w503D4 + 4;
    if (_mov_D_0030DDF0->b5075F == 0) {
        if (end > 0x1EFFFFFU) {
            func_001577A8(D_0056B820, D_0056B848, 0x172);
        }
    } else {
        if (end > 0x1FA003FU) {
            func_001577A8(D_0056B858, D_0056B848, 0x17A);
        }
    }
}

void func_0015CAE0(void) {
    func_00171530(D_0030DDF0 + 0x80, 0x10000, func_0015CB00, 0);
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015CB00);

void func_0015D558(int a) {
    if (a == 0) {
        func_002D3FF0(0);
    } else {
        func_0015DDB8();
        func_0017135C(1);
    }
}

void func_206C630(int fd);
int func_0015B418(int a);
void func_002D5F58(int a);
void TkSndUpdate2(void);
int func_002D64E0(int a);

void mpegstrendsub(S58FE54 *s, int a)
{
    int st;

    if (s == 0) {
        return;
    }
    audioStop(s);
    if (s->w50544 >= 0) {
        if (s->b5075D != 0) {
            while (func_0015C968(s) != 0) {
                func_0015D558(a);
            }
            func_206C630(s->w50544);
        } else if (((S58FE54 *)D_0030DDF0)->b5075C != 0) {
            while ((st = func_0015C9B0(s)) != 0) {
                if (st != -1) {
                    func_0015B350();
                    st = func_0015B418(a);
                    if (st == 0) {
                        break;
                    }
                    if (st == 1) {
                        break;
                    }
                    if (st == 10) {
                        break;
                    }
                }
                func_0015D558(a);
            }
        } else {
            while (func_0015C9B0(s) != 0) {
                func_0015D558(a);
            }
            func_206C630(s->w50544);
        }
        s->w50544 = -1;
    }
    if (s->w50714 != 0) {
        func_002D5F58(1);
        while (1) {
            if (a == 0) {
                TkSndUpdate2();
            }
            if (func_002D64E0(0) == 0) {
                break;
            }
            func_0015D558(a);
        }
        s->w50714 = 0;
    }
}

typedef struct MovieStrView { /* DEBT(NAME): overlay of D_0030DDF0 for func_0015D730 */
    u8 pad0[0x50514];
    s32 w50514;
    s32 w50518;
    s32 w5051C;
    s32 w50520;
    u8 pad50524[0x5059C - 0x50524];
    u8 *p5059C;
    u8 pad505A0[0x505C0 - 0x505A0];
    s32 w505C0;
    u8 pad505C4[0x506DC - 0x505C4];
    s32 w506DC;
    u8 pad506E0[0x5075F - 0x506E0];
    s8 b5075F;
    s8 b50760;
} MovieStrView;

extern MovieStrView *_mov2_D_0030DDF0 __asm__("D_0030DDF0"); /* DEBT(TYPE): local view of D_0030DDF0 */
int func_0015DE90(void);
int func_0015E1D0(void);

void func_0015D730(void)
{
    MovieStrView *m = _mov2_D_0030DDF0;
    u8 *hdr = m->p5059C;

    m->w50514 = hdr[0xB];
    m->w50518 = hdr[0xC];
    m->w5051C = m->w50514 << 4;
    m->w50520 = m->w50518 << 4;
    if (m->w5051C == 0x200 && m->w50520 == 0x1A0) {
        if ((m->w505C0 & 0x10000) != 0) {
            m->b5075F = 0;
        } else {
            m->b5075F = 6;
        }
    }
    if (_mov2_D_0030DDF0->w5051C == 0x140) {
        _mov2_D_0030DDF0->b5075F = 2;
        if (_mov2_D_0030DDF0->w50520 == 0x1A0) {
            _mov2_D_0030DDF0->b5075F = 5;
        }
    }
    if (_mov2_D_0030DDF0->w5051C == 0x280) {
        _mov2_D_0030DDF0->b5075F = 1;
        if (_mov2_D_0030DDF0->w50520 == 0x1A0) {
            _mov2_D_0030DDF0->b5075F = 4;
        }
    }
    if (_mov2_D_0030DDF0->b5075F != _mov2_D_0030DDF0->b50760) {
        _mov2_D_0030DDF0->b50760 = _mov2_D_0030DDF0->b5075F;
        ((void (*)(int, int))func_0011A5A0)(_mov2_D_0030DDF0->b5075F, 0); /* DEBT(TYPE): header prototype has 1 arg */
        func_00159640(_mov2_D_0030DDF0->b5075F);
        func_0020D468();
        {
            register MovieStrView *mv __asm__("$3") = _mov2_D_0030DDF0; /* DEBT(REG): ee-gcc picks $v0 instead of $v1 */

            TOInitMovieMessage(mv->w5051C, mv->w50520);
        }
        func_0015C9F0();
    }
    func_0015F338();
    *(volatile u32 *)0x10002010 = 0x40000000;
    if (_mov2_D_0030DDF0->p5059C[8] == 0) {
        func_00171530((void *)(D_0030DDF4 + 0x10F0), 0x1800, func_0015DE90, 0);
    } else {
        func_00171530((void *)(D_0030DDF4 + 0x10F0), 0x1800, func_0015E1D0, 0);
    }
    _mov2_D_0030DDF0->w506DC = 1;
}

void func_0015F198(int addr, int size);
void func_0015F1F8(int addr, int size);
extern void func_0015BBF8(void *, void *, int, int, int, int, int, int, int, int, int);
extern void func_0015C068(void *);

void func_0015D940(void)
{
    int started = 0;
    int buf_idx = 0;
    int prev_idx = 1;
    u8 *base = D_0030DDF0 + 0x50000;
    int mb_w = *(s32 *)(base + 0x514);
    int mb_h = *(s32 *)(base + 0x518);
    int total = mb_w * mb_h * 0x180;
    int flg61 = *(s8 *)(base + 0x761);
    int flg6E = *(s8 *)(base + 0x76E);
    register int flg62 __asm__("$20") = (flg61 != 0) ? *(s8 *)(base + 0x762) : 0; /* DEBT(REG): keeps flg62 in $s4 instead of $s3 */
    register int y_off __asm__("$18"); /* DEBT(REG): keeps y_off in $s2 instead of $s3 */
    int row;

    {
        u8 *b = D_0030DDF0 + 0x50000;
        y_off = *(s32 *)(b + 0x6E0);
        if (*(s8 *)(b + 0x75F) == 0) {
            y_off += 0 / *(s32 *)(b + 0x51C);
        }
        if (*(s8 *)(b + 0x763) == 0 && *(s32 *)(b + 0x534) == 0) {
            y_off += *(s32 *)(b + 0x520);
        }
    }

    func_002DA610(0, 0);
    func_0015F198(*(s32 *)(D_0030DDF0 + 0x503CC), total);

    row = 0;
    while (row < *(s32 *)(D_0030DDF0 + 0x50518)) {
        u8 *b = D_0030DDF0 + 0x50000;
        u32 cmd;
        func_0015F1F8(*(s32 *)((b + (buf_idx << 2)) + 0x3C0), *(s32 *)(b + 0x514) << 10);
        cmd = (flg62 << 26) | 0x70000000U;
        *(volatile u32 *)0x10002000 = ((flg61 << 27) | *(s32 *)(D_0030DDF0 + 0x50514)) | cmd;
        if (started != 0) {
            u8 *b2 = D_0030DDF0 + 0x50000;
            if (*(s32 *)(b2 + 0x524) == 0) {
                func_0015BBF8(
                    *(void **)(b2 + 0x3D0),
                    *(void **)((b2 + (prev_idx << 2)) + 0x3C0),
                    0,
                    ((row - 1) << 4) + y_off,
                    *(s32 *)(b2 + 0x514) << 4,
                    0x10,
                    *(s32 *)(b2 + 0x51C),
                    0,
                    0,
                    flg61,
                    flg6E
                );
            }
            func_002DA610(0, 0);
            func_0015C068(*(void **)(D_0030DDF0 + 0x503D0));
        }
        prev_idx ^= 1;
        buf_idx ^= 1;
        started = 1;
        while (*(volatile s32 *)0x10002010 < 0)
            ;
        while ((*(volatile u32 *)0x1000B000 >> 8) & 1)
            ;
        row++;
    }

    {
        u8 *b2 = D_0030DDF0 + 0x50000;
        if (*(s32 *)(b2 + 0x524) == 0) {
            func_0015BBF8(
                *(void **)(b2 + 0x3D0),
                *(void **)((b2 + (prev_idx << 2)) + 0x3C0),
                0,
                ((row - 1) << 4) + y_off,
                *(s32 *)(b2 + 0x514) << 4,
                0x10,
                *(s32 *)(b2 + 0x51C),
                0,
                0,
                flg61,
                flg6E
            );
        }
    }
    func_002DA610(0, 0);
    func_0015C068(*(void **)(D_0030DDF0 + 0x503D0));
    while ((*(volatile u32 *)0x1000B400 >> 8) & 1)
        ;
    func_002DA610(0, 0);
}

extern char D_0056B8C0[];
extern char D_0056B8D0[];
extern char D_0056B8E0[];
extern char D_0056B8E8[];
extern char D_0056B8F0[];
extern char D_0056B900[];

void print_sound_debug_info(void)
{
    char buf[0x80];
    int *p = (int *)(D_0030DDF0 + 0x50730);

    func_002F0008(buf, D_0056B8C0, p[0], p[1]);
    func_001609A8(0x20, 0x66, buf);
    func_002F0008(buf, D_0056B8D0, p[3], p[2]);
    func_001609A8(0x20, 0x76, buf);
    func_002F0008(buf, D_0056B8E0, p[4]);
    func_001609A8(0x20, 0x86, buf);
    func_002F0008(buf, D_0056B8E8, p[5]);
    func_001609A8(0x20, 0x96, buf);
}

void movie_csc(void)
{
    char buf[0x80];
    u8 *p = D_0030DDF0;
    int v;

    func_002F0008(buf, D_0056B8F0, *(int *)(p + 0x50528), *(int *)(p + 0x50708));
    func_001609A8(0x20, 0x20, buf);
    v = ((int (*)(int))func_0011AC68)(0);
    func_002F0008(buf, D_0056B900, v);
    func_001609A8(0x20, 0x36, buf);
}

void func_0015D940(void);

void func_0015DDB8(void)
{
    if (*(s32 *)(D_0030DDF0 + 0x506DC) == 0) {
        return;
    }
    if (func_002D9868() != 0) {
        while ((func_002D4118() & 0x2000) == 0) {
            func_002D3FF0(0);
        }
    }
    *(volatile int *)0x10002010 = 0x40000000;
    func_00157808();
    func_00171530((void *)(D_0030DDF4 + 0x10F0), 0x1800, func_0015D940, 0);
    if (func_0020D540() != 0) {
        movie_csc();
    }
    TODrawMovieMessage();
}

void func_0015F198(int addr, int size);
void func_0015F1F8(int addr, int size);
void func_0015F258(int a, int b, int c);
void func_0015F2C8(int a, int b, int c);
void func_0015F028(int a, int b, int c, int d);
void func_00170DC4(void *p);

static inline int mov_ipu_not_eof(void)
{
    u32 b15;
    if (((*(volatile u32 *)0x10002010 >> 14) & 1) != 0) {
        return 0;
    }
    b15 = (*(volatile u32 *)0x10002010 >> 15) & 1;
    __asm__("" : "+r"(b15));
    return b15 ^ 1;
}

int func_0015DE90(void)
{
    register u8 *hdr __asm__("$4") = *(u8 **)(D_0030DDF0 + 0x5059C);
    volatile int sz;
    register u32 bE __asm__("$7");
    register u32 ctrl_flags __asm__("$19");
    register u32 p9 __asm__("$21");
    volatile u32 ipu_ctrl;
    int idx;
    int mb;

    sz = *(s32 *)hdr;
    {
        register u32 bF2 __asm__("$2") = hdr[0xF];
        register u32 f0 __asm__("$3");
        bE = hdr[0xE];
        f0 = bF2 & 1;
        __asm__("" : "+r"(f0), "+r"(bF2));
        bF2 >>= 1;
        f0 <<= 22;
        bF2 <<= 16;
        __asm__("" : "+r"(f0), "+r"(bF2), "+r"(bE));
        ctrl_flags = bE << 20;
        __asm__("" : "+r"(f0) : "r"(ctrl_flags));
        f0 += bF2;
        ctrl_flags += f0;
    }
    {
        register volatile u32 *p5 __asm__("$5") = (volatile u32 *)0x10002010;
        register u32 b9 __asm__("$2");
        register u32 v6 __asm__("$6");
        register u32 r2 __asm__("$2");
        register u32 v3 __asm__("$3");
        __asm__("" : "+r"(hdr) : "r"(ctrl_flags));
        b9 = hdr[9];
        __asm__("" : "+r"(ctrl_flags) : "r"(b9));
        v6 = ctrl_flags + 0x01200000;
        *p5 = v6;
        __asm__("" : "+r"(b9) : : "memory");
        p9 = b9 << 16;
        r2 = *p5 | 0x40000000;
        v3 = r2 + ctrl_flags;
        *p5 = v3;
    }
    while (*(volatile s32 *)0x10002010 < 0)
        ;
    idx = -1;
    mb = 0;
    func_0015F198((int)(*(u8 **)(D_0030DDF0 + 0x5059C) += 0x10), sz);
    {
        register u32 ic __asm__("$2") = ctrl_flags + 0x01200000;
        ipu_ctrl = ic;
    }
    while (1) {
        register int next_mb __asm__("$16");
        idx++;
        *(volatile u32 *)0x10002000 = 0x30000000;
        next_mb = mb + 1;
        __asm__ volatile("" : "+r"(next_mb));
        while (*(volatile s32 *)0x10002010 < 0)
            ;
        func_0015F1F8((int)(D_0030DDF4 + 0x70), 0x300);
        {
            register u32 ic5 __asm__("$5") = ipu_ctrl;
            *(volatile u32 *)0x10002010 = ic5;
        }
        *(volatile u32 *)0x10002000 = p9 | (mb == 0 ? 0x2C000000 : 0x28000000);
        mb = next_mb;
        while (*(volatile s32 *)0x10002010 < 0)
            ;
        while ((*(volatile u32 *)0x1000B000 >> 8) & 1)
            ;
        func_0015F2C8(*(s32 *)(D_0030DDF0 + 0x503C8) + idx * 0x300, (int)(D_0030DDF4 + 0x70), 0x300);
        while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
            ;
        func_0015F028(idx, 0, 0, 2);
        while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
            ;
        if (!mov_ipu_not_eof()) {
            break;
        }
    }
    {
        register volatile u32 *p3 __asm__("$3") = (volatile u32 *)0x10002010;
        register u32 v4 __asm__("$4");
        register u32 c5 __asm__("$5") = 0x40000000;
        register volatile s32 *p8 __asm__("$8") = (volatile s32 *)0x10002010;
        register u32 v2 __asm__("$2");
        *(volatile u32 *)0x1000B400 = 0;
        v4 = *p3;
        v2 = (v4 | c5) + ctrl_flags;
        *p3 = v2;
        while (*p8 < 0)
            ;
    }
    while ((*(volatile u32 *)0x1000B400 >> 8) & 1)
        ;
    {
        typedef struct {
            u8 pad[0x59C];
            u8 *p59C;
        } MovOff59C;
        register int off5 __asm__("$5") = 0x50000;
        register MovOff59C *base __asm__("$3") = (MovOff59C *)(D_0030DDF0 + off5);
        register u8 *cur __asm__("$4") = base->p59C;
        register int s5 __asm__("$5");
        __asm__("" : "+r"(cur));
        s5 = sz;
        base->p59C = cur + s5;
    }
    return 0;
}

void func_0015ED58(int idx, int mvx, int mvy);
void func_0015F028(int idx, int mvx, int mvy, int type);

int func_0015E1D0(void)
{
    register u8 *hdr __asm__("$4") = *(u8 **)(D_0030DDF0 + 0x5059C);
    volatile int b9;
    int sz;
    register u32 bE __asm__("$7");
    int bA;
    register u32 ctrl_flags __asm__("$18");
    register int first __asm__("$22") = 1;
    int mvx;
    int mvy;
    register int mb __asm__("$21");
    int idx;
    u32 val;
    int type;

    sz = *(s32 *)hdr;
    b9 = hdr[9];
    {
        register u32 bF2 __asm__("$2") = hdr[0xF];
        register u32 f0 __asm__("$3");
        bE = hdr[0xE];
        f0 = bF2 & 1;
        __asm__("" : "+r"(f0), "+r"(bF2));
        bA = hdr[0xA];
        bF2 >>= 1;
        f0 <<= 22;
        bF2 <<= 16;
        __asm__("" : "+r"(f0), "+r"(bF2), "+r"(bE));
        ctrl_flags = bE << 20;
        __asm__("" : "+r"(f0) : "r"(ctrl_flags));
        f0 += bF2;
        ctrl_flags += f0;
    }
    {
        register volatile u32 *p5 __asm__("$5") = (volatile u32 *)0x10002010;
        register u32 v6 __asm__("$6");
        register u32 r2 __asm__("$2");
        register u32 v3 __asm__("$3");
        v6 = ctrl_flags + 0x01200000;
        *p5 = v6;
        r2 = *p5 | 0x40000000;
        v3 = r2 + ctrl_flags;
        *p5 = v3;
    }
    while (*(volatile s32 *)0x10002010 < 0)
        ;
    mvx = 0;
    mvy = 0;
    func_0015F198((int)(*(u8 **)(D_0030DDF0 + 0x5059C) += 0x10), sz);
    __asm__ volatile("" : : : "memory");
    mb = 0;
    goto check_mb;

    while (1) {
        mb++;
        do {
            *(volatile u32 *)0x10002000 = 0x30000000;
            while (*(volatile s32 *)0x10002010 < 0)
                ;
        } while ((*(volatile u32 *)0x10002000 & 0xFFFF) == 0x23);
        if (val & 1) {
            *(volatile u32 *)0x10002000 = 0x38000000;
            {
                register volatile s32 *p4 __asm__("$4") = (volatile s32 *)0x10002010;
                __asm__ volatile("" : "+r"(p4));
                while (*p4 < 0)
                    ;
            }
            mvx = ((s32)(*(volatile u32 *)0x10002000 << 20)) >> 16;
            *(volatile u32 *)0x10002000 = 0x38000000;
            {
                register volatile s32 *p6 __asm__("$6") = (volatile s32 *)0x10002010;
                __asm__ volatile("" : "+r"(p6));
                while (*p6 < 0)
                    ;
            }
            mvy = ((s32)(*(volatile u32 *)0x10002000 << 20)) >> 16;
            *(volatile u32 *)0x10002000 = 0x38000000;
            {
                register volatile s32 *p6b __asm__("$6") = (volatile s32 *)0x10002010;
                __asm__ volatile("" : "+r"(p6b));
                while (*p6b < 0)
                    ;
            }
            {
                u32 t = *(volatile u32 *)0x10002000;
                mvx = (s16)(mvx + t);
            }
            *(volatile u32 *)0x10002000 = 0x38000000;
            {
                register volatile s32 *p5b __asm__("$5") = (volatile s32 *)0x10002010;
                __asm__ volatile("" : "+r"(p5b));
                while (*p5b < 0)
                    ;
            }
            {
                u32 t = *(volatile u32 *)0x10002000;
                mvy = (s16)(mvy + t);
            }
        }
        switch (type) {
        case 1:
            func_0015F1F8(D_0030DDF4 + 0x70, 0x300);
            {
                register volatile u32 *p6 __asm__("$6") = (volatile u32 *)0x10002010;
                register u32 c3 __asm__("$3") = 0x01000000;
                register u32 c5 __asm__("$5");
                register volatile u32 *p4 __asm__("$4");
                register u32 v2 __asm__("$2");
                __asm__ volatile("" : "+r"(p6), "+r"(c3));
                c3 = ctrl_flags + c3;
                __asm__ volatile("" : "+r"(c3));
                c5 = 0x20000000;
                __asm__ volatile("" : "+r"(c5));
                p4 = (volatile u32 *)0x10000000;
                __asm__ volatile("" : "+r"(p4));
                v2 = bA << 16;
                __asm__ volatile("" : "+r"(v2));
                *p6 = c3;
                v2 |= c5;
                p4 = (volatile u32 *)((u32)p4 | 0x2000);
                __asm__ volatile("" : "+r"(p4), "+r"(v2));
                *p4 = v2;
            }
            {
                register int a5 __asm__("$5") = mvx;
                __asm__ volatile("" : "+r"(a5));
                func_0015ED58(idx, a5, mvy);
            }
            while (*(volatile s32 *)0x10002010 < 0)
                ;
            while ((*(volatile u32 *)0x1000B000 >> 8) & 1)
                ;
            while ((*(volatile u32 *)0x1000D400 >> 8) & 1)
                ;
            while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
                ;
            func_0015F028(idx, mvx, mvy, type);
            if (!((*(volatile u32 *)0x10002010 >> 14) & 1)) {
                (void)*(volatile u32 *)0x10002010;
            }
            break;
        case 2:
            func_0015F1F8(D_0030DDF4 + 0x70, 0x300);
            {
                register int v9 __asm__("$2") = b9;
                register volatile u32 *p6 __asm__("$6") = (volatile u32 *)0x10000000;
                register u32 c4 __asm__("$4") = 0x01200000;
                register u32 v3 __asm__("$3");
                register u32 v5 __asm__("$5");
                __asm__ volatile("" : "+r"(v9), "+r"(p6), "+r"(c4));
                v3 = first << 26;
                v5 = v9 << 16;
                c4 = ctrl_flags + c4;
                __asm__ volatile("" : "+r"(c4), "+r"(v3), "+r"(v5));
                p6 = (volatile u32 *)((u32)p6 | 0x2010);
                v5 |= 0x28000000;
                __asm__ volatile("" : "+r"(p6), "+r"(c4), "+r"(v5));
                *p6 = c4;
                __asm__ volatile("" : : : "memory");
                v3 |= v5;
                {
                    register volatile u32 *p2 __asm__("$2") = (volatile u32 *)0x10002000;
                    __asm__ volatile("" : "+r"(p2), "+r"(v3));
                    first = 0;
                    __asm__ volatile("" : "+r"(first));
                    *p2 = v3;
                }
            }
            while (*(volatile s32 *)0x10002010 < 0)
                ;
            while ((*(volatile u32 *)0x1000B000 >> 8) & 1)
                ;
            while ((*(volatile u32 *)0x1000D400 >> 8) & 1)
                ;
            while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
                ;
            func_0015F028(idx, 0, 0, type);
            if (!((*(volatile u32 *)0x10002010 >> 14) & 1)) {
                (void)*(volatile u32 *)0x10002010;
            }
            break;
        case 3:
            func_0015ED58(idx, mvx, mvy);
            while ((*(volatile u32 *)0x1000D400 >> 8) & 1)
                ;
            func_0015F028(idx, mvx, mvy, type);
            while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
                ;
            break;
        }
    check_mb:
        *(volatile u32 *)0x10002000 = 0x30000000;
        idx = mb;
        while (*(volatile s32 *)0x10002010 < 0)
            ;
        val = *(volatile u32 *)0x10002000;
        type = val & 0xFFFF;
        if (type == 4) {
            break;
        }
    }
    {
        register volatile u32 *p3 __asm__("$3") = (volatile u32 *)0x10002010;
        register u32 v4 __asm__("$4");
        register u32 c5 __asm__("$5") = 0x40000000;
        register volatile s32 *p8 __asm__("$8") = (volatile s32 *)0x10002010;
        register u32 v2 __asm__("$2");
        *(volatile u32 *)0x1000B400 = 0;
        v4 = *p3;
        v2 = (v4 | c5) + ctrl_flags;
        *p3 = v2;
        while (*p8 < 0)
            ;
    }
    while ((*(volatile u32 *)0x1000B400 >> 8) & 1)
        ;
    while ((*(volatile u32 *)0x1000D000 >> 8) & 1)
        ;
    *(u8 **)(D_0030DDF0 + 0x5059C) += sz;
    return 0;
}

void func_0015E858(void)
{
    S58FE54 *s = (S58FE54 *)D_0030DDF0; /* DEBT(CAST): D_0030DDF0 is declared as a byte pointer */

    switch (s->w506C8) {
    case 0:
        func_0015ACC0(s->p5059C + 0x10, s->buf2DDC0, 0, s);
        break;
    case 1:
        func_0015ACC0(s->p5059C + 0x10, s->buf2DDC0, s->p5059C + 0x1C40, s);
        break;
    }
}

void func_0015E8C0(void)
{
    S58FE54 *s = (S58FE54 *)D_0030DDF0; /* DEBT(CAST): D_0030DDF0 is declared as a byte pointer */

    switch (s->w506C8) {
    case 0:
        func_0015AF10((s16 *)(s->p5059C + 0x10), 0, s);
        break;
    case 1:
        func_0015AF10((s16 *)(s->p5059C + 0x10), (int)(s->p5059C + (s->w50758 + 0x10)), s); /* DEBT(CAST) */
        break;
    }
}

typedef struct {
    u8 b[0x2300];
} MovStrSubBlk;

typedef struct {
    u8 pad0[0x2DDC0];
    u8 buf2DDC0[0xF000];
    u8 buf3CDC0[2][0x7800];
    MovStrSubBlk buf4BDC0[2];
    u8 pad503C0[0x5059C - 0x503C0];
    u8 *p5059C;
    u8 pad505A0[0x506C8 - 0x505A0];
    s32 w506C8;
    u8 pad506CC[0x50714 - 0x506CC];
    s32 w50714;
    u8 pad50718[8];
    s32 w50720;
    s32 w50724[2];
    u8 pad5072C[4];
    s32 w50730[7];
    u8 pad5074C[12];
    s32 w50758;
    u8 pad5075C[9];
    s8 b50765;
    s8 b50766;
    s8 b50767;
    s8 b50768[2];
    s8 b5076A[2];
    u8 pad5076C[5];
    u8 b50771;
} __attribute__((aligned(8))) MovStrAudioCtx;

extern MovStrAudioCtx *_movaud_D_0030DDF0 __asm__("D_0030DDF0");
void func_0015AF88(void *, void *, int, void *, void *);
void func_0015B008(void *, void *, int, void *, void *);
void func_0015A828(void *);
void func_0015A790(void *, void *, int, int, void *);
void SndDataSendSync(int);
int SqsStraightStreamingDataEnableStatus(void);
int *func_002531B0(void);

void func_0015E910(void)
{
    MovStrAudioCtx *s = _movaud_D_0030DDF0;
    u8 *p = s->p5059C;
    u32 sz = *(u32 *)p;
    int idx;
    void *sub;

    switch (sz) {
    case 0:
        break;
    case 0x40: {
        int arg2 = *(s32 *)(p + 4);
        sub = 0;
        switch (s->w506C8) {
        case 0:
            sub = 0;
            break;
        case 1:
            sub = p + ((((arg2 + 15) / 16) * 16) + 0x10);
            break;
        }
        func_0015AF88(_movaud_D_0030DDF0->p5059C + 0x10, _movaud_D_0030DDF0->buf2DDC0, arg2, sub, _movaud_D_0030DDF0);
        break;
    }
    case 0x50:
    case 0x51: {
        int arg2 = *(s32 *)(p + 4);
        sub = 0;
        switch (s->w506C8) {
        case 0:
            sub = 0;
            break;
        case 1:
            sub = (p + (*(s32 *)(p + 8) + 0x10)) - *(s32 *)(p + 12);
            break;
        }
        func_0015B008(_movaud_D_0030DDF0->p5059C + 0x10, _movaud_D_0030DDF0->buf2DDC0, arg2, sub, _movaud_D_0030DDF0);
        break;
    }
    case 0x1C30:
        func_0015ACC0(p + 0x10, s->buf2DDC0, 0, (S58FE54 *)s);
        break;
    case 0x3860:
        func_0015ACC0(p + s->w506C8 * 0x1C30 + 0x10, s->buf2DDC0, 0, (S58FE54 *)s);
        break;
    case 0xC800:
        func_0015AF10((s16 *)(p + (s->w506C8 * s->w50758 + 0x10)), 0, (S58FE54 *)s);
        break;
    case 0x7800:
    case 0x6400:
        func_0015AF10((s16 *)(p + 0x10), 0, (S58FE54 *)s);
        break;
    case 0x8700:
    case 0x8000:
        func_0015E8C0();
        break;
    case 0x3830:
    case 0x3F30:
        func_0015E858();
        break;
    }

    if (sz == 0) {
        if (_movaud_D_0030DDF0->b50766 == 0
            && (_movaud_D_0030DDF0->b5076A[0] != 0 || _movaud_D_0030DDF0->b5076A[1] != 0)
            && SqsStraightStreamingDataEnableStatus() != 0) {
            func_0015A828(_movaud_D_0030DDF0);
            idx = 0;
            if (_movaud_D_0030DDF0->w50724[0] == -1) {
                idx = 1;
            } else if (_movaud_D_0030DDF0->w50724[1] < _movaud_D_0030DDF0->w50724[0] && _movaud_D_0030DDF0->w50724[1] >= 0) {
                idx = 1;
            }
            if (_movaud_D_0030DDF0->w50714 != 0 && _movaud_D_0030DDF0->b50768[idx] != 0) {
                sub = &_movaud_D_0030DDF0->buf4BDC0[idx];
            } else {
                sub = 0;
            }
            func_0015A790(_movaud_D_0030DDF0->buf3CDC0[idx], sub, 0, _movaud_D_0030DDF0->w50724[idx], _movaud_D_0030DDF0);
            SndDataSendSync(1);
            _movaud_D_0030DDF0->b5076A[idx] = 0;
            _movaud_D_0030DDF0->b50768[idx] = 0;
            _movaud_D_0030DDF0->w50724[idx] = -1;
        }
    } else {
        _movaud_D_0030DDF0->w50720++;
    }

    {
        int *st = func_002531B0();
        MovStrAudioCtx *s2 = _movaud_D_0030DDF0;
        s2->w50730[0] = st[0];
        s2->w50730[1] = st[1];
        s2->w50730[2] = st[2];
        s2->w50730[3] = st[3];
        s2->w50730[4] = st[4];
        s2->w50730[5] = st[5];
        s2->w50730[6] = st[6];
        if (s2->b50765 != 0 && s2->w50730[6] != 0) {
            s2->b50771++;
        }
    }
}

void func_0015ED58(int mb, int dx, int dy)
{
    int w = *(s32 *)(D_0030DDF0 + 0x50514);
    int mb_y = mb / w;
    int mb_x = mb % w;
    int ref_y = mb_y + dy / 16;
    int ref_x = mb_x + dx / 16;
    int px;
    int py;
    int ref_mb;

    if (dy % 16 < 0) {
        ref_y--;
    }
    if (dx % 16 < 0) {
        ref_x--;
    }
    px = mb_x * 16 + dx;
    py = mb_y * 16 + dy;
    ref_mb = ref_y * w + ref_x;
    func_0015F258(D_0030DDF4 + 0x4F0, *(s32 *)(D_0030DDF0 + 0x503C8) + ref_mb * 0x300, 0x600);
    while ((*(volatile u32 *)0x1000D000 >> 9) & 1) {
    }
    func_0015F258(D_0030DDF4 + 0xAF0, *(s32 *)(D_0030DDF0 + 0x503C8) + (ref_mb + *(s32 *)(D_0030DDF0 + 0x50514)) * 0x300, 0x600);
    if (px < 0 || px > *(s32 *)(D_0030DDF0 + 0x5051C) - 16 || py < 0 || py > *(s32 *)(D_0030DDF0 + 0x50520) - 16) {
        int mask[4];
        int i;

        while ((*(volatile u32 *)0x1000D000 >> 9) & 1) {
        }
        mask[0] = 0;
        mask[1] = 0;
        mask[2] = 0;
        mask[3] = 0;
        if (px < 0) {
            mask[0] = 1;
            mask[2] = 1;
        }
        if (py < 0) {
            mask[0] = 1;
            mask[1] = 1;
        }
        if (px < -15) {
            mask[1] = 1;
            mask[3] = 1;
        }
        if (py < -15) {
            mask[2] = 1;
            mask[3] = 1;
        }
        if (px > *(s32 *)(D_0030DDF0 + 0x5051C) - 16) {
            mask[1] = 1;
            mask[3] = 1;
        }
        if (py > *(s32 *)(D_0030DDF0 + 0x50520) - 16) {
            mask[2] = 1;
            mask[3] = 1;
        }
        if (px >= *(s32 *)(D_0030DDF0 + 0x5051C)) {
            mask[0] = 1;
            mask[2] = 1;
        }
        if (py >= *(s32 *)(D_0030DDF0 + 0x50520)) {
            mask[0] = 1;
            mask[1] = 1;
        }
        for (i = 0; i < 4; i++) {
            if (mask[i] != 0) {
                func_00170DC4((void *)(D_0030DDF4 + 0x4F0 + i * 0x300));
            }
        }
    }
}

typedef struct {
    u8 *blk[4];
    s32 w10;
    s32 w14;
    u8 pad18[0x58];
    u8 buf70[0x300];
    u8 buf370[1];
} MovWork2;

extern MovWork2 *_mov_D_0030DDF4 __asm__("D_0030DDF4");
void func_00170D4C(void *p);
void func_00170E14(void *p);
void func_00170BC4(void *p);
void func_0015F2C8(int a, int b, int c);

void func_0015F028(int a, int b, int c, int d)
{
    if (d == 2) {
        func_00170D4C(_mov_D_0030DDF4);
    }
    if (d == 3) {
        func_00170E14(_mov_D_0030DDF4->buf70);
    }
    if (d & 1) {
        b %= 16;
        c %= 16;
        if (b < 0) {
            b += 16;
        }
        if (c < 0) {
            c += 16;
        }
        _mov_D_0030DDF4->w10 = b;
        _mov_D_0030DDF4->w14 = c;
        func_00170BC4(_mov_D_0030DDF4);
    }
    func_0015F2C8(_mov_D_0030DDF0->w503CC + a * 0x180, (int)_mov_D_0030DDF4->buf370, 0x180);
}

void func_0015F140(u8 *dst, u8 *src, int alt)
{
    u8 *order;
    int i;

    if (alt == 0) {
        order = D_0030DD70;
    } else {
        order = D_0030DDB0;
    }
    for (i = 0; i < 64; i++) {
        dst[i] = src[order[i]];
    }
}

void func_0015F198(int addr, int size)
{
    if ((u32)addr > 0x6FFFFFFFU) {
        addr -= (int)0x80000000;
    }
    *(volatile int *)0x1000B410 = addr;
    *(volatile int *)0x1000B420 = size / 16;
    *(volatile int *)0x1000B400 = 0x101;
}

void func_0015F1F8(int addr, int size)
{
    if ((u32)addr > 0x6FFFFFFFU) {
        addr -= (int)0x80000000;
    }
    *(volatile int *)0x1000B010 = addr;
    *(volatile int *)0x1000B020 = size / 16;
    *(volatile int *)0x1000B000 = 0x100;
}

void func_0015F258(int a, int b, int c)
{
    *(volatile int *)0x1000E030 = 0xFF0000;
    *(volatile int *)0x1000E000 &= 0x7CF;
    *(volatile int *)0x1000D410 = b;
    *(volatile int *)0x1000D480 = a;
    *(volatile int *)0x1000D420 = c / 16;
    *(volatile int *)0x1000D400 = 0x101;
}

void func_0015F2C8(int a, int b, int c)
{
    *(volatile int *)0x1000E030 = 0xFF0000;
    *(volatile int *)0x1000E000 &= 0x7CF;
    *(volatile int *)0x1000D010 = a;
    *(volatile int *)0x1000D080 = b;
    *(volatile int *)0x1000D020 = c / 16;
    *(volatile int *)0x1000D000 = 0x100;
}

void func_0015F338(void)
{
    MovWork *w = (MovWork *)D_0030DDF4; /* DEBT(CAST): D_0030DDF4 is declared as an int. DEBT(ORDER): store order found by permutation */
    u8 *b = (u8 *)w;

    w->p60 = b + 0x70;
    w->p64 = b + 0x370;
    w->p68 = b + 0x4F0;
    w->q40 = 0x8000800080008000;
    w->blk[0] = b + 0x4F0;
    w->blk[1] = b + 0x7F0;
    w->blk[2] = b + 0xAF0;
    w->blk[3] = b + 0xDF0;
    w->q48 = 0x8000800080008000;
    w->q50 = 0x7F007F007F007F00;
    w->q58 = 0x7F007F007F007F00;
}

extern u8 D_00591EC8[];
extern u8 D_00591F08[];

void func_0015F3B8(void)
{
    func_002DA610(0, 0);
    func_002E25F8();
    func_0015FB30();
    func_0015F140(D_0030DDF0, D_00591EC8, 0);
    func_0015F140(D_0030DDF0 + 0x40, D_00591F08, 0);
    func_002F8660(0);
    func_0015F198((int)D_0030DDF0, 0x40);
    *(volatile int *)0x10002000 = 0x50000000;
    while (((*(volatile u32 *)0x1000B000 >> 8) & 1) != 0) {
    }
    while (*(volatile int *)0x10002010 < 0) {
    }
    func_0015F198((int)(D_0030DDF0 + 0x40), 0x40);
    *(volatile int *)0x10002000 = 0x58000000;
    while (((*(volatile u32 *)0x1000B000 >> 8) & 1) != 0) {
    }
    while (*(volatile int *)0x10002010 < 0) {
    }
}

typedef struct {
    u8 pad0[0x10080];
    u8 b10080[0x40];
    u8 b100C0[0x40];
    u8 pad10100[0x5053C - 0x10100];
    s32 w5053C;
    s32 w50540;
    s32 w50544;
    s32 w50548;
    s32 w5054C[5];
    u8 *p50560[5];
    s32 w50574[5];
    s32 w50588[5];
    u8 *p5059C;
    u8 pad505A0[0x506EC - 0x505A0];
    s32 w506EC;
    s32 w506F0;
    u8 pad506F4[0x50754 - 0x506F4];
    s32 w50754;
    s32 w50758;
    s8 b5075C;
    s8 b5075D;
    u8 pad5075E[6];
    s8 b50764;
} MovieStrOpen;

extern MovieStrOpen *_movopen_D_0030DDF0 __asm__("D_0030DDF0");
extern char D_0056B908[];
int func_0015B798(int a, int b, u8 *c, MovieStrOpen *s);
int func_206C550(int a, u8 *b, MovieStrOpen *s);
int movieOpenCd(MovieStrOpen *s);
int func_206C610(int a);

void func_0015F508(int a0, int a1)
{
    int i;
    int v;

    if (_movopen_D_0030DDF0->b5075C != 0) {
        if (_movopen_D_0030DDF0->b5075D == 0) {
            func_0015B798(_movopen_D_0030DDF0->w506EC, _movopen_D_0030DDF0->w506F0, _movopen_D_0030DDF0->b10080, _movopen_D_0030DDF0);
        } else {
            _movopen_D_0030DDF0->w50544 = movie_hdd_file_open(_movopen_D_0030DDF0->b50764, _movopen_D_0030DDF0->w506EC);
            if (_movopen_D_0030DDF0->w50544 < 0) {
                func_001577A8(D_0056B908, D_0056B848, 0x86D);
            }
            func_0015B798(_movopen_D_0030DDF0->w506EC, _movopen_D_0030DDF0->w506F0, _movopen_D_0030DDF0->b10080, _movopen_D_0030DDF0);
            ((int (*)(int))func_002FC768)(_movopen_D_0030DDF0->w50544); /* DEBT(TYPE): header declares void, compiled as returning int */
            _movopen_D_0030DDF0->w50544 = -1;
        }
    } else {
        func_206C550(a1, _movopen_D_0030DDF0->b10080, _movopen_D_0030DDF0);
    }
    func_002F8660(0);
    for (i = 0; i < 0x40; i++) {
        D_00591EC8[i] = _movopen_D_0030DDF0->b10080[i];
        D_00591F08[i] = _movopen_D_0030DDF0->b100C0[i];
    }
    func_002F8660(0);
    {
        register MovieStrOpen *p __asm__("$5") = _movopen_D_0030DDF0; /* DEBT(REG): pin to $a1 to match lw $a1 / move $a0,$a1 */
        if (p->b5075C != 0) {
            _movopen_D_0030DDF0->w50544 = movieOpenCd(p);
        } else {
            _movopen_D_0030DDF0->w50544 = func_206C610(a0);
        }
    }
    if (_movopen_D_0030DDF0->w50544 < 0) {
        while (1) {
            func_0015C808();
        }
    }
    v = func_0015FBA8(_movopen_D_0030DDF0->w5053C);
    func_0015C888(_movopen_D_0030DDF0->w50544, v, _movopen_D_0030DDF0->p50560[_movopen_D_0030DDF0->w5053C], &_movopen_D_0030DDF0->w50574[_movopen_D_0030DDF0->w5053C], (S58FE54 *)_movopen_D_0030DDF0);
    func_0015C928(_movopen_D_0030DDF0->w50544, 0, (S58FE54 *)_movopen_D_0030DDF0);
    _movopen_D_0030DDF0->w50588[_movopen_D_0030DDF0->w5053C] = 2;
    _movopen_D_0030DDF0->p5059C = _movopen_D_0030DDF0->p50560[_movopen_D_0030DDF0->w5053C];
    _movopen_D_0030DDF0->w5053C = (_movopen_D_0030DDF0->w5053C + 1) % _movopen_D_0030DDF0->w50754;
    _movopen_D_0030DDF0->w50588[_movopen_D_0030DDF0->w5053C] = 1;
    func_002F8660(0);
    v = func_0015FBA8(_movopen_D_0030DDF0->w5053C);
    if (_movopen_D_0030DDF0->w5054C[_movopen_D_0030DDF0->w5053C] != _movopen_D_0030DDF0->w50548) {
        func_0015C888(_movopen_D_0030DDF0->w50544, v, _movopen_D_0030DDF0->p50560[_movopen_D_0030DDF0->w5053C], &_movopen_D_0030DDF0->w50574[_movopen_D_0030DDF0->w5053C], (S58FE54 *)_movopen_D_0030DDF0);
    }
    _movopen_D_0030DDF0->w50540 = _movopen_D_0030DDF0->w5053C;
}

typedef struct {
    u8 pad0[0x50514];
    s32 w50514;
    s32 w50518;
    s32 w5051C;
    s32 w50520;
    s32 w50524;
    s32 w50528;
    s32 w5052C;
    s32 w50530;
    s32 w50534;
    s32 w50538;
    s32 w5053C;
    s32 w50540;
    s32 w50544;
    s32 w50548;
    s32 w5054C[5];
    u8 *p50560[5];
    s32 w50574[5];
    s32 w50588[5];
    u8 *p5059C;
    s32 w505A0;
    s8 b505A4;
    u8 pad505A5[3];
    s32 w505A8;
    s8 b505AC;
    u8 pad505AD[0x13];
    s32 w505C0;
    u8 pad505C4[0x100];
    s32 w506C4;
    s32 w506C8;
    s32 w506CC;
    s32 w506D0;
    s32 w506D4;
    s32 w506D8;
    s32 w506DC;
    s32 w506E0;
    u8 pad506E4[0x10];
    u8 *p506F4;
    s32 w506F8;
    s32 w506FC;
    u8 pad50700[8];
    s32 w50708;
    s32 w5070C;
    s32 w50710;
    s32 w50714;
    u8 pad50718[4];
    s32 w5071C;
    s32 w50720;
    s32 w50724;
    s32 w50728;
    u8 pad5072C[4];
    s32 w50730[8];
    s32 w50750;
    s32 w50754;
    s32 w50758;
    s8 b5075C;
    s8 b5075D;
    s8 b5075E;
    s8 b5075F;
    s8 b50760;
    s8 b50761;
    s8 b50762;
    s8 b50763;
    s8 b50764;
    s8 b50765;
    s8 b50766;
    s8 b50767;
    s8 b50768;
    s8 b50769;
    s8 b5076A;
    s8 b5076B;
    s8 b5076C;
    s8 b5076D;
    s8 b5076E;
    s8 b5076F;
    s8 b50770;
    s8 b50771;
    s8 b50772;
    s8 b50773;
    u8 pad50774[0xC];
    u8 buf50780[1];
} MovieStrInit;

extern MovieStrInit *_movinit_D_0030DDF0 __asm__("D_0030DDF0");

void func_0015F800(int buf, int w, int h, int flag)
{
    int i;

    _movinit_D_0030DDF0 = (MovieStrInit *)buf;
    if (w != 0 || h != 0) {
        _movinit_D_0030DDF0->w50514 = w / 16;
        _movinit_D_0030DDF0->w50518 = h / 16;
        _movinit_D_0030DDF0->w5051C = w;
        _movinit_D_0030DDF0->w50520 = h;
    }
    _movinit_D_0030DDF0->w50708 = 0xFFFF;
    _movinit_D_0030DDF0->w506D8 = 0x7F;
    _movinit_D_0030DDF0->w50524 = 0;
    _movinit_D_0030DDF0->w50534 = 0;
    _movinit_D_0030DDF0->w50528 = 0;
    _movinit_D_0030DDF0->w5052C = 0;
    _movinit_D_0030DDF0->w50530 = 0;
    _movinit_D_0030DDF0->w50538 = 0;
    _movinit_D_0030DDF0->w5053C = 0;
    _movinit_D_0030DDF0->w50540 = 0;
    _movinit_D_0030DDF0->w506CC = 0;
    _movinit_D_0030DDF0->w506D0 = 0;
    _movinit_D_0030DDF0->w506D4 = -1;
    _movinit_D_0030DDF0->w505A0 = 0;
    _movinit_D_0030DDF0->b505A4 = 0;
    _movinit_D_0030DDF0->w505A8 = 0;
    _movinit_D_0030DDF0->b505AC = 0;
    _movinit_D_0030DDF0->w505C0 = 2;
    _movinit_D_0030DDF0->w506C4 = 0;
    _movinit_D_0030DDF0->w506C8 = 0;
    _movinit_D_0030DDF0->w506DC = 0;
    _movinit_D_0030DDF0->w50544 = -1;
    _movinit_D_0030DDF0->b5075F = 0;
    _movinit_D_0030DDF0->b50760 = -1;
    _movinit_D_0030DDF0->b50761 = 0;
    _movinit_D_0030DDF0->w506E0 = 0;
    _movinit_D_0030DDF0->b50762 = 0;
    _movinit_D_0030DDF0->b50763 = 0;
    _movinit_D_0030DDF0->b50765 = 0;
    _movinit_D_0030DDF0->w50714 = 0;
    _movinit_D_0030DDF0->b50767 = 0;
    _movinit_D_0030DDF0->w5071C = 0;
    _movinit_D_0030DDF0->w5070C = 0;
    _movinit_D_0030DDF0->w50710 = 0;
    _movinit_D_0030DDF0->b5076A = 0;
    _movinit_D_0030DDF0->b5076B = 0;
    _movinit_D_0030DDF0->b50768 = 0;
    _movinit_D_0030DDF0->b50769 = 0;
    _movinit_D_0030DDF0->b50766 = 0;
    _movinit_D_0030DDF0->w50720 = 0;
    _movinit_D_0030DDF0->w50724 = -1;
    _movinit_D_0030DDF0->w50728 = -1;
    _movinit_D_0030DDF0->b5076F = 0;
    _movinit_D_0030DDF0->w50750 = 1;
    _movinit_D_0030DDF0->b50770 = 0;
    _movinit_D_0030DDF0->b50771 = 0;
    _movinit_D_0030DDF0->b50772 = 0;
    _movinit_D_0030DDF0->b50773 = 0;
    _movinit_D_0030DDF0->w50548 = 0;
    _movinit_D_0030DDF0->b5076D = 0;
    _movinit_D_0030DDF0->b5076E = 0;
    _movinit_D_0030DDF0->w50754 = 3;
    for (i = 0; i < 5; i++) {
        _movinit_D_0030DDF0->w50588[i] = 0;
        _movinit_D_0030DDF0->w50574[i] = 0;
        _movinit_D_0030DDF0->w5054C[i] = 0;
    }
    if (flag == 0) {
        _movinit_D_0030DDF0->w506F8 = 0xE3000;
        _movinit_D_0030DDF0->w506FC = 0xE4000;
    } else {
        _movinit_D_0030DDF0->w506F8 = 0xFF000;
        _movinit_D_0030DDF0->w506FC = 0x100000;
    }
    _movinit_D_0030DDF0->p50560[0] = _movinit_D_0030DDF0->buf50780;
    _movinit_D_0030DDF0->p50560[1] = _movinit_D_0030DDF0->p50560[0] + _movinit_D_0030DDF0->w506FC;
    _movinit_D_0030DDF0->p50560[2] = _movinit_D_0030DDF0->p50560[1] + _movinit_D_0030DDF0->w506FC;
    _movinit_D_0030DDF0->p506F4 = _movinit_D_0030DDF0->p50560[2] + _movinit_D_0030DDF0->w506FC;
    _movinit_D_0030DDF0->p50560[3] = (u8 *)0x800000;
    _movinit_D_0030DDF0->p50560[4] = (u8 *)0x800000 + _movinit_D_0030DDF0->w506FC;
    for (i = 7; i >= 0; i--) {
        _movinit_D_0030DDF0->w50730[i] = 0;
    }
    if (func_002D9868() == 0) {
        _movinit_D_0030DDF0->w50758 = 0x6400;
    } else {
        _movinit_D_0030DDF0->w50758 = 0x7800;
    }
}

void func_0015FB30(void)
{
    *(volatile int *)0x1000F590 = 0x10000;
    *(volatile int *)0x1000B000 &= 0xFFFFFEFF;
    *(volatile int *)0x1000F590 = 0;
    *(volatile int *)0x10002010 = 0x40000000;
    func_002E2528(0, 0);
    *(volatile int *)0x10002000 = 0;
    func_002E2528(0, 0);
}

int func_0015FBA8(int a)
{
    S58FE54 *s = (S58FE54 *)D_0030DDF0;
    int sum = 0;
    int v;
    int next;

    s->w5054C[a] = s->w50548;
    while (1) {
        v = s->w10100[s->w50548];
        if (v == 0) {
            return sum;
        }
        next = sum + v;
        if (next >= s->w506F8) {
            break;
        }
        sum = next;
        s->w50548++;
    }
    return sum;
}

/* DEBT(CAST): I/O work blocks are still passed to func_0015FCE8 as integer handles. */
void func_0015FC20(ScriptIoWork *work)
{
    D_0078E498.f10(work->handle);
    D_0078E498.f00(work->source, work->buffer, 0, 0);
    D_0078E498.f08(0);
    func_002F8660(0);
    func_0015FCE8((int)work, work->buffer);
}

void func_0015FCA8(int a) {
    func_0015FCE8(a, *(int *)(a + 0xF7160)); /* DEBT(CAST): table base is a raw address */
}

void func_0015FCB8(int a)
{
    *(volatile int *)0x1000B430 = a;
    *(volatile int *)0x1000B420 = 0;
    *(volatile int *)0x1000B400 = 0x105;
}

extern u8 D_0030DCF0[];
extern u8 D_0030DD30[];
void func_0015C098(void *a, void *b, int c, int d, int e, int f, int g, int h);
void func_0015C328(void *a, void *b, int c);
void func_0017135C(int a);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015FCE8);

void func_001600B8(void) {
    func_002DA610(0, 0);
    func_002E25F8();
    func_0015FB30();
}

void func_001600E0(u8 *arg)
{
    u8 *hdr = *(u8 **)(arg + 0x460F4);
    u32 ipu_ctrl;
    register u32 frame __asm__("$19");
    u8 *p;
    int w;
    int h;
    int size;

    hdr += *(s32 *)(hdr + 8);
    p = hdr + 0x20;
    w = *(u16 *)(hdr + 0xC);
    h = *(u16 *)(hdr + 0xE);
    size = ((w / 16) * (h / 16)) << 10;
    ipu_ctrl = *(u32 *)hdr;
    func_002E25F8();
    func_0015FB30();
    func_0015C098(arg + 0x40000, arg, 0x400, w, h, 0x3400, 0, 0);
    func_0015F140(D_00591EC8, D_0030DCF0, 0);
    func_0015F140(D_00591F08, D_0030DD30, 0);
    func_002F8660(0);
    *(s32 *)(arg + 0x460E8) = 0;
    *(s32 *)(arg + 0x460EC) = 0;
    while (1) {
        u8 *data;

        if (*(u32 *)(p + 8) == 0xFFFFFFFFU) {
            p = hdr + 0x20;
            *(s32 *)(arg + 0x460E8) = 0;
            *(u32 *)(arg + 0x460EC) |= 0x2000;
        }
        func_002F8660(0);
        data = p + 0x10;
        func_0015C328(arg + 0x46060, data, *(s32 *)(p + 4));
        *(volatile u32 *)0x10002010 = 0x40000000;
        func_002E2528(0, 0);
        *(volatile u32 *)0x10002000 = 0;
        func_002E2528(0, 0);
        func_0015FCB8((int)(arg + 0x46060));
        *(volatile u32 *)0x10002010 = ipu_ctrl | 0x1200000;
        frame = 0;
        if (*(u32 *)(p + 8) != 0) {
            do {
                *(volatile u32 *)0x10002000 = 0x10010000;
                frame++;
                func_0015F1F8((int)arg, size);
                func_0017135C(1);
                {
                    register u32 cond2 __asm__("$2") = (frame < *(u32 *)(p + 8));
                    if (cond2) {
                        *(volatile u32 *)0x10002000 = 0x40000020;
                    }
                }
                func_002DA610(0, 0);
                func_0015C068(arg + 0x40000);
                func_002DA610(0, 0);
                if (*(s8 *)(arg + 0x460FC) != 0) {
                    func_002DA610(0, 0);
                    *(s8 *)(arg + 0x460FC) = 0;
                    return;
                }
                {
                    register s32 cnt __asm__("$3") = *(s32 *)(arg + 0x460E8);
                    *(s32 *)(arg + 0x460F0) = 1;
                    *(s32 *)(arg + 0x460E8) = cnt + 1;
                }
                {
                    register u32 cond __asm__("$2") = (frame < *(u32 *)(p + 8));
                    if (!cond) {
                        break;
                    }
                }
            } while (1);
        }
        p = data + *(s32 *)(p + 4);
    }
}

int texanim_malloc_memory_get(int i) {
    return D_0078D898[i].w04;
}

void texanim_malloc_memory_set(int i, int v) {
    D_0078D898[i].w04 += v;
}

void func_001603E0(int a, int b) {
    switch (D_0078D898[b].b0D) {
    case 0:
        func_00162488(a, b);
        break;
    case 1:
        func_00160CB8(a, b);
        break;
    }
}

typedef struct {
    s8 b00;
    s8 b01;
    s8 b02;
} TexAnimHdr;

typedef struct {
    u8 pad00[0x20];
    TexAnimHdr *p20;
} ChrTexAnimArg;

typedef struct {
    TexAnimHdr *p00;
    s32 w04;
    s32 w08;
    s8 b0C;
    s8 b0D;
    s8 b0E;
    u8 pad0F[0x21];
} TexAnimSlot;

extern TexAnimSlot _texanim_D_0078D898[] __asm__("D_0078D898");
extern s8 D_00591F48;
extern s8 D_00591F49;
extern char D_0056B918[];
extern char D_0056B930[];
extern char D_0056B938[];
void func_00161B00(int i, int b, void *a);
void func_00160D30(int i, int b, void *a);

int chr_texanim_set(ChrTexAnimArg *a, int b)
{
    int i;
    TexAnimSlot *p = _texanim_D_0078D898;

    for (i = 0; i < 0x40; i++, p++) {
        if (p->p00 == 0) {
            TexAnimHdr *hdr;

            p->p00 = a->p20;
            hdr = a->p20;
            p->b0D = hdr->b02;
            p->b0C = hdr->b00;
            switch (hdr->b00) {
            case 1:
                D_00591F48 = 1;
                D_00591F49 = i;
                break;
            case 2:
                switch (p->b0D) {
                case 0:
                    func_00161B00(i, b, a);
                    break;
                case 1:
                    func_00160D30(i, b, a);
                    break;
                }
                break;
            }
            return i;
        }
    }
    if (i == 0x40) {
        func_001577A8(D_0056B918, D_0056B848, 0xAFE);
        return -1;
    }
    return -1;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00160520(s32 *arg0, s32 *arg1) {
    register s32 *a0_save __asm__("$9");
    register s32 hi __asm__("$2");
    register s32 *var_7 __asm__("$7");
    register s32 var_6 __asm__("$6");
    register s32 *end __asm__("$8");
    register s32 next __asm__("$3");
    s32 val;

    hi = 0x790000;
    __asm__ volatile("" : "+r"(hi));
    a0_save = arg0;
    __asm__ volatile("" : "+r"(a0_save));
    var_7 = (s32 *)(hi - 10088);
    var_6 = 0;
    __asm__ volatile("" : "+r"(var_7), "+r"(var_6));
    end = (s32 *)((u8 *)var_7 + 0xC00);
    __asm__ volatile("" : "+r"(end));
    do {
        val = *var_7;
        next = var_6 + 1;
        __asm__("" : "+r"(val), "+r"(next));
        if (val != 0) {
            var_6 = next;
        }
        var_7 = (s32 *)((u8 *)var_7 + 0x30);
    } while ((s32) var_7 < (s32) end);
    *a0_save = var_6;
    *arg1 = 0x40;
}

typedef union {
    struct {
        u8 pad0[0x460F4];
        void *p460F4;
        SaTaskGroup *t460F8;
        s8 b460FC;
    } s;
} ChrMovieBuf;

void chr_texanim_del(int i)
{
    ChrMovieBuf *p;

    if (i < 0) {
        func_001577A8(D_0056B930, D_0056B848, 0xB0F);
    }
    if (i >= 0x40) {
        func_001577A8(D_0056B938, D_0056B848, 0xB10);
    }
    switch (_texanim_D_0078D898[i].b0C) {
    case 1:
        p = (ChrMovieBuf *)_texanim_D_0078D898[i].w04;
        if (p != 0) {
            p->s.t460F8->leave();
            func_0011D590(_texanim_D_0078D898[i].w04, 0xA);
            _texanim_D_0078D898[i].w04 = 0;
            D_00591F48 = 0;
            D_00591F49 = -1;
        }
        break;
    case 2:
        if (_texanim_D_0078D898[i].w04 != 0) {
            func_0011D590(_texanim_D_0078D898[i].w04, 0xA);
            _texanim_D_0078D898[i].w04 = 0;
        }
        break;
    }
    _texanim_D_0078D898[i].w08 = 0;
    _texanim_D_0078D898[i].p00 = 0;
}

void func_0011C348(s32 a);
SaTaskGroup *sa_task_init(int n);

void chr_movie_main(int i)
{
    ChrMovieBuf *p = (ChrMovieBuf *)D_0078D898[i].w04;
    SaTaskGroup *t;
    ChrMovieBuf **r;

    if (p == 0) {
        func_0011C348(0x40);
        p = (ChrMovieBuf *)user_malloc(0x46100, 0xA, D_0056B848, 0xB2E);
        t = sa_task_init(1);
        p->s.t460F8 = t;
        p->s.p460F4 = D_0078D898[i].p00;
        r = (ChrMovieBuf **)t->call((int)func_001600E0, 1, 0);
        D_0078D898[i].w04 = (s32)p;
        *r = p;
        p->s.b460FC = 0;
    }
    p->s.t460F8->enter();
}
