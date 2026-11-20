/* Battle-effect overlay 09709: 0x01B01410..0x01B014E4 */
#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern float D_01B00624;
extern TtCfg *D_01B00654;
extern u8 D_01B00658[];
extern int D_01B00A90;
extern int D_01B00A94;
extern char D_01B025C8[];

int func_01B02170(char *, ...);
void func_00267658(PppObj *, int, int, int);
void func_00107428(int, int, int, float *);

int func_01B01410(PppObj *p)
{
    func_01B02170(D_01B025C8, D_01B00A90);
    D_006A3924 = D_01B00658;
    func_00267658(p, 0x1000, D_01B00654->w10[7], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0105969999f;
    p->scale[3] = 1.0f;
    func_00107428(D_01B00A94, 0x74, 0, p->pos);
    p->pos[1] = D_01B00624;
    return 1;
}
