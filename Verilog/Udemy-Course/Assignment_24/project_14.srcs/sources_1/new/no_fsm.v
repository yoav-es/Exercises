`timescale 1ns / 1ps

module no_fsm(
  input clk, rst, din,
  output reg dout
  );
parameter idle = 0;
parameter s0 = 1;
parameter s1 = 2; 
parameter s2 = 3; 
parameter s3 = 4; 
reg [2:0] state; 
  
always@(posedge clk)
  begin
  /////reset logic -----Sequential process  
    if(rst == 1'b1)
      begin
        state <= idle;
        dout <= 1'b0;
  end
    else 
      begin
  ///////////output decoder
        case(state)
        idle: begin
          dout <= 1'b0;
          state <= s0;
        end
        s0: begin 
          dout <= 1'b0; 
          state <= (din) ? s1 : s0; 
        end
        s1: begin
          dout <= 1'b0; 
          state <= (~din) ? s2 : s1; 
        end
        s2: begin
          dout <= 1'b0; 
          state <= (~din) ? s3 : s1; 
        end
        s3: begin
          dout  <= (din) ? 1'b1 : 1'b0; 
          state <= (din) ? s1 : s0; 
        end         
        default: begin
          state <= idle;
          dout  <= 1'b0;
        end
        endcase
      end      
  end
endmodule