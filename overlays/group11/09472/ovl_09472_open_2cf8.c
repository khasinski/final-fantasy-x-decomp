/* EE Battle-Effect Overlay: group 0x11, file 09472
 * .text: 0x01B02CF8..0x01B030E4 (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9472;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9472 *eff;           /* 0x04 */
} Eff9472CbArg;

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
    P6Node30 scl[8];        /* 0x000 */
    P6Node30 pos[8];        /* 0x180 */
} P6Nodes9472;

typedef struct {
    u8 pad00[0x14C];
    u8 b14C;                /* 0x14C */
    u8 pad14D[3];
} P6Obj150B;

typedef struct {
    u8 pad00[0x100];
} PppSlot;

typedef struct {
    u8 pad00[0x38];
} MotSlot;

typedef struct {
    u8 pad00[0x30];
    float f30;              /* 0x30 */
    float f34;              /* 0x34 */
    float f38;              /* 0x38 */
    u8 pad3C[0x24];
    float f60;              /* 0x60 */
    float f64;              /* 0x64 */
    float f68;              /* 0x68 */
    float f6C;              /* 0x6C */
} P6FadeObj;

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
extern P6Nodes9472 D_01B00E70;
extern P6Obj150B D_01B01170[8];
extern PppSlot D_01B01BF0[8];
extern MotSlot D_01B023F0[8];
extern P6FadeObj D_01B025B0;
extern u8 D_01B0DB00[];
extern void *D_01B0DB2C;

extern void func_01B03470(void *);
extern void func_01B04748(void *);
extern void func_01B077C0(void *);
extern void func_01B078F0(void *);
extern void func_01B079D0(void *);
extern void func_01B08478(void *);
extern void func_01B09600(void *);
extern void func_01B0AEB8(void *);
extern void func_01B0AEF0(void *);
extern void func_01B0B760(void *);
extern void func_01B0C7B8(void *);

void func_01B02CF8(Eff9472CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgFade fade;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9472 *eff = arg->eff;
    P6FadeObj *fade = &D_01B025B0;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

    switch (eff->state) {
    case 0:
        msg.grp.w00 = &D_01B00930;
        msg.grp.w04 = &D_01B008E8;
        msg.grp.w08 = D_01B00504;
        msg.grp.w0C = 0;
        msg.grp.b10 = 0;
        func_01B03470(&msg);

        msg.p[0] = fade;
        msg.p[1] = &D_01B00908;
        func_01B077C0(&msg);
        fade->f6C = 0.5f;
        fade->f68 = 0.5f;
        fade->f64 = 0.5f;
        fade->f60 = 0.5f;
        fade->f38 = 0.5f;
        fade->f34 = 0.5f;
        fade->f30 = 0.5f;
        msg.fade.w00 = fade;
        msg.fade.w04 = 0;
        msg.fade.f08 = 0.1f;
        func_01B078F0(&msg);

        eff->state = 10;
        /* fallthrough */
    case 10:
        eff->frame = 100;
        eff->state++;
        eff->idx = 0;
        /* fallthrough */
    case 11:
        if (eff->frame > 15) {
            int i = eff->idx;
            P6ChrGroup *grp = &D_01B00930;
            P6Node30 *pos = &D_01B00E70.pos[i];
            P6Node30 *scl = &D_01B00E70.scl[i];
            P6Obj150B *xf = &D_01B01170[i];
            PppSlot *ppp = &D_01B01BF0[i];

            msg.p[0] = pos;
            msg.p[1] = &D_01B008E8;
            func_01B08478(&msg);

            msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
            msg.p[1] = &pos->v;
            func_01B04748(&msg);
            pos->v.w = 1.0f;

            msg.p[0] = scl;
            msg.p[1] = &D_01B008E8;
            func_01B08478(&msg);
            scl->v.x = 1.0f;
            scl->v.y = 1.0f;
            scl->v.z = 1.0f;
            scl->v.w = 0.2f;

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B008E8;
            msg.a6.w08 = D_01B006C0;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B00690;
            msg.a6.w14 = scl;
            func_01B09600(&msg);
            xf->b14C = 1;

            msg.a6.w00 = ppp;
            msg.a6.w04 = &D_01B00908;
            msg.a6.w08 = xf;
            msg.a6.w0C = D_01B0DB2C;
            msg.a6.w10 = D_01B0DB00;
            msg.a6.w14 = 0;
            func_01B0B760(&msg);

            msg.mot.w00 = &D_01B023F0[eff->idx];
            msg.mot.w04 = &D_01B008E8;
            msg.mot.w08 = xf;
            msg.mot.w0C = D_01B00630;
            msg.mot.w10 = D_01B00500;
            msg.mot.w14 = 0;
            func_01B0AEF0(&msg);

            msg.p[0] = &D_01B023F0[eff->idx];
            msg.p[1] = 0;
            func_01B0AEB8(&msg);

            eff->idx++;
            if (eff->idx >= grp->count) {
                eff->state++;
            }
            eff->frame = 0;
        }
        break;
    case 12:
        if (eff->frame > 80) {
            fade->f6C = 1.0f;
            fade->f68 = 1.0f;
            fade->f64 = 1.0f;
            fade->f60 = 1.0f;
            fade->f38 = 1.0f;
            fade->f34 = 1.0f;
            fade->f30 = 1.0f;
            msg.fade.w00 = fade;
            msg.fade.w04 = 0;
            msg.fade.f08 = 0.025f;
            msg.fade.f0C = 1.0f;
            func_01B079D0(&msg);
            eff->state = 10000;
        }
        break;
    case 10000:
        {
            void *end_msg[1];
            end_msg[0] = arg->obj;
            func_01B0C7B8(end_msg);
        }
        break;
    }
    eff->frame++;
}
