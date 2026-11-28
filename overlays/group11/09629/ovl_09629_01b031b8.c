#include "common.h"

typedef struct { u16 a, b, c, d; } Entry8;

extern u8 D_01B03100[];
extern u8 D_01B00A20[];
extern Entry8 D_01B00620[];
extern void func_01B0D050(void *);
extern void func_01B0D458(void *);
extern void func_002698C0(u32);

static __inline__ void call_d050(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; func_01B0D050(m); }
static __inline__ void call_d458(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B0D458(m); }

void func_01B031B8(u8 *s0, int s1)
{
    call_d050(s0, D_01B03100, s0);
    call_d458(D_01B00A20, s0);
    func_002698C0(D_01B00620[s1].a);
    *(int *)(s0 + 0x3C) = s1;
    *(int *)(s0 + 0x18) = 0;
}
