#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;

extern int D_01B00858;
extern void *D_01B00860;
extern void *D_01B00864;
extern void *D_01B00868;
extern int D_01B00870;
extern u8 D_01B00880[];
extern int D_01B01258;
extern int D_01B01260[];
extern int D_01B01370[];
extern int D_01B01480[];
extern int D_01B01590[];

extern char D_01B04698[];
extern char D_01B046A8[];
extern char D_01B046B8[];
extern char D_01B046C8[];
extern char D_01B046D8[];

int func_01B03858(char *, ...);
void func_01B038B0(char *, ...);
void func_01B038F0(int, int);
void func_01B04228(void *);
int func_01B04380(void *);
int func_0014AA50(int);
void func_001A9EE0(void *);
void func_001AACA0(void *);
void func_001CDDD8(int);

int func_01B035B8(void)
{
    if (D_01B00858 == 0) {
        return 0;
    }
    D_006A3924 = D_01B00880;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00860;
    D_01B00868 = D_01B00864;
    if (func_0014AA50(1) != 0) {
        func_01B038F0(0x20, 0x1A);
        func_01B038B0(D_01B04698, D_01B01260[0]);
        func_01B04228(D_01B01260);
    }
    if (func_0014AA50(2) != 0) {
        func_01B038F0(0x20, 0x1B);
        func_01B038B0(D_01B046A8, D_01B01370[0]);
        func_01B04228(D_01B01370);
    }
    if (func_0014AA50(3) != 0) {
        func_01B038F0(0x20, 0x1C);
        func_01B038B0(D_01B046B8, D_01B01480[0]);
        func_01B04228(D_01B01480);
    }
    if (func_0014AA50(4) != 0) {
        func_01B038F0(0x20, 0x1D);
        func_01B038B0(D_01B046C8, D_01B01590[0]);
        func_01B04228(D_01B01590);
    }
    if (func_0014AA50(5) != 0) {
        func_01B04380(D_01B01260);
        func_01B04380(D_01B01370);
        func_01B04380(D_01B01480);
        func_01B04380(D_01B01590);
        func_01B03858(D_01B046D8, D_01B01258);
        func_001CDDD8(D_01B00870);
        return 1;
    }
    D_01B01258++;
    return 1;
}
