#include "rcef_overlay.h"
#include "vu0.h"

#define VEC3_COPY(d, a) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(a) : "memory")
#define VEC3_ADD(d, a, b) \
    __asm__ volatile(".set noreorder\n\tlqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)\n\t.set reorder" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")
#define MFC1_NV(v, f) __asm__("mfc1 %0, %1" : "=r"(v) : "f"(f))

W3Task *func_0019FF90_t(RcefMainCtx *, W3TaskFn) __asm__("func_0019FF90");
void func_001A0000_m(RcefMainCtx *, RcefObj *, int) __asm__("func_001A0000");

extern float D_01B01AA0[3];
extern float D_01B01AAC;
extern float D_01B01AB0;
extern int D_01B01AB4;
extern int D_01B01AB8;

extern void func_01B00A78(W3Task *);
extern void func_01B01070(W3Task *);
extern void func_01B014D8(W3Task *);
extern void func_01B014E0(W3Task *);

extern void func_001A2F50(int, int, float *, float *);
extern float func_001A3620(int, float, float, float);
extern float func_002E8648(float);
extern float func_002E89C0(float);

void func_01B00B68(RcefObj *o, float ang, int idx, int count)
{
    float v0[4];
    float pos[4];
    float vel[4];
    float tmp[4];
    /* DEBT(FAKE): pin FP/temp regs and chain dependencies to match ee-gcc allocation/scheduling */
    register float ang_r __asm__("$f24") = ang;
    register float sc __asm__("$f20");
    register float rng_k __asm__("$f21");
    register float one_f __asm__("$f22");
    register float sc_v __asm__("$f23");
    register float *vel_p __asm__("$18");
    int inv_i;
    int t_i;
    float c;

    if (idx != 0) {
        ang_r += (float)func_002EFD78() * 4.6566128730773926e-10f * 0.34906584f - 0.17453292f;
    }
    vel[0] = -func_002E89C0(ang_r) * D_01B01AAC;
    vel[1] = D_01B01AB0;
    one_f = 1.0f;
    c = func_002E8648(ang_r);
    {
        register float f_inv __asm__("$f1") = (float)D_01B01AB8;
        float dist;
        __asm__("" : "+f"(f_inv), "+f"(c));
        dist = D_01B01AAC;
        c = -c;
        __asm__ volatile("" : "+f"(c), "+f"(dist));
        vel_p = vel;
        __asm__("" : "+r"(vel_p) : "f"(c), "f"(dist));
        f_inv = one_f / f_inv;
        __asm__("" : "+f"(c) : "f"(f_inv));
        vel[2] = c * dist;
        __asm__("" : "+f"(f_inv) : "m"(vel[2]));
        MFC1_NV(inv_i, f_inv);
    }
    VEC3_SCALE(vel_p, vel_p, inv_i);
    v0[0] = 0.0f;
    v0[1] = 0.0f;
    v0[2] = 0.0f;
    v0[3] = 0.0f;
    func_001A2F50(D_00313CB0.caster, 0x48, v0, pos);
    rng_k = 4.6566128730773926e-10f;
    {
        register float r0 __asm__("$f0") = (float)func_002EFD78();
        register float k360 __asm__("$f1") = 360.0f;
        r0 *= rng_k;
        ang_r = r0 * k360;
    }
    sc = (float)func_002EFD78();
    {
        register float k02 __asm__("$f3") = 0.2f;
        register float k014 __asm__("$f5") = 0.14f;
        register float f_cnt __asm__("$f0") = (float)count;
        register float k15 __asm__("$f4") = 1.5f;
        register float f_idx __asm__("$f1") = (float)idx;
        register float k05 __asm__("$f2");
        register float f_dur __asm__("$f6");
        register float *tmp_p __asm__("$2");
        __asm__("" : "+f"(k02) : "f"(sc));
        __asm__("" : "+f"(k014) : "f"(k02));
        __asm__("" : "+f"(f_cnt) : "f"(k014));
        __asm__("" : "+f"(k15) : "f"(f_cnt));
        __asm__("" : "+f"(f_idx) : "f"(k15));
        __asm__("" : "+f"(sc) : "f"(f_idx));
        sc = sc * rng_k;
        __asm__("" : "+f"(sc) : : "$f2", "$f6", "$2");
        k05 = 0.5f;
        __asm__("" : "+f"(k05) : "f"(sc));
        f_dur = (float)D_01B01AB8;
        __asm__("" : "+f"(f_dur) : "f"(k05));
        tmp_p = tmp;
        __asm__("" : "+r"(tmp_p) : "f"(f_dur));
        __asm__("" : "+f"(f_idx) : "r"(tmp_p));
        f_idx = f_idx / f_cnt;
        __asm__("" : "+f"(sc) : "f"(f_idx));
        sc *= k02;
        sc += k014;
        __asm__("" : "+f"(f_idx) : "f"(sc));
        MFC1_NV(t_i, f_idx);
        sc_v = sc * k15;
        sc = sc * k05;
        {
            register float diff __asm__("$f0") = sc_v - sc;
            sc_v = diff / f_dur;
        }
        VEC3_SCALE(tmp_p, vel_p, t_i);
        VEC3_ADD(pos, pos, tmp_p);
    }
    vel[1] -= ((float)func_002EFD78() * rng_k * 15.0f) / (float)D_01B01AB8;
    o->flagsBC |= 0x4000;
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    o->pos_w = 0;
    o->vel[0] = vel[0];
    o->vel[1] = vel[1];
    o->vel[2] = vel[2];
    o->vel[3] = 0.0f;
    o->rot[0] = 0.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = ang_r;
    o->rot_w = 0;
    o->scale[0] = sc;
    o->scale[1] = sc;
    o->scale[2] = sc;
    o->scale[3] = 0.0f;
    o->unk140[0] = sc_v;
    o->unk140[1] = sc_v;
    o->unk140[2] = sc_v;
    o->unk14C_w = 0;
    o->unk170[0] = 0.7f;
    o->unk170[1] = 1.1f;
    o->unk170[2] = one_f;
    o->unk170[3] = 0.4f;
    o->task.frame[o->task.sp].arg1 = idx;
    func_001A0000_m(&D_00313CB0, o, 0);
}

void func_01B00EA8(W3Task *t)
{
    float pos[4];
    float vel[4];
    float ang;
    RcefObj *o;
    int i;

    ang = func_001A3620(1, D_01B01AA0[2], D_01B01AA0[1], (float)D_01B01AB4 / 38.0f);
    if (D_01B01AB4 == 0) {
        func_0019FF90_t(&D_00313CB0, func_01B00A78);
    }
    o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014D8);
    func_01B00B68(o, ang, 0, 2);
    if ((D_01B01AB4 & 0xF) == 0) {
        VEC3_COPY(pos, o->pos);
        VEC3_COPY(vel, o->vel);
        o = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014E0);
        o->pos[0] = pos[0];
        o->pos[1] = pos[1];
        o->pos[2] = pos[2];
        /* DEBT(CAST): RcefObj::pos_w is typed int; float store keeps strict-aliasing order with pos[0..2] */
        *(float *)&o->pos_w = 0.0f;
        o->vel[0] = vel[0];
        o->vel[1] = vel[1];
        o->vel[2] = vel[2];
        o->vel[3] = 0.0f;
    }
    for (i = 1; i < 2; i++) {
        RcefObj *o3 = (RcefObj *)func_0019FF90_t(&D_00313CB0, func_01B014D8);
        func_01B00B68(o3, ang, i, 2);
    }
    D_01B01AB4++;
    if (D_01B01AB4 >= 38) {
        D_01B01AB4 = 0;
        func_001A1D08(t, func_01B01070);
    }
}
