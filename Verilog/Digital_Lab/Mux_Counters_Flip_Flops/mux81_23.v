module mux81_23(in0,in1,in2,in3,in4,in5,in6,in7,s0,s1,s2,out);
// inputs
	input wire	s0;
	input wire	s1;
	input wire	s2;
	input wire	in0;
	input wire	in1;
	input wire	in2;
	input wire	in3;
	input wire	in4;
	input wire	in5;
	input wire	in6;
	input wire	in7;
//output
	output wire	out;
//inner wires (from first level to second level(8->4) and from second level to third level(4-2)
	wire	wire_0;
	wire	wire_1;
	wire	wire_2;
	wire	wire_3;
	wire	wire_4;
	wire	wire_5;


//first level mux, entries 0 and 1, out wire_0
	m21 m21_inst0
	(
		.in1(in0) ,	// input  in1_sig
		.in2(in1) ,	// input  in2_sig
		.sel(s0) ,	// input  sel_sig
		.out(wire_0) 	// output  out_sig
	);

//first level mux, entries 2 and 3, out wire_1
	m21 m21_inst1
	(
		.in1(in2) ,	// input  in1_sig
		.in2(in3) ,	// input  in2_sig
		.sel(s0) ,	// input  sel_sig
		.out(wire_1) 	// output  out_sig
	);
	
//first level mux, entries 4 and 5 out wire_2
	m21 m21_inst2
	(
		.in1(in4) ,	// input  in1_sig
		.in2(in5) ,	// input  in2_sig
		.sel(s0) ,	// input  sel_sig
		.out(wire_2) 	// output  out_sig
	);
	
//first level mux, entries 6 and 5 out wire_3
	m21 m21_inst3
	(
		.in1(in6) ,	// input  in1_sig
		.in2(in7) ,	// input  in2_sig
		.sel(s0) ,	// input  sel_sig
		.out(wire_3) 	// output  out_sig
	);
	
//second level mux, entries wire_0 and wire_1 out wire_4
	m21 m21_inst4
	(
		.in1(wire_0) ,	// input  in1_sig
		.in2(wire_1) ,	// input  in2_sig
		.sel(s1) ,	// input  sel_sig
		.out(wire_4) 	// output  out_sig
	);
	
//second level mux, entries wire_0 and wire_1 out wire_5
	m21 m21_inst5
	(
		.in1(wire_2) ,	// input  in1_sig
		.in2(wire_3) ,	// input  in2_sig
		.sel(s1) ,	    // input  sel_sig
		.out(wire_5) 	// output  out_sig
	);
	
//third level mux, entries wire_4 and wire_5 out mux total output

	m21 m21_inst6
	(
		.in1(wire_4) ,	// input  in1_sig
		.in2(wire_5) ,	// input  in2_sig
		.sel(s2) ,	// input  sel_sig
		.out(out) 	// output  out_sig
	);
endmodule












