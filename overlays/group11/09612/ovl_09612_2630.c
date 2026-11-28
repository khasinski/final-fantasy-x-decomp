#include "common.h"
#include "vu0.h"

extern u8 *D_01B0A568;
extern u8 D_01B0A448[];

extern void func_002DD128(float *mat);
extern void func_002DD318(float *dst, float *src, float angle);
extern void func_002DCE08(float *dst, float *mat, float *vec);
extern float func_002B3DB0(float scale);
extern float func_002B3DF8(float scale);
extern s32 func_002EFD78(void);
extern void *func_01B09A18(void);
extern u32 *func_01B06240(void *a0, s32 a1);
extern void func_01B07078(void *a0, u32 a1);

typedef struct {
    float pos[4];
    float vel[4];
    float acc[4];
    u8 unk30[0xC];
    float unk3C;
    u8 unk40[0x8];
    float unk48;
    s32 unk4C;
    s32 unk50;
    u8 unk54[0xC];
    s32 unk60;
} Particle2630;

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

static inline void copy_vec_r(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B02630(void) {
    float mat0[16];
    float mat1[16];
    float vec0[4];
    float vec1[4];
    float pos[4];
    u8 *src_pos = D_01B0A568 + 0x1500;
    s32 i;
    register s32 j __asm__("$17");
    register float *vec1_p __asm__("$23");
    register float *vec0_p __asm__("$22");
    register float *mat1_p __asm__("$18");
    register s32 five __asm__("$19");
    Particle2630 *p;

    vec0[0] = 0.0f;
    vec0[1] = 0.0f;
    vec0[2] = 0.0f;
    vec0[3] = 1.0f;

    copy_vec(pos, src_pos);
    pos[1] -= 42.0f;
    five = 5;
    func_002DD128(mat0);
    vec1_p = vec1;
    vec0_p = vec0;
    mat1_p = mat1;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 60; j++) {
            p = (Particle2630 *)func_01B09A18();
            if (p == 0) {
                break;
            }
            func_01B07078(p->unk30, *func_01B06240(D_01B0A448, 3));
            func_002DD318(mat1_p, mat0, func_002B3DB0(3.1415927f));
            vec0[2] = func_002B3DF8(50.0f) + func_002B3DF8(50.0f) + 10.0f;
            func_002DCE08(vec1_p, mat1_p, vec0_p);
            copy_vec(p->pos, pos);
            p->pos[0] += func_002B3DB0(10.0f);
            p->pos[1] += func_002B3DB0(10.0f);
            p->pos[2] += func_002B3DB0(10.0f);
            p->vel[0] = vec1[0] * 0.07f + func_002B3DB0(1.0f);
            p->vel[1] = func_002B3DB0(0.3f);
            p->vel[2] = vec1[2] * 0.07f + func_002B3DB0(1.0f);
            p->vel[3] = func_002B3DB0(3.1415927f);
            p->acc[0] = 0.0f;
            p->acc[1] = 0.05f;
            p->acc[2] = 0.0f;
            p->acc[3] = 1.0f;
            p->unk3C = (func_002B3DB0(0.4f) + 1.0f) * 0.02f;
            p->unk4C = 70;
            p->unk50 = 0;
            p->unk60 = func_002EFD78() % five;
            p->unk48 = func_002B3DB0(0.62831855f);
        }
        copy_vec_r(pos, src_pos);
    }
}
