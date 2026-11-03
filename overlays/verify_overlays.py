#!/usr/bin/env python3
"""Compile decompiled EE battle-effect overlays with ee-gcc 2.9-991111-01 (-O2 -G0)
and verify byte-identical .text and full container reconstruction against
build/overlay-audit/overlay-group11-fileXXXXX.bin.

Can be run either on the host (automatically invokes Docker ffx-decomp) or inside
the ffx-decomp container.
"""
import hashlib
import os
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x01B00000

RESIDENT_SYMS = {
    "D_00313CB0": 0x00313CB0,
    "D_00313E50": 0x00313E50,
    "func_0019FC00": 0x0019FC00,
    "rcefMainProcRunAfter": 0x0019FDF0,
    "func_0019FE38": 0x0019FE38,
    "func_0019FE48": 0x0019FE48,
    "func_0019FE58": 0x0019FE58,
    "func_0019FF90": 0x0019FF90,
    "rcefMainKickPar": 0x0019FFD0,
    "func_001A1378": 0x001A1378,
    "func_001A13A0": 0x001A13A0,
    "func_001A1420": 0x001A1420,
    "func_001A1D08": 0x001A1D08,
    "func_001A1D50": 0x001A1D50,
    "func_001A1DF0": 0x001A1DF0,
    "func_001A2058": 0x001A2058,
    "func_001A2098": 0x001A2098,
    "func_001A20D8": 0x001A20D8,
    "func_001A2148": 0x001A2148,
    "func_001A21E0": 0x001A21E0,
    "func_001A2210": 0x001A2210,
    "func_001A2B58": 0x001A2B58,
    "func_001A2B68": 0x001A2B68,
    "func_001A2B80": 0x001A2B80,
    "func_001A36D8": 0x001A36D8,
    "func_001A37F0": 0x001A37F0,
    "func_001A3800": 0x001A3800,
    "func_001A4288": 0x001A4288,
    "func_001A42D0": 0x001A42D0,
    "func_001A4310": 0x001A4310,
    "func_001A9EE0": 0x001A9EE0,
    "func_001AAC18": 0x001AAC18,
    "func_001AACA0": 0x001AACA0,
    "MsGetChrHandle": 0x001B4E58,
    "MsGetChrMotionSignal": 0x001B5620,
    "MsGetChrHeight": 0x001B63B8,
    "MsGetChrWidth": 0x001B6410,
    "func_001B6790": 0x001B6790,
    "MsSetChrPos": 0x001B6BB0,
    "func_001C5E90": 0x001C5E90,
    "MsEffectMotionLevel": 0x001CDAF8,
    "MsEffectReady": 0x001CDC58,
    "MsEffectTerminate": 0x001CDDD8,
    "MsGetEff2Chr": 0x001CE048,
    "func_001CE050": 0x001CE050,
    "MsEffectEndMotion": 0x001CE2F0,
    "MsGetTargetList": 0x001E53D0,
    "func_001072F8": 0x001072F8,
    "func_00107428": 0x00107428,
    "Ch_OptposGet": 0x00108910,
    "Ch_SetShadeCol": 0x001104C8,
    "Ch_EnBodyHit": 0x001105E0,
    "func_00110718": 0x00110718,
    "Ch_SetMotionSpeed": 0x00110820,
    "Sg_GetCurExecFrames": 0x00116068,
    "Ch_ClutDispose": 0x001178E0,
    "Ch_ClutCreate": 0x00117A68,
    "func_00120108": 0x00120108,
    "func_0013B150": 0x0013B150,
    "func_0014AA50": 0x0014AA50,
    "func_00266F40": 0x00266F40,
    "pppMemAlloc": 0x00266FA0,
    "_pppAllFreePObject": 0x00267530,
    "pppSetMatrix": 0x002675B0,
    "_pppStartPart": 0x00267658,
    "_pppInitData": 0x002678E0,
    "pppInitEnv": 0x00267A68,
    "_pppRunPart": 0x00267FA0,
    "func_0026BDE0": 0x0026BDE0,
    "func_00293CD8": 0x00293CD8,
    "func_00293D48": 0x00293D48,
    "op_oef2_sound_cue_multi": 0x002944B0,
    "op_oef2_se_on": 0x00294B70,
    "func_00294CD8": 0x00294CD8,
    "opu_init": 0x00296CB8,
    "opu_test_data_read": 0x0029A8A8,
    "func_0029B830": 0x0029B830,
    "op_chara_hsv_size_get": 0x002A3B48,
    "func_002A3BD8": 0x002A3BD8,
    "op_chara_hsv": 0x002A3CA0,
    "func_002AC750": 0x002AC750,
    "func_002B22F8": 0x002B22F8,
    "func_002B2F30": 0x002B2F30,
    "op_oef2_set2": 0x002B4980,
    "op_oef2_a_get": 0x002B49A0,
    "op_oef2_texture_load": 0x002CF528,
    "op_oef2_clut_load": 0x002CF810,
    "func_002D02E8": 0x002D02E8,
    "func_002DCE38": 0x002DCE38,
    "func_002DCEC8": 0x002DCEC8,
    "func_002DCFF8": 0x002DCFF8,
    "func_002DD038": 0x002DD038,
    "func_002DD068": 0x002DD068,
    "func_002EA328": 0x002EA328,
    "dpadd": 0x002EBBB0,
    "dpmul": 0x002EBC70,
    "dptofp": 0x002EC440,
    "fptodp": 0x002ED038,
    "func_002EF0D0": 0x002EF0D0,
    "D_003F3944": 0x003F3944,
    "D_004F3FD0": 0x004F3FD0,
    "D_004F4010": 0x004F4010,
    "D_004F4610": 0x004F4610,
    "D_0054D5E8": 0x0054D5E8,
    "D_00551C98": 0x00551C98,
    "D_00551CA0": 0x00551CA0,
    "D_006A3924": 0x006A3924,
    "D_006A3930": 0x006A3930,
    "D_006A3970": 0x006A3970,
    "D_006A39B0": 0x006A39B0,
    "D_006A3A70": 0x006A3A70,
    "D_006A3AB0": 0x006A3AB0,
    "D_006A3BC4": 0x006A3BC4,
    "D_006A3BCC": 0x006A3BCC,
    "D_00703E20": 0x00703E20,
    "D_00764990": 0x00764990,
    "D_007649A0": 0x007649A0,
    "D_2008250": 0x02008250,
    "func_206C3B8": 0x0206C3B8,
    "func_206C3F8": 0x0206C3F8,
}

# (cid, text_start, D_01B00648, D_01B0A578, D_01B0F8D0, D_01B78720)
TU0_9065_LAYOUTS = [
    (9065, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0F8D0, 0x01B78720),
    (9066, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F800, 0x01B74800),
    (9067, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F800, 0x01B74B40),
    (9068, 0x01B006E8, 0x01B004B8, 0x01B0A3E8, 0x01B0F740, 0x01B75F90),
    (9069, 0x01B007D8, 0x01B005A8, 0x01B0A4D8, 0x01B0F630, 0x01B7A9B0),
    (9070, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F790, 0x01B4DEF0),
    (9071, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F590, 0x01B52550),
    (9072, 0x01B00758, 0x01B00530, 0x01B0A458, 0x01B0F7B0, 0x01B57820),
    (9073, 0x01B00758, 0x01B00530, 0x01B0A458, 0x01B0F5B0, 0x01B5C1B0),
    (9074, 0x01B00788, 0x01B00558, 0x01B0A488, 0x01B0F7E0, 0x01B5EE20),
    (9075, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F600, 0x01B63620),
    (9078, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F800, 0x01B95A70),
    (9079, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F600, 0x01B95D70),
    (9080, 0x01B006B8, 0x01B00490, 0x01B0A3B8, 0x01B0F710, 0x01B97120),
    (9081, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0F560, 0x01B9B990),
    (9082, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F790, 0x01B6F200),
    (9083, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F590, 0x01B73990),
    (9113, 0x01B00B48, 0x01B00918, 0x01B0A848, 0x01B0D580, 0x01B725D0),
    (9117, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F880, 0x01BB08A0),
    (9162, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F680, 0x01BB06D0),
    (9163, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0CCE0, 0x01B92650),
    (9166, 0x01B00AC8, 0x01B008A0, 0x01B0A7C8, 0x01B0F990, 0x01B5D050),
    (9167, 0x01B00668, 0x01B00440, 0x01B0A368, 0x01B0F530, 0x01B59830),
    (9174, 0x01B006B8, 0x01B00490, 0x01B0A3B8, 0x01B0F580, 0x01B3B380),
    (9175, 0x01B006B8, 0x01B00490, 0x01B0A3B8, 0x01B0F580, 0x01B3B380),
    (9180, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F670, 0x01B836B0),
    (9181, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0F670, 0x01B836B0),
    (9182, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F600, 0x01B87F20),
    (9183, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0F600, 0x01B87F20),
    (9184, 0x01B00788, 0x01B00558, 0x01B0A488, 0x01B0F650, 0x01B87A90),
    (9185, 0x01B00788, 0x01B00558, 0x01B0A488, 0x01B0F650, 0x01B87A90),
    (9186, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0F5D0, 0x01B88930),
    (9187, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0F5D0, 0x01B88930),
    (9195, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0D780, 0x01BBD000),
    (9201, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F880, 0x01BB08A0),
    (9202, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F880, 0x01BB08A0),
    (9204, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CEB0, 0x01B799B0),
    (9205, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CF80, 0x01B79EC0),
    (9211, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CF30, 0x01B79960),
    (9213, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D800, 0x01B99FE0),
    (9219, 0x01B006B8, 0x01B00490, 0x01B0A3B8, 0x01B0F580, 0x01B746D0),
    (9234, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0D0B0, 0x01B84F00),
    (9252, 0x01B00CF8, 0x01B00AD0, 0x01B0A9F8, 0x01B0CD80, 0x01BD9FF0),
    (9279, 0x01B005C8, 0x01B003A0, 0x01B0A2C8, 0x01B0F490, 0x01B54FB0),
    (9280, 0x01B005C8, 0x01B003A0, 0x01B0A2C8, 0x01B0F490, 0x01B54FB0),
    (9281, 0x01B00758, 0x01B00530, 0x01B0A458, 0x01B0F620, 0x01B58AC0),
    (9282, 0x01B00758, 0x01B00530, 0x01B0A458, 0x01B0F620, 0x01B58AC0),
    (9300, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CFB0, 0x01B86500),
    (9303, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0CDC0, 0x01BAB780),
    (9305, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0CE10, 0x01BAB850),
    (9308, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0CF00, 0x01BBD410),
    (9309, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0D240, 0x01BA4120),
    (9321, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0D7E0, 0x01BAD5B0),
    (9322, 0x01B007D8, 0x01B005A8, 0x01B0A4D8, 0x01B0D050, 0x01B84B10),
    (9323, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0D110, 0x01B79D00),
    (9324, 0x01B007D8, 0x01B005A8, 0x01B0A4D8, 0x01B0D260, 0x01BBA200),
    (9325, 0x01B00A58, 0x01B00828, 0x01B0A758, 0x01B0D6B0, 0x01BCC1E0),
    (9326, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0D760, 0x01B89BA0),
    (9333, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0D1B0, 0x01BA7C00),
    (9334, 0x01B00848, 0x01B00620, 0x01B0A548, 0x01B0D2C0, 0x01BA65B0),
    (9338, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0CED0, 0x01BBC3C0),
    (9340, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0D0F0, 0x01BA3FD0),
    (9346, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CF20, 0x01B79B80),
    (9350, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0CF40, 0x01BBC7C0),
    (9353, 0x01B00698, 0x01B00468, 0x01B0A398, 0x01B0CF10, 0x01B11FE0),
    (9359, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0D360, 0x01BBD800),
    (9363, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0F8D0, 0x01B78820),
    (9364, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F880, 0x01B6C730),
    (9365, 0x01B008E8, 0x01B006C0, 0x01B0A5E8, 0x01B0F940, 0x01B6C4D0),
    (9367, 0x01B00698, 0x01B00468, 0x01B0A398, 0x01B0CDF0, 0x01B11FB0),
    (9368, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0D040, 0x01B79A20),
    (9370, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0F8D0, 0x01B78720),
    (9371, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0F8D0, 0x01B78820),
    (9372, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0F880, 0x01B6C730),
    (9373, 0x01B008E8, 0x01B006C0, 0x01B0A5E8, 0x01B0F940, 0x01B6C4D0),
    (9384, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0CE30, 0x01B88110),
    (9388, 0x01B00988, 0x01B00760, 0x01B0A688, 0x01B0D010, 0x01BBEE30),
    (9389, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0D360, 0x01BBD800),
    (9390, 0x01B007A8, 0x01B00580, 0x01B0A4A8, 0x01B0CE80, 0x01B7A280),
    (9399, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0CED0, 0x01B950E0),
    (9402, 0x01B007F8, 0x01B005D0, 0x01B0A4F8, 0x01B0D170, 0x01B95560),
    (9430, 0x01B009D8, 0x01B007B0, 0x01B0A6D8, 0x01B0D310, 0x01BD7940),
    (9462, 0x01B006B8, 0x01B00490, 0x01B0A3B8, 0x01B0F580, 0x01B746D0),
    (9480, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CEB0, 0x01B79930),
    (9481, 0x01B008E8, 0x01B006C0, 0x01B0A5E8, 0x01B0D180, 0x01BA8600),
    (9482, 0x01B008E8, 0x01B006C0, 0x01B0A5E8, 0x01B0D180, 0x01BA7520),
    (9529, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0CE10, 0x01B351B0),
    (9560, 0x01B00708, 0x01B004E0, 0x01B0A408, 0x01B0CEA0, 0x01B79C10),
    (9597, 0x01B00828, 0x01B005F8, 0x01B0A528, 0x01B0CEC0, 0x01B64FF0),
    (9625, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8EE50),
    (9626, 0x01B00968, 0x01B00738, 0x01B0A668, 0x01B0D010, 0x01BC5B70),
    (9636, 0x01B00738, 0x01B00508, 0x01B0A438, 0x01B0CDC0, 0x01B35170),
    (9637, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0CF40, 0x01BBC7C0),
    (9639, 0x01B00918, 0x01B006E8, 0x01B0A618, 0x01B0CFB0, 0x01C09390),
    (9648, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0CF40, 0x01BBC7C0),
    (9659, 0x01B00898, 0x01B00670, 0x01B0A598, 0x01B0CF40, 0x01BBC7C0),
    (9666, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F320),
    (9667, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F700),
    (9668, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F240),
    (9669, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F1E0),
    (9670, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F2B0),
    (9671, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F1D0),
    (9672, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F3C0),
    (9673, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0CFD0, 0x01B8F450),
    (9674, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D110, 0x01BB3180),
    (9675, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D190, 0x01BB2210),
    (9676, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D0D0, 0x01BB1120),
    (9677, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D190, 0x01BB3200),
    (9678, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D1D0, 0x01BC3250),
    (9679, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D190, 0x01BBC270),
    (9680, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D110, 0x01BC3180),
    (9681, 0x01B00938, 0x01B00710, 0x01B0A638, 0x01B0D190, 0x01BC25C0),
    (9684, 0x01B00FC8, 0x01B00DA0, 0x01B0ACC8, 0x01B0D660, 0x01BF4B70),
    (9714, 0x01B00578, 0x01B00350, 0x01B0A278, 0x01B0CC20, 0x01B52B80),
    (9743, 0x01B00878, 0x01B00648, 0x01B0A578, 0x01B0F8D0, 0x01B73310),
    (9753, 0x01B002A8, 0x01B00080, 0x01B09FA8, 0x01B0C9A0, 0x01B1E1A0),
    (9756, 0x01B00578, 0x01B00350, 0x01B0A278, 0x01B0CC20, 0x01B59F00),
]


def _tu0_9065_syms(text_start: int, d_0648: int, d_a578: int, d_f8d0: int, d_end: int) -> dict[str, int]:
    return {
        "D_01B00000": 0x01B00000,
        "D_01B00648": d_0648,
        "D_01B006A0": text_start - 0x1D8,
        "D_01B0A578": d_a578,
        "D_01B0A5A8": d_a578 + 0x30,
        "D_01B0A5C0": d_a578 + 0x48,
        "D_01B0A6C0": d_a578 + 0x148,
        "D_01B0A7C0": d_a578 + 0x248,
        "D_01B0A8C0": d_a578 + 0x348,
        "D_01B0C8C0": d_a578 + 0x2348,
        "D_01B0F8D0": d_f8d0,
        "D_01B78720": d_end,
    }


# (cid, text_start, D_01B0078C, D_01B05B50, D_01B0B670, func_01B009D8, func_01B01428)
TU0_9053_LAYOUTS = [
    (9053, 0x01B007D8, 0x01B0078C, 0x01B05B50, 0x01B0B670, 0x01B009D8, 0x01B01428),
    (9054, 0x01B005B0, 0x01B0059C, 0x01B041A0, 0x01B0C690, 0x01B00808, 0x01B009D0),
    (9058, 0x01B00718, 0x01B00704, 0x01B04310, 0x01B0A8D0, 0x01B00970, 0x01B00B38),
    (9076, 0x01B00718, 0x01B00704, 0x01B04250, 0x01B09FD0, 0x01B00970, 0x01B00A80),
    (9084, 0x01B006C8, 0x01B006B4, 0x01B04200, 0x01B09F90, 0x01B00920, 0x01B00A30),
    (9090, 0x01B006C8, 0x01B006B4, 0x01B04200, 0x01B09F90, 0x01B00920, 0x01B00A30),
    (9092, 0x01B006C8, 0x01B006B4, 0x01B04200, 0x01B09F90, 0x01B00920, 0x01B00A30),
    (9094, 0x01B006C8, 0x01B006B4, 0x01B04200, 0x01B09F90, 0x01B00920, 0x01B00A30),
    (9098, 0x01B008D0, 0x01B008BC, 0x01B04470, 0x01B0C250, 0x01B00B28, 0x01B00C98),
    (9118, 0x01B005B0, 0x01B0059C, 0x01B041B0, 0x01B0B120, 0x01B00808, 0x01B009D8),
    (9144, 0x01B006A0, 0x01B0068C, 0x01B046E0, 0x01B0ADF0, 0x01B008A0, 0x01B00B60),
    (9145, 0x01B00628, 0x01B00614, 0x01B045F0, 0x01B0ABB0, 0x01B00828, 0x01B00A70),
    (9152, 0x01B00600, 0x01B005EC, 0x01B041C0, 0x01B0C6D0, 0x01B00858, 0x01B009F0),
    (9154, 0x01B00628, 0x01B00614, 0x01B044E0, 0x01B0CA50, 0x01B00880, 0x01B00A88),
    (9156, 0x01B006F0, 0x01B006DC, 0x01B045A0, 0x01B0CB10, 0x01B00948, 0x01B00B50),
    (9158, 0x01B00740, 0x01B0072C, 0x01B04370, 0x01B0D210, 0x01B00998, 0x01B00BA0),
    (9159, 0x01B00740, 0x01B0072C, 0x01B04370, 0x01B0D210, 0x01B00998, 0x01B00BA0),
    (9164, 0x01B007E0, 0x01B007CC, 0x01B046B0, 0x01B0CC50, 0x01B00A38, 0x01B00C58),
    (9165, 0x01B007B8, 0x01B007A4, 0x01B04670, 0x01B0CC10, 0x01B00A10, 0x01B00C18),
    (9176, 0x01B00748, 0x01B00704, 0x01B06320, 0x01B0C000, 0x01B00948, 0x01B013E0),
    (9177, 0x01B00748, 0x01B00704, 0x01B06340, 0x01B0C040, 0x01B00948, 0x01B01400),
    (9178, 0x01B007C8, 0x01B0077C, 0x01B063A0, 0x01B0C080, 0x01B009C8, 0x01B01460),
    (9179, 0x01B007E8, 0x01B007A4, 0x01B063E0, 0x01B0C0C0, 0x01B009E8, 0x01B014A0),
    (9261, 0x01B00628, 0x01B00614, 0x01B04160, 0x01B0BE10, 0x01B00880, 0x01B00990),
    (9263, 0x01B00678, 0x01B00664, 0x01B041B0, 0x01B0BE50, 0x01B008D0, 0x01B009E0),
    (9265, 0x01B00768, 0x01B00754, 0x01B04330, 0x01B0C850, 0x01B009C0, 0x01B00B60),
    (9273, 0x01B00628, 0x01B00614, 0x01B041F0, 0x01B0C710, 0x01B00880, 0x01B00A20),
    (9275, 0x01B00678, 0x01B00664, 0x01B04240, 0x01B0BF10, 0x01B008D0, 0x01B00A68),
    (9277, 0x01B006F0, 0x01B006DC, 0x01B042C0, 0x01B0C7D0, 0x01B00948, 0x01B00AF0),
    (9382, 0x01B007C8, 0x01B007B4, 0x01B04610, 0x01B09FC0, 0x01B00A20, 0x01B00D68),
    (9409, 0x01B00768, 0x01B00754, 0x01B042C0, 0x01B09980, 0x01B009C0, 0x01B00AF0),
    (9514, 0x01B007A8, 0x01B00794, 0x01B04410, 0x01B09950, 0x01B00A00, 0x01B00C40),
    (9598, 0x01B007A8, 0x01B00794, 0x01B04410, 0x01B09A40, 0x01B00A00, 0x01B00C40),
    (9615, 0x01B00768, 0x01B00754, 0x01B04350, 0x01B0A330, 0x01B00968, 0x01B00B80),
    (9616, 0x01B00768, 0x01B00754, 0x01B043A0, 0x01B0C890, 0x01B00968, 0x01B00BC8),
    (9634, 0x01B007A8, 0x01B00794, 0x01B04410, 0x01B09950, 0x01B00A00, 0x01B00C38),
    (9663, 0x01B006D0, 0x01B006BC, 0x01B04F20, 0x01B0CF70, 0x01B008D0, 0x01B00C28),
    (9719, 0x01B00710, 0x01B006FC, 0x01B05040, 0x01B0D0B0, 0x01B00910, 0x01B00D50),
    (9724, 0x01B007F0, 0x01B007DC, 0x01B05280, 0x01B0E5F0, 0x01B009F0, 0x01B00F90),
    (9725, 0x01B00790, 0x01B0077C, 0x01B05000, 0x01B0D070, 0x01B00990, 0x01B00D08),
]


def _tu0_9053_syms(d_078c: int, d_5b50: int, d_b670: int, f_09d8: int, f_1428: int) -> dict[str, int]:
    return {
        "D_01B00000": 0x01B00000,
        "D_01B0078C": d_078c,
        "D_01B00790": d_078c + 4,
        "D_01B05B50": d_5b50,
        "D_01B05B54": d_5b50 + 4,
        "D_01B0B670": d_b670,
        "func_01B009D8": f_09d8,
        "func_01B01428": f_1428,
        "func_01B02E60": f_1428 + 0x1A38,
        "func_01B03568": f_1428 + 0x2140,
        "func_01B03590": f_1428 + 0x2168,
        "func_01B035C8": f_1428 + 0x21A0,
        "func_01B03618": f_1428 + 0x21F0,
        "func_01B03728": f_1428 + 0x2300,
        "func_01B03C78": f_1428 + 0x2850,
        "func_01B03CF8": f_1428 + 0x28D0,
        "func_01B046F8": f_1428 + 0x32D0,
    }


OVERLAY_UNITS = [
    {
        "src": "overlays/group11/ovl_09551.c",
        "containers": [9551],
        "text_start": 0x01B00530,
        "text_end": 0x01B00720,
        "discovered_code_bytes": 460,
        "functions": 13,
        "syms": {
            "D_01B004F0": 0x01B004F0,
            "D_01B004F8": 0x01B004F8,
            "D_01B00730": 0x01B00730,
        },
    },
    {
        "src": "overlays/group11/ovl_09380.c",
        "containers": [9380, 9407],
        "text_start": 0x01B00468,
        "text_end": 0x01B007B0,
        "discovered_code_bytes": 792,
        "functions": 16,
        "syms": {
            "D_01B00428": 0x01B00428,
            "D_01B00430": 0x01B00430,
            "D_01B007C0": 0x01B007C0,
        },
    },
    {
        "src": "overlays/group11/ovl_09379.c",
        "containers": [9379, 9406],
        "text_start": 0x01B00558,
        "text_end": 0x01B008E0,
        "discovered_code_bytes": 856,
        "functions": 17,
        "syms": {
            "D_01B00518": 0x01B00518,
            "D_01B00520": 0x01B00520,
            "D_01B008F0": 0x01B008F0,
        },
    },
    {
        "src": "overlays/group11/ovl_09383.c",
        "containers": [9383, 9410],
        "text_start": 0x01B004E0,
        "text_end": 0x01B00868,
        "discovered_code_bytes": 856,
        "functions": 17,
        "syms": {
            "D_01B004A0": 0x01B004A0,
            "D_01B004A8": 0x01B004A8,
            "D_01B00870": 0x01B00870,
        },
    },
    {
        "src": "overlays/group11/ovl_09240.c",
        "containers": [9240, 9378],
        "text_start": 0x01B005D0,
        "text_end": 0x01B00968,
        "discovered_code_bytes": 872,
        "functions": 17,
        "syms": {
            "D_01B00590": 0x01B00590,
            "D_01B00598": 0x01B00598,
            "D_01B00970": 0x01B00970,
        },
    },
    {
        "src": "overlays/group11/ovl_09381.c",
        "containers": [9381, 9408],
        "text_start": 0x01B004B8,
        "text_end": 0x01B00858,
        "discovered_code_bytes": 884,
        "functions": 17,
        "syms": {
            "D_01B00478": 0x01B00478,
            "D_01B00480": 0x01B00480,
            "D_01B00860": 0x01B00860,
        },
    },
    {
        "src": "overlays/group11/ovl_09422.c",
        "containers": [9422],
        "text_start": 0x01B00530,
        "text_end": 0x01B00930,
        "discovered_code_bytes": 976,
        "functions": 18,
        "syms": {
            "D_01B004F0": 0x01B004F0,
            "D_01B004F8": 0x01B004F8,
            "D_01B00940": 0x01B00940,
        },
    },
    {
        "src": "overlays/group11/ovl_09231.c",
        "containers": [9231],
        "text_start": 0x01B004B8,
        "text_end": 0x01B009D8,
        "discovered_code_bytes": 1264,
        "functions": 18,
        "syms": {
            "D_01B00478": 0x01B00478,
            "D_01B00480": 0x01B00480,
            "D_01B009E0": 0x01B009E0,
        },
    },
    {
        "src": "overlays/group11/ovl_09565.c",
        "containers": [9565],
        "text_start": 0x01B00558,
        "text_end": 0x01B00A88,
        "discovered_code_bytes": 1268,
        "functions": 21,
        "syms": {
            "D_01B00518": 0x01B00518,
            "D_01B00520": 0x01B00520,
            "D_01B00A90": 0x01B00A90,
        },
    },
    {
        "src": "overlays/group11/ovl_09746.c",
        "containers": [9746],
        "text_start": 0x01B00508,
        "text_end": 0x01B00B00,
        "discovered_code_bytes": 1504,
        "functions": 10,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B004F0": 0x01B004F0,
            "D_01B004F4": 0x01B004F4,
            "D_01B004F8": 0x01B004F8,
            "D_01B00B40": 0x01B00B40,
            "D_01B00B44": 0x01B00B44,
            "D_01B00B50": 0x01B00B50,
            "D_01B00BD0": 0x01B00BD0,
            "D_01B00C00": 0x01B00C00,
            "D_01C00C00": 0x01C00C00,
            "D_01D00C00": 0x01D00C00,
            "D_01D00C04": 0x01D00C04,
            "D_01D00C08": 0x01D00C08,
            "D_01D00C0C": 0x01D00C0C,
            "D_01D00C10": 0x01D00C10,
            "D_01D00C30": 0x01D00C30,
            "D_01D00C50": 0x01D00C50,
            "D_01D1E710": 0x01D1E710,
        },
    },
    {
        "src": "overlays/group11/ovl_09747.c",
        "containers": [9747],
        "text_start": 0x01B00508,
        "text_end": 0x01B00B00,
        "discovered_code_bytes": 1504,
        "functions": 10,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B004F0": 0x01B004F0,
            "D_01B004F4": 0x01B004F4,
            "D_01B004F8": 0x01B004F8,
            "D_01B00B40": 0x01B00B40,
            "D_01B00B44": 0x01B00B44,
            "D_01B00B50": 0x01B00B50,
            "D_01B00BD0": 0x01B00BD0,
            "D_01B00C00": 0x01B00C00,
            "D_01C00C00": 0x01C00C00,
            "D_01D00C00": 0x01D00C00,
            "D_01D00C04": 0x01D00C04,
            "D_01D00C08": 0x01D00C08,
            "D_01D00C0C": 0x01D00C0C,
            "D_01D00C10": 0x01D00C10,
            "D_01D00C30": 0x01D00C30,
            "D_01D00C50": 0x01D00C50,
            "D_01D1E710": 0x01D1E710,
        },
    },
    {
        "src": "overlays/group11/ovl_09744.c",
        "containers": [9744],
        "text_start": 0x01B00508,
        "text_end": 0x01B00B10,
        "discovered_code_bytes": 1524,
        "functions": 10,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B004F0": 0x01B004F0,
            "D_01B004F4": 0x01B004F4,
            "D_01B004F8": 0x01B004F8,
            "D_01B00B40": 0x01B00B40,
            "D_01B00B44": 0x01B00B44,
            "D_01B00B50": 0x01B00B50,
            "D_01B00BD0": 0x01B00BD0,
            "D_01B00C00": 0x01B00C00,
            "D_01C00C00": 0x01C00C00,
            "D_01D00C00": 0x01D00C00,
            "D_01D00C04": 0x01D00C04,
            "D_01D00C08": 0x01D00C08,
            "D_01D00C0C": 0x01D00C0C,
            "D_01D00C10": 0x01D00C10,
            "D_01D00C30": 0x01D00C30,
            "D_01D00C50": 0x01D00C50,
            "D_01D1E710": 0x01D1E710,
        },
    },
    {
        "src": "overlays/group11/ovl_09745.c",
        "containers": [9745],
        "text_start": 0x01B00508,
        "text_end": 0x01B00B10,
        "discovered_code_bytes": 1524,
        "functions": 10,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B004F0": 0x01B004F0,
            "D_01B004F4": 0x01B004F4,
            "D_01B004F8": 0x01B004F8,
            "D_01B00B40": 0x01B00B40,
            "D_01B00B44": 0x01B00B44,
            "D_01B00B50": 0x01B00B50,
            "D_01B00BD0": 0x01B00BD0,
            "D_01B00C00": 0x01B00C00,
            "D_01C00C00": 0x01C00C00,
            "D_01D00C00": 0x01D00C00,
            "D_01D00C04": 0x01D00C04,
            "D_01D00C08": 0x01D00C08,
            "D_01D00C0C": 0x01D00C0C,
            "D_01D00C10": 0x01D00C10,
            "D_01D00C30": 0x01D00C30,
            "D_01D00C50": 0x01D00C50,
            "D_01D1E710": 0x01D1E710,
        },
    },
    {
        "src": "overlays/group11/ovl_09242.c",
        "containers": [9242],
        "text_start": 0x01B00508,
        "text_end": 0x01B00CA8,
        "discovered_code_bytes": 1936,
        "functions": 9,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B004F0": 0x01B004F0,
            "D_01B004F4": 0x01B004F4,
            "D_01B004F8": 0x01B004F8,
            "D_01B00CC0": 0x01B00CC0,
            "D_01B00CC4": 0x01B00CC4,
            "D_01B00CD0": 0x01B00CD0,
            "D_01B00D10": 0x01B00D10,
            "D_01B00D50": 0x01B00D50,
            "D_01B00D80": 0x01B00D80,
            "D_01C00D80": 0x01C00D80,
            "D_01D00D80": 0x01D00D80,
            "D_01D00D84": 0x01D00D84,
            "D_01D00D88": 0x01D00D88,
            "D_01D00D8C": 0x01D00D8C,
            "D_01D00D90": 0x01D00D90,
            "D_01D00DA0": 0x01D00DA0,
            "D_01D00DB0": 0x01D00DB0,
            "D_01D00DD0": 0x01D00DD0,
            "D_01D089F0": 0x01D089F0,
        },
    },
    {
        "src": "overlays/group11/ovl_09543.c",
        "containers": [9543],
        "text_start": 0x01B00450,
        "text_end": 0x01B00C58,
        "discovered_code_bytes": 2040,
        "functions": 12,
        "syms": {
            "D_01B00040": 0x01B00040,
            "D_01B00428": 0x01B00428,
            "D_01B0043C": 0x01B0043C,
            "D_01B00440": 0x01B00440,
            "D_01B00444": 0x01B00444,
            "D_01B00C60": 0x01B00C60,
            "D_01B00C68": 0x01B00C68,
            "D_01B00CA0": 0x01B00CA0,
            "D_01B011C0": 0x01B011C0,
            "D_01B011C4": 0x01B011C4,
            "D_01B011C8": 0x01B011C8,
            "D_01B011E0": 0x01B011E0,
            "D_01B03650": 0x01B03650,
            "D_01B03660": 0x01B03660,
            "D_01B83A50": 0x01B83A50,
        },
    },
    {
        "src": "overlays/group11/ovl_09065_tu0.c",
        "containers": [row[0] for row in TU0_9065_LAYOUTS],
        "text_start": 0x01B00878,
        "text_end": 0x01B01420,
        "discovered_code_bytes": 2676,
        "functions": 21,
        "syms": _tu0_9065_syms(*TU0_9065_LAYOUTS[0][1:]),
        "container_layouts": [
            {
                "cid": cid,
                "text_start": ts,
                "text_end": ts + (0x01B01420 - 0x01B00878),
                "syms": _tu0_9065_syms(ts, d_0648, d_a578, d_f8d0, d_end),
            }
            for cid, ts, d_0648, d_a578, d_f8d0, d_end in TU0_9065_LAYOUTS
        ],
    },
    {
        "src": "overlays/group11/ovl_09053_tu0.c",
        "containers": [row[0] for row in TU0_9053_LAYOUTS],
        "text_start": 0x01B007D8,
        "text_end": 0x01B009B8,
        "discovered_code_bytes": 468,
        "functions": 6,
        "syms": _tu0_9053_syms(*TU0_9053_LAYOUTS[0][2:]),
        "container_layouts": [
            {
                "cid": cid,
                "text_start": ts,
                "text_end": ts + (0x01B009B8 - 0x01B007D8),
                "syms": _tu0_9053_syms(d_078c, d_5b50, d_b670, f_09d8, f_1428),
            }
            for cid, ts, d_078c, d_5b50, d_b670, f_09d8, f_1428 in TU0_9053_LAYOUTS
        ],
    },
]


def main() -> int:
    os.chdir(ROOT)
    if sys.platform != "linux":
        cmd = [
            "docker", "run", "--rm", "-v", f"{ROOT}:/work", "ffx-decomp",
            "python3", "overlays/verify_overlays.py",
        ]
        return subprocess.run(cmd).returncode

    cc = "tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc"
    out_dir = ROOT / "build" / "overlays"
    out_dir.mkdir(parents=True, exist_ok=True)

    total_containers = 0
    total_text_bytes = 0
    total_discovered_bytes = 0
    total_funcs = 0

    for unit in OVERLAY_UNITS:
        src = Path(unit["src"])
        stem = src.stem
        obj = out_dir / f"{stem}.o"
        ld = out_dir / f"{stem}.ld"
        elf = out_dir / f"{stem}.elf"
        text_bin = out_dir / f"{stem}.text.bin"

        subprocess.run(
            [cc, "-c", "-O2", "-G0", "-g0", "-Iinclude", "-Ioverlays", str(src), "-o", str(obj)],
            check=True,
        )
        subprocess.run(["mipsel-linux-gnu-objcopy", str(obj), str(obj)], check=True)

        layouts = unit.get("container_layouts") or [
            {
                "cid": cid,
                "text_start": unit["text_start"],
                "text_end": unit["text_end"],
                "syms": unit["syms"],
            }
            for cid in unit["containers"]
        ]

        link_cache: dict[tuple, bytes] = {}
        for item in layouts:
            cid = item["cid"]
            ts = item["text_start"]
            te = item["text_end"]
            syms = item["syms"]
            cache_key = (ts, te, tuple(sorted(syms.items())))
            if cache_key not in link_cache:
                sym_lines = [f"{k} = 0x{v:08x};" for k, v in sorted({**RESIDENT_SYMS, **syms}.items())]
                ld_script = (
                    "SECTIONS\n{\n"
                    f"    . = 0x{ts:08x};\n"
                    f"    .text : {{ {obj.as_posix()}(.text) }}\n"
                    "    /DISCARD/ : { *(*) }\n"
                    "}\n" + "\n".join(sym_lines) + "\n"
                )
                ld.write_text(ld_script)
                subprocess.run(["mipsel-linux-gnu-ld", "-EL", "-T", str(ld), "-o", str(elf)], check=True)
                subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", str(elf), str(text_bin)], check=True)
                link_cache[cache_key] = text_bin.read_bytes()

            built_text = link_cache[cache_key]
            off_start = ts - BASE
            off_end = te - BASE
            expected_len = off_end - off_start
            if len(built_text) != expected_len:
                print(f"FAIL {stem}: expected .text size {expected_len:#x}, got {len(built_text):#x}")
                return 1

            orig_path = ROOT / "build" / "overlay-audit" / f"overlay-group11-file{cid:05d}.bin"
            orig = orig_path.read_bytes()
            orig_text = orig[off_start:off_end]
            if built_text != orig_text:
                print(f"FAIL {stem} against container {cid}: .text mismatch")
                return 1
            rebuilt = orig[:off_start] + built_text + orig[off_end:]
            rebuilt_sha = hashlib.sha256(rebuilt).hexdigest()
            orig_sha = hashlib.sha256(orig).hexdigest()
            assert rebuilt_sha == orig_sha
            print(
                f"MATCH file{cid:05d} ({src.as_posix()}): "
                f".text 0x{ts:08x}..0x{te:08x} "
                f"({len(built_text)}B span / {unit['discovered_code_bytes']}B insns, "
                f"{unit['functions']} funcs) sha256={rebuilt_sha[:12]}..."
            )
            total_containers += 1
            total_text_bytes += len(built_text)
            total_discovered_bytes += unit["discovered_code_bytes"]
            total_funcs += unit["functions"]

    print(
        f"\nOK: {len(OVERLAY_UNITS)} unique overlay C units -> {total_containers} battle-effect containers matched "
        f"({total_funcs} function instances, {total_text_bytes} .text bytes / {total_discovered_bytes} instruction bytes)."
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
