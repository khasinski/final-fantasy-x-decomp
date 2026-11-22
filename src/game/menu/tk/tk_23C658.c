/* tu_265 0x23c658-0x23cbd0: medium; ~TOClearMessageWindowForMenu (config/tu_map.tsv) */
#define TkMenuSetDummyControlerFlag _hdr_TkMenuSetDummyControlerFlag
#define TkMenuMainActiveMenu _hdr_TkMenuMainActiveMenu
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef TkMenuMainActiveMenu
#undef TkMenuSetDummyControlerFlag

void TkMenuSetDummyControlerFlag(int a);
void TkMenuMainActiveMenu(int a, int b);

void func_0023C658(void)
{
    Rec124828 *rec = func_00124828();
    Rec124828 *bak = D_0069A60C;
    char *name;
    int ofs;
    int i;

    for (i = 0; i < 18; i++) {
        name = (char *)MsGetSaveChrName(i);
        ofs = name - (char *)&D_003194D0;
        func_002F072C(name, (char *)D_0069A60C + ofs); /* DEBT(CAST): same offset inside the backup copy of D_003194D0 */
    }
    rec->xD1 = bak->xD1;
}

typedef struct SaveCopy64B8 {
    u64 q[0x64B8 / 8];
} SaveCopy64B8; /* DEBT(TYPE): 0x64B8-byte save block copy */

typedef struct TutoEntry {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} TutoEntry;

extern void *D_0069A608;
extern SaveCopy64B8 D_00694150;
extern TutoEntry D_00326290[];
extern char D_00572BD0[];
extern char D_00572BE8[];
extern char D_00572C10[];
extern char D_00572C28[];
extern char D_00572C40[];
extern char D_00572C58[];
extern char D_00572C70[];

int TkCdReadSync(int a);
int func_001BD360(void);
void TkMenuRefreshPartyList(void);
void func_00242668(void);
void TkMsSetSaveParamAll(void);
void TOMenuAtelReq(int a, int b, int c);
int TkMn2SetMainFrameRatioDiff(int a);
int func_00242818(void);
int TkMenuGetSummonListMax(void);
int TkMenuMainGetMenuActiveMask(void);
void SndSepLock(int a);

void TkMenuCtrlTuto(Task *o)
{
    int i;
    s32 *st;

    i = TkGetLastSyncVCounter() - 1;
    for (i = -i; i <= 0; i++) {
        TkGetControlerTrigHist(0, 0, i);
    }
    st = &o->x1C;
    switch (o->x1C) {
    case 0:
        TkMenuSetDummyControlerFlag(1);
        *st = 1;
        break;
    case 1:
        *st = 2;
        break;
    case 2:
        if (TOMenuGetFirstReadEndFlag() != 0) {
            *st = 3;
        }
        break;
    case 3:
        D_0069A608 = (void *)func_002281E0();
        D_0069A60C = (Rec124828 *)&D_00694150;
        D_00694150 = *(SaveCopy64B8 *)&D_003194D0; /* DEBT(CAST): 0x64B8-byte save block copy */
        TkCdReadNB(D_00326290[D_0069A610].w8, D_00326290[D_0069A610].wC, (int)D_0069A608);
        *st = 4;
        break;
    case 4:
        {
            int cfg = func_001BD360();
            if (TkCdReadSync(1) != 0) {
                break;
            }
            func_002EF240(D_00572BD0);
            __builtin_memcpy(&D_003194D0, (u8 *)D_0069A608 + 0x40, 0x64B8);
            MsSetSaveConfigEnglish(cfg);
            func_0023C658();
            TkMenuRefreshPartyList();
            func_00242668();
            TkMsSetSaveParamAll();
            *st = 5;
        }
        break;
    case 5:
        TOMenuAtelReq(1, 0, D_00326290[D_0069A610].w4);
        func_002EF240(D_00572BE8, D_0069A610, D_00326290[D_0069A610].w4);
        TkMn2SetMainFrameRatioDiff(-16);
        TkMenuMainActiveMenu(D_00326290[D_0069A610].w0, 0);
        func_002EF240(D_00572C10, D_00326290[D_0069A610].w0);
        func_002EF240(D_00572C28, func_00242818());
        func_002EF240(D_00572C40, TkMenuGetSummonListMax());
        *st = 6;
        break;
    case 6:
    case 7:
        if (((TkMenuMainGetMenuActiveMask() >> D_00326290[D_0069A610].w0) & 1) == 0) {
            *st = 8;
        }
        break;
    case 8:
        {
            int mask;
            SndSepLock(0);
            TkMn2SetMainFrameRatioDiff(16);
            mask = TkMenuMainGetMenuActiveMask();
            func_002EF240(D_00572C58);
            func_002EF240(D_00572C70, mask);
            *st = 9;
        }
        break;
    case 9:
        *st = 10;
    case 10:
        TkMenuSetDummyControlerFlag(0);
        *(SaveCopy64B8 *)&D_003194D0 = *(SaveCopy64B8 *)D_0069A60C; /* DEBT(CAST): restore 0x64B8-byte save block */
        TkMenuRefreshPartyList();
        func_00242668();
        TkMsSetSaveParamAll();
        TkMenuMainRemoveMenu(0x16);
        break;
    }
}

void func_0023CB90(void) {
}

void func_0023CB98(Task *o) { o->x1C = 0; }

void func_0023CBA0(int a, int b) {
    D_00323954 = 1;
    D_0069A610 = b;
}

void func_0023CBB8(void) {
}

void func_0023CBC0(void) {
    D_00323954 = 0;
}
