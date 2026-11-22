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

typedef struct { s8 a; s8 b; } S2Bytes_2D9208;
char *func_002F032C(char *dst, const char *src);
extern S2Bytes_2D9208 D_00576360;

void func_002D9198(char *arg0, char *arg1, int arg2)
{
    char sp[0x400];

    func_002F0008(sp, arg1, arg2);
    *(S2Bytes_2D9208 *)arg0 = D_00576360;
    func_002F032C(arg0, sp);
    func_002F032C(arg0, (const char *)&D_00576360);
    func_002F032C(arg0, sp);
}

/* DEBT(CAST) */
void func_002D9208(char *arg0, char *arg1) {
    char sp[0x400];
    char *temp_2;

    func_002F0008(sp, arg1, 0);
    *(S2Bytes_2D9208 *)arg0 = D_00576360;
    func_002F032C(arg0, sp);
    temp_2 = (char *)(func_002F0840(arg0) + (s32)arg0);
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

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
    u8 pad6[2];
    char *name;
    char *arg;
} IopModEntry; /* DEBT(NAME): 16-byte IOP module entry */

extern char D_005763E8[];
extern char D_00576400[];
extern char D_00576410[];
extern char D_00576418[];
extern char D_00576428[];
extern char D_00576438[];
extern char D_00576458[];
extern const s8 _const_D_00576479 __asm__("D_00576479"); /* DEBT(TYPE): const for loop hoisting */
extern s8 D_005661F1;
extern s8 D_005661F2;
extern s8 D_005661F3;
extern s8 D_005661F5;
extern s8 ffx_debugmode;
extern IopModEntry D_00566188[];
extern IopModEntry D_005660C8[];
extern void func_002FAC88(int);
extern void func_002E1420(int);
extern int func_00300170(char *);
extern int func_00300138(void);
extern void func_002E18F8(int);
extern void func_002FC4A8(void);
extern void func_001660B8(void);
extern int func_00164A70(int);
extern void func_2031988(void);

void TkSg_IOPInit(void)
{
    char buf[0x40];
    char argbuf[0x100];
    IopModEntry *mods;
    int hdd_ok;
    char *dir;
    int hdd_flag;
    int cnt;
    int i;

    func_002D92D8();
    if (TkGetTGS() != 0) {
        dir = D_005763E8;
    } else {
        dir = D_00576400;
    }
    if (func_002D92C8() != 0) {
        hdd_ok = 1;
        hdd_flag = 1;
    } else {
        hdd_ok = 0;
        hdd_flag = 0;
    }

    func_002FAC88(0);
    func_002E1420(0);
    func_002F0008(buf, D_00576410, dir, D_00576418);

    if (_const_D_00576479 == 0) {
        if (D_005661F1 != 0) {
            while (func_00300170(buf) == 0) {
            }
            while (func_00300138() == 0) {
            }
            func_002FAC88(0);
            func_002E1420(0);
        }
        if (D_005661F5 == 0) {
            func_002E18F8(2);
        } else {
            func_002E18F8(1);
        }
        func_002FC4A8();
    }

    D_005661E8 = 0;
    if (TkGetTGS() != 0) {
        cnt = 6;
        mods = D_00566188;
    } else {
        cnt = 0xC;
        mods = D_005660C8;
    }

    for (i = 0; i < cnt; i++) {
        IopModEntry *m = &mods[i];
        int retry = m->b5;
        int arglen;
        char *argp;
        int r;

        if (ffx_debugmode == 0 && m->b0 != 0) {
            continue;
        }
        if (m->b4 > 0 && hdd_ok == 0) {
            continue;
        }
        if ((m->b3 != 0 && D_005661F3 != 0) || _const_D_00576479 != 0) {
                if (m->b2 != 0 && D_005661F2 != 0) {
                    func_002F0008(buf, D_00576428, m->name);
                } else {
                    func_002F0008(buf, D_00576438, m->name);
                }
            } else {
                char *p;

                func_002F0008(buf, D_00576458, dir, m->name);
                p = buf + func_002F0840(dir);
                while (*p != 0) {
                    if ((u8)(*p - 'a') < 26) {
                        *p -= 0x20;
                    }
                    p++;
                }
            }

            arglen = func_002D9328(argbuf, m->arg);
            argp = (arglen != 0) ? argbuf : 0;
            while ((r = func_002FFC70((int)buf, arglen, (int)argp)) < 0) { /* DEBT(TYPE): func_002FFC70 ptr args */
                if (retry < 0) {
                    for (i = 0; i < 100000; i++) {
                    }
                } else {
                    if (retry > 0) {
                        retry--;
                    }
                    if (retry == 0) {
                        if (m->b4 == 1) {
                            hdd_ok = 0;
                            hdd_flag = 0;
                        }
                        if (m->b4 != 0) {
                            hdd_flag = 0;
                        }
                        break;
                    }
                }
            }
            if (r >= 0) {
                D_005661E8 |= 1 << i;
            }
        }

    func_001660B8();
    func_00164A70(hdd_flag);
    if (ffx_debugmode != 0) {
        func_2031988();
    }
}
