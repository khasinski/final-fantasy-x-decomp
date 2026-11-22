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

int func_00163110(int i)
{
    u32 *p = (u32 *)((G1_VT78E498->w20 + i) * 4 + D_0078E498.f28);
    register int ret __asm__("$2") = 0;

    if (!(*p & 0x800000)) {
        if (*p & 0x400000) {
            ret = 1;
        }
    }
    return ret;
}


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

extern s8 _mscd_D_0030DE24 __asm__("D_0030DE24.NON_MATCHING");
extern s8 _mscd_D_0030DE25 __asm__("D_0030DE25");
extern int _mscd_D_00595F50 __asm__("D_00595F50.NON_MATCHING");
extern s32 _mscd_D_0030DE18 __asm__("D_0030DE18.NON_MATCHING");
extern s32 dvd_hdd_copy_system_cnf_buff;
int func_002EEE88(const void *a, const void *b, int n);

int func_001632D8(void)
{
    int s;
    int r;

    if (func_002E1F00() == 1) {
    next_outer:
        for (;;) {
            if (func_002E1700(1) == 2) {
                if (func_002E1F00() != 1) {
                check_de25:
                    if (_mscd_D_0030DE25 == 0) {
                        return 0;
                    }
                    if (dvd_hdd_copy_system_cnf_buff == 0) {
                        return 1;
                    }
                    func_0017135C(1);
                    func_0015B350();
                    s = func_00163188(1, 1);
                    func_002F8660(0);
                    if (func_002E19C0(s, 1, _mscd_D_00595F50, &_mscd_D_0030DE18) == 0) {
                        goto next_outer;
                    }
                    while ((r = func_0015B850()) != 0) {
                        if (r != -1) {
                            goto next_outer;
                        }
                        func_0017135C(1);
                    }
                    func_002F8660(0);
                    ((char *)_mscd_D_00595F50)[0x20] = 0;
                    if (func_002EEE88((void *)_mscd_D_00595F50, (void *)dvd_hdd_copy_system_cnf_buff, 0x20) == 0) {
                        return 0;
                    }
                    for (;;) {
                        if (func_002E1700(1) == 2) {
                            if (func_002E1F00() == 1) {
                                goto next_outer;
                            }
                            goto check_de25;
                        }
                        func_0017135C(1);
                    }
                } else {
                    _mscd_D_0030DE24 = 1;
                    func_0017135C(1);
                }
            } else {
                _mscd_D_0030DE24 = 1;
                func_0017135C(1);
            }
        }
    }
    return 1;
}

extern s8 _mscd_D_005661F4 __asm__("D_005661F4");
extern s8 _mscd_D_0030DDFD __asm__("D_0030DDFD");
extern s8 _mscd_D_0030DDFE __asm__("D_0030DDFE");
void hd_file_read_th(int lbn, void *buf, int size, int a3);
int get_hdd_err(void);

int Sa_CdRead_task(int lbn, int size, void *buf, void *mode, int a4)
{
    int sectors;
    int rmode;
    int retry;
    int wait1;
    int wait2;
    int i;

    while (func_002D6788() != 0) {
        func_0017135C(1);
    }
    D_00595F54 = lbn;
    D_00595F58 = size;
    D_00595F5C = (int)buf;
    D_00595F60 = *(Mode1631F0 *)mode;
    sectors = size / 2048;
    rmode = hdd_rmode_get(a4);
    if (_mscd_D_005661F4 != 0 && rmode != 0) {
        func_0015B350();
        hd_file_read_th(lbn, buf, sectors * 2048, a4);
        if (get_hdd_err() == 0) {
            return 1;
        }
        _mscd_D_005661F4 = 0;
        TkRefreshHDDMode();
    }
    D_0030DE28 = 0;
    D_0030DE24 = 0;
    retry = 0;
    wait1 = 60;
    wait2 = 450;
    for (;;) {
        for (i = 0; i < wait1; i++) {
            if (func_002E1700(1) == 2) {
                func_0015B350();
                func_002F8660(0);
                if (func_002E19C0(lbn, sectors, (int)buf, mode) == 1) {
                    for (i = 0; i < wait2; i++) {
                        if (func_00163710() == 0) {
                            return 1;
                        }
                        func_0017135C(1);
                    }
                    break;
                }
            }
            func_001632D8();
            D_0030DE24 = 2;
            D_0030DE28++;
            func_0017135C(1);
        }
        func_002E1FB8();
        D_0030DE24 = 2;
        func_0017135C(1);
        if (retry >= 3) {
            wait1 = 120;
            wait2 = 600;
            for (i = 0; i < 60; i++) {
                if (func_002E1C70() != 0) {
                    break;
                }
                func_0017135C(1);
            }
            for (i = 0; i < 120; i++) {
                if (func_002E11A0(1) == 0) {
                    break;
                }
                func_0017135C(1);
            }
            mode = D_0030DE20;
        } else {
            retry++;
        }
    }
}

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

typedef struct Rec78E530View {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 id;
    s32 w28;
    s32 w2C;
    s8 b30;
    s8 used;
    s8 flag;
    s8 b33;
    s8 b34;
    u8 pad35[3];
} Rec78E530View;

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

int func_00255CF8(u8 *dst, u8 *src, int len, int buf);
int func_00255EC8(u8 *dst, u8 *src, int len, int buf);

void cd_decode_data(s32 a)
{
    Rec78E530View *rec = (Rec78E530View *)a;
    u8 *p = (u8 *)rec->w04;
    u32 sz = rec->w2C;
    int out_sz = p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);

    if (sz <= 0x1800) {
        func_002EEF1C((void *)D_00595F50, p, sz);
        sa_decode((int)p, (u8 *)D_00595F50);
    } else {
        int rem = sz - 0x1800;
        u8 *dst;
        int i;

        __builtin_memcpy((void *)D_00595F50, p + rem, 0x1800);
        dst = p + out_sz - 1;
        i = 0;
        if (rem > 0) {
            do {
                *dst-- = p[rem - i - 1];
                i++;
            } while (i < rem);
        }
        dst++;
        switch (*dst) {
        case 1:
            func_00255CF8(dst, p, rem, D_00595F50);
            break;
        case 2:
            func_00255EC8(dst, p, rem, D_00595F50);
            break;
        }
    }
}

void func_00163958(Q3Obj20 *o) {
    func_00171530(D_00591F50, 0x4000, o->fn, o);
}

extern char D_00595F70[];
extern char D_0056BB68[];
extern char D_0056BBA8[];
extern char D_0056BBC8[];
extern char D_0056BBE0[];
extern char D_0056BC20[];
extern char D_0056BC38[];
extern char D_0056BC48[];
extern char D_0056BC50[];
extern char D_0056BC78[];
extern char D_0056BC88[];
extern char D_0056BCB0[];
extern char D_0056BCC8[];
extern char D_0056BCF0[];
extern char D_0056BD08[];
extern char D_0056BD30[];
extern u8 _mscd_D_0030DE34_nv __asm__("D_0030DE34");
extern s32 _mscd_D_0030DE18_v __asm__("D_0030DE18");
void func_001667B8(char *path, void *buf, int size, int off);
void _mscd_yiAssert(int a, char *b, char *c, ...) __asm__("yiAssert");
int CDfileSize_PC(int a);
void func_00165EF8(void);
void func_00165FA8(void);
void func_00166458(void);
void func_00166390(void);
void func_00254A38(void);
void pc_fat_index_filename_set(void);
int hdd_install_check(void *p);
void hdd_install_init(int a);
void *sa_task_init(int n);
void func_00165398(int v);
void func_001655A8(int a);
u8 *_mscd_func_002558E0(void) __asm__("func_002558E0");
s32 _mscd_func_00255920(void) __asm__("func_00255920");
Rec595F6C *func_00165D20(int type, int id);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163970);

extern G1Rec78E530 _mscd_D_0078E530[] __asm__("D_0078E530.NON_MATCHING");

void func_00163D40(SysVt *cd, G1Rec78E530 *rec, int idx)
{
    int i;
    int j;
    int cnt;

    if (_mscd_D_005661F4 == 0) {
        ((Vt78E498View *)cd)->w74 = idx;
        cnt = 0;
        for (i = 0; i < 0x40; i++) {
            if (_mscd_D_0078E530[i].used != 0) {
                cnt++;
            }
        }
        if (cnt == 1) {
            for (j = 0; j < 16; j++) {
                if (func_002E1BA0(((Rec78E530View *)rec)->w1C) == 1) {
                    break;
                }
                func_0017135C(1);
            }
            if (j != 16) {
                for (;;) {
                    cnt = 0;
                    for (i = 0; i < 0x40; i++) {
                        if (_mscd_D_0078E530[i].used != 0) {
                            cnt++;
                        }
                    }
                    if (cnt != 1) {
                        while (func_002E1FB8() == 0) {
                            func_0017135C(1);
                        }
                        break;
                    }
                    if (func_00163710() == 0) {
                        break;
                    }
                    func_0017135C(1);
                }
            }
        }
    }
    ((Vt78E498View *)cd)->w70 = 0;
    ((Vt78E498View *)cd)->w74 = -1;
    cd->fd5C = -1;
    rec->used = 0;
    rec->id = 0;
}

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

extern char D_0056BB90[];
extern char _f4648_D_0056BB20[] __asm__("D_0056BB20.NON_MATCHING");
extern char _f4648_D_0056BBB8[] __asm__("D_0056BBB8.NON_MATCHING");
extern s32 _f4648_D_0030DDF8 __asm__("D_0030DDF8.NON_MATCHING");
extern SysVt _f4648_D_0078E498 __asm__("D_0078E498.NON_MATCHING");
extern char _f4648_D_0078F330[][0x80] __asm__("D_0078F330");

int func_00164060(int a0, int a1, int a2, Rec78E530View *a3)
{
    int i;
    Rec78E530View *rec;
    char *name = 0;

    for (i = 0; i < 0x40 && _mscd_D_0078E530[i].used != 0; i++)
        ;
    if (i == 0x40) {
        func_001577A8(D_0056BB90, _f4648_D_0056BB20, 0x550);
    }
    rec = (Rec78E530View *)&_mscd_D_0078E530[i];
    rec->used = 1;
    rec->w04 = a1;
    rec->w28 = ((G1Vt78E498 *)&_f4648_D_0078E498)->w24;
    rec->w08 = a0;
    if (a3 == 0) {
        rec->w0C = 0;
        rec->w10 = 0;
        rec->w14 = 0;
        rec->w18 = 0;
    } else {
        rec->w0C = a3->w0C;
        rec->w10 = a3->w10;
        rec->w14 = a3->w14;
        rec->w18 = a3->w18;
    }
    rec->b30 = 0;
    rec->w20 = a2;
    _f4648_D_0030DDF8++;
    if (_f4648_D_0030DDF8 > 0xFFFF) {
        _f4648_D_0030DDF8 = 1;
    }
    rec->id = _f4648_D_0030DDF8;
    switch (((Vt78E498View *)&_f4648_D_0078E498)->w18) {
    case 0:
        if (_mscd_D_005661F4 == 0) {
            rec->w2C = rec->w00 = CDfileSize_PC(a0);
        } else {
            rec->w00 = func_00162ED8(a0);
        }
        rec->w1C = 0;
        if (_mscd_D_005661F4 == 0) {
            name = (char *)CDfileName_PC(a0);
            func_002D3FF0(2);
        } else {
            rec->w1C = func_001631B8(a0);
            rec->w2C = func_001630B0(a0);
            name = D_0056BBA8;
        }
        {
            int j;
            for (j = 0; j < 0x80; j++) {
                _f4648_D_0078F330[i][j] = name[j];
                if (name[j] == 0) {
                    break;
                }
            }
        }
        break;
    case 1:
        rec->w00 = func_00162ED8(a0);
        rec->w1C = func_001631B8(a0);
        rec->w2C = func_001630B0(a0);
        name = _f4648_D_0056BBB8;
        break;
    }
    if (func_0015A550() != 0) {
        _mscd_yiAssert(1, D_0056BBC8, D_0056BBE0, name, ((G1Vt78E498 *)&_f4648_D_0078E498)->w24, a0);
    }
    rec->b33 = func_00163110(a0);
    rec->b34 = 0;
    return _f4648_D_0030DDF8;
}

int func_00164340(int a0, int a1, int a2, int a3, int a4, Rec78E530View *a5)
{
    int i;
    Rec78E530View *rec;
    char *name = 0;

    for (i = 0; i < 0x40 && _mscd_D_0078E530[i].used != 0; i++)
        ;
    if (i == 0x40) {
        func_001577A8(D_0056BB90, _f4648_D_0056BB20, 0x5AA);
    }
    rec = (Rec78E530View *)&_mscd_D_0078E530[i];
    rec->used = 1;
    rec->w04 = a1;
    rec->w28 = ((G1Vt78E498 *)&_f4648_D_0078E498)->w24;
    rec->w08 = a0;
    if (a5 == 0) {
        rec->w0C = 0;
        rec->w10 = 0;
        rec->w14 = 0;
        rec->w18 = 0;
    } else {
        rec->w0C = a5->w0C;
        rec->w10 = a5->w10;
        rec->w14 = a5->w14;
        rec->w18 = a5->w18;
    }
    rec->b30 = 0;
    rec->w20 = a4;
    _f4648_D_0030DDF8++;
    if (_f4648_D_0030DDF8 > 0xFFFF) {
        _f4648_D_0030DDF8 = 1;
    }
    rec->id = _f4648_D_0030DDF8;
    switch (((Vt78E498View *)&_f4648_D_0078E498)->w18) {
    case 0:
        if (_mscd_D_005661F4 == 0) {
            rec->w00 = a3;
            rec->w2C = a3;
        } else {
            rec->w00 = a3;
        }
        if (_mscd_D_005661F4 == 0) {
            rec->w1C = a2 / 2048;
            name = (char *)CDfileName_PC(a0);
            func_002D3FF0(2);
        } else {
            rec->w1C = func_001631B8(a0) + a2 / 2048;
            rec->w2C = a3;
            name = D_0056BBA8;
        }
        {
            int j;
            for (j = 0; j < 0x80; j++) {
                _f4648_D_0078F330[i][j] = name[j];
                if (name[j] == 0) {
                    break;
                }
            }
        }
        break;
    case 1:
        rec->w00 = a3;
        rec->w1C = func_001631B8(a0) + a2 / 2048;
        rec->w2C = a3;
        name = _f4648_D_0056BBB8;
        break;
    }
    if (func_0015A550() != 0) {
        _mscd_yiAssert(1, D_0056BBC8, D_0056BBE0, name, ((G1Vt78E498 *)&_f4648_D_0078E498)->w24, a0);
    }
    rec->b33 = func_00163110(a0);
    rec->b34 = 0;
    return _f4648_D_0030DDF8;
}

int func_00164648(int a0, int a1, int a2, int a3, Rec78E530View *a4)
{
    int i;
    Rec78E530View *rec;
    char *s;

    for (i = 0; i < 0x40 && _mscd_D_0078E530[i].used != 0; i++)
        ;
    if (i == 0x40) {
        func_001577A8(D_0056BB90, _f4648_D_0056BB20, 0x604);
    }
    rec = (Rec78E530View *)&_mscd_D_0078E530[i];
    rec->used = 1;
    rec->w04 = a1;
    rec->w08 = -1;
    rec->w28 = -1;
    if (a4 == 0) {
        rec->w0C = 0;
        rec->w10 = 0;
        rec->w14 = 0;
        rec->w18 = 0;
    } else {
        rec->w0C = a4->w0C;
        rec->w10 = a4->w10;
        rec->w14 = a4->w14;
        rec->w18 = a4->w18;
    }
    rec->w20 = a3;
    _f4648_D_0030DDF8++;
    if (_f4648_D_0030DDF8 > 0xFFFF) {
        _f4648_D_0030DDF8 = 1;
    }
    rec->id = _f4648_D_0030DDF8;
    rec->w00 = a2;
    rec->w2C = a2;
    rec->w1C = a0;
    s = _f4648_D_0056BBB8;
    if (((Vt78E498View *)&_f4648_D_0078E498)->w18 == 0) {
        int j;

        for (j = 0; j < 0x80; j++) {
            if ((_f4648_D_0078F330[i][j] = s[j]) == 0) {
                break;
            }
        }
    }
    rec->b33 = 0;
    rec->b34 = 0;
    return _f4648_D_0030DDF8;
}

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

typedef struct {
    u8 pad00[0x28];
    void *f28;
    void *f2C;
    u8 pad30[4];
    s32 w34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
} CdEnvVt;

void CdEnvInit(int mode)
{
    CdEnvVt *vt;

    D_0030DE34 = 0;
    if (_mscd_D_0030DDFD != 0) {
        func_001577A8(D_0056BC20, (char *)D_0056BB20, 0x6B5);
    }
    _mscd_D_0030DDFD = 1;
    D_00595F64 = sa_task_init(1);
    func_001655A8(mode);
    vt = (CdEnvVt *)&D_0078E498;
    vt->w50 = 0;
    vt->w34 = func_00162798();
    vt->w38 = dvd_cd_fat_sector();
    vt->w3C = dvd_cd_fid_sector();
    vt->w40 = dvd_cd_id_size();
    vt->w44 = dvd_cd_fat_size();
    vt->w48 = func_00162B58();
    vt->w4C = func_00162C18();
    func_00165398(0);
    func_0011C348(0x40);
    D_00595F50 = (s32)user_malloc(0x1800, 10, (char *)D_0056BB20, 0x6C9);
    func_00165EF8();
    _mscd_D_0030DDFE = 0;
    D_0030DE25 = 0;
    if (mode == 0) {
        func_00254A38();
        pc_fat_index_filename_set();
        _mscd_D_00595F68 = _mscd_func_002558E0();
        *(s32 *)((u8 *)&D_0057CB80 + 4) = _mscd_func_00255920();
        func_00165FA8();
    } else {
        int fd;
        u32 sz;
        int sec;

        if (D_0030DE44 != 0) {
            while (func_002E11A0(1) != 0) {
                func_002D3FF0(0);
            }
            while (func_002E1C70() == 0) {
                func_002D3FF0(0);
            }
        }
        while (func_002E11A0(1) != 0) {
            func_002D3FF0(0);
        }
        switch (func_002E1DD0()) {
        case 0x12:
        case 0x13:
            if (func_001663A0() == 0) {
                _mscd_D_0030DDFE = 1;
                fd = func_002FC4E0(D_0056BC38, 1);
                if (fd < 0) {
                    _mscd_yiAssert(1, D_0056BC48, D_0056BC50);
                    BREAK();
                }
                sz = func_002FC8E8(fd, 0, 2);
                func_0011C348(0x40);
                ((CdEnvVt *)&D_0078E498)->f28 = user_malloc(sz, 10, (char *)D_0056BB20, 0x702);
                func_002FC8E8(fd, 0, 0);
                if (func_002FCB20(fd, ((CdEnvVt *)&D_0078E498)->f28, sz) != sz) {
                    BREAK();
                }
                func_002FC768(fd);

                fd = func_002FC4E0(D_0056BC78, 1);
                if (fd < 0) {
                    _mscd_yiAssert(1, D_0056BC48, D_0056BC88);
                    BREAK();
                }
                sz = func_002FC8E8(fd, 0, 2);
                func_0011C348(0x40);
                ((CdEnvVt *)&D_0078E498)->f2C = user_malloc(sz, 10, (char *)D_0056BB20, 0x712);
                func_002FC8E8(fd, 0, 0);
                if (func_002FCB20(fd, ((CdEnvVt *)&D_0078E498)->f2C, sz) != sz) {
                    BREAK();
                }
                func_002FC768(fd);

                fd = func_002FC4E0(D_0056BCB0, 1);
                if (fd < 0) {
                    _mscd_yiAssert(1, D_0056BC48, D_0056BCC8);
                    BREAK();
                }
                sz = func_002FC8E8(fd, 0, 2);
                func_0011C348(0x40);
                _mscd_D_00595F68 = user_malloc(sz, 10, (char *)D_0056BB20, 0x722);
                func_002FC8E8(fd, 0, 0);
                if (func_002FCB20(fd, _mscd_D_00595F68, sz) != sz) {
                    BREAK();
                }
                func_002FC768(fd);

                fd = func_002FC4E0(D_0056BCF0, 1);
                if (fd < 0) {
                    _mscd_yiAssert(1, D_0056BC48, D_0056BD08);
                    BREAK();
                }
                sz = func_002FC8E8(fd, 0, 2);
                func_0011C348(0x40);
                *(void **)((u8 *)&D_0057CB80 + 4) = user_malloc(sz, 10, (char *)D_0056BB20, 0x732);
                func_002FC8E8(fd, 0, 0);
                if (func_002FCB20(fd, *(void **)((u8 *)&D_0057CB80 + 4), sz) != sz) {
                    BREAK();
                }
                func_002FC768(fd);
                func_002F8660(0);
                func_00166458();
            } else {
                _mscd_yiAssert(1, D_0056BC48, D_0056BD30);
                BREAK();
            }
            break;
        default: {
            int saved_de2c = D_0030DE2C;

            D_0030DE2C = 0;
            if (D_0030DE08[0] == 0) {
                sz = dvd_cd_fat_size();
                sec = dvd_cd_fat_sector();
            } else {
                sz = D_0030DE08[1];
                sec = D_0030DE08[0];
            }
            sz += 0x7FF;
            func_0011C348(0x40);
            ((CdEnvVt *)&D_0078E498)->f28 = user_malloc(sz & 0xFFFFF800U, 10, (char *)D_0056BB20, 0x75B);
            while (func_001631F0(sec, sz, (int)((CdEnvVt *)&D_0078E498)->f28, &_mscd_D_0030DE18_v) == 0) {
                do {
                    func_002D3FF0(0);
                } while (func_002E1700(1) != 2);
            }
            while (func_00163710() != 0) {
                func_002D3FF0(0);
            }

            if (D_0030DE08[2] == 0) {
                sz = func_00162B58();
                sec = dvd_cd_fid_sector();
            } else {
                sz = D_0030DE08[3];
                sec = D_0030DE08[2];
            }
            sz += 0x7FF;
            func_0011C348(0x40);
            ((CdEnvVt *)&D_0078E498)->f2C = user_malloc(sz & 0xFFFFF800U, 10, (char *)D_0056BB20, 0x772);
            while (func_001631F0(sec, sz, (int)((CdEnvVt *)&D_0078E498)->f2C, &_mscd_D_0030DE18_v) == 0) {
                do {
                    func_002D3FF0(0);
                } while (func_002E1700(1) != 2);
            }
            while (func_00163710() != 0) {
                func_002D3FF0(0);
            }

            {
                int base = func_00163188(1, 0);
                D_0030DE2C = saved_de2c;
                if (saved_de2c != 0) {
                    D_0030DE2C = saved_de2c - base;
                }
            }
            func_00163FF0(1);
            sz = func_00162ED8(func_001626D8());
            func_0011C348(0x40);
            sz += 0x7FF;
            _mscd_D_00595F68 = user_malloc(sz & 0xFFFFF800U, 10, (char *)D_0056BB20, 0x78D);
            while (func_001631F0(func_00163158((u8 *)func_001626D8()), sz, (int)_mscd_D_00595F68, &_mscd_D_0030DE18_v) == 0) {
                do {
                    func_002D3FF0(0);
                } while (func_002E1700(1) != 2);
            }
            while (func_00163710() != 0) {
                func_002D3FF0(0);
            }

            sz = func_00162ED8(func_00162618());
            func_0011C348(0x40);
            sz += 0x7FF;
            *(void **)((u8 *)&D_0057CB80 + 4) = user_malloc(sz & 0xFFFFF800U, 10, (char *)D_0056BB20, 0x79C);
            while (func_001631F0(func_00163158((u8 *)func_00162618()), sz, *(int *)((u8 *)&D_0057CB80 + 4), &_mscd_D_0030DE18_v) == 0) {
                do {
                    func_002D3FF0(0);
                } while (func_002E1700(1) != 2);
            }
            while (func_00163710() != 0) {
                func_002D3FF0(0);
            }
            func_002F8660(0);
            break;
        }
        }
        func_00165FA8();
    }
    func_00162CE8();
    D_0030DE30 = hdd_install_check(D_00595F6C);
    hdd_install_init(0);
    ((Vt78E498View *)&D_0078E498)->w5C = -1;
    ((Vt78E498View *)&D_0078E498)->w74 = -1;
    ((Vt78E498View *)&D_0078E498)->w70 = 0;
    ((void (*)(void))((Vt78E498View *)&D_0078E498)->f64)();
    ((void (*)(void *, int, int))((void **)D_00595F64)[2])(func_00164A40, 1, 0);
    func_00166390();
}

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

extern char D_0056BD50[];
extern s32 _log_D_0030DE48 __asm__("D_0030DE48");
extern char _log_D_00596070[0x80][0x28] __asm__("D_00596070");
int func_002F46B0(char *, char *, va_list);
void _log_func_002D9190(char *, char *, int) __asm__("func_002D9190"); /* DEBT(TYPE): funcs.h declares fewer args */
void func_001715C0(char *);

void func_00165828(char *fmt, va_list ap)
{
    char buf[0x200];
    char *slot;

    func_002F46B0(buf, fmt, ap);
    slot = _log_D_00596070[_log_D_0030DE48];
    func_002F0C10(slot, buf, 0x27);
    slot[0x27] = 0;
    _log_D_0030DE48 = (_log_D_0030DE48 + 1) & 0x7F;
    if (FFXIsPC() == 1) {
        if (D_00597470[0] == 0) {
            func_001715C0(buf);
        } else {
            register int matched __asm__("$6") = 0; /* DEBT(REG): matches $a2 for prefix-match flag */
            int i = 0;
            while (slot[i] != 0) {
                if (D_00597470[i] == 0) {
                    matched = 1;
                    break;
                }
                if (slot[i] != D_00597470[i]) {
                    break;
                }
                i++;
            }
            if ((s8)D_0030DE4E == matched) {
                func_001715C0(buf);
            }
        }
    } else if (((s8 *)TkGetFFXCofingAdrs())[0xB] != 0) {
        if (D_00597470[0] == 0) {
            func_001715C0(buf);
        } else {
            register int matched __asm__("$6") = 0; /* DEBT(REG): matches $a2 for prefix-match flag */
            int i = 0;
            while (slot[i] != 0) {
                if (D_00597470[i] == 0) {
                    matched = 1;
                    break;
                }
                if (slot[i] != D_00597470[i]) {
                    break;
                }
                i++;
            }
            if ((s8)D_0030DE4E == matched) {
                func_001715C0(buf);
            }
        }
    }
    switch (D_0030DE4D) {
    case 3: {
        int len = func_002F0840(slot);
        if (len != 0) {
            _log_func_002D9190(D_0056BD50, slot, len);
        }
        break;
    }
    case 4:
        if (FFXIsPC() == 1) {
            int len = func_002F0840(slot);
            if (len != 0) {
                func_00165700(slot, len);
            }
        }
        break;
    }
    D_0030DE4C = 1;
}

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

extern s32 _pw_D_0030DE48 __asm__("D_0030DE48.NON_MATCHING");
extern char _pw_D_00596070[0x80][0x28] __asm__("D_00596070.NON_MATCHING");

void printf_write(void)
{
    int idx;
    int i;
    int fd;
    int len;
    int total;
    char *s;
    char *buf;
    char *p;

    if (FFXIsPC() == 1 && D_0030DE4C != 0) {
        switch (D_0030DE4D) {
        case 0:
            break;
        case 1:
            idx = _pw_D_0030DE48;
            fd = func_002FC4E0(D_0056BD40, 0x602);
            if (fd < 0) {
                return;
            }
            for (i = 0; i < 0x80; i++) {
                s = _pw_D_00596070[idx];
                len = func_002F0840(s);
                if (len != 0) {
                    func_002FCD90(fd, s, len);
                }
                idx++;
                idx &= 0x7F;
            }
            func_002FC768(fd);
            break;
        case 2:
            idx = _pw_D_0030DE48;
            total = 0;
            for (i = 0; i < 0x80; i++) {
                char *s0 = _pw_D_00596070[idx];
                idx++;
                idx &= 0x7F;
                total += func_002F0840(s0);
            }
            if (total != 0) {
                buf = (char *)user_malloc(total, 10, (const char *)D_0056BB20, 0x928);
                idx = _pw_D_0030DE48;
                p = buf;
                for (i = 0; i < 0x80; i++) {
                    s = _pw_D_00596070[idx];
                    len = func_002F0840(s);
                    if (len != 0) {
                        func_002F0C10(p, s, len);
                        p += len;
                    }
                    idx++;
                    idx &= 0x7F;
                }
                func_0011D590((s32)buf, 10);
            }
            break;
        }
        _pw_D_0030DE48 = 0;
    }
}

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
