#include "common.h"
typedef struct Track { float value[4], target[4]; u8 pad20[12]; float phase, step; int duration; int pad38; int active; } Track;
typedef struct Ramp { float a,b; int c,d; } Ramp;
typedef struct Control { u8 pad0[0xB0]; Track track0; Track track1; int pad130[6]; int flag148; u8 pad14C[0x1C]; int flag168; Ramp ramp; u8 pad17C[12]; u8 flag188; u8 pad189[3]; s16 counter; s16 pad18E; } Control;
extern u16 D_01B07000[],D_01B07008[],D_01B07010[];
extern int D_01B07018;
extern Control D_01B07020[];
extern int D_01B07CD4,D_01B07CD8,D_01B07CDC;
Control *func_01B01DA0(int);
void func_01B03BB0(void);
void func_01B03FB0(int);
void func_002DD968(void *,void *,void *,float);

void func_01B022A0(Control *p)
{
    p->track0.active=0;
    p->track1.active=0;
    p->flag148=0;
    p->flag168=0;
}

void func_01B022B8(Control *p,int a,int b,float x,float y)
{
    Ramp *r=&p->ramp;
    r->a=x;
    r->b=y;
    r->c=a;
    r->d=b;
    p->flag188=1;
}

void func_01B022D8(Control *p)
{
    p->flag188=0;
}
