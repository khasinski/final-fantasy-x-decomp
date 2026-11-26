typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned char pad[0x3C];
} Entry09168;

typedef struct {
    unsigned char pad[0xB4];
    void *pB4;
} Obj09168;

extern void *D_01B003F8[10];
extern Entry09168 D_01B00420[];
extern void *D_01B00520;
extern void func_01B00F98(void);
extern void func_00268610(void *, void **);

void func_01B01298(Obj09168 *a0, void *a1, int a2, int a3)
{
    int i;
    register Entry09168 *p __asm__("$6");

    for (i = 0; i < 10; i++) {
        D_01B003F8[i] = 0;
    }

    p = D_01B00420;
    if (p->unk0 != 0xFFFF) {
        do {
            if (p->unk2 == a3) {
                if (p->unk0 == a2) {
                    int sh = a3 << 2;
                    __asm__("" : "+r"(sh) : "r"(p));
                    *(void **)((char *)D_01B003F8 + sh) = (void *)func_01B00F98;
                    break;
                }
            }
            p++;
        } while (p->unk0 != 0xFFFF);
    }

    {
        register void *r_a1 __asm__("$5") = a1;
        void *p520 = &D_01B00520;
        __asm__("" : "+r"(r_a1) : "r"(p520));
        D_01B00520 = r_a1;
        a0->pB4 = p520;
        func_00268610(r_a1, D_01B003F8);
    }
}
