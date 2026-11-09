/* tu_096 0x153ea0-0x1543e0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

void MsAtelCameraInit(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        D_0058FE10[i] = 0;
        D_0058FE20[i] = 0;
        D_0058FE30[i] = 0;
        D_0058FE40[i] = 0;
    }
}

int MsAtelGetCameraID(int a, int kind, u32 i)
{
    int *p;
    int h = 0;

    if (i < 3) {
        switch (kind) {
        case 0:
            p = &D_0058FE20[i];
            if (*p == 0) {
                *p = MsCameraGet(a, i, 3);
            }
            h = *p;
            break;
        case 1:
            p = &D_0058FE10[i];
            if (*p == 0) {
                *p = MsCameraGet(a, i, 1);
            }
            h = *p;
            break;
        case 2:
            p = &D_0058FE30[i];
            if (*p == 0) {
                *p = MsCameraGet(a, i, 5);
            }
            h = *p;
            break;
        case 3:
            p = &D_0058FE40[i];
            if (*p == 0) {
                *p = MsCameraGet(a, i, 7);
            }
            h = *p;
            break;
        }
    }
    return h;
}

void func_00154010(int kind, u32 i)
{
    if (i < 3) {
        switch (kind) {
        case 0:
            MsCameraFree(D_0058FE20[i]);
            D_0058FE20[i] = 0;
            break;
        case 1:
            MsCameraFree(D_0058FE10[i]);
            D_0058FE10[i] = 0;
            break;
        case 2:
            MsCameraFree(D_0058FE30[i]);
            D_0058FE30[i] = 0;
            break;
        case 3:
            MsCameraFree(D_0058FE40[i]);
            D_0058FE40[i] = 0;
            break;
        }
    }
}

void func_001540C0(int kind)
{
    int i;

    switch (kind) {
    case 0:
        for (i = 0; i < 3; i++) {
            MsCameraResetMove(D_0058FE20[i], 0);
            MsCameraResetMove(D_0058FE20[i], 1);
        }
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            MsCameraResetMove(D_0058FE10[i], 0);
            MsCameraResetMove(D_0058FE10[i], 1);
        }
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            MsCameraResetMove(D_0058FE30[i], 0);
            MsCameraResetMove(D_0058FE30[i], 1);
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            MsCameraResetMove(D_0058FE40[i], 0);
            MsCameraResetMove(D_0058FE40[i], 1);
        }
        break;
    }
}

int func_00154218(void *a, int kind, int i)
{
    int *h = (int *)func_0013A468((char *)a); /* DEBT(CAST): per-actor effect handle */

    if (*h == 0) {
        if (kind == 0) {
            kind = func_00143D78() == func_00145628(a);
        }
        *h = MsAtelGetCameraID(5, kind, i);
    }
    return *h;
}

int MsBindCamera(void *a, int kind, int i)
{
    int r = 0;

    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        r = func_00154218(a, kind, i);
        break;
    }
    return r;
}

void MsBindOffCamera(Actor *a)
{
    int *w = (int *)func_0013A468((char *)a); /* DEBT(CAST): per-actor effect handle */
    int h = *w;
    int i;

    if (h != 0) {
        for (i = 0; i < 3; i++) {
            if (h == D_0058FE10[i]) {
                D_0058FE10[i] = 0;
            }
            if (h == D_0058FE20[i]) {
                D_0058FE20[i] = 0;
            }
            if (h == D_0058FE30[i]) {
                D_0058FE30[i] = 0;
            }
            if (h == D_0058FE40[i]) {
                D_0058FE40[i] = 0;
            }
        }
        MsCameraFree(h);
        *w = 0;
    }
}

void func_00154390(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_00154010(2, i);
        func_00154010(3, i);
    }
    func_001AAD78();
}
