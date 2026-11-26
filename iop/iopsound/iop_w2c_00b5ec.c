#include "iopsound.h"

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    void *hdr;
    s32 active;
    s32 spu_addr;
} BankSlot;

typedef struct {
    u8 pad[16];
    u8 body[4];
} SebHdr;

typedef struct {
    s32 idx;
    s32 id;
    SebHdr *data;
    s32 size;
} SepSlot;

typedef struct {
    u8 pad000[0x37C];
    s32 f37C;
    u8 pad380[0x0A];
    s16 f38A;
    u8 pad38C[0x70C - 0x38C];
    s32 f70C;
    u8 pad710[0x0A];
    s16 f71A;
} MusicCtrl;

extern BankSlot *D_019308;
extern MusicCtrl *D_01936C;
extern SepSlot *D_01938C;

extern s32 func_009A9C(void);
extern void func_009B28(s32);
extern s32 func_009BB0(s32);

void func_00B5EC(s32 flags, s32 bank_id) {
    s32 found;

    if (flags & 1) {
        SepSlot *p = D_01938C;
        found = 0;
        if (p->size != 0) {
            u8 *b = p->data->body;
            if ((b[1] | (b[2] << 8)) == bank_id) {
                found++;
                goto check_found;
            }
        }
    loop_inc:
        p++;
        if (p < D_01938C + 192) {
            if (p->size == 0) {
                goto loop_inc;
            }
            {
                u8 *b = p->data->body;
                if ((b[1] | (b[2] << 8)) != bank_id) {
                    goto loop_inc;
                }
            }
            found++;
        }
        goto check_found;
    }
    if (flags & 4) {
        MusicCtrl *mc = D_01936C;
        found = 0;
        if (mc->f38A != 0) {
            if (mc->f37C == bank_id) {
                found = 1;
            }
        }
        if (mc->f71A != 0) {
            if (mc->f70C == bank_id) {
                found |= 1;
            }
        }
    check_found:
        if (found == 0) {
            found = func_009BB0(bank_id);
            if (found >= 16) {
                if (D_019308[found].lru == 0) {
                    func_009A9C();
                    D_019308[found].lru = 1;
                }
            }
        }
        return;
    }

    found = func_009BB0(bank_id);
    if (found >= 16) {
        if (D_019308[found].lru != 0) {
            func_009B28(D_019308[found].lru);
            D_019308[found].lru = 0;
        }
    }
}
