/* EE Battle-Effect Overlay: group 0x11, file 09439 (0x01B00FF8..0x01B01450)
 * Load base: 0x01B00000, .text: 0x01B00FF8..0x01B01450 (1 function)
 */
#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

extern int D_01B081AC;
extern int D_01B081B8;
extern u64 D_006F2D40;

void func_01B00B18(void);
void func_0011ABA8(int);
void func_01B00D38(void);
void func_002DA610(int, int);
void *func_002DB6D8(int);
void func_002DBA28(void *, void *);

void func_01B00FF8(void)
{
    void *ch;
    register Qword *p __asm__("$7");
    int n;
    int a;
    register u32 y __asm__("$23");

    if (D_01B081B8 == 0) {
        func_01B00B18();
        func_0011ABA8(1);
        D_01B081B8 = 1;
    }

    func_01B00D38();
    func_002DA610(0, 0);
    ch = func_002DB6D8(2);
    n = 10;
    y = 0x72F8;

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000003;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008002ULL;
    p->d[1] = 0xEULL;
    p++;
    p->d[0] = 0x0003000DULL;
    p->d[1] = 0x47ULL;
    p++;
    p->d[0] = 0x0000008000000044ULL;
    p->d[1] = 0x42ULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    a = ((n - D_01B081AC) << 6) / n;
    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000004;
    p++;
    p->q = 0;
    p->d[0] = 0x3023400000008001ULL;
    p->d[1] = 0x551ULL;
    p++;
    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = a;
    p++;
    p->w[0] = 0x6FF8;
    p->w[1] = y;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    {
        register u32 yc __asm__("$8") = 0x8CF8;
        __asm__("" : "+r"(yc) : "m"(p[-3].d[1]));
        p->w[1] = yc;
        __asm__("" : "+m"(*p));
        p->w[0] = 0x8FF8;
        p->w[2] = 0;
        p->w[3] = 0;
    }
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    a = ((10 - D_01B081AC) << 7) / 10;
    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000011;
    p++;
    p->q = 0;
    p->d[0] = 0x8026400000008002ULL;
    p->d[1] = 0x51515151ULL;
    p++;
    p->w[0] = 0; p->w[1] = 0; p->w[2] = 0; p->w[3] = a;
    p++;
    p->w[0] = 0x6FF8; p->w[1] = y; p->w[2] = 0; p->w[3] = 0;
    p++;
    p->w[0] = 0; p->w[1] = 0; p->w[2] = 0; p->w[3] = a;
    p++;
    p->w[0] = 0x8FF8; p->w[1] = y; p->w[2] = 0; p->w[3] = 0;
    y = 0x87F8;
    {
        register u32 yt __asm__("$8") = 0x77F8;
        p++;
        p->w[0] = 0; p->w[1] = 0; p->w[2] = 0; p->w[3] = 0;
        p++;
        p->w[0] = 0x6FF8; p->w[1] = yt; p->w[2] = 0; p->w[3] = 0;
        p++;
        p->w[0] = 0; p->w[1] = 0; p->w[2] = 0; p->w[3] = 0;
        p++;
        p->w[0] = 0x8FF8; p->w[1] = yt; p->w[3] = 0;
        yt = 0x8CF8;
        __asm__("" : "+r"(yt) : "m"(p->w[3]));
        p->w[2] = 0;
        p++;
        p->w[0] = 0; __asm__("" : "+m"(*p)); p->w[1] = 0; __asm__("" : "+m"(*p)); p->w[3] = 0; __asm__("" : "+m"(*p)); p->w[2] = 0;
        p++;
        p->w[0] = 0x6FF8; __asm__("" : "+m"(*p)); p->w[1] = y; p->w[2] = 0; p->w[3] = 0;
        p++;
        p->w[0] = 0; __asm__("" : "+m"(*p)); p->w[1] = 0; __asm__("" : "+m"(*p)); p->w[3] = 0; __asm__("" : "+m"(*p)); p->w[2] = 0;
        p++;
        p->w[1] = y; __asm__("" : "+m"(*p)); p->w[0] = 0x8FF8; p->w[2] = 0; p->w[3] = 0;
        p++;
        p->w[0] = 0; __asm__("" : "+m"(*p)); p->w[1] = 0; __asm__("" : "+m"(*p)); p->w[3] = a; __asm__("" : "+m"(*p)); p->w[2] = 0;
        p++;
        p->w[0] = 0x6FF8; p->w[1] = yt; p->w[3] = 0; __asm__("" : "+m"(*p)); p->w[2] = 0;
        p++;
        p->w[0] = 0; __asm__("" : "+m"(*p)); p->w[1] = 0; __asm__("" : "+m"(*p)); p->w[3] = a; __asm__("" : "+m"(*p)); p->w[2] = 0;
        p++;
        p->w[0] = 0x8FF8; p->w[1] = yt; p->w[3] = 0; p->w[2] = 0;
    }
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;
    p->q = 0;
    ((u64 *)p)[1] = 0xEULL;
    __asm__("" : "+m"(*p));
    ((u64 *)p)[0] = 0x1000000000008001ULL;
    p++;
    p->d[0] = D_006F2D40;
    p->d[1] = 0x47ULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
