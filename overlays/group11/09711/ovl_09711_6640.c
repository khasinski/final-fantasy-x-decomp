#include "oef_overlay.h"

typedef struct ChrSlot {
    int id;            /* 0x00 */
    u8 pad04[0x3C];
    float pos1[4];     /* 0x40 */
    u8 pad50[0x80];
} ChrSlot;             /* 0xD0 */

extern int D_01B0B400;
extern void *D_01B0C0E4;
extern void *D_01B0C0E8;
extern void *D_01B0C0EC;
extern void *D_01B0C0F0;
extern void *D_01B0C0F4;
extern void *D_01B0C0F8;
extern void *D_01B0C0FC;
extern void *D_01B0C100;
extern void *D_01B0C104;
extern void *D_01B0C108;
extern void *D_01B0C10C;
extern void *D_01B0C110;
extern void *D_01B0C114;
extern void *D_01B0C118;
extern OefPartObj D_01B0C120;
extern OefPartObj D_01B0C1A0;
extern OefPartObj D_01B0C220;
extern OefPartObj D_01B0C2A0[3];
extern OefPartObj D_01B0C420;
extern OefPartObj D_01B0C4A0;
extern OefPartObj D_01B0C520;
extern OefPartObj D_01B0C5A0;
extern OefPartObj D_01B0C620;
extern OefPartObj D_01B0C6A0[3];
extern OefPartObj D_01B0C820;
extern OefPartObj D_01B0C8A0;
extern OefPartObj D_01B0C920;
extern OefPartObj D_01B0C9A0;
extern int D_01B0CAD0;
extern int D_01B0CAD4;
extern s16 D_01B0CADC;
extern s16 D_01B0CADE;
extern s16 D_01B0CAE0;
extern s16 D_01B0CAE2;
extern s16 D_01B0CAE4;
extern s16 D_01B0CAE6;
extern s16 D_01B0CAE8;
extern s16 D_01B0CAEA;
extern s16 D_01B0CAEC;
extern s16 D_01B0CAEE;
extern s16 D_01B0CAF0;
extern s16 D_01B0CAF2;
extern s16 D_01B0CAF4;
extern s16 D_01B0CAF6;
extern s16 D_01B0CAF8;
extern s16 D_01B0CAFA;
extern s16 D_01B0CAFC;
extern s16 D_01B0CAFE;
extern s16 D_01B0CB00;
extern s16 D_01B0CB02;
extern s16 D_01B0CB04;
extern s16 D_01B0CB06;
extern s16 D_01B0CB08;
extern s16 D_01B0CB0A;
extern s16 D_01B0CB0C;
extern s16 D_01B0CB0E;
extern s16 D_01B0CB10;
extern s16 D_01B0CB12;
extern s16 D_01B0CB14;
extern s16 D_01B0CB16;
extern s16 D_01B0CB18;
extern s16 D_01B0CB1A;
extern s16 D_01B0CB1C;
extern s16 D_01B0CB1E;
extern s16 D_01B0CB20;
extern s16 D_01B0CB22;
extern float D_01B0CB30[4];
extern float D_01B0CB40[16];
extern int D_01B0CB80;
extern int D_01B0CB84;
extern int D_01B0CB88;
extern void *D_01B0CB8C;
extern ChrSlot D_01B0CBA0[3];
extern ChrSlot D_01B0CE10[8];
extern ChrSlot D_01B0D490[8];
extern ChrSlot D_01B0EDC0;
extern u8 D_01BE9720[];
extern u8 D_01C07760[];

int MsGetRamChrMonster(int);
float MsGetChrGround(int);
void func_002DD0B0(void *, void *);
int MsGetSummonerNum(int);
u8 *MsGetBattleList(int, int *);
void MsGetDamageInfo(int, int, int, int, int);
void *func_002B2E10(void *, int, int, int);
void func_01B05010(ChrSlot *);
int func_01B04FD8(ChrSlot *, int, int);
void func_01B04358(void);
void func_01B02220(int);
void func_01B02528(int);
void func_01B05EB0(void);
void func_01B05270(void);
void func_01B057F0(void);
void func_01B06608(void);

int func_01B06640(int eff_id)
{
    int cnt;
    int i;
    u8 *tlist;
    u8 *blist;

    D_01B0B400 = eff_id;
    D_01B0CAD0 = 0;
    D_01B0CBA0[0].id = MsGetEff2Chr(eff_id);
    if (MsGetRamChrMonster(D_01B0CBA0[0].id) == 0) {
        D_01B0CBA0[1].id = D_01B0CBA0[0].id + 1;
        D_01B0CBA0[2].id = D_01B0CBA0[0].id + 2;
    } else {
        D_01B0CBA0[1].id = D_01B0CBA0[0].id - 1;
        D_01B0CBA0[2].id = D_01B0CBA0[0].id - 2;
    }
    for (i = 0; i < 3; i++) {
        ChrSlot *p = &D_01B0CBA0[i];
        func_01B05010(p);
        D_01B0CB30[0] += p->pos1[0];
        D_01B0CB30[2] += p->pos1[2];
    }
    D_01B0CB30[0] /= 3.0f;
    D_01B0CB30[2] /= 3.0f;
    D_01B0CB30[1] = MsGetChrGround(D_01B0CBA0[0].id);
    D_01B0CB30[3] = 1.0f;
    func_002DD0B0(D_01B0CB40, D_01B0CB30);

    tlist = MsGetTargetList(D_01B0B400, &D_01B0CB80);
    for (i = 0; i < D_01B0CB80; i++) {
        D_01B0CE10[i].id = tlist[i];
        func_01B05010(&D_01B0CE10[i]);
    }
    if (MsGetRamChrMonster(D_01B0CBA0[0].id) == 0) {
        D_01B0EDC0.id = MsGetSummonerNum(D_01B0CBA0[0].id);
    } else {
        D_01B0EDC0.id = 255;
    }
    func_01B05010(&D_01B0EDC0);

    blist = MsGetBattleList(16, &cnt);
    D_01B0CB84 = 0;
    for (i = 0; i < cnt; i++) {
        u8 id = blist[i];
        if (!func_01B04FD8(D_01B0CBA0, 3, id) &&
            !func_01B04FD8(D_01B0CE10, D_01B0CB80, id) &&
            !func_01B04FD8(&D_01B0EDC0, 1, id)) {
            ChrSlot *q = &D_01B0D490[D_01B0CB84++];
            q->id = id;
            func_01B05010(q);
        }
    }
    func_01B04358();
    D_01B0C114 = D_01C07760;
    op_oef2_set2(D_01C07760);
    D_01B0C118 = D_01BE9720;
    op_oef2_set2(D_01BE9720);
    D_01B0C0E4 = op_oef2_a_get(D_01B0C118, 6, 0);
    D_01B0C0E8 = op_oef2_a_get(D_01B0C118, 6, 1);
    D_01B0C0EC = op_oef2_a_get(D_01B0C118, 6, 2);
    D_01B0C0F0 = op_oef2_a_get(D_01B0C118, 6, 3);
    D_01B0C0F4 = op_oef2_a_get(D_01B0C118, 6, 4);
    D_01B0C0F8 = op_oef2_a_get(D_01B0C118, 6, 5);
    D_01B0C0FC = op_oef2_a_get(D_01B0C118, 6, 6);
    D_01B0C100 = op_oef2_a_get(D_01B0C118, 6, 7);
    D_01B0C104 = op_oef2_a_get(D_01B0C118, 6, 8);
    D_01B0C108 = op_oef2_a_get(D_01B0C118, 6, 9);
    D_01B0C10C = op_oef2_a_get(D_01B0C118, 6, 10);
    op_oef2_sound_cue_multi(D_01B0C118, 0, 10, 256);
    D_01B0C110 = op_oef2_a_get(D_01B0C118, 5, 1);

    D_01B0CADC = D_01B0CADE = D_01B0CAE0 = D_01B0CAE2 =
    D_01B0CAE4 = D_01B0CAE6 = D_01B0CAE8 = D_01B0CAEA =
    D_01B0CAEC = D_01B0CAEE = D_01B0CAF0 = D_01B0CAF2 =
    D_01B0CAF4 = D_01B0CAF6 = D_01B0CAF8 = D_01B0CAFA =
    D_01B0CAFC = D_01B0CAFE = D_01B0CB00 = D_01B0CB02 =
    D_01B0CB04 = D_01B0CB06 = D_01B0CB08 = D_01B0CB0A =
    D_01B0CB0C = D_01B0CB0E = D_01B0CB10 = D_01B0CB12 =
    D_01B0CB14 = D_01B0CB16 = D_01B0CB18 = D_01B0CB1A =
    D_01B0CB1C = 0;
    D_01B0CB1E = 0x7FFF;
    MsGetDamageInfo(D_01B0B400, D_01B0CE10[0].id, 0, 0, 0);
    {
        register int n __asm__("$3") = D_01B0CB80;
        D_01B0CB20 = n * 5;
        D_01B0CB22 = 0;
    }

    D_01B0C120.enabled = D_01B0C1A0.enabled = D_01B0C220.enabled =
    D_01B0C2A0[0].enabled = D_01B0C2A0[1].enabled = D_01B0C2A0[2].enabled =
    D_01B0C420.enabled = D_01B0C4A0.enabled = D_01B0C520.enabled =
    D_01B0C5A0.enabled = D_01B0C620.enabled = D_01B0C6A0[0].enabled =
    D_01B0C6A0[1].enabled = D_01B0C6A0[2].enabled = D_01B0C820.enabled =
    D_01B0C8A0.enabled = D_01B0C920.enabled = D_01B0C9A0.enabled = 0;

    D_01B0CAD4 = 0;
    D_01B0CB88 = 0;
    func_01B02220(0);
    func_01B02528(0);
    func_01B05EB0();
    func_01B05270();
    func_01B057F0();
    D_01B0CB8C = func_002B2E10(func_01B06608, 0, 0, 0);
    return 0;
}
