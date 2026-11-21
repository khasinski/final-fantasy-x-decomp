/* Shared 09053-family ppp object update loop (TU rank 17, 912 B, 211 containers).
 * Pure-C u128 (TI-mode) vector copies emit native lq/sq with zero inline asm instructions. */

typedef unsigned char u8;
typedef unsigned short u16;
/* DEBT(TYPE): 128-bit TI-mode integer to emit native lq/sq without inline asm */
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x30];
    void *w30;
    void *w34;
    void *w38;
} OvlList;

typedef struct OvlNode {
    u8 pad00[0x40];
    float v40[4];
    u8 pad50[0x10];
    float f60;
    float f64;
    float f68;
    float f6C;
    u8 pad70[0x10];
    float m80[4][4];
    float fC0[3];
    float fCC;
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    float vE0[4];
    float vF0[4];
    void (*fn100)(struct OvlNode *);
    void (*fn104)(struct OvlNode *);
    void *w108;
    void *w10C;
    void *w110;
    int w114;
    int w118;
    int w11C;
    u8 pad120[4];
    u16 h124;
    u8 b126;
} OvlNode;

extern void *D_006A3924;
extern float D_006A3930[4][4];
extern float D_006A3970[4][4];
extern float D_006A39B0[4][4];
extern float D_006A3A70[4][4];
extern float D_006A3AB0[4][4];
extern float D_006A3BB0[4];
extern void *D_006A3BC8;
extern void *D_006A3BCC;

extern void fn_ovl_2510(void *, void *);
extern void fn_ovl_2f40(void *);
extern void fn_ovl_30e0(void *, void *);
extern void fn_ovl_3fa0(void *, void *);
extern void fn_ovl_40d0(void *);
extern OvlNode *fn_ovl_4130(void *);

extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DD270(void *, void *, float);
extern void func_002DD318(void *, void *, float);
extern void func_002DD3C0(void *, void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_002DD948(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern int func_00267FA0(void *, int);
extern void func_00267530(void *);
extern void func_00268610(void *, void *, void *);

static __inline__ void copy_vec(void *dst, const void *src)
{
    /* DEBT(FAKE): pin $2 (v0) and $7 (a3) to match PS2 SDK sceVu0CopyVector */
    /* DEBT(ORDER): empty asm barriers prevent offset folding into lq/sq */
    register const u128 *sp __asm__("$2") = (const u128 *)src;
    u128 *dp = (u128 *)dst;
    register u128 t __asm__("$7");
    __asm__ volatile("" : "+r"(sp) : "r"(dp) : "memory");
    t = *(const volatile u128 *)sp;
    *(volatile u128 *)dp = t;
    __asm__ volatile("" : : : "memory");
}

int ovl_09053_pppcalc(OvlList *arg0_in, void *arg1)
{
    /* DEBT(FAKE): pin s5/s4/s6 for arg0/list/unit so count and m[1] spill to 144(sp)/148(sp) */
    register OvlList *arg0 __asm__("$21") = arg0_in;
    float m[4][4];
    float unit[4][4];
    float v[4];
    int count;
    register void *list __asm__("$20") = &arg0->w30;
    OvlNode *node;
    register float (*punit)[4] __asm__("$22");
    float *m1, *m2, *m3;

    /* DEBT(ORDER): empty asm barrier keeps sw zero,144(sp) between lw v0,48(s5) and sw v0,8(s4) */
    {
        void *t0 = arg0->w30;
        count = 0;
        __asm__("" : : "r"(t0));
        ((void **)list)[2] = t0;
    }
    D_006A3924 = arg0;
    if (arg1 != 0) {
        D_006A3BCC = arg1;
    }
    fn_ovl_2510(D_006A3A70, D_006A3970);
    punit = unit;
    func_002DD128(punit);
    /* DEBT(ORDER): keep m[1..3] base pointers hoisted across loop and fill branch delay slot with m3 */
    m1 = m[1];
    m2 = m[2];
    __asm__ volatile("" : "+r"(m2) : "r"(arg0), "r"(list));
    m3 = m[3];

    while ((node = fn_ovl_4130(list)) != 0) {
        if (node->h124 & 0x8000) {
            if (!(node->h124 & 1)) {
                if (node->w114 == 0) {
                    int ret;
                    /* DEBT(FAKE): pin s2/s1/s3 for post-switch m[1..3] row pointers */
                    register float *rm1 __asm__("$18");
                    register float *rm2 __asm__("$17");
                    register float *rm3 __asm__("$19");
                    if (node->fn104 != 0) {
                        node->fn104(node);
                    }
                    if (node->fn100 != 0 && node->w11C == node->w118) {
                        node->fn100(node);
                    }
                    switch (node->b126) {
                    case 1:
                        func_002DD3C0(m, punit, node->fC0);
                    set_m23:
                        rm1 = m[1];
                        rm2 = m[2];
                        rm3 = m[3];
                        break;
                    case 2:
                        copy_vec(m[0], node->m80[0]);
                        rm1 = m1;
                        {
                            /* DEBT(FAKE): pin $2/$7 and "+r"(rm1) to emit sq a3,0(s2) without reload */
                            /* DEBT(ORDER): empty asm barriers prevent offset folding into lq/sq */
                            register const u128 *_sp __asm__("$2") = (const u128 *)node->m80[1];
                            register u128 _t __asm__("$7");
                            __asm__ volatile("" : "+r"(_sp), "+r"(rm1) : : "memory");
                            _t = *(const volatile u128 *)_sp;
                            *(volatile u128 *)rm1 = _t;
                            __asm__ volatile("" : : : "memory");
                        }
                        /* DEBT(ORDER): empty asm barriers keep move s1,s8 / move s3,s7 before lq/sq and stop CSE into set_m23 */
                        rm2 = m2;
                        __asm__("" : "+r"(rm2));
                        copy_vec(m2, node->m80[2]);
                        rm3 = m3;
                        __asm__("" : "+r"(rm3));
                        copy_vec(m3, unit[3]);
                        __asm__("" : "+g"(m1), "+r"(m3));
                        break;
                    default:
                        func_002DD1C8(m, punit, node->fC0[2]);
                        func_002DD270(m, m, node->fC0[0]);
                        func_002DD318(m, m, node->fC0[1]);
                        /* DEBT(GOTO): cross-jump to shared m[1..3] setup tail with case 1 */
                        goto set_m23;
                    }
                    func_002DCE08(v, m, node->vE0);
                    func_002DD998(m[0], m[0], node->f60);
                    func_002DD998(rm1, rm1, node->f64);
                    func_002DD998(rm2, rm2, node->f68);
                    m[3][0] = node->fD0 + v[0];
                    m[3][1] = node->fD4 + v[1];
                    m[3][2] = node->fD8 + v[2];
                    func_002DD948(node->v40, rm3);
                    func_002DD0C0(D_006A3930, m);
                    if (node->w108 != 0) {
                        D_006A3BC8 = node->w108;
                    }
                    copy_vec(D_006A3BB0, node->vF0);
                    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                    if (!(node->h124 & 0x4000)) {
                        /* DEBT(ORDER): empty asm inputs preserve arg0/list register priority over m1 */
                        __asm__("" : : "r"(arg0));
                        __asm__("" : : "r"(arg0));
                        __asm__("" : : "r"(arg0));
                        __asm__("" : : "r"(list));
                        __asm__("" : : "r"(list));
                        D_006A3924 = arg0;
                        ret = func_00267FA0(node, 48);
                    } else {
                        node->h124 &= 0xBFFF;
                        ret = 1;
                    }
                    if (ret == 1) {
                        D_006A3924 = arg0;
                        func_00267530(node);
                        node->h124 &= 0x7FFF;
                        fn_ovl_3fa0(list, node);
                    } else if (node->w10C != 0) {
                        func_00268610(node, node->w10C, node);
                    }
                    if (node->w110 != 0) {
                        fn_ovl_30e0(node->w110, rm3);
                        fn_ovl_2f40(node->w110);
                    }
                    node->w118++;
                } else {
                    node->w114--;
                }
            }
            count++;
        }
        if (node == fn_ovl_4130(list)) {
            fn_ovl_40d0(list);
        }
    }
    return count == 0;
}
