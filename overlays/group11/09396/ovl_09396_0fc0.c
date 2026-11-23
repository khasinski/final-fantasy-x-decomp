/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B00FC0..0x01B01030)
 * Load base: 0x01B00000, .text: 0x01B00FC0..0x01B01030 (1 function)
 */
#include "common.h"

typedef struct OvlCtx {
    u8 pad00[0x104];
    void *p104;
    u8 pad108[0x1E];
    u8 b126;
} OvlCtx;

extern u8 D_01B07AA0[];
extern u8 *D_01B07B68;

extern void func_01B00FB0(void);

float func_01B00EF0(void);
void func_01B04488(void *, void *, int, int, float, int, void *);

void func_01B00FC0(void)
{
    OvlCtx *ctx = (OvlCtx *)(D_01B07B68 + 0x5F0);
    float sc = func_01B00EF0() * 0.008f;

    func_01B04488(D_01B07AA0, ctx, 5, 0, sc, 0, 0);
    {
        register int two __asm__("$2") = 2;
        ctx->b126 = two;
    }
    ctx->p104 = func_01B00FB0;
}
