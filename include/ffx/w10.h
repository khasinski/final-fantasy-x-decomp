#ifndef FFX_W10_H

#define FFX_W10_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

#define GS_CSR (*(volatile s64 *)0x12001000)

/* ---- c_2D1D68: EE kernel thread/semaphore wrappers (SDK layouts) ---- */
/* clamp a mode index into 0..2 */
#define W10_CLAMP_IDX(a) ((a) < 0 ? 0 : ((a) < 3 ? (a) : 2))

typedef struct W10AnimHdr {
    s16 count;
    s16 ids[15];
    u8 data[1];
} W10AnimHdr;

/* DEBT(NAME): 32-byte sound voice entry; the first word is also accessed by halfword. */
typedef struct W10SoundVoice {
    union { u32 word; u16 half[2]; } header;
    u8 pad4[0x1B];
    u8 active;
} W10SoundVoice;

/* DEBT(NAME): packed resource and 32-byte entry views from func_002B7388. */
typedef struct W10PackedResource {
    u8 pad0[0x14];
    u32 entries; /* Absolute table address, or an offset from the resource. */
} W10PackedResource;

typedef struct W10PackedResourceEntry {
    u8 pad0[0x1C];
    s32 value; /* Absolute target address, or an offset from the resource. */
} W10PackedResourceEntry;

void *func_002B7388(W10PackedResource *resource, int index);

int op_file_read(const char *path, void *buffer);

#endif
