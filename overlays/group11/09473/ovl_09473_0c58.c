extern int D_01B00688;
extern int D_01B0068C;
extern int D_01B00690;
extern void *D_01B0069C;
extern int func_00116068(void);
extern int func_0029B830(int);
extern void func_001CDC58(void *, int);
extern int func_001CDAF8(void *);
int ovl_09473_0c58(void) {
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00688 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00688++;
    }
    if (D_01B0068C == 0) {
        D_01B0068C = 1;
        func_001CDC58(D_01B0069C, 0);
    }
    if (D_01B00690 == 0) {
        if (func_001CDAF8(D_01B0069C) > 0) {
            D_01B00690++;
        } else {
            return 1;
        }
    }
}
