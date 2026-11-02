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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015C718);

void func_0015C808(void) {
    func_0017135C(1);
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015C810);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015C9F0);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", mpegstrendsub);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015D730);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015D940);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", print_sound_debug_info);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", movie_csc);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015DDB8);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F198);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F1F8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F258);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F2C8);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F3B8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F508);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015F800);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015FB30);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015FBA8);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_0015FCB8);

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

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", func_00160520);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", chr_texanim_del);

INCLUDE_ASM("build/ee_asm/game/movie/movie_str", chr_movie_main);
