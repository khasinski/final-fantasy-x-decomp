/* Overlay 09559: rank 512 camera keyframe setter (0x01B06878..0x01B06918). */
#include "common.h"

typedef struct Keyframe {
    void *unk00;
    int unk04;
    void *unk08;
    int unk0C;
    void *unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    int unk24;
} Keyframe;

void func_01B064E8(void *, int, int);
void func_01B06558(void *, void *, int, int);
void func_01B065D8(void *, int, int);
void func_01B06648(void *, void *, int, int);
void func_01B06730(void *, void *, int, int);
void func_01B067A8(float, float, int);
void func_01B06810(float, float, int);

void func_01B06878(Keyframe *a0) {
    if (a0->unk10 == 0) {
        func_01B064E8(a0->unk00, a0->unk04, a0->unk24);
        func_01B065D8(a0->unk08, a0->unk0C, a0->unk24);
        func_01B067A8(a0->unk14, a0->unk18, a0->unk24);
    } else {
        func_01B06558(a0->unk00, a0->unk10, a0->unk04, a0->unk24);
        func_01B06648(a0->unk08, a0->unk10, a0->unk0C, a0->unk24);
        func_01B06730(&a0->unk14, a0->unk10, 2, a0->unk24);
    }
    func_01B06810(a0->unk1C, a0->unk20, a0->unk24);
}
