/* tu_206 0x1dd7b8-0x1df1c0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"

void MsImportantInit(void) {
    D_00662E0C = 0;
    D_00662E10 = 0;
}

int MsImportantRead(void) {
    D_00662E0C = MsGetFileSize(0xD, 7, 0x18);
    if (D_00662E10 == 0) {
        func_0011C348(0x40);
        D_00662E10 = (s32)user_malloc(D_00662E0C, 5, D_0056F7D0, -1); /* DEBT(TYPE): handle/pointer kept as int */
        MsMemCheckRegist((void *)D_00662E10, D_00662E0C); /* DEBT(TYPE): handle/pointer kept as int */
    }
    GetCD()->f0(0x18, D_00662E10, 0, 0);
    return 0;
}

OfsTbl *MsImportantPtr(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, (void *)D_00662E10, pos);
}

int MsImportantName(int a) {
    s32 pos;
    u8 *t = MsGetExcelData(a & 0xFFF, (void *)D_00662E10, &pos);
    t += MsGetSaveConfigHiragana() * 4;
    return pos + *(u16 *)t;
}

int MsImportantGet(int i) {
    i &= 0xFFF;
    if (i < 0x80) {
        int w = i / 16;
        int m = 1 << (i & 0xF);
        if (D_003194D0.bits[w] & m) {
            return 1;
        }
    }
    return 0;
}

void MsImportantSet(int i)
{
    i &= 0xFFF;
    if (i < 0x80) {
        D_003194D0.bits[i / 16] |= 1 << (i & 0xF);
    }
}

void func_001DD998(int i)
{
    i &= 0xFFF;
    if (i < 0x80) {
        D_003194D0.bits[i / 16] &= ~(1 << (i & 0xF));
    }
}

int func_001DD9F0(void) {
    if (D_00662E10 != 0) {
        func_0011D590(D_00662E10, 5);
        D_00662E10 = 0;
    }
    return 0;
}

void func_001DDA30(void) {
    D_00662E14 = 0;
    D_00662E18 = 0;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void MsWeaponNameRead(void)
{
    s32 value0;

    D_00662E14 = MsGetFileSize(0xD, 7, 0x1B);
    if (D_00662E18 == 0)
    {
        func_0011C348(0x40);
        value0 = user_malloc(D_00662E14, 5, D_0056F7E0, -1);
        D_00662E18 = value0;
        MsMemCheckRegist((void *) value0, D_00662E14);
    }
    GetCD()->f0(0x1B, D_00662E18, 0, 0);
}

void MsWeaponNameFree(void) {
    if (D_00662E18 != 0) {
        func_0011D590(D_00662E18, 5);
        D_00662E18 = 0;
    }
}

int func_001DDB18(W5Rec *r, u16 key)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (r->h0E[i] == key) {
            return 1;
        }
    }
    return 0;
}

int MsWeaponNameNum(W5Rec *r)
{
    if (r->b5 == 0) {
        return func_001DDC18(r);
    }
    return func_001DE468(r);
}

int MsWeaponName(int a, int b, int alt, u16 *len) {
    s32 pos;
    u8 lang = b;
    V3TxtEnt *t = MsGetExcelData(a & 0xFFF, (void *)D_00662E18, &pos); /* DEBT(TYPE): handle/pointer kept as int */
    if (len != 0) {
        *len = t->n[lang];
    }
    if (alt != 0) {
        return pos + t->b[lang].ofs;
    }
    return pos + t->a[lang].ofs;
}

int func_001DDC18(W5Rec *r)
{
    int atk;
    int mag;
    int elem;
    int stat;

    atk = func_001DDB18(r, 0x8062);
    atk += func_001DDB18(r, 0x8063);
    atk += func_001DDB18(r, 0x8064);
    atk += func_001DDB18(r, 0x8065);
    mag = func_001DDB18(r, 0x8066);
    mag += func_001DDB18(r, 0x8067);
    mag += func_001DDB18(r, 0x8068);
    mag += func_001DDB18(r, 0x8069);
    elem = func_001DDB18(r, 0x801E);
    elem += func_001DDB18(r, 0x8022);
    elem += func_001DDB18(r, 0x8026);
    elem += func_001DDB18(r, 0x802A);
    stat = func_001DDB18(r, 0x802E);
    stat += func_001DDB18(r, 0x8036);
    stat += func_001DDB18(r, 0x803A);
    stat += func_001DDB18(r, 0x803E);
    stat += func_001DDB18(r, 0x8042);
    stat += func_001DDB18(r, 0x8046);
    stat += func_001DDB18(r, 0x804A);

    if ((((u8 *)r)[3] >> 2) & 1) {
        return 0x5000;
    }
    if ((((u8 *)r)[3] >> 3) & 1) {
        return 0x5001;
    }
    if (func_001DDB18(r, 0x807A)) {
        return 0x5002;
    }
    if (elem >= 4) {
        return 0x5003;
    }
    if (func_001DDB18(r, 0x8019)) {
        return 0x5004;
    }
    if (func_001DDB18(r, 0x800F) && func_001DDB18(r, 0x8013) && func_001DDB18(r, 0x8011)) {
        return 0x5005;
    }
    if (func_001DDB18(r, 0x800F) && func_001DDB18(r, 0x8011)) {
        return 0x5006;
    }
    if (func_001DDB18(r, 0x800E) && func_001DDB18(r, 0x8012)) {
        return 0x5007;
    }
    if (func_001DDB18(r, 0x800F)) {
        return 0x5008;
    }
    if (func_001DDB18(r, 0x800E)) {
        return 0x5009;
    }
    if (func_001DDB18(r, 0x8013)) {
        return 0x500A;
    }
    if (func_001DDB18(r, 0x8012)) {
        return 0x500B;
    }
    if (func_001DDB18(r, 0x8011)) {
        return 0x500C;
    }
    if (func_001DDB18(r, 0x8010)) {
        return 0x500D;
    }
    if (func_001DDB18(r, 0x800D)) {
        return 0x500F;
    }
    if (stat >= 4) {
        return 0x5010;
    }
    if (atk >= 4) {
        return 0x5013;
    }
    if (mag >= 4) {
        return 0x5014;
    }
    if (mag >= 3 && func_001DDB18(r, 0x8006)) {
        return 0x5015;
    }
    if (func_001DDB18(r, 0x800C)) {
        return 0x5016;
    }
    if (func_001DDB18(r, 0x801A)) {
        return 0x5017;
    }
    if (elem >= 3) {
        return 0x5018;
    }
    if (stat >= 3) {
        return 0x5019;
    }
    if ((func_001DDB18(r, 0x8003) || func_001DDB18(r, 0x8004)) && func_001DDB18(r, 0x8005)) {
        return 0x501A;
    }
    if (func_001DDB18(r, 0x8003) || func_001DDB18(r, 0x8004)) {
        return 0x501B;
    }
    if (func_001DDB18(r, 0x8005)) {
        return 0x5020;
    }
    if (func_001DDB18(r, 0x8006)) {
        return 0x5021;
    }
    if (func_001DDB18(r, 0x8007)) {
        return 0x5022;
    }
    if (func_001DDB18(r, 0x8001)) {
        return 0x5023;
    }
    if (func_001DDB18(r, 0x8002)) {
        return 0x5024;
    }
    if (func_001DDB18(r, 0x802E)) {
        return 0x5025;
    }
    if (func_001DDB18(r, 0x804A)) {
        return 0x5026;
    }
    if (func_001DDB18(r, 0x8036)) {
        return 0x5027;
    }
    if (func_001DDB18(r, 0x803A)) {
        return 0x5028;
    }
    if (func_001DDB18(r, 0x803E)) {
        return 0x5029;
    }
    if (func_001DDB18(r, 0x8042)) {
        return 0x502A;
    }
    if (func_001DDB18(r, 0x8046)) {
        return 0x502B;
    }
    if (atk >= 3) {
        return 0x502C;
    }
    if (mag >= 3) {
        return 0x502D;
    }
    if (elem >= 2) {
        return 0x502E;
    }
    stat = 0;
    if (func_001DDB18(r, 0x802E) || func_001DDB18(r, 0x802F)) {
        stat++;
    }
    if (func_001DDB18(r, 0x8036) || func_001DDB18(r, 0x8037)) {
        stat++;
    }
    if (func_001DDB18(r, 0x803A) || func_001DDB18(r, 0x803B)) {
        stat++;
    }
    if (func_001DDB18(r, 0x803E) || func_001DDB18(r, 0x803F)) {
        stat++;
    }
    if (func_001DDB18(r, 0x8042) || func_001DDB18(r, 0x8043)) {
        stat++;
    }
    if (func_001DDB18(r, 0x8046) || func_001DDB18(r, 0x8047)) {
        stat++;
    }
    if (func_001DDB18(r, 0x804A) || func_001DDB18(r, 0x804B)) {
        stat++;
    }
    if (stat >= 2) {
        return 0x502F;
    }
    if (func_001DDB18(r, 0x802F)) {
        return 0x5030;
    }
    if (func_001DDB18(r, 0x804B)) {
        return 0x5031;
    }
    if (func_001DDB18(r, 0x8037)) {
        return 0x5032;
    }
    if (func_001DDB18(r, 0x803B)) {
        return 0x5033;
    }
    if (func_001DDB18(r, 0x803F)) {
        return 0x5034;
    }
    if (func_001DDB18(r, 0x8043)) {
        return 0x5035;
    }
    if (func_001DDB18(r, 0x8047)) {
        return 0x5036;
    }
    if (func_001DDB18(r, 0x8000)) {
        return 0x5037;
    }
    if (func_001DDB18(r, 0x801E)) {
        return 0x5038;
    }
    if (func_001DDB18(r, 0x8022)) {
        return 0x5039;
    }
    if (func_001DDB18(r, 0x8026)) {
        return 0x503A;
    }
    if (func_001DDB18(r, 0x802A)) {
        return 0x503B;
    }
    if (func_001DDB18(r, 0x807C)) {
        return 0x501C;
    }
    if (func_001DDB18(r, 0x807D)) {
        return 0x501D;
    }
    if (func_001DDB18(r, 0x807E)) {
        return 0x501E;
    }
    if (func_001DDB18(r, 0x807F)) {
        return 0x501F;
    }
    if (((u8 *)r)[0xB] >= 4) {
        return 0x503C;
    }
    if (mag > 0 && atk > 0) {
        return 0x503D;
    }
    if (((u8 *)r)[0xB] >= 2) {
        return 0x503E;
    }
    if (func_001DDB18(r, 0x8068) || func_001DDB18(r, 0x8069)) {
        return 0x503F;
    }
    if (func_001DDB18(r, 0x8064) || func_001DDB18(r, 0x8065)) {
        return 0x5040;
    }
    if (func_001DDB18(r, 0x8067)) {
        return 0x5041;
    }
    if (func_001DDB18(r, 0x8066)) {
        return 0x5042;
    }
    if (func_001DDB18(r, 0x8063)) {
        return 0x5043;
    }
    if (func_001DDB18(r, 0x8062)) {
        return 0x5044;
    }
    if (func_001DDB18(r, 0x800B)) {
        return 0x5045;
    }
    return 0x5046;
}

int func_001DE468(W5Rec *r)
{
    int v_8008;
    int elem_eat;
    int elem_proof;
    int auto_buf;
    int stat_proof;
    int def_up;
    int mdef_up;
    int hp_up;
    int mp_up;
    int sos_buf;
    register int auto_buf2 __asm__("$18");

    v_8008 = func_001DDB18(r, 0x8008);
    v_8008 += func_001DDB18(r, 0x8009);
    v_8008 += func_001DDB18(r, 0x800A);
    elem_eat = func_001DDB18(r, 0x8021);
    elem_eat += func_001DDB18(r, 0x8025);
    elem_eat += func_001DDB18(r, 0x8029);
    elem_eat += func_001DDB18(r, 0x802D);
    elem_proof = func_001DDB18(r, 0x8020);
    elem_proof += func_001DDB18(r, 0x8024);
    elem_proof += func_001DDB18(r, 0x8028);
    elem_proof += func_001DDB18(r, 0x802C);
    auto_buf = func_001DDB18(r, 0x8054);
    auto_buf += func_001DDB18(r, 0x8055);
    auto_buf += func_001DDB18(r, 0x8057);
    auto_buf += func_001DDB18(r, 0x8058);
    stat_proof = func_001DDB18(r, 0x8030);
    stat_proof += func_001DDB18(r, 0x8034);
    stat_proof += func_001DDB18(r, 0x8038);
    stat_proof += func_001DDB18(r, 0x803C);
    stat_proof += func_001DDB18(r, 0x8040);
    stat_proof += func_001DDB18(r, 0x8044);
    stat_proof += func_001DDB18(r, 0x8048);
    stat_proof += func_001DDB18(r, 0x804C);
    stat_proof += func_001DDB18(r, 0x804E);
    stat_proof += func_001DDB18(r, 0x8050);
    stat_proof += func_001DDB18(r, 0x8052);
    def_up = func_001DDB18(r, 0x806A);
    def_up += func_001DDB18(r, 0x806B);
    def_up += func_001DDB18(r, 0x806C);
    def_up += func_001DDB18(r, 0x806D);
    mdef_up = func_001DDB18(r, 0x806E);
    mdef_up += func_001DDB18(r, 0x806F);
    mdef_up += func_001DDB18(r, 0x8070);
    mdef_up += func_001DDB18(r, 0x8071);
    hp_up = func_001DDB18(r, 0x8072);
    hp_up += func_001DDB18(r, 0x8073);
    hp_up += func_001DDB18(r, 0x8074);
    hp_up += func_001DDB18(r, 0x8075);
    mp_up = func_001DDB18(r, 0x8076);
    mp_up += func_001DDB18(r, 0x8077);
    mp_up += func_001DDB18(r, 0x8078);
    mp_up += func_001DDB18(r, 0x8079);
    sos_buf = func_001DDB18(r, 0x805E);
    sos_buf += func_001DDB18(r, 0x805F);
    sos_buf += func_001DDB18(r, 0x8060);
    sos_buf += func_001DDB18(r, 0x8061);
    auto_buf2 = func_001DDB18(r, 0x8059);
    auto_buf2 += func_001DDB18(r, 0x805A);
    auto_buf2 += func_001DDB18(r, 0x805B);
    auto_buf2 += func_001DDB18(r, 0x805C);
    auto_buf2 += func_001DDB18(r, 0x805D);

    if (func_001DDB18(r, 0x8017) && func_001DDB18(r, 0x8018)) {
        return 0x504A;
    }
    if (func_001DDB18(r, 0x8080)) {
        return 0x509E;
    }
    if (func_001DDB18(r, 0x8017)) {
        return 0x504B;
    }
    if (func_001DDB18(r, 0x8018)) {
        return 0x504C;
    }
    if (elem_eat >= 4) {
        return 0x504D;
    }
    if (elem_proof >= 4) {
        return 0x504E;
    }
    if (auto_buf >= 4) {
        return 0x504F;
    }
    if (v_8008 >= 3) {
        return 0x5050;
    }
    if (func_001DDB18(r, 0x8008) && func_001DDB18(r, 0x8009)) {
        return 0x5051;
    }
    if (stat_proof >= 4) {
        return 0x5052;
    }
    if (def_up >= 4) {
        return 0x5053;
    }
    if (mdef_up >= 4) {
        return 0x5054;
    }
    if (hp_up >= 4) {
        return 0x5055;
    }
    if (mp_up >= 4) {
        return 0x5056;
    }
    if (func_001DDB18(r, 0x8016)) {
        return 0x5057;
    }
    if (func_001DDB18(r, 0x8015)) {
        return 0x5058;
    }
    if (func_001DDB18(r, 0x801B) && func_001DDB18(r, 0x801C)) {
        return 0x5059;
    }
    v_8008 = auto_buf + func_001DDB18(r, 0x8056);
    if (v_8008 >= 3) {
        return 0x505A;
    }
    if (elem_eat >= 3) {
        return 0x505B;
    }
    if (func_001DDB18(r, 0x801B)) {
        return 0x505C;
    }
    if (func_001DDB18(r, 0x801C)) {
        return 0x505D;
    }
    if (func_001DDB18(r, 0x800A)) {
        return 0x505E;
    }
    if (func_001DDB18(r, 0x8009)) {
        return 0x505F;
    }
    if (sos_buf >= 4) {
        return 0x5060;
    }
    auto_buf2 = sos_buf + auto_buf2;
    if (auto_buf2 >= 4) {
        return 0x5061;
    }
    if (stat_proof >= 3) {
        return 0x5062;
    }
    if (func_001DDB18(r, 0x801D)) {
        return 0x5063;
    }
    if (func_001DDB18(r, 0x8008)) {
        return 0x5064;
    }
    if (elem_proof >= 3) {
        return 0x5065;
    }
    if (auto_buf2 >= 3) {
        return 0x5066;
    }
    v_8008 = auto_buf + func_001DDB18(r, 0x8056);
    if (v_8008 >= 2) {
        return 0x5067;
    }
    if (auto_buf2 >= 2) {
        return 0x5068;
    }
    if (func_001DDB18(r, 0x8057) || func_001DDB18(r, 0x805C)) {
        return 0x5069;
    }
    if (func_001DDB18(r, 0x8056) || func_001DDB18(r, 0x805B)) {
        return 0x506A;
    }
    if (func_001DDB18(r, 0x8058) || func_001DDB18(r, 0x805D)) {
        return 0x506B;
    }
    if (func_001DDB18(r, 0x8054) || func_001DDB18(r, 0x8059)) {
        return 0x506C;
    }
    if (func_001DDB18(r, 0x8055) || func_001DDB18(r, 0x805A)) {
        return 0x506D;
    }
    if (func_001DDB18(r, 0x8007)) {
        return 0x506E;
    }
    if (def_up >= 3) {
        return 0x506F;
    }
    if (mdef_up >= 3) {
        return 0x5070;
    }
    if (hp_up >= 3) {
        return 0x5071;
    }
    if (mp_up >= 3) {
        return 0x5072;
    }
    v_8008 = 0;
    if (func_001DDB18(r, 0x8021) || func_001DDB18(r, 0x8020)) {
        v_8008++;
    }
    if (func_001DDB18(r, 0x8025) || func_001DDB18(r, 0x8024)) {
        v_8008++;
    }
    if (func_001DDB18(r, 0x8029) || func_001DDB18(r, 0x8028)) {
        v_8008++;
    }
    if (func_001DDB18(r, 0x802D) || func_001DDB18(r, 0x802C)) {
        v_8008++;
    }
    if (v_8008 >= 2) {
        return 0x5073;
    }
    if (stat_proof >= 2) {
        return 0x5074;
    }
    if (func_001DDB18(r, 0x8021)) {
        return 0x5075;
    }
    if (func_001DDB18(r, 0x8025)) {
        return 0x5076;
    }
    if (func_001DDB18(r, 0x8029)) {
        return 0x5077;
    }
    if (func_001DDB18(r, 0x802D)) {
        return 0x5078;
    }
    if (func_001DDB18(r, 0x8052) || func_001DDB18(r, 0x8053)) {
        return 0x5079;
    }
    if (func_001DDB18(r, 0x804E) || func_001DDB18(r, 0x804F)) {
        return 0x507A;
    }
    if (func_001DDB18(r, 0x8050) || func_001DDB18(r, 0x8051)) {
        return 0x507B;
    }
    if (func_001DDB18(r, 0x804C) || func_001DDB18(r, 0x804D)) {
        return 0x507C;
    }
    if (func_001DDB18(r, 0x8030) || func_001DDB18(r, 0x8031)) {
        return 0x507D;
    }
    if (func_001DDB18(r, 0x8034) || func_001DDB18(r, 0x8035)) {
        return 0x507E;
    }
    if (func_001DDB18(r, 0x8038) || func_001DDB18(r, 0x8039)) {
        return 0x507F;
    }
    if (func_001DDB18(r, 0x803C) || func_001DDB18(r, 0x803D)) {
        return 0x5080;
    }
    if (func_001DDB18(r, 0x8040) || func_001DDB18(r, 0x8041)) {
        return 0x5081;
    }
    if (func_001DDB18(r, 0x8044) || func_001DDB18(r, 0x8045)) {
        return 0x5082;
    }
    if (func_001DDB18(r, 0x8048) || func_001DDB18(r, 0x8049)) {
        return 0x5083;
    }
    if (func_001DDB18(r, 0x8020) || func_001DDB18(r, 0x801F)) {
        return 0x5084;
    }
    if (func_001DDB18(r, 0x8024) || func_001DDB18(r, 0x8023)) {
        return 0x5085;
    }
    if (func_001DDB18(r, 0x8028) || func_001DDB18(r, 0x8027)) {
        return 0x5086;
    }
    if (func_001DDB18(r, 0x802C) || func_001DDB18(r, 0x802B)) {
        return 0x5087;
    }
    if (func_001DDB18(r, 0x805E)) {
        return 0x5088;
    }
    if (func_001DDB18(r, 0x8061)) {
        return 0x5089;
    }
    if (func_001DDB18(r, 0x8060)) {
        return 0x508A;
    }
    if (func_001DDB18(r, 0x805F)) {
        return 0x508B;
    }
    if (hp_up + mp_up >= 4) {
        return 0x508C;
    }
    if (((u8 *)r)[0xB] >= 4) {
        return 0x508D;
    }
    if (def_up > 0 && mdef_up > 0) {
        return 0x508E;
    }
    if (def_up >= 2) {
        return 0x508F;
    }
    if (mdef_up >= 2) {
        return 0x5090;
    }
    if (hp_up >= 2) {
        return 0x5091;
    }
    if (mp_up >= 2) {
        return 0x5092;
    }
    if (func_001DDB18(r, 0x806C) || func_001DDB18(r, 0x806D)) {
        return 0x5093;
    }
    if (func_001DDB18(r, 0x8070) || func_001DDB18(r, 0x8071)) {
        return 0x5094;
    }
    if (func_001DDB18(r, 0x8078) || func_001DDB18(r, 0x8079)) {
        return 0x5095;
    }
    if (func_001DDB18(r, 0x8074) || func_001DDB18(r, 0x8075)) {
        return 0x5096;
    }
    if (((u8 *)r)[0xB] >= 3) {
        return 0x5097;
    }
    if (func_001DDB18(r, 0x806A) || func_001DDB18(r, 0x806B)) {
        return 0x5098;
    }
    if (func_001DDB18(r, 0x806E) || func_001DDB18(r, 0x806F)) {
        return 0x5099;
    }
    if (func_001DDB18(r, 0x8076) || func_001DDB18(r, 0x8077)) {
        return 0x509A;
    }
    if (func_001DDB18(r, 0x8072) || func_001DDB18(r, 0x8073)) {
        return 0x509B;
    }
    __asm__ volatile("" : : "r"(auto_buf2));
    if (((u8 *)r)[0xB] >= 2) {
        return 0x509C;
    }
    return 0x509D;
}
