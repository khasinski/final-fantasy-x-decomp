/* tu_343 0x2d81e8-0x2d8780: low; ~Snd (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"

int SndSyncMusicStandby(int a)
{
    return func_002D5EA8(a);
}

void SndMusicStart(u32 id)
{
    if (id < 0x100) {
        func_002D6260(id);
        SndSyncMusicStandby(1);
        func_002D62F8(id);
        iMusicStart(id);
        func_002D8618(id, 0x7F);
    }
}

void func_002D8268(u32 id, int a)
{
    if (id < 0x100) {
        func_002D6260(id);
        SndSyncMusicStandby(1);
        func_002D62F8(id);
        func_00252210(id, a);
        func_002D8618(id, 0x7F);
    }
}

void func_002D82E0(u32 id)
{
    if (id < 0x100) {
        func_002D6260(id);
        SndSyncMusicStandby(1);
        func_002D62F8(id);
        func_00252258(id);
        func_002D8618(id, 0x7F);
    }
}

/* Module: sound driver wrappers (calls into the 0x25xxxx sound library; handle = bit31 flag + 31 bit id) */

void SndMusicVolumeFadeOut(u32 id, int b)
{
    if (id < 0x100) {
        iMusicVolumeFadeOut(id, b);
        func_002D62B8(id);
        func_002D6260(id);
    }
}

void SndSepVolumeFadeOut(int handle, int a)
{
    SqsSeVolumeFadeOut(func_002D7090(handle), func_002D70A0(handle), a);
}

void SndMusicCrossStart(u32 id, int a)
{
    if (id != (u32)SndGetNowPlayMusic()) {
        if (id >= 0x100) {
            SndMusicVolumeFadeOut(SndGetNowPlayMusic(), *(u32 *)&a);
        } else {
            if (SndGetNowPlayMusic() >= 0) {
                SndGetNowPlayMusic();
            }
            func_002D6260(id);
            SndSyncMusicStandby(1);
            func_002D62F8(id);
            func_002522A0(id, a);
        }
    }
}

void func_002D8478(int a)
{
    iMusicTempoDirect(a);
}

void func_002D8480(int a, int b)
{
    iMusicTempoTranslate(a, b);
}

void func_002D8488(u8 a, int b)
{
    iMusicPitchDirect(a, b);
}

void func_002D8490(int a, u8 b, int c)
{
    func_00252430(a, b, c);
}

void SndVagStreamVolumeDirect(int a)
{
    iVoiceVolumeDirect(func_0014AC20() ? a : 0);
}

void func_002D84C8(int a, int b)
{
    iVoiceVolumeTranslate(a, func_0014AC20() ? b : 0);
}

void func_002D8508(int a)
{
    func_00252CB0(a);
}

void func_002D8510(int a, int b)
{
    func_00252CD8(a, b);
}

void SndMusicStop(u32 id)
{
    if (id < 0x100) {
        iMusicStop(id);
        func_002D62B8(id);
    }
}

void SndMusicClear(u32 id)
{
    if (id < 0x100) {
        iMusicClear(id);
        func_002D62B8(id);
    }
}

void SndDataSendSync(int a)
{
    D_0078BA18 = SqsDataSendingCompleted(a);
}

void func_002D85D0(void)
{
    func_00252460();
}

void SndMusicReplayPointClear(u32 id)
{
    func_00252488(id);
}

void func_002D85E0(int a)
{
    func_002522E8(a);
}

void func_002D85E8(int a, int b)
{
    func_00252310(a, b);
}

void func_002D85F0(u32 id, int b, int c)
{
    if (D_0078BB9C != 0) {
        c = 0;
    }
    if (id < 0x100) {
        iMusicVolumeTranslate(id, b, c);
    }
}

void func_002D8618(u32 id, int a)
{
    if (D_0078BB9C != 0) {
        a = 0;
    }
    if (id < 0x100) {
        iMusicVolumeDirect(id, a);
    }
}

int SndIsSepPlay(int handle)
{
    int id;

    id = func_002D70A0(handle);
    if (func_002D7090(handle) == 0) {
        return func_002527F8(id);
    }
    return func_00252830(id);
}

void func_002D8698(int handle, s8 a, int b)
{
    func_00252A88(func_002D7090(handle), func_002D70A0(handle), (u8)a, b);
}

void func_002D8700(int handle, int a, s8 b, int c)
{
    func_00252AB8(func_002D7090(handle), func_002D70A0(handle), a, b, c);
}

void func_002D8778(int a)
{
    func_00251CA0(a);
}
