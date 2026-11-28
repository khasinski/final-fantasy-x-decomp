#include "common.h"

extern void func_01B0D7B0(void *);
extern void func_01B0D6B8(void *);
extern void func_01B0E8E8(void *);
extern void func_01B0E840(void *);
extern void func_01B119A8(void *);
extern void func_01B11980(void *);

typedef struct {
    void *unk00;
    u8 *unk04;
} Arg8488;

void func_01B08488(Arg8488 *a0) {
    u8 *s3 = a0->unk04;
    void *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7;

    if (*(s32 *)(s3 + 0x18) == 0 && (*(s32 *)(s3 + 0x2B8) & 4)) {
        u8 *s0 = s3 + 0x170;
        u8 *s1 = s3 + 0x1A0;
        u8 *s2 = s3 + 0x20;

        p0 = s0;
        func_01B0D7B0(&p0);
        p1 = s0;
        func_01B0D6B8(&p1);
        p2 = s1;
        func_01B0D7B0(&p2);
        p3 = s1;
        func_01B0D6B8(&p3);
        p4 = s2;
        func_01B0E8E8(&p4);
        p5 = s2;
        func_01B0E840(&p5);
        p6 = a0->unk00;
        func_01B119A8(&p6);
        p7 = a0->unk00;
        func_01B11980(&p7);
        *(s32 *)(s3 + 0x18) = 20000;
    }
}
