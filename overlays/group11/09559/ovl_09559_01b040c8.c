/* Overlay 09559: rank 505 Sub130 dispatcher (0x01B040C8..0x01B04150). */
#include "common.h"

typedef struct Sub130 {
    u8 pad0[0x18];
    int mode;
} Sub130;

extern char D_01B0B4D0[];
extern char D_01B0B6C8[];

void func_01B04150(Sub130 *, void *);
void func_01B04208(Sub130 *, void *);
void func_002EF240(const char *, ...);
void func_01B01768(int, const char *, int);

void func_01B040C8(Sub130 *a0, void *a1) {
    switch (a0->mode) {
        case 0:
            break;
        case 1:
            func_01B04150(a0, a1);
            break;
        case 2:
            func_01B04208(a0, a1);
            break;
        default:
            func_002EF240(D_01B0B6C8, a0->mode);
            func_01B01768(14, D_01B0B4D0, 0x6BA);
            break;
    }
}
