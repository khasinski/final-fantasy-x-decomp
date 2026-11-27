#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x140];
    u8 *p140;
    u8 *p144;
    u8 *p148;
} Node4790;

typedef struct {
    u8 pad00[0x50];
    Node4790 *p50;
    u8 pad54[0xAC];
} Entry4790;

typedef struct {
    u8 pad00[0x10];
    u32 flags;
} B40Struct;

extern int D_01B00044;
extern u32 D_01B00048;
extern u32 D_01B0004C;
extern u8 D_01B0F4D0[];
extern void *D_006A3924;
extern B40Struct D_01B00B40;
extern u8 D_01B00B54;
extern u8 D_01B00930[];
extern u8 D_01B00B58[];
extern u8 D_01B00B78[];
extern u32 D_01B005C8;
extern int D_01B005CC;
extern int D_01B005D0;
extern Entry4790 *D_01B005D4;
extern u8 D_01B0F4C0[];
extern u32 D_01B00780;

void func_01B02E58(void);
void func_01B0D4A0(void *);
void func_01B0A738(void *);
void func_01B04F60(void *);
int func_01B02F08(void *, void *, void *);
void func_01B03830(void);
void func_001CDDD8(u32);

int func_01B04790(void)
{
    struct {
        void *a;
        u8 pad4;
        u8 b5;
        u8 pad6[0xA];
        void *p10;
    } arg;

    if (D_01B00044 >= 4) {
        D_006A3924 = D_01B0F4D0;
        D_01B00048 = D_01B0004C;
        func_01B02E58();
        D_01B00B54++;
        arg.p10 = &D_01B00B40;
        func_01B0D4A0(&arg.p10);
        arg.a = D_01B00930;
        arg.b5 = D_01B00B54;
        func_01B0A738(&arg);
        arg.a = D_01B00B58;
        arg.b5 = D_01B00B54;
        func_01B04F60(&arg);
        if (D_01B005C8 != 0) {
            Node4790 *n = D_01B005D4[D_01B005D0].p50;
            int s2 = func_01B02F08(n->p140 + 0x20, n->p148 + 0x20, n->p144 + 0x20);
            arg.a = D_01B005D4[D_01B005D0].p50;
            arg.b5 = D_01B00B54;
            func_01B0A738(&arg);
            *(u_long128 *)D_01B0F4C0 = *(u_long128 *)(D_01B005D4[D_01B005D0].p50->p140 + 0x20);
            func_01B03830();
            if (s2 & 2) {
                D_01B005D0++;
                if (D_01B005D0 >= D_01B005CC) {
                    D_01B005D0 = 0;
                }
            } else if (s2 & 1) {
                D_01B005D0--;
                if (D_01B005D0 < 0) {
                    D_01B005D0 = D_01B005CC - 1;
                }
            }
        }
        arg.a = D_01B00B78;
        arg.b5 = D_01B00B54;
        func_01B04F60(&arg);
        if ((D_01B00B40.flags & 1) == 0) {
            return 0;
        }
        if (*(u16 *)(D_01B00B78 + 0x18) != 0) {
            return 0;
        }
        func_001CDDD8(D_01B00780);
    }
    return 0;
}
