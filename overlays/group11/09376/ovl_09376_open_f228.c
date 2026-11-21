/* EE Battle-Effect Overlay: group 0x11, file 09376
 * .text: 0x01B0F228..0x01B0F558 (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9376;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9376 *eff;           /* 0x04 */
} Eff9376CbArg;

typedef struct {
    u8 pad00[0x54];
    int chr_id;             /* 0x54 (offset 116 from group base) */
    u8 pad58[0x48];
} P6ChrSlot;

typedef struct {
    P6Node node;            /* 0x0000 */
    u8 pad1C[4];            /* 0x001C */
    P6ChrSlot slots[64];    /* 0x0020 */
    int count;              /* 0x2820 */
} P6ChrGroup64;

typedef struct {
    P6Node30 scl[64];       /* 0x0000 (0x01B031C0) */
    P6Node30 pos[64];       /* 0x0C00 (0x01B03DC0) */
} P6Nodes9376;

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

extern void *D_01B00550;
extern int D_01B00554;
extern u8 D_01B00680[];
extern u8 D_01B006E0[];
extern u8 D_01B00710[];
extern P6Node D_01B00938;
extern P6Node D_01B00958;
extern P6ChrGroup64 D_01B00980;
extern P6Nodes9376 D_01B031C0;
extern P6Obj150B D_01B049C0[64];
extern PppSlot D_01B09DC0[64];
extern MotSlot D_01B0DDC0[64];
extern u8 D_01B192B0[];
extern void *D_01B192DC;

extern void func_001C5E90(int, int, int);
extern void func_01B0F8E0(void *);
extern void func_01B10BB8(void *);
extern void func_01B13C30(void *);
extern void func_01B14DB8(void *);
extern void func_01B16670(void *);
extern void func_01B166A8(void *);
extern void func_01B16F18(void *);
extern void func_01B17F70(void *);

void func_01B0F228(Eff9376CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9376 *eff = arg->eff;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

    switch (eff->state) {
    case 0:
        msg.grp.w00 = &D_01B00980;
        msg.grp.w04 = &D_01B00938;
        msg.grp.w08 = D_01B00554;
        msg.grp.w0C = 0;
        msg.grp.b10 = 1;
        func_01B0F8E0(&msg);
        eff->state = 10;
        /* fallthrough */
    case 10:
        eff->frame = 25;
        eff->state++;
        eff->idx = 0;
        /* fallthrough */
    case 11:
        if (eff->frame > 25) {
            int i = eff->idx;
            P6ChrGroup64 *grp = &D_01B00980;
            P6Obj150B *xf = &D_01B049C0[i];
            P6Node30 *pos = &D_01B031C0.pos[i];
            P6Node30 *scl = &D_01B031C0.scl[i];
            PppSlot *ppp = &D_01B09DC0[i];

            func_001C5E90(D_01B00554, *(int *)(((u8 *)grp + i * sizeof(P6ChrSlot)) + 0x74), 0);

            msg.p[0] = pos;
            msg.p[1] = &D_01B00938;
            func_01B13C30(&msg);

            msg.p[0] = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
            msg.p[1] = &pos->v;
            func_01B10BB8(&msg);

            msg.p[0] = scl;
            msg.p[1] = &D_01B00938;
            func_01B13C30(&msg);

            scl->v.x = 1.0f;
            scl->v.y = 1.0f;
            scl->v.z = 1.0f;
            scl->v.w = 0.3f;

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B00938;
            msg.a6.w08 = D_01B00710;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B006E0;
            msg.a6.w14 = scl;
            func_01B14DB8(&msg);
            xf->b14C = 1;

            msg.a6.w00 = ppp;
            msg.a6.w04 = &D_01B00958;
            msg.a6.w08 = xf;
            msg.a6.w0C = D_01B192DC;
            msg.a6.w10 = D_01B192B0;
            msg.a6.w14 = 0;
            func_01B16F18(&msg);

            msg.mot.w00 = &D_01B0DDC0[eff->idx];
            msg.mot.w04 = &D_01B00938;
            msg.mot.w08 = D_01B00680;
            msg.mot.w0C = xf;
            msg.mot.w10 = D_01B00550;
            msg.mot.w14 = 0;
            func_01B166A8(&msg);

            msg.p[0] = &D_01B0DDC0[eff->idx];
            msg.p[1] = 0;
            func_01B16670(&msg);

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
            func_01B17F70(end_msg);
        }
        break;
    }
    eff->frame++;
}
