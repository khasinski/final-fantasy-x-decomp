/* Battle-effect overlay 09530: 0x01B00BB8..0x01B015E0 (17 functions) */
#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern void *D_006A3BCC;

extern u8 D_01B00040[];
extern u8 D_01B00428[];
extern u8 D_01B00440[];
extern int D_01B00470;
extern int D_01B00474;
extern int D_01B00478;
extern void *D_01B0047C;
extern void *D_01B00480;
extern void *D_01B00484;
extern void *D_01B00488;
extern int D_01B0048C;
extern void *D_01B00490;
extern TtCfg *D_01B00494;
extern TtHeap D_01B00498;
extern PppObj D_01B004D0;
extern PppObj D_01B00550;
extern PppObj D_01B005D0;
extern int D_01B00950;
extern int D_01B00954;
extern u8 D_01B00958[];
extern u8 D_01B00A68[];
extern float D_01B00B80[4];
extern float D_01B00B90[4];
extern float D_01B00BA0[4];
extern char D_01B01A10[];
extern char D_01B01A20[];
extern char D_01B01A38[];
extern char D_01B01A50[];
extern char D_01B01A68[];
extern char D_01B01A78[];
extern char D_01B01A88[];
extern char D_01B01A98[];
extern char D_01B01AA8[];
extern u8 D_01B01B00[];
extern u8 D_01B3C7A0[];

int func_01B016A0(char *, ...);
void func_01B016D0(char *);
void func_01B01740(void *, void *, int);
void func_01B017F0(void *);
int func_01B01948(void *);
void func_00267530(void *);
void func_002675B0(void *);
void func_00267658(void *, int, int, int);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, int);
void func_00267FA0(void *, int);
void func_00107428(int, int, int, float *);
void func_00108910(int, int, float *);
void func_001AACA0(void *);
void func_001A9EE0(void *);
void func_002DCE38(void *, void *, void *);
void func_002B4980(void *);
void func_002D02E8(void *, int, int, int);
TtCfg *func_002B49A0(void *, int, int);
int func_0013B0F8(int);
int func_0029B830(int);
void func_001CDC58(int, int);
int func_001CDAF8(int);
int func_00116068(void);
int func_0014AA50(int);
void func_001CDDD8(int);

int func_01B00BB8(void)
{
    return 1;
}

int func_01B00BC0(void)
{
    func_01B016A0(D_01B01A10);
    D_006A3924 = &D_01B00498;
    func_00267658(&D_01B004D0, 0x1000, D_01B00494->w10[0], 1);
    D_01B004D0.pos[0] = 0.0f;
    D_01B004D0.pos[1] = 0.0f;
    D_01B004D0.pos[2] = 0.0f;
    D_01B004D0.pos[3] = 1.0f;
    D_01B004D0.rot[0] = 0;
    D_01B004D0.rot[1] = 0;
    D_01B004D0.rot[2] = 0;
    D_01B004D0.rot[3] = 1;
    D_01B004D0.scale[2] = D_01B004D0.scale[1] = D_01B004D0.scale[0] = 0.0125f;
    D_01B004D0.scale[3] = 1.0f;
    return 1;
}

int func_01B00C70(void)
{
    func_00107428(D_01B00950, 0x66, 0, D_01B00B80);
    D_01B00B80[1] -= 0.2f;
    D_006A3924 = &D_01B00498;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B004D0.pos[0] = D_01B00B80[0];
    D_01B004D0.pos[1] = D_01B00B80[1];
    D_01B004D0.pos[2] = D_01B00B80[2];
    func_002675B0(&D_01B004D0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00498;
    func_00267FA0(&D_01B004D0, 0x30);
    return 1;
}

int func_01B00D90(void)
{
    D_006A3924 = &D_01B00498;
    func_00267530(&D_01B004D0);
    func_01B016A0(D_01B01A20, D_01B00954);
    return 1;
}

int func_01B00DD8(void)
{
    func_01B016A0(D_01B01A38, D_01B00954);
    D_006A3924 = &D_01B00498;
    func_00267658(&D_01B00550, 0x1000, D_01B00494->w10[1], 1);
    D_01B00550.pos[0] = 0.0f;
    D_01B00550.pos[1] = 0.0f;
    D_01B00550.pos[2] = 0.0f;
    D_01B00550.pos[3] = 1.0f;
    D_01B00550.rot[0] = 0;
    D_01B00550.rot[1] = 0;
    D_01B00550.rot[2] = 0;
    D_01B00550.rot[3] = 1;
    D_01B00550.scale[2] = D_01B00550.scale[1] = D_01B00550.scale[0] = 0.03125f;
    D_01B00550.scale[3] = 1.0f;
    func_00108910(D_01B00950, 6, D_01B00B90);
    return 1;
}

int func_01B00EA0(void)
{
    D_006A3924 = &D_01B00498;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B00550.pos[0] = D_01B00B90[0];
    D_01B00550.pos[1] = D_01B00B90[1] - 0.5f + 0.2f;
    D_01B00550.pos[2] = D_01B00B90[2] + 1.0f;
    func_002675B0(&D_01B00550);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00498;
    func_00267FA0(&D_01B00550, 0x30);
    return 1;
}

int func_01B00FB0(void)
{
    D_006A3924 = &D_01B00498;
    func_00267530(&D_01B00550);
    func_01B016A0(D_01B01A50);
    return 0;
}

int func_01B00FF0(void)
{
    func_01B016A0(D_01B01A68);
    D_006A3924 = &D_01B00498;
    func_00267658(&D_01B005D0, 0x1000, D_01B00494->w10[2], 1);
    D_01B005D0.pos[0] = 0.0f;
    D_01B005D0.pos[1] = 0.0f;
    D_01B005D0.pos[2] = 0.0f;
    D_01B005D0.pos[3] = 1.0f;
    D_01B005D0.rot[0] = 0;
    D_01B005D0.rot[1] = 0;
    D_01B005D0.rot[2] = 0;
    D_01B005D0.rot[3] = 1;
    D_01B005D0.scale[2] = D_01B005D0.scale[1] = D_01B005D0.scale[0] = 0.0234375f;
    D_01B005D0.scale[3] = 1.0f;
    func_00108910(D_01B00950, 6, D_01B00BA0);
    return 1;
}

int func_01B010B0(void)
{
    D_006A3924 = &D_01B00498;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_01B005D0.pos[0] = D_01B00BA0[0];
    D_01B005D0.pos[1] = D_01B00BA0[1] - 0.2f - 0.1f;
    D_01B005D0.pos[2] = D_01B00BA0[2] + 1.0f;
    func_002675B0(&D_01B005D0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00498;
    func_00267FA0(&D_01B005D0, 0x30);
    return 1;
}

int func_01B011C8(void)
{
    D_006A3924 = &D_01B00498;
    func_00267530(&D_01B005D0);
    func_01B016A0(D_01B01A78);
    return 0;
}

int func_01B01208(int a0)
{
    u8 *mem = D_01B3C7A0;

    D_01B0047C = mem;
    D_01B00480 = mem + 0x80000;
    D_01B00484 = (u8 *)D_01B00480 + 0x80000;
    func_01B016A0(D_01B01A88);
    D_01B0048C = a0;
    D_01B00490 = D_01B01B00;
    func_002B4980(D_01B01B00);
    func_002D02E8(D_01B00490, 0, 1000, 0x2000);
    D_01B00494 = func_002B49A0(D_01B00490, 8, 0);
    func_002678E0(D_01B00494, D_01B00040);
    func_00267A68(&D_01B00498, D_01B00494, D_01B0047C, 0x80000);
    D_01B00498.w20 = D_01B00494->w14;
    D_01B00498.w24 = D_01B00494->w18;
    D_01B00498.w28 = D_01B00494->w1c;
    func_01B01740(D_01B00958, D_01B00428, 1);
    func_01B01740(D_01B00A68, D_01B00440, 2);
    D_01B00950 = func_0013B0F8(0);
    if (D_01B00950 == 0) {
        func_01B016D0(D_01B01A98);
    }
    return 1;
}

int func_01B01360(void)
{
    return 1;
}

int func_01B01368(void)
{
    return 1;
}

int func_01B01370(void)
{
    if (D_01B00470 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00470++;
    }
    if (D_01B00474 == 0) {
        D_01B00474 = 1;
        func_001CDC58(D_01B0048C, 0);
    }
    if (D_01B00478 == 0) {
        if (func_001CDAF8(D_01B0048C) > 0) {
            return ++D_01B00478;
        }
        return 1;
    }
    return D_01B00478;
}

void func_01B01418(void)
{
    int i;

    i = 1000000;
    do { i--; __asm__ volatile("nop"); } while (i != 0);
    i = 1000000;
    do { i--; __asm__ volatile("nop"); } while (i != 0);
    i = 1000000;
    do { i--; __asm__ volatile("nop"); } while (i != 0);
    i = 1000000;
    do { i--; __asm__ volatile("nop"); } while (i != 0);
    i = 1000000;
    do { i--; __asm__ volatile("nop"); } while (i != 0);
}

int func_01B014E8(void)
{
    int pad[4]; /* DEBT(PADDING): match 0x20 stack frame */
    __asm__ volatile("" : : "r"(pad)); /* DEBT(FAKE): keep pad on stack */
    if (func_00116068() == 0 || D_01B00478 == 0) {
        return 0;
    }
    D_006A3BCC = D_01B00480;
    D_01B00488 = D_01B00484;
    if (func_0014AA50(1) != 0) {
        func_01B017F0(D_01B00958);
    }
    if (func_0014AA50(2) != 0) {
        func_01B017F0(D_01B00A68);
    }
    if (func_0014AA50(3) != 0) {
        func_01B01948(D_01B00958);
        func_01B01948(D_01B00A68);
        func_01B016A0(D_01B01AA8, D_01B00954);
        func_001CDDD8(D_01B0048C);
        return 1;
    }
    D_01B00954++;
    return 1;
}

int func_01B015D0(void)
{
    return 1;
}

int func_01B015D8(void)
{
    return 1;
}
