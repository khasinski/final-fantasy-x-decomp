typedef struct {
    unsigned char pad00[0x10];
    void **p10;
} Sub08B8;

typedef struct {
    unsigned char pad00[0x40];
    float pos[4];
    volatile int w50[4];
    volatile float scale[4];
} Obj08B8;

extern void *D_006A3924;
extern void *D_01B006A4;
extern Sub08B8 *D_01B006AC;
extern unsigned char D_01B006B0[];
extern void *D_01B00760;

extern int abs(int);
extern void func_00267658(Obj08B8 *, int, void *, int);
extern void func_00108910(void *, int, float *);
extern void func_00107378(void *, float (*)[4]);
extern void func_002DD0B0(float *, float *);
extern void func_00294968(void *, float *, int);

int ovl_09473_08b8(Obj08B8 *a0) {
    float mat[4][4];
    float vec[4];
    int diff;

    {
        register Sub08B8 *ac __asm__("$6") = D_01B006AC;
        register void *b0 __asm__("$3") = D_01B006B0;
        void **p10 = ac->p10;
        D_006A3924 = b0;
        func_00267658(a0, 0x1000, p10[3], 1);
    }
    func_00108910(D_01B00760, 16, a0->pos);
    func_00107378(D_01B00760, mat);
    func_002DD0B0(vec, mat[3]);

    if ((double)abs((int)(a0->pos[1] - vec[1])) < 8.996623) {
        a0->pos[1] = (float)((double)vec[1] - 8.996623);
    }

    {
        register float f0 __asm__("$f0") = 0.0728f;
        register float f1 __asm__("$f1") = 1.0f;
        register int one __asm__("$2");
        register float *pa1 __asm__("$5");
        __asm__("" : "+f"(f1) : : "$2");
        one = 1;
        __asm__("" : "+f"(f0) : "r"(one) : "$5");
        a0->scale[2] = f0;
        pa1 = a0->pos;
        __asm__("" : "+f"(f1) : "r"(pa1));
        a0->scale[3] = f1;
        __asm__("" : "+f"(f0) : "f"(f1) : "$6");
        a0->scale[0] = f0;
        a0->scale[1] = f0;
        a0->w50[0] = 0;
        a0->w50[1] = 0;
        a0->w50[2] = 0;
        a0->w50[3] = one;
        func_00294968(D_01B006A4, pa1, 0x100);
    }
    return 1;
}
