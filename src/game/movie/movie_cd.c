/* tu_103 0x15b340-0x15bbf8: low; movie_cd (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"

void *func_0015B340(void) {
    return D_0030DCE0;
}

void func_0015B350(void) {
    D_00591EC0 = 0;
    D_00591EC4 = 0;
}

int func_0015B368(S58FE54 *s)
{
    if (s->b5075D != 0) {
        return 0;
    }
    if (func_002E1F00() == 1) {
        D_00591EB0 = 1;
        audioStop(s);
        for (;;) {
            if (func_002E1700(1) == 2) {
                if (func_002E1F00() != 1) {
                    return 0;
                }
            }
            func_001631E0(1);
            func_0015C808();
            func_0015DDB8();
        }
    }
    return 1;
}

int func_0015B418(int a)
{
    if (func_002E1F00() == 1) {
        for (;;) {
            if (func_002E1700(1) == 2) {
                if (func_002E1F00() != 1) {
                    return 0;
                }
            }
            func_001631E0(1);
            if (a == 0) {
                func_002D3FF0(0);
            } else {
                func_0015C808();
            }
        }
    }
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_cd", func_0015B4B0);

int func_0015B798(int a, int size, int c, S58FE54 *s)
{
    int n = size / 2048;
    int m;

    if (size & 0x7FF) {
        m = n + 1;
    } else {
        m = n;
    }
    D_00591EB0 = 1;
    func_0015B4B0(a, m, c, D_0030DCE0, s);
    func_0015B9E8(0, s);
    return 1;
}

void func_0015B808(int a) {
    D_00591EC0 = a;
    D_00591EC4 = func_002E1E68();
}

int func_0015B830(void) {
    return func_002E0738();
}

int func_0015B850(void) {
    if (D_00591EC4 == 0) {
        return D_00591EC0 == 1 ? 0 : -1;
    }
    return D_00591EC4;
}

int movieOpenCd(S58FE54 *s)
{
    D_00591E9C = 0;
    D_00591EA0 = 0;
    D_00591EA4 = 0;
    D_00591EA8 = 0;
    D_00591EAC = 0;
    D_00591EB0 = 1;
    func_0015B350();
    D_00591E78[0] = s->w506E4;
    D_00591E78[1] = s->w506E8;
    if (s->b5075D != 0) {
        return movie_hdd_file_open(s->b50764, s->w506E4);
    }
    return 1;
}

int func_0015B918(int n, u8 *buf, int *out, S58FE54 *s)
{
    int sectors;

    if (D_00591E9C != 0) {
        int tmp = n + 0x800;
        *out = 0x800 - D_00591E9C;
        n = tmp - D_00591E9C;
        D_00591E78[0]--;
    } else {
        *out = 0;
    }
    sectors = n / 0x800;
    if (n & 0x7FF) {
        D_00591E9C = 0x800 - (n % 0x800);
        sectors++;
    } else {
        D_00591E9C = 0;
    }
    func_0015B4B0(D_00591E78[0], sectors, (int)buf, D_0030DCE0, s);
    D_00591E78[0] += sectors;
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_cd", func_0015B9E8);

int func_0015BBA8(S58FE54 *s)
{
    if (s->b5075D != 0) {
        return D_00591EB0;
    }
    if (func_0015B850() != 0) {
        return 1;
    }
    D_00591EB0 = 0;
    return 0;
}
