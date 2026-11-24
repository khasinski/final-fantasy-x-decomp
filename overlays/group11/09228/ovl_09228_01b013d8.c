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

s32 func_01B013D8(void)
{
    s32 frame;
    s32 t0;
    s32 t1;
    register s32 t2 __asm__("$23");

    if (D_01B00458 == 0) {
        return 0;
    }

    if (D_01D023C0 == 0x83) {
        func_00294B70(D_01B01944, 0x40, 0x100);
        func_00294B70(D_01B01948, 0x40, 0x100);
    }
    if (D_01D023C0 == 0xD3) {
        func_00294B70(D_01B0194C, 0x40, 0x100);
        func_00294B70(D_01B01950, 0x40, 0x100);
    }

    frame = D_01D023C0;
    t1 = frame - 0xDD;
    t0 = frame - 0x83;
    t2 = frame - 0xF1;
    if (t0 >= 0 || t1 >= 0 || t2 >= 0) {
        D_01B01B60.w20 = D_01D02620.w14;
        D_01B01B60.w24 = D_01D02620.w18;
        D_01B01B60.w28 = D_01D02620.w1C;
        D_006A3924 = &D_01B01B60;
        func_001AACA0(&D_006A3A70);
        func_001A9EE0(&D_006A3970);
        D_006A3BCC = D_01C01BC0;

        if (t0 >= 0 && D_01B01AE0.h1E != 0) {
            D_01B01AE0.f60[0] = D_01B01AE0.f60[1] = D_01B01AE0.f60[2] = D_01B01AE0.f60[3] = 0.8f;
            func_002DD068(D_006A3930[0], D_01D02500[0], D_01B01AE0.f60[0]);
            func_002DD068(D_006A3930[1], D_01D02500[1], D_01B01AE0.f60[1]);
            func_002DD068(D_006A3930[2], D_01D02500[2], D_01B01AE0.f60[2]);
            *(u_long128 *)D_006A3930[3] = *(u_long128 *)D_01D02500[3];
            func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
            func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
            D_006A3924 = &D_01B01B60;
            if (func_00267FA0(&D_01B01AE0, 0x30) != 0) {
                D_01B01AE0.h1E = 0;
            }
        }
        if (t1 >= -5 && D_01B01960.h1E != 0) {
            D_01B01960.f60[0] = D_01B01960.f60[1] = D_01B01960.f60[2] = D_01B01960.f60[3] = 1.0f;
            func_002DD068(D_006A3930[0], D_01D02440[0], D_01B01960.f60[0]);
            func_002DD068(D_006A3930[1], D_01D02440[1], D_01B01960.f60[1]);
            func_002DD068(D_006A3930[2], D_01D02440[2], D_01B01960.f60[2]);
            *(u_long128 *)D_006A3930[3] = *(u_long128 *)D_01D02440[3];
            func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
            func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
            D_006A3924 = &D_01B01B60;
            if (func_00267FA0(&D_01B01960, 0x30) != 0) {
                D_01B01960.h1E = 0;
            }
        }
        if (t1 >= 0 && D_01B01A60.h1E != 0) {
            D_01B01A60.f60[0] = D_01B01A60.f60[1] = D_01B01A60.f60[2] = D_01B01A60.f60[3] = 1.0f;
            func_002DD068(D_006A3930[0], D_01D024C0[0], D_01B01A60.f60[0]);
            func_002DD068(D_006A3930[1], D_01D024C0[1], D_01B01A60.f60[1]);
            func_002DD068(D_006A3930[2], D_01D024C0[2], D_01B01A60.f60[2]);
            *(u_long128 *)D_006A3930[3] = *(u_long128 *)D_01D024C0[3];
            func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
            func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
            D_006A3924 = &D_01B01B60;
            if (func_00267FA0(&D_01B01A60, 0x30) != 0) {
                D_01B01A60.h1E = 0;
            }
        }
        if (t2 >= 0 && D_01B019E0.h1E != 0) {
            D_01B019E0.f60[0] = D_01B019E0.f60[1] = D_01B019E0.f60[2] = D_01B019E0.f60[3] = 1.0f;
            func_002DD068(D_006A3930[0], D_01D02480[0], D_01B019E0.f60[0]);
            func_002DD068(D_006A3930[1], D_01D02480[1], D_01B019E0.f60[1]);
            func_002DD068(D_006A3930[2], D_01D02480[2], D_01B019E0.f60[2]);
            *(u_long128 *)D_006A3930[3] = *(u_long128 *)D_01D02480[3];
            func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
            func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
            D_006A3924 = &D_01B01B60;
            if (func_00267FA0(&D_01B019E0, 0x30) != 0) {
                D_01B019E0.h1E = 0;
            }
        }
        if (t2 >= 0) {
            func_002DD0C0(&D_006A39B0, &D_006A3970);
            func_01B004E0();
        }
    }

    if (D_01D023C0 >= 0x11E && func_001DC7C0(D_01D023C8) != 0) {
        func_001CE2F0(D_01D023C4, 0);
        func_001CE2F0(D_01D023C8, 4);
        func_001CDDD8(D_01B01940);
    }

    D_01D023C0++;
    return 0;
}
