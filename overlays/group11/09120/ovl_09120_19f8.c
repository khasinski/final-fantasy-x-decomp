typedef unsigned char u8;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
} Ovl9120SubA;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
} Ovl9120SubB;

typedef struct {
    u8 pad00[0x150];
} Ovl9120SubC;

typedef struct {
    u8 pad00[0x100];
} Ovl9120SubD;

typedef struct {
    u8 pad00[0x20];
    Ovl9120SubD d[4];
    Ovl9120SubA a[4];
    u8 b4E0[0x20];
    u8 b500[0x10];
    Ovl9120SubB b[4];
    Ovl9120SubC c[4];
    float fB10;
    int wB14;
} Ovl9120Eff;

typedef struct {
    void *self;
    Ovl9120Eff *eff;
} Ovl9120Task;

extern float g_ovl_tbl_0378[];
extern void *g_ovl_p38c;
extern u8 g_ovl_dat_0768[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0510[];
extern u8 g_ovl_dat_0788[];
extern void *g_ovl_res;
extern u8 g_ovl_mgr[];

extern void func_001C5E90(void *, int, int);
extern void fn_ovl_6280(void *msg);
extern void func_002DD0B0(void *, void *);
extern float func_001ACED8(void);
extern void fn_ovl_7408(void *msg);
extern void fn_ovl_9568(void *msg);
extern void fn_ovl_a5c0(void *msg);

/* DEBT(CAST): stride-48/256/336 base-offset helpers match ee-gcc addu + offset addressing */
#define EFF_OFF48(eff, idx) ((Ovl9120Eff *)((u8 *)(eff) + (idx) * 48))
#define EFF_OFF256(eff, idx) ((Ovl9120Eff *)(((idx) << 8) + (int)(eff)))
#define EFF_OFF336(eff, idx) ((Ovl9120Eff *)((u8 *)(eff) + (idx) * 336))

void ovl_09120_19f8(Ovl9120Task *task) {
    void *m0[10];
    void *m_end;
    Ovl9120Eff *eff = task->eff;

    eff->fB10 += 1.0f / 30.0f;
    if (eff->fB10 >= g_ovl_tbl_0378[eff->wB14]) {
        /* DEBT(FAKE): pin p768 to s1 so stride 336 uses s2 */
        register u8 *p768 __asm__("$17");
        if (eff->wB14 >= 2) {
            func_001C5E90(g_ovl_p38c, -5, 0);
        }

        p768 = g_ovl_dat_0768;
        m0[0] = &EFF_OFF48(eff, eff->wB14)->a[0];
        m0[1] = p768;
        fn_ovl_6280(m0);

        func_002DD0B0(&EFF_OFF48(eff, eff->wB14)->a[0].f20, eff->b500);

        EFF_OFF48(eff, eff->wB14)->a[0].f20 += (func_001ACED8() - 1.0f) * 8.0f - 4.0f;
        EFF_OFF48(eff, eff->wB14)->a[0].f24 += 2.5f - (func_001ACED8() - 1.0f) * 7.0f;
        {
            float r = (func_001ACED8() - 1.0f) * 8.0f - 4.0f;
            Ovl9120Eff *e = EFF_OFF48(eff, eff->wB14);
            e->a[0].f28 += r;
            e->a[0].f2C = 1.0f;
            m0[0] = &e->b[0];
            m0[1] = p768;
            fn_ovl_6280(m0);
        }

        {
            Ovl9120Eff *e = EFF_OFF48(eff, eff->wB14);
            e->b[0].f20 = 1.0f;
            e->b[0].f24 = 1.0f;
            e->b[0].f28 = 1.0f;
        }
        {
            float r = (func_001ACED8() - 1.0f) * 0.6f + 0.9f;
            /* DEBT(FAKE): pin v1/a2/a1/v0/a0 for 7408 message at 16(sp) */
            /* DEBT(ORDER): volatile stores and empty asm barriers preserve 7408 sw/swc1 schedule */
            register int idx __asm__("$3") = eff->wB14;
            register void *p540 __asm__("$6") = g_ovl_dat_0540;
            register void *p510 __asm__("$5");
            Ovl9120Eff *e;
            void **m16;
            register void **v0 __asm__("$2");
            __asm__("" : "+r"(p540));
            p510 = g_ovl_dat_0510;
            *(void *volatile *)&m0[4] = &EFF_OFF336(eff, idx)->c[0];
            e = EFF_OFF48(eff, idx);
            v0 = m0 + 4;
            __asm__("" : "+r"(v0), "+r"(p540), "+r"(p510), "+r"(e) : "m"(m0[4]));
            *(volatile float *)&e->b[0].f2C = r;
            *(void *volatile *)&v0[1] = p768;
            __asm__("" : "+r"(e), "+r"(v0) : "m"(v0[1]));
            {
                register void *ea __asm__("$7") = &e->a[0];
                __asm__("" : "+r"(ea), "+r"(v0));
                *(void *volatile *)&v0[2] = p540;
                __asm__("" : "+r"(e) : "m"(v0[2]));
                {
                    register void *eb __asm__("$8") = &e->b[0];
                    __asm__("" : "+r"(eb), "+r"(ea));
                    *(void *volatile *)&m0[7] = ea;
                    __asm__("" : "+r"(v0) : "m"(m0[7]));
                    {
                        register void **a0 __asm__("$4") = v0;
                        __asm__("" : "+r"(v0) : "r"(a0));
                        *(void *volatile *)&v0[4] = p510;
                        m0[9] = eb;
                        m16 = a0;
                    }
                }
            }
            fn_ovl_7408(m16);
        }

        {
            int idx = eff->wB14;
            m0[0] = &EFF_OFF256(eff, idx)->d[0];
            m0[1] = g_ovl_dat_0788;
            m0[2] = &EFF_OFF336(eff, idx)->c[0];
            m0[3] = g_ovl_res;
            m0[4] = g_ovl_mgr;
            m0[5] = 0;
            fn_ovl_9568(m0);
        }

        eff->wB14++;
        if (eff->wB14 >= 4) {
            m_end = task->self;
            fn_ovl_a5c0(&m_end);
        }
    }
}
