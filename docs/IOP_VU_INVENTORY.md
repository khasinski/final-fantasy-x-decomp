# IOP & VU Microcode Inventory (`SCES_504.90` PAL)

Generated reproducibly by `python3 tools/inventory_iop_vu.py` from `baserom/Final Fantasy X (Europe, Australia).iso` and `baserom/SCES_504.90`. Structured data is in [iop-vu-inventory.json](iop-vu-inventory.json).

## Executive Summary

| Scope | Category | Count | Total File Bytes | Code (`.text` / VU) Bytes |
|---|---|---:|---:|---:|
| **IOP (Standalone IRX)** | **Game-custom (Square)** | 1 | 141,425 | 90,240 |
| **IOP (Standalone IRX)** | Sony PS2 SDK | 9 | 276,129 | 196,336 |
| **IOP (Standalone IRX)** | *Subtotal* | 10 | 417,554 | 286,576 |
| **IOP (`IOPRP234.IMG`)** | Sony PS2 SDK IOPRP modules | 15 | 246,619 *(image: 247,641)* | 152,816 |
| **IOP (All Combined)** | **Total IOP modules** | **25** | **664,173** | **439,392** |
| **VU1 Microcode** | **Game-custom (`.vutext`)** | **2 programs (8 MPG chunks)** | **14,416** *(padded bin: 14,464)* | **14,304** *(1,788 insns)* |

Key takeaways:
- **Game-custom IOP code** is confined to a single standalone module: `IOPSOUND.IRX` (`IopSoundDriver` v2.20, **90,240 B** `.text`, 141,425 B file).
- **All other 24 IOP modules** (9 standalone SDK `.IRX` files + 15 embedded modules in `IOPRP234.IMG`) are standard Sony PS2 SDK 2.3.x drivers/kernel modules (349,152 B `.text` total).
- **No hidden/embedded IOP modules** exist in FFX's disc archive: scanning all 7,338 active FAT slots (of 16,227 total) found only the 10 standalone IRX files, `IOPRP234.IMG`, and `SCES_504.90` itself (all mirrored in ISO9660 root).
- **VU microcode** in `SCES_504.90` consists of **2 VU1 microprograms** in `.vutext` (`0x578e00..0x57c650`, 14,416 B section; **14,304 B** / 1,788 64-bit VU instructions + 112 B DMA/VIF headers & trailer). Zero additional VIF `MPG` blocks were found in `.data` or the 584 audited group11 EE overlays. Inline VU0 macro-mode (`COP2`) instructions in EE `.text` are already counted in the EE resident scope.

## 1. Standalone IOP IRX Modules (ISO9660 Root)

| File | Class | `.iopmod` Name | Ver | LBA | File Bytes | `.text` Bytes | `.rodata` | `.data` | `.bss` | SHA-256 (prefix) | Description |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|---|---|
| `IOPSOUND.IRX` | **game** | `IopSoundDriver` | 2.20 | 2706 | 141,425 | 90,240 | 3,120 | 9,792 | 1,086,324 | `2d70ed6a16d4` | Square custom FFX IOP sound driver (SPU2/BGM/SE/voice/streaming) |
| `ATAD.IRX` | sdk | `atad` | 1.3 | 2821 | 11,781 | 7,712 | 752 | 32 | 576 | `021b7d845900` | Sony SDK ATA hard disk driver |
| `DEV9.IRX` | sdk | `dev9` | 1.3 | 2816 | 9,197 | 5,456 | 640 | 176 | 96 | `07628b00f0d2` | Sony SDK DEV9 expansion bay driver (HDD/network adapter) |
| `HDD.IRX` | sdk | `hdd` | 1.4 | 2827 | 30,405 | 20,432 | 1,488 | 1,248 | 576 | `6b86ed1c1ffb` | Sony SDK APA hard disk partition driver |
| `LIBSD.IRX` | sdk | `Sound_Device_Library` | 1.4 | 2776 | 27,173 | 16,912 | 544 | 2,288 | 68 | `e9f67bbab64a` | Sony SDK SPU2 Sound Device Library |
| `MCMAN.IRX` | sdk | `mcman` | 2.26 | 2661 | 90,533 | 68,624 | 272 | 512 | 83,532 | `9d0416820ca0` | Sony SDK memory card low-level driver |
| `MCSERV.IRX` | sdk | `mcserv` | 2.14 | 2657 | 7,353 | 4,656 | 64 | 32 | 9,376 | `1ebd7f42a384` | Sony SDK memory card RPC server |
| `PADMAN.IRX` | sdk | `padman` | 4.2 | 2790 | 43,861 | 31,376 | 656 | 64 | 7,120 | `68eb256ee126` | Sony SDK DualShock 2 controller driver |
| `PFS.IRX` | sdk | `pfs` | 1.4 | 2842 | 49,665 | 37,536 | 1,936 | 576 | 1,104 | `8cf9e353dedb` | Sony SDK PlayStation File System driver |
| `SIO2MAN.IRX` | sdk | `sio2man` | 2.4 | 2812 | 6,161 | 3,632 | 96 | 32 | 48 | `b18b1b41db31` | Sony SDK SIO2 serial I/O manager (controller/memcard bus) |

`IOPSOUND.IRX` imports 12 IOP kernel/SDK libraries: `libsd 1.4`, `cdvdman 1.1`, `sysmem 1.1`, `intrman 1.2`, `ioman 1.4`, `loadcore 1.3`, `sifcmd 1.1`, `sifman 1.1`, `sysclib 1.3`, `thbase 1.1`, `thsemap 1.1`, `timrman 1.2`.

## 2. `IOPRP234.IMG` Embedded Sony SDK Modules (ROMDIR)

- **ISO Path**: `/IOPRP234.IMG` (LBA `2867`, `247,641` bytes, SHA-256 `8fc286a2f18af07184c104511e481a56b7ca4efd937f924f0fe314c46f5155b9`)
- **ROMDIR Entries**: 18 total (3 metadata: `RESET` (0 B), `ROMDIR` (304 B), `EXTINFO` (580 B); **15 Sony SDK ELF modules**)

| Module | `.iopmod` Name | Ver | Offset | File Bytes | `.text` Bytes | `.data` | `.bss` | SHA-256 (prefix) |
|---|---|---:|---:|---:|---:|---:|---:|---|
| `LOADCORE` | `Module_Manager` | 2.2 | `0x380` | 9,717 | 7,344 | 32 | 100 | `fb84e4f9fd1a` |
| `SIFCMD` | `IOP_SIF_rpc_interface` | 2.7 | `0x2980` | 10,105 | 6,960 | 48 | 6,832 | `01e2e82f760d` |
| `SIFMAN` | `IOP_SIF_manager` | 2.1 | `0x5100` | 6,009 | 4,176 | 32 | 1,600 | `825aa677d689` |
| `THREADMAN` | `Multi_Thread_Manager` | 2.2 | `0x6880` | 36,945 | 26,080 | 32 | 1,228 | `0f051b6f492a` |
| `IOMAN` | `IO/File_Manager` | 2.2 | `0xf8e0` | 12,025 | 7,488 | 272 | 656 | `e5f0a62689b3` |
| `MODLOAD` | `Moldule_File_loader` | 2.5 | `0x127e0` | 17,589 | 12,576 | 64 | 36 | `2fc9770b3c9e` |
| `FILEIO` | `FILEIO_service` | 2.11 | `0x16ca0` | 18,325 | 11,312 | 192 | 3,956 | `2f6a3f58b386` |
| `CDVDMAN` | `cdvd_driver` | 2.22 | `0x1b440` | 60,893 | 33,552 | 320 | 51,896 | `0f50d81f82e4` |
| `CDVDFSV` | `cdvd_ee_driver` | 2.22 | `0x2a220` | 38,597 | 21,568 | 96 | 45,184 | `ca96667cfc6c` |
| `LOADFILE` | `LoadModuleByEE` | 2.1 | `0x338f0` | 11,617 | 7,168 | 128 | 656 | `f11028eaf8f8` |
| `TIMEMANI` | `Timer_Manager` | 2.1 | `0x36660` | 5,813 | 3,584 | 320 | 0 | `548e8e07880c` |
| `ROMDRV` | `ROM_file_driver` | 2.1 | `0x37d20` | 3,881 | 2,128 | 160 | 208 | `62f2ae6b687b` |
| `EESYNC` | `SyncEE` | 2.1 | `0x38c50` | 1,545 | 640 | 32 | 0 | `bf1377e93904` |
| `SYSCLIB` | `System_C_lib` | 2.2 | `0x39260` | 10,205 | 6,400 | 192 | 0 | `e10f703fc388` |
| `STDIO` | `Stdio` | 2.2 | `0x3ba40` | 3,353 | 1,840 | 32 | 4 | `1541a2cc5032` |

## 3. VU0 / VU1 Microcode (`SCES_504.90` `.vutext`)

- **ELF `.vutext` section**: `0x578e00..0x57c650` (file offset `0x479e00`, **14,416 bytes**, SHA-256 `e1d95186dccad4b4...`)
- **`assets/vutext.bin`**: `14,464` bytes (exact match to `.vutext` plus 48 bytes of zero-padding to 64-byte alignment before `.lit4` at `0x0057c680`).
- **`.vudata` / `.vubss`**: 0 bytes / 0 bytes.

### Resident VU1 Microprograms

| # | Target | EE VMA Range | DMA Tag | Packet Bytes | VIF `MPG` Chunks | VU Instructions | Pure VU Code Bytes | VU Dest Range | SHA-256 (prefix) |
|---:|---|---|---|---:|---:|---:|---:|---|---|
| 1 | VU1 | `0x578e00..0x579b00` | `ref` (`qwc=207`, `addr=0x578e10`) | 3,328 | 2 | 412 | 3,296 | `0x0..0xce0` | `e886909b0ca4` |
| 2 | VU1 | `0x579b00..0x57c640` | `next` (`qwc=691`, `addr=0x0`) | 11,072 | 6 | 1,376 | 11,008 | `0x0..0x2b00` | `e26c55520a04` |

Notes on `.vutext` and `.DVP.ovlytab`:
- Program 1 (`0x00578e00`) is referenced by `src/game/chr/chr_10EA50.c` (`D_00578E00`), which copies its 16-byte DMA `ref` tag into character rendering packets.
- `SCES_504.90` also retains `dvp-as` linker metadata in `.DVP.ovlytab` (10 entries). The first 8 entries map 1-to-1 to the 8 VIF `MPG` chunks of Programs 1 and 2 inside `.vutext`. The remaining 2 entries (`0x020ae3a8`, 608 B / 76 insns; `0x02132630`, 912 B / 114 insns) have LMAs above retail 32 MiB EE RAM and empty/fill-pattern `.DVP.overlay.*` sections, indicating unlinked/stripped devkit metadata rather than resident microcode.
- Additional VIF `MPG` (`0x4A`) scans: `.data` in `SCES_504.90` = **0 hits**; audited group11 EE overlays (584 containers) = **0 hits**.
