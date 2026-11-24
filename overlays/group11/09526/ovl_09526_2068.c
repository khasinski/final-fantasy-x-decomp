typedef unsigned char u8;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x18];
    int w34;
} OvlState;

typedef struct {
    int w00;
    OvlState *p04;
} OvlTask;

extern int g_ovl_6c0;

extern int func_001D3A70(int);
extern void func_001CE050(int, int);
extern int func_001CE1A8(int);
extern void func_01B0D6D0(void *);

void ovl_09526_2068(OvlTask *task)
{
    int x;
    OvlState *st;

    st = task->p04;
retry:
    switch (st->state) {
    case 0:
        st->w34 = 10;
        st->state++;
    case 1:
        if (st->w34 <= 0) {
            st->state = 10;
            goto retry;
        }
        break;
    case 10:
        if (func_001D3A70(g_ovl_6c0) == 0x79) {
            func_001CE050(g_ovl_6c0, 0x7A);
        } else {
            func_001CE050(g_ovl_6c0, 0x8A);
        }
        st->state++;
        break;
    case 11:
        if (func_001CE1A8(g_ovl_6c0)) {
            x = task->w00;
            func_01B0D6D0(&x);
            st->state = 20000;
        }
        break;
    }
    st->w34--;
}
