#ifndef FFX_ACTOR_RESOURCES_H
#define FFX_ACTOR_RESOURCES_H

#include "common.h"

/* DEBT(NAME)/DEBT(TYPE): resource records initialized by AtelExecEventSound;
 * the 0x3C stride and payload self-reference are established by its accesses. */
typedef struct ActorInitRecord ActorInitRecord;
typedef struct ActorInitPayload {
    s32 word0;
    ActorInitRecord *self;
    u8 pad8[0x1C];
} ActorInitPayload;
struct ActorInitRecord {
    u8 pad0[0x18];
    ActorInitPayload payload;
};
/* C89 trailing array: the resource's count determines the record extent. */
typedef struct ActorInitTable {
    s32 count;
    ActorInitRecord records[1];
} ActorInitTable;

void func_00135F50(void);
void func_00135F60(int a, int b, int c);
int func_00138BC8(void);
char *func_00139228(char *p);
void func_0014A000(int v);

#endif
