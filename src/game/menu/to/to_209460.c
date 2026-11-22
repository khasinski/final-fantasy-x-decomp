/* tu_231 0x209460-0x20cc98: low; ~TOSetExeWindowArea (config/tu_map.tsv) */
#define TODrawMessageWindowForMenu _hdr_TODrawMessageWindowForMenu
#define TODrawMessageWindow _hdr_TODrawMessageWindow
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/s4.h"
#undef TODrawMessageWindow
#undef TODrawMessageWindowForMenu

void func_00209460(s32 i)
{
    func_002EF0D0(D_0066B508[i], 0, 0x5C);
}

void TOSetExeWindowArea(int a)
{
    int i;

    if (a == 0) {
        for (i = 7; i >= 0; i--) {
            D_0066B508[i] = &D_0066AF48[i];
        }
    } else {
        for (i = 7; i >= 0; i--) {
            D_0066B508[i] = &D_0066B228[i];
        }
    }
}

void func_00209508(UiWidget *w)
{
    w->f06 = 0x1000;
    w->cur[0] = w->target[0];
    w->cur[1] = w->target[1];
    w->cur[2] = w->target[2];
    w->cur[3] = w->target[3];
}

MenuSlot *func_00209538(s32 idx)
{
    return D_0066B508[idx];
}

void TOOpenWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    s->w00 = 1;
    s->state = 0;
    s->fn[0](s);
    s = D_0066B508[i];
    s->state = 1;
    s->fn[5] = s->fn[1];
}

int TOControlWindow(int i)
{
    MenuSlot *m = D_0066B508[i];

    if (m->w00 == 0) {
        return 0;
    }
    return m->fn[5]();
}

int TOCloseWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    if (s->w00 != 0) {
        s->state = 3;
        s->fn[5] = s->fn[3];
    }
}

s16 func_00209630(s32 i)
{
    return D_0066B508[i]->w04;
}

void TODrawWindow(int i)
{
    MenuSlot *s = D_0066B508[i];

    if (s->w00 != 0) {
        s->fn[6](s);
    }
}

s32 func_00209690(s32 i, s16 v)
{
    D_0066B508[i]->state = v;
    return 0;
}

int TOGetWindowStatus(int i)
{
    return D_0066B508[i]->state;
}

int func_002096D0(int i, int v)
{
    MenuSlot *s = D_0066B508[i];

    s->w04 = v;
    TOInitWindowCallBack(s);
}

void func_002096F0(int i, int x, int y, int w, int h)
{
    MenuSlot *m = D_0066B508[i];

    m->w = w;
    m->h = h;
    m->x = x;
    m->y = y;
    m->x1 = x + w;
    m->y1 = y + h;
}

void func_00209728(s32 i, s32 *x, s32 *y, s32 *w, s32 *h)
{
    MenuSlot *s = D_0066B508[i];

    *x = s->x;
    *y = s->y;
    *w = s->w;
    *h = s->h;
}

void func_00209760(s32 i, u8 a, u8 b, u8 c, u8 d)
{
    D_0066B508[i]->b36 = a;
    D_0066B508[i]->b37 = b;
    D_0066B508[i]->b38 = c;
    D_0066B508[i]->b39 = d;
}

extern u8 D_00324140[];
extern u8 D_00323960[];
extern u8 D_00670DA0[];
extern u8 D_0066B5A0[];
extern u8 D_0066BDA0[];
extern u8 D_00323910[];
extern s8 D_00323958;
extern void _void_func_00214650(void) __asm__("func_00214650"); /* DEBT(TYPE): funcs.h declares as int */
void func_0020B710(void);

void TOInit(void)
{
    void *p;
    int lang;
    int i;

    func_0020B710();
    TOMenuMakeSaveFileName();
    TOInitPadData();
    func_001EF910();
    D_0068EEDC = 0;
    D_0068EEE0 = 0;
    p = (void *)TODVDFileReadAuto(0x12, 0);
    TOFTCTransfer(p);
    func_0011D590((int)p, 2);
    if (TOGetFFXLangSwapFlag() == 1) {
        p = (void *)TODVDFileReadAuto(4, 0);
        TOFTCTransfer(p);
        func_0011D590((int)p, 2);
    }
    if (func_0020B850() == 0x11 || func_0020B850() == 0x12) {
        lang = 4;
    } else {
        lang = 0x12;
    }
    D_0066B590 = TODVDFileReadAuto(lang, 0xB);
    D_0066B594 = TODVDFileReadAuto(lang, 0xA);
    D_0066B58C = TODVDFileReadAuto(lang, 0xF);
    D_0066B588 = TODVDFileReadAuto(lang, 0xE);
    D_0066B598 = TODVDFileReadAuto(lang, 8);
    func_0020CC20(lang, 6, D_00324140);
    D_003241C0 = (int)D_00324140;
    func_0020CC20(lang, 5, (void *)TOGetFFXToAlbhedTblAdrs());
    func_0020CC20(lang, 7, D_00323960);
    func_0020CC20(lang, 0x16, D_00670DA0);
    D_0066B584 = (void *)TODVDFileReadAuto(0x12, 0x13);
    func_0020CC20(0x12, 0x14, D_0066B5A0);
    func_0020CC20(0x12, 0x15, D_0066BDA0);
    func_0020DD38();
    TkMenuInitSeq();
    TkMenuSetSceneDataAdrs(0, D_0066B5A0);
    TkMenuSetSceneDataAdrs(1, D_0066BDA0);
    TkMenuSetSceneDataAdrs(2, D_00670DA0);
    TOSeqInitParam();
    func_00206980();
    D_00323910[0] = 0x12;
    D_00323910[1] = 0x50;
    D_00323910[2] = 0;
    TOSetExeMessageWindowArea(1);
    for (i = 0; i < 8; i++) {
        TOInitMessageWindow(i);
    }
    for (i = 0; i < 8; i++) {
        TOInitMacroCmd(i);
    }
    TOSetExeMessageWindowArea(0);
    for (i = 0; i < 8; i++) {
        TOInitMessageWindow(i);
    }
    for (i = 0; i < 8; i++) {
        TOInitMacroCmd(i);
    }
    TODapsInit();
    TOMenuInit();
    _void_func_00214650();
    D_00323958 = 0;
}

void TOReset1(void)
{
    int i;

    TOInitPadData();
    D_0068EEDC = 0;
    D_0068EEE0 = 0;
    TOSetExeMessageWindowArea(1);
    for (i = 0; i < 8; i++) {
        TOInitMessageWindow(i);
    }
    for (i = 0; i < 8; i++) {
        TOInitMacroCmd(i);
    }
    TOSetExeMessageWindowArea(0);
    for (i = 0; i < 8; i++) {
        TOInitMessageWindow(i);
    }
    for (i = 0; i < 8; i++) {
        TOInitMacroCmd(i);
    }
    TOMenuInit();
    func_00214650();
    TODapsInit();
}

void func_00209B68(void)
{
    func_0020DD38();
    TkMenuInitSeq();
    TkMenuSetSceneDataAdrs(0, D_0066B5A0);
    TkMenuSetSceneDataAdrs(1, D_0066BDA0);
    TkMenuSetSceneDataAdrs(2, D_00670DA0);
    TOSeqInitParam();
}

extern u8 D_003241CC;
extern u8 D_003241D0;
extern u8 D_003241D4;
extern u8 D_003241F8[];
extern u8 D_003241FC;
extern u8 D_003241FD;
extern u8 D_003241FE;
extern u8 D_003241FF;
extern u8 D_00324200;
extern u8 D_00324201;
extern u8 D_00324202;
extern u8 D_00324203;
extern u8 D_00324204;
extern u8 D_00324206;
extern u8 D_0032420A;
extern u8 D_00324218;
extern u8 D_0032421A;
extern u8 D_0032421C;
extern u8 D_0032421E;
extern u8 D_00324220;
extern u8 D_00324222;
extern u8 D_00324224;
extern u8 D_00324226;
extern u8 D_00324230;
extern u8 D_00324232;
extern u8 D_00324238;
extern u8 D_00324244[];
extern u8 D_00324270;
extern u8 D_00324272;
extern u8 D_00324274;
extern u8 D_00324278;
extern u8 D_0032427C;
extern u8 D_00324280;
extern u8 D_00324282;
extern u8 D_00324284;
extern u8 D_00324288;
extern u8 D_0032428C;
extern u8 D_00324290;
extern u8 D_00324292;
extern u8 D_00324294;
extern u8 D_00324296;
extern u8 D_00324298;
extern u8 D_0032429C;
extern u8 D_003242A0;
extern u8 D_003242A4;
extern u8 D_003242A8;
extern u8 D_003242AC;
extern u8 D_003242B0;
extern u8 D_003242B4;
extern u8 D_003242C0;
extern u8 D_003242C4;
extern u8 D_003242C8[];
extern u8 D_003242DC[];
extern u8 D_003242E0[];
extern u8 D_003242E4;
extern u8 D_003242E8;
extern u8 D_003242EC[];
extern u8 D_003242F0[];
extern u8 D_003242F4;
extern u8 D_003242F8;
extern u8 D_003242FC[];
extern u8 D_0032430C;
extern u8 D_0032430E;
extern u8 D_00324310;
extern u8 D_00324312;
extern u8 D_00324314;
extern u8 D_00324318;
extern u8 D_0032431C;
extern u8 D_00324320;
extern u8 D_00324324;
extern u8 D_00324326;
extern u8 D_00324328;
extern u8 D_0032432A;
extern u8 D_0032432C;
extern u8 D_0032432E;
extern u8 D_00324330;
extern u8 D_00324331;
extern u8 D_00324332;
extern u8 D_00324333;
extern u8 D_00324334;
extern u8 D_00324336;
extern u8 D_00324338;
extern u8 D_0032433A;
extern u8 D_0032433C;
extern u8 D_0032433E;
extern u8 D_00324340;
extern u8 D_00324342;
extern u8 D_00324344;
extern u8 D_00324346;
extern u8 D_00324348;
extern u8 D_0032434A;
extern u8 D_0032434C;
extern u8 D_00324350;
extern u8 D_00324352;
extern u8 D_00324356;
extern u8 D_00324358;
extern u8 D_0032435A;
extern u8 D_00324360;
extern u8 D_00324362;
extern u8 D_00324366;
extern u8 D_00324368;
extern u8 D_0032436E;
extern u8 D_00324370;
extern u8 D_00324378;
extern u8 D_00570370[];
extern u8 D_00570380[];
extern u8 D_00570390[];
extern u8 D_00570398[];
extern u8 D_005703A0[];
extern u8 D_005703A8[];
extern u8 D_005703B8[];
extern u8 D_005703C8[];
extern u8 D_005703D8[];
extern u8 D_005703E8[];
extern u8 D_005703F8[];
extern u8 D_00570408[];
extern u8 D_00570418[];
extern u8 D_00570428[];
extern u8 D_00570438[];
extern u8 D_00570448[];
extern u8 D_00570458[];
extern u8 D_00570468[];
extern u8 D_00570478[];
extern u8 D_00570488[];
extern u8 D_00570498[];
extern u8 D_005704A8[];
extern u8 D_005704B8[];
extern u8 D_005704C8[];
extern u8 D_005704D8[];
extern u8 D_005704E8[];
extern u8 D_005704F8[];
extern u8 D_00570508[];
extern u8 D_00570518[];
extern u8 D_00570528[];
extern u8 D_00570538[];
extern u8 D_00570548[];
extern u8 D_00570558[];
extern u8 D_00570568[];
extern u8 D_00570578[];
extern u8 D_00570588[];
extern u8 D_00570598[];
extern u8 D_005705A8[];
extern u8 D_005705B8[];
extern u8 D_005705C8[];
extern u8 D_005705E0[];
extern u8 D_005705F8[];
extern u8 D_00570610[];
extern u8 D_00570620[];
extern u8 D_00570630[];
extern u8 D_00570640[];
extern u8 D_00570650[];
extern u8 D_00570660[];
extern u8 D_00570670[];
extern u8 D_00570680[];
extern u8 D_00570690[];
extern u8 D_005706A0[];
extern u8 D_005706B0[];
extern u8 D_005706C0[];
extern u8 D_005706D0[];
extern u8 D_005706E0[];
extern u8 D_005706F0[];
extern u8 D_00570700[];
extern u8 D_00570710[];
extern u8 D_00570720[];
extern u8 D_00570730[];
extern u8 D_00570740[];
extern u8 D_00570750[];
extern u8 D_00570760[];
extern u8 D_00570768[];
extern u8 D_00570770[];
extern u8 D_00570778[];
extern u8 D_00570780[];
extern u8 D_00570788[];
extern u8 D_00570790[];
extern u8 D_00570798[];
extern u8 D_005707A0[];
extern u8 D_005707A8[];
extern u8 D_005707B0[];
extern u8 D_005707B8[];
extern u8 D_005707C0[];
extern u8 D_005707C8[];
extern u8 D_005707D0[];
extern u8 D_005707D8[];
extern u8 D_005707E0[];
extern u8 D_005707E8[];
extern u8 D_005707F0[];
extern u8 D_005707F8[];
extern u8 D_00570800[];
extern u8 D_00570808[];
extern u8 D_00570810[];
extern u8 D_00570818[];
extern u8 D_00570820[];
extern u8 D_00570828[];
extern u8 D_00570830[];

extern u8 D_00324208;
extern u8 D_0032420C;
extern u8 D_00324210;
extern u8 D_00324214;
extern u8 D_00324216;
extern u8 D_00324228;
extern u8 D_0032422A;
extern u8 D_0032422C;
extern u8 D_0032422E;
extern u8 D_00324264;
extern u8 D_00324268;
extern u8 D_0032426C;
extern u8 D_0032426E;

extern u8 _D_003241F8_0x1 __asm__("D_003241F8+0x1"); /* DEBT(TYPE): split scalar symbol at +0x1 */
extern u8 _D_003241F8_0x2 __asm__("D_003241F8+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003241F8_0x3 __asm__("D_003241F8+0x3"); /* DEBT(TYPE): split scalar symbol at +0x3 */
extern u8 _D_00324244_0x2 __asm__("D_00324244+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242C8_0x2 __asm__("D_003242C8+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242DC_0x2 __asm__("D_003242DC+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242E0_0x2 __asm__("D_003242E0+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242EC_0x2 __asm__("D_003242EC+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242F0_0x2 __asm__("D_003242F0+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */
extern u8 _D_003242FC_0x2 __asm__("D_003242FC+0x2"); /* DEBT(TYPE): split scalar symbol at +0x2 */

void TOSeqInitParam(void)
{
    s16 dummy;

    TOSeqGetColor(1, D_00570370, (void *)&D_003241C4);
    TOSeqGetColor(1, D_00570380, (void *)&D_003241C8);
    TOSeqGetColor(1, D_00570390, (void *)&D_003241D4);
    TOSeqGetColor(1, D_00570398, (void *)&D_003241D0);
    TOSeqGetColor(1, D_005703A0, (void *)&D_003241CC);
    TOSeqGetColor(1, D_005703A8, (void *)&D_003241D8);
    TOSeqGetColor(1, D_005703B8, (void *)&D_003241DC);
    TOSeqGetColor(1, D_005703C8, (void *)&D_003241E0);
    TOSeqGetColor(1, D_005703D8, (void *)&D_003241E4);
    TOSeqGetColor(1, D_005703E8, (void *)&D_003241E8);
    TOSeqGetColor(1, D_005703F8, (void *)&D_003241EC);
    TOSeqGetColor(1, D_00570408, (void *)&D_003241F0);
    TOSeqGetColor(1, D_00570418, (void *)&D_003241F4);
    TOSeqGetColorRGBA(1, D_00570428, (void *)D_003241F8, (void *)&_D_003241F8_0x2, (void *)&_D_003241F8_0x1, (void *)&_D_003241F8_0x3);
    TOSeqGetColorRGBA(1, D_00570438, (void *)&D_003241FC, (void *)&D_003241FE, (void *)&D_003241FD, (void *)&D_003241FF);
    TOSeqGetColorRGBA(1, D_00570448, (void *)&D_00324200, (void *)&D_00324202, (void *)&D_00324201, (void *)&D_00324203);
    TOSeqGetRect(1, D_00570458, (void *)&D_00324204, (void *)&D_00324206, (void *)&D_00324208, &dummy);
    TOSeqGetNum(1, D_00570468, (void *)&D_0032420A);
    TOSeqGetColor(1, D_00570478, (void *)&D_0032420C);
    TOSeqGetColor(1, D_00570488, (void *)&D_00324210);
    TOSeqGetPoint(1, D_00570498, (void *)&D_00324214, (void *)&D_00324216);
    TOSeqGetPoint(1, D_005704A8, (void *)&D_00324218, (void *)&D_0032421A);
    TOSeqGetPoint(1, D_005704B8, (void *)&D_0032421C, (void *)&D_0032421E);
    TOSeqGetPoint(1, D_005704C8, (void *)&D_00324220, (void *)&D_00324222);
    TOSeqGetPoint(1, D_005704D8, (void *)&D_00324224, (void *)&D_00324226);
    TOSeqGetPoint(1, D_005704E8, (void *)&D_00324228, (void *)&D_0032422A);
    TOSeqGetPoint(1, D_005704F8, (void *)&D_0032422C, (void *)&D_0032422E);
    TOSeqGetRect(1, D_00570508, (void *)&D_00324230, (void *)&D_00324232, (void *)&D_00324234, (void *)&D_00324236);
    TOSeqGetColor(1, D_00570518, (void *)&D_0032423C);
    TOSeqGetColor(1, D_00570528, (void *)&D_00324240);
    TOSeqGetNum(1, D_00570538, (void *)&D_00324238);
    TOSeqGetPoint(1, D_00570548, (void *)D_00324244, (void *)&_D_00324244_0x2);
    TOSeqGetRect(1, D_00570558, (void *)&D_00324248, (void *)&D_0032424A, (void *)&D_0032424C, &dummy);
    TOSeqGetColor(1, D_00570568, (void *)&D_00324250);
    TOSeqGetColor(1, D_00570578, (void *)&D_00324254);
    TOSeqGetRect(1, D_00570588, (void *)&D_0032425C, (void *)&D_0032425E, (void *)&D_00324260, &dummy);
    TOSeqGetColor(1, D_00570598, (void *)&D_00324264);
    TOSeqGetColor(1, D_005705A8, (void *)&D_00324268);
    TOSeqGetPoint(1, D_005705B8, (void *)&D_0032426C, (void *)&D_0032426E);
    TOSeqGetRect(1, D_005705C8, (void *)&D_00324270, (void *)&D_00324272, (void *)&D_00324274, &dummy);
    TOSeqGetColor(1, D_005705E0, (void *)&D_00324278);
    TOSeqGetColor(1, D_005705F8, (void *)&D_0032427C);
    TOSeqGetRect(1, D_00570610, (void *)&D_00324280, (void *)&D_00324282, (void *)&D_00324284, &dummy);
    TOSeqGetColor(1, D_00570620, (void *)&D_00324288);
    TOSeqGetColor(1, D_00570630, (void *)&D_0032428C);
    TOSeqGetPoint(1, D_00570640, (void *)&D_00324290, (void *)&D_00324292);
    TOSeqGetPoint(1, D_00570650, (void *)&D_00324294, (void *)&D_00324296);
    TOSeqGetColor(1, D_00570660, (void *)&D_00324298);
    TOSeqGetColor(1, D_00570660, (void *)&D_0032429C);
    TOSeqGetColor(1, D_00570670, (void *)&D_003242A0);
    TOSeqGetColor(1, D_00570680, (void *)&D_003242A4);
    TOSeqGetColor(1, D_00570690, (void *)&D_003242A8);
    TOSeqGetColor(1, D_00570690, (void *)&D_003242AC);
    TOSeqGetColor(1, D_005706A0, (void *)&D_003242B0);
    TOSeqGetColor(1, D_005706B0, (void *)&D_003242B4);
    TOSeqGetColor(1, D_005706C0, (void *)&D_003242C0);
    TOSeqGetColor(1, D_005706D0, (void *)&D_003242C4);
    TOSeqGetPoint(1, D_005706E0, (void *)D_003242C8, (void *)&_D_003242C8_0x2);
    TOSeqGetRect(1, D_005706F0, (void *)D_003242DC, (void *)&_D_003242DC_0x2, (void *)D_003242E0, (void *)&_D_003242E0_0x2);
    TOSeqGetColor(1, D_00570700, (void *)&D_003242E4);
    TOSeqGetColor(1, D_00570710, (void *)&D_003242E8);
    TOSeqGetRect(1, D_00570720, (void *)D_003242EC, (void *)&_D_003242EC_0x2, (void *)D_003242F0, (void *)&_D_003242F0_0x2);
    TOSeqGetColor(1, D_00570730, (void *)&D_003242F4);
    TOSeqGetColor(1, D_00570740, (void *)&D_003242F8);
    TOSeqGetPoint(1, D_00570750, (void *)D_003242FC, (void *)&_D_003242FC_0x2);
    TOSeqGetPoint(2, D_00570760, (void *)&D_00324300, (void *)&D_00324302);
    TOSeqGetColor(2, D_00570768, (void *)&D_00324304);
    TOSeqGetColor(2, D_00570770, (void *)&D_00324308);
    TOSeqGetPoint(2, D_00570778, (void *)&D_0032430C, (void *)&D_0032430E);
    TOSeqGetNum(2, D_00570780, (void *)&D_00324310);
    TOSeqGetNum(2, D_00570788, (void *)&D_00324312);
    TOSeqGetColor(2, D_00570790, (void *)&D_00324314);
    TOSeqGetColor(2, D_00570798, (void *)&D_00324318);
    TOSeqGetColor(2, D_005707A0, (void *)&D_0032431C);
    TOSeqGetColor(2, D_005707A8, (void *)&D_00324320);
    TOSeqGetPoint(2, D_005707B0, (void *)&D_00324324, (void *)&D_00324326);
    TOSeqGetRect(2, D_005707B8, (void *)&D_00324328, (void *)&D_0032432A, (void *)&D_0032432C, (void *)&D_0032432E);
    TOSeqGetColorRGBA(2, D_005707C0, (void *)&D_00324330, (void *)&D_00324331, (void *)&D_00324332, (void *)&D_00324333);
    TOSeqGetPoint(2, D_005707C8, (void *)&D_00324334, (void *)&D_00324336);
    TOSeqGetPoint(2, D_005707D0, (void *)&D_00324338, (void *)&D_0032433A);
    TOSeqGetPoint(2, D_005707D8, (void *)&D_0032433C, (void *)&D_0032433E);
    TOSeqGetPoint(2, D_005707E0, (void *)&D_00324340, (void *)&D_00324342);
    TOSeqGetRect(2, D_005707E8, (void *)&D_00324344, (void *)&D_00324346, (void *)&D_00324348, (void *)&D_0032434A);
    TOSeqGetColor(2, D_005707F0, (void *)&D_0032434C);
    TOSeqGetRect(2, D_005707F8, (void *)&D_00324350, (void *)&D_00324352, (void *)&D_00324354, (void *)&D_00324356);
    TOSeqGetRect(2, D_00570800, (void *)&D_00324358, (void *)&D_0032435A, (void *)&D_0032435C, (void *)&D_0032435E);
    TOSeqGetNum(2, D_00570808, (void *)&D_00324360);
    TOSeqGetPoint(2, D_00570810, (void *)&D_00324362, (void *)&D_00324364);
    TOSeqGetPoint(2, D_00570818, (void *)&D_00324366, (void *)&D_00324368);
    TOSeqGetPoint(2, D_00570820, (void *)&D_0032436A, (void *)&D_0032436C);
    TOSeqGetPoint(2, D_00570828, (void *)&D_0032436E, (void *)&D_00324370);
    TOSeqGetNum(2, D_00570830, (void *)&D_00324378);
}

void TOSetExeMessageWindowArea(int a)
{
    int i;

    if (a == 0) {
        for (i = 7; i >= 0; i--) {
            D_0068F0A8[i] = &D_0068EEE8[i];
        }
    } else {
        for (i = 7; i >= 0; i--) {
            D_0068F0A8[i] = &D_0068EFC8[i];
        }
    }
    func_0020A7A8(a);
    TOSetExeWindowArea(a);
    TOSetExeMessageArea(a);
}

void func_0020A758(void) {
}

/* DEBT(FAKE) */
s32 TOGetInternationalBaseDicType(void) {
    register s32 var_3 __asm__("$3");

    if (func_0020B850() == 0) {
        var_3 = (func_001BD360() == 0) ? 0 : 4;
    } else {
        var_3 = 4;
    }
    return var_3;
}

s32 func_0020A798(void)
{
    return D_0068EEDC;
}

void func_0020A7A8(s32 v)
{
    D_0068EEDC = v;
}

void func_0020A7B8(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        R4PT(i)->p10->w00 = 0;
        R4PT(i)->p14->w00 = 0;
        R4PT(i)->p18->b0 = 0;
        R4PT(i)->p10->state = 0;
        R4PT(i)->p14->state = 0;
        R4PT(i)->p18->b1 = 0;
    }
}

void func_0020A818(void) {
}

int TOInitMessageWindow(int i) /* DEBT(TYPE): declared int, no return value in the asm */
{
    func_002EF0D0(D_0068F0A8[i], 0, 0x1C);
    R4PT(i)->p10 = func_00209538(i);
    R4PT(i)->p14 = func_002043D0(i);
    R4PT(i)->p18 = func_002043E8(i);
    func_002EF0D0(R4PT(i)->p10, 0, 0x5C);
    func_00204168(i);
    R4PT(i)->p10->h2 = i;
    R4PT(i)->p14->id = i;
    D_0068F0A8[i]->w04 = -1;
    R4PT(i)->p14->fDC = (MenuFn)func_00207AA0;
}

int TOOpenMessageWindow(int w)
{
    D_0068F0A8[w]->w00 = 1;
    TOOpenWindow(w);
    TOOpenMessage(w);
}

void TOCloseMessageWindow(int i)
{
    TOCloseWindow(i);
    TOCloseMessage(i);
}

void func_0020A948(int i)
{
    R4PT(i)->p10->w00 = 0;
    R4PT(i)->p14->w00 = 0;
    R4PT(i)->p18->b0 = 0;
    R4PT(i)->p10->state = 0;
    R4PT(i)->p14->state = 0;
    R4PT(i)->p18->b1 = 0;
}

void func_0020A998(void)
{
    int i;
    int r;

    TOGetPadStatus();
    for (i = 0; i < 8; i++) {
        if (D_0068F0A8[i]->w00 != 0) {
            r = TOControlWindow(i);
            TOControlMessage(i);
            if (r != 0) {
                TOSetMessageFunc(i, R4PT(i)->p10->state);
            }
            if (D_0068F0A8[i]->w06 == 1) {
                TOGetControlPadStatus(i);
            }
        }
    }
}

s32 *_m2c_TODrawMessageWindow_MsGetSaveMenu() __asm__("MsGetSaveMenu");
void _m2c_TODrawMessageWindow_TODrawBtlWindow() __asm__("TODrawBtlWindow");
void _m2c_TODrawMessageWindow_TODrawKick() __asm__("TODrawKick");
void _m2c_TODrawMessageWindow_TODrawMessage(s32) __asm__("TODrawMessage");
void _m2c_TODrawMessageWindow_TODrawWindow(s32) __asm__("TODrawWindow");
void _m2c_TODrawMessageWindow_TOInitAddPkt() __asm__("TOInitAddPkt");
void _m2c_TODrawMessageWindow_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
void _m2c_TODrawMessageWindow_TOSetAddPkt() __asm__("TOSetAddPkt");
void _m2c_TODrawMessageWindow_TOSetPktBuffAdrs(s32, s32, s32) __asm__("TOSetPktBuffAdrs");
void _m2c_TODrawMessageWindow_TOTransTexture() __asm__("TOTransTexture");
void _m2c_TODrawMessageWindow_func_001EF940() __asm__("func_001EF940");
void _m2c_TODrawMessageWindow_func_001EF978() __asm__("func_001EF978");
void _m2c_TODrawMessageWindow_func_001EFB08() __asm__("func_001EFB08");
void _m2c_TODrawMessageWindow_func_001FC3C8(s32, s32) __asm__("func_001FC3C8");
void _m2c_TODrawMessageWindow_func_0020B520(void *) __asm__("func_0020B520");
void _m2c_TODrawMessageWindow_func_0020E5F0() __asm__("func_0020E5F0");
void _m2c_TODrawMessageWindow_func_0020EC88() __asm__("func_0020EC88");
void TODrawMessageWindow(void) {
    u8 sp[0x10];
    R4Ptrs **var_17;
    s16 temp_2;
    s32 var_16;
    MenuCmd *temp_4;

    var_16 = 0;
    _m2c_TODrawMessageWindow_TOSetAddPkt();
    _m2c_TODrawMessageWindow_TOTransTexture();
    _m2c_TODrawMessageWindow_TOSetPktBuffAdrs(0x01F00000, 0x100000, 0xF0000);
    _m2c_TODrawMessageWindow_func_001EF940();
    _m2c_TODrawMessageWindow_func_0020B520(sp);
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_func_001EFB08();
    var_17 = D_0068F0A8;
    do {
        if ((((s32) *_m2c_TODrawMessageWindow_MsGetSaveMenu() >> 9) & 1) || (temp_4 = (*var_17)->p14, (temp_4->x08 != 2)) || ((temp_2 = temp_4->h1A, (temp_2 != 1)) && (temp_2 != 3)) || (temp_4->h10 == 0x4000) || (temp_4->h0C != 0) || (D_0068EEDC != 0)) {
            _m2c_TODrawMessageWindow_TODrawWindow(var_16);
            _m2c_TODrawMessageWindow_TODrawMessage(var_16);
        }
        var_16 += 1;
        var_17++;
    } while (var_16 < 8);
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_TODrawBtlWindow();
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindow_func_0020E5F0();
    _m2c_TODrawMessageWindow_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    if (D_00323958 != 0) {
        _m2c_TODrawMessageWindow_func_001FC3C8(0xA, 0x172);
    }
    _m2c_TODrawMessageWindow_func_001EF978();
    _m2c_TODrawMessageWindow_TODrawKick();
    D_003238D0.pad00[0] = 1;
    _m2c_TODrawMessageWindow_TOInitAddPkt();
    _m2c_TODrawMessageWindow_func_0020EC88();
}

void func_0020AC10(void)
{
    int i;
    int r;

    for (i = 0; i < 8; i++) {
        if (D_0068F0A8[i]->w00 != 0) {
            r = TOControlWindow(i);
            TOControlMessage(i);
            if (r != 0) {
                TOSetMessageFunc(i, R4PT(i)->p10->state);
            }
            if (D_0068F0A8[i]->w06 == 1) {
                TOGetControlPadStatus(i);
            }
        }
    }
}

s32 *_m2c_TODrawMessageWindowForMenu_MsGetSaveMenu() __asm__("MsGetSaveMenu");
s32 _m2c_TODrawMessageWindowForMenu_TODrawKick() __asm__("TODrawKick");
s32 _m2c_TODrawMessageWindowForMenu_TODrawMessage(s32) __asm__("TODrawMessage");
s32 _m2c_TODrawMessageWindowForMenu_TODrawWindow(s32) __asm__("TODrawWindow");
s32 _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
s32 _m2c_TODrawMessageWindowForMenu_TOSetPktBuffAdrs(s32, s32, s32) __asm__("TOSetPktBuffAdrs");
s32 _m2c_TODrawMessageWindowForMenu_func_001EF940() __asm__("func_001EF940");
s32 _m2c_TODrawMessageWindowForMenu_func_001EF978() __asm__("func_001EF978");
s32 _m2c_TODrawMessageWindowForMenu_func_001EFB08() __asm__("func_001EFB08");
s32 _m2c_TODrawMessageWindowForMenu_func_0020B520(void *) __asm__("func_0020B520");
void TODrawMessageWindowForMenu(void) {
    u8 sp[0x10];
    R4Ptrs **var_17;
    s16 temp_2;
    s32 var_16;
    MenuCmd *temp_4;

    var_16 = 0;
    _m2c_TODrawMessageWindowForMenu_TOSetPktBuffAdrs(0x01F00000, 0x100000, 0xF0000);
    _m2c_TODrawMessageWindowForMenu_func_001EF940();
    _m2c_TODrawMessageWindowForMenu_func_0020B520(sp);
    _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindowForMenu_func_001EFB08();
    var_17 = D_0068F0A8;
    do {
        if ((((s32) *_m2c_TODrawMessageWindowForMenu_MsGetSaveMenu() >> 9) & 1) || (temp_4 = (*var_17)->p14, (temp_4->x08 != 2)) || ((temp_2 = temp_4->h1A, (temp_2 != 1)) && (temp_2 != 3)) || (temp_4->h10 == 0x4000) || (temp_4->h0C != 0) || (D_0068EEDC != 0)) {
            _m2c_TODrawMessageWindowForMenu_TODrawWindow(var_16);
            _m2c_TODrawMessageWindowForMenu_TODrawMessage(var_16);
        }
        var_16 += 1;
        var_17++;
    } while (var_16 < 8);
    _m2c_TODrawMessageWindowForMenu_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_TODrawMessageWindowForMenu_func_001EF978();
    _m2c_TODrawMessageWindowForMenu_TODrawKick();
    D_003238D0.pad00[0] = 1;
}

void TOAllCloseMessageWindow(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        TOCloseWindow(i);
        TOCloseMessage(i);
    }
}

void func_0020AE58(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        R4PT(i)->p10->w00 = 0;
        R4PT(i)->p14->w00 = 0;
        R4PT(i)->p18->b0 = 0;
        R4PT(i)->p10->state = 0;
        R4PT(i)->p14->state = 0;
        R4PT(i)->p18->b1 = 0;
    }
}

void func_0020AEB8(int i, int mode, int v)
{
    func_002096D0(i, mode);
    TOSetMessageType(i, v);
}

void TOSetMessageWindowPosition(int i, int align, int x, int y)
{
    int k;
    s16 w;
    s16 h;
    int maxy;
    int tw;
    int th;

    R4PT(i)->hC = align;
    R4PT(i)->h8 = x;
    R4PT(i)->hA = y;
    R4PT(i)->p14->h18 = align;
    R4PT(i)->p14->h14 = x;
    R4PT(i)->p14->h16 = y;

    k = R4PT(i)->p10->w04;
    tw = R4PT(i)->p14->w;
    th = R4PT(i)->p14->h;
    w = D_00323848[k].x + D_00323848[k].w;
    h = D_00323848[k].y + D_00323848[k].h;
    w += tw;
    h += th;

    switch (align) {
    case 0:
        break;
    case 4:
        x -= (s16)(w / 2);
        y -= (s16)(h / 2);
        break;
    case 2:
        x -= w;
        break;
    case 3:
        x -= w;
        /* fallthrough */
    case 1:
        y -= h;
        break;
    }

    w = R4_CLAMP(w, 0, 0x1FF);
    x = R4_CLAMP(x, 0, 0x1FF - w);
    if (TOGetMessageWindowMode() == 1) {
        h = R4_CLAMP(h, 4, 0x7F);
        y = R4_CLAMP(y, 4, 0x7B - h);
    } else {
        h = R4_CLAMP(h, 4, 0x19F);
        y = R4_CLAMP(y, 4, 0x19B - h);
    }
    func_0020B308(i, x, y, w, h);
}

void TOSetMessageWindowPositionRect(int i, int align, int x, int y, int w, int h)
{
    switch (align) {
    case 0:
        break;
    case 4:
        x -= w / 2;
        y -= h / 2;
        break;
    case 2:
        x -= w;
        break;
    case 3:
        x -= w;
        /* fallthrough */
    case 1:
        y -= h;
        break;
    }
    w = R4_CLAMP(w, 0, 0x1FF);
    h = R4_CLAMP(h, 4, 0x19B);
    x = R4_CLAMP(x, 0, 0x1FF - w);
    y = R4_CLAMP(y, 4, 0x19B - h);
    func_0020B308(i, x, y, w, h);
}

int func_0020B238(int font, u8 *text)
{
    s16 size[2];
    int k = R4PT(font)->p10->w04;
    s16 x = D_00323848[k].x + D_00323848[k].w;
    s16 y = D_00323848[k].y + D_00323848[k].h;

    _TOGetMessageWH(font, text, &size[0], &size[1], R4PT(font)->p14->h1A, 0);
    x += R4PT(font)->p14->h3C;
    y += R4PT(font)->p14->h3E;
    return (y << 16) | x;
}

void func_0020B308(int id, int x, int y, int w, int h)
{
    func_002096F0(id, x, y, w, h);
    if (TOGetMessageWindowMode() == 1) {
        func_00205A10(id, x, y, w, h);
    } else {
        int k = R4PT(id)->p10->w04;
        int dx = (s16)D_00323848[k].x;
        int dy = (s16)D_00323848[k].y;

        func_00205A10(id, x + dx, y + dy, w - (dx + (s16)D_00323848[k].w), h - (dy + (s16)D_00323848[k].h));
    }
}

void TOSetSelectMessageWindow(int i, int a, int b, int c)
{
    R4PT(i)->p14->w1C = 1;
    R4PT(i)->p18->b1 = 0;
    R4PT(i)->p18->b2 = a;
    R4PT(i)->p18->b3 = b;
    R4PT(i)->p18->b7 = 0;
    R4PT(i)->p18->b6 = c;
    R4PT(i)->p14->fDC = TOFuncPadMessageSelect;
}

void func_0020B478(int i, int x, int y, int v)
{
    int n;

    if (x < 8) {
        n = x;
        if (n < 0) {
            n = 0;
        }
    } else {
        n = 7;
    }
    if (y < 8) {
        if (y < 0) {
            y = 0;
        }
    } else {
        y = 7;
    }
    R4PT(i)->p18->b2 = n;
    R4PT(i)->p18->b3 = y;
    R4PT(i)->p18->w10 = v;
    R4PT(i)->p14->fDC = TOFuncPadMessageInputValue;
    R4PT(i)->p18->wC = v;
}

void TOSetMessageWindowPriority(int i, int v)
{
    D_0068F0A8[i]->w04 = v;
}

void func_0020B520(s16 *out)
{
    struct {
        s16 id;
        s16 pri;
    } arr[8], tmp;
    int i, j;

    for (i = 0; i < 8; i++) {
        arr[i].id = 0x7FFF;
        arr[i].pri = 0x7FFF;
    }
    for (i = 0; i < 8; i++) {
        R4Ptrs *p = D_0068F0A8[i];

        if (p->w00 == 1) {
            arr[i].id = i;
            arr[i].pri = p->w04;
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr[j].pri < arr[i].pri) {
                tmp.id = arr[i].id;
                tmp.pri = arr[i].pri;
                arr[i].id = arr[j].id;
                arr[i].pri = arr[j].pri;
                arr[j].id = tmp.id;
                arr[j].pri = tmp.pri;
            }
        }
    }
    func_002EF0D0(out, -1, 0x10);
    for (i = 0; i < 8 && arr[i].id != 0x7FFF; i++) {
        *out++ = arr[i].id;
    }
}

int func_0020B6A8(int i)
{
    int j;

    for (j = 0; j < 8; j++) {
        D_0068F0A8[j]->w06 = 0;
    }
    D_0068F0A8[i]->w06 = 1;
}

void func_0020B6F0(s32 v)
{
    D_0068EEE0 = v;
}

s32 TOGetMessageWindowMode(void)
{
    return D_0068EEE0;
}

void func_0020B710(void)
{
    switch (FFXGetLang()) {
    case 0:
        switch (func_002D9880()) {
        case 0:
            D_0068F190 = 0;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        case 1:
            D_0068F190 = 0x11;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        case 2:
            D_0068F190 = 0x12;
            D_0068F194 = 1;
            D_0068F198 = 0;
            break;
        }
        break;
    case 1:
        D_0068F190 = 1;
        D_0068F194 = 0;
        D_0068F198 = 0;
        break;
    case 6:
        D_0068F190 = 2;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 2:
        D_0068F190 = 3;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 3:
        D_0068F190 = 4;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 4:
        D_0068F190 = 5;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    case 5:
        D_0068F190 = 6;
        D_0068F194 = 0;
        D_0068F198 = 1;
        break;
    }
}

s32 func_0020B850(void)
{
    return D_0068F190;
}

s32 TOGetFFXLangSwapFlag(void)
{
    return D_0068F194;
}

s32 TOGetFFXVideoMode(void)
{
    return D_0068F198;
}

s32 func_0020B880(int i)
{
    return D_0066B530[i].w0;
}

s32 TOGetFontWidthTblAdrs(int i)
{
    return D_0066B530[i].w4;
}

s32 func_0020B8B0(void)
{
    return D_0066B590;
}

u32 func_0020B8C0(void)
{
    return D_0066B594;
}

s32 func_0020B8D0(void)
{
    return D_0066B58C;
}

s32 func_0020B8E0(void)
{
    return D_0066B588;
}

s32 func_0020B8F0(void)
{
    return D_0066B598;
}

void *func_0020B900(void)
{
    return &D_0066B5A0;
}

void *func_0020B910(void)
{
    return &D_0066BDA0;
}

void *func_0020B920(void)
{
    return &D_00670DA0;
}

void TOSwapInternationalEnvInit(int a)
{
    MsSetSaveConfigEnglish_void(a);
    D_003238A8 = 0;
    switch (a) {
    case 1:
        D_003238AC = 4;
        break;
    default:
        D_003238AC = 0x12;
        break;
    }
    D_003238B0 = 0;
    D_003238B4 = 0;
    D_003238B8 = 0;
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
s32 TOSwapInternationalEnvExec(void)
{
    D_003238B4 = 1;
    func_0020CC20((s8 *) D_003238AC, 0xB, func_0020B8B0());
    func_0020CC20((s8 *) D_003238AC, 0xA, func_0020B8C0());
    func_0020CC20((s8 *) D_003238AC, 0xF, func_0020B8D0());
    func_0020CC20((s8 *) D_003238AC, 0xE, func_0020B8E0());
    func_0020CC20((s8 *) D_003238AC, 8, func_0020B8F0());
    func_0020CC20((s8 *) D_003238AC, 6, D_00324140);
    func_0020CC20((s8 *) D_003238AC, 5, TOGetFFXToAlbhedTblAdrs());
    func_0020CC20((s8 *) D_003238AC, 7, D_00323960);
    func_0020DC78(2);
    func_0020CC20((s8 *) D_003238AC, 0x16, D_00670DA0);
    TkMenuSetSceneDataAdrs(2, D_00670DA0);
    TOSeqInitParam();
    MsBattleReadData();
    D_003238B4 = 0;
    D_003238B0 = 1;
    return 1;
}

s32 TOSwapInternationalEnvExecNonBlock(void)
{
    s32 *st = &D_003238A8;

    switch (*st) {
    case 0:
        D_003238B4 = 1;
        *st = 1;
        break;
    case 1:
        *st = 2;
        break;
    case 2:
        func_0020CD30(D_003238AC, 0xB, func_0020B8B0());
        *st = 3;
        break;
    case 3:
        if (func_0020CDB8() == 0) {
            *st = 4;
        }
        break;
    case 4:
        func_0020CD30(D_003238AC, 0xA, func_0020B8C0());
        *st = 5;
        break;
    case 5:
        if (func_0020CDB8() == 0) {
            *st = 6;
        }
        break;
    case 6:
        func_0020CD30(D_003238AC, 0xF, func_0020B8D0());
        *st = 7;
        break;
    case 7:
        if (func_0020CDB8() == 0) {
            *st = 8;
        }
        break;
    case 8:
        func_0020CD30(D_003238AC, 0xE, func_0020B8E0());
        *st = 9;
        break;
    case 9:
        if (func_0020CDB8() == 0) {
            *st = 10;
        }
        break;
    case 10:
        func_0020CD30(D_003238AC, 8, func_0020B8F0());
        *st = 11;
        break;
    case 11:
        if (func_0020CDB8() == 0) {
            *st = 12;
        }
        break;
    case 12:
        func_0020CD30(D_003238AC, 6, (int)D_00324140); /* DEBT(CAST): buffer address passed as int */
        *st = 13;
        break;
    case 13:
        if (func_0020CDB8() == 0) {
            *st = 14;
        }
        break;
    case 14:
        func_0020CD30(D_003238AC, 5, (int)TOGetFFXToAlbhedTblAdrs()); /* DEBT(CAST): buffer address passed as int */
        *st = 15;
        break;
    case 15:
        if (func_0020CDB8() == 0) {
            *st = 16;
        }
        break;
    case 16:
        func_0020CD30(D_003238AC, 7, (int)D_00323960); /* DEBT(CAST): buffer address passed as int */
        *st = 17;
        break;
    case 17:
        if (func_0020CDB8() == 0) {
            *st = 18;
        }
        break;
    case 18:
        func_0020DC78(2);
        *st = 19;
        /* fallthrough */
    case 19:
        func_0020CD30(D_003238AC, 0x16, (int)D_00670DA0); /* DEBT(CAST): buffer address passed as int */
        *st = 20;
        break;
    case 20:
        if (func_0020CDB8() == 0) {
            *st = 21;
        }
        break;
    case 21:
        TkMenuSetSceneDataAdrs(2, D_00670DA0);
        TOSeqInitParam();
        *st = 22;
        break;
    case 22:
        *st = 23;
        D_003238B8 = 0;
        break;
    case 23:
        if (MsBattleReadDataNB(D_003238B8) != 0) {
            *st = 24;
        } else {
            *st = 26;
        }
        break;
    case 24:
        if (GetCD()->f8(1) == 0) {
            *st = 25;
        }
        break;
    case 25:
        *st = 23;
        D_003238B8++;
        break;
    case 26:
        *st = 27;
        break;
    case 27:
        *st = 28;
        break;
    case 28:
        D_003238B0 = 1;
        D_003238B4 = 0;
        break;
    }
    if (D_00323958) {
        TODapsSetPos(0x1E, 0x1E);
        TODapsPrintf(D_005708A0, D_003238A8);
        TODapsPrintf(D_005708B0, D_003238B8);
    }
    return D_003238B0;
}

s32 func_0020BED0(void)
{
    return D_003238B4;
}

int func_0020BEE0(void)
{
    int r = TOGetFFXLangSwapFlag();

    if (r == 1 && func_001BD360() == r) {
        return 4;
    }
    return 0x12;
}

void TOSwapInternationalEnvInitMenu(int a)
{
    MsSetSaveConfigEnglish_void(a);
    D_003238BC = 0;
    switch (a) {
    case 1:
        D_003238C0 = 4;
        break;
    default:
        D_003238C0 = 0x12;
        break;
    }
    D_003238C4 = 0;
}

int TOSwapInternationalEnvExecMenu(void)
{
    s32 *st = &D_003238BC;

    switch (*st) {
    case 0:
        *st = 1;
        break;
    case 1:
        *st = 2;
        break;
    case 2:
        func_0020CD30(D_003238C0, 0xD, 0x1D3EB00);
        *st = 3;
        break;
    case 3:
        if (func_0020CDB8() == 0) {
            *st = 6;
        }
        break;
    case 6:
        D_003238C4 = 1;
        break;
    }
    return D_003238C4;
}
