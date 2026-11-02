/* tu_108 0x162618-0x165eb8: high; libmscd (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/g1.h"
#include "ffx/b0.h"
#include "ffx/u1.h"
#define D_0030DE34 v1_D_0030DE34 /* DEBT(TYPE): v1.h guesses another type for this datum */
#include "ffx/v1.h"
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

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00162E00);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00162E68);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00162ED8);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00162FC0);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_001630B0);

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

INCLUDE_ASM("build/ee_asm/game/libmscd", func_001631F0);

int func_001632B0(void) {
    if (D_0030DE24 != 0) {
        return func_0020D540();
    }
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_001632D8);

INCLUDE_ASM("build/ee_asm/game/libmscd", Sa_CdRead_task);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163710);

INCLUDE_ASM("build/ee_asm/game/libmscd", cd_decode_data);

void func_00163958(Q3Obj20 *o) {
    func_00171530(D_00591F50, 0x4000, o->fn, o);
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163970);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163D40);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163EB0);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00163FF0);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164060);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164340);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164648);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164840);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164918);

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00164990);

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

INCLUDE_ASM("build/ee_asm/game/libmscd", func_00165408);

int func_00165548(int a) {
    return func_00165408(a, 0, 0);
}

int func_00165568(int a, int b) {
    return func_00165408(func_00163188(a, b), a, b);
}

INCLUDE_ASM("build/ee_asm/game/libmscd", func_001655A8);

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
