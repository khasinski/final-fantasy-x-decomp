/* EE Battle-Effect Overlay: group 0x11, file 09052
 * .text: 0x01B02BE8..0x01B030BC (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9052;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9052 *eff;           /* 0x04 */
} Eff9052CbArg;

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
    P6Node30 scl[8];        /* 0x000 (0x01B00E40) */
    P6Node30 pos[8];        /* 0x180 (0x01B00FC0) */
} P6Nodes9052;

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
    void *w00;
    void *w04;
    int w08;
    void *w0C;
    u8 b10;
} ArgChrGrp;

typedef struct {
    void *w00;
    void *w04;
    float f08;
    float f0C;
} ArgRotF;

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

extern void *D_01B004D8;
extern int D_01B004DC;
extern u8 D_01B00600[];
extern u8 D_01B00660[];
extern u8 D_01B00690[];
extern P6Node D_01B008B8;
extern P6Node D_01B008D8;
extern P6ChrGroup D_01B00900;
extern P6Nodes9052 D_01B00E40;
extern P6Obj150B D_01B01140[8];
extern PppSlot D_01B01BC0[8];
extern MotSlot D_01B023C0[8];
extern u8 D_01B0CE20[];
extern void *D_01B0CE4C;

extern int func_001B4E18(int);
extern void func_01B03448(void *);
extern void func_01B04138(void *);
extern void func_01B04720(void *);
extern void func_01B04790(void *);
extern void func_01B07798(void *);
extern void func_01B08920(void *);
extern void func_01B0A1D8(void *);
extern void func_01B0A210(void *);
extern void func_01B0AA80(void *);
extern void func_01B0BAD8(void *);

void func_01B02BE8(Eff9052CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgRotF rot;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9052 *eff = arg->eff;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

    switch (eff->state) {
    case 0:
        msg.grp.w00 = &D_01B00900;
        msg.grp.w04 = &D_01B008B8;
        msg.grp.w08 = D_01B004DC;
        msg.grp.w0C = 0;
        msg.grp.b10 = 0;
        func_01B03448(&msg);
        eff->state = 10;
        /* fallthrough */
    case 10:
        eff->frame = 100;
        eff->state++;
        eff->idx = 0;
        /* fallthrough */
    case 11:
        if (eff->frame > 30) {
            P6Node30 *pos = &D_01B00E40.pos[eff->idx];
            P6Obj150B *xf = &D_01B01140[eff->idx];
            P6Node30 *scl = &D_01B00E40.scl[eff->idx];
            PppSlot *ppp = &D_01B01BC0[eff->idx];
            P6ChrGroup *grp = &D_01B00900;

            msg.p[0] = pos;
            msg.p[1] = &D_01B008B8;
            func_01B07798(&msg);

            msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
            msg.p[1] = &pos->v;
            func_01B04790(&msg);

            msg.p[0] = scl;
            msg.p[1] = &D_01B008B8;
            func_01B07798(&msg);

            msg.rot.w00 = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
            msg.rot.w04 = &scl->v;
            msg.rot.f08 = 1.0f;
            msg.rot.f0C = 18.0f;
            func_01B04138(&msg);

            switch (func_001B4E18(*(int *)(((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x74))) {
            case 0x3003:
                pos->v.y -= 3.0f;
                scl->v.w *= 0.0098f;
                break;
            case 0x3002:
                pos->v.y += 4.0f;
                scl->v.w *= 0.014f;
                break;
            case 0x3006:
                pos->v.y += 5.0f;
                scl->v.w *= 0.014f;
                break;
            case 0x3007:
                pos->v.y += 2.5f;
                scl->v.w *= 0.014f;
                break;
            case 0x108C:
                msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
                msg.p[1] = &pos->v;
                func_01B04720(&msg);
                pos->v.y += 2.5f;
                scl->v.w *= 0.014f;
                break;
            default:
                scl->v.w *= 0.014f;
                break;
            }

            if (scl->v.w < 0.1f) {
                scl->v.w = 0.1f;
            } else if (scl->v.w > 0.5f) {
                scl->v.w = 0.5f;
            }

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B008B8;
            msg.a6.w08 = D_01B00690;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B00660;
            msg.a6.w14 = scl;
            func_01B08920(&msg);
            xf->b14C = 1;

            msg.a6.w00 = ppp;
            msg.a6.w04 = &D_01B008D8;
            msg.a6.w08 = xf;
            msg.a6.w0C = D_01B0CE4C;
            msg.a6.w10 = D_01B0CE20;
            msg.a6.w14 = 0;
            func_01B0AA80(&msg);

            msg.mot.w00 = &D_01B023C0[eff->idx];
            msg.mot.w04 = &D_01B008B8;
            msg.mot.w08 = xf;
            msg.mot.w0C = D_01B00600;
            msg.mot.w10 = D_01B004D8;
            msg.mot.w14 = 0;
            func_01B0A210(&msg);

            msg.p[0] = &D_01B023C0[eff->idx];
            msg.p[1] = 0;
            func_01B0A1D8(&msg);

            eff->idx++;
            if (eff->idx >= grp->count) {
                eff->state = 10000;
            }
            eff->frame = 0;
        }
        break;
    case 10000:
        {
            void *end_msg[1];
            end_msg[0] = arg->obj;
            func_01B0BAD8(end_msg);
        }
        break;
    }
    eff->frame++;
}
