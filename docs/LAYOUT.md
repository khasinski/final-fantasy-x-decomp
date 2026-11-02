# Source Tree Layout

The repository is organized into resident ELF translation units (`src/game/` and `src/sdk/`) and EE battle-effect overlays (`overlays/`).

- **`src/game/`**: Game subsystems shared with the HD ports (character, event VM, battle, menu, rendering, particle, audio, and platform glue).
- **`src/sdk/`**: Sony PS2 SDK libraries (`libgraph`, `libdma`, `libpad`, `libmc`, `libcdvd`, `libipu`, `libkernl`), `newlib` (`libc`, `libm`), and `libgcc`.
- **`overlays/`**: Fixed-base (`0x01B00000`) EE battle-effect overlays from disc resource group `0x11` (see [overlays/README.md](../overlays/README.md)).

## Resident ELF Address Map

The link order of the resident executable (`SCES_504.90`) is defined in `config/units.txt`. Game and SDK regions interleave around `0x002D9730..0x002DDB48`:

| `.text` Range | Tree | Description |
|---|---|---|
| `0x001008D8..0x002D9730` | `src/game/` | Core game subsystems |
| `0x002D9730..0x002D98A8` | `src/game/platform/` | `FFXIsPC`, `FFXIsDebug`, `FFXGetLang`, `FFXSetVideoMode`, `TkIsDebug` |
| `0x002D98A8..0x002DBA00` | `src/sdk/libgraph/` | `sceGs*` graphics synthesiser library |
| `0x002DBA00..0x002DC110` | `src/sdk/libdma/` | `sceDma*` DMA library |
| `0x002DC110..0x002DDB48` | `src/game/platform/` | VU0 matrix/vector helpers (`FFXVu0*`, `FFXSamp0ViewScreenMatrix`) |
| `0x002DDB48..0x003003B0` | `src/sdk/` | `libpad`, `libmc`, `libcdvd`, `libipu`, `newlib`, `libgcc`, `libkernl` |

## `src/game/` Subsystems

| Directory | Units | Description & Evidence |
|---|---:|---|
| `game/` | 2 | `libmscd.c` (`dvd_cd_fat_*`), `hddcopy.c` (`hdd_`/`hd_`) |
| `chr/` | 35 | Character and model system (`src/chr/chr.c`, `src/chr/cache.c`, `Ch_`/`ChN_`, `tex_anim.c`) |
| `main/` | 20 | Memory and scene graph core (`src/main/mem.c`, `src/main/mem2.c`, `Sg_`/`sg_`) |
| `tk/` | 9 | Toolkit, CD/save/thread helpers (`tklib.c`, `Tk*`) |
| `atel/` | 40 | ATEL event script virtual machine (`Atel*`, `0x00126D68..0x0014F3E0`) |
| `battle/` | 45 | Battle engine and camera (`Ms*`, `0x00153EA0..0x00157798` and `0x001A56F8..0x001EF910`) |
| `movie/` | 5 | FMV playback and audio streaming (`movie_cd.c`, `movie_str.c`) |
| `menu/` | 17 | Menu core (`0x001691C8..0x00170BC4` and `0x001EF910..0x00251178`) |
| `menu/to/` | 28 | Text, font, battle UI, and windowing (`TO*`/`_TO*`, `meswin.c`) |
| `menu/tk/` | 24 | Menu screens (`Tk*`/`TkMn2*`) |
| `sa/` | 3 | Task scheduler (`sa_task.c`) |
| `yi/` | 22 | Field map and image management (`yi*`, `yiMemory.c`) |
| `rc/` | 10 | Render core and effect runner (`rcBBox.c`, `rcPacket.c`, `rcef*`, `Yn_*`) |
| `rc/bg/` | 12 | Background rendering (`rcbg*.c`) |
| `rc/dt/` | 4 | Data tables (`rcdt*.c`) |
| `rc/fx/` | 6 | Render effects (`rcfx*.c`) |
| `sqs/` | 5 | Sound sequencer (`Sqs*`, `iMusic*`, `iVoice*`, `decode.c`, `read_debug.c`) |
| `abm/` | 5 | Ability map / Sphere Grid (`abmap_*`, `eiAbm*`) |
| `particle/` | 21 | Particle system (`Ke*`, `0x00266A48..0x002931B0`) |
| `particle/eiProg/` | 9 | Particle programs (`eiProg/pppYanagi.c`, `ppp*`) |
| `op/` | 16 | Effect program opcodes (`op_*`, `opus_*`, `opp_*`, `opf_*`) |
| `op/opu/` | 6 | Effect utility opcodes (`opu_*`) |
| `snd/` | 6 | Sound driver interface (`Snd*`, `Ss*`, `TkSnd*`) |
| `platform/` | 4 | Platform and VU0 glue (`FFX*`) |

## `src/sdk/` Libraries

| Directory | Units | Description |
|---|---:|---|
| `libgraph/` | 1 | `sceGs*` |
| `libdma/` | 1 | `sceDma*` |
| `libpad/` | 1 | `scePad*` |
| `libmc/` | 1 | `sceMc*` |
| `libcdvd/` | 1 | `sceCd*` |
| `libipu/` | 1 | `sceIpu*` |
| `newlib/libm/` | 4 | `fdlibm` single/double precision math routines |
| `libgcc/` | 2 | `fp_bit.c` (`fp-bit`/`dp-bit` soft-float) and `libgcc_2E9828.c` (64-bit integer/float helpers) |
| `newlib/libc/` | 9 | Standard C library (`vfprintf.c`, `_dtoa_r`, `malloc`, string and stdio routines) |
| `libkernl/` | 6 | EE kernel syscall stubs, SIF/RPC, file I/O, `tty.c`, `iopreset.c` |

## Unit Naming Conventions

1. **ELF `__FILE__` strings**: Units containing an original `__FILE__` assertion or debug string keep their original filename stem (`chr.c`, `cache.c`, `mem.c`, `mem2.c`, `tklib.c`, `rcbgFP.c`, `meswin.c`, `pppYanagi.c`, etc.).
2. **Identified SDK objects**: Single-object SDK units use the library stem (`libgraph.c`, `libdma.c`, `libpad.c`, `libmc.c`, `libcdvd.c`, `fp_bit.c`, `vfprintf.c`, `tty.c`, `iopreset.c`).
3. **Dominant symbol family**: Units with a clear majority prefix in `config/names_map.tsv` use `<family>_<START>.c` (`sg_1041C8.c`, `atel_126D68.c`, `to_2021E8.c`).
4. **Address fallback**: Units without recovered symbol names use `<dirname>_<START>.c` (`chr_103C28.c`, `libc_2ED128.c`).
5. **Compiler-flag splits**: When a translation unit is split into multiple build objects to accommodate per-object compiler flags (`config/cflags.txt`, `config/unit_splits.tsv`), the continuation objects use `<stem>_<TUSTART>_<PARTSTART>.c`.
