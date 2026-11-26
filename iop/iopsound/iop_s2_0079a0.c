#include "iopsound.h"

typedef struct SeHeader {
    u8 pad00[0x0A];
    s16 count;
    u8 pad0C[0x04];
    s32 offsets[1];
} SeHeader;

typedef struct SeEntry {
    s32 unk00;
    s32 id;
    u8 *data;
    s32 unk0C;
} SeEntry;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x48];
    s32 vol;            /* 0x04C */
    s32 vol_step;       /* 0x050 */
    s32 vol_cnt;        /* 0x054 */
    u8 pad058[0x88];
    s32 se_id;          /* 0x0E0 */
    u8 pad0E4[0x53];
    u8 voice_idx;       /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13C = 316 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x64];
    u32 flags68;        /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct DriverState {
    u8 pad000[0x720];
    Track *se_tracks;   /* 0x720 */
} DriverState;

extern SeHeader *D_01873C;
extern SeEntry *D_01938C;
extern DriverState *D_01936C;
extern Voice *D_0192F0;

extern char D_0160A8[];
extern char D_0160BC[];
extern char D_0160C4[];
extern char D_0160CC[];
extern char D_0160F4[];

extern void func_00F120(s32);
extern void func_00F0D4(s32);
extern void func_0075FC(u8 *, s32, s32, s32, s32);

s32 func_0079A0(s32 a0, s32 a1, s32 a2, s32 a3) {
    SeHeader *hdr;

    func_00F120(16);
    hdr = D_01873C;
    if (a1 < hdr->count) {
        s32 *tbl = hdr->offsets;
        if (tbl[a1] != -1) {
            func_0075FC((u8 *)&tbl[hdr->count] + tbl[a1], a0, a1, a2, a3);
            return a1;
        }
    }
    imp_sysmem_14(D_0160CC, D_0160A8, D_0160BC, a1, D_0160C4);
    func_00F0D4(16);
    return -1;
}

s32 func_007A84(s32 a0, s32 a1, s32 a2, s32 a3) {
    SeEntry *p;

    func_00F120(16);
    p = D_01938C;
    a1 |= 0x80000000;
    do {
        if (p->id == a1) {
            break;
        }
    } while (++p < D_01938C + 192);

    if (p < D_01938C + 192) {
        func_0075FC(p->data + 16, a0, a1, a2, a3);
        return a1;
    }
    imp_sysmem_14(D_0160F4, D_0160A8, D_0160BC, a1 & 0x7FFFFFFF, D_0160C4);
    func_00F0D4(16);
    return -1;
}

s32 func_007B8C(s32 se_id, s32 vol) {
    Track *trk;

    vol <<= 12;
    trk = D_01936C->se_tracks;
    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                D_0192F0[trk->voice_idx].flags68 |= 2;
                trk->vol = vol;
                trk->vol_cnt = 0;
            }
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}
