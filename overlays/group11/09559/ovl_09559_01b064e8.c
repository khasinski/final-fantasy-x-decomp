/* Overlay 09559: rank 89 wrappers around control track/ramp setters (0x01B064E8..0x01B06810). */
#include "common.h"

typedef struct Control {
    u8 pad0[0x18C];
    s16 counter;
    s16 pad18E;
} Control;

Control *func_01B02810(int);
void func_01B02928(Control *, int, void *, int, int);
void func_01B029B0(Control *, int, void *, void *, int, int);
void func_01B02C48(Control *, float, float, int);
void func_01B02C80(Control *, void *, int, int);
void func_01B02CC8(Control *, void *, void *, int, int);

void func_01B064E8(void *a0, int a1, int a2) {
    func_01B02928(func_01B02810(0), 0, a0, a1, a2 - func_01B02810(0)->counter);
}

void func_01B06558(void *a0, void *a1, int a2, int a3) {
    func_01B029B0(func_01B02810(0), 0, a0, a1, a2, a3 - func_01B02810(0)->counter);
}

void func_01B065D8(void *a0, int a1, int a2) {
    func_01B02928(func_01B02810(0), 1, a0, a1, a2 - func_01B02810(0)->counter);
}

void func_01B06648(void *a0, void *a1, int a2, int a3) {
    func_01B029B0(func_01B02810(0), 1, a0, a1, a2, a3 - func_01B02810(0)->counter);
}

void func_01B066C8(void *a0, int a1, int a2) {
    func_01B02C80(func_01B02810(0), a0, a1, a2 - func_01B02810(0)->counter);
}

void func_01B06730(void *a0, void *a1, int a2, int a3) {
    func_01B02CC8(func_01B02810(0), a0, a1, a2, a3 - func_01B02810(0)->counter);
}

void func_01B067A8(float a0, float a1, int a2) {
    func_01B02C48(func_01B02810(0), a0, a1, a2 - func_01B02810(0)->counter);
}
