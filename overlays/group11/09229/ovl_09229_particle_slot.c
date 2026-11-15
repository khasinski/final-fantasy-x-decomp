/* Find the first unused particle slot. */
typedef struct Particle {
    float position[4];
    float scale;
    unsigned short age;
    short index;
    unsigned char reserved[8];
} Particle;
extern Particle D_01D01EE0[128];

Particle *func_01B00B70(void)
{
    int i;
    Particle *p = D_01D01EE0;
    for (i = 0; i < 128; i++, p++) {
        if (p->index == -1)
            return p;
    }
    return 0;
}
