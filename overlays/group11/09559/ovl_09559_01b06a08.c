#include "oef_overlay.h"

typedef struct ChrInfo {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    u8 pad08[0x38];
    float pos40[4];    /* 0x40 */
    u8 pad50[0x80];
} ChrInfo;             /* 0xD0 */

extern int D_01B0BAE0;
extern OefPartObj D_01B0C800;
extern OefPartObj D_01B0C880;
extern OefPartObj D_01B0C900;
extern OefPartObj D_01B0C980[3];
extern OefPartObj D_01B0CB00;
extern OefPartObj D_01B0CB80;
extern OefPartObj D_01B0CC00;
extern OefPartObj D_01B0CC80;
extern OefPartObj D_01B0CD00;
extern OefPartObj D_01B0CD80[3];
extern OefPartObj D_01B0CF00;
extern OefPartObj D_01B0CF80;
extern OefPartObj D_01B0D000;
extern OefPartObj D_01B0D080;

extern void *D_01B0C7C4;
extern void *D_01B0C7C8;
extern void *D_01B0C7CC;
extern void *D_01B0C7D0;
extern void *D_01B0C7D4;
extern void *D_01B0C7D8;
extern void *D_01B0C7DC;
extern void *D_01B0C7E0;
extern void *D_01B0C7E4;
extern void *D_01B0C7E8;
extern void *D_01B0C7EC;
extern void *D_01B0C7F0;
extern void *D_01B0C7F4;
extern void *D_01B0C7F8;

extern int D_01B0D1B0;
extern int D_01B0D1B4;
extern s16 D_01B0D1BC;
extern s16 D_01B0D1BE;
extern s16 D_01B0D1C0;
extern s16 D_01B0D1C2;
extern s16 D_01B0D1C4;
extern s16 D_01B0D1C6;
extern s16 D_01B0D1C8;
extern s16 D_01B0D1CA;
extern s16 D_01B0D1CC;
extern s16 D_01B0D1CE;
extern s16 D_01B0D1D0;
extern s16 D_01B0D1D2;
extern s16 D_01B0D1D4;
extern s16 D_01B0D1D6;
extern s16 D_01B0D1D8;
extern s16 D_01B0D1DA;
extern s16 D_01B0D1DC;
extern s16 D_01B0D1DE;
extern s16 D_01B0D1E0;
extern s16 D_01B0D1E2;
extern s16 D_01B0D1E4;
extern s16 D_01B0D1E6;
extern s16 D_01B0D1E8;
extern s16 D_01B0D1EA;
extern s16 D_01B0D1EC;
extern s16 D_01B0D1EE;
extern s16 D_01B0D1F0;
extern s16 D_01B0D1F2;
extern s16 D_01B0D1F4;
extern s16 D_01B0D1F6;
extern s16 D_01B0D1F8;
extern s16 D_01B0D1FA;
extern s16 D_01B0D1FC;
extern s16 D_01B0D1FE;
extern s16 D_01B0D200;
extern s16 D_01B0D202;

extern float D_01B0D210[4];
extern float D_01B0D220[16];
extern int D_01B0D260;
extern int D_01B0D264;
extern int D_01B0D268;
extern int D_01B0D26C;
extern int D_01B0D280;
extern int D_01B0D284;
extern int D_01B0D288;
extern int D_01B0D28C;
extern int D_01B0D290;
extern int D_01B0D294;
extern ChrInfo D_01B0D2A0[3];
extern ChrInfo D_01B0D510[];
extern ChrInfo D_01B0DB90[];
extern ChrInfo D_01B0F4C0;
extern u8 D_01BE9E20[];
extern u8 D_01C07E60[];

int func_001AEBD8(void);
int MsGetRamChrMonster(int);
float MsGetChrGround(int);
void func_002DD0B0(float *, float *);
int MsGetSummonerNum(int);
u8 *MsGetBattleList(int, int *);
void MsGetDamageInfo(int, int, int, int, int);
void *op_oef2_a_get(void *, int, int);
int func_002B2E10(void *, int, int, int);

void func_01B05268(ChrInfo *);
int func_01B05230(ChrInfo *, int, int);
void func_01B045B0(void);
void func_01B02478(int);
void func_01B02780(int);
void func_01B06278(void);
void func_01B05638(void);
void func_01B05BB8(void);
void func_01B069D0(void);

int func_01B06A08(int eff_id)
{
    int btl_cnt;
    u8 *tgt_list;
    u8 *btl_list;
    int i;

    D_01B0BAE0 = eff_id;
    D_01B0D1B0 = 0;

    if (func_001AEBD8() == 0x02350000) {
        D_01B0D280 = 1;
    } else {
        D_01B0D280 = 0;
    }
    if (func_001AEBD8() == 0x02360000) {
        D_01B0D284 = 1;
    } else {
        D_01B0D284 = 0;
    }
    if (func_001AEBD8() == 0x02370000) {
        D_01B0D288 = 1;
    } else {
        D_01B0D288 = 0;
    }
    if (func_001AEBD8() == 0x02470000) {
        D_01B0D28C = 1;
    } else {
        D_01B0D28C = 0;
    }
    if (func_001AEBD8() == 0x024A0000) {
        D_01B0D290 = 1;
    } else {
        D_01B0D290 = 0;
    }
    if (func_001AEBD8() == 0x018B0046) {
        D_01B0D294 = 1;
    } else {
        D_01B0D294 = 0;
    }

    D_01B0D2A0[0].chr = MsGetEff2Chr(D_01B0BAE0);
    if (MsGetRamChrMonster(D_01B0D2A0[0].chr) == 0) {
        D_01B0D2A0[1].chr = D_01B0D2A0[0].chr + 1;
        D_01B0D2A0[2].chr = D_01B0D2A0[0].chr + 2;
    } else {
        D_01B0D2A0[1].chr = D_01B0D2A0[0].chr - 1;
        D_01B0D2A0[2].chr = D_01B0D2A0[0].chr - 2;
    }

    for (i = 0; i < 3; i++) {
        ChrInfo *p = &D_01B0D2A0[i];
        func_01B05268(p);
        D_01B0D210[0] += p->pos40[0];
        D_01B0D210[2] += p->pos40[2];
    }
    D_01B0D210[0] /= 3.0f;
    D_01B0D210[2] /= 3.0f;
    D_01B0D210[1] = MsGetChrGround(D_01B0D2A0[0].chr);
    D_01B0D210[3] = 1.0f;
    if (D_01B0D280 != 0) {
        D_01B0D210[0] = D_01B0D2A0[0].pos40[0];
        D_01B0D210[2] = D_01B0D2A0[0].pos40[2];
    }
    func_002DD0B0(D_01B0D220, D_01B0D210);

    tgt_list = MsGetTargetList(D_01B0BAE0, &D_01B0D260);
    for (i = 0; i < D_01B0D260; i++) {
        D_01B0D510[i].chr = tgt_list[i];
        func_01B05268(&D_01B0D510[i]);
    }

    if (MsGetRamChrMonster(D_01B0D2A0[0].chr) == 0) {
        D_01B0F4C0.chr = MsGetSummonerNum(D_01B0D2A0[0].chr);
    } else {
        D_01B0F4C0.chr = 0xFF;
    }
    func_01B05268(&D_01B0F4C0);

    btl_list = MsGetBattleList(16, &btl_cnt);
    D_01B0D264 = 0;
    for (i = 0; i < btl_cnt; i++) {
        int c = btl_list[i];
        if (func_01B05230(D_01B0D2A0, 3, c) == 0 &&
            func_01B05230(D_01B0D510, D_01B0D260, c) == 0 &&
            func_01B05230(&D_01B0F4C0, 1, c) == 0) {
            ChrInfo *p = &D_01B0DB90[D_01B0D264++];
            p->chr = c;
            func_01B05268(p);
        }
    }

    func_01B045B0();
    D_01B0C7F4 = D_01C07E60;
    op_oef2_set2(D_01C07E60);
    D_01B0C7F8 = D_01BE9E20;
    op_oef2_set2(D_01BE9E20);
    D_01B0C7C4 = op_oef2_a_get(D_01B0C7F8, 6, 0);
    D_01B0C7C8 = op_oef2_a_get(D_01B0C7F8, 6, 1);
    D_01B0C7CC = op_oef2_a_get(D_01B0C7F8, 6, 2);
    D_01B0C7D0 = op_oef2_a_get(D_01B0C7F8, 6, 3);
    D_01B0C7D4 = op_oef2_a_get(D_01B0C7F8, 6, 4);
    D_01B0C7D8 = op_oef2_a_get(D_01B0C7F8, 6, 5);
    D_01B0C7DC = op_oef2_a_get(D_01B0C7F8, 6, 6);
    D_01B0C7E0 = op_oef2_a_get(D_01B0C7F8, 6, 7);
    D_01B0C7E4 = op_oef2_a_get(D_01B0C7F8, 6, 8);
    D_01B0C7E8 = op_oef2_a_get(D_01B0C7F8, 6, 9);
    D_01B0C7EC = op_oef2_a_get(D_01B0C7F8, 6, 10);
    op_oef2_sound_cue_multi(D_01B0C7F8, 0, 10, 0x100);
    D_01B0C7F0 = op_oef2_a_get(D_01B0C7F8, 5, 0);

    D_01B0D1FC = 0;
    D_01B0D1FA = 0;
    D_01B0D1F8 = 0;
    D_01B0D1F6 = 0;
    D_01B0D1F4 = 0;
    D_01B0D1F2 = 0;
    D_01B0D1F0 = 0;
    D_01B0D1EE = 0;
    D_01B0D1EC = 0;
    D_01B0D1EA = 0;
    D_01B0D1E8 = 0;
    D_01B0D1E6 = 0;
    D_01B0D1E4 = 0;
    D_01B0D1E2 = 0;
    D_01B0D1E0 = 0;
    D_01B0D1DE = 0;
    D_01B0D1DC = 0;
    D_01B0D1DA = 0;
    D_01B0D1D8 = 0;
    D_01B0D1D6 = 0;
    D_01B0D1D4 = 0;
    D_01B0D1D2 = 0;
    D_01B0D1D0 = 0;
    D_01B0D1CE = 0;
    D_01B0D1CC = 0;
    D_01B0D1CA = 0;
    D_01B0D1C8 = 0;
    D_01B0D1C6 = 0;
    D_01B0D1C4 = 0;
    D_01B0D1C2 = 0;
    D_01B0D1C0 = 0;
    D_01B0D1BE = 0;
    D_01B0D1BC = 0;
    D_01B0D1FE = 0x7FFF;

    MsGetDamageInfo(D_01B0BAE0, D_01B0D510[0].chr, 0, 0, 0);
    {
        register int t __asm__("$3") = D_01B0D260;
        D_01B0D200 = t * 5;
    }

    D_01B0C800.enabled = D_01B0C880.enabled = D_01B0C900.enabled =
    D_01B0C980[0].enabled = D_01B0C980[1].enabled = D_01B0C980[2].enabled =
    D_01B0CB00.enabled = D_01B0CB80.enabled = D_01B0CC00.enabled = D_01B0CC80.enabled = D_01B0CD00.enabled =
    D_01B0CD80[0].enabled = D_01B0CD80[1].enabled = D_01B0CD80[2].enabled =
    D_01B0CF00.enabled = D_01B0CF80.enabled = D_01B0D000.enabled = D_01B0D080.enabled =
    D_01B0D202 = 0;

    D_01B0D1B4 = 0;
    D_01B0D268 = 0;
    func_01B02478(0);
    func_01B02780(0);
    func_01B06278();
    func_01B05638();
    func_01B05BB8();
    D_01B0D26C = func_002B2E10(func_01B069D0, 0, 0, 0);
    return 0;
}
