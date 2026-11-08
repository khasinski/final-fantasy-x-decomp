/* tu_346 0x2d9188-0x2d9730: low; ~FFXGetHddEnable (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"
#include "ffx/g4.h"

void func_002D9188(void) {
}

void func_002D9190(void) {
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D9188", func_002D9198);

typedef struct { s8 a; s8 b; } S2Bytes_2D9208;
char *func_002F032C(char *dst, const char *src);
extern S2Bytes_2D9208 D_00576360;

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002D9208(char *arg0, char *arg1) {
    char sp[0x400];
    register char *temp_2 __asm__("$2");

    func_002F0008(sp, arg1, 0);
    *(S2Bytes_2D9208 *)arg0 = D_00576360;
    func_002F032C(arg0, sp);
    temp_2 = (char *)(func_002F0840(arg0) + (s32)arg0);
    __asm__("" : "+r"(temp_2));
    *(temp_2 - 1) = '?';
    *(temp_2 - 2) = '?';
}

/* two trailing ASCII digits of the string -> number */
int func_002D9270(const char *s)
{
    const char *end;
    int tens, ones;

    end = &s[func_002F0840(s)];
    tens = *(end - 2) - '0';
    ones = *(end - 1) - '0';
    return ones + tens * 10;
}

int func_002D92B8(void)
{
    return D_005661E8;
}

int func_002D92C8(void)
{
    return D_005661EC;
}

int func_002D92D8(void)
{
    int ok = 1;
    int ret;

    if (FFXGetLang() == 0) {
        if (func_002D9880() != 0) {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    ret = func_002EF240(D_00576368, ok);
    D_005661EC = ok;
    return ret;
}

/* copies src to dst turning '\n' into '\0'; returns length including the terminator */
int func_002D9328(char *dst, const char *src)
{
    int len;
    u8 c, d;

    if (src == 0) {
        *dst = 0;
        return 0;
    }
    len = func_002F0840(src) + 1;
    do {
        c = *src++;
        d = c;
        if (d == '\n') {
            d = 0;
        }
        *dst++ = d;
    } while (c != 0);
    return len;
}

/* Module: sound driver wrappers (calls into the 0x25xxxx sound library; handle = bit31 flag + 31 bit id) */

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D9188", TkSg_IOPInit);
