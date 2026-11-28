#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Msg30E0;

typedef struct {
    void *p0;
    u8 pad4;
    u8 b5;
} Msg30E0B;

extern u8 D_01B00800[];
extern u8 D_01B00A10[];
extern u8 D_01B00A24;
extern u8 D_01B00A28[];

extern void func_01B02F60(void *);
extern void func_01B0F148(void *);
extern void func_01B0F550(void *);
extern void func_01B096A0(void *);
extern void func_002DD0B0(void *, void *);
extern void func_01B0B380(void *);
extern void func_01B0B408(void *);
extern void func_01B0C038(void *);

static inline void set_p4_p8(Msg30E0 *p, void *p4, void *p8) {
    p->p4 = p4;
    p->p8 = p8;
}

void func_01B030E0(u8 *s0, void *s3, u8 *s2) {
    struct {
        void *p0;
        u8 b4;
        u8 b5;
        u8 pad6[2];
        void *p8;
        void *pC;
    } a00;
    Msg30E0 a10;
    u8 *s6 = s0 + 0x170;
    u8 *s5 = s0 + 0x1D0;
    u8 *s4 = s0 + 0x1A0;

    {
        void **p = (void **)&a00;
        p[0] = s0;
        p[1] = (void *)func_01B02F60;
        p[2] = s0;
        func_01B0F148(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = D_01B00A10;
        p[1] = s0;
        func_01B0F550(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = s6;
        p[1] = D_01B00A28;
        func_01B096A0(p);
    }

    func_002DD0B0(s0 + 0x190, s3);
    *(float *)(s0 + 0x194) -= 0.4f;

    {
        void **p = (void **)&a00;
        p[0] = s5;
        p[1] = D_01B00A28;
        func_01B0B380(p);
    }

    a00.p0 = s2;
    a00.b5 = D_01B00A24;
    func_01B0B408(&a00);

    *(s32 *)(s0 + 0x1F0) = *(s32 *)(s2 + 0x20);
    *(s32 *)(s0 + 0x1F4) = *(s32 *)(s2 + 0x24);
    *(s32 *)(s0 + 0x1F8) = *(s32 *)(s2 + 0x28);

    {
        void **p = (void **)&a00;
        p[0] = s4;
        p[1] = D_01B00A28;
        func_01B096A0(p);
    }

    *(float *)(s0 + 0x1C0) = 1.0f;
    *(float *)(s0 + 0x1C4) = 1.0f;
    *(float *)(s0 + 0x1C8) = 1.0f;
    *(volatile float *)(s0 + 0x1CC) = 1.0f;

    {
        Msg30E0 *p = &a10;
        a10.p0 = s0 + 0x20;
        *(volatile void **)&p->p4 = D_01B00A28;
        p->p8 = D_01B00800;
        a10.pC = s6;
        a10.p10 = s5;
        a10.p14 = s4;
        func_01B0C038(p);
    }

    *(s32 *)(s0 + 0x18) = 0;
}
