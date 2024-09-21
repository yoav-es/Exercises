module fsm1010(clk, in, resetb, out);
//inputs
input wire clk;
input wire in;
input wire resetb;
//outputs
output [2:0] out;
//internal regs
reg out;	
reg [2:0] state;
//states 
parameter S = 3'b000,
		  S1 = 3'b001,
		  S10 = 3'b010,
		  S101 = 3'b011,
		  S1010 = 3'b100;

//state transitions
always @(posedge clk or negedge resetb)
     begin
          if (~resetb)
               state = S;
          else
               case (state)
					S:   
						if(in)
							state = S1;
						else
							state = S;
					S1:   
						if(in)
							state = S1;
						else
							state = S10;		   
					S10:
						if(in)
							state = S101;
						else
							state = S;	
					S101:
						if(in)
							state = S1;
						else
							state = S1010;	
					S1010:
						if(in)
							state = S101;
						else
							state = S;	
               endcase
     end
     
//end cases
always @(posedge clk) 
     begin
          case (state)
               S1010:
                    out = 1;
               default:
                    out = 0;
          endcase
     end
endmodule