/* tu_104 0x15bbf8-0x15c5a8: low; ~set (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015BBF8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015BF00);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015BF50);

void func_0015BFA0(int *p, int a, long b) {
    p[2] = a;
    p[3] = 0;
    p[1] = (int)(b >> 32);
    p[0] = (int)(b & 0xFFFFFFFF);
}

/* DEBT(ORDER): bitfield terms are grouped to preserve the original instruction order. */
void func_0015BFD0(int *packet, u32 b, u32 c, u32 d, int flag)
{
    u64 bits;
    if (flag == 0) {
        bits = (((u64)d << 24) | ((u64)c << 48)) | (((u64)b << 32) | ((u64)d << 56));
    } else {
        bits = ((u64)d << 56) | ((u64)c << 48) | ((u64)b << 32);
    }
    func_0015BFA0(packet, 0x50, bits);
}

void func_0015C020(int *p, u32 b, u32 c, u32 d) {
    func_0015BFA0(p, 0x51, ((u64)b << 59) | ((u64)d << 48) | ((u64)c << 32));
}

void func_0015C040(int *p, u32 b, u32 c) {
    func_0015BFA0(p, 0x52, ((u64)c << 32) | b);
}

void func_0015C058(int *p, u32 b) {
    func_0015BFA0(p, 0x53, b);
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015C068);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015C098);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015C328);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", setLoadImageTagsTexAnim);

void func_0015C560(u64 *p, u32 a, u32 b, u32 c)
{
    *p = ((u64)a << 32) | ((u64)b << 28) | c;
}

void func_0015C588(int *p, int v) {
    p[0] = v | 0x10000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}
