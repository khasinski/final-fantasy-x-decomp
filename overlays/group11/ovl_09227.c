/* EE Battle-Effect Overlay: group 0x11, file 09227
 * Load base: 0x01B00000, .text: 0x01B00648..0x01B012A8 (9 functions)
 */
#include "../oef_overlay.h"
#include "vu0.h"

extern u8 D_01B00040[];
extern int D_01B00630;
extern int D_01B00634;
extern int D_01B00638;
extern int D_01B012C0;
extern void *D_01B012C4;
extern void *D_01B012C8;
extern OefPartObj D_01B012D0;
extern OefPartObj D_01B01350;
extern OefHeapMgr D_01B013D0;
extern u8 D_01B01400[];
extern u8 D_01C01400[];
extern int D_01D01400;
extern int D_01D01404;
extern int D_01D01408;
extern void *D_01D0140C;
extern void *D_01D01410;
extern void *D_01D01414;
extern void *D_01D01418;
extern int D_01D0141C;
extern u16 D_01D01420;
extern u16 D_01D01422;
extern float D_01D01440[4];
extern float D_01D01490[16];
extern float D_01D014D0[16];
extern float D_01D01510;
extern float D_01D01514;
extern float D_01D01520[4];
extern float D_01D01530[4];
extern float D_01D01520b[4] __asm__("D_01D01520");
extern OefHeapCfg D_01D01550;
extern u8 D_01D15500[];

void func_002B4980(void *res);
void func_002944B0(void *res, int a, int b, int c);
void *func_002B49A0(void *res, int a, int b);
void *func_001B4EA8(int id, int n);
float func_001B63B8(int id);
void func_001B5810(int id, int v);
int func_001CDAF8(int id);
void func_001CDC58(int id, int v);
int func_001CDDD8(int id);
void func_001CE2F0(int h, int v);
void func_001CE050(int h, int v);
int func_00294B70(void *h, int a, int b);
void func_00107378(void *chr, void *dst);
void func_00110830(void *chr, void *m);
int func_001108B8(void *chr, int v);
void func_0026BEB0(void *m, int angle);
void func_002DCE08(void *out, void *m, void *in);
void func_01B00938(float *p, float scale);

void func_01B00648(void *res)
{
    void **p0 = &D_01B012C4;
    void **p1 = &D_01B012C8;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
    *p1 = func_002B49A0(res, 6, 1);
}

int func_01B006D8(int eff_id)
{
    u8 buf[16];

    D_01B012C0 = eff_id;
    D_01D01408 = MsGetEff2Chr(eff_id);
    D_01D01404 = *MsGetTargetList(D_01B012C0, buf);
    D_01D01404 = MsGetEff2Chr(D_01B012C0);
    D_01D01408 = *MsGetTargetList(D_01B012C0, buf);
    D_01D0140C = MsGetChrHandle(D_01D01404);
    D_01D01410 = MsGetChrHandle(D_01D01408);
    D_01D01414 = func_001B4EA8(D_01D01408, 0);
    D_01D01418 = func_001B4EA8(D_01D01408, 1);
    func_001B6790(D_01D01408, D_01D01440);
    D_01D01510 = func_001B63B8(D_01D01408) * 0.5;
    D_01D0141C = -1;
    D_01D01422 = D_01D01420 = 0;
    func_00107378(D_01D01410, D_01D014D0);
    *(u_long128 *)&D_01D014D0[12] = 0;
    D_01D014D0[15] = 1.0f;
    func_002DD068(&D_01D014D0[0], &D_01D014D0[0], 100.0f);
    func_002DD068(&D_01D014D0[4], &D_01D014D0[4], 100.0f);
    func_002DD068(&D_01D014D0[8], &D_01D014D0[8], 100.0f);
    D_01D01400 = 0x47;
    func_01B00648(D_01D15500);
    _pppInitData(&D_01D01550, D_01B00040);
    pppInitEnv(&D_01B013D0, &D_01D01550, D_01B01400, 0x100000);
    D_006A3924 = &D_01B013D0;
    _pppStartPart(&D_01B012D0, 0x1000, D_01D01550.pdt[0], 1);
    D_006A3924 = &D_01B013D0;
    _pppStartPart(&D_01B01350, 0x1000, D_01D01550.pdt[1], 1);
    D_01B01350.enabled = 1;
    D_01B012D0.enabled = 1;
    return 0;
}

int func_01B00928(void)
{
    return 0;
}

int func_01B00930(void)
{
    return 0;
}

void func_01B00938(float *p, float scale)
{
    func_002DD068(p, D_01D01520, scale);
    p[0] += D_01D01530[0];
    p[1] += D_01D01530[1] + D_01D01510;
    p[2] += D_01D01530[2];
}

int func_01B009A8(void)
{
    float m[16];
    float o[4];
    float t[4];
    float u[4];
    float f;
    float z;
    float one;
    int s;
    float unused[16];

    if (D_01B00630 == 0) {
        if (func_0029B830(D_01B012C0) != 0) {
            return 0;
        }
        D_01B00630++;
    }
    if (D_01B00634 == 0) {
        D_01B00634 = 1;
        func_001CDC58(D_01B012C0, 0);
    }
    if (D_01B00638 == 0) {
        if (func_001CDAF8(D_01B012C0) <= 0) {
            goto done;
        }
        D_01B00638 += 1;
    }
    if (D_01D01400 == 0x83) {
        func_001CE050(D_01D01404, 0xB2);
    }
    s = D_01D01400 - 0xBF;
    if ((unsigned)s >= 0x47) {
        return 0;
    }
    if (s == 0) {
        func_001CE050(D_01D01408, 0x80);
    } else if (s == 30) {
        func_001CE050(D_01D01408, 0x81);
    }
    func_0026BEB0(m, (s16)D_01D01420);
    func_002DCE38(D_01D01490, D_01D014D0, m);
    z = 0.0f;
    one = 1.0f;
    o[2] = z;
    o[0] = z;
    o[1] = D_01D01510;
    o[3] = one;
    func_002DCE08(o, D_01D01490, o);
    o[1] -= D_01D01510;
    func_002DD068(&D_01D01490[0], &D_01D01490[0], 0.01f);
    func_002DD068(&D_01D01490[4], &D_01D01490[4], 0.01f);
    func_002DD068(&D_01D01490[8], &D_01D01490[8], 0.01f);
    if (s < 30) {
        f = s;
        f /= 30.0f;
        func_01B00938(u, D_01D01514);
        func_002DCFF8(t, u, D_01D01440, f);
    } else if (s < 50) {
        func_01B00938(t, D_01D01514);
    } else if (s < 70) {
        f = s - 50;
        f /= 20.0f;
        f = f * f;
        func_01B00938(u, D_01D01514);
        func_002DCFF8(t, D_01D01530, u, f);
    } else if (s == 70) {
        func_001B5810(D_01D01408, 0);
        return 0;
    }
    if (D_01D01440[1] < t[1]) {
        t[1] = D_01D01440[1];
    } else {
        if (D_01D0141C == -1) {
            D_01D0141C = func_001108B8(D_01D01410, 0);
        }
    }
    D_01D01490[12] = t[0] + o[0];
    D_01D01490[13] = t[1] + o[1];
    D_01D01490[14] = t[2] + o[2];
    func_00110830(D_01D01410, D_01D01490);
    D_01D01422 += 0x80;
    D_01D01420 += D_01D01422;
done:
    return 0;
}

int func_01B00D38(void)
{
    float a[4];
    float b[4];
    float c[4];
    float mid[4];
    float m[16];
    float w[16];
    float r[16];
    float d[4];
    float q;
    float dx;
    float dz;
    float ta0;
    float tb0;
    float ta2;
    float tb2;
    float z;
    float one;
    int ia;
    int ib;

    if (D_01B00638 == 0) {
        return 0;
    }
    ia = D_01D01400 - 0xA1;
    ib = D_01D01400 - 0xBF;
    if (D_01D01400 == 0xA1) {
        func_00294B70(D_01B012C4, 0x40, 0x100);
        func_00294B70(D_01B012C8, 0x40, 0x100);
    }
    if (ib >= 0 || ia >= 0) {
        func_00107428(D_01D0140C, 0xA8, 0, a);
        func_00107428(D_01D0140C, 0xEB, 0, b);
        func_00107428(D_01D0140C, 0x2D, 0, D_01D01530);
        mid[0] = (a[0] + b[0]) * 0.5;
        mid[1] = (a[1] + b[1]) * 0.5;
        mid[2] = (a[2] + b[2]) * 0.5;
        D_01D01530[1] = mid[1];
        func_001072F8(D_01D0140C, 0x2D, w);
        func_002DD068(&w[0], &w[0], 100.0f);
        func_002DD068(&w[4], &w[4], 100.0f);
        func_002DD068(&w[8], &w[8], 100.0f);
        *(u_long128 *)&w[12] = 0;
        w[15] = 1.0f;
        func_0026BEB0(r, 0x4000);
        func_002DCE38(m, w, r);
        z = 0.0f;
        one = 1.0f;
        c[0] = one;
        c[2] = z;
        c[1] = z;
        c[3] = one;
        func_002DCE08(D_01D01520, w, c);
        m[12] = mid[0];
        m[13] = mid[1];
        m[14] = mid[2];
        m[15] = 1.0f;
        if (ib == 0) {
            tb0 = D_01D01440[0];
            ta2 = D_01D01530[2];
            ta0 = D_01D01530[0];
            tb2 = D_01D01440[2];
            dx = ta0 - tb0;
            dz = ta2 - tb2;
            q = dx * dx + dz * dz;
            D_01D01514 = q;
            __asm__ volatile("" : : : "memory");
            __asm__ volatile("mfc1 $4, %1\n\tqmtc2 $4, $vf2\n\t.word 0x4A0203BD\n\tvwaitq\n\tvaddq.x $vf2, $vf0, Q\n\tqmfc2 $4, $vf2\n\tmtc1 $4, %0"
                             : "=f"(q) : "f"(q) : "$4");
            D_01D01514 = q;
        }
        D_01B013D0.w20 = D_01D01550.w14;
        D_01B013D0.tbl = D_01D01550.tbl;
        D_01B013D0.p28 = D_01D01550.p1C;
        D_006A3924 = &D_01B013D0;
        func_001AACA0(D_006A3A70);
        func_001A9EE0(D_006A3970);
        D_006A3BCC = D_01C01400;
        if (D_01B012D0.enabled != 0 && ib >= 0) {
            D_01B012D0.scale[0] = D_01B012D0.scale[1] = D_01B012D0.scale[2] = D_01B012D0.scale[3] = 0.35f;
            func_002DD068(D_006A3930, &m[0], D_01B012D0.scale[0]);
            func_002DD068(D_006A3930 + 0x10, &m[4], D_01B012D0.scale[1]);
            func_002DD068(D_006A3930 + 0x20, &m[8], D_01B012D0.scale[2]);
            *(u_long128 *)(D_006A3930 + 0x30) = *(u_long128 *)&m[12];
            func_002DD068(d, D_01D01520b, 5.0f);
            ((float *)(D_006A3930 + 0x30))[0] += d[0];
            ((float *)(D_006A3930 + 0x30))[1] += d[1];
            ((float *)(D_006A3930 + 0x30))[2] += d[2];
            func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
            func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
            D_006A3924 = &D_01B013D0;
            if (_pppRunPart(&D_01B012D0, 0x30) != 0) {
                D_01B012D0.enabled = 0;
            }
        }
        if (D_01B01350.enabled != 0 && ia >= 0) {
            D_01B01350.scale[0] = D_01B01350.scale[1] = D_01B01350.scale[2] = D_01B01350.scale[3] = 0.3f;
            func_002DD068(D_006A3930, &m[0], D_01B01350.scale[0]);
            func_002DD068(D_006A3930 + 0x10, &m[4], D_01B01350.scale[1]);
            func_002DD068(D_006A3930 + 0x20, &m[8], D_01B01350.scale[2]);
            *(u_long128 *)(D_006A3930 + 0x30) = *(u_long128 *)&m[12];
            func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
            func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
            D_006A3924 = &D_01B013D0;
            if (_pppRunPart(&D_01B01350, 0x30) != 0) {
                D_01B01350.enabled = 0;
            }
        }
    }
    if (D_01D01400 == 0x183) {
        func_00110830(D_01D01410, 0);
        func_001108B8(D_01D01410, D_01D0141C);
        func_001CE2F0(D_01D01404, 0);
        func_001CE2F0(D_01D01408, 0);
        func_001CDDD8(D_01B012C0);
    }
    D_01D01400++;
    return 0;
}

int func_01B01298(void)
{
    return 0;
}

void func_01B012A0(void)
{
}
