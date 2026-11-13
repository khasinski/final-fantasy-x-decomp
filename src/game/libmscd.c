/* tu_108 0x162618-0x165eb8: high; libmscd (config/tu_map.tsv) */
#define func_00163FF0 _hdr_func_00163FF0
#define func_001631F0 _hdr_func_001631F0
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/g1.h"
#include "ffx/b0.h"
#include "ffx/u1.h"
#define D_0030DE34 v1_D_0030DE34 /* DEBT(TYPE): v1.h guesses another type for this datum */
#include "ffx/v1.h"
#undef func_00163FF0
#undef func_001631F0
#undef D_0030DE34

int func_00162618(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E90();
        case 3:
            return func_00171D28();
        case 4:
            return func_00171D70();
        case 5:
            return func_00171ED8();
        case 6:
            return func_00171E00();
        case 0:
        default:
            return func_00171DB8();
        case 1:
            return func_00171E48();
        }
    }
    return func_00171E48();
}

int func_001626D8(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E50();
        case 3:
            return func_00171CE8();
        case 4:
            return func_00171D30();
        case 5:
            return func_00171E98();
        case 6:
            return func_00171DC0();
        case 0:
        default:
            return func_00171D78();
        case 1:
            return func_00171E08();
        }
    }
    return func_00171E08();
}

int func_00162798(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E58();
        case 3:
            return func_00171CF0();
        case 4:
            return func_00171D38();
        case 5:
            return func_00171EA0();
        case 6:
            return func_00171DC8();
        case 0:
        default:
            return func_00171D80();
        case 1:
            return func_00171E10();
        }
    }
    return func_00171E10();
}

int dvd_cd_fat_sector(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E60();
        case 3:
            return func_00171CF8();
        case 4:
            return func_00171D40();
        case 5:
            return func_00171EA8();
        case 6:
            return func_00171DD0();
        case 0:
        default:
            return func_00171D88();
        case 1:
            return func_00171E18();
        }
    }
    return func_00171E18();
}

int dvd_cd_fid_sector(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E68();
        case 3:
            return func_00171D00();
        case 4:
            return func_00171D48();
        case 5:
            return func_00171EB0();
        case 6:
            return func_00171DD8();
        case 0:
        default:
            return func_00171D90();
        case 1:
            return func_00171E20();
        }
    }
    return func_00171E20();
}

int dvd_cd_fat_size(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E70();
        case 3:
            return func_00171D08();
        case 4:
            return func_00171D50();
        case 5:
            return func_00171EB8();
        case 6:
            return func_00171DE0();
        case 0:
        default:
            return func_00171D98();
        case 1:
            return func_00171E28();
        }
    }
    return func_00171E28();
}

int dvd_cd_id_size(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E78();
        case 3:
            return func_00171D10();
        case 4:
            return func_00171D58();
        case 5:
            return func_00171EC0();
        case 6:
            return func_00171DE8();
        case 0:
        default:
            return func_00171DA0();
        case 1:
            return func_00171E30();
        }
    }
    return func_00171E30();
}

int func_00162B58(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E80();
        case 3:
            return func_00171D18();
        case 4:
            return func_00171D60();
        case 5:
            return func_00171EC8();
        case 6:
            return func_00171DF0();
        case 0:
        default:
            return func_00171DA8();
        case 1:
            return func_00171E38();
        }
    }
    return func_00171E38();
}

int func_00162C18(void) {
    if (func_001BD360() == 0) {
        switch (FFXGetLang()) {
        case 2:
            return func_00171E88();
        case 3:
            return func_00171D20();
        case 4:
            return func_00171D68();
        case 5:
            return func_00171ED0();
        case 6:
            return func_00171DF8();
        case 0:
        default:
            return func_00171DB0();
        case 1:
            return func_00171E40();
        }
    }
    return func_00171E40();
}

void func_00162CD8(u8 v) {
    D_0030DE25 = v;
}

void func_00162CE8(void) {
    Rec595F6C **p = &D_00595F6C; /* DEBT(FAKE): local pointer so gcc keeps %hi(D_00595F6C) in s0 across the call */

    D_0030DE30 = 0;
    *p = user_malloc(0x6800, 10, (char *)D_0056BB20, 0x203); /* DEBT(CAST): D_0056BB20 is u8[] in q3.h */
    func_002EF0D0(*p, 0, 0x6800);
}

void func_00162D38(void) {
    func_001577A8(D_0056BB30, D_0056BB20, 0x20C);
}

void func_00162D50(void) {
    func_001577A8(D_0056BB50, D_0056BB20, 0x211);
}

int func_00162D68(void) {
    return D_00595F50;
}

void func_00162D78(void) {
    switch ((s8)D_0030DE34) {
    case 1:
        cd_decode_data(D_0057CB80.w00);
        break;
    case 3:
        hd_file_read_th_main();
        break;
    default:
        return;
    }
    D_0030DE34 = 0;
}

void func_00162DE0(void) {
    TkRegistBGThreadFunc(func_00162D78);
}

SysVt *GetCD(void) {
    return (SysVt *)&D_0078E498; /* DEBT(CAST): same address, two views of it */
}

void func_00162E00(int i)
{
    if (D_0078E4B0 == 0) {
        D_0078F330[i][0] = 0;
    }
    D_0078E530[i].w08 = 0;
    D_0078E530[i].w04 = 0;
    D_0078E530[i].w00 = 0;
    D_0078E530[i].b30 = 0;
    D_0078E530[i].used = 0;
    D_0078E530[i].id = 0;
    D_0078E530[i].flag = 0;
    D_0078E530[i].b33 = 0;
}


void func_00162E68(void)
{
    int i;

    for (i = 0; i < 0x40; i++) {
        func_00162E00(i);
    }
    D_0030DDFC = 0;
    D_00595F54 = 0;
    D_00595F58 = 0;
    D_0030DE00 = 0;
    D_0030DE04 = 0;
    D_00595F5C = 0;
    D_0030DDF8 = 0;
    func_0015B350();
}

extern u8 *_mscd_D_00595F68 __asm__("D_00595F68");
int func_00165D90(int type, int id);

int func_00162ED8(int i)
{
    int idx = G1_VT78E498->w20 + i;
    int off = idx * 3;
    int ret = func_00165D90(G1_VT78E498->w24, i);
    u32 *p;

    if (ret != 0) {
        return ret;
    }
    p = (u32 *)(idx * 4 + D_0078E498.f28);
    if (!(*p & 0x800000)) {
        if (*p & 0x400000) {
            u8 *b = _mscd_D_00595F68 + off;
            ret = b[0];
            ret += b[1] << 8;
            ret += b[2] << 16;
            ret <<= 3;
        } else {
            ret = (((p[1] & 0x3FFFFF) - (*p & 0x3FFFFF)) << 11) - ((*p >> 24) << 3);
        }
    }
    return ret;
}

int func_00162FC0(int a, int b)
{
    int idx = G1_VT78E498->p2C[a] + b;
    int off = idx * 3;
    int ret = func_00165D90(a, b);
    u32 *p;

    if (ret != 0) {
        return ret;
    }
    p = (u32 *)(idx * 4 + D_0078E498.f28);
    if (!(*p & 0x800000)) {
        if (*p & 0x400000) {
            u8 *b = _mscd_D_00595F68 + off;
            ret = b[0];
            ret += b[1] << 8;
            ret += b[2] << 16;
            ret <<= 3;
        } else {
            ret = (((p[1] & 0x3FFFFF) - (*p & 0x3FFFFF)) << 11) - ((*p >> 24) << 3);
        }
    }
    return ret;
}

int func_001630B0(int i)
{
    int ret = 0;
    u32 *p = (u32 *)((G1_VT78E498->w20 + i) * 4 + D_0078E498.f28);

    if (!(*p & 0x800000)) {
        ret = (((p[1] & 0x3FFFFF) - (*p & 0x3FFFFF)) << 11) - ((*p >> 24) << 3);
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163110);


int func_00163158(u8 *p) {
    return (D_0078E4C0[(int)p] & 0x3FFFFF) + D_0030DE2C; /* DEBT(TYPE): header declares a pointer, asm indexes with it */
}

int func_00163188(int i, int off) {
    return func_00163158((u8 *)(D_0078E4C4[i] + off)); /* DEBT(TYPE): see func_00163158 */
}

int func_001631B8(int a) {
    return func_00163158(D_0078E4B8 + a);
}

void func_001631E0(u8 v) {
    D_0030DE24 = v;
}

typedef struct {
    u8 a[4];
} Mode1631F0;

extern Mode1631F0 D_00595F60;
extern s32 D_0030DE28;
int func_002E19C0(int a, int b, int c, void *d);

int func_001631F0(int a0, int a1, int a2, void *a3)
{
    int s0;

    D_0030DE24 = 0;
    D_0030DE28 = 0;
    D_00595F54 = a0;
    D_00595F58 = a1;
    D_00595F5C = a2;
    D_00595F60 = *(Mode1631F0 *)a3;
    func_0015B350();
    s0 = a1 / 2048;
    func_002F8660(0);
    return func_002E19C0(a0, s0, a2, a3);
}

int func_001632B0(void) {
    if (D_0030DE24 != 0) {
        return func_0020D540();
    }
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_001632D8);

INCLUDE_ASM("build/ee_asm/game/libmscd", Sa_CdRead_task);

int func_00163710(void)
{
    int s = func_0015B850();

    if (s == 0) {
        return 0;
    }
    if (s == -1) {
        return 1;
    }
    if (func_002E1700(1) != 2) {
        return -1;
    }
    func_002E1FB8();
    func_001631F0(D_00595F54, D_00595F58, D_00595F5C, D_0030DE20);
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/libmscd", cd_decode_data);

void func_00163958(Q3Obj20 *o) {
    func_00171530(D_00591F50, 0x4000, o->fn, o);
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163970);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163D40);

typedef struct Vt78E498View {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    s32 w18;
    void *f1C;
    u8 pad20[0x54 - 0x20];
    void *f54;
    void *f58;
    s32 w5C;
    void *f60;
    void *f64;
    void *f68;
    void *f6C;
    s32 w70;
    s32 w74;
    void *f78;
    void *f7C;
    void *f80;
    void *f84;
    void *f88;
    void *f8C;
    void *f90;
} Vt78E498View;

void func_00163970(SysVt *cd, G1Rec78E530 *rec, int idx);
void func_00163D40(SysVt *cd, G1Rec78E530 *rec, int idx);

void func_00163EB0(void)
{
    SysVt *cd = GetCD();
    int i;

    for (;;) {
        for (i = 0; i < 0x40; i++) {
            G1Rec78E530 *rec = &D_0078E530[i];

            if (rec->used != 0) {
                switch (rec->b30) {
                case 0:
                    if (rec->flag != 0) {
                        while (func_002E1FB8() == 0) {
                            func_0017135C(1);
                        }
                        rec->flag = 0;
                        func_00162E00(((Vt78E498View *)cd)->w74);
                        {
                            int j;
                            for (j = 0; j < 0x40; j++) {
                                if (D_0078E530[j].used != 0) {
                                    break;
                                }
                            }
                            if (j == 0x40) {
                                ((Vt78E498View *)cd)->w70 = 0;
                                cd->fd5C = -1;
                                func_0015B350();
                            }
                            ((Vt78E498View *)cd)->w74 = -1;
                        }
                    } else {
                        func_00163970(cd, rec, i);
                    }
                    break;
                case 1:
                    func_00163D40(cd, rec, i);
                    break;
                }
            }
        }
        func_0017135C(1);
    }
}

s32 _m2c_func_00163FF0_func_001577A8(s32 *, u8 *, s32) __asm__("func_001577A8");
extern s8 _m2c_func_00163FF0_D_0030DDFD __asm__("D_0030DDFD");
extern s32 _m2c_func_00163FF0_D_0056BB78 __asm__("D_0056BB78");
/* DEBT(CAST) */
s16 func_00163FF0(s32 arg0) {
    s16 var_2;

    if (_m2c_func_00163FF0_D_0030DDFD == 0) {
        _m2c_func_00163FF0_func_001577A8(&_m2c_func_00163FF0_D_0056BB78, D_0056BB20, 0x534);
    }
    var_2 = *(s32 *)((arg0 * 2) + D_0078E498.f2C);
    (*(s32 *)((u8 *)(&D_0078E498) + (0x24))) = arg0;
    (*(s32 *)((u8 *)(&D_0078E498) + (0x20))) = (s32) var_2;
    if (var_2 < 0) {
        (*(s32 *)((u8 *)(&D_0078E498) + (0x20))) = 0;
        var_2 = -1;
    }
    return var_2;
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164060);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164340);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164648);

extern char D_0056BC00[];
extern char D_0056BC18[];
int TkSndIsStandbyVoice(void);

static __inline__ int check_4840(void)
{
    int i;

    for (i = 0; i < 0x40; i++) {
        if (D_0078E530[i].used != 0) {
            if (TkSndIsStandbyVoice() != 0) {
                func_001577A8(D_0056BC18, (char *)D_0056BB20, 0x642);
            }
            break;
        }
    }
    return i;
}

void func_00164840(void)
{
    if (D_00595F64 == 0) {
        func_001577A8(D_0056BC00, (char *)D_0056BB20, 0x63B);
    }
    while (check_4840() != 0x40) {
        (*D_00595F64)();
        func_002D3FF0(0);
    }
}

int func_00164918(int a, int b)
{
    int i;

    for (i = 0; i < 0x40; i++) {
        if (D_0078E530[i].used != 0 && *(s32 *)&D_0078E530[i].pad28[0] == a && D_0078E530[i].w08 == b) {
            if (((Vt78E498View *)&D_0078E498)->w70 != 0 && ((Vt78E498View *)&D_0078E498)->w74 == i) {
                return 2;
            }
            return 1;
        }
    }
    return 0;
}

extern char D_0056BC18[];
int TkSndIsStandbyVoice(void);
void func_00164840(void);

int func_00164990(int mode)
{
    int i;

    switch (mode) {
    case 0:
    default:
        func_00164840();
        return 0;
    case 1:
        for (i = 0; i < 0x40; i++) {
            if (D_0078E530[i].used != 0) {
                if (TkSndIsStandbyVoice() != 0) {
                    func_001577A8(D_0056BC18, (char *)D_0056BB20, 0x67E);
                }
                return 1;
            }
        }
        return 0;
    }
}

void *func_00164A30(void) {
    return D_0030DE38;
}

void func_00164A40(void)
{
    for (;;) {
        D_0078E498.f68();
        func_0017135C(1);
    }
}

void func_00164A70(u8 v) {
    D_0030DE41 = v;
}

void func_00164A80(int v) {
    D_0030DE44 = v;
}

INCLUDE_ASM("build/ee_asm/game/libmscd", CdEnvInit);

void func_00165320(int id)
{
    int i;

    if (id <= 0) {
        for (i = 0; i < 64; i++) {
            if (D_0078E530[i].used) {
                D_0078E530[i].flag = 1;
            }
        }
    } else {
        for (i = 0; i < 64; i++) {
            if (D_0078E530[i].used && D_0078E530[i].id == id) {
                D_0078E530[i].flag = 1;
            }
        }
    }
}

void func_00165398(int v)
{
    switch (v) {
    case 0:
    default:
        D_0030DE19 = 1;
        break;
    case 1:
        D_0030DE19 = 0;
        break;
    }
}

void func_001653C0(int v)
{
    switch (v) {
    case 0:
    default:
        ((u8 *)func_0015B340())[1] = 1; /* DEBT(CAST): record type of D_0030DCE0 unknown */
        break;
    case 1:
        ((u8 *)func_0015B340())[1] = 0; /* DEBT(CAST): record type of D_0030DCE0 unknown */
        break;
    }
}

extern s32 _m2c_func_00165408_D_0056BB90 __asm__("D_0056BB90");
/* DEBT(CAST) */ /* DEBT(GOTO) */
s32 func_00165408(s32 a, s32 b, s32 c) {
    G1Rec78E530 *temp_5;
    s32 temp_2;
    s32 var_16;

    var_16 = 0;
    if (D_0078E530->used != 0) {
loop_2:
        var_16 += 1;
        if (var_16 < 0x40) {
            if (D_0078E530[var_16].used == 0) {

            } else {
                goto loop_2;
            }
        }
    }
    if (var_16 == 0x40) {
        func_001577A8(&_m2c_func_00165408_D_0056BB90, D_0056BB20, 0x816);
    }
    temp_5 = &D_0078E530[var_16];
    temp_5->w08 = c;
    temp_5->used = 1;
    temp_5->w04 = 0;
    temp_2 = D_0030DDF8 + 1;
    (*(s32 *)((u8 *)(temp_5) + (0x28))) = b;
    (*(s32 *)((u8 *)(temp_5) + (0xC))) = 0;
    (*(s32 *)((u8 *)(temp_5) + (0x10))) = 0;
    (*(s32 *)((u8 *)(temp_5) + (0x14))) = 0;
    (*(s32 *)((u8 *)(temp_5) + (0x18))) = 0;
    temp_5->w00 = 0;
    (*(s32 *)((u8 *)(temp_5) + (0x20))) = 0;
    D_0030DDF8 = temp_2;
    if (temp_2 > 0xFFFF) {
        D_0030DDF8 = 1;
    }
    temp_5->id = D_0030DDF8;
    (*(s32 *)((u8 *)(temp_5) + (0x1C))) = a;
    temp_5->b33 = 0;
    temp_5->pad34[0] = 0;
    (*(s32 *)((u8 *)(temp_5) + (0x2C))) = 0;
    temp_5->b30 = 1;
    return D_0030DDF8;
}

int func_00165548(int a) {
    return func_00165408(a, 0, 0);
}

int func_00165568(int a, int b) {
    return func_00165408(func_00163188(a, b), a, b);
}

void PcReadFunc_set(void);
void func_00164060(void);
void func_00164340(void);

#define VT78E498 ((Vt78E498View *)&D_0078E498)

void func_001655A8(int a)
{
    VT78E498->w18 = a;
    if (a == 0) {
        PcReadFunc_set();
    } else {
        VT78E498->f14 = func_00162ED8;
        VT78E498->f58 = func_00164A30;
        VT78E498->f68 = func_00163EB0;
        VT78E498->f54 = func_00162D50;
        VT78E498->f60 = func_00162D38;
        VT78E498->f04 = func_001631B8;
        VT78E498->f78 = func_00164648;
        VT78E498->f88 = func_00165568;
        VT78E498->f8C = func_00165548;
    }
    VT78E498->f08 = func_00164990;
    VT78E498->f1C = func_00165320;
    D_0078E498.f00 = (int (*)())func_00164060;
    VT78E498->f90 = func_00164340;
    VT78E498->f64 = func_00162E68;
    VT78E498->f0C = func_001655A8;
    VT78E498->f10 = func_00163FF0;
    VT78E498->f7C = func_00165398;
    VT78E498->f84 = func_001653C0;
    VT78E498->f80 = func_00164918;
    VT78E498->f6C = func_00163188;
}

void func_001656D8(void) {
    (*D_00595F64)();
}

void func_00165700(void *buf, int size)
{
    int fd;

    if (D_0030DE4C == 0) {
        fd = func_002FC4E0(D_0056BD40, 0x602);
        if (fd < 0) {
            return;
        }
        func_002FC8E8(fd, 0, 0);
    } else {
        fd = func_002FC4E0(D_0056BD40, 0x402);
        if (fd < 0) {
            return;
        }
        func_002FC8E8(fd, 0, 2);
    }
    func_002FCD90(fd, buf, size);
    func_002FC768(fd);
}

void func_001657C8(char *s, u8 v)
{
    int i;

    D_0030DE4E = v;
    if (s == 0) {
        D_00597470[0] = 0;
        return;
    }
    D_00597470[0] = s[0];
    for (i = 0; s[i] != 0; ) {
        i++;
        D_00597470[i] = s[i];
    }
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00165828);

void func_00165A38(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    func_00165828(fmt, ap);
    va_end(ap);
}

void func_00165A70(int on)
{
    if (on != 0 && D_0030DE4F == 0) {
        func_002EF0D0(D_00596070, 0, sizeof(D_00596070));
        D_00597470[0] = 0;
        D_0030DE4E = 0;
        D_0030DE4F = 1;
        func_00171568((void (*)(void))func_00165A38); /* DEBT(CAST): prototype of func_00171568 takes void (*)(void) */
        func_002F8660(0);
        func_002F8660(2);
    }
    D_0030DE4D = on;
}

void func_00165B00(void) {
}

void func_00165B08(void) {
    func_00171568(func_00165B00);
    func_002F8660(0);
    func_002F8660(2);
}

INCLUDE_ASM("build/ee_asm/game/libmscd", printf_write);

Rec595F6C *func_00165D20(int type, int id)
{
    int i;
    Rec595F6C *e;

    if (D_0030DE30 == 0 || type == -1 || id == -1) {
        return 0;
    }
    e = D_00595F6C;
    for (i = 0; i < D_0030DE30; i++, e++) {
        if (e->type == type && e->id == id) {
            return e;
        }
    }
    return 0;
}

int func_00165D90(int type, int id)
{
    int i;
    Rec595F6C *e;

    if (D_0030DE30 == 0) {
        return 0;
    }
    e = D_00595F6C;
    for (i = 0; i < D_0030DE30; i++, e++) {
        if (e->type == type && e->id == id) {
            return e->value;
        }
    }
    return 0;
}

void func_00165DF0(int *src)
{
    int buf[12]; /* DEBT(PADDING): only the first two words are used */

    if (src != 0) {
        while (func_002E0C98(buf, src[0]) == 0) {
            func_002D3FF0(1);
        }
        D_0030DE2C = buf[0];
        while (func_002E0C98(buf, src[1]) == 0) {
            func_002D3FF0(1);
        }
        D_0030DE08[0] = buf[0];
        D_0030DE08[1] = buf[1];
        while (func_002E0C98(buf, src[2]) == 0) {
            func_002D3FF0(1);
        }
        D_0030DE08[2] = buf[0];
        D_0030DE08[3] = buf[1];
    }
}
