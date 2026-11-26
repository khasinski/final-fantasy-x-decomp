#include "iopsound.h"

typedef struct {
    s32 addr;
    s32 size;
} MemBlock;

typedef struct {
    u32 unk00;
    s32 spu_size;
    u32 unk08;
    u32 unk0C;
    s32 spu_addr;
} BankHdr;

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    BankHdr *hdr;
    s32 active;
    s32 spu_addr;
} BankSlot;

extern MemBlock *D_019334;
extern BankSlot *D_019308;
extern s32 D_018734[];
extern s32 D_01877C;
extern MemBlock *D_018730;
extern s32 D_01872C;

s32 func_009C14(BankSlot *p);

s32 func_009360(s32 src, s32 dst, s32 size) {
    s32 step = 0;

    if (size <= 0) {
        return step;
    }

    if (src < dst && src + size >= dst) {
        step = -1;
    }

    if (step == -1) {
        step = -4;
        src += size + step;
        dst += size + step;
    } else {
        step = 4;
    }

    do {
        *(s32 *)dst = *(s32 *)src;
        src += step;
        dst += step;
        size -= 4;
    } while (size > 0);

    return 4;
}

s32 func_0093C8(u32 dst, s32 size, s32 val) {
    if (size <= 0) {
        return 0;
    }

    if ((dst & 3) == 0 && (size & 3) == 0) {
        u32 *p = (u32 *)dst;
        size = (u32)size >> 2;
        do {
            *p++ = val;
        } while (--size != 0);
        return 4;
    }

    if ((dst & 1) == 0 && (size & 1) == 0) {
        u16 *p = (u16 *)dst;
        size = (u32)size >> 1;
        do {
            *p++ = val;
        } while (--size != 0);
        return 2;
    }

    {
        u8 *p = (u8 *)dst;
        do {
            *p++ = val;
        } while (--size != 0);
        return 1;
    }
}

void func_00944C(s32 addr) {
    MemBlock *p = D_019334;

    while (p->size != 0) {
        if (p->addr == addr) {
            break;
        }
        p++;
    }

    if (p->size != 0) {
        func_009360((s32)(p + 1), (s32)p, (s32)D_019334 + 1032 - (s32)p);
    }
}

s32 func_0094C4(s32 addr, u32 size) {
    MemBlock *p = D_019334;

    while (p->size != 0) {
        s32 diff = p->addr - addr;
        s32 end_diff = diff + p->size;
        if ((u32)diff < size || (diff < 0 && end_diff > 0)) {
            return p->addr;
        }
        p++;
    }

    return -1;
}

void func_009530(s32 addr, s32 size) {
    MemBlock *p = D_019334;

    while (p->size != 0) {
        if (p->addr >= addr) {
            break;
        }
        p++;
    }

    func_009360((s32)p, (s32)(p + 1), (s32)D_019334 + 1016 - (s32)p);
    p->addr = addr;
    p->size = size;
}

s32 func_0095C4(s32 addr, s32 size) {
    s32 hit;

    do {
        hit = func_0094C4(addr, size);
        if (hit >= 0) {
            BankSlot *b = D_019308;
            do {
                if (b->active != 0 && b->hdr->spu_addr == hit) {
                    break;
                }
                b++;
            } while (b < D_019308 + 128);
            if (b->active != 0) {
                func_009C14(b);
            }
            func_00944C(hit);
        }
    } while (hit >= 0);

    func_009530(addr, size);
    return addr;
}

s32 func_009698(s32 size) {
    s32 addr = 0;

    if (size != 0) {
        MemBlock *p = D_019334;
        while (p->size != 0) {
            if (p->addr >= addr + size) {
                break;
            }
            addr = p->addr + p->size;
            p++;
        }
        if (addr + size <= 0x200000) {
            func_009530(addr, size);
        } else {
            addr = 0;
        }
    }

    return addr;
}

s32 func_00973C(s32 addr, s32 size) {
    if (size != 0) {
        MemBlock *p = D_019334;
        while (p->size != 0) {
            if (p->addr == addr) {
                if (size < p->size) {
                    p->size = size;
                }
                break;
            }
            p++;
        }
    }

    return size;
}

void func_0097A8(void) {
    s32 eff_size;

    func_0093C8((u32)D_019334, 1032, 0);
    func_0095C4(0, 0x7100);
    func_0095C4(0x20000, 0x2000);
    eff_size = D_01877C;
    D_018734[0] = 0x200000 - eff_size;
    D_018734[1] = 0x20000 - eff_size;
    func_0095C4(D_018734[0], eff_size);
    func_0095C4(D_018734[1], eff_size);
}

s32 func_009834(s32 addr) {
    MemBlock *p = D_018730;
    s32 size;

    while (p->size != 0) {
        if (p->addr == addr) {
            break;
        }
        p++;
    }

    size = p->size;
    if (size != 0) {
        func_009360((s32)(p + 1), (s32)p, (s32)D_018730 + 2056 - (s32)p);
    }

    return size;
}

void func_0098B4(s32 addr, s32 size) {
    MemBlock *p = D_018730;

    while (p->size != 0) {
        if (p->addr >= addr) {
            break;
        }
        p++;
    }

    func_009360((s32)p, (s32)(p + 1), (s32)D_018730 + 2048 - (s32)p);
    p->addr = addr;
    p->size = size;
}

s32 func_009948(s32 size) {
    s32 addr;
    MemBlock *p;

    if (size == 0) {
        return 0;
    }

    size += 3;
    size &= -4;
    p = D_018730;
    addr = D_01872C;
    while (p->size != 0) {
        if (p->addr >= addr + size) {
            break;
        }
        addr = p->addr + p->size;
        p++;
    }

    if (addr + size <= D_01872C + 0x40000) {
        func_0098B4(addr, size);
    } else {
        addr = 0;
    }

    return addr;
}

s32 func_009A04(s32 addr, s32 size) {
    if (size != 0) {
        MemBlock *p = D_018730;
        while (p->size != 0) {
            if (p->addr == addr) {
                if (size < p->size) {
                    p->size = size;
                }
                break;
            }
            p++;
        }
    }

    return size;
}

void func_009A70(void) {
    func_0093C8((u32)D_018730, 2056, 0);
}

void func_009A9C(void) {
    BankSlot *p = D_019308 + 16;
    BankSlot *end = D_019308 + 128;

    do {
        if (p->lru != 0) {
            p->lru++;
        }
        p++;
    } while (p < end);
}

s32 func_009AE0(void) {
    BankSlot *p = D_019308 + 16;
    BankSlot *end = D_019308 + 128;
    s32 max = 0;

    do {
        if (p->lru != 0 && p->lru > max) {
            max = p->lru;
        }
        p++;
    } while (p < end);

    return max;
}

void func_009B28(s32 lru) {
    if (lru != 0) {
        BankSlot *p = D_019308;
        BankSlot *end = p + 128;
        do {
            if (p->lru > lru) {
                p->lru--;
            }
            p++;
        } while (p < end);
    }
}

void func_009B74(BankSlot *p) {
    if (p->lru != 0) {
        func_009B28(p->lru);
        p->lru = 0;
    }
}

s32 func_009BB0(s32 id) {
    BankSlot *p;

    for (p = D_019308; p < D_019308 + 128; p++) {
        if (p->active != 0 && p->id == id) {
            return p->idx;
        }
    }

    return -1;
}

s32 func_009C14(BankSlot *p) {
    s32 ret = -1;

    if (p->id >= 0) {
        s32 id;
        func_009B28(p->lru);
        id = p->id;
        p->id = -1;
        p->active = 0;
        ret = func_009BB0(id);
        if (ret < 0) {
            BankHdr *hdr = p->hdr;
            func_009834((s32)hdr);
            if (hdr->spu_addr != 0) {
                func_00944C(hdr->spu_addr);
            }
        }
        p->lru = 0;
        p->hdr = NULL;
    }

    return ret;
}

void func_009CAC(void) {
    s32 i;
    BankSlot *p;

    func_0093C8((u32)D_019308, 3096, 0);
    p = D_019308;
    i = 0;
    do {
        p->idx = i;
        p->id = -1;
        p++;
        i++;
    } while (i < 128);
}

void func_009D04(BankSlot *p, s32 spu_addr) {
    func_00944C(p->spu_addr);
    func_0095C4(spu_addr, p->hdr->spu_size);
    p->spu_addr = spu_addr;
}
