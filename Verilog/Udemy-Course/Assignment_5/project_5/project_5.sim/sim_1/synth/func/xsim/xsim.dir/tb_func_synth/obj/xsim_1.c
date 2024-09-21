/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2020 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

#if defined(_WIN32)
 #include "stdio.h"
 #define IKI_DLLESPEC __declspec(dllimport)
#else
 #define IKI_DLLESPEC
#endif
#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2020 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

#if defined(_WIN32)
 #include "stdio.h"
 #define IKI_DLLESPEC __declspec(dllimport)
#else
 #define IKI_DLLESPEC
#endif
#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
typedef void (*funcp)(char *, char *);
extern int main(int, char**);
IKI_DLLESPEC extern void execute_448(char*, char *);
IKI_DLLESPEC extern void execute_449(char*, char *);
IKI_DLLESPEC extern void execute_450(char*, char *);
IKI_DLLESPEC extern void execute_791(char*, char *);
IKI_DLLESPEC extern void execute_792(char*, char *);
IKI_DLLESPEC extern void execute_793(char*, char *);
IKI_DLLESPEC extern void execute_794(char*, char *);
IKI_DLLESPEC extern void execute_795(char*, char *);
IKI_DLLESPEC extern void execute_796(char*, char *);
IKI_DLLESPEC extern void execute_797(char*, char *);
IKI_DLLESPEC extern void execute_798(char*, char *);
IKI_DLLESPEC extern void execute_799(char*, char *);
IKI_DLLESPEC extern void execute_800(char*, char *);
IKI_DLLESPEC extern void vlog_const_rhs_process_execute_0_fast_no_reg_no_agg(char*, char*, char*);
IKI_DLLESPEC extern void execute_456(char*, char *);
IKI_DLLESPEC extern void execute_480(char*, char *);
IKI_DLLESPEC extern void execute_490(char*, char *);
IKI_DLLESPEC extern void execute_491(char*, char *);
IKI_DLLESPEC extern void execute_492(char*, char *);
IKI_DLLESPEC extern void execute_81(char*, char *);
IKI_DLLESPEC extern void execute_82(char*, char *);
IKI_DLLESPEC extern void execute_83(char*, char *);
IKI_DLLESPEC extern void execute_549(char*, char *);
IKI_DLLESPEC extern void execute_550(char*, char *);
IKI_DLLESPEC extern void execute_551(char*, char *);
IKI_DLLESPEC extern void execute_242(char*, char *);
IKI_DLLESPEC extern void execute_243(char*, char *);
IKI_DLLESPEC extern void vlog_simple_process_execute_0_fast_no_reg_no_agg(char*, char*, char*);
IKI_DLLESPEC extern void execute_309(char*, char *);
IKI_DLLESPEC extern void execute_452(char*, char *);
IKI_DLLESPEC extern void execute_453(char*, char *);
IKI_DLLESPEC extern void execute_454(char*, char *);
IKI_DLLESPEC extern void execute_455(char*, char *);
IKI_DLLESPEC extern void execute_801(char*, char *);
IKI_DLLESPEC extern void execute_802(char*, char *);
IKI_DLLESPEC extern void execute_803(char*, char *);
IKI_DLLESPEC extern void execute_804(char*, char *);
IKI_DLLESPEC extern void execute_805(char*, char *);
IKI_DLLESPEC extern void execute_806(char*, char *);
IKI_DLLESPEC extern void vlog_transfunc_eventcallback(char*, char*, unsigned, unsigned, unsigned, char *);
IKI_DLLESPEC extern void transaction_71(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_75(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_79(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_83(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_87(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_91(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_95(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_99(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_103(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_107(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_111(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_115(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_119(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_123(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_127(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_131(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_135(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_139(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_143(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_147(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_151(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_155(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_159(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_163(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_167(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_171(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_175(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_179(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_183(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_187(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_191(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_195(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_199(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_203(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_207(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_211(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_215(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_219(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_223(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_227(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_311(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_316(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_321(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_326(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_331(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_336(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_341(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_346(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_351(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_355(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_359(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_363(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_367(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_371(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_375(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_379(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_383(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_387(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_391(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_395(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_399(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_403(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_407(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_411(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_415(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_419(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_423(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_427(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_431(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_435(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_439(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_443(char*, char*, unsigned, unsigned, unsigned);
funcp funcTab[112] = {(funcp)execute_448, (funcp)execute_449, (funcp)execute_450, (funcp)execute_791, (funcp)execute_792, (funcp)execute_793, (funcp)execute_794, (funcp)execute_795, (funcp)execute_796, (funcp)execute_797, (funcp)execute_798, (funcp)execute_799, (funcp)execute_800, (funcp)vlog_const_rhs_process_execute_0_fast_no_reg_no_agg, (funcp)execute_456, (funcp)execute_480, (funcp)execute_490, (funcp)execute_491, (funcp)execute_492, (funcp)execute_81, (funcp)execute_82, (funcp)execute_83, (funcp)execute_549, (funcp)execute_550, (funcp)execute_551, (funcp)execute_242, (funcp)execute_243, (funcp)vlog_simple_process_execute_0_fast_no_reg_no_agg, (funcp)execute_309, (funcp)execute_452, (funcp)execute_453, (funcp)execute_454, (funcp)execute_455, (funcp)execute_801, (funcp)execute_802, (funcp)execute_803, (funcp)execute_804, (funcp)execute_805, (funcp)execute_806, (funcp)vlog_transfunc_eventcallback, (funcp)transaction_71, (funcp)transaction_75, (funcp)transaction_79, (funcp)transaction_83, (funcp)transaction_87, (funcp)transaction_91, (funcp)transaction_95, (funcp)transaction_99, (funcp)transaction_103, (funcp)transaction_107, (funcp)transaction_111, (funcp)transaction_115, (funcp)transaction_119, (funcp)transaction_123, (funcp)transaction_127, (funcp)transaction_131, (funcp)transaction_135, (funcp)transaction_139, (funcp)transaction_143, (funcp)transaction_147, (funcp)transaction_151, (funcp)transaction_155, (funcp)transaction_159, (funcp)transaction_163, (funcp)transaction_167, (funcp)transaction_171, (funcp)transaction_175, (funcp)transaction_179, (funcp)transaction_183, (funcp)transaction_187, (funcp)transaction_191, (funcp)transaction_195, (funcp)transaction_199, (funcp)transaction_203, (funcp)transaction_207, (funcp)transaction_211, (funcp)transaction_215, (funcp)transaction_219, (funcp)transaction_223, (funcp)transaction_227, (funcp)transaction_311, (funcp)transaction_316, (funcp)transaction_321, (funcp)transaction_326, (funcp)transaction_331, (funcp)transaction_336, (funcp)transaction_341, (funcp)transaction_346, (funcp)transaction_351, (funcp)transaction_355, (funcp)transaction_359, (funcp)transaction_363, (funcp)transaction_367, (funcp)transaction_371, (funcp)transaction_375, (funcp)transaction_379, (funcp)transaction_383, (funcp)transaction_387, (funcp)transaction_391, (funcp)transaction_395, (funcp)transaction_399, (funcp)transaction_403, (funcp)transaction_407, (funcp)transaction_411, (funcp)transaction_415, (funcp)transaction_419, (funcp)transaction_423, (funcp)transaction_427, (funcp)transaction_431, (funcp)transaction_435, (funcp)transaction_439, (funcp)transaction_443};
const int NumRelocateId= 112;

void relocate(char *dp)
{
	iki_relocate(dp, "xsim.dir/tb_func_synth/xsim.reloc",  (void **)funcTab, 112);

	/*Populate the transaction function pointer field in the whole net structure */
}

void sensitize(char *dp)
{
	iki_sensitize(dp, "xsim.dir/tb_func_synth/xsim.reloc");
}

void simulate(char *dp)
{
		iki_schedule_processes_at_time_zero(dp, "xsim.dir/tb_func_synth/xsim.reloc");
	// Initialize Verilog nets in mixed simulation, for the cases when the value at time 0 should be propagated from the mixed language Vhdl net
	iki_execute_processes();

	// Schedule resolution functions for the multiply driven Verilog nets that have strength
	// Schedule transaction functions for the singly driven Verilog nets that have strength

}
#include "iki_bridge.h"
void relocate(char *);

void sensitize(char *);

void simulate(char *);

extern SYSTEMCLIB_IMP_DLLSPEC void local_register_implicit_channel(int, char*);
extern SYSTEMCLIB_IMP_DLLSPEC int xsim_argc_copy ;
extern SYSTEMCLIB_IMP_DLLSPEC char** xsim_argv_copy ;

int main(int argc, char **argv)
{
    iki_heap_initialize("ms", "isimmm", 0, 2147483648) ;
    iki_set_xsimdir_location_if_remapped(argc, argv)  ;
    iki_set_sv_type_file_path_name("xsim.dir/tb_func_synth/xsim.svtype");
    iki_set_crvs_dump_file_path_name("xsim.dir/tb_func_synth/xsim.crvsdump");
    void* design_handle = iki_create_design("xsim.dir/tb_func_synth/xsim.mem", (void *)relocate, (void *)sensitize, (void *)simulate, (void*)0, 0, isimBridge_getWdbWriter(), 0, argc, argv);
     iki_set_rc_trial_count(100);
    (void) design_handle;
    return iki_simulate_design();
}
