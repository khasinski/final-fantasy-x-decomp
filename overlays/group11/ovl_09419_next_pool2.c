#include "common.h"
typedef struct AnimFrame { s16 offset; s16 duration; int unused; } AnimFrame;
typedef struct AnimData { int unused0; s16 count; u8 pad6[10]; AnimFrame frames[1]; } AnimData;
typedef struct AnimState {
    AnimData *data; AnimFrame *frame; s16 index; s16 padA; void *image; s16 timer; u8 pad12[14];
    float pos[4]; float scale; float rotation; int r,g,b; float alpha; u8 pad48[8];
} AnimState;
typedef struct Particle {
    int active; u8 pad4[12]; float pos[4]; float velocity[4]; int life, remaining, flags; int pad3C;
    AnimState anim; int color0[4]; int color1[4]; float scale0,scale1; u8 padB8[8];
} Particle;
typedef struct Pool {
    int count; Particle *items; u8 pad8[8]; int gravity_on; float gravity; int drag_on; float drag; int matrix_on; u8 pad24[12]; float matrix[16];
} Pool;
void *func_002EF0D0(void *,int,int);
void func_002DD0C0(void *,void *);
void func_002DD0B0(void *,void *);
void func_002DCE08(void *,void *,void *);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
void func_01B034A8(AnimState *, AnimData *);
int func_01B03530(AnimState *, void *, int, float);
void func_01B03720(Particle *,AnimData *);
void func_01B03780(Particle *);
int func_01B037B0(Particle *);

void func_01B03990(Particle *p,float alpha)
{
    p->anim.alpha = alpha;
}

void func_01B03998(Pool *p,Particle *items,int n)
{
    int i;
    func_002EF0D0(p,0,0x70);
    p->count = n;
    p->items = items;
    p->gravity_on = 0;
    p->drag_on = 0;
    p->matrix_on = 0;
    for(i=0;i<n;i++,items++) {
        func_01B03780(items);
    }
}

void func_01B03A10(Pool *p)
{
    int i;
    Particle *q;
    float len;
    float speed;
    q=p->items;
    for(i=0;i<p->count;i++,q++) {
        if(q->active != 0) {
            if(func_01B037B0(q)==0) {
                func_01B03780(q);
            } else {
                if(p->gravity_on != 0) {
                    q->velocity[1] += p->gravity;
                }
                if(p->drag_on != 0) {
                    len=func_002EC440(func_002E9290(func_002ED038(q->velocity[0]*q->velocity[0]+q->velocity[1]*q->velocity[1]+q->velocity[2]*q->velocity[2])));
                    if(len != 0.0f) {
                        speed=len-p->drag;
                        if(speed<0.0f) speed=0.0f;
                        speed=speed/len;
                        q->velocity[0]*=speed;
                        q->velocity[1]*=speed;
                        q->velocity[2]*=speed;
                    }
                }
            }
        }
    }
}

Particle *func_01B03B48(Pool *p,AnimData *a)
{
    int i;
    Particle *q=p->items;
    for(i=0;i<p->count;i++,q++) {
        if(q->active==0) {
            func_01B03720(q,a);
            return q;
        }
    }
    return 0;
}

int func_01B03BA8(Pool *p,void *draw,int packet,float depth)
{
    int i;
    Particle *q=p->items;
    float pos[4];
    for(i=0;i<p->count;i++,q++) {
        if(q->active!=0) {
            if(p->matrix_on==0) {
                func_002DD0B0(q->anim.pos,q->pos);
            } else {
                func_002DCE08(pos,p->matrix,q->pos);
                func_002DD0B0(q->anim.pos,pos);
            }
            packet=func_01B03530(&q->anim,draw,packet,depth);
        }
    }
    return packet;
}

void func_01B03C80(Pool *p,void *matrix,float gravity,float drag)
{
    if(gravity!=0.0f) { p->gravity_on=1; p->gravity=gravity; }
    else { p->gravity_on=0; }
    if(drag!=0.0f) { p->drag_on=1; p->drag=drag; }
    else { p->drag_on=0; }
    if(matrix!=0) { p->matrix_on=1; func_002DD0C0(p->matrix,matrix); }
    else { p->matrix_on=0; }
}

int func_01B03CE8(Pool *p)
{
    int i;
    int n=0;
    Particle *q=p->items;
    for(i=0;i<p->count;i++,q++) {
        if(q->active!=0) n++;
    }
    return n;
}
