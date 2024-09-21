module ALU_unit(alu_in,A_val, B_val, ALUout);
	//input
	input wire alu_in;
	input wire [8:0]A_val, B_val;  
	//output
	output wire [8:0]ALUout;
	
	parameter	SUB = 1'b0,
					ADD = 1'b1;
	//output assigments
	assign ALUout = (alu_in == ADD)? A_val + B_val: A_val - B_val;

endmodule
