#include "common.h"

typedef struct Task9392 {
    u8 pad00[0x18];
    u8 b18;
} Task9392;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9392;

typedef struct Slot9392 {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    union {
        u_long128 q;
        struct {
            float x;
            float y;
            float z;
            float w;
        } v;
    } pos;
    u8 padE0[0x24];
    void (*p104)(struct Slot9392 *);
    u8 pad108[0x18];
    int w120;
    u8 pad124[0xC];
} Slot9392;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[0xDE];
} SubD330_9392;

typedef struct {
    u8 pad00[0x4];
    int w04;
    float f08;
    int w0C;
    int w10;
    float f14;
    int w18;
    u8 pad1C[0x8];
    int w24;
    u8 pad28[0x4];
    u16 h2C;
    u8 pad2E[0x3A];
} SubD4A8_9392;

typedef struct {
    u8 pad000[0x80];
    float f80;
    int w84;
    u8 pad088[0x138];
    u8 sub1C0[0x10];
    u8 sub1D0[0x10];
    u8 sub1E0[0x40];
    u8 sub220[0x10];
    u8 sub230[0x10];
    u8 sub240[0x10];
    u8 sub250[0x20];
} SubD590_9392;

typedef struct {
    Slot9392 slots[11];
    int wD10;
    float fD14;
    int wD18;
    int wD1C;
    u_long128 qD20;
    u8 subD30[0xC600];
    SubD330_9392 subD330;
    SubD4A8_9392 subD4A8;
    u8 subD510[0x40];
    u8 subD550[0x40];
    SubD590_9392 subD590;
    float fD800;
    int wD804;
    int wD808;
    int wD80C;
} Obj9392;

extern u8 D_01BCFA80[];
extern u8 D_01B00040[];
extern int D_01B006A8[];
extern int D_01B006C0[];
extern u8 D_01B006D8[];
extern int D_01B09840;
extern Ctrl9392 D_01B09848;
extern u8 *D_01B09888;
extern u8 *D_01B0988C;
extern u8 D_01B09890[];
extern u8 D_01B098F0[];
extern int D_01B09904;
extern Obj9392 *D_01B09910;
extern u8 *D_01B09914;
extern u8 D_01B0F3B0[];

extern int func_002B49A0(void *, int, int);
extern void func_01B05B00(void *, void *, void *, int);
extern void func_01B08AB8(void *, void *);
extern void func_01B050E8(int);
extern Task9392 *func_01B05878(void *);
extern void func_01B05A40(Task9392 *);
extern void func_01B09260(void *);
extern int func_01B08AD8(void *);
extern int func_01B04D58(void *);
extern void func_01B058F8(void *);
extern int func_01B05CB8(void *, void *);
extern void func_001CDDD8(int);
extern void func_01B04268(int);
extern float func_01B03190(int);
extern void func_01B032B8(int, void *, int);
extern void func_01B09408(void *);
extern int func_01B03100(int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);
extern void func_002A7308(void *, int, int, int);
extern void func_01B05BD8(void *, void *, int, int, int, int, float);
extern void func_01B094C8(void *, int, void *, int);
extern void func_01B09028(void *, int, int, float, float);
extern void func_01B08D48(void *, int);
extern void func_01B00C50(void);
extern void func_002DD128(void *);
extern void func_01B03808(int, void *);
extern void func_01B00E20(int, void *, void *, void *, unsigned long, float, int, float);
extern void func_01B00D30(void);
extern void func_01B01908(void);
extern int func_01B01AD0(void *, void *, void *, int);
extern void func_01B01A20(void);
extern void func_01B015A0(void *, void *);
extern void func_00269AA8(int);
extern void func_01B08BD8(void *, int);
extern void func_01B03758(int, int, int, void *);
extern void func_01B09498(void *, int, void *, int);
extern void func_01B03EF8(int, int);

static __inline__ void copy_vec(void *dst, const void *src)
{
    register u_long128 *dp __asm__("$3") = (u_long128 *)dst;
    register const u_long128 *sp __asm__("$2") = (const u_long128 *)src;
    register u_long128 t __asm__("$7");
    __asm__ volatile("" : "+r"(dp), "+r"(sp) : : "memory");
    t = *(const volatile u_long128 *)sp;
    *(volatile u_long128 *)dp = t;
    __asm__ volatile("" : : : "memory");
}

void func_01B02508(void *a0);
void func_01B025A0(void);
void func_01B02610(void);
void func_01B02680(void);
void func_01B026B0(void);
void func_01B028E0(void *a0);
void func_01B02A18(void *a0);
void func_01B02BC8(Slot9392 *a0);

int func_01B023E8(void)
{
    u8 *base = D_01BCFA80;
    Ctrl9392 *s0;
    Task9392 *task;

    D_01B09888 = 0;
    D_01B0988C = base + 0x40000;
    D_01B09914 = base + 0x140000;
    D_01B09910 = (Obj9392 *)(base + 0x190000);
    s0 = &D_01B09848;
    s0->w2C = func_002B49A0(D_01B0F3B0, 8, 0);
    func_01B05B00(s0, D_01B00040, base, 0x40000);
    func_01B02610();
    func_01B026B0();
    func_01B08AB8(D_01B09890, D_01B006D8);
    func_01B050E8(1);

    task = func_01B05878(func_01B02508);
    task->b18 = 1;
    func_01B05A40(task);

    func_01B09260(&D_01B09910->subD590);

    task = func_01B05878(func_01B025A0);
    task->b18 = 2;
    func_01B05A40(task);

    return 0;
}

void func_01B02508(void *a0)
{
    Obj9392 *s1 = D_01B09910;
    int s0 = func_01B08AD8(D_01B09890);
    int v1 = func_01B04D58(D_01B098F0);

    if (s0 == 1 && v1 == 1) {
        s1->wD80C = 1;
        func_01B02680();
        func_01B058F8(a0);
    }
}

void func_01B025A0(void)
{
    Obj9392 *s0 = D_01B09910;

    if (func_01B05CB8(&D_01B09848, D_01B0988C) == 1 && s0->wD80C == 1) {
        func_001CDDD8(D_01B09840);
    }
}

void func_01B02610(void)
{
    Obj9392 *s0 = D_01B09910;

    func_01B04268(0);
    s0->wD10 = 0;
    s0->fD14 = func_01B03190(-1);
    s0->wD18 = 0;
    s0->wD1C = 0;
    func_01B032B8(-1, &s0->qD20, 3);
    s0->wD80C = 0;
    D_01B09904 = 1;
}

void func_01B02680(void)
{
    func_01B09408(&D_01B09910->subD590);
    func_01B04268(1);
}

void func_01B026B0(void)
{
    int s0 = func_01B03100(-1);

    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_002A7308(D_01B09914, s0, 1, 0);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
}

void func_01B02730(void)
{
    float v3[4];
    float zero;
    Obj9392 *s0 = D_01B09910;

    func_01B05BD8(&D_01B09848, &s0->slots[0], 0, 0, 0, 0, 0.12f);
    copy_vec(&s0->slots[0].pos, &s0->qD20);
    s0->slots[0].pos.v.y -= 1.5f;
    s0->slots[0].fC4 = s0->fD14;
    zero = 0.0f;
    __asm__("" : "+f"(zero));
    v3[2] = zero;
    v3[1] = zero;
    v3[0] = zero;
    func_01B094C8(&s0->subD590, 3, v3, 30);
    func_01B09028(s0->subD510, 30, 0, 1.0f, 0.5f);
}

void func_01B027F8(void)
{
    Obj9392 *s1 = D_01B09910;
    Slot9392 *s2 = &s1->slots[2];
    SubD4A8_9392 *s0;
    float tmp;

    func_01B05BD8(&D_01B09848, s2, 2, 0, 0, 0, 0.24f);
    copy_vec(&s2->pos, &s1->qD20);
    tmp = s2->pos.v.y - 0.2f;
    s2->fC4 = s1->fD14;
    s2->pos.v.y = tmp;
    s0 = &s1->subD4A8;
    func_01B08D48(s0, 0x8C);
    s0->f08 = 0.2f;
    s0->w24 = 30;
    s0->f14 = 5.0f;
    s0->h2C |= 3;
    s0->w0C = 0;
    s0->w10 = 0;
    s0->w18 = 0;
    s0->w04 = 0;
}

void func_01B028E0(void *a0)
{
    float mat1[4][4];
    float mat2[4][4];
    Obj9392 *s3 = D_01B09910;
    int s4;
    int s2;
    unsigned long s1;

    if (s3->wD808 <= 0) {
        func_01B058F8(a0);
        return;
    }

    s3->wD808--;
    s4 = (s3->wD808 * 80) / s3->wD804;
    s3->fD800 -= 0.015f;
    if (s3->fD800 < 0.0f) {
        s3->fD800 += 1.0f;
    }

    func_01B00C50();
    s2 = func_01B03100(-1);
    s1 = *(unsigned long *)func_002B49A0(D_01B0F3B0, 2, 6);
    func_002DD128(mat2);
    func_01B03808(-1, mat1);
    func_01B00E20(s2, D_01B09914, mat1, mat2, s1, 0.0f, s4, s3->fD800);
    func_01B00D30();
}

void func_01B02A18(void *a0)
{
    float mat[4][4];
    Obj9392 *s0 = D_01B09910;
    void *p;
    int r;

    func_002DD128(mat);
    mat[2][2] = 0.025f;
    mat[1][1] = 0.025f;
    mat[0][0] = 0.025f;
    copy_vec(mat[3], &s0->qD20);
    mat[3][1] -= 1.5f;
    func_01B01908();
    p = (void *)func_002B49A0(D_01B0F3B0, 4, 0);
    r = func_01B01AD0(p, s0->subD30, mat, 0x80);
    func_01B01A20();
    if (r == 0) {
        func_01B058F8(a0);
    }
}

void func_01B02AD0(void)
{
    Obj9392 *s0 = D_01B09910;

    func_01B015A0((void *)func_002B49A0(D_01B0F3B0, 4, 0), s0->subD30);
}

void func_01B02B10(void)
{
    Obj9392 *s0 = D_01B09910;
    SubD330_9392 *v0;

    func_00269AA8(0x5A);
    v0 = &s0->subD330;
    v0->b82 = 0xFF;
    v0->b81 = 0xFF;
    v0->b80 = 0xFF;
    v0->b83 = 0x80;
    v0->b84 = 0xFF;
    v0->b85 = 0xFF;
    v0->b86 = 0xFF;
    v0->b87 = 0;
    v0->w88 = 0;
    v0->b98 = 0x48;
    v0->b99 = 0;
    func_01B08BD8(v0, 30);
    s0->fD800 = 0.0f;
    s0->wD808 = 250;
    s0->wD804 = 250;
    func_01B05A40(func_01B05878(func_01B028E0));
    func_01B05A40(func_01B05878(func_01B02A18));
}

void func_01B02BC8(Slot9392 *a0)
{
    func_01B03758(-1, a0->w120, 0, &a0->pos);
    a0->p104 = 0;
}

void func_01B02C00(void)
{
    float v3[4];
    float v2[2];
    Obj9392 *s2 = D_01B09910;
    Slot9392 *slot = &s2->slots[6];
    SubD590_9392 *s0;
    int i;

    for (i = 0; i < 5; i++, slot++) {
        func_01B05BD8(&D_01B09848, slot, 4, D_01B006C0[i] - 45, 0, 0, 0.12f);
        slot->p104 = func_01B02BC8;
        slot->w120 = D_01B006A8[i];
        slot->fC4 = s2->fD14;
    }

    s0 = &s2->subD590;
    s0->f80 = 2.79252696f;
    s0->w84 = 0;
    v2[0] = 0.6981315613f;
    v2[1] = 0.0f;
    func_01B09498(s0, 2, v2, 100);

    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = 0.0f;
    func_01B094C8(s0, 0, v3, 30);
    func_01B094C8(s0, 1, v3, 30);

    v3[0] = 1.5f;
    v3[1] = 1.4f;
    v3[2] = 1.3f;
    func_01B094C8(s0, 2, v3, 100);
    func_01B03EF8(-1, 0);
}

void func_01B02DA0(void)
{
    Obj9392 *s2 = D_01B09910;
    Slot9392 *s1 = &s2->slots[3];
    SubD590_9392 *s0;
    float tmp;

    func_01B05BD8(&D_01B09848, s1, 3, 0, 0, 0, 0.28f);
    copy_vec(&s1->pos, &s2->qD20);
    tmp = s1->pos.v.y - 1.0f;
    s1->fC4 = s2->fD14;
    s1->pos.v.y = tmp;

    s0 = &s2->subD590;
    func_01B09498(s0, 0, s0->sub1C0, 80);
    func_01B09498(s0, 1, s0->sub1D0, 80);
    func_01B09498(s0, 2, s0->sub1E0, 80);
    func_01B094C8(s0, 0, s0->sub220, 80);
    func_01B094C8(s0, 1, s0->sub230, 80);
    func_01B094C8(s0, 2, s0->sub240, 80);
    func_01B094C8(s0, 3, s0->sub250, 80);
    func_01B09028(s2->subD550, 80, 0, 0.5f, 1.0f);
    func_01B03EF8(-1, 2);
}
