/* EE Battle-Effect Overlay: group 0x11, file 09188
 * .text: 0x01B020F8..0x01B02818 (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9188;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9188 *eff;           /* 0x04 */
} Eff9188CbArg;

typedef struct {
    u8 pad00[0xA0];
} P6ChrSlot;

typedef struct {
    P6Node node;            /* 0x000 */
    u8 pad1C[4];            /* 0x01C */
    P6ChrSlot slots[8];     /* 0x020 */
    int count;              /* 0x520 */
} P6ChrGroup;

typedef struct {
    u8 pad00[0x34];
    float off_y;            /* 0x34 */
    u8 pad38[0x0C];
    u8 mode;                /* 0x44 */
    u8 pad45[0x0B];
} P6PosNode50;

typedef struct {
    u8 pad00[0x14C];
    u8 b14C;                /* 0x14C */
    u8 pad14D[3];
} P6Obj150B;

typedef struct {
    u8 pad00[0x20];
    float f20;              /* 0x20 */
    float f24;              /* 0x24 */
    float f28;              /* 0x28 */
    float f2C;              /* 0x2C */
    float f30;              /* 0x30 */
    float f34;              /* 0x34 */
    float f38;              /* 0x38 */
    float f3C;              /* 0x3C */
} P6Fade9188;

typedef struct {
    void *w00;
    void *w04;
    int w08;
    void *w0C;
    u8 b10;
} ArgChrGrp;

typedef struct {
    void *w00;
    int w04;
    float f08;
    float f0C;
} ArgFade;

typedef struct {
    void *w00;
    void *w04;
    void *w08;
    void *w0C;
    void *w10;
    void *w14;
} Arg6;

typedef struct {
    void *w00;
    void *w04;
    void *w08;
    void *w0C;
    void *w10;
    int w14;
} ArgMot;

extern void *D_01B00500;
extern int D_01B00504;
extern u8 D_01B00630[];
extern u8 D_01B00690[];
extern u8 D_01B006C0[];
extern P6Node D_01B008E8;
extern P6Node D_01B00908;
extern P6ChrGroup D_01B00930;
extern P6Node30 D_01B00E70;
extern P6Node30 D_01B00EA0;
extern P6Node30 D_01B00ED0;
extern P6Node30 D_01B00F00;
extern P6PosNode50 D_01B00F30;
extern P6PosNode50 D_01B00F80;
extern P6PosNode50 D_01B00FD0;
extern P6Obj150B D_01B01020;
extern P6Obj150B D_01B01170;
extern P6Obj150B D_01B012C0;
extern P6Obj150B D_01B01410;
extern u8 D_01B01560[];
extern u8 D_01B01660[];
extern u8 D_01B01760[];
extern u8 D_01B01860[];
extern P6Fade9188 D_01B01960;
extern u8 D_01B01A20[];
extern float D_01B0DCA0;
extern u8 D_01B0DCA8[];
extern void *D_01B0DCD4;

extern void func_01B02BA0(void *);
extern void func_01B06EF0(void *);
extern void func_01B07020(void *);
extern void func_01B07100(void *);
extern void func_01B07BA8(void *);
extern void func_01B08078(void *);
extern void func_01B097A0(void *);
extern void func_01B0B058(void *);
extern void func_01B0B090(void *);
extern void func_01B0B900(void *);
extern void func_01B0C958(void *);

void func_01B020F8(Eff9188CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgFade fade;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9188 *eff = arg->eff;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

retry:
    switch (eff->state) {
        case 0:
            {
                /* DEBT(FAKE): match ee-gcc CSE of constant 1 into s2 across calls */
                register int one __asm__("$18");
            msg.grp.w00 = &D_01B00930;
            msg.grp.w04 = &D_01B008E8;
            msg.grp.w08 = D_01B00504;
            msg.grp.w0C = 0;
            one = 1;
            msg.grp.b10 = one;
            func_01B02BA0(&msg);

            msg.p[0] = &D_01B01960;
            msg.p[1] = &D_01B008E8;
            func_01B06EF0(&msg);
            D_01B01960.f20 = 1.0f;
            D_01B01960.f24 = 1.0f;
            D_01B01960.f28 = 1.0f;
            D_01B01960.f2C = 1.0f;
            D_01B01960.f3C = 1.0f / 3.0f;
            D_01B01960.f38 = 1.0f / 3.0f;
            D_01B01960.f34 = 1.0f / 3.0f;
            D_01B01960.f30 = 1.0f / 3.0f;
            msg.fade.w00 = &D_01B01960;
            msg.fade.w04 = one;
            msg.fade.f08 = 0.03f;
            func_01B07020(&msg);

            eff->state = 10;
            }
            /* fallthrough */
        case 10:
            {
                P6ChrGroup *grp = &D_01B00930;
                P6PosNode50 *pos = &D_01B00F30;
                P6Obj150B *xf = &D_01B01020;
                P6Node30 *scl = &D_01B00E70;
                u8 *ppp = D_01B01560;

                void *slot = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;

                msg.p[0] = pos;
                msg.p[1] = &D_01B008E8;
                msg.p[2] = slot;
                func_01B08078(&msg);
                pos->mode = 0;
                pos->off_y = -26.0f;

                msg.p[0] = scl;
                msg.p[1] = &D_01B008E8;
                func_01B07BA8(&msg);
                scl->v.x = 1.0f;
                scl->v.y = 1.0f;
                scl->v.z = 1.0f;
                scl->v.w = 1.5f;

                msg.a6.w00 = xf;
                msg.a6.w04 = &D_01B008E8;
                msg.a6.w08 = D_01B006C0;
                msg.a6.w0C = pos;
                msg.a6.w10 = D_01B00690;
                msg.a6.w14 = scl;
                func_01B097A0(&msg);
                xf->b14C = 1;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B00908;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCD4;
                msg.a6.w10 = D_01B0DCA8;
                msg.a6.w14 = (void *)3;
                func_01B0B900(&msg);

                msg.mot.w00 = D_01B01A20;
                msg.mot.w04 = &D_01B008E8;
                msg.mot.w08 = xf;
                msg.mot.w0C = D_01B00630;
                msg.mot.w10 = D_01B00500;
                msg.mot.w14 = 0;
                func_01B0B090(&msg);

                msg.p[0] = D_01B01A20;
                msg.p[1] = 0;
                func_01B0B058(&msg);

                eff->frame = 0;
                eff->state++;
            }
            /* fallthrough */
        case 11:
            if (eff->frame > 19) {
                eff->state = 20;
                goto retry;
            }
            break;
        case 20:
            {
                P6ChrGroup *grp = &D_01B00930;
                P6PosNode50 *pos = &D_01B00F80;
                P6Obj150B *xf = &D_01B01170;
                P6Node30 *scl = &D_01B00EA0;
                u8 *ppp = D_01B01660;

                void *slot = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;

                msg.p[0] = pos;
                msg.p[1] = &D_01B008E8;
                msg.p[2] = slot;
                func_01B08078(&msg);
                pos->mode = 4;
                pos->off_y = D_01B0DCA0;

                msg.p[0] = scl;
                msg.p[1] = &D_01B008E8;
                func_01B07BA8(&msg);
                scl->v.x = 1.0f;
                scl->v.y = 1.0f;
                scl->v.z = 1.0f;
                scl->v.w = 1.0f;

                msg.a6.w00 = xf;
                msg.a6.w04 = &D_01B008E8;
                msg.a6.w08 = D_01B006C0;
                msg.a6.w0C = pos;
                msg.a6.w10 = D_01B00690;
                msg.a6.w14 = scl;
                func_01B097A0(&msg);
                xf->b14C = 1;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B00908;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCD4;
                msg.a6.w10 = D_01B0DCA8;
                msg.a6.w14 = 0;
                func_01B0B900(&msg);

                eff->frame = 0;
                eff->state++;
            }
            /* fallthrough */
        case 21:
            if (eff->frame > 24) {
                eff->state = 30;
                goto retry;
            }
            break;
        case 30:
            {
                P6ChrGroup *grp = &D_01B00930;
                P6PosNode50 *pos = &D_01B00FD0;
                P6Obj150B *xf = &D_01B012C0;
                P6Node30 *scl = &D_01B00ED0;
                u8 *ppp = D_01B01760;

                void *slot = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;

                msg.p[0] = pos;
                msg.p[1] = &D_01B008E8;
                msg.p[2] = slot;
                func_01B08078(&msg);
                pos->mode = 3;
                pos->off_y = -1.5f;

                msg.p[0] = scl;
                msg.p[1] = &D_01B008E8;
                func_01B07BA8(&msg);
                scl->v.x = 1.0f;
                scl->v.y = 1.0f;
                scl->v.z = 1.0f;
                scl->v.w = 1.2f;

                msg.a6.w00 = xf;
                msg.a6.w04 = &D_01B008E8;
                msg.a6.w08 = D_01B006C0;
                msg.a6.w0C = pos;
                msg.a6.w10 = D_01B00690;
                msg.a6.w14 = scl;
                func_01B097A0(&msg);
                xf->b14C = 1;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B00908;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCD4;
                msg.a6.w10 = D_01B0DCA8;
                msg.a6.w14 = (void *)1;
                func_01B0B900(&msg);

                eff->frame = 0;
                eff->state++;
            }
            /* fallthrough */
        case 31:
            if (eff->frame > 29) {
                eff->state = 40;
                goto retry;
            }
            break;
        case 40:
            {
                P6Node30 *scl = &D_01B00F00;
                P6Obj150B *xf = &D_01B01410;
                P6PosNode50 *pos = &D_01B00F80;
                u8 *ppp = D_01B01860;

                msg.p[0] = scl;
                msg.p[1] = &D_01B008E8;
                func_01B07BA8(&msg);
                scl->v.x = 1.0f;
                scl->v.y = 1.0f;
                scl->v.z = 1.0f;
                scl->v.w = 1.0f;

                msg.a6.w00 = xf;
                msg.a6.w04 = &D_01B008E8;
                msg.a6.w08 = D_01B006C0;
                msg.a6.w0C = pos;
                msg.a6.w10 = D_01B00690;
                msg.a6.w14 = scl;
                func_01B097A0(&msg);
                xf->b14C = 1;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B00908;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCD4;
                msg.a6.w10 = D_01B0DCA8;
                msg.a6.w14 = (void *)2;
                func_01B0B900(&msg);

                eff->frame = 0;
                eff->state++;
            }
            /* fallthrough */
        case 41:
            if (eff->frame > 24) {
                D_01B01960.f30 = 1.0f;
                D_01B01960.f34 = 1.0f;
                D_01B01960.f38 = 1.0f;
                D_01B01960.f3C = 1.0f;
                msg.fade.w00 = &D_01B01960;
                msg.fade.w04 = 0;
                msg.fade.f08 = 0.025f;
                msg.fade.f0C = 1.0f;
                func_01B07100(&msg);
                eff->state = 10000;
                goto retry;
            }
            break;
        case 42:
            if (eff->frame > 64) {
                eff->state = 10000;
                goto retry;
            }
            break;
        case 10000:
            {
                void *end_msg[1];
                end_msg[0] = arg->obj;
                func_01B0C958(end_msg);
            }
            break;
    }
    eff->frame++;
}
