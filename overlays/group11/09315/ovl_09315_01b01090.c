#include "common.h"

typedef struct {
    u8 pad00[0x14];
    int idx;
} Ovl09315Task;

typedef struct {
    float v00[4];
    float v10[4];
    float v20[4];
    float v30[4];
    u8 s40[0xD0];
    u_long128 q110;
    u8 pad120[0x50];
    u8 s170[0x22C];
    int unk39C;
    u8 pad3A0[0x20];
    int unk3C0;
    u8 pad3C4[0x0C];
} Ovl09315Elem;

extern u8 *D_01B06318;
extern u8 D_01B06320[];

extern float func_01B05150(float, float, float, float, float);
extern void func_002DD128(float (*)[4]);
extern void func_01B04630(void *, void *, int, int, int, int, float);
extern void func_01B04350(void *);
extern void func_01B01318(void *, float (*)[4], float *);

void func_01B01090(Ovl09315Task *task)
{
    float mtx[4][4];
    float pos[4];
    u8 *base;
    Ovl09315Elem *elem;
    u8 *sub;
    float t;

    base = D_01B06318;
    elem = (Ovl09315Elem *)(base + task->idx * 0x3D0);
    if (elem->unk3C0 > 0) {
        elem->unk3C0--;
        if (elem->unk3C0 > 0) {
            t = (float)elem->unk3C0 / 30.0f;
        } else {
            t = 0.0f;
        }
    } else {
        t = 0.0f;
    }

    sub = elem->s170;
    pos[0] = func_01B05150(elem->v30[0], elem->v20[0], elem->v10[0], elem->v00[0], t);
    pos[1] = func_01B05150(elem->v30[1], elem->v20[1], elem->v10[1], elem->v00[1], t);
    pos[2] = func_01B05150(elem->v30[2], elem->v20[2], elem->v10[2], elem->v00[2], t);
    pos[3] = 1.0f;

    func_002DD128(mtx);
    mtx[0][0] = mtx[1][1] = mtx[2][2] = 0.12f;

    if (elem->unk3C0 <= 0) {
        if (elem->unk3C0 == 0) {
            u8 *s0 = elem->s40;
            func_01B04630(D_01B06320, s0, 2, 0, 0, 0, 0.15f);
            {
                register u_long128 *dst __asm__("$4") = (u_long128 *)((u8 *)elem + 0x110);
                register u_long128 *src __asm__("$2") = (u_long128 *)((u8 *)elem + 0x30);
                register u_long128 _t __asm__("$7");
                __asm__("" : "+r"(dst), "+r"(src));
                _t = *src;
                *dst = _t;
                __asm__ volatile("" : : : "memory");
            }
            {
                register int cnt __asm__("$3") = elem->unk3C0 - 1;
                *(float *)(s0 + 0xC4) = *(float *)(base + 0x1F40);
                elem->unk3C0 = cnt;
            }
        }
        if (*(int *)(sub + 0x22C) > 0) {
            (*(int *)(sub + 0x22C))--;
        } else {
            func_01B04350(task);
            return;
        }
    }

    func_01B01318(sub, mtx, pos);
}
