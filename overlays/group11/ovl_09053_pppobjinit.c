#include "p8_overlay.h"

void func_01B04088(P8PObj *o, int delay, int trigger, P8PObjFn on_frame)
{
    o->delay = delay;
    o->trigger = trigger;
    o->on_frame = on_frame;
    o->flags = 0x8000;
    o->on_tick = 0;
    o->w108 = 0;
    o->w10C = 0;
    o->w110 = 0;
    o->frame = 0;
    o->chr = 0;
    o->mode = 0;
    o->rot.v.x = o->rot.v.y = o->rot.v.z = o->rot.v.w = 0.0f;
    o->trans.v.x = o->trans.v.y = o->trans.v.z = 0.0f;
    o->trans.v.w = 1.0f;
    o->offset.v.x = o->offset.v.y = o->offset.v.z = 0.0f;
    o->offset.v.w = 1.0f;
    o->color.v.x = o->color.v.y = o->color.v.z = o->color.v.w = 1.0f;
}
