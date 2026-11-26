#include "iopsound.h"

typedef struct {
    s32 f0;
    u8 pad4[316 - 4];
} Track;

typedef struct {
    Track *f0;
    u8 pad4[0x16 - 4];
    u8 f16;
    u8 pad17[0x4c - 0x17];
    s32 f4C;
    u8 pad50[0x58 - 0x50];
    u16 f58;
    u8 pad5A[0x62 - 0x5a];
    u16 f62;
    u8 pad64[116 - 0x64];
} Voice;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 f1F;
} BgmInfo;

typedef struct {
    Track *tracks;
    u8 pad4[880 - 4];
    BgmInfo info;
} BgmSlot;

extern Voice *D_0192F0;
extern s32 D_019314;
extern BgmSlot *D_01936C;

extern void func_006D2C(Voice *);
extern void func_002D20(s32, Track *);
extern void func_009834(Track *);
extern void func_00B5EC(s32, s32);
extern void func_00C1C8(s32, s32);

s32 func_008AC4(s32 id) {
    BgmSlot *slot = D_01936C;
    Voice *v;
    Track *t;
    s32 old_id;
    u32 tmp;

    do {
        if (id == -1 || slot->info.f4 == id) {
            old_id = slot->info.f4;
            slot->info.f14 = 0;
            slot->info.f4 = -1;
            if (slot->info.f1A != 0) {
                v = D_0192F0;
                do {
                    if (v->f0 >= slot->tracks && v->f0 < slot->tracks + slot->info.f1D) {
                        func_006D2C(v);
                        tmp = v->f62 & ~0x1f;
                        imp_libsd_5(v->f58 | 0x400, tmp | 8);
                        v->f4C = (v->f4C & ~0xd) | 2;
                        v->f16 = (s8)v->f16 & ~0x10;
                        v->f0 = NULL;
                    }
                    v++;
                } while (v < D_0192F0 + 48);

                t = slot->tracks;
                do {
                    if (t->f0 != 0) {
                        func_002D20(D_019314, t);
                        t->f0 = 0;
                    }
                    t++;
                } while (t < slot->tracks + slot->info.f1D);

                slot->info.f1A = 0;
                func_009834(slot->tracks);
                slot->tracks = NULL;
                if ((slot->info.f0 & 0x20000) == 0) {
                    func_00B5EC(4, slot->info.fC);
                    slot->info.f0 &= ~0x20000;
                }
                func_00C1C8(1, old_id);
            }
        }
        slot++;
    } while (slot < D_01936C + 2);

    slot = D_01936C;
    if (slot[0].info.f4 < 0 && slot[1].info.f4 >= 0) {
        u32 *a = (u32 *)&slot[0];
        u32 *b = (u32 *)&slot[1];
        do {
            tmp = *a;
            *a = *b;
            *b = tmp;
            a++;
            b++;
        } while (a < (u32 *)&D_01936C[1]);
    }

    return id;
}
