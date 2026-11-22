/* tu_133 0x184ea0-0x187260: low; ~yiPacketConvToOMD (config/tu_map.tsv) */
#include "common.h"
#include "ffx/v2.h"

typedef struct S2DmaCtl { u8 f0 : 1; u8 f1 : 1; u8 f2 : 2; u8 f4 : 2; u8 f6 : 1; u8 f7 : 1; } S2DmaCtl;
void Sg_MFIFOSync(void);
int func_002DA610(int a, int b); /* DEBT(TYPE): asm reads (int a); C callers c_2203B8.c:36 pass 2 */
u32 *func_002DB6D8(int a0);
extern void func_002DBB00(S2DmaCtl *ch, int a, int b);
int func_002DBF78(int a, int b, int c);
void func_002F8660();
void func_00184EA0(s32 arg0, s32 arg1) {
    s32 temp_2;

    Sg_MFIFOSync();
    func_002DA610(0, 0);
    temp_2 = func_002DB6D8(2);
    func_002DBF78(temp_2, 0, 0x100);
    *(volatile u8 *)(temp_2) |= 1;
    *(volatile u8 *)(temp_2) |= 0x40;
    *(volatile u8 *)(temp_2) &= 0x7F;
    *(u8 *)(temp_2) &= 0xF3;
    func_002F8660(0);
    func_002DBB00((S2DmaCtl *) temp_2, arg0, arg1);
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_00184F50);

void Sg_GetDBuffDC(void *p);

void func_00185408(void)
{
    u32 pkt[0x40];
    int dbuff;
    u32 fbp;
    u64 frame;
    u32 *p1, *p2, *p3;

    Sg_GetDBuffDC(&dbuff);
    if (dbuff & 1) {
        fbp = 0;
    } else {
        fbp = 0x34000;
    }
    frame = (fbp >> 11) | 0x01080000;

    pkt[0] = 0x8003;
    pkt[1] = 0x10000000;
    pkt[2] = 0xE;
    pkt[3] = 0;

    p1 = &pkt[4];
    p1[0] = (int)frame;
    p1[1] = (int)(frame >> 32);
    p1[2] = 0x4C;
    p1[3] = 0;

    p2 = &pkt[8];
    p2[0] = 0x02000000;
    p2[3] = 0;
    p2[2] = 0x40;
    p2[1] = 0x01A00000;

    p3 = &pkt[12];
    p3[0] = 0x7000;
    p3[3] = 0;
    p3[2] = 0x18;
    p3[1] = 0x7300;

    func_00184EA0((s32)pkt, 4);
}

typedef struct YiMesh1854D8 {
    s32 w00;
    s32 w04;
    s32 v_ofs;
    s32 w0C;
    u16 h10;
    s16 v_cnt;
} YiMesh1854D8;

extern float D_0056CF64;
extern float D_0056CF68;

int func_001854D8(YiMesh1854D8 *m, float *min, float *max)
{
    int i;
    int j;
    float *v;

    v = (float *)((u8 *)m + m->v_ofs);
    for (i = 0; i < 3; i++) {
        min[i] = D_0056CF64;
        max[i] = D_0056CF68;
    }
    min[3] = 1.0f;
    max[3] = 1.0f;
    for (i = 0; i < m->v_cnt; i++) {
        for (j = 0; j < 3; j++) {
            if (min[j] > v[j]) {
                min[j] = v[j];
            }
            if (max[j] < v[j]) {
                max[j] = v[j];
            }
        }
        v += 4;
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_001855C0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", yiPacketConvToOMD_DRAWACC);

extern u8 D_00597F00[];
extern char D_0056CF70[];
extern char D_0056CF80[];
extern char D_0056CF88[];
extern char D_0056CF90[];
extern char D_0056CF98[];
extern char D_0056CFA0[];
extern char D_0056CFA8[];
extern char D_0056CFB0[];
extern char D_0056CFB8[];
extern char D_0056CFC0[];
extern char D_0056CFC8[];
extern char D_0056CFD0[];
extern char D_0056CFD8[];
extern char D_0056CFE0[];

extern void *func_0011D678(int size);
extern void func_002EF0D0(void *dst, int val, int size);
extern void yiRender_setfogparam(void *p);
extern void yiRender_setupparamGS(void *p);
extern void *func_202F3B0(void *w);
extern void func_202F3A8(void *w, void *p);
extern void func_202F3F0(void *w, const char *s);
extern void func_202F768(void *w, int id, const char *s, int x, int y, int cw, int ch);
extern void func_202F740(void *w, int id, const char *s, int x, int y, int cw, int ch);
extern void func_202EEE0(void *w, int id, const char *s);
extern void func_20324F0(int y);
extern void func_20324B8(int x);
extern void func_2032970(const char *fmt, int v);

typedef struct {
    u8 pad00[0x67F20];
    u32 flags;
    u8 pad67F24[0x44C];
    u8 r;
    u8 g;
    u8 b;
    u8 pad68373;
    float f374;
    float f378;
    float f37C;
} YiFogCtx;

int yiGui_setfogparam_proc(void *win, int msg, int param)
{
    char buf[0x100];
    YiFogCtx *ctx;
    int v;

    func_202F3B0(win);
    switch (msg) {
    case 0x8001: {
        void *p = func_0011D678(0x54);
        func_002EF0D0(p, 0, 0x54);
        func_202F3A8(win, p);
        func_202F3F0(win, D_0056CF70);
        func_202F768(win, 1, D_0056CF80, 0, 0, 0x30, 0xA);
        func_202F740(win, 2, D_0056CF88, 0x40, 0, 0x10, 0xA);
        func_202F740(win, 3, D_0056CF90, 0x80, 0, 0x10, 0xA);
        func_202F768(win, 5, D_0056CF98, 0, 0xB, 0x30, 0xA);
        func_202F740(win, 6, D_0056CF88, 0x40, 0xB, 0x10, 0xA);
        func_202F740(win, 7, D_0056CF90, 0x80, 0xB, 0x10, 0xA);
        func_202F768(win, 9, D_0056CFA0, 0, 0x16, 0x30, 0xA);
        func_202F740(win, 0xA, D_0056CF88, 0x40, 0x16, 0x10, 0xA);
        func_202F740(win, 0xB, D_0056CF90, 0x80, 0x16, 0x10, 0xA);
        func_202F768(win, 0xD, D_0056CFA8, 0, 0x21, 0x30, 0xA);
        func_202F740(win, 0xE, D_0056CF88, 0x40, 0x21, 0x10, 0xA);
        func_202F740(win, 0xF, D_0056CF90, 0x80, 0x21, 0x10, 0xA);
        func_202F768(win, 0x11, D_0056CFB0, 0, 0x2C, 0x30, 0xA);
        func_202F740(win, 0x12, D_0056CF88, 0x40, 0x2C, 0x10, 0xA);
        func_202F740(win, 0x13, D_0056CF90, 0x80, 0x2C, 0x10, 0xA);
        func_202F768(win, 0x15, D_0056CFB8, 0, 0x37, 0x30, 0xA);
        func_202F740(win, 0x16, D_0056CF88, 0x40, 0x37, 0x10, 0xA);
        func_202F740(win, 0x17, D_0056CF90, 0x80, 0x37, 0x10, 0xA);
        func_202F740(win, 0x19, D_0056CFC0, 0, 0x42, 0x80, 0xA);
        if (((YiFogCtx *)D_00597F00)->flags & 8) {
            func_202EEE0(win, 0x19, D_0056CFC8);
        } else {
            func_202EEE0(win, 0x19, D_0056CFD0);
        }
        break;
    }
    case 0x8006:
        if (param == 0x19) {
            if (((YiFogCtx *)D_00597F00)->flags & 8) {
                ((YiFogCtx *)D_00597F00)->flags ^= 8;
            } else {
                ((YiFogCtx *)D_00597F00)->flags |= 8;
            }
        }
        if (((YiFogCtx *)D_00597F00)->flags & 8) {
            func_202EEE0(win, 0x19, D_0056CFC8);
        } else {
            func_202EEE0(win, 0x19, D_0056CFD0);
        }
        break;
    case 0x8005:
        switch (param) {
        case 2:
            if (((YiFogCtx *)D_00597F00)->r != 0) {
                ((YiFogCtx *)D_00597F00)->r--;
            }
            break;
        case 3:
            if (((YiFogCtx *)D_00597F00)->r < 0xFF) {
                ((YiFogCtx *)D_00597F00)->r++;
            }
            break;
        case 6:
            if (((YiFogCtx *)D_00597F00)->g != 0) {
                ((YiFogCtx *)D_00597F00)->g--;
            }
            break;
        case 7:
            if (((YiFogCtx *)D_00597F00)->g < 0xFF) {
                ((YiFogCtx *)D_00597F00)->g++;
            }
            break;
        case 0xA:
            if (((YiFogCtx *)D_00597F00)->b != 0) {
                ((YiFogCtx *)D_00597F00)->b--;
            }
            break;
        case 0xB:
            if (((YiFogCtx *)D_00597F00)->b < 0xFF) {
                ((YiFogCtx *)D_00597F00)->b++;
            }
            break;
        case 0xE:
            v = (int)((YiFogCtx *)D_00597F00)->f374;
            if (v > 0) {
                v--;
            }
            ((YiFogCtx *)D_00597F00)->f374 = (float)v;
            break;
        case 0xF:
            v = (int)((YiFogCtx *)D_00597F00)->f374;
            if (v < 0xFF) {
                v++;
            }
            ((YiFogCtx *)D_00597F00)->f374 = (float)v;
            break;
        case 0x12:
            v = (int)((YiFogCtx *)D_00597F00)->f378;
            if (v > 0) {
                v--;
            }
            ((YiFogCtx *)D_00597F00)->f378 = (float)v;
            break;
        case 0x13:
            v = (int)((YiFogCtx *)D_00597F00)->f378;
            if (v < 9999) {
                v++;
            }
            ((YiFogCtx *)D_00597F00)->f378 = (float)v;
            break;
        case 0x16:
            v = (int)((YiFogCtx *)D_00597F00)->f37C;
            if (v > 0) {
                v--;
            }
            ((YiFogCtx *)D_00597F00)->f37C = (float)v;
            break;
        case 0x17:
            v = (int)((YiFogCtx *)D_00597F00)->f37C;
            if (v < 9999) {
                v++;
            }
            ((YiFogCtx *)D_00597F00)->f37C = (float)v;
            break;
        }
        yiRender_setfogparam(D_00597F00);
        yiRender_setupparamGS(D_00597F00);
        break;
    case 0x8009:
        switch (param) {
        case 2:
            if (((YiFogCtx *)D_00597F00)->r > 10) {
                ((YiFogCtx *)D_00597F00)->r -= 10;
            } else {
                ((YiFogCtx *)D_00597F00)->r = 0;
            }
            break;
        case 3:
            if (((YiFogCtx *)D_00597F00)->r < 245) {
                ((YiFogCtx *)D_00597F00)->r += 10;
            } else {
                ((YiFogCtx *)D_00597F00)->r = 255;
            }
            break;
        case 6:
            if (((YiFogCtx *)D_00597F00)->g > 10) {
                ((YiFogCtx *)D_00597F00)->g -= 10;
            } else {
                ((YiFogCtx *)D_00597F00)->g = 0;
            }
            break;
        case 7:
            if (((YiFogCtx *)D_00597F00)->g < 245) {
                ((YiFogCtx *)D_00597F00)->g += 10;
            } else {
                ((YiFogCtx *)D_00597F00)->g = 255;
            }
            break;
        case 0xA:
            if (((YiFogCtx *)D_00597F00)->b > 10) {
                ((YiFogCtx *)D_00597F00)->b -= 10;
            } else {
                ((YiFogCtx *)D_00597F00)->b = 0;
            }
            break;
        case 0xB:
            if (((YiFogCtx *)D_00597F00)->b < 245) {
                ((YiFogCtx *)D_00597F00)->b += 10;
            } else {
                ((YiFogCtx *)D_00597F00)->b = 255;
            }
            break;
        case 0xE:
            v = (int)((YiFogCtx *)D_00597F00)->f374;
            if (v > 10) {
                v -= 10;
            } else {
                v = 0;
            }
            ((YiFogCtx *)D_00597F00)->f374 = (float)v;
            break;
        case 0xF:
            v = (int)((YiFogCtx *)D_00597F00)->f374;
            if (v < 245) {
                v += 10;
            } else {
                v = 255;
            }
            ((YiFogCtx *)D_00597F00)->f374 = (float)v;
            break;
        case 0x12:
            v = (int)((YiFogCtx *)D_00597F00)->f378;
            if (v > 10) {
                v -= 10;
            } else {
                v = 0;
            }
            ((YiFogCtx *)D_00597F00)->f378 = (float)v;
            break;
        case 0x13:
            v = (int)((YiFogCtx *)D_00597F00)->f378;
            if (v < 9989) {
                v += 10;
            } else {
                v = 9999;
            }
            ((YiFogCtx *)D_00597F00)->f378 = (float)v;
            break;
        case 0x16:
            v = (int)((YiFogCtx *)D_00597F00)->f37C;
            if (v > 10) {
                v -= 10;
            } else {
                v = 0;
            }
            ((YiFogCtx *)D_00597F00)->f37C = (float)v;
            break;
        case 0x17:
            v = (int)((YiFogCtx *)D_00597F00)->f37C;
            if (v < 9989) {
                v += 10;
            } else {
                v = 9999;
            }
            ((YiFogCtx *)D_00597F00)->f37C = (float)v;
            break;
        }
        yiRender_setfogparam(D_00597F00);
        yiRender_setupparamGS(D_00597F00);
        break;
    case 0x8011: {
        int val;
        func_20324F0(2);
        func_20324B8(0x54);
        func_2032970(D_0056CFD8, ((YiFogCtx *)D_00597F00)->r);
        func_20324F0(0xD);
        func_20324B8(0x54);
        func_2032970(D_0056CFD8, ((YiFogCtx *)D_00597F00)->g);
        func_20324F0(0x18);
        func_20324B8(0x54);
        func_2032970(D_0056CFD8, ((YiFogCtx *)D_00597F00)->b);
        val = (int)((YiFogCtx *)D_00597F00)->f374;
        func_20324F0(0x23);
        func_20324B8(0x54);
        func_2032970(D_0056CFE0, val);
        val = (int)((YiFogCtx *)D_00597F00)->f378;
        func_20324F0(0x2E);
        func_20324B8(0x54);
        func_2032970(D_0056CFE0, val);
        val = (int)((YiFogCtx *)D_00597F00)->f37C;
        func_20324F0(0x39);
        func_20324B8(0x54);
        func_2032970(D_0056CFE0, val);
        break;
    }
    }
    return 0;
}

__asm__(".text\n.space 0xAC");
INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_00186C00);
