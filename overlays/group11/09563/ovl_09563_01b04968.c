#include "common.h"

typedef struct {
    u8 f00;
    u8 pad01[3];
    int f04;
    int f08;
    u8 pad0C[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    u8 buf20[0x1E];
    u16 f3E;
    u8 pad40[0x60];
} OvlObj;

typedef struct {
    u8 pad00[0x10];
    OvlObj objs[12];
} OvlGroup;

extern float D_006A3970[16];
extern float D_006A3A70[16];
extern void *D_006A3924;
extern int D_006A3BC4;
extern void *D_006A3BCC;

extern u8 D_01B00040;
extern u8 D_01B008B0;
extern int D_01B009A4;
extern int D_01B009A8;
extern int D_01B009AC;
extern u8 D_01B00A30;
extern int D_01B06060;
extern u8 D_01B06068;
extern OvlGroup D_01B060A0[2];
extern u8 D_01B06830;
extern void *D_01B06FC0;
extern int D_01B06FC4;
extern int D_01B06FC8;
extern int D_01B06FCC;
extern int D_01B06FD0;
extern int D_01B06FD4;
extern int D_01B06FD8;
extern int D_01B06FDC;
extern int D_01B06FE0;
extern int D_01B06FE4;
extern int D_01B06FE8;
extern u8 D_01B06FF0;
extern int D_01B07014;
extern int D_01B07CD4;
extern u8 D_01B07CF0;
extern u8 D_01D07390;
extern u8 D_01D87790;

extern int func_00116068(void);
extern int func_0014AA50(int);
extern void func_00173520(void *);
extern void func_00173650(void *);
extern void func_00173A70(int);
extern void func_00173A90(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(int);
extern void func_001CDC58(int, int);
extern void func_001CDDD8(int);
extern void func_001CE9A8(int);
extern int func_001CEA70(int, int, int);
extern void func_00267530(void *);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_0026AA10(void *, void *, int);
extern void func_0026BE48(void *, int);
extern int func_0029B830(int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002DCE08(void *, void *, void *);

extern void func_01B00A90(void *, int, float, float, float, float, float, float, float, float, float);
extern void func_01B01B08(void);
extern void func_01B03B40(void *, int);
extern void func_01B04050(void *);
extern void func_01B04090(void);
extern void func_01B040A0(void);
extern void func_01B04178(int);
extern void func_01B04350(int, int, int, int, int, int, int, int);
extern void func_01B04498(void *, int);
extern void func_01B04500(void *);
extern void func_01B047C8(void);
extern void func_01B04820(void);

void func_01B04968(void *a0, float *a1, int a2) {
    float mat[16];
    func_0026BE48(mat, -a2 - 0x4000);
    a1[3] = 1.0f;
    func_002DCE08(a0, mat, a1);
}

void func_01B049C0(OvlObj *a0, int a1, int a2, int a3, int a4,
                   float f0, float f1, float f2, float f3, float f4, float f5,
                   float f6, float f7, float f8) {
    a0->f00 = a2;
    a0->f04 = a3;
    a0->f08 = a4;
    a0->f10 = f0;
    a0->f14 = f1;
    a0->f18 = f2;
    a0->f1C = 1.0f;
    func_01B00A90(a0->buf20, a1, f0, f1, f2, f3, f4, f5, f6, f7, f8);
}

void func_01B04A10(OvlObj *a0) {
    if (a0->f3E != 0) {
        D_006A3924 = &D_01B06068;
        func_00267530(a0->buf20);
        a0->f3E = 0;
    }
}

void func_01B04A58(void) {
    int i, j;
    OvlGroup *g = D_01B060A0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 12; j++) {
            g->objs[j].f3E = 0;
        }
        g++;
    }
    func_0026AA10(&D_01B06068, &D_01D07390, 0x80000);
}

int func_01B04AC0(void) {
    u8 pad[0x50];
    (void)pad;
    if (D_01B009A4 == 0) {
        if (func_0029B830(D_01B06060) != 0) {
            return 0;
        }
        D_01B009A4++;
    }
    if (D_01B009A8 == 0) {
        D_01B009A8 = 1;
        func_001CDC58(D_01B06060, 0);
    }
    if (D_01B009AC == 0) {
        if (func_001CDAF8(D_01B06060) <= 0) {
            return 0;
        }
        D_01B009AC++;
    }
    if (D_01B06FC8 == 0) {
        D_01B06FC8 = 1;
        func_002678E0(&D_01B07CF0, &D_01B00040);
        func_00267A68(&D_01B06068, &D_01B07CF0, &D_01D07390, 0x80000);
    }

    if (func_0014AA50(7) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FE8++;
        }
    } else if (func_0014AA50(6) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FE4++;
        }
    } else if (func_0014AA50(5) != 0) {
        if (D_006A3BC4 == 0) {
            if (++D_01B06FE0 == 10) {
                func_01B04498(&D_01B06830, 0x1084);
            }
        }
    } else if (func_0014AA50(4) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FDC++;
            D_01B06FD8++;
        }
    } else if (func_0014AA50(3) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FD8++;
        }
    } else if (func_0014AA50(2) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FD4++;
        }
    } else if (func_0014AA50(1) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FCC++;
            D_01B06FD0++;
        }
    } else if (func_0014AA50(0) != 0) {
        if (D_006A3BC4 == 0) {
            D_01B06FCC++;
        }
    }

    if (D_006A3BC4 == 0) {
        if (D_01B06FCC == 0x64) {
            func_01B049C0(&D_01B060A0[0].objs[0], 0, 0, -1, -1,
                          0.08083400130271912f, 0.0f, -52.57814025878906f,
                          0.0f, 0.0f, 0.0f, 0.052f, 0.052f, 0.052f);
        } else if (D_01B06FCC == 0x87) {
            func_01B049C0(&D_01B060A0[0].objs[1], 1, 0, -1, -1,
                          -0.903922975063324f, 0.0f, -54.75206756591797f,
                          0.0f, 0.0f, 0.0f, 0.04f, 0.04f, 0.04f);
        } else if (D_01B06FCC == 0x8A) {
            func_01B049C0(&D_01B060A0[0].objs[2], 2, 0, 0x44, 0x45,
                          -0.9999989867210388f, -1.0f, -1.8f,
                          0.0f, 0.0f, 0.0f, 0.021f, 0.021f, 0.021f);
        } else if (D_01B06FCC == 0x122) {
            func_01B04A58();
            func_01B049C0(&D_01B060A0[0].objs[0], 4, 1, 0x20, -1,
                          16.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
            func_01B049C0(&D_01B060A0[0].objs[1], 3, 0, -1, -1,
                          -0.8191660046577454f, -17.89988899230957f, -54.17824172973633f,
                          0.0f, 0.0f, 0.0f, 0.031f, 0.031f, 0.031f);
        } else if (D_01B06FD0 == 0x290) {
            func_01B049C0(&D_01B060A0[0].objs[2], 12, 0, 0x20, -1,
                          0.09997600317001343f, -0.8f, 1.6999989748001099f,
                          0.0f, 0.0f, 0.0f, 0.007f, 0.007f, 0.007f);
        }

        if (D_01B06FD0 == 0x2E1) {
            func_01B04A10(&D_01B060A0[0].objs[2]);
            func_01B049C0(&D_01B060A0[0].objs[2], 13, 2, -1, -1,
                          0.04794599860906601f, 2.6739609241485596f, 9.634370803833008f,
                          -9216.0f, 0.0f, 0.0f, 0.005f, 0.005f, 0.005f);
        }

        if (D_01B06FD0 == 0x106 || D_01B06FD0 == 0x14D || D_01B06FD0 == 0x20F || D_01B06FD0 == 0x2E1) {
            D_01B060A0[0].objs[0].f3E = 0;
        } else if (D_01B06FD0 == 0x122 || D_01B06FD0 == 0x1A4 || D_01B06FD0 == 0x23F) {
            D_01B060A0[0].objs[0].f3E = 1;
        } else if (D_01B06FD4 == 0) {
            func_01B04A58();
            func_002D02E8(D_01B06FC0, 0, 19, 0x100);
        } else if (D_01B06FD4 == 30) {
            func_002D02E8(D_01B06FC0, 20, 39, 0x100);
        } else if (D_01B06FD8 == 0) {
            float vec[4];
            float z;
            func_01B047C8();
            z = 0.0f;
            func_00173A90(1);
            func_00173A90(4);
            func_00173A90(16);
            func_00173520(&D_01B06FF0);
            func_00173650(&D_01B008B0);
            func_01B04A58();
            vec[2] = z;
            vec[3] = 1.0f;
            vec[1] = z;
            vec[0] = z;
            D_01B07014 = func_001CEA70(8, 0, 7);
            func_01B03B40(vec, 0);
            func_01B04050(&D_01B00A30);
            func_01B049C0(&D_01B060A0[0].objs[0], 5, 0, -1, -1,
                          z, z, z,
                          z, z, z, 0.1f, 0.1f, 0.1f);
        } else if (D_01B06FDC == 0) {
            func_01B04A58();
            func_001CE9A8(0);
            func_01B04090();
            func_01B04820();
            func_00173A70(1);
            func_00173A70(4);
            func_00173A70(16);
            func_00173650(&D_01B06FF0);
        } else if (D_01B06FE0 == 0) {
            func_002D02E8(D_01B06FC0, 40, 49, 0x100);
        } else if (D_01B06FE0 == 200) {
            func_01B049C0(&D_01B060A0[1].objs[0], 6, 0, 0x2A, -1,
                          0.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
            func_01B049C0(&D_01B060A0[1].objs[1], 6, 0, 0x2E, -1,
                          0.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
        } else if (D_01B06FE4 == 0) {
            func_01B049C0(&D_01B060A0[1].objs[2], 11, 0, -1, -1,
                          0.2f, -0.4f, 6.299993991851807f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
        } else if (D_01B06FE4 == 100) {
            func_01B049C0(&D_01B060A0[1].objs[3], 10, 0, 0x22, -1,
                          11.599957466125488f, -13.19992733001709f, -7.799983024597168f,
                          0.0f, 0.0f, 0.0f, 0.135f, 0.135f, 0.135f);
            func_01B049C0(&D_01B060A0[1].objs[4], 10, 0, 0x43, -1,
                          -7.399992942810059f, -7.899992942810059f, -7.79999303817749f,
                          0.0f, 0.0f, 0.0f, 0.19999800622463226f, 0.19999800622463226f, 0.19999800622463226f);
            func_01B049C0(&D_01B060A0[1].objs[5], 10, 0, 0x1E, -1,
                          -1.2f, 8.899958610534668f, -6.999825954437256f,
                          0.0f, 0.0f, 0.0f, 0.13599899411201477f, 0.13599899411201477f, 0.13599899411201477f);
            func_01B049C0(&D_01B060A0[1].objs[6], 10, 0, 0x3F, -1,
                          3.1999969482421875f, 19.899839401245117f, -1.0999970436096191f,
                          0.0f, 0.0f, 0.0f, 0.21199800074100494f, 0.21199800074100494f, 0.21199800074100494f);
            func_01B049C0(&D_01B060A0[1].objs[7], 9, 0, 0x1E, -1,
                          -6.899959087371826f, -9.899933815002441f, -9.599946022033691f,
                          0.0f, -2560.0f, 0.0f, 0.11299899965524673f, 0.11299899965524673f, 0.11299899965524673f);
            func_01B049C0(&D_01B060A0[1].objs[8], 9, 0, 0x3F, -1,
                          8.099992752075195f, -1.2999980449676514f, -5.699972152709961f,
                          0.0f, -9216.0f, 0.0f, 0.117f, 0.117f, 0.117f);
        } else if (D_01B06FE8 == 0) {
            func_01B049C0(&D_01B060A0[1].objs[9], 6, 0, 0x4C, -1,
                          0.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
            func_01B049C0(&D_01B060A0[1].objs[10], 6, 0, 0x4F, -1,
                          0.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
        } else if (D_01B06FE8 == 300) {
            func_00173A70(1);
            func_00173A70(4);
            func_00173A70(16);
            func_00173650(&D_01B06FF0);
            func_001CDDD8(D_01B06060);
        }
    }

    if (D_006A3BC4 == 0) {
        if (D_01B07CD4 != 0) {
            func_01B040A0();
        }
    }
    if (D_01B07CD4 != 0) {
        func_01B01B08();
    }
    return 0;
}

int func_01B056C8(void) {
    if (D_01B009AC == 0) {
        return 0;
    }
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = &D_01D87790;
    func_01B04500(&D_01B060A0[0]);
    func_01B04500(&D_01B060A0[1]);

    if (D_01B06FCC >= 0x11E && D_01B06FCC < 0x13C) {
        func_01B04350(D_01B06FCC, 0x11E, 4, 15, 0x80, 0x80, 0x80, 0x48);
    } else if (D_01B06FD8 >= 0xA0) {
        int t = D_01B06FD8 - 0xA0;
        if (t >= 0) {
            if (t < 40) {
                func_01B04178((t * 0x70) / 40);
            } else if (t < 80) {
                func_01B04178(((80 - t) * 0x70) / 40);
            }
        }
    }

    if (D_006A3BC4 == 0) {
        D_01B06FC4++;
    }
    return 0;
}
