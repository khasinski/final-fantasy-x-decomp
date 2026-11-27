# IOP Sound Driver (`IOPSOUND.IRX`) Decompilation

`IOPSOUND.IRX` (`IopSoundDriver` v2.20) is the sole game-custom IOP module in Final Fantasy X PAL (`SCES_504.90`). All other 24 IOP modules on the disc are Sony PS2 SDK drivers.

## Binary Layout (`baserom/IOPSOUND.IRX`)

- **`.text`**: `0x000000..0x016080` (`90,240 B`)
  - **Decompilable code**: `0x000000..0x015d10` (`89,360 B`, `422` functions)
  - **IOP import stub tables**: `0x015d10..0x016080` (`880 B`, `12` libraries, `67` callable stubs + `8 B` alignment padding)
- **`.rodata`**: `0x016080..0x016cb0` (`3,120 B`)
- **`.data`**: `0x016cb0..0x0192f0` (`9,792 B`)
- **`.sbss`**: `0x0192f0..0x0193b4` (`196 B`)
- **`.bss`**: `0x0193c0..0x122670` (`1,086,128 B`)

## Extracting `baserom/IOPSOUND.IRX`

`IOPSOUND.IRX` is stored in the ISO9660 root of the PAL disc image (`baserom/Final Fantasy X (Europe, Australia).iso`, LBA `2706`, `141,425` bytes, SHA-256 `2d70ed6a16d4...`). Place the extracted file at `baserom/IOPSOUND.IRX`.

## Compiler Toolchain

Units are compiled with the period Sony PS2 IOP GCC 2.8.1 compiler (`tools/cc/iop-gcc2.8.1/bin/iop-gcc -O2 -G0`), assembled with the unmodified period GNU `binutils 2.9.1` MIPS R3000A assembler ([`tools/cc/iop-as-2.9/as`](../tools/cc/iop-as-2.9/README.md) `-EL -mcpu=r3000 -G0`, zero `.s` post-processing), and linked with `mipsel-linux-gnu-ld -EL` inside the `ffx-decomp` Docker container.

## Usage (`iop/verify_iopsound.py`)

```bash
# Scan baserom/IOPSOUND.IRX and regenerate iop/iopsound/funcs.tsv
python3 iop/verify_iopsound.py --scan

# Disassemble a function with resolved HI16/LO16/R_MIPS_26 targets and .rodata strings
python3 iop/verify_iopsound.py --disasm func_015C94
python3 iop/verify_iopsound.py --disasm 0x015aa0

# List registered units
python3 iop/verify_iopsound.py --list

# Verify all registered units byte-for-byte (also updates docs/iopsound-progress.json)
python3 iop/verify_iopsound.py

# Verify a single unit
python3 iop/verify_iopsound.py --unit iop_015c94

# Print a side-by-side instruction diff for a unit
python3 iop/verify_iopsound.py --diff iop_015c94
```
