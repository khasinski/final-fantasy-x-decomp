/* Overlay 09559: rank 595 actor flag batch setter (0x01B04F10..0x01B04F88). */
#include "common.h"

typedef struct Actor {
    int id;
    u8 pad04[0xCC];
} Actor;

void func_001B5810(int, int);

void func_01B04F10(Actor *a0, int a1, int a2) {
    while (a1-- != 0) {
        if (a0->id != 0xFF) {
            func_001B5810(a0->id, a2);
        }
        a0++;
    }
}
