typedef unsigned char u8;

extern void fn_sys_1c5e90(void *a0, void *a1, int a2);
extern void fn_ovl_358d0(void *msg);
extern void fn_sys_2dd0b0(void *a0, void *a1);
extern float fn_sys_1aced8(void);
extern void fn_ovl_36a58(void *msg);
extern void fn_ovl_38bb8(void *msg);
extern void fn_ovl_39c10(void *msg);

extern float g_ovl_times_378[];
extern u8 g_ovl_dat_7b0[];
extern void *g_ovl_ptr_38c;
extern u8 g_ovl_dat_768[];
extern u8 g_ovl_dat_540[];
extern u8 g_ovl_dat_510[];
extern void *g_ovl_ptr_3af7c;
extern u8 g_ovl_dat_788[];
extern u8 g_ovl_dat_3af50[];

void ovl_09374_30c58(void **arg) {
    u8 *ctx = (u8 *)arg[1];
    void *m0[10];
    void *m_end;
    float t;
    int step;

    t = *(float *)(ctx + 2832) + (1.0f / 30.0f);
    *(float *)(ctx + 2832) = t;
    step = *(int *)(ctx + 2836);
    if (t >= g_ovl_times_378[step]) {
        if (step == 2) {
            u8 *p7b0 = g_ovl_dat_7b0;
            fn_sys_1c5e90(g_ovl_ptr_38c, *(void **)(p7b0 + *(int *)(ctx + 2840) * 160 + 116), 0);
            step = *(int *)(ctx + 2836);
        }

        {
            u8 *p768 = g_ovl_dat_768;
            m0[0] = ctx + step * 48 + 1056;
            m0[1] = p768;
            fn_ovl_358d0(m0);

            fn_sys_2dd0b0(ctx + *(int *)(ctx + 2836) * 48 + 1088, ctx + 1472);

            *(float *)(ctx + *(int *)(ctx + 2836) * 48 + 1088) += (fn_sys_1aced8() - 1.0f) * 8.0f - 4.0f;
            *(float *)(ctx + *(int *)(ctx + 2836) * 48 + 1092) += 2.5f - (fn_sys_1aced8() - 1.0f) * 7.0f;
            {
                float r = (fn_sys_1aced8() - 1.0f) * 8.0f - 4.0f;
                u8 *p = ctx + *(int *)(ctx + 2836) * 48;
                *(float *)(p + 1096) += r;
                *(float *)(p + 1100) = 1.0f;
                m0[0] = p + 1248;
                m0[1] = p768;
                fn_ovl_358d0(m0);
            }

            {
                u8 *p = ctx + *(int *)(ctx + 2836) * 48;
                *(float *)(p + 1280) = 1.0f;
                *(float *)(p + 1284) = 1.0f;
                *(float *)(p + 1288) = 1.0f;
            }
            {
                /* DEBT(FAKE): pin v1/a2/a1/a0/v0 for 36a58 message at 16(sp) */
                /* DEBT(ORDER): volatile stores preserve sw/swc1 interleaving for 36a58 message */
                float s = (fn_sys_1aced8() - 1.0f) * 0.6f + 0.9f;
                register int st __asm__("$3") = *(int *)(ctx + 2836);
                register void *p540 __asm__("$6") = g_ovl_dat_540;
                register void *p510 __asm__("$5") = g_ovl_dat_510;
                register void *slot __asm__("$4") = ctx + st * 336 + 1488;
                register u8 *p __asm__("$3") = ctx + st * 48;
                m0[4] = slot;
                {
                    void **v0 = m0 + 4;
                    register void *p1056 __asm__("$7") = p + 1056;
                    register void *p1248 __asm__("$8") = p + 1248;
                    *(volatile float *)(p + 1292) = s;
                    v0[1] = p768;
                    v0[2] = p540;
                    *(void *volatile *)&m0[7] = p1056;
                    v0[4] = p510;
                    m0[9] = p1248;
                    fn_ovl_36a58(v0);
                }
            }

            {
                int st = *(int *)(ctx + 2836);
                m0[0] = (u8 *)(st << 8) + (int)ctx + 32;
                m0[1] = g_ovl_dat_788;
                m0[2] = ctx + st * 336 + 1488;
                m0[3] = g_ovl_ptr_3af7c;
                m0[4] = g_ovl_dat_3af50;
                m0[5] = 0;
                fn_ovl_38bb8(m0);
            }
        }

        *(int *)(ctx + 2836) += 1;
        if (*(int *)(ctx + 2836) >= 4) {
            m_end = arg[0];
            fn_ovl_39c10(&m_end);
        }
    }
}
