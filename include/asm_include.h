#ifndef ASM_INCLUDE_H
#define ASM_INCLUDE_H

/* Pulls the split assembly of one function into the translation unit.
 * The bodies are rewritten by tools/eeasm.py (numeric registers) because the
 * period ee-as does not understand $v0-style names; ee_labels.inc is labels.inc
 * minus .aent (unknown to ee-as) with global jump-table labels. */
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )

/* Same for the jump table(s) of such a function. Each table gets its own input section
 * (.rodata.jtbl_XXXXXXXX) because configure.py places it at its original address in
 * .rodata (config/rodata_layout.txt). When the function becomes C, delete this line
 * together with the INCLUDE_ASM: gcc then emits the table into the chunk's .rodata. */
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata." #NAME ", \"a\"\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .section .text\n" \
    )

__asm__(".include \"include/ee_labels.inc\"\n");

#endif /* ASM_INCLUDE_H */
