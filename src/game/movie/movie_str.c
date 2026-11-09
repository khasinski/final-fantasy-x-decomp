/* tu_105 0x15c5a8-0x160780: low; movie_str (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

void func_0015C5A8(int v) {
    D_0030DDF4 = v;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015C5B8);

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
    s8 b505C4;
    u8 pad505C5[0x50644 - 0x505C5];
    s8 b50644;
    u8 pad50645[0x506E4 - 0x50645];
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

int func_0015C718(int a, int b, int c, int d, int e, int f)
{
    if (f == 0) {
        func_0015F800(e, 0x200, 0x1A0, 0);
    } else {
        func_0015F800(e, 0x280, 0x1C0, f);
    }
    audioInit(e);
    _mov_D_0030DDF0->b5075C = 1;
    _mov_D_0030DDF0->b505C4 = 0;
    _mov_D_0030DDF0->b50644 = 0;
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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015D730);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015D940);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015DE90);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015E1D0);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015E910);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015ED58);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F028);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F508);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F800);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015FCE8);

void func_001600B8(void) {
    func_002DA610(0, 0);
    func_002E25F8();
    func_0015FB30();
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_001600E0);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", chr_texanim_set);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", chr_texanim_del);

typedef union {
    struct {
        u8 pad0[0x460F4];
        void *p460F4;
        SaTaskGroup *t460F8;
        s8 b460FC;
    } s;
} ChrMovieBuf;

void func_0011C348(s32 a);
SaTaskGroup *sa_task_init(int n);
void func_001600E0(void);

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
