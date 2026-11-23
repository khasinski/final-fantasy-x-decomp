/* tu_137 0x18b680-0x18d0f8: low; unk_18B680 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/v2.h"
#include "ffx/s2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018B680);

void func_0018B7A0(void *p, s32 a, s32 b) {
    s32 var_17;
    void *var_16;

    var_16 = p + 0x70;
    for (var_17 = 0; var_17 < 0x48; var_17++) {
        func_0018C468(var_16, var_16, a, b, 0x100);
        var_16 += 0x460;
    }
}

typedef struct {
    int a[8];
} YiTbl8;

extern YiTbl8 D_0056D190;
void func_0018BC00(void *, void *, int);
void func_0018C008(void *, void *, int);
void func_0018C248(void *, void *, int);

void func_0018B810(void)
{
    YiTbl8 tbl = D_0056D190;
    u8 buf1[0x80];
    u8 buf2[0x20];
    int i;
    int j;

    func_0018BC00(buf1, &tbl, 8);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
        }
    }
    func_0018C008(buf1, &tbl, 8);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
        }
    }
    func_0018C248(buf2, buf1, 8);
    for (i = 0; i < 8; i++) {
    }
}

void func_0018B950(u8 *p)
{
    u8 unused[0x1000];
    float a[4];
    float b[4];
    u8 *q;
    int i;

    func_002EF0D0(a, 0, 0x10);
    q = p + 0x70;
    i = 0x47;
    a[0] = 1.0f;
    func_002EF0D0(b, 0, 0x10);
    {
        register volatile int *reg __asm__("$2") = (volatile int *)0x10000000;
        __asm__("" : "+r"(reg));
        b[2] = 64.0f;
        *reg = 0;
    }
    do {
        func_0018C468(q, q, a, b, 0x100);
        q += 0x460;
        i--;
    } while (i >= 0);
    *(volatile int *)0x10000000;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BA08);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BC00);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018BD98);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C008);

void func_0018C248(void *dst_p, void *src_p, int n)
{
    u32 *dst = (u32 *)dst_p;
    float *src = (float *)src_p;
    int i;

    for (i = 0; i < n; i++, dst++) {
        float h = src[0];
        float s = src[1];
        float v = src[2];
        u32 a = (u32)src[3];
        u32 ri, gi, bi;

        if (s == 0.0f) {
            gi = (u32)v;
            ri = gi;
            bi = gi;
            src += 4;
            *dst = (ri & 0xFF) | ((gi << 8) & 0xFF00) | ((bi << 16) & 0xFF0000) | (a << 24);
        } else {
            int hi;
            float f, p, q, t;
            float r, g, b;

            h /= 60.0f;
            hi = (int)h;
            f = h - (float)hi;
            p = v * (1.0f - s);
            q = v * (1.0f - s * f);
            t = v * (1.0f - s * (1.0f - f));
            switch (hi) {
            case 0:
                r = v;
                g = t;
                b = p;
                break;
            case 1:
                r = q;
                g = v;
                b = p;
                break;
            case 2:
                r = p;
                g = v;
                b = t;
                break;
            case 3:
                r = p;
                g = q;
                b = v;
                break;
            case 4:
                r = t;
                g = p;
                b = v;
                break;
            default:
                r = v;
                g = p;
                b = q;
                break;
            }
            src += 4;
            ri = (u32)(r * 255.0f);
            gi = (u32)(g * 255.0f);
            bi = (u32)(b * 255.0f);
            *dst = (ri & 0xFF) | ((gi << 8) & 0xFF00) | ((bi << 16) & 0xFF0000) | (a << 24);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C468);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C6D8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018C9D0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18B680", func_0018CB90);

typedef struct {
    u8 pad0[0x10C];
    u16 type;
    u8 pad10E[0x124 - 0x10E];
    u32 idx;
    u8 pad128[0x134 - 0x128];
    u16 h134;
    u8 pad136[2];
    u16 h138;
    u8 pad13A[0x148 - 0x13A];
    void *p148;
    u8 pad14C[0x178 - 0x14C];
} Yi18Ent; /* DEBT(NAME): guessed 0x178-byte entry in yi_18B680 */

typedef struct {
    u8 pad0[0x68870];
    float f68870;
} Yi18MatView; /* DEBT(NAME): guessed view at +0x68870 */

typedef struct {
    u8 pad0[0x9E7D0];
    u32 count;
    Yi18Ent *ents;
} Yi18ListView; /* DEBT(NAME): guessed view at +0x9E7D0 */

int func_0018C9D0(void *dst, void *src, int n, float scale);

int func_0018CEC8(S2Ctx *ctx) /* DEBT(TYPE): declared int with no return so $v0 is live across loop exit (emits bnezl) */
{
    u8 buf[0x400];
    float a[4];
    int b[4];
    int i;
    int cnt;
    Yi18ListView *lv = (Yi18ListView *)ctx; /* DEBT(CAST): offset view into S2Ctx */

    for (i = 0; i < 4; i++) {
        a[i] = 1.0f;
        b[i] = 0;
    }

    for (i = 0; (u32)i < lv->count; i++) {
        if (lv->ents[i].idx == 0xFFFFFFFFu) {
            continue;
        }
        if (((Yi18MatView *)((u8 *)ctx + lv->ents[i].idx * 0xC0))->f68870 == 1.0f) {
            continue;
        }
        switch (lv->ents[i].type) {
        case 0x14:
        case 0x24:
        case 0x2C:
            cnt = 0x10;
            break;
        case 0x13:
        case 0x1B:
            cnt = 0x100;
            break;
        default:
            cnt = 0;
            break;
        }
        if (cnt > 0) {
            a[0] = ((Yi18MatView *)((u8 *)ctx + lv->ents[i].idx * 0xC0))->f68870;
            func_0018C9D0(buf, lv->ents[i].p148, cnt, a[0]);
            switch (lv->ents[i].type) {
            case 0x14:
            case 0x24:
            case 0x2C:
                func_0018B5A8(ctx, (int)buf, lv->ents[i].h138, lv->ents[i].h134);
                break;
            case 0x13:
            case 0x1B:
                func_0018B558(ctx, (int)buf, lv->ents[i].h138);
                break;
            }
        }
    }
}
