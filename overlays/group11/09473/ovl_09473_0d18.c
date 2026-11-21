extern int D_01B00690;
extern void *D_01B00698;
extern void *D_01B0069C;
extern unsigned char D_01B006B0[];
extern int D_01B00768;
extern unsigned char D_01B00770[];
extern void *D_006A3924;
extern void *D_006A3BCC;
extern float D_006A3970[16];
extern float D_006A3A70[16];
extern void func_001AACA0(float *);
extern void func_001A9EE0(float *);
extern void func_01B013B0(int, int);
extern int func_01B01450(void *);
extern int func_01B015B0(void *);
extern void func_001CDDD8(void *);
int ovl_09473_0d18(void) {
    if (D_01B00690 == 0) {
        return 0;
    }
    D_006A3924 = D_01B006B0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00698;
    func_01B013B0(32, 26);
    if (func_01B01450(D_01B00770) == 0) {
        func_01B015B0(D_01B00770);
        func_001CDDD8(D_01B0069C);
        return 1;
    }
    D_01B00768++;
    return 1;
}
