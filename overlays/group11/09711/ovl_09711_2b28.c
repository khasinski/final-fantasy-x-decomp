#include "common.h"

typedef struct CamDbg {
    u8 pad00[0x80];
    float pitch;       /* 0x80 */
    float yaw;         /* 0x84 */
    float roll;        /* 0x88 */
    u8 pad8C[4];
    float eye[4];      /* 0x90 */
    float ref[4];      /* 0xA0 */
    u8 padB0[0xCC];
    float dist;        /* 0x17C */
    float scr_dpt;     /* 0x180 */
    int active;        /* 0x184 */
    u8 mode;           /* 0x188 */
    s8 b189;           /* 0x189 */
    s8 use_mtx;        /* 0x18A */
    u8 pad18B;
    s16 counter;       /* 0x18C */
    s16 pad18E;
} CamDbg;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern int D_01B000E0;
extern char D_01B0AE20[];
extern char D_01B0AE60[];
extern char D_01B0AE88[];
extern char D_01B0AE98[];
extern char D_01B0AEA8[];
extern char D_01B0AEB8[];
extern char D_01B0AEC8[];
extern char D_01B0AEE0[];
extern char D_01B0AEF8[];
extern char D_01B0AF10[];
extern char D_01B0AF28[];
extern char D_01B0AF38[];
extern char D_01B0AF48[];
extern char D_01B0AF58[];
extern char D_01B0AF70[];
extern char D_01B0AF80[];
extern char D_01B0AF90[];
extern int D_01B0B41C;
extern Vec3 D_01B0B8E0[];
extern Vec3 D_01B0BBE0[];
extern float D_01B0BEE0[];
extern float D_01B0BFE0[];
extern int D_01B0C0E0;

int func_01B02180(int);
int func_01B021B0(int);
int func_01B025A8(void);
void func_01B02528(int);
CamDbg *func_01B025B8(int);
void func_002B41B0(const char *, ...);
void func_002EF240(const char *, ...);
void func_002DD128(void *);
void func_002DD270(void *, void *, float);
void func_002DD318(void *, void *, float);
void func_002DCE08(void *, void *, void *);
void func_01B019F8(float *, float *, float *);
void func_01B026D0(CamDbg *, int, Vec3 *, int, int);
void func_01B029A8(CamDbg *, float *, int, int);
void func_01B02A28(CamDbg *, float *, int, int);
void func_002DD038(float *, float *, float *);
double func_002E9290(double);
double fptodp(float);
void func_01B021C8(float *);
void func_001A9EF0(int, int, float *, float *, float *);
float func_01B01BA0(float *, float *);

static inline void wrap_angle(float *p, float d)
{
    float v = *p + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *p = v;
}

void func_01B02B28(void)
{
    float mtx[16];
    float delta[4];
    float ang[4];
    float v0[4];
    float v1[4];
    int pad0_h;
    int pad0_t;
    int pad1_h;
    int pad1_t;
    int btn_b;
    CamDbg *c;
    float rot_step;
    float mov_step;
    int i;

    pad0_h = func_01B02180(0);
    pad0_t = func_01B021B0(0);
    pad1_h = func_01B02180(1);
    pad1_t = func_01B021B0(1);

    func_002B41B0(D_01B0AE60);
    func_002B41B0(D_01B0AE88, func_01B025A8());

    if (pad1_t & 0x10) {
        if (func_01B025A8() == 0) {
            func_01B02528(1);
        } else {
            func_01B02528(0);
        }
    }
    btn_b = pad1_t & 0x2;
    if (btn_b) {
        if (D_01B000E0 == 1) {
            D_01B000E0 = 0;
        } else {
            D_01B000E0 = 1;
        }
    }
    c = func_01B025B8(-1);
    if (pad0_t & 0x10) {
        c->b189 = (c->b189 + 1) & 1;
    }
    if (c->b189 == 0) {
        func_002B41B0(D_01B0AE98);
    } else {
        func_002B41B0(D_01B0AEA8);
    }
    if (pad0_h & 0x40) {
        rot_step = 0.034906585f;
        mov_step = 4.0f;
    } else {
        rot_step = 0.00087266468f;
        mov_step = 0.1f;
    }
    if (pad1_h & 0x2000) {
        wrap_angle(&c->roll, rot_step);
    } else if (pad1_h & 0x8000) {
        wrap_angle(&c->roll, -rot_step);
    }
    if (pad1_t & 0x40) {
        c->roll = 0.0f;
    }
    delta[0] = 0.0f;
    delta[3] = 1.0f;
    delta[1] = 0.0f;
    delta[2] = 0.0f;
    if (!(pad0_h & 0x4)) {
        if (!(pad0_h & 0x1)) {
            float *tgt = (c->b189 == 0) ? c->eye : c->ref;
            if (pad0_h & 0x2000) {
                delta[0] = -mov_step;
            } else if (pad0_h & 0x8000) {
                delta[0] = mov_step;
            }
            if (c->b189 == 1) {
                delta[0] = -delta[0];
            }
            if (pad0_h & 0x8) {
                delta[2] = mov_step;
            } else if (pad0_h & 0x2) {
                delta[2] = -mov_step;
            }
            if (pad0_h & 0x1000) {
                tgt[1] -= mov_step;
            } else if (pad0_h & 0x4000) {
                tgt[1] += mov_step;
            }
            if (c->b189 == 0) {
                func_002DD128(mtx);
                func_002DD318(mtx, mtx, c->yaw);
                func_002DCE08(delta, mtx, delta);
            }
            tgt[0] += delta[0];
            tgt[1] += delta[1];
            tgt[2] += delta[2];
            func_01B019F8(ang, c->eye, c->ref);
            c->pitch = ang[0];
            c->yaw = ang[1];
        } else {
            if (pad0_h & 0x2000) {
                wrap_angle(&c->yaw, rot_step);
            } else if (pad0_h & 0x8000) {
                wrap_angle(&c->yaw, -rot_step);
            }
            if (pad0_h & 0x1000) {
                wrap_angle(&c->pitch, -rot_step);
            } else if (pad0_h & 0x4000) {
                wrap_angle(&c->pitch, rot_step);
            }
            delta[2] = -c->dist;
            if (pad0_h & 0x8) {
                delta[2] += mov_step;
            } else if (pad0_h & 0x2) {
                delta[2] -= mov_step;
            }
            func_002DD128(mtx);
            func_002DD270(mtx, mtx, c->pitch);
            func_002DD318(mtx, mtx, c->yaw);
            mtx[12] = c->eye[0];
            mtx[13] = c->eye[1];
            mtx[14] = c->eye[2];
            func_002DCE08(c->ref, mtx, delta);
        }
    }
    if (pad1_h & 0x1000) {
        c->scr_dpt += 10.0f;
    } else if (pad1_h & 0x4000) {
        c->scr_dpt -= 10.0f;
    }
    if (pad1_t & 0x80) {
        func_002EF240(D_01B0AEB8, c->counter);
        func_002EF240(D_01B0AEC8, (double)c->pitch, (double)c->yaw, (double)c->roll);
        func_002EF240(D_01B0AEE0, (double)c->eye[0], (double)c->eye[1], (double)c->eye[2]);
        func_002EF240(D_01B0AEF8, (double)c->ref[0], (double)c->ref[1], (double)c->ref[2]);
        func_002EF240(D_01B0AF10, (double)c->dist, (double)c->scr_dpt);
    } else if (pad1_t & 0x8) {
        if (D_01B0C0E0 >= 0) {
            D_01B0C0E0--;
        }
    } else if (!btn_b && (pad1_t & 0x1)) {
        if (D_01B0C0E0 >= 0) {
            func_01B026D0(c, 0, D_01B0B8E0, D_01B0C0E0 + 1, 32);
            func_01B026D0(c, 1, D_01B0BBE0, D_01B0C0E0 + 1, 32);
            func_01B029A8(c, D_01B0BEE0, D_01B0C0E0 + 1, 32);
            func_01B02A28(c, D_01B0BFE0, D_01B0C0E0 + 1, 32);
        }
    }
    func_002DD038(delta, c->ref, c->eye);
    fptodp(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
    c->dist = (float)func_002E9290((double)(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]));
    func_002B41B0(D_01B0AF28, (double)c->pitch, (double)c->yaw, (double)c->roll);
    func_002B41B0(D_01B0AF38, (double)c->eye[0], (double)c->eye[1], (double)c->eye[2]);
    func_002B41B0(D_01B0AF48, (double)c->ref[0], (double)c->ref[1], (double)c->ref[2]);
    func_002B41B0(D_01B0AF58, (double)c->dist, (double)c->scr_dpt);
    v1[0] = 0.0f;
    v1[1] = 0.0f;
    v1[2] = 0.0f;
    v1[3] = 1.0f;
    func_01B021C8(v1);
    func_001A9EF0(D_01B0B41C, 1, &v0[0], &v0[1], &v0[2]);
    v0[3] = 1.0f;
    v0[1] = 0.0f;
    func_002B41B0(D_01B0AE20, (double)func_01B01BA0(v1, v0));
    for (i = 0; i <= D_01B0C0E0; i++) {
        Vec3 *p = &D_01B0B8E0[i];
        func_002B41B0(D_01B0AF70, (double)p->x, (double)p->y, (double)p->z, (double)D_01B0BEE0[i]);
        p = &D_01B0BBE0[i];
        func_002B41B0(D_01B0AF80, (double)p->x, (double)p->y, (double)p->z, (double)D_01B0BFE0[i]);
    }
    func_002B41B0(D_01B0AF90);
}
