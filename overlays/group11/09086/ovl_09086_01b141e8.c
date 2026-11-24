#include "common.h"

typedef struct {
    u32 flags;      /* 0x00 */
    u32 f04;        /* 0x04 */
    u32 off08;      /* 0x08 */
    u32 off0C;      /* 0x0C */
    u8 pad10[0x06]; /* 0x10 */
    u16 h16;        /* 0x16 */
} MdHdr141E8;

typedef struct {
    u8 pad00[0x1C];
    u8 *p1C;
    MdHdr141E8 *p20;
    u32 f24;
} Node141E8;

typedef struct {
    Node141E8 *node;
    u8 flags;
} Msg141E8;

typedef struct {
    u32 f00;   /* 0x50 */
    u32 f04;   /* 0x54 */
    u16 f08;   /* 0x58 */
    u16 pad0A; /* 0x5A */
    u32 f0C;   /* 0x5C */
    unsigned long f10; /* 0x60 */
    u32 f18;   /* 0x68 */
    u32 f1C;   /* 0x6C */
    void *f20; /* 0x70 */
    void *f24; /* 0x74 */
    void *f28; /* 0x78 */
    void *f2C; /* 0x7C */
    u32 f30;   /* 0x80 */
    void *f34; /* 0x84 */
    void *f38; /* 0x88 */
    void *f3C; /* 0x8C */
    u32 f40;   /* 0x90 */
    u32 f44;   /* 0x94 */
    u8 pad48[0x28]; /* 0x98..0xC0 */
} DrawParam141E8;

extern void *D_01B00048;
extern u8 D_01B00AC0[];
extern u32 D_00303550;
extern void func_01B14520(Msg141E8 *);
extern void func_002DCE38(void *, void *, void *);
extern void *op1_md_draw(MdHdr141E8 *, DrawParam141E8 *);

void func_01B141E8(register Msg141E8 *s0)
{
    func_01B14520(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        u8 mat[0x40];
        MdHdr141E8 *p;
        DrawParam141E8 dp;

        p = s0->node->p20;
        if (p->flags & 1) {
            dp.f00 = 0x80;
        } else {
            dp.f00 = 0;
        }
        if (!(p->flags & 2)) {
            dp.f00 |= 0x10;
        }
        dp.f08 = *(u16 *)((u8 *)p + 0x16);
        dp.f1C = 0;
        dp.f38 = (u8 *)p + p->off08;
        dp.f3C = (u8 *)p + p->off0C;
        dp.f04 = D_00303550;
        dp.f0C = 0;
        dp.f10 = 0;
        dp.f18 = *(u32 *)((u8 *)s0->node + 0x24);
        dp.f40 = 0;
        func_002DCE38(mat, D_01B00AC0, s0->node->p1C + 0xA0);
        dp.f20 = mat;
        dp.f44 = 0;
        dp.f24 = mat;
        dp.f28 = mat;
        dp.f2C = mat;
        dp.f34 = D_01B00048;
        D_01B00048 = op1_md_draw(p, &dp);
    }
}
