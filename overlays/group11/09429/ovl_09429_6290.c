typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 h00;
    u16 h02;
    signed char b04;
    u8 pad05[0x03];
} OvlFrame;

typedef struct {
    u8 pad00[0x06];
    s16 count;
    u8 pad08[0x08];
    OvlFrame frames[1];
} OvlAnimData;

typedef struct {
    OvlAnimData *data;
    int playing;
    s16 frame;
    s16 timer;
} OvlAnim;

typedef struct {
    u8 pad00[0x10];
    OvlAnim anim;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    int w30;
    int w34;
    int w38;
    int w3C;
    int w40;
    int w44;
    int w48;
    int w4C;
    int w50;
    int w54;
    union {
        u32 word;
        u8 rgba[4];
    } col0;
    union {
        u32 word;
        u8 rgba[4];
    } col1;
    int active;
    u16 flags;
    u8 pad66[0x0A];
} OvlPart;

typedef struct {
    u8 pad00[0x04];
    union {
        u32 word;
        u8 rgba[4];
    } col;
    u8 pad08[0x08];
    float *mtx;
    int w14;
    u8 pad18[0x04];
    float *mtx2;
} OvlDrawCtx;

extern OvlPart *g_b5fc;
extern int g_b604;
extern int g_b608;
extern OvlDrawCtx g_0930;

extern void func_01B02F20(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_01B01CF0(int, int, void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern int func_002CD590(void *, void *);

void ovl_09429_6290(void)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[16];
    float m4[16];
    float v140[4];
    OvlPart *p;
    OvlDrawCtx *ctx;
    int i;
    int count;

    p = g_b5fc;
    count = 0;
    func_01B02F20(m1, m2);
    ctx = &g_0930;
    ctx->mtx = m3;
    func_002DD128(m0);

    for (i = 0; i < g_b604; i++, p++) {
        float scale;
        float *angp;
        float ang;
        OvlAnim *anim;
        OvlAnimData *adata;
        OvlFrame *fr;
        int flag;

        if (p->active == 0) {
            continue;
        }
        count++;
        if (p->w54 > 0) {
            p->w54--;
            continue;
        }
        scale = p->f1C;
        if (p->w44 > 0) {
            float t = (float)p->w50 / (float)p->w44;
            float s = p->f20 * (1.0f - t) + t;
            p->w50++;
            scale *= s;
            if (p->w50 > p->w44) {
                p->w44 = 0;
                p->w50 = 0;
            }
        } else if (p->w48 > 0) {
            p->w50++;
            if (p->w50 > p->w48) {
                p->w48 = 0;
                p->w50 = 0;
            }
        } else if (p->w4C > 0) {
            float f20 = p->f20;
            float t = (float)p->w50 / (float)p->w4C;
            float s = (1.0f - t) + f20 * t;
            p->w50++;
            scale *= s;
            if (p->w50 > p->w4C) {
                p->w4C = 0;
            }
        } else {
            scale *= p->f20;
        }

        m0[10] = scale;
        m0[5] = scale;
        m0[0] = scale;

        {
            float d = p->f2C;
            angp = &p->f28;
            ang = *angp + d;
            if (ang > 3.1415927f) {
                ang -= 6.2831855f;
            } else if (ang < -3.1415927f) {
                ang += 6.2831855f;
            }
            *angp = ang;
        }

        func_002DD1C8(m3, m0, p->f28);
        func_01B01CF0(p->w30, p->w34, (p->flags & 2) ? (void *)p : 0, v140);
        func_002DCE08(&m3[12], m2, v140);

        ctx->mtx2 = 0;
        if (p->flags & 1) {
            func_002DD0C0(m4, m3);
            m4[14] += p->f24;
            func_002DCE38(m4, m1, m4);
            ctx->mtx2 = m4;
        }
        func_002DCE38(m3, m1, m3);

        if (p->w3C > 0) {
            int t = p->w40;
            if (t < 0) t = -t;
            ctx->col.rgba[0] = (p->col1.rgba[0] * t + p->col0.rgba[0] * (p->w3C - t)) / p->w3C;
            ctx->col.rgba[1] = (p->col1.rgba[1] * t + p->col0.rgba[1] * (p->w3C - t)) / p->w3C;
            ctx->col.rgba[2] = (p->col1.rgba[2] * t + p->col0.rgba[2] * (p->w3C - t)) / p->w3C;
            ctx->col.rgba[3] = (p->col1.rgba[3] * t + p->col0.rgba[3] * (p->w3C - t)) / p->w3C;
            if (++p->w40 > p->w3C) {
                p->w3C = 0;
            }
        } else {
            ctx->col.word = p->col1.word;
        }

        anim = &p->anim;
        adata = anim->data;
        fr = &adata->frames[anim->frame];
        {
            u16 prev = *(u16 *)&anim->frame;
            if (anim->playing) {
                anim->timer -= 0x200;
                if (anim->timer <= 0) {
                    anim->frame = prev + 1;
                    if (anim->frame >= adata->count) {
                        if (fr->b04 & 0x80) {
                            anim->frame = 0;
                        } else {
                            anim->frame = prev;
                            anim->playing = 0;
                            goto done_anim;
                        }
                    }
                    fr = &adata->frames[anim->frame];
                    anim->timer = fr->h02;
                }
            }
        }
done_anim:

        if (p->w38 >= 0) {
            flag = 1;
        } else {
            flag = p->anim.playing;
        }
        if (flag == 1) {
            ctx->w14 = func_002CD590((u8 *)adata + fr->h00, ctx);
        } else {
            p->w38 = 1;
        }

        if (p->w38 > 0) {
            if (--p->w38 == 0) {
                p->active = 0;
            }
        }
    }
    g_b608 = count;
}
