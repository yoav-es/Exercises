module mux_module( g_in, DIN, R0, R1, R2, R3, R4, R5, R6, R7, r_out, g_out, DIN_out, out);
	// input
	input wire 	[8:0]g_in,DIN,R0, R1, R2, R3, R4, R5, R6, R7;
	input wire [7:0]r_out;        
	input wire g_out, DIN_out;
	// output
	output wire [8:0] out;
	
	parameter zero = 8'b0;
	
	// output assigment
	assign out = (g_out == 1)    ? g_in:
					(DIN_out == 1)    ? DIN:
					(r_out == 8'h1) ? R0: 	
					(r_out == 8'h2) ? R1:	
					(r_out == 8'h4) ? R2:	
					(r_out == 8'h8) ? R3:	
					(r_out == 8'h10)? R4:	
					(r_out == 8'h20)? R5:	
					(r_out == 8'h40)? R6:	
					(r_out == 8'h80)? R7:	
					R0;
endmodule
