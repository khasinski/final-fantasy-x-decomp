typedef unsigned char u8;
typedef float sceVu0FMATRIX[4][4];
typedef float sceVu0FVECTOR[4];

typedef struct {
    u8 pad0[0x40];
    sceVu0FVECTOR pos;
    int rot[4];
    sceVu0FVECTOR scale;
} Part;

extern float D_01B00720;
extern float D_01B00728;
extern float D_01B0072C;
extern float D_01B00730;
extern float D_01B00734;
extern u8 D_01B00768;
extern int D_01B008A8;
extern int D_01B008B4;

extern void *D_006A3924;
extern sceVu0FMATRIX D_006A3930;
extern sceVu0FMATRIX D_006A3970;
extern sceVu0FMATRIX D_006A39B0;
extern sceVu0FMATRIX D_006A3A70;
extern sceVu0FMATRIX D_006A3AB0;

extern void func_00107378(int, void *);
extern int func_00267FA0(void *, int);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_01B01760(void *, float);
extern void func_01B02A18(void *, float);

static __inline__ void pppSetEnv(void *e)
{
    D_006A3924 = e;
}

int func_01B00FE0(Part *arg)
{
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m1;
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;

    func_00107378(D_01B008A8, m0);
    func_01B01760(m1, 1000.0f);
    func_002DCE38(m0, m0, m1);
    func_01B02A18(m0, 50.0f);
    if (D_01B008B4 == 0) {
        v0[0] = 0.0f;
        v0[1] = D_01B0072C;
        v0[2] = D_01B00728;
        v0[3] = 1.0f;
    } else {
        v0[0] = 0.0f;
        v0[1] = D_01B00734;
        v0[2] = D_01B00730;
        v0[3] = 1.0f;
    }
    func_002DCE08(v1, m0, v0);
    func_002DD0B0(m0[3], v1);
    func_01B01760(m1, D_01B00720);
    func_002DCE38(m0, m0, m1);
    func_002DD0C0(D_006A3930, m0);
    func_01B02A18(D_006A3930, 20.0f);
    arg->scale[0] = D_01B00720;
    arg->scale[1] = D_01B00720;
    arg->scale[2] = D_01B00720;
    arg->scale[3] = 1.0f;
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    pppSetEnv(&D_01B00768);
    return func_00267FA0(arg, 0x30) == 0;
}
