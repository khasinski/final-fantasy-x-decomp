/* tu_104 0x15bbf8-0x15c5a8: low; ~set (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015BBF8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_15BBF8", func_0015BF00);

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0015BF50(void *arg0, s64 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    register s64 v0 __asm__("$2");
    register s32 a3 __asm__("$7");
    register s32 t1 __asm__("$9");

    (*(s32 *)((u8 *)(arg0) + (0xC))) = (s32)(arg1 >> 0x20);
    t1 = (arg5 << 0xE) | (arg2 << 0x1C);
    a3 = (arg3 << 0x1A) | (arg4 << 0xF);
    t1 |= a3;
    (*(s32 *)((u8 *)(arg0) + (4))) = t1;
    v0 = arg1 & 0xFFFFFFFFULL;
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32)v0;
    (*(s32 *)((u8 *)(arg0) + (0))) = (arg6 << 0xF) | arg7;
}

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
