#include "common.h"

typedef struct CamSlot {
    u8 pad00[0x88];
    float roll;        /* 0x88 */
    u8 pad8C[4];
    float eye[4];      /* 0x90 */
    float ref[4];      /* 0xA0 */
    u8 padB0[0xD0];
    float scr_dpt;     /* 0x180 */
    int active;        /* 0x184 */
    u8 mode;           /* 0x188 */
    s8 pad189;         /* 0x189 */
    s8 use_mtx;        /* 0x18A */
    u8 pad18B[5];
} CamSlot;             /* 0x190 */

extern char D_01B0ADF0[];
extern char D_01B0AE10[];
extern char D_01B0AE20[];
extern char D_01B0AE30[];
extern int D_01B0B41C;
extern int D_01B0B420;
extern CamSlot D_01B0B430[];

int Sg_GetCurExecFrames(void);
void func_01B03860(void *, void *);
void func_01B03E70(void *, void *);
void func_01B04030(void *, void *);
void func_01B04248(void *);
void func_002EF240(const char *, ...);
void func_01B01510(int, const char *, int);
void func_002DCE08(void *, void *, void *);
void MsCameraSetRect(int, int, void *);
void MsCameraSetRoll(int, float);
void MsCameraSetScrDpt(int, float);
void func_01B021C8(void *);
void func_001A9EF0(int, int, float *, float *, float *);
float func_01B01BA0(void *, void *);
void func_002B41B0(const char *, ...);

static inline void copy_vec(void *dst, void *src)
{
    *(u_long128 *)dst = *(u_long128 *)src;
}

void func_01B02368(CamSlot *s)
{
    float eye[4] __attribute__((aligned(16)));
    float ref[4] __attribute__((aligned(16)));
    int cam;

    if (Sg_GetCurExecFrames() != 0) {
        u8 mode;
        func_01B03860((u8 *)s + 0xF0, s->ref);
        func_01B03860((u8 *)s + 0xB0, s->eye);
        func_01B03E70((u8 *)s + 0x130, &s->roll);
        func_01B04030((u8 *)s + 0x14C, &s->scr_dpt);
        mode = s->mode;
        if (mode != 0) {
            if (mode == 1) {
                func_01B04248(s);
            } else {
                func_002EF240(D_01B0ADF0, mode);
                func_01B01510(14, D_01B0AE10, 305);
            }
        }
    }
    if (s->active == 1) {
        float *rp;
        if (s->use_mtx == 0) {
            register u_long128 *src __asm__("$2") = (u_long128 *)s->eye;
            register u_long128 _t __asm__("$7");
            __asm__ volatile("" : "+r"(src));
            _t = *src;
            *(u_long128 *)eye = _t;
            __asm__ volatile("");
            rp = ref;
            __asm__ volatile("" : "+r"(rp));
            src = (u_long128 *)s->ref;
            __asm__ volatile("" : "+r"(src));
            _t = *src;
            *(u_long128 *)rp = _t;
            __asm__ volatile("");
        } else {
            func_002DCE08(eye, s, s->eye);
            rp = ref;
            func_002DCE08(rp, s, s->ref);
        }
        cam = D_01B0B41C;
        MsCameraSetRect(cam, 1, eye);
        MsCameraSetRect(cam, 0, rp);
        MsCameraSetRoll(cam, s->roll);
        MsCameraSetScrDpt(cam, s->scr_dpt);
        ref[0] = 0.0f;
        ref[1] = 0.0f;
        ref[2] = 0.0f;
        ref[3] = 1.0f;
        func_01B021C8(rp);
        func_001A9EF0(D_01B0B41C, 1, &eye[0], &eye[1], &eye[2]);
        eye[3] = 1.0f;
        eye[1] = 0.0f;
        func_002B41B0(D_01B0AE20, (double)func_01B01BA0(rp, eye));
    }
}
