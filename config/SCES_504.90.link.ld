/* Hand-written: splat's generated script groups by section type, but this ELF
   interleaves text/data/rodata/vutext/lit4 at fixed addresses. */
INCLUDE config/undefined_syms_auto.txt
INCLUDE config/undefined_funcs_auto.txt
/* Projection work backing view starts inside an existing BSS allocation. */
D_00600110 = 0x00600110;
D_0069247A = 0x0069247a;
/* data inside .text that splat folds into padding: absolute aliases */
func_0017A540 = 0x17A540;
/* ee-gcc soft-float libcall names (what the compiler emits for double arithmetic/conversions) */
dpadd = 0x2EBBB0;
dpsub = 0x2EBC08;
dpcmp = 0x2EC198;
litodp = 0x2EC1E8;
dptoli = 0x2EC2A0;
dptoul = 0x2EC338;
dptofp = 0x2EC440;
fptoui = 0x2ECF38;
fptodp = 0x2ED038;
sqrtf = 0x2E9708;
SECTIONS
{
    . = 0x100000;
    .text : {
        build/asm/text.s.o(.text)
        build/src/game/chr/chr.c.o(.text)
        build/src/game/chr/chr_103C28.c.o(.text)
        build/src/game/main/sg_1041C8.c.o(.text)
        build/src/game/chr/ch_104528.c.o(.text)
        build/src/game/chr/ch_104718.c.o(.text)
        build/src/game/chr/chr_106380.c.o(.text)
        build/src/game/main/sg_106440.c.o(.text)
        build/src/game/chr/ch_106DC8.c.o(.text)
        build/src/game/chr/ch_1074A8.c.o(.text)
        build/src/game/chr/ch_10AD70.c.o(.text)
        build/src/game/chr/ch_10D0A0.c.o(.text)
        build/src/game/main/sg_10D6D0.c.o(.text)
        build/src/game/main/sg_10DE98.c.o(.text)
        build/src/game/chr/chr_10EA50.c.o(.text)
        build/src/game/chr/ch_110158.c.o(.text)
        build/src/game/chr/ch_1106A8.c.o(.text)
        build/src/game/chr/ch_110910.c.o(.text)
        build/src/game/chr/cache.c.o(.text)
        build/src/game/chr/ch_111B50.c.o(.text)
        build/src/game/chr/ch_1132B8.c.o(.text)
        build/src/game/chr/ch_113938.c.o(.text)
        build/src/game/chr/ch_113FF8.c.o(.text)
        build/src/game/main/sg_115E70.c.o(.text)
        build/src/game/chr/ch_116CB8.c.o(.text)
        build/src/game/chr/ch_117D38.c.o(.text)
        build/src/game/main/sg_117D78.c.o(.text)
        build/src/game/main/sg_1194E0.c.o(.text)
        build/src/game/chr/chr_119F30.c.o(.text)
        build/src/game/main/sg_11A428.c.o(.text)
        build/src/game/main/sg_11A538.c.o(.text)
        build/src/game/main/mem.c.o(.text)
        build/src/game/main/mem2.c.o(.text)
        build/src/game/main/sg_11D750.c.o(.text)
        build/src/game/main/sg_11E2C8.c.o(.text)
        build/src/game/chr/chr_11EDA0.c.o(.text)
        build/src/game/main/sg_11EE40.c.o(.text)
        build/src/game/main/sg_11F8D0.c.o(.text)
        build/src/game/main/sg_11FC58.c.o(.text)
        build/src/game/main/sg_1201B0.c.o(.text)
        build/src/game/chr/ch_120CF8.c.o(.text)
        build/src/game/main/sg_1229D0.c.o(.text)
        build/src/game/main/sg_123844.c.o(.text)
        build/src/game/chr/chr_124058.c.o(.text)
        build/src/game/tk/tklib.c.o(.text)
        build/src/game/tk/tk_126108.c.o(.text)
        build/src/game/tk/tk_126768.c.o(.text)
        build/src/game/atel/atel_126D68.c.o(.text)
        build/src/game/atel/atel_127970.c.o(.text)
        build/src/game/atel/atel_128A58.c.o(.text)
        build/src/game/atel/atel_12A0B8.c.o(.text)
        build/src/game/atel/atel_12AF80.c.o(.text)
        build/src/game/atel/atel_12B4F0.c.o(.text)
        build/src/game/atel/atel_12BC40.c.o(.text)
        build/src/game/atel/atel_12BEC0.c.o(.text)
        build/src/game/atel/atel_12C2D0.c.o(.text)
        build/src/game/atel/atel_12C788.c.o(.text)
        build/src/game/atel/atel_12CE80.c.o(.text)
        build/src/game/atel/atel_12D498.c.o(.text)
        build/src/game/atel/atel_12DD60.c.o(.text)
        build/src/game/atel/atel_12F2F8.c.o(.text)
        build/src/game/atel/atel_12F740.c.o(.text)
        build/src/game/atel/atel_135510.c.o(.text)
        build/src/game/atel/atel_135B90.c.o(.text)
        build/src/game/atel/atel_135E88.c.o(.text)
        build/src/game/atel/atel_1365D0.c.o(.text)
        build/src/game/atel/atel_137250.c.o(.text)
        build/src/game/atel/atel_137A00.c.o(.text)
        build/src/game/atel/tk_138220.c.o(.text)
        build/src/game/atel/atel_1382E0.c.o(.text)
        build/src/game/atel/atel_138588.c.o(.text)
        build/src/game/atel/atel_13A5D8.c.o(.text)
        build/src/game/atel/atel_13A7E0.c.o(.text)
        build/src/game/atel/atel_13A940.c.o(.text)
        build/src/game/atel/atel_13CA30.c.o(.text)
        build/src/game/atel/atel_13CA80.c.o(.text)
        build/src/game/atel/atel_141FF0.c.o(.text)
        build/src/game/atel/atel_143910.c.o(.text)
        build/src/game/atel/atel_143BD0.c.o(.text)
        build/src/game/atel/atel_145938.c.o(.text)
        build/src/game/atel/atel_148660.c.o(.text)
        build/src/game/atel/atel_148F40.c.o(.text)
        build/src/game/atel/atel_14B260.c.o(.text)
        build/src/game/atel/atel_14C3A8.c.o(.text)
        build/src/game/atel/tk_14CE18.c.o(.text)
        build/src/game/atel/atel_14D610.c.o(.text)
        build/src/game/atel/atel_14D940.c.o(.text)
        build/src/game/chr/chr_14F3E0.c.o(.text)
        build/src/game/main/sg_14F708.c.o(.text)
        build/src/game/chr/chr_150200.c.o(.text)
        build/src/game/chr/chr_150550.c.o(.text)
        build/src/game/chr/chr_1508A0.c.o(.text)
        build/src/game/chr/ch_150D70.c.o(.text)
        build/src/game/chr/chr_152308.c.o(.text)
        build/src/game/chr/ch_152420.c.o(.text)
        build/src/game/chr/chr_1530D8.c.o(.text)
        build/src/game/chr/chr_1531C8.c.o(.text)
        build/src/game/battle/ms_153EA0.c.o(.text)
        build/src/game/battle/battle_1543E0.c.o(.text)
        build/src/game/battle/battle_155930.c.o(.text)
        build/src/game/battle/battle_1561A0.c.o(.text)
        build/src/game/battle/ms_1570A0.c.o(.text)
        build/src/game/movie/movie_157798.c.o(.text)
        build/src/game/movie/audio_15A560.c.o(.text)
        build/src/game/movie/movie_cd.c.o(.text)
        build/src/game/movie/movie_15BBF8.c.o(.text)
        build/src/game/movie/movie_str.c.o(.text)
        build/src/game/chr/tex_anim.c.o(.text)
        build/src/game/chr/tex_anim_old.c.o(.text)
        build/src/game/libmscd.c.o(.text)
        build/src/game/hddcopy.c.o(.text)
        build/src/game/menu/to/to_1691C8.c.o(.text)
        build/src/game/menu/menu_16CD98.c.o(.text)
        build/src/game/menu/menu_16DC58.c.o(.text)
        build/src/game/menu/menu_16E078.c.o(.text)
        build/src/game/menu/menu_16E478.c.o(.text)
        build/src/game/menu/menu_16E8C8.c.o(.text)
        build/src/game/menu/menu_16EA68.c.o(.text)
        build/src/game/menu/menu_16F108.c.o(.text)
        build/src/game/menu/menu_170398.c.o(.text)
        build/src/game/menu/menu_1709E0.c.o(.text)
        build/src/game/sa/sa_170BC4.c.o(.text)
        build/src/game/sa/sa_task.c.o(.text)
        build/src/game/sa/sa_171CE8.c.o(.text)
        build/src/game/yi/yi_171EF0.c.o(.text)
        build/src/game/yi/yirender_174FF8.c.o(.text)
        build/src/game/yi/yi_178648.c.o(.text)
        build/src/game/yi/yi_1787E8.c.o(.text)
        build/src/game/yi/yi_17A1B8.c.o(.text)
        build/src/game/yi/yi_17A9C0.c.o(.text)
        build/src/game/yi/yiMemory.c.o(.text)
        build/src/game/yi/yiimage_17DC98.c.o(.text)
        build/src/game/yi/yi_180618.c.o(.text)
        build/src/game/yi/yi_180B70.c.o(.text)
        build/src/game/yi/yi_184EA0.c.o(.text)
        build/src/game/yi/yi_187260.c.o(.text)
        build/src/game/yi/yi_188D98.c.o(.text)
        build/src/game/yi/yi_18AA10.c.o(.text)
        build/src/game/yi/yi_18B680.c.o(.text)
        build/src/game/yi/yi_18D0F8.c.o(.text)
        build/src/game/yi/yi_18D7F8.c.o(.text)
        build/src/game/yi/yi_18DBB0.c.o(.text)
        build/src/game/yi/yi_18DF18.c.o(.text)
        build/src/game/yi/yi_18E228.c.o(.text)
        build/src/game/yi/yi_18E788.c.o(.text)
        build/src/game/yi/yi_18E9C8.c.o(.text)
        build/src/game/rc/rcBBox.c.o(.text)
        build/src/game/rc/rcPacket.c.o(.text)
        build/src/game/rc/bg/rcbgAnime.c.o(.text)
        build/src/game/rc/bg/rcbgDebug.c.o(.text)
        build/src/game/rc/bg/rcbgLoad.c.o(.text)
        build/src/game/rc/bg/rcbgMain.c.o(.text)
        build/src/game/rc/bg/rcbgModel.c.o(.text)
        build/src/game/rc/bg/rcbgGuide.c.o(.text)
        build/src/game/rc/rc_197CD8.c.o(.text)
        build/src/game/rc/bg/rcbgPSim.c.o(.text)
        build/src/game/rc/rc_198860.c.o(.text)
        build/src/game/rc/bg/rcbgPre.c.o(.text)
        build/src/game/rc/bg/rcbgScene.c.o(.text)
        build/src/game/rc/bg/rcbgTrx.c.o(.text)
        build/src/game/rc/bg/rcbgTrxTex.c.o(.text)
        build/src/game/rc/bg/rcbgFP.c.o(.text)
        build/src/game/rc/yn_19BAD8.c.o(.text)
        build/src/game/rc/rc_19CFE0.c.o(.text)
        build/src/game/rc/yn_19D040.c.o(.text)
        build/src/game/rc/rc_19D3C0.c.o(.text)
        build/src/game/rc/dt/rcdtChunk.c.o(.text)
        build/src/game/rc/dt/rcdtParse.c.o(.text)
        build/src/game/rc/dt/rcdtRsd2.c.o(.text)
        build/src/game/rc/dt/rcdtTm2.c.o(.text)
        build/src/game/rc/rcef_19FC00.c.o(.text)
        build/src/game/rc/rcef_1A21E0.c.o(.text)
        build/src/game/rc/fx/rcfxParticle.c.o(.text)
        build/src/game/rc/fx/rcfxSpring.c.o(.text)
        build/src/game/rc/fx/rcfxNail.c.o(.text)
        build/src/game/rc/fx/rcfxWind.c.o(.text)
        build/src/game/rc/fx/rcfxGravity.c.o(.text)
        build/src/game/rc/fx/rcfxDamp.c.o(.text)
        build/src/game/battle/ms_1A56F8.c.o(.text)
        build/src/game/battle/ms_1AC0B8.c.o(.text)
        build/src/game/battle/ms_1ACFD8.c.o(.text)
        build/src/game/battle/ms_1AF9E8.c.o(.text)
        build/src/game/battle/ms_1B15C8.c.o(.text)
        build/src/game/battle/ms_1B3388.c.o(.text)
        build/src/game/battle/ms_1B4100.c.o(.text)
        build/src/game/battle/ms_1B5298.c.o(.text)
        build/src/game/battle/ms_1B63B8.c.o(.text)
        build/src/game/battle/ms_1B72F0.c.o(.text)
        build/src/game/battle/ms_1B89D8.c.o(.text)
        build/src/game/battle/ms_1BA7D0.c.o(.text)
        build/src/game/battle/ms_1BB380.c.o(.text)
        build/src/game/battle/ms_1BC440.c.o(.text)
        build/src/game/battle/ms_1BF978.c.o(.text)
        build/src/game/battle/ms_1C0720.c.o(.text)
        build/src/game/battle/ms_1C0C98.c.o(.text)
        build/src/game/battle/ms_1C5E90.c.o(.text)
        build/src/game/battle/ms_1C8C80.c.o(.text)
        build/src/game/battle/ms_1CCC10.c.o(.text)
        build/src/game/battle/ms_1CE8E0.c.o(.text)
        build/src/game/battle/ms_1D00D8.c.o(.text)
        build/src/game/battle/ms_1D2170.c.o(.text)
        build/src/game/battle/ms_1D27C0.c.o(.text)
        build/src/game/battle/ms_1D48D0.c.o(.text)
        build/src/game/battle/ms_1D8078.c.o(.text)
        build/src/game/battle/ms_1D8C28.c.o(.text)
        build/src/game/battle/ms_1DBB50.c.o(.text)
        build/src/game/battle/ms_1DC7A0.c.o(.text)
        build/src/game/battle/ms_1DD7B8.c.o(.text)
        build/src/game/battle/ms_1DF1C0.c.o(.text)
        build/src/game/battle/ms_1DFC50.c.o(.text)
        build/src/game/battle/ms_1E08F0.c.o(.text)
        build/src/game/battle/ms_1E1F40.c.o(.text)
        build/src/game/battle/ms_1E2360.c.o(.text)
        build/src/game/battle/battle_1E4C30.c.o(.text)
        build/src/game/battle/ms_1E4CD0.c.o(.text)
        build/src/game/battle/ms_1E7AF0.c.o(.text)
        build/src/game/battle/battle_1EA000.c.o(.text)
        build/src/game/battle/battle_1EF4E8.c.o(.text)
        build/src/game/menu/to/to_1EF910.c.o(.text)
        build/src/game/menu/to/to_1F1EB8.c.o(.text)
        build/src/game/menu/to/to_1F3280.c.o(.text)
        build/src/game/menu/menu_1F4818.c.o(.text)
        build/src/game/menu/to/to_1F5060.c.o(.text)
        build/src/game/menu/to/to_1F8418.c.o(.text)
        build/src/game/menu/to/to_1FA0E8.c.o(.text)
        build/src/game/menu/menu_2004D0.c.o(.text)
        build/src/game/menu/menu_200C58.c.o(.text)
        build/src/game/menu/menu_201760.c.o(.text)
        build/src/game/menu/to/to_2021E8.c.o(.text)
        build/src/game/menu/to/to_207648.c.o(.text)
        build/src/game/menu/to/to_207F50.c.o(.text)
        build/src/game/menu/to/to_208448.c.o(.text)
        build/src/game/menu/to/to_209460.c.o(.text)
        build/src/game/menu/to/meswin.c.o(.text)
        build/src/game/menu/to/to_20D058.c.o(.text)
        build/src/game/menu/to/to_20DFC8.c.o(.text)
        build/src/game/menu/menu_20E248.c.o(.text)
        build/src/game/menu/to/to_20E8A0.c.o(.text)
        build/src/game/menu/tk/tk_20EC90.c.o(.text)
        build/src/game/menu/to/to_210340.c.o(.text)
        build/src/game/menu/to/to_212EA8.c.o(.text)
        build/src/game/menu/to/to_214650.c.o(.text)
        build/src/game/menu/to/to_216FA0.c.o(.text)
        build/src/game/menu/to/to_2180A0.c.o(.text)
        build/src/game/menu/to/to_218A78.c.o(.text)
        build/src/game/menu/to/to_21D048.c.o(.text)
        build/src/game/menu/to/to_21F9A8.c.o(.text)
        build/src/game/menu/to/to_21FDD8.c.o(.text)
        build/src/game/menu/to/to_2207E8.c.o(.text)
        build/src/game/menu/tk/tk_220F30.c.o(.text)
        build/src/game/menu/to/to_224430.c.o(.text)
        build/src/game/menu/tk/tk_224930.c.o(.text)
        build/src/game/menu/tk/tk_226BF0.c.o(.text)
        build/src/game/menu/tk/tk_227C88.c.o(.text)
        build/src/game/menu/tk/tk_228B08.c.o(.text)
        build/src/game/menu/tk/tk_22B9F8.c.o(.text)
        build/src/game/menu/tk/tk_22CE70.c.o(.text)
        build/src/game/menu/tk/tk_22FB30.c.o(.text)
        build/src/game/menu/tk/tk_2315E8.c.o(.text)
        build/src/game/menu/tk/tk_232C88.c.o(.text)
        build/src/game/menu/menu_234910.c.o(.text)
        build/src/game/menu/tk/tk_234A30.c.o(.text)
        build/src/game/menu/menu_235C38.c.o(.text)
        build/src/game/menu/to/to_2362B8.c.o(.text)
        build/src/game/menu/tk/tk_237888.c.o(.text)
        build/src/game/menu/tk/tk_23A450.c.o(.text)
        build/src/game/menu/tk/tk_23C658.c.o(.text)
        build/src/game/menu/tk/tk_23CBD0.c.o(.text)
        build/src/game/menu/tk/tk_2414F0.c.o(.text)
        build/src/game/menu/tk/tk_2416C0.c.o(.text)
        build/src/game/menu/tk/tk_242040.c.o(.text)
        build/src/game/menu/tk/tk_2454C0.c.o(.text)
        build/src/game/menu/tk/tk_249328.c.o(.text)
        build/src/game/menu/tk/tk_249928.c.o(.text)
        build/src/game/menu/tk/tk_24B828.c.o(.text)
        build/src/game/menu/menu_250D00.c.o(.text)
        build/src/game/menu/tk/tk_250F68.c.o(.text)
        build/src/game/sqs/sqs_251178.c.o(.text)
        build/src/game/sqs/decode.c.o(.text)
        build/src/game/sqs/read_debug.c.o(.text)
        build/src/game/sqs/sqs_255A08.c.o(.text)
        build/src/game/sqs/sqs_255EA4.c.o(.text)
        build/src/game/abm/abmap_256098.c.o(.text)
        build/src/game/abm/ei_258140.c.o(.text)
        build/src/game/abm/abm_25AEB0.c.o(.text)
        build/src/game/abm/ei_260A70.c.o(.text)
        build/src/game/abm/abm_265F78.c.o(.text)
        build/src/game/particle/particle_266A48.c.o(.text)
        build/src/game/particle/particle_266A48_266EB8.c.o(.text)
        build/src/game/particle/particle_266A48_266EE8.c.o(.text)
        build/src/game/particle/eiProg/ppp_266F10.c.o(.text)
        build/src/game/particle/eiProg/ppp_268680.c.o(.text)
        build/src/game/particle/eiProg/ppp_26A9A8.c.o(.text)
        build/src/game/particle/particle_26AC38.c.o(.text)
        build/src/game/particle/particle_26B218.c.o(.text)
        build/src/game/particle/eiProg/ppp_26BDE0.c.o(.text)
        build/src/game/particle/particle_26CCE0.c.o(.text)
        build/src/game/particle/particle_26DAD8.c.o(.text)
        build/src/game/particle/particle_26F218.c.o(.text)
        build/src/game/particle/particle_26FBF8.c.o(.text)
        build/src/game/particle/particle_270220.c.o(.text)
        build/src/game/particle/eiProg/pppYanagi.c.o(.text)
        build/src/game/particle/particle_276E00.c.o(.text)
        build/src/game/particle/particle_2781C8.c.o(.text)
        build/src/game/particle/particle_278C40.c.o(.text)
        build/src/game/particle/particle_279F40.c.o(.text)
        build/src/game/particle/particle_27BC40.c.o(.text)
        build/src/game/particle/particle_27ED88.c.o(.text)
        build/src/game/particle/ke_27F2E8.c.o(.text)
        build/src/game/particle/ke_2803C0.c.o(.text)
        build/src/game/particle/eiProg/ppp_2856F0.c.o(.text)
        build/src/game/particle/particle_288570.c.o(.text)
        build/src/game/particle/eiProg/ppp_289808.c.o(.text)
        build/src/game/particle/eiProg/ppp_28B480.c.o(.text)
        build/src/game/particle/particle_28D740.c.o(.text)
        build/src/game/particle/particle_28FDD8.c.o(.text)
        build/src/game/particle/eiProg/ppp_291120.c.o(.text)
        build/src/game/op/op_2931B0.c.o(.text)
        build/src/game/op/opus_294CD8.c.o(.text)
        build/src/game/op/op_2967E8.c.o(.text)
        build/src/game/op/opu/opu_29A8A8.c.o(.text)
        build/src/game/op/opu/opu_29DC40.c.o(.text)
        build/src/game/op/opu/opu_29DC40_2A0618.c.o(.text)
        build/src/game/op/opu/opu_2A0820.c.o(.text)
        build/src/game/op/op_2A2220.c.o(.text)
        build/src/game/op/opu/opu_2A43D8.c.o(.text)
        build/src/game/op/opu/opu_2A6FE8.c.o(.text)
        build/src/game/op/opp_2AC750.c.o(.text)
        build/src/game/op/opp_2AF1D0.c.o(.text)
        build/src/game/op/opf_2B0FC0.c.o(.text)
        build/src/game/op/op_2B1720.c.o(.text)
        build/src/game/op/op_2B1E08.c.o(.text)
        build/src/game/op/op_2B33F8.c.o(.text)
        build/src/game/op/op_2B4630.c.o(.text)
        build/src/game/op/op_2B4FF8.c.o(.text)
        build/src/game/op/op_2B6B50.c.o(.text)
        build/src/game/op/op_2CEC08.c.o(.text)
        build/src/game/op/op_2CEFF0.c.o(.text)
        build/src/game/op/op_2D0AF0.c.o(.text)
        build/src/game/tk/tk_2D1D68.c.o(.text)
        build/src/game/tk/tk_2D25C8.c.o(.text)
        build/src/game/tk/tk_2D3D68.c.o(.text)
        build/src/game/tk/tk_2D41A8.c.o(.text)
        build/src/game/snd/snd_2D5B90.c.o(.text)
        build/src/game/snd/snd_2D6808.c.o(.text)
        build/src/game/snd/snd_2D7090.c.o(.text)
        build/src/game/snd/snd_2D7C20.c.o(.text)
        build/src/game/snd/snd_2D81E8.c.o(.text)
        build/src/game/snd/snd_2D8780.c.o(.text)
        build/src/game/tk/tk_2D89C8.c.o(.text)
        build/src/game/tk/tk_2D9188.c.o(.text)
        build/src/game/platform/ffx_2D9730.c.o(.text)
        build/src/sdk/libgraph/libgraph.c.o(.text)
        build/src/sdk/libdma/libdma.c.o(.text)
        build/src/game/platform/platform_2DC110.c.o(.text)
        build/src/game/platform/ffx_2DC580.c.o(.text)
        build/src/game/platform/ffx_2DCE38.c.o(.text)
        build/src/sdk/libpad/libpad.c.o(.text)
        build/src/sdk/libmc/libmc.c.o(.text)
        build/src/sdk/libcdvd/libcdvd.c.o(.text)
        build/src/sdk/libipu/libipu_2E2220.c.o(.text)
        build/src/sdk/newlib/libm/libm_2E2830.c.o(.text)
        build/src/sdk/newlib/libm/libm_2E4250.c.o(.text)
        build/src/sdk/newlib/libm/libm_2E7C68.c.o(.text)
        build/src/sdk/newlib/libm/libm_2E7E60.c.o(.text)
        build/src/sdk/libgcc/libgcc_2E9828.c.o(.text)
        build/src/sdk/libgcc/fp_bit.c.o(.text)
        build/src/sdk/newlib/libc/libc_2ED078.c.o(.text)
        build/src/sdk/newlib/libc/libc_2ED128.c.o(.text)
        build/src/sdk/newlib/libc/libc_2EEF1C.c.o(.text)
        build/src/sdk/newlib/libc/libc_2EF0D0.c.o(.text)
        build/src/sdk/newlib/libc/libc_2F032C.c.o(.text)
        build/src/sdk/newlib/libc/libc_2F0840.c.o(.text)
        build/src/sdk/newlib/libc/vfprintf.c.o(.text)
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.text)
        build/src/sdk/newlib/libc/libc_2F3A70_2F5CB8.c.o(.text)
        build/src/sdk/libkernl/tty.c.o(.text)
        build/src/sdk/libkernl/libkernl_2FAC84.c.o(.text)
        build/src/sdk/libkernl/libkernl_2FAC88.c.o(.text)
        build/src/sdk/libkernl/libkernl_2FBBE8.c.o(.text)
        build/src/sdk/libkernl/libkernl_2FF270.c.o(.text)
        build/src/sdk/libkernl/iopreset.c.o(.text)
    }
    . = 0x300500;
    .data : { build/asm/data/data.data.s.o(.data) }
    . = 0x568f00;
    .rodata : SUBALIGN(1) {   /* every piece/table is placed by an explicit `. = ADDR` */
        . = 0x568f00 - 0x568f00;
        build/asm/data/rodata/piece_00568F00.s.o(.rodata)
        . = 0x568fa0 - 0x568f00;
        build/src/game/chr/chr.c.o(.rodata.cjt0)
        . = 0x569180 - 0x568f00;
        build/src/game/chr/chr.c.o(.rodata.cjt1)
        . = 0x5691e0 - 0x568f00;
        build/src/game/chr/chr.c.o(.rodata.cjt2)
        . = 0x569200 - 0x568f00;
        build/asm/data/rodata/piece_00569200.s.o(.rodata)
        . = 0x569350 - 0x568f00;
        build/src/game/chr/chr.c.o(.rodata.jtbl_00569350)
        . = 0x569390 - 0x568f00;
        build/asm/data/rodata/piece_00569390.s.o(.rodata)
        . = 0x5694d0 - 0x568f00;
        build/src/game/chr/ch_104718.c.o(.rodata.cjt0)
        . = 0x5694f0 - 0x568f00;
        build/src/game/chr/ch_104718.c.o(.rodata.cjt1)
        . = 0x569510 - 0x568f00;
        build/src/game/chr/ch_104718.c.o(.rodata.cjt2)
        . = 0x569530 - 0x568f00;
        build/asm/data/rodata/piece_00569530.s.o(.rodata)
        . = 0x569570 - 0x568f00;
        build/src/game/chr/ch_106DC8.c.o(.rodata.jtbl_00569570)
        . = 0x5695b8 - 0x568f00;
        build/asm/data/rodata/piece_005695B8.s.o(.rodata)
        . = 0x569720 - 0x568f00;
        build/src/game/chr/ch_111B50.c.o(.rodata.jtbl_00569720)
        . = 0x569748 - 0x568f00;
        build/asm/data/rodata/piece_00569748.s.o(.rodata)
        . = 0x5697e0 - 0x568f00;
        build/src/game/chr/ch_113FF8.c.o(.rodata.jtbl_005697E0)
        . = 0x5699ac - 0x568f00;
        build/asm/data/rodata/piece_005699AC.s.o(.rodata)
        . = 0x5699d0 - 0x568f00;
        build/src/game/chr/ch_113FF8.c.o(.rodata.jtbl_005699D0)
        . = 0x5699e8 - 0x568f00;
        build/asm/data/rodata/piece_005699E8.s.o(.rodata)
        . = 0x569a00 - 0x568f00;
        build/src/game/main/sg_117D78.c.o(.rodata.cjt0)
        . = 0x569a30 - 0x568f00;
        build/src/game/main/sg_1194E0.c.o(.rodata.jtbl_00569A30)
        . = 0x569a48 - 0x568f00;
        build/asm/data/rodata/piece_00569A48.s.o(.rodata)
        . = 0x569c90 - 0x568f00;
        build/src/game/main/mem.c.o(.rodata.cjt0)
        . = 0x569cd0 - 0x568f00;
        build/src/game/main/mem.c.o(.rodata.cjt1)
        . = 0x569ce8 - 0x568f00;
        build/asm/data/rodata/piece_00569CE8.s.o(.rodata)
        . = 0x56a440 - 0x568f00;
        build/src/game/atel/atel_126D68.c.o(.rodata.cjt0)
        . = 0x56a460 - 0x568f00;
        build/src/game/atel/atel_126D68.c.o(.rodata.cjt1)
        . = 0x56a480 - 0x568f00;
        build/src/game/atel/atel_12CE80.c.o(.rodata.cjt0)
        . = 0x56a4a0 - 0x568f00;
        build/src/game/atel/atel_12F740.c.o(.rodata.jtbl_0056A4A0)
        . = 0x56a4f0 - 0x568f00;
        build/src/game/atel/atel_12F740.c.o(.rodata.cjt0)
        . = 0x56a510 - 0x568f00;
        build/asm/data/rodata/piece_0056A510.s.o(.rodata)
        . = 0x56a7f0 - 0x568f00;
        build/src/game/atel/atel_13A940.c.o(.rodata.jtbl_0056A7F0)
        . = 0x56a810 - 0x568f00;
        build/asm/data/rodata/piece_0056A810.s.o(.rodata)
        . = 0x56a890 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt0)
        . = 0x56a8b0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt1)
        . = 0x56a8d0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt2)
        . = 0x56a8f0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt3)
        . = 0x56a910 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt4)
        . = 0x56a930 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.jtbl_0056A930)
        . = 0x56a960 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.jtbl_0056A960)
        . = 0x56a980 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.jtbl_0056A980)
        . = 0x56a9a0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.jtbl_0056A9A0)
        . = 0x56a9d0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt5)
        . = 0x56a9f0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt6)
        . = 0x56aa50 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt7)
        . = 0x56aac0 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.cjt8)
        . = 0x56ab10 - 0x568f00;
        build/src/game/atel/atel_13CA80.c.o(.rodata.jtbl_0056AB10)
        . = 0x56ad00 - 0x568f00;
        build/src/game/atel/atel_143BD0.c.o(.rodata.jtbl_0056AD00)
        . = 0x56ad20 - 0x568f00;
        build/src/game/atel/atel_143BD0.c.o(.rodata.jtbl_0056AD20)
        . = 0x56ad38 - 0x568f00;
        build/asm/data/rodata/piece_0056AD38.s.o(.rodata)
        . = 0x56adb0 - 0x568f00;
        build/src/game/atel/atel_145938.c.o(.rodata.jtbl_0056ADB0)
        . = 0x56add8 - 0x568f00;
        build/asm/data/rodata/piece_0056ADD8.s.o(.rodata)
        . = 0x56ade0 - 0x568f00;
        build/src/game/atel/atel_145938.c.o(.rodata.cjt0)
        . = 0x56ae00 - 0x568f00;
        build/asm/data/rodata/piece_0056AE00.s.o(.rodata)
        . = 0x56ae10 - 0x568f00;
        build/src/game/atel/atel_145938.c.o(.rodata.cjt1)
        . = 0x56ae28 - 0x568f00;
        build/asm/data/rodata/piece_0056AE28.s.o(.rodata)
        . = 0x56ae30 - 0x568f00;
        build/src/game/atel/atel_145938.c.o(.rodata.jtbl_0056AE30)
        . = 0x56ae70 - 0x568f00;
        build/asm/data/rodata/piece_0056AE70.s.o(.rodata)
        . = 0x56aeb0 - 0x568f00;
        build/src/game/atel/atel_145938.c.o(.rodata.cjt2)
        . = 0x56aed0 - 0x568f00;
        build/src/game/atel/atel_148F40.c.o(.rodata.cjt0)
        . = 0x56aef0 - 0x568f00;
        build/src/game/atel/atel_148F40.c.o(.rodata.cjt1)
        . = 0x56af10 - 0x568f00;
        build/src/game/atel/atel_148F40.c.o(.rodata.cjt2)
        . = 0x56af30 - 0x568f00;
        build/asm/data/rodata/piece_0056AF30.s.o(.rodata)
        . = 0x56af60 - 0x568f00;
        build/src/game/atel/atel_14B260.c.o(.rodata.cjt0)
        . = 0x56af80 - 0x568f00;
        build/src/game/atel/atel_14B260.c.o(.rodata.cjt1)
        . = 0x56af98 - 0x568f00;
        build/asm/data/rodata/piece_0056AF98.s.o(.rodata)
        . = 0x56afd0 - 0x568f00;
        build/src/game/atel/atel_14C3A8.c.o(.rodata.cjt0)
        . = 0x56b0b0 - 0x568f00;
        build/src/game/atel/atel_14D940.c.o(.rodata.cjt0)
        . = 0x56b0d0 - 0x568f00;
        build/asm/data/rodata/piece_0056B0D0.s.o(.rodata)
        . = 0x56b1b0 - 0x568f00;
        build/src/game/atel/atel_14D940.c.o(.rodata.cjt1)
        . = 0x56b1d0 - 0x568f00;
        build/asm/data/rodata/piece_0056B1D0.s.o(.rodata)
        . = 0x56b5e0 - 0x568f00;
        build/src/game/movie/movie_157798.c.o(.rodata.jtbl_0056B5E0)
        . = 0x56b778 - 0x568f00;
        build/asm/data/rodata/piece_0056B778.s.o(.rodata)
        . = 0x56b970 - 0x568f00;
        build/src/game/chr/tex_anim.c.o(.rodata.jtbl_0056B970)
        . = 0x56b988 - 0x568f00;
        build/asm/data/rodata/piece_0056B988.s.o(.rodata)
        . = 0x56b990 - 0x568f00;
        build/src/game/chr/tex_anim.c.o(.rodata.jtbl_0056B990)
        . = 0x56b9b0 - 0x568f00;
        build/asm/data/rodata/piece_0056B9B0.s.o(.rodata)
        . = 0x56b9c0 - 0x568f00;
        build/src/game/chr/tex_anim_old.c.o(.rodata.jtbl_0056B9C0)
        . = 0x56b9e0 - 0x568f00;
        build/src/game/chr/tex_anim_old.c.o(.rodata.jtbl_0056B9E0)
        . = 0x56ba00 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt0)
        . = 0x56ba20 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt1)
        . = 0x56ba40 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt2)
        . = 0x56ba60 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt3)
        . = 0x56ba80 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt4)
        . = 0x56baa0 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt5)
        . = 0x56bac0 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt6)
        . = 0x56bae0 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt7)
        . = 0x56bb00 - 0x568f00;
        build/src/game/libmscd.c.o(.rodata.cjt8)
        . = 0x56bb20 - 0x568f00;
        build/asm/data/rodata/piece_0056BB20.s.o(.rodata)
        . = 0x56bfb0 - 0x568f00;
        build/src/game/hddcopy.c.o(.rodata.cjt0)
        . = 0x56bfd0 - 0x568f00;
        build/asm/data/rodata/piece_0056BFD0.s.o(.rodata)
        . = 0x56c040 - 0x568f00;
        build/src/game/menu/to/to_1691C8.c.o(.rodata.jtbl_0056C040)
        . = 0x56c060 - 0x568f00;
        build/src/game/menu/to/to_1691C8.c.o(.rodata.jtbl_0056C060)
        . = 0x56c080 - 0x568f00;
        build/src/game/menu/to/to_1691C8.c.o(.rodata.jtbl_0056C080)
        . = 0x56c0a0 - 0x568f00;
        build/src/game/menu/to/to_1691C8.c.o(.rodata.jtbl_0056C0A0)
        . = 0x56c118 - 0x568f00;
        build/asm/data/rodata/piece_0056C118.s.o(.rodata)
        . = 0x56c160 - 0x568f00;
        build/src/game/menu/to/to_1691C8.c.o(.rodata.jtbl_0056C160)
        . = 0x56c178 - 0x568f00;
        build/asm/data/rodata/piece_0056C178.s.o(.rodata)
        . = 0x56c1e0 - 0x568f00;
        build/src/game/yi/yi_171EF0.c.o(.rodata.cjt0)
        . = 0x56c238 - 0x568f00;
        build/asm/data/rodata/piece_0056C238.s.o(.rodata)
        . = 0x56c420 - 0x568f00;
        build/src/game/yi/yi_17A9C0.c.o(.rodata.jtbl_0056C420)
        . = 0x56c448 - 0x568f00;
        build/asm/data/rodata/piece_0056C448.s.o(.rodata)
        . = 0x56c470 - 0x568f00;
        build/src/game/yi/yi_17A9C0.c.o(.rodata.jtbl_0056C470)
        . = 0x56c530 - 0x568f00;
        build/src/game/yi/yi_17A9C0.c.o(.rodata.jtbl_0056C530)
        . = 0x56c5f0 - 0x568f00;
        build/src/game/yi/yi_17A9C0.c.o(.rodata.jtbl_0056C5F0)
        . = 0x56c6a8 - 0x568f00;
        build/asm/data/rodata/piece_0056C6A8.s.o(.rodata)
        . = 0x56c840 - 0x568f00;
        build/src/game/yi/yiimage_17DC98.c.o(.rodata.jtbl_0056C840)
        . = 0x56c860 - 0x568f00;
        build/src/game/yi/yiimage_17DC98.c.o(.rodata.jtbl_0056C860)
        . = 0x56c8c0 - 0x568f00;
        build/src/game/yi/yiimage_17DC98.c.o(.rodata.cjt0)
        . = 0x56c928 - 0x568f00;
        build/asm/data/rodata/piece_0056C928.s.o(.rodata)
        . = 0x56c9b0 - 0x568f00;
        build/src/game/yi/yiimage_17DC98.c.o(.rodata.cjt1)
        . = 0x56ca08 - 0x568f00;
        build/asm/data/rodata/piece_0056CA08.s.o(.rodata)
        . = 0x56ca20 - 0x568f00;
        build/src/game/yi/yiimage_17DC98.c.o(.rodata.cjt2)
        . = 0x56ca78 - 0x568f00;
        build/asm/data/rodata/piece_0056CA78.s.o(.rodata)
        . = 0x56cde0 - 0x568f00;
        build/src/game/yi/yi_180B70.c.o(.rodata.jtbl_0056CDE0)
        . = 0x56cf64 - 0x568f00;
        build/asm/data/rodata/piece_0056CF64.s.o(.rodata)
        . = 0x56cff0 - 0x568f00;
        build/src/game/yi/yi_184EA0.c.o(.rodata.jtbl_0056CFF0)
        . = 0x56d040 - 0x568f00;
        build/src/game/yi/yi_184EA0.c.o(.rodata.jtbl_0056D040)
        . = 0x56d0a0 - 0x568f00;
        build/src/game/yi/yi_184EA0.c.o(.rodata.jtbl_0056D0A0)
        . = 0x56d100 - 0x568f00;
        build/asm/data/rodata/piece_0056D100.s.o(.rodata)
        . = 0x56d120 - 0x568f00;
        build/src/game/yi/yi_187260.c.o(.rodata.jtbl_0056D120)
        . = 0x56d140 - 0x568f00;
        build/asm/data/rodata/piece_0056D140.s.o(.rodata)
        . = 0x56d1b0 - 0x568f00;
        build/src/game/yi/yi_18B680.c.o(.rodata.jtbl_0056D1B0)
        . = 0x56d1d0 - 0x568f00;
        build/asm/data/rodata/piece_0056D1D0.s.o(.rodata)
        . = 0x56d2a0 - 0x568f00;
        build/src/game/yi/yi_18B680.c.o(.rodata.jtbl_0056D2A0)
        . = 0x56d310 - 0x568f00;
        build/src/game/yi/yi_18B680.c.o(.rodata.jtbl_0056D310)
        . = 0x56d378 - 0x568f00;
        build/asm/data/rodata/piece_0056D378.s.o(.rodata)
        . = 0x56d8a0 - 0x568f00;
        build/src/game/rc/bg/rcbgMain.c.o(.rodata.cjt0)
        . = 0x56d8d0 - 0x568f00;
        build/asm/data/rodata/piece_0056D8D0.s.o(.rodata)
        . = 0x56da70 - 0x568f00;
        build/src/game/rc/bg/rcbgGuide.c.o(.rodata.cjt0)
        . = 0x56da88 - 0x568f00;
        build/asm/data/rodata/piece_0056DA88.s.o(.rodata)
        . = 0x56db80 - 0x568f00;
        build/src/game/rc/bg/rcbgFP.c.o(.rodata.cjt0)
        . = 0x56db98 - 0x568f00;
        build/asm/data/rodata/piece_0056DB98.s.o(.rodata)
        . = 0x56dc70 - 0x568f00;
        build/src/game/rc/dt/rcdtRsd2.c.o(.rodata.cjt0)
        . = 0x56dc88 - 0x568f00;
        build/asm/data/rodata/piece_0056DC88.s.o(.rodata)
        . = 0x56dd40 - 0x568f00;
        build/src/game/rc/dt/rcdtRsd2.c.o(.rodata.cjt1)
        . = 0x56dd88 - 0x568f00;
        build/asm/data/rodata/piece_0056DD88.s.o(.rodata)
        . = 0x56de80 - 0x568f00;
        build/src/game/battle/ms_1A56F8.c.o(.rodata.jtbl_0056DE80)
        . = 0x56ded0 - 0x568f00;
        build/src/game/battle/ms_1A56F8.c.o(.rodata.jtbl_0056DED0)
        . = 0x56dee8 - 0x568f00;
        build/asm/data/rodata/piece_0056DEE8.s.o(.rodata)
        . = 0x56df10 - 0x568f00;
        build/src/game/battle/ms_1A56F8.c.o(.rodata.jtbl_0056DF10)
        . = 0x56df30 - 0x568f00;
        build/src/game/battle/ms_1A56F8.c.o(.rodata.jtbl_0056DF30)
        . = 0x56df58 - 0x568f00;
        build/asm/data/rodata/piece_0056DF58.s.o(.rodata)
        . = 0x56e000 - 0x568f00;
        build/src/game/battle/ms_1ACFD8.c.o(.rodata.jtbl_0056E000)
        . = 0x56e020 - 0x568f00;
        build/asm/data/rodata/piece_0056E020.s.o(.rodata)
        . = 0x56e150 - 0x568f00;
        build/src/game/battle/ms_1ACFD8.c.o(.rodata.cjt0)
        . = 0x56e170 - 0x568f00;
        build/asm/data/rodata/piece_0056E170.s.o(.rodata)
        . = 0x56e1c0 - 0x568f00;
        build/src/game/battle/ms_1ACFD8.c.o(.rodata.cjt1)
        . = 0x56e1e0 - 0x568f00;
        build/src/game/battle/ms_1AF9E8.c.o(.rodata.jtbl_0056E1E0)
        . = 0x56e230 - 0x568f00;
        build/asm/data/rodata/piece_0056E230.s.o(.rodata)
        . = 0x56e270 - 0x568f00;
        build/src/game/battle/ms_1AF9E8.c.o(.rodata.jtbl_0056E270)
        . = 0x56e2a0 - 0x568f00;
        build/asm/data/rodata/piece_0056E2A0.s.o(.rodata)
        . = 0x56e2d0 - 0x568f00;
        build/src/game/battle/ms_1B15C8.c.o(.rodata.cjt0)
        . = 0x56e300 - 0x568f00;
        build/src/game/battle/ms_1B3388.c.o(.rodata.jtbl_0056E300)
        . = 0x56e340 - 0x568f00;
        build/src/game/battle/ms_1B3388.c.o(.rodata.jtbl_0056E340)
        . = 0x56e370 - 0x568f00;
        build/asm/data/rodata/piece_0056E370.s.o(.rodata)
        . = 0x56e380 - 0x568f00;
        build/src/game/battle/ms_1B72F0.c.o(.rodata.jtbl_0056E380)
        . = 0x56e3c0 - 0x568f00;
        build/src/game/battle/ms_1B72F0.c.o(.rodata.cjt0)
        . = 0x56e430 - 0x568f00;
        build/asm/data/rodata/piece_0056E430.s.o(.rodata)
        . = 0x56e450 - 0x568f00;
        build/src/game/battle/ms_1B89D8.c.o(.rodata.jtbl_0056E450)
        . = 0x56e490 - 0x568f00;
        build/src/game/battle/ms_1B89D8.c.o(.rodata.jtbl_0056E490)
        . = 0x56e4d0 - 0x568f00;
        build/src/game/battle/ms_1BB380.c.o(.rodata.cjt0)
        . = 0x56e500 - 0x568f00;
        build/asm/data/rodata/piece_0056E500.s.o(.rodata)
        . = 0x56e550 - 0x568f00;
        build/src/game/battle/ms_1BC440.c.o(.rodata.jtbl_0056E550)
        . = 0x56e5b0 - 0x568f00;
        build/src/game/battle/ms_1C0C98.c.o(.rodata.cjt0)
        . = 0x56e5e0 - 0x568f00;
        build/src/game/battle/ms_1C0C98.c.o(.rodata.jtbl_0056E5E0)
        . = 0x56e640 - 0x568f00;
        build/src/game/battle/ms_1C0C98.c.o(.rodata.jtbl_0056E640)
        . = 0x56e660 - 0x568f00;
        build/src/game/battle/ms_1C0C98.c.o(.rodata.jtbl_0056E660)
        . = 0x56e680 - 0x568f00;
        build/src/game/battle/ms_1C5E90.c.o(.rodata.jtbl_0056E680)
        . = 0x56e6c0 - 0x568f00;
        build/src/game/battle/ms_1C8C80.c.o(.rodata.jtbl_0056E6C0)
        . = 0x56e740 - 0x568f00;
        build/src/game/battle/ms_1C8C80.c.o(.rodata.jtbl_0056E740)
        . = 0x56e760 - 0x568f00;
        build/src/game/battle/ms_1C8C80.c.o(.rodata.jtbl_0056E760)
        . = 0x56e780 - 0x568f00;
        build/asm/data/rodata/piece_0056E780.s.o(.rodata)
        . = 0x56e7a0 - 0x568f00;
        build/src/game/battle/ms_1C8C80.c.o(.rodata.jtbl_0056E7A0)
        . = 0x56e7b8 - 0x568f00;
        build/asm/data/rodata/piece_0056E7B8.s.o(.rodata)
        . = 0x56e8b0 - 0x568f00;
        build/src/game/battle/ms_1CCC10.c.o(.rodata.jtbl_0056E8B0)
        . = 0x56e8f0 - 0x568f00;
        build/asm/data/rodata/piece_0056E8F0.s.o(.rodata)
        . = 0x56e910 - 0x568f00;
        build/src/game/battle/ms_1CCC10.c.o(.rodata.cjt0)
        . = 0x56e930 - 0x568f00;
        build/asm/data/rodata/piece_0056E930.s.o(.rodata)
        . = 0x56e980 - 0x568f00;
        build/src/game/battle/ms_1CE8E0.c.o(.rodata.cjt0)
        . = 0x56e9f0 - 0x568f00;
        build/src/game/battle/ms_1CE8E0.c.o(.rodata.jtbl_0056E9F0)
        . = 0x56ea20 - 0x568f00;
        build/src/game/battle/ms_1D00D8.c.o(.rodata.jtbl_0056EA20)
        . = 0x56ea98 - 0x568f00;
        build/asm/data/rodata/piece_0056EA98.s.o(.rodata)
        . = 0x56eaa0 - 0x568f00;
        build/src/game/battle/ms_1D00D8.c.o(.rodata.jtbl_0056EAA0)
        . = 0x56eac0 - 0x568f00;
        build/src/game/battle/ms_1D27C0.c.o(.rodata.jtbl_0056EAC0)
        . = 0x56eaf8 - 0x568f00;
        build/asm/data/rodata/piece_0056EAF8.s.o(.rodata)
        . = 0x56eb20 - 0x568f00;
        build/src/game/battle/ms_1D27C0.c.o(.rodata.jtbl_0056EB20)
        . = 0x56eb70 - 0x568f00;
        build/src/game/battle/ms_1D48D0.c.o(.rodata.jtbl_0056EB70)
        . = 0x56f0e0 - 0x568f00;
        build/src/game/battle/ms_1D48D0.c.o(.rodata.jtbl_0056F0E0)
        . = 0x56f650 - 0x568f00;
        build/src/game/battle/ms_1D48D0.c.o(.rodata.cjt0)
        . = 0x56f680 - 0x568f00;
        build/src/game/battle/ms_1D48D0.c.o(.rodata.cjt1)
        . = 0x56f6a8 - 0x568f00;
        build/asm/data/rodata/piece_0056F6A8.s.o(.rodata)
        . = 0x56f720 - 0x568f00;
        build/src/game/battle/ms_1DBB50.c.o(.rodata.jtbl_0056F720)
        . = 0x56f770 - 0x568f00;
        build/src/game/battle/ms_1DBB50.c.o(.rodata.jtbl_0056F770)
        . = 0x56f7b8 - 0x568f00;
        build/asm/data/rodata/piece_0056F7B8.s.o(.rodata)
        . = 0x56f810 - 0x568f00;
        build/src/game/battle/ms_1E08F0.c.o(.rodata.cjt0)
        . = 0x56f840 - 0x568f00;
        build/src/game/battle/ms_1E08F0.c.o(.rodata.cjt1)
        . = 0x56f890 - 0x568f00;
        build/src/game/battle/ms_1E08F0.c.o(.rodata.cjt2)
        . = 0x56f8b0 - 0x568f00;
        build/src/game/battle/ms_1E08F0.c.o(.rodata.jtbl_0056F8B0)
        . = 0x56f8d0 - 0x568f00;
        build/asm/data/rodata/piece_0056F8D0.s.o(.rodata)
        . = 0x56f8e0 - 0x568f00;
        build/src/game/battle/ms_1E2360.c.o(.rodata.jtbl_0056F8E0)
        . = 0x56f9b0 - 0x568f00;
        build/src/game/battle/ms_1E4CD0.c.o(.rodata.jtbl_0056F9B0)
        . = 0x56f9f0 - 0x568f00;
        build/asm/data/rodata/piece_0056F9F0.s.o(.rodata)
        . = 0x56fa00 - 0x568f00;
        build/src/game/battle/ms_1E4CD0.c.o(.rodata.jtbl_0056FA00)
        . = 0x56fa20 - 0x568f00;
        build/asm/data/rodata/piece_0056FA20.s.o(.rodata)
        . = 0x56fbe0 - 0x568f00;
        build/src/game/battle/ms_1E7AF0.c.o(.rodata.cjt0)
        . = 0x56fc20 - 0x568f00;
        build/src/game/battle/ms_1E7AF0.c.o(.rodata.cjt1)
        . = 0x56fc40 - 0x568f00;
        build/src/game/battle/ms_1E7AF0.c.o(.rodata.cjt2)
        . = 0x56fc60 - 0x568f00;
        build/src/game/battle/ms_1E7AF0.c.o(.rodata.cjt3)
        . = 0x56fc80 - 0x568f00;
        build/src/game/battle/ms_1E7AF0.c.o(.rodata.cjt4)
        . = 0x56fc98 - 0x568f00;
        build/asm/data/rodata/piece_0056FC98.s.o(.rodata)
        . = 0x56fd70 - 0x568f00;
        build/src/game/battle/battle_1EA000.c.o(.rodata.cjt0)
        . = 0x56fde0 - 0x568f00;
        build/src/game/battle/battle_1EA000.c.o(.rodata.cjt1)
        . = 0x56fe48 - 0x568f00;
        build/asm/data/rodata/piece_0056FE48.s.o(.rodata)
        . = 0x56feb0 - 0x568f00;
        build/src/game/menu/menu_1F4818.c.o(.rodata.cjt0)
        . = 0x56ff20 - 0x568f00;
        build/src/game/menu/menu_1F4818.c.o(.rodata.cjt1)
        . = 0x56ff90 - 0x568f00;
        build/asm/data/rodata/piece_0056FF90.s.o(.rodata)
        . = 0x5700d0 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.cjt0)
        . = 0x570160 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.cjt1)
        . = 0x570220 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.cjt2)
        . = 0x570250 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.cjt3)
        . = 0x570280 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.cjt4)
        . = 0x5702d0 - 0x568f00;
        build/asm/data/rodata/piece_005702D0.s.o(.rodata)
        . = 0x5702f0 - 0x568f00;
        build/src/game/menu/to/to_2021E8.c.o(.rodata.jtbl_005702F0)
        . = 0x570340 - 0x568f00;
        build/asm/data/rodata/piece_00570340.s.o(.rodata)
        . = 0x570840 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.jtbl_00570840)
        . = 0x570860 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.cjt0)
        . = 0x570880 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.cjt1)
        . = 0x5708a0 - 0x568f00;
        build/asm/data/rodata/piece_005708A0.s.o(.rodata)
        . = 0x5708c0 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.cjt2)
        . = 0x570940 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.cjt3)
        . = 0x570960 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.jtbl_00570960)
        . = 0x570980 - 0x568f00;
        build/src/game/menu/to/to_209460.c.o(.rodata.cjt4)
        . = 0x570a38 - 0x568f00;
        build/asm/data/rodata/piece_00570A38.s.o(.rodata)
        . = 0x570a80 - 0x568f00;
        build/src/game/menu/tk/tk_20EC90.c.o(.rodata.jtbl_00570A80)
        . = 0x570aa0 - 0x568f00;
        build/src/game/menu/tk/tk_20EC90.c.o(.rodata.jtbl_00570AA0)
        . = 0x570ad0 - 0x568f00;
        build/src/game/menu/to/to_210340.c.o(.rodata.cjt0)
        . = 0x570b30 - 0x568f00;
        build/src/game/menu/to/to_210340.c.o(.rodata.jtbl_00570B30)
        . = 0x570b90 - 0x568f00;
        build/asm/data/rodata/piece_00570B90.s.o(.rodata)
        . = 0x570c50 - 0x568f00;
        build/src/game/menu/to/to_210340.c.o(.rodata.jtbl_00570C50)
        . = 0x570c90 - 0x568f00;
        build/asm/data/rodata/piece_00570C90.s.o(.rodata)
        . = 0x570d30 - 0x568f00;
        build/src/game/menu/to/to_214650.c.o(.rodata.cjt0)
        . = 0x570d50 - 0x568f00;
        build/src/game/menu/to/to_214650.c.o(.rodata.cjt1)
        . = 0x570d90 - 0x568f00;
        build/src/game/menu/to/to_214650.c.o(.rodata.jtbl_00570D90)
        . = 0x570dd8 - 0x568f00;
        build/asm/data/rodata/piece_00570DD8.s.o(.rodata)
        . = 0x570f20 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt0)
        . = 0x570f50 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt1)
        . = 0x570f78 - 0x568f00;
        build/asm/data/rodata/piece_00570F78.s.o(.rodata)
        . = 0x570fb0 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt2)
        . = 0x570fe0 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt3)
        . = 0x571010 - 0x568f00;
        build/asm/data/rodata/piece_00571010.s.o(.rodata)
        . = 0x571030 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.jtbl_00571030)
        . = 0x571060 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt4)
        . = 0x571090 - 0x568f00;
        build/asm/data/rodata/piece_00571090.s.o(.rodata)
        . = 0x5710e0 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt5)
        . = 0x571110 - 0x568f00;
        build/src/game/menu/to/to_218A78.c.o(.rodata.cjt6)
        . = 0x571138 - 0x568f00;
        build/asm/data/rodata/piece_00571138.s.o(.rodata)
        . = 0x5711a0 - 0x568f00;
        build/src/game/menu/tk/tk_220F30.c.o(.rodata.cjt0)
        . = 0x5711b8 - 0x568f00;
        build/asm/data/rodata/piece_005711B8.s.o(.rodata)
        . = 0x5711d0 - 0x568f00;
        build/src/game/menu/tk/tk_220F30.c.o(.rodata.jtbl_005711D0)
        . = 0x571280 - 0x568f00;
        build/asm/data/rodata/piece_00571280.s.o(.rodata)
        . = 0x571290 - 0x568f00;
        build/src/game/menu/tk/tk_220F30.c.o(.rodata.cjt1)
        . = 0x5712b0 - 0x568f00;
        build/src/game/menu/tk/tk_220F30.c.o(.rodata.cjt2)
        . = 0x5712c8 - 0x568f00;
        build/asm/data/rodata/piece_005712C8.s.o(.rodata)
        . = 0x5712f0 - 0x568f00;
        build/src/game/menu/to/to_224430.c.o(.rodata.cjt0)
        . = 0x571320 - 0x568f00;
        build/src/game/menu/tk/tk_224930.c.o(.rodata.jtbl_00571320)
        . = 0x571378 - 0x568f00;
        build/asm/data/rodata/piece_00571378.s.o(.rodata)
        . = 0x571420 - 0x568f00;
        build/src/game/menu/tk/tk_227C88.c.o(.rodata.cjt0)
        . = 0x571470 - 0x568f00;
        build/asm/data/rodata/piece_00571470.s.o(.rodata)
        . = 0x5717e0 - 0x568f00;
        build/src/game/menu/tk/tk_228B08.c.o(.rodata.jtbl_005717E0)
        . = 0x571830 - 0x568f00;
        build/asm/data/rodata/piece_00571830.s.o(.rodata)
        . = 0x571840 - 0x568f00;
        build/src/game/menu/tk/tk_228B08.c.o(.rodata.cjt0)
        . = 0x571860 - 0x568f00;
        build/asm/data/rodata/piece_00571860.s.o(.rodata)
        . = 0x5718b0 - 0x568f00;
        build/src/game/menu/tk/tk_22B9F8.c.o(.rodata.jtbl_005718B0)
        . = 0x5718e0 - 0x568f00;
        build/asm/data/rodata/piece_005718E0.s.o(.rodata)
        . = 0x571930 - 0x568f00;
        build/src/game/menu/tk/tk_22B9F8.c.o(.rodata.jtbl_00571930)
        . = 0x5719b0 - 0x568f00;
        build/asm/data/rodata/piece_005719B0.s.o(.rodata)
        . = 0x571b20 - 0x568f00;
        build/src/game/menu/tk/tk_22CE70.c.o(.rodata.cjt0)
        . = 0x571b68 - 0x568f00;
        build/asm/data/rodata/piece_00571B68.s.o(.rodata)
        . = 0x571b80 - 0x568f00;
        build/src/game/menu/tk/tk_22CE70.c.o(.rodata.jtbl_00571B80)
        . = 0x571bb0 - 0x568f00;
        build/asm/data/rodata/piece_00571BB0.s.o(.rodata)
        . = 0x571c20 - 0x568f00;
        build/src/game/menu/tk/tk_22CE70.c.o(.rodata.jtbl_00571C20)
        . = 0x571cb8 - 0x568f00;
        build/asm/data/rodata/piece_00571CB8.s.o(.rodata)
        . = 0x571cc0 - 0x568f00;
        build/src/game/menu/tk/tk_22CE70.c.o(.rodata.cjt1)
        . = 0x571ce0 - 0x568f00;
        build/asm/data/rodata/piece_00571CE0.s.o(.rodata)
        . = 0x571d70 - 0x568f00;
        build/src/game/menu/tk/tk_22FB30.c.o(.rodata.cjt0)
        . = 0x571dc0 - 0x568f00;
        build/src/game/menu/tk/tk_22FB30.c.o(.rodata.jtbl_00571DC0)
        . = 0x571e00 - 0x568f00;
        build/asm/data/rodata/piece_00571E00.s.o(.rodata)
        . = 0x571e50 - 0x568f00;
        build/src/game/menu/tk/tk_22FB30.c.o(.rodata.jtbl_00571E50)
        . = 0x571e90 - 0x568f00;
        build/asm/data/rodata/piece_00571E90.s.o(.rodata)
        . = 0x571ff0 - 0x568f00;
        build/src/game/menu/tk/tk_2315E8.c.o(.rodata.jtbl_00571FF0)
        . = 0x572030 - 0x568f00;
        build/src/game/menu/tk/tk_2315E8.c.o(.rodata.jtbl_00572030)
        . = 0x572050 - 0x568f00;
        build/src/game/menu/tk/tk_2315E8.c.o(.rodata.cjt0)
        . = 0x572068 - 0x568f00;
        build/asm/data/rodata/piece_00572068.s.o(.rodata)
        . = 0x5721c0 - 0x568f00;
        build/src/game/menu/tk/tk_232C88.c.o(.rodata.jtbl_005721C0)
        . = 0x5721f0 - 0x568f00;
        build/src/game/menu/tk/tk_232C88.c.o(.rodata.jtbl_005721F0)
        . = 0x572210 - 0x568f00;
        build/asm/data/rodata/piece_00572210.s.o(.rodata)
        . = 0x572340 - 0x568f00;
        build/src/game/menu/tk/tk_234A30.c.o(.rodata.jtbl_00572340)
        . = 0x572370 - 0x568f00;
        build/asm/data/rodata/piece_00572370.s.o(.rodata)
        . = 0x572380 - 0x568f00;
        build/src/game/menu/menu_235C38.c.o(.rodata.cjt0)
        . = 0x5723a0 - 0x568f00;
        build/src/game/menu/menu_235C38.c.o(.rodata.cjt1)
        . = 0x5723c0 - 0x568f00;
        build/asm/data/rodata/piece_005723C0.s.o(.rodata)
        . = 0x5723d0 - 0x568f00;
        build/src/game/menu/to/to_2362B8.c.o(.rodata.cjt0)
        . = 0x572420 - 0x568f00;
        build/asm/data/rodata/piece_00572420.s.o(.rodata)
        . = 0x5725c0 - 0x568f00;
        build/src/game/menu/tk/tk_237888.c.o(.rodata.cjt0)
        . = 0x5725e0 - 0x568f00;
        build/src/game/menu/tk/tk_237888.c.o(.rodata.cjt1)
        . = 0x572600 - 0x568f00;
        build/asm/data/rodata/piece_00572600.s.o(.rodata)
        . = 0x572610 - 0x568f00;
        build/src/game/menu/tk/tk_237888.c.o(.rodata.jtbl_00572610)
        . = 0x5726a8 - 0x568f00;
        build/asm/data/rodata/piece_005726A8.s.o(.rodata)
        . = 0x572a30 - 0x568f00;
        build/src/game/menu/tk/tk_23A450.c.o(.rodata.cjt0)
        . = 0x572a50 - 0x568f00;
        build/src/game/menu/tk/tk_23A450.c.o(.rodata.cjt1)
        . = 0x572a70 - 0x568f00;
        build/asm/data/rodata/piece_00572A70.s.o(.rodata)
        . = 0x572a80 - 0x568f00;
        build/src/game/menu/tk/tk_23A450.c.o(.rodata.jtbl_00572A80)
        . = 0x572b08 - 0x568f00;
        build/asm/data/rodata/piece_00572B08.s.o(.rodata)
        . = 0x572c80 - 0x568f00;
        build/src/game/menu/tk/tk_23C658.c.o(.rodata.jtbl_00572C80)
        . = 0x572cb0 - 0x568f00;
        build/asm/data/rodata/piece_00572CB0.s.o(.rodata)
        . = 0x572d00 - 0x568f00;
        build/src/game/menu/tk/tk_23CBD0.c.o(.rodata.jtbl_00572D00)
        . = 0x572d50 - 0x568f00;
        build/src/game/menu/tk/tk_23CBD0.c.o(.rodata.jtbl_00572D50)
        . = 0x572d70 - 0x568f00;
        build/src/game/menu/tk/tk_23CBD0.c.o(.rodata.jtbl_00572D70)
        . = 0x572db0 - 0x568f00;
        build/src/game/menu/tk/tk_23CBD0.c.o(.rodata.jtbl_00572DB0)
        . = 0x572f80 - 0x568f00;
        build/src/game/menu/tk/tk_23CBD0.c.o(.rodata.cjt0)
        . = 0x572fd0 - 0x568f00;
        build/asm/data/rodata/piece_00572FD0.s.o(.rodata)
        . = 0x572ff0 - 0x568f00;
        build/src/game/menu/tk/tk_242040.c.o(.rodata.cjt0)
        . = 0x573058 - 0x568f00;
        build/asm/data/rodata/piece_00573058.s.o(.rodata)
        . = 0x5730f0 - 0x568f00;
        build/src/game/menu/tk/tk_249928.c.o(.rodata.cjt0)
        . = 0x573150 - 0x568f00;
        build/src/game/menu/tk/tk_249928.c.o(.rodata.jtbl_00573150)
        . = 0x5731f0 - 0x568f00;
        build/asm/data/rodata/piece_005731F0.s.o(.rodata)
        . = 0x573270 - 0x568f00;
        build/src/game/menu/tk/tk_249928.c.o(.rodata.cjt1)
        . = 0x573288 - 0x568f00;
        build/asm/data/rodata/piece_00573288.s.o(.rodata)
        . = 0x5732a0 - 0x568f00;
        build/src/game/menu/tk/tk_249928.c.o(.rodata.jtbl_005732A0)
        . = 0x573300 - 0x568f00;
        build/asm/data/rodata/piece_00573300.s.o(.rodata)
        . = 0x5733b0 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.jtbl_005733B0)
        . = 0x5733d0 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.cjt0)
        . = 0x5733f0 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.cjt1)
        . = 0x573428 - 0x568f00;
        build/asm/data/rodata/piece_00573428.s.o(.rodata)
        . = 0x5734b0 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.jtbl_005734B0)
        . = 0x573510 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.jtbl_00573510)
        . = 0x5735f8 - 0x568f00;
        build/asm/data/rodata/piece_005735F8.s.o(.rodata)
        . = 0x573620 - 0x568f00;
        build/src/game/menu/tk/tk_24B828.c.o(.rodata.jtbl_00573620)
        . = 0x573670 - 0x568f00;
        build/asm/data/rodata/piece_00573670.s.o(.rodata)
        . = 0x573a10 - 0x568f00;
        build/src/game/abm/abm_25AEB0.c.o(.rodata.jtbl_00573A10)
        . = 0x573a24 - 0x568f00;
        build/asm/data/rodata/piece_00573A24.s.o(.rodata)
        . = 0x573a40 - 0x568f00;
        build/src/game/abm/ei_260A70.c.o(.rodata.jtbl_00573A40)
        . = 0x573a60 - 0x568f00;
        build/src/game/abm/ei_260A70.c.o(.rodata.cjt0)
        . = 0x573a90 - 0x568f00;
        build/asm/data/rodata/piece_00573A90.s.o(.rodata)
        . = 0x573ad0 - 0x568f00;
        build/src/game/abm/abm_265F78.c.o(.rodata.cjt0)
        . = 0x573b20 - 0x568f00;
        build/asm/data/rodata/piece_00573B20.s.o(.rodata)
        . = 0x573cc0 - 0x568f00;
        build/src/game/abm/abm_265F78.c.o(.rodata.cjt1)
        . = 0x573d10 - 0x568f00;
        build/asm/data/rodata/piece_00573D10.s.o(.rodata)
        . = 0x573d30 - 0x568f00;
        build/src/game/abm/abm_265F78.c.o(.rodata.cjt2)
        . = 0x573d90 - 0x568f00;
        build/src/game/abm/abm_265F78.c.o(.rodata.cjt3)
        . = 0x573df0 - 0x568f00;
        build/asm/data/rodata/piece_00573DF0.s.o(.rodata)
        . = 0x573e10 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt0)
        . = 0x573e40 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt1)
        . = 0x573e70 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt2)
        . = 0x573ea0 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt3)
        . = 0x573ed0 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt4)
        . = 0x573f00 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt5)
        . = 0x573f30 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt6)
        . = 0x573f60 - 0x568f00;
        build/src/game/particle/particle_266A48.c.o(.rodata.cjt7)
        . = 0x573f88 - 0x568f00;
        build/asm/data/rodata/piece_00573F88.s.o(.rodata)
        . = 0x574020 - 0x568f00;
        build/src/game/particle/eiProg/ppp_268680.c.o(.rodata.jtbl_00574020)
        . = 0x574038 - 0x568f00;
        build/asm/data/rodata/piece_00574038.s.o(.rodata)
        . = 0x574390 - 0x568f00;
        build/src/game/particle/eiProg/pppYanagi.c.o(.rodata.cjt0)
        . = 0x5743d0 - 0x568f00;
        build/src/game/particle/eiProg/pppYanagi.c.o(.rodata.jtbl_005743D0)
        . = 0x5743e8 - 0x568f00;
        build/asm/data/rodata/piece_005743E8.s.o(.rodata)
        . = 0x575470 - 0x568f00;
        build/src/game/op/opu/opu_29A8A8.c.o(.rodata.jtbl_00575470)
        . = 0x5754a0 - 0x568f00;
        build/src/game/op/opu/opu_29A8A8.c.o(.rodata.jtbl_005754A0)
        . = 0x5754d8 - 0x568f00;
        build/asm/data/rodata/piece_005754D8.s.o(.rodata)
        . = 0x575530 - 0x568f00;
        build/src/game/op/opu/opu_29A8A8.c.o(.rodata.cjt0)
        . = 0x575550 - 0x568f00;
        build/src/game/op/opu/opu_29DC40.c.o(.rodata.cjt0)
        . = 0x575570 - 0x568f00;
        build/src/game/op/opu/opu_29DC40.c.o(.rodata.cjt1)
        . = 0x575590 - 0x568f00;
        build/src/game/op/opu/opu_29DC40.c.o(.rodata.cjt2)
        . = 0x5755b0 - 0x568f00;
        build/src/game/op/opu/opu_29DC40.c.o(.rodata.cjt3)
        . = 0x5755d0 - 0x568f00;
        build/src/game/op/opu/opu_2A0820.c.o(.rodata.jtbl_005755D0)
        . = 0x5755e8 - 0x568f00;
        build/asm/data/rodata/piece_005755E8.s.o(.rodata)
        . = 0x575670 - 0x568f00;
        build/src/game/op/opu/opu_2A43D8.c.o(.rodata.jtbl_00575670)
        . = 0x5756a0 - 0x568f00;
        build/asm/data/rodata/piece_005756A0.s.o(.rodata)
        . = 0x575780 - 0x568f00;
        build/src/game/op/opu/opu_2A6FE8.c.o(.rodata.jtbl_00575780)
        . = 0x5757a0 - 0x568f00;
        build/src/game/op/opu/opu_2A6FE8.c.o(.rodata.jtbl_005757A0)
        . = 0x5757f0 - 0x568f00;
        build/asm/data/rodata/piece_005757F0.s.o(.rodata)
        . = 0x575820 - 0x568f00;
        build/src/game/op/opu/opu_2A6FE8.c.o(.rodata.jtbl_00575820)
        . = 0x575860 - 0x568f00;
        build/src/game/op/opu/opu_2A6FE8.c.o(.rodata.cjt0)
        . = 0x575878 - 0x568f00;
        build/asm/data/rodata/piece_00575878.s.o(.rodata)
        . = 0x575a70 - 0x568f00;
        build/src/game/op/opp_2AC750.c.o(.rodata.jtbl_00575A70)
        . = 0x575a90 - 0x568f00;
        build/src/game/op/opp_2AF1D0.c.o(.rodata.cjt0)
        . = 0x575aa8 - 0x568f00;
        build/asm/data/rodata/piece_00575AA8.s.o(.rodata)
        . = 0x575ca0 - 0x568f00;
        build/src/game/op/op_2B4FF8.c.o(.rodata.cjt0)
        . = 0x575cb8 - 0x568f00;
        build/asm/data/rodata/piece_00575CB8.s.o(.rodata)
        . = 0x575d30 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575D30)
        . = 0x575d50 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575D50)
        . = 0x575de0 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575DE0)
        . = 0x575e00 - 0x568f00;
        build/asm/data/rodata/piece_00575E00.s.o(.rodata)
        . = 0x575e50 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575E50)
        . = 0x575e70 - 0x568f00;
        build/asm/data/rodata/piece_00575E70.s.o(.rodata)
        . = 0x575ea0 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575EA0)
        . = 0x575ec0 - 0x568f00;
        build/asm/data/rodata/piece_00575EC0.s.o(.rodata)
        . = 0x575f20 - 0x568f00;
        build/src/game/op/op_2B6B50.c.o(.rodata.jtbl_00575F20)
        . = 0x575f40 - 0x568f00;
        build/asm/data/rodata/piece_00575F40.s.o(.rodata)
        . = 0x576020 - 0x568f00;
        build/src/game/tk/tk_2D25C8.c.o(.rodata.jtbl_00576020)
        . = 0x576040 - 0x568f00;
        build/asm/data/rodata/piece_00576040.s.o(.rodata)
        . = 0x576060 - 0x568f00;
        build/src/game/snd/snd_2D6808.c.o(.rodata.jtbl_00576060)
        . = 0x5760a0 - 0x568f00;
        build/src/game/snd/snd_2D6808.c.o(.rodata.jtbl_005760A0)
        . = 0x5760e0 - 0x568f00;
        build/src/game/snd/snd_2D6808.c.o(.rodata.jtbl_005760E0)
        . = 0x576100 - 0x568f00;
        build/src/game/snd/snd_2D6808.c.o(.rodata.jtbl_00576100)
        . = 0x576140 - 0x568f00;
        build/src/game/snd/snd_2D6808.c.o(.rodata.jtbl_00576140)
        . = 0x576180 - 0x568f00;
        build/asm/data/rodata/piece_00576180.s.o(.rodata)
        . = 0x5766b0 - 0x568f00;
        build/src/sdk/libgraph/libgraph.c.o(.rodata.jtbl_005766B0)
        . = 0x5767a0 - 0x568f00;
        build/asm/data/rodata/piece_005767A0.s.o(.rodata)
        . = 0x5768c0 - 0x568f00;
        build/src/sdk/libgraph/libgraph.c.o(.rodata.jtbl_005768C0)
        . = 0x5769b0 - 0x568f00;
        build/asm/data/rodata/piece_005769B0.s.o(.rodata)
        . = 0x5769d0 - 0x568f00;
        build/src/game/platform/platform_2DC110.c.o(.rodata.jtbl_005769D0)
        . = 0x5769f0 - 0x568f00;
        build/src/game/platform/ffx_2DC580.c.o(.rodata.jtbl_005769F0)
        . = 0x576a08 - 0x568f00;
        build/asm/data/rodata/piece_00576A08.s.o(.rodata)
        . = 0x5781e0 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F0840.c.o(.rodata.jtbl_005781E0)
        . = 0x578298 - 0x568f00;
        build/asm/data/rodata/piece_00578298.s.o(.rodata)
        . = 0x578350 - 0x568f00;
        build/src/sdk/newlib/libc/vfprintf.c.o(.rodata.jtbl_00578350)
        . = 0x5784c0 - 0x568f00;
        build/asm/data/rodata/piece_005784C0.s.o(.rodata)
        . = 0x5784f0 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.rodata.jtbl_005784F0)
        . = 0x5786e0 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.rodata.jtbl_005786E0)
        . = 0x578700 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.rodata.jtbl_00578700)
        . = 0x578840 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.rodata.jtbl_00578840)
        . = 0x578930 - 0x568f00;
        build/asm/data/rodata/piece_00578930.s.o(.rodata)
        . = 0x578970 - 0x568f00;
        build/src/sdk/newlib/libc/libc_2F3A70.c.o(.rodata.jtbl_00578970)
        . = 0x578988 - 0x568f00;
        build/asm/data/rodata/piece_00578988.s.o(.rodata)
        . = 0x578bc0 - 0x568f00;
        build/src/sdk/libkernl/tty.c.o(.rodata.jtbl_00578BC0)
        . = 0x578cf0 - 0x568f00;
        build/src/sdk/libkernl/libkernl_2FBBE8.c.o(.rodata.cjt0)
        . = 0x578d58 - 0x568f00;
        build/asm/data/rodata/piece_00578D58.s.o(.rodata)
    }
    . = 0x578e00;
    .vutext : { build/assets/vutext.bin.o(.data) }
    . = 0x57c680;
    .lit4 : SUBALIGN(4) { build/asm/data/lit4.data.s.o(.data) }
    . = 0x57cb80;
    .bss (NOLOAD) : { build/asm/data/47DB0C.bss.s.o(.bss) }
    /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.gnu.attributes) *(.comment) *(.pdr) *(.mdebug*) }
}
