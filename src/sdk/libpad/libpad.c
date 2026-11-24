/* tu_352 0x2ddb48-0x2deef0: low; libpad (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#define D_0078BC90 D_0078BC90_orig
#include "ffx/q7.h"
#undef D_0078BC90
#include "ffx/u5.h"

typedef struct SndSlotFull {
    SndVoice *v;
    s32 *p04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s32 w14;
    s32 w18;
} SndSlotFull;

extern SndSlotFull D_0078BC90[][4];

extern int D_00566344;
extern char D_00576A08[];
int func_002F8780(int id);
int func_002F87A0(void *dma, int n);

typedef struct PadDma {
    void *src;
    void *dst;
    int size;
    int attr;
} PadDma;

void func_002DDB48(int port, int slot)
{
    PadDma dma[16];
    s32 *p = D_0078BC90[port][slot].p04;
    void *dst;
    int cnt;
    int id;

    if (func_002F8780(D_0078BC90[port][slot].w0C) >= 0) {
        if (D_00566344 != 0) {
            func_002EF240(D_00576A08);
        }
        return;
    }
    cnt = p[0] + 1;
    dst = (void *)(D_0078BC90[port][slot].w08 + ((cnt & 1) << 5));
    p[0] = cnt;
    func_002F8C30((SndVoice *)p, (SndVoice *)(p + 8));
    dma[0].dst = dst;
    dma[0].src = p;
    dma[0].size = 0x20;
    dma[0].attr = 0;
    id = func_002F87A0(dma, 1);
    if (id == 0) {
        if (D_00566344 != 0) {
            func_002EF240(D_00576A08);
        }
    }
    D_0078BC90[port][slot].w0C = id;
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDC78);

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002DDDB8(void) {
    register void *sp __asm__("$29");
    register void *d __asm__("$6");
    s32 var_3;
    void *var_2;

    __asm__("" : "=r"(d) : "r"(sp));
    __asm__("" : "+r"(d));
    var_2 = (void *)D_0078BC90;
    __asm__("" : "+r"(var_2), "=r"(var_3) : "r"(d));
    var_2 += 0x84;
    var_3 = 3;
    do {
        (*(s32 *)((u8 *)(var_2) + (-0x74))) = 0;
        var_3 -= 1;
        (*(s32 *)((u8 *)(var_2) + (-0x6C))) = 0;
        (*(s32 *)((u8 *)(var_2) + (-0x70))) = 0;
        (*(s32 *)((u8 *)(var_2) + (-4))) = 0;
        (*(s32 *)((u8 *)(var_2) + (4))) = 0;
        (*(s32 *)((u8 *)(var_2) + (0))) = 0;
        var_2 += 0x1C;
    } while (var_3 >= 0);
    (*(s32 *)((u8 *)(D_0078BF80) + (0))) = 0x10;
    (*(s32 *)((u8 *)(D_0078BF80) + (0x10))) = 0;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return (*(s32 *)((u8 *)(D_0078BF80) + (0xC)));
}

extern s32 D_00566340;

/* DEBT(CAST) */
s32 func_002DDE58(void) {
    s32 a3;

    (*(s32 *)((u8 *)(D_0078BF80) + (0))) = 0xF;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    a3 = (*(s32 *)((u8 *)(D_0078BF80) + (0xC)));
    if (a3 == 1) {
        D_00566340 = 0;
    }
    return a3;
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDED8);

int func_002DE0C0(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    D_0078BF80[0] = 0xE;
    D_0078BF80[1] = a;
    D_0078BF80[2] = b;
    D_0078BF80[4] = 1;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    D_0078BC90[a][b].w10 = 0;
    return D_0078BF80[3];
}

SndHalf *func_002DE178(int a, int b)
{
    SndVoice *v = D_0078BC90[a][b].v;
    int i;

    func_002F8C30(v, v + 1);
    i = v->h[0].w58 < v->h[1].w58;
    return &v->h[i];
}

int func_002DE1D8(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DE178(a, b)->w58;
}

/* DEBT(CAST): SndHalf layout incomplete */
#define HB(p, o) (*((u8 *)(p) + (o)))
int func_002DE228(int a, int b, void *dst)
{
    SndHalf *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    h = func_002DE178(a, b);
    func_002EEF1C(dst, h, *(int *)&HB(h, 0x60));
    return *(int *)&HB(h, 0x60);
}

int func_002DE2A8(int a, int b)
{
    SndHalf *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 99;
    }
    h = func_002DE178(a, b);
    if (HB(h, 0x70) == 6 && h->b71 == 2) {
        return 5;
    }
    return HB(h, 0x70);
}

void func_002DE320(unsigned int i, char *dst)
{
    if (i < 8) {
        func_002F072C(dst, D_00566348[i]);
    } else {
        *dst = D_00576B28;
    }
}

int func_002DE358(int a, int b, int c)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    func_002DE178(a, b)->b71 = c;
    return 1;
}

int func_002DE3C0(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DE178(a, b)->b71;
}

void func_002DE410(unsigned int i, char *dst)
{
    if (i < 4) {
        func_002F072C(dst, D_00566368[i]);
    } else {
        *dst = D_00576B28;
    }
}

typedef struct SndHalfFull {
    u8 pad00[0x30];
    u8 f30[4][4];
    u8 f40[4][4];
    u16 h50[4];
    s32 w58;
    u8 pad5C[8];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 pad67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
    u8 pad6C[4];
    u8 b70;
    u8 b71;
    u8 b72;
    u8 pad73[6];
    u8 b79;
    u8 b7A;
    u8 b7B;
    u8 b7C;
} SndHalfFull;

s32 func_002DE448(s32 a, s32 b, s32 c, s32 d)
{
    SndHalfFull *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    h = (SndHalfFull *)func_002DE178(a, b);
    if (h->b72 != 1) {
        return 0;
    }
    if (h->b64 < 2) {
        return 0;
    }
    if (!(c < h->b6A)) {
        return 0;
    }
    if (c == -1) {
        return h->b6A;
    }
    switch (d) {
    case 1:
        return h->f30[c][0];
    case 2:
        return h->f30[c][1];
    case 3:
        return h->f30[c][2];
    case 4:
        return h->f30[c][3];
    }
    return 0;
}

int func_002DE568(int a, int b, int c, int d)
{
    SndHalfFull *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    h = (SndHalfFull *)func_002DE178(a, b);
    if (h->b72 != 1) {
        return 0;
    }
    if (h->b64 < 2) {
        return 0;
    }
    if (c == -1) {
        return h->b6B;
    }
    if (!(c < h->b6B)) {
        return 0;
    }
    switch (d) {
    case -1:
        return h->f40[c][0];
    case 0:
        return h->f40[c][1];
    case 1:
        return h->f40[c][2];
    case 2:
        return h->f40[c][3];
    }
    return 0;
}

int func_002DE688(int a, int b, int c, int d)
{
    SndHalfFull *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    h = (SndHalfFull *)func_002DE178(a, b);
    if (h->b72 != 1) {
        return 0;
    }
    if (h->b71 == 2) {
        return 0;
    }
    switch (c) {
    case 1:
        if (h->b65 == 0xF3) {
            return 0;
        }
        return h->b65 >> 4;
    case 2:
        if (h->b64 == 1) {
            return 0;
        }
        return h->h50[h->b69];
    case 3:
        if (h->b64 == 1) {
            return 0;
        }
        return h->b69;
    case 4:
        if (h->b64 == 1) {
            return 0;
        }
        if (d == -1) {
            return h->b68;
        }
        if (d < h->b68) {
            return h->h50[d];
        }
        return 0;
    }
    return 0;
}

int func_002DE7C0(int a, int b, int c, int d)
{
    D_0078BF80[3] = c;
    D_0078BF80[4] = d;
    D_0078BF80[0] = 6;
    D_0078BF80[1] = a;
    D_0078BF80[2] = b;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[5] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[5];
}

int func_002DE878(int a, int b, u8 *src)
{
    s32 *p;
    u8 *dst;
    int i;

    if (((SndHalfFull *)func_002DE178(a, b))->b72 != 1) {
        return 0;
    }
    p = D_0078BC90[a][b].p04;
    dst = (u8 *)&p[3];
    for (i = 0; i < 6; i++) {
        dst[i] = src[i];
    }
    p[2] = 6;
    p[1] = 1;
    func_002DDB48(a, b);
    return 1;
}

int func_002DE930(int a, int b, u8 *src)
{
    int *buf = D_0078BF80;
    u8 *dst;
    int i;

    buf[0] = 8;
    buf[1] = a;
    buf[2] = b;
    dst = (u8 *)&buf[3]; /* DEBT(CAST): request words 3.. hold a 6-byte block */
    for (i = 0; i < 6; i++) {
        dst[i] = src[i];
    }
    if (func_002FB4C8(D_0078BC40, 1, 0, buf, 0x80, buf, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (buf[5] == 1) {
        func_002DE358(a, b, 2);
    }
    return buf[5];
}

int func_002DEA08(int a, int b)
{
    SndHalf *h;

    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    h = func_002DE178(a, b);
    if (HB(h, 0x72) != 1) {
        return 0;
    }
    if (HB(h, 0x64) < 2) {
        return 0;
    }
    if (HB(h, 0x66) < 2) {
        return 0;
    }
    return HB(h, 0x79) + ((u64)HB(h, 0x7A) << 8) + ((u64)HB(h, 0x7B) << 16) + ((u64)HB(h, 0x7C) << 24);
}

int func_002DEAC0(int a, int b, int c)
{
    D_0078BF80[3] = c;
    D_0078BF80[0] = 0xA;
    D_0078BF80[1] = a;
    D_0078BF80[2] = b;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[4] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[4];
}

int func_002DEB70(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEA08(a, b) == 0x3FFFF;
}

int func_002DEBD0(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEAC0(a, b, 0xFFF);
}

int func_002DEC28(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEAC0(a, b, 0);
}

int func_002DEC80(int a, int b, U5Blk12 *src)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0xB;
    D_0078BF80[2] = b;
    *(U5Blk12 *)&D_0078BF80[3] = *src; /* DEBT(CAST): request words 3..5 hold a 12-byte block */
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[7] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[7];
}

int func_002DED50(void)
{
    D_0078BF80[0] = 0xC;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEDB8(int a)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0xD;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEE20(void)
{
    D_0078BF80[0] = 0x12;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEE88(int a)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0x14;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[2];
}
