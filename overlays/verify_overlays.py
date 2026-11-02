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
    "func_0013B150": 0x0013B150,
    "func_0014AA50": 0x0014AA50,
    "func_00266F40": 0x00266F40,
    "pppMemAlloc": 0x00266FA0,
    "pppSetMatrix": 0x002675B0,
    "_pppStartPart": 0x00267658,
    "_pppInitData": 0x002678E0,
    "pppInitEnv": 0x00267A68,
    "_pppRunPart": 0x00267FA0,
    "func_0026BDE0": 0x0026BDE0,
    "op_oef2_sound_cue_multi": 0x002944B0,
    "op_oef2_se_on": 0x00294B70,
    "func_0029B830": 0x0029B830,
    "op_chara_hsv_size_get": 0x002A3B48,
    "func_002A3BD8": 0x002A3BD8,
    "op_chara_hsv": 0x002A3CA0,
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
    "dpadd": 0x002EBBB0,
    "dpmul": 0x002EBC70,
    "dptofp": 0x002EC440,
    "fptodp": 0x002ED038,
    "D_004F4610": 0x004F4610,
    "D_006A3924": 0x006A3924,
    "D_006A3930": 0x006A3930,
    "D_006A3970": 0x006A3970,
    "D_006A39B0": 0x006A39B0,
    "D_006A3A70": 0x006A3A70,
    "D_006A3AB0": 0x006A3AB0,
    "D_006A3BC4": 0x006A3BC4,
    "D_006A3BCC": 0x006A3BCC,
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

        sym_lines = [f"{k} = 0x{v:08x};" for k, v in sorted({**RESIDENT_SYMS, **unit["syms"]}.items())]
        ld_script = (
            "SECTIONS\n{\n"
            f"    . = 0x{unit['text_start']:08x};\n"
            f"    .text : {{ {obj.as_posix()}(.text) }}\n"
            "    /DISCARD/ : { *(*) }\n"
            "}\n" + "\n".join(sym_lines) + "\n"
        )
        ld.write_text(ld_script)

        subprocess.run(
            [cc, "-c", "-O2", "-G0", "-g0", "-Iinclude", "-Ioverlays", str(src), "-o", str(obj)],
            check=True,
        )
        subprocess.run(["mipsel-linux-gnu-objcopy", str(obj), str(obj)], check=True)
        subprocess.run(["mipsel-linux-gnu-ld", "-EL", "-T", str(ld), "-o", str(elf)], check=True)
        subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", str(elf), str(text_bin)], check=True)

        built_text = text_bin.read_bytes()
        off_start = unit["text_start"] - BASE
        off_end = unit["text_end"] - BASE
        expected_len = off_end - off_start
        if len(built_text) != expected_len:
            print(f"FAIL {stem}: expected .text size {expected_len:#x}, got {len(built_text):#x}")
            return 1

        for cid in unit["containers"]:
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
                f".text 0x{unit['text_start']:08x}..0x{unit['text_end']:08x} "
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
