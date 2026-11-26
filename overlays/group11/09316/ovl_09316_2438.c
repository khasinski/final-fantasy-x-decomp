typedef unsigned char u8;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x20];
    int timer;
} Ovl9316Ctx;

extern void func_01B0CDF0(void *);

void ovl_09316_2438(void **arg)
{
    Ovl9316Ctx *ctx = (Ovl9316Ctx *)arg[1];
    void *m_end;

top:
    switch (ctx->state) {
    case 0:
        ctx->timer = 0x5A;
        ctx->state += 1;
        break;
    case 1:
        if (ctx->timer > 0) {
            break;
        }
        ctx->state = 10000;
        goto top;
    case 10000:
        m_end = arg[0];
        func_01B0CDF0(&m_end);
        break;
    }
    ctx->timer -= 1;
}
