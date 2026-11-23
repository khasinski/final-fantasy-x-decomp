/* tu_198 0x1d00d8-0x1d2170: low; ~Ms (config/tu_map.tsv) */
#define D_0031FA50 _hdr_D_0031FA50
#define MsExchangeChr _hdr_MsExchangeChr
#define func_001D1DF8 _hdr_func_001D1DF8
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#undef func_001D1DF8
#undef D_0031FA50
#undef MsExchangeChr

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    u16 h4;
    u8 b6;
    u8 pad7;
    u16 h8;
    u8 bA;
    u8 padB;
    u16 hC;
    u8 bE;
    u8 padF;
} CmdUseEnt16;

extern CmdUseEnt16 D_0031FA50[];
int MsInsertChrCommand(int id, int target, int mode);
void MsExchangeParty(void);
void MsGetMoveTargetPos(int id, BtlChr *c, int a2, float *out, int a4);
float func_001AC348(float *a, float *b);
extern u64 _u64_D_00317320 __asm__("D_00317320");
extern s64 _d_D_0056EA98 __asm__("D_0056EA98");
s32 _D1DF8_cmpdf2(s64, s64) __asm__("func_002EC198");
s64 _D1DF8_extendsfdf2(float) __asm__("func_002ED038");

extern void *MsGetCommand(int, int, int, void *, int *);
extern int MsCheckRange(int, int, int);
extern int func_001D0D48(u16 *);
extern void func_001B7498(int, int);
extern int MsGetRamChrMonster(int);
extern int MsGetRamChrSummon(int);
extern BtlChr *MsGetWeaponSpecial(int, int);
extern void MsMusicVolume(int, int);
extern void MsSetTargetDir(int, int);
extern int _m_MsGetMagicEffNum(int, int, void *) __asm__("MsGetMagicEffNum");
extern void MsSetSaveCommandUse(int, int, int);
extern int MsLimitCommandProcess(int, BtlChr *, GsEnt48 *, int);
extern void func_001D0D98(int, BtlChr *);
extern void MsSetMotionAttackWait(int);
extern void MsEffectRead(int, int);
extern void MsSetMotionReturn(int);
extern void func_001E0A18(BtlChr *, int, int);
extern int MsCalcEscape(int, BtlChr *);
extern float MsGetEscapeDir(int);
extern void MsEscapeAll(void);
extern int MsExchangeChr(int, int, int, int);
extern void MsExchangeSummon(int, int);
extern void msSetEndDir(BtlChr *);
extern int MsCheckMegas(int);
extern s32 func_001D1458(int, int, int);
extern int MsActionRequest(int, int, int, int, int, void *);
extern void MsPopBtlPos(BtlChr *);
extern void MsUseChrMpLimit(int);

extern void _m_MsMenuOpenTitleWindow(int, int) __asm__("MsMenuOpenTitleWindow");

typedef struct {
    u8 pad0[0x1753];
    u8 f1753;
    u8 pad1754[0x2004 - 0x1754];
    s32 f2004;
    s32 f2008;
    s32 f200C;
    u8 pad2010[0x2125 - 0x2010];
    u8 f2125;
    u8 pad2126[0x2134 - 0x2126];
    s8 f2134;
    u8 f2135;
    u8 pad2136[0x2145 - 0x2136];
    u8 f2145;
} ParseGS;

typedef struct {
    u8 pad0[0x24];
    u8 b24[8];
} ParseBtlGetData;

extern ParseGS _pgs_D_003172F0 __asm__("D_003172F0");
extern ParseBtlGetData _pbg_btlgetdata __asm__("btlgetdata");

int MsParseCommand(GsEnt48 *ent)
{
    int cmd_id;
    int show_title;
    int use_mp;
    int f106;
    int idx;
    int mot;
    int req_mcam;
    int mcam_a3;
    int mcam_t0;
    int m34;
    int m38;
    int m3C;
    int m40;
    int flag44;
    int flag48;
    int mot_atk;
    int fBA;
    int do_act = -1;
    int id = ent->id;
    u8 *cmd;
    BtlChr *c;
    u8 *cp;
    BtlChr *wsp;
    int mS6;
    int mFP;
    int target_dir;
    int i;
    int eff_num;
    u16 cmd_u16;

    idx = ent->f2;
    flag48 = 1;
    flag44 = -1;
    cmd = (u8 *)MsGetCommand(id, 1, -1, &ent->f8[idx], &cmd_id);
    c = MsGetChr(id);
    cp = (u8 *)c;

    show_title = -1;
    {
        u16 c16 = cmd_id;
        _pgs_D_003172F0.f2008 = cmd_id;
        _pgs_D_003172F0.f200C = cmd_id;
        use_mp = -1;
        mot = -1;
        f106 = 0;
        mot_atk = 2;
        req_mcam = 0;
        fBA = 0;
        mcam_a3 = 0xFFFF;
        mcam_t0 = 0xFFFF;

        _pgs_D_003172F0.f2135 = (*(u32 *)(cmd + 0x1C) >> 29) & 1;
        _pgs_D_003172F0.f2134 = (*(u32 *)(cmd + 0x1C) >> 30) & 1;
        cp[0xAD6] = flag48;
        cp[0xAD9] = flag48;
        *(u16 *)(cp + 0xC1C) = c16;
        *(s16 *)(cp + 0xADA) = flag44;
    }
    cp[0x39F] = MsCheckRange(cp[0x39F] + 1, 1, 0xFF);
    cp[0x10A] = 0;
    cp[0xAD4] = (*(u16 *)(cmd + 0x1A) >> 14) & 1;
    cp[0x111] = func_001D1BF0(id, (Sub1C *)cmd);

    if (idx == 0) {
        cp[0x390] = func_001D0D48((u16 *)&ent->f8[0]);
    }
    if (cp[0x390] != 0) {
        _pgs_D_003172F0.f2145++;
    }
    if (*(u32 *)(cp + 0x16C) & 0x10000) {
        func_001B7498(id, -1);
    }

    if (MsGetRamChrMonster(id) != 0) {
        m34 = 0x2E;
        mS6 = 0x2C;
        mFP = 0x2D;
        m38 = 0x2F;
        m3C = 0x85;
        m40 = 0x86;
    } else {
        if (MsGetRamChrSummon(id) != 0) {
            mS6 = 0x78;
            mFP = 0x79;
            m3C = 0x7A;
            m40 = 0x7B;
        } else {
            m3C = 0x3B;
            mS6 = 0x1B;
            m40 = 0x3C;
            mFP = 0x34;
        }
        m34 = 0x32;
        m38 = 0x33;
    }

    wsp = MsGetWeaponSpecial(id, 0);
    if (wsp != 0) {
        *(s32 *)((u8 *)wsp + 0xA80) = *(s32 *)(cp + 0xA80);
    }
    if (*(s8 *)(cp + 0xAAA) == 1) {
        target_dir = 0;
        mS6 = 0xFFFF;
        mFP = 0x89;
    } else {
        target_dir = *(s32 *)(cp + 0xA80);
    }
    _pgs_D_003172F0.f2004 = *(s32 *)(cp + 0xA80);
    if (_pgs_D_003172F0.f2134 != 0) {
        MsMusicVolume(0x65, 0x1E);
    }
    MsSetTargetDir(id, target_dir);
    if ((*(u32 *)(cmd + 0x1C) >> 22) & 1) {
        cp[0x38A] = 1;
    }
    if (!((*(u32 *)(cmd + 0x1C) >> 26) & 1)) {
        cp[0xACF] = 0;
    }
    for (i = 0; i < 4; i++) {
        ((struct { u8 pad[0xAC0]; u8 b[4]; u16 h[4]; } *)c)->b[i] = 0xFF;
        ((struct { u8 pad[0xAC0]; u8 b[4]; u16 h[4]; } *)c)->h[i] = 0xFFFF;
    }
    eff_num = _m_MsGetMagicEffNum(id, cmd_id, cmd);
    MsSetSaveCommandUse(id, cmd_id, 1);
    cmd_u16 = cmd_id;
    switch (cmd_u16) {
    case 0x3026:
        MsSetVoiceCheck(id, 0xD, 1, 0, 0);
        break;
    case 0x3025:
        MsSetVoiceCheck(id, 0xE, 1, 0, 0);
        break;
    }
    MsLimitCommandProcess(id, c, ent, idx);

    switch (cmd[0x15]) {
    case 30:
        fBA = 1;
        mot_atk = 0x50;
        /* fallthrough */
    case 1:
        func_001D0D98(id, c);
        f106 = 1;
        if (MsGetRamChrMonster(id) == 0) {
            mcam_a3 = id + 0x7B;
            if (id <= 0xE) {
                mcam_a3 = id + 0x1D;
            }
            mcam_t0 = 0x1A;
        } else {
            mcam_a3 = 0x31;
            mcam_t0 = 0x1A;
        }
        if (*(u32 *)(cp + 0x16C) & 0x10) {
            do_act = 0;
            cp[0xAC0] = mot_atk;
            *(u16 *)(cp + 0xAC4) = mcam_a3;
            show_title = 0;
            *(u16 *)(cp + 0xAC8) = mcam_t0;
            MsSetMotionAttackWait(id);
        } else {
            req_mcam = 1;
            mot = mot_atk;
        }
        break;
    case 23:
        func_001D0D98(id, c);
        do_act = 0;
        *(u16 *)(cp + 0xAC4) = m3C;
        cp[0xAC0] = 0xA;
        *(u16 *)(cp + 0xAC6) = m40;
        cp[0xAC1] = 2;
        f106 = 3;
        show_title = 0;
        use_mp = 0;
        flag48 = 0;
        MsEffectRead(id, eff_num);
        break;
    case 24:
        func_001D0D98(id, c);
        do_act = 0;
        *(u16 *)(cp + 0xAC4) = m3C;
        cp[0xAC0] = 0xA;
        *(u16 *)(cp + 0xAC6) = m40;
        cp[0xAC1] = 0x42;
        f106 = 3;
        show_title = 0;
        use_mp = 0;
        flag48 = 0;
        MsEffectRead(id, eff_num);
        break;
    case 5:
        cp[0xAC0] = 0x13;
        *(u16 *)(cp + 0xAC4) = 0x37;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 6:
        cp[0xAC0] = 0x14;
        *(u16 *)(cp + 0xAC4) = 0x38;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 7:
        cp[0xAC0] = 0x15;
        *(u16 *)(cp + 0xAC4) = 0x39;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 8:
        cp[0xAC0] = 0x16;
        *(u16 *)(cp + 0xAC4) = 0x3A;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 18:
        cp[0xAC0] = 0x17;
        *(u16 *)(cp + 0xAC4) = 0x7E;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 19:
        cp[0xAC0] = 0x18;
        *(u16 *)(cp + 0xAC4) = 0x7F;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 20:
        cp[0xAC0] = 0x19;
        *(u16 *)(cp + 0xAC4) = 0x80;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 21:
        cp[0xAC0] = 0x1A;
        *(u16 *)(cp + 0xAC4) = 0x81;
        do_act = 0;
        show_title = 0;
        MsSetMotionReturn(id);
        break;
    case 14:
        req_mcam = 1;
        f106 = 1;
        mot = 0x28;
        mcam_a3 = 0x40;
        break;
    case 15:
        req_mcam = 1;
        f106 = 1;
        mot = 0x29;
        mcam_a3 = 0x41;
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        cp[0xAC0] = cmd[0x15] + 0x14;
        *(u16 *)(cp + 0xAC4) = mS6;
        show_title = 0;
        do_act = 0;
        f106 = 2;
        use_mp = 0;
        cp[0xAC1] = cmd[0x15] + 0x19;
        *(u16 *)(cp + 0xAC6) = mFP;
        MsEffectRead(id, eff_num);
        break;
    case 25:
    case 26:
    case 27:
        cp[0xAC0] = cmd[0x15] + 0x2B;
        *(u16 *)(cp + 0xAC4) = mS6;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        f106 = 2;
        cp[0xAC1] = cmd[0x15] + 0x2E;
        *(u16 *)(cp + 0xAC6) = mFP;
        MsEffectRead(id, eff_num);
        break;
    case 28:
        *(u16 *)(cp + 0xAC4) = m34;
        do_act = 0;
        cp[0xAC0] = 0xFF;
        *(u16 *)(cp + 0xAC6) = m38;
        cp[0xAC1] = 0x22;
        show_title = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    case 2:
        *(u16 *)(cp + 0xAC4) = m34;
        do_act = 0;
        cp[0xAC0] = 6;
        *(u16 *)(cp + 0xAC6) = m38;
        cp[0xAC1] = 7;
        show_title = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    case 3:
        cp[0xAC0] = 4;
        cp[0xAC1] = 5;
        *(u16 *)(cp + 0xAC4) = mS6;
        *(u16 *)(cp + 0xAC6) = mFP;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    case 17:
        *(u16 *)(cp + 0xAC4) = mS6;
        *(u16 *)(cp + 0xAC6) = mFP;
        f106 = 2;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        MsEffectRead(id, eff_num);
        break;
    case 16:
        cp[0xAC0] = 0x2A;
        cp[0xAC1] = 0x2B;
        *(u16 *)(cp + 0xAC4) = mS6;
        *(u16 *)(cp + 0xAC6) = mFP;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    case 29:
        cp[0xAC0] = 0x4C;
        cp[0xAC1] = 0x4D;
        *(u16 *)(cp + 0xAC4) = mS6;
        *(u16 *)(cp + 0xAC6) = mFP;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    case 4:
        *(u16 *)(cp + 0xAC4) = m3C;
        do_act = 0;
        cp[0xAC0] = 0xA;
        *(u16 *)(cp + 0xAC6) = m40;
        cp[0xAC1] = 0xB;
        f106 = 2;
        show_title = 0;
        use_mp = 0;
        MsEffectRead(id, eff_num);
        break;
    case 22:
        cp[0xABC] = 1;
        cp[0xAC0] = 0x4B;
        cp[0xAC1] = 0x2B;
        *(u16 *)(cp + 0xAC4) = mS6;
        *(u16 *)(cp + 0xAC6) = mFP;
        do_act = 0;
        show_title = 0;
        use_mp = 0;
        f106 = 2;
        MsEffectRead(id, eff_num);
        break;
    default:
        switch (cmd_u16) {
        case 0x3055:
            cp[0xAC0] = 0x4A;
            *(u16 *)(cp + 0xAC4) = 0x47;
            do_act = 0;
            show_title = 0;
            MsSetMotionReturn(id);
            break;
        case 0x3021:
        case 0x3023:
        case 0x3054:
            cp[0xAC0] = 0x35;
            *(u16 *)(cp + 0xAC4) = 0x77;
            do_act = 0;
            show_title = 0;
            MsSetMotionReturn(id);
            break;
        case 0x3022:
            cp[0xAC0] = 0x3E;
            *(u16 *)(cp + 0xAC4) = 0x7D;
            do_act = 0;
            show_title = 0;
            MsSetMotionReturn(id);
            break;
        case 0x3004:
            cp[0xAC0] = 0x2E;
            *(u16 *)(cp + 0xAC4) = 0x82;
            cp[0xAC1] = 0x2F;
            do_act = 0;
            show_title = 0;
            func_001E0A18(c, 0, ent->f8[idx].h2);
            break;
        case 0x3005:
            cp[0xAC0] = 0x2E;
            *(u16 *)(cp + 0xAC4) = 0x82;
            cp[0xAC1] = 0x2F;
            do_act = 0;
            show_title = 0;
            func_001E0A18(c, 1, ent->f8[idx].h2);
            break;
        case 0x3003:
            if (MsCalcEscape(id, c) != 0) {
                MsLimitTypeEscapeCheck(id, c);
                mot = 0x11;
                cp[0xDC] = 0;
                req_mcam = 1;
                mcam_a3 = 0x35;
                *(float *)(cp + 0x15C) = MsGetEscapeDir(id);
                *(u16 *)(cp + 0x2C6) &= ~8;
                cp[0xAAA] = 4;
            } else {
                mot = 0x37;
                req_mcam = 1;
                mcam_a3 = 0x35;
            }
            break;
        case 0x3018:
            req_mcam = 1;
            _pgs_D_003172F0.f2125 = 1;
            do_act = 0;
            cp[0xAAA] = 5;
            mcam_a3 = 0x35;
            *(u16 *)(cp + 0x2C6) &= ~8;
            MsEscapeAll();
            MsSetVoiceCheck(id, 0xF, 1, 0, 0);
            break;
        case 0x3002:
            {
                int t;
                flag44 = 0;
                t = ent->f8[idx].h2;
                do_act = 0;
                req_mcam = 1;
                _pgs_D_003172F0.f2125 = 1;
                cp[0xAAA] = 6;
                MsExchangeChr(id, t, 0, 0);
                mcam_a3 = 0x36;
                MsSetVoiceCheck(t, 0xB, 1, 0, 0);
            }
            break;
        case 0x30FF:
            do_act = 0;
            _pgs_D_003172F0.f1753 = 0;
            MsExchangeSummon(id, 0xF);
            use_mp = 0;
            req_mcam = 1;
            msSetEndDir(c);
            break;
        case 0x3117:
        case 0x3118:
            cmd_u16 = ent->f8[idx].h2;
            do_act = 0;
            _pgs_D_003172F0.f1753 = 0;
            use_mp = 0;
            MsExchangeSummon(id, cmd_u16);
            req_mcam = 1;
            msSetEndDir(c);
            break;
        case 0x3056:
        case 0x3057:
            do_act = 0;
            req_mcam = 1;
            MsInsertChrCommand(MsCheckMegas(id), id, 1);
            break;
        case 0x3129:
            func_001D1458(0xF, id, 0x30EA);
            break;
        }
        break;
    }

    cp[0xD3] = flag48;
    cp[0x106] = f106;
    if (f106 == 2 && (*(s8 *)(cp + 0x15) == 0 || *(s8 *)(cp + 0xA8E) != 0)) {
        cp[0xAC0] = 0xFF;
        cp[0xAC1] = 0xFF;
    }
    if (do_act != 0) {
        MsActionRequest(id, 0xFF, 7, 0, 2, 0);
        MsPopBtlPos(c);
    }
    if (use_mp != 0) {
        MsUseChrMpLimit(id);
    }
    if (show_title != 0) {
        _m_MsMenuOpenTitleWindow(cmd_id, 0x3C);
    }
    cp[0xBA] = fBA;
    if (mot >= 0) {
        cp[0xC8] = 0;
        MsResetChrPos(id, c);
        MsSetMotion(id, mot, 1, 1, 1, 0, 0);
    }
    cp[0xBA] = 0;
    MsAtelRequestCamera(0, id, 0x3D, 0xFFFF, 0, 1, 0, 0);
    if (req_mcam != 0) {
        MsAtelRequestMagicCamera(0, id, *(u16 *)(cp + 0xC1C), mcam_a3, mcam_t0, 0, 1, 0, 0);
    }
    if (flag44 != 0 && id < 8) {
        _pbg_btlgetdata.b24[id] = 1;
    }
    return *(s8 *)(cp + 0xAB2);
}

int func_001D0D48(u16 *p) {
    int r = 0;
    int i;
    u16 *q;
    if (p != 0) {
        for (i = 0; i < 2; i++) {
            q = p + i;
            if (*q == 0x3029) {
                r = 1;
                break;
            }
        }
    }
    return r;
}

void func_001D0D98(int a, BtlChr *c) {
    if (c->f10B != 0) {
        c->f10A = c->f10B;
    } else {
        c->f10A = func_001D1DF8(a, c, c->fA80);
    }
}

int MsCheckMegas(int x) {
    if (x == 16 || x == 17) {
        x = 15;
    }
    return x;
}

typedef struct {
    u8 pad00[4];
    s32 f04;
    s32 f08;
    u8 pad0C[4];
    s8 f10;
    u8 pad11[9];
    s8 f1A;
    u8 pad1B[3];
    s8 f1E;
    u8 pad1F[0x1E];
    s8 f3D;
    u8 pad3E[0x7A];
    u8 fB8;
    u8 padB9[0x23];
    s8 fDC;
    u8 padDD[0x19];
    s8 fF6;
    u8 padF7[6];
    s8 fFD;
    u8 padFE[0xBE];
    u8 f1BC;
    u8 f1BD;
    u8 f1BE;
    u8 f1BF;
    u8 f1C0;
    u8 f1C1;
    u8 f1C2;
    u8 pad1C3[6];
    u8 f1C9;
    u8 f1CA;
    u8 f1CB;
    u8 pad1CC[5];
    s8 f1D1;
    u8 pad1D2[2];
    float f1D4[2];
    u8 pad1DC[0x140];
    s8 f31C;
    u8 pad31D[0xB9];
    s8 f3D6;
    u8 pad3D7[0x6B1];
    s8 fA88;
    u8 padA89[2];
    s8 fA8B;
    u8 padA8C[1];
    s8 fA8D;
    u8 padA8E[0x2A];
    s8 fAB8;
} ExChr; /* DEBT(NAME): BtlChr offset view for MsExchangeChr */

typedef struct {
    u8 pad00[0x1FC5];
    u8 f1FC5[7];
    u8 pad1FCC[7];
    u8 f1FD3[17];
    u8 pad1FE4[0x134];
    s8 f2118;
    s8 f2119;
} ExGS; /* DEBT(NAME): GameState offset view for MsExchangeChr */

extern void MsProvOff(int);
extern void MsThreatOff(int, void *);
extern int MsCleanInputCue(int, int);
extern void func_001B7498(int, int);
extern void MsEffectWeaponFree(int);
extern void MsStatusEffectCheck(int);
extern void MsBtlReadCueRegist(int, int, int, int, int);
extern void func_001B1490(int, int);
extern void MsInsertInputCue(int, int, int, int, int, int);

#define EX_GS ((ExGS *)&D_003172F0) /* DEBT(CAST): GameState offset view */

int MsExchangeChr(int a, int b, int mode, int arg3)
{
    ExChr *ca = (ExChr *)MsGetChr(a); /* DEBT(CAST): offset view */
    ExChr *cb = (ExChr *)MsGetChr(b); /* DEBT(CAST): offset view */
    int i;

    if (a != 0xFF && ca->f10 != 0) {
        ca->f1C0 = ca->f1C9;
        ca->f1C1 = ca->f1CA;
        ca->f1C2 = ca->f1CB;
        if (ca->fA8D == 0) {
            ca->fA88 = 0;
            ca->fAB8 = 1;
            ca->fDC = 0;
            MsProvOff(a);
            MsThreatOff(a, ca);
            MsCleanInputCue(a, 1);
            if (mode > 0) {
                ca->fA8B = 1;
                ca->f1A = 1;
                func_001B7498(a, -1);
                EX_GS->f2118 = b;
                EX_GS->f2119 = a;
                ca->f1BC = cb->f1BC;
                ca->f1BD = 12;
                ca->f1BE = b;
                MsSetDirThetaMode(ca);
                if (b != 0xFF) {
                    ca->f1D4[1] = cb->f1D4[cb->f1D1];
                }
                MsSetMotion(a, 3, 1, 1, 1, 0, 0);
            } else {
                ca->fF6 = 0;
                ca->f1BD += 3;
                MsSetMotion(a, 0x12, 1, 1, 1, 0, 0);
            }
            MsPushBtlPos(ca);
        }
        MsEffectWeaponFree(a);
        MsSEPchrClear(ca, 1);
        for (i = 0; i < 7; i++) {
            if (EX_GS->f1FC5[i] == a) {
                EX_GS->f1FC5[i] = b;
                break;
            }
        }
        for (i = 0; i < 17; i++) {
            if (EX_GS->f1FD3[i] == b) {
                EX_GS->f1FD3[i] = a;
                break;
            }
        }
    } else {
        ca = 0;
    }

    if (b != 0xFF && cb->f10 != 0) {
        s32 f04 = cb->f04;
        s32 f08 = cb->f08;
        int cue_type;
        if (cb->fA8D != 0) {
            cue_type = 10;
            MsPushBtlPos(cb);
        } else {
            if (mode <= 0 && ca != 0) {
                cb->f1BC = ca->f1C0;
                cb->f1BD = ca->f1C1;
                cb->f1BE = ca->f1C2;
                cb->f1BF = ca->f1BF;
                cb->f1D4[0] = ca->f1D4[0];
                cb->f1D4[1] = ca->f1D4[1];
                cb->fB8 = ca->fB8;
                cb->f31C = 0;
            }
            MsPushBtlPos(cb);
            cb->fAB8 = 0;
            cb->fA88 = 1;
            if (mode > 0) {
                MsSummonLimitSave(cb);
                cue_type = 8;
                cb->f1E = 0;
                cb->fFD = 4;
            } else {
                ((u8 *)&btlgetdata)[b] = 1; /* DEBT(CAST): byte array at btlgetdata */
                if (mode < 0) {
                    cb->fA8B = 0;
                    cb->f1A = 0;
                    cue_type = 0;
                    msSetChrBodyHit(cb, 3, 1);
                    MsSetDirThetaMode(cb);
                    MsStatusEffectCheck(b);
                } else {
                    cb->f3D = 1;
                    cue_type = 6;
                }
            }
        }
        MsBtlReadCueRegist(3, b, b, 0, 0);
        MsBtlReadCueRegist(0, b, b, f04, 0);
        MsBtlReadCueRegist(2, b, b, f08, cue_type);
        func_001B1490(b, 3);
        if (a != 0xFF && mode >= 0) {
            cb->f3D6 = 1;
            MsInsertInputCue(b, 0, 1, 0, a, arg3);
        }
    }
    return b;
}

void MsExchangeSummon(int a, int b) {
    int j;
    int i;

    D_00319407 = 1;
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        c->padA89[0] = c->fA88;
    }
    for (i = 0; i < 17; i++) {
        D_003172F0.pad1FCC[i + 24] = D_003172F0.pad1FCC[i + 7];
    }
    for (i = 0; i < 7; i++) {
        u8 id = D_003172F0.f1FC5[i];
        D_003172F0.f1FC5[i + 7] = id;
        if (id != a && id != 0xFF) {
            MsExchangeChr(id, 0xFF, 0, 0);
        }
    }
    MsGetChr(b)->f391 = a;
    if ((u32)(b - 15) < 3) {
        MsExchangeChr(a, b, 1, 0);
        i = 0;
        for (j = 15; j < 18; j++, i++) {
            D_003192B5[i] = j;
            if (j != b) {
                MsGetChr(j)->f391 = a;
                MsExchangeChr(0xFF, j, 1, 0);
            }
        }
    } else {
        MsExchangeChr(a, b, 1, 0);
    }
    MsChangeMonsterDir();
    MsInsertChrCommand(b, a, 0);
}

void MsEscapeAll(void) {
    int i;
    for (i = 0; i < 7; i++) {
        u8 id = D_003192B5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            c->fDC = 0;
            if (c->fA88 != 0 && c->fA8C == 0 && c->fA8E == 0) {
                MsLimitTypeEscapeCheck(id, c);
                c->f1BC.b += 3;
                MsSetMotion(id, 0x12, 1, 1, 1, 0, 0);
                MsPushBtlPos(c);
            }
        }
    }
}

s32 func_001D1458(int id, int a, int h) {
    GsEnt48 e;
    MsGetChr(id)->fAB2 = 0;
    MsStructClear(&e, 0x48);
    e.f3 = 1;
    e.f8[0].h0 = h;
    e.f8[0].targets = D_003172F0.f2000;
    e.f2 = 0;
    e.f8[0].h2 = 0;
    MsInsertInputCue(id, 0, 0, 0, a, 1);
    MsInsertCommandCue(id, &e, 8, 0, 0, 0, a);
    return D_003172F0.f2000;
}

int func_001D1510(int id, int cmd, int mode, int *out_a, int *out_b) {
    CmdUseEnt16 *p = &D_0031FA50[id];
    int val_a;
    int val_b;
    int ret = 0;
    val_a = 0;
    val_b = 0;

    switch (mode) {
    case 0:
        if (((D_0031D1DC >> 11) & 1) || MsGetSaveCommandUse(id, cmd) == 0) {
            ret = p->h0;
            val_b = p->b2;
        } else {
            ret = p->h4;
            val_b = p->b6;
        }
        val_a = 1;
        break;
    case 1:
        ret = p->h8;
        val_b = p->bA;
        val_a = 3;
        break;
    case 2:
        ret = p->hC;
        val_b = p->bE;
        val_a = 2;
        break;
    }
    if (out_a != 0) {
        *out_a = val_a;
    }
    if (out_b != 0) {
        *out_b = val_b;
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", MsInsertChrCommand);

/* DEBT(ORDER): independent reset fields are ordered to retain the original schedule. */
void MsReturnSummon(s32 reset)
{
    BtlChr *chr;
    s32 index;
    u8 id;

    if (D_003172F0.f2118 != 0)
    {
            for (index = 0; index < 7; index++)
        {
            id = D_003172F0.f1FC5[index];
            if (id != 0xFF)
            {
                chr = MsGetChr((s32) id);
                MsSummonLimitLoad(chr);
                if ((reset != 0) && (chr->f290 <= 0))
                {
                    MsRelife((s32) id, chr, 0);
                }
                MsFreePlayer(id);
            }
                }
        MsReturnParty();
        MsExchangePlayer(D_003172F0.f2118);
        MsChangeMonsterDir();
        D_003172F0.f2125 = 1;
        D_003172F0.f2118 = 0;
        D_003172F0.f2119 = -1;
    }
}

void MsReturnParty(void) {
    int i;
    if (D_003172F0.f2117 != 0) {
        D_003172F0.f2117 = 0;
        for (i = 0; i < 7; i++) {
            u8 id = D_003172F0.f1FC5[i + 7];
            D_003172F0.f1FC5[i] = id;
            if (id != 0xFF) {
                MsGetChr(id);
            }
        }
        for (i = 0; i < 17; i++) {
            D_003172F0.pad1FCC[i + 7] = D_003172F0.pad1FCC[i + 24];
        }
    }
}

void MsExchangeParty(void) {
    int i;

    for (i = 0; i < 7; i++) {
        u8 t = D_003172F0.pad1FA6[i + 0x26];
        D_003172F0.pad1FA6[i + 0x26] = D_003172F0.pad1FA6[i + 0x1F];
        D_003172F0.pad1FA6[i + 0x1F] = t;
    }
    for (i = 0; i < 17; i++) {
        u8 t = D_003172F0.pad1FCC[i + 24];
        D_003172F0.pad1FCC[i + 24] = D_003172F0.pad1FCC[i + 7];
        D_003172F0.pad1FCC[i + 7] = t;
    }
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        s8 t = ((s8 *)c)[0xA89];
        ((s8 *)c)[0xA89] = c->fA88;
        c->fA88 = t;
    }
}

void func_001D1A30(void) {
    int i;
    for (i = 0; i < 7; i++) {
        int id = D_003192BC[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            if (c->fA8D == 0) {
                c->fA88 = 1;
            }
        }
    }
}

void MsFreePlayer(int id) {
    BtlChr *c = MsGetChr(id);
    c->fA88 = 0;
    MsCleanInputCue(id, 0);
    if (D_003172F0.f2114 == id) {
        D_003172F0.f2114 = -1;
    }
    if (c->chr != 0) {
        MsBtlChrFree(id, 7);
    }
}

void MsExchangePlayer(void) {
    int i;
    for (i = 0; i < 7; i++) {
        u8 id = D_003172F0.f1FC5[i];
        if (id != 0xFF) {
            BtlChr *c = MsGetChr(id);
            int k = id == D_003172F0.f2119 ? -1 : 0;
            c->f1BC.a = c->f1C0.a;
            c->f1BC.b = c->f1C0.b;
            c->f1BC.c = c->f1C0.c;
            MsExchangeChr(0xFF, id, k, 0);
        }
    }
}

int func_001D1BF0(int a, Sub1C *p) {
    int r = 1;
    if (a == 1 || a == 5) {
        u32 f = p->f1C;
        if ((f >> 20) & 1) {
            r = 0;
        } else if ((f >> 21) & 1) {
            r = 2;
        }
    }
    return r;
}

void MsSortCommand(u16 *p) {
    u16 *s = (u16 *)btl_ply_win; /* DEBT(TYPE): btl_ply_win is declared s32 */
    func_001D1CE0(p, s + 0x2838, 0x14);
    func_001D1CE0(p + 0x14, s + 0x284C, 8);
    func_001D1CE0(p + 0x1C, s + 0x2854, 8);
    func_001D1CE0(p + 0x24, s + 0x285C, 0x18);
    func_001D1CE0(p + 0x3C, s + 0x2874, 0x18);
    func_001D1CE0(p + 0x54, s + 0x288C, 0x20);
    func_001D1CE0(p + 0x74, s + 0x28AC, 0x20);
    func_001D1CE0(p + 0x94, s + 0x28CC, 0x18);
}

void func_001D1CE0(u16 *src, u16 *dst, int n) {
    int i;
    int k;
    int v;
    u16 t;

    for (i = 0; i < n; i++) {
        k = src[i];
        t = k; /* DEBT(FAKE): u16 copy only steers register allocation of the sort loop */
        v = 0x100;
        if (t != 0xFF && (k >> 12) == 3) {
            v = MsGetRomPlyCommand(k, 0)->b5C;
        }
        dst[i] = v;
    }
    do {
        v = 0;
        for (i = 0; i < n - 1; i++) {
            if (dst[i + 1] < dst[i]) {
                t = dst[i + 1];
                dst[i + 1] = dst[i];
                dst[i] = t;
                t = src[i + 1];
                src[i + 1] = src[i];
                src[i] = t;
                v = 1;
            }
        }
    } while (v);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D00D8", func_001D1DF8);

void MsComBufInit(void) {
    D_00662628 = 0;
}

int func_001D1FA8(int x, int y, int z) {
    int r = 0;
    int n = D_00662628;
    if (n < 8) {
        Q4Ev *e = &D_00662630[n];
        r = 1;
        D_00662628 = n + 1;
        e->key = x;
        e->v[0] = y;
        e->v[1] = z;
    }
    return r;
}

typedef struct {
    u8 pad0[0x10];
    u16 h10[2];
    u8 pad14[0x19 - 0x14];
    u8 b19;
    u8 pad1A[0x58 - 0x1A];
    u8 b58;
} MagicEffData;

int MsGetMagicEffNum(int id, int cmd, MagicEffData *p) {
    int idx;
    int res;

    if ((u32)(p->b19 - 8) < 10) {
        if (((D_0031D1DC >> 11) & 1) || MsGetSaveCommandUse(id, cmd) == 0) {
            idx = 0;
        } else {
            idx = 1;
        }
    } else {
        idx = D_003193EE;
    }
    res = p->h10[idx];
    if (p->b58 == 0x24 || p->b58 == 0x34 || p->b58 == 0x44 || p->b58 == 0x54) {
        int sp0[2];
        switch (FFXGetLang()) {
        case 2:
            sp0[0] = 0x2B3;
            sp0[1] = 0x2B4;
            break;
        case 0:
        case 3:
            sp0[0] = 0x2B9;
            sp0[1] = 0x2BA;
            break;
        case 4:
            sp0[0] = 0x2B7;
            sp0[1] = 0x2B8;
            break;
        case 5:
            sp0[0] = 0x2B5;
            sp0[1] = 0x2B6;
            break;
        default:
            sp0[0] = p->h10[0];
            sp0[1] = p->h10[1];
            break;
        }
        res = sp0[idx];
    } else {
        int i;
        Q4Ev *e = D_00662630;
        for (i = 0; i < D_00662628; i++, e++) {
            if (cmd == e->key) {
                res = e->v[idx];
            }
        }
    }
    return res;
}
