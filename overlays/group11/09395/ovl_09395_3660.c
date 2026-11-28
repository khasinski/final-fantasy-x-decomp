#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern s32 D_006A3BC4;
extern void *D_006A3BCC;
extern s32 D_01B0099C;
extern void *D_01B009A4;
extern void *D_01B009B0;
extern void *D_01B009B4;
extern void *D_01B009BC;
extern u8 D_01B009D8[];
extern s32 D_01B00F50;
extern u8 D_01B011F8[];

extern s32 func_00116068(void);
extern void func_001AACA0(void *);
extern void func_001A9EE0(void *);
extern s32 func_01B04688(void *);
extern void func_001CDDD8(void *);

s32 func_01B03660(void) {
    if (D_01B0099C == 0) {
        return 0;
    }
    D_006A3BC4 = 0;
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    }
    D_006A3924 = D_01B009D8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B009A4;
    D_01B009B4 = D_01B009B0;
    if (func_01B04688(D_01B011F8) == 0) {
        func_001CDDD8(D_01B009BC);
        return 1;
    }
    D_01B00F50++;
    return 1;
}
