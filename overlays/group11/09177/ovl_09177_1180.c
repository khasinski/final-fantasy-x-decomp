/* 09176 beam/projectile update task (604 B). */

typedef unsigned char u8;
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

typedef struct {
    u8 pad00[0x10];
    float vx;
    float vy;
    float vz;
    int w1C;
    int w20;
    float f24;
    int w28;
    float f2C;
    u8 s30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    int w4C;
    int w50;
    u8 pad54[0x17];
    unsigned char b6B;
} OvlPart;

typedef struct {
    u8 pad00[0x260];
    u8 s260[0x228];
    int w488;
    u8 pad48C[0x44];
    sceVu0FVECTOR p0;
    sceVu0FVECTOR p1;
    sceVu0FVECTOR p2;
    sceVu0FVECTOR p3;
    float t;
    float dt;
    int w518;
    int w51C;
    int w520;
    int w524;
} OvlWork;

typedef struct {
    u8 pad00[0x14];
    OvlWork *work;
} OvlTask;

extern u8 g_ovl_res[];

extern float func_001ACED8(void);
extern void *func_002B49A0(void *, int, int);
extern void func_002DD0B0(void *, void *);
extern void func_002DD128(void *);
extern void fn_ovl_0c30(OvlWork *);
extern void fn_ovl_0f20(OvlWork *);
extern void fn_ovl_3de0(OvlTask *);
extern float fn_ovl_4be0(float, float, float, float, float);
extern void fn_ovl_5488(void *, void *);
extern void fn_ovl_56e8(void *, void *, void *);
extern OvlPart *fn_ovl_5e10(void);

void ovl_09177_1180(OvlTask *task)
{
    sceVu0FMATRIX mat;
    sceVu0FVECTOR pos;
    OvlWork *work = task->work;

    if (work->w520 > 0) {
        work->w520--;
        if (work->w520 == 0) {
            fn_ovl_0c30(work);
        }
        return;
    }
    if (work->w524 > 0) {
        work->w524--;
        return;
    }

    work->t += work->dt;
    if (work->t > 1.0f) {
        work->t = 1.0f;
    }
    pos[0] = fn_ovl_4be0(work->p0[0], work->p1[0], work->p2[0], work->p3[0], work->t);
    pos[1] = fn_ovl_4be0(work->p0[1], work->p1[1], work->p2[1], work->p3[1], work->t);
    pos[2] = fn_ovl_4be0(work->p0[2], work->p1[2], work->p2[2], work->p3[2], work->t);
    pos[3] = 1.0f;

    if (work->w51C == 0) {
        if (work->w488 > 0) {
            work->w488 /= 2;
        } else {
            fn_ovl_3de0(task);
            return;
        }
    } else {
        int i;
        work->w51C--;
        if (work->w51C == 0) {
            fn_ovl_0f20(work);
        }
        for (i = 0; i < 6; i++) {
            OvlPart *part = fn_ovl_5e10();
            if (part == 0) {
                break;
            }
            fn_ovl_5488(part->s30, func_002B49A0(g_ovl_res, 9, 1));
            func_002DD0B0(part, pos);
            part->vx = (func_001ACED8() - 1.5f) * 0.5f;
            part->vy = (func_001ACED8() - 1.0f) * 0.4f;
            part->vz = (func_001ACED8() - 1.5f) * 0.5f;
            part->w1C = 0;
            part->w20 = 0;
            part->f24 = -0.02f;
            part->w28 = 0;
            part->f2C = 1.0f;
            part->f3C = 0.015f;
            part->w4C = 32;
            part->w50 = 32;
            part->b6B = 0;
        }
    }

    func_002DD128(mat);
    mat[2][2] = 0.03f;
    mat[1][1] = 0.03f;
    mat[0][0] = 0.03f;
    fn_ovl_56e8(work->s260, mat, pos);
}
