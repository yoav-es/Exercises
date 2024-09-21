`timescale 1ns / 1ps


module mil(
    input clk, rst, din,
    output reg dout
    );

parameter s0 = 0;
parameter s1 = 1; 
parameter s2 = 2; 


reg [1:0] state; 
  
always@(posedge clk)
    begin
    /////reset logic  -----Sequential process  
        if(rst == 1'b1)
            begin
                state <= s0;
                dout  <= 1'b0;
            end
        else 
            begin
    ///////////output decoder
                case(state)
                s0: begin 
                    dout  <= 1'b0; 
                    state <= (din) ? s1 : s2; 
                end
                s1: begin
                    dout  <= 1'b1; 
                    state <= (din) ? s1 : s2; 
                end
                s2: begin
                    dout  <= 1'b0; 
                    state <= (din) ? s1 : s2; 
                end
                default: begin
                    state <= s0;
                    dout  <= 1'b0;
                end
                endcase
            end           
    end
endmodule
