#include "oef_overlay.h"

typedef unsigned long u64;

typedef struct Part30 {
    float pos[4];
    float vel[4];
    float f20;
    u16 h24;
    u16 h26;
    s16 h28;
    u8 pad2A[6];
} Part30;

typedef struct WorkC0 {
    u16 h00;
    u16 h02;
    u32 w04;
    u64 q08;
    void *p10;
    void *p14;
    u8 b18;
    u8 pad19[3];
    void *p1C;
    u8 pad20[0x10];
    float mtx30[16];
    float mtx70[16];
    u8 *pB0;
    void *pB4;
    u8 padB8[8];
} WorkC0;

typedef struct ResPtr {
    u32 w00;
    u8 *p04;
} ResPtr;

extern Part30 D_01B00660[128];
extern int D_01B057E0;
extern int D_01B0629C;
extern void *D_01B062A0;
extern int D_01B062A4;
extern int D_01B062A8;
extern int D_01B062AC;
extern int D_01B062B0;
extern int D_01B062B4;
extern int D_01B062B8;
extern int D_01B062BC;
extern int D_01B062C0;
extern int D_01B062C4;
extern int D_01B062C8;
extern int D_01B062CC;
extern int D_01B062D0;
extern int D_01B062D4;
extern int D_01B062D8;
extern int D_01B062DC;
extern int D_01B062E0;
extern int D_01B062E4;
extern int D_01B062E8;
extern int D_01B062EC;
extern int D_01B062F0;
extern int D_01B062F4;
extern int D_01B062F8;
extern int D_01B062FC;
extern ResPtr *D_01B06378;
extern u8 D_01B65100[];

extern void *func_002B3888(int);
extern void func_002B39C0(int);
extern void *func_002CD590(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD128(void *);
extern void func_01B01E68(void *);
extern void func_01B02D48(void);

void func_01B02FD0(void)
{
    Part30 *p = D_01B00660;
    WorkC0 *w = (WorkC0 *)func_002B3888(0xC0);
    int i;

    w->pB4 = D_006A3BCC;
    w->pB0 = D_01B06378->p04;
    for (i = 127; i != -1; i--, p++) {
        if (p->h28 != 0) {
            float sc;
            register u8 *base __asm__("$6");
            u8 *entry;
            func_002DD128(w->mtx30);
            sc = p->f20;
            w->mtx30[10] = sc;
            w->mtx30[5] = sc;
            w->mtx30[0] = sc;
            func_002DCE08(&w->mtx30[12], D_006A3970, p->pos);
            func_002DD0C0(w->mtx70, w->mtx30);
            func_002DCE38(w->mtx30, D_006A3A70, w->mtx30);
            w->mtx70[14] -= 100.0f;
            func_002DCE38(w->mtx70, D_006A3A70, w->mtx70);
            w->b18 = 0;
            w->h02 = 0x80;
            w->w04 = 0x70808080;
            w->q08 = 0;
            w->p10 = w->mtx30;
            w->p1C = w->mtx70;
            base = w->pB0;
            entry = base + *(s16 *)(base + p->h26 * 8 + 0x10);
            w->p14 = w->pB4;
            w->pB4 = func_002CD590(entry, w, base);
            if (D_006A3BC4 == 0) {
                register float py __asm__("$f1") = p->pos[1];
                register float vy __asm__("$f2") = p->vel[1];
                register float px __asm__("$f5") = p->pos[0];
                register float one __asm__("$f0");
                p->pos[1] = py + vy;
                px += p->vel[0];
                p->pos[0] = px;
                one = 1.0f;
                vy += one;
                p->vel[1] = vy;
                p->pos[2] += p->vel[2];
                p->h28--;
            }
        }
    }
    D_006A3BCC = w->pB4;
    func_002B39C0(0xC0);
}

int func_01B031A8(int eff_id)
{
    D_01B057E0 = eff_id;
    func_00266F40();
    D_01B062A0 = func_0013B150(0);
    func_01B01E68(D_01B65100);
    func_01B02D48();
    D_01B0629C = D_01B062A4 = D_01B062A8 = D_01B062B0 = D_01B062B4 = D_01B062B8 = D_01B062BC =
    D_01B062C0 = D_01B062C4 = D_01B062C8 = D_01B062CC = D_01B062D0 = D_01B062D4 = D_01B062D8 =
    D_01B062DC = D_01B062E0 = D_01B062E4 = D_01B062E8 = D_01B062EC = D_01B062F0 = D_01B062F4 =
    D_01B062F8 = D_01B062FC = D_01B062AC = 0;
    return 0;
}
