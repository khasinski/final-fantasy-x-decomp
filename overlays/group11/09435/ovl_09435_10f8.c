#include "common.h"

extern void func_01B03F98(float *);
extern double sqrt(double);

int func_01B010F8(float *out, float *p1, float *p2, float radius)
{
    float center[4];
    float a, b, c;
    float ab2;
    float ac, bc;
    float disc1, disc2;
    /* DEBT(FAKE): pin float temporaries for exact register allocation */
    register float x1 __asm__("$f22");
    register float z1 __asm__("$f21");
    register float x2 __asm__("$f4");
    register float z2 __asm__("$f12");
    double db, da;

    func_01B03F98(center);
    a = p2[2] - p1[2];
    b = p1[0] - p2[0];
    c = p2[0] * p1[2] - p1[0] * p2[2];
    c += a * center[0] + b * center[2];
    ab2 = a * a + b * b;
    ac = a * c;
    bc = b * c;
    disc1 = ac * ac - ab2 * (c * c - b * b * radius * radius);
    disc2 = bc * bc - ab2 * (c * c - a * a * radius * radius);
    if (disc1 < 0.0f || disc2 < 0.0f) {
        return 0;
    }

    db = (double)b;
    if (db < 0.0) {
        db = -db;
    }
    da = (double)a;
    if (da < 0.0) {
        da = -da;
    }

    if (db >= da) {
        float neg_ac = -ac;
        register float t __asm__("$f0");
        x1 = (float)(((double)neg_ac + sqrt((double)disc1)) / (double)ab2);
        t = -(a * x1 + c);
        z1 = t / b;
        x2 = (float)(((double)neg_ac - sqrt((double)disc1)) / (double)ab2);
        t = -(a * x2 + c);
        z2 = t / b;
    } else {
        float neg_bc = -bc;
        register float t __asm__("$f0");
        z1 = (float)(((double)neg_bc + sqrt((double)disc2)) / (double)ab2);
        t = -(b * z1 + c);
        x1 = t / a;
        z2 = (float)(((double)neg_bc - sqrt((double)disc2)) / (double)ab2);
        t = -(b * z2 + c);
        x2 = t / a;
    }

    {
        register float cx __asm__("$f1") = center[0];
        register float cz __asm__("$f2") = center[2];
        x1 += cx;
        z1 += cz;
        z2 += cz;
        x2 += cx;
    }

    out[0] = x1;
    out[1] = 0.0f;
    out[2] = z1;
    out[3] = 1.0f;

    {
        register float f6 __asm__("$f6") = out[1];
        register float f2 __asm__("$f2") = p1[0];
        register float f0 __asm__("$f0") = p2[0];
        register float f3 __asm__("$f3") = x1 - f2;
        register float f5 __asm__("$f5") = p1[2];
        register float f1 __asm__("$f1");
        __asm__("" : "+f"(f6), "+f"(f2), "+f"(f0), "+f"(f3));
        __asm__("" : "+f"(f5));
        f0 = f0 - f2;
        __asm__("" : "+r"(out), "+r"(p1), "+r"(p2) : "f"(f0));
        f1 = p2[2];
        __asm__("" : "+f"(f1));
        f0 = f0 * f3;
        f1 = f1 - f5;
        if (f0 >= f6) {
            f0 = z1 - f5;
            if (f1 * f0 >= f6) {
                goto done;
            }
        }
        *(volatile float *)&out[2] = z2;
        *(volatile float *)&out[0] = x2;
    done:
        ;
    }

    if (disc1 == 0.0f && disc2 == 0.0f) {
        return 1;
    }
    return 2;
}
