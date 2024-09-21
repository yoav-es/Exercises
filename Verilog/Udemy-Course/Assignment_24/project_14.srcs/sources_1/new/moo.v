`timescale 1ns / 1ps

module moo(
  input clk, rst, din,
  output reg dout
  );
parameter idle = 0;
parameter s0 = 1;
parameter s1 = 2;
parameter s2 = 3;
parameter s3 = 4;
parameter s4 = 5;

reg [2:0] state, nstate;

/////reset logic -----Sequential process
always@(posedge clk)
begin
  if(rst == 1'b1)
    state <= idle;
  else
    state <= nstate;
end

///////////output decoder

//always@(state , din)
//begin
//  case(state)
//  idle : dout = 1'b0;
//  s0   
//  : dout = 1'b0;
//  s1  : dout = 1'b0;
//  s2  : dout = 1'b0;
//  s3  : dout = 1'b0;
//  s4  : dout = (din == 1'b0) ? 1'b1 : 1'b0;
//  default: dout = 1'b0;
//  endcase
//end

//////////////////Next State decoder
always@(state,din)
begin
  case(state)
  idle : begin
  s0: begin
    nstate = (din == 1'b1) ? s1 : s0;
    dout = 1'b0;
  end
  s1: begin
    nstate = (din == 1'b0) ? s2 : s1;
    dout = 1'b0;
  end
  s2: begin
    nstate = (din == 1'b0) ? s3 : s1;
    dout = 1'b0;
  end
  s3: begin
    nstate = (din == 1'b1) ? s4 : s0;
    dout = 1'b0;
   end
  s4: begin
    nstate = (din == 1'b0) ? s1 : s0;
    dout   = 1'b1; 
  end
  default : nstate = idle;
  endcase
end

endmodule