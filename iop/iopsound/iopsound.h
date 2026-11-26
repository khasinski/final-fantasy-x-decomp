#ifndef FFX_IOPSOUND_H
#define FFX_IOPSOUND_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

#ifndef NULL
#define NULL ((void *)0)
#endif

/* IOPSOUND.IRX imported library stubs (12 libraries, 67 stubs) */

/* libsd 1.4 */
extern s32 imp_libsd_4();   /* sceSdInit */
extern s32 imp_libsd_5();   /* sceSdSetParam */
extern s32 imp_libsd_6();   /* sceSdGetParam */
extern s32 imp_libsd_7();   /* sceSdSetSwitch */
extern s32 imp_libsd_8();   /* sceSdGetSwitch */
extern s32 imp_libsd_9();   /* sceSdSetAddr */
extern s32 imp_libsd_10();  /* sceSdGetAddr */
extern s32 imp_libsd_11();  /* sceSdSetCoreAttr */
extern s32 imp_libsd_12();  /* sceSdGetCoreAttr */
extern s32 imp_libsd_17();  /* sceSdVoiceTrans */
extern s32 imp_libsd_18();  /* sceSdBlockTrans */
extern s32 imp_libsd_19();  /* sceSdVoiceTransStatus */
extern s32 imp_libsd_20();  /* sceSdBlockTransStatus */
extern s32 imp_libsd_23();  /* sceSdSetEffectAttr */
extern s32 imp_libsd_24();  /* sceSdGetEffectAttr */
extern s32 imp_libsd_25();  /* sceSdClearEffectWorkArea */
extern s32 imp_libsd_26();  /* sceSdSetTransIntrHandler */
extern s32 imp_libsd_27();  /* sceSdSetSpu2IntrHandler */
extern s32 imp_libsd_28();  /* sceSdGetTransIntrHandlerArgument */

/* cdvdman 1.1 */
extern s32 imp_cdvdman_5();
extern s32 imp_cdvdman_6();
extern s32 imp_cdvdman_8();
extern s32 imp_cdvdman_11();
extern s32 imp_cdvdman_12();
extern s32 imp_cdvdman_13();
extern s32 imp_cdvdman_28();
extern s32 imp_cdvdman_39();

/* sysmem 1.1 */
extern s32 imp_sysmem_7();  /* QueryMaxFreeMemSize */
extern s32 imp_sysmem_8();  /* QueryTotalFreeMemSize */
extern s32 imp_sysmem_14(); /* Kprintf / printf */

/* intrman 1.2 */
extern s32 imp_intrman_6();
extern s32 imp_intrman_9();
extern s32 imp_intrman_17(); /* CpuSuspendIntr */
extern s32 imp_intrman_18(); /* CpuResumeIntr */

/* ioman 1.4 */
extern s32 imp_ioman_4();   /* open */
extern s32 imp_ioman_5();   /* close */
extern s32 imp_ioman_6();   /* read */
extern s32 imp_ioman_7();   /* write */
extern s32 imp_ioman_8();   /* lseek */

/* loadcore 1.3 */
extern s32 imp_loadcore_5(); /* FlushIcache */

/* sifcmd 1.1 */
extern s32 imp_sifcmd_14();
extern s32 imp_sifcmd_17();
extern s32 imp_sifcmd_19();
extern s32 imp_sifcmd_20();
extern s32 imp_sifcmd_21();
extern s32 imp_sifcmd_24();
extern s32 imp_sifcmd_25();

/* sifman 1.1 */
extern s32 imp_sifman_7();  /* sceSifSetDma */
extern s32 imp_sifman_8();  /* sceSifDmaStat */

/* sysclib 1.3 */
extern s32 imp_sysclib_19();
extern s32 imp_sysclib_23();
extern s32 imp_sysclib_27();

/* thbase 1.1 */
extern s32 imp_thbase_4();  /* CreateThread */
extern s32 imp_thbase_6();  /* StartThread */
extern s32 imp_thbase_20(); /* GetThreadId */
extern s32 imp_thbase_22(); /* ReferThreadStatus */
extern s32 imp_thbase_24(); /* SleepThread */
extern s32 imp_thbase_33(); /* DelayThread */
extern s32 imp_thbase_34(); /* GetSystemTime */

/* thsemap 1.1 */
extern s32 imp_thsemap_4(); /* CreateSema */
extern s32 imp_thsemap_6(); /* SignalSema */
extern s32 imp_thsemap_7(); /* iSignalSema */
extern s32 imp_thsemap_8(); /* WaitSema */

/* timrman 1.2 */
extern s32 imp_timrman_4();
extern s32 imp_timrman_20();
extern s32 imp_timrman_22();
extern s32 imp_timrman_23();

#endif /* FFX_IOPSOUND_H */
