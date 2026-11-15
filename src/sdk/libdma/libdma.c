/* tu_348 0x2dba00-0x2dc110: medium; libdma (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"
#include "ffx/s2.h"

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002DBA00(s32 arg0) {
    register s32 p __asm__("$2");
    register s32 m1 __asm__("$3");

    p = 0x10000000;
    m1 = 0xFFFF0000;
    __asm__("" : "+r"(p), "+r"(m1));
    p |= 0xE060;
    m1 |= 0xFFFF;
    __asm__("" : "+r"(p), "+r"(m1));
    p = *(s32 *)p;
    if (arg0 != m1) {
        *(s32 *)0x1000E060 = arg0;
    }
    return p;
}

void func_002DBA28(void *address, int memory) {
    /* DEBT(CAST): view the DMA channel as volatile hardware registers. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    if (channel[12] != 0xffffffffU) {
        channel[12] = memory;
    }
    control.word = *channel;
    channel[8] = 0;
    control.bits.mode = 1;
    control.bits.direction = 1;
    control.bits.start = 1;
    *channel = control.word;
}

void func_002DBB00(S2DmaCtl *address, int memory, int count) {
    /* DEBT(CAST): view the DMA channel as volatile hardware registers. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    if (channel[4] != 0xffffffffU) {
        channel[4] = memory;
    }
    control.word = *channel;
    channel[8] = count;
    control.bits.mode = 0;
    control.bits.direction = 1;
    control.bits.start = 1;
    *channel = control.word;
}

void func_002DBBE8(int address, int memory, int count) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    if (channel[4] != 0xffffffffU) {
        channel[4] = memory;
    }
    control.word = *channel;
    channel[8] = count;
    control.bits.mode = 2;
    control.bits.direction = 1;
    control.bits.start = 1;
    *channel = control.word;
}

void func_002DBCD0(int address) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    control.word = *channel;
    channel[8] = 0;
    control.bits.mode = 1;
    control.bits.direction = 0;
    control.bits.start = 1;
    *channel = control.word;
}

void func_002DBD98(int address, int memory, int count) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    if (channel[4] != 0xffffffffU) {
        channel[4] = memory;
    }
    control.word = *channel;
    channel[8] = count;
    control.bits.mode = 0;
    control.bits.direction = 0;
    control.bits.start = 1;
    *channel = control.word;
}

void func_002DBE88(int address, int memory, int count) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    int timeout = 0x1000000;
    union {
        int word;
        struct {
            unsigned int direction : 1;
            unsigned int reserved1 : 1;
            unsigned int mode : 2;
            unsigned int reserved2 : 4;
            unsigned int start : 1;
            unsigned int remaining : 23;
        } bits;
    } control;
    DmaControl updated;
    DmaControl current;

    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): convert the first member back to its union. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    if (channel[4] != 0xffffffffU) {
        channel[4] = memory;
    }
    control.word = *channel;
    channel[8] = count;
    control.bits.mode = 2;
    control.bits.direction = 0;
    control.bits.start = 1;
    *channel = control.word;
}

int func_002DBF78(int address, int mode, int timeout) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    DmaControl updated;
    DmaControl current;

    if (mode == 1) {
        return (*channel >> 8) & 1;
    }
    if (timeout == 0) {
        timeout = 0x1000000;
    }
    while (*channel & 0x100) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): the first union member converts back to its
                     * containing union; retain the original bit-field access. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    return 0;
}

int func_002EF240(char *, ...);
int func_002DC040(int address, unsigned int end, int mode, int timeout) {
    /* DEBT(CAST): callers pass the DMA register address as an integer. */
    volatile u32 *channel = (volatile u32 *)address;
    DmaControl updated;
    DmaControl current;

    if (mode == 1) {
        return channel[4] < end;
    }
    if (timeout == 0) {
        timeout = 0x1000000;
    }
    while (channel[4] < end) {
        timeout--;
        if (timeout < 0) {
            func_002EF240(D_005769B0);
            current.word = *channel;
            if ((current.word >> 8) & 1) {
                do {
                    updated.word = current.word;
                    updated.bits.start = 0;
                    current.word = updated.word;
                    /* DEBT(CAST): the first union member converts back to its
                     * containing union; retain the original bit-field access. */
                } while (((DmaControl *)&current.word)->bits.start);
                *channel = current.word;
            }
        }
    }
    return 0;
}
