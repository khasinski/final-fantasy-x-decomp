/* EE Battle-Effect Overlay: group 0x11, file 09443
 * .text: 0x01B02D98..0x01B0327C (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9443;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9443 *eff;           /* 0x04 */
} Eff9443CbArg;

typedef struct {
    u8 pad00[0x54];
    int w54;                /* 0x54 */
    u8 pad58[0x48];
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
} P6Nodes9443;

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

extern void *D_01B005A0;
extern int D_01B005A4;
extern int D_01B005A8;
extern u8 D_01B006D0[];
extern u8 D_01B00730[];
extern u8 D_01B00760[];
extern P6Node D_01B00988;
extern P6Node D_01B009A8;
extern P6ChrGroup D_01B009D0;
extern P6Nodes9443 D_01B00F10;
extern P6Obj150B D_01B01210[8];
extern PppSlot D_01B01C90[8];
extern MotSlot D_01B02490[8];
extern P6FadeObj D_01B02650;
extern u8 D_01B0DC90[];
extern void *D_01B0DCBC;

extern int func_001C5E90(int, int, int);
extern int func_01B02A48(int);
extern void func_01B03608(void *);
extern void func_01B048E0(void *);
extern void func_01B04918(void *);
extern void func_01B07958(void *);
extern void func_01B07A88(void *);
extern void func_01B07B68(void *);
extern void func_01B08610(void *);
extern void func_01B09798(void *);
extern void func_01B0B050(void *);
extern void func_01B0B088(void *);
extern void func_01B0B8F8(void *);
extern void func_01B0C950(void *);

void func_01B02D98(Eff9443CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgFade fade;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9443 *eff = arg->eff;
    P6FadeObj *fade = &D_01B02650;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

    switch (eff->state) {
    case 0:
        msg.grp.w00 = &D_01B009D0;
        msg.grp.w04 = &D_01B00988;
        msg.grp.w08 = D_01B005A4;
        msg.grp.w0C = 0;
        msg.grp.b10 = 0;
        func_01B03608(&msg);

        msg.p[0] = fade;
        msg.p[1] = &D_01B009A8;
        func_01B07958(&msg);
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
        func_01B07A88(&msg);

        eff->state = 10;
        /* fallthrough */
    case 10:
        eff->frame = 100;
        eff->state++;
        eff->idx = 0;
        /* fallthrough */
    case 11:
        if (eff->frame > 25) {
            int i = eff->idx;
            P6ChrGroup *grp = &D_01B009D0;
            P6Node30 *pos = &D_01B00F10.pos[i];
            P6Node30 *scl = &D_01B00F10.scl[i];
            P6Obj150B *xf = &D_01B01210[i];
            PppSlot *ppp = &D_01B01C90[i];

            msg.p[0] = pos;
            msg.p[1] = &D_01B00988;
            func_01B08610(&msg);

            msg.p[0] = scl;
            msg.p[1] = &D_01B00988;
            func_01B08610(&msg);
            scl->v.x = 1.0f;
            scl->v.y = 1.0f;
            scl->v.z = 1.0f;
            scl->v.w = 1.0f;

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B00988;
            msg.a6.w08 = D_01B00760;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B00730;
            msg.a6.w14 = scl;
            func_01B09798(&msg);
            xf->b14C = 1;

            if (func_01B02A48(*(int *)(((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x74))) {
                msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
                msg.p[1] = &pos->v;
                func_01B048E0(&msg);
                pos->v.w = 1.0f;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B009A8;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCBC;
                msg.a6.w10 = D_01B0DC90;
                msg.a6.w14 = (void *)1;
                func_01B0B8F8(&msg);
            } else {
                msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
                msg.p[1] = &pos->v;
                msg.p[2] = (void *)1;
                func_01B04918(&msg);
                pos->v.y -= 0.2f;
                pos->v.w = 1.0f;

                msg.a6.w00 = ppp;
                msg.a6.w04 = &D_01B009A8;
                msg.a6.w08 = xf;
                msg.a6.w0C = D_01B0DCBC;
                msg.a6.w10 = D_01B0DC90;
                msg.a6.w14 = 0;
                func_01B0B8F8(&msg);
            }

            msg.mot.w00 = &D_01B02490[eff->idx];
            msg.mot.w04 = &D_01B00988;
            msg.mot.w08 = xf;
            msg.mot.w0C = D_01B006D0;
            msg.mot.w10 = D_01B005A0;
            msg.mot.w14 = 0;
            func_01B0B088(&msg);

            msg.p[0] = &D_01B02490[eff->idx];
            msg.p[1] = 0;
            func_01B0B050(&msg);

            eff->state++;
            eff->frame = 0;
        }
        break;
    case 12:
        if (eff->frame > 20) {
            P6ChrGroup *grp = &D_01B009D0;
            func_001C5E90(D_01B005A8, *(int *)(((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x74), 0);
            eff->idx++;
            if (eff->idx >= grp->count) {
                eff->state++;
            } else {
                eff->state--;
            }
        }
        break;
    case 13:
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
            func_01B07B68(&msg);
            eff->state = 10000;
        }
        break;
    case 10000:
        {
            void *end_msg[1];
            end_msg[0] = arg->obj;
            func_01B0C950(end_msg);
        }
        break;
    }
    eff->frame++;
}
