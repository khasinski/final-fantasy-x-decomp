/* tu_333 0x2ceff0-0x2d0af0: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: bitfield/size helpers and wrappers (see w10.h). */
#define func_002CF8D0 _hdr_func_002CF8D0
#define func_002D0940 _hdr_func_002D0940
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r7.h"
#undef func_002D0940
#undef func_002CF8D0

void func_002CEFF0(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        D_00764430.c[i] = 0;
        D_00764430.a[i] = 0;
        D_00764430.b[i] = 0;
        D_00764740.w10[i] = 0;
    }
    D_00764740.h00 = 0;
    D_00764430.h300 = 0;
    D_00764430.h302 = 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF040);

void func_002CF1D0(s16 *values, int destination)
{
    func_002DAB10(D_006F2EE0, values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DADD0(D_006F2EE0, destination);
    func_002DA610(0, 0);
    func_002F8660(0);
}

typedef struct OpTim2Pic {
    u32 totalSize;
    u32 clutSize;
    u32 imageSize;
    u16 headerSize;
    u16 clutColors;
    u8 picFormat;
    u8 mipMaps;
    u8 clutType;
    u8 imageType;
    s16 width;
    s16 height;
    u16 gsTex0Lo;
    u16 gsTex0Mid;
    u32 gsTex0Hi;
    u64 gsTex1;
    u8 b28;
    u8 b29;
    u8 b2A;
    u8 b2B;
    u32 gsTexClut;
} OpTim2Pic;

typedef struct OpTim2 {
    u8 fileHdr[0xF];
    u8 bF;
    OpTim2Pic pic;
    u8 data[1];
} OpTim2;

extern u8 D_004F4600[];
void func_002DA928(void *buf, int tbp, int bw, int psm, int x, int y, int w, int h);
void func_002DAC50(void *dst, void *src);

void func_002CF258(OpTim2 *tim2)
{
    u_long128 li1[6];
    u_long128 li2[6];
    OpTim2Pic *pic = &tim2->pic;
    u8 *data;
    int bw;

    if (pic->imageSize != 0) {
        int psm = D_004F4600[pic->imageType];
        int tbp = pic->gsTex0Lo & 0x3FFF;

        tim2->bF = 0x6F;
        data = tim2->data;
        bw = pic->b28;
        func_002DA928(li1, tbp, bw / 4, psm,
                      pic->b2A << 4, pic->b2B << 4, pic->width, pic->height);
        /* DEBT(FAKE): keep tim2 live across call so it is allocated to $s0 */
        __asm__("" : : "r"(tim2));
        func_002DA610(0, 0);
        func_002F8660(0);
        func_002DAC50(li1, data);
    }
    if (pic->clutSize != 0) {
        func_002DA928(li2, (pic->gsTex0Hi >> 5) & 0x3FFF, 1, D_004F4600[pic->clutType],
                      0, 0, 0x10, (s16)(pic->clutSize / 64));
        func_002DA610(0, 0);
        func_002F8660(0);
        func_002DAC50(li2, data + pic->imageSize);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF388);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", op_oef2_texture_load);

typedef struct Oef2Clut {
    u16 h0;
    u16 h2;
    int w4;
    u8 b8;
    u8 b9;
} Oef2Clut;

extern char D_00575FB0[];
void func_002EA328(int) __attribute__((noreturn));
void func_002CF388(int, int, int, int);

void op_oef2_clut_load(Oef2Clut *p, int a)
{
    if (p->w4 == 0) {
        func_00120108(D_00575FB0);
        func_002EA328(1);
    }
    func_002CF388(p->w4, p->b9, p->h0, a);
}

int func_002CF850(W10SoundVoice *voice, int value)
{
    u32 word;
    int previous;
    word = voice->header.word;
    previous = voice->header.half[0] & 0x3FFF;
    voice->active = 1;
    voice->header.word = (word & 0xFFFFC000) | (value & 0x3FFF);
    return previous;
}

int func_002CF880(W10SoundVoice *voice, int value)
{
    int v = (value & 0x3FFF) + (voice->header.half[0] & 0xFC);

    voice->active = 1;
    voice->header.word = (voice->header.word & 0xFFFFC000) | v;
    return v;
}

/* DEBT(CAST) */
u16 func_002CF8B8(void *arg0, s32 arg1) {
    u16 temp_2;

    temp_2 = (*(u16 *)((u8 *)(arg0) + (0)));
    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (arg1 & 0x3FFF);
    (*(s8 *)((u8 *)(arg0) + (0xF))) = 1;
    return temp_2;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002CF8D0(void *arg0, s32 arg1) {
    register s32 _ret_v0 __asm__("$2");
    register u16 temp_5 __asm__("$5");

    __asm__ volatile("" : : : "memory");
    (*(s8 *)((u8 *)(arg0) + (0xF))) = 1;
    temp_5 = (arg1 & 0x3FFF) + ((*(u16 *)((u8 *)(arg0) + (0))) & 0x3C);
    _ret_v0 = temp_5;
    __asm__ volatile("" : "+r"(_ret_v0));
    (*(u16 *)((u8 *)(arg0) + (0))) = temp_5;
    return _ret_v0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF8F8);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFA20);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFC70);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFE38);

typedef struct Oef2Tex {
    u32 w0;
    u8 pad4[0xC];
    int w10;
    int w14;
} Oef2Tex;

typedef struct Oef2Hdr {
    u64 pad0[8];
    u16 h40;
    u16 h42;
    u16 h44;
    u16 h46;
} Oef2Hdr;

int func_002CFE38(void *p, int mask, int kind);
void op_oef2_texture_load(void *p, int a);

int func_002D0180(void *p, int mask);
int func_002D0238(void *p, int mask);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0180);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0238);

int func_002D02E8(Oef2Hdr *p, u16 start, u16 end, int mask)
{
    u16 end1;
    u16 end2;
    int i;

    if (p->h44 == 0 && p->h46 == 0) {
        return 0;
    }
    end1 = end + 1;
    end2 = end + 1;
    if (end1 >= p->h44) {
        end1 = p->h44;
    }
    if (end2 >= p->h46) {
        end2 = p->h46;
    }
    for (i = start; i < end1; i++) {
        func_002D0180(op_oef2_a_get((int)p, 2, i), mask);
    }
    for (i = start; i < end2; i++) {
        func_002D0238(op_oef2_a_get((int)p, 3, i), mask);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0408);

int func_002D0570(int mask)
{
    EvQueue *q = &D_00764430;
    u16 cnt = q->h302;
    u16 base = q->h300;
    u16 i;

    for (i = 0; i < cnt; i++) {
        if (q->c[(u16)((base + i) % 64)] & mask) {
            return -1;
        }
    }
    return 0;
}

typedef struct EvSlotsFull {
    u16 h00;
    u8 pad02[0xE];
    u32 w10[64];
    u8 b110[64];
    void *p150[64];
} EvSlotsFull;

void op_oef2_texture_load(void *p, int a);

void func_002D05F0(int a)
{
    EvQueue *q = &D_00764430;
    int i;
    u32 *pb = q->b;
    u32 *pa = q->a;
    u32 *pc = q->c;

    for (i = 0; i < 64; i++, pa++, pb++, pc++) {
        u32 va = *pa;
        u32 vb = *pb;

        if (va != 0) {
            op_oef2_texture_load((void *)va, 1);
        }
        if (vb != 0) {
            op_oef2_clut_load((Oef2Clut *)vb, 1);
        }
        *pa = 0;
        *pb = 0;
        *pc = 0;
    }
    q->h300 = 0;
    q->h302 = 0;
}

void func_002D0698(u32 mask)
{
    if (D_00703FF6 != 0) {
        EvSlotsFull *d = (EvSlotsFull *)&D_00764740;
        int i;

        if (d->h00 != 0) {
            for (i = 0; i < d->h00; i++) {
                if (d->w10[i] & mask) {
                    if (d->b110[i] == 0) {
                        op_oef2_texture_load(d->p150[i], 1);
                    } else {
                        op_oef2_clut_load((Oef2Clut *)d->p150[i], 1);
                    }
                }
            }
        }
    }
}

void op_oef2_tex_clut_ovl_clear(u32 mask)
{
    EvSlots *d = &D_00764740;
    int last = -1;
    int i;

    for (i = 0; i < 64; i++) {
        if (d->w10[i] != 0) {
            if (d->w10[i] & mask) {
                d->w10[i] = 0;
            } else {
                last = i;
            }
        }
    }
    d->h00 = last + 1;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D07A0);

void func_002D0910(u_long128 *d, u_long128 *s)
{
    d[0] = s[0];
    d[1] = s[1];
}

void func_002D0928(u_long128 *d, u_long128 *s)
{
    d[0] = s[0];
}

void func_002D0938(void) {
}

void _m2c_func_002D0940_op_oef2_clut_load(int *p, int a) __asm__("op_oef2_clut_load");
void _m2c_func_002D0940_op_oef2_texture_load(int *p, int a) __asm__("op_oef2_texture_load");
extern s32 _m2c_func_002D0940_D_00518D40 __asm__("D_00518D40");
extern s32 _m2c_func_002D0940_D_00703FF3 __asm__("D_00703FF3");
void func_002D0940(void) {
    s32 var_16;
    s32 base;

    if ((u8) _m2c_func_002D0940_D_00703FF3 != 0) {
        var_16 = 0;
        base = (s32) &_m2c_func_002D0940_D_00518D40;
        op_oef2_set2((void *)base);
        do {
            _m2c_func_002D0940_op_oef2_texture_load(op_oef2_a_get(base, 2, var_16), 1);
            _m2c_func_002D0940_op_oef2_clut_load(op_oef2_a_get(base, 3, var_16), 1);
            var_16 += 1;
        } while (var_16 < 6);
    }
}

void func_002D09D0(u8 a) {
    D_00703FF6 = a;
}

typedef struct HandlePoolTex {
    u8 pad0[0x60];
    s8 b60[8];
    u8 pad68[0x18];
    void *tex[8][2];
    Oef2Clut *clut[8][2];
} HandlePoolTex;

extern u8 D_00703FF3;

void func_002D09E0(void)
{
    int i;
    int j;

    if (D_00703FF3 != 0) {
        HandlePoolTex *pool = (HandlePoolTex *)&D_00703E20;

        for (i = 0; i < 8; i++) {
            if (pool->b60[i] != 0) {
                for (j = 0; j < 2; j++) {
                    if (pool->tex[i][j] != 0) {
                        op_oef2_texture_load(pool->tex[i][j], 1);
                    }
                    if (pool->clut[i][j] != 0) {
                        op_oef2_clut_load(pool->clut[i][j], 1);
                    }
                }
            }
        }
    }
}

void func_002D0AD0(void)
{
    op_gs1_transfer();
    func_002D05F0(0xFFFF);
}
