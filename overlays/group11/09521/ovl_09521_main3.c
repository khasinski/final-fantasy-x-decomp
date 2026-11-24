#include "common.h"

typedef struct PPool {
    u8 data[0x70];
} PPool;

extern void *D_006A3BCC;

extern int D_01B004F0;
extern void *D_01B004F8;
extern void *D_01B004FC;
extern void *D_01B00500;
extern int D_01B00504;
extern u8 D_01B009D0[];

extern PPool D_01B18100[2];
extern int D_01B181E8;
extern u8 D_01B181F0[];
extern u8 D_01B18300[];
extern u8 D_01B18410[];
extern u8 D_01B18520[];
extern u8 D_01B18630[];

extern char D_01B1B108[];

int func_01B1A348(char *, ...);
void func_01B1A950(void *);
void *func_01B1AAE8(void *, void *, void *, float);
int func_01B1AD18(void *);
int func_01B1AE70(void *);
int func_00116068(void);
int func_0014AA50(int);
void func_001CDDD8(int);

void func_01B1A008(void)
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

int func_01B1A0D8(void)
{
    int i;

    if (func_00116068() == 0 || D_01B004F0 == 0) {
        return 0;
    }
    D_006A3BCC = D_01B004F8;
    D_01B00500 = D_01B004FC;
    if (func_0014AA50(1) != 0) {
        func_01B1AD18(D_01B181F0);
    }
    if (func_0014AA50(2) != 0) {
        func_01B1AD18(D_01B18300);
    }
    if (func_0014AA50(3) != 0) {
        func_01B1AD18(D_01B18410);
    }
    if (func_0014AA50(4) != 0) {
        func_01B1AD18(D_01B18520);
    }
    if (func_0014AA50(5) != 0) {
        if (func_01B1AD18(D_01B18630) == 0) {
            func_01B1A348(D_01B1B108, D_01B181E8);
            func_001CDDD8(D_01B00504);
            return 1;
        }
    }
    if (func_0014AA50(6) != 0) {
        func_01B1AE70(D_01B18630);
        func_01B1A348(D_01B1B108, D_01B181E8);
        func_001CDDD8(D_01B00504);
        return 1;
    }
    for (i = 0; i < 2; i++) {
        func_01B1A950(&D_01B18100[i]);
        D_01B00500 = func_01B1AAE8(&D_01B18100[i], D_01B009D0, D_01B00500, 0.0f);
    }
    D_01B181E8++;
    return 1;
}
