#include "iopsound.h"

typedef struct Voice {
    void *unk00;        /* 0x00 */
    u8 pad04[0x12];
    u8 unk16;           /* 0x16 */
    u8 pad17[0x35];
    u32 unk4C;          /* 0x4C */
    u8 pad50[0x08];
    u32 unk58;          /* 0x58 */
    u32 unk5C;          /* 0x5C */
    u8 pad60[0x12];
    s16 unk72;          /* 0x72 */
} Voice; /* size 0x74 = 116 */

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x1C];
    s32 unk020;         /* 0x020 */
    u8 pad024[1];
    u8 unk025;          /* 0x025 */
    u8 unk026;          /* 0x026 */
    u8 pad027[0xB9];
    s32 unk0E0;         /* 0x0E0 */
    u8 pad0E4[0x53];
    u8 unk137;          /* 0x137 */
    u8 pad138[4];
} Track; /* size 0x13C = 316 */

typedef struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x18];
    s32 unk01C;         /* 0x01C */
    s32 unk020;         /* 0x020 */
    s32 unk024;         /* 0x024 */
    u8 pad028[0x330];
    s32 unk358;         /* 0x358 */
    u8 pad35C[0x18];
    s32 unk374;         /* 0x374 */
    u8 pad378[0x08];
    s32 unk380;         /* 0x380 */
    s32 unk384;         /* 0x384 */
    s16 unk388;         /* 0x388 */
    s16 unk38A;         /* 0x38A */
    u8 pad38C[1];
    u8 unk38D;          /* 0x38D */
    u8 pad38E[2];
} Seq; /* size 0x390 = 912 */

typedef struct Stream {
    u8 pad00[0x1C];
    s32 unk1C;          /* 0x1C */
    s32 unk20;          /* 0x20 */
    u8 pad24[0x2C];
    s32 unk50;          /* 0x50 */
    u8 pad54[0x04];
    s32 unk58;          /* 0x58 */
    s32 unk5C;          /* 0x5C */
    u8 pad60[0x04];
    s32 unk64;          /* 0x64 */
    u8 pad68[0x08];
} Stream; /* size 0x70 = 112 */

typedef struct Fade {
    s32 cur;
    s32 step;
    s32 cnt;
} Fade;

extern s32 D_01873C;
extern void *D_0192F4;
extern void *D_0192F8;
extern void *D_019384;
extern Track *D_019324;
extern void *D_019334;
extern void *D_019308;
extern void *D_01938C;
extern void *D_019338;
extern Seq *D_01936C;
extern Voice *D_0192F0;
extern s32 D_019328;
extern Stream *D_018754;
extern void *D_019314;
extern void *D_0192FC;
extern s32 D_01932C;
extern Fade D_122460;
extern Fade D_122450;
extern Fade D_122440;
extern s32 *D_018750;
extern u32 D_01934C;
extern s32 D_06D2A0[];
extern s32 D_019300[];
extern void *D_0193A4;

extern void func_009A70(void);
extern void *func_009948(s32);
extern void func_0097A8(void);
extern void func_009CAC(void);
extern void func_00B9C4(void);
extern void func_00C2F0(void);
extern void func_0093C8(void *, s32, s32);

void func_000000(void) {
    s32 i;
    Voice *v;
    Track *t;

    D_01873C = 0;
    func_009A70();

    D_0192F4 = func_009948(0x5000);
    D_0192F8 = func_009948(0x800);
    D_019384 = func_009948(0x8000);
    D_019324 = func_009948(sizeof(Track) * 2);
    D_019334 = func_009948(0x408);
    D_019308 = func_009948(0xC18);
    D_01938C = func_009948(0xC10);
    D_019338 = func_009948(0x48);

    func_0097A8();
    func_009CAC();
    func_00B9C4();
    func_00C2F0();

    D_01936C = func_009948(sizeof(Seq) * 4);
    D_0192F0 = func_009948(sizeof(Voice) * 48);
    func_0093C8(D_0192F0, sizeof(Voice) * 48, 0);

    i = 0;
    v = D_0192F0;
    do {
        v->unk58 = i << 1;
        v->unk5C = 1 << i;
        v->unk72 = i;
        v->unk00 = NULL;
        v->unk16 = 0;
        v->unk4C = 2;
        v++;
    } while (++i < 24);
    i = 0;
    do {
        v->unk58 = (i << 1) | 1;
        v->unk5C = 1 << i;
        v->unk72 = i;
        v->unk00 = NULL;
        v->unk16 = 0;
        v->unk4C = 2;
        v++;
    } while (++i < 24);

    i = 24;
    D_019328 = 120;
    t = func_009948(sizeof(Track) * 24);
    D_01936C[2].tracks = t;
    do {
        t->unk137 = i;
        t->ptr = NULL;
        t->unk026 = 17;
        t->unk025 = 0;
        t->unk0E0 = -1;
        t->unk020 = 0;
        t++;
    } while (++i < 48);

    {
        Stream *st0 = D_018754;
        Stream *st1 = st0 + 1;
        st1->unk1C = 0;
        st0->unk1C = 0;
        st1->unk20 = 0;
        st0->unk20 = 0;
    }

    D_019324[0].unk137 = 22;
    D_019324[1].unk137 = 23;
    {
        Track *t2 = D_019324;
        t2[1].ptr = NULL;
        t2[0].ptr = NULL;
        t2[1].unk026 = 2;
        t2[0].unk026 = 2;
    }
    D_019324[1].unk0E0 = -1;
    D_019324[0].unk0E0 = -1;

    D_019314 = func_009948(1152);
    D_0192FC = func_009948(1152);
    func_0093C8(D_019314, 1152, 0);

    {
        Seq *s0 = D_01936C;
        Seq *s1 = s0 + 1;
        s1->unk374 = -1;
        s0->unk374 = -1;
        s0[1].unk38A = 0;
        s1->unk38D = 0;
        s0->unk38D = 0;
        s0->unk38A = 0;
    }
    D_01936C[2].unk38D = 24;

    D_01932C = 0;
    {
        Seq *s0 = D_01936C;
        Seq *s1 = s0 + 1;
        Seq *s2 = s0 + 2;
        s1->unk358 = 0;
        s0->unk358 = 0;
        s2->unk388 = 1;
        s1->unk388 = 1;
        s0->unk388 = 1;
        s2->unk384 = 0;
        s1->unk384 = 0;
        s0->unk384 = 0;
        s1->unk01C = 0x1FF000;
        s0->unk01C = 0x1FF000;
        s1->unk024 = 0;
        s0->unk024 = 0;
        s1->unk380 = 0;
        s0->unk380 = 0;
    }

    D_122460.cnt = 0;
    {
        Fade *f = &D_122450;
        f->cnt = 0;
        f->cur = 0;
    }
    {
        Fade *f = &D_122440;
        f->cnt = 0;
        f->cur = 0;
    }

    {
        Stream *st0 = D_018754;
        Stream *st1 = st0 + 1;
        st1->unk50 = 0x03F80000;
        st0->unk50 = 0x03F80000;
        st1->unk5C = 0x00080000;
        st0->unk5C = 0x00080000;
        st1->unk58 = 0;
        st0->unk58 = 0;
        st1->unk64 = 0;
        st0->unk64 = 0;
    }

    D_01934C = 0xC800;
    D_06D2A0[0] = 0x07FFF000;
    D_06D2A0[2] = 0;
    {
        s32 *p = D_019300;
        p[1] = 0;
        p[0] = 0;
    }
    *D_018750 = 0;

    D_0193A4 = func_009948(1024);
    func_0093C8(D_0193A4, 1024, 0);
}
