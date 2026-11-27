#include "vu0.h"

typedef struct {
    u8 pad00[0xC0];
    float rot[3];
    u8 padCC[0x38];
    void *p104;
    u8 pad108[0x28];
} Ctx2BA0;

typedef struct {
    u8 pad00[0x130];
    Ctx2BA0 ctx130;
    u8 pad260[0x390];
    u8 unk5F0[0x15B4];
    float f1BA4;
    u8 pad1BA8[0x08];
    u8 unk1BB0[0x30];
    float vec1BE0[4];
    float vec1BF0[4];
    float vec1C00[4];
    u8 pad1C10[0x20];
    float vec1C30[4];
    float vec1C40[4];
    float vec1C50[4];
    u8 pad1C60[0x2B0];
    float f1F10;
    u8 pad1F14[0x0C];
    int w1F20;
    int w1F24;
} Work2BA0;

extern Work2BA0 *D_01B0A310;
extern u8 D_01B0A228[];

extern void func_01B02B80(void);
extern void func_01B037E8(int, void *, int);
extern void func_01B04A58(int, void *);
extern void func_01B04FD8(int, void *, void *);
extern void func_01B06108(void *, void *, float, int, int, int, void *);
extern void func_01B06578(void *, void *);
extern void func_01B06E38(void *, void *, void *);
extern void func_01B06F40(void *, void *, void *);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02BA0(void)
{
    float v00[4];
    float v10[4];
    float v20[4];
    Work2BA0 *s0 = D_01B0A310;
    register u8 *s2 __asm__("$18") = D_01B0A228;
    register float *s5 __asm__("$21");
    register float *s4 __asm__("$20");
    register u_long128 _q __asm__("$7");
    Ctx2BA0 *ctx;

    func_01B06578(s2, s0->unk5F0);
    s5 = s0->vec1C40;
    func_01B037E8(0, v00, 4);
    __asm__ volatile("" : "+r"(s5));
    _q = *(u_long128 *)v00;
    *(u_long128 *)s5 = _q;
    __asm__ volatile("");
    v00[1] = s0->f1BA4;
    v10[0] = 0.0f;
    v10[1] = s0->f1F10;
    v10[2] = 0.0f;
    v10[3] = 0.0f;
    v20[0] = 0.0f;
    v20[1] = -25.0f;
    v20[2] = 80.0f;
    v20[3] = 1.0f;
    s4 = s0->vec1C30;
    func_01B06F40(v10, v00, v20);
    __asm__ volatile("" : "+r"(s4));
    _q = *(u_long128 *)v00;
    *(u_long128 *)s4 = _q;
    __asm__ volatile("");
    s0->vec1BF0[0] = 0.0f;
    s0->vec1BF0[1] = s0->f1F10;
    s0->vec1BF0[2] = 0.0f;
    s0->vec1BF0[3] = 0.0f;
    func_01B04FD8(1, s0->unk1BB0, s0->vec1BF0);
    copy_vec(s0->vec1BE0, v00);
    copy_vec(s0->vec1C00, v00);
    func_01B04A58(1, s0->unk1BB0);
    ctx = &s0->ctx130;
    __asm__ volatile("" : "+r"(ctx));
    func_01B06108(s2, ctx, 0.04f, 1, 0, 0, 0);
    func_01B06E38(v10, s4, s5);
    ctx->rot[0] = v10[0];
    ctx->p104 = (void *)func_01B02B80;
    ctx->rot[1] = v10[1];
    copy_vec(s0->vec1C50, v10);
    s0->w1F20 = 12;
    s0->w1F24 = 1;
}
