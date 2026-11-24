#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float vD0[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x0C];
    int f120;
    u8 pad124[0x0C];
} Part21B0;

typedef struct {
    Part21B0 parts[6];
    float v720[4];
    float v730[4];
    u8 pad740[0x60];
    float v7A0[4];
    float v7B0[4];
    float v7C0[4];
    u8 sub7D0[6][0x40];
    int f950;
    int f954;
    u8 pad958[0x04];
    int f95C;
    int f960;
    u8 pad964[0x1C];
    u8 b980[16];
} Sub21B0;

extern u8 g_data_540[];
extern u8 g_data_5a0[];
extern u8 g_data_5c0[];
extern u8 g_data_5e0[];
extern u8 g_data_600[];
extern u8 g_data_5910[];
extern u8 g_env_8fd0[];
extern u8 g_state_9078[];
extern u8 g_buf_ea20[];

extern float func_002B3DB0(float);
extern void func_ovl_1610(Sub21B0 *);
extern int func_ovl_27e0(int);
extern void func_ovl_2a30(int, void *, int);
extern void func_ovl_4418(int, void *, void *);
extern void func_ovl_4ad8(void *, void *, void *);
extern void func_ovl_4ce0(void *, int, int);
extern void func_ovl_5350(void *, void *, int, int, int, void *, float);
extern float func_ovl_6358(float, float);

void func_01B021B0(Sub21B0 *s)
{
    int flag = s->f950;
    float ang;
    void *tbl;
    float scale;
    int idx;
    Part21B0 *p;
    u8 *sub;

    func_ovl_1610(s);
    ang = func_ovl_6358(s->v720[1], s->v730[1]);
    if (flag == 0) {
        if (s->v720[1] <= ang) {
            tbl = g_data_5a0;
        } else {
            tbl = g_data_5e0;
        }
    } else {
        if (s->v720[1] <= ang) {
            tbl = g_data_5c0;
        } else {
            tbl = g_data_600;
        }
    }
    func_ovl_4418(-1, g_state_9078, tbl);

    scale = (func_002B3DB0(0.2f) + 1.0f) * 0.35f;
    idx = s->f954 - 1;
    p = &s->parts[idx];
    func_ovl_5350(g_env_8fd0, p, 0, 3, 0, g_data_5910, scale);
    func_ovl_2a30(s->b980[idx], p->vD0, 4);
    p->fC4 = s->v720[1];
    p->f120 = func_ovl_27e0(s->b980[idx]);
    sub = s->sub7D0[idx];
    func_ovl_4ad8(sub, g_buf_ea20, g_data_540);
    p->p110 = sub;
    func_ovl_4ce0(g_buf_ea20, 1, 0);
    func_ovl_2a30(-1, s->v7B0, 0);
    {
        register void *d __asm__("$4") = s->v7C0;
        void *src = s->v7A0;
        __asm__("" : "+r"(d));
        copy_vec4_a3(d, src);
    }
    {
        register int v __asm__("$3") = 0x24;
        s->f960 = v;
        s->f95C = v;
    }
}
