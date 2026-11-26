#include "iopsound.h"

typedef struct {
    s16 magic;
    s16 id;
    s32 spu_size;
    s32 unk08;
    s32 unk0C;
    s32 spu_addr;
} WaveHdr;

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    WaveHdr *hdr;
    s32 active;
    s32 spu_addr;
} BankSlot;

extern BankSlot *D_019308;
extern s32 D_018708;

extern const char D_016168[];
extern const char D_016184[];
extern const char D_0161DC[];
extern const char D_0161E4[];
extern const char D_016200[];
extern const char D_016208[];
extern const char D_016228[];
extern const char D_016260[];

extern void func_00A680(void);
extern s32 func_009C14(BankSlot *);
extern s32 func_0095C4(s32, s32);
extern s32 func_009698(s32);
extern void *func_009948(s32);
extern void func_00944C(s32);
extern void func_009360(WaveHdr *, void *, s32);
extern s32 func_00A6D0(void);
extern s32 func_009EDC(void);
extern s32 func_00A038(void);
extern s32 func_00A200(s32);
extern void func_00A4B8(s32);
extern void func_00F0D4(s32);

s32 func_00A7A0(s32 slot_idx, WaveHdr *hdr, s32 wave_id) {
    BankSlot *slot;
    s32 spu_addr;
    s32 sz;
    void *buf;

    if (hdr->magic != 0x4457) {
        return 0;
    }

    func_00A680();
    hdr->id = wave_id;

retry:
    do {
        if (slot_idx < 0) {
            for (slot = D_019308 + 16; slot->active != 0 && slot < D_019308 + 128; slot++) {
            }
            if (slot >= D_019308 + 128) {
                imp_sysmem_14(D_0161E4, D_016168, D_016200, D_016184);
                return 0;
            }
        } else {
            slot_idx &= 0x0F;
            slot = &D_019308[slot_idx];
            if (slot->active != 0) {
                func_009C14(slot);
            }
        }

        if (hdr->spu_addr != 0) {
            spu_addr = func_0095C4(hdr->spu_addr, hdr->spu_size);
        } else {
            spu_addr = func_009698(hdr->spu_size);
        }

        if (spu_addr != 0) {
            s32 a;
            s32 b;
            imp_sysmem_14(D_016208, D_016168, D_0161DC, wave_id, D_016184);
            a = ((hdr->unk08 + 3) & ~3) << 2;
            b = (hdr->unk0C << 5) + 32;
            sz = a + b;
            buf = func_009948(sz);
            if (buf != NULL) {
                slot->hdr = buf;
                slot->active = sz;
                hdr->spu_addr = spu_addr;
                slot->id = wave_id;
                slot->lru = 0;
                func_009360(hdr, buf, sz);
                break;
            }
            func_00944C(spu_addr);
        }

        if (func_00A6D0() == 0) {
            sz = 0;
            if ((D_018708 & 1) == 0) {
                sz = func_009EDC();
                func_00A4B8(0);
                if (sz >= hdr->spu_size) {
                    goto retry;
                }
                func_00A038();
                sz = func_009EDC();
                func_00A4B8(1);
                if (sz >= hdr->spu_size) {
                    goto retry;
                }
                sz = func_00A200(hdr->spu_size);
                func_00A4B8(2);
                if (sz >= hdr->spu_size) {
                    goto retry;
                }
                sz = func_009EDC();
                func_00A4B8(3);
            }

            if (sz < hdr->spu_size) {
                imp_sysmem_14(D_016228, D_016168, D_016260, hdr->id, hdr->spu_size, D_016184);
                func_00F0D4(4);
                spu_addr = 0;
                break;
            }
        }
    } while (1);

    return spu_addr;
}
