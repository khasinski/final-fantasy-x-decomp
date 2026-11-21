/* EE Battle-Effect Overlay: group 0x11, file 09048
 * .text: 0x01B02D08..0x01B03054 (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9048;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9048 *eff;           /* 0x04 */
} Eff9048CbArg;

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
extern P6Node30 D_01B00E40[8];
extern P6PosNode50 D_01B00FC0[8];
extern P6Obj150B D_01B01240[8];
extern PppSlot D_01B01CC0[8];
extern MotSlot D_01B024C0[8];
extern u8 D_01B0D820[];
extern void *D_01B0D84C;

extern void func_01B033E0(void *);
extern void func_01B040D0(void *);
extern void func_01B07730(void *);
extern void func_01B07C00(void *);
extern void func_01B09328(void *);
extern void func_01B0ABE0(void *);
extern void func_01B0AC18(void *);
extern void func_01B0B488(void *);
extern void func_01B0C4E0(void *);

void func_01B02D08(Eff9048CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgRotF rot;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9048 *eff = arg->eff;

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
        func_01B033E0(&msg);
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
            P6ChrGroup *grp = &D_01B00900;
            P6PosNode50 *pos = &D_01B00FC0[i];
            P6Obj150B *xf = &D_01B01240[i];
            P6Node30 *scl = &D_01B00E40[i];
            PppSlot *ppp = &D_01B01CC0[i];

            msg.p[0] = pos;
            msg.p[1] = &D_01B008B8;
            msg.p[2] = ((u8 *)grp + i * sizeof(P6ChrSlot)) + 0x20;
            func_01B07C00(&msg);
            pos->mode = 3;
            pos->off_y = -2.5f;

            msg.p[0] = scl;
            msg.p[1] = &D_01B008B8;
            func_01B07730(&msg);

            msg.rot.w00 = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
            msg.rot.w04 = &scl->v;
            msg.rot.f08 = 1.0f;
            msg.rot.f0C = 20.0f;
            func_01B040D0(&msg);
            scl->v.w *= 0.135f;

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B008B8;
            msg.a6.w08 = D_01B00690;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B00660;
            msg.a6.w14 = scl;
            func_01B09328(&msg);
            xf->b14C = 1;

            msg.a6.w00 = ppp;
            msg.a6.w04 = &D_01B008D8;
            msg.a6.w08 = xf;
            msg.a6.w0C = D_01B0D84C;
            msg.a6.w10 = D_01B0D820;
            msg.a6.w14 = 0;
            func_01B0B488(&msg);

            msg.mot.w00 = &D_01B024C0[eff->idx];
            msg.mot.w04 = &D_01B008B8;
            msg.mot.w08 = xf;
            msg.mot.w0C = D_01B00600;
            msg.mot.w10 = D_01B004D8;
            msg.mot.w14 = 0;
            func_01B0AC18(&msg);

            msg.p[0] = &D_01B024C0[eff->idx];
            msg.p[1] = 0;
            func_01B0ABE0(&msg);

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
            func_01B0C4E0(end_msg);
        }
        break;
    }
    eff->frame++;
}
