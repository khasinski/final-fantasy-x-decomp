#ifndef FFX_W8_H

#define FFX_W8_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

typedef struct ByteQuad {
    u8 a, b, c, d;
} ByteQuad;

typedef struct Block3 {
    u32 flags;
    u32 f4;
    u32 f8;
} Block3;

typedef struct Msg10 {
    u8 pad[0xC];
    int f0C;
    u8 f10;
} Msg10;

typedef struct EvtCtl {
    int f0;
    int f4;
} EvtCtl;

typedef struct NodeOwner {
    u8 pad[0x30];
    struct Node8 *list;
} NodeOwner;

typedef struct Node8 {
    struct Node8 *next;
    u8 pad4[4];
    struct { u8 pad[0xE]; u8 b0E; } *info;
} Node8;

#endif
