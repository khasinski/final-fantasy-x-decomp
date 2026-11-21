/* EE Battle-Effect Overlay: group 0x11, file 09377
 * .text: 0x01B0F158..0x01B0F550 (1 function).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;              /* 0x18 */
    float t1C;              /* 0x1C */
    float t20;              /* 0x20 */
    int idx;                /* 0x24 */
    int frame;              /* 0x28 */
} Eff9377;

typedef struct {
    void *obj;              /* 0x00 */
    Eff9377 *eff;           /* 0x04 */
} Eff9377CbArg;

typedef struct {
    u8 pad00[0xA0];
} P6ChrSlot;

typedef struct {
    P6Node node;            /* 0x0000 */
    u8 pad1C[4];            /* 0x001C */
    P6ChrSlot slots[64];    /* 0x0020 */
    int count;              /* 0x2820 */
} P6ChrGroup64;

typedef struct {
    P6Node30 scl[64];       /* 0x0000 (0x01B030F0) */
    P6Node30 pos[64];       /* 0x0C00 (0x01B03CF0) */
} P6Nodes9377;

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

typedef struct {
    void *w00;
    void *w04;
    int w08;
} ArgPos;

extern void *D_01B00488;
extern int D_01B0048C;
extern u8 D_01B005B0[];
extern u8 D_01B00610[];
extern u8 D_01B00640[];
extern P6Node D_01B00868;
extern P6Node D_01B00888;
extern P6ChrGroup64 D_01B008B0;
extern P6Nodes9377 D_01B030F0;
extern P6Obj150B D_01B048F0[64];
extern PppSlot D_01B09CF0[64];
extern MotSlot D_01B0DCF0[64];
extern u8 D_01B192B0[];
extern void *D_01B192DC;

extern void func_001C5E90(int, int, int);
extern int func_01B0EE08(int);
extern void func_01B0F8D8(void *);
extern void func_01B10BE8(void *);
extern void func_01B13C28(void *);
extern void func_01B14DB0(void *);
extern void func_01B16668(void *);
extern void func_01B166A0(void *);
extern void func_01B16F10(void *);
extern void func_01B17F68(void *);

void func_01B0F158(Eff9377CbArg *arg)
{
    union {
        void *p[6];
        ArgChrGrp grp;
        ArgPos pos;
        Arg6 a6;
        ArgMot mot;
    } msg;
    Eff9377 *eff = arg->eff;

    eff->t1C += 1.0f / 30.0f;
    eff->t20 += 1.0f / 30.0f;
    eff->frame++;

    switch (eff->state) {
    case 0:
        msg.grp.w00 = &D_01B008B0;
        msg.grp.w04 = &D_01B00868;
        msg.grp.w08 = D_01B0048C;
        msg.grp.w0C = 0;
        msg.grp.b10 = 1;
        func_01B0F8D8(&msg);
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
            P6Obj150B *xf = &D_01B048F0[i];
            P6Node30 *pos = &D_01B030F0.pos[i];
            P6Node30 *scl = &D_01B030F0.scl[i];
            PppSlot *ppp = &D_01B09CF0[i];
            P6ChrGroup64 *grp = &D_01B008B0;

            msg.p[0] = pos;
            msg.p[1] = &D_01B00868;
            func_01B13C28(&msg);

            msg.p[0] = scl;
            msg.p[1] = &D_01B00868;
            func_01B13C28(&msg);

            scl->v.x = 1.0f;
            scl->v.y = 1.0f;
            scl->v.z = 1.0f;
            scl->v.w = 1.0f;

            msg.a6.w00 = xf;
            msg.a6.w04 = &D_01B00868;
            msg.a6.w08 = D_01B00640;
            msg.a6.w0C = pos;
            msg.a6.w10 = D_01B00610;
            msg.a6.w14 = scl;
            func_01B14DB0(&msg);
            xf->b14C = 1;

            if (func_01B0EE08(*(int *)(((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x74)) != 0) {
                msg.pos.w00 = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
                msg.pos.w04 = &pos->v;
                msg.pos.w08 = 0;
                func_01B10BE8(&msg);

                msg.mot.w00 = ppp;
                msg.mot.w04 = &D_01B00888;
                msg.mot.w08 = xf;
                msg.mot.w0C = D_01B192DC;
                msg.mot.w10 = D_01B192B0;
                msg.mot.w14 = 1;
                func_01B16F10(&msg);
            } else {
                msg.pos.w00 = ((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x20;
                msg.pos.w04 = &pos->v;
                msg.pos.w08 = 1;
                func_01B10BE8(&msg);
                pos->v.y -= 0.2f;

                msg.mot.w00 = ppp;
                msg.mot.w04 = &D_01B00888;
                msg.mot.w08 = xf;
                msg.mot.w0C = D_01B192DC;
                msg.mot.w10 = D_01B192B0;
                msg.mot.w14 = 0;
                func_01B16F10(&msg);
            }

            msg.mot.w00 = &D_01B0DCF0[eff->idx];
            msg.mot.w04 = &D_01B00868;
            msg.mot.w08 = D_01B005B0;
            msg.mot.w0C = xf;
            msg.mot.w10 = D_01B00488;
            msg.mot.w14 = 0;
            func_01B166A0(&msg);

            msg.p[0] = &D_01B0DCF0[eff->idx];
            msg.p[1] = 0;
            func_01B16668(&msg);

            eff->frame = 0;
            eff->state++;
        }
        break;
    case 12:
        if (eff->frame > 20) {
            P6ChrGroup64 *grp = &D_01B008B0;
            func_001C5E90(D_01B0048C, *(int *)(((u8 *)grp + eff->idx * sizeof(P6ChrSlot)) + 0x74), 0);
            {
                /* DEBT(FAKE): pin incremented idx to $v1 to match ee-gcc regalloc */
                register int next __asm__("$3") = eff->idx + 1;
                eff->idx = next;
                if (next >= grp->count) {
                    void *end_msg[1];
                    end_msg[0] = arg->obj;
                    func_01B17F68(end_msg);
                }
            }
            eff->state--;
        }
        break;
    }
    eff->frame++;
}
