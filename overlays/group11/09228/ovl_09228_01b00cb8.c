#include "common.h"

typedef float Vec4[4] __attribute__((aligned(16)));
typedef Vec4 Mat4[4] __attribute__((aligned(16)));

typedef struct Ovl09228DrawObj {
    u8 pad00[0x1E];
    u16 h1E;
    u8 pad20[0x40];
    float f60[4];
} Ovl09228DrawObj;

typedef struct Ovl09228Light {
    u8 pad00[0x20];
    s32 w20;
    s32 w24;
    s32 w28;
} Ovl09228Light;

typedef struct Ovl09228Work2620 {
    u8 pad00[0x14];
    s32 w14;
    s32 w18;
    s32 w1C;
} Ovl09228Work2620;

extern s32 D_01B00450;
extern s32 D_01B00454;
extern s32 D_01B00458;
extern double D_01B01918;
extern double D_01B01920;
extern s32 D_01B01940;
extern s32 D_01B01944;
extern s32 D_01B01948;
extern s32 D_01B0194C;
extern s32 D_01B01950;
extern Ovl09228DrawObj D_01B01960;
extern Ovl09228DrawObj D_01B019E0;
extern Ovl09228DrawObj D_01B01A60;
extern Ovl09228DrawObj D_01B01AE0;
extern Ovl09228Light D_01B01B60;
extern u8 D_01C01BC0[];

extern s32 D_01D023C0;
extern s32 D_01D023C4;
extern s32 D_01D023C8;
extern s32 D_01D023CC;
extern s32 D_01D023D0;
extern s16 D_01D023DC;
extern Vec4 D_01D023F0;
extern Vec4 D_01D02400;
extern Vec4 D_01D02410;
extern Vec4 D_01D02420;
extern Vec4 D_01D02430;
extern Mat4 D_01D02440;
extern Mat4 D_01D02480;
extern Mat4 D_01D024C0;
extern Mat4 D_01D02500;
extern Mat4 D_01D02580;
extern Mat4 D_01D025C0;
extern float D_01D02600;
extern Ovl09228Work2620 D_01D02620;

extern float D_004F4610[];
extern void *D_006A3924;
extern Mat4 D_006A3930;
extern Mat4 D_006A3970;
extern Mat4 D_006A39B0;
extern Mat4 D_006A3A70;
extern Mat4 D_006A3AB0;
extern void *D_006A3BCC;

void func_001072F8(s32, s32, void *);
void func_00107428(s32, s32, s32, void *);
void func_00110830(s32, void *);
void func_001A9EE0(void *);
void func_001AACA0(void *);
void func_001B57F0(s32, s32);
void func_001C5E90(s32, s32, s32);
s32 func_001CDAF8(s32);
void func_001CDC58(s32, s32);
void func_001CDDD8(s32);
void func_001CE050(s32, s32);
void func_001CE2F0(s32, s32);
s32 func_001DC7C0(s32);
s32 func_00267FA0(void *, s32);
void func_0026BDE0(void *, s32);
void func_0026BEB0(void *, s32);
s32 func_00294B70(s32, s32, s32);
s32 func_0029B830(s32);
void func_002DCE08(void *, void *, void *);
void func_002DCE38(void *, void *, void *);
void func_002DCEC8(void *, void *);
void func_002DCFF8(void *, void *, void *, float);
void func_002DD038(void *, void *, void *);
void func_002DD068(void *, void *, float);
void func_002DD0C0(void *, void *);
void func_002DD128(void *);

void func_01B004E0(void);
void func_01B00660(void *, s32, float, float);

s32 func_01B00CB8(void)
{
    Vec4 v0;
    Vec4 v1;
    Mat4 tmpMtx;
    Mat4 rotMtx;
    s32 frame;
    s32 t0;
    s32 t1;
    s32 t2;

    if (D_01B00450 == 0) {
        if (func_0029B830(D_01B01940) != 0) {
            return 0;
        }
        D_01B00450++;
    }
    if (D_01B00454 == 0) {
        D_01B00454 = 1;
        func_001CDC58(D_01B01940, 0);
    }
    if (D_01B00458 == 0) {
        if (func_001CDAF8(D_01B01940) <= 0) {
            return 0;
        }
        D_01B00458++;
    }

    if (D_01D023C0 == 0x47) {
        func_001CE050(D_01D023C4, 0xB8);
    } else if (D_01D023C0 == 0x10E) {
        func_001CE2F0(D_01D023C4, 0);
    }

    frame = D_01D023C0;
    t2 = frame - 0xF1;
    t1 = frame - 0xDD;
    t0 = frame - 0x83;
    if (t0 >= 0 || t1 >= 0 || t2 >= 0) {
        if (t0 >= 0) {
            func_00107428(D_01D023CC, 0xA8, 0, &v0);
            func_00107428(D_01D023CC, 0xEB, 0, &v1);
            D_01D02420[0] = (v0[0] + v1[0]) * 0.5;
            D_01D02420[1] = (v0[1] + v1[1]) * 0.5;
            D_01D02420[2] = (v0[2] + v1[2]) * 0.5;
            D_01D02420[3] = 1.0f;

            func_001072F8(D_01D023CC, 0x2D, &D_01D02440);
            func_002DD068(D_01D02440[0], D_01D02440[0], 100.0f);
            func_002DD068(D_01D02440[1], D_01D02440[1], 100.0f);
            func_002DD068(D_01D02440[2], D_01D02440[2], 100.0f);

            if (D_01B01AE0.h1E != 0) {
                func_0026BEB0(&tmpMtx, 0x4000);
                func_002DCE38(&D_01D02500, &D_01D02440, &tmpMtx);
                func_0026BDE0(&tmpMtx, -0x4000);
                func_002DCE38(&D_01D02500, &D_01D02500, &tmpMtx);
                func_0026BEB0(&tmpMtx, 0x8000);
                func_002DCE38(&D_01D02500, &D_01D02500, &tmpMtx);
                *(u_long128 *)D_01D02500[3] = *(u_long128 *)D_01D02420;
            }
            if (D_01B01960.h1E != 0) {
                func_0026BEB0(&tmpMtx, 0x4000);
                func_002DCE38(&D_01D02440, &D_01D02440, &tmpMtx);
                *(u_long128 *)D_01D02440[3] = *(u_long128 *)D_01D02420;
            }
        }

        if (t1 == 0) {
            func_001B57F0(D_01D023C8, 1);
            {
                register u_long128 q __asm__("$2") = *(u_long128 *)D_01D02420;
                *(u_long128 *)D_01D02430 = q;
            }
            func_002DCFF8(D_01D02400, D_01D023F0, D_01D02430, 0.7f);
            D_01D02400[1] = D_01D023F0[1];
            func_002DD038(&tmpMtx, D_01D023F0, D_01D02430);
            tmpMtx[0][1] = 0.0f;
            func_002DCEC8(&tmpMtx, &tmpMtx);
            func_002DD068(D_01D02410, &tmpMtx, 20.0f);
            func_002DD128(&D_01D02480);
            *(u_long128 *)D_01D02480[3] = *(u_long128 *)D_01D02400;
            D_01D02480[3][1] -= 0.1f;
            D_01D02480[3][3] = 1.0f;
            func_001CE050(D_01D023C8, 0x22);
        }
        if ((u32)t1 < 0x14) {
            float ft = (float)t1 / 20.0f + 0.1f;
            float ft2;
            float y;

            func_002DD128(&D_01D024C0);
            func_002DCFF8(D_01D024C0[3], D_01D02400, D_01D02430, ft);
            ft2 = ft * ft;
            D_01D024C0[3][3] = 1.0f;
            D_01D024C0[3][1] = (D_01D02400[1] - D_01D02430[1]) * ft2 + D_01D02430[1];
            if (t1 == 0x13) {
                func_001CE050(D_01D023C8, 0x49);
            }
            func_0026BDE0(&rotMtx, D_01D023DC);
            func_002DCE38(&D_01D02580, &D_01D025C0, &rotMtx);
            tmpMtx[1][0] = tmpMtx[1][2] = 0.0f;
            tmpMtx[1][1] = D_01D02600 * 100.0f;
            tmpMtx[1][3] = 1.0f;
            func_002DCE08(tmpMtx[1], &D_01D02580, tmpMtx[1]);
            y = tmpMtx[1][1] - D_01D02600;
            tmpMtx[1][1] = y;
            D_01D02580[3][0] = D_01D024C0[3][0] + tmpMtx[1][0];
            D_01D02580[3][1] = D_01D024C0[3][1] + y + D_01D02600 * (1.0f - ft2);
            D_01D02580[3][2] = D_01D024C0[3][2] + tmpMtx[1][2];
            D_01D02580[3][3] = 1.0f;
            func_00110830(D_01D023D0, &D_01D02580);
        }

        if ((u32)t2 < 0x14) {
            float ft = (float)t2 / 20.0f;
            float s = D_004F4610[((u32)(s32)(ft * ft * 98304.0f) >> 4) & 0xFFF];
            float inv2;

            if (s < 0.0f) {
                s = -s;
            }
            func_002DD0C0(&D_01D02580, &D_01D025C0);
            ft = 1.0f - ft;
            inv2 = ft * ft;
            func_002DCFF8(D_01D02580[3], D_01D02400, D_01D023F0, inv2);
            tmpMtx[2][0] = D_01D02580[3][0] + D_01D02410[0];
            tmpMtx[2][1] = D_01D02580[3][1];
            tmpMtx[2][2] = D_01D02580[3][2] + D_01D02410[2];
            func_01B00660(tmpMtx[2], 2, 15.0f, (float)((ft + 0.1) * 0.2));
            D_01D02580[3][1] -= s * inv2 * 10.0f;
            if (t2 == 0xA) {
                func_001C5E90(D_01B01940, -5, 6);
            }
        } else if (t2 == 0x14) {
            func_00110830(D_01D023D0, 0);
            func_001CE050(D_01D023C8, 0x4A);
        }
    }

    D_01D023DC -= 0x1000;
    return 0;
}

