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
    s8 tgt_sel;        /* 0x189 */
    s8 use_mtx;        /* 0x18A */
    s8 pad18B;
    s16 frame;         /* 0x18C */
    s16 pad18E;
} CamDbg;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern int D_01B000E0;
extern char D_01B0B4E0[];
extern char D_01B0B520[];
extern char D_01B0B548[];
extern char D_01B0B558[];
extern char D_01B0B568[];
extern char D_01B0B578[];
extern char D_01B0B588[];
extern char D_01B0B5A0[];
extern char D_01B0B5B8[];
extern char D_01B0B5D0[];
extern char D_01B0B5E8[];
extern char D_01B0B5F8[];
extern char D_01B0B608[];
extern char D_01B0B618[];
extern char D_01B0B630[];
extern char D_01B0B640[];
extern char D_01B0B650[];
extern int D_01B0BAFC;
extern Vec3 D_01B0BFC0[];
extern Vec3 D_01B0C2C0[];
extern float D_01B0C5C0[];
extern float D_01B0C6C0[];
extern int D_01B0C7C0;

int func_01B023D8(int);
int func_01B02408(int);
int func_01B02800(void);
void func_01B02780(int);
CamDbg *func_01B02810(int);
void func_01B01C50(float *, float *, float *);
void func_01B02928(CamDbg *, int, Vec3 *, int, int);
void func_01B02C00(CamDbg *, float *, int, int);
void func_01B02C80(CamDbg *, float *, int, int);
void func_01B02420(float *);
float func_01B01DF8(float *, float *);

void func_002B41B0(const char *, ...);
void func_002EF240(const char *, ...);
void func_002DD128(float *);
void func_002DD270(float *, float *, float);
void func_002DD318(float *, float *, float);
void func_002DCE08(float *, float *, float *);
void func_002DD038(float *, float *, float *);
double func_002E9290(double);
double fptodp(float);
void func_001A9EF0(int, int, float *, float *, float *);

static inline void wrap_add(float *p, float d)
{
    float v = *p + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *p = v;
}

void func_01B02D80(void)
{
    float mtx[16];
    float vec[4];
    float ang[4];
    float v60[4];
    float v70[4];
    int p0, t0, p1, t1;
    int t1_2;
    CamDbg *cam;
    float da, dv;
    int i;

    p0 = func_01B023D8(0);
    t0 = func_01B02408(0);
    p1 = func_01B023D8(1);
    t1 = func_01B02408(1);

    func_002B41B0(D_01B0B520);
    func_002B41B0(D_01B0B548, func_01B02800());

    if (t1 & 0x10) {
        if (func_01B02800() == 0) {
            func_01B02780(1);
        } else {
            func_01B02780(0);
        }
    }

    t1_2 = t1 & 2;
    if (t1_2) {
        if (D_01B000E0 == 1) {
            D_01B000E0 = 0;
        } else {
            D_01B000E0 = 1;
        }
    }

    cam = func_01B02810(-1);
    if (t0 & 0x10) {
        cam->tgt_sel = (cam->tgt_sel + 1) & 1;
    }
    if (cam->tgt_sel == 0) {
        func_002B41B0(D_01B0B558);
    } else {
        func_002B41B0(D_01B0B568);
    }

    if (p0 & 0x40) {
        da = 0.034906585f;
        dv = 4.0f;
    } else {
        da = 0.00087266468f;
        dv = 0.1f;
    }

    if (p1 & 0x2000) {
        wrap_add(&cam->roll, da);
    } else if (p1 & 0x8000) {
        wrap_add(&cam->roll, -da);
    }
    if (t1 & 0x40) {
        cam->roll = 0.0f;
    }

    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = 0.0f;
    vec[3] = 1.0f;

    if (!(p0 & 4)) {
        if (!(p0 & 1)) {
            float *dst = (cam->tgt_sel == 0) ? cam->eye : cam->ref;
            if (p0 & 0x2000) {
                vec[0] = -dv;
            } else if (p0 & 0x8000) {
                vec[0] = dv;
            }
            if (cam->tgt_sel == 1) {
                vec[0] = -vec[0];
            }
            if (p0 & 8) {
                vec[2] = dv;
            } else if (p0 & 2) {
                vec[2] = -dv;
            }
            if (p0 & 0x1000) {
                dst[1] -= dv;
            } else if (p0 & 0x4000) {
                dst[1] += dv;
            }
            if (cam->tgt_sel == 0) {
                func_002DD128(mtx);
                func_002DD318(mtx, mtx, cam->yaw);
                func_002DCE08(vec, mtx, vec);
            }
            dst[0] += vec[0];
            dst[1] += vec[1];
            dst[2] += vec[2];
            func_01B01C50(ang, cam->eye, cam->ref);
            cam->pitch = ang[0];
            cam->yaw = ang[1];
        } else {
            if (p0 & 0x2000) {
                wrap_add(&cam->yaw, da);
            } else if (p0 & 0x8000) {
                wrap_add(&cam->yaw, -da);
            }
            if (p0 & 0x1000) {
                wrap_add(&cam->pitch, -da);
            } else if (p0 & 0x4000) {
                wrap_add(&cam->pitch, da);
            }
            vec[2] = -cam->dist;
            if (p0 & 8) {
                vec[2] += dv;
            } else if (p0 & 2) {
                vec[2] -= dv;
            }
            func_002DD128(mtx);
            func_002DD270(mtx, mtx, cam->pitch);
            func_002DD318(mtx, mtx, cam->yaw);
            mtx[12] = cam->eye[0];
            mtx[13] = cam->eye[1];
            mtx[14] = cam->eye[2];
            func_002DCE08(cam->ref, mtx, vec);
        }
    }

    if (p1 & 0x1000) {
        cam->scr_dpt += 10.0f;
    } else if (p1 & 0x4000) {
        cam->scr_dpt -= 10.0f;
    }

    if (t1 & 0x80) {
        func_002EF240(D_01B0B578, cam->frame);
        func_002EF240(D_01B0B588, (double)cam->pitch, (double)cam->yaw, (double)cam->roll);
        func_002EF240(D_01B0B5A0, (double)cam->eye[0], (double)cam->eye[1], (double)cam->eye[2]);
        func_002EF240(D_01B0B5B8, (double)cam->ref[0], (double)cam->ref[1], (double)cam->ref[2]);
        func_002EF240(D_01B0B5D0, (double)cam->dist, (double)cam->scr_dpt);
    } else if (t1 & 8) {
        if (D_01B0C7C0 >= 0) {
            D_01B0C7C0--;
        }
    } else if (!t1_2 && (t1 & 1)) {
        if (D_01B0C7C0 >= 0) {
            func_01B02928(cam, 0, D_01B0BFC0, D_01B0C7C0 + 1, 32);
            func_01B02928(cam, 1, D_01B0C2C0, D_01B0C7C0 + 1, 32);
            func_01B02C00(cam, D_01B0C5C0, D_01B0C7C0 + 1, 32);
            func_01B02C80(cam, D_01B0C6C0, D_01B0C7C0 + 1, 32);
        }
    }

    func_002DD038(vec, cam->ref, cam->eye);
    fptodp(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
    cam->dist = (float)func_002E9290((double)(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));

    func_002B41B0(D_01B0B5E8, (double)cam->pitch, (double)cam->yaw, (double)cam->roll);
    func_002B41B0(D_01B0B5F8, (double)cam->eye[0], (double)cam->eye[1], (double)cam->eye[2]);
    func_002B41B0(D_01B0B608, (double)cam->ref[0], (double)cam->ref[1], (double)cam->ref[2]);
    func_002B41B0(D_01B0B618, (double)cam->dist, (double)cam->scr_dpt);

    v70[0] = 0.0f;
    v70[1] = 0.0f;
    v70[2] = 0.0f;
    v70[3] = 1.0f;
    func_01B02420(v70);
    func_001A9EF0(D_01B0BAFC, 1, &v60[0], &v60[1], &v60[2]);
    v60[3] = 1.0f;
    v60[1] = 0.0f;
    func_002B41B0(D_01B0B4E0, (double)func_01B01DF8(v70, v60));

    for (i = 0; i <= D_01B0C7C0; i++) {
        Vec3 *p = &D_01B0BFC0[i];
        func_002B41B0(D_01B0B630, (double)p->x, (double)p->y, (double)p->z, (double)D_01B0C5C0[i]);
        p = &D_01B0C2C0[i];
        func_002B41B0(D_01B0B640, (double)p->x, (double)p->y, (double)p->z, (double)D_01B0C6C0[i]);
    }
    func_002B41B0(D_01B0B650);
}
