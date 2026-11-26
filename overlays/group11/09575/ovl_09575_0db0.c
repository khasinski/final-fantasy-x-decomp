typedef unsigned char u8;
typedef float sceVu0FMATRIX[4][4];
typedef float sceVu0FVECTOR[4];

typedef struct {
    u8 pad0[0x40];
    sceVu0FVECTOR pos;
    int rot[4];
    sceVu0FVECTOR scale;
} Part;

extern float D_01B00724;
extern u8 D_01B00768;
extern int D_01B008B0;
extern int D_01B008BC;
extern float D_01B008C0[4];

extern void *D_006A3924;
extern sceVu0FMATRIX D_006A3930;
extern sceVu0FMATRIX D_006A3970;
extern sceVu0FMATRIX D_006A39B0;
extern sceVu0FMATRIX D_006A3A70;
extern sceVu0FMATRIX D_006A3AB0;

extern void func_00107378(int, void *);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_01B01760(void *, float);
extern void func_01B02A18(void *, float);

static __inline__ void pppSetEnv(void *e)
{
    D_006A3924 = e;
}

int func_01B00DB0(Part *arg)
{
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m1;
    volatile sceVu0FVECTOR pad;
    (void)pad;

    if (D_01B008BC == 0) {
        return 0;
    }
    arg->scale[0] = D_01B00724;
    arg->scale[1] = D_01B00724;
    arg->scale[2] = D_01B00724;
    arg->scale[3] = 1.0f;
    func_00107378(D_01B008B0, m0);
    func_01B01760(m1, 1000.0f);
    func_002DCE38(m0, m0, m1);
    func_002DD0B0(m0[3], D_01B008C0);
    func_01B02A18(m0, 10.0f);
    func_01B01760(m1, D_01B00724);
    func_002DCE38(m0, m0, m1);
    func_002DD0C0(D_006A3930, m0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    pppSetEnv(&D_01B00768);
    return func_00267FA0(arg, 0x30) == 0;
}
