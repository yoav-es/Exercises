`timescale 1ns / 1ps
 module fsm(
    input clk, rst, din,
    output reg dout
    );
parameter idle = 0;
parameter s0 = 1;
parameter s1 = 2; 
parameter s2 = 3; 
parameter s3 = 4; 
reg [2:0] state, nstate; 

always@(posedge clk)
   begin
     if(rst == 1'b1)
       state <= idle;
     else
       state <= nstate;
   end 

always@(state , din)   
    begin
        case(state)
        idle : dout = 1'b0; 
        s0   : dout = 1'b0;
        s1   : dout = 1'b0;
        s2   : dout = 1'b0;
        s3   : dout = 1'b1;
        default: dout = 1'b0;
        endcase
    end 
 
always@(state,din) 
    begin
        case(state)
        idle :   begin
                nstate = s0;
            end
        s0: begin
                nstate = (din == 1'b1) ? s1 : s0; 
            end
        s1: begin
                nstate = (din == 1'b0) ? s2 : s0; 
            end
        s2: begin
                nstate = (din == 1'b0) ? s3 : s0; 
        end
        s3: begin
                nstate = (din == 1'b1) ? s1 : s0; 
        end
        
        default : nstate = idle; 
        endcase
    end    
endmodule