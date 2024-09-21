module proc (DIN, Resetn, Clock, Run, Done, BusWires, R0, R1, R2, R3, R4, R5, R6, R7, RA, RG, alu_out,Tstep_Q); 
	//inputs
	input wire Resetn, Clock, Run;
	input wire [8:0] DIN;
	//outputs
	output reg Done;
	output wire [8:0] R0, R1, R2, R3, R4, R5, R6, R7, RA, RG, alu_out,BusWires;
	//wires
	wire [2:0]I;
	wire [7:0]Xreg, Yreg;
	wire [8:0]IR;
	// registers
	output reg [1:0] Tstep_Q;
	reg a_in, g_in ,IR_in, g_out, DIN_out,ALU_in;
	reg [1:0]  Tstep_D;
	reg [7:0]R_in,R_out; 
					//cycle parameters
	parameter 	T0 = 2'b00, 
					T1 = 2'b01,
					T2 = 2'b10,
					T3 = 2'b11,
					// order parameters
					mv  = 3'b000, 
					mvi = 3'b001,
					add = 3'b010,
					sub = 3'b011,
					addi = 3'b100,
					subi = 3'b101;

	
	assign I = IR[8:6]; 				// take bits 6,7,8 - INSTRUCTION
	dec3to8 decX (IR[5:3], 1'b1, Xreg); // take bits 3,4,5 - XXX - convert to 9 bits "one-hot code"
	dec3to8 decY (IR[2:0], 1'b1, Yreg);	// take bits 0,1,2 - YYY - convert to 9 bits "one-hot code"

	// state machine cycle handeling

	always @(Tstep_Q, Run, Done) begin
		
		case (Tstep_Q)
			T0: begin	
					// data is loaded into IR in this time step 
					if (!Run)
						Tstep_D = T0;
					else
						Tstep_D = T1;
				end
				
			T1: begin
					if(Done)
						Tstep_D = T0;
					else
						Tstep_D = T2;
				end
				
			T2: begin
					 Tstep_D = T3;
				end
				
			T3: begin
					 Tstep_D = T0;
				end
		endcase
	end


	// Control FSM outputs
	always @(Tstep_Q or I or Xreg or Yreg)
	begin
	//initial values
		IR_in <= 1'b0; 
		a_in <= 1'b0;
		g_in <= 1'b0;
		g_out <= 1'b0;
		DIN_out <= 1'b0;
		R_in <= 8'b0;
		R_out <= 8'b0;
		Done <= 1'b0;
		case (Tstep_Q) 
			default
			T0:
			//data reading
				begin  	
					IR_in <= 1'b1; 
					a_in <= 1'b0;
					g_in <= 1'b0;
					g_out <= 1'b0;
					DIN_out <= 1'b0;
					R_in <= 8'b0;
					R_out <= 8'b0;
					Done <= 1'b0;
					
						
				end
			T1:
			// mv or mvi are executed here and finish here, 
			//add, sub ,addi , subi are saving first value to A reg.
				begin			
					case (I)
						mv: 
							begin
							IR_in <= 1'b0; 
							a_in <= 1'b0;
							g_in <= 1'b0;
							g_out <= 1'b0;
							DIN_out <= 1'b0;
							R_in <= Xreg;
							R_out <= Yreg;
							Done <= 1'b1;
							end
						
						mvi: 
							begin
							IR_in <= 1'b0; 
							a_in <= 1'b0;
							g_in <= 1'b0;
							g_out <= 1'b0;
							DIN_out <= 1'b1;
							R_in <= Xreg;
							R_out <= 8'b0;
							Done <= 1'b1;
							end
		
						add: 
							begin
								IR_in <= 1'b0; 
								a_in <= 1'b1;
								g_in <= 1'b0;
								g_out <= 1'b0;
								DIN_out <= 1'b0;
								R_in <= 8'b0;
								R_out <= Xreg;
								Done <= 1'b0;
					
							end
								
						sub:
							begin
								IR_in <= 1'b0; 
								a_in <= 1'b1;
								g_in <= 1'b0;
								g_out <= 1'b0;
								DIN_out <= 1'b0;
								R_in <= 8'b0;
								R_out <= Xreg;
								Done <= 1'b0;

							end
						
						addi: 
							begin
								IR_in <= 1'b0; 
								a_in <= 1'b1;
								g_in <= 1'b0;
								g_out <= 1'b0;
								DIN_out <= 1'b0;
								R_in <= 8'b0;
								R_out <= Xreg;
								Done <= 1'b0;
	
							end
						subi:
							begin
								IR_in <= 1'b0; 
								a_in <= 1'b1;
								g_in <= 1'b0;
								g_out <= 1'b0;
								DIN_out <= 1'b0;
								R_in <= 8'b0;
								R_out <= Xreg;
								Done <= 1'b0;
							end
						
					endcase 
				end 
									
			T2: 
			//second cycle of add, sub ,addi ,subi is preformed here - add and sub loading second value into buswires,
			//and turning on g reg for keeping alu result value
			begin
				if ((I==add) || (I==sub))
				begin
					IR_in <= 1'b0; 
					a_in <= 1'b1;
					g_in <= 1'b1;
					g_out <= 1'b0;
					DIN_out <= 1'b0;
					R_in <= 8'b0;
					R_out <= Yreg;
					Done <= 1'b0;
					
				end	
				else if ((I == addi) || (I == subi))
				begin
					IR_in <= 1'b0; 
					a_in <= 1'b0;
					g_in <= 1'b1;
					g_out <= 1'b0;
					DIN_out <= 1'b1;
					R_in <= 8'b0;
					R_out <= 8'b0;
					Done <= 1'b0;
				end 
				if((I == add) || (I == addi))
				begin
					ALU_in <= 1'b1;
				end
				else if((I==sub) || (I == subi))
				begin
					ALU_in <= 1'b0;
				end
			end
				
			T3: 
			// final step for add, sub ,addi ,subi , result is read from g register into the fsm machine, 
			// and done bit is turned on for reseting the machine back to data read state.
				begin 
				IR_in <= 1'b0; 
				a_in <= 1'b0;
				g_in <= 1'b0;
				g_out <= 1'b1;
				DIN_out <= 1'b0;
				R_in <= Xreg;
				R_out <= 8'b0;
				Done <= 1'b1;	
				end 
		endcase 
	end 

	// Control FSM flip-flops
	always @(posedge Clock, negedge Resetn) 
	begin
		if (!Resetn) 			
			Tstep_Q = Tstep_Q;
		else
			Tstep_Q = Tstep_D; // cs = ns
	end

	regn reg_0 (BusWires, R_in[0], Clock, R0);
	regn reg_1 (BusWires, R_in[1], Clock, R1);
	regn reg_2 (BusWires, R_in[2], Clock, R2);
	regn reg_3 (BusWires, R_in[3], Clock, R3);
	regn reg_4 (BusWires, R_in[4], Clock, R4);
	regn reg_5 (BusWires, R_in[5], Clock, R5);
	regn reg_6 (BusWires, R_in[6], Clock, R6);
	regn reg_7 (BusWires, R_in[7], Clock, R7);
	
	regn reg_A (BusWires, a_in, Clock, RA);
	regn reg_G (alu_out, g_in, Clock, RG); 	
	regn reg_IR (DIN, IR_in, Clock, IR);


mux_module mux_module_inst
(
	.g_in(RG) ,	// input [8:0] g_in_sig
	.DIN(DIN) ,	// input [8:0] DIN_sig
	.R0(R0),
	.R1(R1), 
	.R2(R2), 
	.R3(R3),
	.R4(R4), 
	.R5(R5), 
	.R6(R6), 
	.R7(R7), 	// input [8:0] R7_sig
	.r_out(R_out) ,	// input [7:0] r_out_sig
	.g_out(g_out) ,	// input  g_out_sig
	.DIN_out(DIN_out) ,	// input  DIN_out_sig
	.out(BusWires) 	// output [8:0] out_sig
);


ALU_unit ALU_unit_inst
(
	.alu_in(ALU_in) ,	// input  alu_in_sig
	.A_val(RA) ,	// input [8:0] regA_sig
	.B_val(BusWires) ,	// input [8:0] regB_sig
	.ALUout(alu_out) 	// output [8:0] ALUout_sig
);


endmodule








