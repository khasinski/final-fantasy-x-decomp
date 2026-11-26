typedef unsigned char u8;

extern int D_01B00744;
extern void *D_01B0074C;
extern int D_01B00750;
extern u8 D_01B00768[];
extern int D_01B008A0;
extern int D_01B008B4;
extern u8 D_01B008D0[];
extern u8 D_01B009E0[];

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;

extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(int);
extern void func_01B01BB0(int, int);
extern int func_01B01C50(void *);
extern void func_01B01DB0(void *);

int func_01B014D8(void)
{
    int r;

    if (D_01B00744 == 0) {
        return 0;
    }
    D_006A3924 = D_01B00768;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B0074C;
    func_01B01BB0(0x20, 0x1A);
    if (D_01B008B4 == 0) {
        r = func_01B01C50(D_01B008D0);
    } else {
        r = func_01B01C50(D_01B009E0);
    }
    if (r == 0) {
        if (D_01B008B4 == 0) {
            func_01B01DB0(D_01B008D0);
        } else {
            func_01B01DB0(D_01B009E0);
        }
        func_001CDDD8(D_01B00750);
        return 1;
    }
    D_01B008A0 += 1;
    return 1;
}
