/* Battle-effect overlay 09345: 0x01B00648..0x01B00A20 */
#include "rcef_overlay.h"
#include "vu0.h"

extern float D_01B01970[4][4];
extern int D_01B019B0[2];

void func_001A40E0(int chr, int bone, float *out);
float rcVec3fLength(Vec4 *v);
void func_001A2E80(int chr, int idx, float *out_mat);
int func_002EFD78(void);

void func_01B00A20(W3Task *t);

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_SCALE_BITS(d, s, bits) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tqmtc2 %2, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(s), "r"(bits) : "memory")

#define RAND_SCALE() ((float)func_002EFD78() * 4.6566128730773926e-10f * 0.4f + 1.0f)

void func_01B00648(W3Task *t)
{
    float p0[4];
    float p1[4];
    float vx[4];
    float vx2[4];
    float vz[4];
    float vz2[4];
    float mat[4][4];
    int caster = D_00313CB0.caster;
    int t0 = D_00313CB0.targets[0];
    int t1 = D_00313CB0.targets[D_00313CB0.target_count - 1];
    float half_len;
    float r;

    func_001A40E0(caster, 0x18, p0);
    func_001A40E0(caster, 0x25, p1);
    VEC3_SUB(p0, p0, p1);
    half_len = rcVec3fLength((Vec4 *)p0) * 0.5f;

    func_001A2E80(t0, 0, &mat[0][0]);
    D_01B019B0[0] = t0;
    VEC3_SCALE(vx, mat[0], half_len);
    VEC3_SCALE(vz, mat[2], -20.0f);
    r = RAND_SCALE();
    VEC3_SCALE(vx2, vx, r);
    r = RAND_SCALE();
    VEC3_SCALE(vx, vx, r);
    r = RAND_SCALE();
    VEC3_SCALE(vz2, vz, r);
    r = RAND_SCALE();
    VEC3_SCALE(vz, vz, r);
    VEC3_ADD(D_01B01970[0], vz, mat[3]);
    VEC3_SUB(D_01B01970[0], D_01B01970[0], vx);
    VEC3_ADD(D_01B01970[1], vx2, vz2);
    VEC3_ADD(D_01B01970[1], D_01B01970[1], mat[3]);

    func_001A2E80(t1, 0, &mat[0][0]);
    D_01B019B0[1] = t1;
    VEC3_SCALE(vx, mat[0], half_len);
    VEC3_SCALE(vz, mat[2], -20.0f);
    r = RAND_SCALE();
    VEC3_SCALE(vx2, vx, r);
    r = RAND_SCALE();
    VEC3_SCALE(vx, vx, r);
    r = RAND_SCALE();
    VEC3_SCALE(vz2, vz, r);
    r = RAND_SCALE();
    VEC3_SCALE(vz, vz, r);
    VEC3_ADD(D_01B01970[2], vz, mat[3]);
    VEC3_SUB(D_01B01970[2], D_01B01970[2], vx);
    VEC3_ADD(D_01B01970[3], vx2, vz2);
    VEC3_ADD(D_01B01970[3], D_01B01970[3], mat[3]);

    func_001A1D08(t, func_01B00A20);
    func_001A1D50(t, func_001A2058);
}
